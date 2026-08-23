/*
  Generated from python/mgga_exc/mgga_x_m06l.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_m06l
*/

#ifndef _MGGA_X_M06L_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_M06L_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_M06L_HELPER_BODIES
#include "mgga_x_m06l.c"
#undef _MGGA_X_M06L_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_M06L_HELPER_BODIES
#include "mgga_x_m06l.c"
#undef _MGGA_X_M06L_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_M06L_HELPER_BODIES
#include "mgga_x_m06l.c"
#undef _MGGA_X_M06L_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_M06L_HELPER_BODIES
#include "mgga_x_m06l.c"
#undef _MGGA_X_M06L_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_M06L_HELPER_BODIES
#include "mgga_x_m06l.c"
#undef _MGGA_X_M06L_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_m06l.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_m06l.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_m06l.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_m06l.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_m06l.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_m06l.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_m06l.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_m06l.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_m06l.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_m06l.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_M06L_HELPER_BODIES)

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
  const mgga_x_m06l_params *params = (const mgga_x_m06l_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = -p->dens_threshold + n_s <= 0;
  const double _t6 = xc_powr(n_s, -8, 3);
  const double _t7 = _t6*sigma_ss;
  const double _t8 = xc_powr(n_s, -5, 3);
  const double _t9 = _t8*tau_s;
  const double _t10 = xc_powr(0.6e1, 2, 3);
  const double _t11 = (M_PI * M_CBRTPI);
  const double _t12 = _t10*_t11;
  const double _t13 = -0.0011203559999999999*_t12 + 0.0018672599999999999*_t7 + 0.0037345199999999999*_t9 + 0.1e1;
  const double _t14 = (0.1e1 / (_t13 * _t13));
  const double _t15 = -0.3e1 / 0.5e1*_t12 + 0.2e1*_t8*tau_s;
  const double _t16 = _t15*params->d[2] + _t7*params->d[1];
  const double _t17 = (0.1e1 / (_t13 * _t13 * _t13));
  const double _t18 = (sigma_ss * sigma_ss);
  const double _t19 = xc_powr(n_s, -16, 3);
  const double _t20 = _t19*params->d[3];
  const double _t21 = _t15*params->d[4];
  const double _t22 = (_t15 * _t15)*params->d[5] + _t18*_t20 + _t21*_t7;
  const double _t23 = _t1/_t11;
  const double _t24 = _t23*_t7;
  const double _t25 = 0.009146457198521546*_t24 + 0.80400000000000005;
  const double _t26 = (0.1e1 / _t25);
  const double _t27 = 0.0073537515876113235*_t24*_t26 + 0.1e1;
  const double _t28 = (0.3e1 / 0.10e2)*_t12;
  const double _t29 = _t28 - _t9;
  const double _t30 = _t28 + _t9;
  const double _t31 = (0.1e1 / _t30);
  const double _t32 = _t31*params->a[1];
  const double _t33 = xc_powi(_t30, -10);
  const double _t34 = xc_powi(_t29, 10);
  const double _t35 = _t34*params->a[10];
  const double _t36 = xc_powi(_t30, -11);
  const double _t37 = xc_powi(_t29, 11);
  const double _t38 = _t37*params->a[11];
  const double _t39 = (_t29 * _t29);
  const double _t40 = (0.1e1 / (_t30 * _t30));
  const double _t41 = _t40*params->a[2];
  const double _t42 = (_t29 * _t29 * _t29);
  const double _t43 = (0.1e1 / (_t30 * _t30 * _t30));
  const double _t44 = _t43*params->a[3];
  const double _t45 = (_t29 * _t29 * _t29 * _t29);
  const double _t46 = (0.1e1 / (_t30 * _t30 * _t30 * _t30));
  const double _t47 = _t46*params->a[4];
  const double _t48 = xc_powi(_t30, -5);
  const double _t49 = xc_powi(_t29, 5);
  const double _t50 = _t49*params->a[5];
  const double _t51 = xc_powi(_t30, -6);
  const double _t52 = xc_powi(_t29, 6);
  const double _t53 = _t52*params->a[6];
  const double _t54 = xc_powi(_t30, -7);
  const double _t55 = xc_powi(_t29, 7);
  const double _t56 = _t55*params->a[7];
  const double _t57 = xc_powi(_t30, -8);
  const double _t58 = xc_powi(_t29, 8);
  const double _t59 = _t58*params->a[8];
  const double _t60 = xc_powi(_t30, -9);
  const double _t61 = xc_powi(_t29, 9);
  const double _t62 = _t61*params->a[9];
  const double _t63 = _t29*_t32 + _t33*_t35 + _t36*_t38 + _t39*_t41 + _t42*_t44 + _t45*_t47 + _t48*_t50 + _t51*_t53 + _t54*_t56 + _t57*_t59 + _t60*_t62 + params->a[0];
  const double _t64 = _t14*_t16 + _t17*_t22 + _t27*_t63 + params->d[0]/_t13;
#if _KMAX >= 1
  const double _t66 = _t14*params->d[0];
  const double _t67 = _t14*params->d[2];
  const double _t68 = 0.2e1*_t8;
  const double _t69 = _t16*_t17;
  const double _t70 = 0.0074690399999999997*_t8;
  const double _t71 = 0.2e1*sigma_ss;
  const double _t72 = xc_powr(n_s, -13, 3);
  const double _t73 = _t72*params->d[4];
  const double _t74 = _t15*params->d[5];
  const double _t75 = 0.4e1*_t8;
  const double _t76 = _t71*_t73 + _t74*_t75;
  const double _t77 = (0.1e1 / (_t13 * _t13 * _t13 * _t13));
  const double _t78 = _t22*_t77;
  const double _t79 = 0.01120356*_t8;
  const double _t80 = _t40*params->a[1];
  const double _t81 = _t29*_t8;
  const double _t82 = 0.10e2*_t8;
  const double _t83 = _t33*params->a[10];
  const double _t84 = _t61*_t83;
  const double _t85 = _t35*_t36;
  const double _t86 = 0.11e2*_t8;
  const double _t87 = _t36*params->a[11];
  const double _t88 = _t34*_t87;
  const double _t89 = xc_powi(_t30, -12);
  const double _t90 = _t38*_t89;
  const double _t91 = _t43*params->a[2];
  const double _t92 = _t39*_t91;
  const double _t93 = 0.3e1*_t8;
  const double _t94 = _t39*_t44;
  const double _t95 = _t46*params->a[3];
  const double _t96 = _t42*_t95;
  const double _t97 = _t42*_t47;
  const double _t98 = _t45*_t48;
  const double _t99 = _t98*params->a[4];
  const double _t100 = 0.5e1*_t8;
  const double _t101 = _t98*params->a[5];
  const double _t102 = _t50*_t51;
  const double _t103 = 0.6e1*_t8;
  const double _t104 = _t51*params->a[6];
  const double _t105 = _t104*_t49;
  const double _t106 = _t53*_t54;
  const double _t107 = 0.7e1*_t8;
  const double _t108 = _t54*params->a[7];
  const double _t109 = _t108*_t52;
  const double _t110 = _t56*_t57;
  const double _t111 = 0.8e1*_t8;
  const double _t112 = _t57*params->a[8];
  const double _t113 = _t112*_t55;
  const double _t114 = _t59*_t60;
  const double _t115 = 0.9e1*_t8;
  const double _t116 = _t60*params->a[9];
  const double _t117 = _t116*_t58;
  const double _t118 = _t33*_t62;
  const double _t119 = -_t100*_t101 - _t100*_t102 - _t103*_t105 - _t103*_t106 - _t107*_t109 - _t107*_t110 - _t111*_t113 - _t111*_t114 - _t115*_t117 - _t115*_t118 - _t32*_t8 - 0.2e1*_t41*_t81 - _t68*_t92 - _t75*_t97 - _t75*_t99 - _t80*_t81 - _t82*_t84 - _t82*_t85 - _t86*_t88 - _t86*_t90 - _t93*_t94 - _t93*_t96;
  const double _t120 = _t119*_t27 + _t17*_t76 - 0.0037345199999999999*_t66*_t8 + _t67*_t68 - _t69*_t70 - _t78*_t79;
  const double _t122 = _t14*_t6;
  const double _t123 = _t122*params->d[0];
  const double _t124 = _t6*_t69;
  const double _t125 = _t20*_t71 + _t21*_t6;
  const double _t126 = 0.0056017799999999998*_t6;
  const double _t127 = _t23*_t26;
  const double _t128 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t129 = (0.1e1 / (_t25 * _t25));
  const double _t130 = _t10*_t128*_t129;
  const double _t131 = _t130*_t19;
  const double _t132 = 0.0073537515876113235*_t127*_t6 - 6.7260774144646838e-5*_t131*sigma_ss;
  const double _t133 = _t122*params->d[1] - 0.0018672599999999999*_t123 - 0.0037345199999999999*_t124 + _t125*_t17 - _t126*_t78 + _t132*_t63;
  const double _t135 = xc_powr(n_s, -4, 3);
  const double _t139 = xc_powr(n_s, -11, 3);
  const double _t140 = _t139*sigma_ss;
  const double _t141 = _t6*tau_s;
  const double _t142 = 0.0049793599999999995*_t140 + 0.0062242*_t141;
  const double _t143 = (0.8e1 / 0.3e1)*params->d[1];
  const double _t144 = (0.10e2 / 0.3e1)*params->d[2];
  const double _t145 = -_t140*_t143 - _t141*_t144;
  const double _t146 = 0.009958719999999999*_t140 + 0.0124484*_t141;
  const double _t147 = 0.014938079999999999*_t140 + 0.018672600000000001*_t141;
  const double _t148 = _t147*_t77;
  const double _t149 = _t19*params->d[4];
  const double _t150 = _t149*sigma_ss;
  const double _t151 = (0.10e2 / 0.3e1)*tau_s;
  const double _t152 = xc_powr(n_s, -19, 3);
  const double _t153 = _t152*params->d[3];
  const double _t154 = (0.8e1 / 0.3e1)*_t21;
  const double _t155 = (0.20e2 / 0.3e1)*_t74;
  const double _t156 = -_t140*_t154 - _t141*_t155 - _t150*_t151 - 0.16e2 / 0.3e1*_t153*_t18;
  const double _t157 = 0.019610004233630196*_t127;
  const double _t158 = 0.0001793620643857249*_t10*_t128*_t129*_t152*_t18 - _t140*_t157;
  const double _t159 = _t141*_t29;
  const double _t160 = (0.50e2 / 0.3e1)*_t141;
  const double _t161 = (0.55e2 / 0.3e1)*_t141;
  const double _t162 = 0.5e1*_t141;
  const double _t163 = (0.20e2 / 0.3e1)*_t141;
  const double _t164 = (0.25e2 / 0.3e1)*_t141;
  const double _t165 = 0.10e2*_t141;
  const double _t166 = (0.35e2 / 0.3e1)*_t141;
  const double _t167 = (0.40e2 / 0.3e1)*_t141;
  const double _t168 = 0.15e2*_t141;
  const double _t169 = _t101*_t164 + _t102*_t164 + _t105*_t165 + _t106*_t165 + _t109*_t166 + _t110*_t166 + _t113*_t167 + _t114*_t167 + _t117*_t168 + _t118*_t168 + (0.5e1 / 0.3e1)*_t141*_t32 + (0.10e2 / 0.3e1)*_t141*_t92 + (0.10e2 / 0.3e1)*_t159*_t41 + (0.5e1 / 0.3e1)*_t159*_t80 + _t160*_t84 + _t160*_t85 + _t161*_t88 + _t161*_t90 + _t162*_t94 + _t162*_t96 + _t163*_t97 + _t163*_t99;
  const double _t170 = _t14*_t145 + _t142*_t66 + _t146*_t69 + _t148*_t22 + _t156*_t17 + _t158*_t63 + _t169*_t27;
#endif
#if _KMAX >= 2
  const double _t172 = xc_powr(n_s, -10, 3);
  const double _t173 = _t17*_t172;
  const double _t174 = 0.8e1*params->d[5];
  const double _t175 = _t16*_t77;
  const double _t176 = 8.3679837782399996e-5*_t172;
  const double _t177 = _t76*_t77;
  const double _t178 = 0.022407119999999999*_t8;
  const double _t179 = xc_powi(_t13, -5);
  const double _t180 = _t179*_t22;
  const double _t181 = 0.00016735967556479999*_t172;
  const double _t182 = 0.2e1*_t172;
  const double _t183 = _t43*params->a[1];
  const double _t184 = _t183*_t29;
  const double _t185 = _t172*_t29;
  const double _t186 = 0.6e1*_t44;
  const double _t187 = 0.90e2*_t172;
  const double _t188 = _t58*_t83;
  const double _t189 = _t61*params->a[10];
  const double _t190 = _t189*_t36;
  const double _t191 = 0.110e3*_t172;
  const double _t192 = _t35*_t89;
  const double _t193 = _t61*_t87;
  const double _t194 = _t34*params->a[11];
  const double _t195 = _t194*_t89;
  const double _t196 = xc_powi(_t30, -13);
  const double _t197 = _t196*_t38;
  const double _t198 = _t46*params->a[2];
  const double _t199 = _t172*_t39;
  const double _t200 = _t48*params->a[3];
  const double _t201 = _t172*_t42;
  const double _t202 = _t201*_t48;
  const double _t203 = _t172*_t45;
  const double _t204 = _t51*params->a[4];
  const double _t205 = _t51*params->a[5];
  const double _t206 = _t172*_t54;
  const double _t207 = _t49*params->a[6];
  const double _t208 = 0.42e2*_t172;
  const double _t209 = _t53*_t57;
  const double _t210 = _t108*_t49;
  const double _t211 = _t52*params->a[7];
  const double _t212 = _t211*_t57;
  const double _t213 = 0.56e2*_t172;
  const double _t214 = _t56*_t60;
  const double _t215 = _t112*_t52;
  const double _t216 = _t55*params->a[8];
  const double _t217 = _t216*_t60;
  const double _t218 = 0.72e2*_t172;
  const double _t219 = _t33*_t59;
  const double _t220 = _t116*_t55;
  const double _t221 = _t58*params->a[9];
  const double _t222 = _t221*_t33;
  const double _t223 = _t36*_t62;
  const double _t224 = 0.30e2*_t104*_t203 + 0.200e3*_t172*_t190 + 0.242e3*_t172*_t195 + 0.132e3*_t172*_t197 + 0.98e2*_t172*_t212 + 0.128e3*_t172*_t217 + 0.162e3*_t172*_t222 + _t182*_t184 + _t182*_t41 + _t182*_t80 + _t185*_t186 + 0.8e1*_t185*_t91 + _t187*_t188 + _t187*_t223 + _t191*_t192 + _t191*_t193 + 0.6e1*_t198*_t199 + 0.12e2*_t199*_t47 + 0.18e2*_t199*_t95 + 0.12e2*_t200*_t201 + 0.32e2*_t202*params->a[4] + 0.20e2*_t202*params->a[5] + 0.20e2*_t203*_t204 + 0.50e2*_t203*_t205 + 0.72e2*_t206*_t207 + 0.30e2*_t206*_t50 + _t208*_t209 + _t208*_t210 + _t213*_t214 + _t213*_t215 + _t218*_t219 + _t218*_t220;
  const double _t225 = _t173*_t174 + 2.7893279260799996e-5*_t173*params->d[0] - 0.029876159999999999*_t173*params->d[2] + _t175*_t176 - _t177*_t178 + _t180*_t181 + _t224*_t27;
  const double _t227 = _t17*_t72;
  const double _t228 = _t227*params->d[0];
  const double _t229 = 0.0074690399999999997*_t227;
  const double _t230 = 0.2e1*_t17;
  const double _t231 = _t175*_t72;
  const double _t232 = _t125*_t77;
  const double _t233 = _t180*_t72;
  const double _t234 = _t119*_t132 - _t126*_t177 + 1.3946639630399998e-5*_t228 - _t229*params->d[1] - _t229*params->d[2] + _t230*_t73 + 4.1839918891199998e-5*_t231 - _t232*_t79 + 8.3679837782399996e-5*_t233;
  const double _t236 = _t17*_t19;
  const double _t237 = _t236*params->d[0];
  const double _t238 = _t236*params->d[1];
  const double _t239 = _t175*_t19;
  const double _t240 = _t232*_t6;
  const double _t241 = 4.1839918891199998e-5*_t19;
  const double _t242 = xc_powi(n_s, -8);
  const double _t243 = 0.1e1/((M_PI * M_PI * M_PI * M_PI)*(_t25 * _t25 * _t25));
  const double _t244 = _t242*_t243;
  const double _t245 = -0.00013452154828929368*_t131 + 7.3823735022412434e-6*_t244*sigma_ss;
  const double _t246 = _t180*_t241 + _t20*_t230 + 6.9733198151999991e-6*_t237 - 0.0074690399999999997*_t238 + 2.0919959445599999e-5*_t239 - 0.01120356*_t240 + _t245*_t63;
  const double _t248 = _t142*params->d[0];
  const double _t249 = _t17*_t248;
  const double _t250 = _t146*_t17;
  const double _t251 = _t68*params->d[2];
  const double _t252 = _t145*_t17;
  const double _t253 = params->d[5]*tau_s;
  const double _t254 = (0.40e2 / 0.3e1)*_t72;
  const double _t255 = -0.26e2 / 0.3e1*_t150 - _t155*_t6 - _t253*_t254;
  const double _t256 = _t146*_t175;
  const double _t257 = 0.018672600000000001*_t6;
  const double _t258 = _t147*_t180;
  const double _t259 = 0.014938079999999999*_t8;
  const double _t260 = _t156*_t77;
  const double _t261 = _t151*_t72;
  const double _t262 = _t29*_t91;
  const double _t263 = _t262*tau_s;
  const double _t264 = _t29*_t72;
  const double _t265 = _t264*_t44;
  const double _t266 = 0.10e2*tau_s;
  const double _t267 = _t72*tau_s;
  const double _t268 = 0.150e3*_t267;
  const double _t269 = _t190*_t72;
  const double _t270 = (0.550e3 / 0.3e1)*_t267;
  const double _t271 = _t195*_t72;
  const double _t272 = _t197*_t72;
  const double _t273 = _t39*_t72;
  const double _t274 = _t273*_t95;
  const double _t275 = _t42*_t72;
  const double _t276 = _t200*_t275;
  const double _t277 = 0.20e2*_t273;
  const double _t278 = _t47*tau_s;
  const double _t279 = _t48*params->a[4];
  const double _t280 = _t275*_t279;
  const double _t281 = _t45*_t72;
  const double _t282 = _t204*_t281;
  const double _t283 = (0.100e3 / 0.3e1)*tau_s;
  const double _t284 = _t48*params->a[5];
  const double _t285 = _t275*_t284;
  const double _t286 = _t205*_t281;
  const double _t287 = _t50*_t54;
  const double _t288 = 0.50e2*_t267;
  const double _t289 = _t104*_t45;
  const double _t290 = _t207*_t54;
  const double _t291 = 0.120e3*_t267;
  const double _t292 = 0.70e2*_t267;
  const double _t293 = _t212*_t72;
  const double _t294 = (0.280e3 / 0.3e1)*_t267;
  const double _t295 = _t217*_t72;
  const double _t296 = _t222*_t72;
  const double _t297 = -_t184*_t261 - _t188*_t268 - _t192*_t270 - _t193*_t270 - _t198*_t266*_t273 - _t209*_t292 - _t210*_t292 - _t214*_t294 - _t215*_t294 - _t219*_t291 - _t220*_t291 - _t223*_t268 - _t254*_t263 - _t261*_t41 - _t261*_t80 - _t265*_t266 - 0.1000e4 / 0.3e1*_t269*tau_s - 0.1210e4 / 0.3e1*_t271*tau_s - 0.220e3*_t272*tau_s - 0.30e2*_t274*tau_s - 0.20e2*_t276*tau_s - _t277*_t278 - 0.160e3 / 0.3e1*_t280*tau_s - _t282*_t283 - _t283*_t285 - 0.250e3 / 0.3e1*_t286*tau_s - _t287*_t288 - _t288*_t289 + (0.5e1 / 0.3e1)*_t29*_t40*_t6*params->a[1] + (0.10e2 / 0.3e1)*_t29*_t40*_t6*params->a[2] - _t290*_t291 - 0.490e3 / 0.3e1*_t293*tau_s - 0.640e3 / 0.3e1*_t295*tau_s - 0.270e3*_t296*tau_s + (0.5e1 / 0.3e1)*_t31*_t6*params->a[1] + (0.50e2 / 0.3e1)*_t33*_t6*_t61*params->a[10] + 0.15e2*_t33*_t6*_t61*params->a[9] + (0.50e2 / 0.3e1)*_t34*_t36*_t6*params->a[10] + (0.55e2 / 0.3e1)*_t34*_t36*_t6*params->a[11] + (0.55e2 / 0.3e1)*_t37*_t6*_t89*params->a[11] + (0.10e2 / 0.3e1)*_t39*_t43*_t6*params->a[2] + 0.5e1*_t39*_t43*_t6*params->a[3] + 0.5e1*_t42*_t46*_t6*params->a[3] + (0.20e2 / 0.3e1)*_t42*_t46*_t6*params->a[4] + (0.20e2 / 0.3e1)*_t45*_t48*_t6*params->a[4] + (0.25e2 / 0.3e1)*_t45*_t48*_t6*params->a[5] + (0.25e2 / 0.3e1)*_t49*_t51*_t6*params->a[5] + 0.10e2*_t49*_t51*_t6*params->a[6] + 0.10e2*_t52*_t54*_t6*params->a[6] + (0.35e2 / 0.3e1)*_t52*_t54*_t6*params->a[7] + (0.35e2 / 0.3e1)*_t55*_t57*_t6*params->a[7] + (0.40e2 / 0.3e1)*_t55*_t57*_t6*params->a[8] + (0.40e2 / 0.3e1)*_t58*_t6*_t60*params->a[8] + 0.15e2*_t58*_t6*_t60*params->a[9];
  const double _t298 = _t119*_t158 - _t122*_t144 + 0.0062242*_t123 + 0.0124484*_t124 + _t148*_t76 + _t17*_t255 - _t249*_t70 + _t250*_t251 - _t252*_t70 - _t256*_t79 + _t257*_t78 - _t258*_t259 - _t260*_t79 + _t27*_t297;
  const double _t300 = _t139*_t66;
  const double _t301 = _t6*params->d[1];
  const double _t302 = 0.0037345199999999999*_t6;
  const double _t303 = _t252*_t6;
  const double _t304 = _t139*_t69;
  const double _t305 = (0.32e2 / 0.3e1)*_t153;
  const double _t306 = -_t139*_t154 - _t149*_t151 - _t305*sigma_ss;
  const double _t307 = 0.014938079999999999*_t139;
  const double _t308 = 0.0074690399999999997*_t6;
  const double _t309 = xc_powi(n_s, -9);
  const double _t310 = _t243*_t309;
  const double _t311 = 0.0005380861931571747*_t10*_t128*_t129*_t152*sigma_ss - _t139*_t157 - 1.9686329339309982e-5*_t18*_t310;
  const double _t312 = _t125*_t148 - _t126*_t256 - _t126*_t260 + _t132*_t169 - _t139*_t14*_t143 + _t17*_t306 - _t249*_t302 + _t250*_t301 - _t258*_t308 + 0.0049793599999999995*_t300 - 0.0037345199999999999*_t303 + 0.009958719999999999*_t304 + _t307*_t78 + _t311*_t63;
  const double _t314 = (0.2e1 / 0.9e1)*_t64;
  const double _t315 = xc_powr(n_s, -7, 3);
  const double _t317 = (0.1e1 / 0.36e2)*_t64;
  const double _t318 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t322 = xc_powr(n_s, -14, 3);
  const double _t323 = _t322*sigma_ss;
  const double _t324 = _t139*tau_s;
  const double _t325 = -0.018257653333333332*_t323 - 0.016597866666666666*_t324;
  const double _t326 = (0.88e2 / 0.9e1)*params->d[1];
  const double _t327 = (0.80e2 / 0.9e1)*_t324;
  const double _t328 = _t323*_t326 + _t327*params->d[2];
  const double _t329 = _t145*_t146;
  const double _t330 = -0.036515306666666664*_t323 - 0.033195733333333331*_t324;
  const double _t331 = _t146*_t16;
  const double _t332 = -0.054772959999999996*_t323 - 0.0497936*_t324;
  const double _t333 = _t332*_t77;
  const double _t334 = _t152*params->d[4];
  const double _t335 = _t334*sigma_ss;
  const double _t336 = (0.80e2 / 0.3e1)*tau_s;
  const double _t337 = xc_powr(n_s, -22, 3);
  const double _t338 = _t337*params->d[3];
  const double _t339 = (tau_s * tau_s);
  const double _t340 = _t339*params->d[5];
  const double _t341 = (0.200e3 / 0.9e1)*_t19;
  const double _t342 = (0.88e2 / 0.9e1)*_t21;
  const double _t343 = (0.160e3 / 0.9e1)*_t74;
  const double _t344 = (0.304e3 / 0.9e1)*_t18*_t338 + _t323*_t342 + _t324*_t343 + _t335*_t336 + _t340*_t341;
  const double _t345 = 0.019917439999999998*_t140 + 0.0248968*_t141;
  const double _t346 = _t147*_t345;
  const double _t347 = 0.2e1*_t148;
  const double _t348 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t349 = _t243/xc_powi(n_s, 10);
  const double _t350 = 0.071903348856644053*_t127;
  const double _t351 = _t130*_t337;
  const double _t352 = -0.0016142585794715241*_t18*_t351 + _t323*_t350 + 5.2496878238159953e-5*_t348*_t349;
  const double _t353 = 0.2e1*_t158;
  const double _t354 = (0.40e2 / 0.9e1)*_t32;
  const double _t355 = (0.50e2 / 0.9e1)*_t339;
  const double _t356 = _t29*_t80;
  const double _t357 = (0.40e2 / 0.9e1)*_t356;
  const double _t358 = _t29*_t41;
  const double _t359 = _t262*_t339;
  const double _t360 = _t19*_t29;
  const double _t361 = _t360*_t44;
  const double _t362 = (0.50e2 / 0.3e1)*_t339;
  const double _t363 = (0.400e3 / 0.9e1)*_t324;
  const double _t364 = (0.440e3 / 0.9e1)*_t324;
  const double _t365 = (0.40e2 / 0.3e1)*_t324;
  const double _t366 = (0.160e3 / 0.9e1)*_t324;
  const double _t367 = (0.200e3 / 0.9e1)*_t324;
  const double _t368 = (0.80e2 / 0.3e1)*_t324;
  const double _t369 = (0.280e3 / 0.9e1)*_t324;
  const double _t370 = (0.320e3 / 0.9e1)*_t324;
  const double _t371 = 0.40e2*_t324;
  const double _t372 = _t19*_t339;
  const double _t373 = 0.250e3*_t372;
  const double _t374 = _t19*_t190;
  const double _t375 = (0.2750e4 / 0.9e1)*_t372;
  const double _t376 = _t19*_t195;
  const double _t377 = _t19*_t197;
  const double _t378 = _t19*_t39;
  const double _t379 = _t198*_t378;
  const double _t380 = _t378*_t95;
  const double _t381 = _t19*_t42;
  const double _t382 = _t200*_t381;
  const double _t383 = (0.100e3 / 0.3e1)*_t339;
  const double _t384 = _t378*_t47;
  const double _t385 = _t279*_t381;
  const double _t386 = _t19*_t45;
  const double _t387 = _t204*_t386;
  const double _t388 = (0.500e3 / 0.9e1)*_t339;
  const double _t389 = _t284*_t381;
  const double _t390 = _t205*_t386;
  const double _t391 = (0.250e3 / 0.3e1)*_t372;
  const double _t392 = 0.200e3*_t372;
  const double _t393 = (0.350e3 / 0.3e1)*_t372;
  const double _t394 = _t19*_t212;
  const double _t395 = (0.1400e4 / 0.9e1)*_t372;
  const double _t396 = _t19*_t217;
  const double _t397 = _t19*_t222;
  const double _t398 = -_t101*_t367 - _t102*_t367 - _t105*_t368 - _t106*_t368 - _t109*_t369 - _t110*_t369 - _t113*_t370 - _t114*_t370 - _t117*_t371 - _t118*_t371 + _t184*_t19*_t355 + _t188*_t373 + _t19*_t355*_t41 + _t19*_t355*_t80 + _t192*_t375 + _t193*_t375 + _t209*_t393 + _t210*_t393 + _t214*_t395 + _t215*_t395 + _t219*_t392 + _t220*_t392 + _t223*_t373 + _t287*_t391 + _t289*_t391 + _t290*_t392 - _t324*_t354 - _t324*_t357 - _t327*_t358 - _t327*_t92 + (0.5000e4 / 0.9e1)*_t339*_t374 + (0.6050e4 / 0.9e1)*_t339*_t376 + (0.1100e4 / 0.3e1)*_t339*_t377 + 0.50e2*_t339*_t380 + (0.800e3 / 0.9e1)*_t339*_t385 + (0.1250e4 / 0.9e1)*_t339*_t390 + (0.2450e4 / 0.9e1)*_t339*_t394 + (0.3200e4 / 0.9e1)*_t339*_t396 + 0.450e3*_t339*_t397 + _t341*_t359 + _t361*_t362 + _t362*_t379 - _t363*_t84 - _t363*_t85 - _t364*_t88 - _t364*_t90 - _t365*_t94 - _t365*_t96 - _t366*_t97 - _t366*_t99 + _t382*_t383 + _t383*_t384 + _t387*_t388 + _t388*_t389;
  const double _t399 = _t14*_t328 + _t148*_t331 + _t156*_t347 + _t169*_t353 + _t17*_t344 + _t180*_t346 + _t22*_t333 + _t230*_t329 + _t248*_t250 + _t27*_t398 + _t325*_t66 + _t330*_t69 + _t352*_t63;
#endif
#if _KMAX >= 3
  const double _t401 = xc_powi(n_s, -5);
  const double _t402 = _t401*_t77;
  const double _t403 = _t16*_t179;
  const double _t404 = 1.2500161111805137e-6*_t401;
  const double _t405 = xc_powi(_t13, -6);
  const double _t406 = _t22*_t405;
  const double _t407 = 3.1250402779512841e-6*_t401;
  const double _t408 = _t401*_t43;
  const double _t409 = 0.6e1*params->a[1];
  const double _t410 = _t29*_t401;
  const double _t411 = _t55*_t83;
  const double _t412 = _t36*_t401;
  const double _t413 = _t58*params->a[10];
  const double _t414 = _t401*_t89;
  const double _t415 = _t196*_t401;
  const double _t416 = _t58*_t87;
  const double _t417 = _t61*params->a[11];
  const double _t418 = xc_powi(_t30, -14);
  const double _t419 = _t38*_t418;
  const double _t420 = _t39*_t401;
  const double _t421 = _t420*_t48;
  const double _t422 = _t401*_t42;
  const double _t423 = _t51*params->a[3];
  const double _t424 = _t401*_t45;
  const double _t425 = _t424*_t54;
  const double _t426 = _t401*_t57;
  const double _t427 = _t54*params->a[6];
  const double _t428 = _t401*_t60;
  const double _t429 = _t49*params->a[7];
  const double _t430 = _t33*_t401;
  const double _t431 = _t112*_t49;
  const double _t432 = _t52*params->a[8];
  const double _t433 = _t116*_t52;
  const double _t434 = _t55*params->a[9];
  const double _t435 = -0.120e3*_t104*_t422 - 0.210e3*_t108*_t424 - _t186*_t401 - 0.3300e4*_t189*_t414 - 0.4356e4*_t194*_t415 - 0.36e2*_t198*_t410 - 0.108e3*_t200*_t420 - 0.240e3*_t204*_t422 - 0.300e3*_t205*_t422 - 0.756e3*_t207*_t426 - 0.1176e4*_t211*_t428 - 0.1728e4*_t216*_t430 - 0.2430e4*_t221*_t412 - 0.144e3*_t279*_t420 - 0.1320e4*_t35*_t415 - 0.720e3*_t401*_t411 - 0.990e3*_t401*_t416 - 0.1716e4*_t401*_t419 - 0.336e3*_t401*_t431 - 0.504e3*_t401*_t433 - _t408*_t409 - 0.12e2*_t408*params->a[2] - _t409*_t410*_t46 - 0.24e2*_t410*_t47 - 0.54e2*_t410*_t95 - 0.2700e4*_t412*_t413 - 0.720e3*_t412*_t59 - 0.3630e4*_t414*_t417 - 0.990e3*_t414*_t62 - 0.24e2*_t421*params->a[2] - 0.60e2*_t421*params->a[5] - 0.60e2*_t422*_t423 - 0.540e3*_t424*_t427 - 0.120e3*_t425*params->a[4] - 0.450e3*_t425*params->a[5] - 0.882e3*_t426*_t429 - 0.210e3*_t426*_t50 - 0.1344e4*_t428*_t432 - 0.336e3*_t428*_t53 - 0.1944e4*_t430*_t434 - 0.504e3*_t430*_t56;
  const double _t436 = 0.00050207902669439995*_t172*_t179*_t76 + _t27*_t435 + 0.00050207902669439995*_t401*_t77*params->d[2] - 3.1250402779512838e-7*_t402*params->d[0] - 0.26888543999999998*_t402*params->d[5] - _t403*_t404 - _t406*_t407;
  const double _t438 = xc_powi(n_s, -6);
  const double _t439 = _t438*_t77;
  const double _t440 = _t439*params->d[0];
  const double _t441 = 8.3679837782399996e-5*params->d[1];
  const double _t442 = _t439*params->d[2];
  const double _t443 = 0.044814239999999998*_t439;
  const double _t444 = _t403*_t438;
  const double _t445 = _t125*_t179;
  const double _t446 = _t179*_t76;
  const double _t447 = 0.00016735967556479999*_t72;
  const double _t448 = _t406*_t438;
  const double _t449 = _t132*_t224 + _t181*_t445 + _t439*_t441 - 1.5625201389756419e-7*_t440 + 0.00016735967556479999*_t442 - _t443*params->d[4] - _t443*params->d[5] - 6.2500805559025686e-7*_t444 + _t446*_t447 - 1.5625201389756421e-6*_t448;
  const double _t451 = xc_powi(n_s, -7);
  const double _t452 = _t451*_t77;
  const double _t453 = _t452*params->d[0];
  const double _t454 = _t452*params->d[2];
  const double _t455 = 0.022407119999999999*_t452;
  const double _t456 = _t403*_t451;
  const double _t457 = _t406*_t451;
  const double _t458 = _t119*_t245 + _t241*_t446 + _t441*_t452 + _t445*_t447 - 7.8126006948782095e-8*_t453 + 4.1839918891199998e-5*_t454 - _t455*params->d[3] - _t455*params->d[4] - 3.1250402779512843e-7*_t456 - 7.8126006948782103e-7*_t457;
  const double _t460 = _t242*_t77;
  const double _t461 = _t460*params->d[0];
  const double _t462 = _t460*params->d[3];
  const double _t463 = _t242*_t403;
  const double _t464 = 3.9063003474391051e-7*_t242;
  const double _t465 = xc_powr(n_s, -32, 3);
  const double _t466 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t467 = (0.1e1 / (_t25 * _t25 * _t25 * _t25));
  const double _t468 = _t1*_t466*_t467;
  const double _t469 = _t465*_t468;
  const double _t470 = 2.214712050672373e-5*_t244 - 2.0256768978524741e-7*_t469*sigma_ss;
  const double _t471 = 0.00012551975667359999*_t125*_t179*_t19 + 6.2759878336799993e-5*_t242*_t77*params->d[1] - _t406*_t464 - 3.9063003474391047e-8*_t461 - 0.033610679999999997*_t462 - 1.5625201389756422e-7*_t463 + _t470*_t63;
  const double _t473 = _t248*_t77;
  const double _t474 = _t146*_t77;
  const double _t475 = _t474*params->d[2];
  const double _t476 = 0.044814239999999998*_t172;
  const double _t477 = _t172*_t174;
  const double _t478 = _t145*_t77;
  const double _t479 = 0.037345200000000002*_t6;
  const double _t480 = _t255*_t77;
  const double _t481 = _t179*_t331;
  const double _t482 = _t147*_t446;
  const double _t483 = 0.029876159999999999*_t8;
  const double _t484 = _t147*_t406;
  const double _t485 = 0.00027893279260799998*_t172;
  const double _t486 = _t156*_t179;
  const double _t487 = (0.20e2 / 0.3e1)*_t72;
  const double _t488 = _t438*tau_s;
  const double _t489 = 0.10e2*_t488;
  const double _t490 = _t46*params->a[1];
  const double _t491 = _t29*_t490;
  const double _t492 = _t198*_t29;
  const double _t493 = _t29*_t488;
  const double _t494 = 0.40e2*_t47;
  const double _t495 = 0.300e3*_t72;
  const double _t496 = (0.1100e4 / 0.3e1)*_t72;
  const double _t497 = 0.100e3*_t72;
  const double _t498 = 0.240e3*_t72;
  const double _t499 = 0.140e3*_t72;
  const double _t500 = (0.560e3 / 0.3e1)*_t72;
  const double _t501 = 0.1200e4*_t488;
  const double _t502 = _t36*_t488;
  const double _t503 = _t488*_t89;
  const double _t504 = _t196*_t488;
  const double _t505 = 0.1650e4*_t488;
  const double _t506 = _t39*params->a[2];
  const double _t507 = _t48*_t506;
  const double _t508 = _t39*_t488;
  const double _t509 = _t42*_t423;
  const double _t510 = 0.100e3*_t488;
  const double _t511 = _t42*_t488;
  const double _t512 = _t45*params->a[4];
  const double _t513 = _t512*_t54;
  const double _t514 = 0.200e3*_t488;
  const double _t515 = _t284*_t39;
  const double _t516 = _t45*params->a[5];
  const double _t517 = _t516*_t54;
  const double _t518 = _t50*_t57;
  const double _t519 = 0.350e3*_t488;
  const double _t520 = _t104*_t42;
  const double _t521 = _t427*_t45;
  const double _t522 = _t488*_t57;
  const double _t523 = _t53*_t60;
  const double _t524 = 0.560e3*_t488;
  const double _t525 = _t108*_t45;
  const double _t526 = _t488*_t60;
  const double _t527 = _t33*_t56;
  const double _t528 = 0.840e3*_t488;
  const double _t529 = _t33*_t488;
  const double _t530 = _t36*_t59;
  const double _t531 = _t62*_t89;
  const double _t532 = _t183*_t489 - _t184*_t487 - _t188*_t495 + 0.5500e4*_t189*_t503 - _t192*_t496 - _t193*_t496 + 0.7260e4*_t194*_t504 - _t198*_t277 + 0.180e3*_t200*_t508 + 0.400e3*_t204*_t511 + 0.500e3*_t205*_t511 + 0.1260e4*_t207*_t522 - _t209*_t499 - _t210*_t499 + 0.1960e4*_t211*_t526 - _t214*_t500 - _t215*_t500 + 0.2880e4*_t216*_t529 - _t219*_t498 - _t220*_t498 + 0.4050e4*_t221*_t502 - _t223*_t495 - 0.80e2 / 0.3e1*_t264*_t91 - 0.20e2*_t265 - 0.2000e4 / 0.3e1*_t269 - 0.2420e4 / 0.3e1*_t271 - 0.440e3*_t272 - _t273*_t494 - 0.60e2*_t274 - 0.40e2*_t276 + 0.240e3*_t279*_t508 - 0.320e3 / 0.3e1*_t280 - 0.200e3 / 0.3e1*_t282 - 0.200e3 / 0.3e1*_t285 - 0.500e3 / 0.3e1*_t286 - _t287*_t497 - _t289*_t497 - _t290*_t498 - 0.980e3 / 0.3e1*_t293 - 0.1280e4 / 0.3e1*_t295 - 0.540e3*_t296 + 0.2200e4*_t35*_t504 - _t41*_t487 + _t411*_t501 + 0.4500e4*_t413*_t502 + _t416*_t505 + 0.6050e4*_t417*_t503 + 0.2860e4*_t419*_t488 + 0.1470e4*_t429*_t522 + _t431*_t524 + 0.2240e4*_t432*_t526 + _t433*_t528 + 0.3240e4*_t434*_t529 + 0.60e2*_t438*_t492*tau_s + _t44*_t489 - _t487*_t80 + 0.40e2*_t488*_t507 + 0.750e3*_t488*_t517 + 0.900e3*_t488*_t521 + 0.20e2*_t488*_t91 + _t489*_t491 + _t493*_t494 + 0.90e2*_t493*_t95 + _t501*_t530 + _t505*_t531 + _t509*_t510 + _t510*_t515 + _t513*_t514 + _t514*_t520 + _t518*_t519 + _t519*_t525 + _t523*_t524 + _t527*_t528;
  const double _t533 = _t148*_t477 + _t158*_t224 + _t176*_t473 + _t176*_t478 + _t177*_t479 - _t178*_t480 + _t181*_t481 + _t181*_t486 + 0.099587200000000001*_t227*params->d[2] - 0.80e2 / 0.3e1*_t227*params->d[5] - 9.2977597535999997e-5*_t228 - 0.00027893279260799998*_t231 - 0.00055786558521600006*_t233 + _t27*_t532 - _t475*_t476 - _t482*_t483 + _t484*_t485;
  const double _t535 = _t236*params->d[2];
  const double _t536 = 4.1839918891199998e-5*_t72;
  const double _t537 = 0.01120356*_t72;
  const double _t538 = _t474*params->d[1];
  const double _t539 = _t478*_t72;
  const double _t540 = _t306*_t77;
  const double _t541 = 8.3679837782399996e-5*_t72;
  const double _t542 = _t147*_t445;
  const double _t543 = _t180*_t19;
  const double _t544 = _t484*_t72;
  const double _t545 = _t486*_t72;
  const double _t546 = _t119*_t311 - _t126*_t480 + _t132*_t297 + _t177*_t307 - 0.26e2 / 0.3e1*_t236*params->d[4] - 6.0435438398399993e-5*_t237 + 0.03236584*_t238 - 0.00018130631519519997*_t239 + 0.018672600000000001*_t240 - _t259*_t542 - _t308*_t482 + _t347*_t73 + _t473*_t536 - _t475*_t537 + _t481*_t541 + 0.03236584*_t535 - _t537*_t538 + 4.1839918891199998e-5*_t539 - _t540*_t79 - 0.00036261263039039999*_t543 + 0.00013946639630399999*_t544 + 8.3679837782399996e-5*_t545;
  const double _t548 = _t152*_t17;
  const double _t549 = _t548*params->d[0];
  const double _t550 = _t548*params->d[1];
  const double _t551 = 2.0919959445599999e-5*_t19;
  const double _t552 = _t19*_t538;
  const double _t553 = _t19*_t478;
  const double _t554 = _t152*_t175;
  const double _t555 = 0.029876159999999999*_t139;
  const double _t556 = 0.01120356*_t6;
  const double _t557 = 0.014938079999999999*_t6;
  const double _t558 = 0.00022314623408639997*_t152;
  const double _t559 = 6.9733198151999994e-5*_t19;
  const double _t560 = xc_powr(n_s, -35, 3);
  const double _t561 = 0.0007174482575428996*_t130*_t152 + 5.4018050609399309e-7*_t18*_t468*_t560 - 9.8431646696549911e-5*_t310*sigma_ss;
  const double _t562 = _t169*_t245 - _t17*_t305 - _t180*_t558 + _t20*_t347 + _t232*_t555 + _t241*_t481 + _t241*_t486 + _t473*_t551 + _t484*_t559 - _t540*_t556 - _t542*_t557 - 3.7191039014399997e-5*_t549 + 0.039834879999999996*_t550 - 0.01120356*_t552 + 2.0919959445599999e-5*_t553 - 0.00011157311704319999*_t554 + _t561*_t63;
  const double _t566 = (0.80e2 / 0.9e1)*_t139;
  const double _t567 = 0.0124484*_t6;
  const double _t568 = _t250*params->d[0];
  const double _t569 = 0.0062242*_t6;
  const double _t570 = _t325*params->d[0];
  const double _t571 = _t17*_t570;
  const double _t572 = _t250*params->d[2];
  const double _t573 = _t17*_t330;
  const double _t574 = _t17*_t328;
  const double _t575 = _t146*_t473;
  const double _t576 = _t146*_t148;
  const double _t577 = _t329*_t77;
  const double _t578 = _t139*_t343 + 0.80e2*_t19*_t253 + (0.416e3 / 0.9e1)*_t335;
  const double _t579 = _t148*_t16;
  const double _t580 = _t175*_t330;
  const double _t581 = _t147*_t481;
  const double _t582 = 0.0497936*_t139;
  const double _t583 = 0.0248968*_t6;
  const double _t584 = _t180*_t345;
  const double _t585 = _t180*_t332;
  const double _t586 = _t344*_t77;
  const double _t587 = _t346*_t406;
  const double _t588 = 0.018672599999999998*_t8;
  const double _t589 = _t147*_t486;
  const double _t590 = _t339*_t451;
  const double _t591 = (0.50e2 / 0.3e1)*_t590;
  const double _t592 = (0.400e3 / 0.9e1)*_t139;
  const double _t593 = (0.440e3 / 0.9e1)*_t139;
  const double _t594 = (0.40e2 / 0.3e1)*_t139;
  const double _t595 = (0.160e3 / 0.9e1)*_t139;
  const double _t596 = (0.200e3 / 0.9e1)*_t139;
  const double _t597 = (0.80e2 / 0.3e1)*_t139;
  const double _t598 = (0.280e3 / 0.9e1)*_t139;
  const double _t599 = (0.320e3 / 0.9e1)*_t139;
  const double _t600 = 0.40e2*_t139;
  const double _t601 = _t29*_t95;
  const double _t602 = _t29*_t47;
  const double _t603 = (0.200e3 / 0.3e1)*_t590;
  const double _t604 = 0.2000e4*_t590;
  const double _t605 = _t36*_t590;
  const double _t606 = _t590*_t89;
  const double _t607 = _t196*_t590;
  const double _t608 = 0.2750e4*_t590;
  const double _t609 = _t39*_t590;
  const double _t610 = (0.500e3 / 0.3e1)*_t590;
  const double _t611 = _t42*_t590;
  const double _t612 = (0.1000e4 / 0.3e1)*_t590;
  const double _t613 = (0.1750e4 / 0.3e1)*_t590;
  const double _t614 = _t57*_t590;
  const double _t615 = (0.2800e4 / 0.3e1)*_t590;
  const double _t616 = _t590*_t60;
  const double _t617 = 0.1400e4*_t590;
  const double _t618 = _t33*_t590;
  const double _t619 = -_t101*_t596 - _t102*_t596 - _t105*_t597 - _t106*_t597 - _t109*_t598 - _t110*_t598 - _t113*_t599 - _t114*_t599 - _t117*_t600 - _t118*_t600 - _t139*_t354 - _t139*_t357 - _t183*_t591 - 0.27500e5 / 0.3e1*_t189*_t606 + 0.1320e4*_t19*_t196*_t37*params->a[11]*tau_s + 0.20e2*_t19*_t29*_t43*params->a[1]*tau_s + 0.80e2*_t19*_t29*_t43*params->a[2]*tau_s + 0.60e2*_t19*_t29*_t43*params->a[3]*tau_s + 0.900e3*_t19*_t33*_t58*params->a[10]*tau_s + 0.720e3*_t19*_t33*_t58*params->a[8]*tau_s + 0.1620e4*_t19*_t33*_t58*params->a[9]*tau_s + 0.1100e4*_t19*_t34*_t89*params->a[10]*tau_s + 0.2420e4*_t19*_t34*_t89*params->a[11]*tau_s + 0.2000e4*_t19*_t36*_t61*params->a[10]*tau_s + 0.1100e4*_t19*_t36*_t61*params->a[11]*tau_s + 0.900e3*_t19*_t36*_t61*params->a[9]*tau_s + 0.60e2*_t19*_t39*_t46*params->a[2]*tau_s + 0.180e3*_t19*_t39*_t46*params->a[3]*tau_s + 0.120e3*_t19*_t39*_t46*params->a[4]*tau_s + 0.20e2*_t19*_t40*params->a[1]*tau_s + 0.20e2*_t19*_t40*params->a[2]*tau_s + 0.120e3*_t19*_t42*_t48*params->a[3]*tau_s + 0.320e3*_t19*_t42*_t48*params->a[4]*tau_s + 0.200e3*_t19*_t42*_t48*params->a[5]*tau_s + 0.200e3*_t19*_t45*_t51*params->a[4]*tau_s + 0.500e3*_t19*_t45*_t51*params->a[5]*tau_s + 0.300e3*_t19*_t45*_t51*params->a[6]*tau_s + 0.300e3*_t19*_t49*_t54*params->a[5]*tau_s + 0.720e3*_t19*_t49*_t54*params->a[6]*tau_s + 0.420e3*_t19*_t49*_t54*params->a[7]*tau_s + 0.420e3*_t19*_t52*_t57*params->a[6]*tau_s + 0.980e3*_t19*_t52*_t57*params->a[7]*tau_s + 0.560e3*_t19*_t52*_t57*params->a[8]*tau_s + 0.560e3*_t19*_t55*_t60*params->a[7]*tau_s + 0.1280e4*_t19*_t55*_t60*params->a[8]*tau_s + 0.720e3*_t19*_t55*_t60*params->a[9]*tau_s - 0.12100e5*_t194*_t607 - 0.300e3*_t200*_t609 - 0.2000e4 / 0.3e1*_t204*_t611 - 0.2500e4 / 0.3e1*_t205*_t611 - 0.2100e4*_t207*_t614 - 0.9800e4 / 0.3e1*_t211*_t616 - 0.4800e4*_t216*_t618 - 0.6750e4*_t221*_t605 - 0.400e3*_t279*_t609 - 0.11000e5 / 0.3e1*_t35*_t607 - _t358*_t566 - _t411*_t604 - 0.7500e4*_t413*_t605 - _t416*_t608 - 0.30250e5 / 0.3e1*_t417*_t606 - 0.14300e5 / 0.3e1*_t419*_t590 - 0.2450e4*_t429*_t614 - _t431*_t615 - 0.11200e5 / 0.3e1*_t432*_t616 - _t433*_t617 - 0.5400e4*_t434*_t618 - _t44*_t591 - _t491*_t591 - 0.100e3*_t492*_t590 - _t507*_t603 - _t509*_t610 - _t513*_t612 - _t515*_t610 - 0.1250e4*_t517*_t590 - _t518*_t613 - _t520*_t612 - 0.1500e4*_t521*_t590 - _t523*_t615 - _t525*_t613 - _t527*_t617 - _t530*_t604 - _t531*_t608 - _t566*_t92 - 0.150e3*_t590*_t601 - 0.100e3 / 0.3e1*_t590*_t91 - _t592*_t84 - _t592*_t85 - _t593*_t88 - _t593*_t90 - _t594*_t94 - _t594*_t96 - _t595*_t97 - _t595*_t99 - _t602*_t603;
  const double _t620 = _t119*_t352 + _t17*_t578 - _t178*_t577 + _t249*_t567 + _t251*_t573 + _t251*_t576 + _t255*_t347 + _t256*_t257 + _t257*_t584 + _t258*_t583 - _t259*_t581 - _t259*_t585 + _t260*_t479 + _t27*_t619 + _t297*_t353 - 0.016597866666666666*_t300 + 0.0248968*_t303 - 0.033195733333333331*_t304 + _t333*_t76 + _t346*_t446 - _t483*_t589 + _t566*_t67 + _t567*_t579 + _t568*_t569 - _t571*_t70 - 0.20e2 / 0.3e1*_t572*_t6 - _t574*_t70 - _t575*_t79 - _t580*_t79 - _t582*_t78 - _t586*_t79 - _t587*_t588;
  const double _t622 = _t322*_t66;
  const double _t623 = 0.009958719999999999*_t139;
  const double _t624 = _t139*_t568;
  const double _t625 = _t139*params->d[1];
  const double _t626 = _t139*_t252;
  const double _t627 = _t322*_t69;
  const double _t628 = (0.608e3 / 0.9e1)*_t338;
  const double _t629 = _t322*_t342 + _t334*_t336 + _t628*sigma_ss;
  const double _t630 = 0.054772959999999996*_t322;
  const double _t631 = 0.019917439999999998*_t139;
  const double _t632 = 0.0093362999999999988*_t6;
  const double _t633 = _t468/xc_powr(n_s, 38, 3);
  const double _t634 = 0.0003346675987682697*_t18*_t349 + _t322*_t350 - 1.4404813495839816e-6*_t348*_t633 - 0.0038861780616907062*_t351*sigma_ss;
  const double _t635 = 0.2e1*_t311;
  const double _t636 = _t125*_t333 - _t126*_t575 - _t126*_t580 - _t126*_t586 + _t132*_t398 + _t14*_t322*_t326 + _t169*_t635 + _t17*_t629 + _t249*_t623 - 0.16e2 / 0.3e1*_t250*_t625 + _t256*_t307 + _t258*_t631 + _t260*_t555 + _t301*_t573 + _t301*_t576 - _t302*_t571 - _t302*_t574 + _t306*_t347 + _t307*_t584 - _t308*_t581 - _t308*_t585 + _t346*_t445 - _t556*_t577 - _t557*_t589 + _t579*_t623 - _t587*_t632 - 0.018257653333333332*_t622 + 0.0049793599999999995*_t624 + 0.019917439999999998*_t626 - 0.036515306666666664*_t627 + _t63*_t634 - _t630*_t78;
  const double _t638 = (0.1e1 / M_PI);
  const double _t645 = xc_powr(n_s, -17, 3);
  const double _t646 = _t645*sigma_ss;
  const double _t647 = _t322*tau_s;
  const double _t648 = 0.08520238222222222*_t646 + 0.060858844444444435*_t647;
  const double _t649 = (0.1232e4 / 0.27e2)*params->d[1];
  const double _t650 = (0.880e3 / 0.27e2)*_t647;
  const double _t651 = -_t646*_t649 - _t650*params->d[2];
  const double _t652 = _t146*_t570;
  const double _t653 = 0.3e1*_t330;
  const double _t654 = 0.3e1*_t250;
  const double _t655 = 0.17040476444444444*_t646 + 0.12171768888888887*_t647;
  const double _t656 = 0.3e1*_t148;
  const double _t657 = _t16*_t330;
  const double _t658 = 0.25560714666666667*_t646 + 0.18257653333333332*_t647;
  const double _t659 = _t658*_t77;
  const double _t660 = _t337*params->d[4];
  const double _t661 = _t660*sigma_ss;
  const double _t662 = (0.5440e4 / 0.27e2)*tau_s;
  const double _t663 = xc_powr(n_s, -25, 3);
  const double _t664 = _t663*params->d[3];
  const double _t665 = (0.1600e4 / 0.9e1)*_t152;
  const double _t666 = (0.1232e4 / 0.27e2)*_t21;
  const double _t667 = (0.1760e4 / 0.27e2)*_t74;
  const double _t668 = -0.6688e4 / 0.27e2*_t18*_t664 - _t340*_t665 - _t646*_t666 - _t647*_t667 - _t661*_t662;
  const double _t669 = -0.073030613333333327*_t323 - 0.066391466666666663*_t324;
  const double _t670 = _t147*_t669;
  const double _t671 = 0.2e1*_t332;
  const double _t672 = 0.3e1*_t333;
  const double _t673 = 0.024896799999999997*_t140 + 0.031120999999999999*_t141;
  const double _t674 = _t346*_t673;
  const double _t675 = 0.3e1*_t346;
  const double _t676 = _t243/xc_powi(n_s, 11);
  const double _t677 = 0.33554896133100558*_t127;
  const double _t678 = xc_powr(n_s, -41, 3);
  const double _t679 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t680 = 3.8412835988906175e-6*_t1*_t466*_t467*_t678*_t679 + 0.013591658656784932*_t10*_t128*_t129*_t18*_t663 - 0.00099744068652503909*_t348*_t676 - _t646*_t677;
  const double _t681 = 0.3e1*_t352;
  const double _t682 = 0.3e1*_t158;
  const double _t683 = (tau_s * tau_s * tau_s);
  const double _t684 = _t242*_t683;
  const double _t685 = (0.250e3 / 0.9e1)*_t684;
  const double _t686 = _t152*_t80;
  const double _t687 = (0.400e3 / 0.9e1)*_t339;
  const double _t688 = _t152*_t41;
  const double _t689 = (0.1000e4 / 0.9e1)*_t684;
  const double _t690 = _t152*_t184;
  const double _t691 = _t152*_t339;
  const double _t692 = _t29*_t44;
  const double _t693 = (0.4400e4 / 0.27e2)*_t647;
  const double _t694 = (0.4840e4 / 0.27e2)*_t647;
  const double _t695 = (0.440e3 / 0.9e1)*_t647;
  const double _t696 = (0.1760e4 / 0.27e2)*_t647;
  const double _t697 = (0.2200e4 / 0.27e2)*_t647;
  const double _t698 = (0.880e3 / 0.9e1)*_t647;
  const double _t699 = (0.3080e4 / 0.27e2)*_t647;
  const double _t700 = (0.3520e4 / 0.27e2)*_t647;
  const double _t701 = (0.440e3 / 0.3e1)*_t647;
  const double _t702 = (0.10000e5 / 0.3e1)*_t684;
  const double _t703 = _t36*_t684;
  const double _t704 = _t684*_t89;
  const double _t705 = _t196*_t684;
  const double _t706 = (0.13750e5 / 0.3e1)*_t684;
  const double _t707 = _t39*_t684;
  const double _t708 = (0.2500e4 / 0.9e1)*_t684;
  const double _t709 = _t42*_t684;
  const double _t710 = (0.5000e4 / 0.9e1)*_t684;
  const double _t711 = (0.8750e4 / 0.9e1)*_t684;
  const double _t712 = _t57*_t684;
  const double _t713 = (0.14000e5 / 0.9e1)*_t684;
  const double _t714 = _t60*_t684;
  const double _t715 = (0.7000e4 / 0.3e1)*_t684;
  const double _t716 = _t33*_t684;
  const double _t717 = 0.2000e4*_t691;
  const double _t718 = (0.22000e5 / 0.9e1)*_t691;
  const double _t719 = _t39*_t691;
  const double _t720 = _t42*_t691;
  const double _t721 = _t45*_t691;
  const double _t722 = (0.2000e4 / 0.3e1)*_t691;
  const double _t723 = 0.1600e4*_t691;
  const double _t724 = (0.2800e4 / 0.3e1)*_t691;
  const double _t725 = (0.11200e5 / 0.9e1)*_t691;
  const double _t726 = _t101*_t697 + _t102*_t697 + _t105*_t698 + _t106*_t698 + _t109*_t699 + _t110*_t699 + _t113*_t700 + _t114*_t700 + _t117*_t701 + _t118*_t701 + _t183*_t685 - _t188*_t717 + (0.137500e6 / 0.9e1)*_t189*_t704 - 0.40000e5 / 0.9e1*_t190*_t691 - _t192*_t718 - _t193*_t718 + (0.60500e5 / 0.3e1)*_t194*_t705 - 0.48400e5 / 0.9e1*_t195*_t691 - 0.8800e4 / 0.3e1*_t197*_t691 - 0.400e3 / 0.3e1*_t198*_t719 + 0.500e3*_t200*_t707 - 0.800e3 / 0.3e1*_t200*_t720 + (0.10000e5 / 0.9e1)*_t204*_t709 - 0.4000e4 / 0.9e1*_t204*_t721 + (0.12500e5 / 0.9e1)*_t205*_t709 - 0.10000e5 / 0.9e1*_t205*_t721 + 0.3500e4*_t207*_t712 - _t209*_t724 - _t210*_t724 + (0.49000e5 / 0.9e1)*_t211*_t714 - 0.19600e5 / 0.9e1*_t212*_t691 - _t214*_t725 - _t215*_t725 + 0.8000e4*_t216*_t716 - 0.25600e5 / 0.9e1*_t217*_t691 - _t219*_t723 - _t220*_t723 + 0.11250e5*_t221*_t703 - 0.3600e4*_t222*_t691 - _t223*_t717 + (0.2000e4 / 0.3e1)*_t279*_t707 - 0.6400e4 / 0.9e1*_t279*_t720 - 0.4000e4 / 0.9e1*_t284*_t720 - _t287*_t722 - _t289*_t722 - _t290*_t723 + (0.440e3 / 0.27e2)*_t32*_t647 + (0.55000e5 / 0.9e1)*_t35*_t705 + (0.440e3 / 0.27e2)*_t356*_t647 + _t358*_t650 - _t359*_t665 + _t411*_t702 + 0.12500e5*_t413*_t703 + _t416*_t706 + (0.151250e6 / 0.9e1)*_t417*_t704 + (0.71500e5 / 0.9e1)*_t419*_t684 + (0.12250e5 / 0.3e1)*_t429*_t712 + _t431*_t713 + (0.56000e5 / 0.9e1)*_t432*_t714 + _t433*_t715 + 0.9000e4*_t434*_t716 + _t44*_t685 - 0.800e3 / 0.3e1*_t47*_t719 + _t491*_t685 + (0.500e3 / 0.3e1)*_t492*_t684 + _t507*_t689 + _t509*_t708 + _t513*_t710 + _t515*_t708 + (0.6250e4 / 0.3e1)*_t517*_t684 + _t518*_t711 + _t520*_t710 + 0.2500e4*_t521*_t684 + _t523*_t713 + _t525*_t711 + _t527*_t715 + _t530*_t702 + _t531*_t706 + 0.250e3*_t601*_t684 + _t602*_t689 + _t650*_t92 + (0.500e3 / 0.9e1)*_t684*_t91 - _t686*_t687 - _t687*_t688 - _t687*_t690 - 0.400e3 / 0.3e1*_t691*_t692 + _t693*_t84 + _t693*_t85 + _t694*_t88 + _t694*_t90 + _t695*_t94 + _t695*_t96 + _t696*_t97 + _t696*_t99 - 0.400e3*_t719*_t95;
  const double _t727 = _t14*_t651 + _t156*_t672 + _t169*_t681 + _t17*_t668 + _t180*_t670 + _t22*_t659 + _t230*_t652 + _t248*_t573 + _t248*_t576 + _t252*_t653 + _t27*_t726 + _t328*_t654 + _t329*_t656 + _t331*_t333 + _t344*_t656 + _t346*_t481 + _t347*_t657 + _t398*_t682 + _t406*_t674 + _t486*_t675 + _t584*_t671 + _t63*_t680 + _t648*_t66 + _t655*_t69;
#endif
#if _KMAX >= 4
  const double _t729 = xc_powr(n_s, -20, 3);
  const double _t730 = _t179*_t729;
  const double _t731 = _t16*_t405;
  const double _t732 = _t405*_t76;
  const double _t733 = _t22/xc_powi(_t13, 7);
  const double _t734 = 0.24e2*_t729;
  const double _t735 = 0.72e2*_t729;
  const double _t736 = _t29*_t48;
  const double _t737 = _t736*params->a[1];
  const double _t738 = _t736*params->a[2];
  const double _t739 = _t29*_t729;
  const double _t740 = 0.120e3*_t729;
  const double _t741 = _t284*_t29;
  const double _t742 = 0.5040e4*_t729;
  const double _t743 = _t52*_t83;
  const double _t744 = _t36*_t729;
  const double _t745 = _t55*params->a[10];
  const double _t746 = _t729*_t89;
  const double _t747 = _t196*_t729;
  const double _t748 = _t418*_t729;
  const double _t749 = 0.7920e4*_t729;
  const double _t750 = _t55*_t87;
  const double _t751 = _t58*params->a[11];
  const double _t752 = _t38/xc_powi(_t30, 15);
  const double _t753 = _t506*_t51;
  const double _t754 = _t39*_t729;
  const double _t755 = 0.360e3*_t729;
  const double _t756 = _t42*_t54;
  const double _t757 = _t756*params->a[3];
  const double _t758 = _t729*_t756;
  const double _t759 = 0.840e3*_t729;
  const double _t760 = _t512*_t57;
  const double _t761 = _t57*_t729;
  const double _t762 = 0.1680e4*_t729;
  const double _t763 = _t50*_t60;
  const double _t764 = _t104*_t39;
  const double _t765 = _t42*_t427;
  const double _t766 = _t45*_t761;
  const double _t767 = _t60*_t729;
  const double _t768 = 0.3024e4*_t729;
  const double _t769 = _t33*_t53;
  const double _t770 = _t108*_t42;
  const double _t771 = _t33*_t729;
  const double _t772 = _t36*_t56;
  const double _t773 = _t112*_t45;
  const double _t774 = _t49*params->a[8];
  const double _t775 = _t59*_t89;
  const double _t776 = _t116*_t49;
  const double _t777 = _t52*params->a[9];
  const double _t778 = xc_powr(n_s, -23, 3);
  const double _t779 = _t179*_t778;
  const double _t780 = 1.2500161111805137e-6*params->d[1];
  const double _t781 = _t125*_t405;
  const double _t782 = xc_powr(n_s, -26, 3);
  const double _t783 = _t179*_t782;
  const double _t784 = 0.00033471935112959998*_t783;
  const double _t785 = 3.1250402779512841e-6*_t438;
  const double _t786 = 1.5625201389756421e-6*_t451;
  const double _t787 = xc_powr(n_s, -29, 3);
  const double _t788 = _t179*_t787;
  const double _t789 = 0.00050207902669439995*params->d[3];
  const double _t790 = _t179*_t465;
  const double _t791 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t792 = xc_powi(_t25, -5);
  const double _t793 = _t179*_t248;
  const double _t794 = _t179*_t401;
  const double _t795 = _t146*params->d[2];
  const double _t796 = _t147*params->d[5];
  const double _t797 = _t145*_t179;
  const double _t798 = _t179*_t255;
  const double _t799 = _t331*_t405;
  const double _t800 = _t147*_t732;
  const double _t801 = _t147*_t733;
  const double _t802 = _t156*_t405;
  const double _t803 = _t778*tau_s;
  const double _t804 = 0.40e2*_t803;
  const double _t805 = 0.120e3*_t803;
  const double _t806 = _t29*_t803;
  const double _t807 = 0.200e3*_t803;
  const double _t808 = 0.8400e4*_t803;
  const double _t809 = _t36*_t803;
  const double _t810 = _t803*_t89;
  const double _t811 = _t196*_t803;
  const double _t812 = _t418*_t803;
  const double _t813 = 0.13200e5*_t803;
  const double _t814 = _t39*_t803;
  const double _t815 = 0.600e3*_t803;
  const double _t816 = _t756*_t803;
  const double _t817 = 0.1400e4*_t803;
  const double _t818 = _t57*_t803;
  const double _t819 = 0.2800e4*_t803;
  const double _t820 = _t45*_t818;
  const double _t821 = _t60*_t803;
  const double _t822 = 0.5040e4*_t803;
  const double _t823 = _t33*_t803;
  const double _t824 = 0.00050207902669439995*params->d[1];
  const double _t825 = 6.2500805559025686e-7*_t438;
  const double _t826 = _t179*_t438;
  const double _t827 = _t146*params->d[1];
  const double _t828 = 0.00016735967556479999*_t827;
  const double _t829 = 0.059752319999999998*_t826;
  const double _t830 = _t147*params->d[4];
  const double _t831 = 0.00055786558521600006*_t72;
  const double _t832 = 0.00072522526078079997*_t19;
  const double _t833 = _t179*_t306;
  const double _t834 = 1.5625201389756421e-6*_t438;
  const double _t835 = _t147*_t781;
  const double _t836 = 0.00027893279260799998*_t72;
  const double _t837 = 3.1250402779512843e-7*_t451;
  const double _t838 = _t179*_t451;
  const double _t839 = 0.029876159999999999*_t838;
  const double _t840 = _t147*params->d[3];
  const double _t841 = 7.8126006948782103e-7*_t451;
  const double _t842 = _t309*_t77;
  const double _t843 = 1.5625201389756422e-7*_t242;
  const double _t844 = _t179*_t242;
  const double _t845 = _t10*_t791*_t792;
  const double _t846 = 0.00013946639630399999*_t72;
  const double _t847 = _t474*params->d[0];
  const double _t848 = _t148*_t72;
  const double _t849 = _t570*_t77;
  const double _t850 = _t330*_t77;
  const double _t851 = _t850*params->d[2];
  const double _t852 = _t328*_t77;
  const double _t853 = _t146*_t793;
  const double _t854 = _t147*_t179;
  const double _t855 = _t795*_t854;
  const double _t856 = _t179*_t346;
  const double _t857 = _t179*_t329;
  const double _t858 = 0.099587200000000001*_t139;
  const double _t859 = 0.074690400000000004*_t6;
  const double _t860 = _t578*_t77;
  const double _t861 = _t147*_t403;
  const double _t862 = _t330*_t403;
  const double _t863 = 0.0497936*_t6;
  const double _t864 = _t345*_t446;
  const double _t865 = _t332*_t446;
  const double _t866 = _t147*_t798;
  const double _t867 = _t147*_t799;
  const double _t868 = _t346*_t732;
  const double _t869 = 0.037345199999999995*_t8;
  const double _t870 = _t345*_t406;
  const double _t871 = _t332*_t406;
  const double _t872 = _t179*_t344;
  const double _t873 = _t346*_t733;
  const double _t874 = _t147*_t802;
  const double _t875 = (0.260e3 / 0.9e1)*_t19;
  const double _t876 = _t451*tau_s;
  const double _t877 = (0.280e3 / 0.3e1)*_t876;
  const double _t878 = _t339*_t782;
  const double _t879 = (0.200e3 / 0.3e1)*_t878;
  const double _t880 = 0.200e3*_t878;
  const double _t881 = (0.1120e4 / 0.3e1)*_t876;
  const double _t882 = 0.1300e4*_t19;
  const double _t883 = (0.14300e5 / 0.9e1)*_t19;
  const double _t884 = (0.1300e4 / 0.3e1)*_t19;
  const double _t885 = 0.1040e4*_t19;
  const double _t886 = (0.1820e4 / 0.3e1)*_t19;
  const double _t887 = (0.7280e4 / 0.9e1)*_t19;
  const double _t888 = _t29*_t878;
  const double _t889 = (0.1000e4 / 0.3e1)*_t878;
  const double _t890 = 0.11200e5*_t876;
  const double _t891 = _t36*_t876;
  const double _t892 = _t876*_t89;
  const double _t893 = _t196*_t876;
  const double _t894 = 0.15400e5*_t876;
  const double _t895 = _t39*_t876;
  const double _t896 = (0.2800e4 / 0.3e1)*_t876;
  const double _t897 = _t42*_t876;
  const double _t898 = (0.5600e4 / 0.3e1)*_t876;
  const double _t899 = (0.9800e4 / 0.3e1)*_t876;
  const double _t900 = _t57*_t876;
  const double _t901 = (0.15680e5 / 0.3e1)*_t876;
  const double _t902 = _t60*_t876;
  const double _t903 = 0.7840e4*_t876;
  const double _t904 = _t33*_t876;
  const double _t905 = 0.14000e5*_t878;
  const double _t906 = _t36*_t878;
  const double _t907 = _t878*_t89;
  const double _t908 = _t196*_t878;
  const double _t909 = _t418*_t878;
  const double _t910 = 0.22000e5*_t878;
  const double _t911 = _t39*_t878;
  const double _t912 = 0.1000e4*_t878;
  const double _t913 = _t756*_t878;
  const double _t914 = (0.7000e4 / 0.3e1)*_t878;
  const double _t915 = _t57*_t878;
  const double _t916 = (0.14000e5 / 0.3e1)*_t878;
  const double _t917 = _t45*_t915;
  const double _t918 = _t60*_t878;
  const double _t919 = 0.8400e4*_t878;
  const double _t920 = _t33*_t878;
  const double _t921 = _t148*_t19;
  const double _t922 = _t850*params->d[1];
  const double _t923 = 0.2e1*_t333;
  const double _t924 = 0.014938079999999999*_t72;
  const double _t925 = _t827*_t854;
  const double _t926 = 0.2e1*_t856;
  const double _t927 = _t629*_t77;
  const double _t928 = _t345*_t445;
  const double _t929 = _t332*_t445;
  const double _t930 = _t147*_t833;
  const double _t931 = _t346*_t781;
  const double _t932 = _t17*_t337;
  const double _t933 = 0.10954591999999999*_t322;
  const double _t934 = 0.059752319999999998*_t139;
  const double _t935 = 0.039834879999999996*_t139;
  const double _t936 = 0.018672599999999998*_t6;
  const double _t938 = _t573*params->d[0];
  const double _t939 = _t648*params->d[0];
  const double _t940 = _t17*_t939;
  const double _t941 = 0.10e2*_t6*params->d[2];
  const double _t942 = _t17*_t655;
  const double _t943 = _t17*_t651;
  const double _t944 = _t148*_t248;
  const double _t945 = _t576*params->d[0];
  const double _t946 = _t330*_t473;
  const double _t947 = _t474*_t570;
  const double _t948 = _t146*_t333;
  const double _t949 = 0.056017800000000006*_t6;
  const double _t950 = _t145*_t148;
  const double _t951 = 0.033610679999999997*_t8;
  const double _t952 = _t330*_t478;
  const double _t953 = _t146*_t852;
  const double _t954 = (0.13120e5 / 0.27e2)*_t152;
  const double _t955 = 0.066391466666666663*_t139;
  const double _t956 = _t16*_t333;
  const double _t957 = _t175*_t655;
  const double _t958 = _t147*_t853;
  const double _t959 = _t146*_t856;
  const double _t960 = 0.044814239999999998*_t8;
  const double _t961 = _t147*_t857;
  const double _t962 = _t345*_t481;
  const double _t963 = _t346*_t403;
  const double _t964 = _t332*_t481;
  const double _t965 = _t147*_t862;
  const double _t966 = _t346*_t799;
  const double _t967 = _t180*_t669;
  const double _t968 = _t180*_t658;
  const double _t969 = _t668*_t77;
  const double _t970 = _t484*_t673;
  const double _t971 = _t673*_t870;
  const double _t972 = _t406*_t670;
  const double _t973 = _t345*_t871;
  const double _t974 = _t345*_t486;
  const double _t975 = _t332*_t486;
  const double _t976 = _t147*_t872;
  const double _t977 = _t674*_t733;
  const double _t978 = _t346*_t802;
  const double _t979 = (0.3280e4 / 0.27e2)*tau_s;
  const double _t980 = _t683*_t787;
  const double _t981 = (0.1000e4 / 0.9e1)*_t980;
  const double _t982 = (0.1000e4 / 0.3e1)*_t980;
  const double _t983 = _t152*tau_s;
  const double _t984 = _t29*_t980;
  const double _t985 = (0.5000e4 / 0.9e1)*_t980;
  const double _t986 = (0.16400e5 / 0.3e1)*_t983;
  const double _t987 = (0.180400e6 / 0.27e2)*_t983;
  const double _t988 = _t39*_t983;
  const double _t989 = _t42*_t983;
  const double _t990 = _t45*_t983;
  const double _t991 = (0.16400e5 / 0.9e1)*_t983;
  const double _t992 = (0.13120e5 / 0.3e1)*_t983;
  const double _t993 = (0.22960e5 / 0.9e1)*_t983;
  const double _t994 = (0.91840e5 / 0.27e2)*_t983;
  const double _t995 = (0.70000e5 / 0.3e1)*_t980;
  const double _t996 = _t36*_t980;
  const double _t997 = _t89*_t980;
  const double _t998 = _t196*_t980;
  const double _t999 = (0.2200000e7 / 0.9e1)*_t189;
  const double _t1000 = _t418*_t980;
  const double _t1001 = (0.110000e6 / 0.3e1)*_t980;
  const double _t1002 = _t39*_t980;
  const double _t1003 = (0.5000e4 / 0.3e1)*_t980;
  const double _t1004 = _t756*_t980;
  const double _t1005 = (0.35000e5 / 0.9e1)*_t980;
  const double _t1006 = _t57*_t980;
  const double _t1007 = (0.70000e5 / 0.9e1)*_t980;
  const double _t1008 = _t1006*_t45;
  const double _t1009 = _t60*_t980;
  const double _t1010 = 0.14000e5*_t980;
  const double _t1011 = (0.196000e6 / 0.3e1)*_t429;
  const double _t1012 = _t33*_t980;
  const double _t1013 = 0.036515306666666664*_t322;
  const double _t1014 = 0.0049793599999999995*_t139;
  const double _t1015 = 0.8e1*_t625;
  const double _t1016 = _t330*_t347;
  const double _t1017 = 0.044814239999999998*_t139;
  const double _t1018 = 0.016805339999999998*_t6;
  const double _t1019 = 0.073030613333333327*_t322;
  const double _t1020 = 0.022407119999999999*_t6;
  const double _t1021 = _t729*sigma_ss;
  const double _t1022 = _t645*tau_s;
  const double _t1023 = (0.20944e5 / 0.81e2)*_t1021;
  const double _t1024 = (0.12320e5 / 0.81e2)*_t1022;
  const double _t1025 = _t18/xc_powr(n_s, 28, 3);
  const double _t1026 = (0.108800e6 / 0.81e2)*_t337;
  const double _t1027 = (0.24640e5 / 0.81e2)*_t1022;
  const double _t1028 = (0.6160e4 / 0.81e2)*_t1022;
  const double _t1029 = _t465*(tau_s * tau_s * tau_s * tau_s);
  const double _t1030 = (0.5000e4 / 0.27e2)*_t1029;
  const double _t1031 = (0.5000e4 / 0.9e1)*_t1029;
  const double _t1032 = _t309*_t683;
  const double _t1033 = (0.4000e4 / 0.9e1)*_t1032;
  const double _t1034 = _t337*_t339;
  const double _t1035 = (0.27200e5 / 0.81e2)*_t1034;
  const double _t1036 = _t1029*_t29;
  const double _t1037 = (0.25000e5 / 0.27e2)*_t1029;
  const double _t1038 = (0.16000e5 / 0.9e1)*_t1032;
  const double _t1039 = (0.61600e5 / 0.81e2)*_t1022;
  const double _t1040 = (0.67760e5 / 0.81e2)*_t1022;
  const double _t1041 = (0.6160e4 / 0.27e2)*_t1022;
  const double _t1042 = (0.30800e5 / 0.81e2)*_t1022;
  const double _t1043 = (0.12320e5 / 0.27e2)*_t1022;
  const double _t1044 = (0.43120e5 / 0.81e2)*_t1022;
  const double _t1045 = (0.49280e5 / 0.81e2)*_t1022;
  const double _t1046 = (0.6160e4 / 0.9e1)*_t1022;
  const double _t1047 = (0.350000e6 / 0.9e1)*_t1029;
  const double _t1048 = _t1029*_t36;
  const double _t1049 = _t1029*_t89;
  const double _t1050 = _t1029*_t196;
  const double _t1051 = _t1029*_t418;
  const double _t1052 = (0.550000e6 / 0.9e1)*_t1029;
  const double _t1053 = _t1029*_t39;
  const double _t1054 = (0.25000e5 / 0.9e1)*_t1029;
  const double _t1055 = _t1029*_t756;
  const double _t1056 = (0.175000e6 / 0.27e2)*_t1029;
  const double _t1057 = _t1029*_t57;
  const double _t1058 = (0.350000e6 / 0.27e2)*_t1029;
  const double _t1059 = _t1057*_t45;
  const double _t1060 = _t1029*_t60;
  const double _t1061 = (0.70000e5 / 0.3e1)*_t1029;
  const double _t1062 = _t1029*_t33;
  const double _t1063 = (0.160000e6 / 0.3e1)*_t1032;
  const double _t1064 = _t1032*_t36;
  const double _t1065 = _t1032*_t89;
  const double _t1066 = _t1032*_t196;
  const double _t1067 = (0.220000e6 / 0.3e1)*_t1032;
  const double _t1068 = _t1032*_t39;
  const double _t1069 = (0.40000e5 / 0.9e1)*_t1032;
  const double _t1070 = _t1032*_t42;
  const double _t1071 = (0.80000e5 / 0.9e1)*_t1032;
  const double _t1072 = (0.140000e6 / 0.9e1)*_t1032;
  const double _t1073 = _t1032*_t57;
  const double _t1074 = (0.224000e6 / 0.9e1)*_t1032;
  const double _t1075 = _t1032*_t60;
  const double _t1076 = (0.112000e6 / 0.3e1)*_t1032;
  const double _t1077 = _t1032*_t33;
  const double _t1078 = (0.136000e6 / 0.9e1)*_t1034;
  const double _t1079 = (0.1496000e7 / 0.81e2)*_t1034;
  const double _t1080 = _t1034*_t39;
  const double _t1081 = _t1034*_t42;
  const double _t1082 = _t1034*_t45;
  const double _t1083 = (0.136000e6 / 0.27e2)*_t1034;
  const double _t1084 = (0.108800e6 / 0.9e1)*_t1034;
  const double _t1085 = (0.190400e6 / 0.27e2)*_t1034;
  const double _t1086 = (0.761600e6 / 0.81e2)*_t1034;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t5)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  const double _t65 = my_piecewise3(_t5, 0, _hc0[0]*_t64);
