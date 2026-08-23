/*
  Generated from python/mgga_exc/mgga_x_2d_js17.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_2d_js17
*/

#ifndef _MGGA_X_2D_JS17_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_2D_JS17_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_2D_JS17_HELPER_BODIES
#include "mgga_x_2d_js17.c"
#undef _MGGA_X_2D_JS17_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_2D_JS17_HELPER_BODIES
#include "mgga_x_2d_js17.c"
#undef _MGGA_X_2D_JS17_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_2D_JS17_HELPER_BODIES
#include "mgga_x_2d_js17.c"
#undef _MGGA_X_2D_JS17_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_2D_JS17_HELPER_BODIES
#include "mgga_x_2d_js17.c"
#undef _MGGA_X_2D_JS17_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_2D_JS17_HELPER_BODIES
#include "mgga_x_2d_js17.c"
#undef _MGGA_X_2D_JS17_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_2d_js17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_2d_js17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_2d_js17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_2d_js17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_2d_js17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_2d_js17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_2d_js17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_2d_js17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_2d_js17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_2d_js17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_2D_JS17_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_m1_n3_2_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z - p->zeta_threshold + 0.1e1;
  const double _t2 = _t1 <= 0;
  const double _t3 = _t1 > 0;
  const double _t4 = my_piecewise3(_t3, z, p->zeta_threshold - 0.1e1);
  const double _t5 = xc_expm1((0.3e1 / 0.2e1)*xc_log1p(_t4));
#if _KMAX >= 1
  const double _t6 = my_piecewise3(_t3, 0.1e1, 0);
  const double _t7 = _t4 + 0.1e1;
  const double _t8 = _t5 + 0.1e1;
#endif

  const double f = my_piecewise3(_t2, xc_powr(p->zeta_threshold, 3, 2) - 0.1e1, _t5);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise3(_t2, 0, (0.3e1 / 0.2e1)*_t6*_t8/_t7);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise3(_t2, 0, (0.3e1 / 0.4e1)*(_t6 * _t6)*_t8/(_t7 * _t7));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise3(_t2, 0, -0.3e1 / 0.8e1*(_t6 * _t6 * _t6)*_t8/(_t7 * _t7 * _t7));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = my_piecewise3(_t2, 0, (0.9e1 / 0.16e2)*(_t6 * _t6 * _t6 * _t6)*_t8/(_t7 * _t7 * _t7 * _t7));
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n3_2_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  const double _t1 = -p->dens_threshold + n_s <= 0;
  const double _t2 = xc_powr(n_s, 1, 2);
  const double _t3 = (0.2e1 / 0.3e1)*_t2;
  const double _t4 = (0.1e1 / M_PI);
  const double _t5 = (0.1e1 / (n_s * n_s * n_s));
  const double _t6 = _t4*_t5;
  const double _t7 = _t6*sigma_ss;
  const double _t8 = (sigma_ss * sigma_ss);
  const double _t9 = xc_powi(n_s, -6);
  const double _t10 = (0.1e1 / (M_PI * M_PI));
  const double _t11 = _t10*_t9;
  const double _t12 = 0.0062207999999999986*_t11*_t8 + 1.296*_t7 + 0.1e1;
  const double _t13 = (0.1e1 / (n_s * n_s));
  const double _t14 = (0.1e1 / 0.4e1)*_t4*(-0.077200000000000046*_t13*tau_s + 0.30880000000000019*M_PI) + 0.08777142857142857*_t7;
  const double _t15 = pow(_t12, -0.1e1 / 0.5e1);
  const double _t16 = (0.2e1 / 0.5e1)*_t15;
  const double _t17 = _t14*_t16 + pow(_t12, -0.1e1 / 0.15e2);
  const double _t18 = xc_powr(M_PI, -1, 2);
  const double _t19 = xc_powr(0.2e1, 1, 2);
  const double _t20 = _hc0[0] + 0.1e1;
  const double _t21 = _t19*_t20;
  const double _t22 = _t18*_t21;
  const double _t23 = _t17*_t22;
  const double _t24 = my_piecewise3(_t1, 0, -_t23*_t3);
