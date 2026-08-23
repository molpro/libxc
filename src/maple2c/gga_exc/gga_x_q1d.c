/*
  Generated from python/gga_exc/gga_x_q1d.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_q1d
*/

#ifndef _GGA_X_Q1D_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_Q1D_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_Q1D_HELPER_BODIES
#include "gga_x_q1d.c"
#undef _GGA_X_Q1D_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_Q1D_HELPER_BODIES
#include "gga_x_q1d.c"
#undef _GGA_X_Q1D_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_Q1D_HELPER_BODIES
#include "gga_x_q1d.c"
#undef _GGA_X_Q1D_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_Q1D_HELPER_BODIES
#include "gga_x_q1d.c"
#undef _GGA_X_Q1D_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_Q1D_HELPER_BODIES
#include "gga_x_q1d.c"
#undef _GGA_X_Q1D_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_q1d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_q1d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_q1d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_q1d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_q1d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_q1d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_q1d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_q1d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_q1d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_q1d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_Q1D_HELPER_BODIES)

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

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = -p->dens_threshold + n_s <= 0;
  const double _t6 = xc_powr(n_s, -8, 3);
  const double _t7 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t8 = _t1*_t7;
  const double _t9 = _t6*_t8;
  const double _t10 = (0.1e1 / 0.24e2)*_t9;
  const double _t11 = _t10*sigma_ss;
  const double _t12 = (sigma_ss * sigma_ss);
  const double _t13 = xc_powr(n_s, -16, 3);
  const double _t14 = xc_powr(0.6e1, 2, 3);
  const double _t15 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t16 = _t14*_t15;
  const double _t17 = _t13*_t16;
  const double _t18 = (0.1e1 / 0.576e3)*_t12*_t17;
  const double _t19 = _t11 + _t18;
  const double _t20 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t21 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t22 = _t21/xc_powi(n_s, 8);
  const double _t23 = _t18 + (0.1e1 / 0.2304e4)*_t20*_t22 + 0.1e1;
  const double _t24 = (0.1e1 / _t23);
  const double _t25 = _t9*sigma_ss;
  const double _t26 = (0.5e1 / 0.972e3)*_t25 + 0.80400000000000005;
  const double _t27 = (0.1e1 / _t26);
  const double _t28 = 0.0041358024691358023*_t27;
  const double _t29 = _t25*_t28 + 0.1e1;
  const double _t30 = -_t11*_t29 + 0.065250000000000002;
  const double _t31 = _t24*_t30;
  const double _t32 = _t19*_t31 + _t29;
#if _KMAX >= 1
  const double _t34 = (0.1e1 / 0.288e3)*_t17;
  const double _t35 = _t34*sigma_ss;
  const double _t36 = _t10 + _t35;
  const double _t37 = (0.1e1 / (_t26 * _t26));
  const double _t38 = _t17*_t37;
  const double _t39 = _t28*_t9 - 2.1274704059340546e-5*_t38*sigma_ss;
  const double _t40 = -_t10*_t29 - _t11*_t39;
  const double _t41 = _t19*_t24;
  const double _t42 = (0.1e1 / (_t23 * _t23));
  const double _t43 = _t30*_t42;
  const double _t44 = _t12*_t22;
  const double _t45 = -_t35 - 0.1e1 / 0.768e3*_t44;
  const double _t46 = _t19*_t45;
  const double _t47 = _t31*_t36 + _t39 + _t40*_t41 + _t43*_t46;
  const double _t49 = xc_powr(n_s, -4, 3);
  const double _t53 = xc_powr(n_s, -11, 3);
  const double _t54 = _t53*_t8;
  const double _t55 = 0.011028806584362139*_t27*_t54;
  const double _t56 = _t55*sigma_ss;
  const double _t57 = xc_powr(n_s, -19, 3);
  const double _t58 = _t16*_t57;
  const double _t59 = _t12*_t58;
  const double _t60 = (0.1e1 / 0.9e1)*_t54;
  const double _t61 = (0.1e1 / 0.108e3)*_t59;
  const double _t62 = -_t60*sigma_ss - _t61;
  const double _t63 = _t21/xc_powi(n_s, 9);
  const double _t64 = _t20*_t63;
  const double _t65 = _t61 + (0.1e1 / 0.288e3)*_t64;
  const double _t66 = _t19*_t43;
  const double _t67 = 5.6732544158241455e-5*_t12*_t14*_t15*_t37*_t57 - _t56;
  const double _t68 = (0.1e1 / 0.9e1)*_t1*_t29*_t53*_t7*sigma_ss - _t11*_t67;
  const double _t69 = _t31*_t62 + 5.6732544158241455e-5*_t37*_t59 + _t41*_t68 - _t56 + _t65*_t66;
