/*
  Generated from python/gga_exc/gga_x_q2d.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_q2d
*/

#ifndef _GGA_X_Q2D_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_Q2D_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_Q2D_HELPER_BODIES
#include "gga_x_q2d.c"
#undef _GGA_X_Q2D_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_Q2D_HELPER_BODIES
#include "gga_x_q2d.c"
#undef _GGA_X_Q2D_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_Q2D_HELPER_BODIES
#include "gga_x_q2d.c"
#undef _GGA_X_Q2D_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_Q2D_HELPER_BODIES
#include "gga_x_q2d.c"
#undef _GGA_X_Q2D_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_Q2D_HELPER_BODIES
#include "gga_x_q2d.c"
#undef _GGA_X_Q2D_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_q2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_q2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_q2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_q2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_q2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_q2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_q2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_q2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_q2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_q2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_Q2D_HELPER_BODIES)

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
  const double _t2 = _t1/M_CBRTPI;
  const double _t3 = (0.1e1 / 0.2e1)*_t2;
  const double _t4 = -p->dens_threshold + n_s <= 0;
  const double _t5 = pow(sigma_ss, 1.75);
  const double _t6 = pow(n_s, -4.6666666666666661);
  const double _t7 = pow(M_PI, -2.333333333333333);
  const double _t8 = xc_powr(n_s, -8, 3);
  const double _t9 = _t1/(M_PI * M_CBRTPI);
  const double _t10 = _t8*_t9;
  const double _t11 = _t10*sigma_ss;
  const double _t12 = (0.1e1 / 0.24e2)*_t11 + 0.1e1;
  const double _t13 = _t12*_t7;
  const double _t14 = _t13*_t6;
  const double _t15 = (sigma_ss * sigma_ss);
  const double _t16 = xc_powr(n_s, -16, 3);
  const double _t17 = xc_powr(0.6e1, 2, 3);
  const double _t18 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t19 = _t17*_t18;
  const double _t20 = _t16*_t19;
  const double _t21 = -0.1e1 / 0.576e3*_t15*_t20 + 0.100e3;
  const double _t22 = (0.5e1 / 0.972e3)*_t11 + 0.80400000000000005;
  const double _t23 = (0.1e1 / _t22);
  const double _t24 = 0.0041358024691358023*_t23;
  const double _t25 = _t11*_t24 + 0.1e1;
  const double _t26 = 0.0057012846727820168*_t14*_t5 + _t21*_t25;
  const double _t27 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t28 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t29 = _t28/xc_powi(n_s, 8);
  const double _t30 = (0.1e1 / 0.2304e4)*_t27*_t29 + 0.100e3;
  const double _t31 = (0.1e1 / _t30);
#if _KMAX >= 1
  const double _t35 = (0.1e1 / (_t30 * _t30));
  const double _t36 = _t29*_t35;
  const double _t37 = _t15*_t36;
  const double _t38 = (0.1e1 / 0.768e3)*_t37;
  const double _t39 = pow(n_s, -7.3333333333333321);
  const double _t40 = pow(M_PI, -3.6666666666666661);
  const double _t41 = _t1*_t40;
  const double _t42 = _t39*_t41;
  const double _t43 = pow(sigma_ss, 0.75);
  const double _t44 = (0.1e1 / 0.288e3)*_t20;
  const double _t45 = _t25*_t44;
  const double _t46 = (0.1e1 / (_t22 * _t22));
  const double _t47 = _t20*_t46;
  const double _t48 = _t10*_t24 - 2.1274704059340546e-5*_t47*sigma_ss;
  const double _t49 = 0.0099772481773685289*_t14*_t43 + _t21*_t48 + 0.00023755352803258401*_t42*_t5 - _t45*sigma_ss;
  const double _t51 = _t26*_t31;
  const double _t52 = xc_powr(n_s, -4, 3);
  const double _t56 = xc_powi(n_s, -9);
  const double _t57 = _t28*_t35;
  const double _t58 = _t56*_t57;
  const double _t60 = (0.1e1 / 0.288e3)*_t27;
  const double _t61 = pow(sigma_ss, 2.75);
  const double _t62 = _t41*pow(n_s, -8.3333333333333321);
  const double _t63 = _t13*pow(n_s, -5.6666666666666661);
  const double _t64 = xc_powr(n_s, -19, 3);
  const double _t65 = xc_powr(n_s, -11, 3);
  const double _t66 = _t23*_t9;
  const double _t67 = 0.011028806584362139*_t65*_t66;
  const double _t68 = 5.6732544158241455e-5*_t15*_t17*_t18*_t46*_t64 - _t67*sigma_ss;
  const double _t69 = (0.1e1 / 0.108e3)*_t15*_t17*_t18*_t25*_t64 + _t21*_t68 - 0.026605995139649407*_t5*_t63 - 0.00063347607475355741*_t61*_t62;