#if _KMAX >= 1
  const double _t25 = xc_powr(M_PI, -3, 2);
  const double _t26 = _t21*_t25;
  const double _t27 = _t15*_t26;
  const double _t28 = xc_powr(n_s, -3, 2);
  const double _t29 = 0.0051466666666666692*_t28;
  const double _t30 = my_piecewise3(_t1, 0, _t27*_t29);
  const double _t31 = _t11*sigma_ss;
  const double _t32 = -0.00082943999999999976*_t31 - 0.086400000000000005*_t6;
  const double _t33 = pow(_t12, -0.16e2 / 0.15e2);
  const double _t34 = pow(_t12, -0.6e1 / 0.5e1);
  const double _t35 = -0.0024883199999999996*_t31 - 0.25920000000000004*_t6;
  const double _t36 = _t34*_t35;
  const double _t37 = (0.2e1 / 0.5e1)*_t14;
  const double _t38 = 0.035108571428571426*_t15*_t6 + _t32*_t33 + _t36*_t37;
  const double _t39 = _t22*_t3;
  const double _t40 = my_piecewise3(_t1, 0, -_t38*_t39);
  const double _t41 = _t22/_t2;
  const double _t42 = (0.1e1 / 0.3e1)*_t41;
  const double _t43 = _t4/(n_s * n_s * n_s * n_s);
  const double _t44 = _t43*sigma_ss;
  const double _t45 = -0.26331428571428572*_t44 + 0.038600000000000023*_t6*tau_s;
  const double _t46 = 0.25919999999999999*_t43;
  const double _t47 = xc_powi(n_s, -7);
  const double _t48 = _t10*_t47;
  const double _t49 = _t48*_t8;
  const double _t50 = _t46*sigma_ss + 0.0024883199999999996*_t49;
  const double _t51 = 0.77760000000000007*_t43;
  const double _t52 = 0.0074649599999999988*_t49 + _t51*sigma_ss;
  const double _t53 = _t34*_t37;
  const double _t54 = _t16*_t45 + _t33*_t50 + _t52*_t53;
  const double _t55 = _t22*_t54;
  const double _t56 = my_piecewise3(_t1, 0, -_t17*_t42 - _t3*_t55);
#endif
#if _KMAX >= 2
  const double _t57 = _t26*_t36;
  const double _t58 = my_piecewise3(_t1, 0, _t29*_t57);
  const double _t59 = _t14*_t34;
  const double _t60 = 0.00099532799999999997*_t11;
  const double _t61 = pow(_t12, -0.31e2 / 0.15e2);
  const double _t62 = -0.013271039999999996*_t31 - 1.3824000000000001*_t6;
  const double _t63 = _t61*_t62;
  const double _t64 = pow(_t12, -0.11e2 / 0.5e1);
  const double _t65 = _t37*_t64;
  const double _t66 = -0.014929919999999996*_t31 - 1.5551999999999999*_t6;
  const double _t67 = _t35*_t66;
  const double _t68 = -0.00082943999999999976*_t11*_t33 + _t32*_t63 + 0.070217142857142853*_t36*_t6 - _t59*_t60 + _t65*_t67;
  const double _t69 = my_piecewise3(_t1, 0, -_t39*_t68);
  const double _t70 = xc_powr(n_s, -5, 2);
  const double _t71 = _t34*_t52;
  const double _t72 = _t13*_t4;
  const double _t73 = 0.0077200000000000046*_t72;
  const double _t74 = 0.015440000000000009*_t15*_t4*_t5 - _t71*_t73;
  const double _t75 = my_piecewise3(_t1, 0, 0.0025733333333333346*_t15*_t19*_t20*_t25*_t70 - _t39*_t74);
  const double _t76 = _t15*_t43;
  const double _t77 = _t48*sigma_ss;
  const double _t78 = _t46 + 0.0049766399999999992*_t77;
  const double _t79 = (0.2e1 / 0.5e1)*_t36;
  const double _t80 = _t51 + 0.014929919999999998*_t77;
  const double _t81 = _t52*_t65;
  const double _t82 = _t33*_t78 + _t45*_t79 + _t50*_t63 + _t53*_t80 + 0.035108571428571426*_t6*_t71 + _t66*_t81 - 0.1053257142857143*_t76;
  const double _t83 = my_piecewise3(_t1, 0, -_t38*_t42 - _t39*_t82);
  const double _t84 = (0.2e1 / 0.3e1)*_t41;
  const double _t85 = xc_powi(n_s, -5);
  const double _t86 = 1.0532571428571429*_t4*_t85*sigma_ss - 0.11580000000000007*_t43*tau_s;
  const double _t87 = _t4*_t85;
  const double _t88 = 1.0367999999999999*_t87;
  const double _t89 = xc_powi(n_s, -8);
  const double _t90 = _t10*_t89;
  const double _t91 = _t8*_t90;
  const double _t92 = -_t88*sigma_ss - 0.017418239999999998*_t91;
  const double _t93 = _t34*_t45;
  const double _t94 = (0.4e1 / 0.5e1)*_t52;
  const double _t95 = 4.1471999999999998*_t43;
  const double _t96 = 0.039813119999999994*_t49 + _t95*sigma_ss;
  const double _t97 = _t61*_t96;
  const double _t98 = 3.1104000000000003*_t87;
  const double _t99 = -0.052254719999999991*_t91 - _t98*sigma_ss;
  const double _t100 = 4.6655999999999995*_t43;
  const double _t101 = _t100*sigma_ss + 0.044789759999999991*_t49;
  const double _t102 = _t101*_t81 + _t16*_t86 + _t33*_t92 + _t50*_t97 + _t53*_t99 + _t93*_t94;
  const double _t103 = my_piecewise3(_t1, 0, -_t102*_t22*_t3 + (0.1e1 / 0.6e1)*_t17*_t18*_t19*_t20*_t28 - _t54*_t84);