#endif
#if _KMAX >= 2
  const double _t71 = (0.1e1 / (_t26 * _t26 * _t26));
  const double _t72 = _t22*sigma_ss;
  const double _t73 = -4.2549408118681091e-5*_t38 + 1.31325333699633e-6*_t71*_t72;
  const double _t74 = (0.1e1 / 0.12e2)*_t9;
  const double _t75 = -_t11*_t73 - _t39*_t74;
  const double _t76 = _t24*_t36;
  const double _t77 = 0.2e1*_t76;
  const double _t78 = -_t34 - 0.1e1 / 0.384e3*_t72;
  const double _t79 = _t36*_t43;
  const double _t80 = 0.2e1*_t79;
  const double _t81 = _t42*_t46;
  const double _t82 = 0.2e1*_t40;
  const double _t83 = (0.1e1 / (_t23 * _t23 * _t23));
  const double _t84 = _t30*_t83;
  const double _t85 = (0.1e1 / 0.144e3)*_t17;
  const double _t86 = -0.1e1 / 0.384e3*_t44 - _t85*sigma_ss;
  const double _t87 = _t46*_t86;
  const double _t88 = _t31*_t34 + _t40*_t77 + _t41*_t75 + _t45*_t80 + _t66*_t78 + _t73 + _t81*_t82 + _t84*_t87;
  const double _t90 = _t12*_t63;
  const double _t91 = 3.50200889865688e-6*_t71*_t90;
  const double _t92 = _t37*_t58;
  const double _t93 = (0.1e1 / 0.54e2)*_t58;
  const double _t94 = _t93*sigma_ss;
  const double _t95 = -_t60 - _t94;
  const double _t96 = (0.1e1 / 0.96e2)*_t90 + _t94;
  const double _t97 = _t43*_t62;
  const double _t98 = _t84*_t86;
  const double _t99 = _t19*_t65;
  const double _t100 = _t24*_t62;
  const double _t101 = _t19*_t42;
  const double _t102 = _t40*_t65;
  const double _t103 = _t42*_t68;
  const double _t104 = 0.00017019763247472436*_t14*_t15*_t37*_t57*sigma_ss - _t55 - _t91;
  const double _t105 = (0.1e1 / 0.9e1)*_t1*_t29*_t53*_t7 + (0.1e1 / 0.9e1)*_t1*_t39*_t53*_t7*sigma_ss - _t10*_t67 - _t104*_t11;
  const double _t106 = _t100*_t40 + _t101*_t102 + _t103*_t46 + _t105*_t41 + _t31*_t95 + _t45*_t97 - _t55 + _t65*_t79 + _t66*_t96 + _t68*_t76 - _t91 + 0.00017019763247472436*_t92*sigma_ss + _t98*_t99;
  const double _t108 = (0.2e1 / 0.9e1)*_t32;
  const double _t109 = xc_powr(n_s, -7, 3);
  const double _t111 = (0.1e1 / 0.36e2)*_t32;
  const double _t112 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t116 = xc_powr(n_s, -14, 3);
  const double _t117 = _t116*_t8;
  const double _t118 = (0.11e2 / 0.27e2)*_t117;
  const double _t119 = _t118*sigma_ss;
  const double _t120 = _t16/xc_powr(n_s, 22, 3);
  const double _t121 = _t12*_t120;
  const double _t122 = (0.19e2 / 0.324e3)*_t121;
  const double _t123 = _t119 + _t122;
  const double _t124 = _t21/xc_powi(n_s, 10);
  const double _t125 = _t124*_t20;
  const double _t126 = 0.040438957475994505*_t117*_t27;
  const double _t127 = -0.00051059289742417309*_t121*_t37 + 9.3386903964183465e-6*_t125*_t71 + _t126*sigma_ss;
  const double _t128 = (0.2e1 / 0.9e1)*_t1*_t53*_t67*_t7*sigma_ss - _t11*_t127 - _t119*_t29;
  const double _t129 = 0.2e1*_t68;
  const double _t130 = -_t122 - 0.1e1 / 0.32e2*_t125;
  const double _t131 = 0.2e1*_t65;
  const double _t132 = _t103*_t19;
  const double _t133 = _t12*_t93 + (0.1e1 / 0.144e3)*_t64;
  const double _t134 = _t84*_t99;
  const double _t135 = _t100*_t129 + _t123*_t31 + _t127 + _t128*_t41 + _t130*_t66 + _t131*_t132 + _t131*_t97 + _t133*_t134;
