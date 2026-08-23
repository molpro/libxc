/*
  Generated from python/gga_exc/gga_k_exp4.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_k_exp4
*/

#ifndef _GGA_K_EXP4_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_K_EXP4_KERNEL_BODY
#define _KMAX 0
#define _GGA_K_EXP4_HELPER_BODIES
#include "gga_k_exp4.c"
#undef _GGA_K_EXP4_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_K_EXP4_HELPER_BODIES
#include "gga_k_exp4.c"
#undef _GGA_K_EXP4_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_K_EXP4_HELPER_BODIES
#include "gga_k_exp4.c"
#undef _GGA_K_EXP4_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_K_EXP4_HELPER_BODIES
#include "gga_k_exp4.c"
#undef _GGA_K_EXP4_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_K_EXP4_HELPER_BODIES
#include "gga_k_exp4.c"
#undef _GGA_K_EXP4_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_k_exp4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_k_exp4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_k_exp4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_k_exp4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_k_exp4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_k_exp4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_k_exp4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_k_exp4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_k_exp4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_k_exp4.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_K_EXP4_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n5_3_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  const double _t1 = -p->dens_threshold + n_s <= 0;
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (M_PI * M_CBRTPI);
  const double _t4 = _t2/_t3;
  const double _t5 = _t4/xc_powr(n_s, 8, 3);
  const double _t6 = xc_expm1(-8.3254166666666656*_t5*sigma_ss);
  const double _t7 = (sigma_ss * sigma_ss);
  const double _t8 = xc_powr(n_s, -16, 3);
  const double _t9 = xc_powr(0.6e1, 2, 3);
  const double _t10 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t11 = _t10*_t9;
  const double _t12 = _t11*_t8;
  const double _t13 = xc_expm1(-0.0075479166666666663*_t12*_t7);
  const double _t14 = xc_powr(0.3e1, 2, 3)*_t3*(_hc0[0] + 0.1e1);
  const double _t15 = _t14*(-1.2263999999999999*_t13 - 0.85240000000000005*_t6);
  const double _t16 = (0.3e1 / 0.20e2)*xc_powr(n_s, 2, 3);
  const double _t17 = my_piecewise3(_t1, 0, _t15*_t16);
#if _KMAX >= 1
  const double _t18 = _t6 + 0.1e1;
  const double _t19 = _t13 + 0.1e1;
  const double _t20 = 0.018513529999999997*_t12*_t19*sigma_ss + 7.0965851666666664*_t18*_t5;
  const double _t21 = _t14*_t16;
  const double _t22 = my_piecewise3(_t1, 0, _t20*_t21);
  const double _t23 = xc_powr(n_s, -1, 3);
  const double _t24 = (0.1e1 / 0.10e2)*_t23;
  const double _t25 = _t18*_t4;
  const double _t26 = 18.924227111111108*_t25/xc_powr(n_s, 11, 3);
  const double _t27 = xc_powr(n_s, -19, 3);
  const double _t28 = _t11*_t19*_t27;
  const double _t29 = -_t26*sigma_ss - 0.049369413333333327*_t28*_t7;
  const double _t30 = my_piecewise3(_t1, 0, _t15*_t24 + _t21*_t29);
