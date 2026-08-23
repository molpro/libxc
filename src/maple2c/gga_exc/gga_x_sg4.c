/*
  Generated from python/gga_exc/gga_x_sg4.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_sg4
*/

#ifndef _GGA_X_SG4_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_SG4_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_SG4_HELPER_BODIES
#include "gga_x_sg4.c"
#undef _GGA_X_SG4_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_SG4_HELPER_BODIES
#include "gga_x_sg4.c"
#undef _GGA_X_SG4_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_SG4_HELPER_BODIES
#include "gga_x_sg4.c"
#undef _GGA_X_SG4_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_SG4_HELPER_BODIES
#include "gga_x_sg4.c"
#undef _GGA_X_SG4_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_SG4_HELPER_BODIES
#include "gga_x_sg4.c"
#undef _GGA_X_SG4_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_sg4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_sg4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_sg4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_sg4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_sg4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_sg4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_sg4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_sg4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_sg4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_sg4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_SG4_HELPER_BODIES)

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
  const double _t9 = _t8*sigma_ss;
  const double _t10 = 0.037270642201834861*_t9 + 0.1e1;
  const double _t11 = (0.1e1 / _t10);
  const double _t12 = 0.0090833333333333321*_t11;
  const double _t13 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t14 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t15 = _t14/xc_powi(n_s, 8);
  const double _t16 = 0.0031233982573039467*_t8;
  const double _t17 = (sigma_ss * sigma_ss);
  const double _t18 = xc_powr(n_s, -16, 3);
  const double _t19 = xc_powr(0.6e1, 2, 3);
  const double _t20 = _t19/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t21 = _t18*_t20;
  const double _t22 = 1.8282405670590909e-7*_t13*_t15 + _t16*sigma_ss + 9.755616673729331e-6*_t17*_t21 + 0.1e1;
  const double _t23 = 0.00175*_t22;
  const double _t24 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t25 = _t1/(M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI);
  const double _t26 = _t25/xc_powr(n_s, 32, 3);
  const double _t27 = _t22 + 5.7103234010847442e-10*_t24*_t26;
  const double _t28 = (0.1e1 / _t27);
  const double _t29 = _t28*_t9;
  const double _t30 = _t12*_t9 + _t23*_t29 + 0.1e1;
#if _KMAX >= 1
  const double _t32 = (0.1e1 / (_t10 * _t10));
  const double _t33 = _t21*_t32;
  const double _t34 = _t15*_t17;
  const double _t35 = 1.9511233347458662e-5*_t21;
  const double _t36 = _t16 + 5.4847217011772728e-7*_t34 + _t35*sigma_ss;
  const double _t37 = 0.00175*_t29;
  const double _t38 = _t28*_t8;
  const double _t39 = (0.1e1 / (_t27 * _t27));
  const double _t40 = _t13*_t26;
  const double _t41 = -_t36 - 2.2841293604338977e-9*_t40;
  const double _t42 = _t39*_t41;
  const double _t43 = _t23*_t9;
  const double _t44 = _t12*_t8 + _t23*_t38 - 0.00033854166666666662*_t33*sigma_ss + _t36*_t37 + _t42*_t43;
  const double _t46 = xc_powr(n_s, -4, 3);
  const double _t50 = xc_powr(n_s, -11, 3);
  const double _t51 = _t50*_t7;
  const double _t52 = 0.024222222222222218*_t11*_t51;
  const double _t53 = _t20/xc_powr(n_s, 19, 3);
  const double _t54 = _t17*_t53;
  const double _t55 = _t14/xc_powi(n_s, 9);
  const double _t56 = _t13*_t55;
  const double _t57 = 0.0083290620194771906*_t51;
  const double _t58 = 5.2029955593223094e-5*_t54 + 1.4625924536472727e-6*_t56 + _t57*sigma_ss;
  const double _t59 = -_t58;
  const double _t60 = 0.0046666666666666662*_t22;
  const double _t61 = _t51*sigma_ss;
  const double _t62 = _t28*_t61;
  const double _t63 = _t25/xc_powr(n_s, 35, 3);
  const double _t64 = _t24*_t63;
  const double _t65 = _t58 + 6.0910116278237272e-9*_t64;
  const double _t66 = _t39*_t65;
  const double _t67 = 0.00090277777777777763*_t32*_t54 + _t37*_t59 + _t43*_t66 - _t52*sigma_ss - _t60*_t62;