#endif
#if _KMAX >= 3
  const double _t137 = (0.1e1 / 0.8e1)*_t9;
  const double _t138 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t139 = (0.1e1 / (_t26 * _t26 * _t26 * _t26));
  const double _t140 = _t1*_t138*_t139;
  const double _t141 = _t140/xc_powr(n_s, 32, 3);
  const double _t142 = -2.0266255200560646e-8*_t141*sigma_ss + 3.9397600109889901e-6*_t22*_t71;
  const double _t143 = -_t11*_t142 - _t137*_t73;
  const double _t144 = 0.3e1*_t75;
  const double _t145 = 0.3e1*_t78;
  const double _t146 = _t101*_t78;
  const double _t147 = 0.3e1*_t40;
  const double _t148 = _t36*_t45;
  const double _t149 = _t40*_t42;
  const double _t150 = 0.6e1*_t149;
  const double _t151 = -0.1e1 / 0.192e3*_t72 - _t85;
  const double _t152 = _t151*_t84;
  const double _t153 = _t19*_t98;
  const double _t154 = 0.3e1*_t98;
  const double _t155 = _t83*_t87;
  const double _t156 = (0.1e1 / 0.384e3)*_t22;
  const double _t157 = _t24*_t40;
  const double _t158 = (0.1e1 / 0.96e2)*_t17;
  const double _t159 = -_t158*sigma_ss - 0.1e1 / 0.256e3*_t44;
  const double _t160 = (0.1e1 / (_t23 * _t23 * _t23 * _t23));
  const double _t161 = _t160*_t30;
  const double _t162 = _t159*_t161;
  const double _t163 = _t43*_t45;
  const double _t164 = _t142 + _t143*_t41 + _t144*_t76 + _t144*_t81 + _t145*_t79 + _t146*_t147 + _t147*_t155 + _t148*_t150 + _t148*_t154 + _t152*_t46 + 0.2e1*_t153*_t78 - _t156*_t66 + _t157*_t158 + _t158*_t163 + _t162*_t87;
  const double _t166 = _t63*sigma_ss;
  const double _t167 = xc_powr(n_s, -35, 3);
  const double _t168 = _t140*_t167;
  const double _t169 = 5.4043347201495061e-8*_t12*_t168 - 1.7510044493284399e-5*_t166*_t71 + 0.00022693017663296582*_t92;
  const double _t170 = (0.2e1 / 0.9e1)*_t1*_t39*_t53*_t7 + (0.1e1 / 0.9e1)*_t1*_t53*_t7*_t73*sigma_ss - _t104*_t74 - _t11*_t169;
  const double _t171 = 0.2e1*_t157;
  const double _t172 = (0.1e1 / 0.48e2)*_t166 + _t93;
  const double _t173 = _t101*_t65;
  const double _t174 = 0.2e1*_t163;
  const double _t175 = 0.2e1*_t103;
  const double _t176 = _t45*_t62;
  const double _t177 = _t42*_t82;
  const double _t178 = 0.2e1*_t105;
  const double _t179 = _t36*_t42;
  const double _t180 = 0.2e1*_t102;
  const double _t181 = _t101*_t40;
  const double _t182 = 0.2e1*_t96;
  const double _t183 = _t68*_t83;
  const double _t184 = _t131*_t98;
  const double _t185 = _t83*_t86;
  const double _t186 = _t180*_t19;
  const double _t187 = _t24*_t68;
  const double _t188 = _t162*_t99;
  const double _t189 = _t43*_t65;
  const double _t190 = _t100*_t75 + _t105*_t77 + _t132*_t78 + _t134*_t151 + _t148*_t175 + _t153*_t182 + _t169 + _t170*_t41 + _t171*_t95 + _t172*_t66 + _t173*_t75 + _t174*_t95 + _t176*_t177 + _t176*_t98 + _t178*_t81 + _t179*_t180 + _t181*_t182 + _t183*_t87 + _t184*_t36 + _t185*_t186 + _t187*_t34 + _t188*_t86 + _t189*_t34 - _t31*_t93 + _t78*_t97 + _t80*_t96;
  const double _t193 = (0.1e1 / 0.36e2)*_t47;
  const double _t194 = (0.19e2 / 0.162e3)*_t120;
  const double _t195 = _t194*sigma_ss;
  const double _t196 = _t118 + _t195;
  const double _t197 = _t123*_t24;
  const double _t198 = _t12*_t124;
  const double _t199 = _t120*_t37;
  const double _t200 = _t140/xc_powr(n_s, 38, 3);
  const double _t201 = _t126 + 5.9534151277166957e-5*_t198*_t71 - 0.0012292051234285648*_t199*sigma_ss - 1.4411559253732016e-7*_t20*_t200;
  const double _t202 = (0.2e1 / 0.9e1)*_t1*_t104*_t53*_t7*sigma_ss + (0.2e1 / 0.9e1)*_t1*_t53*_t67*_t7 - _t10*_t127 - _t11*_t201 - _t118*_t29 - _t119*_t39;
  const double _t203 = _t24*_t95;
  const double _t204 = 0.2e1*_t100;
  const double _t205 = -_t195 - 0.3e1 / 0.32e2*_t198;
  const double _t206 = _t123*_t43;
  const double _t207 = _t101*_t130;
  const double _t208 = _t43*_t95;
  const double _t209 = _t103*_t36;
  const double _t210 = _t42*_t62;
  const double _t211 = _t130*_t19;
  const double _t212 = _t133*_t84;
  const double _t213 = _t36*_t65;
  const double _t214 = (0.1e1 / 0.27e2)*_t58;
  const double _t215 = _t214*sigma_ss + (0.1e1 / 0.48e2)*_t90;
  const double _t216 = _t19*_t212;
  const double _t217 = _t133*_t83;
  const double _t218 = _t102*_t19;
  const double _t219 = _t129*_t185;
  const double _t220 = _t105*_t204 + _t128*_t76 + _t128*_t81 + _t129*_t203 + _t130*_t79 + _t131*_t208 + _t131*_t209 + _t132*_t182 + _t133*_t188 + _t134*_t215 + _t173*_t178 + _t175*_t176 + _t180*_t210 + _t182*_t97 + _t184*_t62 + _t196*_t31 + _t197*_t40 + _t201 + _t202*_t41 + _t205*_t66 + _t206*_t45 + _t207*_t40 + _t211*_t98 + _t212*_t213 + _t216*_t96 + _t217*_t218 + _t219*_t99;
  const double _t222 = (0.1e1 / M_PI);
  const double _t229 = _t21/xc_powi(n_s, 11);
  const double _t230 = _t20*_t229;
  const double _t231 = 0.00017743511753194859*_t230*_t71;
  const double _t232 = xc_powr(n_s, -17, 3);
  const double _t233 = _t232*_t8;
  const double _t234 = 0.18871513488797437*_t233*_t27;
  const double _t235 = _t234*sigma_ss;
  const double _t236 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t237 = xc_powr(n_s, -41, 3);
  const double _t238 = _t140*_t237;
  const double _t239 = xc_powr(n_s, -25, 3);
  const double _t240 = _t16*_t239;
  const double _t241 = _t12*_t240;
  const double _t242 = (0.154e3 / 0.81e2)*_t233;
  const double _t243 = (0.209e3 / 0.486e3)*_t241;
  const double _t244 = -_t242*sigma_ss - _t243;
  const double _t245 = (0.5e1 / 0.16e2)*_t230 + _t243;
  const double _t246 = 0.3e1*_t130;
  const double _t247 = 0.3e1*_t206;
  const double _t248 = -_t12*_t194 - 0.1e1 / 0.16e2*_t125;
  const double _t249 = 0.2e1*_t212;
  const double _t250 = 0.3e1*_t62;
  const double _t251 = _t212*_t65;
  const double _t252 = 0.3e1*_t68;
  const double _t253 = _t161*_t99;
  const double _t254 = (0.1e1 / 0.36e2)*_t59 + (0.1e1 / 0.96e2)*_t64;
  const double _t255 = _t133*_t254;
  const double _t256 = 0.6e1*_t65;
  const double _t257 = _t103*_t62;
  const double _t258 = _t217*_t99;
  const double _t259 = 0.3e1*_t128;
  const double _t260 = (0.11e2 / 0.9e1)*_t117;
  const double _t261 = _t260*_t67;
  const double _t262 = 3.8430824676618711e-7*_t1*_t138*_t139*_t236*_t237 + 0.0042990661239911852*_t12*_t14*_t15*_t239*_t37 - _t231 - _t235;
  const double _t263 = (0.1e1 / 0.3e1)*_t1*_t127*_t53*_t7*sigma_ss + (0.154e3 / 0.81e2)*_t1*_t232*_t29*_t7*sigma_ss - _t11*_t262 - _t261*sigma_ss;
  const double _t264 = _t100*_t259 + _t132*_t246 + _t134*_t248 + _t173*_t259 + _t197*_t252 + _t211*_t249 - _t231 - _t235 + 3.8430824676618711e-7*_t236*_t238 + 0.0042990661239911852*_t241*_t37 + _t244*_t31 + _t245*_t66 + _t246*_t97 + _t247*_t65 + _t250*_t251 + _t252*_t258 + _t253*_t255 + _t256*_t257 + _t263*_t41;
