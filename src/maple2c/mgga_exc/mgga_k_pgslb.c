/*
  Generated from python/mgga_exc/mgga_k_pgslb.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_k_pgslb
*/

#ifndef _MGGA_K_PGSLB_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_K_PGSLB_KERNEL_BODY
#define _KMAX 0
#define _MGGA_K_PGSLB_HELPER_BODIES
#include "mgga_k_pgslb.c"
#undef _MGGA_K_PGSLB_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_K_PGSLB_HELPER_BODIES
#include "mgga_k_pgslb.c"
#undef _MGGA_K_PGSLB_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_K_PGSLB_HELPER_BODIES
#include "mgga_k_pgslb.c"
#undef _MGGA_K_PGSLB_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_K_PGSLB_HELPER_BODIES
#include "mgga_k_pgslb.c"
#undef _MGGA_K_PGSLB_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_K_PGSLB_HELPER_BODIES
#include "mgga_k_pgslb.c"
#undef _MGGA_K_PGSLB_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_k_pgslb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_k_pgslb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_k_pgslb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_k_pgslb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_k_pgslb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_k_pgslb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_k_pgslb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_k_pgslb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_k_pgslb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_k_pgslb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_K_PGSLB_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(pgslb_f0_k, _KMAX)(const xc_func_type *p, double s2, double q, double *out) {
  const mgga_k_pgslb_params *params = (const mgga_k_pgslb_params *)(p->params);

  const double _t1 = exp(-params->pgslb_mu*s2);
#if _KMAX >= 1
  const double _t2 = 0.2e1*params->pgslb_beta;
#endif

  const double f = _t1 + params->pgslb_beta*(q * q) + (0.5e1 / 0.3e1)*s2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dq = _t2*q;
  out[1] = df_dq;
  const double df_ds2 = -_t1*params->pgslb_mu + 0.5e1 / 0.3e1;
  out[2] = df_ds2;
#endif
#if _KMAX >= 2
  const double d2f_dq2 = _t2;
  out[3] = d2f_dq2;
  const double d2f_ds2_dq = 0;
  out[4] = d2f_ds2_dq;
  const double d2f_ds22 = _t1*((params->pgslb_mu) * (params->pgslb_mu));
  out[5] = d2f_ds22;
#endif
#if _KMAX >= 3
  const double d3f_dq3 = 0;
  out[6] = d3f_dq3;
  const double d3f_ds2_dq2 = 0;
  out[7] = d3f_ds2_dq2;
  const double d3f_ds22_dq = 0;
  out[8] = d3f_ds22_dq;
  const double d3f_ds23 = -_t1*((params->pgslb_mu) * (params->pgslb_mu) * (params->pgslb_mu));
  out[9] = d3f_ds23;
#endif
#if _KMAX >= 4
  const double d4f_dq4 = 0;
  out[10] = d4f_dq4;
  const double d4f_ds2_dq3 = 0;
  out[11] = d4f_ds2_dq3;
  const double d4f_ds22_dq2 = 0;
  out[12] = d4f_ds22_dq2;
  const double d4f_ds23_dq = 0;
  out[13] = d4f_ds23_dq;
  const double d4f_ds24 = _t1*((params->pgslb_mu) * (params->pgslb_mu) * (params->pgslb_mu) * (params->pgslb_mu));
  out[14] = d4f_ds24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pgslb_f_k, _KMAX)(const xc_func_type *p, double p_, double u, double *out) {

  const double _t1 = (0.1e1 / 0.24e2)*xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pgslb_f0_k, _KMAX)(p, p_, _t1*u, _hc0);

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_du = _hc0[1]*_t1;
  out[1] = df_du;
  const double df_dp_ = _hc0[2];
  out[2] = df_dp_;
#endif
#if _KMAX >= 2
  const double d2f_du2 = (0.1e1 / 0.576e3)*xc_powr(0.6e1, 2, 3)*_hc0[3]/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  out[3] = d2f_du2;
  const double d2f_dp__du = 0;
  out[4] = d2f_dp__du;
  const double d2f_dp_2 = _hc0[5];
  out[5] = d2f_dp_2;
#endif
#if _KMAX >= 3
  const double d3f_du3 = 0;
  out[6] = d3f_du3;
  const double d3f_dp__du2 = 0;
  out[7] = d3f_dp__du2;
  const double d3f_dp_2_du = 0;
  out[8] = d3f_dp_2_du;
  const double d3f_dp_3 = _hc0[9];
  out[9] = d3f_dp_3;