#endif
#if _KMAX >= 2
  const double _t69 = (0.1e1 / (_t10 * _t10 * _t10));
  const double _t70 = _t15*_t69;
  const double _t71 = 1.0969443402354546e-6*_t15;
  const double _t72 = _t35 + _t71*sigma_ss;
  const double _t73 = 0.0035000000000000001*_t38;
  const double _t74 = _t17*_t26;
  const double _t75 = -_t72 - 6.8523880813016935e-9*_t74;
  const double _t76 = _t39*_t43;
  const double _t77 = _t36*_t9;
  const double _t78 = 0.0035000000000000001*_t77;
  const double _t79 = _t22*_t41;
  const double _t80 = _t39*_t8;
  const double _t81 = 0.0035000000000000001*_t80;
  const double _t82 = (0.1e1 / (_t27 * _t27 * _t27));
  const double _t83 = 3.9022466694917324e-5*_t21;
  const double _t84 = -_t17*_t71 - 4.5682587208677954e-9*_t40 - 0.0062467965146078934*_t8 - _t83*sigma_ss;
  const double _t85 = _t82*_t84;
  const double _t86 = _t43*_t85;
  const double _t87 = -0.00067708333333333325*_t33 + _t36*_t73 + _t37*_t72 + _t41*_t86 + _t42*_t78 + 0.00015141198394495411*_t70*sigma_ss + _t75*_t76 + _t79*_t81;
  const double _t89 = _t17*_t55;
  const double _t90 = _t32*_t53;
  const double _t91 = 0.0046666666666666662*_t62;
  const double _t92 = 0.00010405991118644619*_t53;
  const double _t93 = _t57 + 4.3877773609418182e-6*_t89 + _t92*sigma_ss;
  const double _t94 = -_t93;
  const double _t95 = 0.00175*_t38;
  const double _t96 = _t28*_t51;
  const double _t97 = _t59*_t9;
  const double _t98 = 0.00175*_t97;
  const double _t99 = 0.00175*_t66;
  const double _t100 = _t60*_t61;
  const double _t101 = _t13*_t63;
  const double _t102 = 2.4364046511294909e-8*_t101 + _t93;
  const double _t103 = _t23*_t80;
  const double _t104 = -_t100*_t42 + _t102*_t76 + _t103*_t65 - _t36*_t91 + _t37*_t94 + _t42*_t98 - _t52 + _t59*_t95 - _t60*_t96 + _t65*_t86 - 0.00040376529051987763*_t69*_t89 + _t77*_t99 + 0.002708333333333333*_t90*sigma_ss;
  const double _t106 = (0.2e1 / 0.9e1)*_t30;
  const double _t107 = xc_powr(n_s, -7, 3);
  const double _t109 = (0.1e1 / 0.36e2)*_t30;
  const double _t110 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t114 = _t14/xc_powi(n_s, 10);
  const double _t115 = _t114*_t13;
  const double _t116 = xc_powr(n_s, -14, 3);
  const double _t117 = _t116*_t7;
  const double _t118 = 0.088814814814814791*_t11*_t117;
  const double _t119 = _t20/xc_powr(n_s, 22, 3);
  const double _t120 = _t119*_t17;
  const double _t121 = 0.0093333333333333324*_t62;
  const double _t122 = 0.030539894071416364*_t117;
  const double _t123 = 1.3163332082825454e-5*_t115 + 0.0003295230520904129*_t120 + _t122*sigma_ss;
  const double _t124 = 0.017111111111111108*_t22;
  const double _t125 = _t117*sigma_ss;
  const double _t126 = _t125*_t28;
  const double _t127 = 0.0035000000000000001*_t66;
  const double _t128 = 0.0093333333333333324*_t61;
  const double _t129 = _t22*_t65;
  const double _t130 = _t129*_t39;
  const double _t131 = _t25/xc_powr(n_s, 38, 3);
  const double _t132 = _t131*_t24;
  const double _t133 = -_t123 - 7.1061802324610145e-8*_t132;
  const double _t134 = 0.016658124038954381*_t51;
  const double _t135 = _t134*sigma_ss + _t17*_t92 + 2.9251849072945455e-6*_t56 + 1.2182023255647454e-8*_t64;
  const double _t136 = _t135*_t82;
  const double _t137 = _t43*_t65;
  const double _t138 = 0.0010767074413863403*_t115*_t69 + _t118*sigma_ss - 0.0081249999999999968*_t120*_t32 - _t121*_t59 + _t123*_t37 + _t124*_t126 + _t127*_t97 - _t128*_t130 + _t133*_t76 + _t136*_t137;