#endif
#if _KMAX >= 3
  const double _t104 = (0.1e1 / (M_PI * M_PI * M_PI));
  const double _t105 = _t64*_t67;
  const double _t106 = 1.9209830400000012e-5*_t104*_t34*_t89 - _t105*_t73;
  const double _t107 = my_piecewise3(_t1, 0, -_t106*_t39);
  const double _t108 = xc_powi(n_s, -9);
  const double _t109 = _t104*_t34;
  const double _t110 = _t108*_t109;
  const double _t111 = 0.013271039999999996*_t11;
  const double _t112 = _t14*_t64;
  const double _t113 = _t11*_t112;
  const double _t114 = 0.0059719679999999985*_t113;
  const double _t115 = -0.025712639999999995*_t31 - 2.6784000000000003*_t6;
  const double _t116 = pow(_t12, -0.46e2 / 0.15e2);
  const double _t117 = -0.027371519999999996*_t31 - 2.8512000000000004*_t6;
  const double _t118 = pow(_t12, -0.16e2 / 0.5e1);
  const double _t119 = -0.0016588799999999995*_t11*_t63 - 0.00026208408137142852*_t110 - _t111*_t32*_t61 - 0.0019906559999999999*_t113*_t66 - _t114*_t35 + _t115*_t116*_t32*_t62 + (0.2e1 / 0.5e1)*_t117*_t118*_t14*_t35*_t66 + 0.10532571428571427*_t35*_t4*_t5*_t64*_t66;
  const double _t120 = my_piecewise3(_t1, 0, -_t119*_t39);
  const double _t121 = _t34*_t80;
  const double _t122 = _t52*_t64;
  const double _t123 = _t122*_t66;
  const double _t124 = -_t121*_t73 - _t123*_t73 + 0.015440000000000009*_t34*_t35*_t4*_t5;
  const double _t125 = my_piecewise3(_t1, 0, -_t124*_t39 + 0.0025733333333333346*_t19*_t20*_t25*_t34*_t35*_t70);
  const double _t126 = 0.0049766399999999992*_t48;
  const double _t127 = 0.2106514285714286*_t43;
  const double _t128 = _t50*_t61;
  const double _t129 = 0.0059719679999999994*_t48;
  const double _t130 = 0.2e1*_t63;
  const double _t131 = 0.070217142857142853*_t6;
  const double _t132 = _t45*_t64;
  const double _t133 = (0.2e1 / 0.5e1)*_t67;
  const double _t134 = _t115*_t116;
  const double _t135 = _t134*_t62;
  const double _t136 = (0.4e1 / 0.5e1)*_t80;
  const double _t137 = _t112*_t136;
  const double _t138 = _t118*_t37;
  const double _t139 = _t117*_t138;
  const double _t140 = _t139*_t52;
  const double _t141 = -_t111*_t128 - _t114*_t52 + 0.070217142857142853*_t121*_t6 + _t123*_t131 + _t126*_t33 - _t127*_t36 + _t129*_t59 + _t130*_t78 + _t132*_t133 + _t135*_t50 + _t137*_t66 + _t140*_t66 - _t60*_t93;
  const double _t142 = my_piecewise3(_t1, 0, -_t141*_t39 - _t42*_t68);
  const double _t143 = xc_powr(n_s, -7, 2);
  const double _t144 = 0.0012866666666666673*_t143;
  const double _t145 = _t34*_t99;
  const double _t146 = _t101*_t122;
  const double _t147 = -_t145*_t73 - _t146*_t73 + 0.030880000000000019*_t34*_t4*_t5*_t52 - 0.046320000000000028*_t76;
  const double _t148 = my_piecewise3(_t1, 0, -_t144*_t27 - _t147*_t39 - _t74*_t84);
  const double _t149 = _t90*sigma_ss;
  const double _t150 = -0.034836479999999996*_t149 - _t88;
  const double _t151 = 0.079626239999999987*_t77 + _t95;
  const double _t152 = -0.10450943999999998*_t149 - _t98;
  const double _t153 = 0.035108571428571426*_t6;
  const double _t154 = _t132*_t66;
  const double _t155 = _t50*_t96;
  const double _t156 = _t65*_t80;
  const double _t157 = _t100 + 0.089579519999999982*_t77;
  const double _t158 = _t65*_t66;
  const double _t159 = _t101*_t140 + _t101*_t156 - _t127*_t71 + _t128*_t151 + _t134*_t155 + _t136*_t93 + 0.035108571428571426*_t145*_t6 + _t146*_t153 + 0.4213028571428572*_t15*_t87 + _t150*_t33 + _t152*_t53 + _t154*_t94 + _t157*_t81 + _t158*_t99 + _t63*_t92 + _t78*_t97 + _t79*_t86;
  const double _t160 = my_piecewise3(_t1, 0, -_t159*_t39 + (0.1e1 / 0.6e1)*_t18*_t19*_t20*_t28*_t38 - _t82*_t84);
  const double _t161 = (0.1e1 / 0.4e1)*_t70;
  const double _t162 = _t4*_t9;
  const double _t163 = _t162*sigma_ss;
  const double _t164 = -5.2662857142857149*_t163 + 0.46320000000000028*_t87*tau_s;
  const double _t165 = 5.1839999999999993*_t162;
  const double _t166 = _t10*_t108;
  const double _t167 = _t166*_t8;
  const double _t168 = _t165*sigma_ss + 0.13934591999999998*_t167;
  const double _t169 = (0.6e1 / 0.5e1)*_t93;
  const double _t170 = (0.6e1 / 0.5e1)*_t86;
  const double _t171 = 16.588799999999999*_t87;
  const double _t172 = -_t171*sigma_ss - 0.27869183999999997*_t91;
  const double _t173 = 0.2e1*_t92;
  const double _t174 = 15.552000000000001*_t162;
  const double _t175 = 0.41803775999999992*_t167 + _t174*sigma_ss;
  const double _t176 = (0.6e1 / 0.5e1)*_t101;
  const double _t177 = _t132*_t52;
  const double _t178 = 8.0352000000000015*_t43;
  const double _t179 = _t178*sigma_ss + 0.077137919999999985*_t49;
  const double _t180 = _t116*_t179;
  const double _t181 = 18.662399999999998*_t87;
  const double _t182 = -_t181*sigma_ss - 0.31352831999999992*_t91;
  const double _t183 = (0.4e1 / 0.5e1)*_t112;
  const double _t184 = _t101*_t99;
  const double _t185 = _t101*_t52;
  const double _t186 = 8.5536000000000012*_t43;
  const double _t187 = _t186*sigma_ss + 0.082114559999999989*_t49;
  const double _t188 = _t138*_t187;
  const double _t189 = _t128*_t172 + _t155*_t180 + _t16*_t164 + _t168*_t33 + _t169*_t99 + _t170*_t71 + _t173*_t97 + _t175*_t53 + _t176*_t177 + _t182*_t81 + _t183*_t184 + _t185*_t188;
  const double _t190 = my_piecewise3(_t1, 0, -_t102*_t41 - _t161*_t23 + (0.1e1 / 0.2e1)*_t18*_t19*_t20*_t28*_t54 - _t189*_t39);
