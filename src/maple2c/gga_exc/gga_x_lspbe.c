/*
  Generated from python/gga_exc/gga_x_lspbe.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_lspbe
*/

#ifndef _GGA_X_LSPBE_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_LSPBE_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_LSPBE_HELPER_BODIES
#include "gga_x_lspbe.c"
#undef _GGA_X_LSPBE_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_LSPBE_HELPER_BODIES
#include "gga_x_lspbe.c"
#undef _GGA_X_LSPBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_LSPBE_HELPER_BODIES
#include "gga_x_lspbe.c"
#undef _GGA_X_LSPBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_LSPBE_HELPER_BODIES
#include "gga_x_lspbe.c"
#undef _GGA_X_LSPBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_LSPBE_HELPER_BODIES
#include "gga_x_lspbe.c"
#undef _GGA_X_LSPBE_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_lspbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_lspbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_lspbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_lspbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_lspbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_lspbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_lspbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_lspbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_lspbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_lspbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_LSPBE_HELPER_BODIES)

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
  const gga_x_lspbe_params *params = (const gga_x_lspbe_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = -p->dens_threshold + n_s <= 0;
  const double _t6 = params->kappa + 0.1e1;
  const double _t7 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t8 = _t1*_t7;
  const double _t9 = _t8*params->alpha;
  const double _t10 = xc_powr(n_s, -8, 3);
  const double _t11 = (0.1e1 / 0.24e2)*_t10*sigma_ss;
  const double _t12 = xc_expm1(-_t11*_t9);
  const double _t13 = _t8*params->mu;
  const double _t14 = _t11*_t13;
  const double _t15 = _t14 + params->kappa;
  const double _t16 = (0.1e1 / _t15);
  const double _t17 = _t16*params->kappa;
  const double _t18 = _t12*_t6 + _t14*_t17 + 0.1e1;
#if _KMAX >= 1
  const double _t20 = _t12 + 0.1e1;
  const double _t21 = _t20*_t6;
  const double _t22 = _t21*_t9;
  const double _t23 = xc_powr(n_s, -16, 3);
  const double _t24 = xc_powr(0.6e1, 2, 3);
  const double _t25 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t26 = _t24*_t25;
  const double _t27 = _t23*_t26;
  const double _t28 = (0.1e1 / (_t15 * _t15));
  const double _t29 = ((params->mu) * (params->mu));
  const double _t30 = _t28*_t29*params->kappa;
  const double _t31 = _t27*_t30;
  const double _t32 = (0.1e1 / 0.24e2)*_t1*_t10*_t16*_t7*params->kappa*params->mu - 0.1e1 / 0.24e2*_t10*_t22 - 0.1e1 / 0.576e3*_t31*sigma_ss;
  const double _t34 = xc_powr(n_s, -4, 3);
  const double _t38 = _t13*_t17;
  const double _t39 = xc_powr(n_s, -11, 3);
  const double _t40 = (0.1e1 / 0.9e1)*_t39;
  const double _t41 = _t38*_t40;
  const double _t42 = (sigma_ss * sigma_ss);
  const double _t43 = xc_powr(n_s, -19, 3);
  const double _t44 = _t26*_t43;
  const double _t45 = _t30*_t44;
  const double _t46 = _t22*_t40*sigma_ss - _t41*sigma_ss + (0.1e1 / 0.216e3)*_t42*_t45;
#endif
#if _KMAX >= 2
  const double _t48 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t49 = xc_powi(n_s, -8);
  const double _t50 = _t48*_t49;
  const double _t51 = (0.1e1 / (_t15 * _t15 * _t15));
  const double _t52 = ((params->mu) * (params->mu) * (params->mu));
  const double _t53 = _t51*_t52*params->kappa;
  const double _t54 = ((params->alpha) * (params->alpha));
  const double _t55 = _t21*_t54;
  const double _t56 = (0.1e1 / 0.576e3)*_t27*_t55 - 0.1e1 / 0.288e3*_t31 + (0.1e1 / 0.1152e4)*_t50*_t53*sigma_ss;
  const double _t58 = xc_powi(n_s, -9);
  const double _t59 = _t48*_t58;
  const double _t60 = _t53*_t59;
  const double _t61 = _t44*_t55;
  const double _t62 = (0.1e1 / 0.9e1)*_t1*_t20*_t39*_t6*_t7*params->alpha + (0.1e1 / 0.72e2)*_t24*_t25*_t28*_t29*_t43*params->kappa*sigma_ss - _t41 - 0.1e1 / 0.432e3*_t42*_t60 - 0.1e1 / 0.216e3*_t61*sigma_ss;
  const double _t64 = (0.2e1 / 0.9e1)*_t18;
  const double _t65 = xc_powr(n_s, -7, 3);
  const double _t67 = (0.1e1 / 0.36e2)*_t18;
  const double _t68 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t72 = xc_powr(n_s, -14, 3);
  const double _t73 = (0.11e2 / 0.27e2)*_t72;
  const double _t74 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t75 = xc_powi(n_s, -10);
  const double _t76 = _t48*_t75;
  const double _t77 = _t53*_t76;
  const double _t78 = _t22*_t73;
  const double _t79 = xc_powr(n_s, -22, 3);
  const double _t80 = _t26*_t79;
  const double _t81 = _t30*_t80;
  const double _t82 = _t55*_t80;
  const double _t83 = _t38*_t73*sigma_ss - 0.1e1 / 0.24e2*_t42*_t81 + (0.1e1 / 0.81e2)*_t42*_t82 + (0.1e1 / 0.162e3)*_t74*_t77 - _t78*sigma_ss;
#endif
#if _KMAX >= 3
  const double _t85 = ((params->alpha) * (params->alpha) * (params->alpha));
  const double _t86 = _t21*_t85;
  const double _t87 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t88 = _t1*_t87;
  const double _t89 = _t88/xc_powr(n_s, 32, 3);
  const double _t90 = (0.1e1 / (_t15 * _t15 * _t15 * _t15));
  const double _t91 = ((params->mu) * (params->mu) * (params->mu) * (params->mu));
  const double _t92 = _t90*_t91*params->kappa;
  const double _t93 = _t89*_t92;
  const double _t94 = (0.1e1 / 0.384e3)*_t48*_t49*_t51*_t52*params->kappa - 0.1e1 / 0.2304e4*_t50*_t86 - 0.1e1 / 0.9216e4*_t93*sigma_ss;
  const double _t96 = xc_powr(n_s, -35, 3);
  const double _t97 = _t88*_t92;
  const double _t98 = (0.1e1 / 0.3456e4)*_t42*_t96*_t97 + (0.1e1 / 0.54e2)*_t45 + (0.1e1 / 0.864e3)*_t59*_t86*sigma_ss - 0.5e1 / 0.432e3*_t60*sigma_ss - 0.1e1 / 0.108e3*_t61;
  const double _t101 = (0.1e1 / 0.36e2)*_t32;
  const double _t102 = _t76*_t86;
  const double _t103 = xc_powr(n_s, -38, 3);
  const double _t104 = _t103*_t97;
  const double _t105 = (0.11e2 / 0.27e2)*_t1*_t16*_t7*_t72*params->kappa*params->mu - 0.1e1 / 0.324e3*_t102*_t42 - 0.1e1 / 0.1296e4*_t104*_t74 + (0.1e1 / 0.24e2)*_t20*_t24*_t25*_t54*_t6*_t79*sigma_ss + (0.17e2 / 0.432e3)*_t42*_t48*_t51*_t52*_t75*params->kappa - _t78 - 0.65e2 / 0.648e3*_t81*sigma_ss;
  const double _t107 = (0.1e1 / M_PI);
  const double _t114 = xc_powr(n_s, -17, 3);
  const double _t115 = (0.154e3 / 0.81e2)*_t114;
  const double _t116 = _t115*_t38;
  const double _t117 = xc_powi(n_s, -11);
  const double _t118 = _t117*_t48;
  const double _t119 = _t118*_t74;
  const double _t120 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t121 = xc_powr(n_s, -41, 3);
  const double _t122 = xc_powr(n_s, -25, 3);
  const double _t123 = _t122*_t26;
  const double _t124 = _t123*_t42;
  const double _t125 = _t115*_t22*sigma_ss - _t116*sigma_ss - 0.19e2 / 0.162e3*_t119*_t53 + (0.2e1 / 0.243e3)*_t119*_t86 + (0.1e1 / 0.486e3)*_t120*_t121*_t97 + (0.341e3 / 0.972e3)*_t124*_t30 - 0.11e2 / 0.81e2*_t124*_t55;
#endif
#if _KMAX >= 4
  const double _t127 = _t21*((params->alpha) * (params->alpha) * (params->alpha) * (params->alpha));
  const double _t128 = _t24*params->kappa*xc_powi((params->mu), 5)/((M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI)*xc_powi(_t15, 5));
  const double _t129 = _t127*_t88;
  const double _t130 = (0.2618e4 / 0.243e3)*sigma_ss/xc_powr(n_s, 20, 3);
  const double _t131 = _t48*_t74/xc_powi(n_s, 12);
  const double _t132 = _t120/xc_powr(n_s, 44, 3);
  const double _t133 = _t26*_t42/xc_powr(n_s, 28, 3);
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t5)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  const double _t19 = my_piecewise3(_t5, 0, _hc0[0]*_t18);
#if _KMAX >= 1
  const double _t33 = my_piecewise3(_t5, 0, _hc0[0]*_t32);
  const double _t35 = _hc0[2]*_t3;
  const double _t36 = _t34*_t35;
  const double _t37 = (0.1e1 / 0.6e1)*_t36;
  const double _t47 = my_piecewise3(_t5, 0, _hc0[0]*_t46 - _t18*_t37);