#endif
#if _KMAX >= 4
  const double d4f_du4 = 0;
  out[10] = d4f_du4;
  const double d4f_dp__du3 = 0;
  out[11] = d4f_dp__du3;
  const double d4f_dp_2_du2 = 0;
  out[12] = d4f_dp_2_du2;
  const double d4f_dp_3_du = 0;
  out[13] = d4f_dp_3_du;
  const double d4f_dp_4 = _hc0[14];
  out[14] = d4f_dp_4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_m1_n5_3_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z - p->zeta_threshold + 0.1e1;
  const double _t2 = _t1 <= 0;
  const double _t3 = _t1 > 0;
  const double _t4 = my_piecewise3(_t3, z, p->zeta_threshold - 0.1e1);
  const double _t5 = xc_expm1((0.5e1 / 0.3e1)*xc_log1p(_t4));
#if _KMAX >= 1
  const double _t6 = my_piecewise3(_t3, 0.1e1, 0);
  const double _t7 = _t4 + 0.1e1;
  const double _t8 = _t5 + 0.1e1;
#endif

  const double f = my_piecewise3(_t2, xc_powr(p->zeta_threshold, 5, 3) - 0.1e1, _t5);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise3(_t2, 0, (0.5e1 / 0.3e1)*_t6*_t8/_t7);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise3(_t2, 0, (0.10e2 / 0.9e1)*(_t6 * _t6)*_t8/(_t7 * _t7));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise3(_t2, 0, -0.10e2 / 0.27e2*(_t6 * _t6 * _t6)*_t8/(_t7 * _t7 * _t7));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = my_piecewise3(_t2, 0, (0.40e2 / 0.81e2)*(_t6 * _t6 * _t6 * _t6)*_t8/(_t7 * _t7 * _t7 * _t7));
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {
  const mgga_k_pgslb_params *params = (const mgga_k_pgslb_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n5_3_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  const double _t1 = xc_powr(n_s, -8, 3);
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (M_PI * M_CBRTPI);
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = _t2*_t4;
  const double _t6 = _t5*sigma_ss;
  const double _t7 = -p->dens_threshold + n_s <= 0;
  const double _t8 = _hc0[0] + 0.1e1;
  const double _t9 = xc_powr(0.3e1, 2, 3)*_t8;
  const double _t10 = _t3*_t9;
  const double _t11 = (0.3e1 / 0.20e2)*_t10;
  const double _t12 = _t11*xc_powr(n_s, 2, 3);
#if _KMAX >= 1
  const double _t15 = (0.1e1 / (n_s * n_s));
  const double _t16 = M_CBRT2*_t8;
  const double _t17 = (0.3e1 / 0.160e3)*_t16;
  const double _t19 = xc_powr(n_s, -1, 3);
  const double _t20 = (0.1e1 / 0.10e2)*_t10;
  const double _t21 = (0.5e1 / 0.3e1)*_t1;
  const double _t23 = xc_powr(n_s, -11, 3);
  const double _t24 = (0.1e1 / 0.9e1)*_t6;
  const double _t25 = _t23*_t24;
#endif
#if _KMAX >= 2
  const double _t31 = xc_powr(n_s, -14, 3);
  const double _t33 = xc_powr(0.12e2, 1, 3)*_t4*_t8;
  const double _t34 = (0.1e1 / 0.1280e4)*_t33;
  const double _t36 = xc_powr(n_s, -13, 3);
  const double _t37 = (0.5e1 / 0.3e1)*lapl_s;
  const double _t38 = _t36*_t37;
  const double _t39 = xc_powr(n_s, -16, 3);
  const double _t43 = (0.1e1 / (n_s * n_s * n_s));
  const double _t44 = (0.1e1 / 0.80e2)*_t16;
  const double _t45 = (0.1e1 / 0.9e1)*_t5;
  const double _t46 = _t23*_t45;
  const double _t48 = (0.5e1 / 0.72e2)*_t5;
  const double _t49 = _t39*_t48;
  const double _t50 = xc_powr(0.6e1, 2, 3);
  const double _t51 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t52 = _t50*_t51;
  const double _t54 = xc_powr(n_s, -19, 3);
  const double _t55 = (0.1e1 / 0.216e3)*sigma_ss;
  const double _t56 = _t54*_t55;
  const double _t59 = xc_powr(n_s, -4, 3);
  const double _t60 = (0.1e1 / 0.30e2)*_t10;
  const double _t61 = _t10*_t19;
  const double _t62 = (0.1e1 / 0.5e1)*_t61;
  const double _t63 = (0.40e2 / 0.9e1)*_t23;
  const double _t65 = (0.11e2 / 0.27e2)*_t6;
  const double _t66 = _t31*_t65;
#endif
#if _KMAX >= 3
  const double _t79 = xc_powr(n_s, -22, 3);
  const double _t80 = (0.1e1 / 0.15360e5)*_t51*_t9;
  const double _t82 = (0.10e2 / 0.3e1)*_t36;
  const double _t83 = xc_powi(n_s, -6);
  const double _t85 = xc_powi(n_s, -7);
  const double _t90 = (0.13e2 / 0.72e2)*_t5;
  const double _t92 = xc_powi(n_s, -8);
  const double _t97 = xc_powr(n_s, -17, 3);
  const double _t98 = (0.1e1 / 0.1920e4)*_t33;
  const double _t99 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t100 = xc_powi(n_s, -9);
  const double _t101 = _t100*_t99;
  const double _t103 = (0.1e1 / 0.864e3)*sigma_ss;
  const double _t104 = (0.1e1 / 0.108e3)*_t54;
  const double _t105 = (0.5e1 / 0.1728e4)*lapl_s;
  const double _t109 = (0.40e2 / 0.9e1)*lapl_s;
  const double _t111 = _t21*lapl_s;
  const double _t116 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t117 = (0.1e1 / 0.240e3)*_t16;
  const double _t118 = (0.11e2 / 0.27e2)*_t5;
  const double _t119 = _t118*_t31;
  const double _t120 = (0.5e1 / 0.27e2)*_t5;
  const double _t122 = (0.11e2 / 0.648e3)*sigma_ss;
  const double _t123 = _t48*lapl_s;
  const double _t132 = xc_powr(n_s, -7, 3);
  const double _t133 = (0.2e1 / 0.45e2)*_t10;
  const double _t134 = _t20*_t59;
  const double _t135 = (0.3e1 / 0.10e2)*_t61;
  const double _t136 = (0.440e3 / 0.27e2)*_t31;
  const double _t138 = (0.154e3 / 0.81e2)*_t97;
#endif
#if _KMAX >= 4
  const double _t157 = _t99/xc_powi(n_s, 10);
  const double _t161 = _t52*_t55;
  const double _t164 = _t99/xc_powr(n_s, 32, 3);
  const double _t165 = _t105*_t52;
  const double _t166 = xc_powr(n_s, -25, 3);
  const double _t171 = xc_powr(n_s, -20, 3);
  const double _t173 = (0.154e3 / 0.81e2)*_t6;
  const double _t174 = _t24*_t39;
  const double _t176 = _t120*lapl_s;
  const double _t177 = _t49*lapl_s;
  const double _t178 = _t52*_t56;
  const double _t180 = _t63*lapl_s;
#endif
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t7)) XC_CAT(pgslb_f_k, _KMAX)(p, (0.1e1 / 0.24e2)*_t1*_t6, lapl_s/xc_powr(n_s, 5, 3), _hc1);
  const double _t13 = my_piecewise3(_t7, 0, _hc1[0]*_t12);