#if _KMAX >= 1
  const double _t121 = my_piecewise3(_t5, 0, _hc0[0]*_t120);
  const double _t134 = my_piecewise3(_t5, 0, _hc0[0]*_t133);
  const double _t136 = _hc0[2]*_t3;
  const double _t137 = _t135*_t136;
  const double _t138 = (0.1e1 / 0.6e1)*_t137;
  const double _t171 = my_piecewise3(_t5, 0, _hc0[0]*_t170 - _t138*_t64);
#endif
#if _KMAX >= 2
  const double _t226 = my_piecewise3(_t5, 0, _hc0[0]*_t225);
  const double _t235 = my_piecewise3(_t5, 0, _hc0[0]*_t234);
  const double _t247 = my_piecewise3(_t5, 0, _hc0[0]*_t246);
  const double _t299 = my_piecewise3(_t5, 0, _hc0[0]*_t298 - _t120*_t138);
  const double _t313 = my_piecewise3(_t5, 0, _hc0[0]*_t312 - _t133*_t138);
  const double _t316 = _t136*_t315;
  const double _t319 = _hc0[5]*_t10*_t318;
  const double _t320 = _t319*_t6;
  const double _t321 = (0.1e1 / 0.3e1)*_t137;
  const double _t400 = my_piecewise3(_t5, 0, _hc0[0]*_t399 - _t170*_t321 + _t314*_t316 + _t317*_t320);