#endif
#if _KMAX >= 2
  const double _t71 = (0.1e1 / 0.384e3)*_t36;
  const double _t73 = xc_powi(n_s, -16);
  const double _t74 = xc_powi(M_PI, -8);
  const double _t75 = (0.1e1 / (_t30 * _t30 * _t30));
  const double _t76 = _t74*_t75;
  const double _t79 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t80 = (0.1e1 / 0.294912e6)*_t79;
  const double _t82 = _t15*_t71;
  const double _t83 = pow(sigma_ss, -0.25);
  const double _t84 = _t20*sigma_ss;
  const double _t85 = (0.1e1 / 0.144e3)*_t84;
  const double _t86 = (0.1e1 / (_t22 * _t22 * _t22));
  const double _t87 = _t29*_t86;
  const double _t88 = -4.2549408118681091e-5*_t47 + 1.31325333699633e-6*_t87*sigma_ss;
  const double _t89 = 0.0074829361330263962*_t14*_t83 + _t21*_t88 + 0.00083143734811404408*_t42*_t43 - _t45 - _t48*_t85;
  const double _t91 = xc_powi(n_s, -17);
  const double _t93 = xc_powi(sigma_ss, 5);
  const double _t94 = (0.1e1 / 0.110592e6)*_t93;
  const double _t95 = xc_powr(n_s, -28, 3);
  const double _t96 = _t15*_t95;
  const double _t97 = _t26*_t35;
  const double _t104 = _t44*_t68;
  const double _t105 = _t28*_t86;
  const double _t106 = _t105*_t56;
  const double _t107 = -3.50200889865688e-6*_t106*_t15 + 0.00017019763247472436*_t17*_t18*_t46*_t64*sigma_ss - _t67;
  const double _t108 = -_t104*sigma_ss + _t107*_t21 + (0.1e1 / 0.108e3)*_t15*_t17*_t18*_t48*_t64 + (0.1e1 / 0.54e2)*_t17*_t18*_t25*_t64*sigma_ss - 0.046560491494386465*_t43*_t63 - 0.0028506423363910084*_t5*_t62;
  const double _t110 = (0.2e1 / 0.9e1)*_t51;
  const double _t112 = (0.1e1 / 0.36e2)*_t51;
  const double _t116 = xc_powi(n_s, -18);
  const double _t118 = xc_powi(sigma_ss, 6);
  const double _t119 = (0.1e1 / 0.41472e5)*_t118;
  const double _t120 = xc_powi(n_s, -10);
  const double _t121 = _t120*_t57;
  const double _t123 = (0.1e1 / 0.32e2)*_t27;
  const double _t124 = xc_powr(n_s, -31, 3);
  const double _t126 = (0.1e1 / 0.864e3)*_t27;
  const double _t127 = _t31*_t69;
  const double _t130 = (0.1e1 / 0.144e3)*_t27;
  const double _t131 = _t41*pow(n_s, -9.3333333333333321);
  const double _t132 = _t13*pow(n_s, -6.6666666666666661);
  const double _t133 = _t19/xc_powr(n_s, 22, 3);
  const double _t134 = _t133*_t25;
  const double _t135 = (0.19e2 / 0.324e3)*_t15;
  const double _t136 = _t19*_t64;
  const double _t137 = _t136*_t68;
  const double _t138 = (0.1e1 / 0.54e2)*_t15;
  const double _t139 = _t105*_t120;
  const double _t140 = xc_powr(n_s, -14, 3);
  const double _t141 = 0.040438957475994505*_t140*_t66;
  const double _t142 = _t133*_t46;
  const double _t143 = 9.3386903964183465e-6*_t139*_t27 + _t141*sigma_ss - 0.00051059289742417309*_t142*_t15;
  const double _t144 = 0.0082351889717962451*_t131*_t61 + 0.15076730579134662*_t132*_t5 - _t134*_t135 + _t137*_t138 + _t143*_t21;
