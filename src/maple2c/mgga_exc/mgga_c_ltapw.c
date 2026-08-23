/*
  Generated from python/mgga_exc/mgga_c_ltapw.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_c_ltapw
*/

#ifndef _MGGA_C_LTAPW_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_C_LTAPW_KERNEL_BODY
#define _KMAX 0
#define _MGGA_C_LTAPW_HELPER_BODIES
#include "mgga_c_ltapw.c"
#undef _MGGA_C_LTAPW_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_C_LTAPW_HELPER_BODIES
#include "mgga_c_ltapw.c"
#undef _MGGA_C_LTAPW_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_C_LTAPW_HELPER_BODIES
#include "mgga_c_ltapw.c"
#undef _MGGA_C_LTAPW_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_C_LTAPW_HELPER_BODIES
#include "mgga_c_ltapw.c"
#undef _MGGA_C_LTAPW_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_C_LTAPW_HELPER_BODIES
#include "mgga_c_ltapw.c"
#undef _MGGA_C_LTAPW_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_c_ltapw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_c_ltapw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_c_ltapw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_c_ltapw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_c_ltapw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_c_ltapw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_c_ltapw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_c_ltapw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_c_ltapw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_c_ltapw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_C_LTAPW_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_zeta_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = (0.1e1 / (-0.2e1 + 0.2e1*M_CBRT2));
  const double _t2 = z + 0.1e1 <= p->zeta_threshold;
  const double _t3 = xc_powr(p->zeta_threshold, 4, 3) - 0.1e1;
  const double _t4 = p->zeta_threshold - 0.1e1;
  const double _t5 = z > _t4;
  const double _t6 = my_piecewise3(_t5, z, _t4);
  const double _t7 = xc_expm1((0.4e1 / 0.3e1)*xc_log1p(_t6));
  const double _t8 = 0.1e1 - z <= p->zeta_threshold;
  const double _t9 = -z;
  const double _t10 = _t9 > _t4;
  const double _t11 = my_piecewise3(_t10, _t9, _t4);
  const double _t12 = xc_expm1((0.4e1 / 0.3e1)*xc_log1p(_t11));
#if _KMAX >= 1
  const double _t13 = my_piecewise3(_t5, 0.1e1, 0);
  const double _t14 = _t6 + 0.1e1;
  const double _t15 = _t7 + 0.1e1;
  const double _t16 = my_piecewise3(_t10, -0.1e1, 0);
  const double _t17 = _t11 + 0.1e1;
  const double _t18 = _t12 + 0.1e1;
#endif

  const double f = _t1*(my_piecewise3(_t2, _t3, _t7) + my_piecewise3(_t8, _t3, _t12));
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t1*(my_piecewise3(_t2, 0, (0.4e1 / 0.3e1)*_t13*_t15/_t14) + my_piecewise3(_t8, 0, (0.4e1 / 0.3e1)*_t16*_t18/_t17));
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t1*(my_piecewise3(_t2, 0, (0.4e1 / 0.9e1)*(_t13 * _t13)*_t15/(_t14 * _t14)) + my_piecewise3(_t8, 0, (0.4e1 / 0.9e1)*(_t16 * _t16)*_t18/(_t17 * _t17)));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t1*(my_piecewise3(_t2, 0, -0.8e1 / 0.27e2*(_t13 * _t13 * _t13)*_t15/(_t14 * _t14 * _t14)) + my_piecewise3(_t8, 0, -0.8e1 / 0.27e2*(_t16 * _t16 * _t16)*_t18/(_t17 * _t17 * _t17)));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t1*(my_piecewise3(_t2, 0, (0.40e2 / 0.81e2)*(_t13 * _t13 * _t13 * _t13)*_t15/(_t14 * _t14 * _t14 * _t14)) + my_piecewise3(_t8, 0, (0.40e2 / 0.81e2)*(_t16 * _t16 * _t16 * _t16)*_t18/(_t17 * _t17 * _t17 * _t17)));
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k, _KMAX)(p, zeta, _hc0);
  const double _t1 = 0.0132882934*rs + 0.062182000000000001;
  const double _t2 = -_t1;
  const double _t3 = pow(rs, 1.5);
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = (rs * rs);
  const double _t6 = 0.1018665524*_t3 + 0.4723158174*_t4 + 0.030651995080000001*_t5 + 0.2230841432*rs;
  const double _t7 = (0.1e1 / _t6);
  const double _t8 = xc_log1p(_t7);
  const double _t9 = _t2*_t8;
  const double _t10 = 0.029729901239999999*_t3 + 0.34979731799999997*_t4 + 0.016775883539999998*_t5 + 0.12236657939999999*rs;
  const double _t11 = (0.1e1 / _t10);
  const double _t12 = xc_log1p(_t11);
  const double _t13 = -0.0037573575*rs - 0.033773999999999998;
  const double _t14 = 0.58482233974552045*_t13;
  const double _t15 = _t12*_t14;
  const double _t16 = (zeta * zeta * zeta * zeta);
  const double _t17 = 0.0063883732000000002*rs + 0.03109;
  const double _t18 = -_t17;
  const double _t19 = 0.104655158*_t3 + 0.438956601*_t4 + 0.019436535299999998*_t5 + 0.19268649300000001*rs;
  const double _t20 = (0.1e1 / _t19);
  const double _t21 = xc_log1p(_t20);
  const double _t22 = _t15 + _t18*_t21 - _t9;
  const double _t23 = _t16*_t22;
#if _KMAX >= 1
  const double _t24 = _hc0[0]*_t22;
  const double _t25 = (zeta * zeta * zeta);
  const double _t26 = 0.4e1*_t25;
  const double _t27 = 0.0021973866044103793*_t12;
  const double _t28 = sqrt(rs);
  const double _t29 = (0.1e1 / _t4);
  const double _t30 = -0.15698273699999998*_t28 - 0.2194783005*_t29 - 0.038873070599999997*rs - 0.19268649300000001;
  const double _t31 = (0.1e1 / (_t19 * _t19));
  const double _t32 = _t20 + 0.1e1;
  const double _t33 = (0.1e1 / _t32);
  const double _t34 = -0.04459485186*_t28 - 0.17489865899999998*_t29 - 0.033551767079999996*rs - 0.12236657939999999;
  const double _t35 = (0.1e1 / (_t10 * _t10));
  const double _t36 = _t11 + 0.1e1;
  const double _t37 = (0.1e1 / _t36);
  const double _t38 = _t7 + 0.1e1;
  const double _t39 = (0.1e1 / _t38);
  const double _t40 = _t39/(_t6 * _t6);
  const double _t41 = -0.15279982860000002*_t28 - 0.2361579087*_t29 - 0.061303990160000002*rs - 0.2230841432;
  const double _t42 = _t2*_t41;
  const double _t43 = _t40*_t42 - 0.0132882934*_t8;
  const double _t44 = 0.58482233974552045*_t13*_t34*_t35*_t37 + _t18*_t30*_t31*_t33 - 0.0063883732000000002*_t21 - _t27 - _t43;
  const double _t45 = _t16*_t44;
  const double _t46 = _t35*_t37;
  const double _t47 = _t34*_t46;
  const double _t48 = _t14*_t47;
#endif
#if _KMAX >= 2
  const double _t49 = (zeta * zeta);
  const double _t50 = 0.12e2*_t49;
  const double _t51 = _t22*_t25;
  const double _t52 = 0.8e1*_hc0[1];
  const double _t53 = _hc0[0]*_t44;
  const double _t54 = 0.0265765868*_t40*_t41;
  const double _t55 = 0.0043947732088207587*_t47;
  const double _t56 = (0.1e1 / _t28);
  const double _t57 = xc_powr(rs, -3, 2);
  const double _t58 = -0.07639991430000001*_t56 + 0.11807895435*_t57 - 0.061303990160000002;
  const double _t59 = _t40*_t58;
  const double _t60 = _t2*_t59;
  const double _t61 = -0.02229742593*_t56 + 0.087449329499999992*_t57 - 0.033551767079999996;
  const double _t62 = _t46*_t61;
  const double _t63 = _t14*_t62;
  const double _t64 = (0.1e1 / (_t6 * _t6 * _t6 * _t6));
  const double _t65 = (0.1e1 / (_t38 * _t38));
  const double _t66 = (_t41 * _t41);
  const double _t67 = _t65*_t66;
  const double _t68 = _t64*_t67;
  const double _t69 = (0.1e1 / (_t10 * _t10 * _t10 * _t10));
  const double _t70 = (0.1e1 / (_t36 * _t36));
  const double _t71 = (_t34 * _t34);
  const double _t72 = _t70*_t71;
  const double _t73 = _t69*_t72;
  const double _t74 = _t14*_t73;
  const double _t75 = _t39/(_t6 * _t6 * _t6);
  const double _t76 = -0.30559965720000004*_t28 - 0.4723158174*_t29 - 0.12260798032*rs - 0.4461682864;
  const double _t77 = _t42*_t76;
  const double _t78 = _t75*_t77;
  const double _t79 = _t37/(_t10 * _t10 * _t10);
  const double _t80 = -0.089189703719999999*_t28 - 0.34979731799999997*_t29 - 0.067103534159999992*rs - 0.24473315879999999;
  const double _t81 = _t34*_t80;
  const double _t82 = _t79*_t81;
  const double _t83 = _t14*_t82;
  const double _t84 = _t31*_t33;
  const double _t85 = -0.078491368499999992*_t56 + 0.10973915025*_t57 - 0.038873070599999997;
  const double _t86 = _t84*_t85;
  const double _t87 = 0.0021973866044103793*rs + 0.019751789702565206;
  const double _t88 = (0.1e1 / (_t19 * _t19 * _t19 * _t19));
  const double _t89 = (0.1e1 / (_t32 * _t32));
  const double _t90 = (_t30 * _t30);
  const double _t91 = _t89*_t90;
  const double _t92 = _t88*_t91;
  const double _t93 = _t2*_t64;
  const double _t94 = _t33/(_t19 * _t19 * _t19);
  const double _t95 = -0.31396547399999997*_t28 - 0.438956601*_t29 - 0.077746141199999994*rs - 0.38537298600000003;
  const double _t96 = _t18*_t30;
  const double _t97 = _t95*_t96;
  const double _t98 = _t17*_t92 + _t18*_t86 - 0.0127767464*_t30*_t84 + _t54 - _t55 - _t60 + _t63 + _t67*_t93 + _t73*_t87 - _t78 + _t83 + _t94*_t97;
  const double _t99 = _t16*_t98;
#endif
#if _KMAX >= 3
  const double _t100 = 0.24e2*_t24;
  const double _t101 = _t22*_t49;
  const double _t102 = 0.36e2*_hc0[1];
  const double _t103 = 0.12e2*_hc0[2];
  const double _t104 = _t25*_t44;
  const double _t105 = _hc0[0]*_t98;
  const double _t106 = 0.039864880200000001*_t59;
  const double _t107 = 0.006592159813231138*_t62;
  const double _t108 = (0.1e1 / _t3);
  const double _t109 = xc_powr(rs, -5, 2);
  const double _t110 = 0.038199957150000005*_t108 - 0.17711843152500001*_t109;
  const double _t111 = _t110*_t40;
  const double _t112 = _t111*_t2;
  const double _t113 = 0.039864880200000001*_t68;
  const double _t114 = 0.011148712965*_t108 - 0.13117399424999998*_t109;
  const double _t115 = _t114*_t46;
  const double _t116 = _t115*_t14;
  const double _t117 = 0.006592159813231138*_t73;
  const double _t118 = 0.0265765868*rs + 0.124364;
  const double _t119 = (_t41 * _t41 * _t41);
  const double _t120 = (0.1e1 / (_t38 * _t38 * _t38));
  const double _t121 = xc_powi(_t6, -6);
  const double _t122 = _t120*_t121;
  const double _t123 = _t119*_t122;
  const double _t124 = (_t34 * _t34 * _t34);
  const double _t125 = (0.1e1 / (_t36 * _t36 * _t36));
  const double _t126 = xc_powi(_t10, -6);
  const double _t127 = _t125*_t126;
  const double _t128 = _t124*_t127;
  const double _t129 = 1.1696446794910409*_t13;
  const double _t130 = _t128*_t129;
  const double _t131 = _t41*_t75;
  const double _t132 = 0.039864880200000001*_t131*_t76;
  const double _t133 = 0.006592159813231138*_t82;
  const double _t134 = -0.15279982860000002*_t56 + 0.2361579087*_t57 - 0.12260798032;
  const double _t135 = _t42*_t75;
  const double _t136 = _t134*_t135;
  const double _t137 = _t64*_t65;
  const double _t138 = _t137*_t42;
  const double _t139 = _t134*_t138;
  const double _t140 = _t138*_t58;
  const double _t141 = _t75*_t76;
  const double _t142 = _t141*_t58;
  const double _t143 = 0.2e1*_t2;
  const double _t144 = _t142*_t143;
  const double _t145 = -0.04459485186*_t56 + 0.17489865899999998*_t57 - 0.067103534159999992;
  const double _t146 = _t69*_t70;
  const double _t147 = _t14*_t34;
  const double _t148 = _t146*_t147;
  const double _t149 = _t145*_t148;
  const double _t150 = _t146*_t61;
  const double _t151 = _t147*_t150;
  const double _t152 = _t145*_t79;
  const double _t153 = _t147*_t152;
  const double _t154 = _t79*_t80;
  const double _t155 = _t154*_t61;
  const double _t156 = _t129*_t155;
  const double _t157 = -0.61119931440000008*_t28 - 0.94463163480000001*_t29 - 0.24521596064000001*rs - 0.89233657280000001;
  const double _t158 = xc_powi(_t6, -5);
  const double _t159 = _t158*_t67;
  const double _t160 = _t159*_t2;
  const double _t161 = _t157*_t160;
  const double _t162 = _t160*_t76;
  const double _t163 = -0.17837940744*_t28 - 0.69959463599999994*_t29 - 0.13420706831999998*rs - 0.48946631759999998;
  const double _t164 = xc_powi(_t10, -5);
  const double _t165 = _t164*_t72;
  const double _t166 = _t14*_t165;
  const double _t167 = _t163*_t166;
  const double _t168 = _t166*_t80;
  const double _t169 = -0.45839948580000006*_t28 - 0.70847372610000003*_t29 - 0.18391197048000002*rs - 0.66925242959999998;
  const double _t170 = _t169*_t39;
  const double _t171 = _t170*_t64;
  const double _t172 = _t171*_t77;
  const double _t173 = -0.13378455557999999*_t28 - 0.52469597699999992*_t29 - 0.10065530123999999*rs - 0.36709973819999997;
  const double _t174 = _t173*_t37*_t69;
  const double _t175 = _t174*_t81;
  const double _t176 = _hc0[0]*_t14;
  const double _t177 = 0.039245684249999996*_t108 - 0.16460872537499999*_t109;
  const double _t178 = _t177*_t84;
  const double _t179 = (_t30 * _t30 * _t30);
  const double _t180 = (0.1e1 / (_t32 * _t32 * _t32));
  const double _t181 = xc_powi(_t19, -6);
  const double _t182 = _t180*_t181;
  const double _t183 = _t179*_t182;
  const double _t184 = _t30*_t94;
  const double _t185 = -0.15698273699999998*_t56 + 0.2194783005*_t57 - 0.077746141199999994;
  const double _t186 = _t185*_t96;
  const double _t187 = _t88*_t89;
  const double _t188 = _t187*_t85;
  const double _t189 = _t94*_t95;
  const double _t190 = _t189*_t85;
  const double _t191 = 0.2e1*_t18;
  const double _t192 = -0.62793094799999993*_t28 - 0.877913202*_t29 - 0.15549228239999999*rs - 0.77074597200000006;
  const double _t193 = xc_powi(_t19, -5);
  const double _t194 = _t193*_t91;
  const double _t195 = _t18*_t194;
  const double _t196 = -0.47094821099999995*_t28 - 0.65843490149999995*_t29 - 0.11661921179999998*rs - 0.57805947899999999;
  const double _t197 = _t196*_t33*_t88;
  const double _t198 = _t14*_t175;
  const double _t199 = _t106 - _t107 - _t112 - _t113 + _t116 + _t117 + _t118*_t123 + _t128*(-0.0043947732088207587*rs - 0.039503579405130412) + _t132 - _t133 - _t136 + _t139 + _t140 - _t144 - _t149 - _t151 + _t153 + _t156 + _t161 + _t162 - _t167 - _t168 - _t172 + _t178*_t18 + _t183*(-0.0127767464*rs - 0.062179999999999999) - 0.019165119600000002*_t184*_t95 - _t186*_t187 + _t186*_t94 - _t188*_t96 + _t190*_t191 - _t192*_t195 - _t195*_t95 + _t197*_t97 + _t198 - 0.019165119600000002*_t86 + 0.019165119600000002*_t92;
  const double _t200 = _t16*_t199;
#endif
#if _KMAX >= 4
  const double _t201 = 0.053153173599999999*_t111;
  const double _t202 = 0.0087895464176415174*_t115;
  const double _t203 = pow(rs, -2.5);
  const double _t204 = xc_powr(rs, -7, 2);
  const double _t205 = _t2*_t40*(-0.057299935725000008*_t203 + 0.44279607881250005*_t204);
  const double _t206 = 0.1063063472*_t123;
  const double _t207 = _t14*_t46*(-0.016723069447499999*_t203 + 0.32793498562499995*_t204);
  const double _t208 = 0.017579092835283035*_t128;
  const double _t209 = (_t58 * _t58)*_t65;
  const double _t210 = _t146*(_t61 * _t61);
  const double _t211 = 0.079729760400000002*rs + 0.37309199999999998;
  const double _t212 = (_t41 * _t41 * _t41 * _t41)/((_t38 * _t38 * _t38 * _t38)*xc_powi(_t6, 8));
  const double _t213 = (_t34 * _t34 * _t34 * _t34)/(xc_powi(_t10, 8)*(_t36 * _t36 * _t36 * _t36));
  const double _t214 = 0.053153173599999999*_t134;
  const double _t215 = _t137*_t41;
  const double _t216 = _t214*_t215;
  const double _t217 = 0.053153173599999999*_t215*_t58;
  const double _t218 = _t131*_t214;
  const double _t219 = 0.1063063472*_t142;
  const double _t220 = 0.0087895464176415174*_t34;
  const double _t221 = _t145*_t220;
  const double _t222 = _t146*_t221;
  const double _t223 = _t150*_t220;
  const double _t224 = _t221*_t79;
  const double _t225 = 0.017579092835283035*_t155;
  const double _t226 = _t134*_t58;
  const double _t227 = _t226*_t65*_t93;
  const double _t228 = 0.3e1*_t2;
  const double _t229 = _t226*_t228*_t75;
  const double _t230 = _t14*_t145;
  const double _t231 = _t150*_t230;
  const double _t232 = 1.7544670192365612*_t13;
  const double _t233 = _t232*_t61;
  const double _t234 = _t152*_t233;
  const double _t235 = 0.07639991430000001*_t108 - 0.35423686305000002*_t109;
  const double _t236 = _t135*_t235;
  const double _t237 = 0.032487183262504181*_t28 + 0.050210169272576204*_t29 + 0.013034006525388686*rs + 0.047430520763667439;
  const double _t238 = 0.01624359163125209*_t28 + 0.025105084636288102*_t29 + 0.0065170032626943432*rs + 0.023715260381833719;
  const double _t239 = 0.2e1*_t110*_t138;
  const double _t240 = _t138*_t235;
  const double _t241 = _t110*_t141*_t228;
  const double _t242 = _t114*_t129*_t146*_t34;
  const double _t243 = 0.02229742593*_t108 - 0.26234798849999996*_t109;
  const double _t244 = _t148*_t243;
  const double _t245 = _t114*_t154*_t232;
  const double _t246 = _t147*_t243*_t79;
  const double _t247 = 0.0087895464176415174*_t165;
  const double _t248 = _hc0[0]*_t163;
  const double _t249 = _hc0[0]*_t80;
  const double _t250 = -0.22919974290000003*_t56 + 0.35423686305000002*_t57 - 0.18391197048000002;
  const double _t251 = _t122*_t143*_t66;
  const double _t252 = _t250*_t251;
  const double _t253 = _t134*_t251;
  const double _t254 = _t251*_t58;
  const double _t255 = _t160*(-0.30559965720000004*_t56 + 0.4723158174*_t57 - 0.24521596064000001);
  const double _t256 = 0.2e1*_t134;
  const double _t257 = _t160*_t256;
  const double _t258 = -0.066892277789999996*_t56 + 0.26234798849999996*_t57 - 0.10065530123999999;
  const double _t259 = _t127*_t129*_t71;
  const double _t260 = _t258*_t259;
  const double _t261 = _t145*_t259;
  const double _t262 = _t259*_t61;
  const double _t263 = _t166*(-0.089189703719999999*_t56 + 0.34979731799999997*_t57 - 0.13420706831999998);
  const double _t264 = _t129*_t145;
  const double _t265 = _t165*_t264;
  const double _t266 = _t119*_t120*_t143/xc_powi(_t6, 7);
  const double _t267 = _t266*(-0.91679897160000012*_t28 - 1.4169474522000001*_t29 - 0.36782394096000004*rs - 1.3385048592);
  const double _t268 = _t157*_t266;
  const double _t269 = _t266*_t76;
  const double _t270 = _t124*_t125*_t129/xc_powi(_t10, 7);
  const double _t271 = _t270*(-0.26756911115999998*_t28 - 1.0493919539999998*_t29 - 0.20131060247999999*rs - 0.73419947639999994);
  const double _t272 = _t163*_t270;
  const double _t273 = _t270*_t80;
  const double _t274 = 0.053153173599999999*_t171*_t41*_t76;
  const double _t275 = 0.0087895464176415174*_t175;
  const double _t276 = _t250*_t39*_t64*_t77;
  const double _t277 = _t158*_t65;
  const double _t278 = _t157*_t42;
  const double _t279 = _t256*_t277*_t278;
  const double _t280 = _t134*_t277*_t77;
  const double _t281 = _t277*_t58;
  const double _t282 = _t278*_t281;
  const double _t283 = 0.2e1*_t281*_t77;
  const double _t284 = _t171*_t256*_t42;
  const double _t285 = 0.3e1*_t170*_t58*_t76*_t93;
  const double _t286 = _t264*_t34;
  const double _t287 = _t164*_t70;
  const double _t288 = _t286*_t287;
  const double _t289 = _t230*_t287*_t81;
  const double _t290 = _t287*_t61;
  const double _t291 = _t147*_t290;
  const double _t292 = _t129*_t290*_t81;
  const double _t293 = _t258*_t69;
  const double _t294 = _t37*_t81;
  const double _t295 = _t176*_t294;
  const double _t296 = _t174*_t286;
  const double _t297 = _t174*_t233;
  const double _t298 = _t121*_t2*_t67*(-0.76399914300000016*_t28 - 1.1807895435*_t29 - 0.3065199508*rs - 1.115420716);
  const double _t299 = _t157*_t298;
  const double _t300 = _t298*_t76;
  const double _t301 = _t121*_t169*_t2*_t67*_t76;
  const double _t302 = _t126*_t72*(-0.22297425930000001*_t28 - 0.87449329499999995*_t29 - 0.16775883539999997*rs - 0.61183289699999999);
  const double _t303 = _t176*_t302;
  const double _t304 = _t126*_t173*_t72*_t80;
  const double _t305 = _t157*_t158*_t170*_t77;
  const double _t306 = _t163*_t164*_t173;
  const double _t307 = 0.025553492800000001*_t30;
  const double _t308 = _t18*_t185;
  const double _t309 = _t96*(0.078491368499999992*_t108 - 0.32921745074999997*_t109);
  const double _t310 = 0.3e1*_t18;
  const double _t311 = -0.23547410549999997*_t56 + 0.32921745074999997*_t57 - 0.11661921179999998;
  const double _t312 = _t182*_t90;
  const double _t313 = _t191*_t312;
  const double _t314 = _t179*_t180*_t191/xc_powi(_t19, 7);
  const double _t315 = _t197*_t95;
  const double _t316 = _t33*_t97;
  const double _t317 = _t14*_t294;
  const double _t318 = _t193*_t89;
  const double _t319 = 0.2e1*_t186;
  const double _t320 = _t318*_t85;
  const double _t321 = _t14*_t302;
  const double _t322 = -0.78491368499999992*_t28 - 1.0973915025000001*_t29 - 0.19436535299999999*rs - 0.96343246500000013;
  const double _t323 = _t18*_t181*_t91;
  const double _t324 = _t323*_t95;