#endif
#if _KMAX >= 3
  const double _t140 = (0.1e1 / (_t10 * _t10 * _t10 * _t10));
  const double _t141 = _t26*sigma_ss;
  const double _t142 = 1.9196525954120457e-9*_t141;
  const double _t143 = 0.0052500000000000003*_t38;
  const double _t144 = -1.3704776162603387e-8*_t141 - _t71;
  const double _t145 = _t72*_t9;
  const double _t146 = 0.0052500000000000003*_t145;
  const double _t147 = _t39*_t75;
  const double _t148 = 0.0052500000000000003*_t77;
  const double _t149 = _t75*_t80;
  const double _t150 = 0.0052500000000000003*_t22;
  const double _t151 = _t41*_t80;
  const double _t152 = 0.010500000000000001*_t36;
  const double _t153 = 2.1938886804709091e-6*_t15;
  const double _t154 = -_t153*sigma_ss - 1.3704776162603387e-8*_t74 - _t83;
  const double _t155 = _t154*_t82;
  const double _t156 = _t41*_t43;
  const double _t157 = 0.0035000000000000001*_t22;
  const double _t158 = _t157*_t9;
  const double _t159 = _t75*_t85;
  const double _t160 = _t41*_t85;
  const double _t161 = _t8*_t82;
  const double _t162 = _t161*_t84;
  const double _t163 = (0.1e1 / (_t27 * _t27 * _t27 * _t27));
  const double _t164 = 5.8533700042375986e-5*_t21;
  const double _t165 = -_t164*sigma_ss - 1.6454165103531817e-6*_t34 - 6.8523880813016935e-9*_t40 - 0.0093701947719118401*_t8;
  const double _t166 = _t165*_t84;
  const double _t167 = _t163*_t166;
  const double _t168 = -1.6929665636047048e-5*_t140*_t141 + _t142*_t28 + _t143*_t72 + _t144*_t76 + _t146*_t42 + _t147*_t148 + _t148*_t160 + _t149*_t150 + _t151*_t152 + _t155*_t156 + _t156*_t167 + _t158*_t159 + 0.0052500000000000003*_t162*_t79 + 0.00045423595183486233*_t70;
  const double _t170 = _t55*_t69;
  const double _t171 = _t17*_t63;
  const double _t172 = 8.7755547218836365e-6*_t55;
  const double _t173 = _t172*sigma_ss + _t92;
  const double _t174 = -_t173;
  const double _t175 = 0.0093333333333333324*_t96;
  const double _t176 = 7.3092139533884726e-8*_t171 + _t173;
  const double _t177 = _t128*_t36;
  const double _t178 = _t42*_t9;
  const double _t179 = 0.0035000000000000001*_t178;
  const double _t180 = _t102*_t39;
  const double _t181 = _t41*_t81;
  const double _t182 = _t65*_t81;
  const double _t183 = _t39*_t51;
  const double _t184 = 0.0093333333333333324*_t183;
  const double _t185 = _t22*_t81;
  const double _t186 = _t65*_t85;
  const double _t187 = _t102*_t158;
  const double _t188 = 0.0035000000000000001*_t129;
  const double _t189 = -_t100*_t147 - _t100*_t160 + _t102*_t185 + _t137*_t155 + _t137*_t167 + 4.5145775029458792e-5*_t140*_t171 + _t145*_t99 + _t147*_t98 + _t160*_t98 + _t162*_t188 - 0.0020188264525993881*_t170*sigma_ss + _t174*_t37 - _t175*_t36 + _t176*_t76 - _t177*_t42 + _t179*_t94 + _t180*_t78 + _t181*_t59 + _t182*_t36 - _t184*_t79 + _t186*_t78 + _t187*_t85 - _t72*_t91 + _t73*_t94 + 0.0036111111111111105*_t90;
  const double _t192 = (0.1e1 / 0.36e2)*_t44;
  const double _t193 = _t114*_t17;
  const double _t194 = _t119*_t32;
  const double _t195 = _t13*_t131;
  const double _t196 = 0.017111111111111108*_t126;
  const double _t197 = 0.0006590461041808258*_t119;
  const double _t198 = _t122 + 3.9489996248476362e-5*_t193 + _t197*sigma_ss;
  const double _t199 = _t117*_t28;
  const double _t200 = _t128*_t59;
  const double _t201 = 0.00175*_t123;
  const double _t202 = _t9*_t94;
  const double _t203 = _t102*_t59;
  const double _t204 = _t39*_t9;
  const double _t205 = _t133*_t36;
  const double _t206 = _t124*_t125;
  const double _t207 = _t22*_t39;
  const double _t208 = _t128*_t207;
  const double _t209 = -2.8424720929844058e-7*_t195 - _t198;
  const double _t210 = 0.0035000000000000001*_t97;
  const double _t211 = _t136*_t65;
  const double _t212 = 0.00175*_t77;
  const double _t213 = _t128*_t129;
  const double _t214 = _t102*_t135;
  const double _t215 = _t214*_t82;
  const double _t216 = 0.00020811982237289238*_t53;
  const double _t217 = 4.8728093022589817e-8*_t101 + _t134 + _t17*_t172 + _t216*sigma_ss;
  const double _t218 = _t137*_t82;
  const double _t219 = _t161*_t65;
  const double _t220 = _t135*_t219;
  const double _t221 = _t163*_t165;
  const double _t222 = _t135*_t137;
  const double _t223 = -_t102*_t208 + _t103*_t133 + _t118 - _t121*_t94 + _t123*_t95 + _t124*_t199 + _t127*_t202 - _t129*_t184 + _t133*_t86 - 0.00012038873341189011*_t140*_t195 - _t175*_t59 - _t177*_t66 + _t178*_t201 + _t182*_t59 + _t186*_t210 + 0.0068640099388379179*_t193*_t69 - 0.019560185185185177*_t194*sigma_ss + _t196*_t36 + _t198*_t37 - _t200*_t42 + 0.0035000000000000001*_t203*_t204 + 0.00175*_t204*_t205 + _t206*_t42 + _t209*_t76 + _t211*_t212 - _t213*_t85 + _t215*_t43 + _t217*_t218 + _t220*_t23 + _t221*_t222;
  const double _t225 = (0.1e1 / M_PI);
  const double _t232 = _t14/xc_powi(n_s, 11);
  const double _t233 = _t13*_t232;
  const double _t234 = _t7/xc_powr(n_s, 17, 3);
  const double _t235 = 0.41446913580246902*_t11*_t234;
  const double _t236 = _t25/xc_powr(n_s, 41, 3);
  const double _t237 = _t236*_t24;
  const double _t238 = _t20/xc_powr(n_s, 25, 3);
  const double _t239 = _t17*_t238;
  const double _t240 = 0.051333333333333328*_t59;
  const double _t241 = 0.013999999999999999*_t62;
  const double _t242 = 0.1425195056666097*_t234;
  const double _t243 = 0.00013163332082825454*_t233 + 0.0024165023819963613*_t239 + _t242*sigma_ss;
  const double _t244 = -_t243;
  const double _t245 = _t234*sigma_ss;
  const double _t246 = 0.079851851851851841*_t28;
  const double _t247 = _t22*_t246;
  const double _t248 = 0.027999999999999997*_t61;
  const double _t249 = _t59*_t66;
  const double _t250 = _t66*_t9;
  const double _t251 = 0.0052500000000000003*_t123;
  const double _t252 = 0.0052500000000000003*_t59;
  const double _t253 = _t204*_t252;
  const double _t254 = 0.051333333333333328*_t129;
  const double _t255 = _t125*_t254;
  const double _t256 = 0.013999999999999999*_t133;
  const double _t257 = _t207*_t61;
  const double _t258 = 9.0011616277839516e-7*_t237 + _t243;
  const double _t259 = _t252*_t9;
  const double _t260 = 0.013999999999999999*_t136;
  const double _t261 = _t129*_t260;
  const double _t262 = 0.061079788142832728*_t117;
  const double _t263 = -2.6326664165650908e-5*_t115 - 1.4212360464922029e-7*_t132 - _t17*_t197 - _t262*sigma_ss;
  const double _t264 = _t133*_t135;
  const double _t265 = _t158*_t82;
  const double _t266 = 0.024987186058431574*_t51;
  const double _t267 = _t266*sigma_ss + 0.0001560898667796693*_t54 + 4.3877773609418182e-6*_t56 + 1.8273034883471181e-8*_t64;
  const double _t268 = _t163*_t222;
  const double _t269 = -_t123*_t241 + _t126*_t240 + _t133*_t253 + 0.00032103662243170695*_t140*_t237 + _t211*_t259 + _t218*_t263 - 0.020457441386340463*_t233*_t69 - _t235*sigma_ss + 0.068410493827160468*_t239*_t32 + _t244*_t37 - _t245*_t247 - _t248*_t249 + _t250*_t251 + _t255*_t39 - _t256*_t257 + _t258*_t76 - _t261*_t61 + _t264*_t265 + _t267*_t268;
