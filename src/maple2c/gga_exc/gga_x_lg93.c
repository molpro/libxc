/*
  Generated from python/gga_exc/gga_x_lg93.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_lg93
*/

#ifndef _GGA_X_LG93_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_LG93_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_LG93_HELPER_BODIES
#include "gga_x_lg93.c"
#undef _GGA_X_LG93_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_LG93_HELPER_BODIES
#include "gga_x_lg93.c"
#undef _GGA_X_LG93_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_LG93_HELPER_BODIES
#include "gga_x_lg93.c"
#undef _GGA_X_LG93_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_LG93_HELPER_BODIES
#include "gga_x_lg93.c"
#undef _GGA_X_LG93_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_LG93_HELPER_BODIES
#include "gga_x_lg93.c"
#undef _GGA_X_LG93_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_lg93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_lg93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_lg93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_lg93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_lg93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_lg93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_lg93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_lg93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_lg93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_lg93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_LG93_HELPER_BODIES)

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
  const double _t5 = xc_powi(sigma_ss, 6);
  const double _t6 = xc_powi(M_PI, -8);
  const double _t7 = _t6/xc_powi(n_s, 16);
  const double _t8 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t9 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t10 = xc_powi(n_s, -8);
  const double _t11 = _t10*_t9;
  const double _t12 = xc_powr(n_s, -8, 3);
  const double _t13 = _t1/(M_PI * M_CBRTPI);
  const double _t14 = _t12*_t13;
  const double _t15 = _t14*sigma_ss;
  const double _t16 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t17 = _t1/(M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI);
  const double _t18 = _t17/xc_powr(n_s, 32, 3);
  const double _t19 = xc_powi(sigma_ss, 5);
  const double _t20 = xc_powr(0.6e1, 2, 3);
  const double _t21 = _t20/(M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t22 = _t21/xc_powr(n_s, 40, 3);
  const double _t23 = (sigma_ss * sigma_ss);
  const double _t24 = xc_powr(n_s, -16, 3);
  const double _t25 = _t20/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t26 = _t24*_t25;
  const double _t27 = 0.0097296006944444444*_t11*_t8 + 0.20588079936467257*_t15 + 0.00021916594328703703*_t16*_t18 + 0.0011831024546682097*_t19*_t22 + 0.051718749999999994*_t23*_t26 + 1.0538736979166666e-5*_t5*_t7 + 0.1e1;
  const double _t28 = pow(_t27, 0.024974);
  const double _t29 = 4.1666666666666668e-10*_t15 + 0.1e1;
  const double _t30 = (0.1e1 / _t29);
#if _KMAX >= 1
  const double _t33 = (0.1e1 / (_t29 * _t29));
  const double _t36 = 4.1666666666666668e-10*_t14;
  const double _t37 = _t19*_t7;
  const double _t38 = _t11*_t23;
  const double _t39 = 0.0025832481249999997*_t26;
  const double _t40 = _t18*_t8;
  const double _t41 = _t16*_t22;
  const double _t42 = 0.0051416670833333324*_t14 + 1.5791665039062501e-6*_t37 + 0.00072896114322916668*_t38 + _t39*sigma_ss + 2.1893801070601849e-5*_t40 + 0.00014773400351441934*_t41;
  const double _t43 = pow(_t27, -0.97502599999999995);
  const double _t48 = _t30/xc_powr(n_s, 4, 3);
  const double _t49 = (0.1e1 / 0.6e1)*_t48;
  const double _t50 = xc_powr(n_s, -11, 3);
  const double _t51 = _t13*_t50;
  const double _t52 = _t51*sigma_ss;
  const double _t54 = _t6/xc_powi(n_s, 17);
  const double _t55 = _t5*_t54;
  const double _t56 = xc_powi(n_s, -9);
  const double _t57 = _t56*_t9;
  const double _t58 = _t57*_t8;
  const double _t59 = 0.013711112222222219*_t51;
  const double _t60 = _t17/xc_powr(n_s, 35, 3);
  const double _t61 = _t16*_t60;
  const double _t62 = _t21/xc_powr(n_s, 43, 3);
  const double _t63 = _t19*_t62;
  const double _t64 = xc_powr(n_s, -19, 3);
  const double _t65 = _t25*_t64;
  const double _t66 = _t23*_t65;
  const double _t67 = -4.2111106770833335e-6*_t55 - 0.0019438963819444445*_t58 - _t59*sigma_ss - 5.8383469521604931e-5*_t61 - 0.00039395734270511825*_t63 - 0.0068886616666666645*_t66;
#endif
#if _KMAX >= 2
  const double _t69 = (0.1e1 / (_t29 * _t29 * _t29));
  const double _t71 = 3.4722222222222222e-19*_t26;
  const double _t72 = 0.0014579222864583334*_t11;
  const double _t73 = _t16*_t7;
  const double _t74 = _t18*_t23;
  const double _t75 = _t22*_t8;
  const double _t76 = _t39 + _t72*sigma_ss + 7.8958325195312504e-6*_t73 + 6.5681403211805548e-5*_t74 + 0.00059093601405767735*_t75;
  const double _t77 = _t42*_t43;
  const double _t78 = _t33*_t77;
  const double _t81 = pow(_t27, -1.9750259999999999);
  const double _t83 = 0.10085425187499998*_t26;
  const double _t84 = -0.20073913228133922*_t14 - 6.1653255371093752e-5*_t37 - 0.028459840940104165*_t38 - 0.00085476997207754619*_t40 - 0.0057677782698266284*_t41 - _t83*sigma_ss;
  const double _t85 = _t42*_t84;
  const double _t87 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t88 = 6.9444444444444442e-11*_t33;
  const double _t89 = _t20/(M_PI * M_CBRTPI * M_CBRTPI);
  const double _t91 = _t65*sigma_ss;
  const double _t92 = _t19*_t54;
  const double _t93 = _t23*_t57;
  const double _t94 = 0.013777323333333329*_t65;
  const double _t95 = _t60*_t8;
  const double _t96 = _t16*_t62;
  const double _t97 = -_t59 - 2.5266664062500001e-5*_t92 - 0.0058316891458333334*_t93 - _t94*sigma_ss - 0.00023353387808641973*_t95 - 0.0019697867135255913*_t96;
  const double _t99 = _t2*_t49;
  const double _t101 = 1.1111111111111111e-9*_t52;
  const double _t102 = _t43*_t67;
  const double _t103 = _t102*_t33;
  const double _t107 = xc_powr(n_s, -7, 3);
  const double _t108 = (0.2e1 / 0.9e1)*_t30;
  const double _t109 = _t107*_t108;
  const double _t111 = _t20/(M_CBRTPI * M_CBRTPI);
  const double _t113 = (0.1e1 / 0.36e2)*_t30;
  const double _t114 = _t113*_t12;
  const double _t115 = xc_powr(n_s, -14, 3);
  const double _t116 = _t115*_t13;
  const double _t117 = _t116*sigma_ss;
  const double _t119 = xc_powi(n_s, -5);
  const double _t122 = 3.7037037037037036e-10*sigma_ss;
  const double _t123 = xc_powr(n_s, -22, 3);
  const double _t124 = _t123*_t25;
  const double _t125 = _t124*_t23;
  const double _t126 = 2.4691358024691357e-18*_t125;
  const double _t127 = _t6/xc_powi(n_s, 18);
  const double _t128 = _t127*_t5;
  const double _t129 = xc_powi(n_s, -10);
  const double _t130 = _t129*_t9;
  const double _t131 = _t130*_t8;
  const double _t132 = 0.050274078148148132*_t116;
  const double _t133 = _t17/xc_powr(n_s, 38, 3);
  const double _t134 = _t133*_t16;
  const double _t135 = _t21/xc_powr(n_s, 46, 3);
  const double _t136 = _t135*_t19;
  const double _t137 = 0.043628190555555536*_t125 + 7.158888151041667e-5*_t128 + 0.017495067437500001*_t131 + _t132*sigma_ss + 0.00068114047775205753*_t134 + 0.0056467219121066952*_t136;
  const double _t140 = (0.1e1 / 0.3e1)*_t48;
  const double _t141 = 2.2222222222222221e-9*_t52;
  const double _t142 = 0.53530435275023791*_t51;
  const double _t143 = _t142*sigma_ss + 0.00016440868098958333*_t55 + 0.075892909173611106*_t58 + 0.0022793865922067897*_t61 + 0.015380742052871011*_t63 + 0.26894467166666658*_t66;
#endif
#if _KMAX >= 3
  const double _t145 = (0.1e1 / (_t29 * _t29 * _t29 * _t29));
  const double _t147 = 2.6041666666666665e-27*_t11;
  const double _t148 = _t7*_t8;
  const double _t149 = 0.0001313628064236111*_t18;
  const double _t150 = _t22*_t23;
  const double _t151 = 3.1583330078125001e-5*_t148 + _t149*sigma_ss + 0.0017728080421730321*_t150 + _t72;
  const double _t152 = _t43*_t76;
  const double _t158 = 0.05691968188020833*_t11;
  const double _t159 = -_t158*sigma_ss - 0.00030826627685546875*_t73 - 0.0025643099162326387*_t74 - 0.023071113079306513*_t75 - _t83;
  const double _t163 = _t81*_t85;
  const double _t164 = 0.20429175187499998*_t26;
  const double _t165 = -0.40661993164601179*_t14 - _t164*sigma_ss - 0.00012488567724609374*_t37 - 0.057648643023437501*_t38 - 0.0017314337452256944*_t40 - 0.011683290543167676*_t41;
  const double _t166 = pow(_t27, -2.9750259999999997);
  const double _t170 = xc_powr(n_s, -20, 3);
  const double _t171 = _t69/(M_PI * M_PI * M_PI);
  const double _t173 = _t57*sigma_ss;
  const double _t174 = 0.011663378291666667*_t57;
  const double _t175 = _t16*_t54;
  const double _t176 = _t23*_t60;
  const double _t177 = _t62*_t8;
  const double _t178 = -_t174*sigma_ss - 0.00012633332031250001*_t175 - 0.00070060163425925918*_t176 - 0.0078791468541023653*_t177 - _t94;
  const double _t182 = 2.2222222222222221e-9*_t51;
  const double _t183 = _t43*_t97;
  const double _t185 = _t33*_t89;
  const double _t186 = _t185*_t87;
  const double _t187 = 1.3888888888888888e-10*_t186;
  const double _t189 = 1.851851851851852e-18*_t91;
  const double _t193 = _t67*_t81;
  const double _t194 = _t193*_t84;
  const double _t197 = (0.1e1 / (M_PI * M_PI));
  const double _t199 = xc_powr(n_s, -23, 3);
  const double _t201 = _t130*_t23;
  const double _t202 = _t124*sigma_ss;
  const double _t203 = _t127*_t19;
  const double _t204 = 0.087256381111111073*_t124;
  const double _t205 = _t133*_t8;
  const double _t206 = _t135*_t16;
  const double _t207 = _t132 + 0.052485202312500007*_t201 + 0.00042953328906250002*_t203 + _t204*sigma_ss + 0.0027245619110082301*_t205 + 0.028233609560533477*_t206;
  const double _t213 = 4.0740740740740737e-9*_t117;
  const double _t215 = _t119*_t185;
  const double _t217 = _t137*_t43;
  const double _t222 = 0.53788934333333316*_t65;
  const double _t223 = _t142 + _t222*sigma_ss + 0.00098645208593750003*_t92 + 0.22767872752083332*_t93 + 0.0091175463688271587*_t95 + 0.076903710264355052*_t96;
  const double _t224 = _t143*_t193;
  const double _t226 = (0.1e1 / M_PI);
  const double _t229 = _t113*_t87;
  const double _t232 = 5.5555555555555553e-10*sigma_ss;
  const double _t233 = _t9/xc_powi(n_s, 11);
  const double _t234 = _t233*_t8;
  const double _t235 = 4.9382716049382711e-26*_t234;
  const double _t236 = xc_powr(n_s, -26, 3);
  const double _t238 = 7.4074074074074063e-18*_t23;
  const double _t240 = xc_powr(n_s, -10, 3);
  const double _t241 = (0.14e2 / 0.27e2)*_t240;
  const double _t242 = (0.1e1 / 0.9e1)*_t30;
  const double _t243 = _t242*_t50;
  const double _t244 = _t13/xc_powr(n_s, 17, 3);
  const double _t245 = _t244*sigma_ss;
  const double _t247 = xc_powi(n_s, -6);
  const double _t249 = 2.7777777777777776e-9*sigma_ss;
  const double _t250 = _t25/xc_powr(n_s, 25, 3);
  const double _t251 = _t23*_t250;
  const double _t252 = 2.7160493827160492e-17*_t251;
  const double _t253 = _t6/xc_powi(n_s, 19);
  const double _t254 = _t253*_t5;
  const double _t255 = 0.23461236469135796*_t244;
  const double _t256 = _t17/xc_powr(n_s, 41, 3);
  const double _t257 = _t16*_t256;
  const double _t258 = _t21/xc_powr(n_s, 49, 3);
  const double _t259 = _t19*_t258;
  const double _t260 = -0.174950674375*_t234 - 0.31994006407407394*_t251 - 0.0012885998671875001*_t254 - _t255*sigma_ss - 0.0086277793848593947*_t257 - 0.086583069318969336*_t259;
  const double _t262 = (0.2e1 / 0.3e1)*_t107;
  const double _t264 = _t3*_t48;
  const double _t266 = (0.1e1 / 0.12e2)*_t12;
  const double _t271 = 1.1111111111111111e-9*sigma_ss;
  const double _t272 = 7.4074074074074063e-18*_t125;
  const double _t273 = 1.9627826267508723*_t116;
  const double _t274 = -1.7033162538888882*_t125 - 0.0027949475768229166*_t128 - 0.68303618256249998*_t131 - 0.026592843575745879*_t134 - 0.22045730275781783*_t136 - _t273*sigma_ss;
  const double _t277 = 1.084319817722698*_t51;
  const double _t278 = _t277*sigma_ss + 0.00033302847265624999*_t55 + 0.15372971472916666*_t58 + 0.0046171566539351845*_t61 + 0.031155441448447143*_t63 + 0.54477800499999984*_t66;
#endif
#if _KMAX >= 4
  const double _t283 = _t151*_t43;
  const double _t288 = -0.001233065107421875*_t148 - 0.069213339237919544*_t150 - _t158 - 0.0051286198324652773*_t18*sigma_ss;
  const double _t290 = 0.3e1*_t159;
  const double _t291 = _t159*_t42*_t81;
  const double _t292 = _t81*_t84;
  const double _t293 = _t292*_t76;
  const double _t294 = -0.115297286046875*_t11*sigma_ss - _t164 - 0.00062442838623046873*_t73 - 0.005194301235677083*_t74 - 0.046733162172670706*_t75;
  const double _t295 = 0.2e1*_t159;
  const double _t298 = _t165*_t85;
  const double _t299 = _t166*_t298;
  const double _t302 = xc_powr(n_s, -28, 3);
  const double _t304 = _t60*sigma_ss;
  const double _t307 = _t178*_t43;
  const double _t311 = 2.7777777777777781e-18*_t91;
  const double _t312 = _t170*_t171;
  const double _t315 = _t159*_t193;
  const double _t316 = _t292*_t97;
  const double _t318 = _t165*_t166*_t67;
  const double _t319 = _t318*_t84;
  const double _t322 = _t130*sigma_ss;
  const double _t324 = _t133*_t23;
  const double _t332 = _t199*sigma_ss;
  const double _t334 = _t207*_t43;
  const double _t337 = 3.7037037037037039e-18*_t91;
  const double _t341 = _t137*_t292;
  const double _t342 = _t143*_t97;
  const double _t343 = _t342*_t81;
  const double _t344 = _t193*_t223;
  const double _t347 = _t143*_t318;
  const double _t349 = _t23*_t233;
  const double _t350 = _t250*sigma_ss;
  const double _t351 = _t256*_t8;
  const double _t354 = _t183*_t30;
  const double _t360 = _t185*_t247;
  const double _t362 = _t260*_t43;
  const double _t364 = 2.7777777777777778e-18*_t91;
  const double _t365 = _t194*_t30;
  const double _t366 = _t193*_t274;
  const double _t367 = _t137*_t143;
  const double _t368 = _t367*_t81;
  const double _t372 = _t143*_t278;
  const double _t373 = _t372*_t67;
  const double _t374 = _t166*_t373;
  const double _t375 = _t8*_t9/xc_powi(n_s, 12);
  const double _t376 = _t13*_t170*sigma_ss;
  const double _t377 = _t16*_t17/xc_powr(n_s, 44, 3);
  const double _t378 = _t23*_t25*_t302;
  const double _t379 = 2.2222222222222221e-9*sigma_ss;
  const double _t380 = _t217*_t30;
  const double _t384 = 1.4814814814814813e-17*_t125;
  const double _t385 = _t224*_t30;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t4)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t3/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  const double _t31 = _hc0[0]*_t30;
  const double _t32 = my_piecewise3(_t4, 0, _t28*_t31);
