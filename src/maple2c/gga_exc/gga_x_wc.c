/*
  Generated from python/gga_exc/gga_x_wc.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_wc
*/

#ifndef _GGA_X_WC_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_WC_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_WC_HELPER_BODIES
#include "gga_x_wc.c"
#undef _GGA_X_WC_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_WC_HELPER_BODIES
#include "gga_x_wc.c"
#undef _GGA_X_WC_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_WC_HELPER_BODIES
#include "gga_x_wc.c"
#undef _GGA_X_WC_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_WC_HELPER_BODIES
#include "gga_x_wc.c"
#undef _GGA_X_WC_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_WC_HELPER_BODIES
#include "gga_x_wc.c"
#undef _GGA_X_WC_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_wc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_wc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_wc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_wc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_wc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_wc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_wc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_wc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_wc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_wc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_WC_HELPER_BODIES)

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
  const double _t7 = _t1/(M_PI * M_CBRTPI);
  const double _t8 = _t6*_t7;
  const double _t9 = (0.5e1 / 0.972e3)*_t8;
  const double _t10 = (sigma_ss * sigma_ss);
  const double _t11 = xc_powr(n_s, -16, 3);
  const double _t12 = xc_powr(0.6e1, 2, 3);
  const double _t13 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t14 = _t12*_t13;
  const double _t15 = _t11*_t14;
  const double _t16 = 1.3780328706878162e-5*_t10*_t15;
  const double _t17 = _t8*sigma_ss;
  const double _t18 = exp(-0.1e1 / 0.24e2*_t17);
  const double _t19 = 0.0040024242767108464*_t17*_t18 + _t9*sigma_ss + xc_log1p(_t16);
  const double _t20 = _t19 + 0.80400000000000005;
  const double _t21 = 0.80400000000000005/_t20;
  const double _t22 = _t19*_t21 + 0.1e1;
#if _KMAX >= 1
  const double _t24 = _t18*_t8;
  const double _t25 = _t15*_t18;
  const double _t26 = _t16 + 0.1e1;
  const double _t27 = (0.1e1 / _t26);
  const double _t28 = _t15*_t27;
  const double _t29 = 2.7560657413756323e-5*_t28;
  const double _t30 = 0.0040024242767108464*_t24 - 0.00016676767819628527*_t25*sigma_ss + _t29*sigma_ss + _t9;
  const double _t31 = (0.1e1 / (_t20 * _t20));
  const double _t32 = -_t30;
  const double _t33 = _t31*_t32;
  const double _t34 = 0.80400000000000005*_t19;
  const double _t35 = _t21*_t30 + _t33*_t34;
  const double _t37 = xc_powr(n_s, -4, 3);
  const double _t41 = xc_powr(n_s, -11, 3);
  const double _t42 = _t41*_t7;
  const double _t43 = (0.10e2 / 0.729e3)*_t42;
  const double _t44 = _t18*_t42;
  const double _t45 = 0.010673131404562257*_t44;
  const double _t46 = xc_powr(n_s, -19, 3);
  const double _t47 = _t14*_t46;
  const double _t48 = _t27*_t47;
  const double _t49 = _t10*_t48;
  const double _t50 = -0.00044471380852342738*_t10*_t12*_t13*_t18*_t46 + _t43*sigma_ss + _t45*sigma_ss + 7.3495086436683528e-5*_t49;
  const double _t51 = -_t50;
  const double _t52 = _t31*_t34;
  const double _t53 = _t21*_t51 + _t50*_t52;