#if _KMAX >= 1
  const double _t14 = my_piecewise3(_t7, 0, _hc1[1]*_t11/n_s);
  const double _t18 = my_piecewise3(_t7, 0, _hc1[2]*_t15*_t17);
  const double _t22 = _hc1[1]*_t21;
  const double _t26 = -_hc1[2]*_t25 - _t22*lapl_s;
  const double _t27 = my_piecewise3(_t7, 0, _hc1[0]*_t19*_t20 + _t12*_t26);
#endif
#if _KMAX >= 2
  const double _t28 = my_piecewise3(_t7, 0, _hc1[3]*_t1*_t11);
  const double _t29 = _hc1[4]*_t23;
  const double _t30 = my_piecewise3(_t7, 0, _t17*_t29);
  const double _t32 = _hc1[5]*_t31;
  const double _t35 = my_piecewise3(_t7, 0, _t32*_t34);
  const double _t40 = _hc1[4]*_t39;
  const double _t41 = -_hc1[3]*_t38 - _t22 - _t24*_t40;
  const double _t42 = my_piecewise3(_t7, 0, _hc1[1]*_t15*_t20 + _t12*_t41);
  const double _t47 = _hc1[4]*lapl_s;
  const double _t53 = _hc1[5]*_t52;
  const double _t57 = -_hc1[2]*_t46 - _t47*_t49 - _t53*_t56;
  const double _t58 = my_piecewise3(_t7, 0, _hc1[2]*_t43*_t44 + _t12*_t57);
  const double _t64 = _hc1[1]*_t63;
  const double _t67 = _hc1[3]*_t21;
  const double _t68 = -_t24*_t29 - _t67*lapl_s;
  const double _t69 = _t21*_t68;
  const double _t70 = _hc1[4]*_t21;
  const double _t71 = -_hc1[5]*_t25 - _t70*lapl_s;
  const double _t72 = _hc1[2]*_t66 - _t25*_t71 + _t64*lapl_s - _t69*lapl_s;
  const double _t73 = my_piecewise3(_t7, 0, -_hc1[0]*_t59*_t60 + _t12*_t72 + _t26*_t62);