#endif
#if _KMAX >= 3
  const double _t146 = xc_powi(n_s, -24);
  const double _t147 = (0.1e1 / (_t30 * _t30 * _t30 * _t30));
  const double _t148 = _t147/xc_powi(M_PI, 12);
  const double _t151 = (0.1e1 / 0.75497472e8)*_t118;
  const double _t153 = (0.1e1 / 0.128e3)*sigma_ss;
  const double _t155 = (0.1e1 / 0.256e3)*_t37;
  const double _t156 = pow(sigma_ss, -1.25);
  const double _t157 = (0.1e1 / 0.96e2)*_t20;
  const double _t158 = _t157*sigma_ss;
  const double _t159 = xc_powr(n_s, -32, 3);
  const double _t160 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t161 = (0.1e1 / (_t22 * _t22 * _t22 * _t22));
  const double _t162 = _t1*_t160*_t161;
  const double _t163 = _t159*_t162;
  const double _t164 = -2.0266255200560646e-8*_t163*sigma_ss + 3.9397600109889901e-6*_t87;
  const double _t165 = 0.00093536701662829953*_t1*_t39*_t40*_t83 - 0.0018707340332565991*_t14*_t156 - _t157*_t48 - _t158*_t88 + _t164*_t21;
  const double _t168 = xc_powi(n_s, -25);
  const double _t169 = xc_powi(sigma_ss, 7);
  const double _t170 = _t168*_t169;
  const double _t172 = xc_powr(n_s, -52, 3);
  const double _t174 = _t75/(M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI);
  const double _t179 = (0.1e1 / 0.55296e5)*_t93;
  const double _t180 = (0.1e1 / 0.48e2)*_t15;
  const double _t184 = (0.1e1 / 0.2304e4)*_t96;
  const double _t189 = xc_powr(n_s, -35, 3);
  const double _t190 = -1.7510044493284399e-5*_t106*sigma_ss + 0.00022693017663296582*_t136*_t46 + 5.4043347201495061e-8*_t15*_t162*_t189;
  const double _t191 = -_t104 - _t107*_t85 + (0.1e1 / 0.108e3)*_t15*_t17*_t18*_t64*_t88 + (0.1e1 / 0.54e2)*_t17*_t18*_t25*_t64 + (0.1e1 / 0.27e2)*_t17*_t18*_t48*_t64*sigma_ss + _t190*_t21 - 0.0069286445676170335*_t43*_t62 - 0.03492036862078985*_t63*_t83;
  const double _t193 = xc_powi(sigma_ss, 8);
  const double _t194 = xc_powi(n_s, -26);
  const double _t196 = xc_powr(n_s, -55, 3);
  const double _t197 = _t196*_t93;
  const double _t198 = _t15*_t97;
  const double _t199 = (0.1e1 / 0.27648e5)*_t198;
  const double _t200 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t203 = _t31*_t49;
  const double _t205 = (0.1e1 / 0.36e2)*_t49;
  const double _t207 = _t116*_t119;
  const double _t215 = (0.19e2 / 0.162e3)*_t134;
  const double _t216 = _t133*_t48;
  const double _t217 = (0.1e1 / 0.27e2)*_t137;
  const double _t218 = _t136*_t138;
  const double _t219 = _t143*_t44;
  const double _t220 = xc_powr(n_s, -38, 3);
  const double _t221 = _t162*_t220;
  const double _t222 = 5.9534151277166957e-5*_t139*_t15 + _t141 - 0.0012292051234285648*_t142*sigma_ss - 1.4411559253732016e-7*_t221*_t27;
  const double _t223 = _t107*_t218 + 0.028928740747079115*_t131*_t5 + 0.26384278513485659*_t132*_t43 - _t135*_t216 + _t21*_t222 - _t215*sigma_ss + _t217*sigma_ss - _t219*sigma_ss;
  const double _t225 = (0.1e1 / M_PI);
  const double _t231 = xc_powi(n_s, -27);
  const double _t233 = xc_powi(sigma_ss, 9);
  const double _t234 = (0.1e1 / 0.3981312e7)*_t233;
  const double _t235 = xc_powi(n_s, -19);
  const double _t237 = (0.1e1 / 0.1536e4)*_t118;
  const double _t238 = xc_powi(n_s, -11);
  const double _t241 = (0.5e1 / 0.16e2)*_t27;
  const double _t242 = xc_powr(n_s, -58, 3);
  const double _t244 = (0.1e1 / 0.82944e5)*_t118;
  const double _t245 = xc_powr(n_s, -34, 3);
  const double _t247 = (0.31e2 / 0.1728e4)*_t27;
  const double _t248 = _t27*_t97;
  const double _t253 = (0.1e1 / 0.13824e5)*_t118;
  const double _t255 = (0.3e1 / 0.32e2)*_t27;
  const double _t257 = _t144*_t31;
  const double _t260 = (0.1e1 / 0.96e2)*_t27;
  const double _t261 = _t41*pow(n_s, -10.333333333333332);
  const double _t262 = _t13*pow(n_s, -7.6666666666666661);
  const double _t263 = xc_powr(n_s, -25, 3);
  const double _t264 = _t133*_t68;
  const double _t265 = (0.19e2 / 0.108e3)*_t15;
  const double _t266 = _t105*_t238;
  const double _t267 = 0.18871513488797437*_t66/xc_powr(n_s, 17, 3);
  const double _t268 = xc_powr(n_s, -41, 3);
  const double _t269 = 3.8430824676618711e-7*_t1*_t160*_t161*_t268*_t79 + 0.0042990661239911852*_t15*_t17*_t18*_t263*_t46 - 0.00017743511753194859*_t266*_t27 - _t267*sigma_ss;
  const double _t270 = (0.1e1 / 0.36e2)*_t143*_t15*_t17*_t18*_t64 + (0.209e3 / 0.486e3)*_t15*_t17*_t18*_t25*_t263 + _t21*_t269 - 0.093613686602470117*_t261*_t61 - 1.0051153719423107*_t262*_t5 - _t264*_t265;