#endif
#if _KMAX >= 4
  const double _t191 = _t104*_t64;
  const double _t192 = _t191*_t89;
  const double _t193 = _t117*_t118;
  const double _t194 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t195 = xc_powi(n_s, -12);
  const double _t196 = _t108*_t191;
  const double _t197 = 0.026542079999999992*_t11;
  const double _t198 = 0.025712639999999995*_t11;
  const double _t199 = _t116*_t198;
  const double _t200 = _t14*_t193;
  const double _t201 = _t11*_t35;
  const double _t202 = 0.010948607999999999*_t11*_t118*_t14;
  const double _t203 = -0.038154239999999992*_t31 - 3.9744000000000006*_t6;
  const double _t204 = pow(_t12, -0.61e2 / 0.15e2);
  const double _t205 = -0.039813119999999994*_t31 - 4.1472000000000007*_t6;
  const double _t206 = pow(_t12, -0.21e2 / 0.5e1);
  const double _t207 = _t66*_t80;
  const double _t208 = _t207*_t64;
  const double _t209 = 0.015440000000000009*_t72;
  const double _t210 = _t52*_t66;
  const double _t211 = _t193*_t73;
  const double _t212 = xc_powi(n_s, -10);
  const double _t213 = _t61*_t78;
  const double _t214 = _t134*_t50;
  const double _t215 = _t50*_t62;
  const double _t216 = _t112*_t48;
  const double _t217 = 0.011943935999999997*_t11;
  const double _t218 = _t193*_t45;
  const double _t219 = _t203*_t204;
  const double _t220 = _t115*_t219;
  const double _t221 = _t206*_t37;
  const double _t222 = _t205*_t221;
  const double _t223 = _t117*_t222;
  const double _t224 = _t152*_t34;
  const double _t225 = _t64*_t73;
  const double _t226 = _t101*_t80;
  const double _t227 = _t122*_t157;
  const double _t228 = _t66*_t99;
  const double _t229 = 0.4213028571428572*_t43;
  const double _t230 = _t61*_t92;
  const double _t231 = 0.2e1*_t151;
  const double _t232 = _t131*_t64;
  const double _t233 = _t116*_t155;
  const double _t234 = _t78*_t96;
  const double _t235 = _t152*_t183;
  const double _t236 = _t175*_t34;
  const double _t237 = _t122*_t182;
  const double _t238 = _t118*_t187;
  const double _t239 = _t185*_t238;
  const double _t240 = _t166*sigma_ss;
  const double _t241 = 0.31597714285714285*_t43;
  const double _t242 = (0.6e1 / 0.5e1)*_t99;
  const double _t243 = _t180*_t50;
  const double _t244 = _t155*_t179;
  const double _t245 = _t138*_t185;
  const double _t246 = _t185*_t187;
  const double _t247 = _t4*_t47*sigma_ss;
  const double _t248 = _t10*_t212*_t8;
  const double _t249 = (0.12e2 / 0.5e1)*_t86;
  const double _t250 = _t87*sigma_ss;
  const double _t251 = _t14*_t238;