#endif
#if _KMAX >= 4
  const double _t266 = 8.1065020802242597e-8*_t141;
  const double _t267 = xc_powr(n_s, -40, 3);
  const double _t268 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t269 = xc_powi(_t26, -5);
  const double _t270 = _t14*_t268*_t269;
  const double _t271 = (0.1e1 / 0.96e2)*_t22;
  const double _t272 = (0.1e1 / 0.48e2)*_t17;
  const double _t273 = (0.1e1 / 0.192e3)*_t22;
  const double _t274 = 0.4e1*_t148;
  const double _t275 = _t36*_t78;
  const double _t276 = _t145*_t19;
  const double _t277 = -_t158 - 0.1e1 / 0.128e3*_t72;
  const double _t278 = _t162*_t86;
  const double _t279 = _t151*_t46;
  const double _t280 = 0.4e1*_t143;
  const double _t281 = _t159*_t87;
  const double _t282 = _t30/xc_powi(_t23, 5);
  const double _t283 = _t282*(-0.1e1 / 0.72e2*_t17*sigma_ss - 0.1e1 / 0.192e3*_t44);
  const double _t284 = _t148*_t42;
  const double _t285 = 0.6e1*_t75;
  const double _t286 = _t185*_t40;
  const double _t287 = 0.4e1*_t40;
  const double _t288 = _t19*_t78;
  const double _t289 = 3.1518080087911921e-5*_t63*_t71;
  const double _t290 = 1.1120030288373469e-9*_t12*_t270/xc_powr(n_s, 43, 3);
  const double _t291 = (0.1e1 / 0.18e2)*_t58;
  const double _t292 = 0.3e1*_t172;
  const double _t293 = _t65*_t98;
  const double _t294 = 0.3e1*_t152;
  const double _t295 = _t45*_t95;
  const double _t296 = _t36*_t96;
  const double _t297 = _t19*_t96;
  const double _t298 = _t62*_t78;
  const double _t299 = 0.2e1*_t98;
  const double _t300 = _t253*_t277;
  const double _t301 = 0.3e1*_t278;
  const double _t302 = 0.2e1*_t188;
  const double _t303 = _t102*_t42;
  const double _t304 = _t149*_t62;
  const double _t305 = _t159*_t86;
  const double _t306 = _t305*_t99;
  const double _t307 = _t179*_t65;
  const double _t308 = _t101*_t96;
  const double _t309 = _t176*_t42;
  const double _t310 = _t102*_t185;
  const double _t311 = _t218*_t83;
  const double _t312 = 0.6e1*_t96;
  const double _t313 = _t185*_t252;
  const double _t314 = _t185*_t99;
  const double _t315 = _t160*_t218;
  const double _t316 = _t160*_t68;
  const double _t317 = 0.3e1*_t105;
  const double _t318 = 0.3e1*_t170;
  const double _t319 = _t124*sigma_ss;
  const double _t320 = -1.3510836800373763e-6*_t12*_t200 - 0.0014372244520087835*_t199 + 2.9653414102329253e-9*_t20*_t270/xc_powr(n_s, 46, 3) + 0.00019494516202523299*_t319*_t71;
  const double _t321 = 0.4e1*_t105;
  const double _t322 = 0.2e1*_t172;
  const double _t323 = 0.2e1*_t205;
  const double _t324 = _t130*_t36;
  const double _t325 = _t123*_t45;
  const double _t326 = 0.4e1*_t96;
  const double _t327 = 0.4e1*_t95;
  const double _t328 = _t131*_t62;
  const double _t329 = _t215*_t84;
  const double _t330 = _t131*_t36;
  const double _t331 = _t182*_t19;
  const double _t332 = _t211*_t82;
  const double _t333 = _t83*_t99;
  const double _t334 = _t217*_t297;
  const double _t335 = _t62*_t98;
  const double _t336 = _t183*_t86;
  const double _t337 = 0.4e1*_t62;
  const double _t338 = _t133*_t162;
  const double _t339 = _t133*_t159;
  const double _t340 = _t160*_t339;
  const double _t341 = _t283*_t99;
  const double _t342 = _t12*_t229;
  const double _t343 = 0.00079767980469406716*_t342*_t71;
  const double _t344 = _t240*sigma_ss;
  const double _t345 = 7.9075770939544674e-9*_t236*_t270/xc_powr(n_s, 49, 3);
  const double _t346 = (0.209e3 / 0.243e3)*_t344;
  const double _t347 = 0.3e1*_t205;
  const double _t348 = _t248*_t84;
  const double _t349 = 0.2e1*_t211;
  const double _t350 = _t250*_t65;
  const double _t351 = 0.3e1*_t123;
  const double _t352 = _t161*_t255;
  const double _t353 = _t253*_t254;
  const double _t354 = _t133*_t253;
  const double _t355 = 0.3e1*_t202;
  const double _t356 = _t8*sigma_ss/xc_powr(n_s, 20, 3);
  const double _t357 = (0.2618e4 / 0.243e3)*_t356;
  const double _t358 = _t12*_t16/xc_powr(n_s, 28, 3);
  const double _t359 = (0.5225e4 / 0.1458e4)*_t358;
  const double _t360 = _t20*_t21/xc_powi(n_s, 12);
  const double _t361 = -1.2554069394362112e-5*_t140*_t236/xc_powr(n_s, 44, 3) + 1.0693857643651881*_t27*_t356 + 2.1086872250545246e-8*_t270*xc_powi(sigma_ss, 5)/xc_powr(n_s, 52, 3) - 0.038414236011147046*_t358*_t37 + 0.0026594514984466912*_t360*_t71;
  const double _t362 = 0.4e1*_t244;
  const double _t363 = 0.4e1*_t263;
  const double _t364 = 0.6e1*_t128;
  const double _t365 = 0.4e1*_t245;
  const double _t366 = 0.12e2*_t65;
  const double _t367 = 0.3e1*_t211;
  const double _t368 = _t337*_t65;
  const double _t369 = 0.4e1*_t99;
  const double _t370 = _t133*_t183;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t5)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  const double _t33 = my_piecewise3(_t5, 0, _hc0[0]*_t32);