#endif
#if _KMAX >= 2
  const double _t55 = _t18/(M_PI * M_PI * M_PI * M_PI);
  const double _t56 = _t55/xc_powi(n_s, 8);
  const double _t57 = _t56*sigma_ss;
  const double _t58 = (0.1e1 / (_t26 * _t26));
  const double _t59 = xc_powr(n_s, -32, 3);
  const double _t60 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t61 = _t1*_t60;
  const double _t62 = _t59*_t61;
  const double _t63 = _t58*_t62;
  const double _t64 = -4.5575390224706483e-9*_t10*_t63 - 0.00033353535639257054*_t25 + _t29 + 4.1691919549071317e-5*_t57;
  const double _t65 = -_t64;
  const double _t66 = 1.6080000000000001*_t33;
  const double _t67 = (0.1e1 / (_t20 * _t20 * _t20));
  const double _t68 = _t34*_t67;
  const double _t69 = 5.5121314827512646e-5*_t28;
  const double _t70 = 0.00033353535639257054*_t11*_t12*_t13*_t18*sigma_ss - 0.0080048485534216928*_t24 - _t69*sigma_ss - 0.5e1 / 0.486e3*_t8;
  const double _t71 = _t32*_t70;
  const double _t72 = _t21*_t64 + _t30*_t66 + _t52*_t65 + _t68*_t71;
  const double _t74 = _t55/xc_powi(n_s, 9);
  const double _t75 = _t10*_t74;
  const double _t76 = 0.00014699017287336706*_t48;
  const double _t77 = xc_powr(n_s, -35, 3);
  const double _t78 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t79 = -1.2153437393255062e-8*_t1*_t58*_t60*_t77*_t78 - 0.0013341414255702821*_t12*_t13*_t18*_t46*sigma_ss + _t43 + _t45 + 0.00011117845213085685*_t75 + _t76*sigma_ss;
  const double _t80 = -_t79;
  const double _t81 = 0.80400000000000005*_t51;
  const double _t82 = _t31*_t50;
  const double _t83 = 0.80400000000000005*_t82;
  const double _t84 = _t50*_t68;
  const double _t85 = _t21*_t80 + _t30*_t83 + _t33*_t81 + _t52*_t79 + _t70*_t84;
  const double _t87 = (0.2e1 / 0.9e1)*_t22;
  const double _t88 = xc_powr(n_s, -7, 3);
  const double _t90 = (0.1e1 / 0.36e2)*_t22;
  const double _t91 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t95 = xc_powr(n_s, -14, 3);
  const double _t96 = _t7*_t95;
  const double _t97 = (0.110e3 / 0.2187e4)*_t96;
  const double _t98 = _t55/xc_powi(n_s, 10);
  const double _t99 = _t78*_t98;
  const double _t100 = _t18*_t96;
  const double _t101 = 0.03913481515006161*_t100;
  const double _t102 = xc_powr(n_s, -22, 3);
  const double _t103 = _t102*_t14;
  const double _t104 = _t103*_t18;
  const double _t105 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t106 = xc_powr(n_s, -38, 3);
  const double _t107 = _t58*_t61;
  const double _t108 = _t106*_t107;
  const double _t109 = _t103*_t27;
  const double _t110 = _t10*_t109;
  const double _t111 = -0.0040024242767108464*_t10*_t104 + _t101*sigma_ss - 3.2409166382013499e-8*_t105*_t108 + 0.00046546888076566235*_t110 + _t97*sigma_ss + 0.00029647587234895159*_t99;
  const double _t112 = 1.6080000000000001*_t51;
  const double _t113 = -_t111;
  const double _t114 = (0.20e2 / 0.729e3)*_t42;
  const double _t115 = 0.021346262809124514*_t44;
  const double _t116 = _t18*_t47;
  const double _t117 = _t10*_t116;
  const double _t118 = _t10*_t76 + _t114*sigma_ss + _t115*sigma_ss - 0.00088942761704685475*_t117;
  const double _t119 = _t111*_t21 + _t112*_t82 + _t113*_t52 + _t118*_t84;