#endif

  const double f = my_piecewise3(_t1, 0, _t24*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t1, 0, _t30*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = 0;
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t1, 0, _t40*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t1, 0, _t24 + _t56*n_s);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = 0;
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = 0;
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = my_piecewise3(_t1, 0, _t58*n_s);
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = 0;
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t1, 0, _t69*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t1, 0, _t30 + _t75*n_s);
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = 0;
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t1, 0, _t40 + _t83*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t1, 0, _t103*n_s + 0.2e1*_t56);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = 0;
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = 0;
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = 0;
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = 0;
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = my_piecewise3(_t1, 0, _t107*n_s);
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = 0;
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t1, 0, _t120*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = 0;
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = 0;
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = my_piecewise3(_t1, 0, _t125*n_s + _t58);
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = 0;
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t1, 0, _t142*n_s + _t69);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t1, 0, _t148*n_s + 0.2e1*_t75);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = 0;
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t1, 0, _t160*n_s + 0.2e1*_t83);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t1, 0, 0.3e1*_t103 + _t190*n_s);
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
  const double d4f_dlapl_s4 = 0;
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = 0;
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = 0;
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = 0;
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = 0;
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, -_t39*(0.00011525898240000004*_t192*_t35 + 3.8419660800000025e-5*_t192*_t66 - _t193*_t67*_t73)));
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = 0;
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, -_t39*(-0.0024883199999999992*_t11*_t135 - 0.0029859839999999997*_t11*_t200*_t66 + _t115*_t203*_t204*_t32*_t62 + 0.14043428571428571*_t117*_t118*_t35*_t4*_t5*_t66 + (0.2e1 / 0.5e1)*_t117*_t14*_t205*_t206*_t35*_t66 - _t134*_t197*_t32 + 4.4580502241279988e-5*_t14*_t194*_t195*_t64 + 3.302259425279998e-5*_t194*_t195*_t61 - 0.0020966726509714277*_t196*_t35 - 0.00069889088365714276*_t196*_t66 - _t199*_t32*_t62 - 0.011943935999999997*_t200*_t201 - _t202*_t67)));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = 0;
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = 0;
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = 0;
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = 0;
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = my_piecewise3(_t1, 0, _t107 + n_s*my_piecewise3(_t1, 0, -_t106*_t42 - _t39*(0.00011525898240000004*_t104*_t52*_t64*_t89 - 0.00015367864320000007*_t110 - _t208*_t209 - _t210*_t211 + 0.015440000000000009*_t35*_t4*_t5*_t64*_t66)));
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = 0;
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t1, 0, _t120 + n_s*my_piecewise3(_t1, 0, -_t119*_t42 - _t39*(-0.3159771428571429*_t105*_t43 + 0.0023587567323428565*_t109*_t212 - 0.0019906559999999999*_t11*_t154 - 0.039813119999999987*_t11*_t213 - 0.017915903999999996*_t113*_t80 - 0.0059719679999999985*_t132*_t201 + _t133*_t218 + 0.3e1*_t135*_t78 + 0.10532571428571427*_t193*_t210*_t6 - 0.001572504488228571*_t196*_t52 - _t197*_t214 - _t199*_t215 + (0.6e1 / 0.5e1)*_t200*_t207 - _t200*_t217*_t52 - _t202*_t210 + 0.21065142857142855*_t208*_t6 + _t210*_t223 + _t215*_t220 + 0.017915903999999996*_t216*_t66 + 0.014929919999999998*_t48*_t63)));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = 0;
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = 0;
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = my_piecewise3(_t1, 0, 0.2e1*_t125 + n_s*my_piecewise3(_t1, 0, -_t124*_t84 - _t144*_t57 - _t39*(-_t185*_t211 - _t224*_t73 - _t225*_t226 - _t225*_t228 - _t227*_t73 + 0.030880000000000019*_t34*_t4*_t5*_t80 - 0.046320000000000028*_t36*_t43 + 0.030880000000000019*_t4*_t5*_t52*_t64*_t66)));
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = 0;
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t1, 0, 0.2e1*_t142 + n_s*my_piecewise3(_t1, 0, -_t141*_t84 + (0.1e1 / 0.6e1)*_t18*_t19*_t20*_t28*_t68 - _t39*(_t101*_t112*_t129 + _t101*_t136*_t200 - _t111*_t230 - _t114*_t99 - _t121*_t229 - _t123*_t229 + _t126*_t97 + 0.079626239999999987*_t128*_t48 + _t130*_t150 + _t131*_t185*_t193 + _t131*_t224 + _t131*_t227 + _t133*_t64*_t86 + 0.2e1*_t134*_t234 + _t135*_t92 + _t137*_t157 + _t139*_t228 + (0.8e1 / 0.5e1)*_t154*_t80 + _t155*_t220 + _t157*_t200*_t94 - _t177*_t217 - _t185*_t202 + _t185*_t223 - _t198*_t233 + _t213*_t231 + _t214*_t231 + 0.035831807999999993*_t216*_t52 + _t218*_t66*_t94 + _t226*_t232 + _t228*_t232 + _t235*_t66 - 0.034836479999999996*_t33*_t90 - _t34*_t60*_t86 + 0.8426057142857144*_t36*_t87 + 0.011943935999999999*_t48*_t93 - 0.041803775999999994*_t59*_t90)));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t1, 0, 0.3e1*_t148 + n_s*my_piecewise3(_t1, 0, -_t147*_t41 + 0.0019300000000000012*_t15*_t19*_t20*_t25/xc_powr(n_s, 9, 2) + (0.1e1 / 0.2e1)*_t18*_t19*_t20*_t28*_t74 - _t39*(0.046320000000000028*_t101*_t4*_t5*_t52*_t64 + 0.18528000000000011*_t15*_t4*_t85 - _t184*_t209*_t64 - _t236*_t73 - _t237*_t73 - _t239*_t73 + 0.046320000000000028*_t34*_t4*_t5*_t99 - 0.13896000000000008*_t43*_t71)));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = 0;
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t1, 0, 0.3e1*_t160 + n_s*my_piecewise3(_t1, 0, -_t159*_t41 - _t161*_t22*_t38 + (0.1e1 / 0.2e1)*_t18*_t19*_t20*_t28*_t82 - _t39*(_t101*_t235 + _t121*_t170 + _t123*_t170 + _t128*(-0.55738367999999994*_t149 - _t171) + _t132*_t176*_t80 + _t134*_t173*_t96 + _t140*_t182 - _t145*_t241 - _t146*_t241 - 2.1065142857142862*_t15*_t162 + 0.2e1*_t150*_t97 + _t151*_t173*_t61 + _t151*_t243 + _t152*_t169 + _t153*_t236 + _t153*_t237 + _t153*_t239 + _t154*_t242 + _t156*_t182 + (0.6e1 / 0.5e1)*_t157*_t177 + _t157*_t183*_t99 + _t157*_t188*_t52 + _t158*_t175 + _t164*_t79 + _t168*_t63 + _t172*_t213 + _t172*_t214 + _t176*_t218*_t52 + _t180*_t234 + (0.4e1 / 0.5e1)*_t184*_t200 + _t184*_t232 + _t188*_t226 + _t219*_t244 + _t222*_t246 + _t233*(_t178 + 0.15427583999999997*_t77) + _t245*(_t186 + 0.16422911999999998*_t77) + _t33*(_t165 + 0.27869183999999997*_t240) + _t53*(_t174 + 0.83607551999999985*_t240) + 1.2639085714285714*_t71*_t87 + _t81*(-0.62705663999999983*_t149 - _t181))));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t1, 0, 0.4e1*_t190 + n_s*my_piecewise3(_t1, 0, _t102*_t18*_t19*_t20*_t28 + (0.5e1 / 0.8e1)*_t143*_t17*_t18*_t19*_t20 - 0.4e1 / 0.3e1*_t189*_t41 - _t39*(_t112*_t175*_t176 + _t112*_t182*_t242 + _t128*(82.943999999999988*_t163 + 2.2295347199999997*_t167) + (0.16e2 / 0.5e1)*_t132*_t184 + _t145*_t249 + _t146*_t249 + _t16*(-2.3160000000000016*_t162*tau_s + 31.597714285714289*_t4*_t47*sigma_ss) + (0.8e1 / 0.5e1)*_t164*_t71 + 0.3e1*_t168*_t97 + 0.3e1*_t172*_t230 + 0.2e1*_t172*_t243 + (0.8e1 / 0.5e1)*_t175*_t93 + (0.8e1 / 0.5e1)*_t177*_t182 + 0.3e1*_t180*_t92*_t96 + _t182*_t251*_t94 + (0.6e1 / 0.5e1)*_t184*_t251 + _t204*_t244*(11.923200000000001*_t44 + 0.11446271999999998*_t49) + _t221*_t246*(12.441600000000001*_t44 + 0.11943935999999998*_t49) + _t233*(-32.140800000000006*_t250 - 0.53996543999999991*_t91) + (0.8e1 / 0.5e1)*_t239*_t45 + _t245*(-34.214400000000005*_t250 - 0.57480191999999997*_t91) + _t33*(-31.103999999999996*_t247 - 1.2541132799999999*_t248) + _t53*(-93.312000000000012*_t247 - 3.7623398399999992*_t248) + _t81*(93.311999999999983*_t163 + 2.5082265599999993*_t167)) - _t55*_t70));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double ta = tau[0];

  const double _t1 = (0.1e1 / 0.2e1)*na;
  const double _t2 = (0.1e1 / 0.4e1)*gaa;
  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, _t2, 0, (0.1e1 / 0.2e1)*ta, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, _t2, 0, 0, _hc1);
  const double dF_dna = _hc0[4];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc0[3];
  const double dF_dta = _hc1[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc0[14];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[13];
  const double d2F_dna_dta = (0.1e1 / 0.2e1)*_hc1[11];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc0[10];
  const double d2F_dgaa_dta = (0.1e1 / 0.4e1)*_hc1[8];
  const double d2F_dta2 = 0;
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
  const double d3F_dna2_dta = (0.1e1 / 0.4e1)*_hc1[31];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[30];
  const double d3F_dna_dgaa_dta = (0.1e1 / 0.8e1)*_hc1[28];
  const double d3F_dna_dta2 = 0;
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc0[24];
  const double d3F_dgaa2_dta = (0.1e1 / 0.16e2)*_hc1[22];
  const double d3F_dgaa_dta2 = 0;
  const double d3F_dta3 = 0;
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
  const double d4F_dna3_dta = (0.1e1 / 0.8e1)*_hc1[66];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc0[65];
  const double d4F_dna2_dgaa_dta = (0.1e1 / 0.16e2)*_hc1[63];
  const double d4F_dna2_dta2 = 0;
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[59];
  const double d4F_dna_dgaa2_dta = (0.1e1 / 0.32e2)*_hc1[57];
  const double d4F_dna_dgaa_dta2 = 0;
  const double d4F_dna_dta3 = 0;
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc0[49];
  const double d4F_dgaa3_dta = (0.1e1 / 0.64e2)*_hc1[47];
  const double d4F_dgaa2_dta2 = 0;
  const double d4F_dgaa_dta3 = 0;
  const double d4F_dta4 = 0;
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
  double _hc2[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, 0, 0, _hc2);
  double _hc3[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, 0, 0, _hc3);
  const double dF_dna = _hc0[4];
  const double dF_dnb = _hc1[4];
  const double dF_dgaa = _hc0[3];
  const double dF_dgbb = _hc1[3];
  const double dF_dta = _hc2[1];
  const double dF_dtb = _hc3[1];
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
  const double d2F_dna_dta = _hc2[11];
  const double d2F_dnb_dtb = _hc3[11];
  const double d2F_dgaa2 = _hc0[10];
  const double d2F_dgbb2 = _hc1[10];
  const double d2F_dgaa_dta = _hc2[8];
  const double d2F_dgbb_dtb = _hc3[8];
  const double d2F_dta2 = 0;
  const double d2F_dtb2 = 0;
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
  const double d3F_dna2_dta = _hc2[31];
  const double d3F_dnb2_dtb = _hc3[31];
  const double d3F_dna_dgaa2 = _hc0[30];
  const double d3F_dnb_dgbb2 = _hc1[30];
  const double d3F_dna_dgaa_dta = _hc2[28];
  const double d3F_dnb_dgbb_dtb = _hc3[28];
  const double d3F_dna_dta2 = 0;
  const double d3F_dnb_dtb2 = 0;
  const double d3F_dgaa3 = _hc0[24];
  const double d3F_dgbb3 = _hc1[24];
  const double d3F_dgaa2_dta = _hc2[22];
  const double d3F_dgbb2_dtb = _hc3[22];
  const double d3F_dgaa_dta2 = 0;
  const double d3F_dgbb_dtb2 = 0;
  const double d3F_dta3 = 0;
  const double d3F_dtb3 = 0;
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
  const double d4F_dna3_dta = _hc2[66];
  const double d4F_dnb3_dtb = _hc3[66];
  const double d4F_dna2_dgaa2 = _hc0[65];
  const double d4F_dnb2_dgbb2 = _hc1[65];
  const double d4F_dna2_dgaa_dta = _hc2[63];
  const double d4F_dnb2_dgbb_dtb = _hc3[63];
  const double d4F_dna2_dta2 = 0;
  const double d4F_dnb2_dtb2 = 0;
  const double d4F_dna_dgaa3 = _hc0[59];
  const double d4F_dnb_dgbb3 = _hc1[59];
  const double d4F_dna_dgaa2_dta = _hc2[57];
  const double d4F_dnb_dgbb2_dtb = _hc3[57];
  const double d4F_dna_dgaa_dta2 = 0;
  const double d4F_dnb_dgbb_dtb2 = 0;
  const double d4F_dna_dta3 = 0;
  const double d4F_dnb_dtb3 = 0;
  const double d4F_dgaa4 = _hc0[49];
  const double d4F_dgbb4 = _hc1[49];
  const double d4F_dgaa3_dta = _hc2[47];
  const double d4F_dgbb3_dtb = _hc3[47];
  const double d4F_dgaa2_dta2 = 0;
  const double d4F_dgbb2_dtb2 = 0;
  const double d4F_dgaa_dta3 = 0;
  const double d4F_dgbb_dtb3 = 0;
  const double d4F_dta4 = 0;
  const double d4F_dtb4 = 0;
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