#endif
#if _KMAX >= 4
  const double _t273 = _t146*_t148;
  const double _t275 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t276 = xc_powi(_t22, -5);
  const double _t280 = _t95*sigma_ss;
  const double _t283 = _t172*_t79;
  const double _t284 = _t91*_t93;
  const double _t285 = (0.1e1 / 0.36864e5)*_t284;
  const double _t286 = (0.1e1 / 0.32e2)*_t15;
  const double _t288 = (0.1e1 / 0.1536e4)*_t96;
  const double _t291 = _t17*_t275*_t276;
  const double _t293 = _t193*_t194;
  const double _t294 = _t35*_t49;
  const double _t301 = xc_powi(n_s, -12);
  const double _t304 = _t238*_t57;
  const double _t305 = _t35*_t69;
  const double _t308 = _t27*_t301;
  const double _t309 = _t19*_t96;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t4)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t3/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  const double _t32 = _hc0[0]*_t31;
  const double _t33 = my_piecewise3(_t4, 0, _t26*_t32);
#if _KMAX >= 1
  const double _t34 = _hc0[0]*_t26;
  const double _t50 = my_piecewise3(_t4, 0, _t32*_t49 - _t34*_t38);
  const double _t53 = _hc0[2]*_t2;
  const double _t54 = _t52*_t53;
  const double _t55 = (0.1e1 / 0.6e1)*_t54;
  const double _t59 = _t34*_t58;
  const double _t70 = my_piecewise3(_t4, 0, _t32*_t69 - _t51*_t55 + _t59*_t60);
#endif
#if _KMAX >= 2
  const double _t72 = _t34*_t71;
  const double _t77 = _t34*_t76;
  const double _t78 = _t73*_t77;
  const double _t81 = _hc0[0]*_t49;
  const double _t90 = my_piecewise3(_t4, 0, _t32*_t89 - _t72*sigma_ss + _t78*_t80 - _t81*_t82);
  const double _t92 = _t77*_t91;
  const double _t98 = _hc0[2]*_t1;
  const double _t99 = _t98/(M_PI * M_PI * M_PI * M_PI * M_CBRTPI);
  const double _t100 = _t97*_t99;
  const double _t101 = _t31*_t55;
  const double _t102 = _t58*_t81;
  const double _t103 = _hc0[0]*_t69;
  const double _t109 = my_piecewise3(_t4, 0, (0.1e1 / 0.4608e4)*_t100*_t96 - _t101*_t49 + _t102*_t60 - _t103*_t38 + _t108*_t32 + (0.1e1 / 0.96e2)*_t15*_t59 - _t92*_t94);
  const double _t111 = _t53/xc_powr(n_s, 7, 3);
  const double _t113 = _hc0[5]*_t17;
  const double _t114 = _t113/(M_CBRTPI * M_CBRTPI);
  const double _t115 = _t114*_t8;
  const double _t117 = _t116*_t77;
  const double _t122 = _t121*_t34;
  const double _t125 = _t100*_t124;
  const double _t128 = (0.1e1 / 0.3e1)*_t54;
  const double _t129 = _t103*_t58;
  const double _t145 = my_piecewise3(_t4, 0, _t110*_t111 + _t112*_t115 + _t117*_t119 - _t122*_t123 - _t125*_t126 - _t127*_t128 + _t129*_t130 + _t144*_t32);