#endif

  const double f = -_hc0[0]*_t15 + _hc0[0]*_t23 + _t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = -_hc0[1]*_t15 + _hc0[1]*_t23 + _t24*_t26;
  out[1] = df_dzeta;
  const double df_drs = _hc0[0]*_t27 + _hc0[0]*_t45 - _hc0[0]*_t48 + _t43;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = -_hc0[2]*_t15 + _hc0[2]*_t23 + _t24*_t50 + _t51*_t52;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = _hc0[1]*_t27 + _hc0[1]*_t45 - _hc0[1]*_t48 + _t26*_t53;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = _hc0[0]*_t55 - _hc0[0]*_t63 + _hc0[0]*_t74 - _hc0[0]*_t83 + _hc0[0]*_t99 + _t1*_t68 - _t54 + _t60 + _t78;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = -_hc0[3]*_t15 + _hc0[3]*_t23 + _t100*zeta + _t101*_t102 + _t103*_t51;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = _hc0[2]*_t27 + _hc0[2]*_t45 - _hc0[2]*_t48 + _t104*_t52 + _t50*_t53;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = _hc0[1]*_t55 - _hc0[1]*_t63 + _hc0[1]*_t74 - _hc0[1]*_t83 + _hc0[1]*_t99 + _t105*_t26;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = _hc0[0]*_t107 - _hc0[0]*_t116 - _hc0[0]*_t117 - _hc0[0]*_t130 + _hc0[0]*_t133 + _hc0[0]*_t149 + _hc0[0]*_t151 - _hc0[0]*_t153 - _hc0[0]*_t156 + _hc0[0]*_t167 + _hc0[0]*_t168 + _hc0[0]*_t200 - _t106 + _t112 + _t113 - _t118*_t123 - _t132 + _t136 - _t139 - _t140 + _t144 - _t161 - _t162 + _t172 - _t175*_t176;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dzeta4 = 0.96e2*_hc0[1]*_t22*zeta + 0.72e2*_hc0[2]*_t101 + 0.16e2*_hc0[3]*_t51 - _hc0[4]*_t15 + _hc0[4]*_t23 + _t100;
  out[10] = d4f_dzeta4;
  const double d4f_drs_dzeta3 = _hc0[3]*_t27 + _hc0[3]*_t45 - _hc0[3]*_t48 + _t102*_t44*_t49 + _t103*_t104 + 0.24e2*_t53*zeta;
  out[11] = d4f_drs_dzeta3;
  const double d4f_drs2_dzeta2 = _hc0[2]*_t55 - _hc0[2]*_t63 + _hc0[2]*_t74 - _hc0[2]*_t83 + _hc0[2]*_t99 + _t105*_t50 + _t25*_t52*_t98;
  out[12] = d4f_drs2_dzeta2;
  const double d4f_drs3_dzeta = _hc0[0]*_t199*_t26 + _hc0[1]*_t107 - _hc0[1]*_t116 - _hc0[1]*_t117 - _hc0[1]*_t130 + _hc0[1]*_t133 + _hc0[1]*_t149 + _hc0[1]*_t151 - _hc0[1]*_t153 - _hc0[1]*_t156 + _hc0[1]*_t167 + _hc0[1]*_t168 - _hc0[1]*_t198 + _hc0[1]*_t200;
  out[13] = d4f_drs3_dzeta;
  const double d4f_drs4 = 3.5089340384731225*_hc0[0]*_t13*_t213 + _hc0[0]*_t16*(-_t14*_t304 + _t159*_t237 + _t159*_t238 - _t163*_t288 - _t163*_t291 - _t163*_t321 + _t165*(-0.0015678740816452686*_t28 - 0.0061491195266550206*_t29 - 0.0011796192565742263*rs - 0.0043021869184172654) + _t165*(-0.00078393704082263429*_t28 - 0.0030745597633275103*_t29 - 0.00058980962828711315*rs - 0.0021510934592086327) + _t17*_t187*(_t85 * _t85) - 0.2e1*_t177*_t187*_t96 + _t177*_t189*_t310 - 0.025553492800000001*_t178 + _t18*_t84*(-0.058868526374999994*_t203 + 0.41152181343749994*_t204) - 0.051106985600000002*_t183 - 0.025553492800000001*_t184*_t185 + _t185*_t187*_t307 - 0.2e1*_t185*_t195 - _t185*_t318*_t97 - _t187*_t309 + _t188*_t307 - _t188*_t308 - 0.051106985600000002*_t190 + _t192*_t193*_t196*_t316 + _t192*_t314 - _t192*_t318*_t319 - _t192*_t320*_t96 - _t192*_t322*_t323 + _t194*(-0.016045828958615175*_t28 - 0.022433748686331946*_t29 - 0.0039733709187639663*rs - 0.019695251646131003) + _t194*(-0.0080229144793075875*_t28 - 0.011216874343165973*_t29 - 0.0019866854593819832*rs - 0.0098476258230655016) - _t195*(-0.31396547399999997*_t56 + 0.438956601*_t57 - 0.15549228239999999) - _t196*_t324 + _t197*_t319 + _t201 - _t202 - _t205 + _t206 + _t207 - _t208 + _t209*_t93 + _t210*_t87 - _t211*_t212 + _t213*(0.013184319626462274*rs + 0.11851073821539124) - _t216 - _t217 + _t218 + _t219 + _t222 + _t223 - _t224 - _t225 + _t227 - _t229 - _t231 + _t234 - _t236 + _t239 + _t240 - _t241 - _t242 - _t244 + _t245 + _t246 - _t252 - _t253 - _t254 + _t255 + _t257 + _t260 + _t261 + _t262 - _t263 - _t265 - _t267 - _t268 - _t269 + _t271 + _t272 + _t273 + _t274 - _t275 - _t276 + _t279 + _t280 + _t282 + _t283 - _t284 - _t285 - _t289 - _t292 + _t293*_t317 + _t296 + _t297*_t80 + _t299 + _t300 + _t301 - _t305 + _t306*_t317 - _t307*_t315 + 0.2e1*_t308*_t312 + 0.3e1*_t308*_t85*_t94 + _t309*_t94 + _t310*_t315*_t85 + _t311*_t313 + _t311*_t316*_t88 + _t313*_t85 + _t314*_t95 + _t314*(-0.9418964219999999*_t28 - 1.3168698029999999*_t29 - 0.23323842359999997*rs - 1.156118958) - 0.2e1*_t320*_t97 - _t321*_t80 - _t322*_t324 + (_t30 * _t30 * _t30 * _t30)*(0.038330239200000005*rs + 0.18653999999999998)/(xc_powi(_t19, 8)*(_t32 * _t32 * _t32 * _t32))) + _hc0[0]*_t202 - _hc0[0]*_t207 + _hc0[0]*_t208 - _hc0[0]*_t222 - _hc0[0]*_t223 + _hc0[0]*_t224 + _hc0[0]*_t225 + _hc0[0]*_t231 - _hc0[0]*_t234 + _hc0[0]*_t242 + _hc0[0]*_t244 - _hc0[0]*_t245 - _hc0[0]*_t246 - _hc0[0]*_t260 - _hc0[0]*_t261 - _hc0[0]*_t262 + _hc0[0]*_t263 + _hc0[0]*_t265 - _hc0[0]*_t271 - _hc0[0]*_t272 - _hc0[0]*_t273 + _hc0[0]*_t275 + _hc0[0]*_t289 + _hc0[0]*_t292 - _hc0[0]*_t296 + _t1*_t209*_t64 - _t159*_t237 - _t159*_t238 + _t163*_t303 + _t176*_t210 + _t176*_t304 - _t201 + _t205 - _t206 + _t211*_t212 + _t216 + _t217 - _t218 - _t219 - _t227 + _t229 + _t236 - _t239 - _t240 + _t241 - _t247*_t248 - _t247*_t249 + _t248*_t288 + _t248*_t291 - _t249*_t297 + _t252 + _t253 + _t254 - _t255 - _t257 + _t267 + _t268 + _t269 - _t274 + _t276 - _t279 - _t280 - _t282 - _t283 + _t284 + _t285 - _t293*_t295 - _t295*_t306 - _t299 - _t300 - _t301 + _t303*_t80 + _t305;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(nt_tau_k, _KMAX)(const xc_func_type *p, double t, double *out) {
  const mgga_c_ltapw_params *params = (const mgga_c_ltapw_params *)(p->params);

  const double _t1 = (0.3e1 / 0.5e1)*params->ltafrac;
  const double _t2 = pow((0.5e1 / 0.9e1)*xc_powr(0.6e1, 1, 3)*t/(M_PI * M_CBRTPI), _t1);
#if _KMAX >= 1
  const double _t3 = _t1*_t2;
#endif
#if _KMAX >= 2
  const double _t4 = (0.1e1 / (t * t));
  const double _t5 = _t2*((params->ltafrac) * (params->ltafrac));
#endif
#if _KMAX >= 3
  const double _t6 = (0.1e1 / (t * t * t));
  const double _t7 = _t2*_t6;
  const double _t8 = ((params->ltafrac) * (params->ltafrac) * (params->ltafrac));
#endif
#if _KMAX >= 4
  const double _t9 = (0.1e1 / (t * t * t * t));
  const double _t10 = _t2*_t9;
#endif

  const double f = _t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t3/t;
  out[1] = df_dt;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = -_t3*_t4 + (0.9e1 / 0.25e2)*_t4*_t5;
  out[2] = d2f_dt2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = -0.27e2 / 0.25e2*_t5*_t6 + (0.27e2 / 0.125e3)*_t7*_t8 + (0.6e1 / 0.5e1)*_t7*params->ltafrac;
  out[3] = d3f_dt3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = -0.162e3 / 0.125e3*_t10*_t8 + (0.81e2 / 0.625e3)*_t10*((params->ltafrac) * (params->ltafrac) * (params->ltafrac) * (params->ltafrac)) - 0.18e2 / 0.5e1*_t10*params->ltafrac + (0.99e2 / 0.25e2)*_t5*_t9;
  out[4] = d4f_dt4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = 0.0132882934*rs + 0.062182000000000001;
  const double _t2 = -_t1;
  const double _t3 = pow(rs, 1.5);
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = 0.1018665524*_t3 + 0.4723158174*_t4 + 0.030651995080000001*(rs * rs) + 0.2230841432*rs;
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = xc_log1p(_t6);
#if _KMAX >= 1
  const double _t8 = sqrt(rs);
  const double _t9 = (0.1e1 / _t4);
  const double _t10 = -0.15279982860000002*_t8 - 0.2361579087*_t9 - 0.061303990160000002*rs - 0.2230841432;
  const double _t11 = (0.1e1 / (_t5 * _t5));
  const double _t12 = _t6 + 0.1e1;
  const double _t13 = (0.1e1 / _t12);
#endif
#if _KMAX >= 2
  const double _t14 = _t11*_t13;
  const double _t15 = (0.1e1 / _t8);
  const double _t16 = xc_powr(rs, -3, 2);
  const double _t17 = -0.07639991430000001*_t15 + 0.11807895435*_t16 - 0.061303990160000002;
  const double _t18 = _t14*_t17;
  const double _t19 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t20 = (0.1e1 / (_t12 * _t12));
  const double _t21 = (_t10 * _t10);
  const double _t22 = _t20*_t21;
  const double _t23 = _t19*_t22;
  const double _t24 = _t13/(_t5 * _t5 * _t5);
  const double _t25 = -0.30559965720000004*_t8 - 0.4723158174*_t9 - 0.12260798032*rs - 0.4461682864;
  const double _t26 = _t10*_t2;
  const double _t27 = _t25*_t26;
#endif
#if _KMAX >= 3
  const double _t28 = (0.1e1 / _t3);
  const double _t29 = xc_powr(rs, -5, 2);
  const double _t30 = 0.038199957150000005*_t28 - 0.17711843152500001*_t29;
  const double _t31 = _t14*_t30;
  const double _t32 = (_t10 * _t10 * _t10);
  const double _t33 = (0.1e1 / (_t12 * _t12 * _t12));
  const double _t34 = xc_powi(_t5, -6);
  const double _t35 = _t33*_t34;
  const double _t36 = _t32*_t35;
  const double _t37 = _t10*_t24;
  const double _t38 = -0.15279982860000002*_t15 + 0.2361579087*_t16 - 0.12260798032;
  const double _t39 = _t26*_t38;
  const double _t40 = _t19*_t20;
  const double _t41 = _t17*_t40;
  const double _t42 = _t24*_t25;
  const double _t43 = _t17*_t42;
  const double _t44 = 0.2e1*_t2;
  const double _t45 = -0.61119931440000008*_t8 - 0.94463163480000001*_t9 - 0.24521596064000001*rs - 0.89233657280000001;
  const double _t46 = xc_powi(_t5, -5);
  const double _t47 = _t22*_t46;
  const double _t48 = _t2*_t47;
  const double _t49 = -0.45839948580000006*_t8 - 0.70847372610000003*_t9 - 0.18391197048000002*rs - 0.66925242959999998;
  const double _t50 = _t13*_t19*_t49;
#endif
#if _KMAX >= 4
  const double _t51 = 0.053153173599999999*_t10;
  const double _t52 = _t2*_t38;
  const double _t53 = _t26*(0.07639991430000001*_t28 - 0.35423686305000002*_t29);
  const double _t54 = 0.3e1*_t2;
  const double _t55 = -0.22919974290000003*_t15 + 0.35423686305000002*_t16 - 0.18391197048000002;
  const double _t56 = _t21*_t35;
  const double _t57 = _t44*_t56;
  const double _t58 = _t32*_t33*_t44/xc_powi(_t5, 7);
  const double _t59 = _t25*_t50;
  const double _t60 = _t13*_t27;
  const double _t61 = _t20*_t46;
  const double _t62 = 0.2e1*_t39;
  const double _t63 = _t17*_t61;
  const double _t64 = _t2*_t22*_t34*(-0.76399914300000016*_t8 - 1.1807895435*_t9 - 0.3065199508*rs - 1.115420716);
#endif

  const double f = _t2*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t10*_t11*_t13*_t2 - 0.0132882934*_t7;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t1*_t23 - 0.0265765868*_t10*_t14 + _t18*_t2 + _t24*_t27;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.039864880200000001*_t18 + _t2*_t31 + 0.039864880200000001*_t23 + _t24*_t39 - 0.039864880200000001*_t25*_t37 - _t25*_t48 - _t26*_t41 + _t27*_t50 + _t36*(-0.0265765868*rs - 0.124364) - _t39*_t40 + _t43*_t44 - _t45*_t48;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _t1*(_t17 * _t17)*_t40 + (_t10 * _t10 * _t10 * _t10)*(0.079729760400000002*rs + 0.37309199999999998)/((_t12 * _t12 * _t12 * _t12)*xc_powi(_t5, 8)) + _t14*_t2*(-0.057299935725000008*pow(rs, -2.5) + 0.44279607881250005/xc_powr(rs, 7, 2)) + 0.3e1*_t17*_t24*_t52 + _t17*_t54*_t59 + _t17*_t57 + _t19*_t55*_t60 - _t2*_t22*_t25*_t34*_t49 + _t24*_t53 + _t25*_t58 - _t25*_t64 - 0.2e1*_t26*_t30*_t40 - _t26*_t45*_t63 - _t27*_t38*_t61 - 0.2e1*_t27*_t63 + _t30*_t42*_t54 - 0.053153173599999999*_t31 - 0.1063063472*_t36 - 0.053153173599999999*_t37*_t38 + _t38*_t40*_t51 - 0.2e1*_t38*_t48 - _t40*_t53 + _t41*_t51 - _t41*_t52 - 0.1063063472*_t43 + _t45*_t46*_t49*_t60 + _t45*_t58 - _t45*_t61*_t62 - _t45*_t64 + _t47*(-0.032487183262504181*_t8 - 0.050210169272576204*_t9 - 0.013034006525388686*rs - 0.047430520763667439) + _t47*(-0.01624359163125209*_t8 - 0.025105084636288102*_t9 - 0.0065170032626943432*rs - 0.023715260381833719) - _t48*(-0.30559965720000004*_t15 + 0.4723158174*_t16 - 0.24521596064000001) + _t50*_t62 - _t51*_t59 + 0.2e1*_t52*_t56 + _t55*_t57 + _t58*(-0.91679897160000012*_t8 - 1.4169474522000001*_t9 - 0.36782394096000004*rs - 1.3385048592);
  out[4] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_c_ltapw_params *params = (const mgga_c_ltapw_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double ta = tau[0];

  const double _t1 = xc_powr(0.2e1, 2, 3);
  const double _t2 = _t1*ta;
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = (0.1e1 / (M_CBRTPI));
  const double _t5 = _t3*_t4;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(nt_tau_k, _KMAX)(p, _t2/xc_powr(na, 5, 3), _hc0);
  const double _t6 = _t5/xc_powr(_hc0[0], 1, 3);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t6/xc_powr(na, 1, 3), _hc1);
  const double zk = _hc1[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t7 = M_CBRT3;
  const double _t9 = (0.1e1 / (na * na * na));
  const double _t12 = (0.1e1 / na);
  const double _t13 = _t4*_t7;
  const double _t8 = xc_powr(_hc0[0], -4, 3);
  const double _t10 = (0.5e1 / 0.9e1)*_hc0[1]*_t4*_t7*_t8*_t9*ta - 0.1e1 / 0.6e1*_t6/xc_powr(na, 4, 3);
  const double _t14 = _hc0[1]*_t13;
  const double _t15 = _t14*_t8;
  const double _t16 = _t12*_t15;
  const double _t11 = _hc1[1]*_t10;
  const double _t17 = (0.1e1 / 0.3e1)*_hc1[1];
  const double dF_dna = _hc1[0] + _t11*na;
  const double dF_dta = -_t16*_t17;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  const double _t21 = (0.1e1 / (na * na * na * na));
  const double _t24 = (ta * ta);
  const double _t25 = xc_powr(na, -17, 3);
  const double _t39 = (0.1e1 / (na * na));
  const double _t45 = xc_powr(na, -14, 3);
  const double _t52 = xc_powr(0.3e1, 2, 3);
  const double _t56 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t60 = xc_powr(na, -8, 3);
  const double _t18 = (_t10 * _t10);
  const double _t20 = _t6/xc_powr(na, 7, 3);
  const double _t22 = _t15*_t21;
  const double _t23 = _t22*ta;
  const double _t26 = _t13*_t8;
  const double _t27 = _t1*_t26;
  const double _t28 = _hc0[2]*_t27;
  const double _t29 = _t25*_t28;
  const double _t30 = _t24*_t29;
  const double _t31 = xc_powr(_hc0[0], -7, 3);
  const double _t32 = _t13*_t31;
  const double _t33 = ((_hc0[1]) * (_hc0[1]));
  const double _t34 = _t1*_t33;
  const double _t35 = _t32*_t34;
  const double _t36 = _t24*_t25*_t35;
  const double _t37 = (0.2e1 / 0.9e1)*_t20 - 0.50e2 / 0.27e2*_t23 - 0.25e2 / 0.27e2*_t30 + (0.100e3 / 0.81e2)*_t36;
  const double _t40 = _t15*_t39;
  const double _t42 = (0.1e1 / 0.3e1)*_t16;
  const double _t43 = (0.2e1 / 0.3e1)*_t8;
  const double _t44 = _t14*_t9;
  const double _t46 = _hc0[2]*_t45;
  const double _t47 = _t2*_t26;
  const double _t48 = _t46*_t47;
  const double _t49 = _t2*_t32*_t33;
  const double _t50 = _t45*_t49;
  const double _t51 = _t43*_t44 + (0.5e1 / 0.9e1)*_t48 - 0.20e2 / 0.27e2*_t50;
  const double _t53 = _t33*_t52;
  const double _t54 = _t53*_t9;
  const double _t55 = xc_powr(_hc0[0], -8, 3);
  const double _t62 = _t35*_t60;
  const double _t19 = _hc1[2]*_t18;
  const double _t38 = _hc1[1]*na;
  const double _t41 = _hc1[2]*_t10;
  const double _t57 = _hc1[2]*_t56;
  const double _t58 = _t55*_t57;
  const double _t59 = (0.1e1 / 0.9e1)*_t58;
  const double _t61 = _t17*_t28;
  const double _t63 = (0.4e1 / 0.9e1)*_hc1[1];
  const double d2F_dna2 = 0.2e1*_t11 + _t19*na + _t37*_t38;
  const double d2F_dna_dta = _hc1[1]*_t51*na - _t17*_t40 - _t41*_t42;
  const double d2F_dta2 = _t54*_t59 - _t60*_t61 + _t62*_t63;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
#endif
#if _KMAX >= 3
  const double _t71 = xc_powi(na, -5);
  const double _t76 = xc_powr(na, -25, 3);
  const double _t77 = (ta * ta * ta);
  const double _t78 = _t76*_t77;
  const double _t88 = xc_powr(na, -20, 3);
  const double _t89 = _t24*_t88;
  const double _t99 = xc_powr(na, -22, 3);
  const double _t100 = _t24*_t99;
  const double _t107 = xc_powr(na, -11, 3);
  const double _t118 = xc_powr(na, -19, 3);
  const double _t119 = _t118*_t5;
  const double _t130 = (0.1e1 / M_PI);
  const double _t134 = xc_powr(na, -13, 3);
  const double _t137 = xc_powr(0.6e1, 2, 3);
  const double _t64 = (_t10 * _t10 * _t10);
  const double _t69 = (0.4e1 / 0.9e1)*_t20 - 0.100e3 / 0.27e2*_t23 - 0.50e2 / 0.27e2*_t30 + (0.200e3 / 0.81e2)*_t36;
  const double _t70 = _t6/xc_powr(na, 10, 3);
  const double _t72 = _t15*_t71;
  const double _t73 = _t72*ta;
  const double _t74 = _hc0[3]*_t8;
  const double _t75 = _t5*_t74;
  const double _t79 = _t75*_t78;
  const double _t80 = _hc0[1]*_hc0[2]*_t31;
  const double _t81 = _t5*_t80;
  const double _t82 = _t78*_t81;
  const double _t83 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t84 = xc_powr(_hc0[0], -10, 3);
  const double _t85 = _t83*_t84;
  const double _t86 = _t5*_t85;
  const double _t87 = _t78*_t86;
  const double _t90 = _t28*_t89;
  const double _t91 = _t35*_t89;
  const double _t92 = -0.14e2 / 0.27e2*_t70 + (0.620e3 / 0.81e2)*_t73 + (0.250e3 / 0.81e2)*_t79 - 0.1000e4 / 0.81e2*_t82 + (0.7000e4 / 0.729e3)*_t87 + (0.25e2 / 0.3e1)*_t90 - 0.100e3 / 0.9e1*_t91;
  const double _t93 = _t14*_t43;
  const double _t96 = _t44*_t8;
  const double _t97 = (0.10e2 / 0.9e1)*_t48 - 0.40e2 / 0.27e2*_t50 + (0.4e1 / 0.3e1)*_t96;
  const double _t101 = _t100*_t75;
  const double _t102 = _hc0[2]*_t47;
  const double _t103 = _t102*_t25;
  const double _t104 = _t100*_t86;
  const double _t105 = (0.200e3 / 0.27e2)*_hc0[1]*_hc0[2]*_t24*_t3*_t31*_t4*_t99 + (0.400e3 / 0.81e2)*_t1*_t25*_t31*_t33*_t4*_t7*ta - 0.50e2 / 0.27e2*_t101 - 0.100e3 / 0.27e2*_t103 - 0.1400e4 / 0.243e3*_t104 - 0.2e1*_t22;
  const double _t106 = _t21*_t53;
  const double _t108 = _t107*_t35;
  const double _t109 = (0.1e1 / 0.9e1)*_t10;
  const double _t111 = _t54*_t55;
  const double _t113 = _t28*_t60;
  const double _t114 = (0.1e1 / 0.3e1)*_t113;
  const double _t115 = (0.4e1 / 0.9e1)*_t62;
  const double _t117 = _t12*_t93;
  const double _t120 = _t119*_t74;
  const double _t121 = _t120*ta;
  const double _t122 = _t119*_t80;
  const double _t123 = _t122*ta;
  const double _t124 = _t27*_t46;
  const double _t125 = _t119*_t85;
  const double _t126 = _t125*ta;
  const double _t127 = _t35*_t45;
  const double _t128 = (0.10e2 / 0.9e1)*_t121 - 0.40e2 / 0.9e1*_t123 + (0.11e2 / 0.9e1)*_t124 + (0.280e3 / 0.81e2)*_t126 - 0.44e2 / 0.27e2*_t127;
  const double _t129 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t136 = _hc0[3]*_t43;
  const double _t138 = (0.56e2 / 0.27e2)*_t86;
  const double _t139 = xc_powr(_hc0[0], -11, 3);
  const double _t65 = _hc1[3]*_t64;
  const double _t66 = 0.3e1*_hc1[1];
  const double _t67 = _hc1[2]*na;
  const double _t68 = _t10*_t67;
  const double _t94 = _hc1[3]*_t18;
  const double _t95 = 0.2e1*_hc1[1];
  const double _t98 = _hc1[2]*_t37;
  const double _t110 = _hc1[3]*_t56;
  const double _t112 = _t110*_t111;
  const double _t116 = _hc1[2]*_t51;
  const double _t131 = _hc1[3]*_t130;
  const double _t132 = _t129*_t131;
  const double _t133 = (0.1e1 / 0.9e1)*_t132*_t83;
  const double _t135 = _hc1[1]*_t134;
  const double _t140 = _t139*_t57;
  const double _t141 = (0.4e1 / 0.9e1)*_t137*_t140*_t83;
  const double d3F_dna3 = 0.3e1*_t19 + _t37*_t66 + _t37*_t68 + _t38*_t92 + _t65*na + _t68*_t69;
  const double d3F_dna2_dta = _t105*_t38 - _t39*_t41*_t93 - _t42*_t94 - _t42*_t98 + _t51*_t95 + _t68*_t97;
  const double d3F_dna_dta2 = _t106*_t59 - _t107*_t61 + _t108*_t63 + _t109*_t112 - _t114*_t41 + _t115*_t41 - _t116*_t117 + _t128*_t38;
  const double d3F_dta3 = (0.8e1 / 0.3e1)*_hc0[1]*_hc0[2]*_hc1[1]*_t134*_t3*_t31*_t4 + (0.1e1 / 0.3e1)*_hc0[1]*_hc0[2]*_hc1[2]*_t137*_t45*_t55*_t56 - _t133*_t71 - _t135*_t136*_t5 - _t135*_t138 - _t141*_t45;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
#endif
#if _KMAX >= 4
  const double _t145 = xc_powi(na, -6);
  const double _t146 = (ta * ta * ta * ta)/xc_powi(na, 11);
  const double _t148 = _t77/xc_powr(na, 28, 3);
  const double _t150 = _t13*_t146;
  const double _t156 = _t24/xc_powr(na, 23, 3);
  const double _t163 = _t77/xc_powi(na, 10);
  const double _t164 = _t24*_t76;
  const double _t168 = _t99*ta;
  const double _t169 = xc_powi(na, -9);
  const double _t170 = _t169*_t24;
  const double _t171 = xc_powr(na, -16, 3);
  const double _t175 = ta/xc_powi(na, 8);
  const double _t177 = xc_powr(0.18e2, 1, 3)*_t118;
  const double _t147 = _hc0[4]*_t26;
  const double _t149 = _hc0[3]*_t14*_t31;
  const double _t151 = xc_powr(_hc0[0], -13, 3);
  const double _t152 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t153 = _t151*_t152;
  const double _t154 = ((_hc0[2]) * (_hc0[2]));
  const double _t155 = _t154*_t32;
  const double _t157 = _hc0[2]*_t33;
  const double _t158 = _t157*_t84;
  const double _t165 = _t13*_t153;
  const double _t166 = _t13*_t158;
  const double _t173 = _t136*_t5;
  const double _t142 = 0.4e1*_t41;
  const double _t143 = _t94*na;
  const double _t144 = _t37*_t67;
  const double _t159 = _hc1[3]*_t10;
  const double _t160 = _t159*_t42;
  const double _t161 = _t51*_t67;
  const double _t162 = _hc1[2]*_t16;
  const double _t167 = _t10*_t110;
  const double _t172 = _hc1[1]*_t171;
  const double _t174 = _t134*_t41;
  const double _t176 = _hc1[1]*_t145;
  const double _t178 = _t177*_t58;
  const double d4F_dna4 = 0.4e1*_hc1[1]*_t92 + _hc1[4]*(_t10 * _t10 * _t10 * _t10)*na + _t142*_t37 + _t142*_t69 + _t143*_t37 + _t143*_t69 + _t143*((0.2e1 / 0.3e1)*_t20 - 0.50e2 / 0.9e1*_t23 - 0.25e2 / 0.9e1*_t30 + (0.100e3 / 0.27e2)*_t36) + _t144*_t69 + (_t37 * _t37)*_t67 + _t38*((0.140e3 / 0.81e2)*_t134*_t6 - 0.9440e4 / 0.243e3*_t145*_t15*ta - 0.2500e4 / 0.243e3*_t146*_t147 + (0.40000e5 / 0.729e3)*_t146*_t149 + (0.10000e5 / 0.243e3)*_t146*_t155 - 0.13000e5 / 0.243e3*_t148*_t75 + (0.52000e5 / 0.243e3)*_t148*_t81 - 0.364000e6 / 0.2187e4*_t148*_t86 + (0.700000e6 / 0.6561e4)*_t150*_t153 - 0.140000e6 / 0.729e3*_t150*_t158 - 0.16600e5 / 0.243e3*_t156*_t28 + (0.66400e5 / 0.729e3)*_t156*_t35) + 0.4e1*_t65 + 0.2e1*_t68*_t92 + _t68*(-0.28e2 / 0.27e2*_t70 + (0.1240e4 / 0.81e2)*_t73 + (0.500e3 / 0.81e2)*_t79 - 0.2000e4 / 0.81e2*_t82 + (0.14000e5 / 0.729e3)*_t87 + (0.50e2 / 0.3e1)*_t90 - 0.200e3 / 0.9e1*_t91);
  const double d4F_dna3_dta = -_hc1[4]*_t42*_t64 + _t105*_t66 + _t105*_t68 + _t143*((0.5e1 / 0.3e1)*_t48 - 0.20e2 / 0.9e1*_t50 + 0.2e1*_t96) + _t144*_t51 - _t160*_t37 - _t160*_t69 + _t161*_t69 - 0.1e1 / 0.3e1*_t162*_t92 + _t38*((0.1970e4 / 0.81e2)*_t102*_t88 + (0.500e3 / 0.81e2)*_t147*_t163 - 0.8000e4 / 0.243e3*_t149*_t163 - 0.2000e4 / 0.81e2*_t155*_t163 - 0.140000e6 / 0.2187e4*_t163*_t165 + (0.28000e5 / 0.243e3)*_t163*_t166 + (0.700e3 / 0.27e2)*_t164*_t75 - 0.2800e4 / 0.27e2*_t164*_t81 + (0.19600e5 / 0.243e3)*_t164*_t86 - 0.7880e4 / 0.243e3*_t49*_t88 + 0.8e1*_t72) - _t40*_t94 - _t40*_t98 + 0.3e1*_t41*_t97 + _t68*((0.400e3 / 0.27e2)*_hc0[1]*_hc0[2]*_t24*_t3*_t31*_t4*_t99 + (0.800e3 / 0.81e2)*_t1*_t25*_t31*_t33*_t4*_t7*ta - 0.100e3 / 0.27e2*_t101 - 0.200e3 / 0.27e2*_t103 - 0.2800e4 / 0.243e3*_t104 - 0.4e1*_t22);
  const double d4F_dna2_dta2 = -_hc0[2]*_t1*_t107*_t13*_t41*_t43 - _hc1[2]*_t105*_t117 + (0.1e1 / 0.9e1)*_hc1[4]*_t111*_t18*_t56 + (0.2e1 / 0.9e1)*_t106*_t167*_t55 + (0.8e1 / 0.9e1)*_t108*_t41 + (0.1e1 / 0.9e1)*_t112*_t37 - _t114*_t94 - _t114*_t98 + _t115*_t94 + _t115*_t98 - 0.4e1 / 0.3e1*_t116*_t40 - _t117*_t159*_t97 + _t128*_t95 + _t161*_t97 + _t38*((0.400e3 / 0.9e1)*_hc0[1]*_hc0[2]*_t3*_t31*_t4*_t99*ta + (0.1600e4 / 0.81e2)*_hc0[1]*_hc0[3]*_t169*_t24*_t31*_t4*_t7 + (0.616e3 / 0.81e2)*_t1*_t25*_t31*_t33*_t4*_t7 - 0.100e3 / 0.27e2*_t147*_t170 + (0.28000e5 / 0.729e3)*_t151*_t152*_t169*_t24*_t4*_t7 + (0.400e3 / 0.27e2)*_t154*_t169*_t24*_t31*_t4*_t7 - 0.5600e4 / 0.81e2*_t166*_t170 - 0.100e3 / 0.9e1*_t168*_t75 - 0.2800e4 / 0.81e2*_t168*_t86 - 0.154e3 / 0.27e2*_t29) + _t68*((0.20e2 / 0.9e1)*_t121 - 0.80e2 / 0.9e1*_t123 + (0.22e2 / 0.9e1)*_t124 + (0.560e3 / 0.81e2)*_t126 - 0.88e2 / 0.27e2*_t127);
  const double d4F_dna_dta3 = (0.8e1 / 0.3e1)*_hc0[1]*_hc0[2]*_hc1[1]*_t171*_t3*_t31*_t4 + (0.8e1 / 0.3e1)*_hc0[1]*_hc0[2]*_hc1[2]*_t10*_t134*_t3*_t31*_t4 + (0.1e1 / 0.3e1)*_hc0[1]*_hc0[2]*_hc1[2]*_t137*_t25*_t55*_t56 + (0.1e1 / 0.3e1)*_hc0[1]*_hc0[2]*_hc1[3]*_t10*_t137*_t45*_t55*_t56 + _hc1[1]*na*((0.32e2 / 0.9e1)*_t120 - 0.128e3 / 0.9e1*_t122 + (0.896e3 / 0.81e2)*_t125 + (0.20e2 / 0.9e1)*_t147*_t175 - 0.320e3 / 0.27e2*_t149*_t175 - 0.80e2 / 0.9e1*_t155*_t175 - 0.5600e4 / 0.243e3*_t165*_t175 + (0.1120e4 / 0.27e2)*_t166*_t175) + (0.4e1 / 0.3e1)*_hc1[2]*_t1*_t31*_t33*_t4*_t51*_t60*_t7 + (0.1e1 / 0.3e1)*_hc1[3]*_t33*_t51*_t52*_t55*_t56*_t9 - _hc1[4]*_t109*_t129*_t130*_t71*_t83 - _t113*_t116 - _t128*_t162 - _t133*_t145 - 0.4e1 / 0.9e1*_t137*_t139*_t167*_t45*_t83 - _t138*_t172 - _t138*_t174 - _t141*_t25 - _t172*_t173 - _t173*_t174;
  const double d4F_dta4 = (0.8e1 / 0.9e1)*_hc0[1]*_hc0[3]*_t178 - 0.2e1 / 0.3e1*_hc0[2]*_t132*_t34*_t88 - 0.16e2 / 0.3e1*_t140*_t157*_t177 - 0.4e1 / 0.3e1*_t147*_t176 + (0.64e2 / 0.9e1)*_t149*_t176 + (0.2e1 / 0.3e1)*_t154*_t178 + (0.16e2 / 0.3e1)*_t155*_t176 + (0.1120e4 / 0.81e2)*_t165*_t176 - 0.224e3 / 0.9e1*_t166*_t176 + (0.8e1 / 0.9e1)*_t1*_t131*_t152*_t88/xc_powi((_hc0[0]), 5) + (0.320e3 / 0.81e2)*_t152*_t177*_t57/xc_powr(_hc0[0], 14, 3) + (0.1e1 / 0.27e2)*_hc1[4]*_t152*_t7/((M_PI * M_CBRTPI)*xc_powr(_hc0[0], 16, 3)*xc_powi(na, 7));
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double ta = tau[0];
  const double tb = tau[1];

  const double _t1 = xc_powr(na, -5, 3);
  const double _t2 = _t1*ta;
  const double _t3 = xc_powr(nb, -5, 3);
  const double _t7 = xc_powr(0.6e1, 1, 3);
  const double _t8 = (0.1e1 / (M_CBRTPI));
  const double _t9 = _t7*_t8;
  const double _t10 = (0.1e1 / 0.2e1)*_t9;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(nt_tau_k, _KMAX)(p, _t2, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(nt_tau_k, _KMAX)(p, _t3*tb, _hc1);
  const double _t4 = _hc0[0]*na;
  const double _t5 = _hc1[0]*nb;
  const double _t6 = _t4 + _t5;
  const double _t11 = _t4 - _t5;
  const double _t12 = (0.1e1 / _t6);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, _t10/xc_powr(_t6, 1, 3), _t11*_t12, _hc2);
  const double zk = _hc2[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t13 = na + nb;
  const double _t31 = xc_powr(na, -2, 3);
  const double _t38 = xc_powr(nb, -2, 3);
  const double _t14 = -0.1e1 / 0.3e1*_hc0[0] + (0.5e1 / 0.9e1)*_hc0[1]*_t1*ta;
  const double _t16 = xc_powr(_t6, -4, 3);
  const double _t17 = _t10*_t16;
  const double _t18 = _hc0[0] - 0.5e1 / 0.3e1*_hc0[1]*_t2;
  const double _t19 = -_t18;
  const double _t20 = (0.1e1 / (_t6 * _t6));
  const double _t21 = _t11*_t20;
  const double _t22 = _t12*_t18 + _t19*_t21;
  const double _t25 = -0.1e1 / 0.3e1*_hc1[0] + (0.5e1 / 0.9e1)*_hc1[1]*_t3*tb;
  const double _t27 = -_hc1[0] + (0.5e1 / 0.3e1)*_hc1[1]*_t3*tb;
  const double _t28 = _t12*_t27 + _t21*_t27;
  const double _t32 = _hc0[1]*_t31;
  const double _t33 = _t16*_t9;
  const double _t37 = _hc0[1]*_t12*_t31 - _t21*_t32;
  const double _t39 = _hc1[1]*_t38;
  const double _t41 = -_t12*_t39 - _t21*_t39;
  const double _t15 = _hc2[2]*_t14;
  const double _t23 = _hc2[1]*_t22;
  const double _t24 = _t15*_t17 + _t23;
  const double _t26 = _hc2[2]*_t17;
  const double _t29 = _hc2[1]*_t28;
  const double _t30 = _t25*_t26 + _t29;
  const double _t34 = _hc2[2]*_t33;
  const double _t35 = (0.1e1 / 0.6e1)*_t34;
  const double _t36 = _t32*_t35;
  const double _t40 = _t35*_t39;
  const double dF_dna = _hc2[0] + _t13*_t24;
  const double dF_dnb = _hc2[0] + _t13*_t30;
  const double dF_dta = _t13*(_hc2[1]*_t37 - _t36);
  const double dF_dtb = _t13*(_hc2[1]*_t41 - _t40);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 1] += dF_dtb;
#endif
#if _KMAX >= 2
  const double _t42 = xc_powr(na, -8, 3);
  const double _t45 = (ta * ta);
  const double _t80 = xc_powr(nb, -8, 3);
  const double _t83 = (tb * tb);
  const double _t145 = xc_powr(na, -7, 3);
  const double _t149 = xc_powr(na, -4, 3);
  const double _t163 = xc_powr(nb, -7, 3);
  const double _t166 = xc_powr(nb, -4, 3);
  const double _t43 = _hc0[1]*_t42;
  const double _t44 = (0.10e2 / 0.27e2)*_t43;
  const double _t46 = _hc0[2]/xc_powr(na, 13, 3);
  const double _t47 = _t45*_t46;
  const double _t48 = -_t44*ta - 0.25e2 / 0.27e2*_t47;
  const double _t49 = xc_powr(_t6, -7, 3);
  const double _t50 = _t10*_t49;
  const double _t51 = -0.4e1 / 0.3e1*_hc0[0] + (0.20e2 / 0.9e1)*_hc0[1]*_t1*ta;
  const double _t53 = _t14*_t17;
  const double _t57 = (0.10e2 / 0.9e1)*_t43;
  const double _t58 = (0.25e2 / 0.9e1)*_t47 + _t57*ta;
  const double _t59 = 0.2e1*_t20;
  const double _t60 = _t18*_t59;
  const double _t61 = -_t58;
  const double _t62 = (0.1e1 / (_t6 * _t6 * _t6));
  const double _t63 = _t11*_t62;
  const double _t64 = -0.2e1*_hc0[0] + (0.10e2 / 0.3e1)*_hc0[1]*_t1*ta;
  const double _t65 = _t19*_t64;
  const double _t66 = _t12*_t58 + _t19*_t60 + _t21*_t61 + _t63*_t65;
  const double _t69 = -0.4e1 / 0.3e1*_hc1[0] + (0.20e2 / 0.9e1)*_hc1[1]*_t3*tb;
  const double _t70 = _t50*_t69;
  const double _t71 = _t20*_t27;
  const double _t72 = -0.2e1*_hc1[0] + (0.10e2 / 0.3e1)*_hc1[1]*_t3*tb;
  const double _t73 = _t63*_t72;
  const double _t74 = _t18*_t71 + _t19*_t71 + _t19*_t73;
  const double _t76 = _t17*_t25;
  const double _t81 = _hc1[1]*_t80;
  const double _t82 = (0.10e2 / 0.27e2)*_t81;
  const double _t84 = _hc1[2]/xc_powr(nb, 13, 3);
  const double _t85 = _t83*_t84;
  const double _t86 = -_t82*tb - 0.25e2 / 0.27e2*_t85;
  const double _t87 = _t25*_t70;
  const double _t88 = (_t27 * _t27);
  const double _t89 = (0.10e2 / 0.9e1)*_t81;
  const double _t90 = -0.25e2 / 0.9e1*_t85 - _t89*tb;
  const double _t91 = _t12*_t90 + _t21*_t90 + _t27*_t73 + _t59*_t88;
  const double _t95 = _hc0[1]*_t1;
  const double _t96 = _hc0[2]/xc_powr(na, 10, 3);
  const double _t97 = _t96*ta;
  const double _t98 = (0.2e1 / 0.9e1)*_t95 + (0.5e1 / 0.9e1)*_t97;
  const double _t99 = _t49*_t9;
  const double _t102 = (0.1e1 / 0.6e1)*_t33;
  const double _t108 = (0.2e1 / 0.3e1)*_t95 + (0.5e1 / 0.3e1)*_t97;
  const double _t109 = -_t108;
  const double _t110 = _t20*_t32;
  const double _t111 = _t19*_t63;
  const double _t112 = 0.2e1*_t111;
  const double _t113 = _t108*_t21 + _t109*_t12 - _t110*_t18 + _t110*_t19 - _t112*_t32;
  const double _t117 = _t20*_t39;
  const double _t118 = -_t112*_t39 - _t117*_t18 - _t117*_t19;
  const double _t121 = _t102*_t39;
  const double _t127 = (0.2e1 / 0.3e1)*_t99;
  const double _t130 = _t27*_t63;
  const double _t131 = 0.2e1*_t32;
  const double _t132 = _t130*_t131;
  const double _t134 = _hc1[1]*_t3;
  const double _t135 = _hc1[2]/xc_powr(nb, 10, 3);
  const double _t136 = _t135*tb;
  const double _t137 = (0.2e1 / 0.9e1)*_t134 + (0.5e1 / 0.9e1)*_t136;
  const double _t139 = (0.2e1 / 0.3e1)*_t134 + (0.5e1 / 0.3e1)*_t136;
  const double _t140 = 0.2e1*_t71;
  const double _t141 = 0.2e1*_t39;
  const double _t142 = _t11*_t139*_t20 + _t12*_t139 - _t130*_t141 - _t140*_t39;
  const double _t146 = _hc0[2]*_t145;
  const double _t147 = (0.2e1 / 0.9e1)*_t99;
  const double _t148 = ((_hc0[1]) * (_hc0[1]));
  const double _t150 = _t148*_t149;
  const double _t152 = 0.2e1*_t63;
  const double _t153 = _t12*_t146 - _t146*_t21 + _t150*_t152 - _t150*_t59;
  const double _t155 = (0.1e1 / 0.6e1)*_t32;
  const double _t157 = _t32*_t39;
  const double _t158 = _t147*_t157;
  const double _t159 = _t152*_t39;
  const double _t164 = _hc1[2]*_t163;
  const double _t165 = ((_hc1[1]) * (_hc1[1]));
  const double _t167 = _t165*_t166;
  const double _t168 = _t147*_t167;
  const double _t169 = -_t12*_t164 + _t152*_t167 - _t164*_t21 + _t167*_t59;
  const double _t52 = _t15*_t51;
  const double _t54 = _hc2[4]*_t22 + _hc2[5]*_t53;
  const double _t55 = _hc2[3]*_t22 + _hc2[4]*_t53;
  const double _t56 = _t22*_t55;
  const double _t67 = _hc2[1]*_t66;
  const double _t68 = _t26*_t48 + _t50*_t52 + _t53*_t54 + _t56 + _t67;
  const double _t75 = _hc2[1]*_t74;
  const double _t77 = _hc2[4]*_t28 + _hc2[5]*_t76;
  const double _t78 = _hc2[3]*_t28 + _hc2[4]*_t76;
  const double _t79 = _t22*_t78;
  const double _t92 = _hc2[1]*_t91;
  const double _t93 = _t28*_t78;
  const double _t94 = _hc2[2]*_t87 + _t26*_t86 + _t76*_t77 + _t92 + _t93;
  const double _t100 = _t15*_t99;
  const double _t101 = (0.2e1 / 0.3e1)*_t100;
  const double _t103 = _hc2[5]*_t102;
  const double _t104 = _hc2[4]*_t37 - _t103*_t32;
  const double _t105 = _hc2[4]*_t32;
  const double _t106 = _hc2[3]*_t37 - _t102*_t105;
  const double _t107 = _t106*_t22;
  const double _t114 = _hc2[1]*_t113;
  const double _t115 = -_t101*_t32 + _t104*_t53 + _t107 + _t114 + _t26*_t98;
  const double _t116 = _hc2[1]*_t37 - _t36;
  const double _t119 = _hc2[1]*_t118;
  const double _t120 = _hc2[4]*_t41 - _t103*_t39;
  const double _t122 = _hc2[3]*_t41 - _hc2[4]*_t121;
  const double _t123 = _t122*_t22;
  const double _t124 = -_t101*_t39 + _t119 + _t120*_t53 + _t123;
  const double _t125 = _hc2[1]*_t41 - _t40;
  const double _t126 = _hc2[2]*_t25;
  const double _t128 = _t126*_t127;
  const double _t129 = _t128*_t32;
  const double _t133 = _hc2[1]*_t132;
  const double _t138 = _t122*_t28;
  const double _t143 = _hc2[1]*_t142;
  const double _t144 = _t120*_t76 - _t128*_t39 + _t137*_t26 + _t138 + _t143;
  const double _t151 = _hc2[2]*_t150;
  const double _t154 = _t104*_t33;
  const double _t156 = _hc2[1]*_t153 + _t106*_t37 - _t146*_t35 + _t147*_t151 - _t154*_t155;
  const double _t160 = _hc2[1]*_t32;
  const double _t161 = _t120*_t33;
  const double _t162 = _hc2[2]*_t158 + _t122*_t37 - _t155*_t161 + _t159*_t160;
  const double _t170 = (0.1e1 / 0.6e1)*_t161;
  const double _t171 = _hc2[1]*_t169 + _hc2[2]*_t168 + _t122*_t41 - _t164*_t35 - _t170*_t39;
  const double d2F_dna2 = _t13*_t68 + _t15*_t33 + 0.2e1*_t23;
  const double d2F_dna_dnb = _t13*(_t15*_t70 + _t53*_t77 + _t75 + _t79) + _t24 + _t30;
  const double d2F_dnb2 = _t13*_t94 + _t25*_t34 + 0.2e1*_t29;
  const double d2F_dna_dta = _t115*_t13 + _t116;
  const double d2F_dna_dtb = _t124*_t13 + _t125;
  const double d2F_dnb_dta = _t116 + _t13*((0.1e1 / 0.2e1)*_t104*_t16*_t25*_t7*_t8 + _t106*_t28 - _t129 - _t133);
  const double d2F_dnb_dtb = _t125 + _t13*_t144;
  const double d2F_dta2 = _t13*_t156;
  const double d2F_dta_dtb = _t13*_t162;
  const double d2F_dtb2 = _t13*_t171;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 1] += d2F_dna_dtb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 2] += d2F_dnb_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 3] += d2F_dnb_dtb;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 1] += d2F_dta_dtb;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 2] += d2F_dtb2;