#endif
#if _KMAX >= 3
  const double _t74 = my_piecewise3(_t7, 0, _hc1[6]*_t11*_t36);
  const double _t75 = _hc1[7]*_t39;
  const double _t76 = my_piecewise3(_t7, 0, _t17*_t75);
  const double _t77 = _hc1[8]*_t54;
  const double _t78 = my_piecewise3(_t7, 0, _t34*_t77);
  const double _t81 = my_piecewise3(_t7, 0, _hc1[9]*_t79*_t80);
  const double _t84 = _hc1[6]*_t83;
  const double _t86 = _hc1[7]*_t85;
  const double _t87 = -_hc1[3]*_t82 - _t24*_t86 - _t37*_t84;
  const double _t88 = my_piecewise3(_t7, 0, _hc1[3]*_t20*_t23 + _t12*_t87);
  const double _t89 = _hc1[4]*_t31;
  const double _t91 = _t5*_t86;
  const double _t93 = _hc1[8]*_t52;
  const double _t94 = _t92*_t93;
  const double _t95 = -_t40*_t90 - _t55*_t94 - 0.5e1 / 0.72e2*_t91*lapl_s;
  const double _t96 = my_piecewise3(_t7, 0, _t12*_t95 + _t44*_t89);
  const double _t102 = _hc1[9]*_t101;
  const double _t106 = -_t102*_t103 - _t104*_t53 - _t105*_t94;
  const double _t107 = my_piecewise3(_t7, 0, _hc1[5]*_t97*_t98 + _t106*_t12);
  const double _t108 = _hc1[3]*_t39;
  const double _t110 = -_hc1[6]*_t38 - _t24*_t75 - _t67;
  const double _t112 = _hc1[8]*_t39;
  const double _t113 = -_hc1[7]*_t38 - _t112*_t24 - _t70;
  const double _t114 = _hc1[4]*_t54*_t65 + _t108*_t109 - _t110*_t111 - _t113*_t25 + _t64 - _t69;
  const double _t115 = my_piecewise3(_t7, 0, -_hc1[1]*_t43*_t60 + _t114*_t12 + _t41*_t62);
  const double _t121 = _t53*_t79;
  const double _t124 = -_t123*_t75 - _t29*_t45 - _t56*_t93;
  const double _t125 = _t124*_t21;
  const double _t126 = _hc1[9]*sigma_ss;
  const double _t127 = _t126*_t52;
  const double _t128 = -_hc1[5]*_t46 - _t112*_t123 - 0.1e1 / 0.216e3*_t127*_t54;
  const double _t129 = _t128*_t23;
  const double _t130 = _hc1[2]*_t119 + _t120*_t47*_t54 + _t121*_t122 - _t125*lapl_s - _t129*_t24 - _t46*_t71;
  const double _t131 = my_piecewise3(_t7, 0, -_hc1[2]*_t116*_t117 + _t12*_t130 + _t57*_t62);
  const double _t137 = _hc1[1]*_t136;
  const double _t139 = _hc1[2]*_t138;
  const double _t140 = _hc1[3]*_t63;
  const double _t141 = _hc1[6]*_t21;
  const double _t142 = -_hc1[7]*_t25 - _t141*lapl_s;
  const double _t143 = _t142*_t21;
  const double _t144 = _hc1[7]*_t21;
  const double _t145 = -_hc1[8]*_t25 - _t144*lapl_s;
  const double _t146 = _t140*lapl_s - _t143*lapl_s - _t145*_t25 + _t65*_t89;
  const double _t147 = _t146*_t21;
  const double _t148 = _hc1[4]*_t63;
  const double _t149 = _t145*_t21;
  const double _t150 = _hc1[8]*_t21;
  const double _t151 = -_hc1[9]*_t25 - _t150*lapl_s;
  const double _t152 = _t148*lapl_s - _t149*lapl_s - _t151*_t25 + _t32*_t65;
  const double _t153 = -_t137*lapl_s - _t139*_t6 - _t147*lapl_s - _t152*_t25 + (0.22e2 / 0.27e2)*_t2*_t31*_t4*_t71*sigma_ss + (0.80e2 / 0.9e1)*_t23*_t68*lapl_s;
  const double _t154 = my_piecewise3(_t7, 0, _hc1[0]*_t132*_t133 + _t12*_t153 - _t134*_t26 + _t135*_t72);