#endif
#if _KMAX >= 3
  const double _t149 = _t148*_t34;
  const double _t150 = _t146*_t149;
  const double _t152 = _t36*_t81;
  const double _t154 = _hc0[0]*_t89;
  const double _t166 = my_piecewise3(_t4, 0, _hc0[0]*_t165*_t31 + (0.1e1 / 0.49152e5)*_hc0[0]*_t26*_t27*_t73*_t74*_t75 + (0.1e1 / 0.98304e5)*_hc0[0]*_t49*_t73*_t74*_t75*_t79 - _t150*_t151 - _t152*_t153 - _t154*_t155 - _t72);
  const double _t167 = (0.1e1 / 0.48e2)*_t59;
  const double _t171 = (0.1e1 / 0.2304e4)*_t100*_t95;
  const double _t173 = _t26*_t98;
  const double _t175 = _t173*_t174;
  const double _t176 = _t172*_t175;
  const double _t177 = _t76*_t81;
  const double _t178 = _t177*_t91;
  const double _t181 = _t103*_t71;
  const double _t182 = _t35*_t99;
  const double _t183 = _t182*_t49;
  const double _t185 = _t103*_t76;
  const double _t186 = _t185*_t73;
  const double _t187 = _t154*_t58;
  const double _t188 = _hc0[0]*_t108;
  const double _t192 = my_piecewise3(_t4, 0, -_t101*_t89 + _t102*_t180 + (0.1e1 / 0.28311552e8)*_t149*_t170 + _t167*sigma_ss + _t171*sigma_ss - 0.1e1 / 0.1769472e7*_t176*_t79 - _t178*_t179 - _t181*sigma_ss + _t183*_t184 + _t186*_t80 + _t187*_t60 - _t188*_t82 + _t191*_t32 - 0.1e1 / 0.13824e5*_t79*_t92);
  const double _t195 = _t149*_t194;
  const double _t201 = _t113*_t200;
  const double _t202 = _t159*_t201;
  const double _t204 = (0.2e1 / 0.9e1)*_t111;
  const double _t206 = _t115*_t31;
  const double _t208 = _t121*_t81;
  const double _t209 = _t124*_t183;
  const double _t210 = _t185*_t91;
  const double _t211 = _t182*_t69;
  const double _t212 = _hc0[0]*_t144;
  const double _t213 = _t128*_t31;
  const double _t214 = _t188*_t58;
  const double _t224 = my_piecewise3(_t4, 0, -_t108*_t213 + (0.25e2 / 0.110592e6)*_t117*_t93 - 0.3e1 / 0.32e2*_t122*_t15 - _t123*_t208 - 0.13e2 / 0.3456e4*_t125*_t15 - _t126*_t209 + _t129*_t180 + _t130*_t214 + (0.1e1 / 0.331776e6)*_t175*_t197 + _t177*_t207 - _t179*_t210 + _t184*_t211 - 0.1e1 / 0.10616832e8*_t193*_t195 - _t199*_t202 + _t203*_t204 + _t205*_t206 - _t212*_t38 + _t223*_t32);
  const double _t226 = _hc0[9]*_t225/(n_s * n_s * n_s * n_s);
  const double _t227 = _t53/xc_powr(n_s, 10, 3);
  const double _t228 = (0.14e2 / 0.27e2)*_t227;
  const double _t229 = _t114*_t65;
  const double _t230 = (0.1e1 / 0.9e1)*_t229;
  const double _t232 = _t149*_t231;
  const double _t236 = _t235*_t77;
  const double _t239 = _t34*_t57;
  const double _t240 = _t238*_t239;
  const double _t243 = _t175*_t242;
  const double _t246 = _t100*_t245;
  const double _t249 = _t189*_t201;
  const double _t250 = (0.1e1 / 0.3456e4)*_t249;
  const double _t251 = (0.2e1 / 0.3e1)*_t111;
  const double _t252 = _t116*_t185;
  const double _t254 = _t103*_t121;
  const double _t256 = _t124*_t211;
  const double _t258 = _hc0[2]*_t3*_t52;
  const double _t259 = _t212*_t58;
  const double _t271 = my_piecewise3(_t4, 0, -_t112*_t226 + (0.1e1 / 0.12e2)*_t115*_t127 + _t127*_t251 - _t228*_t51 - _t230*_t51 + _t232*_t234 - _t236*_t237 + _t240*_t241 - _t243*_t244 + _t246*_t247 + _t248*_t250 + _t252*_t253 - _t254*_t255 - _t256*_t60 - _t257*_t258 + _t259*_t260 + _t270*_t32);
