/*
  Generated from python/gga_exc/gga_c_wl.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_wl
*/

#ifndef _GGA_C_WL_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_WL_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_WL_HELPER_BODIES
#include "gga_c_wl.c"
#undef _GGA_C_WL_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_WL_HELPER_BODIES
#include "gga_c_wl.c"
#undef _GGA_C_WL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_WL_HELPER_BODIES
#include "gga_c_wl.c"
#undef _GGA_C_WL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_WL_HELPER_BODIES
#include "gga_c_wl.c"
#undef _GGA_C_WL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_WL_HELPER_BODIES
#include "gga_c_wl.c"
#undef _GGA_C_WL_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_wl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_wl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_wl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_wl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_wl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_wl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_wl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_wl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_wl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_wl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_WL_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_den_k, _KMAX)(const xc_func_type *p, double rs, double xs0, double xs1, double *out) {


  const double f = rs + 0.90000000000000002*xs0 + 0.90000000000000002*xs1 + 3.60073;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs1 = 0.90000000000000002;
  out[1] = df_dxs1;
  const double df_dxs0 = 0.90000000000000002;
  out[2] = df_dxs0;
  const double df_drs = 0.1e1;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxs12 = 0;
  out[4] = d2f_dxs12;
  const double d2f_dxs0_dxs1 = 0;
  out[5] = d2f_dxs0_dxs1;
  const double d2f_dxs02 = 0;
  out[6] = d2f_dxs02;
  const double d2f_drs_dxs1 = 0;
  out[7] = d2f_drs_dxs1;
  const double d2f_drs_dxs0 = 0;
  out[8] = d2f_drs_dxs0;
  const double d2f_drs2 = 0;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxs13 = 0;
  out[10] = d3f_dxs13;
  const double d3f_dxs0_dxs12 = 0;
  out[11] = d3f_dxs0_dxs12;
  const double d3f_dxs02_dxs1 = 0;
  out[12] = d3f_dxs02_dxs1;
  const double d3f_dxs03 = 0;
  out[13] = d3f_dxs03;
  const double d3f_drs_dxs12 = 0;
  out[14] = d3f_drs_dxs12;
  const double d3f_drs_dxs0_dxs1 = 0;
  out[15] = d3f_drs_dxs0_dxs1;
  const double d3f_drs_dxs02 = 0;
  out[16] = d3f_drs_dxs02;
  const double d3f_drs2_dxs1 = 0;
  out[17] = d3f_drs2_dxs1;
  const double d3f_drs2_dxs0 = 0;
  out[18] = d3f_drs2_dxs0;
  const double d3f_drs3 = 0;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxs14 = 0;
  out[20] = d4f_dxs14;
  const double d4f_dxs0_dxs13 = 0;
  out[21] = d4f_dxs0_dxs13;
  const double d4f_dxs02_dxs12 = 0;
  out[22] = d4f_dxs02_dxs12;
  const double d4f_dxs03_dxs1 = 0;
  out[23] = d4f_dxs03_dxs1;
  const double d4f_dxs04 = 0;
  out[24] = d4f_dxs04;
  const double d4f_drs_dxs13 = 0;
  out[25] = d4f_drs_dxs13;
  const double d4f_drs_dxs0_dxs12 = 0;
  out[26] = d4f_drs_dxs0_dxs12;
  const double d4f_drs_dxs02_dxs1 = 0;
  out[27] = d4f_drs_dxs02_dxs1;
  const double d4f_drs_dxs03 = 0;
  out[28] = d4f_drs_dxs03;
  const double d4f_drs2_dxs12 = 0;
  out[29] = d4f_drs2_dxs12;
  const double d4f_drs2_dxs0_dxs1 = 0;
  out[30] = d4f_drs2_dxs0_dxs1;
  const double d4f_drs2_dxs02 = 0;
  out[31] = d4f_drs2_dxs02;
  const double d4f_drs3_dxs1 = 0;
  out[32] = d4f_drs3_dxs1;
  const double d4f_drs3_dxs0 = 0;
  out[33] = d4f_drs3_dxs0;
  const double d4f_drs4 = 0;
  out[34] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = xc_powr(na, -1, 3);
  const double _t2 = xc_powr(0.6e1, 1, 3)/M_CBRTPI;
  const double _t3 = (0.1e1 / 0.2e1)*_t2;
  const double _t4 = M_CBRT2;
  const double _t5 = xc_powr(gaa, 1, 2);
  const double _t6 = xc_powr(na, -4, 3);
  const double _t7 = _t5*_t6;
  const double _t8 = _t4*_t7;
  const double _t10 = 0.060010000000000001*_t7 - 0.74860000000000004;
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(f_den_k, _KMAX)(p, _t1*_t3, _t8, _t8, _hc0);
  const double _t9 = (0.1e1 / (_hc0[0]));
  const double _t11 = _t10*_t9;
  const double zk = _t11;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t12 = 0.080013333333333325*_t7;
  const double _t15 = xc_powr(na, -7, 3);
  const double _t16 = (0.4e1 / 0.3e1)*_t15;
  const double _t25 = (0.1e1 / _t5);
  const double _t27 = 0.030005*_t1;
  const double _t28 = _t25*_t6;
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(f_den_k, _KMAX)(p, 0, 0, 0, _hc1);
  const double _t13 = _hc1[1]*_t4;
  const double _t14 = _t13*_t5;
  const double _t17 = _hc1[2]*_t4;
  const double _t18 = _t17*_t5;
  const double _t19 = _hc1[3]*_t2;
  const double _t20 = _t19*_t6;
  const double _t21 = _t14*_t16 + _t16*_t18 + (0.1e1 / 0.6e1)*_t20;
  const double _t22 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t23 = _t10*_t22;
  const double _t24 = _t21*_t23;
  const double _t26 = _t25*_t9;
  const double _t29 = _t13*_t28;
  const double _t30 = _t17*_t28;
  const double _t31 = -0.1e1 / 0.2e1*_t29 - 0.1e1 / 0.2e1*_t30;
  const double _t32 = _t23*_t31;
  const double dF_dna = _t11 - _t12*_t9 + _t24*na;
  const double dF_dgaa = _t26*_t27 + _t32*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t34 = 0.026671111111111104*_t15;
  const double _t36 = 0.16002666666666665*_t7;
  const double _t37 = xc_powr(na, -10, 3);
  const double _t38 = (0.28e2 / 0.9e1)*_t37;
  const double _t45 = (0.8e1 / 0.3e1)*_t15;
  const double _t48 = 0.010001666666666662*_t6;
  const double _t51 = (0.2e1 / 0.3e1)*_t15;
  const double _t54 = _t25*_t27;
  const double _t57 = xc_powr(gaa, -3, 2);
  const double _t59 = 0.0150025*_t1;
  const double _t60 = _t1*_t25;
  const double _t61 = 0.060010000000000001*_t60;
  const double _t63 = (0.1e1 / 0.4e1)*_t6;
  const double _t33 = _t5*_t9;
  const double _t35 = _t21*_t22;
  const double _t39 = _t15*_t19;
  const double _t40 = -_t14*_t38 - _t18*_t38 - 0.2e1 / 0.9e1*_t39;
  const double _t41 = _t23*na;
  const double _t42 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t43 = _t10*_t42;
  const double _t44 = _t21*_t43;
  const double _t46 = _t14*_t45 + _t18*_t45 + (0.1e1 / 0.3e1)*_t20;
  const double _t47 = _t46*na;
  const double _t49 = _t22*_t31;
  const double _t50 = _t13*_t25;
  const double _t52 = _t17*_t25;
  const double _t53 = _t50*_t51 + _t51*_t52;
  const double _t55 = -_t29 - _t30;
  const double _t56 = _t44*na;
  const double _t58 = _t57*_t9;
  const double _t62 = _t13*_t57;
  const double _t64 = _t17*_t57;
  const double _t65 = _t62*_t63 + _t63*_t64;
  const double _t66 = _t23*_t65;
  const double _t67 = _t31*_t55;
  const double _t68 = _t43*_t67;
  const double d2F_dna2 = 0.2e1*_t24 + _t33*_t34 - _t35*_t36 + _t40*_t41 + _t44*_t47;
  const double d2F_dna_dgaa = -_t12*_t49 - _t26*_t48 + _t32 + _t35*_t54 + _t41*_t53 + _t55*_t56;
  const double d2F_dgaa2 = _t49*_t61 - _t58*_t59 + _t66*na + _t68*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t69 = 0.062232592592592582*_t37;
  const double _t70 = _t15*_t5;
  const double _t71 = 0.080013333333333297*_t70;
  const double _t73 = 0.24003999999999998*_t7;
  const double _t75 = xc_powr(na, -13, 3);
  const double _t76 = (0.280e3 / 0.27e2)*_t75;
  const double _t82 = (0.56e2 / 0.9e1)*_t37;
  const double _t87 = 0.4e1*_t15;
  const double _t95 = (0.14e2 / 0.9e1)*_t37;
  const double _t97 = 0.020003333333333324*_t28;
  const double _t106 = (0.1e1 / 0.3e1)*_t15;
  const double _t111 = (0.1e1 / 0.2e1)*_t6;
  const double _t116 = xc_powr(gaa, -5, 2);
  const double _t118 = 0.022503749999999999*_t1;
  const double _t120 = 0.045007499999999999*_t1;
  const double _t121 = 0.090014999999999998*_t60;
  const double _t123 = (0.3e1 / 0.8e1)*_t6;
  const double _t72 = _t22*_t40;
  const double _t74 = 0.3e1*_t23;
  const double _t77 = _t19*_t37;
  const double _t78 = _t14*_t76 + _t18*_t76 + (0.14e2 / 0.27e2)*_t77;
  const double _t79 = _t21*_t42;
  const double _t80 = _t46*_t79;
  const double _t81 = 0.3e1*_t46;
  const double _t83 = -_t14*_t82 - _t18*_t82 - 0.4e1 / 0.9e1*_t39;
  const double _t84 = _t40*_t43;
  const double _t85 = 0.2e1*_t84;
  const double _t86 = _t21*_t47;
  const double _t88 = _hc1[3]*_t3*_t6 + _t14*_t87 + _t18*_t87;
  const double _t89 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t90 = _t10*_t89;
  const double _t91 = _t88*_t90;
  const double _t92 = _t49*_t5;
  const double _t93 = _t22*_t53;
  const double _t94 = 0.2e1*_t23;
  const double _t96 = -_t50*_t95 - _t52*_t95;
  const double _t98 = _t55*_t79;
  const double _t99 = 0.2e1*_t55;
  const double _t100 = _t43*_t53;
  const double _t101 = _t16*_t50 + _t16*_t52;
  const double _t102 = _t55*na;
  const double _t103 = -0.3e1 / 0.2e1*_t29 - 0.3e1 / 0.2e1*_t30;
  const double _t104 = _t103*_t90;
  const double _t105 = _t22*_t65;
  const double _t107 = -_t106*_t62 - _t106*_t64;
  const double _t108 = _t35*_t57;
  const double _t109 = _t42*_t67;
  const double _t110 = _t100*na;
  const double _t112 = _t111*_t62 + _t111*_t64;
  const double _t113 = _t112*_t43;
  const double _t114 = _t113*_t21;
  const double _t115 = _t104*_t21;
  const double _t117 = _t116*_t9;
  const double _t119 = _t49*_t57;
  const double _t122 = _t116*_t13;
  const double _t124 = _t116*_t17;
  const double _t125 = -_t122*_t123 - _t123*_t124;
  const double _t126 = _t125*_t23;
  const double _t127 = _t113*_t31;
  const double _t128 = _t43*_t99;
  const double _t129 = _t128*_t65;
  const double _t130 = _t104*_t67;
  const double d3F_dna3 = -_t33*_t69 + _t35*_t71 + _t40*_t74 + _t41*_t78 + _t44*_t81 + _t47*_t85 + _t56*_t83 - _t72*_t73 - _t73*_t80 + _t86*_t91;
  const double d3F_dna2_dgaa = _t100*_t47 + _t101*_t56 + _t102*_t84 + _t104*_t86 + 0.013335555555555552*_t15*_t26 + _t34*_t92 - _t35*_t97 - _t36*_t93 - _t36*_t98 + _t41*_t96 + _t44*_t99 + _t53*_t94 + _t54*_t72 + _t54*_t80;
  const double d3F_dna_dgaa2 = _t102*_t115 - _t105*_t12 + _t107*_t41 - _t108*_t59 - _t109*_t12 + _t110*_t99 + _t114*na - _t49*_t97 + 0.0050008333333333311*_t58*_t6 + _t61*_t93 + _t61*_t98 + _t66 + _t68;
  const double d3F_dgaa3 = _t105*_t121 + _t109*_t121 + _t117*_t118 - _t119*_t120 + _t126*na + _t127*na + _t129*na + _t130*na;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t131 = 0.16002666666666662*_t70;
  const double _t133 = 0.3200533333333333*_t7;
  const double _t134 = (0.3640e4 / 0.81e2)/xc_powr(na, 16, 3);
  const double _t138 = (0.560e3 / 0.27e2)*_t75;
  const double _t146 = (0.28e2 / 0.3e1)*_t37;
  const double _t148 = (0.16e2 / 0.3e1)*_t15;
  const double _t153 = (0.140e3 / 0.27e2)*_t75;
  const double _t154 = 0.03000499999999999*_t28;
  const double _t163 = 0.2e1*_t15;
  const double _t166 = 0.040006666666666649*_t28;
  const double _t167 = _t34*_t5;
  const double _t169 = (0.7e1 / 0.9e1)*_t37;
  const double _t170 = _t57*_t59;
  const double _t178 = (0.3e1 / 0.4e1)*_t6;
  const double _t181 = _t120*_t57;
  const double _t182 = 0.030004999999999987*_t28;
  const double _t184 = (0.1e1 / 0.2e1)*_t15;
  const double _t196 = xc_powr(gaa, -7, 2);
  const double _t197 = 0.090014999999999998*_t1;
  const double _t198 = _t197*_t57;
  const double _t199 = 0.12002*_t60;
  const double _t200 = (0.15e2 / 0.16e2)*_t196*_t6;
  const double _t132 = _t22*_t78;
  const double _t135 = _t79*_t83;
  const double _t136 = _t40*_t42;
  const double _t137 = _t136*_t46;
  const double _t139 = _t43*_t78;
  const double _t140 = 0.3e1*_t47;
  const double _t141 = 0.3e1*_t84;
  const double _t142 = _t83*na;
  const double _t143 = _t21*_t89;
  const double _t144 = _t143*_t46*_t88;
  const double _t145 = _t21*_t91;
  const double _t147 = _t86*_t90;
  const double _t149 = _t10/xc_powi((_hc0[0]), 5);
  const double _t150 = _t149*_t86;
  const double _t151 = _t150*_t88;
  const double _t152 = _t22*_t96;
  const double _t155 = _t42*_t53;
  const double _t156 = _t46*_t73;
  const double _t157 = _t101*_t79;
  const double _t158 = _t136*_t55;
  const double _t159 = _t43*_t47;
  const double _t160 = _t101*na;
  const double _t161 = _t103*_t143;
  const double _t162 = _t47*_t53;
  const double _t164 = _t104*_t40;
  const double _t165 = -0.2e1*_t29 - 0.2e1*_t30;
  const double _t168 = _t107*_t22;
  const double _t171 = _t155*_t55;
  const double _t172 = _t46*_t61;
  const double _t173 = _t112*_t79;
  const double _t174 = _t113*na;
  const double _t175 = _t36*_t55;
  const double _t176 = 0.2e1*_t104;
  const double _t177 = 0.2e1*_t115;
  const double _t179 = _t178*_t62 + _t178*_t64;
  const double _t180 = _t103*_t165;
  const double _t183 = _t125*_t22;
  const double _t185 = _t42*_t65;
  const double _t186 = _t112*_t31*_t42;
  const double _t187 = 0.3e1*_t102;
  const double _t188 = _t187*_t43;
  const double _t189 = 0.3e1*_t174;
  const double _t190 = -_t122*_t178 - _t124*_t178;
  const double _t191 = _t103*_t67*_t89;
  const double _t192 = _t104*_t187;
  const double _t193 = _t179*_t90;
  const double _t194 = _t102*_t21;
  const double _t195 = _t149*_t180;
  const double _t201 = _t31*na;
  const double _t202 = _t67*na;
  const double d4F_dna4 = _t131*_t72 + _t131*_t80 - _t132*_t133 - _t133*_t135 - _t133*_t144 - 0.6401066666666666*_t137*_t7 + _t139*_t140 + _t140*_t40*_t91 + _t141*_t142 + 0.2e1*_t142*_t145 + 0.4e1*_t145*_t46 + _t147*(-_t14*_t146 - _t146*_t18 - 0.2e1 / 0.3e1*_t39) + _t151*(_t14*_t148 + _t148*_t18 + (0.2e1 / 0.3e1)*_t20) + 0.4e1*_t23*_t78 + 0.20744197530864195*_t33*_t75 - 0.2489303703703703*_t35*_t37*_t5 + _t41*(-_t134*_t14 - _t134*_t18 - 0.140e3 / 0.81e2*_t19*_t75) + 0.4e1*_t44*_t83 + 0.8e1*_t46*_t84 + _t56*(_t138*_t14 + _t138*_t18 + (0.28e2 / 0.27e2)*_t77);
  const double d4F_dna3_dgaa = _t100*_t81 + 0.3e1*_t101*_t44 + _t102*_t139 + _t110*_t83 + _t115*_t142 + _t115*_t81 + _t132*_t54 + _t135*_t54 + _t137*_t61 + _t141*_t55 + _t144*_t54 + _t145*_t160 + _t147*(_t163*_t50 + _t163*_t52) + 0.040006666666666649*_t15*_t25*_t35 + _t151*_t165 - _t152*_t73 - _t154*_t72 - _t154*_t80 - _t155*_t156 - _t156*_t161 - _t157*_t73 - _t158*_t73 + 0.2e1*_t159*_t96 + _t160*_t85 + _t162*_t91 + 0.2e1*_t164*_t47 - 0.031116296296296291*_t26*_t37 + _t41*(_t153*_t50 + _t153*_t52) + _t56*(-_t38*_t50 - _t38*_t52) - _t69*_t92 + _t71*_t93 + _t71*_t98 + _t74*_t96;
  const double d4F_dna2_dgaa2 = 0.4e1*_t100*_t55 + 0.2e1*_t101*_t110 + _t102*_t164 + _t105*_t167 + _t107*_t159 + _t107*_t94 + _t108*_t48 + _t109*_t167 + 0.2e1*_t114 + _t115*_t99 + _t128*_t96*na - _t133*_t171 + _t147*_t179 - 0.0066677777777777759*_t15*_t58 + _t150*_t180 + _t152*_t61 + _t155*_t172 + _t157*_t61 + _t158*_t61 + _t160*_t177 + _t161*_t172 - _t161*_t175 + _t162*_t176 - _t166*_t93 - _t166*_t98 - _t168*_t36 - _t170*_t72 - _t170*_t80 - _t173*_t36 + _t174*_t40 + _t25*_t34*_t49 + _t41*(_t169*_t62 + _t169*_t64) + _t56*(-_t51*_t62 - _t51*_t64);
  const double d4F_dna_dgaa3 = -_t105*_t182 + _t107*_t188 - _t109*_t182 + _t112*_t177*na + _t116*_t118*_t35 - 0.0075012499999999966*_t117*_t6 + 0.015002499999999993*_t119*_t6 - _t12*_t183 - _t12*_t186 - _t12*_t191 + _t121*_t161*_t55 + _t121*_t168 + _t121*_t173 + _t126 + _t127 + _t129 + _t130 + 0.18003*_t171*_t60 - _t175*_t185 - _t181*_t93 - _t181*_t98 + _t189*_t53 + _t190*_t56 + _t192*_t53 + _t193*_t194 + _t194*_t195 + _t41*(_t122*_t184 + _t124*_t184);
  const double d4F_dgaa4 = -0.056259375*_t1*_t196*_t9 - _t105*_t198 - _t109*_t198 + _t112*_t176*_t201 + _t116*_t197*_t49 + _t125*_t188 + _t183*_t199 + 0.24003999999999998*_t185*_t55*_t60 + _t186*_t199 + _t189*_t65 + _t190*_t201*_t43 + _t191*_t199 + _t192*_t65 + _t193*_t202 + _t195*_t202 + _t41*(_t13*_t200 + _t17*_t200);
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
  const double gab = sigma[1];
  const double gbb = sigma[2];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = (0.1e1 / 0.2e1)*_t4;
  const double _t6 = xc_powr(gaa, 1, 2);
  const double _t7 = xc_powr(gbb, 1, 2);
  const double _t9 = xc_powr(_t1, -4, 3);
  const double _t10 = gaa + 0.2e1*gab + gbb;
  const double _t11 = xc_powr(_t10, 1, 2);
  const double _t12 = 0.060010000000000001*_t11*_t9 - 0.74860000000000004;
  const double _t14 = xc_powr(nb, 1, 2);
  const double _t15 = xc_powr(na, 1, 2);
  const double _t16 = _t14*_t15;
  const double _t17 = 0.2e1*_t16;
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(f_den_k, _KMAX)(p, _t5/xc_powr(_t1, 1, 3), _t6/xc_powr(na, 4, 3), _t7/xc_powr(nb, 4, 3), _hc0);
  const double _t8 = (0.1e1 / (_hc0[0]));
  const double _t13 = _t12*_t8;
  const double zk = _t13*_t17/_t1;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t19 = xc_powr(_t1, -7, 3);
  const double _t20 = _t11*_t19;
  const double _t21 = 0.16002666666666665*_t20;
  const double _t23 = (0.1e1 / _t15);
  const double _t24 = _t14*_t23;
  const double _t34 = (0.1e1 / _t14);
  const double _t40 = 0.060010000000000001*_t9;
  const double _t41 = (0.1e1 / _t11);
  const double _t44 = (0.1e1 / _t6);
  const double _t47 = xc_powr(na, -5, 6);
  const double _t48 = _t14*_t47;
  const double _t49 = 0.12002*_t9;
  const double _t50 = (0.1e1 / _t7);
  const double _t52 = xc_powr(nb, -5, 6);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(f_den_k, _KMAX)(p, 0, 0, 0, _hc1);
  const double _t18 = _t16*_t8;
  const double _t22 = -_t18*_t21;
  const double _t25 = _hc1[2]*_t6;
  const double _t26 = _t25/xc_powr(na, 7, 3);
  const double _t27 = _hc1[3]*_t4;
  const double _t28 = _t27*_t9;
  const double _t29 = (0.1e1 / 0.6e1)*_t28;
  const double _t30 = (0.4e1 / 0.3e1)*_t26 + _t29;
  const double _t31 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t32 = _t12*_t31;
  const double _t33 = _t30*_t32;
  const double _t35 = _t13*_t34;
  const double _t36 = _hc1[1]*_t7;
  const double _t37 = _t36/xc_powr(nb, 7, 3);
  const double _t38 = _t29 + (0.4e1 / 0.3e1)*_t37;
  const double _t39 = _t32*_t38;
  const double _t42 = _t18*_t41;
  const double _t43 = _t40*_t42;
  const double _t45 = _hc1[2]*_t44;
  const double _t46 = _t32*_t45;
  const double _t51 = _t32*_t50;
  const double _t53 = _hc1[1]*_t52;
  const double _t54 = _t15*_t53;
  const double dF_dna = _t13*_t24 + _t17*_t33 + _t22;
  const double dF_dnb = _t15*_t35 + _t17*_t39 + _t22;
  const double dF_dgaa = _t43 - _t46*_t48;
  const double dF_dgab = _t42*_t49;
  const double dF_dgbb = _t43 - _t51*_t54;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t56 = xc_powr(_t1, -10, 3);
  const double _t57 = _t11*_t56;
  const double _t58 = 0.37339555555555554*_t57;
  const double _t61 = xc_powr(na, -3, 2);
  const double _t62 = _t14*_t61;
  const double _t66 = 0.2e1*_t24;
  const double _t78 = 0.080013333333333325*_t20;
  const double _t79 = _t15*_t34;
  const double _t81 = (0.1e1 / 0.2e1)*_t23;
  const double _t87 = xc_powr(nb, -3, 2);
  const double _t88 = _t15*_t87;
  const double _t97 = 0.030005*_t9;
  const double _t104 = xc_powr(na, -11, 6);
  const double _t105 = (0.5e1 / 0.6e1)*_t104;
  const double _t109 = 0.2e1*_t48;
  const double _t116 = (0.1e1 / 0.2e1)*_t47;
  const double _t119 = xc_powr(nb, -11, 6);
  const double _t123 = xc_powr(_t10, -3, 2);
  const double _t129 = xc_powr(gaa, -3, 2);
  const double _t131 = (0.1e1 / gaa);
  const double _t132 = xc_powr(na, -13, 6);
  const double _t136 = xc_powr(gbb, -3, 2);
  const double _t138 = (0.1e1 / gbb);
  const double _t139 = xc_powr(nb, -13, 6);
  const double _t55 = _t24*_t8;
  const double _t59 = _t18*_t58;
  const double _t60 = (0.1e1 / 0.2e1)*_t13;
  const double _t63 = _t20*_t30;
  const double _t64 = _t16*_t31;
  const double _t65 = 0.3200533333333333*_t64;
  const double _t67 = _t25/xc_powr(na, 10, 3);
  const double _t68 = _t19*_t27;
  const double _t69 = (0.2e1 / 0.9e1)*_t68;
  const double _t70 = -0.28e2 / 0.9e1*_t67 - _t69;
  const double _t71 = _t17*_t32;
  const double _t72 = (0.1e1 / 0.3e1)*_t28;
  const double _t73 = (0.8e1 / 0.3e1)*_t26 + _t72;
  const double _t74 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t75 = _t12*_t74;
  const double _t76 = _t30*_t75;
  const double _t77 = _t17*_t76;
  const double _t80 = _t79*_t8;
  const double _t82 = (0.4e1 / 0.9e1)*_t68;
  const double _t83 = _t16*_t32;
  const double _t84 = _t21*_t64;
  const double _t85 = _t24*_t32;
  const double _t86 = (0.8e1 / 0.3e1)*_t37 + _t72;
  const double _t89 = _t20*_t38;
  const double _t90 = _t32*_t79;
  const double _t91 = 0.2e1*_t38;
  const double _t92 = _t36/xc_powr(nb, 10, 3);
  const double _t93 = -_t69 - 0.28e2 / 0.9e1*_t92;
  const double _t94 = _t75*_t86;
  const double _t95 = _t17*_t94;
  const double _t96 = _t41*_t55;
  const double _t98 = _t19*_t42;
  const double _t99 = 0.080013333333333325*_t98;
  const double _t100 = -_t99;
  const double _t101 = _t31*_t78;
  const double _t102 = _t45*_t48;
  const double _t103 = _t14*_t46;
  const double _t106 = _t41*_t64;
  const double _t107 = _t30*_t40;
  const double _t108 = _t45*_t76;
  const double _t110 = -0.16002666666666665*_t98;
  const double _t111 = _t106*_t49;
  const double _t112 = _t51*_t53;
  const double _t113 = _t50*_t54;
  const double _t114 = 0.2e1*_t76;
  const double _t115 = _t34*_t46;
  const double _t117 = _t75*_t91;
  const double _t118 = _t41*_t80;
  const double _t120 = _hc1[1]*_t51;
  const double _t121 = _t119*_t120;
  const double _t122 = _t106*_t40;
  const double _t124 = _t123*_t18;
  const double _t125 = _t124*_t97;
  const double _t126 = _t31*_t41;
  const double _t127 = _t126*_t40;
  const double _t128 = _t102*_t127;
  const double _t130 = ((_hc1[2]) * (_hc1[2]));
  const double _t133 = _t124*_t40;
  const double _t134 = _t126*_t97;
  const double _t135 = _t113*_t127;
  const double _t137 = ((_hc1[1]) * (_hc1[1]));
  const double d2F_dna2 = -_t21*_t55 + _t33*_t66 + _t59 - _t60*_t62 - _t63*_t65 + _t70*_t71 + _t73*_t77;
  const double d2F_dna_dnb = -_t30*_t84 + _t33*_t79 + _t35*_t81 - _t38*_t84 + _t38*_t85 - _t55*_t78 + _t59 + _t77*_t86 - _t78*_t80 - _t82*_t83;
  const double d2F_dnb2 = -_t21*_t80 + _t38*_t95 + _t59 - _t60*_t88 - _t65*_t89 + _t71*_t93 + _t90*_t91;
  const double d2F_dna_dgaa = _t100 + _t101*_t102 + _t103*_t105 + _t106*_t107 - _t108*_t109 + _t96*_t97;
  const double d2F_dna_dgab = _t110 + _t111*_t30 + _t40*_t96;
  const double d2F_dna_dgbb = 0.080013333333333325*_hc1[1]*_t11*_t15*_t19*_t31*_t50*_t52 - _t112*_t81 - _t113*_t114 + 0.060010000000000001*_t14*_t15*_t30*_t31*_t41*_t9 + 0.030005*_t14*_t23*_t41*_t8*_t9 - _t99;
  const double d2F_dnb_dgaa = 0.080013333333333325*_hc1[2]*_t11*_t14*_t19*_t31*_t44*_t47 - _t102*_t117 - _t115*_t116 + 0.060010000000000001*_t14*_t15*_t31*_t38*_t41*_t9 + 0.030005*_t15*_t34*_t41*_t8*_t9 - _t99;
  const double d2F_dnb_dgab = _t110 + _t111*_t38 + _t118*_t40;
  const double d2F_dnb_dgbb = _t100 + _t101*_t113 - _t113*_t117 + _t118*_t97 + (0.5e1 / 0.6e1)*_t121*_t15 + _t122*_t38;
  const double d2F_dgaa2 = (0.1e1 / 0.2e1)*_hc1[2]*_t12*_t129*_t14*_t31*_t47 + _t12*_t130*_t131*_t132*_t14*_t74 - _t125 - _t128;
  const double d2F_dgaa_dgab = -_t128 - _t133;
  const double d2F_dgaa_dgbb = _hc1[1]*_hc1[2]*_t12*_t44*_t47*_t50*_t52*_t74 - _t102*_t134 - _t113*_t134 - _t125;
  const double d2F_dgab2 = -_t124*_t49;
  const double d2F_dgab_dgbb = -_t133 - _t135;
  const double d2F_dgbb2 = (0.1e1 / 0.2e1)*_hc1[1]*_t12*_t136*_t15*_t31*_t52 + _t12*_t137*_t138*_t139*_t15*_t74 - _t125 - _t135;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 1] += d2F_dna_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 2] += d2F_dna_dgbb;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 3] += d2F_dnb_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 4] += d2F_dnb_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 1] += d2F_dgaa_dgab;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 2] += d2F_dgaa_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 3] += d2F_dgab2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 4] += d2F_dgab_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