#endif
#if _KMAX >= 4
  const double _t155 = _hc1[11]*_t85;
  const double _t156 = _hc1[12]*_t92;
  const double _t158 = _hc1[10]*_t37;
  const double _t159 = _hc1[11]/xc_powr(n_s, 26, 3);
  const double _t160 = _hc1[7]*_t54;
  const double _t162 = _hc1[12]/xc_powr(n_s, 29, 3);
  const double _t163 = _hc1[13]*_t103;
  const double _t167 = _hc1[13]*lapl_s;
  const double _t168 = _hc1[6]*_t109;
  const double _t169 = _hc1[12]*_t85;
  const double _t170 = _hc1[4]*_t97;
  const double _t172 = _hc1[3]*lapl_s;
  const double _t175 = -_hc1[11]*_t38 - _hc1[12]*_t174 - _t144;
  const double _t179 = -_hc1[12]*_t177 - _hc1[13]*_t178 - _hc1[8]*_t46;
  const double _t181 = -_hc1[11]*_t111 - _hc1[12]*_t25;
  const double _t182 = -_hc1[12]*_t111 - _hc1[13]*_t25;
  const double _t183 = _hc1[7]*_t180 + _hc1[8]*_t66 - _t111*_t181 - _t182*_t25;
#endif

  const double f = my_piecewise3(_t7, 0, _t13*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = 0;
  out[1] = df_dtau_s;
  const double df_dlapl_s = my_piecewise3(_t7, 0, _t14*n_s);
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t7, 0, _t18*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t7, 0, _t13 + _t27*n_s);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = 0;
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = my_piecewise3(_t7, 0, _t28*n_s);
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = 0;
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = my_piecewise3(_t7, 0, _t30*n_s);
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t7, 0, _t35*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = 0;
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = my_piecewise3(_t7, 0, _t14 + _t42*n_s);
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t7, 0, _t18 + _t58*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t7, 0, 0.2e1*_t27 + _t73*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = 0;
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = my_piecewise3(_t7, 0, _t74*n_s);
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = 0;
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = my_piecewise3(_t7, 0, _t76*n_s);
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = 0;
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = my_piecewise3(_t7, 0, _t78*n_s);
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t7, 0, _t81*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = 0;
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = my_piecewise3(_t7, 0, _t28 + _t88*n_s);
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = 0;
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = my_piecewise3(_t7, 0, _t30 + _t96*n_s);
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t7, 0, _t107*n_s + _t35);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = 0;
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = my_piecewise3(_t7, 0, _t115*n_s + 0.2e1*_t42);
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t7, 0, _t131*n_s + 0.2e1*_t58);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t7, 0, _t154*n_s + 0.3e1*_t73);
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
  const double d4f_dlapl_s4 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc1[10]*_t11*_t83));
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = 0;
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _t155*_t17));
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = 0;
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _t156*_t34));
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = 0;
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc1[13]*_t100*_t80));
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, (0.1e1 / 0.122880e6)*_hc1[14]*_t157*_t16));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = 0;
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = my_piecewise3(_t7, 0, _t74 + n_s*my_piecewise3(_t7, 0, _hc1[6]*_t20*_t39 + _t12*(-_t158/xc_powr(n_s, 23, 3) - _t159*_t24 - 0.5e1*_t84)));
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = 0;
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = my_piecewise3(_t7, 0, _t76 + n_s*my_piecewise3(_t7, 0, _t12*(-_t123*_t159 - _t161*_t162 - 0.1e1 / 0.4e1*_t91) + _t160*_t44));
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = 0;
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = my_piecewise3(_t7, 0, _t78 + n_s*my_piecewise3(_t7, 0, _hc1[8]*_t79*_t98 + _t12*(-_t162*_t165 - _t163*_t164 - 0.7e1 / 0.576e3*_t94)));
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t7, 0, _t81 + n_s*my_piecewise3(_t7, 0, (0.1e1 / 0.23040e5)*_hc1[9]*_t166*_t51*_t9 + _t12*(-0.1e1 / 0.20736e5*_hc1[14]*_t2*sigma_ss/((M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI)*xc_powr(n_s, 35, 3)) - 0.1e1 / 0.288e3*_t102 - 0.5e1 / 0.6912e4*_t164*_t167)));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = 0;
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = my_piecewise3(_t7, 0, 0.2e1*_t88 + n_s*my_piecewise3(_t7, 0, -_hc1[3]*_t31*_t60 + _t12*(_hc1[7]*_t65*_t92 - 0.10e2 / 0.3e1*_t1*_t110 + (0.80e2 / 0.9e1)*_t108 - _t111*(-_hc1[6]*_t82 - _t155*_t24 - _t158*_t83) + _t168*_t85 - _t25*(-_hc1[11]*_t37*_t83 - _hc1[7]*_t82 - _t169*_t24)) + _t62*_t87));
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = 0;
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = my_piecewise3(_t7, 0, 0.2e1*_t96 + n_s*my_piecewise3(_t7, 0, -_t117*_t170 + _t12*((0.16e2 / 0.27e2)*_hc1[4]*_t2*_t4*_t54 + (0.5e1 / 0.27e2)*_hc1[7]*_t2*_t4*_t92*lapl_s + (0.11e2 / 0.648e3)*_hc1[8]*_t100*_t50*_t51*sigma_ss - _t111*(-_t123*_t155 - _t156*_t161 - _t75*_t90) - _t113*_t46 - _t125 - _t25*(-_hc1[13]*_t161*_t92 - _t112*_t90 - _t123*_t169)) + _t62*_t95));
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t7, 0, 0.2e1*_t107 + n_s*my_piecewise3(_t7, 0, -0.1e1 / 0.5760e4*_hc1[5]*_t171*_t33 + _t106*_t62 + _t12*((0.5e1 / 0.648e3)*_t100*_t93*lapl_s - _t111*(-_t101*_t163 - _t104*_t93 - _t156*_t165) + (0.11e2 / 0.324e3)*_t121 + (0.11e2 / 0.2592e4)*_t126*_t157 - 0.2e1 / 0.9e1*_t129*_t5 - _t25*(-_hc1[14]*_t101*_t103 - _hc1[9]*_t104*_t52 - 0.5e1 / 0.1728e4*_t167*_t52*_t92))));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = 0;
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = my_piecewise3(_t7, 0, 0.3e1*_t115 + n_s*my_piecewise3(_t7, 0, _hc1[1]*_t116*_t133 + _t114*_t135 + _t12*(-_hc1[4]*_t173*_t79 + (0.80e2 / 0.9e1)*_t110*_t23*lapl_s - _t111*(-_t111*(-_hc1[10]*_t38 - _hc1[11]*_t174 - _t141) + _t140 - _t143 + _t160*_t65 + _t168*_t39 - _t175*_t25) + (0.22e2 / 0.27e2)*_t113*_t2*_t31*_t4*sigma_ss - _t137 - _t147 - 0.440e3 / 0.27e2*_t172*_t54 + (0.80e2 / 0.9e1)*_t23*_t68 - _t25*(_t109*_t75 - _t111*_t175 + _t148 - _t149 - _t25*(-_hc1[12]*_t38 - _hc1[13]*_t174 - _t150) + _t65*_t77)) - _t134*_t41));
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t7, 0, 0.3e1*_t131 + n_s*my_piecewise3(_t7, 0, (0.1e1 / 0.180e3)*_hc1[2]*_t16/xc_powi(n_s, 5) + _t12*(-_t111*(-_t111*(-_hc1[11]*_t177 - _hc1[12]*_t178 - _hc1[7]*_t46) + _t118*_t89 + _t122*_t79*_t93 - _t145*_t46 + _t160*_t176 - _t179*_t25) + (0.80e2 / 0.9e1)*_t124*_t23*lapl_s + (0.22e2 / 0.27e2)*_t128*_t2*_t31*_t4*sigma_ss - _t139*_t5 - _t152*_t46 - 0.77e2 / 0.972e3*_t166*_t53*sigma_ss + (0.22e2 / 0.27e2)*_t2*_t31*_t4*_t71 - _t25*(_hc1[5]*_t119 - _t111*_t179 + (0.11e2 / 0.648e3)*_t127*_t79 - _t151*_t46 + _t176*_t77 - _t25*(-_hc1[14]*_t178 - _hc1[9]*_t46 - _t167*_t49)) - 0.55e2 / 0.81e2*_t47*_t5*_t79) + _t130*_t135 - _t134*_t57));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t7, 0, 0.4e1*_t154 + n_s*my_piecewise3(_t7, 0, -0.14e2 / 0.135e3*_hc1[0]*_t10/xc_powr(n_s, 10, 3) + (0.8e1 / 0.45e2)*_t10*_t132*_t26 - 0.1e1 / 0.5e1*_t10*_t59*_t72 + _t12*((0.6160e4 / 0.81e2)*_hc1[1]*_t97*lapl_s + (0.2618e4 / 0.243e3)*_hc1[2]*_t171*_t6 - _t111*(-_t111*(_hc1[6]*_t180 + _hc1[7]*_t66 - _t111*(-_hc1[10]*_t111 - _hc1[11]*_t25) - _t181*_t25) - _t136*_t172 + (0.80e2 / 0.9e1)*_t142*_t23*lapl_s + (0.22e2 / 0.27e2)*_t145*_t2*_t31*_t4*sigma_ss - _t170*_t173 - _t183*_t25) + (0.40e2 / 0.3e1)*_t146*_t23*lapl_s + (0.11e2 / 0.9e1)*_t152*_t31*_t6 - _t25*(-_hc1[5]*_t138*_t6 - _t111*_t183 - _t136*_t47 + (0.80e2 / 0.9e1)*_t145*_t23*lapl_s + (0.22e2 / 0.27e2)*_t151*_t2*_t31*_t4*sigma_ss - _t25*(_hc1[8]*_t180 + _hc1[9]*_t66 - _t111*_t182 - _t25*(-_hc1[13]*_t111 - _hc1[14]*_t25))) - 0.440e3 / 0.9e1*_t31*_t68*lapl_s - 0.154e3 / 0.27e2*_t6*_t71*_t97) + (0.2e1 / 0.5e1)*_t153*_t61));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_k_pgslb_params *params = (const mgga_k_pgslb_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;

  const double _t1 = (0.1e1 / 0.2e1)*na;
  const double _t2 = (0.1e1 / 0.4e1)*gaa;
  const double _t3 = (0.1e1 / 0.2e1)*la;
  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, _t2, _t3, 0, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, _t2, 0, 0, _hc1);
  double _hc2[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, 0, _t3, 0, _hc2);
  const double dF_dna = _hc0[4];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc1[3];
  const double dF_dla = _hc2[2];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
