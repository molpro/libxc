/*
  Generated from python/gga_exc/gga_k_pw86.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_k_pw86
*/

#ifndef _GGA_K_PW86_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_K_PW86_KERNEL_BODY
#define _KMAX 0
#define _GGA_K_PW86_HELPER_BODIES
#include "gga_k_pw86.c"
#undef _GGA_K_PW86_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_K_PW86_HELPER_BODIES
#include "gga_k_pw86.c"
#undef _GGA_K_PW86_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_K_PW86_HELPER_BODIES
#include "gga_k_pw86.c"
#undef _GGA_K_PW86_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_K_PW86_HELPER_BODIES
#include "gga_k_pw86.c"
#undef _GGA_K_PW86_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_K_PW86_HELPER_BODIES
#include "gga_k_pw86.c"
#undef _GGA_K_PW86_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_k_pw86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_k_pw86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_k_pw86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_k_pw86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_k_pw86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_k_pw86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_k_pw86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_k_pw86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_k_pw86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_k_pw86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_K_PW86_HELPER_BODIES)

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

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n5_3_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  const double _t1 = -p->dens_threshold + n_s <= 0;
  const double _t2 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t3 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t4 = _t3/xc_powi(n_s, 8);
  const double _t5 = (M_PI * M_CBRTPI);
  const double _t6 = xc_powr(0.6e1, 1, 3)/_t5;
  const double _t7 = _t6/xc_powr(n_s, 8, 3);
  const double _t8 = (sigma_ss * sigma_ss);
  const double _t9 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t10 = xc_powr(0.6e1, 2, 3)*_t9;
  const double _t11 = _t10/xc_powr(n_s, 16, 3);
  const double _t12 = 0.016093749999999997*_t11*_t8 + 8.6805555555555559e-5*_t2*_t4 + 0.091999999999999998*_t7*sigma_ss + 0.1e1;
  const double _t13 = xc_powr(0.3e1, 2, 3)*(_hc0[0] + 0.1e1);
  const double _t14 = _t13*_t5;
  const double _t15 = pow(_t12, 0.1e1 / 0.15e2)*_t14;
  const double _t16 = xc_powr(n_s, 2, 3);
  const double _t17 = (0.3e1 / 0.20e2)*_t16;
  const double _t18 = my_piecewise3(_t1, 0, _t15*_t17);
#if _KMAX >= 1
  const double _t19 = _t4*_t8;
  const double _t20 = 0.0021458333333333329*_t11;
  const double _t21 = 1.7361111111111111e-5*_t19 + _t20*sigma_ss + 0.0061333333333333335*_t7;
  const double _t22 = pow(_t12, -0.14e2 / 0.15e2);
  const double _t23 = _t14*_t22;
  const double _t24 = _t17*_t23;
  const double _t25 = my_piecewise3(_t1, 0, _t21*_t24);
  const double _t26 = xc_powr(n_s, -1, 3);
  const double _t27 = (0.1e1 / 0.10e2)*_t26;
  const double _t28 = _t3/xc_powi(n_s, 9);
  const double _t29 = _t2*_t28;
  const double _t30 = _t6/xc_powr(n_s, 11, 3);
  const double _t31 = 0.016355555555555554*_t30;
  const double _t32 = _t10/xc_powr(n_s, 19, 3);
  const double _t33 = _t32*_t8;
  const double _t34 = -4.6296296296296301e-5*_t29 - _t31*sigma_ss - 0.0057222222222222214*_t33;
  const double _t35 = my_piecewise3(_t1, 0, _t15*_t27 + _t24*_t34);
#endif
#if _KMAX >= 2
  const double _t36 = _t4*sigma_ss;
  const double _t37 = _t20 + 3.4722222222222222e-5*_t36;
  const double _t38 = pow(_t12, -0.29e2 / 0.15e2);
  const double _t39 = 0.030041666666666661*_t11;
  const double _t40 = -0.00024305555555555555*_t19 - _t39*sigma_ss - 0.085866666666666661*_t7;
  const double _t41 = _t38*_t40;
  const double _t42 = _t14*_t17;
  const double _t43 = _t41*_t42;
  const double _t44 = my_piecewise3(_t1, 0, _t21*_t43 + _t24*_t37);
  const double _t45 = _t23*_t27;
  const double _t46 = _t28*_t8;
  const double _t47 = 0.011444444444444443*_t32;
  const double _t48 = -_t31 - 0.00013888888888888892*_t46 - _t47*sigma_ss;
  const double _t49 = my_piecewise3(_t1, 0, _t21*_t45 + _t24*_t48 + _t34*_t43);
  const double _t50 = xc_powr(n_s, -4, 3);
  const double _t51 = (0.1e1 / 0.30e2)*_t50;
  const double _t52 = _t23*_t34;
  const double _t53 = (0.1e1 / 0.5e1)*_t26;
  const double _t54 = _t3/xc_powi(n_s, 10);
  const double _t55 = _t2*_t54;
  const double _t56 = _t6/xc_powr(n_s, 14, 3);
  const double _t57 = 0.059970370370370361*_t56;
  const double _t58 = xc_powr(n_s, -22, 3);
  const double _t59 = _t10*_t58;
  const double _t60 = _t59*_t8;
  const double _t61 = 0.00041666666666666669*_t55 + _t57*sigma_ss + 0.036240740740740733*_t60;
  const double _t62 = 0.22897777777777778*_t30;
  const double _t63 = 0.00064814814814814813*_t29 + 0.080111111111111091*_t33 + _t62*sigma_ss;
  const double _t64 = _t34*_t38;
  const double _t65 = _t42*_t64;
  const double _t66 = my_piecewise3(_t1, 0, -_t15*_t51 + _t24*_t61 + _t52*_t53 + _t63*_t65);