#if _KMAX >= 1
  const double _t48 = my_piecewise3(_t5, 0, _hc0[0]*_t47);
  const double _t50 = _hc0[2]*_t3;
  const double _t51 = _t49*_t50;
  const double _t52 = (0.1e1 / 0.6e1)*_t51;
  const double _t70 = my_piecewise3(_t5, 0, _hc0[0]*_t69 - _t32*_t52);
#endif
#if _KMAX >= 2
  const double _t89 = my_piecewise3(_t5, 0, _hc0[0]*_t88);
  const double _t107 = my_piecewise3(_t5, 0, _hc0[0]*_t106 - _t47*_t52);
  const double _t110 = _t109*_t50;
  const double _t113 = _hc0[5]*_t112*_t14;
  const double _t114 = _t113*_t6;
  const double _t115 = (0.1e1 / 0.3e1)*_t51;
  const double _t136 = my_piecewise3(_t5, 0, _hc0[0]*_t135 + _t108*_t110 + _t111*_t114 - _t115*_t69);
#endif
#if _KMAX >= 3
  const double _t165 = my_piecewise3(_t5, 0, _hc0[0]*_t164);
  const double _t191 = my_piecewise3(_t5, 0, _hc0[0]*_t190 - _t52*_t88);
  const double _t192 = (0.2e1 / 0.9e1)*_t110;
  const double _t221 = my_piecewise3(_t5, 0, _hc0[0]*_t220 - _t106*_t115 + _t114*_t193 + _t192*_t47);
  const double _t223 = _hc0[9]*_t222/(n_s * n_s * n_s * n_s);
  const double _t224 = _t50/xc_powr(n_s, 10, 3);
  const double _t225 = (0.14e2 / 0.27e2)*_t224;
  const double _t226 = _t113*_t53;
  const double _t227 = (0.1e1 / 0.9e1)*_t226;
  const double _t228 = _hc0[2]*_t4*_t49;
  const double _t265 = my_piecewise3(_t5, 0, _hc0[0]*_t264 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t109*_t2*_t69 + (0.1e1 / 0.12e2)*_hc0[5]*_t112*_t14*_t6*_t69 - _t111*_t223 - _t135*_t228 - _t225*_t32 - _t227*_t32);
