/*
  Generated from python/gga_exc/gga_c_w94.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_w94
*/

#ifndef _GGA_C_W94_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_W94_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_W94_HELPER_BODIES
#include "gga_c_w94.c"
#undef _GGA_C_W94_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_W94_HELPER_BODIES
#include "gga_c_w94.c"
#undef _GGA_C_W94_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_W94_HELPER_BODIES
#include "gga_c_w94.c"
#undef _GGA_C_W94_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_W94_HELPER_BODIES
#include "gga_c_w94.c"
#undef _GGA_C_W94_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_W94_HELPER_BODIES
#include "gga_c_w94.c"
#undef _GGA_C_W94_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_w94.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_w94.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_w94.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_w94.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_w94.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_w94.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_w94.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_w94.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_w94.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_w94.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_W94_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_num_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z >= 0;
  const double _t2 = my_piecewise3(_t1, z, -z);
  const double _t3 = xc_powr(XC_EPSILON, 2, 3);
  const double _t4 = _t2 > _t3;
  const double _t5 = my_piecewise3(_t4, _t2, _t3);
  const double _t6 = 0.1e1 - _t3;
  const double _t7 = _t5 > _t6;
  const double _t8 = my_piecewise3(_t7, _t6, _t5);
  const double _t9 = 0.1e1 - xc_powr(_t8, 5, 3);
  const double _t10 = xc_powr(_t9, 1, 2);
#if _KMAX >= 1
  const double _t11 = my_piecewise3(_t7, 0, my_piecewise3(_t4, my_piecewise3(_t1, 0.1e1, -0.1e1), 0));
  const double _t12 = xc_powr(_t8, 2, 3);
  const double _t13 = (0.1e1 / _t10);
#endif
#if _KMAX >= 2
  const double _t14 = (_t11 * _t11);
  const double _t15 = xc_powr(_t8, 4, 3);
  const double _t16 = xc_powr(_t9, -3, 2);
  const double _t17 = xc_powr(_t8, 1, 3);
#endif
#if _KMAX >= 3
  const double _t18 = (_t11 * _t11 * _t11);
  const double _t19 = xc_powr(_t9, -5, 2);
#endif
#if _KMAX >= 4
  const double _t20 = (_t11 * _t11 * _t11 * _t11);