#endif
#if _KMAX >= 3
  const double _t67 = _t13*_t22*_t9;
  const double _t68 = -0.0004861111111111111*_t36 - _t39;
  const double _t69 = _t21*_t38;
  const double _t70 = _t68*_t69;
  const double _t71 = (0.3e1 / 0.10e2)*_t16;
  const double _t72 = _t14*_t41;
  const double _t73 = _t37*_t72;
  const double _t74 = 0.062229166666666655*_t11;
  const double _t75 = -0.00050347222222222221*_t19 - 0.17786666666666667*_t7 - _t74*sigma_ss;
  const double _t76 = pow(_t12, -0.44e2 / 0.15e2);
  const double _t77 = _t42*_t76;
  const double _t78 = _t75*_t77;
  const double _t79 = _t40*_t78;
  const double _t80 = my_piecewise3(_t1, 0, _t21*_t79 + _t42*_t70 + 5.2083333333333332e-6*_t58*_t67 + _t71*_t73);
  const double _t81 = _t28*sigma_ss;
  const double _t82 = -_t47 - 0.00027777777777777783*_t81;
  const double _t83 = _t21*_t72;
  const double _t84 = _t48*_t72;
  const double _t85 = my_piecewise3(_t1, 0, _t24*_t82 + _t27*_t83 + _t34*_t79 + _t37*_t45 + _t65*_t68 + _t71*_t84);
  const double _t86 = _t23*_t51;
  const double _t87 = _t23*_t53;
  const double _t88 = _t54*_t8;
  const double _t89 = 0.072481481481481466*_t59;
  const double _t90 = _t57 + 0.00125*_t88 + _t89*sigma_ss;
  const double _t91 = _t34*_t72;
  const double _t92 = _t38*_t63;
  const double _t93 = _t42*_t92;
  const double _t94 = 0.16022222222222218*_t32;
  const double _t95 = 0.0019444444444444444*_t46 + _t62 + _t94*sigma_ss;
  const double _t96 = _t34*_t63;
  const double _t97 = my_piecewise3(_t1, 0, -_t21*_t86 + _t24*_t90 + _t43*_t61 + _t48*_t87 + _t48*_t93 + _t53*_t91 + _t65*_t95 + _t78*_t96);
  const double _t98 = xc_powr(n_s, -7, 3);
  const double _t99 = (0.2e1 / 0.45e2)*_t98;
  const double _t100 = (0.1e1 / 0.10e2)*_t50;
  const double _t101 = _t23*_t61;
  const double _t102 = (0.3e1 / 0.10e2)*_t26;
  const double _t103 = _t3/xc_powi(n_s, 11);
  const double _t104 = _t103*_t2;
  const double _t105 = _t6/xc_powr(n_s, 17, 3);
  const double _t106 = 0.27986172839506168*_t105;
  const double _t107 = xc_powr(n_s, -25, 3);
  const double _t108 = _t10*_t107;
  const double _t109 = _t108*_t8;
  const double _t110 = -0.0041666666666666666*_t104 - _t106*sigma_ss - 0.26576543209876535*_t109;
  const double _t111 = _t14*_t64;
  const double _t112 = _t102*_t111;
  const double _t113 = 0.83958518518518521*_t56;
  const double _t114 = -_t113*sigma_ss - 0.0058333333333333327*_t55 - 0.50737037037037025*_t60;
  const double _t115 = _t14*_t71;
  const double _t116 = _t115*_t92;
  const double _t117 = 0.47431111111111107*_t30;
  const double _t118 = _t117*sigma_ss + 0.0013425925925925927*_t29 + 0.16594444444444442*_t33;
  const double _t119 = _t77*_t96;
  const double _t120 = my_piecewise3(_t1, 0, -_t100*_t52 + _t101*_t102 + _t110*_t24 + _t112*_t63 + _t114*_t65 + _t116*_t61 + _t118*_t119 + _t15*_t99);