#endif
#if _KMAX >= 3
  const double _t177 = xc_powr(na, -11, 3);
  const double _t180 = xc_powr(na, -16, 3);
  const double _t183 = xc_powi(na, -7);
  const double _t184 = (ta * ta * ta);
  const double _t274 = xc_powr(nb, -11, 3);
  const double _t277 = xc_powr(nb, -16, 3);
  const double _t280 = xc_powi(nb, -7);
  const double _t281 = (tb * tb * tb);
  const double _t302 = xc_powi(na, -6);
  const double _t401 = xc_powi(nb, -6);
  const double _t501 = (0.1e1 / (na * na * na * na));
  const double _t503 = (0.1e1 / (na * na * na));
  const double _t507 = (0.1e1 / (na * na));
  const double _t533 = (0.1e1 / (nb * nb * nb));
  const double _t173 = _t51*_t99;
  const double _t175 = _t14*_t33;
  const double _t178 = _hc0[1]*_t177;
  const double _t179 = (0.80e2 / 0.81e2)*_t178;
  const double _t181 = _hc0[2]*_t45;
  const double _t182 = _t180*_t181;
  const double _t185 = _hc0[3]*_t184;
  const double _t186 = _t183*_t185;
  const double _t187 = _t179*ta + (0.125e3 / 0.27e2)*_t182 + (0.125e3 / 0.81e2)*_t186;
  const double _t190 = (0.40e2 / 0.27e2)*_t43;
  const double _t191 = -_t190*ta - 0.100e3 / 0.27e2*_t47;
  const double _t193 = xc_powr(_t6, -10, 3);
  const double _t194 = _t10*_t193;
  const double _t195 = -0.7e1 / 0.3e1*_hc0[0] + (0.35e2 / 0.9e1)*_hc0[1]*_t1*ta;
  const double _t197 = _t33*_t48;
  const double _t199 = _t14*_t173;
  const double _t201 = 0.2e1*_t66;
  const double _t202 = (0.80e2 / 0.27e2)*_t178;
  const double _t203 = (0.125e3 / 0.9e1)*_t182 + (0.125e3 / 0.27e2)*_t186 + _t202*ta;
  const double _t204 = -_t203;
  const double _t205 = 0.3e1*_t20;
  const double _t206 = _t18*_t61;
  const double _t207 = _t19*_t205;
  const double _t208 = _t62*_t65;
  const double _t209 = 0.3e1*_t18;
  const double _t210 = (0.20e2 / 0.9e1)*_t43;
  const double _t211 = -_t210*ta - 0.50e2 / 0.9e1*_t47;
  const double _t212 = _t61*_t63;
  const double _t213 = 0.2e1*_t212;
  const double _t214 = -0.3e1*_hc0[0] + 0.5e1*_hc0[1]*_t1*ta;
  const double _t215 = (0.1e1 / (_t6 * _t6 * _t6 * _t6));
  const double _t216 = _t11*_t215;
  const double _t217 = _t216*_t65;
  const double _t218 = _t111*_t211 + _t12*_t204 + _t203*_t21 + _t205*_t206 + _t207*_t58 + _t208*_t209 + _t213*_t64 + _t214*_t217;
  const double _t220 = _t17*_t48;
  const double _t221 = _t50*_t51;
  const double _t231 = -0.7e1 / 0.3e1*_hc1[0] + (0.35e2 / 0.9e1)*_hc1[1]*_t3*tb;
  const double _t232 = _t194*_t231;
  const double _t233 = _t14*_t70;
  const double _t237 = _t62*_t72;
  const double _t238 = _t18*_t237;
  const double _t239 = 0.2e1*_t19;
  const double _t240 = _t27*_t62;
  const double _t241 = -0.3e1*_hc1[0] + 0.5e1*_hc1[1]*_t3*tb;
  const double _t242 = _t217*_t241 + _t238*_t239 + _t240*_t65 + _t58*_t71 + _t61*_t71 + _t61*_t73;
  const double _t251 = _t69*_t99;
  const double _t253 = (0.40e2 / 0.27e2)*_t81;
  const double _t254 = -_t253*tb - 0.100e3 / 0.27e2*_t85;
  const double _t255 = _t232*_t69;
  const double _t259 = _t20*_t90;
  const double _t260 = _t240*_t72;
  const double _t261 = (0.20e2 / 0.9e1)*_t81;
  const double _t262 = -_t261*tb - 0.50e2 / 0.9e1*_t85;
  const double _t263 = _t241*_t72;
  const double _t264 = _t19*_t216;
  const double _t265 = _t111*_t262 + _t18*_t259 + _t18*_t260 + _t19*_t259 + _t239*_t260 + _t263*_t264;
  const double _t267 = _t17*_t86;
  const double _t271 = _t25*_t251;
  const double _t275 = _hc1[1]*_t274;
  const double _t276 = (0.80e2 / 0.81e2)*_t275;
  const double _t278 = _hc1[2]*_t83;
  const double _t279 = _t277*_t278;
  const double _t282 = _hc1[3]*_t281;
  const double _t283 = _t280*_t282;
  const double _t284 = _t276*tb + (0.125e3 / 0.27e2)*_t279 + (0.125e3 / 0.81e2)*_t283;
  const double _t285 = _t251*_t86;
  const double _t287 = _t254*_t50;
  const double _t290 = _t62*_t88;
  const double _t291 = (0.80e2 / 0.27e2)*_t275;
  const double _t292 = (0.125e3 / 0.9e1)*_t279 + (0.125e3 / 0.27e2)*_t283 + _t291*tb;
  const double _t293 = 0.2e1*_t90;
  const double _t294 = _t216*_t263;
  const double _t295 = _t12*_t292 + _t130*_t262 + _t140*_t262 + _t140*_t90 + _t21*_t292 + _t27*_t294 + _t290*(-0.6e1*_hc1[0] + 0.10e2*_hc1[1]*_t3*tb) + _t293*_t73;
  const double _t300 = _t127*_t32;
  const double _t301 = _t46*ta;
  const double _t303 = _hc0[3]*_t45;
  const double _t304 = _t302*_t303;
  const double _t305 = -0.20e2 / 0.9e1*_t301 - 0.25e2 / 0.27e2*_t304 - _t44;
  const double _t307 = (0.8e1 / 0.9e1)*_t95 + (0.20e2 / 0.9e1)*_t97;
  const double _t308 = (0.7e1 / 0.6e1)*_t32;
  const double _t309 = _t193*_t9;
  const double _t311 = _t14*_t221;
  const double _t312 = _t17*_t98;
  const double _t316 = _t102*_t32;
  const double _t320 = (0.20e2 / 0.3e1)*_t301 + (0.25e2 / 0.9e1)*_t304 + _t57;
  const double _t321 = 0.4e1*_t19;
  const double _t322 = _t18*_t62;
  const double _t323 = _t321*_t322;
  const double _t324 = _t19*_t59;
  const double _t325 = -_t320;
  const double _t326 = _t108*_t63;
  const double _t327 = (0.4e1 / 0.3e1)*_t95 + (0.10e2 / 0.3e1)*_t97;
  const double _t328 = 0.3e1*_t217;
  const double _t329 = _t108*_t60 + _t109*_t324 - _t110*_t58 + _t110*_t61 + _t111*_t327 + _t12*_t320 + _t208*_t32 + _t21*_t325 - _t213*_t32 - _t32*_t323 - _t32*_t328 + _t326*_t64;
  const double _t336 = _t127*_t39;
  const double _t337 = (0.7e1 / 0.6e1)*_t39;
  const double _t341 = -_t117*_t58 - _t117*_t61 - _t208*_t39 - _t213*_t39 - _t323*_t39 - _t328*_t39;
  const double _t354 = _t18*_t240;
  const double _t355 = _t19*_t237;
  const double _t356 = _t19*_t240;
  const double _t357 = 0.2e1*_t356;
  const double _t358 = _t32*_t72;
  const double _t359 = 0.3e1*_t264;
  const double _t360 = _t108*_t71 + _t108*_t73 + _t109*_t71 - _t131*_t354 + _t32*_t355 - _t32*_t357 - _t358*_t359;
  const double _t367 = (0.8e1 / 0.9e1)*_t134 + (0.20e2 / 0.9e1)*_t136;
  const double _t370 = (0.4e1 / 0.3e1)*_t134 + (0.10e2 / 0.3e1)*_t136;
  const double _t371 = _t39*_t72;
  const double _t372 = _t11*_t19*_t370*_t62 + _t139*_t18*_t20 + _t139*_t19*_t20 - _t141*_t354 - _t355*_t39 - _t357*_t39 - _t359*_t371;
  const double _t374 = _t137*_t17;
  const double _t376 = _t25*_t336;
  const double _t379 = (0.4e1 / 0.3e1)*_t99;
  const double _t381 = 0.4e1*_t32;
  const double _t382 = _t130*_t381;
  const double _t383 = _t25*_t33;
  const double _t386 = _t309*_t69;
  const double _t387 = (0.7e1 / 0.6e1)*_t386;
  const double _t388 = _t25*_t300;
  const double _t389 = _t130*_t32;
  const double _t390 = 0.4e1*_t290;
  const double _t391 = _t152*_t90;
  const double _t392 = _t216*_t27;
  const double _t393 = 0.3e1*_t392;
  const double _t394 = _hc0[1]*_t27*_t31*_t62*_t72 - _t32*_t390 - _t32*_t391 - _t358*_t393;
  const double _t399 = _t379*_t39;
  const double _t400 = _t84*tb;
  const double _t402 = _hc1[3]*_t83;
  const double _t403 = _t401*_t402;
  const double _t404 = -0.20e2 / 0.9e1*_t400 - 0.25e2 / 0.27e2*_t403 - _t82;
  const double _t407 = _t337*_t386;
  const double _t410 = _t39*_t59;
  const double _t411 = -0.20e2 / 0.3e1*_t400 - 0.25e2 / 0.9e1*_t403 - _t89;
  const double _t412 = _t11*_t139*_t62*_t72 + _t11*_t20*_t411 + _t11*_t27*_t370*_t62 + _t12*_t411 + 0.2e1*_t20*_t27*_t370 - _t260*_t39 - _t371*_t393 - _t39*_t390 - _t39*_t391 - _t410*_t90;
  const double _t416 = _hc0[3]/xc_powi(na, 5);
  const double _t417 = _t416*ta;
  const double _t418 = (0.5e1 / 0.9e1)*_t417 + (0.7e1 / 0.9e1)*_t96;
  const double _t420 = _t32*_t379;
  const double _t421 = _t33*_t98;
  const double _t425 = (0.5e1 / 0.3e1)*_t417 + (0.7e1 / 0.3e1)*_t96;
  const double _t426 = -_t425;
  const double _t427 = _t146*_t20;
  const double _t428 = _t150*_t62;
  const double _t429 = 0.2e1*_t18;
  const double _t430 = _t32*_t59;
  const double _t431 = 0.6e1*_t150;
  const double _t432 = _t108*_t430 - _t109*_t430 - _t112*_t146 + _t12*_t426 - _t18*_t427 + _t19*_t427 + _t21*_t425 + _t264*_t431 - _t321*_t428 - _t326*_t381 + _t428*_t429;
  const double _t434 = _t147*_t150;
  const double _t441 = 0.2e1*_t326;
  const double _t442 = 0.6e1*_hc0[1]*_hc1[1]*_t11*_t19*_t215*_t31*_t38 + 0.2e1*_hc0[1]*_hc1[1]*_t18*_t31*_t38*_t62 - _t108*_t117 - _t109*_t117 - _t39*_t441;
  const double _t446 = _t147*_t39;
  const double _t447 = _t159*_t32;
  const double _t452 = _t164*_t20;
  const double _t453 = _t167*_t62;
  const double _t454 = 0.6e1*_t167;
  const double _t455 = -_t112*_t164 - _t18*_t452 - _t19*_t452 + _t264*_t454 + _t321*_t453 + _t429*_t453;
  const double _t461 = _t150*_t240;
  const double _t465 = _t130*_t146;
  const double _t471 = _t240*_t32;
  const double _t472 = _t141*_t471;
  const double _t474 = (0.14e2 / 0.9e1)*_t309;
  const double _t475 = _t157*_t474;
  const double _t476 = _t152*_t32;
  const double _t477 = _t139*_t476;
  const double _t478 = 0.6e1*_t216;
  const double _t479 = _t32*_t478;
  const double _t480 = _t27*_t39;
  const double _t481 = _t479*_t480;
  const double _t485 = _hc1[3]/xc_powi(nb, 5);
  const double _t486 = _t485*tb;
  const double _t487 = (0.7e1 / 0.9e1)*_t135 + (0.5e1 / 0.9e1)*_t486;
  const double _t488 = _t167*_t474;
  const double _t489 = _t137*_t33;
  const double _t492 = (0.7e1 / 0.3e1)*_t135 + (0.5e1 / 0.3e1)*_t486;
  const double _t493 = _t139*_t20;
  const double _t494 = 0.4e1*_t39;
  const double _t495 = 0.2e1*_t164;
  const double _t496 = _t139*_t494;
  const double _t497 = _t12*_t492 - _t130*_t495 - _t140*_t164 + _t21*_t492 + _t240*_t454 + _t392*_t454 - _t493*_t494 - _t496*_t63;
  const double _t502 = _hc0[3]*_t501;
  const double _t504 = _hc0[1]*_hc0[2]*_t503;
  const double _t505 = (0.14e2 / 0.27e2)*_t309;
  const double _t506 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t508 = _t506*_t507;
  const double _t510 = (0.1e1 / 0.3e1)*_t146;
  const double _t511 = (0.4e1 / 0.9e1)*_t99;
  const double _t513 = 0.6e1*_t20;
  const double _t514 = 0.6e1*_hc0[1]*_hc0[2]*_t11*_t503*_t62 + _hc0[3]*_t12*_t501 - _t21*_t502 - _t478*_t508 - _t504*_t513 + 0.6e1*_t506*_t507*_t62;
  const double _t516 = _t146*_t446;
  const double _t518 = _t150*_t478;
  const double _t519 = _t141*_t428 + _t146*_t159 - _t39*_t518;
  const double _t520 = _t157*_t63;
  const double _t522 = _t131*_t453;
  const double _t523 = _t147*_t164;
  const double _t526 = _t167*_t32;
  const double _t527 = _t505*_t526;
  const double _t528 = _t216*_t454;
  const double _t529 = _t157*_t511;
  const double _t532 = _hc1[3]/(nb * nb * nb * nb);
  const double _t534 = _hc1[1]*_hc1[2]*_t533;
  const double _t535 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]))/(nb * nb);
  const double _t536 = _t505*_t535;
  const double _t537 = (0.1e1 / 0.3e1)*_t164;
  const double _t538 = _t167*_t511;
  const double _t539 = 0.6e1*_t62;
  const double _t540 = 0.6e1*_hc1[1]*_hc1[2]*_t11*_t533*_t62 + 0.6e1*_hc1[1]*_hc1[2]*_t20*_t533 - _t12*_t532 - _t21*_t532 - _t478*_t535 - _t535*_t539;
  const double _t172 = (0.3e1 / 0.2e1)*_t34;
  const double _t174 = (0.3e1 / 0.2e1)*_t15;
  const double _t176 = (0.3e1 / 0.2e1)*_t54;
  const double _t188 = _hc2[2]*_t48;
  const double _t189 = _t173*_t188;
  const double _t192 = _t15*_t50;
  const double _t196 = _t195*_t52;
  const double _t198 = _t197*_t54;
  const double _t200 = _t199*_t54;
  const double _t219 = _hc2[1]*_t218;
  const double _t222 = _hc2[5]*_t14;
  const double _t223 = _hc2[8]*_t22 + _hc2[9]*_t53;
  const double _t224 = _hc2[7]*_t22 + _hc2[8]*_t53;
  const double _t225 = _hc2[4]*_t66 + _hc2[5]*_t220 + _t22*_t224 + _t221*_t222 + _t223*_t53;
  const double _t226 = _hc2[4]*_t14;
  const double _t227 = _hc2[6]*_t22 + _hc2[7]*_t53;
  const double _t228 = _hc2[3]*_t66 + _hc2[4]*_t220 + _t22*_t227 + _t221*_t226 + _t224*_t53;
  const double _t229 = _t22*_t228;
  const double _t230 = _t187*_t26 + _t189 + _t191*_t192 + _t194*_t196 + _t198 + _t200 + _t201*_t55 + _t219 + _t225*_t53 + _t229;
  const double _t234 = _t14*_t77;
  const double _t235 = _t55*_t74;
  const double _t236 = _t66*_t78;
  const double _t243 = _hc2[1]*_t242;
  const double _t244 = _hc2[8]*_t28 + _hc2[9]*_t76;
  const double _t245 = _hc2[7]*_t28 + _hc2[8]*_t76;
  const double _t246 = _hc2[4]*_t74 + _t22*_t245 + _t222*_t70 + _t244*_t53;
  const double _t247 = _hc2[6]*_t28 + _hc2[7]*_t76;
  const double _t248 = _hc2[3]*_t74 + _t22*_t247 + _t226*_t70 + _t245*_t53;
  const double _t249 = _t22*_t248;
  const double _t250 = _t33*_t77;
  const double _t252 = _t14*_t250 + _t15*_t251 + 0.2e1*_t75 + 0.2e1*_t79;
  const double _t256 = _t251*_t77;
  const double _t257 = _t14*_t256;
  const double _t258 = 0.2e1*_t78;
  const double _t266 = _hc2[1]*_t265;
  const double _t268 = _hc2[4]*_t91 + _hc2[5]*_t267 + _hc2[5]*_t87 + _t244*_t76 + _t245*_t28;
  const double _t269 = _hc2[3]*_t91 + _hc2[4]*_t267 + _hc2[4]*_t87 + _t245*_t76 + _t247*_t28;
  const double _t270 = _t22*_t269;
  const double _t272 = (0.3e1 / 0.2e1)*_hc2[2];
  const double _t273 = (0.3e1 / 0.2e1)*_t250;
  const double _t286 = _hc2[2]*_t285;
  const double _t288 = _t250*_t86;
  const double _t289 = _t25*_t256;
  const double _t296 = _hc2[1]*_t295;
  const double _t297 = _t269*_t28;
  const double _t298 = _t126*_t255 + _t126*_t287 + _t258*_t91 + _t26*_t284 + _t268*_t76 + _t286 + _t288 + _t289 + _t296 + _t297;
  const double _t299 = (0.4e1 / 0.3e1)*_t100;
  const double _t306 = _hc2[2]*_t98;
  const double _t310 = _t309*_t52;
  const double _t313 = _t14*_t54;
  const double _t314 = _t106*_t66;
  const double _t315 = _t113*_t55;
  const double _t317 = _hc2[8]*_t37 - _hc2[9]*_t316;
  const double _t318 = _hc2[7]*_t37 - _hc2[8]*_t316;
  const double _t319 = _hc2[4]*_t113 + _hc2[5]*_t312 + _t22*_t318 - _t222*_t300 + _t317*_t53;
  const double _t330 = _hc2[1]*_t329;
  const double _t331 = _t105*_t127;
  const double _t332 = _hc2[6]*_t37 - _hc2[7]*_t316;
  const double _t333 = _hc2[3]*_t113 + _hc2[4]*_t312 - _t14*_t331 + _t22*_t332 + _t318*_t53;
  const double _t334 = _t22*_t333;
  const double _t335 = _t104*_t220 + _t104*_t311 - _t188*_t300 + _t192*_t307 + _t221*_t306 + _t26*_t305 - _t300*_t313 - _t308*_t310 + _t312*_t54 + _t314 + _t315 + _t319*_t53 + _t330 + _t334;
  const double _t338 = _t120*_t14;
  const double _t339 = _t118*_t55;
  const double _t340 = _t122*_t66;
  const double _t342 = _hc2[1]*_t341;
  const double _t343 = _hc2[8]*_t41 - _hc2[9]*_t121;
  const double _t344 = _hc2[7]*_t41 - _hc2[8]*_t121;
  const double _t345 = _hc2[4]*_t118 + _t22*_t344 - _t222*_t336 + _t343*_t53;
  const double _t346 = _hc2[6]*_t41 - _hc2[7]*_t121;
  const double _t347 = _hc2[3]*_t118 + _t22*_t346 - _t226*_t336 + _t344*_t53;
  const double _t348 = _t22*_t347;
  const double _t349 = _t120*_t220 - _t188*_t336 + _t221*_t338 - _t310*_t337 - _t313*_t336 + _t339 + _t340 + _t342 + _t345*_t53 + _t348;
  const double _t350 = _t15*_t309;
  const double _t351 = _t350*_t69;
  const double _t352 = _t106*_t74;
  const double _t353 = _t113*_t78;
  const double _t361 = _hc2[1]*_t360;
  const double _t362 = _hc2[5]*_t25;
  const double _t363 = -_hc2[4]*_t132 + (0.1e1 / 0.2e1)*_t16*_t25*_t317*_t7*_t8 + _t28*_t318 - _t300*_t362;
  const double _t364 = -_hc2[3]*_t132 + (0.1e1 / 0.2e1)*_t16*_t25*_t318*_t7*_t8 - _t25*_t331 + _t28*_t332;
  const double _t365 = _t22*_t364;
  const double _t366 = _t106*_t28;
  const double _t368 = _t122*_t74;
  const double _t369 = _t118*_t78;
  const double _t373 = _hc2[1]*_t372;
  const double _t375 = _hc2[4]*_t142 + _hc2[5]*_t374 + _t28*_t344 - _t336*_t362 + _t343*_t76;
  const double _t377 = _hc2[3]*_t142 + _hc2[4]*_t374 - _hc2[4]*_t376 + _t28*_t346 + _t344*_t76;
  const double _t378 = _t22*_t377;
  const double _t380 = _t126*_t32;
  const double _t384 = _hc2[2]*_t127;
  const double _t385 = _t384*_t86;
  const double _t395 = _hc2[1]*_t394;
  const double _t396 = _t106*_t91;
  const double _t397 = _t28*_t364;
  const double _t398 = _t104*_t267 + _t104*_t87 - _t258*_t389 - _t32*_t385 + _t363*_t76 - _t380*_t387 - _t388*_t77 + _t395 + _t396 + _t397;
  const double _t405 = _hc2[2]*_t70;
  const double _t406 = _t126*_t50;
  const double _t408 = _t122*_t91;
  const double _t409 = _t142*_t78;
  const double _t413 = _hc2[1]*_t412;
  const double _t414 = _t28*_t377;
  const double _t415 = _t120*_t267 + _t120*_t87 - _t126*_t407 + _t137*_t405 + _t26*_t404 + _t367*_t406 + _t374*_t77 + _t375*_t76 - _t376*_t77 - _t385*_t39 + _t408 + _t409 + _t413 + _t414;
  const double _t419 = (0.14e2 / 0.9e1)*_t350;
  const double _t422 = _t104*_t421;
  const double _t423 = _t104*_t14;
  const double _t424 = 0.2e1*_t106;
  const double _t433 = _hc2[1]*_t432;
  const double _t435 = _hc2[4]*_t153 + _hc2[5]*_t434 - _t103*_t146 - _t316*_t317 + _t318*_t37;
  const double _t436 = _hc2[4]*_t102;
  const double _t437 = _hc2[3]*_t153 + _hc2[4]*_t434 - _t146*_t436 - _t316*_t318 + _t332*_t37;
  const double _t438 = _t22*_t437;
  const double _t439 = -_t101*_t146 + _t113*_t424 + _t150*_t419 + _t26*_t418 - _t306*_t420 - _t420*_t423 + _t422 + _t433 + _t435*_t53 + _t438;
  const double _t440 = _t106*_t118;
  const double _t443 = _hc2[1]*_t442;
  const double _t444 = _t113*_t122;
  const double _t445 = _hc2[5]*_t158 + _t105*_t159 - _t316*_t343 + _t344*_t37;
  const double _t448 = _hc2[3]*_t447 + _t105*_t446 - _t316*_t344 + _t346*_t37;
  const double _t449 = _t22*_t448;
  const double _t450 = _t120*_t312 + _t157*_t419 - _t300*_t338 - _t306*_t336 - _t336*_t423 + _t440 + _t443 + _t444 + _t445*_t53 + _t449;
  const double _t451 = 0.2e1*_t122;
  const double _t456 = _hc2[1]*_t455;
  const double _t457 = _hc2[4]*_t169 + _hc2[5]*_t168 - _t103*_t164 - _t121*_t343 + _t344*_t41;
  const double _t458 = _hc2[3]*_t169 + _hc2[4]*_t168 - _t121*_t344 - _t164*_t436 + _t346*_t41;
  const double _t459 = _t22*_t458;
  const double _t460 = -_t101*_t164 + _t118*_t451 + _t167*_t419 - _t338*_t399 + _t456 + _t457*_t53 + _t459;
  const double _t462 = 0.2e1*_hc2[1];
  const double _t463 = _t461*_t462;
  const double _t464 = _t128*_t146;
  const double _t466 = _t462*_t465;
  const double _t467 = _t104*_t25;
  const double _t468 = _t420*_t467;
  const double _t469 = 0.4e1*_t106;
  const double _t470 = _t389*_t469;
  const double _t473 = _hc2[2]*_t137;
  const double _t482 = _t106*_t142;
  const double _t483 = _t28*_t448;
  const double _t484 = _hc2[1]*_t472 - _hc2[1]*_t477 + _hc2[1]*_t481 + _t104*_t374 - _t104*_t376 - _t120*_t388 + _t126*_t475 - _t300*_t473 - _t389*_t451 + _t445*_t76 + _t482 + _t483;
  const double _t490 = _t120*_t489;
  const double _t491 = _t120*_t25;
  const double _t498 = _hc2[1]*_t497;
  const double _t499 = _t28*_t458;
  const double _t500 = _t126*_t488 - _t128*_t164 + _t142*_t451 + _t26*_t487 - _t399*_t473 - _t399*_t491 + _t457*_t76 + _t490 + _t498 + _t499;
  const double _t509 = _hc2[2]*_t508;
  const double _t512 = _t104*_t150;
  const double _t515 = _hc2[1]*_t514 + _t153*_t424 - _t154*_t510 - _t316*_t435 - _t35*_t502 + _t37*_t437 + _t384*_t504 - _t505*_t509 + _t511*_t512;
  const double _t517 = _t151*_t505;
  const double _t521 = _hc2[1]*_t519 + _hc2[2]*_t516 + _t104*_t158 + _t120*_t434 + _t122*_t153 - _t146*_t170 - _t316*_t445 + _t37*_t448 - _t39*_t517 + _t424*_t520;
  const double _t524 = _hc2[2]*_t32;
  const double _t525 = _hc2[1]*_t476;
  const double _t530 = 0.4e1*_t122;
  const double _t531 = -_hc2[1]*_t522 - _hc2[2]*_t527 + _t120*_t529 - _t160*_t528 + _t164*_t525 - _t316*_t457 + _t37*_t458 + _t520*_t530 + _t523*_t524;
  const double _t541 = _hc2[1]*_t540 - _hc2[2]*_t536 + _t120*_t538 - _t121*_t457 - _t161*_t537 + _t169*_t451 - _t35*_t532 + _t384*_t534 + _t41*_t458;
  const double d3F_dna3 = _t13*_t230 + _t172*_t48 + _t173*_t174 + _t175*_t176 + 0.3e1*_t56 + 0.3e1*_t67;
  const double d3F_dna2_dnb = _t13*(_t188*_t70 + _t220*_t77 + _t221*_t234 + _t232*_t52 + _t233*_t54 + _t235 + _t236 + _t243 + _t246*_t53 + _t249) + _t252 + _t68;
  const double d3F_dna_dnb2 = _t13*(_t15*_t255 + _t192*_t254 + _t257 + _t258*_t74 + _t266 + _t268*_t53 + _t270) + _t252 + _t94;
  const double d3F_dnb3 = _t13*_t298 + _t172*_t86 + _t25*_t273 + _t271*_t272 + 0.3e1*_t92 + 0.3e1*_t93;
  const double d3F_dna2_dta = _t104*_t175 + 0.2e1*_t107 + 0.2e1*_t114 + _t13*_t335 - _t299*_t32 + _t34*_t98;
  const double d3F_dna2_dtb = 0.2e1*_t119 + _t120*_t175 + 0.2e1*_t123 + _t13*_t349 - _t299*_t39;
  const double d3F_dna_dnb_dta = _t104*_t76 + _t115 - _t129 + _t13*(_t104*_t233 - _t234*_t300 + _t306*_t70 - _t308*_t351 + _t312*_t77 + _t352 + _t353 + _t361 + _t363*_t53 + _t365) - _t133 + _t366;
  const double d3F_dna_dnb_dtb = _t124 + _t13*(_t192*_t367 - _t234*_t336 - _t337*_t351 + _t338*_t70 + _t368 + _t369 + _t373 + _t375*_t53 + _t378) + _t144;
  const double d3F_dnb2_dta = -_hc2[1]*_t382 + _t104*_t383 + _t13*_t398 + 0.2e1*_t366 - _t379*_t380;
  const double d3F_dnb2_dtb = _t120*_t383 - _t126*_t399 + _t13*_t415 + _t137*_t34 + 0.2e1*_t138 + 0.2e1*_t143;
  const double d3F_dna_dta2 = _t13*_t439 + _t156;
  const double d3F_dna_dta_dtb = _t13*_t450 + _t162;
  const double d3F_dna_dtb2 = _t13*_t460 + _t171;
  const double d3F_dnb_dta2 = _t13*(0.6e1*_hc2[1]*_t11*_t148*_t149*_t215*_t27 + (0.14e2 / 0.9e1)*_hc2[2]*_t148*_t149*_t193*_t25*_t7*_t8 + (0.1e1 / 0.2e1)*_t16*_t25*_t435*_t7*_t8 + _t28*_t437 - _t463 - _t464 - _t466 - _t468 - _t470) + _t156;
  const double d3F_dnb_dta_dtb = _t13*_t484 + _t162;
  const double d3F_dnb_dtb2 = _t13*_t500 + _t171;
  const double d3F_dta3 = _t13*_t515;
  const double d3F_dta2_dtb = _t13*_t521;
  const double d3F_dta_dtb2 = _t13*_t531;
  const double d3F_dtb3 = _t13*_t541;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 1] += d3F_dna2_dtb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 2] += d3F_dna_dnb_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 3] += d3F_dna_dnb_dtb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 4] += d3F_dnb2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 5] += d3F_dnb2_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 1] += d3F_dna_dta_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 2] += d3F_dna_dtb2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 3] += d3F_dnb_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 4] += d3F_dnb_dta_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 5] += d3F_dnb_dtb2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 1] += d3F_dta2_dtb;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 2] += d3F_dta_dtb2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 3] += d3F_dtb3;