#endif
#if _KMAX >= 3
  const double _t143 = xc_powr(_t1, -13, 3);
  const double _t144 = 1.2446518518518519*_t143;
  const double _t148 = xc_powr(na, -5, 2);
  const double _t149 = _t14*_t148;
  const double _t153 = 1.1201866666666667*_t57;
  const double _t155 = 0.48007999999999995*_t20;
  const double _t156 = (0.3e1 / 0.2e1)*_t62;
  const double _t167 = 0.4e1*_t16;
  const double _t177 = _t23*_t34;
  const double _t180 = (0.1e1 / 0.4e1)*_t61;
  const double _t181 = xc_powr(_t1, -14, 3);
  const double _t188 = (0.1e1 / 0.2e1)*_t62;
  const double _t200 = (0.1e1 / 0.4e1)*_t23;
  const double _t207 = 0.74679111111111107*_t57;
  const double _t208 = (0.1e1 / 0.2e1)*_t88;
  const double _t215 = xc_powr(nb, -5, 2);
  const double _t216 = _t15*_t215;
  const double _t220 = (0.3e1 / 0.2e1)*_t88;
  const double _t229 = 0.0150025*_t9;
  const double _t241 = 0.18669777777777777*_t57;
  const double _t243 = xc_powr(na, -17, 6);
  const double _t252 = _t41*_t49;
  const double _t263 = (0.5e1 / 0.12e2)*_t104;
  const double _t266 = _t34*_t47;
  const double _t281 = xc_powr(_t1, -11, 3);
  const double _t303 = _t40*_t41;
  const double _t308 = xc_powr(nb, -17, 6);
  const double _t314 = xc_powr(na, -19, 6);
  const double _t335 = 0.080013333333333325*_t19;
  const double _t371 = 0.3e1*_t14;
  const double _t378 = xc_powr(nb, -19, 6);
  const double _t380 = 0.045007499999999999*_t9;
  const double _t381 = xc_powr(_t10, -5, 2);
  const double _t385 = _t123*_t380;
  const double _t386 = 0.090014999999999998*_t9;
  const double _t387 = _t386*_t41;
  const double _t390 = xc_powr(gaa, -5, 2);
  const double _t394 = xc_powr(na, -7, 2);
  const double _t395 = _t14*_t394;
  const double _t399 = (0.1e1 / (gaa * gaa));
  const double _t403 = _t123*_t40;
  const double _t405 = _t123*_t229;
  const double _t406 = _t41*_t97;
  const double _t408 = _t123*_t97;
  const double _t419 = xc_powr(gbb, -5, 2);
  const double _t421 = xc_powr(nb, -7, 2);
  const double _t422 = _t15*_t421;
  const double _t426 = (0.1e1 / (gbb * gbb));
  const double _t140 = _t20*_t8;
  const double _t141 = _t55*_t57;
  const double _t142 = _t11*_t18;
  const double _t145 = _t142*_t144;
  const double _t146 = -_t145;
  const double _t147 = (0.3e1 / 0.4e1)*_t13;
  const double _t150 = _t24*_t31;
  const double _t151 = 0.48007999999999995*_t63;
  const double _t152 = _t30*_t64;
  const double _t154 = _t64*_t70;
  const double _t157 = 0.3e1*_t70;
  const double _t158 = _t25/xc_powr(na, 13, 3);
  const double _t159 = _t27*_t56;
  const double _t160 = (0.14e2 / 0.27e2)*_t159;
  const double _t161 = (0.280e3 / 0.27e2)*_t158 + _t160;
  const double _t162 = _t16*_t74;
  const double _t163 = _t162*_t73;
  const double _t164 = _t24*_t76;
  const double _t165 = 0.3e1*_t73;
  const double _t166 = -0.56e2 / 0.9e1*_t67 - _t82;
  const double _t168 = _t70*_t75;
  const double _t169 = _t168*_t73;
  const double _t170 = _hc1[3]*_t5*_t9;
  const double _t171 = _t170 + 0.4e1*_t26;
  const double _t172 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t173 = _t12*_t172;
  const double _t174 = _t173*_t73;
  const double _t175 = _t171*_t174;
  const double _t176 = _t17*_t30;
  const double _t178 = _t177*_t8;
  const double _t179 = _t178*_t78;
  const double _t182 = _t24*_t38;
  const double _t183 = _t21*_t31;
  const double _t184 = _t182*_t183;
  const double _t185 = _t150*_t30;
  const double _t186 = _t30*_t79;
  const double _t187 = _t183*_t186;
  const double _t189 = _t16*_t68;
  const double _t190 = (0.8e1 / 0.9e1)*_t189;
  const double _t191 = _t16*_t75;
  const double _t192 = _t191*_t82;
  const double _t193 = _t162*_t86;
  const double _t194 = 0.3200533333333333*_t63;
  const double _t195 = _t193*_t194;
  const double _t196 = _t163*_t30;
  const double _t197 = _t170 + 0.4e1*_t37;
  const double _t198 = _t140*_t88;
  const double _t199 = _t13*_t87;
  const double _t201 = _t181*_t27;
  const double _t202 = _t11*_t201;
  const double _t203 = 0.071122962962962957*_t202;
  const double _t204 = (0.28e2 / 0.27e2)*_t159;
  const double _t205 = _t38*_t79;
  const double _t206 = _t38*_t64;
  const double _t209 = _t193*_t38;
  const double _t210 = _t76*_t79;
  const double _t211 = 0.2e1*_t86;
  const double _t212 = -_t82 - 0.56e2 / 0.9e1*_t92;
  const double _t213 = _t173*_t197;
  const double _t214 = _t213*_t86;
  const double _t217 = _t31*_t79;
  const double _t218 = 0.48007999999999995*_t89;
  const double _t219 = _t64*_t93;
  const double _t221 = 0.3e1*_t93;
  const double _t222 = _t36/xc_powr(nb, 13, 3);
  const double _t223 = _t160 + (0.280e3 / 0.27e2)*_t222;
  const double _t224 = 0.3e1*_t94;
  const double _t225 = _t212*_t75;
  const double _t226 = _t17*_t225;
  const double _t227 = _t93*_t94;
  const double _t228 = _t17*_t214;
  const double _t230 = _t41*_t8;
  const double _t231 = _t230*_t62;
  const double _t232 = _t229*_t231;
  const double _t233 = _t19*_t96;
  const double _t234 = 0.080013333333333325*_t233;
  const double _t235 = -0.18669777777777777*_t14*_t15*_t41*_t56*_t8;
  const double _t236 = _t104*_t45;
  const double _t237 = _t14*_t236;
  const double _t238 = _t20*_t31;
  const double _t239 = 0.13335555555555553*_t238;
  const double _t240 = _t102*_t31;
  const double _t242 = _t240*_t241;
  const double _t244 = _t19*_t30;
  const double _t245 = _t106*_t244;
  const double _t246 = 0.16002666666666665*_t245;
  const double _t247 = _t168*_t45;
  const double _t248 = _t173*_t30;
  const double _t249 = _t165*_t248;
  const double _t250 = _t42*_t56;
  const double _t251 = 0.37339555555555554*_t250;
  const double _t253 = _t41*_t65;
  const double _t254 = _t107*_t41;
  const double _t255 = 0.2e1*_t113;
  const double _t256 = _t23*_t53;
  const double _t257 = _t256*_t50;
  const double _t258 = -_t234 - _t246;
  const double _t259 = 0.18669777777777777*_t250;
  const double _t260 = _t113*_t31;
  const double _t261 = _t241*_t260;
  const double _t262 = _t259 - _t261;
  const double _t264 = _t14*_t75;
  const double _t265 = _t236*_t264;
  const double _t267 = (0.4e1 / 0.3e1)*_t265;
  const double _t268 = 0.040006666666666663*_t238;
  const double _t269 = _t266*_t45;
  const double _t270 = 0.066677777777777766*_t238;
  const double _t271 = _t248*_t86;
  const double _t272 = 0.3e1*_t271;
  const double _t273 = _t21*_t74;
  const double _t274 = _t102*_t273;
  const double _t275 = _t75*_t82;
  const double _t276 = -_t242 + _t259;
  const double _t277 = _t178*_t41;
  const double _t278 = _t118*_t19;
  const double _t279 = _t19*_t38;
  const double _t280 = _t106*_t279;
  const double _t282 = _t27*_t281;
  const double _t283 = _t106*_t282;
  const double _t284 = _t134*_t182 + _t134*_t186 + _t193*_t254 + _t229*_t277 - 0.040006666666666663*_t233 - 0.080013333333333325*_t245 - 0.040006666666666663*_t278 - 0.080013333333333325*_t280 - 0.013335555555555555*_t283;
  const double _t285 = _t193*_t30;
  const double _t286 = 0.080013333333333325*_t278;
  const double _t287 = 0.16002666666666665*_t280;
  const double _t288 = -_t286 - _t287;
  const double _t289 = _t38*_t75;
  const double _t290 = _t15*_t75;
  const double _t291 = _hc1[1]*_t119;
  const double _t292 = _t291*_t50;
  const double _t293 = _t290*_t292;
  const double _t294 = (0.5e1 / 0.3e1)*_t293;
  const double _t295 = _t15*_t291;
  const double _t296 = _t295*_t50;
  const double _t297 = _t113*_t273;
  const double _t298 = _t230*_t88;
  const double _t299 = _t229*_t298;
  const double _t300 = _t46*_t87;
  const double _t301 = _t75*_t93;
  const double _t302 = _t109*_t45;
  const double _t304 = _t173*_t38;
  const double _t305 = 0.3e1*_t304*_t86;
  const double _t306 = _t102*_t74;
  const double _t307 = _t205*_t31;
  const double _t309 = _t120*_t308;
  const double _t310 = -0.080013333333333325*_hc1[2]*_t14*_t19*_t31*_t41*_t44*_t47;
  const double _t311 = _hc1[2]*_t129;
  const double _t312 = _t311*_t32;
  const double _t313 = _t14*_t312;
  const double _t315 = _t130*_t131;
  const double _t316 = _t264*_t315;
  const double _t317 = _t311*_t48;
  const double _t318 = _t268*_t317;
  const double _t319 = _t74*_t78;
  const double _t320 = _t132*_t315;
  const double _t321 = _t14*_t320;
  const double _t322 = _t319*_t321;
  const double _t323 = _t252*_t30;
  const double _t324 = _t306*_t323;
  const double _t325 = _t123*_t55;
  const double _t326 = _t229*_t325;
  const double _t327 = -0.040006666666666663*_t123*_t14*_t15*_t19*_t8;
  const double _t328 = _t123*_t152;
  const double _t329 = _t328*_t97;
  const double _t330 = _t326 + _t327 + _t329;
  const double _t331 = _t325*_t97;
  const double _t332 = _t124*_t19;
  const double _t333 = 0.080013333333333325*_t332;
  const double _t334 = _t126*_t9;
  const double _t336 = _t126*_t335;
  const double _t337 = _t102*_t336;
  const double _t338 = _t107*_t123;
  const double _t339 = _t338*_t64;
  const double _t340 = _t126*_t229;
  const double _t341 = _t50*_t53;
  const double _t342 = _t45*_t75;
  const double _t343 = _t113*_t74;
  const double _t344 = _t45*_t47;
  const double _t345 = _t341*_t344;
  const double _t346 = -0.040006666666666663*_hc1[1]*_t15*_t19*_t31*_t41*_t50*_t52 - 0.040006666666666663*_hc1[2]*_t14*_t19*_t31*_t41*_t44*_t47 + _t319*_t345;
  const double _t347 = -0.16002666666666665*_t123*_t14*_t15*_t19*_t8;
  const double _t348 = -0.080013333333333325*_t123*_t14*_t15*_t19*_t8;
  const double _t349 = _t134*_t257;
  const double _t350 = -0.080013333333333325*_hc1[1]*_t15*_t19*_t31*_t41*_t50*_t52;
  const double _t351 = _t323*_t343;
  const double _t352 = 0.040006666666666663*_t332;
  const double _t353 = _t136*_t54;
  const double _t354 = _t268*_t353;
  const double _t355 = _t113*_t336;
  const double _t356 = _t137*_t138;
  const double _t357 = _t139*_t356;
  const double _t358 = _t15*_t357;
  const double _t359 = _t319*_t358;
  const double _t360 = _t136*_t32;
  const double _t361 = _t360*_t53;
  const double _t362 = _t357*_t75;
  const double _t363 = _t123*_t80;
  const double _t364 = _t229*_t363;
  const double _t365 = _t134*_t269;
  const double _t366 = _t34*_t75;
  const double _t367 = _t123*_t206;
  const double _t368 = _t367*_t97;
  const double _t369 = _t306*_t38;
  const double _t370 = _t252*_t369;
  const double _t372 = _t363*_t97;
  const double _t373 = _t367*_t40;
  const double _t374 = _t343*_t38;
  const double _t375 = _t327 + _t364 + _t368;
  const double _t376 = _t252*_t374;
  const double _t377 = _t291*_t360;
  const double _t379 = _t356*_t378;
  const double _t382 = _t18*_t381;
  const double _t383 = _t380*_t382;
  const double _t384 = _t126*_t380;
  const double _t388 = _t321*_t74;
  const double _t389 = (0.3e1 / 0.4e1)*_t32;
  const double _t391 = _hc1[2]*_t390;
  const double _t392 = _t391*_t48;
  const double _t393 = (0.3e1 / 0.2e1)*_t173;
  const double _t396 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]));
  const double _t397 = _t129*_t396;
  const double _t398 = _t395*_t397;
  const double _t400 = _t130*_t264*_t399;
  const double _t401 = _t382*_t9;
  const double _t402 = 0.090014999999999998*_t401;
  const double _t404 = _t240*_t403;
  const double _t407 = _t320*_t341;
  const double _t409 = _t303*_t74;
  const double _t410 = _t345*_t409;
  const double _t411 = _t240*_t408 + _t410;
  const double _t412 = 0.18003*_t401;
  const double _t413 = _t260*_t408;
  const double _t414 = _t358*_t74;
  const double _t415 = _t136*_t53;
  const double _t416 = _t342*_t415;
  const double _t417 = _t344*_t357;
  const double _t418 = _t260*_t403;
  const double _t420 = _t419*_t54;
  const double _t423 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t424 = _t136*_t423;
  const double _t425 = _t422*_t424;
  const double _t427 = _t137*_t139*_t426;
  const double d3F_dna3 = 0.12001999999999999*_t140*_t62 + 0.56009333333333333*_t141 + _t146 + _t147*_t149 - _t150*_t151 - _t151*_t163 + _t152*_t153 - _t154*_t155 - _t156*_t33 + _t157*_t85 + _t161*_t71 + _t164*_t165 + _t166*_t77 + _t167*_t169 + _t175*_t176;
  const double d3F_dna2_dnb = 0.071122962962962957*_hc1[3]*_t11*_t14*_t15*_t181*_t2*_t3*_t31 + (0.28e2 / 0.27e2)*_hc1[3]*_t12*_t14*_t15*_t2*_t3*_t31*_t56 + 0.74679111111111107*_t11*_t14*_t15*_t30*_t31*_t56 + 0.37339555555555554*_t11*_t14*_t15*_t31*_t38*_t56 + 0.040006666666666663*_t11*_t14*_t19*_t61*_t8 + 0.37339555555555554*_t11*_t14*_t23*_t56*_t8 + 0.18669777777777777*_t11*_t15*_t34*_t56*_t8 + 0.2e1*_t12*_t14*_t15*_t172*_t197*_t30*_t73 + 0.2e1*_t12*_t14*_t15*_t70*_t74*_t86 + 0.2e1*_t12*_t14*_t23*_t30*_t74*_t86 + _t12*_t15*_t30*_t34*_t73*_t74 + _t12*_t15*_t31*_t34*_t70 + _t12*_t23*_t30*_t31*_t34 - _t145 - _t179 - _t180*_t35 - _t184 - _t185*_t21 - _t187 - _t188*_t39 - _t190*_t76 - _t192*_t73 - _t195 - _t196*_t21 - _t70*_t84 - _t82*_t85;
  const double d3F_dna_dnb2 = 0.18669777777777777*_t141 + _t146 + _t152*_t58 + _t176*_t214 + _t177*_t39 - _t179 + _t182*_t94 - _t183*_t205 - _t184 - _t187 - _t190*_t94 - _t195 + 0.040006666666666663*_t198 - _t199*_t200 + _t203*_t64 + _t204*_t83 + _t206*_t207 - _t208*_t33 - _t209*_t21 + _t210*_t211 + _t212*_t77 + _t58*_t80 - _t82*_t90 - _t84*_t93 + _t85*_t93;
  const double d3F_dnb3 = _t146 + _t147*_t216 + _t153*_t206 - _t155*_t219 + _t167*_t227 - _t193*_t218 + 0.12001999999999999*_t198 + _t205*_t224 - _t217*_t218 - _t220*_t39 + _t221*_t90 + _t223*_t71 + _t226*_t38 + _t228*_t38 + 0.56009333333333333*_t57*_t80;
  const double d3F_dna2_dgaa = (0.2e1 / 0.3e1)*_hc1[2]*_t104*_t12*_t14*_t30*_t44*_t74 + (0.4e1 / 0.3e1)*_hc1[2]*_t104*_t12*_t14*_t44*_t73*_t74 + 0.3200533333333333*_hc1[2]*_t11*_t14*_t19*_t30*_t44*_t47*_t74 - _t102*_t249 - 0.55e2 / 0.36e2*_t103*_t243 - _t109*_t247 + 0.060010000000000001*_t14*_t15*_t30*_t41*_t73*_t74*_t9 + 0.060010000000000001*_t14*_t15*_t31*_t41*_t70*_t9 + 0.060010000000000001*_t14*_t23*_t30*_t31*_t41*_t9 - _t232 - _t234 - _t235 - _t237*_t239 - _t242 - _t246;
  const double d3F_dna2_dgab = _t111*_t70 + _t185*_t252 + _t196*_t252 - _t231*_t97 - 0.16002666666666665*_t233 - _t244*_t253 + _t251;
  const double d3F_dna2_dgbb = _t101*_t257 + _t112*_t180 + _t113*_t194*_t74 - _t113*_t249 - _t114*_t257 + _t122*_t70 + _t150*_t254 + _t163*_t254 - _t168*_t255 - _t232 + _t258 + _t262;
  const double d3F_dna_dnb_dgaa = -_t102*_t272 + _t102*_t275 - _t108*_t266 + _t115*_t263 - _t237*_t270 - _t265*_t38 + _t267*_t86 + _t268*_t269 + _t274*_t30 + _t274*_t38 + _t276 + _t284;
  const double d3F_dna_dnb_dgab = _t127*_t182 + _t217*_t254 + _t251 + _t252*_t285 + _t258 + _t277*_t97 - 0.026671111111111111*_t283 + _t288;
  const double d3F_dna_dnb_dgbb = -_t113*_t272 + _t113*_t275 + (0.5e1 / 0.12e2)*_t121*_t23 + _t257*_t268 - _t257*_t289 + _t262 - _t270*_t296 + _t284 + _t294*_t30 + _t297*_t30 + _t297*_t38;
  const double d3F_dnb2_dgaa = _t101*_t269 - _t102*_t305 - _t117*_t269 + _t122*_t93 + _t127*_t205 + _t209*_t303 + _t276 + _t288 - _t299 + (0.1e1 / 0.4e1)*_t300*_t47 - _t301*_t302 + 0.3200533333333333*_t306*_t89;
  const double d3F_dnb2_dgab = _t111*_t93 + _t209*_t252 + _t251 + _t252*_t307 - _t253*_t279 - 0.16002666666666665*_t278 - _t298*_t97;
  const double d3F_dnb2_dgbb = 0.3200533333333333*_hc1[1]*_t11*_t15*_t19*_t38*_t50*_t52*_t74 + (0.2e1 / 0.3e1)*_hc1[1]*_t119*_t12*_t15*_t38*_t50*_t74 + (0.4e1 / 0.3e1)*_hc1[1]*_t119*_t12*_t15*_t50*_t74*_t86 - _t113*_t305 + 0.060010000000000001*_t14*_t15*_t31*_t41*_t9*_t93 + 0.060010000000000001*_t14*_t15*_t38*_t41*_t74*_t86*_t9 - 0.55e2 / 0.36e2*_t15*_t309 + 0.060010000000000001*_t15*_t31*_t34*_t38*_t41*_t9 - _t235 - _t239*_t296 - _t255*_t301 - _t261 - _t286 - _t287 - _t299;
  const double d3F_dna_dgaa2 = 0.050008333333333321*_hc1[2]*_t104*_t14*_t31*_t41*_t44*_t9 + _hc1[2]*_t12*_t129*_t14*_t30*_t47*_t74 + 0.3e1*_t12*_t130*_t131*_t132*_t14*_t172*_t30 - _t263*_t313 - _t310 - 0.13e2 / 0.6e1*_t314*_t316 - _t318 - _t322 - _t324 - _t330;
  const double d3F_dna_dgaa_dgab = 0.050008333333333321*_t237*_t334 - _t324 - _t331 + _t333 + _t337 - _t339;
  const double d3F_dna_dgaa_dgbb = 0.3e1*_hc1[1]*_hc1[2]*_t12*_t172*_t30*_t44*_t47*_t50*_t52 + 0.025004166666666661*_hc1[2]*_t104*_t14*_t31*_t41*_t44*_t9 - _t105*_t341*_t342 - _t254*_t306 - _t254*_t343 - _t257*_t340 - _t330 - _t346;
  const double d3F_dna_dgab2 = -_t325*_t40 - _t328*_t49 - _t347;
  const double d3F_dna_dgab_dgbb = -_t331 - _t339 - _t348 - _t349 - _t350 - _t351;
  const double d3F_dna_dgbb2 = 0.3e1*_t15*_t248*_t357 + _t200*_t361 - _t326 - _t329 - _t349 - _t351 + _t352 + _t353*_t76 - _t354 + _t355 - _t359 + _t362*_t81;
  const double d3F_dnb_dgaa2 = (0.1e1 / 0.4e1)*_t266*_t312 + _t289*_t317 + _t304*_t320*_t371 - _t318 + (0.1e1 / 0.2e1)*_t320*_t366 - _t322 + _t337 + _t352 - _t364 - _t365 - _t368 - _t370;
  const double d3F_dnb_dgaa_dgab = -_t310 - _t348 - _t365 - _t370 - _t372 - _t373;
  const double d3F_dnb_dgaa_dgbb = 0.3e1*_hc1[1]*_hc1[2]*_t12*_t172*_t38*_t44*_t47*_t50*_t52 + 0.025004166666666661*_hc1[1]*_t119*_t15*_t31*_t41*_t50*_t9 - _t269*_t340 - 0.5e1 / 0.6e1*_t292*_t342*_t47 - _t303*_t369 - _t303*_t374 - _t346 - _t375;
  const double d3F_dnb_dgab2 = -_t347 - _t363*_t40 - _t367*_t49;
  const double d3F_dnb_dgab_dgbb = 0.050008333333333321*_t296*_t334 + _t333 + _t355 - _t372 - _t373 - _t376;
  const double d3F_dnb_dgbb2 = 0.050008333333333321*_hc1[1]*_t119*_t15*_t31*_t41*_t50*_t9 + _hc1[1]*_t12*_t136*_t15*_t38*_t52*_t74 + 0.3e1*_t12*_t137*_t138*_t139*_t15*_t172*_t38 - 0.5e1 / 0.12e2*_t15*_t377 - 0.13e2 / 0.6e1*_t290*_t379 - _t350 - _t354 - _t359 - _t375 - _t376;
  const double d3F_dgaa3 = -0.3e1 / 0.2e1*_t132*_t400 + _t240*_t385 + _t317*_t384 + _t383 + _t387*_t388 - _t389*_t392 - _t393*_t398;
  const double d3F_dgaa2_dgab = _t134*_t317 + _t303*_t388 + _t402 + _t404;
  const double d3F_dgaa2_dgbb = -_t116*_t311*_t341*_t75 + _t260*_t405 + _t317*_t340 + _t383 + _t388*_t406 - _t393*_t407 + _t411;
  const double d3F_dgaa_dgab2 = _t404 + _t412;
  const double d3F_dgaa_dgab_dgbb = _t402 + _t411 + _t413;
  const double d3F_dgaa_dgbb2 = -_t116*_t416 + _t240*_t405 + _t340*_t353 + _t383 - _t393*_t417 + _t406*_t414 + _t410 + _t413;
  const double d3F_dgab3 = 0.36005999999999999*_t401;
  const double d3F_dgab2_dgbb = _t412 + _t418;
  const double d3F_dgab_dgbb2 = _t134*_t353 + _t303*_t414 + _t402 + _t418;
  const double d3F_dgbb3 = _t260*_t385 - 0.3e1 / 0.2e1*_t290*_t427 + _t353*_t384 + _t383 + _t387*_t414 - _t389*_t420 - _t393*_t425;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 1] += d3F_dna2_dgab;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 2] += d3F_dna2_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 3] += d3F_dna_dnb_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 4] += d3F_dna_dnb_dgab;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 5] += d3F_dna_dnb_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 6] += d3F_dnb2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 7] += d3F_dnb2_dgab;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 1] += d3F_dna_dgaa_dgab;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 2] += d3F_dna_dgaa_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 3] += d3F_dna_dgab2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 4] += d3F_dna_dgab_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 5] += d3F_dna_dgbb2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 6] += d3F_dnb_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 7] += d3F_dnb_dgaa_dgab;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 8] += d3F_dnb_dgaa_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 9] += d3F_dnb_dgab2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 10] += d3F_dnb_dgab_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 1] += d3F_dgaa2_dgab;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 2] += d3F_dgaa2_dgbb;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 3] += d3F_dgaa_dgab2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 4] += d3F_dgaa_dgab_dgbb;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 5] += d3F_dgaa_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 6] += d3F_dgab3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 7] += d3F_dgab2_dgbb;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 8] += d3F_dgab_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