#endif
#if _KMAX >= 3
  const double _t121 = 0.00012507575864721395*_t56;
  const double _t122 = _t18*_t62;
  const double _t123 = xc_powi(n_s, -16);
  const double _t124 = xc_powi(M_PI, -8);
  const double _t125 = (0.1e1 / (_t26 * _t26 * _t26));
  const double _t126 = _t124*_t125;
  const double _t127 = _t123*_t126*_t78;
  const double _t128 = 1.3672617067411945e-8*_t63;
  const double _t129 = _t121 - 1.7371633145446382e-6*_t122*sigma_ss + 1.507305259777673e-12*_t127 - _t128*sigma_ss;
  const double _t130 = -_t129;
  const double _t131 = 2.4119999999999999*_t33;
  const double _t132 = _t31*_t65;
  const double _t133 = 2.4119999999999999*_t30;
  const double _t134 = 1.6080000000000001*_t19;
  const double _t135 = _t67*_t70;
  const double _t136 = _t135*_t65;
  const double _t137 = 9.1150780449412966e-9*_t1*_t10*_t58*_t59*_t60 + 0.00066707071278514107*_t11*_t12*_t13*_t18 - 8.3383839098142634e-5*_t57 - _t69;
  const double _t138 = _t32*_t68;
  const double _t139 = _t67*_t71;
  const double _t140 = 8.2681972241268969e-5*_t28;
  const double _t141 = 0.0005003030345888558*_t11*_t12*_t13*_t18*sigma_ss - _t140*sigma_ss - 0.012007272830132539*_t24 - 0.5e1 / 0.324e3*_t8;
  const double _t142 = (0.1e1 / (_t20 * _t20 * _t20 * _t20));
  const double _t143 = _t142*_t34;
  const double _t144 = _t141*_t143;
  const double _t145 = _t129*_t21 + _t130*_t52 + _t131*_t64 + _t132*_t133 + _t133*_t139 + _t134*_t136 + _t137*_t138 + _t144*_t71;
  const double _t147 = _t74*sigma_ss;
  const double _t148 = _t126/xc_powi(n_s, 17);
  const double _t149 = _t105*_t148;
  const double _t150 = -4.6324355054523686e-6*_t1*_t10*_t18*_t60*_t77 - 6.076718696627531e-8*_t1*_t10*_t58*_t60*_t77 - 0.0017788552340937095*_t12*_t13*_t18*_t46 + 0.00055589226065428423*_t147 + 4.0194806927404614e-12*_t149 + _t76;
  const double _t151 = -_t150;
  const double _t152 = _t30*_t31;
  const double _t153 = 1.6080000000000001*_t79;
  const double _t154 = _t30*_t50;
  const double _t155 = 1.6080000000000001*_t135;
  const double _t156 = _t135*_t19;
  const double _t157 = _t144*_t50;
  const double _t158 = _t132*_t81 + _t137*_t84 + _t139*_t81 + _t150*_t52 + _t151*_t21 + _t152*_t153 + _t153*_t156 + _t154*_t155 + _t157*_t70 + _t64*_t83 + _t66*_t80;
  const double _t161 = (0.1e1 / 0.36e2)*_t35;
  const double _t162 = _t10*_t98;
  const double _t163 = _t18*_t61;
  const double _t164 = _t106*_t163;
  const double _t165 = xc_powi(sigma_ss, 5);
  const double _t166 = _t126/xc_powi(n_s, 18);
  const double _t167 = _t165*_t166;
  const double _t168 = 0.0009309377615313247*_t109;
  const double _t169 = _t101 - 0.0096354658513409265*_t104*sigma_ss - 2.0660843568533605e-7*_t108*_t78 + 0.0018900336862245664*_t162 - 1.2353161347872983e-5*_t164*_t78 + 1.071861518064123e-11*_t167 + _t168*sigma_ss + _t97;
  const double _t170 = 0.80400000000000005*_t111;
  const double _t171 = 0.80400000000000005*_t113;
  const double _t172 = _t31*_t79;
  const double _t173 = 1.6080000000000001*_t82;
  const double _t174 = -_t169;
  const double _t175 = _t135*_t50;
  const double _t176 = _t118*_t67;
  const double _t177 = 0.80400000000000005*_t176;
  const double _t178 = _t113*_t68;
  const double _t179 = _t116*sigma_ss;
  const double _t180 = 0.00029398034574673411*_t48;
  const double _t181 = _t107*_t77;
  const double _t182 = _t181*_t78;
  const double _t183 = _t114 + _t115 - 0.0026682828511405643*_t179 + _t180*sigma_ss - 2.4306874786510124e-8*_t182 + 0.00022235690426171369*_t75;
  const double _t184 = _t118*_t68;
  const double _t185 = _t112*_t172 + _t112*_t175 + _t118*_t157 + _t152*_t171 + _t154*_t177 + _t169*_t21 + _t170*_t33 + _t173*_t80 + _t174*_t52 + _t178*_t70 + _t183*_t84 + _t184*_t79;
  const double _t187 = (0.1e1 / M_PI);
  const double _t194 = _t7/xc_powr(n_s, 17, 3);
  const double _t195 = (0.1540e4 / 0.6561e4)*_t194;
  const double _t196 = _t55/xc_powi(n_s, 11);
  const double _t197 = _t196*_t78;
  const double _t198 = _t18*_t194;
  const double _t199 = 0.18262913736695418*_t198;
  const double _t200 = xc_powr(n_s, -41, 3);
  const double _t201 = xc_powr(n_s, -25, 3);
  const double _t202 = xc_powi(sigma_ss, 6);
  const double _t203 = _t126/xc_powi(n_s, 19);
  const double _t204 = _t202*_t203;
  const double _t205 = _t14*_t201;
  const double _t206 = _t205*_t27;
  const double _t207 = _t10*_t206;
  const double _t208 = -3.2941763594327954e-5*_t1*_t105*_t18*_t200*_t60 - 6.1577416125825647e-7*_t1*_t105*_t200*_t58*_t60 - 0.033699424156997497*_t10*_t12*_t13*_t18*_t201 + _t195*sigma_ss + 0.0056330415746300802*_t197 + _t199*sigma_ss + 2.8582973815043281e-11*_t204 + 0.0034134384589481906*_t207;
  const double _t209 = -_t208;
  const double _t210 = _t113*_t31;
  const double _t211 = 2.4119999999999999*_t51;
  const double _t212 = 2.4119999999999999*_t82;
  const double _t213 = _t211*_t50;
  const double _t214 = (0.220e3 / 0.2187e4)*_t96;
  const double _t215 = 0.078269630300123219*_t100;
  const double _t216 = 6.4818332764026997e-8*_t1*_t105*_t106*_t58*_t60 + 0.0080048485534216928*_t10*_t102*_t12*_t13*_t18 - _t10*_t168 - _t214*sigma_ss - _t215*sigma_ss - 0.00059295174469790318*_t99;
  const double _t217 = _t113*_t134;
  const double _t218 = _t143*_t50;
  const double _t219 = (0.10e2 / 0.243e3)*_t42;
  const double _t220 = 0.032019394213686771*_t44;
  const double _t221 = -0.0013341414255702821*_t117 + _t219*sigma_ss + _t220*sigma_ss + 0.00022048525931005059*_t49;
  const double _t222 = _t118*_t221;
  const double _t223 = _t111*_t212 + _t176*_t213 + _t176*_t217 + _t208*_t52 + _t209*_t21 + _t210*_t211 + _t216*_t84 + _t218*_t222;