#endif

  const double f = my_piecewise3(_t5, 0, _t33*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t5, 0, _t48*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t5, 0, _t33 + _t70*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t5, 0, _t89*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t5, 0, _t107*n_s + _t48);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t5, 0, _t136*n_s + 0.2e1*_t70);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t5, 0, _t165*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t5, 0, _t191*n_s + _t89);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t5, 0, 0.2e1*_t107 + _t221*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t5, 0, 0.3e1*_t136 + _t265*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t146*_t285 + 0.12e2*_t148*_t286 + (0.1e1 / 0.24e2)*_t149*_t17*_t45 + 0.12e2*_t149*_t275 + _t152*_t274 + _t152*_t276 - 0.1e1 / 0.128e3*_t153*_t22 + _t155*_t285 + _t160*_t281*_t287 + _t161*_t277*_t87 + 0.2e1*_t162*_t279 - _t181*_t271 + _t24*_t272*_t75 - _t266 + 4.1700113581400507e-10*_t267*_t270*sigma_ss - _t271*_t79 + _t272*_t43*_t78 + _t272*_t45*_t98 - _t273*_t46*_t84 + _t274*_t278 + 0.8e1*_t275*_t98 + _t276*_t278 + _t279*_t287*_t83 + _t280*_t76 + _t280*_t81 + _t281*_t283 + 0.12e2*_t284*_t75 + 0.8e1*_t286*_t288 + _t41*(-_t11*(4.1700113581400507e-10*_t14*_t267*_t268*_t269*sigma_ss - _t266) - 0.1e1 / 0.6e1*_t142*_t9))));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t5, 0, _t165 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t100*_t143 + _t103*_t158*_t45 + _t105*_t158*_t24 + 0.6e1*_t105*_t284 - _t132*_t156 - _t134*_t273 + _t143*_t173 + _t144*_t203 + _t144*_t307 + _t144*_t308 + _t144*_t309 + _t144*_t314 + _t145*_t208 + _t145*_t209 + _t145*_t304 + _t146*_t317 + _t147*_t176*_t185 + _t148*_t313 + _t150*_t295 + _t150*_t296 + _t151*_t302 + 0.3e1*_t151*_t311 + _t152*_t176 + _t153*_t292 + _t154*_t295 + _t155*_t317 - _t156*_t97 - _t157*_t291 + _t158*_t293 + _t158*_t303 + _t158*_t43*_t96 - _t163*_t291 + 3.7830343041046538e-7*_t168*sigma_ss + _t176*_t278 + _t181*_t292 + _t183*_t279 + _t19*_t286*_t312 + _t213*_t294 + _t213*_t301 + _t219*_t288 + _t281*_t316 + _t283*_t306 - _t289 - _t290 + _t292*_t79 + _t294*_t297 + 0.6e1*_t296*_t98 + _t297*_t301 + _t298*_t299 + _t300*_t86 + 0.3e1*_t305*_t315 + 0.6e1*_t310*_t36 + _t318*_t76 + _t318*_t81 + _t41*((0.1e1 / 0.9e1)*_t1*_t142*_t53*_t7*sigma_ss + (0.1e1 / 0.3e1)*_t1*_t53*_t7*_t73 - _t11*(3.7830343041046538e-7*_t1*_t138*_t139*_t167*sigma_ss - _t289 - _t290) - _t137*_t169) + (0.1e1 / 0.48e2)*_t63*_t66) - _t164*_t52));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t5, 0, 0.2e1*_t191 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(0.4e1*_t103*_t295 + _t103*_t65*_t85 + _t128*_t146 + _t128*_t155 + _t128*_t24*_t34 + 0.2e1*_t128*_t284 + _t129*_t151*_t333 + _t129*_t160*_t306 + _t130*_t34*_t43 + _t131*_t210*_t75 + _t132*_t322 + _t133*_t300 + _t134*((0.1e1 / 0.24e2)*_t166 + _t214) + _t152*_t211 + _t152*_t328 + _t153*_t323 + 0.2e1*_t170*_t173 + _t170*_t204 + _t171*_t196 + _t172*_t216 + _t174*_t196 + _t175*_t298 + _t176*_t219 + _t177*_t324 + _t177*_t325 + _t180*_t217*_t36 + _t181*_t323 + _t182*_t212*_t36 + _t185*_t332 + _t186*_t215*_t83 + _t186*_t340 - _t187*_t214 - _t189*_t214 + _t19*_t326*_t336 + _t194*_t31 + _t197*_t75 + _t202*_t77 + 0.2e1*_t202*_t81 + _t203*_t321 + _t205*_t80 + _t206*_t78 + _t207*_t75 + _t208*_t326 + _t209*_t326 + _t211*_t278 + 0.4e1*_t213*_t336 + _t215*_t302 + _t251*_t34 + _t258*_t75 + _t278*_t328 + _t293*_t327 + _t299*_t324 + _t303*_t327 + _t304*_t326 + _t307*_t321 + _t308*_t321 + _t309*_t321 + _t310*_t337 + _t314*_t321 + _t320 + _t322*_t97 + _t325*_t98 + _t326*_t335 + _t329*_t330 + _t329*_t331 + _t330*_t338 + _t331*_t338 + _t334*_t82 + _t339*_t341 + _t41*((0.4e1 / 0.9e1)*_t1*_t104*_t53*_t7 + (0.2e1 / 0.9e1)*_t1*_t169*_t53*_t7*sigma_ss - _t11*_t320 - 0.22e2 / 0.27e2*_t117*_t39 - _t119*_t73 - _t201*_t74) + _t66*(-_t194 - 0.3e1 / 0.16e2*_t319)) + (0.1e1 / 0.36e2)*_t114*_t88 - _t115*_t190 + _t192*_t88));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t5, 0, 0.3e1*_t221 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t100*_t355 + _t102*_t217*_t250 + _t103*_t256*_t95 + 0.3e1*_t103*_t325 + _t105*_t210*_t256 + _t130*_t147*_t210 + _t132*_t347 + _t134*(-0.19e2 / 0.81e2*_t120*sigma_ss - 0.3e1 / 0.16e2*_t198) + _t153*_t245 + _t157*_t244 + _t163*_t244 + _t173*_t355 + _t181*_t245 + _t188*_t248 + 0.3e1*_t189*_t196 + _t196*_t24*_t252 + _t197*_t317 + 4.2754292452738312e-6*_t20*_t238 + _t203*_t259 + _t207*_t317 + _t208*_t246 + _t209*_t246 + _t211*_t313 + _t212*_t250*_t96 + _t213*_t217*_t252 + _t213*_t348 + _t213*_t352 + _t215*_t252*_t333 + _t215*_t353 + _t216*_t323 + _t217*_t332 - _t234 + _t245*_t79 + _t246*_t335 + _t247*_t96 + _t248*_t311 + _t249*_t324 + 0.3e1*_t251*_t95 + _t252*_t334 + _t252*_t340*_t99 + _t255*_t315 + _t255*_t341 + _t256*_t336*_t62 + _t257*_t312 + _t258*_t317 + _t259*_t307 + _t259*_t308 + _t259*_t309 + _t259*_t314 + _t263*_t76 + _t263*_t81 + _t293*_t351 + _t297*_t348 + _t297*_t352 + _t303*_t351 + _t31*(-_t242 - _t346) + _t329*_t349 + _t329*_t350 + _t338*_t349 + _t338*_t350 - _t343 + 0.0095688891146900566*_t344*_t37 - _t345 + _t347*_t97 + _t354*(_t291*sigma_ss + (0.1e1 / 0.32e2)*_t90) + _t41*((0.1e1 / 0.3e1)*_t1*_t127*_t53*_t7 + (0.1e1 / 0.3e1)*_t1*_t201*_t53*_t7*sigma_ss + (0.154e3 / 0.81e2)*_t1*_t232*_t29*_t7 + (0.154e3 / 0.81e2)*_t1*_t232*_t39*_t7*sigma_ss - _t10*_t262 - _t104*_t260*sigma_ss - _t11*(4.2754292452738312e-6*_t1*_t138*_t139*_t20*_t237 + 0.0095688891146900566*_t14*_t15*_t239*_t37*sigma_ss - _t234 - _t343 - _t345) - _t261) + _t66*((0.15e2 / 0.16e2)*_t342 + _t346)) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t106*_t109*_t2 + (0.1e1 / 0.12e2)*_hc0[5]*_t106*_t112*_t14*_t6 - _t193*_t223 - _t220*_t228 - _t225*_t47 - _t227*_t47));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t5, 0, 0.4e1*_t265 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t100*_t363 + _t103*_t123*_t366 + _t123*_t212*_t256 + _t128*_t210*_t366 + 0.6e1*_t130*_t206 + 0.8e1*_t130*_t212*_t62 + 0.12e2*_t130*_t257 + _t132*_t365 + _t134*((0.5e1 / 0.8e1)*_t230 + (0.209e3 / 0.243e3)*_t241) + _t173*_t363 + _t183*_t248*_t369 + _t187*_t362 + _t189*_t362 + _t197*_t364 + _t207*_t364 + 0.8e1*_t211*_t370 + 0.3e1*_t216*_t245 + 0.2e1*_t248*_t353 + _t255*_t282*_t99*(_t12*_t214 + (0.1e1 / 0.72e2)*_t64) + _t255*_t316*_t369 + _t258*_t364 + _t31*(_t357 + _t359) + _t348*_t367 + _t348*_t368 + _t352*_t367 + _t352*_t368 + _t354*(-0.19e2 / 0.108e3*_t121 - 0.3e1 / 0.32e2*_t125) + _t361 + _t365*_t97 + _t366*_t370*_t62 + _t41*((0.616e3 / 0.81e2)*_t1*_t232*_t67*_t7*sigma_ss + (0.4e1 / 0.9e1)*_t1*_t262*_t53*_t7*sigma_ss - _t11*_t361 - 0.22e2 / 0.9e1*_t117*_t127*sigma_ss - _t29*_t357) + _t66*(-_t359 - 0.55e2 / 0.16e2*_t360)) + (0.1e1 / 0.216e3)*_hc0[14]*_t13*_t32*_t8 + _hc0[9]*_t108*_t222/xc_powi(n_s, 5) + (0.4e1 / 0.3e1)*_t110*_t135 + (0.40e2 / 0.81e2)*_t113*_t116*_t32 + (0.1e1 / 0.6e1)*_t114*_t135 - 0.1e1 / 0.9e1*_t223*_t69 - 0.56e2 / 0.27e2*_t224*_t69 - 0.4e1 / 0.9e1*_t226*_t69 - 0.2e1 / 0.3e1*_t264*_t51 + (0.140e3 / 0.81e2)*_t32*_t50/xc_powr(n_s, 13, 3)));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
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