#endif
#if _KMAX >= 2
  const double _t31 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t32 = _t2*_t31;
  const double _t33 = _t32/xc_powr(n_s, 32, 3);
  const double _t34 = _t19*_t33;
  const double _t35 = 0.018513529999999997*_t10*_t19*_t8*_t9 - 59.082028422986099*_t12*_t18 - 0.0016768629797499998*_t34*_t7;
  const double _t36 = my_piecewise3(_t1, 0, _t21*_t35);
  const double _t37 = _t14*_t24;
  const double _t38 = 0.098738826666666654*_t28;
  const double _t39 = xc_powr(n_s, -35, 3);
  const double _t40 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t41 = 157.55207579462959*_t10*_t18*_t27*_t9*sigma_ss + 0.004471634612666666*_t19*_t2*_t31*_t39*_t40 - _t26 - _t38*sigma_ss;
  const double _t42 = my_piecewise3(_t1, 0, _t20*_t37 + _t21*_t41);
  const double _t43 = xc_powr(n_s, -4, 3);
  const double _t44 = (0.1e1 / 0.30e2)*_t43;
  const double _t45 = _t14*_t29;
  const double _t46 = (0.1e1 / 0.5e1)*_t23;
  const double _t47 = 69.388832740740725*_t25/xc_powr(n_s, 14, 3);
  const double _t48 = xc_powr(n_s, -22, 3);
  const double _t49 = _t11*_t48;
  const double _t50 = _t18*_t49;
  const double _t51 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t52 = xc_powr(n_s, -38, 3);
  const double _t53 = _t19*_t32;
  const double _t54 = _t52*_t53;
  const double _t55 = _t19*_t49;
  const double _t56 = _t47*sigma_ss - 420.13886878567888*_t50*_t7 - 0.011924358967111108*_t51*_t54 + 0.31267295111111104*_t55*_t7;
  const double _t57 = my_piecewise3(_t1, 0, -_t15*_t44 + _t21*_t56 + _t45*_t46);
#endif
#if _KMAX >= 3
  const double _t58 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t59 = _t18*_t58;
  const double _t60 = xc_powi(n_s, -16);
  const double _t61 = xc_powi(M_PI, -8);
  const double _t62 = _t19*_t61;
  const double _t63 = 0.0050305889392499997*_t34;
  const double _t64 = 0.00015188186439085623*_t40*_t60*_t62 + 2951.295024799213*_t59/xc_powi(n_s, 8) - _t63*sigma_ss;
  const double _t65 = my_piecewise3(_t1, 0, _t21*_t64);
  const double _t66 = _t59/xc_powi(n_s, 9);
  const double _t67 = _t62/xc_powi(n_s, 17);
  const double _t68 = 315.10415158925917*_t10*_t18*_t27*_t9 + 0.02235817306333333*_t19*_t2*_t31*_t39*_t7 - _t38 - 0.00040501830504228325*_t51*_t67 - 7870.1200661312323*_t66*sigma_ss;
  const double _t69 = my_piecewise3(_t1, 0, _t21*_t68 + _t35*_t37);
  const double _t70 = _t14*_t44;
  const double _t71 = _t14*_t46;
  const double _t72 = xc_powi(n_s, -10);
  const double _t73 = xc_powi(sigma_ss, 5);
  const double _t74 = xc_powi(n_s, -18);
  const double _t75 = -0.076017788415333312*_t40*_t54 + _t47 - 1417.9686821516661*_t50*sigma_ss + 0.62534590222222208*_t55*sigma_ss + 20986.986843016621*_t59*_t7*_t72 + 0.0010800488134460884*_t62*_t73*_t74;
  const double _t76 = my_piecewise3(_t1, 0, -_t20*_t70 + _t21*_t75 + _t41*_t71);
  const double _t77 = xc_powr(n_s, -7, 3);
  const double _t78 = (0.2e1 / 0.45e2)*_t77;
  const double _t79 = (0.1e1 / 0.10e2)*_t43;
  const double _t80 = _t14*_t56;
  const double _t81 = (0.3e1 / 0.10e2)*_t23;
  const double _t82 = _t59/xc_powi(n_s, 11);
  const double _t83 = 323.8145527901234*_t25/xc_powr(n_s, 17, 3);
  const double _t84 = xc_powi(sigma_ss, 6);
  const double _t85 = _t62/xc_powi(n_s, 19);
  const double _t86 = xc_powr(n_s, -25, 3);
  const double _t87 = xc_powr(n_s, -41, 3);
  const double _t88 = _t11*_t19*_t86;
  const double _t89 = 4621.5275566424671*_t10*_t18*_t7*_t86*_t9 + 0.22656282037511105*_t19*_t2*_t31*_t51*_t87 - 55965.298248044324*_t40*_t82 - 2.292934974814814*_t7*_t88 - _t83*sigma_ss - 0.0028801301691895693*_t84*_t85;
  const double _t90 = my_piecewise3(_t1, 0, _t15*_t78 + _t21*_t89 - _t45*_t79 + _t80*_t81);
