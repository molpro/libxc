/*
  Generated from python/gga_exc/gga_c_wi.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_wi
*/

#ifndef _GGA_C_WI_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_WI_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_WI_HELPER_BODIES
#include "gga_c_wi.c"
#undef _GGA_C_WI_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_WI_HELPER_BODIES
#include "gga_c_wi.c"
#undef _GGA_C_WI_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_WI_HELPER_BODIES
#include "gga_c_wi.c"
#undef _GGA_C_WI_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_WI_HELPER_BODIES
#include "gga_c_wi.c"
#undef _GGA_C_WI_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_WI_HELPER_BODIES
#include "gga_c_wi.c"
#undef _GGA_C_WI_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_wi.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_wi.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_wi.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_wi.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_wi.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_wi.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_wi.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_wi.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_wi.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_wi.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_WI_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_num_k, _KMAX)(const xc_func_type *p, double xt, double *out) {
  const gga_c_wi_params *params = (const gga_c_wi_params *)(p->params);

  const double _t1 = (xt * xt);
  const double _t2 = _t1*params->k;
  const double _t3 = exp(-_t2);
  const double _t4 = _t3*params->b;
  const double _t5 = _t1*_t4;
#if _KMAX >= 1
  const double _t6 = (xt * xt * xt);
  const double _t7 = 0.2e1*_t4;
#endif
#if _KMAX >= 2
  const double _t8 = (xt * xt * xt * xt);
  const double _t9 = ((params->k) * (params->k));
#endif
#if _KMAX >= 3
  const double _t10 = 0.24e2*_t4*params->k;
  const double _t11 = _t4*((params->k) * (params->k) * (params->k));