#endif
#if _KMAX >= 3
  const double _t437 = my_piecewise3(_t5, 0, _hc0[0]*_t436);
  const double _t450 = my_piecewise3(_t5, 0, _hc0[0]*_t449);
  const double _t459 = my_piecewise3(_t5, 0, _hc0[0]*_t458);
  const double _t472 = my_piecewise3(_t5, 0, _hc0[0]*_t471);
  const double _t534 = my_piecewise3(_t5, 0, _hc0[0]*_t533 - _t138*_t225);
  const double _t547 = my_piecewise3(_t5, 0, _hc0[0]*_t546 - _t138*_t234);
  const double _t563 = my_piecewise3(_t5, 0, _hc0[0]*_t562 - _t138*_t246);
  const double _t564 = (0.2e1 / 0.9e1)*_t316;
  const double _t565 = (0.1e1 / 0.36e2)*_t320;
  const double _t621 = my_piecewise3(_t5, 0, _hc0[0]*_t620 + _t120*_t564 + _t120*_t565 - _t298*_t321);
  const double _t637 = my_piecewise3(_t5, 0, _hc0[0]*_t636 + _t133*_t564 + _t133*_t565 - _t312*_t321);
  const double _t639 = _hc0[9]*_t638/(n_s * n_s * n_s * n_s);
  const double _t640 = _t136*_t172;
  const double _t641 = (0.14e2 / 0.27e2)*_t640;
  const double _t642 = _t139*_t319;
  const double _t643 = (0.1e1 / 0.9e1)*_t642;
  const double _t644 = _hc0[2]*_t135*_t4;
  const double _t728 = my_piecewise3(_t5, 0, _hc0[0]*_t727 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t170*_t2*_t315 + (0.1e1 / 0.12e2)*_hc0[5]*_t10*_t170*_t318*_t6 - _t317*_t639 - _t399*_t644 - _t64*_t641 - _t64*_t643);