#endif
#if _KMAX >= 2
  double _hc3[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, 0, 0, 0, _hc3);
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc0[14];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[13];
  const double d2F_dna_dla = (0.1e1 / 0.2e1)*_hc0[12];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc1[10];
  const double d2F_dgaa_dla = (0.1e1 / 0.4e1)*_hc3[9];
  const double d2F_dla2 = (0.1e1 / 0.2e1)*_hc3[7];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 0] += d2F_dgaa_dla;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc0[34];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc0[33];
  const double d3F_dna2_dla = (0.1e1 / 0.4e1)*_hc0[32];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[30];
  const double d3F_dna_dgaa_dla = (0.1e1 / 0.8e1)*_hc0[29];
  const double d3F_dna_dla2 = (0.1e1 / 0.4e1)*_hc0[27];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc1[24];
  const double d3F_dgaa2_dla = (0.1e1 / 0.16e2)*_hc3[23];
  const double d3F_dgaa_dla2 = (0.1e1 / 0.8e1)*_hc3[21];
  const double d3F_dla3 = (0.1e1 / 0.4e1)*_hc3[18];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 0] += d3F_dna_dgaa_dla;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 0] += d3F_dgaa2_dla;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 0] += d3F_dgaa_dla2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc0[69];
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc0[68];
  const double d4F_dna3_dla = (0.1e1 / 0.8e1)*_hc0[67];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc0[65];
  const double d4F_dna2_dgaa_dla = (0.1e1 / 0.16e2)*_hc0[64];
  const double d4F_dna2_dla2 = (0.1e1 / 0.8e1)*_hc0[62];
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[59];
  const double d4F_dna_dgaa2_dla = (0.1e1 / 0.32e2)*_hc0[58];
  const double d4F_dna_dgaa_dla2 = (0.1e1 / 0.16e2)*_hc0[56];
  const double d4F_dna_dla3 = (0.1e1 / 0.8e1)*_hc0[53];
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc1[49];
  const double d4F_dgaa3_dla = (0.1e1 / 0.64e2)*_hc3[48];
  const double d4F_dgaa2_dla2 = (0.1e1 / 0.32e2)*_hc3[46];
  const double d4F_dgaa_dla3 = (0.1e1 / 0.16e2)*_hc3[43];
  const double d4F_dla4 = (0.1e1 / 0.8e1)*_hc3[39];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 0] += d4F_dna2_dgaa_dla;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 0] += d4F_dna_dgaa2_dla;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 0] += d4F_dna_dgaa_dla2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 0] += d4F_dgaa3_dla;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 0] += d4F_dgaa2_dla2;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 0] += d4F_dgaa_dla3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 0] += d4F_dla4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gbb = sigma[2];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double lb = (lapl != NULL) ? lapl[1] : 0.0;

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, la, 0, _hc0);
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, lb, 0, _hc1);
  const double zk = (_hc0[0] + _hc1[0])/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  double _hc2[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, 0, 0, _hc2);
  double _hc3[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, 0, 0, _hc3);
  double _hc4[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, 0, la, 0, _hc4);
  double _hc5[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, 0, lb, 0, _hc5);
  const double dF_dna = _hc0[4];
  const double dF_dnb = _hc1[4];
  const double dF_dgaa = _hc2[3];
  const double dF_dgbb = _hc3[3];
  const double dF_dla = _hc4[2];
  const double dF_dlb = _hc5[2];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 1] += dF_dlb;
