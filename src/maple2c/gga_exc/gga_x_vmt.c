/*
  Generated from python/gga_exc/gga_x_vmt.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_vmt
*/

#ifndef _GGA_X_VMT_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_VMT_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_VMT_HELPER_BODIES
#include "gga_x_vmt.c"
#undef _GGA_X_VMT_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_VMT_HELPER_BODIES
#include "gga_x_vmt.c"
#undef _GGA_X_VMT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_VMT_HELPER_BODIES
#include "gga_x_vmt.c"
#undef _GGA_X_VMT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_VMT_HELPER_BODIES
#include "gga_x_vmt.c"
#undef _GGA_X_VMT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_VMT_HELPER_BODIES
#include "gga_x_vmt.c"
#undef _GGA_X_VMT_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_vmt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_vmt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_vmt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_vmt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_vmt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_vmt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_vmt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_vmt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_vmt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_vmt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_VMT_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double *out) {
  const gga_x_vmt_params *params = (const gga_x_vmt_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = -p->dens_threshold + n_s <= 0;
  const double _t6 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t7 = _t1*_t6;
  const double _t8 = params->mu*sigma_ss;
  const double _t9 = _t7*_t8;
  const double _t10 = xc_powr(n_s, -8, 3);
  const double _t11 = (0.1e1 / 0.24e2)*_t10;
  const double _t12 = _t11*_t9;
  const double _t13 = params->alpha*sigma_ss;
  const double _t14 = exp(-_t11*_t13*_t7);
  const double _t15 = _t12 + 0.1e1;
  const double _t16 = (0.1e1 / _t15);
  const double _t17 = _t14*_t16;
  const double _t18 = _t12*_t17 + 0.1e1;
#if _KMAX >= 1
  const double _t20 = xc_powr(n_s, -16, 3);
  const double _t21 = (0.1e1 / 0.576e3)*_t20;
  const double _t22 = xc_powr(0.6e1, 2, 3);
  const double _t23 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t24 = _t22*_t23;
  const double _t25 = _t17*_t8;
  const double _t26 = _t24*_t25*params->alpha;
  const double _t27 = (0.1e1 / (_t15 * _t15));
  const double _t28 = ((params->mu) * (params->mu));
  const double _t29 = _t27*_t28;
  const double _t30 = _t14*_t29;
  const double _t31 = _t24*_t30;
  const double _t32 = (0.1e1 / 0.24e2)*_t1*_t10*_t14*_t16*_t6*params->mu - _t21*_t26 - _t21*_t31*sigma_ss;
  const double _t34 = xc_powr(n_s, -4, 3);
  const double _t38 = xc_powr(n_s, -11, 3);
  const double _t39 = (0.1e1 / 0.9e1)*_t38;
  const double _t40 = _t17*_t9;
  const double _t41 = (sigma_ss * sigma_ss);
  const double _t42 = (0.1e1 / 0.216e3)*_t41;
  const double _t43 = xc_powr(n_s, -19, 3);
  const double _t44 = _t16*params->mu;
  const double _t45 = _t14*_t44;
  const double _t46 = _t45*params->alpha;
  const double _t47 = _t24*_t46;
  const double _t48 = _t43*_t47;
  const double _t49 = _t31*_t43;
  const double _t50 = -_t39*_t40 + _t42*_t48 + _t42*_t49;
#endif
#if _KMAX >= 2
  const double _t52 = xc_powi(n_s, -8);
  const double _t53 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t54 = _t14*_t53;
  const double _t55 = _t52*_t54;
  const double _t56 = (0.1e1 / 0.1152e4)*_t55;
  const double _t57 = (0.1e1 / (_t15 * _t15 * _t15));
  const double _t58 = ((params->mu) * (params->mu) * (params->mu));
  const double _t59 = _t57*_t58;
  const double _t60 = _t59*sigma_ss;
  const double _t61 = (0.1e1 / 0.288e3)*_t20*_t24;
  const double _t62 = _t13*_t29;
  const double _t63 = ((params->alpha) * (params->alpha));
  const double _t64 = _t16*_t63*_t8;
  const double _t65 = -_t30*_t61 - _t46*_t61 + (0.1e1 / 0.2304e4)*_t55*_t64 + _t56*_t60 + _t56*_t62;
  const double _t67 = _t45*_t7;
  const double _t68 = xc_powi(n_s, -9);
  const double _t69 = _t54*_t59;
  const double _t70 = _t68*_t69;
  const double _t71 = (0.1e1 / 0.432e3)*_t41;
  const double _t72 = _t29*params->alpha;
  const double _t73 = _t54*_t68;
  const double _t74 = _t72*_t73;
  const double _t75 = _t44*_t63;
  const double _t76 = _t73*_t75;
  const double _t77 = (0.1e1 / 0.72e2)*_t14*_t16*_t22*_t23*_t43*params->alpha*params->mu*sigma_ss + (0.1e1 / 0.72e2)*_t14*_t22*_t23*_t27*_t28*_t43*sigma_ss - _t39*_t67 - 0.1e1 / 0.864e3*_t41*_t76 - _t70*_t71 - _t71*_t74;
  const double _t79 = (0.2e1 / 0.9e1)*_t18;
  const double _t80 = xc_powr(n_s, -7, 3);
  const double _t82 = (0.1e1 / 0.36e2)*_t18;
  const double _t83 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t87 = xc_powr(n_s, -14, 3);
  const double _t88 = xc_powi(n_s, -10);
  const double _t89 = _t69*_t88;
  const double _t90 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t91 = (0.1e1 / 0.162e3)*_t90;
  const double _t92 = _t54*_t88;
  const double _t93 = (0.1e1 / 0.24e2)*_t41;
  const double _t94 = xc_powr(n_s, -22, 3);
  const double _t95 = _t47*_t94;
  const double _t96 = _t31*_t94;
  const double _t97 = (0.11e2 / 0.27e2)*_t40*_t87 + _t72*_t91*_t92 + (0.1e1 / 0.324e3)*_t75*_t90*_t92 + _t89*_t91 - _t93*_t95 - _t93*_t96;
#endif
#if _KMAX >= 3
  const double _t99 = (0.1e1 / (_t15 * _t15 * _t15 * _t15));
  const double _t100 = ((params->mu) * (params->mu) * (params->mu) * (params->mu));
  const double _t101 = _t100*_t14*_t99;
  const double _t102 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t103 = _t1*_t102;
  const double _t104 = _t103/xc_powr(n_s, 32, 3);
  const double _t105 = (0.1e1 / 0.9216e4)*_t104;
  const double _t106 = _t14*_t59;
  const double _t107 = ((params->alpha) * (params->alpha) * (params->alpha));
  const double _t108 = _t104*_t107;
  const double _t109 = _t30*_t63;
  const double _t110 = _t104*_t109;
  const double _t111 = -_t101*_t105*sigma_ss - _t105*_t106*_t13 - 0.1e1 / 0.55296e5*_t108*_t25 - 0.1e1 / 0.18432e5*_t110*sigma_ss + (0.1e1 / 0.768e3)*_t14*_t16*_t52*_t53*_t63*params->mu + (0.1e1 / 0.384e3)*_t14*_t27*_t28*_t52*_t53*params->alpha + (0.1e1 / 0.384e3)*_t14*_t52*_t53*_t57*_t58;
  const double _t113 = _t101*_t103;
  const double _t114 = _t113*_t41;
  const double _t115 = xc_powr(n_s, -35, 3);
  const double _t116 = (0.1e1 / 0.3456e4)*_t115;
  const double _t117 = _t106*params->alpha;
  const double _t118 = _t103*_t117;
  const double _t119 = _t118*_t41;
  const double _t120 = (0.1e1 / 0.20736e5)*_t41;
  const double _t121 = _t103*_t115;
  const double _t122 = _t107*_t45;
  const double _t123 = (0.1e1 / 0.6912e4)*_t109*_t121*_t41 + _t114*_t116 + _t116*_t119 + _t120*_t121*_t122 + (0.1e1 / 0.54e2)*_t48 + (0.1e1 / 0.54e2)*_t49 - 0.5e1 / 0.432e3*_t62*_t73 - 0.5e1 / 0.864e3*_t64*_t73 - 0.5e1 / 0.432e3*_t70*sigma_ss;
  const double _t126 = (0.1e1 / 0.36e2)*_t32;
  const double _t127 = xc_powr(n_s, -38, 3);
  const double _t128 = (0.1e1 / 0.1296e4)*_t127;
  const double _t129 = (0.1e1 / 0.7776e4)*_t90;
  const double _t130 = _t103*_t127;
  const double _t131 = _t122*_t130;
  const double _t132 = _t109*_t130;
  const double _t133 = (0.11e2 / 0.27e2)*_t1*_t14*_t16*_t6*_t87*params->mu - _t113*_t128*_t90 - _t118*_t128*_t90 - _t129*_t131 - 0.1e1 / 0.2592e4*_t132*_t90 + (0.17e2 / 0.864e3)*_t14*_t16*_t41*_t53*_t63*_t88*params->mu + (0.17e2 / 0.432e3)*_t14*_t27*_t28*_t41*_t53*_t88*params->alpha + (0.17e2 / 0.432e3)*_t14*_t41*_t53*_t57*_t58*_t88 - 0.65e2 / 0.648e3*_t26*_t94 - 0.65e2 / 0.648e3*_t96*sigma_ss;
  const double _t135 = (0.1e1 / M_PI);
  const double _t142 = (0.154e3 / 0.81e2)/xc_powr(n_s, 17, 3);
  const double _t143 = xc_powi(n_s, -11);
  const double _t144 = _t143*_t69;
  const double _t145 = (0.19e2 / 0.162e3)*_t90;
  const double _t146 = _t143*_t54;
  const double _t147 = _t146*_t72;
  const double _t148 = _t146*_t75;
  const double _t149 = xc_powr(n_s, -25, 3);
  const double _t150 = (0.341e3 / 0.972e3)*_t149;
  const double _t151 = _t41*_t47;
  const double _t152 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t153 = _t113*_t152;
  const double _t154 = xc_powr(n_s, -41, 3);
  const double _t155 = (0.1e1 / 0.486e3)*_t154;
  const double _t156 = _t31*_t41;
  const double _t157 = _t118*_t152;
  const double _t158 = (0.1e1 / 0.2916e4)*_t152;
  const double _t159 = _t103*_t154;
  const double _t160 = (0.1e1 / 0.972e3)*_t109*_t152*_t159 + _t122*_t158*_t159 - _t142*_t40 - _t144*_t145 - _t145*_t147 - 0.19e2 / 0.324e3*_t148*_t90 + _t150*_t151 + _t150*_t156 + _t153*_t155 + _t155*_t157;
#endif
#if _KMAX >= 4
  const double _t162 = (0.1e1 / 0.2304e4)*_t104;
  const double _t163 = _t22/(M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t164 = _t163/xc_powr(n_s, 40, 3);
  const double _t165 = (0.1e1 / 0.55296e5)*_t164;
  const double _t166 = _t14*xc_powi((params->mu), 5)/xc_powi(_t15, 5);
  const double _t167 = ((params->alpha) * (params->alpha) * (params->alpha) * (params->alpha));
  const double _t168 = _t107*_t30;
  const double _t169 = _t163*_t166;
  const double _t170 = xc_powr(n_s, -43, 3);
  const double _t171 = _t120*_t170;
  const double _t172 = _t101*_t163*params->alpha;
  const double _t173 = _t163*_t170*_t41;
  const double _t174 = _t167*_t45;
  const double _t175 = _t106*_t63;
  const double _t176 = (0.25e2 / 0.3456e4)*_t127;
  const double _t177 = xc_powr(n_s, -46, 3);
  const double _t178 = _t129*_t177;
  const double _t179 = _t177*_t90;
  const double _t180 = _t163*_t179;
  const double _t181 = _t163*_t175;
  const double _t182 = (0.1025e4 / 0.1944e4)*_t41;
  const double _t183 = xc_powr(n_s, -49, 3);
  const double _t184 = _t158*_t183;
  const double _t185 = _t152*_t183;
  const double _t186 = _t163*_t185;
  const double _t187 = _t90/xc_powi(n_s, 12);
  const double _t188 = (0.2563e4 / 0.1458e4)*_t187;
  const double _t189 = (0.3047e4 / 0.972e3)/xc_powr(n_s, 28, 3);
  const double _t190 = xc_powr(n_s, -44, 3);
  const double _t191 = (0.49e2 / 0.729e3)*_t190;
  const double _t192 = xc_powi(sigma_ss, 5)/xc_powr(n_s, 52, 3);
  const double _t193 = (0.2e1 / 0.2187e4)*_t192;
  const double _t194 = _t103*_t152*_t190;
  const double _t195 = _t163*_t192;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t5)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  const double _t19 = my_piecewise3(_t5, 0, _hc0[0]*_t18);
#if _KMAX >= 1
  const double _t33 = my_piecewise3(_t5, 0, _hc0[0]*_t32);
  const double _t35 = _hc0[2]*_t3;
  const double _t36 = _t34*_t35;
  const double _t37 = (0.1e1 / 0.6e1)*_t36;
  const double _t51 = my_piecewise3(_t5, 0, _hc0[0]*_t50 - _t18*_t37);
#endif
#if _KMAX >= 2
  const double _t66 = my_piecewise3(_t5, 0, _hc0[0]*_t65);
  const double _t78 = my_piecewise3(_t5, 0, _hc0[0]*_t77 - _t32*_t37);
  const double _t81 = _t35*_t80;
  const double _t84 = _hc0[5]*_t22*_t83;
  const double _t85 = _t10*_t84;
  const double _t86 = (0.1e1 / 0.3e1)*_t36;
  const double _t98 = my_piecewise3(_t5, 0, _hc0[0]*_t97 - _t50*_t86 + _t79*_t81 + _t82*_t85);
#endif
#if _KMAX >= 3
  const double _t112 = my_piecewise3(_t5, 0, _hc0[0]*_t111);
  const double _t124 = my_piecewise3(_t5, 0, _hc0[0]*_t123 - _t37*_t65);
  const double _t125 = (0.2e1 / 0.9e1)*_t81;
  const double _t134 = my_piecewise3(_t5, 0, _hc0[0]*_t133 + _t125*_t32 + _t126*_t85 - _t77*_t86);
  const double _t136 = _hc0[9]*_t135/(n_s * n_s * n_s * n_s);
  const double _t137 = _t35/xc_powr(n_s, 10, 3);
  const double _t138 = (0.14e2 / 0.27e2)*_t137;
  const double _t139 = _t38*_t84;
  const double _t140 = (0.1e1 / 0.9e1)*_t139;
  const double _t141 = _hc0[2]*_t34*_t4;
  const double _t161 = my_piecewise3(_t5, 0, _hc0[0]*_t160 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t50*_t80 + (0.1e1 / 0.12e2)*_hc0[5]*_t10*_t22*_t50*_t83 - _t136*_t82 - _t138*_t18 - _t140*_t18 - _t141*_t97);
#endif

  const double f = my_piecewise3(_t5, 0, _t19*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t5, 0, _t33*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t5, 0, _t19 + _t51*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t5, 0, _t66*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t5, 0, _t33 + _t78*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t5, 0, 0.2e1*_t51 + _t98*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t5, 0, _t112*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t5, 0, _t124*n_s + _t66);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t5, 0, _t134*n_s + 0.2e1*_t78);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t5, 0, _t161*n_s + 0.3e1*_t98);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t101*_t13*_t165 - _t101*_t162 - 0.1e1 / 0.13824e5*_t108*_t45 - 0.1e1 / 0.4608e4*_t110 - _t117*_t162 + (0.1e1 / 0.110592e6)*_t14*_t164*_t60*_t63 + (0.1e1 / 0.1327104e7)*_t164*_t167*_t25 + (0.1e1 / 0.331776e6)*_t164*_t168*sigma_ss + _t165*_t166*sigma_ss)));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t5, 0, _t112 + n_s*my_piecewise3(_t5, 0, _hc0[0]*((0.7e1 / 0.3456e4)*_t1*_t100*_t102*_t115*_t14*_t99*sigma_ss + (0.7e1 / 0.20736e5)*_t1*_t102*_t107*_t115*_t14*_t16*params->mu*sigma_ss + (0.7e1 / 0.6912e4)*_t1*_t102*_t115*_t14*_t27*_t28*_t63*sigma_ss + (0.7e1 / 0.3456e4)*_t1*_t102*_t115*_t14*_t57*_t58*params->alpha*sigma_ss - 0.1e1 / 0.124416e6*_t168*_t173 - _t169*_t171 - _t171*_t172 - 0.1e1 / 0.497664e6*_t173*_t174 - 0.1e1 / 0.41472e5*_t173*_t175 - 0.1e1 / 0.48e2*_t70 - 0.1e1 / 0.48e2*_t74 - 0.1e1 / 0.96e2*_t76) - _t111*_t37));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t5, 0, 0.2e1*_t124 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-_t114*_t176 - _t119*_t176 - 0.25e2 / 0.20736e5*_t131*_t41 - 0.25e2 / 0.6912e4*_t132*_t41 + (0.1e1 / 0.46656e5)*_t168*_t180 + _t169*_t178 + _t172*_t178 + (0.1e1 / 0.186624e6)*_t174*_t180 + (0.1e1 / 0.15552e5)*_t179*_t181 + (0.167e3 / 0.1296e4)*_t62*_t92 + (0.167e3 / 0.2592e4)*_t64*_t92 + (0.167e3 / 0.1296e4)*_t89*sigma_ss - 0.19e2 / 0.162e3*_t95 - 0.19e2 / 0.162e3*_t96) - _t123*_t86 + _t125*_t65 + (0.1e1 / 0.36e2)*_t65*_t85));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t5, 0, 0.3e1*_t134 + n_s*my_piecewise3(_t5, 0, _hc0[0]*((0.89e2 / 0.3888e4)*_t1*_t100*_t102*_t14*_t154*_t90*_t99 + (0.89e2 / 0.23328e5)*_t1*_t102*_t107*_t14*_t154*_t16*_t90*params->mu + (0.89e2 / 0.7776e4)*_t1*_t102*_t14*_t154*_t27*_t28*_t63*_t90 + (0.89e2 / 0.3888e4)*_t1*_t102*_t14*_t154*_t57*_t58*_t90*params->alpha + (0.253e3 / 0.324e3)*_t14*_t149*_t16*_t22*_t23*params->alpha*params->mu*sigma_ss + (0.253e3 / 0.324e3)*_t14*_t149*_t22*_t23*_t27*_t28*sigma_ss - _t142*_t67 - _t144*_t182 - _t147*_t182 - 0.1025e4 / 0.3888e4*_t148*_t41 - 0.1e1 / 0.17496e5*_t168*_t186 - _t169*_t184 - _t172*_t184 - 0.1e1 / 0.69984e5*_t174*_t186 - 0.1e1 / 0.5832e4*_t181*_t185) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t77*_t80 + (0.1e1 / 0.12e2)*_hc0[5]*_t10*_t22*_t77*_t83 - _t126*_t136 - _t133*_t141 - _t138*_t32 - _t140*_t32));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t5, 0, 0.4e1*_t161 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-0.49e2 / 0.1458e4*_t109*_t194 - 0.49e2 / 0.4374e4*_t122*_t194 - _t151*_t189 - _t153*_t191 - _t156*_t189 - _t157*_t191 + (0.1e1 / 0.6561e4)*_t168*_t195 + _t169*_t193 + _t172*_t193 + (0.1e1 / 0.26244e5)*_t174*_t195 + (0.1e1 / 0.2187e4)*_t181*_t192 + (0.2563e4 / 0.2916e4)*_t187*_t54*_t75 + _t188*_t54*_t72 + _t188*_t69 + (0.2618e4 / 0.243e3)*_t40/xc_powr(n_s, 20, 3)) + (0.1e1 / 0.216e3)*_hc0[14]*_t18*_t20*_t7 + _hc0[9]*_t135*_t79/xc_powi(n_s, 5) - 0.1e1 / 0.9e1*_t136*_t50 - 0.56e2 / 0.27e2*_t137*_t50 - 0.4e1 / 0.9e1*_t139*_t50 - 0.2e1 / 0.3e1*_t160*_t36 + (0.140e3 / 0.81e2)*_t18*_t35/xc_powr(n_s, 13, 3) + (0.40e2 / 0.81e2)*_t18*_t84*_t87 + (0.4e1 / 0.3e1)*_t81*_t97 + (0.1e1 / 0.6e1)*_t85*_t97));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_x_vmt_params *params = (const gga_x_vmt_params *)(p->params);
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