#endif
#if _KMAX >= 4
  const double _t272 = _t34/(xc_powi(M_PI, 16)*xc_powi(_t30, 5));
  const double _t274 = _t154*_t76;
  const double _t277 = _hc0[0]*_t165;
  const double _t278 = _t147*_t173/(M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI);
  const double _t279 = _t148*_t81;
  const double _t281 = _t174*_t98;
  const double _t282 = _t281*_t49;
  const double _t287 = _t182*_t89;
  const double _t289 = _t188*_t76;
  const double _t290 = _hc0[0]*_t191;
  const double _t292 = _t113*_t26*_t75/(M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t295 = _t15*_t202;
  const double _t296 = _t103*_t148;
  const double _t297 = _t281*_t69;
  const double _t298 = _t212*_t76;
  const double _t299 = _t108*_t182;
  const double _t300 = _hc0[0]*_t223;
  const double _t302 = _hc0[9]/xc_powi(M_PI, 5);
  const double _t303 = _t226*_t31;
  const double _t306 = _t144*_t182;
  const double _t307 = _hc0[0]*_t270;
#endif

  const double f = my_piecewise3(_t4, 0, _t33*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t4, 0, _t50*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t4, 0, _t33 + _t70*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t4, 0, _t90*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t4, 0, _t109*n_s + _t50);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t4, 0, _t145*n_s + 0.2e1*_t70);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t4, 0, _t166*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t4, 0, _t192*n_s + _t90);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t4, 0, 0.2e1*_t109 + _t224*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t4, 0, 0.3e1*_t145 + _t271*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t4, 0, n_s*my_piecewise3(_t4, 0, -0.1e1 / 0.18874368e8*_t118*_t273*_t81 + (0.5e1 / 0.73728e5)*_t15*_t78 - 0.1e1 / 0.6291456e7*_t150*_t93 - 0.1e1 / 0.96e2*_t152 - 0.1e1 / 0.64e2*_t154*_t36*sigma_ss + (0.1e1 / 0.12288e5)*_t177*_t27*_t73 + (0.1e1 / 0.14495514624e11)*_t193*_t272/xc_powi(n_s, 32) + (0.1e1 / 0.49152e5)*_t274*_t73*_t79 - 0.1e1 / 0.192e3*_t277*_t37 + _t32*(0.0023384175415707489*_t12*_t6*_t7*pow(sigma_ss, -2.25) - 0.00031178900554276647*_t156*_t42 - 0.1e1 / 0.72e2*_t164*_t84 - 0.1e1 / 0.48e2*_t20*_t88 + _t21*(-8.1065020802242597e-8*_t163 + 4.1700113581400507e-10*_t17*_t275*_t276*sigma_ss/xc_powr(n_s, 40, 3)))));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t4, 0, _t166 + n_s*my_piecewise3(_t4, 0, -_t101*_t165 + (0.1e1 / 0.16e2)*_t102*sigma_ss - _t103*_t151*_t273 + (0.5e1 / 0.9437184e7)*_t118*_t149*_t168 + (0.1e1 / 0.452984832e9)*_t118*_t278/xc_powr(n_s, 76, 3) - _t153*_t188*_t36 - _t155*_t290 + _t167 + (0.1e1 / 0.9437184e7)*_t170*_t279 + _t171 - 0.1e1 / 0.294912e6*_t176*_t27 - 0.1e1 / 0.4608e4*_t178*_t79 - _t181 + (0.1e1 / 0.768e3)*_t183*_t280 + (0.1e1 / 0.49152e5)*_t186*_t27 + _t187*_t286 - 0.1e1 / 0.5435817984e10*_t233*_t272/xc_powi(n_s, 33) - 0.19e2 / 0.55296e5*_t27*_t92 - _t274*_t285 + _t277*_t58*_t60 - 0.1e1 / 0.589824e6*_t282*_t283 + _t287*_t288 + (0.1e1 / 0.98304e5)*_t289*_t73*_t79 + _t32*(-_t107*_t157 + (0.1e1 / 0.108e3)*_t136*_t15*_t164 + (0.1e1 / 0.18e2)*_t136*_t48 + (0.1e1 / 0.18e2)*_t136*_t88*sigma_ss + 0.0087300921551974626*_t156*_t63 - _t158*_t190 + _t21*(3.7830343041046538e-7*_t1*_t160*_t161*_t189*sigma_ss - 3.1518080087911921e-5*_t106 - 1.1120030288373469e-9*_t15*_t291/xc_powr(n_s, 43, 3)) - 0.0066514987849123517*_t62*_t83)));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t4, 0, 0.2e1*_t192 + n_s*my_piecewise3(_t4, 0, -0.1e1 / 0.13824e5*_hc0[5]*_t159*_t17*_t200*_t97*sigma_ss + (0.25e2 / 0.55296e5)*_t116*_t177*_t93 + (0.19e2 / 0.13824e5)*_t117*_t79 - _t121*_t123*_t154 - 0.3e1 / 0.16e2*_t122*sigma_ss - _t124*_t126*_t287 - 0.13e2 / 0.1728e4*_t125*sigma_ss + (0.1e1 / 0.24e2)*_t129*sigma_ss + _t130*_t290*_t58 - 0.3e1 / 0.16e2*_t15*_t208 - 0.13e2 / 0.1728e4*_t15*_t209 + (0.1e1 / 0.24e2)*_t15*_t214 - 0.139e3 / 0.84934656e8*_t169*_t195 - 0.1e1 / 0.84934656e8*_t169*_t278/xc_powr(n_s, 79, 3) + (0.1e1 / 0.14155776e8)*_t170*_t296 + (0.11e2 / 0.442368e6)*_t175*_t196*_t79 - _t191*_t213 + (0.1e1 / 0.165888e6)*_t197*_t282 + _t204*_t31*_t89 + (0.1e1 / 0.36e2)*_t206*_t89 + _t207*_t274 - 0.1e1 / 0.6912e4*_t210*_t79 + (0.1e1 / 0.1152e4)*_t211*_t280 - _t212*_t71*sigma_ss + (0.1e1 / 0.2038431744e10)*_t272*xc_powi(sigma_ss, 10)/xc_powi(n_s, 34) - 0.1e1 / 0.5308416e7*_t279*_t293 - 0.1e1 / 0.884736e6*_t283*_t297 - 0.1e1 / 0.27648e5*_t284*_t289 + (0.1e1 / 0.10616832e8)*_t292*_t79/xc_powr(n_s, 56, 3) - 0.1e1 / 0.13824e5*_t294*_t295 + _t298*_t73*_t80 + (0.1e1 / 0.1152e4)*_t299*_t96 - _t300*_t82 + _t32*((0.2e1 / 0.27e2)*_t107*_t136*sigma_ss + 0.061618745688007473*_t131*_t43 + 0.19788208885114245*_t132*_t83 - _t133*_t135*_t88 + _t190*_t218 + _t21*(0.00019494516202523299*_t139*sigma_ss - 0.0014372244520087835*_t142 - 1.3510836800373763e-6*_t15*_t221 + 2.9653414102329253e-9*_t27*_t291/xc_powr(n_s, 46, 3)) - _t215 - 0.19e2 / 0.81e2*_t216*sigma_ss + _t217 - _t219 - _t222*_t85)));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t4, 0, 0.3e1*_t224 + n_s*my_piecewise3(_t4, 0, (0.1e1 / 0.12e2)*_t108*_t206 + _t108*_t251*_t31 + _t116*_t253*_t289 - _t121*_t188*_t255 - _t124*_t299*_t60 + (0.15e2 / 0.16e2)*_t15*_t240 + (0.565e3 / 0.10368e5)*_t15*_t246 - 0.9e1 / 0.32e2*_t15*_t254 - 0.13e2 / 0.1152e4*_t15*_t256 - _t177*_t235*_t237 + _t183*_t245*_t247 + (0.17e2 / 0.3538944e7)*_t193*_t232 + (0.1e1 / 0.21233664e8)*_t193*_t278/xc_powr(n_s, 82, 3) + _t196*_t297*_t94 + (0.7e1 / 0.6912e4)*_t198*_t249 + _t199*_t301*_t302 - _t203*_t228 - _t203*_t230 - _t205*_t303 - _t223*_t258*_t31 + _t231*_t234*_t279 - 0.29e2 / 0.6144e4*_t236*_t93 + _t241*_t304*_t81 - _t242*_t244*_t282 - 0.79e2 / 0.663552e6*_t243*_t93 + _t250*_t27*_t294 + (0.25e2 / 0.36864e5)*_t252*_t93 + _t259*_t286 + _t260*_t300*_t58 - 0.1e1 / 0.764411904e9*_t272*xc_powi(sigma_ss, 11)/xc_powi(n_s, 35) - _t285*_t298 + _t288*_t306 - 0.1e1 / 0.1327104e7*_t292*_t93/xc_powr(n_s, 59, 3) - 0.1e1 / 0.3538944e7*_t293*_t296 - 0.1e1 / 0.9216e4*_t295*_t305 - _t307*_t38 + _t32*(-_t107*_t133*_t265 + (0.1e1 / 0.18e2)*_t143*_t17*_t18*_t64*sigma_ss + (0.1e1 / 0.36e2)*_t15*_t17*_t18*_t222*_t64 + (0.209e3 / 0.486e3)*_t15*_t17*_t18*_t263*_t48 + (0.209e3 / 0.243e3)*_t17*_t18*_t25*_t263*sigma_ss + _t21*(4.2754292452738312e-6*_t1*_t160*_t161*_t268*_t27 - 0.00079767980469406716*_t15*_t266 + 0.0095688891146900566*_t17*_t18*_t263*_t46*sigma_ss - _t267 - 7.9075770939544674e-9*_t291*_t79/xc_powr(n_s, 49, 3)) - 0.29931744532105575*_t261*_t5 - 1.7589519008990437*_t262*_t43 - 0.19e2 / 0.54e2*_t264*sigma_ss - _t269*_t44*sigma_ss)));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t4, 0, 0.4e1*_t271 + n_s*my_piecewise3(_t4, 0, (0.1e1 / 0.216e3)*_hc0[14]*_t16*_t51*_t9 + _hc0[9]*_t110*_t225/xc_powi(n_s, 5) - 0.125e3 / 0.486e3*_t100*_t27/xc_powr(n_s, 37, 3) + (0.5e1 / 0.4e1)*_t103*_t27*_t304 + (0.4e1 / 0.3e1)*_t111*_t257 + (0.40e2 / 0.81e2)*_t114*_t140*_t51 + (0.1e1 / 0.6912e4)*_t116*_t118*_t298 + (0.29e2 / 0.62208e5)*_t118*_t175/xc_powr(n_s, 61, 3) - 0.1e1 / 0.384e3*_t118*_t185*_t235 - 0.1e1 / 0.20736e5*_t118*_t242*_t297 + (0.1e1 / 0.248832e6)*_t118*_t292/xc_powr(n_s, 62, 3) + (0.67e2 / 0.4608e4)*_t118*_t77/xc_powi(n_s, 20) - 0.3e1 / 0.16e2*_t121*_t212*_t27 - _t124*_t130*_t306 + _t126*_t249*_t305 - 0.56e2 / 0.27e2*_t127*_t227 - 0.4e1 / 0.9e1*_t127*_t229 + (0.1e1 / 0.6e1)*_t144*_t206 - 0.1e1 / 0.73728e5*_t149*_t233/xc_powi(n_s, 28) - 0.35e2 / 0.5184e4*_t201*_t220*_t248 + (0.31e2 / 0.432e3)*_t211*_t245*_t27 + (0.1e1 / 0.995328e6)*_t231*_t233*_t296 - 0.1e1 / 0.5971968e7*_t233*_t278/xc_powr(n_s, 85, 3) - 0.55e2 / 0.16e2*_t239*_t308 - 0.1e1 / 0.2592e4*_t248*_t302/xc_powi(n_s, 13) + (0.1e1 / 0.72e2)*_t27*_t307*_t58 - 0.2e1 / 0.3e1*_t270*_t31*_t54 + (0.1e1 / 0.286654464e9)*_t272*xc_powi(sigma_ss, 12)/xc_powi(n_s, 36) - 0.1e1 / 0.9e1*_t303*_t69 + _t32*(7.7058845182243818*_t13*_t5*pow(n_s, -8.6666666666666661) - 0.19e2 / 0.54e2*_t133*_t143*_t15 + (0.1e1 / 0.27e2)*_t136*_t15*_t269 + (0.418e3 / 0.243e3)*_t15*_t19*_t263*_t68 + _t21*(0.0026594514984466912*_t105*_t308 - 1.2554069394362112e-5*_t162*_t79/xc_powr(n_s, 44, 3) + 2.1086872250545246e-8*_t172*_t291*_t93 - 0.038414236011147046*_t309*_t46 + 1.0693857643651881*_t66*sigma_ss/xc_powr(n_s, 20, 3)) - 0.5225e4 / 0.1458e4*_t25*_t309 + 1.0790209139968923*_t41*_t61*pow(n_s, -11.333333333333332)) + (0.140e3 / 0.81e2)*_t51*_t53/xc_powr(n_s, 13, 3)));
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