#endif
#if _KMAX >= 4
  const double _t271 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t272 = _t19*_t271/xc_powi(_t10, 5);
  const double _t273 = sigma_ss/xc_powr(n_s, 40, 3);
  const double _t274 = _t144*_t39;
  const double _t275 = 0.0070000000000000001*_t77;
  const double _t276 = 0.010500000000000001*_t145;
  const double _t277 = 0.0070000000000000001*_t80;
  const double _t278 = 0.021000000000000001*_t36;
  const double _t279 = -2.7409552325206774e-8*_t141 - _t153;
  const double _t280 = _t85*_t9;
  const double _t281 = _t150*_t154;
  const double _t282 = _t82*_t9;
  const double _t283 = _t281*_t282;
  const double _t284 = _t155*_t41;
  const double _t285 = 0.014*_t75;
  const double _t286 = 0.0070000000000000001*_t79;
  const double _t287 = _t162*_t22;
  const double _t288 = _t162*_t41;
  const double _t289 = -3.2908330207063635e-6*_t15*sigma_ss - _t164 - 2.0557164243905079e-8*_t74;
  const double _t290 = _t163*_t289*_t84;
  const double _t291 = _t154*_t9;
  const double _t292 = _t150*_t9;
  const double _t293 = _t167*_t292;
  const double _t294 = _t167*_t41;
  const double _t295 = _t163*_t8;
  const double _t296 = _t166*_t295;
  const double _t297 = xc_powi(_t27, -5);
  const double _t298 = _t297*(-_t153*_t17 - 7.8044933389834648e-5*_t21*sigma_ss - 9.1365174417355907e-9*_t40 - 0.012493593029215787*_t8);
  const double _t299 = _t166*_t298;
  const double _t300 = _t63*sigma_ss;
  const double _t301 = 0.013999999999999999*_t96;
  const double _t302 = _t42*_t61;
  const double _t303 = 0.013999999999999999*_t302;
  const double _t304 = 0.013999999999999999*_t75;
  const double _t305 = _t39*_t61;
  const double _t306 = _t305*_t36;
  const double _t307 = _t176*_t39;
  const double _t308 = 0.0052500000000000003*_t202;
  const double _t309 = 0.0052500000000000003*_t80;
  const double _t310 = _t65*_t72;
  const double _t311 = _t183*_t22;
  const double _t312 = _t150*_t176;
  const double _t313 = _t183*_t36;
  const double _t314 = _t102*_t152;
  const double _t315 = 0.0052500000000000003*_t280;
  const double _t316 = _t155*_t65;
  const double _t317 = _t36*_t61;
  const double _t318 = _t162*_t65;
  const double _t319 = _t51*_t85;
  const double _t320 = _t165*_t188;
  const double _t321 = _t167*_t65;
  const double _t322 = _t114*sigma_ss;
  const double _t323 = _t131*_t17;
  const double _t324 = _t197 + 7.8979992496952723e-5*_t322;
  const double _t325 = 0.034222222222222216*_t36;
  const double _t326 = 0.018666666666666665*_t94;
  const double _t327 = 0.00175*_t39;
  const double _t328 = _t201*_t9;
  const double _t329 = _t125*_t42;
  const double _t330 = 0.018666666666666665*_t102;
  const double _t331 = _t183*_t59;
  const double _t332 = 0.018666666666666665*_t65;
  const double _t333 = _t65*_t94;
  const double _t334 = _t117*_t39;
  const double _t335 = _t136*_t9;
  const double _t336 = _t133*_t43;
  const double _t337 = 0.0070000000000000001*_t280;
  const double _t338 = 0.0035000000000000001*_t205;
  const double _t339 = _t217*_t82;
  const double _t340 = _t65*_t78;
  const double _t341 = _t22*_t61;
  const double _t342 = _t341*_t85;
  const double _t343 = _t158*_t209;
  const double _t344 = 0.018666666666666665*_t129;
  const double _t345 = _t157*_t161;
  const double _t346 = _t188*_t217;
  const double _t347 = _t135*_t221;
  const double _t348 = _t158*_t221;
  const double _t349 = _t135*_t295;
  const double _t350 = _t222*_t298;
  const double _t351 = _t17*_t232;
  const double _t352 = _t238*sigma_ss;
  const double _t353 = _t13*_t236;
  const double _t354 = _t242 + 0.00039489996248476364*_t351 + 0.0048330047639927225*_t352;
  const double _t355 = 0.051333333333333328*_t125;
  const double _t356 = _t133*_t204;
  const double _t357 = 0.027999999999999997*_t65;
  const double _t358 = _t123*_t65;
  const double _t359 = _t133*_t59;
  const double _t360 = _t259*_t65;
  const double _t361 = _t263*_t82;
  const double _t362 = _t212*_t65;
  const double _t363 = 0.013999999999999999*_t129*_t61;
  const double _t364 = _t163*_t267;
  const double _t365 = _t135*_t364;
  const double _t366 = _t267*_t65;
  const double _t367 = _t13*_t14/xc_powi(n_s, 12);
  const double _t368 = _t7*sigma_ss/xc_powr(n_s, 20, 3);
  const double _t369 = _t24*_t25/xc_powr(n_s, 44, 3);
  const double _t370 = _t17*_t20/xc_powr(n_s, 28, 3);
  const double _t371 = 0.31940740740740736*_t245;
  const double _t372 = 0.0014479665291107998*_t367 + 0.80761053211078837*_t368 + 0.020137519849969678*_t370;
  const double _t373 = 0.055999999999999994*_t61;
  const double _t374 = 0.0070000000000000001*_t97;
  const double _t375 = 0.10266666666666666*_t125;
  const double _t376 = _t344*_t61;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t5)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  const double _t31 = my_piecewise3(_t5, 0, _hc0[0]*_t30);
