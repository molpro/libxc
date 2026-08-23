/*
  Generated from python/gga_exc/gga_k_mpbe.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_k_mpbe
*/

#ifndef _GGA_K_MPBE_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_K_MPBE_KERNEL_BODY
#define _KMAX 0
#define _GGA_K_MPBE_HELPER_BODIES
#include "gga_k_mpbe.c"
#undef _GGA_K_MPBE_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_K_MPBE_HELPER_BODIES
#include "gga_k_mpbe.c"
#undef _GGA_K_MPBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_K_MPBE_HELPER_BODIES
#include "gga_k_mpbe.c"
#undef _GGA_K_MPBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_K_MPBE_HELPER_BODIES
#include "gga_k_mpbe.c"
#undef _GGA_K_MPBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_K_MPBE_HELPER_BODIES
#include "gga_k_mpbe.c"
#undef _GGA_K_MPBE_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_k_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_k_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_k_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_k_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_k_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_k_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_k_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_k_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_k_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_k_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_K_MPBE_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double *out) {
  const gga_k_mpbe_params *params = (const gga_k_mpbe_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n5_3_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  const double _t1 = -p->dens_threshold + n_s <= 0;
  const double _t2 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t3 = xc_powi(n_s, -8);
  const double _t4 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t5 = (0.1e1 / 0.24e2)*params->a;
  const double _t6 = xc_powr(n_s, -8, 3);
  const double _t7 = xc_powr(0.6e1, 1, 3);
  const double _t8 = (M_PI * M_CBRTPI);
  const double _t9 = (0.1e1 / _t8);
  const double _t10 = _t7*_t9;
  const double _t11 = _t10*sigma_ss;
  const double _t12 = _t11*_t6;
  const double _t13 = _t12*_t5 + 0.1e1;
  const double _t14 = (0.1e1 / (_t13 * _t13 * _t13));
  const double _t15 = _t14*_t4;
  const double _t16 = _t15*params->c3;
  const double _t17 = _t16*_t3;
  const double _t18 = (0.1e1 / _t13);
  const double _t19 = _t18*params->c1;
  const double _t20 = (sigma_ss * sigma_ss);
  const double _t21 = _t20*params->c2;
  const double _t22 = xc_powr(n_s, -16, 3);
  const double _t23 = xc_powr(0.6e1, 2, 3);
  const double _t24 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t25 = (0.1e1 / (_t13 * _t13));
  const double _t26 = _t23*_t24*_t25;
  const double _t27 = _t22*_t26;
  const double _t28 = (0.1e1 / 0.576e3)*_t27;
  const double _t29 = xc_powr(0.3e1, 2, 3)*_t8*(_hc0[0] + 0.1e1);
  const double _t30 = _t29*((0.1e1 / 0.24e2)*_t12*_t19 + (0.1e1 / 0.2304e4)*_t17*_t2 + _t21*_t28 + 0.1e1);
  const double _t31 = (0.3e1 / 0.20e2)*xc_powr(n_s, 2, 3);
  const double _t32 = my_piecewise3(_t1, 0, _t30*_t31);
#if _KMAX >= 1
  const double _t33 = _t15*_t3;
  const double _t34 = params->a*params->c2;
  const double _t35 = _t33*_t34;
  const double _t36 = params->a*sigma_ss;
  const double _t37 = _t36*params->c1;
  const double _t38 = _t2*params->c3;
  const double _t39 = xc_powr(n_s, -32, 3);
  const double _t40 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t41 = (0.1e1 / (_t13 * _t13 * _t13 * _t13));
  const double _t42 = _t40*_t41;
  const double _t43 = _t39*_t42;
  const double _t44 = _t43*_t7;
  const double _t45 = _t44*params->a;
  const double _t46 = (0.1e1 / 0.768e3)*_t14*_t20*_t3*_t4*params->c3 + (0.1e1 / 0.24e2)*_t18*_t6*_t7*_t9*params->c1 - 0.1e1 / 0.1152e4*_t20*_t35 + (0.1e1 / 0.288e3)*_t22*_t23*_t24*_t25*params->c2*sigma_ss - _t28*_t37 - 0.1e1 / 0.18432e5*_t38*_t45;
  const double _t47 = _t29*_t31;
  const double _t48 = my_piecewise3(_t1, 0, _t46*_t47);
  const double _t49 = xc_powr(n_s, -1, 3);
  const double _t50 = (0.1e1 / 0.10e2)*_t49;
  const double _t51 = xc_powi(n_s, -9);
  const double _t52 = _t16*_t51;
  const double _t53 = (0.1e1 / 0.9e1)/xc_powr(n_s, 11, 3);
  const double _t54 = _t11*_t19;
  const double _t55 = _t15*_t51;
  const double _t56 = _t34*_t55;
  const double _t57 = xc_powr(n_s, -19, 3);
  const double _t58 = _t26*params->c2;
  const double _t59 = _t57*_t58;
  const double _t60 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t61 = _t60*params->c3;
  const double _t62 = _t61*_t7;
  const double _t63 = xc_powr(n_s, -35, 3);
  const double _t64 = _t42*_t63;
  const double _t65 = _t64*params->a;
  const double _t66 = params->a*params->c1;
  const double _t67 = _t26*_t66;
  const double _t68 = _t57*_t67;
  const double _t69 = -0.1e1 / 0.288e3*_t2*_t52 + (0.1e1 / 0.432e3)*_t2*_t56 - 0.1e1 / 0.108e3*_t20*_t59 + (0.1e1 / 0.216e3)*_t20*_t68 - _t53*_t54 + (0.1e1 / 0.6912e4)*_t62*_t65;
  const double _t70 = my_piecewise3(_t1, 0, _t30*_t50 + _t47*_t69);
#endif
#if _KMAX >= 2
  const double _t71 = (0.1e1 / 0.288e3)*params->c2;
  const double _t72 = ((params->a) * (params->a));
  const double _t73 = _t72*params->c1;
  const double _t74 = _t20*params->c3;
  const double _t75 = _t21*_t72;
  const double _t76 = xc_powr(n_s, -40, 3);
  const double _t77 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t78 = xc_powi(_t13, -5);
  const double _t79 = _t23*_t77*_t78;
  const double _t80 = _t72*_t79;
  const double _t81 = _t76*_t80;
  const double _t82 = (0.1e1 / 0.384e3)*_t17*sigma_ss - 0.1e1 / 0.288e3*_t27*_t66 + _t27*_t71 - _t33*_t36*_t71 + (0.1e1 / 0.1152e4)*_t33*_t73*sigma_ss + (0.1e1 / 0.110592e6)*_t38*_t81 + (0.1e1 / 0.9216e4)*_t44*_t75 - 0.1e1 / 0.3072e4*_t45*_t74;
  const double _t83 = my_piecewise3(_t1, 0, _t47*_t82);
  const double _t84 = _t29*_t50;
  const double _t85 = _t10*_t19;
  const double _t86 = (0.1e1 / 0.54e2)*_t59;
  const double _t87 = _t55*_t73;
  const double _t88 = (0.1e1 / 0.3456e4)*_t64;
  const double _t89 = _t7*_t72*params->c2;
  const double _t90 = _t2*_t89;
  const double _t91 = xc_powr(n_s, -43, 3);
  const double _t92 = _t80*_t91;
  const double _t93 = (0.5e1 / 0.432e3)*_t14*_t20*_t4*_t51*params->a*params->c2 + (0.7e1 / 0.6912e4)*_t2*_t40*_t41*_t63*_t7*params->a*params->c3 - 0.1e1 / 0.96e2*_t20*_t52 - 0.1e1 / 0.432e3*_t20*_t87 + (0.1e1 / 0.72e2)*_t23*_t24*_t25*_t57*params->a*params->c1*sigma_ss - _t53*_t85 - 0.1e1 / 0.41472e5*_t61*_t92 - _t86*sigma_ss - _t88*_t90;
  const double _t94 = my_piecewise3(_t1, 0, _t46*_t84 + _t47*_t93);
  const double _t95 = xc_powr(n_s, -4, 3);
  const double _t96 = (0.1e1 / 0.30e2)*_t95;
  const double _t97 = _t29*_t69;
  const double _t98 = (0.1e1 / 0.5e1)*_t49;
  const double _t99 = xc_powi(n_s, -10);
  const double _t100 = _t16*_t99;
  const double _t101 = (0.11e2 / 0.27e2)/xc_powr(n_s, 14, 3);
  const double _t102 = _t15*_t99;
  const double _t103 = _t102*_t2;
  const double _t104 = xc_powr(n_s, -22, 3);
  const double _t105 = _t104*_t58;
  const double _t106 = _t42/xc_powr(n_s, 38, 3);
  const double _t107 = _t106*params->a;
  const double _t108 = _t20*params->c1;
  const double _t109 = (0.1e1 / 0.1296e4)*_t106;
  const double _t110 = _t60*_t89;
  const double _t111 = xc_powi(sigma_ss, 5);
  const double _t112 = _t111*params->c3;
  const double _t113 = xc_powr(n_s, -46, 3);
  const double _t114 = _t113*_t80;
  const double _t115 = (0.1e1 / 0.32e2)*_t100*_t2 + _t101*_t54 - 0.43e2 / 0.1296e4*_t103*_t34 + (0.1e1 / 0.162e3)*_t103*_t73 - _t104*_t108*_t26*_t5 + (0.19e2 / 0.324e3)*_t105*_t20 - 0.59e2 / 0.20736e5*_t107*_t62 + _t109*_t110 + (0.1e1 / 0.15552e5)*_t112*_t114;
  const double _t116 = my_piecewise3(_t1, 0, _t115*_t47 - _t30*_t96 + _t97*_t98);
#endif
#if _KMAX >= 3
  const double _t117 = _t7*params->c3;
  const double _t118 = ((params->a) * (params->a) * (params->a));
  const double _t119 = xc_powi(M_PI, -8);
  const double _t120 = xc_powi(_t13, -6);
  const double _t121 = _t119*_t120;
  const double _t122 = _t121/xc_powi(n_s, 16);
  const double _t123 = _t118*_t122;
  const double _t124 = _t118*params->c1;
  const double _t125 = _t124*_t44;
  const double _t126 = _t118*_t79;
  const double _t127 = _t126*_t76;
  const double _t128 = -0.1e1 / 0.1024e4*_t117*_t36*_t43 - 0.5e1 / 0.442368e6*_t123*_t38 - 0.1e1 / 0.9216e4*_t125*sigma_ss - 0.1e1 / 0.55296e5*_t127*_t21 + (0.1e1 / 0.384e3)*_t14*_t3*_t4*_t72*params->c1 + (0.1e1 / 0.384e3)*_t14*_t3*_t4*params->c3 + (0.1e1 / 0.12288e5)*_t20*_t23*_t72*_t76*_t77*_t78*params->c3 - 0.1e1 / 0.192e3*_t35 + (0.1e1 / 0.1536e4)*_t39*_t40*_t41*_t7*_t72*params->c2*sigma_ss;
  const double _t129 = my_piecewise3(_t1, 0, _t128*_t47);
  const double _t130 = (0.1e1 / 0.48e2)*_t52;
  const double _t131 = xc_powi(n_s, -17);
  const double _t132 = _t121*_t131;
  const double _t133 = _t124*_t7;
  const double _t134 = _t133*_t20;
  const double _t135 = (0.1e1 / 0.20736e5)*_t91;
  const double _t136 = _t126*params->c2;
  const double _t137 = _t136*_t2;
  const double _t138 = (0.5e1 / 0.165888e6)*_t118*_t132*_t61 - _t130*sigma_ss + _t134*_t88 + _t135*_t137 - 0.11e2 / 0.41472e5*_t38*_t92 + (0.7e1 / 0.216e3)*_t56*sigma_ss - 0.1e1 / 0.432e3*_t64*_t7*_t75 + (0.5e1 / 0.1152e4)*_t65*_t7*_t74 + (0.1e1 / 0.54e2)*_t68 - _t86 - 0.5e1 / 0.432e3*_t87*sigma_ss;
  const double _t139 = my_piecewise3(_t1, 0, _t138*_t47 + _t82*_t84);
  const double _t140 = _t29*_t96;
  const double _t141 = _t29*_t98;
  const double _t142 = (0.19e2 / 0.162e3)*_t105;
  const double _t143 = _t102*_t20;
  const double _t144 = _t121/xc_powi(n_s, 18);
  const double _t145 = _t118*_t144;
  const double _t146 = _t38*_t7;
  const double _t147 = (0.25e2 / 0.3456e4)*_t106;
  const double _t148 = (0.1e1 / 0.7776e4)*_t113;
  const double _t149 = (0.3e1 / 0.32e2)*_t100*_t20 + _t101*_t85 - 0.65e2 / 0.648e3*_t104*_t26*_t37 - 0.317e3 / 0.20736e5*_t107*_t146 - _t109*_t133*_t2 - 0.5e1 / 0.62208e5*_t112*_t145 + (0.11e2 / 0.13824e5)*_t114*_t61 - _t136*_t148*_t60 + _t142*sigma_ss - 0.167e3 / 0.1296e4*_t143*_t34 + (0.17e2 / 0.432e3)*_t143*_t73 + _t147*_t90;
  const double _t150 = my_piecewise3(_t1, 0, -_t140*_t46 + _t141*_t93 + _t149*_t47);
  const double _t151 = xc_powr(n_s, -7, 3);
  const double _t152 = (0.2e1 / 0.45e2)*_t151;
  const double _t153 = (0.1e1 / 0.10e2)*_t95;
  const double _t154 = _t115*_t29;
  const double _t155 = (0.3e1 / 0.10e2)*_t49;
  const double _t156 = xc_powi(n_s, -11);
  const double _t157 = _t156*_t16;
  const double _t158 = (0.154e3 / 0.81e2)/xc_powr(n_s, 17, 3);
  const double _t159 = xc_powr(n_s, -25, 3);
  const double _t160 = _t159*_t58;
  const double _t161 = xc_powi(n_s, -19);
  const double _t162 = xc_powi(sigma_ss, 6);
  const double _t163 = _t15*_t156;
  const double _t164 = xc_powr(n_s, -41, 3);
  const double _t165 = _t164*_t42;
  const double _t166 = xc_powr(n_s, -49, 3);
  const double _t167 = _t166*_t80;
  const double _t168 = -0.1e1 / 0.48e2*_t110*_t165 + (0.1e1 / 0.2916e4)*_t111*_t118*_t166*_t23*_t77*_t78*params->c2 - 0.35e2 / 0.15552e5*_t112*_t167 + (0.5e1 / 0.23328e5)*_t118*_t119*_t120*_t161*_t162*params->c3 + (0.1e1 / 0.486e3)*_t118*_t164*_t40*_t41*_t60*_t7*params->c1 + (0.797e3 / 0.1944e4)*_t14*_t156*_t2*_t4*params->a*params->c2 - 0.5e1 / 0.16e2*_t157*_t2 - _t158*_t54 + (0.341e3 / 0.972e3)*_t159*_t20*_t23*_t24*_t25*params->a*params->c1 - 0.209e3 / 0.486e3*_t160*_t20 - 0.19e2 / 0.162e3*_t163*_t2*_t73 + (0.1445e4 / 0.31104e5)*_t164*_t40*_t41*_t60*_t7*params->a*params->c3;
  const double _t169 = my_piecewise3(_t1, 0, _t152*_t30 - _t153*_t97 + _t154*_t155 + _t168*_t47);
#endif
#if _KMAX >= 4
  const double _t170 = (0.1e1 / 0.768e3)*_t43;
  const double _t171 = ((params->a) * (params->a) * (params->a) * (params->a));
  const double _t172 = _t171*_t79;
  const double _t173 = _t172*params->c1;
  const double _t174 = _t171/((M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI)*xc_powi(_t13, 7));
  const double _t175 = _t171*params->c2;
  const double _t176 = _t102*sigma_ss;
  const double _t177 = _t174*_t7;
  const double _t178 = _t162*params->c3;
  const double _t179 = _t2/xc_powi(n_s, 12);
  const double _t180 = _t15*_t179;
  const double _t181 = _t20/xc_powr(n_s, 28, 3);
  const double _t182 = _t121/xc_powi(n_s, 20);
  const double _t183 = _t42/xc_powr(n_s, 44, 3);
  const double _t184 = xc_powr(n_s, -52, 3);
#endif

  const double f = my_piecewise3(_t1, 0, _t32*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t1, 0, _t48*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t1, 0, _t32 + _t70*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t1, 0, _t83*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t1, 0, _t48 + _t94*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t1, 0, _t116*n_s + 0.2e1*_t70);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t1, 0, _t129*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t1, 0, _t139*n_s + _t83);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t1, 0, _t150*n_s + 0.2e1*_t94);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t1, 0, 0.3e1*_t116 + _t169*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, _t47*(-_t117*_t170*params->a + (0.5e1 / 0.221184e6)*_t122*_t171*_t21 - 0.5e1 / 0.36864e5*_t123*_t74 - 0.1e1 / 0.2304e4*_t125 - 0.1e1 / 0.6912e4*_t127*params->c2*sigma_ss + (0.5e1 / 0.1769472e7)*_t146*_t174/xc_powr(n_s, 56, 3) + _t170*_t89 + (0.1e1 / 0.55296e5)*_t173*_t76*sigma_ss + (0.1e1 / 0.3072e4)*_t81*params->c3*sigma_ss)));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t1, 0, _t129 + n_s*my_piecewise3(_t1, 0, _t128*_t84 + _t47*(-_t108*_t135*_t172 + (0.25e2 / 0.55296e5)*_t118*_t119*_t120*_t131*_t2*params->c3 + (0.11e2 / 0.20736e5)*_t118*_t20*_t23*_t77*_t78*_t91*params->c2 + (0.7e1 / 0.3456e4)*_t118*_t40*_t41*_t63*_t7*params->c1*sigma_ss - _t130 - 0.5e1 / 0.82944e5*_t132*_t175*_t2 + (0.1e1 / 0.24e2)*_t14*_t4*_t51*params->a*params->c2 - 0.5e1 / 0.663552e6*_t174*_t62/xc_powr(n_s, 59, 3) + (0.13e2 / 0.1152e4)*_t40*_t41*_t63*_t7*params->a*params->c3*sigma_ss - 0.5e1 / 0.576e3*_t64*_t89*sigma_ss - 0.7e1 / 0.4608e4*_t74*_t92 - 0.1e1 / 0.48e2*_t87)));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t1, 0, 0.2e1*_t139 + n_s*my_piecewise3(_t1, 0, _t138*_t141 - _t140*_t82 + _t47*((0.3e1 / 0.16e2)*_t100*sigma_ss - 0.19e2 / 0.162e3*_t104*_t67 + (0.49e2 / 0.1296e4)*_t106*_t7*_t75 - 0.199e3 / 0.3456e4*_t107*_t7*_t74 + (0.5e1 / 0.248832e6)*_t112*_t177/xc_powr(n_s, 62, 3) - 0.107e3 / 0.62208e5*_t113*_t137 + (0.713e3 / 0.124416e6)*_t114*_t38 - _t134*_t147 + _t142 + (0.5e1 / 0.31104e5)*_t144*_t175*_t60 - 0.695e3 / 0.497664e6*_t145*_t61 + _t148*_t173*_t2 - 0.205e3 / 0.648e3*_t176*_t34 + (0.167e3 / 0.1296e4)*_t176*_t73)));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t1, 0, 0.3e1*_t150 + n_s*my_piecewise3(_t1, 0, _t149*_t155*_t29 + _t152*_t29*_t46 - _t153*_t29*_t93 + _t47*((0.85e2 / 0.20736e5)*_t111*_t118*_t119*_t120*_t161*params->c3 - 0.5e1 / 0.11664e5*_t111*_t121*_t161*_t175 + (0.89e2 / 0.3888e4)*_t118*_t164*_t2*_t40*_t41*_t7*params->c1 + (0.121e3 / 0.23328e5)*_t118*_t166*_t23*_t60*_t77*_t78*params->c2 + (0.2809e4 / 0.1944e4)*_t14*_t156*_t20*_t4*params->a*params->c2 - 0.15e2 / 0.16e2*_t157*_t20 - _t158*_t85 + (0.253e3 / 0.324e3)*_t159*_t23*_t24*_t25*params->a*params->c1*sigma_ss - 0.209e3 / 0.243e3*_t160*sigma_ss - 0.1025e4 / 0.1944e4*_t163*_t20*_t73 + (0.6995e4 / 0.31104e5)*_t164*_t2*_t40*_t41*_t7*params->a*params->c3 - 0.2093e4 / 0.15552e5*_t165*_t90 - 0.1e1 / 0.2916e4*_t166*_t173*_t60 - 0.3545e4 / 0.186624e6*_t167*_t61 - 0.5e1 / 0.93312e5*_t177*_t178/xc_powr(n_s, 65, 3))));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t1, 0, 0.4e1*_t169 + n_s*my_piecewise3(_t1, 0, (0.8e1 / 0.45e2)*_t151*_t97 - 0.1e1 / 0.5e1*_t154*_t95 + (0.2e1 / 0.5e1)*_t168*_t29*_t49 - 0.14e2 / 0.135e3*_t30/xc_powr(n_s, 10, 3) + _t47*((0.4915e4 / 0.11664e5)*_t110*_t183 - 0.65e2 / 0.4374e4*_t111*_t136*_t184 + (0.2e1 / 0.2187e4)*_t111*_t173*_t184 + (0.8035e4 / 0.139968e6)*_t112*_t184*_t80 + (0.5e1 / 0.34992e5)*_t117*_t174*xc_powi(sigma_ss, 7)/xc_powr(n_s, 68, 3) - 0.5e1 / 0.432e3*_t118*_t178*_t182 - 0.49e2 / 0.729e3*_t133*_t183*_t60 + (0.55e2 / 0.16e2)*_t16*_t179 + (0.5e1 / 0.4374e4)*_t162*_t175*_t182 - 0.29645e5 / 0.5832e4*_t180*_t34 + (0.2563e4 / 0.1458e4)*_t180*_t73 + (0.5225e4 / 0.1458e4)*_t181*_t58 - 0.3047e4 / 0.972e3*_t181*_t67 - 0.68965e5 / 0.93312e5*_t183*_t62*params->a + (0.2618e4 / 0.243e3)*_t54/xc_powr(n_s, 20, 3))));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_k_mpbe_params *params = (const gga_k_mpbe_params *)(p->params);
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