#endif
#if _KMAX >= 4
  const double _t225 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t226 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t227 = (0.1e1 / (_t26 * _t26 * _t26 * _t26));
  const double _t228 = _t12*_t226*_t227;
  const double _t229 = -9.0438315586660382e-12*_t10*_t123*_t124*_t125 + 1.2462697164805627e-16*_t105*_t228/xc_powr(n_s, 64, 3) - 7.2381804772693259e-8*_t12*_t18*_t225*sigma_ss/xc_powr(n_s, 40, 3) + 6.9486532581785529e-6*_t122 + _t128;
  const double _t230 = 4.8239999999999998*_t64;
  const double _t231 = 2.4119999999999999*_t156;
  const double _t232 = 3.4743266290892764e-6*_t1*_t18*_t59*_t60*sigma_ss + 2.734523413482389e-8*_t1*_t58*_t59*_t60*sigma_ss - 3.0146105195553461e-12*_t127 - 0.0002501515172944279*_t56;
  const double _t233 = _t137*_t67;
  const double _t234 = 2.4119999999999999*_t19;
  const double _t235 = _t234*_t65;
  const double _t236 = _t233*_t32;
  const double _t237 = 3.2160000000000002*_t30;
  const double _t238 = _t141*_t142;
  const double _t239 = _t238*_t70;
  const double _t240 = _t134*_t238;
  const double _t241 = _t137*_t240;
  const double _t242 = 1.3672617067411945e-8*_t1*_t10*_t58*_t59*_t60 + 0.0010006060691777116*_t11*_t12*_t13*_t18 - _t121*sigma_ss - _t140;
  const double _t243 = _t238*_t71;
  const double _t244 = _t34/xc_powi(_t20, 5);
  const double _t245 = _t244*(0.00066707071278514107*_t11*_t12*_t13*_t18*sigma_ss - 0.016009697106843386*_t24 - 0.00011024262965502529*_t28*sigma_ss - 0.5e1 / 0.243e3*_t8);
  const double _t246 = _t141*_t245;
  const double _t247 = _t10*_t18;
  const double _t248 = _t12*_t225;
  const double _t249 = -3.242704853816658e-5*_t1*_t18*_t60*_t77*sigma_ss - 1.4584124871906074e-7*_t1*_t58*_t60*_t77*sigma_ss - 3.3233859106148339e-16*_t12*_t165*_t226*_t227/xc_powr(n_s, 67, 3) + 3.6175326234664152e-11*_t148*_t78 + 1.9301814606051536e-7*_t247*_t248/xc_powr(n_s, 43, 3) + 0.0010006060691777116*_t74;
  const double _t250 = _t150*_t31;
  const double _t251 = 2.4119999999999999*_t80;
  const double _t252 = 2.4119999999999999*_t172;
  const double _t253 = 2.4119999999999999*_t175;
  const double _t254 = _t233*_t50;
  const double _t255 = _t234*_t79;
  const double _t256 = _t135*_t79;
  const double _t257 = _t218*_t242;
  const double _t258 = _t239*_t50;
  const double _t259 = _t246*_t50;
  const double _t260 = _t18*_t248;
  const double _t261 = -7.7376884737057228e-7*_t10*_t108 - 0.00011581088763630921*_t10*_t164 - 0.01126608314926016*_t104 + 1.21924247679794e-10*_t105*_t166 + _t168 - 8.8623624283062237e-16*_t202*_t228/xc_powr(n_s, 70, 3) + 5.1471505616137429e-7*_t260*_t78/xc_powr(n_s, 46, 3) + 0.0061889338352843644*_t98*sigma_ss;
  const double _t262 = 1.6080000000000001*_t174;
  const double _t263 = 3.2160000000000002*_t80;
  const double _t264 = _t113*_t30;
  const double _t265 = 3.2160000000000002*_t51;
  const double _t266 = _t183*_t67;
  const double _t267 = 1.6080000000000001*_t154;
  const double _t268 = _t153*_t19;
  const double _t269 = _t118*_t238;
  const double _t270 = -0.00036647711998689849*_t1*_t18*_t200*_t60*_t78 - 3.0275562928530944e-6*_t1*_t200*_t58*_t60*_t78 + 0.025323980763139615*_t10*_t196 + 1.3725734830969981e-6*_t105*_t260/xc_powr(n_s, 49, 3) - 0.075008395704284751*_t12*_t13*_t18*_t201*sigma_ss - 2.3632966475483263e-15*_t12*_t226*_t227*xc_powi(sigma_ss, 7)/xc_powr(n_s, 73, 3) + 3.7515153132244306e-10*_t165*_t203 + _t195 + _t199 + 0.0068268769178963811*_t206*sigma_ss;
  const double _t271 = _t216*_t67;
  const double _t272 = 0.80400000000000005*_t154;
  const double _t273 = _t176*_t50;
  const double _t274 = _t142*_t222;
  const double _t275 = _t118*_t218;
  const double _t276 = _t222*_t50;
  const double _t277 = _t7*sigma_ss/xc_powr(n_s, 20, 3);
  const double _t278 = _t105/xc_powr(n_s, 44, 3);
  const double _t279 = _t14/xc_powr(n_s, 28, 3);
  const double _t280 = 0.028445320491234921*_t10*_t27*_t279 - 9.9208059313830211e-6*_t107*_t278 + 1.0861530049716447e-9*_t126*_t202/xc_powi(n_s, 20) - 0.0010760976107480465*_t163*_t278 + 3.6601959549253283e-6*_t165*_t260/xc_powr(n_s, 52, 3) + 1.034898445079407*_t18*_t277 - 6.3021243934622036e-15*_t228*xc_powi(sigma_ss, 8)/xc_powr(n_s, 76, 3) - 0.30112066101575182*_t247*_t279 + (0.26180e5 / 0.19683e5)*_t277 + 0.084429740092262548*_t55*_t78/xc_powi(n_s, 12);
  const double _t281 = 4.8239999999999998*_t111;
  const double _t282 = _t265*_t50;
  const double _t283 = _t105*_t200;
  const double _t284 = _t113*_t234;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t5)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  const double _t23 = my_piecewise3(_t5, 0, _hc0[0]*_t22);