#endif

  const double f = _t5 + params->a;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = 0.2e1*_t3*params->b*xt - _t6*_t7*params->k;
  out[1] = df_dxt;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = -0.10e2*_t2*_t4 + 0.4e1*_t4*_t8*_t9 + _t7;
  out[2] = d2f_dxt2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = -_t10*xt - 0.8e1*_t11*xc_powi(xt, 5) + 0.36e2*_t3*_t6*_t9*params->b;
  out[3] = d3f_dxt3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = -_t10 - 0.112e3*_t11*_t8 + 0.16e2*_t4*((params->k) * (params->k) * (params->k) * (params->k))*xc_powi(xt, 6) + 0.156e3*_t5*_t9;
  out[4] = d4f_dxt4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_den_k, _KMAX)(const xc_func_type *p, double rs, double xt, double *out) {
  const gga_c_wi_params *params = (const gga_c_wi_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 2, 3)*M_CBRTPI*params->d;
  const double _t2 = (0.1e1 / 0.3e1)*_t1*xc_powr(xt, 7, 2) + 0.1e1;
#if _KMAX >= 1
  const double _t3 = (0.7e1 / 0.6e1)*_t1*xc_powr(xt, 5, 2);
#endif
#if _KMAX >= 2
  const double _t4 = (0.35e2 / 0.12e2)*_t1*xc_powr(xt, 3, 2);
#endif
#if _KMAX >= 3
  const double _t5 = xc_powr(xt, 1, 2);
  const double _t6 = (0.35e2 / 0.8e1)*_t1*_t5;
#endif

  const double f = _t2*rs + params->c;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = _t3*rs;
  out[1] = df_dxt;
  const double df_drs = _t2;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = _t4*rs;
  out[3] = d2f_dxt2;
  const double d2f_drs_dxt = _t3;
  out[4] = d2f_drs_dxt;
  const double d2f_drs2 = 0;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = _t6*rs;
  out[6] = d3f_dxt3;
  const double d3f_drs_dxt2 = _t4;
  out[7] = d3f_drs_dxt2;
  const double d3f_drs2_dxt = 0;
  out[8] = d3f_drs2_dxt;
  const double d3f_drs3 = 0;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = (0.35e2 / 0.16e2)*_t1*rs/_t5;
  out[10] = d4f_dxt4;
  const double d4f_drs_dxt3 = _t6;
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
  assert(p->params != NULL);
  const gga_c_wi_params *params = (const gga_c_wi_params *)(p->params);
  (void)params;
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
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_den_k, _KMAX)(p, _t3*_t5, _t8, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_num_k, _KMAX)(p, _t8, _hc1);
  const double _t9 = (0.1e1 / (_hc0[0]));
  const double _t10 = _hc1[0]*_t9;
  const double zk = _t10;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t13 = xc_powr(na, -7, 3);
  const double _t14 = (0.4e1 / 0.3e1)*_t13;
  const double _t16 = (0.1e1 / 0.6e1)*_t7;
  const double _t21 = (0.1e1 / _t6);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_den_k, _KMAX)(p, 0, _t8, _hc2);
  const double _t11 = _hc1[1]*_t9;
  const double _t12 = _hc0[1]*_t6;
  const double _t15 = _hc2[2]*_t3;
  const double _t17 = _t12*_t14 + _t15*_t16;
  const double _t18 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t19 = _hc1[0]*_t18;
  const double _t20 = _t17*_t19;
  const double _t22 = _t11*_t21;
  const double _t23 = _hc0[1]*_t21;
  const double _t24 = _t19*_t23;
  const double dF_dna = _t10 - 0.4e1 / 0.3e1*_t11*_t8 + _t20*na;
  const double dF_dgaa = _t22*_t5 - _t24*_t5;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t25 = (0.16e2 / 0.9e1)*gaa;
  const double _t26 = xc_powr(na, -11, 3);
  const double _t33 = (0.8e1 / 0.3e1)*_t13;
  const double _t40 = xc_powr(na, -10, 3);
  const double _t41 = (0.28e2 / 0.9e1)*_t40;
  const double _t42 = (0.2e1 / 0.9e1)*_t13;
  const double _t44 = (0.2e1 / 0.9e1)*_t26;
  const double _t45 = _t44*_t6;
  const double _t46 = _t14*_t6;
  const double _t47 = _t16*_t3;
  const double _t51 = xc_powr(na, -8, 3);
  const double _t52 = (0.2e1 / 0.3e1)*_t51;
  const double _t53 = (0.1e1 / 0.2e1)*_t7;
  const double _t56 = (0.2e1 / 0.3e1)*_t26;
  const double _t58 = (0.2e1 / 0.3e1)*_t13;
  const double _t59 = (0.1e1 / 0.12e2)*_t51;
  const double _t60 = _t21*_t59;
  const double _t62 = xc_powr(gaa, 3, 2);
  const double _t63 = (0.1e1 / _t62);
  const double _t65 = (0.1e1 / 0.4e1)*_t4;
  const double _t66 = (0.1e1 / gaa);
  const double _t67 = xc_powr(na, -5, 3);
  const double _t69 = _t66*_t67;
  const double _t70 = (0.1e1 / 0.4e1)*_t67;
  const double _t27 = _hc1[2]*_t9;
  const double _t28 = _t26*_t27;
  const double _t29 = (0.4e1 / 0.9e1)*_t9;
  const double _t30 = _hc1[1]*_t18;
  const double _t31 = _t30*_t8;
  const double _t32 = (0.8e1 / 0.3e1)*_t17;
  const double _t34 = _t15*_t7;
  const double _t35 = _t12*_t33 + (0.1e1 / 0.3e1)*_t34;
  const double _t36 = _t17*_t35;
  const double _t37 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t38 = _hc1[0]*_t37;
  const double _t39 = _t38*na;
  const double _t43 = _hc2[4]*_t3;
  const double _t48 = -_hc0[3]*_t46 - _hc2[4]*_t47;
  const double _t49 = -_t12*_t41 + (0.4e1 / 0.3e1)*_t13*_t48*_t6 - _t15*_t42 - _t43*_t45;
  const double _t50 = _t19*na;
  const double _t54 = _t17*_t38;
  const double _t55 = _t23*_t4;
  const double _t57 = _hc0[3]*_t56;
  const double _t61 = _t23*_t58 + _t43*_t60 + _t57;
  const double _t64 = _t11*_t63;
  const double _t68 = (0.1e1 / 0.2e1)*_hc0[1];
  const double _t71 = _hc0[3]*_t66;
  const double _t72 = _t19*_t71;
  const double _t73 = ((_hc0[1]) * (_hc0[1]));
  const double d2F_dna2 = _hc1[1]*_t13*_t29*_t6 + 0.2e1*_t20 + _t25*_t28 - _t31*_t32 + _t36*_t39 + _t49*_t50;
  const double d2F_dna_dgaa = (0.2e1 / 0.3e1)*_hc0[1]*_hc1[1]*_t18*_t51 + _hc1[0]*_t18*_t61*na + (0.1e1 / 0.2e1)*_hc1[1]*_t17*_t18*_t21*_t4 - _t16*_t22 - _t24*_t53 - _t27*_t52 - _t54*_t55;
  const double d2F_dgaa2 = (0.1e1 / 0.4e1)*_hc0[1]*_hc1[0]*_t18*_t4*_t63 + (0.1e1 / 0.2e1)*_hc1[0]*_t37*_t66*_t67*_t73 + (0.1e1 / 0.4e1)*_hc1[2]*_t66*_t67*_t9 - _t30*_t68*_t69 - _t64*_t65 - _t70*_t72;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t74 = xc_powr(na, -14, 3);
  const double _t76 = _t40*_t6;
  const double _t77 = xc_powi(na, -6);
  const double _t83 = (0.16e2 / 0.3e1)*gaa;
  const double _t97 = (0.4e1 / 0.9e1)*_t13;
  const double _t103 = xc_powr(na, -13, 3);
  const double _t104 = (0.280e3 / 0.27e2)*_t103;
  const double _t105 = (0.14e2 / 0.27e2)*_t40;
  const double _t108 = _t41*_t6;
  const double _t110 = (0.56e2 / 0.9e1)*_t76;
  const double _t112 = _t3*_t42;
  const double _t119 = xc_powi(na, -5);
  const double _t120 = (0.8e1 / 0.9e1)*_t119;
  const double _t126 = (0.1e1 / 0.3e1)*_t7;
  const double _t141 = (0.14e2 / 0.9e1)*_t74;
  const double _t142 = (0.14e2 / 0.9e1)*_t40;
  const double _t143 = (0.1e1 / 0.9e1)*_t26;
  const double _t144 = _t21*_t58;
  const double _t149 = (0.1e1 / (na * na * na * na));
  const double _t150 = (0.1e1 / 0.3e1)*_t149;
  const double _t152 = (0.1e1 / 0.6e1)*_t66;
  const double _t153 = (0.2e1 / 0.3e1)*_t149;
  const double _t159 = _t153*_t21;
  const double _t160 = _t63*_t65;
  const double _t161 = _t66*_t70;
  const double _t164 = (0.1e1 / 0.2e1)*_t67;
  const double _t165 = (0.3e1 / 0.2e1)*_t69;
  const double _t170 = (0.1e1 / 0.3e1)*_t13;
  const double _t171 = (0.1e1 / 0.3e1)*_t66;
  const double _t173 = (0.1e1 / 0.3e1)*_t119;
  const double _t176 = (0.1e1 / 0.24e2)*_t149;
  const double _t178 = xc_powr(gaa, -5, 2);
  const double _t179 = (gaa * gaa);
  const double _t180 = (0.1e1 / _t179);
  const double _t181 = (0.3e1 / 0.8e1)*_t67;
  const double _t182 = (0.1e1 / (na * na * na));
  const double _t186 = _t182*_t63;
  const double _t189 = (0.1e1 / 0.8e1)*_t63;
  const double _t190 = (0.3e1 / 0.4e1)*_t186;
  const double _t194 = (0.3e1 / 0.4e1)*_t180;
  const double _t75 = _t27*_t74;
  const double _t78 = _hc1[3]*_t9;
  const double _t79 = _t62*_t78;
  const double _t80 = _hc1[2]*_t18;
  const double _t81 = _t17*_t80;
  const double _t82 = _t26*_t81;
  const double _t84 = _t17*_t30;
  const double _t85 = 0.3e1*_t38;
  const double _t86 = _hc1[1]*_t37;
  const double _t87 = _t8*_t86;
  const double _t88 = 0.4e1*_t87;
  const double _t89 = 0.4e1*_t12*_t13 + (0.1e1 / 0.2e1)*_t34;
  const double _t90 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t91 = _hc1[0]*_t90;
  const double _t92 = _t36*_t91;
  const double _t93 = _t89*_t92;
  const double _t94 = 0.3e1*_t19;
  const double _t95 = 0.4e1*_t31;
  const double _t96 = _t12*_t40;
  const double _t98 = _t43*_t6;
  const double _t99 = (0.8e1 / 0.3e1)*_t13*_t48*_t6 - _t15*_t97 - 0.4e1 / 0.9e1*_t26*_t98 - 0.56e2 / 0.9e1*_t96;
  const double _t100 = _t17*_t39;
  const double _t101 = _t35*_t49;
  const double _t102 = 0.2e1*_t39;
  const double _t106 = _t74*_t98;
  const double _t107 = _hc2[7]*_t74;
  const double _t109 = _hc2[4]*_t108 + _t107*_t25;
  const double _t111 = (0.28e2 / 0.9e1)*_hc0[3];
  const double _t113 = _hc2[7]*_t3;
  const double _t114 = -_hc0[6]*_t46 - _hc2[7]*_t47;
  const double _t115 = _hc2[4]*_t112 + _t111*_t76 + _t113*_t45 - _t114*_t46;
  const double _t116 = _t104*_t12 + _t105*_t15 + (0.16e2 / 0.27e2)*_t106 + _t109*_t47 - _t110*_t48 + _t115*_t46;
  const double _t117 = _hc0[1]*_t30;
  const double _t118 = _t6*_t78;
  const double _t121 = _t12*_t80;
  const double _t122 = _t17*_t51;
  const double _t123 = _t122*_t80;
  const double _t124 = _hc0[1]*_t86;
  const double _t125 = _t21*_t30;
  const double _t127 = 0.2e1*_t23;
  const double _t128 = _t54*_t7;
  const double _t129 = 0.2e1*_t19;
  const double _t130 = (0.8e1 / 0.3e1)*_t61;
  const double _t131 = _t21*_t86;
  const double _t132 = _t131*_t5;
  const double _t133 = (0.3e1 / 0.2e1)*_t55;
  const double _t134 = _hc0[3]*_t26;
  const double _t135 = _t21*_t43;
  const double _t136 = _t135*_t51;
  const double _t137 = (0.4e1 / 0.3e1)*_t134 + (0.1e1 / 0.6e1)*_t136 + _t14*_t23;
  const double _t138 = _t35*_t61;
  const double _t139 = _t125*_t5;
  const double _t140 = _t38*_t55;
  const double _t145 = -_hc2[4]*_t144 - _hc2[7]*_t56;
  const double _t146 = -_hc0[3]*_t144 - _hc0[6]*_t56 - _t113*_t60;
  const double _t147 = -_hc0[3]*_t141 + (0.1e1 / 0.6e1)*_t1*_t145*_t2*_t7 + (0.4e1 / 0.3e1)*_t13*_t146*_t6 + (0.2e1 / 0.3e1)*_t13*_t21*_t48 - _t135*_t143 - _t142*_t23;
  const double _t148 = _t21*_t78;
  const double _t151 = _hc0[1]*_t63;
  const double _t154 = _t23*_t80;
  const double _t155 = _hc0[3]*_t125;
  const double _t156 = _t38*_t73;
  const double _t157 = _t37*_t73;
  const double _t158 = _hc1[1]*_t157;
  const double _t162 = _t151*_t5;
  const double _t163 = _t124*_t17;
  const double _t166 = _t17*_t73;
  const double _t167 = _t166*_t91;
  const double _t168 = _t4*_t61;
  const double _t169 = _t127*_t38;
  const double _t172 = _hc0[6]*_t21;
  const double _t174 = _t43*_t63;
  const double _t175 = _t113*_t66;
  const double _t177 = _t134*_t171 - _t151*_t170 + _t172*_t173 - 0.1e1 / 0.24e2*_t174*_t51 + _t175*_t176;
  const double _t183 = _hc0[1]*_t19;
  const double _t184 = _t182*_t80;
  const double _t185 = (0.3e1 / 0.8e1)*_t151;
  const double _t187 = (0.3e1 / 0.8e1)*_hc0[3]*_t30;
  const double _t188 = _hc0[6]*_t19;
  const double _t191 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t192 = _t191*_t90;
  const double _t193 = _hc1[0]*_t192;
  const double d3F_dna3 = _t100*_t99 + _t101*_t102 - 0.28e2 / 0.27e2*_t11*_t76 + _t116*_t50 + _t36*_t85 - _t36*_t88 + _t46*_t84 + _t49*_t94 - _t49*_t95 - 0.64e2 / 0.9e1*_t75*gaa - 0.64e2 / 0.27e2*_t77*_t79 + _t82*_t83 + _t93*na;
  const double d3F_dna2_dgaa = _t100*_t137 - _t117*_t44 + _t118*_t120 - _t120*_t121 + (0.8e1 / 0.3e1)*_t122*_t124 - 0.4e1 / 0.3e1*_t123 - _t125*_t126*_t17 - _t127*_t128 + _t129*_t61 - _t130*_t31 + _t132*_t36 - _t133*_t92 + _t138*_t39 + _t139*_t49 - _t140*_t49 + _t147*_t50 + _t22*_t42 + 0.2e1*_t28;
  const double d3F_dna_dgaa2 = -_t117*_t152*_t51 + _t125*_t168 - _t148*_t150 + _t150*_t155 + (0.1e1 / 0.4e1)*_t151*_t19*_t7 + _t153*_t154 + (0.1e1 / 0.2e1)*_t156*_t51*_t66 - _t158*_t159 - _t160*_t84 + _t161*_t81 + _t162*_t54 - _t163*_t69 - _t164*_t54*_t71 + _t165*_t167 - _t168*_t169 + _t177*_t50 - _t27*_t59*_t66 - 0.1e1 / 0.4e1*_t51*_t72 + (0.1e1 / 0.12e2)*_t64*_t7;
  const double d3F_dgaa3 = (0.3e1 / 0.4e1)*_hc0[1]*_hc0[3]*_hc1[0]*_t182*_t37*_t63 + (0.3e1 / 0.4e1)*_hc0[1]*_hc1[1]*_t18*_t180*_t67 + (0.3e1 / 0.8e1)*_hc0[3]*_hc1[0]*_t18*_t180*_t67 + (0.3e1 / 0.8e1)*_hc1[1]*_t178*_t4*_t9 + (0.3e1 / 0.4e1)*_hc1[1]*_t182*_t37*_t63*_t73 + (0.1e1 / 0.8e1)*_hc1[3]*_t182*_t63*_t9 - _t156*_t194*_t67 - 0.3e1 / 0.8e1*_t178*_t183*_t4 - _t180*_t181*_t27 - _t182*_t188*_t189 - _t184*_t185 - _t186*_t187 - _t190*_t193;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t195 = xc_powr(na, -17, 3);
  const double _t196 = _t195*gaa;
  const double _t200 = (0.32e2 / 0.3e1)*gaa;
  const double _t203 = _t33*_t6;
  const double _t220 = xc_powr(na, -16, 3);
  const double _t221 = _t104*_t6;
  const double _t224 = (0.32e2 / 0.27e2)*gaa/xc_powr(na, 22, 3);
  const double _t237 = _t142*_t21;
  const double _t239 = xc_powr(na, -19, 3);
  const double _t240 = (0.8e1 / 0.9e1)*_t239;
  const double _t243 = (0.1e1 / 0.9e1)*_t66;
  const double _t248 = (0.3e1 / 0.4e1)*_t4;
  const double _t250 = _t173*_t21;
  const double _t251 = _t171*_t26;
  const double _t252 = (0.3e1 / 0.8e1)*_t178;
  const double _t253 = (0.3e1 / 0.4e1)*_t63;
  const double _t255 = (0.1e1 / 0.16e2)*_t180;
  const double _t256 = (0.15e2 / 0.16e2)*_t4/xc_powr(gaa, 7, 2);
  const double _t257 = _t67/(gaa * gaa * gaa);
  const double _t258 = (0.15e2 / 0.16e2)*_t257;
  const double _t259 = _t103*_t255;
  const double _t260 = (0.15e2 / 0.8e1)*_t257;
  const double _t261 = _t103*_t180;
  const double _t262 = (0.1e1 / 0.4e1)*_t261;
  const double _t263 = _t178*_t182;
  const double _t264 = (0.3e1 / 0.8e1)*_t261;
  const double _t265 = (0.9e1 / 0.4e1)*_t263;
  const double _t266 = (0.3e1 / 0.2e1)*_t261;
  const double _t197 = _hc1[4]*_t9;
  const double _t198 = _hc1[3]*_t18;
  const double _t199 = _t17*_t198;
  const double _t201 = _hc1[2]*_t37;
  const double _t202 = _t201*_t36;
  const double _t204 = _t36*_t86;
  const double _t205 = _t26*_t80;
  const double _t206 = _hc1[1]*_t90;
  const double _t207 = _t206*_t36*_t89;
  const double _t208 = _t30*_t49;
  const double _t209 = (0.16e2 / 0.3e1)*_t12;
  const double _t210 = _t89*na;
  const double _t211 = _hc1[0]/xc_powi((_hc0[0]), 5);
  const double _t212 = _t211*_t36;
  const double _t213 = _t17*_t99;
  const double _t214 = _t92*na;
  const double _t215 = _t210*_t91;
  const double _t216 = 0.3e1*_t101;
  const double _t217 = _t39*_t99;
  const double _t218 = _t109*_t3;
  const double _t219 = _t35*_t39;
  const double _t222 = _hc2[11]*_t25*_t74 + _hc2[7]*_t108;
  const double _t223 = _hc2[11]*_t3;
  const double _t225 = _hc0[1]*_t198;
  const double _t226 = _t17*_t201;
  const double _t227 = _t36*_t51;
  const double _t228 = _hc0[1]*_t206;
  const double _t229 = _t23*_t7;
  const double _t230 = _t137*_t17;
  const double _t231 = _t51*_t80;
  const double _t232 = 0.2e1*_t49;
  const double _t233 = _t124*_t51;
  const double _t234 = _t230*_t91;
  const double _t235 = _t131*_t4;
  const double _t236 = _t55*_t91;
  const double _t238 = -_hc2[11]*_t56 - _hc2[7]*_t144;
  const double _t241 = _hc0[3]*_t80;
  const double _t242 = _hc1[2]*_t157;
  const double _t244 = _t38*_t71;
  const double _t245 = _hc0[3]*_t17;
  const double _t246 = _t73*_t91;
  const double _t247 = _t61*_t7;
  const double _t249 = _t49*_t69;
  const double _t254 = _hc0[1]*_t178;
  const double d4F_dna4 = _t100*((0.560e3 / 0.27e2)*_t103*_t12 + (0.32e2 / 0.27e2)*_t106 + _t115*_t203 + _t126*_t218 + (0.28e2 / 0.27e2)*_t15*_t40 - 0.112e3 / 0.9e1*_t48*_t76) + 0.8e1*_t101*_t38 - 0.32e2 / 0.3e1*_t101*_t87 + (0.280e3 / 0.81e2)*_t103*_t11*_t6 + 0.4e1*_t116*_t19 + 0.3e1*_t116*_t219 - 0.16e2 / 0.3e1*_t116*_t31 + (0.256e3 / 0.81e2)*_t179*_t197/xc_powr(na, 25, 3) + (0.2800e4 / 0.81e2)*_t196*_t27 - 0.256e3 / 0.27e2*_t199*_t62*_t77 + _t200*_t202*_t26 + _t200*_t205*_t49 + _t203*_t204 + _t203*_t208 - 0.16e2 / 0.3e1*_t207*_t8 + _t210*_t212*(_t13*_t209 + (0.2e1 / 0.3e1)*_t34) + 0.2e1*_t213*_t215 - 0.16e2 / 0.3e1*_t213*_t87 + _t214*(0.4e1*_t13*_t48*_t6 - _t15*_t58 - _t56*_t98 - 0.28e2 / 0.3e1*_t96) + _t215*_t216 + 0.3e1*_t217*_t49 + _t50*((0.1e1 / 0.6e1)*_t1*_t2*_t7*(-_hc2[4]*_t221 - 0.224e3 / 0.27e2*_hc2[7]*_t196 - _t222*_t46) - 0.140e3 / 0.81e2*_t103*_t15 + (0.280e3 / 0.9e1)*_t103*_t48*_t6 - 0.28e2 / 0.3e1*_t115*_t76 - 0.3640e4 / 0.81e2*_t12*_t220 + (0.4e1 / 0.3e1)*_t13*_t6*(-_hc0[3]*_t221 - _t105*_t43 - 0.16e2 / 0.27e2*_t107*_t3*_t6 + (0.56e2 / 0.9e1)*_t114*_t40*_t6 - _t222*_t47 - _t46*(_hc0[6]*_t108 + _hc2[7]*_t112 + _t223*_t45 - _t46*(-_hc0[10]*_t46 - _hc2[11]*_t47))) - 0.56e2 / 0.27e2*_t195*_t98 - _t218*_t58) + 0.4e1*_t54*_t99 - 0.256e3 / 0.9e1*_t74*_t81*gaa - 0.112e3 / 0.27e2*_t76*_t84 + (0.640e3 / 0.27e2)*_t79/xc_powi(na, 7) + 0.4e1*_t93;
  const double d4F_dna3_dgaa = _t100*((0.1e1 / 0.3e1)*_t1*_t145*_t2*_t7 - _t111*_t74 + (0.8e1 / 0.3e1)*_t13*_t146*_t6 + (0.4e1 / 0.3e1)*_t13*_t21*_t48 - _t135*_t44 - _t23*_t41) + _t101*_t235 - _t105*_t22 + _t116*_t139 - _t116*_t140 + (0.14e2 / 0.27e2)*_t117*_t74 - 0.64e2 / 0.9e1*_t118*_t77 + _t119*_t198*_t32*_t6 - _t119*_t209*_t226 + (0.32e2 / 0.9e1)*_t121*_t77 - _t125*_t49*_t53 - _t127*_t212*_t4*_t89 - _t131*_t36*_t53 + _t132*_t213 - _t133*_t213*_t91 + _t137*_t232*_t39 + _t138*_t215 + _t138*_t85 - _t138*_t88 + _t144*_t84 + 0.2e1*_t147*_t219 + _t147*_t94 - _t147*_t95 - 0.4e1 / 0.3e1*_t163*_t26 - _t197*_t224 - 0.2e1*_t201*_t227 + _t205*_t61*_t83 + _t207*_t21*_t5 + _t210*_t234 + _t214*(_t127*_t13 + 0.2e1*_t134 + (0.1e1 / 0.4e1)*_t136) - _t216*_t236 + _t217*_t61 + _t224*_t225 + 0.6e1*_t227*_t228 - _t229*_t49*_t85 - 0.9e1 / 0.2e1*_t229*_t92 + _t230*_t85 - _t230*_t88 - _t231*_t232 + 0.4e1*_t233*_t49 + _t30*_t46*_t61 + _t50*((0.140e3 / 0.27e2)*_hc0[3]*_t195 + (0.140e3 / 0.27e2)*_t103*_t23 - _t110*_t146 + _t115*_t144 + (0.7e1 / 0.27e2)*_t135*_t74 - _t145*_t3*_t97 - _t21*_t41*_t48 + _t46*(_hc0[3]*_t237 + _hc0[6]*_t141 + _t113*_t143*_t21 - _t114*_t144 - _t238*_t47 - _t46*(-_hc0[10]*_t56 - _hc0[6]*_t144 - _t223*_t60)) + _t47*(_hc2[4]*_t237 + (0.22e2 / 0.9e1)*_t107 - _t238*_t46)) - 0.206e3 / 0.27e2*_t75 + 0.6e1*_t82;
  const double d4F_dna2_dgaa2 = _hc1[4]*_t239*_t29 + _t100*((0.2e1 / 0.3e1)*_t119*_t172 + (0.1e1 / 0.12e2)*_t149*_t175 - _t151*_t58 - _t174*_t59 + _t57*_t66) + _t102*_t137*_t61 - _t117*_t243*_t26 + (0.13e2 / 0.9e1)*_t119*_t148 - 0.14e2 / 0.9e1*_t119*_t154 - 0.1e1 / 0.9e1*_t119*_t155 + (0.2e1 / 0.9e1)*_t119*_t158*_t21 - _t122*_t244 + 0.3e1*_t122*_t246*_t66 - _t123*_t152 - _t124*_t249 + _t125*_t147*_t4 - 0.2e1 / 0.3e1*_t125*_t247 + _t128*_t151 + _t129*_t177 - 0.1e1 / 0.9e1*_t13*_t64 - _t130*_t231 + (0.4e1 / 0.3e1)*_t131*_t149*_t245 + _t138*_t235 - 0.3e1*_t138*_t236 - _t147*_t169*_t4 - 0.4e1*_t149*_t166*_t206*_t21 + _t149*_t201*_t23*_t32 + _t151*_t248*_t92 - _t159*_t199 + _t16*_t63*_t84 - _t160*_t204 - _t160*_t208 + _t161*_t202 + _t161*_t49*_t80 + _t162*_t38*_t49 - _t163*_t52*_t66 - _t164*_t244*_t49 - _t165*_t228*_t36 + _t177*_t219 - 0.8e1 / 0.3e1*_t177*_t31 + 0.3e1*_t212*_t69*_t73 - _t225*_t240 - 0.4e1*_t23*_t247*_t38 + _t230*_t235 + (0.16e2 / 0.3e1)*_t233*_t61 - 0.3e1*_t234*_t55 - 0.4e1 / 0.9e1*_t239*_t241 + _t240*_t242 + _t243*_t28 + (0.3e1 / 0.2e1)*_t246*_t249 + _t50*(-0.1e1 / 0.18e2*_t119*_t175 + _t14*_t146*_t21 + (0.7e1 / 0.9e1)*_t151*_t40 - _t170*_t48*_t63 - 0.7e1 / 0.9e1*_t172*_t77 + (0.1e1 / 0.18e2)*_t174*_t26 + _t46*(-_hc0[10]*_t250 + (0.1e1 / 0.3e1)*_hc0[3]*_t13*_t63 - _hc0[6]*_t251 + (0.1e1 / 0.24e2)*_hc2[7]*_t1*_t2*_t51*_t63 - _t176*_t223*_t66) + _t47*(-_hc2[11]*_t250 + (0.1e1 / 0.3e1)*_hc2[4]*_t13*_t63 - _hc2[7]*_t251) - 0.7e1 / 0.9e1*_t71*_t74) - 0.3e1 / 0.4e1*_t67*_t71*_t92;
  const double d4F_dna_dgaa3 = (0.3e1 / 0.4e1)*_hc0[1]*_hc0[3]*_hc1[0]*_t149*_t37*_t63 + (0.9e1 / 0.4e1)*_hc0[1]*_hc0[3]*_hc1[0]*_t17*_t182*_t63*_t90 + (0.3e1 / 0.2e1)*_hc0[1]*_hc1[0]*_t37*_t4*_t61*_t63 + (0.3e1 / 0.2e1)*_hc0[1]*_hc1[1]*_t17*_t180*_t37*_t67 + (0.1e1 / 0.4e1)*_hc0[1]*_hc1[1]*_t18*_t180*_t51 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[3]*_t18*_t220*_t66 + (0.3e1 / 0.4e1)*_hc0[3]*_hc1[0]*_t17*_t180*_t37*_t67 + (0.3e1 / 0.8e1)*_hc0[3]*_hc1[0]*_t18*_t180*_t51 + (0.1e1 / 0.2e1)*_hc0[3]*_hc1[2]*_t18*_t220*_t66 + (0.1e1 / 0.6e1)*_hc0[6]*_hc1[1]*_t18*_t220*_t66 - 0.1e1 / 0.4e1*_hc0[6]*_t186*_t54 + _hc1[0]*_t18*na*(_hc0[10]*_t152*_t239 - _t113*_t149*_t255 + _t13*_t178*_t68 - 0.1e1 / 0.2e1*_t134*_t180 + (0.1e1 / 0.16e2)*_t178*_t43*_t51 + (0.1e1 / 0.48e2)*_t220*_t223*_t63) + (0.9e1 / 0.2e1)*_hc1[0]*_t61*_t66*_t67*_t73*_t90 + (0.3e1 / 0.4e1)*_hc1[1]*_t149*_t37*_t63*_t73 + (0.3e1 / 0.8e1)*_hc1[1]*_t17*_t178*_t18*_t4 + (0.9e1 / 0.4e1)*_hc1[1]*_t17*_t182*_t63*_t73*_t90 + (0.3e1 / 0.2e1)*_hc1[1]*_t177*_t18*_t21*_t4 + _hc1[1]*_t191*_t220*_t66*_t90 + (0.3e1 / 0.4e1)*_hc1[2]*_t18*_t61*_t66*_t67 + (0.1e1 / 0.8e1)*_hc1[2]*_t180*_t51*_t9 + (0.1e1 / 0.8e1)*_hc1[3]*_t149*_t63*_t9 + (0.1e1 / 0.8e1)*_hc1[3]*_t17*_t18*_t182*_t63 - 0.1e1 / 0.8e1*_t11*_t178*_t7 - _t124*_t220*_t71 - 0.3e1*_t124*_t61*_t69 - _t149*_t185*_t80 - _t149*_t187*_t63 - _t149*_t188*_t189 - _t149*_t193*_t253 - 0.3e1 / 0.4e1*_t151*_t182*_t226 - _t152*_t197*_t220 - _t156*_t194*_t51 - 0.9e1 / 0.4e1*_t167*_t180*_t67 - _t168*_t253*_t30 - 0.3e1*_t17*_t186*_t191*_t211 - _t177*_t55*_t85 - _t180*_t181*_t81 - _t183*_t252*_t7 - _t190*_t245*_t86 - _t220*_t242*_t66 - 0.3e1 / 0.2e1*_t244*_t61*_t67 - _t248*_t254*_t54;
  const double d4F_dgaa4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t211*_t266 - _hc0[1]*_hc0[3]*_t265*_t38 - _hc0[10]*_t19*_t259 + ((_hc0[3]) * (_hc0[3]))*_t264*_t38 + _hc0[3]*_t124*_t266 - _hc0[3]*_t19*_t258 - 0.9e1 / 0.4e1*_hc0[3]*_t246*_t261 + (0.9e1 / 0.8e1)*_hc0[3]*_t263*_t30 + _hc0[6]*_t261*_t38*_t68 - _hc0[6]*_t262*_t30 - _hc1[1]*_t192*_t266 + _t103*_t194*_t242 - _t11*_t256 - _t117*_t260 + _t156*_t260 - _t158*_t265 + _t182*_t188*_t252 - _t182*_t252*_t78 + _t183*_t256 + (0.9e1 / 0.8e1)*_t184*_t254 + _t193*_t265 + _t197*_t259 - _t225*_t262 - _t241*_t264 + _t258*_t27;
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
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_den_k, _KMAX)(p, _t3*_t6, _t10, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_num_k, _KMAX)(p, _t10, _hc1);
  const double _t11 = (0.1e1 / (_hc0[0]));
  const double _t12 = _hc1[0]*_t11;
  const double zk = _t12;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t15 = (0.1e1 / 0.6e1)*_t7;
  const double _t16 = xc_powr(_t4, -7, 3);
  const double _t18 = (0.4e1 / 0.3e1)*_t9;
  const double _t24 = (0.1e1 / _t9);
  const double _t29 = _t24*_t5;
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_den_k, _KMAX)(p, 0, _t10, _hc2);
  const double _t13 = _hc1[1]*_t11;
  const double _t14 = _hc2[2]*_t3;
  const double _t17 = _hc0[1]*_t16;
  const double _t19 = _t14*_t15 + _t17*_t18;
  const double _t20 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t21 = _hc1[0]*_t20;
  const double _t22 = _t19*_t21;
  const double _t23 = -0.4e1 / 0.3e1*_t10*_t13 + _t12 + _t22*_t4;
  const double _t25 = _t13*_t24;
  const double _t26 = _hc0[1]*_t24;
  const double _t27 = _t21*_t26;
  const double _t28 = _t25*_t6 - _t27*_t6;
  const double _t30 = _hc0[1]*_t21;
  const double dF_dna = _t23;
  const double dF_dnb = _t23;
  const double dF_dgaa = _t28;
  const double dF_dgab = _t13*_t29 - _t29*_t30;
  const double dF_dgbb = _t28;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t31 = (0.16e2 / 0.9e1)*_t8;
  const double _t32 = xc_powr(_t4, -11, 3);
  const double _t35 = (0.4e1 / 0.9e1)*_t16;
  const double _t38 = (0.8e1 / 0.3e1)*_t10;
  const double _t43 = (0.8e1 / 0.3e1)*_t9;
  const double _t47 = xc_powr(_t4, -10, 3);
  const double _t48 = _t47*_t9;
  const double _t50 = _t32*_t9;
  const double _t51 = (0.2e1 / 0.9e1)*_t3;
  const double _t53 = _t15*_t3;
  const double _t54 = _t16*_t18;
  const double _t59 = xc_powr(_t4, -8, 3);
  const double _t60 = (0.2e1 / 0.3e1)*_t59;
  const double _t62 = (0.1e1 / 0.6e1)*_t24;
  const double _t72 = (0.1e1 / 0.12e2)*_t24;
  const double _t76 = (0.1e1 / 0.3e1)*_t24;
  const double _t80 = xc_powr(_t8, 3, 2);
  const double _t81 = (0.1e1 / _t80);
  const double _t84 = xc_powr(_t4, -5, 3);
  const double _t85 = (0.1e1 / _t8);
  const double _t86 = _t84*_t85;
  const double _t33 = _hc1[2]*_t11;
  const double _t34 = _t32*_t33;
  const double _t36 = _hc1[1]*_t20;
  const double _t37 = _t19*_t36;
  const double _t39 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t40 = _hc1[0]*_t39;
  const double _t41 = _t4*_t40;
  const double _t42 = _t14*_t7;
  const double _t44 = _t17*_t43 + (0.1e1 / 0.3e1)*_t42;
  const double _t45 = _t19*_t44;
  const double _t46 = _t14*_t16;
  const double _t49 = (0.28e2 / 0.9e1)*_hc0[1];
  const double _t52 = _hc2[4]*_t51;
  const double _t55 = -_hc0[3]*_t54 - _hc2[4]*_t53;
  const double _t56 = (0.4e1 / 0.3e1)*_t16*_t55*_t9 - 0.2e1 / 0.9e1*_t46 - _t48*_t49 - _t50*_t52;
  const double _t57 = _t21*_t4;
  const double _t58 = _t13*_t35*_t9 + 0.2e1*_t22 + _t31*_t34 - _t37*_t38 + _t41*_t45 + _t56*_t57;
  const double _t61 = _t13*_t7;
  const double _t63 = _t27*_t7;
  const double _t64 = _t19*_t40;
  const double _t65 = _hc0[1]*_t29;
  const double _t66 = _t64*_t65;
  const double _t67 = _hc0[3]*_t32;
  const double _t68 = (0.2e1 / 0.3e1)*_t67;
  const double _t69 = _t17*_t24;
  const double _t70 = _hc2[4]*_t3;
  const double _t71 = _t59*_t70;
  const double _t73 = _t68 + (0.2e1 / 0.3e1)*_t69 + _t71*_t72;
  const double _t74 = (0.2e1 / 0.3e1)*_hc0[1]*_hc1[1]*_t20*_t59 + _hc1[0]*_t20*_t4*_t73 + (0.1e1 / 0.2e1)*_hc1[1]*_t19*_t20*_t24*_t5 - _t33*_t60 - _t61*_t62 - 0.1e1 / 0.2e1*_t63 - _t66;
  const double _t75 = _t33*_t59;
  const double _t77 = (0.4e1 / 0.3e1)*_t67;
  const double _t78 = _t62*_t71 + (0.4e1 / 0.3e1)*_t69 + _t77;
  const double _t79 = (0.4e1 / 0.3e1)*_hc0[1]*_hc1[1]*_t20*_t59 + _hc1[0]*_t20*_t4*_t78 + _hc1[1]*_t19*_t20*_t24*_t5 - _t61*_t76 - _t63 - 0.2e1*_t66 - 0.4e1 / 0.3e1*_t75;
  const double _t82 = _t13*_t81;
  const double _t83 = _t5*_t82;
  const double _t87 = _hc0[1]*_t36;
  const double _t88 = _t86*_t87;
  const double _t89 = _hc0[3]*_t21;
  const double _t90 = _t86*_t89;
  const double _t91 = ((_hc0[1]) * (_hc0[1]));
  const double _t92 = (0.1e1 / 0.4e1)*_hc0[1]*_hc1[0]*_t20*_t5*_t81 + (0.1e1 / 0.2e1)*_hc1[0]*_t39*_t84*_t85*_t91 + (0.1e1 / 0.4e1)*_hc1[2]*_t11*_t84*_t85 - 0.1e1 / 0.4e1*_t83 - 0.1e1 / 0.2e1*_t88 - 0.1e1 / 0.4e1*_t90;
  const double _t93 = (0.1e1 / 0.2e1)*_hc0[1]*_hc1[0]*_t20*_t5*_t81 + _hc1[0]*_t39*_t84*_t85*_t91 + (0.1e1 / 0.2e1)*_hc1[2]*_t11*_t84*_t85 - _t6*_t82 - _t88 - 0.1e1 / 0.2e1*_t90;
  const double d2F_dna2 = _t58;
  const double d2F_dna_dnb = _t58;
  const double d2F_dnb2 = _t58;
  const double d2F_dna_dgaa = _t74;
  const double d2F_dna_dgab = _t79;
  const double d2F_dna_dgbb = _t74;
  const double d2F_dnb_dgaa = _t74;
  const double d2F_dnb_dgab = _t79;
  const double d2F_dnb_dgbb = _t74;
  const double d2F_dgaa2 = _t92;
  const double d2F_dgaa_dgab = _t93;
  const double d2F_dgaa_dgbb = _t92;
  const double d2F_dgab2 = _hc0[1]*_hc1[0]*_t20*_t5*_t81 + 0.2e1*_hc1[0]*_t39*_t84*_t85*_t91 + _hc1[2]*_t11*_t84*_t85 - _t83 - 0.2e1*_t88 - _t90;
  const double d2F_dgab_dgbb = _t93;
  const double d2F_dgbb2 = _t92;
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
  const double _t94 = xc_powr(_t4, -14, 3);
  const double _t97 = xc_powi(_t4, -6);
  const double _t103 = (0.16e2 / 0.3e1)*_t8;
  const double _t107 = 0.4e1*_t10;
  const double _t116 = (0.56e2 / 0.9e1)*_t48;
  const double _t122 = (0.14e2 / 0.27e2)*_t47;
  const double _t124 = xc_powr(_t4, -13, 3);
  const double _t125 = (0.280e3 / 0.27e2)*_t124;
  const double _t126 = (0.16e2 / 0.27e2)*_t9;
  const double _t129 = (0.28e2 / 0.9e1)*_t48;
  const double _t138 = (0.2e1 / 0.9e1)*_t16;
  const double _t140 = xc_powi(_t4, -5);
  const double _t141 = (0.8e1 / 0.9e1)*_t140;
  const double _t143 = (0.4e1 / 0.3e1)*_t59;
  const double _t145 = (0.8e1 / 0.3e1)*_t59;
  const double _t153 = _t24*_t6;
  const double _t161 = _t24*_t47;
  const double _t162 = (0.14e2 / 0.9e1)*_t161;
  const double _t163 = _t24*_t32;
  const double _t164 = (0.1e1 / 0.9e1)*_t163;
  const double _t165 = (0.2e1 / 0.3e1)*_t32;
  const double _t167 = (0.2e1 / 0.3e1)*_t24;
  const double _t168 = _t16*_t167;
  const double _t177 = (0.16e2 / 0.9e1)*_t140;
  const double _t178 = (0.16e2 / 0.3e1)*_t59;
  const double _t185 = (0.4e1 / 0.3e1)*_t32;
  const double _t187 = (0.4e1 / 0.3e1)*_t24;
  const double _t190 = _t16*_t187;
  const double _t197 = (0.1e1 / 0.3e1)*_t85;
  const double _t200 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t202 = (0.1e1 / 0.24e2)*_t85;
  const double _t205 = (0.1e1 / 0.12e2)*_t85;
  const double _t208 = _t59*_t85;
  const double _t210 = _t167*_t200;
  const double _t214 = _t5*_t81;
  const double _t216 = (0.1e1 / 0.6e1)*_t85;
  const double _t236 = _t187*_t200;
  const double _t243 = (0.8e1 / 0.3e1)*_t200;
  const double _t244 = (0.8e1 / 0.3e1)*_t24;
  const double _t245 = _t200*_t244;
  const double _t249 = xc_powr(_t8, -5, 2);
  const double _t251 = (_t8 * _t8);
  const double _t252 = (0.1e1 / _t251);
  const double _t253 = (0.3e1 / 0.8e1)*_t252;
  const double _t254 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t255 = (0.3e1 / 0.8e1)*_t249;
  const double _t257 = _t254*_t81;
  const double _t258 = (0.3e1 / 0.8e1)*_t257;
  const double _t261 = (0.3e1 / 0.4e1)*_t257;
  const double _t265 = _t252*_t84;
  const double _t266 = (0.3e1 / 0.4e1)*_t265;
  const double _t270 = (0.3e1 / 0.2e1)*_t257;
  const double _t271 = (0.3e1 / 0.2e1)*_t265;
  const double _t273 = 0.3e1*_t257;
  const double _t274 = 0.3e1*_t265;
  const double _t276 = _t249*_t5;
  const double _t278 = 0.6e1*_t257;
  const double _t95 = _t33*_t94;
  const double _t96 = (0.28e2 / 0.27e2)*_t13;
  const double _t98 = _hc1[3]*_t11;
  const double _t99 = _t80*_t98;
  const double _t100 = _hc1[2]*_t20;
  const double _t101 = _t100*_t19;
  const double _t102 = _t101*_t32;
  const double _t104 = 0.3e1*_t40;
  const double _t105 = _hc1[1]*_t39;
  const double _t106 = _t105*_t45;
  const double _t108 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t109 = _hc1[0]*_t108;
  const double _t110 = 0.4e1*_t17*_t9 + (0.1e1 / 0.2e1)*_t42;
  const double _t111 = _t110*_t45;
  const double _t112 = _t109*_t111;
  const double _t113 = 0.3e1*_t21;
  const double _t114 = 0.4e1*_t56;
  const double _t115 = _t10*_t36;
  const double _t117 = (0.4e1 / 0.9e1)*_t70;
  const double _t118 = -_hc0[1]*_t116 - _t117*_t50 + (0.8e1 / 0.3e1)*_t16*_t55*_t9 - 0.4e1 / 0.9e1*_t46;
  const double _t119 = _t19*_t41;
  const double _t120 = _t41*_t44;
  const double _t121 = 0.2e1*_t56;
  const double _t123 = _hc0[1]*_t9;
  const double _t127 = _t70*_t94;
  const double _t128 = _hc2[7]*_t94;
  const double _t130 = _hc2[4]*_t129 + _t128*_t31;
  const double _t131 = _hc2[7]*_t51;
  const double _t132 = -_hc0[6]*_t54 - _hc2[7]*_t53;
  const double _t133 = _hc0[3]*_t129 + _hc2[4]*_t16*_t51 + _t131*_t50 - _t132*_t54;
  const double _t134 = -_t116*_t55 + _t122*_t14 + _t123*_t125 + _t126*_t127 + _t130*_t53 + _t133*_t54;
  const double _t135 = _t102*_t103 + _t104*_t45 - _t106*_t107 + _t112*_t4 + _t113*_t56 - _t114*_t115 + _t118*_t119 + _t120*_t121 + _t134*_t57 + _t37*_t54 - _t48*_t96 - 0.64e2 / 0.9e1*_t8*_t95 - 0.64e2 / 0.27e2*_t97*_t99;
  const double _t136 = _t32*_t87;
  const double _t137 = (0.2e1 / 0.9e1)*_t136;
  const double _t139 = _t9*_t98;
  const double _t142 = _t100*_t123;
  const double _t144 = _t143*_t19;
  const double _t146 = _hc0[1]*_t19;
  const double _t147 = _t105*_t146;
  const double _t148 = _t145*_t147;
  const double _t149 = _t37*_t7;
  const double _t150 = _t26*_t7;
  const double _t151 = 0.2e1*_t21;
  const double _t152 = _t36*_t38;
  const double _t154 = (0.3e1 / 0.2e1)*_t109;
  const double _t155 = _t45*_t65;
  const double _t156 = _t36*_t56;
  const double _t157 = _t40*_t56;
  const double _t158 = _t157*_t65;
  const double _t159 = _hc0[3]*_t94;
  const double _t160 = (0.14e2 / 0.9e1)*_t159;
  const double _t166 = _hc2[7]*_t165;
  const double _t169 = -_hc2[4]*_t168 - _t166;
  const double _t170 = _hc0[6]*_t165;
  const double _t171 = _hc2[7]*_t3;
  const double _t172 = _t171*_t59;
  const double _t173 = -_hc0[3]*_t168 - _t170 - _t172*_t72;
  const double _t174 = -_hc0[1]*_t162 + (0.1e1 / 0.6e1)*_t1*_t169*_t2*_t7 + (0.4e1 / 0.3e1)*_t16*_t173*_t9 + (0.2e1 / 0.3e1)*_t16*_t24*_t55 - _t160 - _t164*_t70;
  const double _t175 = -_t100*_t144 + _t106*_t153 + _t119*_t78 + _t120*_t73 - _t137 + _t138*_t25 + _t139*_t141 - _t141*_t142 + _t148 - _t149*_t76 - 0.2e1*_t150*_t64 + _t151*_t73 - _t152*_t73 + _t153*_t156 - _t154*_t155 - _t158 + _t174*_t57 + 0.2e1*_t34;
  const double _t176 = (0.4e1 / 0.9e1)*_t136;
  const double _t179 = 0.4e1*_t64;
  const double _t180 = _t105*_t29;
  const double _t181 = 0.3e1*_t109;
  const double _t182 = (0.8e1 / 0.3e1)*_t67;
  const double _t183 = _t182 + (0.8e1 / 0.3e1)*_t69 + _t71*_t76;
  const double _t184 = _t29*_t36;
  const double _t186 = _hc0[6]*_t185;
  const double _t188 = -_hc0[3]*_t16*_t187 - _t172*_t62 - _t186;
  const double _t189 = _hc2[7]*_t185;
  const double _t191 = -_hc2[4]*_t190 - _t189;
  const double _t192 = (0.28e2 / 0.9e1)*_t159;
  const double _t193 = -0.4e1 / 0.3e1*_t16*_t24*_t55 + _t161*_t49 + _t163*_t52 + _t192;
  const double _t194 = (0.1e1 / 0.6e1)*_t1*_t191*_t2*_t7 + (0.4e1 / 0.3e1)*_t16*_t188*_t9 - _t193;
  const double _t195 = -_t101*_t145 + _t119*_t183 + _t120*_t78 + _t139*_t177 - _t142*_t177 + _t147*_t178 - _t149*_t167 - _t150*_t179 + _t151*_t78 - _t152*_t78 - _t155*_t181 - 0.2e1*_t158 - _t176 + _t180*_t45 + _t184*_t56 + _t194*_t57 + _t25*_t35 + 0.4e1*_t34;
  const double _t196 = _t17*_t81;
  const double _t198 = _hc0[6]*_t140;
  const double _t199 = _t71*_t81;
  const double _t201 = _t171*_t200;
  const double _t203 = -0.1e1 / 0.3e1*_t196 + _t197*_t67 + _t198*_t76 - 0.1e1 / 0.24e2*_t199 + _t201*_t202;
  const double _t204 = _t200*_t98;
  const double _t206 = _t7*_t82;
  const double _t207 = _t40*_t91;
  const double _t209 = _t207*_t208;
  const double _t211 = _t39*_t91;
  const double _t212 = _hc1[1]*_t211;
  const double _t213 = _t208*_t89;
  const double _t215 = _t214*_t37;
  const double _t217 = _t59*_t87;
  const double _t218 = _hc0[3]*_t36;
  const double _t219 = _t200*_t218;
  const double _t220 = _t30*_t7*_t81;
  const double _t221 = _t101*_t86;
  const double _t222 = _hc0[1]*_t100;
  const double _t223 = _hc0[1]*_t64;
  const double _t224 = _t223*_t81;
  const double _t225 = _t147*_t86;
  const double _t226 = _hc0[3]*_t64;
  const double _t227 = _t226*_t86;
  const double _t228 = _t19*_t91;
  const double _t229 = _t228*_t86;
  const double _t230 = _t40*_t65;
  const double _t231 = 0.2e1*_t230;
  const double _t232 = _t184*_t73 - _t231*_t73;
  const double _t233 = _t154*_t229 + _t203*_t57 - _t204*_t76 - _t205*_t75 + (0.1e1 / 0.12e2)*_t206 + (0.1e1 / 0.2e1)*_t209 - _t210*_t212 + _t210*_t222 - 0.1e1 / 0.4e1*_t213 - 0.1e1 / 0.4e1*_t215 - _t216*_t217 + _t219*_t76 + (0.1e1 / 0.4e1)*_t220 + (0.1e1 / 0.4e1)*_t221 + _t224*_t6 - _t225 - 0.1e1 / 0.2e1*_t227 + _t232;
  const double _t234 = _t167*_t198 - 0.2e1 / 0.3e1*_t196 - 0.1e1 / 0.12e2*_t199 + _t201*_t205 + _t68*_t85;
  const double _t235 = _t153*_t36;
  const double _t237 = _t37*_t81;
  const double _t238 = _t214*_t223;
  const double _t239 = _t230*_t78;
  const double _t240 = _t109*_t229;
  const double _t241 = _t15*_t82 - _t167*_t204 - _t197*_t217 + _t209 + _t210*_t218 - _t212*_t236 - 0.1e1 / 0.2e1*_t213 - _t216*_t75 + (0.1e1 / 0.2e1)*_t220 + (0.1e1 / 0.2e1)*_t221 + _t222*_t236 - 0.2e1*_t225 - _t227 + _t232 + _t234*_t57 + _t235*_t78 - _t237*_t6 + _t238 - _t239 + 0.3e1*_t240;
  const double _t242 = _t100*_t26;
  const double _t246 = 0.2e1*_t78;
  const double _t247 = _t187*_t198 - 0.4e1 / 0.3e1*_t196 - 0.1e1 / 0.6e1*_t199 + _t201*_t216 + _t77*_t85;
  const double _t248 = _t184*_t246 - _t187*_t204 + _t187*_t219 - _t197*_t75 + (0.1e1 / 0.3e1)*_t206 + 0.2e1*_t209 - _t212*_t245 - _t213 - _t215 + _t220 + _t221 - 0.4e1*_t225 - 0.2e1*_t227 + 0.2e1*_t238 - 0.4e1*_t239 + 0.6e1*_t240 + _t242*_t243 + _t247*_t57 - _t60*_t85*_t87;
  const double _t250 = _t33*_t84;
  const double _t256 = _t30*_t5;
  const double _t259 = _hc0[6]*_t21;
  const double _t260 = _t257*_t259;
  const double _t262 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t263 = _t108*_t262;
  const double _t264 = _hc1[0]*_t263;
  const double _t267 = (0.3e1 / 0.4e1)*_hc0[1]*_hc0[3]*_hc1[0]*_t254*_t39*_t81 + (0.3e1 / 0.4e1)*_hc0[1]*_hc1[1]*_t20*_t252*_t84 + (0.3e1 / 0.8e1)*_hc0[3]*_hc1[0]*_t20*_t252*_t84 + (0.3e1 / 0.8e1)*_hc1[1]*_t11*_t249*_t5 + (0.3e1 / 0.4e1)*_hc1[1]*_t254*_t39*_t81*_t91 + (0.1e1 / 0.8e1)*_hc1[3]*_t11*_t254*_t81 - _t207*_t266 - _t218*_t258 - _t222*_t258 - _t250*_t253 - _t255*_t256 - 0.1e1 / 0.8e1*_t260 - _t261*_t264;
  const double _t268 = _t250*_t252;
  const double _t269 = _t249*_t256;
  const double _t272 = (0.3e1 / 0.2e1)*_hc0[1]*_hc0[3]*_hc1[0]*_t254*_t39*_t81 + (0.3e1 / 0.2e1)*_hc0[1]*_hc1[1]*_t20*_t252*_t84 + (0.3e1 / 0.4e1)*_hc0[3]*_hc1[0]*_t20*_t252*_t84 + (0.3e1 / 0.4e1)*_hc1[1]*_t11*_t249*_t5 + (0.3e1 / 0.2e1)*_hc1[1]*_t254*_t39*_t81*_t91 + (0.1e1 / 0.4e1)*_hc1[3]*_t11*_t254*_t81 - _t207*_t271 - _t218*_t261 - _t222*_t261 - 0.1e1 / 0.4e1*_t260 - _t264*_t270 - 0.3e1 / 0.4e1*_t268 - 0.3e1 / 0.4e1*_t269;
  const double _t275 = 0.3e1*_hc0[1]*_hc0[3]*_hc1[0]*_t254*_t39*_t81 + 0.3e1*_hc0[1]*_hc1[1]*_t20*_t252*_t84 + (0.3e1 / 0.2e1)*_hc0[3]*_hc1[0]*_t20*_t252*_t84 + (0.3e1 / 0.2e1)*_hc1[1]*_t11*_t249*_t5 + 0.3e1*_hc1[1]*_t254*_t39*_t81*_t91 + (0.1e1 / 0.2e1)*_hc1[3]*_t11*_t254*_t81 - _t207*_t274 - _t218*_t270 - _t222*_t270 - 0.1e1 / 0.2e1*_t260 - _t264*_t273 - 0.3e1 / 0.2e1*_t268 - 0.3e1 / 0.2e1*_t269;
  const double _t277 = _hc0[1]*_t113;
  const double d3F_dna3 = _t135;
  const double d3F_dna2_dnb = _t135;
  const double d3F_dna_dnb2 = _t135;
  const double d3F_dnb3 = _t135;
  const double d3F_dna2_dgaa = _t175;
  const double d3F_dna2_dgab = _t195;
  const double d3F_dna2_dgbb = _t175;
  const double d3F_dna_dnb_dgaa = _t175;
  const double d3F_dna_dnb_dgab = _t195;
  const double d3F_dna_dnb_dgbb = _t175;
  const double d3F_dnb2_dgaa = _t175;
  const double d3F_dnb2_dgab = _t195;
  const double d3F_dnb2_dgbb = _t175;
  const double d3F_dna_dgaa2 = _t233;
  const double d3F_dna_dgaa_dgab = _t241;
  const double d3F_dna_dgaa_dgbb = _t233;
  const double d3F_dna_dgab2 = _t248;
  const double d3F_dna_dgab_dgbb = _t241;
  const double d3F_dna_dgbb2 = _t233;
  const double d3F_dnb_dgaa2 = _t233;
  const double d3F_dnb_dgaa_dgab = _t241;
  const double d3F_dnb_dgaa_dgbb = _t233;
  const double d3F_dnb_dgab2 = _t248;
  const double d3F_dnb_dgab_dgbb = _t241;
  const double d3F_dnb_dgbb2 = _t233;
  const double d3F_dgaa3 = _t267;
  const double d3F_dgaa2_dgab = _t272;
  const double d3F_dgaa2_dgbb = _t267;
  const double d3F_dgaa_dgab2 = _t275;
  const double d3F_dgaa_dgab_dgbb = _t272;
  const double d3F_dgaa_dgbb2 = _t267;
  const double d3F_dgab3 = 0.6e1*_hc0[1]*_hc0[3]*_hc1[0]*_t254*_t39*_t81 + 0.6e1*_hc0[1]*_hc1[1]*_t20*_t252*_t84 + 0.3e1*_hc0[3]*_hc1[0]*_t20*_t252*_t84 + 0.3e1*_hc1[1]*_t11*_t249*_t5 + 0.6e1*_hc1[1]*_t254*_t39*_t81*_t91 + _hc1[3]*_t11*_t254*_t81 - 0.6e1*_t207*_t265 - _t218*_t273 - _t222*_t273 - _t260 - _t264*_t278 - 0.3e1*_t268 - _t276*_t277;
  const double d3F_dgab2_dgbb = _t275;
  const double d3F_dgab_dgbb2 = _t272;
  const double d3F_dgbb3 = _t267;
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
  const double _t279 = xc_powr(_t4, -17, 3);
  const double _t280 = _t279*_t8;
  const double _t284 = (0.32e2 / 0.3e1)*_t32*_t8;
  const double _t287 = _t16*_t43;
  const double _t291 = (0.16e2 / 0.3e1)*_t9;
  const double _t298 = (0.28e2 / 0.3e1)*_t48;
  const double _t308 = xc_powr(_t4, -16, 3);
  const double _t309 = _t125*_t9;
  const double _t313 = _t8/xc_powr(_t4, 22, 3);
  const double _t323 = _t103*_t32;
  const double _t329 = _t24*_t7;
  const double _t366 = (0.28e2 / 0.9e1)*_t161;
  const double _t369 = xc_powr(_t4, -19, 3);
  const double _t370 = (0.4e1 / 0.9e1)*_t369;
  const double _t371 = (0.8e1 / 0.9e1)*_t369;
  const double _t375 = _t140*_t24;
  const double _t380 = _t60*_t85;
  const double _t385 = _t200*_t24;
  const double _t407 = _t6*_t81;
  const double _t413 = _t47*_t81;
  const double _t416 = _t32*_t81;
  const double _t418 = _t140*_t85;
  const double _t421 = (0.1e1 / 0.3e1)*_t81;
  const double _t423 = _t140*_t76;
  const double _t424 = _t197*_t32;
  const double _t427 = (0.16e2 / 0.9e1)*_t369;
  const double _t432 = (0.2e1 / 0.3e1)*_t81;
  const double _t433 = _t140*_t167;
  const double _t435 = (0.32e2 / 0.9e1)*_t369;
  const double _t437 = _t140*_t187;
  const double _t442 = _t200*_t81;
  const double _t443 = (0.3e1 / 0.8e1)*_t442;
  const double _t445 = _t308*_t85;
  const double _t449 = (0.3e1 / 0.4e1)*_t442;
  const double _t468 = (0.3e1 / 0.2e1)*_t442;
  const double _t476 = 0.3e1*_t442;
  const double _t481 = xc_powr(_t8, -7, 2);
  const double _t483 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t486 = _t124*_t252;
  const double _t489 = _t483*_t84;
  const double _t490 = (0.15e2 / 0.8e1)*_t489;
  const double _t491 = _t249*_t254;
  const double _t492 = (0.9e1 / 0.8e1)*_t491;
  const double _t496 = (0.3e1 / 0.8e1)*_t486;
  const double _t498 = (0.9e1 / 0.4e1)*_t491;
  const double _t500 = (0.3e1 / 0.2e1)*_t486;
  const double _t505 = (0.3e1 / 0.4e1)*_t486;
  const double _t512 = (0.15e2 / 0.4e1)*_t489;
  const double _t514 = (0.9e1 / 0.2e1)*_t491;
  const double _t515 = 0.3e1*_t486;
  const double _t518 = (0.15e2 / 0.2e1)*_t489;
  const double _t519 = 0.9e1*_t491;
  const double _t520 = 0.6e1*_t486;
  const double _t522 = 0.15e2*_t489;
  const double _t523 = 0.18e2*_t491;
  const double _t524 = 0.12e2*_t486;
  const double _t526 = 0.30e2*_t489;
  const double _t527 = 0.36e2*_t491;
  const double _t528 = 0.24e2*_t486;
  const double _t281 = _hc1[4]*_t11;
  const double _t282 = _hc1[3]*_t20;
  const double _t283 = _t19*_t282;
  const double _t285 = _hc1[2]*_t39;
  const double _t286 = _t285*_t45;
  const double _t288 = _hc1[1]*_t108;
  const double _t289 = _t111*_t288;
  const double _t290 = _t100*_t56;
  const double _t292 = xc_powi((_hc0[0]), -5);
  const double _t293 = _hc1[0]*_t292;
  const double _t294 = _t111*_t293;
  const double _t295 = _t118*_t19;
  const double _t296 = _t10*_t105;
  const double _t297 = _t44*_t56;
  const double _t299 = _t70*_t9;
  const double _t300 = _t109*_t4;
  const double _t301 = _t300*_t45;
  const double _t302 = _t110*_t300;
  const double _t303 = _t19*_t302;
  const double _t304 = 0.3e1*_t56;
  const double _t305 = _t302*_t44;
  const double _t306 = _t118*_t41;
  const double _t307 = _t130*_t3;
  const double _t310 = _hc2[11]*_t31*_t94 + _hc2[7]*_t129;
  const double _t311 = -0.16e2 / 0.3e1*_t10*_t289 - 0.256e3 / 0.9e1*_t101*_t8*_t94 + _t106*_t287 + 0.4e1*_t112 - 0.16e2 / 0.3e1*_t115*_t134 + _t118*_t179 + 0.2e1*_t118*_t303 + _t119*((0.560e3 / 0.27e2)*_t123*_t124 + (0.32e2 / 0.27e2)*_t127*_t9 + _t133*_t287 + (0.28e2 / 0.27e2)*_t14*_t47 + (0.1e1 / 0.3e1)*_t307*_t7 - 0.112e3 / 0.9e1*_t48*_t55) + 0.3e1*_t120*_t134 + (0.280e3 / 0.81e2)*_t124*_t13*_t9 + 0.4e1*_t134*_t21 + _t156*_t287 + 0.8e1*_t157*_t44 + (0.256e3 / 0.81e2)*_t251*_t281/xc_powr(_t4, 25, 3) + (0.2800e4 / 0.81e2)*_t280*_t33 - 0.256e3 / 0.27e2*_t283*_t80*_t97 + _t284*_t286 + _t284*_t290 + _t294*_t4*(_t17*_t291 + (0.2e1 / 0.3e1)*_t42) - 0.16e2 / 0.3e1*_t295*_t296 - 0.32e2 / 0.3e1*_t296*_t297 + _t301*(-_hc0[1]*_t298 + 0.4e1*_t16*_t55*_t9 - _t165*_t299 - 0.2e1 / 0.3e1*_t46) + _t304*_t305 + _t304*_t306 - 0.112e3 / 0.27e2*_t37*_t48 + _t57*((0.1e1 / 0.6e1)*_t1*_t2*_t7*(-_hc2[4]*_t309 - 0.224e3 / 0.27e2*_hc2[7]*_t280 - _t310*_t54) - 0.3640e4 / 0.81e2*_t123*_t308 - 0.140e3 / 0.81e2*_t124*_t14 + (0.280e3 / 0.9e1)*_t124*_t55*_t9 - _t133*_t298 - 0.2e1 / 0.3e1*_t16*_t307 + (0.4e1 / 0.3e1)*_t16*_t9*(-_hc0[3]*_t309 - _t122*_t70 - _t126*_t128*_t3 + (0.56e2 / 0.9e1)*_t132*_t47*_t9 - _t310*_t53 - _t54*(_hc0[6]*_t129 + _hc2[11]*_t50*_t51 + _t131*_t16 - _t54*(-_hc0[10]*_t54 - _hc2[11]*_t53))) - 0.56e2 / 0.27e2*_t279*_t299) + (0.640e3 / 0.27e2)*_t99/xc_powi(_t4, 7);
  const double _t312 = _t87*_t94;
  const double _t314 = _t281*_t313;
  const double _t315 = _hc0[1]*_t282;
  const double _t316 = _t313*_t315;
  const double _t317 = _t139*_t97;
  const double _t318 = _t142*_t97;
  const double _t319 = _t140*_t283;
  const double _t320 = _t19*_t285;
  const double _t321 = _t123*_t140;
  const double _t322 = _t100*_t73;
  const double _t324 = _t36*_t54;
  const double _t325 = _t45*_t59;
  const double _t326 = _t285*_t325;
  const double _t327 = _hc0[1]*_t288;
  const double _t328 = _t325*_t327;
  const double _t330 = _t106*_t329;
  const double _t331 = _t109*_t45;
  const double _t332 = _t150*_t331;
  const double _t333 = _t104*_t19;
  const double _t334 = _t104*_t44;
  const double _t335 = _t19*_t78;
  const double _t336 = _t105*_t107;
  const double _t337 = _t336*_t44;
  const double _t338 = _t100*_t59;
  const double _t339 = _hc0[1]*_t105;
  const double _t340 = _t339*_t59;
  const double _t341 = _t294*_t65;
  const double _t342 = 0.2e1*_t67;
  const double _t343 = _t24*_t71;
  const double _t344 = _t156*_t329;
  const double _t345 = _t180*_t44;
  const double _t346 = _t295*_t65;
  const double _t347 = _t44*_t65;
  const double _t348 = 0.4e1*_t115;
  const double _t349 = 0.2e1*_t120;
  const double _t350 = _t134*_t230;
  const double _t351 = _hc0[3]*_t279;
  const double _t352 = _t127*_t24;
  const double _t353 = _t161*_t55;
  const double _t354 = -_hc2[11]*_t165 - _hc2[7]*_t168;
  const double _t355 = _hc0[6]*_t94;
  const double _t356 = _hc2[11]*_t3;
  const double _t357 = _t356*_t59;
  const double _t358 = 0.6e1*_t102 - _t104*_t150*_t56 + _t105*_t153*_t295 - _t109*_t304*_t347 + _t113*_t174 + _t114*_t340 + _t119*((0.1e1 / 0.3e1)*_t1*_t169*_t2*_t7 + (0.8e1 / 0.3e1)*_t16*_t173*_t9 - _t193) - _t121*_t338 + _t121*_t41*_t78 - 0.14e2 / 0.27e2*_t13*_t161 + _t134*_t235 - _t147*_t185 + _t153*_t289 - _t154*_t346 + _t168*_t37 - _t174*_t348 + _t174*_t349 + _t301*(_t342 + (0.1e1 / 0.4e1)*_t343 + 0.2e1*_t69) + _t302*_t335 + _t305*_t73 + _t306*_t73 + (0.14e2 / 0.27e2)*_t312 - 0.32e2 / 0.27e2*_t314 + (0.32e2 / 0.27e2)*_t316 - 0.64e2 / 0.9e1*_t317 + (0.32e2 / 0.9e1)*_t318 + _t319*_t43 - 0.16e2 / 0.3e1*_t320*_t321 + _t322*_t323 + _t324*_t73 - 0.2e1*_t326 + 0.6e1*_t328 - 0.1e1 / 0.2e1*_t330 - 0.9e1 / 0.2e1*_t332 + _t333*_t78 + _t334*_t73 - _t335*_t336 - _t337*_t73 - 0.2e1*_t341 - 0.1e1 / 0.2e1*_t344 + _t345*_t56 - _t350 + _t57*(-_t116*_t173 + (0.140e3 / 0.27e2)*_t124*_t26 + _t133*_t168 - _t169*_t3*_t35 + (0.140e3 / 0.27e2)*_t351 + (0.7e1 / 0.27e2)*_t352 - 0.28e2 / 0.9e1*_t353 + _t53*(_hc2[4]*_t162 + (0.22e2 / 0.9e1)*_t128 - _t354*_t54) + _t54*(_hc0[3]*_t162 - _t132*_t168 + _t164*_t171 - _t354*_t53 + (0.14e2 / 0.9e1)*_t355 - _t54*(-_hc0[10]*_t165 - _hc0[6]*_t168 - _t357*_t72))) - 0.206e3 / 0.27e2*_t95;
  const double _t359 = (0.32e2 / 0.3e1)*_t320;
  const double _t360 = _t100*_t78;
  const double _t361 = _t183*_t19;
  const double _t362 = 0.4e1*_t67;
  const double _t363 = 0.6e1*_t109;
  const double _t364 = _t363*_t65;
  const double _t365 = _t183*_t41;
  const double _t367 = -_hc2[11]*_t185 - _hc2[7]*_t190;
  const double _t368 = 0.12e2*_t102 + _t113*_t194 - _t114*_t338 + _t119*(-0.56e2 / 0.9e1*_hc0[1]*_t161 + (0.1e1 / 0.3e1)*_t1*_t191*_t2*_t7 - _t117*_t163 - 0.56e2 / 0.9e1*_t159 + (0.8e1 / 0.3e1)*_t16*_t188*_t9 + (0.8e1 / 0.3e1)*_t16*_t24*_t55) + _t121*_t345 + _t121*_t365 + _t134*_t184 - 0.8e1 / 0.3e1*_t147*_t32 - 0.6e1*_t150*_t157 - _t161*_t96 + _t180*_t295 - _t181*_t346 + _t183*_t303 + _t183*_t333 + _t190*_t37 - _t194*_t348 + _t194*_t349 + _t289*_t29 + _t291*_t319 - _t297*_t364 + _t301*((0.1e1 / 0.2e1)*_t343 + _t362 + 0.4e1*_t69) + _t305*_t78 + _t306*_t78 + (0.28e2 / 0.27e2)*_t312 - 0.64e2 / 0.27e2*_t314 + (0.64e2 / 0.27e2)*_t316 - 0.128e3 / 0.9e1*_t317 + (0.64e2 / 0.9e1)*_t318 - _t321*_t359 + _t323*_t360 + _t324*_t78 - 0.4e1*_t326 + 0.12e2*_t328 - _t330 - 0.9e1*_t332 + _t334*_t78 - _t336*_t361 - _t337*_t78 + 0.8e1*_t340*_t56 - 0.4e1*_t341 - _t344 - 0.2e1*_t350 + _t57*(-_t116*_t188 + _t125*_t26 + _t133*_t190 - _t191*_t3*_t35 + (0.280e3 / 0.27e2)*_t351 + (0.14e2 / 0.27e2)*_t352 - 0.56e2 / 0.9e1*_t353 + _t53*(_hc2[4]*_t366 + (0.44e2 / 0.9e1)*_t128 - _t367*_t54) + _t54*(_hc0[3]*_t366 + _t131*_t163 - _t132*_t190 + (0.28e2 / 0.9e1)*_t355 - _t367*_t53 - _t54*(-_hc0[10]*_t185 - _hc0[6]*_t190 - _t357*_t62))) - 0.412e3 / 0.27e2*_t95;
  const double _t372 = _hc0[3]*_t100;
  const double _t373 = _hc1[2]*_t211;
  const double _t374 = _t34*_t85;
  const double _t376 = _t375*_t98;
  const double _t377 = _t140*_t242;
  const double _t378 = _t218*_t375;
  const double _t379 = _t101*_t59;
  const double _t381 = _t208*_t226;
  const double _t382 = _hc0[3]*_t105*_t19;
  const double _t383 = _t109*_t228;
  const double _t384 = _t208*_t383;
  const double _t386 = _t228*_t288*_t385;
  const double _t387 = _t145*_t322;
  const double _t388 = _t339*_t73;
  const double _t389 = _t36*_t7;
  const double _t390 = _t167*_t389*_t73;
  const double _t391 = _t150*_t40;
  const double _t392 = 0.4e1*_t391*_t73;
  const double _t393 = _t106*_t214;
  const double _t394 = _t286*_t86;
  const double _t395 = (0.3e1 / 0.4e1)*_t331;
  const double _t396 = _hc0[1]*_t214;
  const double _t397 = _t327*_t86;
  const double _t398 = _t397*_t45;
  const double _t399 = _hc0[3]*_t86;
  const double _t400 = 0.3e1*_t45;
  const double _t401 = _t86*_t91;
  const double _t402 = _t293*_t401;
  const double _t403 = _t181*_t335*_t65;
  const double _t404 = _t181*_t347*_t73;
  const double _t405 = _t156*_t214;
  const double _t406 = _t290*_t86;
  const double _t408 = _hc0[1]*_t157;
  const double _t409 = _t339*_t86;
  const double _t410 = _t157*_t399;
  const double _t411 = _t401*_t56;
  const double _t412 = _t174*_t231;
  const double _t414 = _hc0[1]*_t413;
  const double _t415 = _hc0[6]*_t24*_t97;
  const double _t417 = _t416*_t70;
  const double _t419 = _t171*_t418;
  const double _t420 = _t16*_t55;
  const double _t422 = _t173*_t190;
  const double _t425 = _t200*_t356;
  const double _t426 = _t119*_t234 + _t120*_t203 - 0.1e1 / 0.9e1*_t136*_t85 - _t147*_t380 + _t15*_t237 + _t151*_t203 - _t152*_t203 + _t154*_t411 - 0.1e1 / 0.9e1*_t16*_t82 + _t174*_t184 + _t178*_t388 + _t180*_t335 - _t210*_t283 + (0.2e1 / 0.9e1)*_t212*_t375 - _t216*_t379 + _t224*_t7 + _t236*_t382 + _t243*_t26*_t320 + _t246*_t41*_t73 + _t281*_t370 - _t315*_t371 + _t345*_t73 - _t370*_t372 + _t371*_t373 + (0.1e1 / 0.9e1)*_t374 + (0.13e2 / 0.9e1)*_t376 - 0.14e2 / 0.9e1*_t377 - 0.1e1 / 0.9e1*_t378 - _t381 + 0.3e1*_t384 - 0.4e1*_t386 - _t387 - _t390 - _t392 - 0.1e1 / 0.4e1*_t393 + (0.1e1 / 0.4e1)*_t394 + _t395*_t396 - _t395*_t399 - 0.3e1 / 0.2e1*_t398 + _t400*_t402 - _t403 - _t404 - 0.1e1 / 0.4e1*_t405 + (0.1e1 / 0.4e1)*_t406 + _t407*_t408 - _t409*_t56 - 0.1e1 / 0.2e1*_t410 - _t412 + _t57*(-0.7e1 / 0.9e1*_t159*_t85 + (0.7e1 / 0.9e1)*_t414 - 0.7e1 / 0.9e1*_t415 + (0.1e1 / 0.18e2)*_t417 - 0.1e1 / 0.18e2*_t419 - _t420*_t421 + _t422 + _t53*(-_hc2[11]*_t423 + (0.1e1 / 0.3e1)*_hc2[4]*_t16*_t81 - _hc2[7]*_t424) + _t54*(-_hc0[10]*_t423 + (0.1e1 / 0.3e1)*_hc0[3]*_t16*_t81 - _hc0[6]*_t424 + (0.1e1 / 0.24e2)*_hc2[7]*_t1*_t2*_t59*_t81 - _t202*_t425));
  const double _t428 = _t389*_t78;
  const double _t429 = _t154*_t65;
  const double _t430 = _t44*_t78;
  const double _t431 = _t194*_t230;
  const double _t434 = (0.3e1 / 0.2e1)*_hc0[1]*_hc1[0]*_t108*_t19*_t44*_t5*_t81 + 0.2e1*_hc0[1]*_hc1[0]*_t19*_t39*_t7*_t81 + _hc0[1]*_hc1[0]*_t39*_t5*_t56*_t81 + (0.16e2 / 0.3e1)*_hc0[1]*_hc1[1]*_t39*_t59*_t73 + (0.8e1 / 0.3e1)*_hc0[1]*_hc1[1]*_t39*_t59*_t78 + (0.16e2 / 0.3e1)*_hc0[1]*_hc1[2]*_t19*_t200*_t24*_t39 + (0.8e1 / 0.3e1)*_hc0[3]*_hc1[1]*_t19*_t200*_t24*_t39 + 0.6e1*_hc1[0]*_t108*_t19*_t59*_t85*_t91 + 0.3e1*_hc1[0]*_t108*_t56*_t84*_t85*_t91 + _hc1[0]*_t183*_t39*_t4*_t73 + _hc1[0]*_t19*_t247*_t39*_t4 + 0.6e1*_hc1[0]*_t19*_t292*_t44*_t84*_t85*_t91 + 0.2e1*_hc1[0]*_t20*_t234 + _hc1[0]*_t20*_t4*(-_t160*_t85 + _t168*_t188 + (0.14e2 / 0.9e1)*_t414 - 0.14e2 / 0.9e1*_t415 + (0.1e1 / 0.9e1)*_t417 - 0.1e1 / 0.9e1*_t419 - _t420*_t432 + _t422 + _t53*(-_hc2[11]*_t433 + (0.2e1 / 0.3e1)*_hc2[4]*_t16*_t81 - _t166*_t85) + _t54*(-_hc0[10]*_t433 + (0.2e1 / 0.3e1)*_hc0[3]*_t16*_t81 + (0.1e1 / 0.12e2)*_hc2[7]*_t1*_t2*_t59*_t81 - _t170*_t85 - _t205*_t425)) + _hc1[0]*_t234*_t39*_t4*_t44 + _hc1[0]*_t39*_t4*(_t78 * _t78) + (0.4e1 / 0.9e1)*_hc1[1]*_t140*_t24*_t39*_t91 + _hc1[1]*_t174*_t20*_t24*_t5 + (0.1e1 / 0.2e1)*_hc1[1]*_t183*_t19*_t24*_t39*_t5 + (0.1e1 / 0.3e1)*_hc1[1]*_t19*_t20*_t7*_t81 + _hc1[1]*_t19*_t24*_t39*_t5*_t78 + (0.1e1 / 0.2e1)*_hc1[1]*_t194*_t20*_t24*_t5 + _hc1[1]*_t24*_t39*_t44*_t5*_t73 + (0.1e1 / 0.2e1)*_hc1[1]*_t24*_t39*_t44*_t5*_t78 + (0.2e1 / 0.9e1)*_hc1[2]*_t11*_t32*_t85 + (0.1e1 / 0.2e1)*_hc1[2]*_t19*_t39*_t44*_t84*_t85 + (0.1e1 / 0.2e1)*_hc1[2]*_t20*_t56*_t84*_t85 + (0.16e2 / 0.9e1)*_hc1[2]*_t369*_t39*_t91 + (0.26e2 / 0.9e1)*_hc1[3]*_t11*_t140*_t24 + (0.8e1 / 0.9e1)*_hc1[4]*_t11*_t369 - _t100*_t375*_t49 - _t106*_t407 - _t121*_t409 - _t137*_t85 - _t138*_t82 - _t143*_t360 - _t144*_t339*_t85 - _t152*_t234 - _t154*_t399*_t45 - _t156*_t407 - _t197*_t379 - _t236*_t283 - _t246*_t391 - _t315*_t427 - _t361*_t429 - _t371*_t372 - 0.2e1 / 0.9e1*_t378 - 0.2e1*_t381 - 0.8e1*_t386 - _t387 - _t390 - _t392 - _t397*_t400 - _t403 - _t404 - _t410 - _t412 - _t428*_t76 - _t429*_t430 - _t431;
  const double _t436 = _t181*_t45;
  const double _t438 = _hc0[1]*_t179*_t7*_t81 - _hc0[3]*_t179*_t208 - _t101*_t380 - _t114*_t409 + _t119*(_t182*_t85 - 0.8e1 / 0.3e1*_t196 + _t197*_t201 + _t198*_t244 - _t421*_t71) + _t120*_t247 + _t141*_t212*_t24 - _t148*_t85 + _t149*_t432 + _t151*_t247 - _t152*_t247 - _t176*_t85 + 0.2e1*_t180*_t361 + 0.2e1*_t184*_t194 - _t187*_t428 + _t200*_t26*_t359 + 0.2e1*_t214*_t408 - _t245*_t283 + _t246*_t345 + _t246*_t365 + (0.16e2 / 0.9e1)*_t281*_t369 - _t315*_t435 - 0.16e2 / 0.3e1*_t338*_t78 + (0.32e2 / 0.3e1)*_t340*_t78 - _t35*_t82 - _t361*_t364 + _t363*_t411 - _t364*_t430 - _t372*_t427 + _t373*_t435 + (0.4e1 / 0.9e1)*_t374 + (0.52e2 / 0.9e1)*_t376 - 0.56e2 / 0.9e1*_t377 - 0.4e1 / 0.9e1*_t378 + (0.16e2 / 0.3e1)*_t382*_t385 + 0.12e2*_t384 - 0.16e2*_t386 - 0.8e1*_t391*_t78 - _t393 + _t394 + _t396*_t436 - 0.6e1*_t398 - _t399*_t436 + 0.12e2*_t402*_t45 - _t405 + _t406 - 0.2e1*_t410 - 0.4e1*_t431 + _t57*(-_t131*_t418 + _t16*_t188*_t244 - _t192*_t85 + _t413*_t49 - 0.28e2 / 0.9e1*_t415 + _t416*_t52 - 0.4e1 / 0.3e1*_t420*_t81 + _t53*(-_hc2[11]*_t437 + (0.4e1 / 0.3e1)*_hc2[4]*_t16*_t81 - _t189*_t85) + _t54*(-_hc0[10]*_t437 + (0.4e1 / 0.3e1)*_hc0[3]*_t16*_t81 + (0.1e1 / 0.6e1)*_hc2[7]*_t1*_t2*_t59*_t81 - _t186*_t85 - _t216*_t425));
  const double _t439 = _t249*_t61;
  const double _t440 = _t281*_t308;
  const double _t441 = _t30*_t7;
  const double _t444 = _t259*_t442;
  const double _t446 = _hc0[1]*_hc0[3];
  const double _t447 = _hc1[1]*_t39*_t445*_t446;
  const double _t448 = _t373*_t445;
  const double _t450 = _t207*_t252*_t59;
  const double _t451 = _t223*_t276;
  const double _t452 = _t146*_t285;
  const double _t453 = _hc0[6]*_t257*_t64;
  const double _t454 = _t19*_t262*_t293;
  const double _t455 = _t265*_t383;
  const double _t456 = _t214*_t36;
  const double _t457 = _t456*_t73;
  const double _t458 = _t388*_t86;
  const double _t459 = _t399*_t40;
  const double _t460 = _t17*_t249;
  const double _t461 = _hc0[10]*_t369;
  const double _t462 = _t252*_t67;
  const double _t463 = _t308*_t356*_t81;
  const double _t464 = _t249*_t71;
  const double _t465 = _t201*_t252;
  const double _t466 = (0.9e1 / 0.4e1)*_hc0[1]*_hc0[3]*_hc1[0]*_t108*_t19*_t254*_t81 + (0.3e1 / 0.4e1)*_hc0[1]*_hc0[3]*_hc1[0]*_t200*_t39*_t81 + (0.3e1 / 0.2e1)*_hc0[1]*_hc1[0]*_t39*_t5*_t73*_t81 + (0.3e1 / 0.2e1)*_hc0[1]*_hc1[1]*_t19*_t252*_t39*_t84 + (0.1e1 / 0.4e1)*_hc0[1]*_hc1[1]*_t20*_t252*_t59 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[3]*_t20*_t308*_t85 + (0.3e1 / 0.4e1)*_hc0[3]*_hc1[0]*_t19*_t252*_t39*_t84 + (0.3e1 / 0.8e1)*_hc0[3]*_hc1[0]*_t20*_t252*_t59 + (0.1e1 / 0.2e1)*_hc0[3]*_hc1[2]*_t20*_t308*_t85 + (0.1e1 / 0.6e1)*_hc0[6]*_hc1[1]*_t20*_t308*_t85 + (0.9e1 / 0.2e1)*_hc1[0]*_t108*_t73*_t84*_t85*_t91 + _hc1[0]*_t20*_t4*(_t216*_t461 + (0.1e1 / 0.2e1)*_t460 - 0.1e1 / 0.2e1*_t462 + (0.1e1 / 0.48e2)*_t463 + (0.1e1 / 0.16e2)*_t464 - 0.1e1 / 0.16e2*_t465) + (0.9e1 / 0.4e1)*_hc1[1]*_t108*_t19*_t254*_t81*_t91 + _hc1[1]*_t108*_t262*_t308*_t85 + (0.3e1 / 0.8e1)*_hc1[1]*_t19*_t20*_t249*_t5 + (0.3e1 / 0.2e1)*_hc1[1]*_t20*_t203*_t24*_t5 + (0.3e1 / 0.4e1)*_hc1[1]*_t200*_t39*_t81*_t91 + (0.1e1 / 0.8e1)*_hc1[2]*_t11*_t252*_t59 + (0.3e1 / 0.4e1)*_hc1[2]*_t20*_t73*_t84*_t85 + (0.1e1 / 0.8e1)*_hc1[3]*_t11*_t200*_t81 + (0.1e1 / 0.8e1)*_hc1[3]*_t19*_t20*_t254*_t81 - _t101*_t253*_t84 - _t104*_t203*_t65 - _t216*_t440 - _t218*_t443 - _t222*_t443 - _t255*_t441 - _t261*_t382 - _t261*_t452 - _t264*_t449 - _t273*_t454 - 0.1e1 / 0.8e1*_t439 - 0.1e1 / 0.8e1*_t444 - _t447 - _t448 - 0.3e1 / 0.4e1*_t450 - 0.3e1 / 0.4e1*_t451 - 0.1e1 / 0.4e1*_t453 - 0.9e1 / 0.4e1*_t455 - 0.3e1 / 0.4e1*_t457 - 0.3e1*_t458 - 0.3e1 / 0.2e1*_t459*_t73;
  const double _t467 = _t456*_t78;
  const double _t469 = _t249*_t441;
  const double _t470 = _t409*_t78;
  const double _t471 = _t459*_t78;
  const double _t472 = -0.2e1*_hc0[1]*_hc1[0]*_t39*_t5*_t73*_t81 - 0.6e1*_hc1[0]*_t108*_t73*_t84*_t85*_t91 - _hc1[2]*_t20*_t73*_t84*_t85 + _t457 + 0.4e1*_t458 + 0.2e1*_t459*_t73;
  const double _t473 = (0.9e1 / 0.2e1)*_hc0[1]*_hc0[3]*_hc1[0]*_t108*_t19*_t254*_t81 + (0.3e1 / 0.2e1)*_hc0[1]*_hc0[3]*_hc1[0]*_t200*_t39*_t81 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[0]*_t39*_t5*_t78*_t81 + 0.3e1*_hc0[1]*_hc1[1]*_t19*_t252*_t39*_t84 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[1]*_t20*_t252*_t59 + _hc0[1]*_hc1[3]*_t20*_t308*_t85 + (0.3e1 / 0.2e1)*_hc0[3]*_hc1[0]*_t19*_t252*_t39*_t84 + (0.3e1 / 0.4e1)*_hc0[3]*_hc1[0]*_t20*_t252*_t59 + _hc0[3]*_hc1[2]*_t20*_t308*_t85 + (0.1e1 / 0.3e1)*_hc0[6]*_hc1[1]*_t20*_t308*_t85 + (0.3e1 / 0.2e1)*_hc1[0]*_t108*_t78*_t84*_t85*_t91 + _hc1[0]*_t20*_t4*(_t197*_t461 + _t460 - _t462 + (0.1e1 / 0.24e2)*_t463 + (0.1e1 / 0.8e1)*_t464 - 0.1e1 / 0.8e1*_t465) + (0.9e1 / 0.2e1)*_hc1[1]*_t108*_t19*_t254*_t81*_t91 + 0.2e1*_hc1[1]*_t108*_t262*_t308*_t85 + (0.3e1 / 0.4e1)*_hc1[1]*_t19*_t20*_t249*_t5 + _hc1[1]*_t20*_t203*_t24*_t5 + _hc1[1]*_t20*_t234*_t24*_t5 + (0.3e1 / 0.2e1)*_hc1[1]*_t200*_t39*_t81*_t91 + (0.1e1 / 0.4e1)*_hc1[2]*_t11*_t252*_t59 + (0.1e1 / 0.4e1)*_hc1[2]*_t20*_t78*_t84*_t85 + (0.1e1 / 0.4e1)*_hc1[3]*_t11*_t200*_t81 + (0.1e1 / 0.4e1)*_hc1[3]*_t19*_t20*_t254*_t81 - _t101*_t266 - _t197*_t440 - _t203*_t231 - _t218*_t449 - _t222*_t449 - _t231*_t234 - _t264*_t468 - _t270*_t382 - _t270*_t452 - _t278*_t454 - 0.1e1 / 0.4e1*_t439 - 0.1e1 / 0.4e1*_t444 - 0.2e1*_t447 - 0.2e1*_t448 - 0.3e1 / 0.2e1*_t450 - 0.3e1 / 0.2e1*_t451 - 0.1e1 / 0.2e1*_t453 - 0.9e1 / 0.2e1*_t455 - 0.1e1 / 0.4e1*_t467 - 0.3e1 / 0.4e1*_t469 - _t470 - 0.1e1 / 0.2e1*_t471 - _t472;
  const double _t474 = _t461*_t85;
  const double _t475 = _t440*_t85;
  const double _t477 = _t230*_t247;
  const double _t478 = _t257*_t454;
  const double _t479 = 0.9e1*_hc0[1]*_hc0[3]*_hc1[0]*_t108*_t19*_t254*_t81 + 0.3e1*_hc0[1]*_hc0[3]*_hc1[0]*_t200*_t39*_t81 + 0.2e1*_hc0[1]*_hc1[0]*_t39*_t5*_t78*_t81 + 0.6e1*_hc0[1]*_hc1[1]*_t19*_t252*_t39*_t84 + _hc0[1]*_hc1[1]*_t20*_t252*_t59 + 0.2e1*_hc0[1]*_hc1[3]*_t20*_t308*_t85 - _hc0[1]*_t276*_t333 + 0.3e1*_hc0[3]*_hc1[0]*_t19*_t252*_t39*_t84 + (0.3e1 / 0.2e1)*_hc0[3]*_hc1[0]*_t20*_t252*_t59 + 0.2e1*_hc0[3]*_hc1[2]*_t20*_t308*_t85 + (0.2e1 / 0.3e1)*_hc0[6]*_hc1[1]*_t20*_t308*_t85 + 0.6e1*_hc1[0]*_t108*_t78*_t84*_t85*_t91 + _hc1[0]*_t20*_t4*(-_t252*_t342 + 0.2e1*_t460 + (0.1e1 / 0.12e2)*_t463 + (0.1e1 / 0.4e1)*_t464 - 0.1e1 / 0.4e1*_t465 + (0.2e1 / 0.3e1)*_t474) + 0.9e1*_hc1[1]*_t108*_t19*_t254*_t81*_t91 + 0.4e1*_hc1[1]*_t108*_t262*_t308*_t85 + (0.3e1 / 0.2e1)*_hc1[1]*_t19*_t20*_t249*_t5 + 0.2e1*_hc1[1]*_t20*_t234*_t24*_t5 + (0.1e1 / 0.2e1)*_hc1[1]*_t20*_t24*_t247*_t5 + 0.3e1*_hc1[1]*_t200*_t39*_t81*_t91 + (0.1e1 / 0.2e1)*_hc1[2]*_t11*_t252*_t59 + _hc1[2]*_t20*_t78*_t84*_t85 + (0.1e1 / 0.2e1)*_hc1[3]*_t11*_t200*_t81 + (0.1e1 / 0.2e1)*_hc1[3]*_t19*_t20*_t254*_t81 - _t101*_t271 - _t218*_t468 - _t222*_t468 - 0.4e1*_t230*_t234 - _t246*_t459 - _t264*_t476 - _t273*_t382 - _t273*_t452 - 0.1e1 / 0.2e1*_t439 - 0.1e1 / 0.2e1*_t444 - 0.4e1*_t447 - 0.4e1*_t448 - 0.3e1*_t450 - _t453 - 0.9e1*_t455 - _t467 - 0.3e1 / 0.2e1*_t469 - 0.4e1*_t470 - _t472 - 0.2e1 / 0.3e1*_t475 - _t477 - 0.12e2*_t478;
  const double _t480 = 0.18e2*_hc0[1]*_hc0[3]*_hc1[0]*_t108*_t19*_t254*_t81 + 0.6e1*_hc0[1]*_hc0[3]*_hc1[0]*_t200*_t39*_t81 + 0.6e1*_hc0[1]*_hc1[0]*_t39*_t5*_t78*_t81 + 0.12e2*_hc0[1]*_hc1[1]*_t19*_t252*_t39*_t84 + 0.2e1*_hc0[1]*_hc1[1]*_t20*_t252*_t59 + 0.4e1*_hc0[1]*_hc1[3]*_t20*_t308*_t85 + 0.6e1*_hc0[3]*_hc1[0]*_t19*_t252*_t39*_t84 + 0.3e1*_hc0[3]*_hc1[0]*_t20*_t252*_t59 + 0.4e1*_hc0[3]*_hc1[2]*_t20*_t308*_t85 + (0.4e1 / 0.3e1)*_hc0[6]*_hc1[1]*_t20*_t308*_t85 + 0.18e2*_hc1[0]*_t108*_t78*_t84*_t85*_t91 + _hc1[0]*_t20*_t4*(-_t252*_t362 + 0.4e1*_t460 + (0.1e1 / 0.6e1)*_t463 + (0.1e1 / 0.2e1)*_t464 - 0.1e1 / 0.2e1*_t465 + (0.4e1 / 0.3e1)*_t474) + 0.18e2*_hc1[1]*_t108*_t19*_t254*_t81*_t91 + 0.8e1*_hc1[1]*_t108*_t262*_t308*_t85 + 0.3e1*_hc1[1]*_t19*_t20*_t249*_t5 + 0.3e1*_hc1[1]*_t20*_t24*_t247*_t5 + 0.6e1*_hc1[1]*_t200*_t39*_t81*_t91 + _hc1[2]*_t11*_t252*_t59 + 0.3e1*_hc1[2]*_t20*_t78*_t84*_t85 + _hc1[3]*_t11*_t200*_t81 + _hc1[3]*_t19*_t20*_t254*_t81 - _t101*_t274 - _t218*_t476 - _t222*_t476 - _t249*_t277*_t7 - 0.6e1*_t264*_t442 - _t278*_t382 - _t278*_t452 - _t439 - _t444 - 0.8e1*_t447 - 0.8e1*_t448 - 0.6e1*_t450 - 0.6e1*_t451 - 0.2e1*_t453 - 0.18e2*_t455 - 0.3e1*_t467 - 0.12e2*_t470 - 0.6e1*_t471 - 0.4e1 / 0.3e1*_t475 - 0.6e1*_t477 - 0.24e2*_t478;
  const double _t482 = _t13*_t481*_t5;
  const double _t484 = _t250*_t483;
  const double _t485 = _t254*_t98;
  const double _t487 = _t281*_t486;
  const double _t488 = _t256*_t481;
  const double _t493 = _t315*_t486;
  const double _t494 = _hc0[10]*_t21*_t486;
  const double _t495 = _t489*_t89;
  const double _t497 = _hc0[6]*_t36*_t486;
  const double _t499 = _t40*_t446;
  const double _t501 = _hc0[3]*_t339;
  const double _t502 = _hc0[1]*_hc0[6]*_t40*_t486;
  const double _t503 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t293;
  const double _t504 = _hc1[1]*_t263;
  const double _t506 = ((_hc0[3]) * (_hc0[3]));
  const double _t507 = _t40*_t506;
  const double _t508 = _hc0[3]*_t109;
  const double _t509 = _t486*_t91;
  const double _t510 = _t207*_t490 - _t212*_t498 + _t218*_t492 + _t222*_t492 + _t254*_t255*_t259 - _t255*_t485 + _t264*_t498 - _t372*_t496 + _t373*_t505 - 0.15e2 / 0.16e2*_t482 + (0.15e2 / 0.16e2)*_t484 + (0.1e1 / 0.16e2)*_t487 + (0.15e2 / 0.16e2)*_t488 - _t490*_t87 - 0.1e1 / 0.4e1*_t493 - 0.1e1 / 0.16e2*_t494 - 0.15e2 / 0.16e2*_t495 + _t496*_t507 - 0.1e1 / 0.4e1*_t497 - _t498*_t499 + _t500*_t501 + _t500*_t503 - _t500*_t504 + (0.1e1 / 0.2e1)*_t502 - 0.9e1 / 0.4e1*_t508*_t509;
  const double _t511 = _t249*_t485;
  const double _t513 = _t259*_t491;
  const double _t516 = _t508*_t509;
  const double _t517 = _t207*_t512 - _t212*_t514 + _t218*_t498 + _t222*_t498 + _t264*_t514 - _t372*_t505 + _t373*_t500 - 0.15e2 / 0.8e1*_t482 + (0.15e2 / 0.8e1)*_t484 + (0.1e1 / 0.8e1)*_t487 + (0.15e2 / 0.8e1)*_t488 - _t490*_t89 - 0.1e1 / 0.2e1*_t493 - 0.1e1 / 0.8e1*_t494 - 0.1e1 / 0.2e1*_t497 - _t499*_t514 + _t501*_t515 + _t502 + _t503*_t515 - _t504*_t515 + _t505*_t507 - 0.3e1 / 0.4e1*_t511 - _t512*_t87 + (0.3e1 / 0.4e1)*_t513 - 0.9e1 / 0.2e1*_t516;
  const double _t521 = _t207*_t518 - _t212*_t519 + _t218*_t514 + _t222*_t514 + _t264*_t519 - _t372*_t500 + _t373*_t515 - 0.15e2 / 0.4e1*_t482 + (0.15e2 / 0.4e1)*_t484 + (0.1e1 / 0.4e1)*_t487 + (0.15e2 / 0.4e1)*_t488 - _t493 - 0.1e1 / 0.4e1*_t494 - 0.15e2 / 0.4e1*_t495 - _t497 - _t499*_t519 + _t500*_t507 + _t501*_t520 + 0.2e1*_t502 + _t503*_t520 - _t504*_t520 - 0.3e1 / 0.2e1*_t511 + (0.3e1 / 0.2e1)*_t513 - 0.9e1*_t516 - _t518*_t87;
  const double _t525 = _hc0[6]*_t113*_t491 + _t104*_t486*_t506 + _t207*_t522 - _t212*_t523 + _t218*_t519 + _t222*_t519 + _t264*_t523 - _t372*_t515 + _t373*_t520 - 0.15e2 / 0.2e1*_t482 + (0.15e2 / 0.2e1)*_t484 + (0.1e1 / 0.2e1)*_t487 + (0.15e2 / 0.2e1)*_t488 - 0.2e1*_t493 - 0.1e1 / 0.2e1*_t494 - 0.15e2 / 0.2e1*_t495 - 0.2e1*_t497 - _t499*_t523 + _t501*_t524 + 0.4e1*_t502 + _t503*_t524 - _t504*_t524 - 0.3e1*_t511 - 0.18e2*_t516 - _t522*_t87;
  const double d4F_dna4 = _t311;
  const double d4F_dna3_dnb = _t311;
  const double d4F_dna2_dnb2 = _t311;
  const double d4F_dna_dnb3 = _t311;
  const double d4F_dnb4 = _t311;
  const double d4F_dna3_dgaa = _t358;
  const double d4F_dna3_dgab = _t368;
  const double d4F_dna3_dgbb = _t358;
  const double d4F_dna2_dnb_dgaa = _t358;
  const double d4F_dna2_dnb_dgab = _t368;
  const double d4F_dna2_dnb_dgbb = _t358;
  const double d4F_dna_dnb2_dgaa = _t358;
  const double d4F_dna_dnb2_dgab = _t368;
  const double d4F_dna_dnb2_dgbb = _t358;
  const double d4F_dnb3_dgaa = _t358;
  const double d4F_dnb3_dgab = _t368;
  const double d4F_dnb3_dgbb = _t358;
  const double d4F_dna2_dgaa2 = _t426;
  const double d4F_dna2_dgaa_dgab = _t434;
  const double d4F_dna2_dgaa_dgbb = _t426;
  const double d4F_dna2_dgab2 = _t438;
  const double d4F_dna2_dgab_dgbb = _t434;
  const double d4F_dna2_dgbb2 = _t426;
  const double d4F_dna_dnb_dgaa2 = _t426;
  const double d4F_dna_dnb_dgaa_dgab = _t434;
  const double d4F_dna_dnb_dgaa_dgbb = _t426;
  const double d4F_dna_dnb_dgab2 = _t438;
  const double d4F_dna_dnb_dgab_dgbb = _t434;
  const double d4F_dna_dnb_dgbb2 = _t426;
  const double d4F_dnb2_dgaa2 = _t426;
  const double d4F_dnb2_dgaa_dgab = _t434;
  const double d4F_dnb2_dgaa_dgbb = _t426;
  const double d4F_dnb2_dgab2 = _t438;
  const double d4F_dnb2_dgab_dgbb = _t434;
  const double d4F_dnb2_dgbb2 = _t426;
  const double d4F_dna_dgaa3 = _t466;
  const double d4F_dna_dgaa2_dgab = _t473;
  const double d4F_dna_dgaa2_dgbb = _t466;
  const double d4F_dna_dgaa_dgab2 = _t479;
  const double d4F_dna_dgaa_dgab_dgbb = _t473;
  const double d4F_dna_dgaa_dgbb2 = _t466;
  const double d4F_dna_dgab3 = _t480;
  const double d4F_dna_dgab2_dgbb = _t479;
  const double d4F_dna_dgab_dgbb2 = _t473;
  const double d4F_dna_dgbb3 = _t466;
  const double d4F_dnb_dgaa3 = _t466;
  const double d4F_dnb_dgaa2_dgab = _t473;
  const double d4F_dnb_dgaa2_dgbb = _t466;
  const double d4F_dnb_dgaa_dgab2 = _t479;
  const double d4F_dnb_dgaa_dgab_dgbb = _t473;
  const double d4F_dnb_dgaa_dgbb2 = _t466;
  const double d4F_dnb_dgab3 = _t480;
  const double d4F_dnb_dgab2_dgbb = _t479;
  const double d4F_dnb_dgab_dgbb2 = _t473;
  const double d4F_dnb_dgbb3 = _t466;
  const double d4F_dgaa4 = _t510;
  const double d4F_dgaa3_dgab = _t517;
  const double d4F_dgaa3_dgbb = _t510;
  const double d4F_dgaa2_dgab2 = _t521;
  const double d4F_dgaa2_dgab_dgbb = _t517;
  const double d4F_dgaa2_dgbb2 = _t510;
  const double d4F_dgaa_dgab3 = _t525;
  const double d4F_dgaa_dgab2_dgbb = _t521;
  const double d4F_dgaa_dgab_dgbb2 = _t517;
  const double d4F_dgaa_dgbb3 = _t510;
  const double d4F_dgab4 = _t207*_t526 - _t212*_t527 + _t218*_t523 + _t222*_t523 + _t264*_t527 - _t372*_t520 + _t373*_t524 - 0.15e2*_t482 + 0.15e2*_t484 + _t487 + 0.15e2*_t488 - 0.4e1*_t493 - _t494 - 0.15e2*_t495 - 0.4e1*_t497 - _t499*_t527 + _t501*_t528 + 0.8e1*_t502 + _t503*_t528 - _t504*_t528 + _t507*_t520 - 0.6e1*_t511 + 0.6e1*_t513 - 0.36e2*_t516 - _t526*_t87;
  const double d4F_dgab3_dgbb = _t525;
  const double d4F_dgab2_dgbb2 = _t521;
  const double d4F_dgab_dgbb3 = _t517;
  const double d4F_dgbb4 = _t510;
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