#if _KMAX >= 1
  const double _t34 = _hc0[0]*_t28;
  const double _t35 = _t33*_t34;
  const double _t44 = _t31*_t43;
  const double _t45 = my_piecewise3(_t4, 0, -_t35*_t36 + _t42*_t44);
  const double _t46 = _hc0[2]*_t28;
  const double _t47 = _t2*_t46;
  const double _t53 = 1.1111111111111111e-9*_t35;
  const double _t68 = my_piecewise3(_t4, 0, _t44*_t67 - _t47*_t49 + _t52*_t53);
#endif
#if _KMAX >= 2
  const double _t70 = _t34*_t69;
  const double _t79 = _hc0[0]*_t14;
  const double _t80 = 8.3333333333333335e-10*_t79;
  const double _t82 = _t31*_t81;
  const double _t86 = my_piecewise3(_t4, 0, _t44*_t76 + _t70*_t71 - _t78*_t80 + _t82*_t85);
  const double _t90 = _t46*_t89;
  const double _t98 = _hc0[2]*_t77;
  const double _t100 = _hc0[0]*_t78;
  const double _t104 = _hc0[0]*_t103;
  const double _t105 = _t67*_t82;
  const double _t106 = my_piecewise3(_t4, 0, _t100*_t101 - _t104*_t36 + _t105*_t84 + _t44*_t97 + _t51*_t53 - 9.2592592592592599e-19*_t70*_t91 + _t87*_t88*_t90 - _t98*_t99);
  const double _t110 = _hc0[5]*_t28;
  const double _t112 = _t110*_t111;
  const double _t118 = 4.0740740740740737e-9*_t35;
  const double _t120 = _t33*_t90;
  const double _t121 = _t119*_t120;
  const double _t138 = _hc0[2]*_t102;
  const double _t139 = _t138*_t2;
  const double _t144 = my_piecewise3(_t4, 0, _t104*_t141 + _t105*_t143 + _t109*_t47 + _t112*_t114 - _t117*_t118 - _t121*_t122 + _t126*_t70 + _t137*_t44 - _t139*_t140);