#if _KMAX >= 1
  const double _t36 = my_piecewise3(_t5, 0, _hc0[0]*_t35);
  const double _t38 = _hc0[2]*_t3;
  const double _t39 = _t37*_t38;
  const double _t40 = (0.1e1 / 0.6e1)*_t39;
  const double _t54 = my_piecewise3(_t5, 0, _hc0[0]*_t53 - _t22*_t40);
#endif
#if _KMAX >= 2
  const double _t73 = my_piecewise3(_t5, 0, _hc0[0]*_t72);
  const double _t86 = my_piecewise3(_t5, 0, _hc0[0]*_t85 - _t35*_t40);
  const double _t89 = _t38*_t88;
  const double _t92 = _hc0[5]*_t12*_t91;
  const double _t93 = _t6*_t92;
  const double _t94 = (0.1e1 / 0.3e1)*_t39;
  const double _t120 = my_piecewise3(_t5, 0, _hc0[0]*_t119 - _t53*_t94 + _t87*_t89 + _t90*_t93);
#endif
#if _KMAX >= 3
  const double _t146 = my_piecewise3(_t5, 0, _hc0[0]*_t145);
  const double _t159 = my_piecewise3(_t5, 0, _hc0[0]*_t158 - _t40*_t72);
  const double _t160 = (0.2e1 / 0.9e1)*_t89;
  const double _t186 = my_piecewise3(_t5, 0, _hc0[0]*_t185 + _t160*_t35 + _t161*_t93 - _t85*_t94);
  const double _t188 = _hc0[9]*_t187/(n_s * n_s * n_s * n_s);
  const double _t189 = _t38/xc_powr(n_s, 10, 3);
  const double _t190 = (0.14e2 / 0.27e2)*_t189;
  const double _t191 = _t41*_t92;
  const double _t192 = (0.1e1 / 0.9e1)*_t191;
  const double _t193 = _hc0[2]*_t37*_t4;
  const double _t224 = my_piecewise3(_t5, 0, _hc0[0]*_t223 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t53*_t88 + (0.1e1 / 0.12e2)*_hc0[5]*_t12*_t53*_t6*_t91 - _t119*_t193 - _t188*_t90 - _t190*_t22 - _t192*_t22);