#endif
#if _KMAX >= 2
  const double _t57 = my_piecewise3(_t5, 0, _hc0[0]*_t56);
  const double _t63 = my_piecewise3(_t5, 0, _hc0[0]*_t62 - _t32*_t37);
  const double _t66 = _t35*_t65;
  const double _t69 = _hc0[5]*_t24*_t68;
  const double _t70 = _t10*_t69;
  const double _t71 = (0.1e1 / 0.3e1)*_t36;
  const double _t84 = my_piecewise3(_t5, 0, _hc0[0]*_t83 - _t46*_t71 + _t64*_t66 + _t67*_t70);
#endif
#if _KMAX >= 3
  const double _t95 = my_piecewise3(_t5, 0, _hc0[0]*_t94);
  const double _t99 = my_piecewise3(_t5, 0, _hc0[0]*_t98 - _t37*_t56);
  const double _t100 = (0.2e1 / 0.9e1)*_t66;
  const double _t106 = my_piecewise3(_t5, 0, _hc0[0]*_t105 + _t100*_t32 + _t101*_t70 - _t62*_t71);
  const double _t108 = _hc0[9]*_t107/(n_s * n_s * n_s * n_s);
  const double _t109 = _t35/xc_powr(n_s, 10, 3);
  const double _t110 = (0.14e2 / 0.27e2)*_t109;
  const double _t111 = _t39*_t69;
  const double _t112 = (0.1e1 / 0.9e1)*_t111;
  const double _t113 = _hc0[2]*_t34*_t4;
  const double _t126 = my_piecewise3(_t5, 0, _hc0[0]*_t125 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t46*_t65 + (0.1e1 / 0.12e2)*_hc0[5]*_t10*_t24*_t46*_t68 - _t108*_t67 - _t110*_t18 - _t112*_t18 - _t113*_t83);