#if _KMAX >= 1
  const double _t45 = my_piecewise3(_t5, 0, _hc0[0]*_t44);
  const double _t47 = _hc0[2]*_t3;
  const double _t48 = _t46*_t47;
  const double _t49 = (0.1e1 / 0.6e1)*_t48;
  const double _t68 = my_piecewise3(_t5, 0, _hc0[0]*_t67 - _t30*_t49);
#endif
#if _KMAX >= 2
  const double _t88 = my_piecewise3(_t5, 0, _hc0[0]*_t87);
  const double _t105 = my_piecewise3(_t5, 0, _hc0[0]*_t104 - _t44*_t49);
  const double _t108 = _t107*_t47;
  const double _t111 = _hc0[5]*_t110*_t19;
  const double _t112 = _t111*_t6;
  const double _t113 = (0.1e1 / 0.3e1)*_t48;
  const double _t139 = my_piecewise3(_t5, 0, _hc0[0]*_t138 + _t106*_t108 + _t109*_t112 - _t113*_t67);
#endif
#if _KMAX >= 3
  const double _t169 = my_piecewise3(_t5, 0, _hc0[0]*_t168);
  const double _t190 = my_piecewise3(_t5, 0, _hc0[0]*_t189 - _t49*_t87);
  const double _t191 = (0.2e1 / 0.9e1)*_t108;
  const double _t224 = my_piecewise3(_t5, 0, _hc0[0]*_t223 - _t104*_t113 + _t112*_t192 + _t191*_t44);
  const double _t226 = _hc0[9]*_t225/(n_s * n_s * n_s * n_s);
  const double _t227 = _t47/xc_powr(n_s, 10, 3);
  const double _t228 = (0.14e2 / 0.27e2)*_t227;
  const double _t229 = _t111*_t50;
  const double _t230 = (0.1e1 / 0.9e1)*_t229;
  const double _t231 = _hc0[2]*_t4*_t46;
  const double _t270 = my_piecewise3(_t5, 0, _hc0[0]*_t269 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t107*_t2*_t67 + (0.1e1 / 0.12e2)*_hc0[5]*_t110*_t19*_t6*_t67 - _t109*_t226 - _t138*_t231 - _t228*_t30 - _t230*_t30);