#endif

  const double f = my_piecewise3(_t5, 0, _t23*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t5, 0, _t36*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t5, 0, _t23 + _t54*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t5, 0, _t73*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t5, 0, _t36 + _t86*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t5, 0, _t120*n_s + 0.2e1*_t54);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t5, 0, _t146*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t5, 0, _t159*n_s + _t73);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t5, 0, _t186*n_s + 0.2e1*_t86);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t5, 0, 0.3e1*_t120 + _t224*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(3.2160000000000002*_t129*_t33 + 3.2160000000000002*_t130*_t152 + _t130*_t231 + _t132*_t230 + 6.4320000000000004*_t136*_t30 + _t138*_t232 + _t139*_t230 + _t143*_t242*_t71 - _t21*_t229 + _t229*_t52 + _t233*_t235 + _t235*_t239 + _t236*_t237 + _t237*_t243 + _t241*_t32 + _t246*_t71)));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t5, 0, _t146 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t112*_t136 + _t129*_t83 + _t130*_t31*_t81 + _t131*_t151 + _t132*_t251 + _t133*_t250 + _t133*_t254 + _t133*_t258 + _t139*_t251 + _t150*_t231 - _t21*_t249 + _t232*_t84 + _t233*_t255 + _t236*_t81 + _t239*_t255 + _t241*_t50 + _t243*_t81 + _t249*_t52 + _t252*_t64 + _t253*_t64 + 4.8239999999999998*_t256*_t30 + _t257*_t70 + _t259*_t70) - _t145*_t40));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t5, 0, 0.2e1*_t159 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t112*_t250 + _t112*_t254 + _t112*_t258 + _t113*_t144*_t70 + _t118*_t257 + _t118*_t259 + _t132*_t170 + _t137*_t178 + _t139*_t170 + _t150*_t184 + _t151*_t173 + _t152*_t262 + _t153*_t176*_t30 + _t155*_t264 + _t156*_t262 + _t169*_t66 + _t171*_t31*_t64 + _t172*_t263 + _t175*_t263 + _t177*_t50*_t64 + _t183*_t240*_t50 + _t21*_t261 + _t256*_t265 - _t261*_t52 + _t266*_t267 + _t266*_t268 + _t267*_t269 + _t268*_t269 + _t84*(-9.2648710109047372e-6*_t10*_t163*_t77 - 1.2153437393255062e-7*_t10*_t181 - 0.0035577104681874191*_t116 + 0.0011117845213085685*_t147 + 8.0389613854809227e-12*_t149 + _t180)) - _t158*_t94 + _t160*_t72 + (0.1e1 / 0.36e2)*_t72*_t93));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t5, 0, 0.3e1*_t186 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t111*_t252 + _t111*_t253 + _t113*_t135*_t211 + _t143*_t222*_t79 + 0.80400000000000005*_t152*_t208 + _t157*_t216 + _t169*_t212 + _t174*_t211*_t31 + _t176*_t19*_t262 + _t176*_t211*_t79 + 1.6080000000000001*_t176*_t264 + _t183*_t218*_t221 + _t208*_t68*_t70 + 0.80400000000000005*_t209*_t33 - _t21*_t270 + _t210*_t251 + _t213*_t266 + _t213*_t269 + _t216*_t68*_t79 + _t217*_t266 + _t217*_t269 + _t245*_t276 + _t251*_t273 + _t270*_t52 + _t271*_t272 + _t272*_t274 + _t275*(-0.0040024242767108464*_t179 - 3.6460312179765187e-8*_t182 + _t219 + _t220 + 0.00044097051862010117*_t48*sigma_ss + 0.00033353535639257054*_t75) + _t84*(2.4706322695745966e-5*_t1*_t106*_t18*_t60*_t78 + 4.1321687137067211e-7*_t1*_t106*_t58*_t60*_t78 + 0.019270931702681853*_t102*_t12*_t13*_t18*sigma_ss - 0.0018618755230626494*_t109*sigma_ss - 0.0037800673724491328*_t162 - 2.1437230361282461e-11*_t167 - _t214 - _t215)) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t85*_t88 + (0.1e1 / 0.12e2)*_hc0[5]*_t12*_t6*_t85*_t91 - _t161*_t188 - _t185*_t193 - _t190*_t35 - _t192*_t35));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t5, 0, 0.4e1*_t224 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(6.4320000000000004*_t113*_t176*_t51 + _t134*_t142*_t216*_t221*_t50 + _t176*_t208*_t234 + _t208*_t265*_t31 + 3.2160000000000002*_t209*_t82 + _t21*_t280 + _t210*_t281 + _t244*_t276*(_t10*_t180 - 0.0017788552340937095*_t117 + (0.40e2 / 0.729e3)*_t42*sigma_ss + 0.042692525618249029*_t44*sigma_ss) + _t271*_t282 + _t271*_t284 + _t273*_t281 + _t274*_t282 + _t274*_t284 + _t275*(9.7227499146040495e-8*_t1*_t105*_t106*_t58*_t60 + 0.012007272830132539*_t10*_t102*_t12*_t13*_t18 - 0.11740444545018483*_t100*sigma_ss - 0.001396406642296987*_t110 - 0.110e3 / 0.729e3*_t96*sigma_ss - 0.00088942761704685477*_t99) - _t280*_t52 + _t84*(-1.2315483225165129e-6*_t107*_t283 - 6.5883527188655909e-5*_t163*_t283 + (0.3080e4 / 0.6561e4)*_t194*sigma_ss + 0.01126608314926016*_t197 + 0.36525827473390835*_t198*sigma_ss + 5.7165947630086561e-11*_t204 - 0.067398848313994994*_t205*_t247 + 0.0068268769178963811*_t207)) + (0.1e1 / 0.216e3)*_hc0[14]*_t11*_t22*_t7 + _hc0[9]*_t187*_t87/xc_powi(n_s, 5) + (0.4e1 / 0.3e1)*_t119*_t89 + (0.1e1 / 0.6e1)*_t119*_t93 - 0.1e1 / 0.9e1*_t188*_t53 - 0.56e2 / 0.27e2*_t189*_t53 - 0.4e1 / 0.9e1*_t191*_t53 + (0.140e3 / 0.81e2)*_t22*_t38/xc_powr(n_s, 13, 3) + (0.40e2 / 0.81e2)*_t22*_t92*_t95 - 0.2e1 / 0.3e1*_t223*_t39));
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