#endif

  const double f = -_t10;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = (0.5e1 / 0.6e1)*_t11*_t12*_t13;
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = (0.5e1 / 0.9e1)*_t13*_t14/_t17 + (0.25e2 / 0.36e2)*_t14*_t15*_t16;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = -0.5e1 / 0.27e2*_t13*_t18/_t15 + (0.25e2 / 0.18e2)*_t16*_t17*_t18 + (0.125e3 / 0.72e2)*_t18*_t19*(_t8 * _t8);
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = (0.20e2 / 0.81e2)*_t13*_t20/xc_powr(_t8, 7, 3) + (0.125e3 / 0.18e2)*_t19*_t20*_t8 + (0.3125e4 / 0.432e3)*_t20*xc_powr(_t8, 8, 3)/xc_powr(_t9, 7, 2) + (0.25e2 / 0.81e2)*_t16*_t20/_t12;
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_den_k, _KMAX)(const xc_func_type *p, double rs, double xt, double *out) {

  const double _t1 = xc_powr(0.6e1, 2, 3)*M_CBRTPI;
  const double _t2 = 0.0036733333333333331*_t1*(xt * xt);
#if _KMAX >= 1
  const double _t3 = 0.0073466666666666663*_t1;
  const double _t4 = _t3*rs;
#endif

  const double f = _t2*rs + rs + 0.15067*pow(xt, 0.51e2 / 0.16e2) + 11.800000000000001;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = _t4*xt + 0.480260625*pow(xt, 0.35e2 / 0.16e2);
  out[1] = df_dxt;
  const double df_drs = _t2 + 0.1e1;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = _t4 + 1.0505701171874999*pow(xt, 0.19e2 / 0.16e2);
  out[3] = d2f_dxt2;
  const double d2f_drs_dxt = _t3*xt;
  out[4] = d2f_drs_dxt;
  const double d2f_drs2 = 0;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = 1.2475520141601562*pow(xt, 0.3e1 / 0.16e2);
  out[6] = d3f_dxt3;
  const double d3f_drs_dxt2 = _t3;
  out[7] = d3f_drs_dxt2;
  const double d3f_drs2_dxt = 0;
  out[8] = d3f_drs2_dxt;
  const double d3f_drs3 = 0;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = 0.23391600265502926/pow(xt, 0.13e2 / 0.16e2);
  out[10] = d4f_dxt4;
  const double d4f_drs_dxt3 = 0;
  out[11] = d4f_drs_dxt3;
  const double d4f_drs2_dxt2 = 0;
  out[12] = d4f_drs2_dxt2;
  const double d4f_drs3_dxt = 0;
  out[13] = d4f_drs3_dxt;
  const double d4f_drs4 = 0;
  out[14] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = xc_powr(na, -1, 3);
  const double _t5 = (0.1e1 / 0.2e1)*_t4;
  const double _t6 = xc_powr(gaa, 1, 2);
  const double _t7 = xc_powr(na, -4, 3);
  const double _t8 = _t6*_t7;
  const double _t9 = xc_powr(XC_EPSILON, 2, 3);
  const double _t10 = xc_powr(0.1e1 - xc_powr(my_piecewise3(0.2e1*_t9 - 0.1e1 > 0, 0.1e1 - _t9, _t9), 5, 3), 1, 2);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_den_k, _KMAX)(p, _t3*_t5, _t8, _hc0);
  const double _t11 = _t10/_hc0[0];
  const double zk = -_t11;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t12 = xc_powr(na, -7, 3);
  const double _t13 = _t12*_t6;
  const double _t15 = _t3*_t7;
  const double _t21 = (0.1e1 / _t6);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_den_k, _KMAX)(p, 0, _t8, _hc1);
  const double _t14 = _hc0[1]*_t13;
  const double _t16 = _hc1[2]*_t15;
  const double _t17 = (0.4e1 / 0.3e1)*_t14 + (0.1e1 / 0.6e1)*_t16;
  const double _t18 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t19 = _t10*_t18;
  const double _t20 = _t19*na;
  const double _t22 = _hc0[1]*_t21;
  const double _t23 = _t19*_t22;
  const double dF_dna = -_t11 - _t17*_t20;
  const double dF_dgaa = _t23*_t5;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t29 = xc_powr(na, -10, 3);
  const double _t30 = _t29*_t6;
  const double _t32 = _t12*_t3;
  const double _t34 = xc_powr(na, -11, 3);
  const double _t46 = _t12*_t21;
  const double _t48 = xc_powr(na, -8, 3);
  const double _t49 = _t21*_t48;
  const double _t53 = xc_powr(gaa, -3, 2);
  const double _t56 = (0.1e1 / gaa);
  const double _t57 = xc_powr(na, -5, 3);
  const double _t60 = _t56*_t57;
  const double _t61 = (0.1e1 / 0.2e1)*_t60;
  const double _t24 = (0.8e1 / 0.3e1)*_t14 + (0.1e1 / 0.3e1)*_t16;
  const double _t25 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t26 = _t10*_t25;
  const double _t27 = _t24*_t26;
  const double _t28 = _t17*na;
  const double _t31 = _hc0[1]*_t30;
  const double _t33 = _hc1[2]*_t32;
  const double _t35 = _hc1[4]*_t3;
  const double _t36 = _t35*_t6;
  const double _t37 = _t34*_t36;
  const double _t38 = _hc0[3]*_t13;
  const double _t39 = _hc1[4]*_t15;
  const double _t40 = -0.16e2 / 0.9e1*_t38 - 0.2e1 / 0.9e1*_t39;
  const double _t41 = _t12*_t40*_t6 - 0.28e2 / 0.9e1*_t31 - 0.2e1 / 0.9e1*_t33 - 0.2e1 / 0.9e1*_t37;
  const double _t42 = _t17*_t26;
  const double _t43 = _t22*_t4;
  const double _t44 = _hc0[3]*_t34;
  const double _t45 = (0.2e1 / 0.3e1)*_t44;
  const double _t47 = _hc0[1]*_t46;
  const double _t50 = _t35*_t49;
  const double _t51 = _t45 + (0.2e1 / 0.3e1)*_t47 + (0.1e1 / 0.12e2)*_t50;
  const double _t52 = (0.1e1 / 0.4e1)*_t19;
  const double _t54 = _hc0[1]*_t53;
  const double _t55 = _t4*_t54;
  const double _t58 = ((_hc0[1]) * (_hc0[1]));
  const double _t59 = _t26*_t58;
  const double d2F_dna2 = -_t10*_t18*_t24 - _t20*_t41 - _t27*_t28;
  const double d2F_dna_dgaa = -_t20*_t51 + (0.1e1 / 0.2e1)*_t23*_t7 + _t42*_t43;
  const double d2F_dgaa2 = (0.1e1 / 0.4e1)*_hc0[3]*_t10*_t18*_t56*_t57 - _t52*_t55 - _t59*_t61;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t73 = 0.2e1*na;
  const double _t74 = xc_powr(na, -13, 3);
  const double _t75 = _t6*_t74;
  const double _t77 = _t29*_t3;
  const double _t79 = xc_powr(na, -14, 3);
  const double _t90 = _t3*_t6;
  const double _t101 = _t21*_t29;
  const double _t114 = _t48*_t56;
  const double _t116 = _t12*_t53;
  const double _t117 = xc_powi(na, -5);
  const double _t118 = _t117*_t21;
  const double _t120 = _t48*_t53;
  const double _t121 = (0.1e1 / (na * na * na * na));
  const double _t125 = xc_powr(gaa, -5, 2);
  const double _t129 = (0.1e1 / (gaa * gaa));
  const double _t130 = _t129*_t57;
  const double _t132 = (0.1e1 / (na * na * na));
  const double _t133 = _t132*_t53;
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_den_k, _KMAX)(p, 0, 0, _hc2);
  const double _t62 = 0.3e1*_t17;
  const double _t63 = 0.4e1*_t14 + (0.1e1 / 0.2e1)*_t16;
  const double _t64 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t65 = _t10*_t64;
  const double _t66 = _t24*_t65;
  const double _t67 = _t63*_t66;
  const double _t68 = _t13*_t40;
  const double _t69 = (0.28e2 / 0.3e1)*_t31 + (0.2e1 / 0.3e1)*_t33 + (0.2e1 / 0.3e1)*_t37;
  const double _t70 = _t12*_t6*(-0.32e2 / 0.9e1*_t38 - 0.4e1 / 0.9e1*_t39) - 0.56e2 / 0.9e1*_t31 - 0.4e1 / 0.9e1*_t33 - 0.4e1 / 0.9e1*_t37;
  const double _t71 = _t26*_t28;
  const double _t72 = _t27*_t41;
  const double _t76 = _hc0[1]*_t75;
  const double _t78 = _hc1[2]*_t77;
  const double _t80 = _t36*_t79;
  const double _t81 = _hc2[7]*_t79;
  const double _t82 = _t81*gaa;
  const double _t83 = _hc1[4]*_t30;
  const double _t84 = _t15*((0.8e1 / 0.27e2)*_t82 + (0.14e2 / 0.27e2)*_t83);
  const double _t85 = _t30*((0.224e3 / 0.27e2)*_t38 + (0.28e2 / 0.27e2)*_t39);
  const double _t86 = _hc0[3]*_t30;
  const double _t87 = _hc1[4]*_t32;
  const double _t88 = _hc2[7]*_t34;
  const double _t89 = (0.8e1 / 0.27e2)*_t88;
  const double _t91 = _hc1[6]*_t13;
  const double _t92 = _hc2[7]*_t15;
  const double _t93 = _t13*(_t13*((0.64e2 / 0.27e2)*_t91 + (0.8e1 / 0.27e2)*_t92) + (0.112e3 / 0.27e2)*_t86 + (0.8e1 / 0.27e2)*_t87 + _t89*_t90);
  const double _t94 = (0.280e3 / 0.27e2)*_t76 + (0.14e2 / 0.27e2)*_t78 + (0.16e2 / 0.27e2)*_t80 + _t84 + _t85 + _t93;
  const double _t95 = _t22*_t7;
  const double _t96 = (0.4e1 / 0.3e1)*_t44 + (0.4e1 / 0.3e1)*_t47 + (0.1e1 / 0.6e1)*_t50;
  const double _t97 = _t43*_t66;
  const double _t98 = _t27*_t51;
  const double _t99 = _t26*_t43;
  const double _t100 = _hc0[3]*_t79;
  const double _t102 = _hc0[1]*_t101;
  const double _t103 = _t21*_t34*_t35;
  const double _t104 = _hc1[4]*_t46;
  const double _t105 = -0.1e1 / 0.9e1*_t104 - 0.1e1 / 0.9e1*_t88;
  const double _t106 = -0.8e1 / 0.9e1*_t38 - 0.1e1 / 0.9e1*_t39;
  const double _t107 = _hc1[6]*_t34;
  const double _t108 = _hc0[3]*_t46;
  const double _t109 = _hc2[7]*_t3;
  const double _t110 = _t109*_t49;
  const double _t111 = -0.8e1 / 0.9e1*_t107 - 0.8e1 / 0.9e1*_t108 - 0.1e1 / 0.9e1*_t110;
  const double _t112 = _t1*_t105*_t2*_t7 - 0.14e2 / 0.9e1*_t100 - 0.14e2 / 0.9e1*_t102 - 0.1e1 / 0.9e1*_t103 + _t106*_t12*_t21 + _t111*_t12*_t6;
  const double _t113 = _t54*_t7;
  const double _t115 = _t5*_t54;
  const double _t119 = _hc1[6]*_t118;
  const double _t122 = _t109*_t121;
  const double _t123 = _t122*_t56;
  const double _t124 = -0.1e1 / 0.3e1*_hc0[1]*_t116 + (0.1e1 / 0.3e1)*_t119 - 0.1e1 / 0.24e2*_t120*_t35 + (0.1e1 / 0.24e2)*_t123 + (0.1e1 / 0.3e1)*_t44*_t56;
  const double _t126 = _hc0[1]*_t125;
  const double _t127 = (0.3e1 / 0.8e1)*_t19;
  const double _t128 = _t126*_t127;
  const double _t131 = _hc0[3]*_t130;
  const double _t134 = _hc1[6]*_t133;
  const double _t135 = (0.1e1 / 0.8e1)*_t19;
  const double _t136 = _hc0[3]*_t26;
  const double _t137 = (0.3e1 / 0.4e1)*_t54;
  const double _t138 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t139 = _t133*_t138;
  const double _t140 = (0.3e1 / 0.4e1)*_t65;
  const double _t141 = (0.3e1 / 0.4e1)*_t59;
  const double d3F_dna3 = _t10*_t18*(-0.3e1*_t68 + _t69) - _t20*_t94 - _t27*_t62 - _t28*_t67 - _t70*_t71 - _t72*_t73;
  const double d3F_dna2_dgaa = -_t112*_t20 + (0.3e1 / 0.2e1)*_t17*_t97 - _t19*_t96 + _t41*_t99 + 0.2e1*_t42*_t95 - _t71*_t96 - _t98*na;
  const double d3F_dna_dgaa2 = 0.2e1*_hc0[1]*_t10*_t21*_t25*_t4*_t51 + (0.1e1 / 0.2e1)*_hc0[3]*_t10*_t17*_t25*_t56*_t57 + (0.1e1 / 0.4e1)*_hc0[3]*_t10*_t18*_t48*_t56 + _t10*_t56*_t57*_t58*_t64*(-0.2e1*_t14 - 0.1e1 / 0.4e1*_t16) - _t113*_t52 - 0.1e1 / 0.2e1*_t114*_t59 - _t115*_t42 - _t124*_t20;
  const double d3F_dgaa3 = -_t127*_t131 + _t128*_t4 + _t130*_t141 - _t132*_t136*_t137 + _t134*_t135 + _t139*_t140;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t154 = xc_powr(na, -17, 3);
  const double _t161 = _t21*_t3;
  const double _t168 = (0.1e1 / 0.18e2)*_t56;
  const double _t169 = _t129*_t48;
  const double _t170 = _t121*_t53;
  const double _t174 = (0.1e1 / 0.2e1)*_t129;
  const double _t175 = (0.1e1 / (gaa * gaa * gaa));
  const double _t176 = _t125*_t132;
  const double _t177 = _t129*_t74;
  const double _t142 = 0.4e1*_t17;
  const double _t143 = _t26*_t70;
  const double _t144 = _t28*_t63;
  const double _t145 = xc_powi((_hc0[0]), -5);
  const double _t146 = _t10*_t145;
  const double _t147 = _t146*_t24;
  const double _t148 = _t28*_t66;
  const double _t149 = 0.3e1*_t41;
  const double _t150 = _t67*na;
  const double _t151 = _t143*na;
  const double _t152 = _t88*_t90;
  const double _t153 = _t27*na;
  const double _t155 = (0.56e2 / 0.27e2)*_hc2[7];
  const double _t156 = _t26*_t96;
  const double _t157 = _t65*_t96;
  const double _t158 = _t156*_t73;
  const double _t159 = 0.2e1*_t112;
  const double _t160 = (0.7e1 / 0.27e2)*_hc1[4];
  const double _t162 = (0.32e2 / 0.27e2)*_t91 + (0.4e1 / 0.27e2)*_t92;
  const double _t163 = _t58*_t65;
  const double _t164 = (0.3e1 / 0.4e1)*_t17*_t66;
  const double _t165 = -0.2e1 / 0.3e1*_hc0[1]*_t12*_t53 - 0.1e1 / 0.12e2*_hc1[4]*_t1*_t2*_t48*_t53 + (0.2e1 / 0.3e1)*_t119 + (0.1e1 / 0.12e2)*_t123 + _t45*_t56;
  const double _t166 = _t163*_t60;
  const double _t167 = (0.1e1 / 0.18e2)*_hc1[4];
  const double _t171 = (0.3e1 / 0.4e1)*_t42;
  const double _t172 = (0.9e1 / 0.4e1)*_t65;
  const double _t173 = (0.3e1 / 0.2e1)*_t51;
  const double d4F_dna4 = _t10*_t18*(-0.1120e4 / 0.27e2*_t76 - 0.56e2 / 0.27e2*_t78 - 0.64e2 / 0.27e2*_t80 - 0.4e1*_t84 - 0.4e1*_t85 - 0.4e1*_t93) - _t142*_t143 - _t142*_t67 - _t144*_t147*((0.16e2 / 0.3e1)*_t14 + (0.2e1 / 0.3e1)*_t16) - 0.2e1*_t144*_t65*_t70 - _t148*(_t12*_t6*(-0.16e2 / 0.3e1*_t38 - 0.2e1 / 0.3e1*_t39) - _t69) - _t149*_t150 - _t149*_t151 - 0.3e1*_t153*_t94 - _t20*(-0.3640e4 / 0.81e2*_hc0[1]*_t6/xc_powr(na, 16, 3) - 0.140e3 / 0.81e2*_hc1[2]*_t3*_t74 + _t13*(-0.1120e4 / 0.81e2*_hc0[3]*_t75 - 0.56e2 / 0.81e2*_hc1[4]*_t77 + _t12*_t6*(-0.256e3 / 0.81e2*_hc1[10]*_t79*gaa - 0.448e3 / 0.81e2*_hc1[6]*_t30 - 0.32e2 / 0.81e2*_hc2[7]*_t32) + _t29*_t6*(-0.896e3 / 0.81e2*_t91 - 0.112e3 / 0.81e2*_t92) - 0.40e2 / 0.27e2*_t81*_t90) + _t15*(-0.140e3 / 0.81e2*_hc1[4]*_t75 - _t154*_t155*gaa) - 0.56e2 / 0.27e2*_t154*_t36 + _t30*(_t12*_t6*(-_t15*_t155 - 0.448e3 / 0.27e2*_t91) - 0.56e2 / 0.27e2*_t152 - 0.784e3 / 0.27e2*_t86 - 0.56e2 / 0.27e2*_t87) + _t32*(-0.32e2 / 0.27e2*_t82 - 0.56e2 / 0.27e2*_t83) + _t75*(-0.1120e4 / 0.27e2*_t38 - 0.140e3 / 0.27e2*_t39)) - _t71*(_t13*(_t13*((0.128e3 / 0.27e2)*_t91 + (0.16e2 / 0.27e2)*_t92) + (0.16e2 / 0.27e2)*_t152 + (0.224e3 / 0.27e2)*_t86 + (0.16e2 / 0.27e2)*_t87) + _t15*((0.16e2 / 0.27e2)*_t82 + (0.28e2 / 0.27e2)*_t83) + _t30*((0.448e3 / 0.27e2)*_t38 + (0.56e2 / 0.27e2)*_t39) + (0.560e3 / 0.27e2)*_t76 + (0.28e2 / 0.27e2)*_t78 + (0.32e2 / 0.27e2)*_t80) - 0.8e1*_t72;
  const double d4F_dna3_dgaa = 0.2e1*_hc0[1]*_t10*_t145*_t17*_t21*_t24*_t4*_t63 + (0.9e1 / 0.2e1)*_hc0[1]*_t10*_t17*_t21*_t24*_t64*_t7 + (0.3e1 / 0.2e1)*_hc0[1]*_t10*_t17*_t21*_t4*_t64*_t70 + 0.3e1*_hc0[1]*_t10*_t21*_t24*_t4*_t41*_t64 + _hc0[1]*_t10*_t21*_t25*_t4*_t94 + 0.3e1*_hc0[1]*_t10*_t21*_t25*_t41*_t7 + _t10*_t18*((0.14e2 / 0.3e1)*_t100 + (0.14e2 / 0.3e1)*_t102 + (0.1e1 / 0.3e1)*_t103 - 0.3e1*_t105*_t15 - 0.3e1*_t106*_t46 - 0.3e1*_t111*_t13) - _t144*_t157 - _t148*(0.2e1*_t44 + 0.2e1*_t47 + (0.1e1 / 0.4e1)*_t50) - _t150*_t51 - _t151*_t51 - _t153*_t159 - _t156*_t62 - _t158*_t41 - _t20*((0.140e3 / 0.27e2)*_hc0[3]*_t154 + _t101*((0.112e3 / 0.27e2)*_t38 + (0.14e2 / 0.27e2)*_t39) + _t13*((0.56e2 / 0.27e2)*_hc0[3]*_t101 + (0.56e2 / 0.27e2)*_hc1[6]*_t79 + _t13*((0.32e2 / 0.27e2)*_hc1[10]*_t34 + (0.32e2 / 0.27e2)*_hc1[6]*_t46) + _t161*_t89 + _t162*_t46) + _t15*(_t101*_t160 + (0.5e1 / 0.9e1)*_t81) + _t160*_t161*_t79 + (0.140e3 / 0.27e2)*_t22*_t74 + _t30*((0.112e3 / 0.27e2)*_t107 + (0.112e3 / 0.27e2)*_t108 + (0.14e2 / 0.27e2)*_t110) + _t32*((0.8e1 / 0.27e2)*_t104 + _t89) + _t46*(_t13*_t162 + (0.4e1 / 0.27e2)*_t152 + (0.56e2 / 0.27e2)*_t86 + (0.4e1 / 0.27e2)*_t87)) - _t71*(_t1*_t2*_t7*(-0.2e1 / 0.9e1*_t104 - 0.2e1 / 0.9e1*_t88) - 0.28e2 / 0.9e1*_t100 - 0.28e2 / 0.9e1*_t102 - 0.2e1 / 0.9e1*_t103 + _t12*_t21*_t40 + _t12*_t6*(-0.16e2 / 0.9e1*_t107 - 0.16e2 / 0.9e1*_t108 - 0.2e1 / 0.9e1*_t110)) - 0.3e1*_t98;
  const double d4F_dna2_dgaa2 = _hc0[3]*_t114*_t42 + _hc0[3]*_t164*_t60 - _t113*_t42 - _t114*_t163*_t63 - _t115*_t26*_t41 - _t124*_t153 + _t136*_t41*_t61 - _t147*_t58*_t60*_t62 + _t157*_t43*_t62 - _t158*_t51 + _t159*_t99 - _t164*_t55 - _t165*_t19 - _t165*_t71 + _t166*((0.14e2 / 0.3e1)*_t31 + (0.1e1 / 0.3e1)*_t33 + (0.1e1 / 0.3e1)*_t37 - 0.3e1 / 0.2e1*_t68) - _t20*(-0.7e1 / 0.9e1*_hc1[6]*_t21/xc_powi(na, 6) - 0.7e1 / 0.9e1*_t100*_t56 - _t109*_t117*_t168 + _t111*_t46 + _t116*(_t15*_t167 + (0.4e1 / 0.9e1)*_t38) + _t13*((0.4e1 / 0.9e1)*_hc0[3]*_t116 - 0.4e1 / 0.9e1*_hc1[10]*_t118 - 0.4e1 / 0.9e1*_t107*_t56 + (0.1e1 / 0.18e2)*_t109*_t120) + _t15*(_t116*_t167 - _t168*_t88) + _t167*_t3*_t34*_t53 + (0.7e1 / 0.9e1)*_t29*_t54) + 0.4e1*_t26*_t51*_t95 + 0.3e1*_t51*_t97;
  const double d4F_dna_dgaa3 = -_hc0[3]*_t127*_t169 - _hc0[3]*_t132*_t17*_t172*_t54 + _hc1[6]*_t135*_t170 - _t121*_t136*_t137 + 0.3e1*_t124*_t99 + _t126*_t171*_t4 + _t128*_t7 + _t130*_t163*(0.3e1*_t14 + (0.3e1 / 0.8e1)*_t16) - _t131*_t171 + (0.1e1 / 0.4e1)*_t134*_t42 + _t136*_t173*_t60 + _t138*_t140*_t170 + _t139*_t146*_t63 + _t141*_t169 + _t166*(-0.3e1*_t44 - 0.3e1*_t47 - 0.3e1 / 0.8e1*_t50) - _t173*_t26*_t55 - _t20*((0.1e1 / 0.6e1)*_hc1[10]*_t56/xc_powr(na, 19, 3) + (0.1e1 / 0.2e1)*_t12*_t126 - 0.1e1 / 0.16e2*_t122*_t129 + (0.1e1 / 0.16e2)*_t125*_t35*_t48 - _t174*_t44);
  const double d4F_dgaa4 = -0.3e1 / 0.2e1*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t146*_t177 + (0.9e1 / 0.4e1)*_hc0[1]*_hc0[3]*_t10*_t125*_t132*_t25 - _hc0[1]*_hc1[6]*_t174*_t26*_t74 - 0.15e2 / 0.16e2*_hc0[1]*_t19*_t4/xc_powr(gaa, 7, 2) - 0.3e1 / 0.8e1*((_hc0[3]) * (_hc0[3]))*_t177*_t26 + (0.9e1 / 0.4e1)*_hc0[3]*_t10*_t129*_t58*_t64*_t74 + (0.15e2 / 0.16e2)*_hc0[3]*_t10*_t175*_t18*_t57 + (0.1e1 / 0.16e2)*_hc1[10]*_t10*_t129*_t18*_t74 - _hc1[6]*_t127*_t176 - _t138*_t172*_t176 - 0.15e2 / 0.8e1*_t175*_t57*_t59;
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

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = na + nb;
  const double _t5 = xc_powr(_t4, -1, 3);
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
  const double _t7 = xc_powr(_t4, -4, 3);
  const double _t8 = gaa + 0.2e1*gab + gbb;
  const double _t9 = xc_powr(_t8, 1, 2);
  const double _t10 = _t7*_t9;
  const double _t11 = na - nb;
  const double _t12 = (0.1e1 / _t4);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_den_k, _KMAX)(p, _t3*_t6, _t10, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_num_k, _KMAX)(p, _t11*_t12, _hc1);
  const double _t13 = (0.1e1 / (_hc0[0]));
  const double _t14 = _hc1[0]*_t13;
  const double zk = _t14;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t15 = -_t12;
  const double _t16 = (0.1e1 / (_t4 * _t4));
  const double _t17 = _t11*_t16;
  const double _t18 = -_t15 - _t17;
  const double _t24 = (0.1e1 / 0.6e1)*_t7;
  const double _t25 = xc_powr(_t4, -7, 3);
  const double _t26 = _t25*_t9;
  const double _t27 = (0.4e1 / 0.3e1)*_t26;
  const double _t31 = -_t12 - _t17;
  const double _t33 = (0.1e1 / _t9);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_den_k, _KMAX)(p, 0, _t10, _hc2);
  const double _t19 = _hc1[1]*_t13;
  const double _t20 = _t18*_t19;
  const double _t21 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t22 = _hc1[0]*_t21;
  const double _t23 = _hc2[2]*_t3;
  const double _t28 = _hc0[1]*_t27 + _t23*_t24;
  const double _t29 = _t28*_t4;
  const double _t30 = _t14 + _t22*_t29;
  const double _t32 = _t19*_t31;
  const double _t34 = _hc0[1]*_t33;
  const double _t35 = _t22*_t34;
  const double _t36 = -_t35*_t6;
  const double dF_dna = _t20*_t4 + _t30;
  const double dF_dnb = _t30 + _t32*_t4;
  const double dF_dgaa = _t36;
  const double dF_dgab = -_t35*_t5;
  const double dF_dgbb = _t36;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t37 = 0.2e1*_t16;
  const double _t38 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t39 = 0.2e1*_t38;
  const double _t40 = _t11*_t39;
  const double _t41 = -_t37 + _t40;
  const double _t43 = (_t18 * _t18);
  const double _t50 = _t24*_t3;
  const double _t52 = xc_powr(_t4, -10, 3);
  const double _t53 = _t52*_t9;
  const double _t54 = (0.28e2 / 0.9e1)*_t53;
  const double _t55 = (0.2e1 / 0.9e1)*_t25;
  const double _t58 = xc_powr(_t4, -11, 3);
  const double _t59 = _t58*_t9;
  const double _t64 = (0.8e1 / 0.3e1)*_t26;
  const double _t70 = 0.2e1*_t17;
  const double _t75 = _t37 + _t40;
  const double _t77 = (_t31 * _t31);
  const double _t86 = xc_powr(_t4, -8, 3);
  const double _t87 = (0.1e1 / 0.12e2)*_t86;
  const double _t95 = (0.1e1 / 0.6e1)*_t86;
  const double _t101 = xc_powr(_t8, -3, 2);
  const double _t105 = (0.1e1 / _t8);
  const double _t106 = xc_powr(_t4, -5, 3);
  const double _t107 = _t105*_t106;
  const double _t42 = _t19*_t41;
  const double _t44 = _hc1[2]*_t13;
  const double _t45 = _t43*_t44;
  const double _t46 = _hc1[1]*_t21;
  const double _t47 = _t18*_t29;
  const double _t48 = _t46*_t47;
  const double _t49 = 0.2e1*_t22;
  const double _t51 = -_hc0[3]*_t27 - _hc2[4]*_t50;
  const double _t56 = _hc2[4]*_t3;
  const double _t57 = (0.2e1 / 0.9e1)*_t56;
  const double _t60 = _hc0[1]*_t54 + _t23*_t55 + _t57*_t59;
  const double _t61 = (0.4e1 / 0.3e1)*_t25*_t51*_t9 - _t60;
  const double _t62 = _t22*_t4;
  const double _t63 = _t23*_t7;
  const double _t65 = _hc0[1]*_t64 + (0.1e1 / 0.3e1)*_t63;
  const double _t66 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t67 = _hc1[0]*_t66;
  const double _t68 = _t65*_t67;
  const double _t69 = _t28*_t49 + _t29*_t68 + _t61*_t62;
  const double _t71 = _t31*_t46;
  const double _t72 = _t29*_t71;
  const double _t73 = _t4*_t44;
  const double _t74 = _t18*_t73;
  const double _t76 = _t19*_t75;
  const double _t78 = _t44*_t77;
  const double _t79 = _t18*_t46;
  const double _t80 = _t34*_t6;
  const double _t81 = _hc0[3]*_t58;
  const double _t82 = (0.2e1 / 0.3e1)*_t81;
  const double _t83 = _hc0[1]*_t25;
  const double _t84 = _t33*_t83;
  const double _t85 = _t33*_t56;
  const double _t88 = _t82 + (0.2e1 / 0.3e1)*_t84 + _t85*_t87;
  const double _t89 = _t35*_t7;
  const double _t90 = _t34*_t5;
  const double _t91 = _t28*_t67;
  const double _t92 = -_hc1[0]*_t21*_t4*_t88 + (0.1e1 / 0.2e1)*_t89 + _t90*_t91;
  const double _t93 = -_t79*_t80 - _t92;
  const double _t94 = (0.4e1 / 0.3e1)*_t81;
  const double _t96 = (0.4e1 / 0.3e1)*_t84 + _t85*_t95 + _t94;
  const double _t97 = 0.2e1*_t28;
  const double _t98 = _t67*_t90;
  const double _t99 = -_hc1[0]*_t21*_t4*_t96 + _t89 + _t97*_t98;
  const double _t100 = -_t71*_t80 - _t92;
  const double _t102 = _hc0[1]*_t101;
  const double _t103 = _t102*_t22;
  const double _t104 = _t103*_t5;
  const double _t108 = _hc0[3]*_t22;
  const double _t109 = _t107*_t108;
  const double _t110 = ((_hc0[1]) * (_hc0[1]));
  const double _t111 = _t110*_t67;
  const double _t112 = _t107*_t111;
  const double _t113 = (0.1e1 / 0.4e1)*_t104 - 0.1e1 / 0.4e1*_t109 + (0.1e1 / 0.2e1)*_t112;
  const double _t114 = _t103*_t6 - 0.1e1 / 0.2e1*_t109 + _t112;
  const double d2F_dna2 = 0.2e1*_t20 + _t4*_t42 + _t4*_t45 + 0.2e1*_t48 + _t69;
  const double d2F_dna_dnb = _t19*_t70 + _t20 + _t31*_t74 + _t32 + _t48 + _t69 + _t72;
  const double d2F_dnb2 = 0.2e1*_t32 + _t4*_t76 + _t4*_t78 + _t69 + 0.2e1*_t72;
  const double d2F_dna_dgaa = _t93;
  const double d2F_dna_dgab = -_t79*_t90 - _t99;
  const double d2F_dna_dgbb = _t93;
  const double d2F_dnb_dgaa = _t100;
  const double d2F_dnb_dgab = -_t71*_t90 - _t99;
  const double d2F_dnb_dgbb = _t100;
  const double d2F_dgaa2 = _t113;
  const double d2F_dgaa_dgab = _t114;
  const double d2F_dgaa_dgbb = _t113;
  const double d2F_dgab2 = _t104 - _t109 + 0.2e1*_t112;
  const double d2F_dgab_dgbb = _t114;
  const double d2F_dgbb2 = _t113;
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
  const double _t115 = 0.6e1*_t38;
  const double _t116 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t117 = 0.6e1*_t116;
  const double _t118 = _t11*_t117;
  const double _t119 = _t115 - _t118;
  const double _t121 = (_t18 * _t18 * _t18);
  const double _t125 = 0.4e1*_t16;
  const double _t126 = 0.4e1*_t38;
  const double _t127 = _t11*_t126;
  const double _t128 = -_t125 + _t127;
  const double _t140 = (0.14e2 / 0.27e2)*_t52;
  const double _t142 = xc_powr(_t4, -13, 3);
  const double _t143 = (0.280e3 / 0.27e2)*_t142;
  const double _t144 = xc_powr(_t4, -14, 3);
  const double _t148 = (0.16e2 / 0.9e1)*_t8;
  const double _t150 = (0.56e2 / 0.9e1)*_t53;
  const double _t151 = _t3*_t55;
  const double _t170 = -_t118 + 0.2e1*_t38;
  const double _t176 = -_t11*_t16;
  const double _t177 = _t15 + _t176;
  const double _t178 = _t177*_t43;
  const double _t180 = 0.4e1*_t17;
  const double _t192 = _t12 + _t176;
  const double _t193 = _t192*_t77;
  const double _t195 = -_t115 - _t118;
  const double _t197 = (_t31 * _t31 * _t31);
  const double _t199 = _t125 + _t127;
  const double _t209 = _t33*_t52;
  const double _t212 = (0.2e1 / 0.3e1)*_t58;
  const double _t214 = _t25*_t33;
  const double _t215 = (0.2e1 / 0.3e1)*_t214;
  const double _t229 = (0.4e1 / 0.3e1)*_t58;
  const double _t231 = (0.4e1 / 0.3e1)*_t214;
  const double _t236 = _t33*_t58;
  const double _t240 = (0.1e1 / 0.3e1)*_t33;
  const double _t249 = _t18*_t31;
  const double _t265 = (0.1e1 / 0.3e1)*_t105;
  const double _t266 = xc_powi(_t4, -5);
  const double _t269 = (0.1e1 / 0.24e2)*_t101;
  const double _t273 = _t105*_t86;
  const double _t290 = (0.1e1 / 0.6e1)*_t105;
  const double _t298 = xc_powr(_t8, -5, 2);
  const double _t302 = (0.1e1 / (_t8 * _t8));
  const double _t303 = _t101*_t38;
  const double _t309 = _t106*_t302;
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_den_k, _KMAX)(p, 0, 0, _hc3);
  const double _t120 = _t119*_t19;
  const double _t122 = _hc1[3]*_t13;
  const double _t123 = _t121*_t122;
  const double _t124 = 0.6e1*_t28;
  const double _t129 = _t4*_t61;
  const double _t130 = _t129*_t79;
  const double _t131 = _t29*_t46;
  const double _t132 = _t131*_t41;
  const double _t133 = _t21*_t29;
  const double _t134 = _hc1[2]*_t43;
  const double _t135 = _t133*_t134;
  const double _t136 = _hc1[1]*_t66;
  const double _t137 = _t136*_t65;
  const double _t138 = _t137*_t47;
  const double _t139 = 0.3e1*_t22;
  const double _t141 = _hc0[1]*_t9;
  const double _t145 = _t56*_t9;
  const double _t146 = _t144*_t145;
  const double _t147 = _hc3[7]*_t144;
  const double _t149 = _hc2[4]*_t54 + _t147*_t148;
  const double _t152 = _hc3[7]*_t3;
  const double _t153 = (0.2e1 / 0.9e1)*_t152;
  const double _t154 = -_hc2[6]*_t27 - _hc3[7]*_t50;
  const double _t155 = _hc0[3]*_t54 + _hc2[4]*_t151 + _t153*_t59 - _t154*_t27;
  const double _t156 = _t140*_t23 + _t141*_t143 + (0.16e2 / 0.27e2)*_t146 + _t149*_t50 - _t150*_t51 + _t155*_t27;
  const double _t157 = 0.3e1*_t28;
  const double _t158 = _t23*_t25;
  const double _t159 = -_hc0[1]*_t150 - 0.4e1 / 0.9e1*_t158 + (0.8e1 / 0.3e1)*_t25*_t51*_t9 - 0.4e1 / 0.9e1*_t56*_t59;
  const double _t160 = _t29*_t67;
  const double _t161 = _t4*_t67;
  const double _t162 = _t161*_t65;
  const double _t163 = 0.2e1*_t162;
  const double _t164 = _t29*_t65;
  const double _t165 = 0.4e1*_hc0[1]*_t26 + (0.1e1 / 0.2e1)*_t63;
  const double _t166 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t167 = _hc1[0]*_t166;
  const double _t168 = _t165*_t167;
  const double _t169 = _t139*_t61 + _t156*_t62 + _t157*_t68 + _t159*_t160 + _t163*_t61 + _t164*_t168;
  const double _t171 = _t19*_t4;
  const double _t172 = 0.4e1*_t28;
  const double _t173 = _t129*_t71;
  const double _t174 = _t31*_t73;
  const double _t175 = _t122*_t4;
  const double _t179 = _t18*_t44;
  const double _t181 = _t136*_t31;
  const double _t182 = _t164*_t181;
  const double _t183 = 0.2e1*_t179;
  const double _t184 = _t17*_t46;
  const double _t185 = _hc1[2]*_t21;
  const double _t186 = _t185*_t47;
  const double _t187 = 0.2e1*_t186;
  const double _t188 = _t169 + _t172*_t184 + _t183*_t31 + _t187*_t31;
  const double _t189 = _t131*_t75;
  const double _t190 = _hc1[2]*_t77;
  const double _t191 = _t133*_t190;
  const double _t194 = _t31*_t44;
  const double _t196 = _t19*_t195;
  const double _t198 = _t122*_t197;
  const double _t200 = _t41*_t46;
  const double _t201 = _t134*_t21;
  const double _t202 = _t34*_t7;
  const double _t203 = _t202*_t79;
  const double _t204 = _t136*_t18;
  const double _t205 = _t204*_t90;
  const double _t206 = _t203 + _t205*_t97;
  const double _t207 = _hc0[3]*_t144;
  const double _t208 = (0.14e2 / 0.9e1)*_t207;
  const double _t210 = _hc0[1]*_t209;
  const double _t211 = _t58*_t85;
  const double _t213 = _hc3[7]*_t212;
  const double _t216 = -_hc2[4]*_t215 - _t213;
  const double _t217 = _hc2[6]*_t212;
  const double _t218 = _t152*_t33;
  const double _t219 = -_hc0[3]*_t215 - _t217 - _t218*_t87;
  const double _t220 = (0.1e1 / 0.6e1)*_t1*_t2*_t216*_t7 - _t208 - 0.14e2 / 0.9e1*_t210 - 0.1e1 / 0.9e1*_t211 + (0.4e1 / 0.3e1)*_t219*_t25*_t9 + (0.2e1 / 0.3e1)*_t25*_t33*_t51;
  const double _t221 = _t61*_t98;
  const double _t222 = _t67*_t97;
  const double _t223 = _t167*_t65;
  const double _t224 = _t28*_t90;
  const double _t225 = (0.3e1 / 0.2e1)*_t224;
  const double _t226 = -_hc1[0]*_t21*_t220*_t4 - 0.2e1*_hc1[0]*_t21*_t88 - _hc1[0]*_t28*_t4*_t66*_t96 - _hc1[0]*_t4*_t65*_t66*_t88 + _t202*_t222 + _t221 + _t223*_t225;
  const double _t227 = 0.2e1*_hc1[1]*_t18*_t21*_t4*_t88 - _t200*_t80 - _t201*_t80 - _t206 - _t226;
  const double _t228 = 0.2e1*_t79;
  const double _t230 = _hc2[6]*_t229;
  const double _t232 = -_hc0[3]*_t231 - _t218*_t95 - _t230;
  const double _t233 = _hc3[7]*_t229;
  const double _t234 = -_hc2[4]*_t231 - _t233;
  const double _t235 = (0.28e2 / 0.9e1)*_t207;
  const double _t237 = (0.28e2 / 0.9e1)*_t210 + _t235 + _t236*_t57 - 0.4e1 / 0.3e1*_t25*_t33*_t51;
  const double _t238 = (0.1e1 / 0.6e1)*_t1*_t2*_t234*_t7 + (0.4e1 / 0.3e1)*_t232*_t25*_t9 - _t237;
  const double _t239 = (0.8e1 / 0.3e1)*_t81;
  const double _t241 = _t56*_t86;
  const double _t242 = _t239 + _t240*_t241 + (0.8e1 / 0.3e1)*_t84;
  const double _t243 = _t172*_t67;
  const double _t244 = _t223*_t90;
  const double _t245 = -_hc1[0]*_t21*_t238*_t4 - 0.2e1*_hc1[0]*_t21*_t96 - _hc1[0]*_t242*_t28*_t4*_t66 - _hc1[0]*_t4*_t65*_t66*_t96 + _t157*_t244 + _t202*_t243 + 0.2e1*_t221;
  const double _t246 = _t210*_t46;
  const double _t247 = _t11*_t246;
  const double _t248 = _t202*_t71;
  const double _t250 = _t185*_t249;
  const double _t251 = _hc1[1]*_t18*_t21*_t4*_t88 + _hc1[1]*_t21*_t31*_t4*_t88 - _t181*_t224 - 0.1e1 / 0.2e1*_t203 - _t204*_t224 - _t226 - _t247 - 0.1e1 / 0.2e1*_t248 - _t250*_t80;
  const double _t252 = _t181*_t90;
  const double _t253 = _t248 + _t252*_t97;
  const double _t254 = _t46*_t75;
  const double _t255 = _t190*_t21;
  const double _t256 = 0.2e1*_hc1[1]*_t21*_t31*_t4*_t88 - _t226 - _t253 - _t254*_t80 - _t255*_t80;
  const double _t257 = 0.2e1*_t71;
  const double _t258 = _t107*_t110;
  const double _t259 = _t204*_t258;
  const double _t260 = _hc0[3]*_t107;
  const double _t261 = _t260*_t79;
  const double _t262 = _t102*_t5;
  const double _t263 = _t262*_t79;
  const double _t264 = _t101*_t83;
  const double _t267 = _hc2[6]*_t33;
  const double _t268 = _t266*_t267;
  const double _t270 = _t116*_t152;
  const double _t271 = _t105*_t270;
  const double _t272 = -_t241*_t269 - 0.1e1 / 0.3e1*_t264 + _t265*_t81 + (0.1e1 / 0.3e1)*_t268 + (0.1e1 / 0.24e2)*_t271;
  const double _t274 = _t111*_t273;
  const double _t275 = _t108*_t273;
  const double _t276 = _t103*_t7;
  const double _t277 = _t102*_t6;
  const double _t278 = 0.2e1*_t88;
  const double _t279 = -_t278*_t98;
  const double _t280 = _t260*_t91;
  const double _t281 = _t167*_t258;
  const double _t282 = (0.3e1 / 0.2e1)*_t281;
  const double _t283 = _t272*_t62 + (0.1e1 / 0.2e1)*_t274 - 0.1e1 / 0.4e1*_t275 + (0.1e1 / 0.4e1)*_t276 + _t277*_t91 + _t279 + _t28*_t282 - 0.1e1 / 0.2e1*_t280;
  const double _t284 = (0.1e1 / 0.2e1)*_t259 - 0.1e1 / 0.4e1*_t261 + (0.1e1 / 0.4e1)*_t263 + _t283;
  const double _t285 = _t101*_t56;
  const double _t286 = _t105*_t82 - 0.2e1 / 0.3e1*_t264 + (0.2e1 / 0.3e1)*_t268 + (0.1e1 / 0.12e2)*_t271 - _t285*_t87;
  const double _t287 = _t96*_t98;
  const double _t288 = _t157*_t281 + _t262*_t91 + _t274 - 0.1e1 / 0.2e1*_t275 + (0.1e1 / 0.2e1)*_t276 + _t279 - _t280 + _t286*_t62 - _t287;
  const double _t289 = _t259 - 0.1e1 / 0.2e1*_t261 + _t277*_t79 + _t288;
  const double _t291 = _t105*_t94 - 0.4e1 / 0.3e1*_t264 + (0.4e1 / 0.3e1)*_t268 + _t270*_t290 - _t285*_t95;
  const double _t292 = _t124*_t281 - _t222*_t260 + _t222*_t262 + 0.2e1*_t274 - _t275 + _t276 - 0.4e1*_t287 + _t291*_t62;
  const double _t293 = _t181*_t258;
  const double _t294 = _t260*_t71;
  const double _t295 = _t262*_t71;
  const double _t296 = _t283 + (0.1e1 / 0.2e1)*_t293 - 0.1e1 / 0.4e1*_t294 + (0.1e1 / 0.4e1)*_t295;
  const double _t297 = _t277*_t71 + _t288 + _t293 - 0.1e1 / 0.2e1*_t294;
  const double _t299 = _hc0[1]*_t298;
  const double _t300 = _t299*_t5;
  const double _t301 = _t22*_t300;
  const double _t304 = _hc2[6]*_t22;
  const double _t305 = _t303*_t304;
  const double _t306 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t307 = _t167*_t306;
  const double _t308 = _t303*_t307;
  const double _t310 = _t111*_t309;
  const double _t311 = (0.3e1 / 0.4e1)*_hc0[1]*_hc0[3]*_hc1[0]*_t101*_t38*_t66 + (0.3e1 / 0.8e1)*_hc0[3]*_hc1[0]*_t106*_t21*_t302 - 0.3e1 / 0.8e1*_t301 - 0.1e1 / 0.8e1*_t305 - 0.3e1 / 0.4e1*_t308 - 0.3e1 / 0.4e1*_t310;
  const double _t312 = (0.3e1 / 0.2e1)*_hc0[1]*_hc0[3]*_hc1[0]*_t101*_t38*_t66 + (0.3e1 / 0.4e1)*_hc0[3]*_hc1[0]*_t106*_t21*_t302 - 0.3e1 / 0.4e1*_t301 - 0.1e1 / 0.4e1*_t305 - 0.3e1 / 0.2e1*_t308 - 0.3e1 / 0.2e1*_t310;
  const double _t313 = 0.3e1*_hc0[1]*_hc0[3]*_hc1[0]*_t101*_t38*_t66 + (0.3e1 / 0.2e1)*_hc0[3]*_hc1[0]*_t106*_t21*_t302 - 0.3e1 / 0.2e1*_t301 - 0.1e1 / 0.2e1*_t305 - 0.3e1*_t308 - 0.3e1*_t310;
  const double _t314 = _t101*_t307;
  const double d3F_dna3 = _t120*_t4 + _t123*_t4 + _t124*_t79 + _t128*_t74 + 0.3e1*_t130 + 0.3e1*_t132 + 0.3e1*_t135 + 0.3e1*_t138 + _t169 + _t41*_t74 + 0.3e1*_t42 + 0.3e1*_t45;
  const double d3F_dna2_dnb = _t127*_t19 + 0.2e1*_t130 + _t132 + _t135 + 0.2e1*_t138 + _t170*_t171 + _t172*_t79 + _t173 + _t174*_t41 + _t175*_t178 + _t179*_t180 + _t182 + _t188 + _t42 + _t45 + _t71*_t97;
  const double d3F_dna_dnb2 = _t130 + _t138 + _t172*_t71 + 0.2e1*_t173 + _t175*_t193 + _t180*_t194 + 0.2e1*_t182 + _t188 + _t189 - _t19*_t37 - _t19*_t40 + _t191 + _t74*_t75 + _t76 + _t78 + _t79*_t97;
  const double d3F_dnb3 = _t124*_t71 + _t169 + 0.3e1*_t173 + _t174*_t199 + _t174*_t75 + 0.3e1*_t182 + 0.3e1*_t189 + 0.3e1*_t191 + _t196*_t4 + _t198*_t4 + 0.3e1*_t76 + 0.3e1*_t78;
  const double d3F_dna2_dgaa = _t227;
  const double d3F_dna2_dgab = 0.2e1*_hc1[1]*_t18*_t21*_t4*_t96 - _t172*_t205 - _t200*_t90 - _t201*_t90 - _t202*_t228 - _t245;
  const double d3F_dna2_dgbb = _t227;
  const double d3F_dna_dnb_dgaa = _t251;
  const double d3F_dna_dnb_dgab = _hc1[1]*_t18*_t21*_t4*_t96 + _hc1[1]*_t21*_t31*_t4*_t96 - _t206 - _t245 - 0.2e1*_t247 - _t250*_t90 - _t253;
  const double d3F_dna_dnb_dgbb = _t251;
  const double d3F_dnb2_dgaa = _t256;
  const double d3F_dnb2_dgab = 0.2e1*_hc1[1]*_t21*_t31*_t4*_t96 - _t172*_t252 - _t202*_t257 - _t245 - _t254*_t90 - _t255*_t90;
  const double d3F_dnb2_dgbb = _t256;
  const double d3F_dna_dgaa2 = _t284;
  const double d3F_dna_dgaa_dgab = _t289;
  const double d3F_dna_dgaa_dgbb = _t284;
  const double d3F_dna_dgab2 = 0.2e1*_t259 - _t261 + _t263 + _t292;
  const double d3F_dna_dgab_dgbb = _t289;
  const double d3F_dna_dgbb2 = _t284;
  const double d3F_dnb_dgaa2 = _t296;
  const double d3F_dnb_dgaa_dgab = _t297;
  const double d3F_dnb_dgaa_dgbb = _t296;
  const double d3F_dnb_dgab2 = _t292 + 0.2e1*_t293 - _t294 + _t295;
  const double d3F_dnb_dgab_dgbb = _t297;
  const double d3F_dnb_dgbb2 = _t296;
  const double d3F_dgaa3 = _t311;
  const double d3F_dgaa2_dgab = _t312;
  const double d3F_dgaa2_dgbb = _t311;
  const double d3F_dgaa_dgab2 = _t313;
  const double d3F_dgaa_dgab_dgbb = _t312;
  const double d3F_dgaa_dgbb2 = _t311;
  const double d3F_dgab3 = 0.6e1*_hc0[1]*_hc0[3]*_hc1[0]*_t101*_t38*_t66 + 0.3e1*_hc0[3]*_hc1[0]*_t106*_t21*_t302 - _t115*_t314 - _t139*_t300 - _t305 - 0.6e1*_t310;
  const double d3F_dgab2_dgbb = _t313;
  const double d3F_dgab_dgbb2 = _t312;
  const double d3F_dgbb3 = _t311;
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
  const double _t315 = 0.24e2*_t116;
  const double _t316 = 0.24e2*_t11*_t266;
  const double _t322 = 0.12e2*_t38;
  const double _t323 = 0.12e2*_t116;
  const double _t324 = _t11*_t323;
  const double _t326 = 0.6e1*_t16;
  const double _t327 = 0.6e1*na - 0.6e1*nb;
  const double _t329 = 0.4e1*na - 0.4e1*nb;
  const double _t330 = 0.2e1*na - 0.2e1*nb;
  const double _t331 = _t330*_t38 - _t37;
  const double _t353 = xc_powr(_t4, -17, 3);
  const double _t355 = _t143*_t9;
  const double _t356 = (0.28e2 / 0.3e1)*_t53;
  const double _t377 = 0.6e1*_t17;
  const double _t381 = _t11*_t322;
  const double _t401 = _t330*_t38 + _t37;
  const double _t412 = 0.3e1*_t75;
  const double _t415 = _t31*_t75;
  const double _t436 = (0.4e1 / 0.9e1)*_t25;
  const double _t437 = (0.14e2 / 0.9e1)*_t209;
  const double _t465 = (0.28e2 / 0.9e1)*_t209;
  const double _t557 = _t105*_t266;
  const double _t559 = _t101*_t25;
  const double _t560 = (0.1e1 / 0.3e1)*_t559;
  const double _t561 = _t265*_t58;
  const double _t576 = (0.2e1 / 0.3e1)*_t559;
  const double _t588 = (0.4e1 / 0.3e1)*_t559;
  const double _t634 = _t101*_t116;
  const double _t667 = _t106/(_t8 * _t8 * _t8);
  const double _t669 = _t142*_t302;
  const double _t671 = _t298*_t38;
  const double _t677 = (0.3e1 / 0.2e1)*_t669;
  const double _t317 = _hc1[4]*_t13*_t4;
  const double _t318 = _t128*_t179;
  const double _t319 = _t179*_t41;
  const double _t320 = _t61*_t79;
  const double _t321 = 0.12e2*_t28;
  const double _t325 = _t41*_t73;
  const double _t328 = _t175*_t43;
  const double _t332 = 0.4e1*_t156;
  const double _t333 = _t4*_t79;
  const double _t334 = _t119*_t131;
  const double _t335 = _hc1[3]*_t133;
  const double _t336 = _t121*_t335;
  const double _t337 = _t129*_t200;
  const double _t338 = _t4*(_t25*_t9*(-0.16e2 / 0.9e1*_hc0[3]*_t26 - _t57*_t7) - _t60);
  const double _t339 = _t201*_t338;
  const double _t340 = _t137*_t18;
  const double _t341 = _t136*_t47;
  const double _t342 = _t159*_t341;
  const double _t343 = _t128*_t186;
  const double _t344 = _t186*_t41;
  const double _t345 = _t136*_t164;
  const double _t346 = _t345*_t41;
  const double _t347 = _t164*_t66;
  const double _t348 = _t134*_t347;
  const double _t349 = _t129*_t340;
  const double _t350 = _hc1[1]*_t166;
  const double _t351 = _t47*_t65;
  const double _t352 = _t165*_t350*_t351;
  const double _t354 = _t149*_t3;
  const double _t357 = 0.8e1*_t61;
  const double _t358 = _t159*_t161;
  const double _t359 = 0.3e1*_t61;
  const double _t360 = _t168*_t65;
  const double _t361 = _t164*_t167;
  const double _t362 = _t168*_t29;
  const double _t363 = 0.3e1*_t129;
  const double _t364 = _hc1[0]/xc_powi((_hc0[0]), 5);
  const double _t365 = _t164*_t165;
  const double _t366 = 0.3e1*_t156*_t162 + _t159*_t243 + 0.2e1*_t159*_t362 + _t160*((0.560e3 / 0.27e2)*_t141*_t142 + (0.32e2 / 0.27e2)*_t146 + _t155*_t64 + (0.28e2 / 0.27e2)*_t23*_t52 + (0.1e1 / 0.3e1)*_t354*_t7 - 0.112e3 / 0.9e1*_t51*_t53) + _t172*_t360 + _t22*_t332 + _t357*_t68 + _t358*_t359 + _t360*_t363 + _t361*(-_hc0[1]*_t356 - _t145*_t212 - 0.2e1 / 0.3e1*_t158 + 0.4e1*_t25*_t51*_t9) + _t364*_t365*((0.16e2 / 0.3e1)*_hc0[1]*_t26 + (0.2e1 / 0.3e1)*_t63) + _t62*((0.1e1 / 0.6e1)*_t1*_t2*_t7*(-_hc2[4]*_t355 - 0.112e3 / 0.9e1*_hc3[7]*_t353*_t8) - 0.3640e4 / 0.81e2*_t141/xc_powr(_t4, 16, 3) - 0.140e3 / 0.81e2*_t142*_t23 + (0.280e3 / 0.9e1)*_t142*_t51*_t9 - 0.56e2 / 0.27e2*_t145*_t353 - _t155*_t356 - 0.2e1 / 0.3e1*_t25*_t354 + (0.4e1 / 0.3e1)*_t25*_t9*(-_hc0[3]*_t355 - _t140*_t56 - 0.10e2 / 0.9e1*_t147*_t3*_t9 + (0.56e2 / 0.9e1)*_t154*_t52*_t9 - _t27*(_hc2[10]*_t144*_t148 + _hc2[6]*_t54 + _hc3[7]*_t151)));
  const double _t367 = _t170*_t19;
  const double _t368 = _t61*_t71;
  const double _t369 = _t194*_t41;
  const double _t370 = _t122*_t178;
  const double _t371 = _t156*_t4;
  const double _t372 = _t371*_t71;
  const double _t373 = _t44*_t70;
  const double _t374 = _t181*_t65;
  const double _t375 = _t371*_t79;
  const double _t376 = _t131*_t170;
  const double _t378 = _t122*_t377;
  const double _t379 = 0.9e1*_t28;
  const double _t380 = _t28*_t46;
  const double _t382 = _t181*_t29;
  const double _t383 = _t159*_t382;
  const double _t384 = _t175*_t249;
  const double _t385 = _t129*_t374;
  const double _t386 = _hc1[2]*_t133;
  const double _t387 = _t31*_t386;
  const double _t388 = _t387*_t41;
  const double _t389 = _t178*_t335;
  const double _t390 = _t17*_t185;
  const double _t391 = _t18*_t321;
  const double _t392 = _t31*_t350;
  const double _t393 = _t365*_t392;
  const double _t394 = 0.6e1*_t61;
  const double _t395 = _t137*_t17;
  const double _t396 = _hc1[2]*_t31*_t351*_t66;
  const double _t397 = _t124*_t250 + _t124*_t395 + _t184*_t394 + _t250*_t363 + _t366 + 0.3e1*_t396;
  const double _t398 = _t122*_t193;
  const double _t399 = _t129*_t254;
  const double _t400 = _t255*_t338;
  const double _t402 = _t175*_t77;
  const double _t403 = 0.2e1*_t174;
  const double _t404 = _t11*_t194;
  const double _t405 = 0.8e1*_t28;
  const double _t406 = _t345*_t75;
  const double _t407 = _t190*_t347;
  const double _t408 = _t193*_t335;
  const double _t409 = _t390*_t405;
  const double _t410 = _t194*_t75;
  const double _t411 = _t194*_t199;
  const double _t413 = _t131*_t195;
  const double _t414 = _t197*_t335;
  const double _t416 = _t386*_t415;
  const double _t417 = _t199*_t387;
  const double _t418 = _t4*_t71;
  const double _t419 = _t46*_t80;
  const double _t420 = _hc1[3]*_t21;
  const double _t421 = _t420*_t80;
  const double _t422 = _t200*_t202;
  const double _t423 = _t201*_t202;
  const double _t424 = _t18*_t185;
  const double _t425 = _t424*_t80;
  const double _t426 = _t157*_t90;
  const double _t427 = _t136*_t41;
  const double _t428 = _t134*_t66;
  const double _t429 = _t202*_t204;
  const double _t430 = _t18*_t350;
  const double _t431 = _t430*_t65;
  const double _t432 = (0.9e1 / 0.2e1)*_t224;
  const double _t433 = _hc0[3]*_t353;
  const double _t434 = _t142*_t34;
  const double _t435 = _t144*_t85;
  const double _t438 = _t209*_t51;
  const double _t439 = _hc2[6]*_t144;
  const double _t440 = -_t150*_t219 + _t155*_t215 - _t216*_t3*_t436 + _t27*(_hc0[3]*_t437 + _t153*_t236 - _t154*_t215 - _t27*(-_hc2[10]*_t212 - _hc2[6]*_t215) + (0.14e2 / 0.9e1)*_t439) + (0.140e3 / 0.27e2)*_t433 + (0.140e3 / 0.27e2)*_t434 + (0.7e1 / 0.27e2)*_t435 - 0.28e2 / 0.9e1*_t438 + _t50*(_hc2[4]*_t437 + (0.10e2 / 0.3e1)*_t147);
  const double _t441 = (0.1e1 / 0.3e1)*_t1*_t2*_t216*_t7 + (0.8e1 / 0.3e1)*_t219*_t25*_t9 - _t237;
  const double _t442 = _t156*_t98;
  const double _t443 = 0.2e1*_t81;
  const double _t444 = _t85*_t86;
  const double _t445 = _t443 + (0.1e1 / 0.4e1)*_t444 + 0.2e1*_t84;
  const double _t446 = _t202*_t67;
  const double _t447 = _t359*_t446;
  const double _t448 = _t244*_t359;
  const double _t449 = _t159*_t167;
  const double _t450 = _t225*_t449;
  const double _t451 = _t167*_t28;
  const double _t452 = _t202*_t65;
  const double _t453 = (0.9e1 / 0.2e1)*_t451*_t452;
  const double _t454 = _t90*_t97;
  const double _t455 = _t165*_t364*_t65;
  const double _t456 = _t454*_t455;
  const double _t457 = -_hc1[0]*_t159*_t4*_t66*_t88 - _hc1[0]*_t165*_t166*_t28*_t4*_t96 - _hc1[0]*_t165*_t166*_t4*_t65*_t88 - _hc1[0]*_t166*_t28*_t4*_t445*_t65 - 0.3e1*_hc1[0]*_t21*_t220 - _hc1[0]*_t21*_t4*_t440 - 0.2e1*_hc1[0]*_t220*_t4*_t65*_t66 - _hc1[0]*_t28*_t4*_t441*_t66 - 0.3e1*_hc1[0]*_t28*_t66*_t96 - 0.2e1*_hc1[0]*_t4*_t61*_t66*_t96 - 0.3e1*_hc1[0]*_t65*_t66*_t88 + _t442 + _t447 + _t448 + _t450 + _t453 + _t456;
  const double _t458 = 0.3e1*_hc1[1]*_t18*_t21*_t220*_t4 + 0.6e1*_hc1[1]*_t18*_t21*_t88 + 0.3e1*_hc1[1]*_t18*_t28*_t4*_t66*_t96 + 0.3e1*_hc1[1]*_t18*_t4*_t65*_t66*_t88 + 0.3e1*_hc1[1]*_t21*_t4*_t41*_t88 + 0.3e1*_hc1[2]*_t21*_t4*_t43*_t88 - _t119*_t419 - _t121*_t421 - _t124*_t429 - _t128*_t425 - _t205*_t359 - _t41*_t425 - 0.3e1 / 0.2e1*_t422 - 0.3e1 / 0.2e1*_t423 - _t426*_t427 - _t426*_t428 - _t431*_t432 - _t457;
  const double _t459 = _t46*_t90;
  const double _t460 = _t420*_t90;
  const double _t461 = _t185*_t90;
  const double _t462 = _t18*_t461;
  const double _t463 = _t124*_t90;
  const double _t464 = _t379*_t90;
  const double _t466 = _t143*_t34 - _t150*_t232 + _t155*_t231 - _t234*_t3*_t436 + _t27*(_hc0[3]*_t465 - _t154*_t231 + (0.4e1 / 0.9e1)*_t218*_t58 - _t27*(-_hc2[10]*_t229 - _hc2[6]*_t231) + (0.28e2 / 0.9e1)*_t439) + (0.280e3 / 0.27e2)*_t433 + (0.14e2 / 0.27e2)*_t435 - 0.56e2 / 0.9e1*_t438 + _t50*(_hc2[4]*_t465 + (0.20e2 / 0.3e1)*_t147);
  const double _t467 = (0.1e1 / 0.3e1)*_t1*_t2*_t234*_t7 - 0.56e2 / 0.9e1*_t207 - 0.56e2 / 0.9e1*_t210 - 0.4e1 / 0.9e1*_t211 + (0.8e1 / 0.3e1)*_t232*_t25*_t9 + (0.8e1 / 0.3e1)*_t25*_t33*_t51;
  const double _t468 = 0.4e1*_t81;
  const double _t469 = (0.1e1 / 0.2e1)*_t444 + _t468 + 0.4e1*_t84;
  const double _t470 = 0.2e1*_t442;
  const double _t471 = _t394*_t446;
  const double _t472 = _t426*_t449;
  const double _t473 = _t244*_t394;
  const double _t474 = _t167*_t379;
  const double _t475 = _t452*_t474;
  const double _t476 = _t172*_t90;
  const double _t477 = _t455*_t476;
  const double _t478 = -_hc1[0]*_t159*_t4*_t66*_t96 - _hc1[0]*_t165*_t166*_t242*_t28*_t4 - _hc1[0]*_t165*_t166*_t4*_t65*_t96 - _hc1[0]*_t166*_t28*_t4*_t469*_t65 - 0.3e1*_hc1[0]*_t21*_t238 - _hc1[0]*_t21*_t4*_t466 - 0.2e1*_hc1[0]*_t238*_t4*_t65*_t66 - 0.3e1*_hc1[0]*_t242*_t28*_t66 - 0.2e1*_hc1[0]*_t242*_t4*_t61*_t66 - _hc1[0]*_t28*_t4*_t467*_t66 - 0.3e1*_hc1[0]*_t65*_t66*_t96 + _t470 + _t471 + _t472 + _t473 + _t475 + _t477;
  const double _t479 = _t11*_t46;
  const double _t480 = _t434*_t479;
  const double _t481 = 0.2e1*_t480;
  const double _t482 = _t61*_t90;
  const double _t483 = _t181*_t482;
  const double _t484 = _t136*_t224;
  const double _t485 = _t224*_t66;
  const double _t486 = _t202*_t250;
  const double _t487 = _t185*_t31;
  const double _t488 = _t487*_t80;
  const double _t489 = _t181*_t202;
  const double _t490 = 0.2e1*_t61;
  const double _t491 = _t205*_t490;
  const double _t492 = _t11*_t210;
  const double _t493 = _t424*_t492;
  const double _t494 = _t11*_t136;
  const double _t495 = _t210*_t494;
  const double _t496 = _t172*_t495;
  const double _t497 = _t172*_t429;
  const double _t498 = _hc1[2]*_t249;
  const double _t499 = _t498*_t66;
  const double _t500 = _t454*_t499;
  const double _t501 = _t426*_t431;
  const double _t502 = _t392*_t65;
  const double _t503 = 0.4e1*_hc1[1]*_t11*_t16*_t21*_t88 + 0.2e1*_hc1[1]*_t18*_t21*_t220*_t4 + 0.4e1*_hc1[1]*_t18*_t21*_t88 + 0.2e1*_hc1[1]*_t18*_t28*_t4*_t66*_t96 + 0.2e1*_hc1[1]*_t18*_t4*_t65*_t66*_t88 + _hc1[1]*_t21*_t220*_t31*_t4 + 0.2e1*_hc1[1]*_t21*_t31*_t88 + _hc1[1]*_t21*_t4*_t41*_t88 + _hc1[1]*_t28*_t31*_t4*_t66*_t96 + _hc1[1]*_t31*_t4*_t65*_t66*_t88 + 0.2e1*_hc1[2]*_t18*_t21*_t31*_t4*_t88 + _hc1[2]*_t21*_t4*_t43*_t88 - _t134*_t485 - _t170*_t419 - _t178*_t421 - _t225*_t502 - _t41*_t484 - _t41*_t488 - 0.1e1 / 0.2e1*_t422 - 0.1e1 / 0.2e1*_t423 - _t457 - _t481 - _t483 - _t486 - _t489*_t97 - _t491 - 0.2e1*_t493 - _t496 - _t497 - _t500 - _t501;
  const double _t504 = _t31*_t461;
  const double _t505 = _t252*_t490;
  const double _t506 = 0.2e1*_t250;
  const double _t507 = _t202*_t506;
  const double _t508 = _t172*_t489;
  const double _t509 = _t204*_t482;
  const double _t510 = _t405*_t495;
  const double _t511 = _t426*_t502;
  const double _t512 = _t476*_t499;
  const double _t513 = _t202*_t254;
  const double _t514 = _t202*_t255;
  const double _t515 = _t487*_t492;
  const double _t516 = 0.4e1*_t184;
  const double _t517 = 0.4e1*_t71;
  const double _t518 = _t4*_t88;
  const double _t519 = _t157*_t67;
  const double _t520 = 0.3e1*_t68;
  const double _t521 = _t161*_t96;
  const double _t522 = _t257*_t4;
  const double _t523 = _t139*_t220 + _t160*_t441 + _t163*_t220 - _t190*_t485 - _t193*_t421 + _t220*_t333 + _t220*_t522 - _t225*_t431 + _t228*_t88 + _t246 + _t254*_t518 + _t255*_t518 + _t340*_t518 + _t341*_t96 + _t358*_t88 + _t360*_t518 + _t361*_t445 + _t362*_t96 + 0.2e1*_t374*_t518 + 0.2e1*_t382*_t96 - _t425*_t75 - _t429*_t97 + _t440*_t62 - _t442 - _t447 - _t448 - _t450 - _t453 - _t456 + _t480 - _t484*_t75 - _t486 + _t490*_t521 - _t496 - _t500 - _t505 + _t506*_t518 - _t508 - _t509 - _t511 - 0.1e1 / 0.2e1*_t513 - 0.1e1 / 0.2e1*_t514 - 0.2e1*_t515 + _t516*_t88 + _t517*_t88 + _t519*_t96 + _t520*_t88;
  const double _t524 = _t136*_t75;
  const double _t525 = _t190*_t66;
  const double _t526 = _t4*_t96;
  const double _t527 = _t161*_t242;
  const double _t528 = 0.3e1*_hc1[1]*_t21*_t220*_t31*_t4 + 0.6e1*_hc1[1]*_t21*_t31*_t88 + 0.3e1*_hc1[1]*_t21*_t4*_t75*_t88 + 0.3e1*_hc1[1]*_t28*_t31*_t4*_t66*_t96 + 0.3e1*_hc1[1]*_t31*_t4*_t65*_t66*_t88 + 0.3e1*_hc1[2]*_t21*_t4*_t77*_t88 - _t124*_t489 - _t185*_t415*_t80 - _t195*_t419 - _t197*_t421 - _t199*_t488 - _t252*_t359 - _t426*_t524 - _t426*_t525 - _t432*_t502 - _t457 - 0.3e1 / 0.2e1*_t513 - 0.3e1 / 0.2e1*_t514;
  const double _t529 = _t228*_t4;
  const double _t530 = _t136*_t258;
  const double _t531 = _t41*_t530;
  const double _t532 = _t258*_t66;
  const double _t533 = _t134*_t532;
  const double _t534 = _t200*_t260;
  const double _t535 = _t201*_t260;
  const double _t536 = _t200*_t262;
  const double _t537 = _t201*_t262;
  const double _t538 = 0.4e1*_t88;
  const double _t539 = 0.2e1*_t98;
  const double _t540 = _t90*_t96;
  const double _t541 = -_t157*_t167*_t540 - _t220*_t539 - 0.3e1*_t244*_t88 - _t446*_t538;
  const double _t542 = -_t205*_t538 + _t541;
  const double _t543 = _t110*_t273;
  const double _t544 = _t204*_t543;
  const double _t545 = _t102*_t7;
  const double _t546 = _t545*_t79;
  const double _t547 = _hc0[3]*_t273;
  const double _t548 = _t547*_t79;
  const double _t549 = _t204*_t28;
  const double _t550 = _t260*_t549;
  const double _t551 = _t258*_t430;
  const double _t552 = _t157*_t551 + _t262*_t549 + _t544 + (0.1e1 / 0.2e1)*_t546 - 0.1e1 / 0.2e1*_t548 - _t550;
  const double _t553 = _t102*_t52;
  const double _t554 = _t105*_t207;
  const double _t555 = _t267/xc_powi(_t4, 6);
  const double _t556 = _t285*_t58;
  const double _t558 = _t152*_t557;
  const double _t562 = _t219*_t231;
  const double _t563 = _hc2[10]*_t266;
  const double _t564 = _t61*_t67;
  const double _t565 = _t167*_t543;
  const double _t566 = _t260*_t564;
  const double _t567 = _t157*_t364;
  const double _t568 = _t258*_t65;
  const double _t569 = _t451*_t65;
  const double _t570 = (0.3e1 / 0.4e1)*_t569;
  const double _t571 = _t157*_t565 + _t160*_t286 + _t162*_t272 - _t260*_t570 + _t262*_t570 + _t272*_t49 + _t277*_t564 + _t278*_t521 + _t282*_t61 + _t545*_t91 - _t547*_t91 - 0.1e1 / 0.2e1*_t566 + _t567*_t568 + _t62*(_t27*(_hc0[3]*_t560 - _hc2[6]*_t561 + _t152*_t269*_t86 - _t240*_t563) + _t50*(_hc2[4]*_t560 - _hc3[7]*_t561) - _t51*_t560 + (0.7e1 / 0.9e1)*_t553 - 0.7e1 / 0.9e1*_t554 - 0.7e1 / 0.9e1*_t555 + (0.1e1 / 0.18e2)*_t556 - 0.1e1 / 0.18e2*_t558 + _t562);
  const double _t572 = _t272*_t529 + (0.1e1 / 0.2e1)*_t531 + (0.1e1 / 0.2e1)*_t533 - 0.1e1 / 0.4e1*_t534 - 0.1e1 / 0.4e1*_t535 + (0.1e1 / 0.4e1)*_t536 + (0.1e1 / 0.4e1)*_t537 + _t542 + _t552 + _t571;
  const double _t573 = 0.2e1*_t96;
  const double _t574 = _t204*_t97;
  const double _t575 = _t124*_t551 - _t260*_t574 + _t262*_t574 + 0.2e1*_t544 + _t546 - _t548;
  const double _t577 = _t33*_t563;
  const double _t578 = _t101*_t152;
  const double _t579 = _t238*_t98;
  const double _t580 = _t364*_t568;
  const double _t581 = _t167*_t242;
  const double _t582 = _t223*_t540;
  const double _t583 = (0.3e1 / 0.2e1)*_t569;
  const double _t584 = _t124*_t565 + _t124*_t580 + _t160*_t291 + _t161*(_t96 * _t96) + _t162*_t286 + _t222*_t545 - _t222*_t547 - _t225*_t581 - _t260*_t583 + _t262*_t564 + _t262*_t583 + _t281*_t359 + _t286*_t49 - _t446*_t573 + _t527*_t88 - _t566 - _t579 - 0.3e1 / 0.2e1*_t582 + _t62*(-_t105*_t208 + _t215*_t232 + _t27*(_hc0[3]*_t576 - _t105*_t217 - 0.2e1 / 0.3e1*_t577 + _t578*_t87) + _t50*(_hc2[4]*_t576 - _t105*_t213) - _t51*_t576 + (0.14e2 / 0.9e1)*_t553 - 0.14e2 / 0.9e1*_t555 + (0.1e1 / 0.9e1)*_t556 - 0.1e1 / 0.9e1*_t558 + _t562);
  const double _t585 = _t200*_t277 + _t201*_t277 - _t205*_t573 + _t286*_t529 + _t531 + _t533 - 0.1e1 / 0.2e1*_t534 - 0.1e1 / 0.2e1*_t535 + _t542 + _t575 + _t584;
  const double _t586 = 0.8e1*_t96;
  const double _t587 = _t172*_t204;
  const double _t589 = _t490*_t67;
  const double _t590 = _t157*_t223;
  const double _t591 = _t160*(-0.1e1 / 0.3e1*_t101*_t241 + _t105*_t239 - 0.8e1 / 0.3e1*_t264 + _t265*_t270 + (0.8e1 / 0.3e1)*_t268) + _t162*_t291 + _t243*_t545 - _t243*_t547 - _t260*_t589 - _t260*_t590 + _t262*_t589 + _t262*_t590 + _t281*_t394 + _t291*_t49 + _t321*_t565 + _t321*_t580 - _t446*_t586 - _t463*_t581 + _t527*_t573 - 0.4e1*_t579 - 0.6e1*_t582 + _t62*(_t101*_t57*_t58 - _t105*_t235 - _t153*_t557 + (0.8e1 / 0.3e1)*_t214*_t232 + _t27*(_hc0[3]*_t588 - _t105*_t230 - 0.4e1 / 0.3e1*_t577 + _t578*_t95) + _t50*(_hc2[4]*_t588 - _t105*_t233) - _t51*_t588 + (0.28e2 / 0.9e1)*_t553 - 0.28e2 / 0.9e1*_t555);
  const double _t592 = _t105*_t110*_t144*_t494;
  const double _t593 = _t479*_t553;
  const double _t594 = _t181*_t543;
  const double _t595 = _t479*_t554;
  const double _t596 = _t547*_t71;
  const double _t597 = _t545*_t71;
  const double _t598 = _t181*_t28;
  const double _t599 = _t498*_t532;
  const double _t600 = _t260*_t598;
  const double _t601 = _t250*_t260;
  const double _t602 = _t250*_t262;
  const double _t603 = (0.3e1 / 0.2e1)*_t28;
  const double _t604 = _t258*_t392;
  const double _t605 = -_t205*_t278 - _t252*_t278 + _t541;
  const double _t606 = _t272*_t333 + _t272*_t418 + _t277*_t549 + _t277*_t598 + (0.1e1 / 0.2e1)*_t544 + (0.1e1 / 0.4e1)*_t546 - 0.1e1 / 0.4e1*_t548 - 0.1e1 / 0.2e1*_t550 + _t551*_t603 + _t571 + _t592 + (0.1e1 / 0.2e1)*_t593 + (0.1e1 / 0.2e1)*_t594 - 0.1e1 / 0.2e1*_t595 - 0.1e1 / 0.4e1*_t596 + (0.1e1 / 0.4e1)*_t597 + (0.1e1 / 0.2e1)*_t599 - 0.1e1 / 0.2e1*_t600 - 0.1e1 / 0.4e1*_t601 + (0.1e1 / 0.4e1)*_t602 + _t603*_t604 + _t605;
  const double _t607 = _t204*_t540;
  const double _t608 = _t181*_t540;
  const double _t609 = _t157*_t604 + _t262*_t598 + _t594 - 0.1e1 / 0.2e1*_t596 + (0.1e1 / 0.2e1)*_t597 - _t600;
  const double _t610 = _t250*_t277 + _t286*_t333 + _t286*_t418 + _t552 + _t584 + 0.2e1*_t592 + _t593 - _t595 + _t599 - 0.1e1 / 0.2e1*_t601 + _t605 - _t607 - _t608 + _t609;
  const double _t611 = _t181*_t97;
  const double _t612 = _t124*_t604 - _t260*_t611 + _t262*_t611 + 0.2e1*_t594 - _t596 + _t597;
  const double _t613 = _t530*_t75;
  const double _t614 = _t190*_t532;
  const double _t615 = _t254*_t260;
  const double _t616 = _t255*_t260;
  const double _t617 = _t254*_t262;
  const double _t618 = _t255*_t262;
  const double _t619 = -_t252*_t538 + _t541;
  const double _t620 = _t272*_t522 + _t571 + _t609 + (0.1e1 / 0.2e1)*_t613 + (0.1e1 / 0.2e1)*_t614 - 0.1e1 / 0.4e1*_t615 - 0.1e1 / 0.4e1*_t616 + (0.1e1 / 0.4e1)*_t617 + (0.1e1 / 0.4e1)*_t618 + _t619;
  const double _t621 = -_t252*_t573 + _t254*_t277 + _t255*_t277 + _t286*_t522 + _t584 + _t612 + _t613 + _t614 - 0.1e1 / 0.2e1*_t615 - 0.1e1 / 0.2e1*_t616 + _t619;
  const double _t622 = _t172*_t181;
  const double _t623 = _hc2[6]*_t303;
  const double _t624 = _t623*_t79;
  const double _t625 = _t303*_t306;
  const double _t626 = (0.3e1 / 0.4e1)*_t625;
  const double _t627 = _t110*_t309;
  const double _t628 = _t204*_t627;
  const double _t629 = _t298*_t83;
  const double _t630 = _t302*_t81;
  const double _t631 = _hc2[10]/xc_powr(_t4, 19, 3);
  const double _t632 = _t241*_t298;
  const double _t633 = _t270*_t302;
  const double _t635 = _t304*_t634;
  const double _t636 = _t307*_t634;
  const double _t637 = _t111*_t302*_t86;
  const double _t638 = _t299*_t7;
  const double _t639 = _t22*_t638;
  const double _t640 = _t623*_t91;
  const double _t641 = _t260*_t67;
  const double _t642 = _t300*_t91;
  const double _t643 = -0.3e1 / 0.4e1*_hc0[1]*_hc0[3]*_hc1[0]*_t101*_t116*_t66 - 0.9e1 / 0.4e1*_hc0[1]*_hc0[3]*_hc1[0]*_t101*_t166*_t28*_t38 - 0.3e1 / 0.2e1*_hc0[1]*_hc1[0]*_t101*_t5*_t66*_t88 - 0.3e1 / 0.4e1*_hc0[3]*_hc1[0]*_t106*_t28*_t302*_t66 - 0.3e1 / 0.8e1*_hc0[3]*_hc1[0]*_t21*_t302*_t86 - 0.9e1 / 0.2e1*_hc1[0]*_t105*_t106*_t110*_t166*_t88 - _hc1[0]*_t21*_t4*(_t290*_t631 + (0.1e1 / 0.2e1)*_t629 - 0.1e1 / 0.2e1*_t630 + (0.1e1 / 0.16e2)*_t632 - 0.1e1 / 0.16e2*_t633) + 0.3e1*_t272*_t98 + (0.9e1 / 0.4e1)*_t451*_t627 + _t567*_t625 + (0.1e1 / 0.8e1)*_t635 + (0.3e1 / 0.4e1)*_t636 + (0.3e1 / 0.4e1)*_t637 + (0.3e1 / 0.8e1)*_t639 + (0.1e1 / 0.4e1)*_t640 + (0.3e1 / 0.2e1)*_t641*_t88 + (0.3e1 / 0.4e1)*_t642;
  const double _t644 = (0.3e1 / 0.4e1)*_hc0[1]*_hc0[3]*_hc1[1]*_t101*_t18*_t38*_t66 + (0.3e1 / 0.8e1)*_hc0[3]*_hc1[1]*_t106*_t18*_t21*_t302 - 0.3e1 / 0.8e1*_t300*_t79 - _t430*_t626 - 0.1e1 / 0.8e1*_t624 - 0.3e1 / 0.4e1*_t628 - _t643;
  const double _t645 = _t430*_t625;
  const double _t646 = _t300*_t79;
  const double _t647 = _t641*_t96;
  const double _t648 = _t28*_t364;
  const double _t649 = _t101*_t115*_t306;
  const double _t650 = _t451*_t627;
  const double _t651 = -0.2e1*_hc0[1]*_hc1[0]*_t101*_t5*_t66*_t88 - 0.6e1*_hc1[0]*_t105*_t106*_t110*_t166*_t88 + _t278*_t641;
  const double _t652 = -0.3e1 / 0.2e1*_hc0[1]*_hc0[3]*_hc1[0]*_t101*_t116*_t66 - 0.9e1 / 0.2e1*_hc0[1]*_hc0[3]*_hc1[0]*_t101*_t166*_t28*_t38 - 0.1e1 / 0.2e1*_hc0[1]*_hc1[0]*_t101*_t5*_t66*_t96 - 0.3e1 / 0.2e1*_hc0[3]*_hc1[0]*_t106*_t28*_t302*_t66 - 0.3e1 / 0.4e1*_hc0[3]*_hc1[0]*_t21*_t302*_t86 - 0.3e1 / 0.2e1*_hc1[0]*_t105*_t106*_t110*_t166*_t96 - _hc1[0]*_t21*_t4*(_t265*_t631 + _t629 - _t630 + (0.1e1 / 0.8e1)*_t632 - 0.1e1 / 0.8e1*_t633) + _t272*_t539 + _t286*_t539 + (0.1e1 / 0.4e1)*_t635 + (0.3e1 / 0.2e1)*_t636 + (0.3e1 / 0.2e1)*_t637 + (0.3e1 / 0.4e1)*_t639 + (0.1e1 / 0.2e1)*_t640 + (0.3e1 / 0.2e1)*_t642 + (0.1e1 / 0.2e1)*_t647 + _t648*_t649 + (0.9e1 / 0.2e1)*_t650 + _t651;
  const double _t653 = (0.3e1 / 0.2e1)*_hc0[1]*_hc0[3]*_hc1[1]*_t101*_t18*_t38*_t66 + (0.3e1 / 0.4e1)*_hc0[3]*_hc1[1]*_t106*_t18*_t21*_t302 - 0.1e1 / 0.4e1*_t624 - 0.3e1 / 0.2e1*_t628 - 0.3e1 / 0.2e1*_t645 - 0.3e1 / 0.4e1*_t646 - _t652;
  const double _t654 = _t105*_t631;
  const double _t655 = _t291*_t98;
  const double _t656 = -0.3e1*_hc0[1]*_hc0[3]*_hc1[0]*_t101*_t116*_t66 - 0.9e1*_hc0[1]*_hc0[3]*_hc1[0]*_t101*_t166*_t28*_t38 - 0.2e1*_hc0[1]*_hc1[0]*_t101*_t5*_t66*_t96 - 0.3e1*_hc0[3]*_hc1[0]*_t106*_t28*_t302*_t66 - 0.3e1 / 0.2e1*_hc0[3]*_hc1[0]*_t21*_t302*_t86 - 0.6e1*_hc1[0]*_t105*_t106*_t110*_t166*_t96 - _hc1[0]*_t21*_t4*(-_t302*_t443 + 0.2e1*_t629 + (0.1e1 / 0.4e1)*_t632 - 0.1e1 / 0.4e1*_t633 + (0.2e1 / 0.3e1)*_t654) + _t101*_t306*_t322*_t648 + 0.4e1*_t286*_t98 + _t300*_t519 + _t474*_t627 + _t573*_t641 + (0.1e1 / 0.2e1)*_t635 + 0.3e1*_t636 + 0.3e1*_t637 + (0.3e1 / 0.2e1)*_t639 + _t640 + _t651 + _t655;
  const double _t657 = 0.3e1*_hc0[1]*_hc0[3]*_hc1[1]*_t101*_t18*_t38*_t66 + (0.3e1 / 0.2e1)*_hc0[3]*_hc1[1]*_t106*_t18*_t21*_t302 - 0.1e1 / 0.2e1*_t624 - 0.3e1*_t628 - 0.3e1*_t645 - 0.3e1 / 0.2e1*_t646 - _t656;
  const double _t658 = -0.6e1*_hc0[1]*_hc0[3]*_hc1[0]*_t101*_t116*_t66 - 0.18e2*_hc0[1]*_hc0[3]*_hc1[0]*_t101*_t166*_t28*_t38 - 0.6e1*_hc0[1]*_hc1[0]*_t101*_t5*_t66*_t96 - 0.6e1*_hc0[3]*_hc1[0]*_t106*_t28*_t302*_t66 - 0.3e1*_hc0[3]*_hc1[0]*_t21*_t302*_t86 - 0.18e2*_hc1[0]*_t105*_t106*_t110*_t166*_t96 - _hc1[0]*_t21*_t4*(-_t302*_t468 + 0.4e1*_t629 + (0.1e1 / 0.2e1)*_t632 - 0.1e1 / 0.2e1*_t633 + (0.4e1 / 0.3e1)*_t654) + _hc2[6]*_t101*_t39*_t91 + _t117*_t314 + _t124*_t300*_t67 + _t139*_t638 + 0.24e2*_t625*_t648 + _t635 + 0.6e1*_t637 + 0.6e1*_t647 + 0.18e2*_t650 + 0.6e1*_t655;
  const double _t659 = _t623*_t71;
  const double _t660 = _t181*_t627;
  const double _t661 = (0.3e1 / 0.4e1)*_hc0[1]*_hc0[3]*_hc1[1]*_t101*_t31*_t38*_t66 + (0.3e1 / 0.8e1)*_hc0[3]*_hc1[1]*_t106*_t21*_t302*_t31 - 0.3e1 / 0.8e1*_t300*_t71 - _t392*_t626 - _t643 - 0.1e1 / 0.8e1*_t659 - 0.3e1 / 0.4e1*_t660;
  const double _t662 = _t392*_t625;
  const double _t663 = _t300*_t71;
  const double _t664 = (0.3e1 / 0.2e1)*_hc0[1]*_hc0[3]*_hc1[1]*_t101*_t31*_t38*_t66 + (0.3e1 / 0.4e1)*_hc0[3]*_hc1[1]*_t106*_t21*_t302*_t31 - _t652 - 0.1e1 / 0.4e1*_t659 - 0.3e1 / 0.2e1*_t660 - 0.3e1 / 0.2e1*_t662 - 0.3e1 / 0.4e1*_t663;
  const double _t665 = 0.3e1*_hc0[1]*_hc0[3]*_hc1[1]*_t101*_t31*_t38*_t66 + (0.3e1 / 0.2e1)*_hc0[3]*_hc1[1]*_t106*_t21*_t302*_t31 - _t656 - 0.1e1 / 0.2e1*_t659 - 0.3e1*_t660 - 0.3e1*_t662 - 0.3e1 / 0.2e1*_t663;
  const double _t666 = _hc0[1]*_t22*_t5/xc_powr(_t8, 7, 2);
  const double _t668 = _t108*_t667;
  const double _t670 = _hc2[10]*_t22*_t669;
  const double _t672 = _t304*_t671;
  const double _t673 = (0.9e1 / 0.4e1)*_hc0[3];
  const double _t674 = _t299*_t38*_t67;
  const double _t675 = _t669*_t67;
  const double _t676 = _hc0[1]*_hc2[6]*_t675;
  const double _t678 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t364;
  const double _t679 = _t307*_t671;
  const double _t680 = _t111*_t667;
  const double _t681 = ((_hc0[3]) * (_hc0[3]));
  const double _t682 = _t675*_t681;
  const double _t683 = _t110*_t167*_t669;
  const double _t684 = (0.15e2 / 0.16e2)*_t666 - 0.15e2 / 0.16e2*_t668 - 0.1e1 / 0.16e2*_t670 + (0.3e1 / 0.8e1)*_t672 - _t673*_t674 - _t673*_t683 + (0.1e1 / 0.2e1)*_t676 + _t677*_t678 + (0.9e1 / 0.4e1)*_t679 + (0.15e2 / 0.8e1)*_t680 + (0.3e1 / 0.8e1)*_t682;
  const double _t685 = (0.9e1 / 0.2e1)*_hc0[3];
  const double _t686 = _t669*_t678;
  const double _t687 = (0.15e2 / 0.8e1)*_t666 - 0.15e2 / 0.8e1*_t668 - 0.1e1 / 0.8e1*_t670 + (0.3e1 / 0.4e1)*_t672 - _t674*_t685 + _t676 + (0.9e1 / 0.2e1)*_t679 + (0.15e2 / 0.4e1)*_t680 + (0.3e1 / 0.4e1)*_t682 - _t683*_t685 + 0.3e1*_t686;
  const double _t688 = 0.9e1*_hc0[3];
  const double _t689 = (0.15e2 / 0.4e1)*_t666 - 0.15e2 / 0.4e1*_t668 + _t67*_t677*_t681 - 0.1e1 / 0.4e1*_t670 + (0.3e1 / 0.2e1)*_t672 - _t674*_t688 + 0.2e1*_t676 + 0.9e1*_t679 + (0.15e2 / 0.2e1)*_t680 - _t683*_t688 + 0.6e1*_t686;
  const double _t690 = 0.18e2*_hc0[3];
  const double _t691 = _hc2[6]*_t139*_t671 + (0.15e2 / 0.2e1)*_t666 - 0.15e2 / 0.2e1*_t668 - 0.1e1 / 0.2e1*_t670 - _t674*_t690 + 0.4e1*_t676 + 0.18e2*_t679 + 0.15e2*_t680 + 0.3e1*_t682 - _t683*_t690 + 0.12e2*_t686;
  const double _t692 = 0.36e2*_hc0[3];
  const double d4F_dna4 = 0.2e1*_t119*_t74 + 0.4e1*_t120 + 0.4e1*_t123 + _t128*_t325 + _t171*(-_t315 + _t316) + (_t18 * _t18 * _t18 * _t18)*_t317 + _t200*_t321 + _t201*_t321 + 0.4e1*_t318 + 0.4e1*_t319 + 0.12e2*_t320 + _t321*_t340 + _t328*_t331 + _t328*(-_t125 + _t329*_t38) + _t328*(-_t326 + _t327*_t38) + _t332*_t333 + 0.4e1*_t334 + 0.4e1*_t336 + 0.6e1*_t337 + 0.6e1*_t339 + 0.4e1*_t342 + 0.4e1*_t343 + 0.4e1*_t344 + 0.6e1*_t346 + 0.6e1*_t348 + 0.8e1*_t349 + 0.4e1*_t352 + _t366 + (_t41 * _t41)*_t73 + _t74*(_t322 - _t324);
  const double d4F_dna3_dnb = _t119*_t174 + _t120 + _t121*_t177*_t317 + _t123 + _t124*_t200 + _t124*_t201 + _t128*_t373 + _t128*_t384 + _t157*_t374 + _t170*_t74 + _t171*(_t316 - _t323) + _t179*_t381 + _t318 + _t319 + 0.9e1*_t320 + _t334 + _t336 + 0.3e1*_t337 + 0.3e1*_t339 + _t340*_t379 + 0.3e1*_t342 + _t343 + _t344 + 0.3e1*_t346 + 0.3e1*_t348 + 0.6e1*_t349 + 0.3e1*_t352 + 0.3e1*_t367 + 0.3e1*_t368 + 0.3e1*_t369 + 0.3e1*_t370 + _t372 + _t373*_t41 + 0.3e1*_t375 + 0.3e1*_t376 + _t378*_t43 + _t380*_t381 + _t383 + _t384*_t41 + 0.2e1*_t385 + 0.3e1*_t388 + 0.3e1*_t389 + _t390*_t391 + _t393 + _t397 + _t74*(-_t324 + 0.4e1*_t38);
  const double d4F_dna2_dnb2 = 0.8e1*(_t11 * _t11)*_t266*_t44 + 0.8e1*_t122*_t17*_t249 + _t124*_t340 + _t124*_t374 - _t125*_t179 - _t125*_t380 - _t126*_t19 - _t127*_t179 + _t127*_t380 + 0.4e1*_t129*_t250 + _t170*_t403 + _t18*_t409 + _t183*_t75 + _t184*_t357 + _t187*_t75 + _t19*_t324 + _t200*_t97 + _t201*_t97 + _t250*_t405 + _t254*_t97 + _t255*_t97 + _t31*_t409 + _t317*_t43*_t77 + 0.6e1*_t320 + _t325*_t75 + _t328*_t401 + _t331*_t402 + _t337 + _t339 + 0.2e1*_t342 + _t346 + _t348 + 0.4e1*_t349 + 0.2e1*_t352 + _t366 + 0.2e1*_t367 + 0.6e1*_t368 + 0.2e1*_t369 + 0.2e1*_t370 + 0.2e1*_t372 + 0.2e1*_t375 + 0.2e1*_t376 + 0.8e1*_t38*_t404 + 0.2e1*_t383 + 0.4e1*_t385 + 0.2e1*_t388 + 0.2e1*_t389 + 0.2e1*_t393 + _t395*_t405 + 0.4e1*_t396 + 0.2e1*_t398 + _t399 + _t400 + _t406 + _t407 + 0.2e1*_t408;
  const double d4F_dna_dnb3 = -_t11*_t115*_t380 + _t115*_t19 - _t115*_t404 + _t118*_t19 + _t124*_t254 + _t124*_t255 + _t157*_t340 + _t179*_t412 + _t186*_t412 + _t192*_t197*_t317 - _t194*_t326 + _t195*_t74 + _t196 + _t198 + _t199*_t384 + _t31*_t321*_t390 + 0.3e1*_t320 - _t326*_t380 + _t342 + _t345*_t412 + 0.2e1*_t349 + _t352 + 0.9e1*_t368 + 0.3e1*_t372 + _t374*_t379 + _t375 + _t377*_t44*_t75 + _t378*_t77 + 0.3e1*_t383 + _t384*_t75 + 0.6e1*_t385 + 0.3e1*_t393 + _t397 + 0.3e1*_t398 + 0.3e1*_t399 + 0.3e1*_t400 + 0.3e1*_t407 + 0.3e1*_t408 + _t410 + _t411 + _t413 + _t414 + _t416 + _t417;
  const double d4F_dnb4 = _t171*(_t315 + _t316) + _t174*(-_t322 - _t324) + _t195*_t403 + 0.4e1*_t196 + 0.4e1*_t198 + _t199*_t73*_t75 + _t254*_t321 + _t255*_t321 + (_t31 * _t31 * _t31 * _t31)*_t317 + _t321*_t374 + _t332*_t418 + _t366 + 0.12e2*_t368 + 0.4e1*_t383 + 0.8e1*_t385 + 0.4e1*_t393 + 0.6e1*_t399 + 0.6e1*_t400 + _t401*_t402 + _t402*(_t125 + _t329*_t38) + _t402*(_t326 + _t327*_t38) + 0.6e1*_t406 + 0.6e1*_t407 + 0.4e1*_t410 + 0.4e1*_t411 + 0.4e1*_t413 + 0.4e1*_t414 + 0.4e1*_t416 + 0.4e1*_t417 + _t73*(_t75 * _t75);
  const double d4F_dna3_dgaa = _t458;
  const double d4F_dna3_dgab = 0.3e1*_hc1[1]*_t18*_t21*_t238*_t4 + 0.6e1*_hc1[1]*_t18*_t21*_t96 + 0.3e1*_hc1[1]*_t18*_t242*_t28*_t4*_t66 + 0.3e1*_hc1[1]*_t18*_t4*_t65*_t66*_t96 + 0.3e1*_hc1[1]*_t21*_t4*_t41*_t96 + 0.3e1*_hc1[2]*_t21*_t4*_t43*_t96 - _t119*_t459 - _t121*_t460 - _t128*_t462 - _t205*_t394 - _t321*_t429 - _t41*_t462 - 0.3e1*_t422 - 0.3e1*_t423 - _t427*_t463 - _t428*_t463 - _t431*_t464 - _t478;
  const double d4F_dna3_dgbb = _t458;
  const double d4F_dna2_dnb_dgaa = _t503;
  const double d4F_dna2_dnb_dgab = 0.4e1*_hc1[1]*_t11*_t16*_t21*_t96 + 0.2e1*_hc1[1]*_t18*_t21*_t238*_t4 + 0.4e1*_hc1[1]*_t18*_t21*_t96 + 0.2e1*_hc1[1]*_t18*_t242*_t28*_t4*_t66 + 0.2e1*_hc1[1]*_t18*_t4*_t65*_t66*_t96 + _hc1[1]*_t21*_t238*_t31*_t4 + 0.2e1*_hc1[1]*_t21*_t31*_t96 + _hc1[1]*_t21*_t4*_t41*_t96 + _hc1[1]*_t242*_t28*_t31*_t4*_t66 + _hc1[1]*_t31*_t4*_t65*_t66*_t96 + 0.2e1*_hc1[2]*_t18*_t21*_t31*_t4*_t96 + _hc1[2]*_t21*_t4*_t43*_t96 - _t170*_t459 - _t178*_t460 - _t405*_t429 - _t41*_t504 - _t422 - _t423 - _t427*_t454 - _t428*_t454 - _t431*_t463 - _t478 - 0.4e1*_t480 - 0.4e1*_t493 - _t505 - _t507 - _t508 - 0.4e1*_t509 - _t510 - _t511 - _t512;
  const double d4F_dna2_dnb_dgbb = _t503;
  const double d4F_dna_dnb2_dgaa = _t523;
  const double d4F_dna_dnb2_dgab = _t139*_t238 + _t160*_t467 + _t163*_t238 - _t193*_t460 + _t228*_t96 + _t238*_t333 + _t238*_t522 + _t242*_t341 + _t242*_t362 + 0.2e1*_t242*_t382 + _t242*_t519 + 0.2e1*_t246 + _t254*_t526 + _t255*_t526 + _t340*_t526 + _t358*_t96 + _t360*_t526 + _t361*_t469 + 0.2e1*_t374*_t526 - _t405*_t489 - _t454*_t524 - _t454*_t525 - _t462*_t75 - _t463*_t502 + _t466*_t62 - _t470 - _t471 - _t472 - _t473 - _t475 - _t477 + _t481 - 0.4e1*_t483 + _t490*_t527 - _t491 - _t497 - _t501 + _t506*_t526 - _t507 - _t510 - _t512 - _t513 - _t514 - 0.4e1*_t515 + _t516*_t96 + _t517*_t96 + _t520*_t96;
  const double d4F_dna_dnb2_dgbb = _t523;
  const double d4F_dnb3_dgaa = _t528;
  const double d4F_dnb3_dgab = 0.3e1*_hc1[1]*_t21*_t238*_t31*_t4 + 0.6e1*_hc1[1]*_t21*_t31*_t96 + 0.3e1*_hc1[1]*_t21*_t4*_t75*_t96 + 0.3e1*_hc1[1]*_t242*_t28*_t31*_t4*_t66 + 0.3e1*_hc1[1]*_t31*_t4*_t65*_t66*_t96 + 0.3e1*_hc1[2]*_t21*_t4*_t77*_t96 - _t195*_t459 - _t197*_t460 - _t199*_t504 - _t252*_t394 - _t321*_t489 - _t415*_t461 - _t463*_t524 - _t463*_t525 - _t464*_t502 - _t478 - 0.3e1*_t513 - 0.3e1*_t514;
  const double d4F_dnb3_dgbb = _t528;
  const double d4F_dna2_dgaa2 = _t572;
  const double d4F_dna2_dgaa_dgab = _t585;
  const double d4F_dna2_dgaa_dgbb = _t572;
  const double d4F_dna2_dgab2 = -_t205*_t586 + _t228*_t545 - _t228*_t547 + _t258*_t350*_t391 - _t260*_t587 + _t262*_t587 + _t291*_t529 + 0.2e1*_t531 + 0.2e1*_t533 - _t534 - _t535 + _t536 + _t537 + 0.4e1*_t544 + _t591;
  const double d4F_dna2_dgab_dgbb = _t585;
  const double d4F_dna2_dgbb2 = _t572;
  const double d4F_dna_dnb_dgaa2 = _t606;
  const double d4F_dna_dnb_dgaa_dgab = _t610;
  const double d4F_dna_dnb_dgaa_dgbb = _t606;
  const double d4F_dna_dnb_dgab2 = _t291*_t333 + _t291*_t418 + _t575 + _t591 + 0.4e1*_t592 + 0.2e1*_t593 - 0.2e1*_t595 + 0.2e1*_t599 - _t601 + _t602 - 0.4e1*_t607 - 0.4e1*_t608 + _t612;
  const double d4F_dna_dnb_dgab_dgbb = _t610;
  const double d4F_dna_dnb_dgbb2 = _t606;
  const double d4F_dnb2_dgaa2 = _t620;
  const double d4F_dnb2_dgaa_dgab = _t621;
  const double d4F_dnb2_dgaa_dgbb = _t620;
  const double d4F_dnb2_dgab2 = -_t252*_t586 + _t257*_t545 - _t257*_t547 - _t260*_t622 + _t262*_t622 + _t291*_t522 + _t321*_t604 + _t591 + 0.4e1*_t594 + 0.2e1*_t613 + 0.2e1*_t614 - _t615 - _t616 + _t617 + _t618;
  const double d4F_dnb2_dgab_dgbb = _t621;
  const double d4F_dnb2_dgbb2 = _t620;
  const double d4F_dna_dgaa3 = _t644;
  const double d4F_dna_dgaa2_dgab = _t653;
  const double d4F_dna_dgaa2_dgbb = _t644;
  const double d4F_dna_dgaa_dgab2 = _t657;
  const double d4F_dna_dgaa_dgab_dgbb = _t653;
  const double d4F_dna_dgaa_dgbb2 = _t644;
  const double d4F_dna_dgab3 = 0.6e1*_hc0[1]*_hc0[3]*_hc1[1]*_t101*_t18*_t38*_t66 + 0.3e1*_hc0[3]*_hc1[1]*_t106*_t18*_t21*_t302 - _t430*_t649 - _t624 - 0.6e1*_t628 - 0.3e1*_t646 - _t658;
  const double d4F_dna_dgab2_dgbb = _t657;
  const double d4F_dna_dgab_dgbb2 = _t653;
  const double d4F_dna_dgbb3 = _t644;
  const double d4F_dnb_dgaa3 = _t661;
  const double d4F_dnb_dgaa2_dgab = _t664;
  const double d4F_dnb_dgaa2_dgbb = _t661;
  const double d4F_dnb_dgaa_dgab2 = _t665;
  const double d4F_dnb_dgaa_dgab_dgbb = _t664;
  const double d4F_dnb_dgaa_dgbb2 = _t661;
  const double d4F_dnb_dgab3 = 0.6e1*_hc0[1]*_hc0[3]*_hc1[1]*_t101*_t31*_t38*_t66 + 0.3e1*_hc0[3]*_hc1[1]*_t106*_t21*_t302*_t31 - _t392*_t649 - _t658 - _t659 - 0.6e1*_t660 - 0.3e1*_t663;
  const double d4F_dnb_dgab2_dgbb = _t665;
  const double d4F_dnb_dgab_dgbb2 = _t664;
  const double d4F_dnb_dgbb3 = _t661;
  const double d4F_dgaa4 = _t684;
  const double d4F_dgaa3_dgab = _t687;
  const double d4F_dgaa3_dgbb = _t684;
  const double d4F_dgaa2_dgab2 = _t689;
  const double d4F_dgaa2_dgab_dgbb = _t687;
  const double d4F_dgaa2_dgbb2 = _t684;
  const double d4F_dgaa_dgab3 = _t691;
  const double d4F_dgaa_dgab2_dgbb = _t689;
  const double d4F_dgaa_dgab_dgbb2 = _t687;
  const double d4F_dgaa_dgbb3 = _t684;
  const double d4F_dgab4 = _t115*_t298*_t304 + 0.15e2*_t666 - 0.15e2*_t668 - _t670 - _t674*_t692 + 0.8e1*_t676 + 0.36e2*_t679 + 0.30e2*_t680 + 0.6e1*_t682 - _t683*_t692 + 0.24e2*_t686;
  const double d4F_dgab3_dgbb = _t691;
  const double d4F_dgab2_dgbb2 = _t689;
  const double d4F_dgab_dgbb3 = _t687;
  const double d4F_dgbb4 = _t684;
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