#endif
#if _KMAX >= 3
  const double _t146 = _t145*_t34;
  const double _t153 = _t33*_t79;
  const double _t154 = 1.25e-9*_t153;
  const double _t155 = _hc0[0]*_t69;
  const double _t156 = _t155*_t26;
  const double _t157 = 1.0416666666666667e-18*_t156;
  const double _t160 = _t42*_t82;
  const double _t161 = _t82*_t84;
  const double _t162 = 0.2e1*_t161;
  const double _t167 = _t166*_t31;
  const double _t168 = _t165*_t167;
  const double _t169 = my_piecewise3(_t4, 0, -_t146*_t147 + _t151*_t44 - _t152*_t154 - _t154*_t163 + _t157*_t77 + _t159*_t160 + _t162*_t76 + _t168*_t85);
  const double _t172 = _t171*_t46;
  const double _t179 = _hc0[2]*_t99;
  const double _t180 = _hc0[0]*_t33;
  const double _t181 = _t101*_t180;
  const double _t184 = _t33*_t80;
  const double _t188 = _t155*_t77;
  const double _t190 = _t155*_t71;
  const double _t191 = _t82*_t97;
  const double _t192 = 0.2e1*_t191;
  const double _t195 = _t168*_t67;
  const double _t196 = my_piecewise3(_t4, 0, _t100*_t182 + _t102*_t190 + _t105*_t159 + 6.9444444444444458e-27*_t146*_t173 - _t152*_t179 + _t152*_t181 - _t163*_t179 + _t163*_t181 - 3.4722222222222227e-19*_t170*_t172 + _t178*_t44 - _t183*_t184 - _t184*_t194 + _t187*_t98 - _t188*_t189 + _t192*_t84 + _t195*_t84 - 1.851851851851852e-18*_t65*_t70);
  const double _t198 = _t110*_t197;
  const double _t200 = _t172*_t199;
  const double _t208 = _t2*_t98;
  const double _t209 = _hc0[2]*_t2;
  const double _t210 = _t140*_t209;
  const double _t211 = _hc0[5]*_t111;
  const double _t212 = _t114*_t211;
  const double _t214 = _t141*_t180;
  const double _t216 = _t215*_t98;
  const double _t218 = _t180*_t36;
  const double _t219 = _t102*_t155;
  const double _t220 = _t137*_t82;
  const double _t221 = _t143*_t82;
  const double _t225 = my_piecewise3(_t4, 0, -_t100*_t213 + _t104*_t182 + _t105*_t223 + _t109*_t208 - _t116*_t118 - 4.6296296296296294e-10*_t121 - _t122*_t216 + _t126*_t188 + _t138*_t187 + _t143*_t195 - 1.851851851851852e-26*_t146*_t201 - _t183*_t210 + _t183*_t214 - _t189*_t219 - _t194*_t210 + _t194*_t214 - _t198*_t24*_t88 + 1.8518518518518516e-18*_t200*sigma_ss + 8.3333333333333321e-18*_t202*_t70 + _t207*_t44 + _t212*_t77 - _t217*_t218 - _t218*_t224 + _t220*_t84 + _t221*_t97);
  const double _t227 = _hc0[9]*_t28;
  const double _t228 = _t226*_t227;
  const double _t230 = _t198*_t33;
  const double _t231 = _t230*_t64;
  const double _t237 = _t172*_t236;
  const double _t239 = _t30*_t47;
  const double _t246 = 1.9012345679012344e-8*_t35;
  const double _t248 = _t120*_t247;
  const double _t261 = _t139*_t30;
  const double _t263 = _hc0[2]*_t217;
  const double _t265 = _t102*_t211*_t30;
  const double _t267 = 1.222222222222222e-8*_t104;
  const double _t268 = _t180*_t52;
  const double _t269 = 3.3333333333333334e-9*_t268;
  const double _t270 = _t138*_t215;
  const double _t275 = 0.2e1*_t220;
  const double _t276 = _hc0[2]*_t264;
  const double _t279 = _t167*_t67;
  const double _t280 = _t143*_t279;
  const double _t281 = my_piecewise3(_t4, 0, _t105*_t274 - _t112*_t243 - _t117*_t267 + _t143*_t275 + _t146*_t235 + _t217*_t269 + _t219*_t272 + _t224*_t269 - _t224*_t276 - _t228*_t229 + _t231*_t232 - _t237*_t238 - _t239*_t241 + _t245*_t246 + _t248*_t249 - _t252*_t70 + _t260*_t44 + _t261*_t262 - _t263*_t264 + _t265*_t266 - _t270*_t271 + _t278*_t280);