#endif

  const double f = my_piecewise3(_t5, 0, _t19*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t5, 0, _t33*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t5, 0, _t19 + _t47*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t5, 0, _t57*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t5, 0, _t33 + _t63*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t5, 0, 0.2e1*_t47 + _t84*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t5, 0, _t95*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t5, 0, _t57 + _t99*n_s);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t5, 0, _t106*n_s + 0.2e1*_t63);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t5, 0, _t126*n_s + 0.3e1*_t84);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*((0.1e1 / 0.55296e5)*_t127*_t89 + (0.1e1 / 0.55296e5)*_t128*sigma_ss/xc_powr(n_s, 40, 3) - 0.1e1 / 0.2304e4*_t93)));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t5, 0, _t95 + n_s*my_piecewise3(_t5, 0, _hc0[0]*((0.7e1 / 0.3456e4)*_t1*_t87*_t90*_t91*_t96*params->kappa*sigma_ss - 0.1e1 / 0.20736e5*_t128*_t42/xc_powr(n_s, 43, 3) - 0.1e1 / 0.20736e5*_t129*_t96*sigma_ss + (0.1e1 / 0.288e3)*_t20*_t48*_t58*_t6*_t85 - 0.1e1 / 0.48e2*_t60) - _t37*_t94));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t5, 0, 0.2e1*_t99 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-0.43e2 / 0.2592e4*_t102*sigma_ss + (0.1e1 / 0.7776e4)*_t103*_t129*_t42 - 0.25e2 / 0.3456e4*_t104*_t42 + (0.1e1 / 0.7776e4)*_t128*_t74/xc_powr(n_s, 46, 3) + (0.167e3 / 0.1296e4)*_t77*sigma_ss - 0.19e2 / 0.162e3*_t81 + (0.19e2 / 0.324e3)*_t82) + _t100*_t56 + (0.1e1 / 0.36e2)*_t56*_t70 - _t71*_t98));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t5, 0, 0.3e1*_t106 + n_s*my_piecewise3(_t5, 0, _hc0[0]*((0.154e3 / 0.81e2)*_t1*_t114*_t20*_t6*_t7*params->alpha + (0.89e2 / 0.3888e4)*_t1*_t121*_t74*_t87*_t90*_t91*params->kappa - _t116 + (0.19e2 / 0.324e3)*_t117*_t20*_t42*_t48*_t6*_t85 - 0.1025e4 / 0.1944e4*_t118*_t42*_t53 - 0.1e1 / 0.2916e4*_t120*_t128/xc_powr(n_s, 49, 3) - 0.1e1 / 0.2916e4*_t121*_t129*_t74 + (0.253e3 / 0.324e3)*_t122*_t24*_t25*_t28*_t29*params->kappa*sigma_ss - 0.341e3 / 0.972e3*_t123*_t55*sigma_ss) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t62*_t65 + (0.1e1 / 0.12e2)*_hc0[5]*_t10*_t24*_t62*_t68 - _t101*_t108 - _t105*_t113 - _t110*_t32 - _t112*_t32));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t5, 0, 0.4e1*_t126 + n_s*my_piecewise3(_t5, 0, _hc0[0]*((0.2e1 / 0.2187e4)*_t128*xc_powi(sigma_ss, 5)/xc_powr(n_s, 52, 3) + (0.2e1 / 0.2187e4)*_t129*_t132 - _t130*_t22 + _t130*_t38 + (0.2563e4 / 0.1458e4)*_t131*_t53 - 0.44e2 / 0.243e3*_t131*_t86 - 0.49e2 / 0.729e3*_t132*_t97 - 0.3047e4 / 0.972e3*_t133*_t30 + (0.979e3 / 0.729e3)*_t133*_t55) + (0.1e1 / 0.216e3)*_hc0[14]*_t18*_t23*_t8 + _hc0[9]*_t107*_t64/xc_powi(n_s, 5) - 0.1e1 / 0.9e1*_t108*_t46 - 0.56e2 / 0.27e2*_t109*_t46 - 0.4e1 / 0.9e1*_t111*_t46 - 0.2e1 / 0.3e1*_t125*_t36 + (0.140e3 / 0.81e2)*_t18*_t35/xc_powr(n_s, 13, 3) + (0.40e2 / 0.81e2)*_t18*_t69*_t72 + (0.4e1 / 0.3e1)*_t66*_t83 + (0.1e1 / 0.6e1)*_t70*_t83));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_x_lspbe_params *params = (const gga_x_lspbe_params *)(p->params);
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