#endif
#if _KMAX >= 4
  const double _t121 = _t13*_t58*_t9;
  const double _t122 = 7.2916666666666659e-5*_t121;
  const double _t123 = _t38*_t68;
  const double _t124 = (0.9e1 / 0.20e2)*_t16;
  const double _t125 = _t124*_t14;
  const double _t126 = _t125*_t37;
  const double _t127 = _t21*_t40;
  const double _t128 = -0.0010069444444444444*_t36 - _t74;
  const double _t129 = _t128*_t77;
  const double _t130 = _t75*_t76;
  const double _t131 = _t130*_t21;
  const double _t132 = _t115*_t68;
  const double _t133 = _t130*_t40;
  const double _t134 = _t42/pow(_t12, 0.59e2 / 0.15e2);
  const double _t135 = _t134*(-0.094416666666666649*_t11*sigma_ss - 0.00076388888888888882*_t19 - 0.26986666666666664*_t7);
  const double _t136 = _t135*_t75;
  const double _t137 = _t14*_t27;
  const double _t138 = _t125*_t48;
  const double _t139 = _t34*_t40;
  const double _t140 = _t130*_t34;
  const double _t141 = _t42*_t61;
  const double _t142 = (0.2e1 / 0.5e1)*_t26;
  const double _t143 = _t38*_t48;
  const double _t144 = _t115*_t95;
  const double _t145 = _t48*_t63;
  const double _t146 = _t115*_t130;
  const double _t147 = _t14*_t92;
  const double _t148 = _t114*_t42;
  const double _t149 = _t38*_t61;
  const double _t150 = _t14*_t96;
  const double _t151 = _t61*_t63;
  const double _t152 = _t118*_t77;
  const double _t153 = _t118*_t96;
  const double _t154 = (0.1e1 / 0.5e1)*_t50;
  const double _t155 = _t118*_t76;
#endif

  const double f = my_piecewise3(_t1, 0, _t18*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t1, 0, _t25*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t1, 0, _t18 + _t35*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t1, 0, _t44*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t1, 0, _t25 + _t49*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t1, 0, 0.2e1*_t35 + _t66*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t1, 0, _t80*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t1, 0, _t44 + _t85*n_s);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t1, 0, 0.2e1*_t49 + _t97*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t1, 0, _t120*n_s + 0.3e1*_t66);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, 1.5625e-5*_t121*_t41 - _t122*_t69 + _t123*_t126 + _t126*_t133 + _t127*_t129 + _t127*_t136 + _t131*_t132));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t1, 0, _t80 + n_s*my_piecewise3(_t1, 0, -3.8194444444444451e-5*_t107*_t67 - _t122*_t64 + _t123*_t138 + _t124*_t72*_t82 + _t129*_t139 + _t131*_t137*_t40 + _t132*_t140 + _t133*_t138 + _t136*_t139 + _t137*_t70 + _t53*_t73));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t1, 0, 0.2e1*_t85 + n_s*my_piecewise3(_t1, 0, _t111*_t53*_t68 + _t119*_t128 + _t123*_t141 + _t133*_t14*_t34*_t53 + _t133*_t141 + _t136*_t96 + _t140*_t144 + _t142*_t84 + _t143*_t144 + _t145*_t146 + _t24*(0.0025000000000000001*_t54*sigma_ss + _t89) - _t37*_t86 - _t51*_t83 + _t65*(0.0038888888888888888*_t81 + _t94) + _t71*_t72*_t90 + _t82*_t87 + _t82*_t93));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t1, 0, 0.3e1*_t97 + n_s*my_piecewise3(_t1, 0, -_t100*_t23*_t48 - _t100*_t91 + _t102*_t130*_t150 + _t102*_t147*_t48 + _t102*_t23*_t90 + _t102*_t61*_t72 + _t110*_t43 + _t112*_t95 + _t116*_t90 + _t119*(_t117 + 0.33188888888888884*_t32*sigma_ss + 0.0040277777777777777*_t46) + _t135*_t153 + _t140*_t148 + _t143*_t148 + _t144*_t149 + _t145*_t152 + _t146*_t151 + _t152*_t34*_t95 + _t21*_t23*_t99 + _t24*(-0.012500000000000001*_t103*_t8 - _t106 - 0.53153086419753071*_t108*sigma_ss) + _t65*(-_t113 - 1.0147407407407405*_t59*sigma_ss - 0.017499999999999998*_t88)));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t1, 0, 0.4e1*_t120 + n_s*my_piecewise3(_t1, 0, -_t101*_t154 + _t110*_t125*_t92 + _t110*_t142*_t23 + _t111*_t114*_t142 - _t111*_t154*_t63 + _t114*_t115*_t155*_t34 + _t114*_t125*_t149 + _t119*(-0.012083333333333335*_t55 - 1.7391407407407404*_t56*sigma_ss - 1.0509814814814813*_t60) + _t125*_t151*_t155 + _t134*_t153*(0.0020370370370370369*_t29 + 0.71964444444444431*_t30*sigma_ss + 0.25177777777777771*_t33) + _t142*_t150*_t155 + (0.4e1 / 0.5e1)*_t147*_t26*_t61 - 0.14e2 / 0.135e3*_t15/xc_powr(n_s, 10, 3) + _t24*(2.2147119341563779*_t10*_t8/xc_powr(n_s, 28, 3) + 0.04583333333333333*_t2*_t3/xc_powi(n_s, 12) + 1.5858831275720162*_t6*sigma_ss/xc_powr(n_s, 20, 3)) + (0.8e1 / 0.45e2)*_t52*_t98 + _t65*(0.058333333333333327*_t104 + 3.9180641975308648*_t105*sigma_ss + 3.7207160493827152*_t109)));
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