#endif
#if _KMAX >= 4
  const double _t937 = (0.1e1 / 0.36e2)*_t639;
#endif

  const double f = my_piecewise3(_t5, 0, _t65*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t5, 0, _t121*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = 0;
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t5, 0, _t134*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t5, 0, _t171*n_s + _t65);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = my_piecewise3(_t5, 0, _t226*n_s);
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = 0;
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = my_piecewise3(_t5, 0, _t235*n_s);
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = 0;
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t5, 0, _t247*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t5, 0, _t121 + _t299*n_s);
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = 0;
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t5, 0, _t134 + _t313*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t5, 0, 0.2e1*_t171 + _t400*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = my_piecewise3(_t5, 0, _t437*n_s);
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = 0;
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = my_piecewise3(_t5, 0, _t450*n_s);
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = 0;
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = my_piecewise3(_t5, 0, _t459*n_s);
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = 0;
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t5, 0, _t472*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = my_piecewise3(_t5, 0, _t226 + _t534*n_s);
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = 0;
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = my_piecewise3(_t5, 0, _t235 + _t547*n_s);
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = 0;
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t5, 0, _t247 + _t563*n_s);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t5, 0, 0.2e1*_t299 + _t621*n_s);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = 0;
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t5, 0, 0.2e1*_t313 + _t637*n_s);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t5, 0, 0.3e1*_t400 + _t728*n_s);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t27*(0.52800e5*_t189*_t747 + 0.75504e5*_t194*_t748 + _t198*_t735 + 0.432e3*_t200*_t739 + 0.1440e4*_t204*_t754 + 0.1200e4*_t205*_t754 + 0.8064e4*_t207*_t767 + 0.14112e5*_t211*_t771 + 0.23040e5*_t216*_t744 + 0.35640e5*_t221*_t746 + 0.384e3*_t279*_t739 + 0.17160e5*_t35*_t748 + 0.59400e5*_t413*_t746 + 0.87120e5*_t417*_t747 + 0.720e3*_t423*_t754 + 0.14112e5*_t429*_t767 + 0.24192e5*_t432*_t771 + 0.38880e5*_t434*_t744 + _t47*_t734 + _t490*_t734 + 0.4200e4*_t516*_t761 + 0.11880e5*_t62*_t747 + 0.192e3*_t729*_t738 + 0.24024e5*_t729*_t752 + 0.2880e4*_t729*_t765 + _t734*_t737 + _t735*_t95 + _t740*_t741 + _t740*_t753 + _t742*_t743 + _t742*_t772 + 0.28800e5*_t744*_t745 + 0.43560e5*_t746*_t751 + _t749*_t750 + _t749*_t775 + _t755*_t757 + _t755*_t764 + 0.1920e4*_t758*params->a[4] + 0.3600e4*_t758*params->a[5] + _t759*_t760 + _t759*_t770 + _t762*_t763 + _t762*_t773 + 0.7560e4*_t766*params->a[6] + 0.5880e4*_t766*params->a[7] + 0.10752e5*_t767*_t774 + _t768*_t769 + _t768*_t776 + 0.18144e5*_t771*_t777) - 1.2500161111805135e-5*_t401*_t732 + 2.3341050837629257e-8*_t729*_t731 + 7.002315251288778e-8*_t729*_t733 + 4.6682101675258512e-9*_t730*params->d[0] - 1.000012888944411e-5*_t730*params->d[2] + 0.0080332644271103992*_t730*params->d[5])));
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = 0;
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = 0;
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = 0;
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = 0;
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t132*_t435 - _t407*_t781 - 4.6875604169269262e-6*_t438*_t732 + 1.1670525418814628e-8*_t731*_t778 + 3.501157625644389e-8*_t733*_t778 - _t779*_t780 + 2.3341050837629256e-9*_t779*params->d[0] - 3.7500483335415412e-6*_t779*params->d[2] + 0.0010041580533887999*_t779*params->d[4] + 0.0020083161067775998*_t779*params->d[5])));
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = 0;
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t224*_t245 + 5.8352627094073142e-9*_t731*_t782 - _t732*_t786 + 1.7505788128221945e-8*_t733*_t782 - _t780*_t783 - _t781*_t785 + 1.1670525418814628e-9*_t783*params->d[0] - 1.2500161111805137e-6*_t783*params->d[2] + 0.00066943870225919997*_t783*params->d[4] + _t784*params->d[3] + _t784*params->d[5])));
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = 0;
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t119*_t470 - 2.3437802084634627e-6*_t451*_t781 - _t464*_t732 + 2.9176313547036571e-9*_t731*_t787 + 8.7528940641109725e-9*_t733*_t787 + _t788*_t789 + 5.835262709407314e-10*_t788*params->d[0] - 9.3751208338538519e-7*_t788*params->d[1] - 3.1250402779512843e-7*_t788*params->d[2] + 0.00025103951334719997*_t788*params->d[4])));
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = 0;
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(-1.5625201389756418e-6*_t242*_t781 + 1.4588156773518285e-9*_t465*_t731 + 4.3764470320554863e-9*_t465*_t733 + _t63*(7.4111068176966226e-9*_t10*_t791*_t792*sigma_ss/xc_powr(n_s, 40, 3) - 8.1027075914098964e-7*_t469) + _t789*_t790 + 2.917631354703657e-10*_t790*params->d[0] - 6.2500805559025686e-7*_t790*params->d[1])));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = my_piecewise3(_t5, 0, _t437 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t158*_t435 + 0.00050207902669439995*_t172*_t798 + 0.00083679837782399988*_t172*_t800 + _t27*(-0.88000e5*_t189*_t811 - 0.125840e6*_t194*_t812 + 0.6600e4*_t196*_t34*_t438*params->a[10] + 0.21780e5*_t196*_t34*_t438*params->a[11] - _t198*_t805 - 0.720e3*_t200*_t806 - 0.2400e4*_t204*_t814 - 0.2000e4*_t205*_t814 - 0.13440e5*_t207*_t821 - 0.23520e5*_t211*_t823 - 0.38400e5*_t216*_t809 - 0.59400e5*_t221*_t810 - 0.640e3*_t279*_t806 + 0.30e2*_t29*_t438*_t46*params->a[1] + 0.180e3*_t29*_t438*_t46*params->a[2] + 0.270e3*_t29*_t438*_t46*params->a[3] + 0.120e3*_t29*_t438*_t46*params->a[4] + 0.3600e4*_t33*_t438*_t55*params->a[10] + 0.2520e4*_t33*_t438*_t55*params->a[7] + 0.8640e4*_t33*_t438*_t55*params->a[8] + 0.9720e4*_t33*_t438*_t55*params->a[9] - 0.28600e5*_t35*_t812 + 0.13500e5*_t36*_t438*_t58*params->a[10] + 0.4950e4*_t36*_t438*_t58*params->a[11] + 0.3600e4*_t36*_t438*_t58*params->a[8] + 0.12150e5*_t36*_t438*_t58*params->a[9] + 0.8580e4*_t37*_t418*_t438*params->a[11] + 0.120e3*_t39*_t438*_t48*params->a[2] + 0.540e3*_t39*_t438*_t48*params->a[3] + 0.720e3*_t39*_t438*_t48*params->a[4] + 0.300e3*_t39*_t438*_t48*params->a[5] - 0.99000e5*_t413*_t810 - 0.145200e6*_t417*_t811 + 0.300e3*_t42*_t438*_t51*params->a[3] + 0.1200e4*_t42*_t438*_t51*params->a[4] + 0.1500e4*_t42*_t438*_t51*params->a[5] + 0.600e3*_t42*_t438*_t51*params->a[6] - 0.1200e4*_t423*_t814 - 0.23520e5*_t429*_t821 + 0.30e2*_t43*_t438*params->a[1] + 0.60e2*_t43*_t438*params->a[2] + 0.30e2*_t43*_t438*params->a[3] - 0.40320e5*_t432*_t823 - 0.64800e5*_t434*_t809 + 0.600e3*_t438*_t45*_t54*params->a[4] + 0.2250e4*_t438*_t45*_t54*params->a[5] + 0.2700e4*_t438*_t45*_t54*params->a[6] + 0.1050e4*_t438*_t45*_t54*params->a[7] + 0.1050e4*_t438*_t49*_t57*params->a[5] + 0.3780e4*_t438*_t49*_t57*params->a[6] + 0.4410e4*_t438*_t49*_t57*params->a[7] + 0.1680e4*_t438*_t49*_t57*params->a[8] + 0.1680e4*_t438*_t52*_t60*params->a[6] + 0.5880e4*_t438*_t52*_t60*params->a[7] + 0.6720e4*_t438*_t52*_t60*params->a[8] + 0.2520e4*_t438*_t52*_t60*params->a[9] + 0.16500e5*_t438*_t61*_t89*params->a[10] + 0.18150e5*_t438*_t61*_t89*params->a[11] + 0.4950e4*_t438*_t61*_t89*params->a[9] - _t490*_t804 - _t494*_t803 - 0.7000e4*_t516*_t818 - 0.19800e5*_t62*_t811 - _t737*_t804 - 0.320e3*_t738*_t803 - _t741*_t807 - _t743*_t808 - 0.48000e5*_t745*_t809 - _t750*_t813 - 0.72600e5*_t751*_t810 - 0.40040e5*_t752*_t803 - _t753*_t807 - _t757*_t815 - _t760*_t817 - _t763*_t819 - _t764*_t815 - 0.4800e4*_t765*_t803 - _t769*_t822 - _t770*_t817 - _t772*_t808 - _t773*_t819 - 0.17920e5*_t774*_t821 - _t775*_t813 - _t776*_t822 - 0.30240e5*_t777*_t823 - _t805*_t95 - 0.3200e4*_t816*params->a[4] - 0.6000e4*_t816*params->a[5] - 0.12600e5*_t820*params->a[6] - 0.9800e4*_t820*params->a[7]) - 6.2500805559025682e-6*_t401*_t801 - _t404*_t793 - _t404*_t797 - _t407*_t799 - _t407*_t802 + 1.3444272000000002*_t439*params->d[5] + 1.5625201389756421e-6*_t440 - 0.0025103951334719998*_t442 + 6.2500805559025682e-6*_t444 - 0.0016735967556480002*_t446*_t72 + 1.5625201389756424e-5*_t448 + 0.0010041580533887999*_t794*_t795 - 0.35851391999999999*_t794*_t796) - _t138*_t436));
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = 0;
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = my_piecewise3(_t5, 0, _t450 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t132*_t532 + _t181*_t833 + _t224*_t311 - _t445*_t831 - _t446*_t832 + _t447*_t798 - _t452*_t824 + 0.26888543999999998*_t452*params->d[4] + 0.26888544000000003*_t452*params->d[5] + 9.3751208338538519e-7*_t453 - 0.0010041580533887999*_t454 + 3.7500483335415408e-6*_t456 + 9.3751208338538523e-6*_t457 + _t485*_t835 - _t785*_t801 - _t793*_t825 + 0.00033471935112959998*_t795*_t826 - _t796*_t829 - _t797*_t825 - _t799*_t834 + _t800*_t836 - _t802*_t834 + _t826*_t828 - _t829*_t830) - _t138*_t449));
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = 0;
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = my_piecewise3(_t5, 0, _t459 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t119*_t561 - 0.00072522526078079997*_t19*_t445 + _t241*_t798 + 5.4688204864147463e-6*_t242*_t406 + _t245*_t297 - _t446*_t558 + _t447*_t833 - 0.00058575886447679996*_t460*params->d[1] - 0.00029287943223839998*_t460*params->d[2] + 0.15684983999999999*_t460*params->d[4] + 5.4688204864147468e-7*_t461 + 0.15684983999999999*_t462 + 2.1875281945658987e-6*_t463 + _t559*_t800 - _t786*_t801 - _t793*_t837 + 8.3679837782399996e-5*_t795*_t838 - _t797*_t837 - _t799*_t841 - _t802*_t841 + _t828*_t838 - _t830*_t839 + _t835*_t836 - _t839*_t840) - _t138*_t458));
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = 0;
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t5, 0, _t472 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-0.00066943870225919986*_t152*_t445 + _t169*_t470 + 0.00012551975667359999*_t19*_t833 + 0.00020919959445599997*_t19*_t835 - 7.8126006948782103e-7*_t242*_t801 + 1.2500161111805135e-6*_t309*_t403 + 3.1250402779512837e-6*_t309*_t406 - _t464*_t799 - _t464*_t802 + _t63*(3.7812635426579517e-6*_t1*_t466*_t467*_t560*sigma_ss - 1.976295151385766e-8*_t18*_t845/xc_powr(n_s, 43, 3) - 0.00017717696405378984*_t310) - _t793*_t843 - _t797*_t843 - _t824*_t842 + 0.00012551975667359999*_t827*_t844 - 0.044814239999999998*_t840*_t844 + 3.1250402779512843e-7*_t842*params->d[0] + 0.26888543999999998*_t842*params->d[3]) - _t138*_t471));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = my_piecewise3(_t5, 0, 0.2e1*_t534 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-0.059752319999999998*_t172*_t855 + 0.00033471935112959998*_t172*_t857 + 0.00041839918891199994*_t172*_t873 + 0.00055786558521599995*_t172*_t874 + _t176*_t849 + _t176*_t852 - _t177*_t858 - _t178*_t860 + _t181*_t853 + _t181*_t862 + _t181*_t872 + _t224*_t352 + (0.1040e4 / 0.9e1)*_t236*params->d[5] + 0.00040290292265599995*_t237 + 0.0012087087679680001*_t239 + _t27*(-_t183*_t877 + _t184*_t875 + _t188*_t882 - 0.154000e6 / 0.3e1*_t189*_t892 + (0.440000e6 / 0.3e1)*_t189*_t908 + _t192*_t883 + _t193*_t883 - 0.67760e5*_t194*_t893 + (0.629200e6 / 0.3e1)*_t194*_t909 + _t198*_t880 + 0.1200e4*_t200*_t888 - 0.1680e4*_t200*_t895 - 0.11200e5 / 0.3e1*_t204*_t897 + 0.4000e4*_t204*_t911 - 0.14000e5 / 0.3e1*_t205*_t897 + (0.10000e5 / 0.3e1)*_t205*_t911 - 0.11760e5*_t207*_t900 + 0.22400e5*_t207*_t918 + _t209*_t886 + _t210*_t886 - 0.54880e5 / 0.3e1*_t211*_t902 + 0.39200e5*_t211*_t920 + _t214*_t887 + _t215*_t887 - 0.26880e5*_t216*_t904 + 0.64000e5*_t216*_t906 + _t219*_t885 + _t220*_t885 - 0.37800e5*_t221*_t891 + 0.99000e5*_t221*_t907 + _t223*_t882 + (0.3200e4 / 0.3e1)*_t279*_t888 - 0.2240e4*_t279*_t895 + _t287*_t884 + _t289*_t884 + _t290*_t885 - 0.61600e5 / 0.3e1*_t35*_t893 + (0.143000e6 / 0.3e1)*_t35*_t909 + (0.1040e4 / 0.9e1)*_t360*_t91 + (0.260e3 / 0.3e1)*_t361 + (0.26000e5 / 0.9e1)*_t374 + (0.31460e5 / 0.9e1)*_t376 + (0.5720e4 / 0.3e1)*_t377 + (0.260e3 / 0.3e1)*_t379 + 0.260e3*_t380 + (0.520e3 / 0.3e1)*_t382 + (0.520e3 / 0.3e1)*_t384 + (0.4160e4 / 0.9e1)*_t385 + (0.2600e4 / 0.9e1)*_t387 + (0.2600e4 / 0.9e1)*_t389 + (0.6500e4 / 0.9e1)*_t390 + (0.12740e5 / 0.9e1)*_t394 + (0.16640e5 / 0.9e1)*_t396 + 0.2340e4*_t397 + _t41*_t875 - _t411*_t890 - 0.42000e5*_t413*_t891 + 0.165000e6*_t413*_t907 - _t416*_t894 - 0.169400e6 / 0.3e1*_t417*_t892 + 0.242000e6*_t417*_t908 - 0.80080e5 / 0.3e1*_t419*_t876 + 0.2000e4*_t423*_t911 - 0.13720e5*_t429*_t900 + 0.39200e5*_t429*_t918 - _t431*_t901 - 0.62720e5 / 0.3e1*_t432*_t902 + 0.67200e5*_t432*_t920 - _t433*_t903 - 0.30240e5*_t434*_t904 + 0.108000e6*_t434*_t906 - _t44*_t877 + _t47*_t879 + _t490*_t879 - _t491*_t877 - 0.560e3*_t492*_t876 - _t507*_t881 - _t509*_t896 - _t513*_t898 - _t515*_t896 + (0.35000e5 / 0.3e1)*_t516*_t915 - 0.7000e4*_t517*_t876 - _t518*_t899 - _t520*_t898 - 0.8400e4*_t521*_t876 - _t523*_t901 - _t525*_t899 - _t527*_t903 - _t530*_t890 - _t531*_t894 - 0.840e3*_t601*_t876 - _t602*_t881 + 0.33000e5*_t62*_t908 + _t737*_t879 + (0.1600e4 / 0.3e1)*_t738*_t878 + _t741*_t889 + _t743*_t905 + 0.80000e5*_t745*_t906 + _t750*_t910 + 0.121000e6*_t751*_t907 + (0.200200e6 / 0.3e1)*_t752*_t878 + _t753*_t889 + _t757*_t912 + _t760*_t914 + _t763*_t916 + _t764*_t912 + 0.8000e4*_t765*_t878 + _t769*_t919 + _t770*_t914 + _t772*_t905 + _t773*_t916 + (0.89600e5 / 0.3e1)*_t774*_t918 + _t775*_t910 + _t776*_t919 + 0.50400e5*_t777*_t920 + _t80*_t875 - 0.560e3 / 0.3e1*_t876*_t91 + _t880*_t95 + (0.16000e5 / 0.3e1)*_t913*params->a[4] + 0.10000e5*_t913*params->a[5] + 0.21000e5*_t917*params->a[6] + (0.49000e5 / 0.3e1)*_t917*params->a[7]) + _t333*_t477 + _t353*_t532 - _t473*_t836 + 0.2240712*_t475*_t72 - _t476*_t851 + _t477*_t856 + _t479*_t864 + _t480*_t859 - _t481*_t831 + _t482*_t863 - _t483*_t865 + _t485*_t867 + _t485*_t871 - 0.43154453333333331*_t535 - 0.00055786558521599995*_t539 + 0.0024174175359360003*_t543 - 0.00092977597535999989*_t544 - 0.0011157311704320001*_t545 - 0.00037191039014399999*_t72*_t861 - 0.00069733198151999997*_t72*_t870 - 0.059752319999999998*_t8*_t866 - _t846*_t847 + 0.0497936*_t848*params->d[2] - 0.160e3 / 0.3e1*_t848*params->d[5] - _t868*_t869) + _t225*_t564 + _t225*_t565 - _t321*_t533));
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = 0;
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = my_piecewise3(_t5, 0, 0.2e1*_t547 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t119*_t634 - _t126*_t860 + _t132*_t619 - 0.52e2 / 0.3e1*_t148*_t149 + 0.0019339340287488*_t152*_t180 - _t177*_t630 - 0.00018130631519519997*_t19*_t473 + 0.067221360000000008*_t19*_t475 - 0.00036261263039039999*_t19*_t481 - 0.00060435438398399985*_t19*_t484 - 9.0653157597599983e-5*_t19*_t847 - 0.00024174175359359997*_t19*_t861 - 0.00045326578798799994*_t19*_t870 - _t232*_t582 + _t257*_t928 - _t259*_t929 + _t297*_t635 + _t307*_t864 - _t308*_t865 + _t447*_t857 + _t479*_t540 + _t480*_t555 + _t482*_t631 - _t483*_t930 - _t486*_t832 + _t536*_t849 + _t536*_t852 - _t537*_t851 - _t537*_t922 + _t541*_t853 + _t541*_t862 + _t541*_t872 + _t542*_t583 - 0.17261781333333334*_t548*params->d[2] + (0.416e3 / 0.9e1)*_t548*params->d[4] + 0.00032232233812479991*_t549 - 0.17261781333333331*_t550 + 0.078424919999999995*_t552 - 0.00036261263039039993*_t553 + 0.0009669670143744*_t554 - _t557*_t866 - _t588*_t931 - _t632*_t868 + 0.00020919959445599997*_t72*_t873 + _t73*_t923 + _t73*_t926 - _t79*_t927 + _t836*_t874 + _t846*_t867 + _t846*_t871 - _t855*_t924 + 0.0124484*_t921*params->d[1] + 0.019917439999999998*_t921*params->d[2] - _t924*_t925) + _t234*_t564 + _t234*_t565 - _t321*_t546));
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = 0;
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t5, 0, 0.2e1*_t563 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(0.019917439999999998*_t148*_t152*params->d[1] - 0.64e2 / 0.3e1*_t148*_t153 - 0.00011157311704319999*_t152*_t473 - 0.00037191039014399993*_t152*_t484 - 0.00044629246817279994*_t152*_t486 + 0.089628479999999983*_t152*_t538 - 5.5786558521599993e-5*_t152*_t847 - 0.00014876415605759999*_t152*_t861 - 0.00027893279260799998*_t152*_t870 + 0.2e1*_t169*_t561 + _t17*_t628 + 0.00070662974127359986*_t175*_t337 + 0.0014132594825471997*_t180*_t337 + 8.3679837782399996e-5*_t19*_t857 + 0.00010459979722799998*_t19*_t873 + 0.00013946639630399999*_t19*_t874 - 0.01120356*_t19*_t922 - 0.014938079999999999*_t19*_t925 + _t20*_t923 + _t20*_t926 - _t232*_t933 + _t241*_t853 + _t241*_t862 + _t241*_t872 + _t245*_t398 - _t478*_t558 - _t481*_t558 + _t540*_t934 + _t542*_t935 + _t551*_t849 + _t551*_t852 + _t555*_t928 - _t556*_t927 - _t557*_t929 + _t559*_t867 + _t559*_t871 - 0.029876159999999999*_t6*_t930 + _t63*(-1.3504512652349827e-5*_t18*_t633 + 5.270120403695376e-8*_t348*_t845/xc_powr(n_s, 46, 3) + 0.001095872333221589*_t349*sigma_ss - 0.0045438389644383642*_t351) - _t931*_t936 + 0.00023554324709119994*_t932*params->d[0] - 0.25228757333333329*_t932*params->d[1]) + _t246*_t564 + _t246*_t565 - _t321*_t562));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t5, 0, 0.3e1*_t621 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t119*_t680 - 0.033195733333333331*_t139*_t249 - 0.14938080000000001*_t139*_t260 + _t148*_t330*_t75*params->d[2] + _t17*(-_t253*_t954 - _t322*_t667 - 0.7904e4 / 0.27e2*_t661) - _t178*_t947 - _t178*_t977 + _t251*_t942 + _t251*_t948 + _t251*_t959 + _t255*_t672 - _t256*_t582 + _t257*_t575 + _t257*_t962 + _t257*_t967 + _t257*_t971 - _t258*_t955 - _t259*_t958 - _t259*_t964 - _t259*_t968 + _t27*(-0.3146000e7 / 0.9e1*_t1000*_t194 - 0.715000e6 / 0.9e1*_t1000*_t35 - _t1001*_t750 - _t1001*_t775 - 0.20000e5 / 0.3e1*_t1002*_t204 - 0.50000e5 / 0.9e1*_t1002*_t205 - 0.10000e5 / 0.3e1*_t1002*_t423 - _t1003*_t757 - _t1003*_t764 - 0.80000e5 / 0.9e1*_t1004*params->a[4] - 0.50000e5 / 0.3e1*_t1004*params->a[5] - _t1005*_t760 - _t1005*_t770 - 0.175000e6 / 0.9e1*_t1006*_t516 - _t1007*_t763 - _t1007*_t773 - 0.35000e5*_t1008*params->a[6] - 0.245000e6 / 0.9e1*_t1008*params->a[7] - _t1009*_t1011 - 0.112000e6 / 0.3e1*_t1009*_t207 - 0.448000e6 / 0.9e1*_t1009*_t774 - _t1010*_t769 - _t1010*_t776 - 0.196000e6 / 0.3e1*_t1012*_t211 - 0.112000e6*_t1012*_t432 - 0.84000e5*_t1012*_t777 - 0.6560e4 / 0.9e1*_t152*_t278*_t39 - _t188*_t986 - 0.328000e6 / 0.27e2*_t190*_t983 - _t192*_t987 - _t193*_t987 - 0.396880e6 / 0.27e2*_t195*_t983 + (0.143000e6 / 0.3e1)*_t196*_t242*_t339*_t34*params->a[10] + 0.157300e6*_t196*_t242*_t339*_t34*params->a[11] - 0.72160e5 / 0.9e1*_t197*_t983 - _t198*_t982 - 0.3280e4 / 0.9e1*_t198*_t988 - 0.2000e4*_t200*_t984 - 0.6560e4 / 0.9e1*_t200*_t989 - 0.32800e5 / 0.27e2*_t204*_t990 - 0.82000e5 / 0.27e2*_t205*_t990 - _t209*_t993 - _t210*_t993 - 0.160720e6 / 0.27e2*_t212*_t983 - _t214*_t994 - _t215*_t994 - 0.320000e6 / 0.3e1*_t216*_t996 - 0.209920e6 / 0.27e2*_t217*_t983 - _t219*_t992 - _t220*_t992 - 0.165000e6*_t221*_t997 - 0.9840e4*_t222*_t983 - _t223*_t986 + (0.650e3 / 0.3e1)*_t242*_t29*_t339*_t46*params->a[1] + 0.1300e4*_t242*_t29*_t339*_t46*params->a[2] + 0.1950e4*_t242*_t29*_t339*_t46*params->a[3] + (0.2600e4 / 0.3e1)*_t242*_t29*_t339*_t46*params->a[4] + 0.26000e5*_t242*_t33*_t339*_t55*params->a[10] + 0.18200e5*_t242*_t33*_t339*_t55*params->a[7] + 0.62400e5*_t242*_t33*_t339*_t55*params->a[8] + 0.70200e5*_t242*_t33*_t339*_t55*params->a[9] + 0.97500e5*_t242*_t339*_t36*_t58*params->a[10] + 0.35750e5*_t242*_t339*_t36*_t58*params->a[11] + 0.26000e5*_t242*_t339*_t36*_t58*params->a[8] + 0.87750e5*_t242*_t339*_t36*_t58*params->a[9] + (0.185900e6 / 0.3e1)*_t242*_t339*_t37*_t418*params->a[11] + (0.2600e4 / 0.3e1)*_t242*_t339*_t39*_t48*params->a[2] + 0.3900e4*_t242*_t339*_t39*_t48*params->a[3] + 0.5200e4*_t242*_t339*_t39*_t48*params->a[4] + (0.6500e4 / 0.3e1)*_t242*_t339*_t39*_t48*params->a[5] + (0.6500e4 / 0.3e1)*_t242*_t339*_t42*_t51*params->a[3] + (0.26000e5 / 0.3e1)*_t242*_t339*_t42*_t51*params->a[4] + (0.32500e5 / 0.3e1)*_t242*_t339*_t42*_t51*params->a[5] + (0.13000e5 / 0.3e1)*_t242*_t339*_t42*_t51*params->a[6] + (0.650e3 / 0.3e1)*_t242*_t339*_t43*params->a[1] + (0.1300e4 / 0.3e1)*_t242*_t339*_t43*params->a[2] + (0.650e3 / 0.3e1)*_t242*_t339*_t43*params->a[3] + (0.13000e5 / 0.3e1)*_t242*_t339*_t45*_t54*params->a[4] + 0.16250e5*_t242*_t339*_t45*_t54*params->a[5] + 0.19500e5*_t242*_t339*_t45*_t54*params->a[6] + (0.22750e5 / 0.3e1)*_t242*_t339*_t45*_t54*params->a[7] + (0.22750e5 / 0.3e1)*_t242*_t339*_t49*_t57*params->a[5] + 0.27300e5*_t242*_t339*_t49*_t57*params->a[6] + 0.31850e5*_t242*_t339*_t49*_t57*params->a[7] + (0.36400e5 / 0.3e1)*_t242*_t339*_t49*_t57*params->a[8] + (0.36400e5 / 0.3e1)*_t242*_t339*_t52*_t60*params->a[6] + (0.127400e6 / 0.3e1)*_t242*_t339*_t52*_t60*params->a[7] + (0.145600e6 / 0.3e1)*_t242*_t339*_t52*_t60*params->a[8] + 0.18200e5*_t242*_t339*_t52*_t60*params->a[9] + (0.357500e6 / 0.3e1)*_t242*_t339*_t61*_t89*params->a[10] + (0.393250e6 / 0.3e1)*_t242*_t339*_t61*_t89*params->a[11] + 0.35750e5*_t242*_t339*_t61*_t89*params->a[9] - _t263*_t954 - 0.16000e5 / 0.9e1*_t279*_t984 - 0.52480e5 / 0.27e2*_t279*_t989 - 0.32800e5 / 0.27e2*_t284*_t989 - _t287*_t991 - _t289*_t991 + (0.440e3 / 0.27e2)*_t29*_t322*_t40*params->a[1] + (0.880e3 / 0.27e2)*_t29*_t322*_t40*params->a[2] - _t290*_t992 + (0.440e3 / 0.27e2)*_t31*_t322*params->a[1] + (0.4400e4 / 0.27e2)*_t322*_t33*_t61*params->a[10] + (0.440e3 / 0.3e1)*_t322*_t33*_t61*params->a[9] + (0.4400e4 / 0.27e2)*_t322*_t34*_t36*params->a[10] + (0.4840e4 / 0.27e2)*_t322*_t34*_t36*params->a[11] + (0.4840e4 / 0.27e2)*_t322*_t37*_t89*params->a[11] + (0.880e3 / 0.27e2)*_t322*_t39*_t43*params->a[2] + (0.440e3 / 0.9e1)*_t322*_t39*_t43*params->a[3] + (0.440e3 / 0.9e1)*_t322*_t42*_t46*params->a[3] + (0.1760e4 / 0.27e2)*_t322*_t42*_t46*params->a[4] + (0.1760e4 / 0.27e2)*_t322*_t45*_t48*params->a[4] + (0.2200e4 / 0.27e2)*_t322*_t45*_t48*params->a[5] + (0.2200e4 / 0.27e2)*_t322*_t49*_t51*params->a[5] + (0.880e3 / 0.9e1)*_t322*_t49*_t51*params->a[6] + (0.880e3 / 0.9e1)*_t322*_t52*_t54*params->a[6] + (0.3080e4 / 0.27e2)*_t322*_t52*_t54*params->a[7] + (0.3080e4 / 0.27e2)*_t322*_t55*_t57*params->a[7] + (0.3520e4 / 0.27e2)*_t322*_t55*_t57*params->a[8] + (0.3520e4 / 0.27e2)*_t322*_t58*_t60*params->a[8] + (0.440e3 / 0.3e1)*_t322*_t58*_t60*params->a[9] - 0.275000e6*_t413*_t997 - 0.1210000e7 / 0.3e1*_t417*_t998 - 0.180000e6*_t434*_t996 - _t47*_t981 - _t490*_t981 - 0.55000e5*_t62*_t998 - _t686*_t979 - _t688*_t979 - _t690*_t979 - 0.3280e4 / 0.9e1*_t692*_t983 - _t737*_t981 - 0.8000e4 / 0.9e1*_t738*_t980 - _t741*_t985 - _t743*_t995 - 0.400000e6 / 0.3e1*_t745*_t996 - 0.605000e6 / 0.3e1*_t751*_t997 - 0.1001000e7 / 0.9e1*_t752*_t980 - _t753*_t985 - 0.40000e5 / 0.3e1*_t765*_t980 - _t772*_t995 - _t95*_t982 - 0.3280e4 / 0.3e1*_t95*_t988 - _t998*_t999) + _t297*_t681 - 0.880e3 / 0.27e2*_t322*_t67 + 0.18257653333333332*_t322*_t78 + _t446*_t670 + _t479*_t574 + _t479*_t580 + _t479*_t950 - _t483*_t965 + _t567*_t944 + _t567*_t956 + _t567*_t963 + _t569*_t938 + _t569*_t945 + _t571*_t583 + _t572*_t597 - _t573*_t941 - _t576*_t941 + _t577*_t949 + _t578*_t656 - _t579*_t955 + _t581*_t583 + _t583*_t970 - _t584*_t858 + _t585*_t863 + _t586*_t949 + 0.031120999999999999*_t587*_t6 - _t588*_t966 - _t588*_t972 + _t589*_t859 + _t619*_t682 + 0.060858844444444435*_t622 - 0.033195733333333331*_t624 - 0.099587199999999987*_t626 + 0.12171768888888887*_t627 + _t659*_t76 + _t671*_t864 + _t674*_t732 + _t675*_t798 - _t70*_t940 - _t70*_t943 - _t79*_t946 - _t79*_t957 - _t79*_t969 - 0.056017799999999993*_t8*_t978 - _t869*_t973 + _t949*_t974 - _t951*_t952 - _t951*_t953 - _t960*_t961 - _t960*_t975 - _t960*_t976) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t298*_t315 + (0.1e1 / 0.12e2)*_hc0[5]*_t10*_t298*_t318*_t6 - _t120*_t641 - _t120*_t643 - _t120*_t937 - _t620*_t644));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = 0;
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t5, 0, 0.3e1*_t637 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-_t1013*_t249 - _t1013*_t568 + _t1014*_t938 + _t1014*_t945 - _t1015*_t573 - _t1015*_t576 + _t1016*_t301 + _t1017*_t577 + _t1017*_t586 + _t1017*_t974 - _t1018*_t952 - _t1018*_t953 - _t1019*_t258 - _t1019*_t579 - _t1020*_t961 - _t1020*_t975 - _t1020*_t976 + _t125*_t659 - _t126*_t946 - _t126*_t957 - _t126*_t969 + _t132*_t726 + 0.024896799999999997*_t139*_t587 - _t14*_t645*_t649 + 0.3e1*_t169*_t634 + _t17*(-_t645*_t666 - _t660*_t662 - 0.13376e5 / 0.27e2*_t664*sigma_ss) + (0.88e2 / 0.3e1)*_t250*_t322*params->d[1] - _t252*_t933 - _t256*_t630 - 0.16431888*_t260*_t322 + _t301*_t942 + _t301*_t948 + _t301*_t959 - _t302*_t940 - _t302*_t943 + _t306*_t672 + _t307*_t575 + _t307*_t962 + _t307*_t967 + _t307*_t971 - _t308*_t958 - _t308*_t964 - _t308*_t968 + 0.3e1*_t311*_t398 + _t445*_t670 + _t555*_t574 + _t555*_t580 + _t555*_t950 - _t556*_t947 - _t556*_t977 - _t557*_t965 + _t571*_t631 + _t581*_t631 - _t584*_t933 + _t585*_t935 + _t589*_t934 - 0.028008899999999996*_t6*_t978 + _t623*_t944 + _t623*_t956 + _t623*_t963 + _t629*_t656 + _t63*(4.273428003765812e-5*_t1*_t348*_t466*_t467*_t678 + 0.030252401526392267*_t10*_t128*_t129*_t663*sigma_ss - 0.0044841083495094959*_t18*_t676 - _t645*_t677 - 1.4053654409854336e-7*_t679*_t845/xc_powr(n_s, 49, 3)) + _t631*_t970 - _t632*_t966 - _t632*_t972 + 0.08520238222222222*_t645*_t66 + 0.17040476444444444*_t645*_t69 + 0.25560714666666667*_t645*_t78 + _t671*_t928 + _t674*_t781 + _t675*_t833 - _t936*_t973) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t312*_t315 + (0.1e1 / 0.12e2)*_hc0[5]*_t10*_t312*_t318*_t6 - _t133*_t641 - _t133*_t643 - _t133*_t937 - _t636*_t644));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t5, 0, 0.4e1*_t728 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t1016*_t248 + _t14*(_t1023*params->d[1] + _t1024*params->d[2]) + 0.4e1*_t148*_t668 + 0.4e1*_t156*_t659 + 0.4e1*_t158*_t726 + _t16*_t655*_t656 + 0.4e1*_t169*_t680 + _t17*(_t1023*_t21 + (0.167200e6 / 0.81e2)*_t1025*params->d[3] + _t1026*_t340 + _t1027*_t74 + (0.44000e5 / 0.27e2)*_t663*params->d[4]*sigma_ss*tau_s) + _t248*_t942 + _t248*_t948 + 0.4e1*_t250*_t651 + 0.4e1*_t252*_t655 + _t258*(0.34080952888888888*_t646 + 0.24343537777777774*_t647) + _t27*(-_t101*_t1042 - _t1011*_t1073 - _t102*_t1042 - _t1024*_t358 - _t1024*_t92 + _t1026*_t359 - _t1027*_t97 - _t1027*_t99 - _t1028*_t32 - _t1028*_t356 + (0.40000e5 / 0.27e2)*_t1029*_t738 + (0.5005000e7 / 0.27e2)*_t1029*_t752 + (0.200000e6 / 0.9e1)*_t1029*_t765 + _t1030*_t47 + _t1030*_t490 + _t1030*_t737 + _t1031*_t198 + _t1031*_t95 - 0.1144000e7 / 0.9e1*_t1032*_t419 - 0.8000e4 / 0.3e1*_t1032*_t492 - 0.100000e6 / 0.3e1*_t1032*_t517 - 0.40000e5*_t1032*_t521 - 0.4000e4*_t1032*_t601 - 0.8000e4 / 0.9e1*_t1032*_t91 - _t1033*_t183 - _t1033*_t44 - _t1033*_t491 + (0.2720000e7 / 0.81e2)*_t1034*_t190 + (0.3291200e7 / 0.81e2)*_t1034*_t195 + (0.598400e6 / 0.27e2)*_t1034*_t197 + (0.1332800e7 / 0.81e2)*_t1034*_t212 + (0.1740800e7 / 0.81e2)*_t1034*_t217 + 0.27200e5*_t1034*_t222 + (0.27200e5 / 0.27e2)*_t1034*_t692 + _t1035*_t184 + _t1035*_t41 + _t1035*_t80 + (0.10000e5 / 0.3e1)*_t1036*_t200 + (0.80000e5 / 0.27e2)*_t1036*_t279 + _t1037*_t741 + _t1037*_t753 - _t1038*_t507 - _t1038*_t602 - _t1039*_t84 - _t1039*_t85 - _t1040*_t88 - _t1040*_t90 - _t1041*_t94 - _t1041*_t96 - _t1043*_t105 - _t1043*_t106 - _t1044*_t109 - _t1044*_t110 - _t1045*_t113 - _t1045*_t114 - _t1046*_t117 - _t1046*_t118 + _t1047*_t743 + _t1047*_t772 + (0.1600000e7 / 0.9e1)*_t1048*_t216 + 0.300000e6*_t1048*_t434 + (0.2000000e7 / 0.9e1)*_t1048*_t745 + 0.275000e6*_t1049*_t221 + (0.1375000e7 / 0.3e1)*_t1049*_t413 + (0.3025000e7 / 0.9e1)*_t1049*_t751 + (0.11000000e8 / 0.27e2)*_t1050*_t189 + (0.6050000e7 / 0.9e1)*_t1050*_t417 + (0.275000e6 / 0.3e1)*_t1050*_t62 + (0.15730000e8 / 0.27e2)*_t1051*_t194 + (0.3575000e7 / 0.27e2)*_t1051*_t35 + _t1052*_t750 + _t1052*_t775 + (0.100000e6 / 0.9e1)*_t1053*_t204 + (0.250000e6 / 0.27e2)*_t1053*_t205 + (0.50000e5 / 0.9e1)*_t1053*_t423 + _t1054*_t757 + _t1054*_t764 + (0.400000e6 / 0.27e2)*_t1055*params->a[4] + (0.250000e6 / 0.9e1)*_t1055*params->a[5] + _t1056*_t760 + _t1056*_t770 + (0.875000e6 / 0.27e2)*_t1057*_t516 + _t1058*_t763 + _t1058*_t773 + (0.175000e6 / 0.3e1)*_t1059*params->a[6] + (0.1225000e7 / 0.27e2)*_t1059*params->a[7] + (0.560000e6 / 0.9e1)*_t1060*_t207 + (0.980000e6 / 0.9e1)*_t1060*_t429 + (0.2240000e7 / 0.27e2)*_t1060*_t774 + _t1061*_t769 + _t1061*_t776 + (0.980000e6 / 0.9e1)*_t1062*_t211 + (0.560000e6 / 0.3e1)*_t1062*_t432 + 0.140000e6*_t1062*_t777 - _t1063*_t411 - _t1063*_t530 - 0.180000e6*_t1064*_t221 - 0.200000e6*_t1064*_t413 - 0.2420000e7 / 0.9e1*_t1065*_t417 - _t1065*_t999 - 0.968000e6 / 0.3e1*_t1066*_t194 - 0.880000e6 / 0.9e1*_t1066*_t35 - _t1067*_t416 - _t1067*_t531 - 0.8000e4*_t1068*_t200 - 0.32000e5 / 0.3e1*_t1068*_t279 - _t1069*_t509 - _t1069*_t515 - 0.160000e6 / 0.9e1*_t1070*_t204 - 0.200000e6 / 0.9e1*_t1070*_t205 - _t1071*_t513 - _t1071*_t520 - _t1072*_t518 - _t1072*_t525 - 0.56000e5*_t1073*_t207 - _t1074*_t431 - _t1074*_t523 - 0.784000e6 / 0.9e1*_t1075*_t211 - 0.896000e6 / 0.9e1*_t1075*_t432 - _t1076*_t433 - _t1076*_t527 - 0.128000e6*_t1077*_t216 - 0.144000e6*_t1077*_t434 + _t1078*_t188 + _t1078*_t223 + _t1079*_t192 + _t1079*_t193 + (0.27200e5 / 0.27e2)*_t1080*_t198 + (0.54400e5 / 0.27e2)*_t1080*_t47 + (0.27200e5 / 0.9e1)*_t1080*_t95 + (0.54400e5 / 0.27e2)*_t1081*_t200 + (0.435200e6 / 0.81e2)*_t1081*_t279 + (0.272000e6 / 0.81e2)*_t1081*_t284 + (0.272000e6 / 0.81e2)*_t1082*_t204 + (0.680000e6 / 0.81e2)*_t1082*_t205 + _t1083*_t287 + _t1083*_t289 + _t1084*_t219 + _t1084*_t220 + _t1084*_t290 + _t1085*_t209 + _t1085*_t210 + _t1086*_t214 + _t1086*_t215) + 0.6e1*_t328*_t576 + 0.4e1*_t329*_t333 + 0.6e1*_t330*_t574 + 0.8e1*_t330*_t950 + _t331*_t659 + 0.8e1*_t332*_t974 + 0.6e1*_t333*_t344 + _t346*_t853 + 0.4e1*_t346*_t857 + 0.6e1*_t346*_t872 + 0.6e1*_t352*_t398 + _t481*_t670 + 0.4e1*_t486*_t670 + 0.3e1*_t570*_t573 + 0.3e1*_t584*_t658 + 0.3e1*_t585*_t669 + _t587*(-0.091288266666666645*_t323 - 0.082989333333333332*_t324) + _t63*(1.9014441142090316*_t1021*_t127 - 0.12144804670740084*_t1025*_t130 + 0.014949944324933773*_t243*_t348/xc_powi(n_s, 12) - 0.00012548193089709351*_t468*_t679/xc_powr(n_s, 44, 3) + 3.7476411759611562e-7*_t845*xc_powi(sigma_ss, 5)/xc_powr(n_s, 52, 3)) + _t652*_t656 + _t653*_t963 + _t654*_t939 + _t657*_t672 + _t66*(-0.48281349925925926*_t1021 - 0.28400794074074071*_t1022) + _t671*_t962 + 0.2e1*_t673*_t972 + 0.3e1*_t673*_t973 + _t674*_t799 + 0.4e1*_t674*_t802 + _t69*(-0.96562699851851852*_t1021 - 0.56801588148148141*_t1022) + _t78*(-1.4484404977777778*_t1021 - 0.85202382222222217*_t1022) + _t977*(0.029876159999999999*_t140 + 0.037345200000000002*_t141)) + (0.1e1 / 0.216e3)*_hc0[14]*_t19*_t23*_t64 + _hc0[9]*_t314*_t401*_t638 + (0.140e3 / 0.81e2)*_t136*_t64*_t72 - 0.2e1 / 0.3e1*_t137*_t727 - 0.1e1 / 0.9e1*_t170*_t639 - 0.56e2 / 0.27e2*_t170*_t640 - 0.4e1 / 0.9e1*_t170*_t642 + (0.4e1 / 0.3e1)*_t316*_t399 + (0.40e2 / 0.81e2)*_t319*_t322*_t64 + (0.1e1 / 0.6e1)*_t320*_t399));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_m06l_params *params = (const mgga_x_m06l_params *)(p->params);
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