#endif
#if _KMAX >= 4
  const double _t282 = _t34/xc_powi(_t29, 5);
  const double _t284 = 1.6666666666666667e-9*_t153;
  const double _t285 = 2.0833333333333334e-18*_t156;
  const double _t286 = _hc0[0]*_t145;
  const double _t287 = _t286*_t77;
  const double _t289 = 0.3e1*_t161;
  const double _t296 = _t168*_t84;
  const double _t297 = 0.3e1*_t296;
  const double _t300 = pow(_t27, -3.9750259999999997)*_t31;
  const double _t301 = _t300*(-0.61250073101068436*_t14 - 0.30772925187499994*_t26*sigma_ss - 0.00018811809912109374*_t37 - 0.086837445106770828*_t38 - 0.0026080975183738423*_t40 - 0.017598802816508722*_t41);
  const double _t303 = _t1*_t145*_t46/(M_PI * M_PI * M_PI * M_PI * M_CBRTPI);
  const double _t305 = _t180*_t51;
  const double _t306 = 3.3333333333333334e-9*_t305;
  const double _t308 = _hc0[2]*_t186;
  const double _t309 = 2.0833333333333334e-10*_t308;
  const double _t310 = _t152*_t155;
  const double _t313 = _t102*_t286;
  const double _t314 = _t155*_t65;
  const double _t317 = _t155*_t163;
  const double _t320 = _t301*_t67;
  const double _t321 = _t165*_t320;
  const double _t323 = _t1*_t110*_t69/(M_PI * M_PI * M_PI * M_CBRTPI);
  const double _t325 = _t109*_t209;
  const double _t326 = _t180*_t213;
  const double _t327 = _hc0[2]*_t215;
  const double _t328 = _t122*_t327;
  const double _t329 = _hc0[5]*_t197;
  const double _t330 = _t24*_t329;
  const double _t331 = _t171*_t98;
  const double _t333 = 4.4444444444444443e-9*_t305;
  const double _t335 = 2.7777777777777777e-10*_t308;
  const double _t336 = _t155*_t183;
  const double _t338 = _t209*_t48;
  const double _t339 = (0.2e1 / 0.3e1)*_t338;
  const double _t340 = 4.4444444444444443e-9*_t268;
  const double _t345 = _t155*_t194;
  const double _t346 = 0.2e1*_t168;
  const double _t348 = _t1*_t227*_t33/(M_PI * M_PI * M_CBRTPI);
  const double _t352 = _hc0[9]*_t226;
  const double _t353 = _t329*_t64;
  const double _t355 = _t209*_t262;
  const double _t356 = _t211*_t266;
  const double _t357 = _t138*_t171;
  const double _t358 = _t117*_t180;
  const double _t359 = 1.222222222222222e-8*_t358;
  const double _t361 = _t271*_t327;
  const double _t363 = _t155*_t217;
  const double _t369 = _t155*_t224;
  const double _t370 = _t167*_t278;
  const double _t371 = _t278*_t279;
  const double _t381 = (0.4e1 / 0.3e1)*_t107*_t209;
  const double _t382 = (0.1e1 / 0.6e1)*_t12*_t211;
  const double _t383 = 2.4444444444444441e-8*_t358;