#endif

  const double f = my_piecewise3(_t5, 0, _t31*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t5, 0, _t45*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t5, 0, _t31 + _t68*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t5, 0, _t88*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t5, 0, _t105*n_s + _t45);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t5, 0, _t139*n_s + 0.2e1*_t68);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t5, 0, _t169*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t5, 0, _t190*n_s + _t88);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t5, 0, 0.2e1*_t105 + _t224*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t5, 0, 0.3e1*_t139 + _t270*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(-6.7718662544188191e-5*_t140*_t26 + 7.6786103816481829e-9*_t141*_t42 + _t144*_t150*_t280 + _t144*_t22*_t277 + _t147*_t276 + _t149*_t278 + 0.021000000000000001*_t151*_t72 + _t154*_t161*_t286 + _t156*_t279*_t82 + _t156*_t290 + _t156*_t299 + _t160*_t276 - 2.3983358284555928e-11*_t19*_t207*_t271*_t273 + 0.0035000000000000001*_t221*_t291*_t79 + 7.6786103816481829e-9*_t26*_t28 + 2.5239180420712339e-6*_t272*_t273 + _t274*_t275 + _t275*_t284 + _t275*_t294 + _t278*_t288 + _t283*_t75 + _t285*_t287 + _t285*_t77*_t85 + _t286*_t296 + _t293*_t75)));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t5, 0, _t169 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-_t100*_t274 - _t100*_t284 - _t100*_t294 + _t102*_t283 + 0.010500000000000001*_t102*_t287 + _t102*_t293 - _t128*_t159*_t22 + _t137*_t290 + _t137*_t299 + 0.00031602042520621152*_t140*_t300 + _t142*_t66 + _t143*_t174 + _t146*_t180 + _t147*_t308 + _t148*_t307 + _t148*_t316 + _t148*_t321 + _t149*_t252 + _t150*_t296*_t65 + 0.010500000000000001*_t151*_t94 + _t152*_t318 + _t159*_t210 + _t160*_t308 - 0.013999999999999999*_t160*_t317 + _t163*_t291*_t320 - 6.7304481121899573e-6*_t17*_t272/xc_powr(n_s, 43, 3) - 0.0036338876146788986*_t170 + 0.0052500000000000003*_t174*_t178 + _t218*_t279 + _t219*_t281 + _t252*_t288 + _t274*_t98 - 2.047629435106182e-8*_t28*_t300 + _t280*_t312 + _t280*_t314 + _t284*_t98 + _t294*_t98 - _t301*_t72 - _t303*_t72 - _t304*_t306 - _t304*_t311 + _t309*_t310 + _t310*_t315 + _t312*_t80 - 0.027999999999999997*_t313*_t41 + _t314*_t80 - 0.013999999999999999*_t319*_t79 + _t76*(_t172 + 1.4618427906776945e-7*_t300)) - _t168*_t49));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t5, 0, 0.2e1*_t190 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-_t121*_t174 + _t123*_t181 + _t127*_t174*_t9 - _t128*_t66*_t72 + 1.7947861632506554e-5*_t13*_t272/xc_powr(n_s, 46, 3) + _t133*_t145*_t327 + 0.0035000000000000001*_t133*_t287 + _t136*_t176*_t43 - 0.0011286443757364695*_t140*_t323 - _t147*_t200 + _t147*_t206 + _t147*_t328 - _t155*_t213 + _t155*_t336 - _t160*_t200 + _t160*_t206 + _t160*_t328 + _t161*_t346 + _t165*_t350 - _t167*_t213 + _t167*_t336 - _t176*_t208 + _t179*_t198 + 0.0070000000000000001*_t180*_t202 + _t185*_t209 + _t187*_t339 - 0.02287037037037036*_t194 + _t196*_t72 + _t198*_t73 + _t199*_t325 + _t203*_t277 + _t203*_t337 + _t205*_t81 + _t209*_t39*_t78 + _t210*_t307 + _t210*_t316 + _t210*_t321 + _t214*_t345 + _t214*_t348 + _t215*_t78 + _t218*(1.4618427906776945e-7*_t171 + _t216 + 1.7551109443767273e-5*_t55*sigma_ss) + 0.0035000000000000001*_t220*_t36 + _t221*_t346*_t9 + _t268*_t289 + _t277*_t333 + _t280*_t338 - _t302*_t326 - _t306*_t330 + 0.00175*_t310*_t335 - _t311*_t330 - _t313*_t332 - _t317*_t332*_t85 + 0.0070000000000000001*_t318*_t59 - _t319*_t344 + _t320*_t349 + 0.022476267838939849*_t322*_t69 + _t324*_t37 + _t325*_t329 - _t326*_t96 - _t330*_t342 - 0.018666666666666665*_t331*_t41 + _t333*_t337 + 0.034222222222222216*_t334*_t79 + _t339*_t340 + _t340*_t347 + _t343*_t85 + _t76*(-8.5274162789532168e-7*_t323 - _t324)) + (0.1e1 / 0.36e2)*_t112*_t87 - _t113*_t189 + _t191*_t87));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t5, 0, 0.3e1*_t224 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t102*_t207*_t355 + _t102*_t361*_t43 + _t103*_t258 - _t123*_t301 - _t123*_t303 + 0.051333333333333328*_t126*_t94 + _t133*_t217*_t265 + _t133*_t259*_t85 + _t136*_t343 + _t137*_t217*_t364 + _t137*_t221*_t263 + 0.0035715324245527398*_t140*_t353 + 0.00175*_t178*_t244 + _t180*_t251*_t9 - _t198*_t241 + 0.0052500000000000003*_t198*_t250 + _t199*_t240 - _t203*_t248*_t39 - 0.013999999999999999*_t205*_t305 + _t209*_t253 - 0.013999999999999999*_t209*_t257 + _t214*_t364*_t43 + _t215*_t259 - 0.013999999999999999*_t215*_t341 + _t218*(-0.0013180922083616516*_t119*sigma_ss - 7.8979992496952723e-5*_t193 - 5.6849441859688116e-7*_t195 - _t262) + _t219*_t23*_t263 + _t220*_t252 + _t23*_t349*_t366 - _t234*_t247 - _t235 - 4.7860964353350802e-5*_t24*_t272/xc_powr(n_s, 49, 3) + _t240*_t329 + _t244*_t95 - _t245*_t246*_t36 - 0.079851851851851841*_t245*_t39*_t79 - _t248*_t66*_t94 + _t254*_t334 + _t255*_t85 - _t256*_t311 - _t256*_t342 + _t258*_t327*_t77 + _t258*_t86 - _t260*_t317*_t65 - _t261*_t51 + _t264*_t345 + _t264*_t348 + _t267*_t350 + _t268*(7.3092139533884726e-8*_t101 + _t266 + 0.00031217973355933859*_t53*sigma_ss + 1.3163332082825454e-5*_t89) + _t309*_t358 + _t309*_t359 + _t315*_t358 + 0.15226851851851847*_t32*_t352 - _t331*_t357 + 0.0052500000000000003*_t333*_t335 + _t335*_t338 + _t339*_t360 - _t339*_t363 + _t347*_t360 - _t347*_t363 - 0.091968760618416551*_t351*_t69 - _t354*_t37 + _t355*_t36*_t66 + 0.0052500000000000003*_t356*_t94 - _t357*_t59*_t61*_t85 + _t361*_t362 + _t362*_t365 + _t76*(3.6004646511135806e-6*_t353 + _t354)) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t104*_t107*_t2 + (0.1e1 / 0.12e2)*_hc0[5]*_t104*_t110*_t19*_t6 - _t192*_t226 - _t223*_t231 - _t228*_t44 - _t230*_t44));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t5, 0, 0.4e1*_t270 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(2.3486584362139911*_t11*_t368 + 0.10266666666666666*_t123*_t126 + 0.010500000000000001*_t123*_t356 - _t123*_t373*_t66 + 0.20533333333333331*_t125*_t249 + _t129*_t136*_t375 - _t130*_t371 + _t133*_t150*_t263*_t282 + _t133*_t207*_t375 + _t135*_t163*_t366*_t374 - 0.010487196332769094*_t140*_t369 + _t150*_t258*_t335 + _t188*_t263*_t364*_t9 - _t211*_t373*_t59 + _t218*(0.00026326664165650908*_t233 + 1.8002323255567903e-6*_t237 + 0.0048330047639927225*_t239 + 0.28503901133321941*_t245) + 0.4524938271604938*_t22*_t28*_t368 + _t222*_t267*_t297*(_t17*_t216 + 5.850369814589091e-6*_t56 + 0.033316248077908762*_t61 + 2.4364046511294909e-8*_t64) + 0.0070000000000000001*_t244*_t250 - 0.018666666666666665*_t244*_t62 - 0.018666666666666665*_t257*_t258 + _t258*_t374*_t39 + _t264*_t292*_t364 - 0.037333333333333329*_t264*_t341*_t82 + _t268*(-3.9489996248476362e-5*_t115 - 0.00098856915627123891*_t120 - 0.091619682214249099*_t125 - 2.1318540697383045e-7*_t132) + 0.00012762923827560214*_t272*xc_powi(sigma_ss, 5)/xc_powr(n_s, 52, 3) - _t28*_t371*_t59 - 0.055999999999999994*_t305*_t359 - 0.61128086419753069*_t32*_t370 + 0.010500000000000001*_t335*_t358 + 0.014*_t335*_t359 + _t361*_t374*_t65 - _t361*_t376 - _t365*_t376 + 0.30662235247479885*_t367*_t69 + _t37*_t372 + _t76*(-1.2301587557971399e-5*_t369 - _t372)) + (0.1e1 / 0.216e3)*_hc0[14]*_t18*_t30*_t7 + _hc0[9]*_t106*_t225/xc_powi(n_s, 5) + (0.4e1 / 0.3e1)*_t108*_t138 + (0.40e2 / 0.81e2)*_t111*_t116*_t30 + (0.1e1 / 0.6e1)*_t112*_t138 - 0.1e1 / 0.9e1*_t226*_t67 - 0.56e2 / 0.27e2*_t227*_t67 - 0.4e1 / 0.9e1*_t229*_t67 - 0.2e1 / 0.3e1*_t269*_t48 + (0.140e3 / 0.81e2)*_t30*_t47/xc_powr(n_s, 13, 3)));
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