#endif
#if _KMAX >= 2
  double _hc6[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, 0, 0, 0, _hc6);
  double _hc7[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, 0, 0, 0, _hc7);
  const double d2F_dna2 = _hc0[14];
  const double d2F_dnb2 = _hc1[14];
  const double d2F_dna_dgaa = _hc0[13];
  const double d2F_dnb_dgbb = _hc1[13];
  const double d2F_dna_dla = _hc0[12];
  const double d2F_dnb_dlb = _hc1[12];
  const double d2F_dgaa2 = _hc2[10];
  const double d2F_dgbb2 = _hc3[10];
  const double d2F_dgaa_dla = _hc6[9];
  const double d2F_dgbb_dlb = _hc7[9];
  const double d2F_dla2 = _hc6[7];
  const double d2F_dlb2 = _hc7[7];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 3] += d2F_dnb_dlb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 0] += d2F_dgaa_dla;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 5] += d2F_dgbb_dlb;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 2] += d2F_dlb2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = _hc0[34];
  const double d3F_dnb3 = _hc1[34];
  const double d3F_dna2_dgaa = _hc0[33];
  const double d3F_dnb2_dgbb = _hc1[33];
  const double d3F_dna2_dla = _hc0[32];
  const double d3F_dnb2_dlb = _hc1[32];
  const double d3F_dna_dgaa2 = _hc0[30];
  const double d3F_dnb_dgbb2 = _hc1[30];
  const double d3F_dna_dgaa_dla = _hc0[29];
  const double d3F_dnb_dgbb_dlb = _hc1[29];
  const double d3F_dna_dla2 = _hc0[27];
  const double d3F_dnb_dlb2 = _hc1[27];
  const double d3F_dgaa3 = _hc2[24];
  const double d3F_dgbb3 = _hc3[24];
  const double d3F_dgaa2_dla = _hc6[23];
  const double d3F_dgbb2_dlb = _hc7[23];
  const double d3F_dgaa_dla2 = _hc6[21];
  const double d3F_dgbb_dlb2 = _hc7[21];
  const double d3F_dla3 = _hc6[18];
  const double d3F_dlb3 = _hc7[18];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 5] += d3F_dnb2_dlb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 0] += d3F_dna_dgaa_dla;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 11] += d3F_dnb_dgbb_dlb;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 5] += d3F_dnb_dlb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 0] += d3F_dgaa2_dla;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 11] += d3F_dgbb2_dlb;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 0] += d3F_dgaa_dla2;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 8] += d3F_dgbb_dlb2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 3] += d3F_dlb3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = _hc0[69];
  const double d4F_dnb4 = _hc1[69];
  const double d4F_dna3_dgaa = _hc0[68];
  const double d4F_dnb3_dgbb = _hc1[68];
  const double d4F_dna3_dla = _hc0[67];
  const double d4F_dnb3_dlb = _hc1[67];
  const double d4F_dna2_dgaa2 = _hc0[65];
  const double d4F_dnb2_dgbb2 = _hc1[65];
  const double d4F_dna2_dgaa_dla = _hc0[64];
  const double d4F_dnb2_dgbb_dlb = _hc1[64];
  const double d4F_dna2_dla2 = _hc0[62];
  const double d4F_dnb2_dlb2 = _hc1[62];
  const double d4F_dna_dgaa3 = _hc0[59];
  const double d4F_dnb_dgbb3 = _hc1[59];
  const double d4F_dna_dgaa2_dla = _hc0[58];
  const double d4F_dnb_dgbb2_dlb = _hc1[58];
  const double d4F_dna_dgaa_dla2 = _hc0[56];
  const double d4F_dnb_dgbb_dlb2 = _hc1[56];
  const double d4F_dna_dla3 = _hc0[53];
  const double d4F_dnb_dlb3 = _hc1[53];
  const double d4F_dgaa4 = _hc2[49];
  const double d4F_dgbb4 = _hc3[49];
  const double d4F_dgaa3_dla = _hc6[48];
  const double d4F_dgbb3_dlb = _hc7[48];
  const double d4F_dgaa2_dla2 = _hc6[46];
  const double d4F_dgbb2_dlb2 = _hc7[46];
  const double d4F_dgaa_dla3 = _hc6[43];
  const double d4F_dgbb_dlb3 = _hc7[43];
  const double d4F_dla4 = _hc6[39];
  const double d4F_dlb4 = _hc7[39];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 7] += d4F_dnb3_dlb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 0] += d4F_dna2_dgaa_dla;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 17] += d4F_dnb2_dgbb_dlb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 8] += d4F_dnb2_dlb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 0] += d4F_dna_dgaa2_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 23] += d4F_dnb_dgbb2_dlb;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 0] += d4F_dna_dgaa_dla2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 17] += d4F_dnb_dgbb_dlb2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 7] += d4F_dnb_dlb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 0] += d4F_dgaa3_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 19] += d4F_dgbb3_dlb;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 0] += d4F_dgaa2_dla2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 17] += d4F_dgbb2_dlb2;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 0] += d4F_dgaa_dla3;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 11] += d4F_dgbb_dlb3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 0] += d4F_dla4;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 4] += d4F_dlb4;
#endif
#endif
}
#endif