#endif

  const double f = my_piecewise3(_t4, 0, _t32*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t4, 0, _t45*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t4, 0, _t32 + _t68*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t4, 0, _t86*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t4, 0, _t106*n_s + _t45);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t4, 0, _t144*n_s + 0.2e1*_t68);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t4, 0, _t169*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t4, 0, _t196*n_s + _t86);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t4, 0, 0.2e1*_t106 + _t225*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t4, 0, 0.3e1*_t144 + _t281*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t4, 0, n_s*my_piecewise3(_t4, 0, -1.0416666666666667e-26*_t11*_t287 + _t151*_t289 + _t152*_t285 - 3.3333333333333334e-9*_t153*_t293 + _t160*_t288 + _t163*_t285 + _t167*_t294*_t85 + _t168*_t295*_t42 + 4.3402777777777773e-36*_t18*_t282 - _t283*_t284 - _t284*_t291 - _t284*_t299 + _t290*_t76*_t82 + _t297*_t76 + _t298*_t301 + _t44*(_t149 + 0.0035456160843460641*_t22*sigma_ss + 9.4749990234375004e-5*_t23*_t7)));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t4, 0, _t169 + n_s*my_piecewise3(_t4, 0, _t105*_t288 + 2.0833333333333337e-26*_t146*_t57 - _t147*_t313 + _t152*_t306 + _t152*_t309 - 2.5000000000000001e-9*_t153*_t316 - _t154*_t307 - _t154*_t315 - _t154*_t319 + _t157*_t183 + _t157*_t194 + _t163*_t306 + _t163*_t309 + 2.0833333333333337e-26*_t173*_t287 + _t178*_t289 - _t179*_t283 - _t179*_t291 - _t179*_t299 + _t181*_t283 + _t181*_t291 + _t181*_t299 + _t191*_t290 + _t195*_t295 - _t210*_t293 + _t214*_t293 + _t279*_t294*_t84 - 1.1574074074074077e-35*_t282*_t304 + _t297*_t97 + 4.3402777777777786e-28*_t302*_t303 - _t310*_t311 - _t311*_t317 - 1.0416666666666669e-18*_t312*_t98 - 5.5555555555555563e-18*_t314*_t77 + _t321*_t84 + _t44*(-_t174 - 0.023637440562307096*_t23*_t62 - 0.0014012032685185184*_t304 - 0.00050533328125000002*_t54*_t8)));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t4, 0, 0.2e1*_t196 + n_s*my_piecewise3(_t4, 0, 5.7870370370370374e-20*_t10*_t323 - 8.1481481481481474e-9*_t100*_t116 - 3.7037037037037039e-18*_t102*_t314 + _t105*(0.45535745504166664*_t173 + 0.0049322604296874999*_t175 + 0.027352639106481474*_t176 + 0.30761484105742021*_t177 + _t222) + 1.1728395061728394e-17*_t124*_t70 + _t126*_t310 + _t126*_t317 + _t137*_t296 - 6.9444444444444454e-19*_t138*_t312 + _t143*_t321 - 9.9537037037037036e-26*_t146*_t322 + _t152*_t212 + _t152*_t325 - _t152*_t326 - _t152*_t328 + _t159*_t220 + _t162*_t207 + _t163*_t212 + _t163*_t325 - _t163*_t326 - _t163*_t328 + 1.3888888888888892e-26*_t173*_t313 + _t178*_t221 + _t183*_t333 + _t183*_t335 - _t184*_t334 - _t184*_t341 - _t184*_t343 - _t184*_t344 - _t184*_t347 + 1.6666666666666664e-17*_t188*_t202 + _t190*_t217 + _t190*_t224 + _t192*_t223 + _t194*_t333 + _t194*_t335 + 0.2e1*_t195*_t223 + 4.1666666666666661e-18*_t200 - 3.7037037037037041e-26*_t201*_t287 - _t210*_t307 - _t210*_t315 - _t210*_t319 + _t214*_t307 + _t214*_t315 + _t214*_t319 - 9.2592592592592589e-10*_t216 + _t280*_t294 + 3.0864197530864199e-35*_t282*_t324 - 2.3148148148148147e-27*_t303*sigma_ss/xc_powr(n_s, 31, 3) - _t316*_t339 + _t316*_t340 - 1.3888888888888888e-10*_t330*_t78 + 3.7037037037037032e-18*_t331*_t332 - _t336*_t337 - _t337*_t345 + _t342*_t346 + _t44*(0.0021476664453124999*_t127*_t16 + 0.11293443824213391*_t135*_t8 + _t204 + 0.10497040462500001*_t322 + 0.0081736857330246895*_t324)));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t4, 0, 0.3e1*_t225 + n_s*my_piecewise3(_t4, 0, 1.9012345679012344e-8*_t100*_t245 - 2.0833333333333334e-10*_t103*_t330 + _t105*(-2.0491085476875002*_t201 - 3.4066325077777764*_t202 - 0.016769685460937499*_t203 - 0.10637137430298352*_t205 - 1.1022865137890892*_t206 - _t273) - _t116*_t267 + 3.5185185185185185e-25*_t146*_t349 + _t161*_t260 + 1.1574074074074074e-11*_t170*_t348 - _t183*_t359 - _t183*_t361 - _t184*_t368 + 2.0833333333333334e-10*_t186*_t263 - _t188*_t252 + _t191*_t274 - _t194*_t359 - _t194*_t361 + _t195*_t274 - 5.5555555555555555e-26*_t201*_t313 + 2.4999999999999996e-17*_t202*_t219 + 0.2e1*_t207*_t221 - _t208*_t241*_t30 - _t211*_t243*_t77 + _t217*_t306 - _t218*_t362 - _t218*_t366 - _t218*_t374 + _t223*_t275 + _t223*_t371 + _t224*_t306 + _t224*_t309 - _t229*_t352*_t77 + 9.2592592592592587e-27*_t23*_t303/xc_powr(n_s, 34, 3) + 8.3333333333333335e-10*_t231 + _t232*_t353*_t78 + _t235*_t287 - _t236*_t238*_t331 - 2.8703703703703703e-17*_t237*sigma_ss + _t244*_t246 + 2.9938271604938268e-9*_t248 + _t249*_t360*_t98 + _t269*_t334 + _t269*_t341 + _t269*_t343 + _t269*_t344 + _t269*_t347 - 1.3888888888888888e-9*_t270 + _t272*_t336 + _t272*_t345 - _t276*_t334 - _t276*_t341 - _t276*_t343 - _t276*_t344 - _t276*_t347 + _t280*(_t277 + 1.0895560099999997*_t91 + 0.0019981708359374998*_t92 + 0.46118914418750001*_t93 + 0.018468626615740738*_t95 + 0.1557772072422357*_t96) - 8.2304526748971186e-35*_t282*_t351 + _t320*_t372 - 4.6296296296296299e-19*_t323*_t56*sigma_ss + 5.5555555555555563e-18*_t332*_t357 + _t342*_t370 + _t346*_t367 - 7.0164609053497937e-17*_t350*_t70 + _t354*_t355 + _t354*_t356 + _t355*_t365 + _t356*_t365 - _t363*_t364 - _t364*_t369 + _t44*(-0.43291534659484665*_t16*_t258 - 0.0077315992031249999*_t19*_t253 - _t255 - 0.52485202312500001*_t349 - 0.63988012814814788*_t350 - 0.034511117539437579*_t351)));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t4, 0, 0.4e1*_t281 + n_s*my_piecewise3(_t4, 0, (0.1e1 / 0.216e3)*_hc0[14]*_t13*_t24*_t28*_t30 - _t102*_t242*_t352*_t87 + _t103*_t353*_t379 + 7.6049382716049378e-8*_t104*_t245 + _t105*(6.8303618256249994*_t234 + 9.1596522581707376*_t245 + 12.490985861851847*_t251 + 0.050309056382812495*_t254 + 0.33684268529278111*_t257 + 3.3803453089532067*_t259) + _t108*_t119*_t228 + (0.40e2 / 0.81e2)*_t112*_t115*_t30 - 2.0411522633744854e-8*_t120*sigma_ss/xc_powi(n_s, 7) - 7.0370370370370365e-9*_t123*_t230*sigma_ss + 2.4691358024691357e-18*_t129*_t23*_t323 + 1.111111111111111e-8*_t138*_t360*sigma_ss - 1.0864197530864197e-24*_t146*_t375 + 1.2839506172839504e-16*_t172*_t23/xc_powr(n_s, 29, 3) - _t215*_t263*_t379 - _t217*_t383 - 1.0864197530864196e-16*_t219*_t251 + 0.3e1*_t220*_t274 + 0.3e1*_t221*_t260 - _t224*_t327*_t379 - _t224*_t383 - 2.9629629629629625e-17*_t23*_t236*_t357 + 1.9753086419753084e-25*_t234*_t313 + (0.140e3 / 0.81e2)*_t239/xc_powr(n_s, 13, 3) - 0.56e2 / 0.27e2*_t240*_t261 - 0.4e1 / 0.9e1*_t265*_t50 + 8.8888888888888885e-9*_t268*_t368 + 0.2e1*_t274*_t371 + _t280*(-3.9758393316498926*_t117 - 3.4502606983333322*_t125 - 0.0056614840351562499*_t128 - 1.3835674325625*_t131 - 0.053866827629243816*_t134 - 0.4465613274277424*_t136) + 2.194787379972565e-34*_t282*_t377 + _t300*_t373*(1.6333352826951579*_t52 + 0.00050164826432291657*_t55 + 0.23156652028472219*_t58 + 0.0069549267156635789*_t61 + 0.04693014084402327*_t63 + 0.820611338333333*_t66) - 3.2921810699588474e-26*_t303*_t8/xc_powr(n_s, 37, 3) - 1.2345679012345679e-10*_t332*_t348 - 0.4e1 / 0.3e1*_t338*_t368 - _t339*_t362 - _t339*_t366 - _t339*_t374 + _t340*_t362 + _t340*_t366 + _t340*_t374 - 1.0773662551440329e-7*_t35*_t376 + _t363*_t384 + 0.3e1*_t367*_t370 + _t369*_t384 + 2.6858710562414268e-16*_t378*_t70 + _t380*_t381 + _t380*_t382 + _t381*_t385 + _t382*_t385 + _t44*(1.4141901322098325*_t19*_t21/xc_powr(n_s, 52, 3) + 1.924457418125*_t375 + 1.329470066584362*_t376 + 0.11791298492641172*_t377 + 2.666167200617283*_t378 + 0.024483397476562502*_t5*_t6/xc_powi(n_s, 20))));
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