#endif
#if _KMAX >= 4
  const double _t545 = xc_powr(na, -14, 3);
  const double _t655 = xc_powr(nb, -14, 3);
  const double _t543 = _t191*_t99;
  const double _t546 = _hc0[1]*_t545;
  const double _t547 = _t546*ta;
  const double _t548 = _t181/xc_powr(na, 19, 3);
  const double _t549 = _t185/xc_powi(na, 8);
  const double _t550 = _hc0[4]*(ta * ta * ta * ta)/xc_powr(na, 29, 3);
  const double _t553 = _t178*ta;
  const double _t555 = _t195*_t51;
  const double _t556 = _t309*_t555;
  const double _t557 = _t43*ta;
  const double _t559 = xc_powr(_t6, -13, 3);
  const double _t560 = _t10*_t559;
  const double _t562 = _t173*_t48;
  const double _t564 = (0.3e1 / 0.2e1)*_t197;
  const double _t565 = (0.3e1 / 0.2e1)*_t199;
  const double _t566 = (0.880e3 / 0.81e2)*_t547 + (0.6400e4 / 0.81e2)*_t548 + (0.500e3 / 0.9e1)*_t549 + (0.625e3 / 0.81e2)*_t550;
  const double _t567 = 0.4e1*_t20;
  const double _t568 = _t62*_t64;
  const double _t569 = _t539*_t58;
  const double _t570 = 0.3e1*_t211;
  const double _t571 = _t214*_t65;
  const double _t572 = _t215*_t571;
  const double _t573 = _t63*_t64;
  const double _t574 = _t214*_t216;
  const double _t575 = _t61*_t64;
  const double _t576 = xc_powi(_t6, -5);
  const double _t577 = _t11*_t576;
  const double _t578 = _t571*_t577;
  const double _t579 = _t17*_t187;
  const double _t580 = _t191*_t50;
  const double _t581 = _t194*_t555;
  const double _t585 = _t231*_t309;
  const double _t586 = _t51*_t585;
  const double _t588 = -0.10e2 / 0.3e1*_hc1[0] + (0.50e2 / 0.9e1)*_hc1[1]*_t3*tb;
  const double _t591 = _t240*_t64;
  const double _t592 = 0.2e1*_t61;
  const double _t593 = 0.3e1*_t355;
  const double _t594 = _t241*_t65;
  const double _t595 = _t215*_t594;
  const double _t596 = _t215*_t27;
  const double _t597 = _t241*_t264;
  const double _t598 = _t216*_t241;
  const double _t599 = -0.4e1*_hc1[0] + (0.20e2 / 0.3e1)*_hc1[1]*_t3*tb;
  const double _t600 = _t48*_t70;
  const double _t601 = _t232*_t51;
  const double _t611 = _t14*_t251;
  const double _t617 = _t81*tb;
  const double _t618 = -0.70e2 / 0.27e2*_t617 - 0.175e3 / 0.27e2*_t85;
  const double _t620 = _t560*_t588;
  const double _t621 = 0.2e1*_t74;
  const double _t622 = _t18*_t263;
  const double _t623 = -0.10e2 / 0.3e1*_t617 - 0.25e2 / 0.3e1*_t85;
  const double _t624 = _t577*_t599;
  const double _t628 = _t275*tb;
  const double _t629 = (0.500e3 / 0.27e2)*_t279 + (0.500e3 / 0.81e2)*_t283 + (0.320e3 / 0.81e2)*_t628;
  const double _t631 = _t618*_t69;
  const double _t633 = _t231*_t620;
  const double _t634 = _t254*_t99;
  const double _t636 = _t585*_t69;
  const double _t640 = _t20*_t292;
  const double _t641 = 0.3e1*_t262;
  const double _t642 = (0.250e3 / 0.9e1)*_t279 + (0.250e3 / 0.27e2)*_t283 + (0.160e3 / 0.27e2)*_t628;
  const double _t643 = _t19*_t263;
  const double _t644 = 0.3e1*_t596;
  const double _t645 = _t623*_t72;
  const double _t646 = _t17*_t284;
  const double _t647 = _t25*_t287;
  const double _t648 = _t33*_t86;
  const double _t649 = 0.2e1*_t91;
  const double _t656 = _hc1[1]*_t655;
  const double _t657 = _t656*tb;
  const double _t658 = _t278/xc_powr(nb, 19, 3);
  const double _t659 = _t282/xc_powi(nb, 8);
  const double _t660 = _hc1[4]*(tb * tb * tb * tb)/xc_powr(nb, 29, 3);
  const double _t665 = (0.3e1 / 0.2e1)*_t25;
  const double _t667 = (0.3e1 / 0.2e1)*_t648;
  const double _t668 = -0.880e3 / 0.81e2*_t657 - 0.6400e4 / 0.81e2*_t658 - 0.500e3 / 0.9e1*_t659 - 0.625e3 / 0.81e2*_t660;
  const double _t669 = _t262*_t59;
  const double _t670 = _t215*_t88;
  const double _t671 = 0.4e1*_t263;
  const double _t672 = 0.5e1*_t262;
  const double _t673 = 0.4e1*_t90;
  const double _t674 = _t262*_t63;
  const double _t675 = 0.3e1*_t90;
  const double _t676 = _t241*_t392;
  const double _t677 = _t263*_t27;
  const double _t678 = _t131*_t99;
  const double _t680 = (0.3e1 / 0.2e1)*_t175;
  const double _t681 = _t307*_t99;
  const double _t683 = _hc0[2]*_t180*ta;
  const double _t684 = _t183*_t303;
  const double _t685 = _hc0[4]*_t184/xc_powr(na, 26, 3);
  const double _t686 = _t309*_t51;
  const double _t687 = (0.7e1 / 0.3e1)*_t686;
  const double _t688 = _t32*_t687;
  const double _t689 = _t559*_t9;
  const double _t690 = (0.5e1 / 0.3e1)*_t689;
  const double _t693 = _t305*_t33;
  const double _t694 = _t173*_t98;
  const double _t695 = _t14*_t681;
  const double _t696 = _t14*_t300;
  const double _t697 = _t206*_t539;
  const double _t698 = _t202 + (0.830e3 / 0.27e2)*_t683 + (0.250e3 / 0.9e1)*_t684 + (0.125e3 / 0.27e2)*_t685;
  const double _t699 = _t109*_t205;
  const double _t700 = _t19*_t62;
  const double _t701 = _t211*_t700;
  const double _t702 = _t568*_t592;
  const double _t703 = _t19*_t569;
  const double _t704 = _t108*_t568;
  const double _t705 = _t327*_t700;
  const double _t706 = _t18*_t32;
  const double _t707 = _t215*_t65;
  const double _t708 = 0.9e1*_t707;
  const double _t709 = _t152*_t203;
  const double _t710 = _t478*_t575;
  const double _t711 = _t264*_t570;
  const double _t712 = _t108*_t64;
  const double _t713 = _t264*_t327;
  const double _t715 = _t17*_t305;
  const double _t716 = _t221*_t98;
  const double _t717 = _t307*_t50;
  const double _t725 = _t141*_t99;
  const double _t726 = _t39*_t687;
  const double _t727 = _t14*_t336;
  const double _t732 = _t336*_t48;
  const double _t733 = _t337*_t686;
  const double _t735 = _t308*_t386;
  const double _t737 = _t300*_t48;
  const double _t738 = _t70*_t98;
  const double _t739 = _t308*_t686;
  const double _t740 = _t237*_t61;
  const double _t741 = 0.2e1*_t58;
  const double _t742 = 0.2e1*_t108;
  const double _t743 = 0.6e1*_t18;
  const double _t744 = _t19*_t215;
  const double _t745 = _t743*_t744;
  const double _t746 = _t237*_t239;
  const double _t747 = _t644*_t65;
  const double _t748 = 0.3e1*_t216;
  const double _t749 = _t61*_t748;
  const double _t750 = _t577*_t594;
  const double _t756 = _t367*_t50;
  const double _t757 = (0.14e2 / 0.9e1)*_t134 + (0.35e2 / 0.9e1)*_t136;
  const double _t758 = _t240*_t39;
  const double _t759 = 0.2e1*_t134 + 0.5e1*_t136;
  const double _t765 = _t231*_t690;
  const double _t767 = (0.7e1 / 0.3e1)*_t386;
  const double _t769 = _t293*_t322;
  const double _t770 = _t262*_t700;
  const double _t771 = _t32*_t62;
  const double _t772 = _t239*_t90;
  const double _t773 = _t209*_t596;
  const double _t774 = _t215*_t643;
  const double _t775 = _t19*_t596;
  const double _t776 = _t264*_t641;
  const double _t777 = _t32*_t577;
  const double _t778 = _t263*_t321;
  const double _t782 = -_t253 - 0.80e2 / 0.9e1*_t400 - 0.100e3 / 0.27e2*_t403;
  const double _t783 = _t69*_t757;
  const double _t784 = _t367*_t99;
  const double _t785 = _t20*_t411;
  const double _t786 = _t39*_t62;
  const double _t787 = 0.6e1*_t39;
  const double _t788 = _t775*_t787;
  const double _t789 = -_t261 - 0.40e2 / 0.3e1*_t400 - 0.50e2 / 0.9e1*_t403;
  const double _t790 = _t72*_t759;
  const double _t791 = _t17*_t404;
  const double _t792 = _t137*_t70;
  const double _t793 = _t25*_t756;
  const double _t798 = (0.7e1 / 0.2e1)*_t386;
  const double _t799 = (0.3e1 / 0.2e1)*_t271;
  const double _t801 = 0.6e1*_t389;
  const double _t802 = (0.3e1 / 0.2e1)*_t383;
  const double _t804 = _t32*_t767;
  const double _t805 = _t254*_t309;
  const double _t808 = 0.9e1*_t670;
  const double _t809 = _t152*_t292;
  const double _t810 = _t478*_t90;
  const double _t811 = _t392*_t641;
  const double _t814 = _hc1[2]*_t277*tb;
  const double _t815 = _t280*_t402;
  const double _t816 = _hc1[4]*_t281/xc_powr(nb, 26, 3);
  const double _t817 = _t39*_t767;
  const double _t819 = _t25*_t784;
  const double _t820 = _t291 + (0.830e3 / 0.27e2)*_t814 + (0.250e3 / 0.9e1)*_t815 + (0.125e3 / 0.27e2)*_t816;
  const double _t821 = _t139*_t59;
  const double _t822 = _t237*_t39;
  const double _t823 = 0.3e1*_t370;
  const double _t824 = _t152*_t370;
  const double _t826 = (0.8e1 / 0.3e1)*_t99;
  const double _t828 = _t32*_t826;
  const double _t829 = _t127*_t146;
  const double _t830 = _hc0[3]*_t302*ta;
  const double _t831 = _hc0[4]*_t45/xc_powr(na, 23, 3);
  const double _t832 = _t150*_t474;
  const double _t835 = (0.35e2 / 0.9e1)*_t689;
  const double _t839 = _t17*_t418;
  const double _t840 = _t420*_t98;
  const double _t841 = _t14*_t420;
  const double _t842 = 0.2e1*_t113;
  const double _t843 = (0.70e2 / 0.9e1)*_t46 + (0.110e3 / 0.9e1)*_t830 + (0.25e2 / 0.9e1)*_t831;
  const double _t844 = 0.4e1*_t61;
  const double _t845 = 0.12e2*_t150;
  const double _t846 = _t18*_t744;
  const double _t847 = _t108*_t322;
  const double _t848 = 0.8e1*_t32;
  const double _t849 = _t32*_t700;
  const double _t850 = _t239*_t771;
  const double _t851 = _t381*_t63;
  const double _t852 = _t577*_t65;
  const double _t853 = _t102*_t146;
  const double _t857 = _t336*_t98;
  const double _t858 = _t321*_t786;
  const double _t862 = _t39*_t826;
  const double _t863 = _t127*_t164;
  const double _t865 = _t14*_t399;
  const double _t866 = 0.2e1*_t118;
  const double _t867 = 0.12e2*_t167;
  const double _t868 = _t102*_t164;
  const double _t875 = 0.2e1*_t146;
  const double _t876 = _t150*_t743;
  const double _t877 = _t237*_t32;
  const double _t878 = _t359*_t72;
  const double _t879 = _t577*_t72;
  const double _t880 = 0.2e1*_t461;
  const double _t881 = _t130*_t875;
  const double _t882 = _t25*_t420;
  const double _t886 = _t27*_t518;
  const double _t887 = _t25*_t474;
  const double _t889 = _t32*_t823;
  const double _t890 = 0.12e2*_t39;
  const double _t891 = _t358*_t577*_t890;
  const double _t893 = _t478*_t480;
  const double _t896 = (0.28e2 / 0.9e1)*_t135 + (0.20e2 / 0.9e1)*_t486;
  const double _t897 = (0.7e1 / 0.3e1)*_t39;
  const double _t898 = (0.14e2 / 0.3e1)*_t135 + (0.10e2 / 0.3e1)*_t486;
  const double _t899 = _t17*_t487;
  const double _t900 = _t25*_t399;
  const double _t901 = 0.2e1*_t142;
  const double _t903 = _t137*_t399;
  const double _t907 = (0.28e2 / 0.9e1)*_t309;
  const double _t913 = _t69*_t835;
  const double _t915 = _t393*_t72;
  const double _t916 = _t157*_t907;
  const double _t918 = _t32*_t890;
  const double _t921 = _t39*_t471;
  const double _t922 = _t139*_t63;
  const double _t923 = _t32*_t922;
  const double _t924 = 0.12e2*_t670;
  const double _t926 = _hc1[3]*_t401*tb;
  const double _t927 = _hc1[4]*_t83/xc_powr(nb, 23, 3);
  const double _t929 = _t164*_t90;
  const double _t930 = -0.70e2 / 0.9e1*_t84 - 0.110e3 / 0.9e1*_t926 - 0.25e2 / 0.9e1*_t927;
  const double _t931 = _t167*_t539;
  const double _t932 = _t494*_t63;
  const double _t933 = _hc0[4]*ta/xc_powr(na, 20, 3);
  const double _t935 = (0.140e3 / 0.27e2)*_t689;
  const double _t937 = _t875*_t99;
  const double _t938 = (0.14e2 / 0.3e1)*_t309;
  const double _t942 = 0.4e1*_t416 + (0.5e1 / 0.3e1)*_t933;
  const double _t943 = _t215*_t508;
  const double _t944 = 0.24e2*_t577;
  const double _t945 = _t19*_t944;
  const double _t946 = 0.6e1*_t63;
  const double _t947 = 0.6e1*_t146;
  const double _t948 = _t127*_t504;
  const double _t949 = _t505*_t508;
  const double _t950 = _t33*_t510;
  const double _t951 = _t150*_t511;
  const double _t952 = 0.2e1*_t153;
  const double _t955 = _t146*_t39;
  const double _t956 = _t150*_t39;
  const double _t959 = _t505*_t956;
  const double _t964 = _t32*_t523;
  const double _t965 = _t164*_t476;
  const double _t966 = _t32*_t932;
  const double _t968 = _t167*_t505;
  const double _t969 = _t32*_t528;
  const double _t971 = _t495*_t99;
  const double _t972 = _t167*_t938;
  const double _t974 = _t20*_t532;
  const double _t975 = _t215*_t535;
  const double _t978 = _t127*_t534;
  const double _t979 = _t33*_t537;
  const double _t980 = 0.2e1*_t169;
  const double _t985 = _t27*_t944;
  const double _t986 = _t146*_t152;
  const double _t987 = _t150*_t944;
  const double _t991 = _hc1[4]*tb/xc_powr(nb, 20, 3);
  const double _t992 = 0.4e1*_t485 + (0.5e1 / 0.3e1)*_t991;
  const double _t993 = 0.24e2*_t215;
  const double _t994 = _t27*_t535;
  const double _t995 = 0.6e1*_t164;
  const double _t996 = _t63*_t787;
  const double _t997 = _hc0[4]/xc_powr(na, 17, 3);
  const double _t998 = _hc0[3]*_t546;
  const double _t1000 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t42;
  const double _t1001 = (0.140e3 / 0.81e2)*_t689;
  const double _t1003 = ((_hc0[2]) * (_hc0[2]))*_t545;
  const double _t1004 = _hc0[2]*_t148*_t177;
  const double _t1006 = 0.2e1*_t99;
  const double _t1007 = 0.8e1*_t20;
  const double _t1008 = 0.36e2*_t62;
  const double _t1009 = 0.8e1*_t63;
  const double _t1010 = 0.36e2*_t216;
  const double _t1011 = _t39*_t504;
  const double _t1012 = _t511*_t955;
  const double _t1013 = (0.28e2 / 0.27e2)*_t309;
  const double _t1016 = _hc1[4]/xc_powr(nb, 17, 3);
  const double _t1017 = _hc1[3]*_t656;
  const double _t1018 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_t80;
  const double _t1019 = ((_hc1[2]) * (_hc1[2]))*_t655;
  const double _t1020 = _hc1[2]*_t165*_t274;
  const double _t542 = 0.2e1*_t34;
  const double _t544 = (0.3e1 / 0.2e1)*_t188;
  const double _t551 = _hc2[2]*_t173;
  const double _t552 = (0.3e1 / 0.2e1)*_t551;
  const double _t554 = _t191*_t350;
  const double _t558 = _t194*_t52;
  const double _t561 = _t196*_t560;
  const double _t563 = _t14*_t176;
  const double _t582 = _hc2[12]*_t22 + _hc2[13]*_t53;
  const double _t583 = _hc2[11]*_t22 + _hc2[12]*_t53;
  const double _t584 = _hc2[7]*_t66 + _hc2[8]*_t220 + _hc2[8]*_t311 + _t22*_t583 + _t53*_t582;
  const double _t587 = _t15*_t232;
  const double _t589 = _t251*_t54;
  const double _t590 = 0.2e1*_t55;
  const double _t602 = _hc2[13]*_t28 + _hc2[14]*_t76;
  const double _t603 = _hc2[12]*_t28 + _hc2[13]*_t76;
  const double _t604 = _hc2[11]*_t28 + _hc2[12]*_t76;
  const double _t605 = _hc2[7]*_t74 + _hc2[8]*_t233 + _t22*_t604 + _t53*_t603;
  const double _t606 = _hc2[10]*_t28 + _hc2[11]*_t76;
  const double _t607 = _t175*_t246;
  const double _t608 = _t197*_t77;
  const double _t609 = _t188*_t251;
  const double _t610 = _t199*_t77;
  const double _t612 = _t52*_t585;
  const double _t613 = _t100*_t254;
  const double _t614 = _t231*_t350;
  const double _t615 = _t74*_t78;
  const double _t616 = _t175*_t268;
  const double _t619 = _t231*_t52;
  const double _t625 = _hc2[8]*_t91 + _hc2[9]*_t267 + _hc2[9]*_t87 + _t28*_t603 + _t602*_t76;
  const double _t626 = _hc2[7]*_t91 + _hc2[8]*_t267 + _hc2[8]*_t87 + _t28*_t604 + _t603*_t76;
  const double _t627 = _hc2[6]*_t91 + _hc2[7]*_t267 + _hc2[7]*_t87 + _t28*_t606 + _t604*_t76;
  const double _t630 = _t15*_t194;
  const double _t632 = _t15*_t69;
  const double _t635 = (0.3e1 / 0.2e1)*_t234;
  const double _t637 = 0.3e1*_t78;
  const double _t638 = (0.3e1 / 0.2e1)*_t268;
  const double _t639 = 0.3e1*_t269;
  const double _t650 = _hc2[4]*_t295 + _hc2[5]*_t285 + _hc2[5]*_t646 + _hc2[5]*_t647 + _t244*_t271 + _t244*_t648 + _t245*_t649 + _t255*_t362 + _t28*_t626 + _t625*_t76;
  const double _t651 = _hc2[4]*_t25;
  const double _t652 = _hc2[3]*_t295 + _hc2[4]*_t285 + _hc2[4]*_t646 + _hc2[4]*_t647 + _t245*_t271 + _t245*_t648 + _t247*_t649 + _t255*_t651 + _t28*_t627 + _t626*_t76;
  const double _t653 = _t126*_t585;
  const double _t654 = _t272*_t86;
  const double _t661 = _hc2[2]*_t251;
  const double _t662 = (0.3e1 / 0.2e1)*_t661;
  const double _t663 = _t126*_t194;
  const double _t664 = _t126*_t69;
  const double _t666 = _t665*_t77;
  const double _t679 = (0.7e1 / 0.2e1)*_t310;
  const double _t682 = _t187*_t384;
  const double _t691 = _t196*_t690;
  const double _t692 = _t48*_t54;
  const double _t714 = _hc2[5]*_t48;
  const double _t718 = _t222*_t686;
  const double _t719 = _hc2[13]*_t37 - _hc2[14]*_t316;
  const double _t720 = _hc2[12]*_t37 - _hc2[13]*_t316;
  const double _t721 = _hc2[11]*_t37 - _hc2[12]*_t316;
  const double _t722 = _hc2[7]*_t113 + _hc2[8]*_t312 - _hc2[8]*_t696 + _t22*_t721 + _t53*_t720;
  const double _t723 = _t105*_t14;
  const double _t724 = _hc2[10]*_t37 - _hc2[11]*_t316;
  const double _t728 = _hc2[13]*_t41 - _hc2[14]*_t121;
  const double _t729 = _hc2[12]*_t41 - _hc2[13]*_t121;
  const double _t730 = _hc2[11]*_t41 - _hc2[12]*_t121;
  const double _t731 = _hc2[7]*_t118 - _hc2[8]*_t727 + _t22*_t730 + _t53*_t729;
  const double _t734 = _hc2[10]*_t41 - _hc2[11]*_t121;
  const double _t736 = _t619*_t690;
  const double _t751 = -_hc2[8]*_t132 - _hc2[9]*_t388 + (0.1e1 / 0.2e1)*_t16*_t25*_t7*_t719*_t8 + _t28*_t720;
  const double _t752 = -_hc2[7]*_t132 - _hc2[8]*_t388 + (0.1e1 / 0.2e1)*_t16*_t25*_t7*_t720*_t8 + _t28*_t721;
  const double _t753 = -_hc2[6]*_t132 - _hc2[7]*_t388 + (0.1e1 / 0.2e1)*_t16*_t25*_t7*_t721*_t8 + _t28*_t724;
  const double _t754 = (0.7e1 / 0.3e1)*_t351;
  const double _t755 = _t104*_t611 + _t175*_t363 - _t234*_t420 + _t250*_t98 - _t32*_t754 + 0.2e1*_t352 + 0.2e1*_t353 + 0.2e1*_t361 + 0.2e1*_t365 + _t661*_t98;
  const double _t760 = _hc2[8]*_t142 + _hc2[9]*_t374 - _hc2[9]*_t376 + _t28*_t729 + _t728*_t76;
  const double _t761 = _hc2[7]*_t142 + _hc2[8]*_t374 - _hc2[8]*_t376 + _t28*_t730 + _t729*_t76;
  const double _t762 = _hc2[6]*_t142 + _hc2[7]*_t374 - _hc2[7]*_t376 + _t28*_t734 + _t730*_t76;
  const double _t763 = _t100*_t367 + _t120*_t611 + _t175*_t375 - _t234*_t399 + 0.2e1*_t368 + 0.2e1*_t369 + 0.2e1*_t373 + 0.2e1*_t378 - _t39*_t754;
  const double _t764 = _t254*_t350;
  const double _t766 = _t632*_t765;
  const double _t768 = _t234*_t767;
  const double _t779 = _hc2[5]*_t86;
  const double _t780 = _hc2[4]*_t394 - _t132*_t245 - _t244*_t388 + _t267*_t317 + _t28*_t752 - _t300*_t779 + _t317*_t87 + _t318*_t91 - _t362*_t735 + _t751*_t76;
  const double _t781 = _hc2[3]*_t394 - _t105*_t25*_t387 - _t132*_t247 - _t245*_t388 + _t267*_t318 + _t28*_t753 + _t318*_t87 - _t331*_t86 + _t332*_t91 + _t752*_t76;
  const double _t794 = _hc2[4]*_t412 + _hc2[5]*_t791 + _hc2[5]*_t792 + _hc2[5]*_t793 + _t142*_t245 + _t244*_t374 - _t244*_t376 + _t267*_t343 + _t28*_t761 - _t336*_t779 + _t343*_t87 + _t344*_t91 - _t362*_t407 + _t76*_t760;
  const double _t795 = _hc2[4]*_t336;
  const double _t796 = _hc2[3]*_t412 + _hc2[4]*_t791 + _hc2[4]*_t792 + _hc2[4]*_t793 + _t142*_t247 + _t245*_t374 - _t245*_t376 + _t267*_t344 + _t28*_t762 + _t344*_t87 + _t346*_t91 - _t407*_t651 + _t76*_t761 - _t795*_t86;
  const double _t797 = _hc2[2]*_t86;
  const double _t800 = _t25*_t77;
  const double _t803 = _t284*_t384;
  const double _t806 = (0.7e1 / 0.6e1)*_t380;
  const double _t807 = _t77*_t86;
  const double _t812 = _hc2[2]*_t784;
  const double _t813 = _t126*_t39;
  const double _t818 = _t126*_t367;
  const double _t825 = (0.28e2 / 0.9e1)*_t350;
  const double _t827 = _t306*_t32;
  const double _t833 = _hc2[2]*_t418;
  const double _t834 = (0.7e1 / 0.6e1)*_t310;
  const double _t836 = _t52*_t835;
  const double _t837 = _t307*_t350;
  const double _t838 = _t104*_t420;
  const double _t854 = _hc2[8]*_t153 + _hc2[9]*_t434 - _hc2[9]*_t853 - _t316*_t719 + _t37*_t720;
  const double _t855 = _hc2[7]*_t153 + _hc2[8]*_t434 - _hc2[8]*_t853 - _t316*_t720 + _t37*_t721;
  const double _t856 = _hc2[6]*_t153 + _hc2[7]*_t434 - _hc2[7]*_t853 - _t316*_t721 + _t37*_t724;
  const double _t859 = _hc2[8]*_t447 + _hc2[9]*_t158 - _t316*_t728 + _t37*_t729;
  const double _t860 = _hc2[7]*_t447 + _hc2[8]*_t158 - _t316*_t729 + _t37*_t730;
  const double _t861 = _hc2[6]*_t447 + _hc2[7]*_t158 - _t316*_t730 + _t37*_t734;
  const double _t864 = _t120*_t399;
  const double _t869 = _hc2[8]*_t169 + _hc2[9]*_t168 - _hc2[9]*_t868 - _t121*_t728 + _t41*_t729;
  const double _t870 = _hc2[7]*_t169 + _hc2[8]*_t168 - _hc2[8]*_t868 - _t121*_t729 + _t41*_t730;
  const double _t871 = _hc2[6]*_t169 + _hc2[7]*_t168 - _hc2[7]*_t868 - _t121*_t730 + _t41*_t734;
  const double _t872 = (0.7e1 / 0.6e1)*_t351;
  const double _t873 = _t632*_t835;
  const double _t874 = _t104*_t98;
  const double _t883 = 0.6e1*_hc2[4]*_t11*_t148*_t149*_t215*_t27 - _hc2[4]*_t880 - _hc2[4]*_t881 + (0.14e2 / 0.9e1)*_hc2[5]*_t148*_t149*_t193*_t25*_t7*_t8 + (0.1e1 / 0.2e1)*_t16*_t25*_t7*_t8*_t854 + _t28*_t855 - _t317*_t882 - _t318*_t382 - _t362*_t829;
  const double _t884 = 0.6e1*_hc2[3]*_t11*_t148*_t149*_t215*_t27 - _hc2[3]*_t880 - _hc2[3]*_t881 + (0.14e2 / 0.9e1)*_hc2[4]*_t148*_t149*_t193*_t25*_t7*_t8 + (0.1e1 / 0.2e1)*_t16*_t25*_t7*_t8*_t855 + _t28*_t856 - _t318*_t882 - _t332*_t382 - _t651*_t829;
  const double _t885 = _t28*_t437;
  const double _t888 = _t350*_t367;
  const double _t892 = _hc2[5]*_t137;
  const double _t894 = _hc2[4]*_t472 - _hc2[4]*_t477 + _t105*_t893 - _t132*_t344 + _t142*_t318 + _t28*_t860 - _t300*_t892 + _t317*_t374 - _t317*_t376 - _t343*_t388 + _t362*_t475 + _t76*_t859;
  const double _t895 = _hc2[3]*_t472 - _hc2[3]*_t477 + _hc2[3]*_t481 + _t105*_t39*_t887 - _t132*_t346 - _t137*_t331 + _t142*_t332 + _t28*_t861 + _t318*_t374 - _t318*_t376 - _t344*_t388 + _t76*_t860;
  const double _t902 = _hc2[4]*_t497 + _hc2[5]*_t899 + _t28*_t870 + _t343*_t489 - _t343*_t900 + _t344*_t901 + _t362*_t488 - _t362*_t863 - _t399*_t892 + _t76*_t869;
  const double _t904 = _hc2[3]*_t497 + _hc2[4]*_t167*_t887 + _hc2[4]*_t899 - _hc2[4]*_t903 + _t28*_t871 + _t344*_t489 - _t344*_t900 + _t346*_t901 - _t651*_t863 + _t76*_t870;
  const double _t905 = 0.4e1*_hc2[1];
  const double _t906 = _t126*_t379;
  const double _t908 = _t151*_t25;
  const double _t909 = _hc2[1]*_t392;
  const double _t910 = _t106*_t130;
  const double _t911 = _t151*_t474;
  const double _t912 = _t126*_t387;
  const double _t914 = _t77*_t887;
  const double _t917 = _hc2[1]*_t139;
  const double _t919 = _t32*_t384;
  const double _t920 = _t120*_t300;
  const double _t925 = _t126*_t167;
  const double _t928 = _t120*_t137;
  const double _t934 = (0.14e2 / 0.3e1)*_t350;
  const double _t936 = _t15*_t935;
  const double _t939 = _t435*_t678;
  const double _t940 = 0.3e1*_t106;
  const double _t941 = 0.3e1*_t437;
  const double _t953 = _hc2[4]*_t514 + _hc2[5]*_t948 - _hc2[5]*_t949 - _t103*_t502 - _t316*_t854 - _t317*_t950 + _t317*_t951 + _t318*_t952 + _t37*_t855;
  const double _t954 = _hc2[3]*_t514 + _hc2[4]*_t948 - _hc2[4]*_t949 - _t316*_t855 - _t318*_t950 + _t318*_t951 + _t332*_t952 + _t37*_t856 - _t436*_t502;
  const double _t957 = _t127*_t435;
  const double _t958 = _t39*_t957;
  const double _t960 = _hc2[4]*_t519 + _hc2[5]*_t516 - _hc2[5]*_t959 + _t153*_t344 + _t158*_t317 - _t316*_t859 + _t318*_t447 + _t343*_t434 - _t343*_t853 + _t37*_t860;
  const double _t961 = _hc2[3]*_t519 + _hc2[4]*_t516 - _hc2[4]*_t959 + _t153*_t346 + _t158*_t318 - _t316*_t860 + _t332*_t447 + _t344*_t434 - _t344*_t853 + _t37*_t861;
  const double _t962 = _t127*_t457;
  const double _t963 = _t32*_t962;
  const double _t967 = -_hc2[4]*_t522 + _hc2[4]*_t965 - _hc2[5]*_t527 + _hc2[5]*_t964 - _t105*_t528 - _t316*_t869 + _t343*_t529 + _t344*_t966 + _t37*_t870;
  const double _t970 = -_hc2[3]*_t522 + _hc2[3]*_t965 - _hc2[3]*_t969 + _t105*_t523 - _t105*_t968 - _t316*_t870 + _t344*_t529 + _t346*_t966 + _t37*_t871;
  const double _t973 = 0.3e1*_t122;
  const double _t976 = _t457*_t725;
  const double _t977 = 0.3e1*_t458;
  const double _t981 = _hc2[4]*_t540 - _hc2[5]*_t536 + _hc2[5]*_t978 - _t103*_t532 - _t121*_t869 + _t343*_t538 - _t343*_t979 + _t344*_t980 + _t41*_t870;
  const double _t982 = _hc2[3]*_t540 - _hc2[4]*_t536 + _hc2[4]*_t978 - _t121*_t870 + _t344*_t538 - _t344*_t979 + _t346*_t980 + _t41*_t871 - _t436*_t532;
  const double _t983 = _hc2[1]*_t240;
  const double _t984 = _t126*_t935;
  const double _t988 = _t120*_t474;
  const double _t989 = _t104*_t474;
  const double _t990 = _t122*_t32;
  const double _t999 = (0.8e1 / 0.9e1)*_hc2[2]*_t99;
  const double _t1002 = _hc2[2]*_t1001;
  const double _t1005 = _hc2[2]*_t907;
  const double _t1014 = _hc2[2]*_t146;
  const double _t1015 = _t32*_t424;
  const double d4F_dna4 = 0.2e1*_t100*_t191 + _t13*(_hc2[1]*(_t111*((0.250e3 / 0.9e1)*_t182 + (0.250e3 / 0.27e2)*_t186 + (0.160e3 / 0.27e2)*_t553) + _t12*_t566 + _t18*_t203*_t567 + 0.4e1*_t18*_t572 + _t19*_t204*_t567 + 0.3e1*_t203*_t573 + 0.8e1*_t206*_t568 - _t21*_t566 + _t211*_t239*_t574 + _t211*_t323 + _t212*_t570 + _t217*(-0.25e2 / 0.3e1*_t47 - 0.10e2 / 0.3e1*_t557) + _t513*_t58*_t61 + _t569*_t65 + 0.3e1*_t574*_t575 + _t578*(-0.4e1*_hc0[0] + (0.20e2 / 0.3e1)*_hc0[1]*_t1*ta)) + _t176*_t187*_t33 + _t187*_t552 + _t192*((0.500e3 / 0.27e2)*_t182 + (0.500e3 / 0.81e2)*_t186 + (0.320e3 / 0.81e2)*_t553) + _t195*_t554 + 0.3e1*_t218*_t55 + _t22*(_hc2[3]*_t218 + _hc2[4]*_t562 + _hc2[4]*_t579 + _t197*_t224 + _t199*_t224 + _t201*_t227 + _t22*(_hc2[6]*_t66 + _hc2[7]*_t220 + _hc2[7]*_t311 + _t22*(_hc2[10]*_t22 + _hc2[11]*_t53) + _t53*_t583) + _t226*_t580 + _t226*_t581 + _t53*_t584) + _t225*_t564 + _t225*_t565 + 0.3e1*_t228*_t66 + _t26*(-0.880e3 / 0.243e3*_t547 - 0.6400e4 / 0.243e3*_t548 - 0.500e3 / 0.27e2*_t549 - 0.625e3 / 0.243e3*_t550) + _t53*(_hc2[4]*_t218 + _hc2[5]*_t562 + _hc2[5]*_t579 + _t197*_t223 + _t199*_t223 + _t201*_t224 + _t22*_t584 + _t222*_t580 + _t222*_t581 + _t53*(_hc2[8]*_t66 + _hc2[9]*_t220 + _hc2[9]*_t311 + _t22*_t582 + _t53*(_hc2[13]*_t22 + _hc2[14]*_t53))) + 0.3e1*_t54*_t562 + _t543*_t544 + _t543*_t563 + _t544*_t556 + _t556*_t563 + _t558*(-0.175e3 / 0.27e2*_t47 - 0.70e2 / 0.27e2*_t557) + _t561*(-0.10e2 / 0.3e1*_hc0[0] + (0.50e2 / 0.9e1)*_hc0[1]*_t1*ta)) + 0.2e1*_t175*_t225 + _t187*_t542 + 0.4e1*_t189 + 0.2e1*_t196*_t309 + 0.4e1*_t198 + 0.4e1*_t200 + 0.4e1*_t219 + 0.4e1*_t229 + 0.8e1*_t55*_t66;
  const double d4F_dna3_dnb = _t13*(_hc2[1]*(_t203*_t71 + _t203*_t73 + _t204*_t71 + 0.3e1*_t206*_t237 + _t209*_t595 + _t211*_t356 + _t211*_t597 + _t571*_t596 + _t578*_t599 + _t58*_t593 + _t591*_t592 + _t592*_t598*_t64) + _t187*_t405 + _t188*_t586 + _t191*_t587 + _t197*_t246 + _t199*_t246 + _t201*_t248 + _t218*_t78 + _t22*(_hc2[3]*_t242 + _hc2[4]*_t600 + _t22*(_hc2[6]*_t74 + _hc2[7]*_t233 + _t22*_t606 + _t53*_t604) + _t220*_t245 + _t224*_t233 + _t226*_t601 + _t227*_t74 + _t245*_t311 + _t247*_t66 + _t53*_t605) + _t225*_t233 + _t228*_t74 + _t234*_t580 + _t234*_t581 + _t242*_t590 + _t313*_t586 + _t48*_t589 + _t53*(_hc2[4]*_t242 + _hc2[5]*_t600 + _t22*_t605 + _t220*_t244 + _t222*_t601 + _t223*_t233 + _t224*_t74 + _t244*_t311 + _t245*_t66 + _t53*(_hc2[8]*_t74 + _hc2[9]*_t233 + _t22*_t603 + _t53*_t602)) + _t561*_t588 + _t562*_t77 + _t579*_t77) + _t176*_t611 + _t230 + 0.3e1*_t235 + 0.3e1*_t236 + 0.3e1*_t243 + 0.3e1*_t249 + (0.3e1 / 0.2e1)*_t607 + (0.3e1 / 0.2e1)*_t608 + (0.3e1 / 0.2e1)*_t609 + (0.3e1 / 0.2e1)*_t610 + (0.3e1 / 0.2e1)*_t612;
  const double d4F_dna2_dnb2 = _t13*(_hc2[1]*(_t208*_t90 + _t212*_t262 + _t215*_t239*_t622 + _t217*_t623 + _t239*_t262*_t322 + _t259*_t58 + _t259*_t61 + _t260*_t58 + _t260*_t592 + _t294*_t61 + 0.2e1*_t594*_t596 + _t594*_t624) + _t188*_t255 + _t188*_t287 + _t22*(_hc2[3]*_t265 + _t22*_t627 + _t226*_t255 + _t226*_t287 + _t245*_t611 + _t247*_t621 + _t53*_t626) + _t220*_t268 + _t234*_t586 + _t242*_t258 + _t246*_t611 + _t248*_t621 + _t255*_t313 + _t256*_t48 + _t265*_t55 + _t268*_t311 + _t269*_t66 + _t287*_t313 + _t53*(_hc2[4]*_t265 + _t22*_t626 + _t222*_t255 + _t222*_t287 + _t244*_t611 + _t245*_t621 + _t53*_t625) + _t558*_t618 + _t619*_t620) + _t14*_t589 + 0.2e1*_t235 + 0.2e1*_t236 + 0.2e1*_t243 + 0.2e1*_t249 + 0.2e1*_t257 + 0.2e1*_t266 + 0.2e1*_t270 + _t607 + _t608 + _t609 + _t610 + _t612 + _t613 + _t614*_t69 + 0.4e1*_t615 + _t616;
  const double d4F_dna_dnb3 = _t13*(_hc2[1]*(_t111*_t642 + _t18*_t640 + _t19*_t640 + _t238*_t293 + _t239*_t262*_t598 + _t262*_t354 + _t264*_t645 + _t356*_t641 + _t593*_t90 + _t596*_t622 + _t624*_t643 + _t643*_t644) + _t192*_t629 + _t22*_t652 + _t254*_t614 + _t265*_t637 + _t53*_t650 + _t611*_t638 + _t630*_t631 + _t632*_t633 + _t634*_t635 + _t635*_t636 + _t639*_t74) + _t174*_t636 + 0.3e1*_t257 + 0.3e1*_t266 + 0.3e1*_t270 + _t298 + (0.3e1 / 0.2e1)*_t613 + 0.6e1*_t615 + (0.3e1 / 0.2e1)*_t616;
  const double d4F_dnb4 = 0.2e1*_t126*_t634 + _t13*(_hc2[1]*(_t12*_t668 + _t130*_t642 + _t140*_t642 + _t21*_t668 + _t260*_t672 + _t260*_t673 + 0.2e1*_t262*_t676 + _t290*(-0.80e2 / 0.9e1*_t617 - 0.200e3 / 0.9e1*_t85) + 0.4e1*_t292*_t71 + 0.3e1*_t292*_t73 + _t294*_t675 + _t392*_t645 + _t59*(_t90 * _t90) + _t624*_t677 + _t669*_t90 + _t670*_t671 + _t674*_t675) + _t254*_t653 + 0.3e1*_t256*_t86 + _t26*(-0.880e3 / 0.243e3*_t657 - 0.6400e4 / 0.243e3*_t658 - 0.500e3 / 0.27e2*_t659 - 0.625e3 / 0.243e3*_t660) + _t268*_t667 + _t271*_t638 + _t273*_t284 + _t28*_t652 + _t284*_t662 + _t295*_t637 + _t406*_t629 + _t631*_t663 + _t633*_t664 + _t634*_t654 + _t634*_t666 + _t636*_t654 + _t636*_t666 + _t639*_t91 + _t650*_t76) + 0.2e1*_t268*_t383 + _t284*_t542 + 0.4e1*_t286 + 0.4e1*_t288 + 0.4e1*_t289 + 0.4e1*_t296 + 0.4e1*_t297 + 0.2e1*_t653*_t69 + 0.8e1*_t78*_t91;
  const double d4F_dna3_dta = (0.3e1 / 0.2e1)*_t100*_t307 + _t104*_t564 + _t104*_t565 + _t13*(_hc2[1]*(_t108*_t205*_t58 + 0.3e1*_t109*_t208 + _t110*_t203 - _t110*_t204 + _t111*(-_t210 - 0.40e2 / 0.3e1*_t301 - 0.50e2 / 0.9e1*_t304) - _t12*_t698 + _t18*_t205*_t325 + _t207*_t320 + _t209*_t704 + _t209*_t705 + _t21*_t698 + _t211*_t326 + _t213*_t327 + _t214*_t713 + _t217*(0.2e1*_t95 + 0.5e1*_t97) + _t32*_t572 - _t32*_t697 + _t32*_t701 + _t32*_t702 - _t32*_t703 - _t32*_t709 - _t32*_t710 - _t32*_t711 + 0.2e1*_t325*_t573 - _t381*_t578 + _t574*_t712 + _t61*_t699 - _t706*_t708) + _t104*_t562 + _t104*_t579 + _t106*_t218 + _t113*_t228 + _t188*_t681 - _t188*_t688 + _t192*(-_t190 - 0.80e2 / 0.9e1*_t301 - 0.100e3 / 0.27e2*_t304) + _t195*_t307*_t630 + _t197*_t319 + _t199*_t319 + _t201*_t333 + _t22*(_hc2[3]*_t329 + _hc2[4]*_t715 + _hc2[4]*_t716 + _t113*_t227 + _t22*(_hc2[6]*_t113 + _hc2[7]*_t312 - _hc2[7]*_t696 + _t22*_t724 + _t53*_t721) + _t220*_t318 + _t224*_t312 - _t224*_t696 + _t226*_t717 + _t311*_t318 - _t331*_t48 + _t332*_t66 + _t53*_t722 - 0.7e1 / 0.6e1*_t686*_t723) + _t225*_t312 - _t225*_t696 + _t26*(_t179 + (0.830e3 / 0.81e2)*_t683 + (0.250e3 / 0.27e2)*_t684 + (0.125e3 / 0.81e2)*_t685) + _t305*_t551 + _t306*_t580 + _t306*_t581 - _t308*_t554 - _t313*_t688 - _t32*_t682 - _t32*_t691 + _t329*_t590 - _t420*_t692 + _t423*_t580 + _t423*_t581 + _t53*(_hc2[4]*_t329 + _hc2[5]*_t715 + _hc2[5]*_t716 + _t113*_t224 + _t22*_t722 + _t220*_t317 + _t222*_t717 + _t223*_t312 - _t223*_t696 - _t300*_t714 - _t308*_t718 + _t311*_t317 + _t318*_t66 + _t53*(_hc2[8]*_t113 + _hc2[9]*_t312 - _hc2[9]*_t696 + _t22*_t720 + _t53*_t719)) + _t54*_t693 + _t54*_t694 + _t54*_t695 + _t558*((0.14e2 / 0.9e1)*_t95 + (0.35e2 / 0.9e1)*_t97)) + _t172*_t305 + _t176*_t421 - _t188*_t678 - _t313*_t678 + 0.3e1*_t314 + 0.3e1*_t315 + _t319*_t680 - _t32*_t679 + 0.3e1*_t330 + 0.3e1*_t334 + _t552*_t98;
  const double d4F_dna3_dtb = _t120*_t564 + _t120*_t565 + _t13*(_hc2[1]*(-_t117*_t203 - _t117*_t204 - _t18*_t39*_t708 - _t39*_t572 - _t39*_t697 - _t39*_t701 - _t39*_t702 - _t39*_t703 - _t39*_t709 - _t39*_t710 - _t39*_t711 - _t494*_t578) + _t118*_t228 + _t120*_t562 + _t120*_t579 + _t122*_t218 - _t188*_t726 + _t197*_t345 + _t199*_t345 + _t201*_t347 + _t22*(_hc2[3]*_t341 - _hc2[4]*_t732 + _t118*_t227 + _t22*(_hc2[6]*_t118 - _hc2[7]*_t727 + _t22*_t734 + _t53*_t730) + _t220*_t344 - _t224*_t727 - _t226*_t733 + _t311*_t344 + _t346*_t66 + _t53*_t731) - _t225*_t727 - _t313*_t726 - _t337*_t554 + _t338*_t580 + _t338*_t581 + _t341*_t590 - _t39*_t682 - _t39*_t691 - _t399*_t692 + _t53*(_hc2[4]*_t341 + _t118*_t224 + _t22*_t731 + _t220*_t343 - _t223*_t727 + _t311*_t343 - _t336*_t714 - _t337*_t718 + _t344*_t66 + _t53*(_hc2[8]*_t118 - _hc2[9]*_t727 + _t22*_t729 + _t53*_t728))) - _t188*_t725 - _t313*_t725 + 0.3e1*_t339 + 0.3e1*_t340 + 0.3e1*_t342 + _t345*_t680 + 0.3e1*_t348 - _t39*_t679;
  const double d4F_dna2_dnb_dta = _t13*(_hc2[1]*(_t108*_t591 + _t109*_t746 + _t238*_t742 + _t32*_t595 + _t32*_t740 - _t32*_t747 + _t320*_t71 + _t325*_t71 + _t325*_t73 + _t327*_t356 + _t327*_t597 - _t358*_t745 - _t358*_t749 - _t381*_t750 - _t471*_t592 - _t471*_t741 + _t598*_t712) + _t104*_t600 + _t106*_t242 + _t113*_t248 - _t188*_t735 + _t22*(_hc2[3]*_t360 + _hc2[4]*_t738 + _t113*_t247 + _t22*_t753 + _t233*_t318 + _t245*_t312 - _t245*_t696 + _t332*_t74 - _t387*_t723 + _t53*_t752) + _t220*_t363 + _t233*_t319 + _t234*_t717 - _t234*_t739 + _t246*_t312 - _t246*_t696 + _t305*_t405 + _t306*_t601 + _t307*_t587 + _t311*_t363 - _t313*_t735 - _t32*_t736 + _t329*_t78 + _t333*_t74 + _t360*_t55 + _t364*_t66 + _t423*_t601 + _t53*(_hc2[4]*_t360 + _hc2[5]*_t738 + _t113*_t245 + _t22*_t752 - _t222*_t735 + _t233*_t317 + _t244*_t312 - _t244*_t696 + _t318*_t74 + _t53*_t751) + _t54*_t738 + _t715*_t77 + _t716*_t77 - _t737*_t77) + _t335 + _t755;
  const double d4F_dna2_dnb_dtb = _t13*(_hc2[1]*(_t11*_t19*_t215*_t64*_t759 + _t11*_t370*_t61*_t62 + _t139*_t19*_t62*_t64 + _t139*_t20*_t58 + _t139*_t20*_t61 + 0.2e1*_t18*_t19*_t370*_t62 - _t371*_t745 - _t371*_t749 - _t39*_t595 - _t39*_t740 - _t39*_t747 - _t494*_t750 - _t592*_t758 - _t741*_t758) + _t118*_t248 + _t120*_t600 + _t122*_t242 - _t188*_t407 + _t188*_t756 + _t22*(_hc2[3]*_t372 + _t118*_t247 + _t22*_t762 - _t226*_t407 + _t226*_t756 + _t233*_t344 - _t245*_t727 + _t346*_t74 + _t53*_t761) + _t220*_t375 + _t233*_t345 - _t234*_t733 - _t246*_t727 + _t311*_t375 - _t313*_t407 + _t313*_t756 + _t338*_t601 + _t341*_t78 + _t347*_t74 + _t372*_t55 + _t377*_t66 - _t39*_t736 + _t53*(_hc2[4]*_t372 + _t118*_t245 + _t22*_t761 - _t222*_t407 + _t222*_t756 + _t233*_t343 - _t244*_t727 + _t344*_t74 + _t53*_t760) + _t558*_t757 - _t732*_t77) + _t349 + _t763;
  const double d4F_dna_dnb2_dta = _t13*(_hc2[1]*(_t108*_t259 + _t108*_t294 + _t109*_t259 + _t109*_t260 + _t260*_t742 + _t262*_t326 - _t32*_t769 + _t32*_t770 + _t32*_t774 - _t32*_t776 - _t358*_t773 - 0.6e1*_t358*_t775 - _t771*_t772 - _t777*_t778) + _t106*_t265 + _t113*_t269 + _t22*_t781 + _t255*_t306 + _t255*_t423 + _t256*_t98 + _t258*_t360 + _t268*_t312 - _t268*_t696 + _t287*_t306 + _t287*_t423 - _t308*_t764 - _t32*_t766 - _t32*_t768 + _t363*_t611 + _t364*_t621 + _t53*_t780) + _t398 + _t755;
  const double d4F_dna_dnb2_dtb = _t13*(_hc2[1]*(_t111*_t789 + _t139*_t238 + _t139*_t746 + _t18*_t785 + _t19*_t785 + _t264*_t790 + _t354*_t370 + _t357*_t370 + _t370*_t597 - _t371*_t773 - _t39*_t577*_t778 - _t39*_t769 - _t39*_t770 - _t39*_t774 - _t39*_t776 - _t72*_t788 - _t772*_t786) + _t118*_t269 + _t122*_t265 + _t192*_t782 + _t22*_t796 + _t234*_t784 + _t255*_t338 + _t258*_t372 - _t268*_t727 + _t287*_t338 - _t337*_t764 + _t367*_t587 + _t375*_t611 + _t377*_t621 - _t39*_t766 - _t39*_t768 + _t53*_t794 + _t630*_t783) + _t415 + _t763;
  const double d4F_dnb3_dta = _t104*_t667 + _t104*_t799 + _t13*(_hc2[1]*(_hc0[1]*_t215*_t241*_t27*_t31*_t72 + 0.2e1*_hc0[1]*_t31*_t62*_t72*_t90 - _t27*_t671*_t777 - _t32*_t809 - _t32*_t811 - _t358*_t808 - _t358*_t810 - _t471*_t641 - _t471*_t673) + _t104*_t285 + _t104*_t646 + _t104*_t647 + _t106*_t295 - _t132*_t269 + _t255*_t467 + _t258*_t394 - _t268*_t388 + _t271*_t363 + _t28*_t781 - _t32*_t803 + _t363*_t648 + _t364*_t649 - _t380*_t69*_t765 - _t420*_t807 + _t76*_t780 - _t797*_t804 - _t800*_t804 - _t805*_t806) + _t363*_t802 - _t380*_t798 + 0.3e1*_t395 + 0.3e1*_t396 + 0.3e1*_t397 - _t678*_t797 - _t678*_t800 - _t78*_t801;
  const double d4F_dnb3_dtb = _t120*_t667 + _t120*_t799 + _t13*(_hc2[1]*(_t12*_t820 + _t130*_t789 + _t139*_t294 + _t139*_t669 + _t139*_t674 + _t140*_t411 + _t140*_t789 + _t21*_t820 - _t240*_t494*_t90 + _t260*_t823 - _t263*_t39*_t596 + _t290*(0.4e1*_t134 + 0.10e2*_t136) - _t292*_t410 - _t293*_t822 + _t370*_t676 - _t371*_t808 - _t371*_t810 - _t39*_t809 - _t39*_t811 + _t392*_t790 + 0.2e1*_t411*_t73 - _t494*_t577*_t677 - _t672*_t758 + _t821*_t90 + _t824*_t90) + _t120*_t285 + _t120*_t646 + _t120*_t647 + _t122*_t295 - _t126*_t337*_t805 + _t137*_t256 + _t142*_t269 + _t232*_t818 + _t250*_t404 + _t255*_t473 + _t255*_t491 + _t258*_t412 + _t26*(_t276 + (0.830e3 / 0.81e2)*_t814 + (0.250e3 / 0.27e2)*_t815 + (0.125e3 / 0.81e2)*_t816) + _t268*_t374 - _t268*_t376 + _t271*_t375 + _t28*_t796 + _t287*_t473 + _t375*_t648 + _t377*_t649 - _t39*_t664*_t765 - _t39*_t803 - _t399*_t807 + _t404*_t661 + _t406*_t782 + _t663*_t783 + _t76*_t794 + _t77*_t819 - _t797*_t817 - _t800*_t817 + _t812*_t86) + _t137*_t273 + _t137*_t662 + _t172*_t404 + _t375*_t802 + 0.3e1*_t408 + 0.3e1*_t409 + 0.3e1*_t413 + 0.3e1*_t414 + _t665*_t812 - _t725*_t797 - _t725*_t800 - _t798*_t813;
  const double d4F_dna2_dta2 = _t113*_t469 + _t13*(_hc2[1]*(_t108*_t109*_t567 - 0.8e1*_t109*_t849 + _t111*((0.10e2 / 0.3e1)*_t417 + (0.14e2 / 0.3e1)*_t96) + _t12*_t843 + _t131*_t704 + _t146*_t208 - _t146*_t213 - _t146*_t323 - _t146*_t328 - _t21*_t843 - 0.6e1*_t32*_t713 - _t320*_t430 + _t324*_t426 + _t325*_t430 - _t325*_t851 + _t327*_t441 + _t327*_t850 + _t425*_t573 + _t425*_t60 - _t427*_t58 + _t427*_t61 + _t428*_t741 - _t428*_t844 - _t431*_t707 - _t479*_t712 + _t518*_t61 + _t845*_t846 + _t845*_t852 - _t847*_t848) - _hc2[2]*_t305*_t420 + _t104*_t693 + _t104*_t694 + _t104*_t695 - _t146*_t834 + _t150*_t836 - _t188*_t829 + _t188*_t832 + _t192*((0.20e2 / 0.9e1)*_t417 + (0.28e2 / 0.9e1)*_t96) + _t22*(_hc2[3]*_t432 + _hc2[4]*_t839 - _t105*_t379*_t98 + _t22*_t856 - _t226*_t829 + _t226*_t832 + _t318*_t421 - _t318*_t841 + _t332*_t842 + _t53*_t855) + _t220*_t435 + _t221*_t833 + _t26*(-0.70e2 / 0.27e2*_t46 - 0.110e3 / 0.27e2*_t830 - 0.25e2 / 0.27e2*_t831) + _t306*_t681 + _t311*_t435 - _t313*_t829 + _t313*_t832 + _t319*_t421 - _t319*_t841 - 0.7e1 / 0.3e1*_t32*_t837 + _t329*_t424 + _t333*_t842 - _t423*_t688 + _t432*_t55 + _t437*_t66 - _t48*_t838 + _t53*(_hc2[4]*_t432 + _hc2[5]*_t839 - _hc2[5]*_t840 + _t22*_t855 - _t222*_t829 + _t222*_t832 + _t317*_t421 - _t317*_t841 + _t318*_t842 + _t53*_t854) + _t54*_t839 - _t54*_t840 - _t687*_t827) - _t146*_t299 + _t150*_t825 + _t175*_t435 + _t34*_t418 + 0.2e1*_t422 - _t423*_t828 + 0.2e1*_t433 + 0.2e1*_t438 - _t826*_t827;
  const double d4F_dna2_dta_dtb = _t120*_t421 + _t13*(_hc2[1]*(0.12e2*_hc0[1]*_hc1[1]*_t11*_t19*_t31*_t38*_t576*_t64 + 0.6e1*_hc0[1]*_hc1[1]*_t11*_t215*_t31*_t38*_t61 + 0.12e2*_hc0[1]*_hc1[1]*_t18*_t19*_t215*_t31*_t38 + 0.2e1*_hc0[1]*_hc1[1]*_t31*_t38*_t58*_t62 - _t109*_t858 - _t117*_t320 - _t117*_t325 - _t159*_t325 - _t39*_t704 - _t39*_t705 - _t39*_t712*_t748 - 0.3e1*_t39*_t713 - _t494*_t847) - _t104*_t732 + _t106*_t341 + _t113*_t347 + _t118*_t333 + _t120*_t715 + _t120*_t716 - _t120*_t737 + _t122*_t329 + _t157*_t836 + _t188*_t475 + _t22*(_hc2[3]*_t442 + _t113*_t346 + _t118*_t332 + _t22*_t861 + _t312*_t344 - _t318*_t727 - _t344*_t696 + _t39*_t474*_t723 + _t53*_t860 - _t795*_t98) + _t220*_t445 - _t305*_t384*_t39 - _t306*_t733 + _t311*_t445 + _t312*_t345 + _t313*_t475 - _t319*_t727 - _t337*_t837 + _t338*_t717 - _t338*_t739 - _t345*_t696 - _t423*_t733 + _t442*_t55 + _t448*_t66 + _t53*(_hc2[4]*_t442 - _hc2[5]*_t857 + _t113*_t344 + _t118*_t318 + _t22*_t860 + _t222*_t475 + _t312*_t343 - _t317*_t727 - _t343*_t696 + _t53*_t859) - _t54*_t857) + _t157*_t825 + _t175*_t445 - _t306*_t399 - _t338*_t420 - _t399*_t423 + 0.2e1*_t440 + 0.2e1*_t443 + 0.2e1*_t444 + 0.2e1*_t449;
  const double d4F_dna2_dtb2 = _t118*_t530 + _t13*(_hc2[1]*(-_t164*_t208 - _t164*_t213 - _t164*_t323 - _t164*_t328 - _t452*_t58 - _t452*_t61 + _t453*_t741 + _t453*_t844 + _t454*_t707 + _t528*_t61 + _t846*_t867 + _t852*_t867) - _t164*_t834 + _t167*_t836 + _t188*_t488 - _t188*_t863 + _t22*(_hc2[3]*_t455 + _t22*_t871 + _t226*_t488 - _t226*_t863 - _t344*_t865 + _t346*_t866 + _t53*_t870) + _t220*_t457 + _t311*_t457 + _t313*_t488 - _t313*_t863 - _t338*_t726 + _t341*_t451 - _t345*_t865 + _t347*_t866 + _t455*_t55 + _t458*_t66 - _t48*_t864 + _t53*(_hc2[4]*_t455 + _t22*_t870 + _t222*_t488 - _t222*_t863 - _t343*_t865 + _t344*_t866 + _t53*_t869)) - _t164*_t299 + _t167*_t825 + _t175*_t457 - _t338*_t862 + 0.2e1*_t456 + 0.2e1*_t459;
  const double d4F_dna_dnb_dta2 = _hc2[1]*_t886 + _t13*(_hc2[1]*(-_t108*_t358*_t478 - 0.4e1*_t108*_t471 - _t109*_t240*_t381 + _t146*_t355 - _t146*_t357 - _t146*_t878 + _t19*_t845*_t879 - _t354*_t875 + _t425*_t71 + _t425*_t73 + _t426*_t71 - _t431*_t72*_t744 + _t431*_t775 + _t596*_t876 + _t742*_t877) - _t146*_t872 + _t150*_t873 + _t22*_t884 + _t233*_t435 - _t234*_t829 + _t234*_t832 + _t251*_t874 + _t360*_t424 + _t363*_t421 - _t363*_t841 + _t364*_t842 + _t405*_t418 - _t423*_t804 + _t432*_t78 + _t437*_t74 + _t53*_t883 - _t767*_t827 + _t77*_t839 - _t77*_t840) + _t151*_t887 + _t435*_t76 + _t439 - _t463 - _t464 - _t466 - _t468 - _t470 + _t885;
  const double d4F_dna_dnb_dta_dtb = _t13*(_hc2[1]*(-0.3e1*_t108*_t216*_t371 + _t108*_t493 - _t108*_t822 + _t109*_t493 - 0.2e1*_t109*_t758 - _t139*_t429*_t771 - _t139*_t850 + _t157*_t596*_t743 + _t19*_t891 - _t264*_t889 + _t32*_t788 + _t326*_t370 + _t370*_t849 - _t742*_t758) + _t106*_t372 + _t113*_t377 + _t118*_t364 + _t120*_t738 + _t122*_t360 + _t157*_t873 + _t22*_t895 + _t233*_t445 + _t234*_t475 - _t306*_t407 + _t306*_t756 - _t308*_t888 + _t312*_t375 - _t338*_t735 - _t363*_t727 - _t375*_t696 - _t407*_t423 + _t423*_t756 + _t442*_t78 + _t448*_t74 + _t53*_t894 - _t77*_t857) + _t450 + _t484;
  const double d4F_dna_dnb_dtb2 = _t13*(_hc2[1]*(0.12e2*_t11*_t165*_t166*_t19*_t576*_t72 + _t11*_t19*_t62*_t898 - _t139*_t858 - _t164*_t355 - _t164*_t357 - _t164*_t878 + 0.6e1*_t165*_t166*_t18*_t215*_t27 + 0.6e1*_t165*_t166*_t19*_t215*_t27 + 0.6e1*_t165*_t166*_t19*_t215*_t72 + _t18*_t20*_t492 + _t19*_t20*_t492 - _t239*_t370*_t786 - _t264*_t370*_t787 - _t322*_t496 - _t354*_t495) - _t164*_t872 + _t167*_t873 + _t192*_t896 + _t22*_t904 + _t233*_t457 + _t234*_t488 - _t234*_t863 + _t338*_t784 - _t338*_t817 + _t372*_t451 - _t375*_t865 + _t377*_t866 + _t455*_t78 + _t458*_t74 + _t53*_t902 - _t888*_t897) + _t460 + _t500;
  const double d4F_dnb2_dta2 = _t13*(_hc2[1]*(_hc0[2]*_t145*_t27*_t62*_t72 + 0.6e1*_t11*_t148*_t149*_t215*_t90 + 0.12e2*_t11*_t148*_t149*_t27*_t576*_t72 - _t146*_t390 - _t146*_t391 - _t146*_t915 + 0.12e2*_t148*_t149*_t215*_t88 - _t293*_t428 - _t431*_t596*_t72) - _t146*_t385 - _t146*_t912 + _t150*_t914 - _t258*_t461 - _t258*_t465 + _t267*_t435 + _t28*_t884 - _t363*_t882 - _t364*_t382 + _t394*_t424 + _t435*_t87 + _t437*_t91 - _t467*_t804 + _t76*_t883 + _t78*_t886 - _t800*_t829 - _t838*_t86 + _t86*_t911 + _t908*_t913) - _t146*_t906 + _t383*_t435 - _t461*_t905 - _t465*_t905 - _t467*_t828 + _t845*_t909 - _t848*_t910 + 0.2e1*_t885 + _t907*_t908;
  const double d4F_dnb2_dta_dtb = _hc2[1]*_t471*_t494 + _t104*_t489 + _t126*_t916 + _t13*(_hc2[1]*(-_t139*_t358*_t748 + _t139*_t877 + _t157*_t810 + _t157*_t924 + _t27*_t891 + _t293*_t39*_t771 - _t392*_t889 - _t411*_t476 - _t471*_t823) - _t104*_t336*_t86 + _t104*_t791 + _t104*_t792 + _t104*_t793 + _t106*_t412 + _t122*_t394 - _t132*_t377 - _t137*_t300*_t77 + _t142*_t364 + _t157*_t664*_t835 + _t157*_t914 + _t258*_t921 - _t258*_t923 + _t267*_t445 + _t28*_t895 - _t309*_t367*_t806 + _t363*_t374 - _t363*_t376 - _t375*_t388 - _t404*_t919 - _t407*_t467 + _t445*_t87 + _t448*_t91 - _t473*_t735 + _t475*_t797 + _t481*_t78 - _t491*_t735 + _t76*_t894 - _t86*_t920) + _t383*_t445 - _t389*_t530 - _t399*_t467 - _t420*_t473 - _t420*_t491 + 0.2e1*_t482 + 0.2e1*_t483 - _t851*_t917 + _t909*_t918;
  const double d4F_dnb2_dtb2 = _t13*(_hc2[1]*(_t12*_t930 + _t130*_t898 - _t139*_t371*_t478 - 0.2e1*_t139*_t822 + _t139*_t824 + _t140*_t898 - _t152*_t929 - _t164*_t260 - _t164*_t390 - _t164*_t915 + _t167*_t924 + _t21*_t930 + _t27*_t867*_t879 - 0.10e2*_t370*_t758 + _t370*_t821 - _t370*_t893 - _t411*_t932 + _t454*_t596*_t72 + _t492*_t73 - _t494*_t785 + _t528*_t90 - _t59*_t929 + _t90*_t931) - _hc2[2]*_t399*_t404 + _t120*_t819 + _t137*_t812 + _t161*_t404 - _t164*_t385 - _t164*_t912 + _t167*_t914 + _t251*_t928 + _t26*(-0.70e2 / 0.27e2*_t84 - 0.110e3 / 0.27e2*_t926 - 0.25e2 / 0.27e2*_t927) + _t267*_t457 + _t28*_t904 - _t309*_t818*_t897 + _t375*_t489 - _t375*_t900 + _t377*_t901 + _t405*_t487 + _t406*_t896 + _t412*_t451 + _t457*_t87 + _t458*_t91 - _t473*_t817 + _t488*_t797 - _t491*_t817 + _t497*_t78 + _t76*_t902 + _t77*_t899 - _t77*_t903 - _t800*_t863 - _t86*_t864 + _t913*_t925) + _t142*_t530 - _t164*_t906 + _t34*_t487 + _t383*_t457 - _t473*_t862 + 0.2e1*_t490 - _t491*_t862 + 0.2e1*_t498 + 0.2e1*_t499 + _t907*_t925;
  const double d4F_dna_dta3 = _t13*(_hc2[1]*(0.18e2*_hc0[1]*_hc0[2]*_t11*_t19*_t215*_t503 + 0.6e1*_hc0[1]*_hc0[2]*_t18*_t503*_t62 + 0.3e1*_hc0[1]*_t20*_t31*_t425 + 0.3e1*_hc0[2]*_t108*_t145*_t20 + _hc0[3]*_t19*_t20*_t501 + 0.18e2*_t108*_t11*_t148*_t149*_t215 - 0.12e2*_t108*_t428 + 0.6e1*_t109*_t148*_t149*_t62 + _t11*_t20*_t942 - 0.3e1*_t110*_t426 - _t112*_t502 - _t12*_t942 - _t146*_t699 - _t18*_t20*_t502 + 0.18e2*_t19*_t215*_t506*_t507 - _t32*_t425*_t946 - _t326*_t947 - 0.12e2*_t504*_t700 - _t508*_t945 - _t743*_t943) - _t101*_t502 + _t113*_t941 + _t14*_t512*_t938 - _t14*_t939 + _t150*_t306*_t938 + (0.3e1 / 0.2e1)*_t154*_t418 + _t22*_t954 + _t26*((0.4e1 / 0.3e1)*_t416 + (0.5e1 / 0.9e1)*_t933) - _t306*_t937 - _t381*_t874*_t99 + (0.3e1 / 0.2e1)*_t421*_t435 - _t423*_t937 + _t432*_t940 + _t504*_t934 - _t508*_t936 + _t53*_t953 - _t678*_t833) + _t515;
  const double d4F_dna_dta2_dtb = _t13*(_hc2[1]*(0.12e2*_hc0[1]*_hc1[1]*_t108*_t11*_t215*_t31*_t38 + 0.4e1*_hc0[1]*_hc1[1]*_t109*_t31*_t38*_t62 + 0.6e1*_hc0[2]*_hc1[1]*_t11*_t145*_t19*_t215*_t38 + 0.2e1*_hc0[2]*_hc1[1]*_t145*_t18*_t38*_t62 + 0.6e1*_hc1[1]*_t148*_t149*_t19*_t215*_t38 - _t117*_t425 - _t117*_t426 - _t159*_t425 - _t215*_t39*_t876 - _t945*_t956) + _t118*_t437 + _t120*_t839 - _t120*_t840 + _t122*_t432 - _t14*_t958 + _t22*_t961 + _t306*_t916 - _t336*_t833 - _t338*_t829 + _t338*_t832 - _t399*_t874 + _t419*_t955 + _t421*_t445 + _t423*_t916 + _t424*_t442 - _t445*_t841 + _t448*_t842 + _t53*_t960 - _t936*_t956) + _t521;
  const double d4F_dna_dta_dtb2 = _t13*(_hc2[1]*(0.6e1*_hc0[1]*_hc1[2]*_t11*_t163*_t19*_t215*_t31 + 0.2e1*_hc0[1]*_hc1[2]*_t163*_t18*_t31*_t62 + 0.6e1*_t108*_t11*_t165*_t166*_t215 + 0.4e1*_t108*_t165*_t166*_t62 - _t108*_t452 + 0.2e1*_t109*_t165*_t166*_t62 - _t109*_t452 - _t164*_t441 - _t215*_t454*_t706 - _t32*_t454*_t744 - _t526*_t945) + _t106*_t455 + _t113*_t458 - _t14*_t963 + _t164*_t32*_t419 + _t22*_t970 + _t306*_t488 - _t306*_t863 + _t312*_t457 + _t338*_t916 + _t423*_t488 - _t423*_t863 + _t442*_t451 - _t445*_t865 + _t448*_t866 - _t526*_t936 + _t53*_t967 - _t864*_t98) + _t531;
  const double d4F_dna_dtb3 = _t13*(_hc2[1]*(0.18e2*_hc1[1]*_hc1[2]*_t11*_t19*_t215*_t533 + 0.6e1*_hc1[1]*_hc1[2]*_t18*_t533*_t62 + 0.12e2*_hc1[1]*_hc1[2]*_t19*_t533*_t62 - _t112*_t532 - _t18*_t974 - _t19*_t974 - 0.18e2*_t19*_t975 - _t535*_t945 - _t743*_t975) - _t101*_t532 + _t118*_t977 - _t14*_t976 + _t22*_t982 - _t338*_t971 + _t338*_t972 + _t455*_t973 + _t53*_t981 + _t534*_t934 - _t535*_t936) + _t541;
  const double d4F_dnb_dta3 = _t13*(0.18e2*_hc0[1]*_hc0[2]*_hc2[1]*_t11*_t215*_t27*_t503 + (0.14e2 / 0.3e1)*_hc0[1]*_hc0[2]*_hc2[2]*_t193*_t25*_t503*_t7*_t8 + 0.12e2*_hc2[1]*_t215*_t27*_t506*_t507 - _hc2[1]*_t508*_t985 + (0.14e2 / 0.3e1)*_t104*_t148*_t149*_t193*_t25*_t7*_t8 + 0.18e2*_t106*_t11*_t148*_t149*_t215*_t27 - _t106*_t240*_t431 - _t128*_t502 - _t130*_t462*_t502 + (0.1e1 / 0.2e1)*_t16*_t25*_t7*_t8*_t953 - _t25*_t939 + _t28*_t954 - _t437*_t801 - _t467*_t937 - 0.6e1*_t504*_t983 - _t508*_t984 - _t910*_t947) + _t515;
  const double d4F_dnb_dta2_dtb = _t13*(_hc2[1]*_t146*_t893 - _hc2[1]*_t480*_t987 + _t106*_t392*_t918 + _t122*_t886 - _t137*_t838 + _t137*_t911 - _t139*_t428*_t462 + _t141*_t146*_t983 + _t142*_t437 + _t146*_t474*_t813 + _t150*_t25*_t988 - _t25*_t958 + _t28*_t961 + _t374*_t435 - _t382*_t448 - _t39*_t908*_t935 - _t445*_t882 - _t451*_t461 - _t451*_t465 + _t467*_t916 + _t469*_t921 - _t469*_t923 - _t473*_t829 - _t491*_t829 + _t518*_t917 + _t76*_t960 - _t917*_t986) + _t521;
  const double d4F_dnb_dta_dtb2 = _t13*(_hc2[1]*_t164*_t27*_t479 + _hc2[1]*_t496*_t771 + _t104*_t899 - _t104*_t903 + _t106*_t497 + _t131*_t164*_t983 - _t132*_t458 - _t160*_t167*_t985 - _t160*_t596*_t867 + _t164*_t380*_t474 + _t167*_t25*_t989 - _t167*_t380*_t935 + _t216*_t917*_t918 - _t25*_t963 + _t28*_t970 + _t392*_t890*_t990 - _t420*_t928 + _t445*_t489 - _t445*_t900 + _t448*_t901 - _t467*_t863 + _t473*_t916 - _t487*_t919 + _t491*_t916 - _t492*_t525 + _t530*_t921 - _t530*_t923 + _t76*_t967) + _t531;
  const double d4F_dnb_dtb3 = _t13*(_hc2[1]*(0.18e2*_hc1[1]*_hc1[2]*_t11*_t215*_t27*_t533 + 0.18e2*_hc1[1]*_hc1[2]*_t27*_t533*_t62 + 0.18e2*_t11*_t139*_t165*_t166*_t215 + _t11*_t20*_t992 + _t12*_t992 - 0.2e1*_t130*_t532 + 0.18e2*_t139*_t165*_t166*_t62 - _t140*_t532 - _t20*_t492*_t787 - _t492*_t996 - _t493*_t995 - _t922*_t995 - _t944*_t994 - _t993*_t994) - _hc2[2]*_t487*_t725 + _t126*_t534*_t938 - _t128*_t532 + _t142*_t977 + (0.3e1 / 0.2e1)*_t161*_t487 - _t25*_t976 + _t26*((0.4e1 / 0.3e1)*_t485 + (0.5e1 / 0.9e1)*_t991) + _t28*_t982 + (0.3e1 / 0.2e1)*_t457*_t489 - _t473*_t971 + _t473*_t972 - _t491*_t971 + _t491*_t972 - _t494*_t928*_t99 + _t497*_t973 - _t535*_t984 + _t76*_t981) + _t541;
  const double d4F_dta4 = _t13*(_hc2[1]*(_t1000*_t944 - _t1000*_t993 - _t1003*_t513 + _t1003*_t946 + _t1004*_t1008 - _t1004*_t1010 - _t1007*_t998 + _t1009*_t998 + _t12*_t997 - _t21*_t997) + _t1000*_t1002 + _t1003*_t384 - _t1004*_t1005 + _t1006*_t104*_t504 - _t104*_t17*_t502 - _t146*_t17*_t435 + _t150*_t957 + _t153*_t941 - _t316*_t953 - _t35*_t997 + _t37*_t954 - _t508*_t989 + _t514*_t940 + _t998*_t999);
  const double d4F_dta3_dtb = _t13*(_hc2[1]*(_t1011*_t539 + _t159*_t502 - 0.18e2*_t216*_t39*_t504 + _t39*_t508*_t944 - _t890*_t943) - _hc2[2]*_t1011*_t474 + _hc2[2]*_t446*_t502 + _t1001*_t39*_t509 + _t1012*_t104 - _t1013*_t39*_t512 + _t120*_t948 - _t120*_t949 + _t122*_t514 + _t158*_t435 - _t170*_t502 - _t316*_t960 + _t37*_t961 + _t424*_t519 + _t437*_t447 - _t445*_t950 + _t445*_t951 + _t448*_t952);
  const double d4F_dta2_dtb2 = _t13*(_hc2[1]*(-_t146*_t528 - _t164*_t518 + _t164*_t986 + _t167*_t987 + _t428*_t495 - _t453*_t875) + _t1001*_t151*_t167 + _t1012*_t120 - _t1013*_t120*_t956 + _t1014*_t523 - _t1014*_t968 + _t1015*_t164*_t63 - _t1015*_t453 - _t104*_t527 + _t104*_t964 - _t106*_t969 + _t153*_t458 - _t164*_t517 - _t316*_t967 + _t37*_t970 + _t434*_t457 + _t445*_t529 + _t448*_t966 + _t451*_t519 - _t457*_t853);
  const double d4F_dta_dtb3 = _t13*(_t1002*_t32*_t535 + _t147*_t524*_t532 + _t157*_t962 - 0.18e2*_t160*_t216*_t534 - _t160*_t534*_t539 + _t160*_t535*_t944 + 0.12e2*_t160*_t975 + _t164*_t920 - 0.18e2*_t167*_t216*_t990 - _t316*_t981 + _t32*_t458*_t996 + _t37*_t982 - _t474*_t524*_t534 + _t525*_t532 - _t526*_t988 + _t63*_t990*_t995 - _t931*_t990);
  const double d4F_dtb4 = _t13*(_hc2[1]*(_t1007*_t1017 - _t1008*_t1020 + _t1009*_t1017 - _t1010*_t1020 - _t1016*_t12 - _t1016*_t21 + _t1018*_t944 + _t1018*_t993 + _t1019*_t513 + _t1019*_t946) + _t1002*_t1018 - _t1005*_t1020 + _t1006*_t120*_t534 - _t1016*_t35 + _t1017*_t999 + _t1019*_t384 - _t120*_t17*_t532 - _t121*_t981 - _t164*_t17*_t457 + _t167*_t962 + _t169*_t977 + _t41*_t982 - _t535*_t988 + _t540*_t973);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 1] += d4F_dna3_dtb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 2] += d4F_dna2_dnb_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 3] += d4F_dna2_dnb_dtb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 4] += d4F_dna_dnb2_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 5] += d4F_dna_dnb2_dtb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 6] += d4F_dnb3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 7] += d4F_dnb3_dtb;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 1] += d4F_dna2_dta_dtb;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 2] += d4F_dna2_dtb2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 3] += d4F_dna_dnb_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 4] += d4F_dna_dnb_dta_dtb;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 5] += d4F_dna_dnb_dtb2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 6] += d4F_dnb2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 7] += d4F_dnb2_dta_dtb;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 8] += d4F_dnb2_dtb2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 1] += d4F_dna_dta2_dtb;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 2] += d4F_dna_dta_dtb2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 3] += d4F_dna_dtb3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 4] += d4F_dnb_dta3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 5] += d4F_dnb_dta2_dtb;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 6] += d4F_dnb_dta_dtb2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 7] += d4F_dnb_dtb3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 1] += d4F_dta3_dtb;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 2] += d4F_dta2_dtb2;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 3] += d4F_dta_dtb3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 4] += d4F_dtb4;
#endif
#endif
}
#endif