#endif
#if _KMAX >= 4
  const double _t91 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t92 = _t19*_t9*_t91;
  const double _t93 = _t18*_t32;
  const double _t94 = _t18*_t7;
  const double _t95 = _t51/xc_powr(n_s, 44, 3);
  const double _t96 = _t11/xc_powr(n_s, 28, 3);
#endif

  const double f = my_piecewise3(_t1, 0, _t17*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t1, 0, _t22*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t1, 0, _t17 + _t30*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t1, 0, _t36*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t1, 0, _t22 + _t42*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t1, 0, 0.2e1*_t30 + _t57*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t1, 0, _t65*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t1, 0, _t36 + _t69*n_s);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t1, 0, 0.2e1*_t42 + _t76*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t1, 0, 0.3e1*_t57 + _t90*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, _t21*(-24570.760787713778*_t18*_t33 + 0.0009112911863451374*_t19*_t60*_t61*_t7 - 2.2927833112003004e-6*_t51*_t92/xc_powr(n_s, 64, 3) - _t63)));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t1, 0, _t65 + n_s*my_piecewise3(_t1, 0, _t21*(0.053659615351999992*_t39*_t53*sigma_ss + 65522.028767236719*_t39*_t93*sigma_ss - 0.0036451647453805496*_t40*_t67 - 23610.360198393697*_t66 + 6.1140888298674673e-6*_t73*_t92/xc_powr(n_s, 67, 3)) + _t37*_t64));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t1, 0, 0.2e1*_t69 + n_s*my_piecewise3(_t1, 0, _t21*(0.62534590222222208*_t10*_t19*_t48*_t9 + 112805.05428121434*_t18*_t58*_t72*sigma_ss + 0.012285555252949257*_t19*_t51*_t61*_t74 - 174725.41004596461*_t32*_t52*_t94 - 1995.6596267319746*_t50 - 0.28469407033977773*_t54*_t7 - 1.6304236879646576e-5*_t84*_t92/xc_powr(n_s, 70, 3)) - _t35*_t70 + _t68*_t71));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t1, 0, 0.3e1*_t76 + n_s*my_piecewise3(_t1, 0, _t14*_t20*_t78 - _t14*_t41*_t79 + _t14*_t75*_t81 + _t21*(11938.94618799304*_t10*_t18*_t86*_t9*sigma_ss + 465934.42678923893*_t18*_t2*_t31*_t40*_t87 + 1.113933866844296*_t19*_t2*_t31*_t40*_t87 + 4.3477965012390869e-5*_t19*_t9*_t91*xc_powi(sigma_ss, 7)/xc_powr(n_s, 73, 3) - 398752.75001731579*_t7*_t82 - 0.037801708470613093*_t73*_t85 - _t83 - 4.585869949629628*_t88*sigma_ss)));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t1, 0, 0.4e1*_t90 + n_s*my_piecewise3(_t1, 0, (0.2e1 / 0.5e1)*_t14*_t23*_t89 - 0.14e2 / 0.135e3*_t15/xc_powr(n_s, 10, 3) + _t21*(19.107791456790117*_t19*_t7*_t96 + 1834.949132477366*_t25*sigma_ss/xc_powr(n_s, 20, 3) + 1231236.5614569751*_t40*_t59/xc_powi(n_s, 12) - 3.6501787727101225*_t53*_t95 + 0.10944494642920363*_t62*_t84/xc_powi(n_s, 20) - 0.00011594124003304232*_t92*xc_powi(sigma_ss, 8)/xc_powr(n_s, 76, 3) - 1242491.8047713039*_t93*_t95 - 45701.772504575507*_t94*_t96) - 0.1e1 / 0.5e1*_t43*_t80 + (0.8e1 / 0.45e2)*_t45*_t77));
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