#endif
#if _KMAX >= 4
  const double _t431 = _t11*_t143;
  const double _t436 = 2.2403733333333333*_t57;
  const double _t450 = 0.6e1*_t16;
  const double _t465 = (0.3e1 / 0.8e1)*_t148;
  const double _t466 = _t34*_t61;
  const double _t469 = (0.3e1 / 0.2e1)*_t177;
  const double _t473 = 0.2e1*_t79;
  const double _t478 = _t11*_t144;
  const double _t481 = 0.24003999999999998*_t177;
  const double _t505 = 0.28004666666666667*_t57;
  const double _t507 = 0.56009333333333333*_t57;
  const double _t512 = (0.1e1 / 0.8e1)*_t61;
  const double _t514 = _t23*_t87;
  const double _t536 = (0.3e1 / 0.8e1)*_t215;
  const double _t541 = 0.24003999999999998*_t20;
  const double _t557 = 0.022503749999999999*_t9;
  const double _t566 = 0.62232592592592595*_t431;
  const double _t570 = 0.24003999999999998*_t19;
  const double _t601 = 0.48007999999999995*_t19;
  const double _t602 = 0.18003*_t9;
  const double _t603 = _t41*_t602;
  const double _t605 = 0.24004*_t9;
  const double _t613 = 0.0075012500000000001*_t9;
  const double _t615 = (0.55e2 / 0.72e2)*_t243;
  const double _t648 = 0.16002666666666665*_t19;
  const double _t667 = (0.5e1 / 0.24e2)*_t104;
  const double _t668 = _t47*_t87;
  const double _t717 = _t123*_t613;
  const double _t728 = _t104*_t14;
  const double _t765 = _t123*_t49;
  const double _t797 = 0.040006666666666663*_t19;
  const double _t866 = _t41*_t9;
  const double _t867 = 0.27004499999999998*_t866;
  const double _t869 = _t123*_t386;
  const double _t878 = 0.12001999999999999*_t20;
  const double _t884 = 0.12001999999999999*_t19;
  const double _t922 = 0.36005999999999999*_t9;
  const double _t934 = _t123*_t557;
  const double _t964 = _t380*_t41;
  const double _t967 = 0.13502249999999999*_t866;
  const double _t428 = _t140*_t149;
  const double _t429 = _t57*_t8;
  const double _t430 = _t429*_t62;
  const double _t432 = _t431*_t55;
  const double _t433 = 5.3934913580246908*_t142/xc_powr(_t1, 16, 3);
  const double _t434 = (0.15e2 / 0.8e1)*_t13;
  const double _t435 = _t31*_t62;
  const double _t437 = _t20*_t70;
  const double _t438 = _t150*_t437;
  const double _t439 = _t152*_t431;
  const double _t440 = 0.6401066666666666*_t20*_t64;
  const double _t441 = _t32*_t62;
  const double _t442 = _t143*_t27;
  const double _t443 = (0.140e3 / 0.81e2)*_t442;
  const double _t444 = _t24*_t74;
  const double _t445 = _t63*_t73;
  const double _t446 = _t444*_t445;
  const double _t447 = _t162*_t166;
  const double _t448 = 0.6401066666666666*_t63;
  const double _t449 = _t163*_t437;
  const double _t451 = _t450*_t73;
  const double _t452 = _t161*_t75;
  const double _t453 = _t171*_t73;
  const double _t454 = _t16*_t172;
  const double _t455 = _t453*_t454;
  const double _t456 = _t24*_t30;
  const double _t457 = (0.2e1 / 0.3e1)*_t68;
  const double _t458 = _t174*_t176;
  const double _t459 = _t166*_t248;
  const double _t460 = (0.2e1 / 0.3e1)*_t28;
  const double _t461 = xc_powi((_hc0[0]), -5);
  const double _t462 = _t12*_t461;
  const double _t463 = _t176*_t462;
  const double _t464 = _t453*_t463;
  const double _t467 = (0.3e1 / 0.4e1)*_t33;
  const double _t468 = _t32*_t70;
  const double _t470 = (0.3e1 / 0.4e1)*_t39;
  const double _t471 = _t140*_t466;
  const double _t472 = _t431*_t80;
  const double _t474 = _t24*_t94;
  const double _t475 = _t76*_t86;
  const double _t476 = _t73*_t76;
  const double _t477 = 0.12001999999999999*_t435;
  const double _t479 = 0.24003999999999998*_t217;
  const double _t480 = _t31*_t63;
  const double _t482 = _t174*_t197;
  const double _t483 = _t30*_t447;
  const double _t484 = _t74*_t79;
  const double _t485 = 0.24003999999999998*_t445;
  const double _t486 = _t444*_t86;
  const double _t487 = (0.16e2 / 0.3e1)*_t37 + _t460;
  const double _t488 = (0.1e1 / 0.3e1)*_t68;
  const double _t489 = (0.14e2 / 0.9e1)*_t159;
  const double _t490 = 0.10668444444444443*_t202;
  const double _t491 = _t197*_t73;
  const double _t492 = _t454*_t491;
  const double _t493 = (0.16e2 / 0.9e1)*_t189;
  const double _t494 = (0.4e1 / 0.3e1)*_t68;
  const double _t495 = _t73*_t75;
  const double _t496 = (0.56e2 / 0.27e2)*_t159;
  const double _t497 = _t16*_t496;
  const double _t498 = _t497*_t76;
  const double _t499 = _t191*_t73;
  const double _t500 = 0.21336888888888886*_t202;
  const double _t501 = _t162*_t30;
  const double _t502 = _t171*_t248;
  const double _t503 = _t174*_t30;
  const double _t504 = (0.4e1 / 0.3e1)*_t189;
  const double _t506 = _t186*_t31;
  const double _t508 = _t182*_t31;
  const double _t509 = _t11*_t27*_t64/xc_powr(_t1, 17, 3);
  const double _t510 = _t433 - 0.280e3 / 0.81e2*_t442*_t83;
  const double _t511 = _t153*_t285 + _t178*_t505 + _t506*_t507 + _t507*_t508 - 0.49786074074074071*_t509 + _t510;
  const double _t513 = _t32*_t93;
  const double _t515 = _t140*_t514;
  const double _t516 = _t429*_t88;
  const double _t517 = _t38*_t94;
  const double _t518 = _t31*_t88;
  const double _t519 = _t30*_t78;
  const double _t520 = _t38*_t78;
  const double _t521 = _t150*_t93;
  const double _t522 = _t177*_t183;
  const double _t523 = _t206*_t431;
  const double _t524 = -_t457 - 0.28e2 / 0.3e1*_t92;
  const double _t525 = _t186*_t73;
  const double _t526 = _t182*_t86;
  const double _t527 = _t162*_t212;
  const double _t528 = 0.3200533333333333*_t193;
  const double _t529 = _t484*_t86;
  const double _t530 = _t463*_t487;
  const double _t531 = _t197*_t86;
  const double _t532 = _t454*_t531;
  const double _t533 = (0.8e1 / 0.9e1)*_t68;
  const double _t534 = 0.14224592592592591*_t202;
  const double _t535 = _t213*_t30;
  const double _t537 = _t140*_t216;
  const double _t538 = _t204 + (0.560e3 / 0.27e2)*_t222;
  const double _t539 = 0.3e1*_t212;
  const double _t540 = _t20*_t93;
  const double _t542 = _t524*_t86;
  const double _t543 = _t167*_t212;
  const double _t544 = _t38*_t527;
  const double _t545 = _t529*_t89;
  const double _t546 = _t32*_t88;
  const double _t547 = _t38*_t532;
  const double _t548 = (0.4e1 / 0.3e1)*_t214;
  const double _t549 = 0.6401066666666666*_t89;
  const double _t550 = _t38*_t88;
  const double _t551 = 0.4e1*_t205;
  const double _t552 = _t450*_t93;
  const double _t553 = _t213*_t38;
  const double _t554 = _t462*_t531;
  const double _t555 = _t38*_t554;
  const double _t556 = _t149*_t230;
  const double _t558 = _t19*_t231;
  const double _t559 = _t56*_t96;
  const double _t560 = 0.62232592592592595*_t143*_t42;
  const double _t561 = -_t560;
  const double _t562 = 0.36672777777777776*_t238;
  const double _t563 = _t243*_t45;
  const double _t564 = _t14*_t563;
  const double _t565 = _t31*_t57;
  const double _t567 = _t126*_t62;
  const double _t568 = _t30*_t567;
  const double _t569 = _t380*_t568;
  const double _t571 = _t185*_t41;
  const double _t572 = _t570*_t571;
  const double _t573 = _t41*_t70;
  const double _t574 = _t150*_t573;
  const double _t575 = _t106*_t56;
  const double _t576 = _t30*_t575;
  const double _t577 = _t106*_t70;
  const double _t578 = _t570*_t577;
  const double _t579 = _t237*_t30;
  const double _t580 = _t20*_t74;
  const double _t581 = _t237*_t580;
  const double _t582 = _t581*_t73;
  const double _t583 = _t153*_t30;
  const double _t584 = _t264*_t563;
  const double _t585 = _t264*_t73;
  const double _t586 = _t456*_t74;
  const double _t587 = _t387*_t73;
  const double _t588 = _t244*_t41;
  const double _t589 = _t163*_t588;
  const double _t590 = 0.24003999999999998*_t589;
  const double _t591 = _t252*_t70;
  const double _t592 = 0.3e1*_t459;
  const double _t593 = 0.6e1*_t102;
  const double _t594 = _t174*_t70;
  const double _t595 = _t254*_t454*_t73;
  const double _t596 = 0.4e1*_t30;
  const double _t597 = _t462*_t596;
  const double _t598 = _t453*_t597;
  const double _t599 = _t144*_t42;
  const double _t600 = -_t599;
  const double _t604 = _t603*_t73;
  const double _t606 = _t257*_t75;
  const double _t607 = _t257*_t31;
  const double _t608 = _t341*_t61;
  const double _t609 = _t238*_t608;
  const double _t610 = 0.6e1*_t113;
  const double _t611 = -0.62232592592592595*_hc1[1]*_t11*_t143*_t15*_t31*_t50*_t52 + _t560;
  const double _t612 = _t230*_t466;
  const double _t614 = _t612*_t613;
  const double _t616 = _t335*_t577;
  const double _t617 = _t335*_t571;
  const double _t618 = _t229*_t38*_t567;
  const double _t619 = 0.080013333333333325*_t589;
  const double _t620 = 0.093348888888888884*_t565;
  const double _t621 = _t157*_t173;
  const double _t622 = _t621*_t86;
  const double _t623 = _t30*_t393;
  const double _t624 = _t623*_t73;
  const double _t625 = _t63*_t74;
  const double _t626 = _t282*_t41;
  const double _t627 = _t150*_t626;
  const double _t628 = 0.013335555555555555*_t627;
  const double _t629 = _t207*_t30;
  const double _t630 = _t491*_t597;
  const double _t631 = _t163*_t626;
  const double _t632 = 0.013335555555555555*_t631;
  const double _t633 = _t501*_t626;
  const double _t634 = 0.026671111111111111*_t633;
  const double _t635 = (0.20e2 / 0.27e2)*_t68;
  const double _t636 = -0.37339555555555554*_t14*_t15*_t30*_t31*_t41*_t56 - 0.18669777777777777*_t14*_t23*_t41*_t56*_t8;
  const double _t637 = _t19*_t277;
  const double _t638 = 0.040006666666666663*_t637;
  const double _t639 = _t186*_t336;
  const double _t640 = _t182*_t336;
  const double _t641 = 0.16002666666666665*_t193;
  const double _t642 = _t588*_t641;
  const double _t643 = -0.06667777777777778*_hc1[3]*_t14*_t15*_t181*_t2*_t3*_t31*_t41 + _t638 + _t639 + _t640 + _t642;
  const double _t644 = _t236*_t34;
  const double _t645 = _t204*_t75;
  const double _t646 = -0.62232592592592595*_hc1[2]*_t11*_t14*_t143*_t31*_t44*_t47 + _t560;
  const double _t647 = -0.16002666666666665*_hc1[2]*_t104*_t11*_t14*_t19*_t38*_t44*_t74 - 0.48007999999999995*_hc1[2]*_t11*_t14*_t172*_t19*_t30*_t44*_t47*_t86 - 0.16002666666666665*_hc1[2]*_t11*_t19*_t30*_t34*_t44*_t47*_t74 + _t102*_t645 + _t203*_t306 + _t270*_t644 + 0.21336888888888886*_t581*_t86 + _t646;
  const double _t649 = _t126*_t648;
  const double _t650 = -0.13335555555555556*_hc1[3]*_t14*_t15*_t181*_t2*_t3*_t31*_t41 + _t182*_t649 + _t186*_t649 + _t528*_t588 + _t599 + 0.080013333333333325*_t637;
  const double _t651 = -0.37339555555555554*_t14*_t15*_t31*_t38*_t41*_t56 - 0.18669777777777777*_t15*_t34*_t41*_t56*_t8;
  const double _t652 = _t118*_t56;
  const double _t653 = _t38*_t575;
  const double _t654 = _t23*_t292;
  const double _t655 = _t296*_t565;
  const double _t656 = _t406*_t74;
  const double _t657 = _t40*_t573;
  const double _t658 = _t270*_t654;
  const double _t659 = _t273*_t38;
  const double _t660 = _t273*_t30;
  const double _t661 = 0.26671111111111107*_t296*_t625;
  const double _t662 = _t113*_t172;
  const double _t663 = _t151*_t172;
  const double _t664 = _t113*_t645;
  const double _t665 = _t203*_t343;
  const double _t666 = _t260*_t566 + _t561;
  const double _t669 = _t45*_t668;
  const double _t670 = 0.020003333333333331*_t238;
  const double _t671 = _t269*_t31;
  const double _t672 = _t248*_t539;
  const double _t673 = _t38*_t393;
  const double _t674 = _t673*_t86;
  const double _t675 = _t30*_t58;
  const double _t676 = _t554*_t596;
  const double _t677 = _t230*_t514;
  const double _t678 = _t106*_t93;
  const double _t679 = _t30*_t88;
  const double _t680 = _t279*_t41;
  const double _t681 = _t193*_t680;
  const double _t682 = _t217*_t626;
  const double _t683 = _t193*_t626;
  const double _t684 = -0.060010000000000001*_t14*_t15*_t172*_t197*_t30*_t41*_t86*_t9 - 0.060010000000000001*_t14*_t15*_t212*_t30*_t41*_t74*_t9 - 0.18669777777777777*_t14*_t15*_t30*_t31*_t41*_t56 - 0.030005*_t14*_t23*_t31*_t41*_t9*_t93 - 0.030005*_t14*_t23*_t38*_t41*_t74*_t86*_t9 - 0.093348888888888884*_t14*_t23*_t41*_t56*_t8 - 0.020003333333333331*_t15*_t19*_t41*_t8*_t87 - 0.060010000000000001*_t15*_t30*_t34*_t41*_t74*_t86*_t9 + _t205*_t336 - 0.030005*_t23*_t31*_t34*_t38*_t41*_t9 + _t335*_t678 + _t340*_t679 + _t613*_t677 + _t643 + _t651 + 0.080013333333333325*_t681 + 0.013335555555555555*_t682 + 0.026671111111111111*_t683;
  const double _t685 = _t290*_t30;
  const double _t686 = _hc1[1]*_t308;
  const double _t687 = _t50*_t686;
  const double _t688 = _t296*_t86;
  const double _t689 = _t580*_t688;
  const double _t690 = _t570*_t678;
  const double _t691 = _t126*_t205;
  const double _t692 = _t570*_t691;
  const double _t693 = _t126*_t550;
  const double _t694 = _t380*_t693;
  const double _t695 = 0.060009999999999994*_t238;
  const double _t696 = 0.24003999999999998*_t681;
  const double _t697 = _t304*_t539;
  const double _t698 = _t173*_t86;
  const double _t699 = _t698*_t93;
  const double _t700 = (0.9e1 / 0.2e1)*_t173;
  const double _t701 = _t38*_t700;
  const double _t702 = 0.4e1*_t555;
  const double _t703 = _t216*_t230;
  const double _t704 = _t19*_t298;
  const double _t705 = _t217*_t93;
  const double _t706 = _t205*_t86;
  const double _t707 = _t603*_t74;
  const double _t708 = _t193*_t93;
  const double _t709 = _t290*_t687;
  const double _t710 = _t15*_t686;
  const double _t711 = _t50*_t710;
  const double _t712 = _t387*_t74;
  const double _t713 = _t126*_t56;
  const double _t714 = _t102*_t713;
  const double _t715 = 0.18669777777777777*_t714;
  const double _t716 = -_t715;
  const double _t718 = _t124*_t56;
  const double _t719 = 0.093348888888888884*_t718;
  const double _t720 = -_t719;
  const double _t721 = _t154*_t408;
  const double _t722 = _t185*_t408;
  const double _t723 = _t314*_t315;
  const double _t724 = _t14*_t723;
  const double _t725 = 0.4e1*_t724;
  const double _t726 = _t104*_t311;
  const double _t727 = (0.2e1 / 0.3e1)*_t726;
  const double _t729 = _t311*_t728;
  const double _t730 = _t334*_t564;
  const double _t731 = 0.091681944444444469*_t730;
  const double _t732 = _t126*_t19;
  const double _t733 = _t237*_t732;
  const double _t734 = 0.13335555555555553*_t733;
  const double _t735 = _t196*_t408;
  const double _t736 = 0.6e1*_t462;
  const double _t737 = _t30*_t736;
  const double _t738 = _t237*_t9;
  const double _t739 = _t41*_t74;
  const double _t740 = _t738*_t739;
  const double _t741 = _t306*_t588;
  const double _t742 = _t306*_t591;
  const double _t743 = _t172*_t30;
  const double _t744 = _t102*_t743;
  const double _t745 = _t604*_t744;
  const double _t746 = _t19*_t325;
  const double _t747 = _t328*_t335 + 0.040006666666666663*_t746;
  const double _t748 = _t123*_t154;
  const double _t749 = -0.16002666666666665*_t123*_t14*_t15*_t19*_t30*_t31 - 0.080013333333333325*_t123*_t14*_t19*_t23*_t8;
  const double _t750 = -0.0150025*_t123*_t14*_t61*_t8*_t9 + _t150*_t338 + _t163*_t338 + _t40*_t748 + _t749;
  const double _t751 = 0.18669777777777777*_t718;
  const double _t752 = _t715 + _t751;
  const double _t753 = _t257*_t74;
  const double _t754 = _t236*_t341;
  const double _t755 = _t113*_t743;
  const double _t756 = -0.080013333333333325*_t123*_t14*_t15*_t19*_t30*_t31 - 0.040006666666666663*_t123*_t14*_t19*_t23*_t8 - 0.0075012500000000001*_t123*_t14*_t61*_t8*_t9 + _t721 + _t722 + _t735;
  const double _t757 = -0.16002666666666665*_hc1[1]*_t15*_t19*_t30*_t41*_t50*_t52*_t74 - 0.040006666666666663*_hc1[1]*_t19*_t23*_t31*_t41*_t50*_t52;
  const double _t758 = 0.066677777777777766*_t733;
  const double _t759 = -0.16002666666666665*_hc1[2]*_t14*_t19*_t30*_t41*_t44*_t47*_t74 + _t758;
  const double _t760 = _t113*_t713;
  const double _t761 = 0.093348888888888884*_t760;
  const double _t762 = 0.093348888888888884*_t714;
  const double _t763 = -0.18669777777777777*_hc1[1]*_hc1[2]*_t11*_t44*_t47*_t50*_t52*_t56*_t74 + _t719 + _t761 + _t762;
  const double _t764 = 0.37339555555555554*_t718;
  const double _t766 = 0.18669777777777777*_t760;
  const double _t767 = _t751 + _t766;
  const double _t768 = -0.3200533333333333*_hc1[1]*_t15*_t19*_t30*_t41*_t50*_t52*_t74 - 0.080013333333333325*_hc1[1]*_t19*_t23*_t31*_t41*_t50*_t52 - 0.0150025*_hc1[1]*_t31*_t41*_t50*_t52*_t61*_t9 + _t323*_t753 + _t343*_t591 + _t604*_t755;
  const double _t769 = _t136*_t256;
  const double _t770 = _t23*_t357;
  const double _t771 = -0.093348888888888884*_hc1[1]*_t11*_t136*_t15*_t31*_t52*_t56 - 0.18669777777777777*_t11*_t137*_t138*_t139*_t15*_t56*_t74 + _t719 + _t766;
  const double _t772 = _t266*_t311;
  const double _t773 = _t320*_t34;
  const double _t774 = 0.040006666666666663*_t580;
  const double _t775 = _t317*_t74;
  const double _t776 = 0.24003999999999998*_t172;
  const double _t777 = _t321*_t776;
  const double _t778 = _t237*_t38;
  const double _t779 = _t409*_t778;
  const double _t780 = _t269*_t74;
  const double _t781 = _t254*_t780;
  const double _t782 = _t744*_t86;
  const double _t783 = _t603*_t782;
  const double _t784 = _t173*_t457;
  const double _t785 = _t69*_t75;
  const double _t786 = -0.093348888888888884*_hc1[2]*_t11*_t129*_t14*_t31*_t47*_t56 - 0.18669777777777777*_t11*_t130*_t131*_t132*_t14*_t56*_t74 + _t715 + _t719;
  const double _t787 = -0.16002666666666665*_hc1[2]*_t14*_t19*_t38*_t41*_t44*_t47*_t74 - 0.040006666666666663*_hc1[2]*_t19*_t31*_t34*_t41*_t44*_t47;
  const double _t788 = _t178*_t717;
  const double _t789 = _t405*_t506;
  const double _t790 = _t405*_t508;
  const double _t791 = _t285*_t408;
  const double _t792 = -0.0066677777777777777*_hc1[3]*_t123*_t14*_t15*_t2*_t281*_t3*_t31 - 0.040006666666666663*_t123*_t14*_t15*_t19*_t30*_t31 - 0.040006666666666663*_t123*_t14*_t15*_t19*_t31*_t38 - 0.020003333333333331*_t123*_t14*_t19*_t23*_t8 - 0.020003333333333331*_t123*_t15*_t19*_t34*_t8 + _t788 + _t789 + _t790 + _t791;
  const double _t793 = _t19*_t363;
  const double _t794 = 0.040006666666666663*_t793;
  const double _t795 = _t335*_t367;
  const double _t796 = _t334*_t644;
  const double _t798 = _t126*_t797;
  const double _t799 = _t740*_t86;
  const double _t800 = _t306*_t680;
  const double _t801 = _t282*_t739;
  const double _t802 = _t102*_t801;
  const double _t803 = _t123*_t178;
  const double _t804 = _t123*_t282*_t64;
  const double _t805 = -_t193*_t338 - _t229*_t803 - _t408*_t506 - _t408*_t508 + _t747 - _t751 + 0.013335555555555555*_t804;
  const double _t806 = _t334*_t654;
  const double _t807 = 0.020003333333333331*_t732;
  const double _t808 = _t296*_t732;
  const double _t809 = _t292*_t344;
  const double _t810 = _t345*_t74;
  const double _t811 = _t113*_t801;
  const double _t812 = _t292*_t75;
  const double _t813 = _t38*_t656;
  const double _t814 = _t739*_t9;
  const double _t815 = _t296*_t814;
  const double _t816 = _t30*_t815;
  const double _t817 = _t343*_t680;
  const double _t818 = _t343*_t588;
  const double _t819 = _t30*_t656;
  const double _t820 = _t345*_t776;
  const double _t821 = _t173*_t211;
  const double _t822 = _t755*_t86;
  const double _t823 = -0.16002666666666665*_t123*_t14*_t15*_t19*_t31*_t38 - 0.080013333333333325*_t123*_t15*_t19*_t34*_t8;
  const double _t824 = 0.066677777777777766*_t808;
  const double _t825 = _t303*_t38;
  const double _t826 = _t753*_t825;
  const double _t827 = _t603*_t822;
  const double _t828 = -_t766 + _t794 + _t795;
  const double _t829 = _t23*_t75;
  const double _t830 = _t136*_t291;
  const double _t831 = _t15*_t379;
  const double _t832 = _t353*_t74;
  const double _t833 = _t358*_t776;
  const double _t834 = -0.16002666666666665*_hc1[1]*_t15*_t19*_t38*_t41*_t50*_t52*_t74 + _t824;
  const double _t835 = _t172*_t218;
  const double _t836 = _t306*_t93;
  const double _t837 = _t172*_t38;
  const double _t838 = _t837*_t86;
  const double _t839 = _t102*_t838;
  const double _t840 = -0.3200533333333333*_hc1[2]*_t14*_t19*_t38*_t41*_t44*_t47*_t74 - 0.080013333333333325*_hc1[2]*_t19*_t31*_t34*_t41*_t44*_t47 - 0.0150025*_hc1[2]*_t31*_t41*_t44*_t47*_t87*_t9 + _t252*_t38*_t780 + _t252*_t836 + _t603*_t839;
  const double _t841 = _t219*_t408;
  const double _t842 = _t307*_t408;
  const double _t843 = _t209*_t408;
  const double _t844 = -0.080013333333333325*_t123*_t14*_t15*_t19*_t31*_t38 - 0.040006666666666663*_t123*_t15*_t19*_t34*_t8 - 0.0075012500000000001*_t123*_t15*_t8*_t87*_t9 + _t841 + _t842 + _t843;
  const double _t845 = -0.0150025*_t123*_t15*_t8*_t87*_t9 + _t209*_t403 + _t219*_t403 + _t307*_t403 + _t823;
  const double _t846 = _t334*_t711;
  const double _t847 = _t343*_t93;
  const double _t848 = _t113*_t838;
  const double _t849 = 0.091681944444444469*_t846;
  const double _t850 = 0.13335555555555553*_t808;
  const double _t851 = _t252*_t847;
  const double _t852 = _t603*_t848;
  const double _t853 = _t290*_t830;
  const double _t854 = _t136*_t295;
  const double _t855 = _t38*_t736;
  const double _t856 = _t32*_t391;
  const double _t857 = _t173*_t397;
  const double _t858 = _t130*_t132*_t399;
  const double _t859 = _t14*_t858;
  const double _t860 = _t30*_t700;
  const double _t861 = (0.3e1 / 0.2e1)*_t76;
  const double _t862 = _t334*_t729;
  const double _t863 = _t123*_t31;
  const double _t864 = _t738*_t863;
  const double _t865 = _t724*_t814;
  const double _t868 = _t30*_t712;
  const double _t870 = _t30*_t306;
  const double _t871 = _t381*_t55;
  const double _t872 = _t19*_t382;
  const double _t873 = 0.060009999999999994*_t872;
  const double _t874 = -_t873;
  const double _t875 = _t152*_t381;
  const double _t876 = _t380*_t875 + _t557*_t871 + _t874;
  const double _t877 = _t172*_t398;
  const double _t879 = 0.12001999999999999*_t580;
  const double _t880 = 0.060009999999999994*_t732;
  const double _t881 = _t123*_t240;
  const double _t882 = _t19*_t881;
  const double _t883 = _t388*_t41;
  const double _t885 = -_t317*_t880 + _t392*_t695 + _t859*_t879 + _t877*_t878 - 0.060009999999999994*_t882 - _t883*_t884;
  const double _t886 = _t317*_t798;
  const double _t887 = _t335*_t883;
  const double _t888 = _t335*_t881;
  const double _t889 = -0.12002*_hc1[2]*_t123*_t14*_t30*_t44*_t47*_t74*_t9 + 0.050008333333333321*_t864 + _t888;
  const double _t890 = 0.12001999999999999*_t872;
  const double _t891 = -0.090014999999999998*_t14*_t15*_t30*_t31*_t381*_t9 - 0.045007499999999999*_t14*_t23*_t381*_t8*_t9 + _t890;
  const double _t892 = _t797*_t881;
  const double _t893 = _t335*_t345*_t739;
  const double _t894 = _t123*_t260;
  const double _t895 = _t19*_t894;
  const double _t896 = 0.020003333333333331*_t895;
  const double _t897 = _t317*_t807;
  const double _t898 = _t797*_t883;
  const double _t899 = _t311*_t47;
  const double _t900 = _t341*_t899;
  const double _t901 = 0.050008333333333321*_t814;
  const double _t902 = _t754*_t901;
  const double _t903 = -0.18003*_hc1[1]*_hc1[2]*_t172*_t30*_t41*_t44*_t47*_t50*_t52*_t9 - 0.060010000000000001*_hc1[2]*_t123*_t14*_t30*_t44*_t47*_t74*_t9 + 0.025004166666666661*_t864 + _t902;
  const double _t904 = 0.24003999999999998*_t872;
  const double _t905 = _t797*_t894;
  const double _t906 = _t893 + _t905;
  const double _t907 = _t892 + _t906;
  const double _t908 = _t126*_t613;
  const double _t909 = _t739*_t770;
  const double _t910 = _t353*_t807;
  const double _t911 = 0.020003333333333331*_t882;
  const double _t912 = _t41*_t414;
  const double _t913 = _t797*_t912;
  const double _t914 = (0.5e1 / 0.4e1)*_t173;
  const double _t915 = _t358*_t743;
  const double _t916 = _t344*_t415;
  const double _t917 = _t172*_t878;
  const double _t918 = -_t893;
  const double _t919 = _t345*_t603;
  const double _t920 = _t871*_t9;
  const double _t921 = -0.48007999999999995*_t872;
  const double _t923 = -_t904;
  const double _t924 = _t335*_t894;
  const double _t925 = _t30*_t343;
  const double _t926 = _t408*_t607 + _t765*_t925 - _t924;
  const double _t927 = -_t890;
  const double _t928 = _t353*_t798;
  const double _t929 = _t335*_t912;
  const double _t930 = _t173*_t424;
  const double _t931 = _t32*_t419;
  const double _t932 = _t15*_t427;
  const double _t933 = _t126*_t557;
  const double _t935 = _t172*_t425;
  const double _t936 = -_t353*_t880 + _t420*_t695 + _t878*_t935 + _t879*_t932 - _t884*_t912 - 0.060009999999999994*_t895;
  const double _t937 = (0.3e1 / 0.2e1)*_t289;
  const double _t938 = _t739*_t773;
  const double _t939 = _t321*_t837;
  const double _t940 = _t38*_t712;
  const double _t941 = _t381*_t80;
  const double _t942 = _t206*_t381;
  const double _t943 = _t380*_t942 + _t557*_t941 + _t874;
  const double _t944 = _t369*_t765 + _t408*_t671 - _t888;
  const double _t945 = _t296*_t863*_t9;
  const double _t946 = _t809*_t901;
  const double _t947 = _t9*_t941;
  const double _t948 = -0.090014999999999998*_t14*_t15*_t31*_t38*_t381*_t9 - 0.045007499999999999*_t15*_t34*_t381*_t8*_t9 + _t890;
  const double _t949 = -0.18003*_hc1[1]*_hc1[2]*_t172*_t38*_t41*_t44*_t47*_t50*_t52*_t9 - 0.060010000000000001*_hc1[1]*_t123*_t15*_t38*_t50*_t52*_t74*_t9 + 0.025004166666666661*_t945 + _t946;
  const double _t950 = _t334*_t854;
  const double _t951 = _t814*_t831;
  const double _t952 = -0.12002*_hc1[1]*_t123*_t15*_t38*_t50*_t52*_t74*_t9 + _t924 + 0.050008333333333321*_t945;
  const double _t953 = _t240*_t381;
  const double _t954 = _t386*_t953;
  const double _t955 = _t18*_t9/xc_powr(_t10, 7, 2);
  const double _t956 = 0.11251875*_t955;
  const double _t957 = _t126*_t386;
  const double _t958 = _t31*_t317;
  const double _t959 = _t385*_t958 + _t388*_t869;
  const double _t960 = 0.2250375*_t955;
  const double _t961 = _t9*_t953;
  const double _t962 = _t260*_t381;
  const double _t963 = _t557*_t863;
  const double _t965 = _t380*_t739;
  const double _t966 = _t172*_t407;
  const double _t968 = _t385*_t810 + _t956;
  const double _t969 = 0.450075*_t955;
  const double _t970 = _t602*_t953;
  const double _t971 = _t403*_t810;
  const double _t972 = _t954 + _t971;
  const double _t973 = _t380*_t962 + _t387*_t966 + _t656*_t900;
  const double _t974 = _t31*_t353;
  const double _t975 = _t172*_t417;
  const double _t976 = _t380*_t953 + _t387*_t975 + _t656*_t916 + _t971;
  const double _t977 = 0.90015000000000001*_t955;
  const double _t978 = _t386*_t962;
  const double _t979 = _t9*_t962;
  const double _t980 = _t602*_t962;
  const double _t981 = _t385*_t974 + _t414*_t869;
  const double d4F_dna4 = 0.3e1*_t149*_t33 + _t151*_t435 + _t154*_t436 - _t157*_t441 - _t161*_t440 + 0.4e1*_t161*_t85 + 0.4e1*_t164*_t166 - _t165*_t62*_t76 + _t166*_t168*_t450 + _t167*_t171*_t459 + 0.8e1*_t169*_t24 + _t171*_t173*_t451*_t70 + 0.4e1*_t175*_t456 + _t185*_t436 + _t196*_t436 - _t395*_t434 - 0.24003999999999998*_t428 - 0.56009333333333333*_t430 - 2.4893037037037038*_t432 + _t433 - 0.9601599999999999*_t438 - 4.9786074074074076*_t439 - 0.9601599999999999*_t446 - _t447*_t448 - _t448*_t455 - 1.2802133333333332*_t449 + _t451*_t452 + _t458*(-_t457 - 0.28e2 / 0.3e1*_t67) + _t464*((0.16e2 / 0.3e1)*_t26 + _t460) + _t71*(-0.3640e4 / 0.81e2*_t25/xc_powr(na, 16, 3) - _t443) + _t77*((0.560e3 / 0.27e2)*_t158 + _t204);
  const double d4F_dna3_dnb = _t149*_t470 + _t150*_t490 - _t151*_t486 - _t151*_t492 + _t153*_t154 + _t153*_t185 + _t153*_t196 - _t155*_t193*_t70 - _t156*_t475 + _t157*_t474 - _t16*_t175*_t82 - _t161*_t84 + _t161*_t90 + _t161*_t95 + _t163*_t490 - _t164*_t494 + _t165*_t213*_t456 + _t166*_t176*_t213 - _t166*_t192 + _t166*_t210 + _t167*_t482*_t70 - _t168*_t493 + _t169*_t473 + _t175*_t186 - _t190*_t502 - _t206*_t478 - _t21*_t30*_t455 - _t21*_t483 - _t24*_t457*_t495 + _t35*_t465 - 0.060009999999999994*_t428 - 0.28004666666666667*_t430 - 1.8669777777777778*_t432 - _t437*_t479 - 0.24003999999999998*_t438 - 3.7339555555555557*_t439 + _t441*_t488 - 0.24003999999999998*_t446 - 0.3200533333333333*_t449 + _t464*_t487 - _t466*_t467 + _t468*_t469 + _t469*_t476 + 0.060009999999999994*_t471 - 0.62232592592592595*_t472 + _t477*_t63 + _t477*_t89 - _t480*_t481 - _t484*_t485 + _t489*_t85 + _t496*_t499 + _t498 + _t500*_t501 - _t503*_t504 + _t511;
  const double d4F_dna2_dnb2 = (0.32e2 / 0.81e2)*xc_powr(0.6e1, 2, 3)*((_hc1[3]) * (_hc1[3]))*_t181*_t191/(M_CBRTPI * M_CBRTPI) + _t150*_t203 + _t154*_t58 + _t163*_t203 - _t177*_t32*_t82 + 0.2e1*_t177*_t475 + _t178*_t58 - _t183*_t70*_t79 + _t185*_t58 + 0.2e1*_t186*_t482 - _t188*_t513 - _t188*_t517 - _t190*_t482 + _t193*_t534 - _t194*_t486 - _t194*_t492 - _t194*_t527 - _t194*_t529 - _t194*_t532 + _t196*_t58 + _t199*_t512 + _t203*_t217 + _t204*_t499 + _t204*_t85 + _t204*_t90 + _t207*_t506 + _t207*_t508 - _t208*_t468 - _t208*_t476 + _t209*_t58 - _t21*_t521 - _t210*_t533 + _t212*_t66*_t76 + _t214*_t30*_t66 + _t219*_t58 + _t226*_t70 + _t228*_t70 - _t273*_t525 - _t273*_t526 + 1.4935822222222221*_t285*_t57 - _t30*_t522 + _t307*_t58 - _t33*_t81*_t87 - _t38*_t522 - 0.1e1 / 0.2e1*_t39*_t466 - 0.093348888888888884*_t430 + _t435*_t520 - _t437*_t528 - 2.4893037037037038*_t439 + _t458*_t524 + 0.040006666666666663*_t471 + _t473*_t70*_t94 - _t474*_t533 - _t478*_t55 - _t478*_t80 + _t491*_t530 - _t493*_t535 - _t495*_t79*_t82 + _t497*_t94 + _t498 + _t501*_t534 - 0.66381432098765425*_t509 + _t510 + 0.040006666666666663*_t515 - 0.093348888888888884*_t516 + _t518*_t519 - 2.4893037037037038*_t523;
  const double d4F_dna_dnb3 = _t13*_t23*_t536 - _t151*_t527 - _t151*_t529 - _t151*_t532 - _t152*_t478 + _t153*_t209 + _t153*_t219 + _t153*_t307 + (0.28e2 / 0.9e1)*_t159*_t16*_t94 + _t173*_t176*_t542 + _t182*_t225 + 0.3e1*_t186*_t214 - _t189*_t548 + _t193*_t500 - _t21*_t544 - _t21*_t547 + _t210*_t539 + _t213*_t526 + _t216*_t467 + _t217*_t490 - _t220*_t475 - _t223*_t84 + _t223*_t85 - _t225*_t504 + _t227*_t66 - _t31*_t481*_t89 - 0.62232592592592595*_t432 + _t469*_t513 + _t469*_t517 - _t470*_t514 - 1.8669777777777778*_t472 - _t479*_t540 + 0.12001999999999999*_t480*_t88 + _t488*_t546 + _t489*_t90 + _t511 + 0.060009999999999994*_t515 - 0.28004666666666667*_t516 + 0.12001999999999999*_t518*_t89 - _t521*_t541 - 3.7339555555555557*_t523 - _t526*_t541*_t74 - _t528*_t540 + _t530*_t531 + _t535*_t543 - 0.060009999999999994*_t537 + _t538*_t77 - 0.24003999999999998*_t545 - 0.4e1 / 0.3e1*_t68*_t79*_t94;
  const double d4F_dnb4 = _t17*_t289*_t538 + _t17*_t304*_t542 + _t17*_t487*_t555 - 1.2802133333333332*_t193*_t540 + _t209*_t436 + _t214*_t551 + _t214*_t552 + 0.3e1*_t216*_t39 - 0.9601599999999999*_t217*_t540 + _t218*_t518 + _t219*_t436 - _t221*_t546 - _t223*_t440 + _t223*_t450*_t94 + 0.4e1*_t223*_t90 - _t224*_t550 + _t225*_t551 + _t225*_t552 + 0.8e1*_t227*_t79 + _t307*_t436 - _t422*_t434 + _t433 - 2.4893037037037038*_t472 - 0.56009333333333333*_t516 - 4.9786074074074076*_t523 - _t527*_t549 - _t532*_t549 - 0.24003999999999998*_t537 + _t543*_t553 - 0.9601599999999999*_t545 + _t71*(-0.3640e4 / 0.81e2*_t36/xc_powr(nb, 16, 3) - _t443);
  const double d4F_dna3_dgaa = 0.72011999999999987*_t102*_t172*_t445 - _t102*_t592 - _t102*_t598 + (0.935e3 / 0.216e3)*_t103/xc_powr(na, 23, 6) + _t122*_t161 + _t155*_t306*_t70 + _t163*_t591 + _t166*_t267 + _t171*_t595 - 0.1e1 / 0.2e1*_t174*_t579 + (0.4e1 / 0.3e1)*_t175*_t237 + (0.8e1 / 0.3e1)*_t237*_t502 + 0.46674444444444441*_t237*_t565 + _t240*_t566 + _t254*_t447 + (0.7e1 / 0.3e1)*_t265*_t70 - _t273*_t579 - 0.13e2 / 0.18e2*_t30*_t584 - _t302*_t452 - _t306*_t583 + _t386*_t574 + _t556*_t557 + 0.060009999999999994*_t558 + 0.28004666666666667*_t559 + _t561 + _t562*_t564 - 0.38e2 / 0.9e1*_t563*_t585 - _t569 - _t572 + 0.56009333333333333*_t576 - _t578 - 0.3200533333333333*_t582 + _t586*_t587 - _t590 - _t593*_t594;
  const double d4F_dna3_dgab = _t111*_t161 + _t163*_t573*_t605 + _t252*_t483 + _t323*_t455 + _t380*_t556 - _t386*_t568 + 0.12001999999999999*_t558 + 0.56009333333333333*_t559 - _t571*_t601 + _t574*_t602 + 1.1201866666666667*_t576 - _t577*_t601 + _t586*_t604 - 0.48007999999999995*_t589 + _t600;
  const double d4F_dna3_dgbb = 0.72011999999999987*_hc1[1]*_t11*_t15*_t172*_t19*_t30*_t50*_t52*_t73 + 0.48007999999999995*_hc1[1]*_t11*_t15*_t19*_t50*_t52*_t70*_t74 + 0.48007999999999995*_hc1[1]*_t11*_t19*_t23*_t30*_t50*_t52*_t74 + (0.3e1 / 0.2e1)*_hc1[1]*_t12*_t30*_t50*_t52*_t61*_t74 - _t112*_t465 - _t113*_t592 - _t113*_t598 + 0.022503749999999999*_t14*_t148*_t41*_t8*_t9 + 0.060010000000000001*_t14*_t15*_t161*_t31*_t41*_t9 + 0.060010000000000001*_t14*_t15*_t166*_t30*_t41*_t74*_t9 + 0.060010000000000001*_t14*_t15*_t171*_t172*_t30*_t41*_t73*_t9 + 0.56009333333333333*_t14*_t15*_t30*_t31*_t41*_t56 + 0.12002*_t14*_t15*_t41*_t70*_t73*_t74*_t9 + 0.060009999999999994*_t14*_t19*_t41*_t61*_t8 + 0.090014999999999998*_t14*_t23*_t30*_t41*_t73*_t74*_t9 + 0.090014999999999998*_t14*_t23*_t31*_t41*_t70*_t9 + 0.28004666666666667*_t14*_t23*_t41*_t56*_t8 - _t157*_t606 - _t255*_t452 - 0.9e1 / 0.2e1*_t257*_t503 - _t343*_t583 - _t505*_t607 - _t569 - _t572 - _t578 - _t590 - _t594*_t610 - 0.060009999999999994*_t609 - _t611;
  const double d4F_dna2_dnb_dgaa = (0.4e1 / 0.3e1)*_hc1[2]*_hc1[3]*_t12*_t14*_t172*_t19*_t2*_t3*_t30*_t44*_t47 + (0.2e1 / 0.3e1)*_hc1[2]*_hc1[3]*_t12*_t14*_t172*_t19*_t2*_t3*_t44*_t47*_t73 + 0.31116296296296297*_hc1[2]*_t104*_t11*_t14*_t31*_t44*_t56 + (0.8e1 / 0.3e1)*_hc1[2]*_t104*_t12*_t14*_t172*_t197*_t30*_t44 + (0.4e1 / 0.3e1)*_hc1[2]*_t104*_t12*_t14*_t172*_t197*_t44*_t73 + (0.1e1 / 0.3e1)*_hc1[2]*_t104*_t12*_t30*_t34*_t44*_t74 + (0.2e1 / 0.3e1)*_hc1[2]*_t104*_t12*_t34*_t44*_t73*_t74 + 0.24003999999999998*_hc1[2]*_t11*_t14*_t172*_t19*_t30*_t44*_t47*_t73 + 0.12224259259259261*_hc1[2]*_t11*_t14*_t19*_t243*_t31*_t44 + 0.16002666666666665*_hc1[2]*_t11*_t14*_t19*_t44*_t47*_t70*_t74 + (0.1e1 / 0.2e1)*_hc1[2]*_t12*_t14*_t243*_t38*_t44*_t74 - _t102*_t622 - _t102*_t630 - _t115*_t615 + 0.060010000000000001*_t14*_t15*_t172*_t197*_t30*_t41*_t73*_t9 + 0.18669777777777777*_t14*_t15*_t31*_t38*_t41*_t56 + 0.060010000000000001*_t14*_t15*_t41*_t70*_t74*_t86*_t9 + 0.020003333333333331*_t14*_t19*_t41*_t61*_t8 + 0.060010000000000001*_t14*_t23*_t30*_t41*_t74*_t86*_t9 + 0.030005*_t15*_t30*_t34*_t41*_t73*_t74*_t9 + 0.030005*_t15*_t31*_t34*_t41*_t70*_t9 + 0.093348888888888884*_t15*_t34*_t41*_t56*_t8 + 0.030005*_t23*_t30*_t31*_t34*_t41*_t9 - _t236*_t271*_t371 - 0.053342222222222208*_t237*_t625 - _t247*_t266 - _t265*_t635 - _t269*_t620 - _t269*_t624 - _t306*_t629 - _t369*_t58 - 0.10668444444444443*_t582 - 0.16e2 / 0.9e1*_t584*_t86 - _t614 - _t616 - _t617 - _t618 - _t619 - _t628 - _t632 - _t634 - _t636 - _t643 - _t647;
  const double d4F_dna2_dnb_dgab = -_t134*_t38*_t62 + 0.12002*_t14*_t15*_t172*_t197*_t30*_t41*_t73*_t9 + 0.74679111111111107*_t14*_t15*_t30*_t31*_t41*_t56 + 0.12002*_t14*_t15*_t41*_t70*_t74*_t86*_t9 + 0.040006666666666663*_t14*_t19*_t41*_t61*_t8 + 0.12002*_t14*_t23*_t30*_t41*_t74*_t86*_t9 + 0.37339555555555554*_t14*_t23*_t41*_t56*_t8 + 0.060010000000000001*_t15*_t30*_t34*_t41*_t73*_t74*_t9 + 0.060010000000000001*_t15*_t31*_t34*_t41*_t70*_t9 - _t229*_t612 + 0.060010000000000001*_t23*_t30*_t31*_t34*_t41*_t9 - _t571*_t648 - _t577*_t648 - 0.16002666666666665*_t589 - 0.026671111111111111*_t627 - 0.026671111111111111*_t631 - 0.053342222222222221*_t633 - _t650 - _t651;
  const double d4F_dna2_dnb_dgbb = 0.06667777777777778*_t106*_t201 + _t113*_t174*_t457 + _t113*_t248*_t494 - _t113*_t622 - _t113*_t630 + _t113*_t663*_t86 - 0.5e1 / 0.24e2*_t121*_t61 + _t134*_t177*_t30 + _t193*_t657 + _t197*_t595 + _t217*_t573*_t97 - _t241*_t607 + _t254*_t486 - _t257*_t272 + _t257*_t659 + _t257*_t660 + (0.1e1 / 0.2e1)*_t289*_t608 + _t294*_t70 + (0.5e1 / 0.2e1)*_t296*_t503 + _t297*_t70 - _t343*_t629 - _t374*_t58 + _t485*_t662 + _t525*_t656 + 0.020003333333333331*_t558 + 0.18669777777777777*_t559 + 0.37339555555555554*_t576 + _t606*_t82 - 0.020003333333333331*_t609 - _t614 - _t616 - _t617 - _t618 - _t619 - _t628 - _t632 - _t634 - _t638 - _t639 - _t640 - _t642 + 0.093348888888888884*_t652 + 0.18669777777777777*_t653 + (0.5e1 / 0.3e1)*_t654*_t76 + 0.15558148148148149*_t655 - _t658 - _t661 - _t664 - _t665 + _t666;
  const double d4F_dna_dnb2_dgaa = (0.4e1 / 0.3e1)*_hc1[2]*_hc1[3]*_t12*_t14*_t172*_t19*_t2*_t3*_t44*_t47*_t86 + (0.4e1 / 0.9e1)*_hc1[2]*_hc1[3]*_t12*_t19*_t2*_t3*_t34*_t44*_t47*_t74 + 0.15558148148148149*_hc1[2]*_t104*_t11*_t14*_t31*_t44*_t56 + (0.4e1 / 0.3e1)*_hc1[2]*_t104*_t12*_t14*_t172*_t197*_t44*_t86 + (0.4e1 / 0.3e1)*_hc1[2]*_t104*_t12*_t14*_t212*_t44*_t74 + (0.4e1 / 0.3e1)*_hc1[2]*_t104*_t12*_t34*_t44*_t74*_t86 + 0.24003999999999998*_hc1[2]*_t11*_t14*_t172*_t19*_t38*_t44*_t47*_t86 + 0.16002666666666665*_hc1[2]*_t11*_t14*_t19*_t44*_t47*_t74*_t93 + 0.16002666666666665*_hc1[2]*_t11*_t19*_t34*_t38*_t44*_t47*_t74 + (0.1e1 / 0.2e1)*_hc1[2]*_t12*_t30*_t44*_t47*_t74*_t87 - _t102*_t672 - _t102*_t676 - _t207*_t369 - _t237*_t674 - _t241*_t671 - _t265*_t93 - _t269*_t272 - _t289*_t644 - _t300*_t667 - _t306*_t675 - _t647 - _t669*_t670 - _t684;
  const double d4F_dna_dnb2_dgab = -_t134*_t679 + 0.12002*_t14*_t15*_t172*_t197*_t30*_t41*_t86*_t9 + 0.12002*_t14*_t15*_t212*_t30*_t41*_t74*_t9 + 0.74679111111111107*_t14*_t15*_t31*_t38*_t41*_t56 + 0.060010000000000001*_t14*_t23*_t31*_t41*_t9*_t93 + 0.060010000000000001*_t14*_t23*_t38*_t41*_t74*_t86*_t9 + 0.040006666666666663*_t15*_t19*_t41*_t8*_t87 + 0.12002*_t15*_t30*_t34*_t41*_t74*_t86*_t9 + 0.37339555555555554*_t15*_t34*_t41*_t56*_t8 - _t205*_t649 - _t229*_t677 + 0.060010000000000001*_t23*_t31*_t34*_t38*_t41*_t9 - _t636 - _t641*_t680 - _t648*_t678 - _t650 - 0.026671111111111111*_t682 - 0.053342222222222221*_t683;
  const double d4F_dna_dnb2_dgbb = (0.4e1 / 0.3e1)*_hc1[1]*_hc1[3]*_t12*_t15*_t172*_t19*_t2*_t3*_t50*_t52*_t86 + 0.31116296296296297*_hc1[1]*_t11*_t119*_t15*_t31*_t50*_t56 + 0.48007999999999995*_hc1[1]*_t11*_t15*_t172*_t19*_t30*_t50*_t52*_t86 + 0.24003999999999998*_hc1[1]*_t11*_t15*_t172*_t19*_t38*_t50*_t52*_t86 + 0.12224259259259261*_hc1[1]*_t11*_t15*_t19*_t308*_t31*_t50 + 0.16002666666666665*_hc1[1]*_t11*_t15*_t19*_t50*_t52*_t74*_t93 + 0.16002666666666665*_hc1[1]*_t11*_t19*_t23*_t38*_t50*_t52*_t74 + (0.8e1 / 0.3e1)*_hc1[1]*_t119*_t12*_t15*_t172*_t197*_t30*_t50 + _hc1[1]*_t119*_t12*_t15*_t172*_t30*_t50*_t86 + (0.1e1 / 0.3e1)*_hc1[1]*_t119*_t12*_t23*_t38*_t50*_t74 + (0.2e1 / 0.3e1)*_hc1[1]*_t119*_t12*_t23*_t50*_t74*_t86 - _t113*_t672 - _t113*_t676 - _t207*_t374 - 0.55e2 / 0.72e2*_t23*_t309 - _t257*_t301 - _t257*_t620 - _t257*_t674 - _t293*_t635 - 0.053342222222222208*_t296*_t74*_t89 - _t343*_t675 - _t611 - _t658 - _t661 - _t664 - _t665 - _t684 - 0.55e2 / 0.18e2*_t685*_t687 - 0.10668444444444443*_t689;
  const double d4F_dnb3_dgaa = 0.72011999999999987*_hc1[2]*_t11*_t14*_t172*_t19*_t38*_t44*_t47*_t86 + 0.48007999999999995*_hc1[2]*_t11*_t14*_t19*_t44*_t47*_t74*_t93 + 0.48007999999999995*_hc1[2]*_t11*_t19*_t34*_t38*_t44*_t47*_t74 + (0.3e1 / 0.2e1)*_hc1[2]*_t12*_t38*_t44*_t47*_t74*_t87 - _t102*_t697 - _t102*_t702 - _t109*_t223*_t342 + 0.060010000000000001*_t14*_t15*_t172*_t197*_t38*_t41*_t86*_t9 + 0.060010000000000001*_t14*_t15*_t212*_t38*_t41*_t74*_t9 + 0.060010000000000001*_t14*_t15*_t223*_t31*_t41*_t9 + 0.56009333333333333*_t14*_t15*_t31*_t38*_t41*_t56 + 0.12002*_t14*_t15*_t41*_t74*_t86*_t9*_t93 + 0.060009999999999994*_t15*_t19*_t41*_t8*_t87 + 0.022503749999999999*_t15*_t215*_t41*_t8*_t9 + 0.090014999999999998*_t15*_t31*_t34*_t41*_t9*_t93 + 0.090014999999999998*_t15*_t34*_t38*_t41*_t74*_t86*_t9 + 0.28004666666666667*_t15*_t34*_t41*_t56*_t8 - _t153*_t369 - _t221*_t266*_t342 - _t269*_t701*_t86 - _t46*_t47*_t536 - _t505*_t671 - _t593*_t699 - _t646 - _t669*_t695 - _t690 - _t692 - _t694 - _t696;
  const double d4F_dnb3_dgab = _t111*_t223 + _t197*_t252*_t38*_t454*_t86 + _t252*_t544 + _t380*_t703 - _t386*_t693 + _t41*_t605*_t708 + _t600 - _t601*_t678 - _t601*_t691 + _t603*_t705 + 0.56009333333333333*_t652 + 1.1201866666666667*_t653 - 0.48007999999999995*_t681 + 0.12001999999999999*_t704 + _t706*_t707;
  const double d4F_dnb3_dgbb = -_t113*_t697 - _t113*_t702 + (0.935e3 / 0.216e3)*_t120*_t15/xc_powr(nb, 23, 6) + _t122*_t223 - _t153*_t374 + _t155*_t343*_t93 + (0.4e1 / 0.3e1)*_t212*_t293 - _t223*_t255*_t75 + _t252*_t708 + (0.7e1 / 0.3e1)*_t293*_t93 + _t296*_t548 + (0.8e1 / 0.3e1)*_t296*_t553 - _t296*_t659 + _t303*_t544 + _t303*_t547 - 0.1e1 / 0.2e1*_t304*_t688 - 0.13e2 / 0.18e2*_t38*_t709 + _t387*_t705 + _t557*_t703 + _t562*_t711 - _t610*_t699 + 0.28004666666666667*_t652 + 0.56009333333333333*_t653 + 0.46674444444444441*_t655 + 0.72011999999999987*_t662*_t86*_t89 + _t666 - 0.3200533333333333*_t689 - _t690 - _t692 - _t694 - _t696 + 0.060009999999999994*_t704 + _t706*_t712 - 0.38e2 / 0.9e1*_t709*_t86;
  const double d4F_dna2_dgaa2 = _t168*_t317 - _t174*_t725 + _t241*_t388 - 0.5e1*_t248*_t724 - 0.1e1 / 0.3e1*_t264*_t30*_t726 + _t270*_t729 + 0.040006666666666649*_t30*_t740 + _t313*_t615 + (0.247e3 / 0.36e2)*_t316/xc_powr(na, 25, 6) + _t317*_t620 + _t317*_t624 - _t317*_t660 + _t321*_t621 - _t321*_t663 + _t321*_t73*_t737 + 0.34672444444444439*_t580*_t724 - _t585*_t727 + _t62*_t717*_t8 + _t716 + _t720 - _t721 - _t722 + 0.080013333333333325*_t73*_t740 - _t731 - _t734 - _t735 + 0.3200533333333333*_t741 - _t742 - _t745 + _t747;
  const double d4F_dna2_dgaa_dgab = 0.040006666666666649*_hc1[2]*_t104*_t14*_t30*_t41*_t44*_t74*_t9 + 0.080013333333333325*_hc1[2]*_t104*_t14*_t41*_t44*_t73*_t74*_t9 + 0.3200533333333333*_hc1[2]*_t14*_t19*_t30*_t41*_t44*_t47*_t74 - _t731 - _t734 - _t742 - _t745 - _t750 - _t752;
  const double d4F_dna2_dgaa_dgbb = 0.13335555555555553*_hc1[1]*_hc1[2]*_t104*_t11*_t19*_t44*_t50*_t52*_t74 + 0.3e1*_hc1[1]*_hc1[2]*_t12*_t172*_t44*_t47*_t50*_t52*_t70 + (0.55e2 / 0.36e2)*_hc1[1]*_hc1[2]*_t12*_t243*_t44*_t50*_t52*_t74 + 0.6e1*_hc1[1]*_hc1[2]*_t12*_t30*_t44*_t461*_t47*_t50*_t52*_t73 + 0.0075012500000000001*_hc1[1]*_t31*_t41*_t50*_t52*_t61*_t9 + 0.020003333333333324*_hc1[2]*_t104*_t14*_t30*_t41*_t44*_t74*_t9 + 0.040006666666666663*_hc1[2]*_t104*_t14*_t41*_t44*_t73*_t74*_t9 - 0.2e1*_t174*_t754 - _t248*_t754 - _t254*_t753 - _t306*_t657 - _t343*_t657 - _t345*_t663 - _t587*_t744 - _t587*_t755 - 0.045840972222222234*_t730 - _t756 - _t757 - _t759 - _t763;
  const double d4F_dna2_dgab2 = 0.3200533333333333*_t123*_t14*_t15*_t19*_t30*_t31 + 0.16002666666666665*_t123*_t14*_t19*_t23*_t8 + 0.030005*_t123*_t14*_t61*_t8*_t9 - _t185*_t765 - _t196*_t765 - _t49*_t748 - _t764;
  const double d4F_dna2_dgab_dgbb = -_t750 - _t767 - _t768;
  const double d4F_dna2_dgbb2 = (0.3e1 / 0.2e1)*_hc1[1]*_t12*_t136*_t15*_t172*_t30*_t52*_t73 + _hc1[1]*_t12*_t136*_t15*_t52*_t70*_t74 + _hc1[1]*_t12*_t136*_t23*_t30*_t52*_t74 + 0.3e1*_t12*_t137*_t138*_t139*_t15*_t172*_t70 + 0.6e1*_t12*_t137*_t138*_t139*_t15*_t30*_t461*_t73 + 0.3e1*_t12*_t137*_t138*_t139*_t172*_t23*_t30 - _t180*_t362 - _t268*_t769 - _t319*_t770 - _t353*_t660 - _t358*_t663 - _t361*_t512 - _t756 - _t768 - _t771;
  const double d4F_dna_dnb_dgaa2 = 0.026671111111111111*_hc1[2]*_hc1[3]*_t14*_t2*_t281*_t3*_t41*_t44*_t47*_t74 + 0.033338888888888883*_hc1[2]*_t104*_t11*_t129*_t14*_t19*_t31 + (0.1e1 / 0.2e1)*_hc1[2]*_t104*_t12*_t129*_t14*_t38*_t74 + 0.080013333333333325*_hc1[2]*_t104*_t14*_t41*_t44*_t74*_t86*_t9 + 0.025004166666666661*_hc1[2]*_t104*_t31*_t34*_t41*_t44*_t9 + (0.3e1 / 0.2e1)*_hc1[2]*_t12*_t129*_t14*_t172*_t30*_t47*_t86 + (0.1e1 / 0.2e1)*_hc1[2]*_t12*_t129*_t30*_t34*_t47*_t74 + 0.1733622222222222*_t11*_t130*_t131*_t14*_t19*_t314*_t74 + 0.6e1*_t12*_t130*_t131*_t132*_t14*_t30*_t461*_t86 + (0.3e1 / 0.2e1)*_t12*_t130*_t131*_t132*_t172*_t30*_t34 + (0.3e1 / 0.2e1)*_t12*_t130*_t131*_t14*_t172*_t314*_t38 - _t264*_t727*_t86 - _t312*_t34*_t667 - _t317*_t785 - _t321*_t784 - 0.13e2 / 0.12e2*_t366*_t723 - _t519*_t775 - _t520*_t775 - _t63*_t777 - _t670*_t772 - _t698*_t725 - _t759 - _t773*_t774 - _t777*_t89 - _t779 - _t781 - _t783 - _t786 - _t787 - _t792;
  const double d4F_dna_dnb_dgaa_dgab = _t269*_t798 + _t716 + 0.16002666666666665*_t741 - _t758 - _t779 - _t781 - _t783 + _t794 + _t795 + 0.025004166666666661*_t796 + 0.080013333333333325*_t799 + 0.16002666666666665*_t800 + 0.026671111111111111*_t802 + _t805;
  const double d4F_dna_dnb_dgaa_dgbb = (0.25e2 / 0.36e2)*_t236*_t812 + _t241*_t810 - 0.5e1 / 0.2e1*_t248*_t809 + _t257*_t807 - _t257*_t813 + _t269*_t807 - _t269*_t819 + _t328*_t797 + _t345*_t737*_t86 - _t345*_t784 + _t367*_t797 - _t387*_t782 - _t387*_t822 + 0.066677777777777766*_t580*_t754 + 0.066677777777777766*_t580*_t809 - _t63*_t820 - _t656*_t778 + _t673*_t754 + _t720 - 0.033338888888888883*_t733 + 0.080013333333333325*_t741 + 0.020003333333333331*_t746 - _t754*_t821 - _t761 - _t762 - _t788 - _t789 - _t790 - _t791 + 0.020003333333333331*_t793 + 0.01250208333333333*_t796 + 0.040006666666666663*_t799 + 0.080013333333333325*_t800 + 0.013335555555555555*_t802 + 0.0066677777777777777*_t804 + 0.01250208333333333*_t806 - 0.033338888888888883*_t808 + 0.013335555555555555*_t811 + 0.050008333333333321*_t816 + 0.080013333333333325*_t817 + 0.080013333333333325*_t818 - _t820*_t89;
  const double d4F_dna_dnb_dgab2 = 0.026671111111111111*_hc1[3]*_t123*_t14*_t15*_t2*_t281*_t3*_t31 - _t217*_t338 - _t285*_t765 - _t403*_t508 - _t749 - _t764 - _t803*_t97 - _t823;
  const double d4F_dna_dnb_dgab_dgbb = _t257*_t798 + _t805 + 0.025004166666666661*_t806 + 0.026671111111111111*_t811 + 0.10001666666666664*_t816 + 0.16002666666666665*_t817 + 0.16002666666666665*_t818 - _t824 - _t826 - _t827 + _t828;
  const double d4F_dna_dnb_dgbb2 = 0.026671111111111111*_hc1[1]*_hc1[3]*_t15*_t2*_t281*_t3*_t41*_t50*_t52*_t74 + 0.033338888888888883*_hc1[1]*_t11*_t119*_t136*_t15*_t19*_t31 + 0.10001666666666664*_hc1[1]*_t119*_t15*_t30*_t41*_t50*_t74*_t9 + 0.025004166666666661*_hc1[1]*_t119*_t23*_t31*_t41*_t50*_t9 + (0.3e1 / 0.2e1)*_hc1[1]*_t12*_t136*_t15*_t172*_t30*_t52*_t86 + (0.1e1 / 0.2e1)*_hc1[1]*_t12*_t136*_t23*_t38*_t52*_t74 + 0.1733622222222222*_t11*_t137*_t138*_t15*_t19*_t378*_t74 + 0.6e1*_t12*_t137*_t138*_t139*_t15*_t30*_t461*_t86 + (0.3e1 / 0.2e1)*_t12*_t137*_t138*_t139*_t172*_t23*_t38 - 0.5e1 / 0.24e2*_t23*_t377 - 0.13e2 / 0.2e1*_t248*_t831 - _t353*_t785 - _t358*_t784 - 0.13e2 / 0.12e2*_t379*_t829 - _t519*_t832 - _t520*_t832 - _t63*_t833 - _t670*_t769 - 0.5e1 / 0.6e1*_t685*_t830 - _t757 - _t770*_t774 - _t771 - _t792 - _t826 - _t827 - _t833*_t89 - _t834;
  const double d4F_dnb2_dgaa2 = (0.3e1 / 0.2e1)*_hc1[2]*_t12*_t129*_t14*_t172*_t38*_t47*_t86 + _hc1[2]*_t12*_t129*_t14*_t47*_t74*_t93 + _hc1[2]*_t12*_t129*_t34*_t38*_t47*_t74 + 0.3e1*_t12*_t130*_t131*_t132*_t14*_t172*_t93 + 0.6e1*_t12*_t130*_t131*_t132*_t14*_t38*_t461*_t86 + 0.3e1*_t12*_t130*_t131*_t132*_t172*_t34*_t38 - _t268*_t772 - 0.1e1 / 0.8e1*_t312*_t668 - _t317*_t659 - _t319*_t773 - 0.1e1 / 0.4e1*_t320*_t75*_t87 - _t321*_t835 - _t786 - _t840 - _t844;
  const double d4F_dnb2_dgaa_dgab = -_t752 - _t840 - _t845;
  const double d4F_dnb2_dgaa_dgbb = 0.13335555555555553*_hc1[1]*_hc1[2]*_t11*_t119*_t19*_t44*_t47*_t50*_t74 + 0.3e1*_hc1[1]*_hc1[2]*_t12*_t172*_t44*_t47*_t50*_t52*_t93 + (0.55e2 / 0.36e2)*_hc1[1]*_hc1[2]*_t12*_t308*_t44*_t47*_t50*_t74 + 0.6e1*_hc1[1]*_hc1[2]*_t12*_t38*_t44*_t461*_t47*_t50*_t52*_t86 + 0.020003333333333324*_hc1[1]*_t119*_t15*_t38*_t41*_t50*_t74*_t9 + 0.040006666666666663*_hc1[1]*_t119*_t15*_t41*_t50*_t74*_t86*_t9 + 0.0075012500000000001*_hc1[2]*_t31*_t41*_t44*_t47*_t87*_t9 - _t303*_t836 - _t303*_t847 - _t304*_t809 - _t345*_t835 - _t387*_t839 - _t387*_t848 - _t763 - _t780*_t825 - _t787 - _t809*_t821 - _t834 - _t844 - 0.045840972222222234*_t846;
  const double d4F_dnb2_dgab2 = 0.3200533333333333*_t123*_t14*_t15*_t19*_t31*_t38 + 0.16002666666666665*_t123*_t15*_t19*_t34*_t8 + 0.030005*_t123*_t15*_t8*_t87*_t9 - _t209*_t765 - _t219*_t765 - _t307*_t765 - _t764;
  const double d4F_dnb2_dgab_dgbb = 0.040006666666666649*_hc1[1]*_t119*_t15*_t38*_t41*_t50*_t74*_t9 + 0.080013333333333325*_hc1[1]*_t119*_t15*_t41*_t50*_t74*_t86*_t9 + 0.3200533333333333*_hc1[1]*_t15*_t19*_t38*_t41*_t50*_t52*_t74 - _t767 - _t845 - _t849 - _t850 - _t851 - _t852;
  const double d4F_dnb2_dgbb2 = _t173*_t221*_t358 + _t241*_t414 + _t270*_t854 + (0.247e3 / 0.36e2)*_t290*_t356/xc_powr(nb, 25, 6) + _t301*_t353 - 0.5e1*_t304*_t831 + _t353*_t620 - _t353*_t659 + _t353*_t674 - _t358*_t835 + _t358*_t855*_t86 + (0.55e2 / 0.72e2)*_t360*_t710 + 0.040006666666666649*_t38*_t815 - 0.1e1 / 0.3e1*_t38*_t853 + 0.34672444444444439*_t580*_t831 + 0.080013333333333325*_t688*_t814 - 0.4e1*_t698*_t831 + _t717*_t8*_t88 + _t720 + 0.3200533333333333*_t817 + _t828 - _t841 - _t842 - _t843 - _t849 - _t850 - _t851 - _t852 - 0.2e1 / 0.3e1*_t853*_t86;
  const double d4F_dna_dgaa3 = (0.21e2 / 0.4e1)*_t14*_t857/xc_powr(na, 9, 2) + (0.13e2 / 0.4e1)*_t314*_t400 + _t317*_t868 + _t321*_t743*_t867 - _t392*_t861 - _t398*_t737 + (0.5e1 / 0.8e1)*_t728*_t856 - _t859*_t860 - 0.037506249999999991*_t862 - 0.037506249999999991*_t864 - 0.19503249999999997*_t865 + _t869*_t870 + _t876 + _t885;
  const double d4F_dna_dgaa2_dgab = 0.060010000000000001*_hc1[2]*_t129*_t14*_t30*_t41*_t47*_t74*_t9 + 0.18003*_t130*_t131*_t132*_t14*_t172*_t30*_t41*_t9 - 0.025004166666666661*_t862 - 0.13002166666666665*_t865 - _t886 - _t887 - _t889 - _t891;
  const double d4F_dna_dgaa2_dgbb = (0.5e1 / 0.12e2)*_hc1[1]*_hc1[2]*_t104*_t12*_t129*_t50*_t52*_t74 + 0.040006666666666663*_hc1[1]*_hc1[2]*_t11*_t129*_t19*_t47*_t50*_t52*_t74 + 0.12001999999999999*_hc1[1]*_t11*_t130*_t131*_t132*_t172*_t19*_t50*_t52 + (0.13e2 / 0.4e1)*_hc1[1]*_t12*_t130*_t131*_t172*_t314*_t50*_t52 + 0.030005*_hc1[1]*_t123*_t15*_t30*_t50*_t52*_t74*_t9 + 0.0075012500000000001*_hc1[1]*_t123*_t23*_t31*_t50*_t52*_t9 + 0.030005*_hc1[2]*_t129*_t14*_t30*_t41*_t47*_t74*_t9 + 0.090014999999999998*_t130*_t131*_t132*_t14*_t172*_t30*_t41*_t9 + 0.045007499999999999*_t14*_t15*_t30*_t31*_t381*_t9 + 0.022503749999999999*_t14*_t23*_t381*_t8*_t9 - _t407*_t737 - _t623*_t900 - 0.01250208333333333*_t862 - 0.065010833333333323*_t865 - _t873 - _t892 - _t893 - _t896 - _t897 - _t898 - _t903;
  const double d4F_dna_dgaa_dgab2 = 0.18003*_t14*_t15*_t30*_t31*_t381*_t9 + 0.090014999999999998*_t14*_t23*_t381*_t8*_t9 - _t889 - _t904;
  const double d4F_dna_dgaa_dgab_dgbb = 0.060010000000000001*_hc1[1]*_t123*_t15*_t30*_t50*_t52*_t74*_t9 + 0.0150025*_hc1[1]*_t123*_t23*_t31*_t50*_t52*_t9 - _t891 - _t903 - _t907;
  const double d4F_dna_dgaa_dgbb2 = _t229*_t909 + _t236*_t357*_t914 + _t263*_t416 + _t338*_t343 + _t353*_t819 + _t387*_t915 + _t405*_t607 + _t408*_t870 - _t417*_t737 + _t417*_t917 - _t623*_t916 + _t743*_t919 + _t769*_t908 + _t774*_t916 - 0.01250208333333333*_t864 + _t876 - _t902 - _t905 - _t910 - _t911 - _t913 + _t918;
  const double d4F_dna_dgab3 = _t875*_t922 + 0.18003*_t920 + _t921;
  const double d4F_dna_dgab2_dgbb = _t602*_t875 + 0.090014999999999998*_t920 + _t923 + _t926;
  const double d4F_dna_dgab_dgbb2 = _t254*_t832 + _t340*_t769 + _t380*_t871 + _t386*_t875 + _t603*_t915 + _t656*_t770 + _t926 + _t927 - _t928 - _t929;
  const double d4F_dna_dgbb3 = -0.3e1 / 0.4e1*_t23*_t421*_t930 - 0.3e1 / 0.8e1*_t256*_t931 + _t353*_t868 + _t380*_t909 - _t420*_t861 - _t425*_t737 - 0.3e1 / 0.4e1*_t427*_t829 + _t607*_t934 + _t769*_t933 - _t860*_t932 + _t867*_t915 + _t869*_t925 + _t876 + _t936;
  const double d4F_dnb_dgaa3 = -0.3e1 / 0.8e1*_t266*_t856 + _t317*_t940 - 0.3e1 / 0.4e1*_t34*_t394*_t857 - 0.3e1 / 0.4e1*_t366*_t858 + _t369*_t869 + _t380*_t938 - _t392*_t937 - _t398*_t855 + _t671*_t934 - _t701*_t859 + _t772*_t933 + _t867*_t939 + _t885 + _t943;
  const double d4F_dnb_dgaa2_dgab = _t340*_t772 + _t380*_t941 + _t386*_t942 + _t603*_t939 + _t656*_t773 + _t775*_t825 - _t886 - _t887 + _t927 + _t944;
  const double d4F_dnb_dgaa2_dgbb = _t229*_t938 + _t292*_t320*_t914 + _t317*_t813 + _t369*_t403 + _t374*_t408 + _t387*_t939 + _t405*_t671 - _t407*_t855 + _t407*_t917 - _t673*_t900 + _t772*_t908 + _t774*_t900 + (0.5e1 / 0.12e2)*_t812*_t899 + _t837*_t919 - _t892 - _t896 - _t897 - _t898 + _t918 + _t943 - 0.01250208333333333*_t945 - _t946;
  const double d4F_dnb_dgaa_dgab2 = _t602*_t942 + _t923 + _t944 + 0.090014999999999998*_t947;
  const double d4F_dnb_dgaa_dgab_dgbb = 0.060010000000000001*_hc1[2]*_t123*_t14*_t38*_t44*_t47*_t74*_t9 + 0.0150025*_hc1[2]*_t123*_t31*_t34*_t44*_t47*_t9 - _t907 - _t948 - _t949;
  const double d4F_dnb_dgaa_dgbb2 = 0.040006666666666663*_hc1[1]*_hc1[2]*_t11*_t136*_t19*_t44*_t47*_t52*_t74 + (0.5e1 / 0.12e2)*_hc1[1]*_hc1[2]*_t119*_t12*_t136*_t44*_t47*_t74 + 0.030005*_hc1[1]*_t136*_t15*_t38*_t41*_t52*_t74*_t9 + 0.12001999999999999*_hc1[2]*_t11*_t137*_t138*_t139*_t172*_t19*_t44*_t47 + (0.13e2 / 0.4e1)*_hc1[2]*_t12*_t137*_t138*_t172*_t378*_t44*_t47 + 0.030005*_hc1[2]*_t123*_t14*_t38*_t44*_t47*_t74*_t9 + 0.0075012500000000001*_hc1[2]*_t123*_t31*_t34*_t44*_t47*_t9 + 0.090014999999999998*_t137*_t138*_t139*_t15*_t172*_t38*_t41*_t9 + 0.045007499999999999*_t14*_t15*_t31*_t38*_t381*_t9 + 0.022503749999999999*_t15*_t34*_t381*_t8*_t9 - _t417*_t855 - _t673*_t916 - _t873 - _t906 - _t910 - _t911 - _t913 - _t949 - 0.01250208333333333*_t950 - 0.065010833333333323*_t951;
  const double d4F_dnb_dgab3 = _t921 + _t922*_t942 + 0.18003*_t947;
  const double d4F_dnb_dgab2_dgbb = 0.18003*_t14*_t15*_t31*_t38*_t381*_t9 + 0.090014999999999998*_t15*_t34*_t381*_t8*_t9 - _t904 - _t952;
  const double d4F_dnb_dgab_dgbb2 = 0.060010000000000001*_hc1[1]*_t136*_t15*_t38*_t41*_t52*_t74*_t9 + 0.18003*_t137*_t138*_t139*_t15*_t172*_t38*_t41*_t9 - _t928 - _t929 - _t948 - 0.025004166666666661*_t950 - 0.13002166666666665*_t951 - _t952;
  const double d4F_dnb_dgbb3 = (0.13e2 / 0.4e1)*_t137*_t290*_t378*_t426 + (0.21e2 / 0.4e1)*_t15*_t930/xc_powr(nb, 9, 2) + (0.5e1 / 0.8e1)*_t295*_t931 + _t353*_t940 + _t358*_t837*_t867 + _t374*_t869 - _t420*_t937 - _t425*_t855 - _t701*_t932 + _t936 + _t943 - 0.037506249999999991*_t945 - 0.037506249999999991*_t950 - 0.19503249999999997*_t951;
  const double d4F_dgaa4 = 0.3e1*((_hc1[2]) * (_hc1[2]) * (_hc1[2]) * (_hc1[2]))*_t12*_t14*_t399*_t461/xc_powr(na, 29, 6) + (0.15e2 / 0.8e1)*_hc1[2]*_t12*_t14*_t31*_t47/xc_powr(gaa, 7, 2) + (0.15e2 / 0.4e1)*_t12*_t130*_t132*_t14*_t74/(gaa * gaa * gaa) + (0.9e1 / 0.2e1)*_t12*_t14*_t172*_t390*_t394*_t396 - _t392*_t957 - _t603*_t877 - _t707*_t859 - _t954 - _t956 - _t959;
  const double d4F_dgaa3_dgab = -_t384*_t392 - _t387*_t877 - _t712*_t859 - _t959 - _t960 - 0.13502249999999999*_t961;
  const double d4F_dgaa3_dgbb = (0.3e1 / 0.4e1)*_hc1[1]*_hc1[2]*_t12*_t390*_t47*_t50*_t52*_t74 + 0.3e1*_hc1[1]*_t12*_t129*_t394*_t396*_t461*_t50*_t52 + (0.9e1 / 0.4e1)*_hc1[1]*_t12*_t130*_t132*_t172*_t399*_t50*_t52 - _t317*_t963 - _t385*_t388 - _t392*_t933 - _t557*_t962 - _t859*_t965 - _t877*_t964 - _t900*_t965 - 0.067511249999999995*_t961 - _t966*_t967 - _t968;
  const double d4F_dgaa2_dgab2 = -_t388*_t403 - _t408*_t958 - _t969 - _t970;
  const double d4F_dgaa2_dgab_dgbb = -_t388*_t408 - _t405*_t958 - _t960 - _t972 - _t973;
  const double d4F_dgaa2_dgbb2 = (0.1e1 / 0.4e1)*_hc1[1]*_hc1[2]*_t12*_t129*_t136*_t47*_t52*_t74 + (0.3e1 / 0.4e1)*_hc1[1]*_t12*_t130*_t131*_t132*_t136*_t172*_t52 + (0.3e1 / 0.4e1)*_hc1[2]*_t12*_t129*_t137*_t138*_t139*_t172*_t47 + 0.3e1*_t12*_t130*_t131*_t132*_t137*_t138*_t139*_t461 - _t388*_t405 - _t405*_t414 - _t717*_t958 - _t717*_t974 - _t956 - _t973 - _t976;
  const double d4F_dgaa_dgab3 = -_t970 - _t977;
  const double d4F_dgaa_dgab2_dgbb = -_t969 - _t972 - _t978;
  const double d4F_dgaa_dgab_dgbb2 = -_t405*_t974 - _t408*_t414 - _t960 - _t976 - _t978;
  const double d4F_dgaa_dgbb3 = (0.3e1 / 0.4e1)*_hc1[1]*_hc1[2]*_t12*_t419*_t44*_t47*_t52*_t74 + 0.3e1*_hc1[2]*_t12*_t136*_t421*_t423*_t44*_t461*_t47 + (0.9e1 / 0.4e1)*_hc1[2]*_t12*_t137*_t139*_t172*_t426*_t44*_t47 - _t353*_t963 - _t385*_t414 - _t420*_t933 - _t557*_t953 - _t916*_t965 - _t932*_t965 - _t935*_t964 - _t967*_t975 - _t968 - 0.067511249999999995*_t979;
  const double d4F_dgab4 = -1.8003*_t955;
  const double d4F_dgab3_dgbb = -_t977 - _t980;
  const double d4F_dgab2_dgbb2 = -_t403*_t414 - _t408*_t974 - _t969 - _t980;
  const double d4F_dgab_dgbb3 = -_t384*_t420 - _t387*_t935 - _t712*_t932 - _t960 - 0.13502249999999999*_t979 - _t981;
  const double d4F_dgbb4 = 0.3e1*((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_t12*_t15*_t426*_t461/xc_powr(nb, 29, 6) + (0.15e2 / 0.8e1)*_hc1[1]*_t12*_t15*_t31*_t52/xc_powr(gbb, 7, 2) + (0.15e2 / 0.4e1)*_t12*_t137*_t139*_t15*_t74/(gbb * gbb * gbb) + (0.9e1 / 0.2e1)*_t12*_t15*_t172*_t419*_t421*_t423 - _t420*_t957 - _t603*_t935 - _t707*_t932 - _t956 - _t978 - _t981;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 1] += d4F_dna3_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 2] += d4F_dna3_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 3] += d4F_dna2_dnb_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 4] += d4F_dna2_dnb_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 5] += d4F_dna2_dnb_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 6] += d4F_dna_dnb2_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 7] += d4F_dna_dnb2_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 8] += d4F_dna_dnb2_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 9] += d4F_dnb3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 10] += d4F_dnb3_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 1] += d4F_dna2_dgaa_dgab;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 2] += d4F_dna2_dgaa_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 3] += d4F_dna2_dgab2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 4] += d4F_dna2_dgab_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 5] += d4F_dna2_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 6] += d4F_dna_dnb_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 7] += d4F_dna_dnb_dgaa_dgab;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 8] += d4F_dna_dnb_dgaa_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 9] += d4F_dna_dnb_dgab2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 10] += d4F_dna_dnb_dgab_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 11] += d4F_dna_dnb_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 12] += d4F_dnb2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 13] += d4F_dnb2_dgaa_dgab;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 14] += d4F_dnb2_dgaa_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 15] += d4F_dnb2_dgab2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 16] += d4F_dnb2_dgab_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 1] += d4F_dna_dgaa2_dgab;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 2] += d4F_dna_dgaa2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 3] += d4F_dna_dgaa_dgab2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 4] += d4F_dna_dgaa_dgab_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 5] += d4F_dna_dgaa_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 6] += d4F_dna_dgab3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 7] += d4F_dna_dgab2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 8] += d4F_dna_dgab_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 9] += d4F_dna_dgbb3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 10] += d4F_dnb_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 11] += d4F_dnb_dgaa2_dgab;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 12] += d4F_dnb_dgaa2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 13] += d4F_dnb_dgaa_dgab2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 14] += d4F_dnb_dgaa_dgab_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 15] += d4F_dnb_dgaa_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 16] += d4F_dnb_dgab3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 17] += d4F_dnb_dgab2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 18] += d4F_dnb_dgab_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 1] += d4F_dgaa3_dgab;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 2] += d4F_dgaa3_dgbb;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 3] += d4F_dgaa2_dgab2;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 4] += d4F_dgaa2_dgab_dgbb;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 5] += d4F_dgaa2_dgbb2;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 6] += d4F_dgaa_dgab3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 7] += d4F_dgaa_dgab2_dgbb;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 8] += d4F_dgaa_dgab_dgbb2;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 9] += d4F_dgaa_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 10] += d4F_dgab4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 11] += d4F_dgab3_dgbb;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 12] += d4F_dgab2_dgbb2;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 13] += d4F_dgab_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
#endif
#endif
}
#endif