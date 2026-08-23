/*
  Generated from python/gga_exc/gga_x_2d_pbe.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_2d_pbe
*/

#ifndef _GGA_X_2D_PBE_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_2D_PBE_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_2D_PBE_HELPER_BODIES
#include "gga_x_2d_pbe.c"
#undef _GGA_X_2D_PBE_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_2D_PBE_HELPER_BODIES
#include "gga_x_2d_pbe.c"
#undef _GGA_X_2D_PBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_2D_PBE_HELPER_BODIES
#include "gga_x_2d_pbe.c"
#undef _GGA_X_2D_PBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_2D_PBE_HELPER_BODIES
#include "gga_x_2d_pbe.c"
#undef _GGA_X_2D_PBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_2D_PBE_HELPER_BODIES
#include "gga_x_2d_pbe.c"
#undef _GGA_X_2D_PBE_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_2d_pbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_2d_pbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_2d_pbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_2d_pbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_2d_pbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_2d_pbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_2d_pbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_2d_pbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_2d_pbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_2d_pbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_2D_PBE_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_m1_n3_2_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z - p->zeta_threshold + 0.1e1;
  const double _t2 = _t1 <= 0;
  const double _t3 = _t1 > 0;
  const double _t4 = my_piecewise3(_t3, z, p->zeta_threshold - 0.1e1);
  const double _t5 = xc_expm1((0.3e1 / 0.2e1)*xc_log1p(_t4));
#if _KMAX >= 1
  const double _t6 = my_piecewise3(_t3, 0.1e1, 0);
  const double _t7 = _t4 + 0.1e1;
  const double _t8 = _t5 + 0.1e1;
#endif

  const double f = my_piecewise3(_t2, xc_powr(p->zeta_threshold, 3, 2) - 0.1e1, _t5);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise3(_t2, 0, (0.3e1 / 0.2e1)*_t6*_t8/_t7);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise3(_t2, 0, (0.3e1 / 0.4e1)*(_t6 * _t6)*_t8/(_t7 * _t7));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise3(_t2, 0, -0.3e1 / 0.8e1*(_t6 * _t6 * _t6)*_t8/(_t7 * _t7 * _t7));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = my_piecewise3(_t2, 0, (0.9e1 / 0.16e2)*(_t6 * _t6 * _t6 * _t6)*_t8/(_t7 * _t7 * _t7 * _t7));
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n3_2_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  const double _t1 = -p->dens_threshold + n_s <= 0;
  const double _t2 = xc_powr(n_s, 1, 2);
  const double _t3 = (0.2e1 / 0.3e1)*_t2;
  const double _t4 = (0.1e1 / M_PI);
  const double _t5 = _t4/(n_s * n_s * n_s);
  const double _t6 = _t5*sigma_ss;
  const double _t7 = 0.022159179687499999*_t6 + 0.46039999999999998;
  const double _t8 = (0.1e1 / _t7);
  const double _t9 = 0.010202086328124998*_t8;
  const double _t10 = _t6*_t9 + 0.1e1;
  const double _t11 = xc_powr(0.2e1, 1, 2);
  const double _t12 = xc_powr(M_PI, -1, 2);
  const double _t13 = _hc0[0] + 0.1e1;
  const double _t14 = _t11*_t12*_t13;
  const double _t15 = _t10*_t14;
  const double _t16 = my_piecewise3(_t1, 0, -_t15*_t3);
#if _KMAX >= 1
  const double _t17 = xc_powi(n_s, -6);
  const double _t18 = (0.1e1 / (M_PI * M_PI));
  const double _t19 = (0.1e1 / (_t7 * _t7));
  const double _t20 = _t18*_t19;
  const double _t21 = _t17*_t20;
  const double _t22 = -0.00022606986413230891*_t21*sigma_ss + _t5*_t9;
  const double _t23 = _t14*_t3;
  const double _t24 = my_piecewise3(_t1, 0, -_t22*_t23);
  const double _t25 = _t14/_t2;
  const double _t26 = (0.1e1 / 0.3e1)*_t25;
  const double _t27 = _t4*_t8;
  const double _t28 = 0.030606258984374995*_t27/(n_s * n_s * n_s * n_s);
  const double _t29 = xc_powi(n_s, -7);
  const double _t30 = (sigma_ss * sigma_ss);
  const double _t31 = 0.00067820959239692669*_t18*_t19*_t29*_t30 - _t28*sigma_ss;
  const double _t32 = _t14*_t31;
  const double _t33 = my_piecewise3(_t1, 0, -_t10*_t26 - _t3*_t32);
#endif
#if _KMAX >= 2
  const double _t34 = (0.1e1 / (M_PI * M_PI * M_PI));
  const double _t35 = xc_powi(n_s, -9);
  const double _t36 = (0.1e1 / (_t7 * _t7 * _t7));
  const double _t37 = -0.00045213972826461783*_t21 + 1.0019045482473089e-5*_t34*_t35*_t36*sigma_ss;
  const double _t38 = my_piecewise3(_t1, 0, -_t23*_t37);
  const double _t39 = xc_powi(n_s, -10);
  const double _t40 = _t34*_t36;
  const double _t41 = _t39*_t40;
  const double _t42 = 0.0020346287771907802*_t18*_t19*_t29*sigma_ss - _t28 - 3.0057136447419265e-5*_t30*_t41;
  const double _t43 = my_piecewise3(_t1, 0, -_t22*_t26 - _t23*_t42);
  const double _t44 = xc_powr(n_s, -3, 2);
  const double _t45 = (0.2e1 / 0.3e1)*_t25;
  const double _t46 = 0.12242503593749998*_t27/xc_powi(n_s, 5);
  const double _t47 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t48 = xc_powi(n_s, -11);
  const double _t49 = _t40*_t48;
  const double _t50 = _t20/xc_powi(n_s, 8);
  const double _t51 = -0.0067820959239692676*_t30*_t50 + _t46*sigma_ss + 9.0171409342257791e-5*_t47*_t49;
  const double _t52 = my_piecewise3(_t1, 0, (0.1e1 / 0.6e1)*_t10*_t11*_t12*_t13*_t44 - _t14*_t3*_t51 - _t31*_t45);
#endif
#if _KMAX >= 3
  const double _t53 = xc_powi(n_s, -12);
  const double _t54 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t55 = (0.1e1 / (_t7 * _t7 * _t7 * _t7));
  const double _t56 = _t54*_t55;
  const double _t57 = _t53*_t56;
  const double _t58 = 3.0057136447419268e-5*_t35*_t40 - 6.660414874300689e-7*_t57*sigma_ss;
  const double _t59 = my_piecewise3(_t1, 0, -_t23*_t58);
  const double _t60 = xc_powi(n_s, -13);
  const double _t61 = 0.0027128383695877072*_t20*_t29 + 1.9981244622902066e-6*_t30*_t56*_t60 - 0.00015028568223709633*_t41*sigma_ss;
  const double _t62 = my_piecewise3(_t1, 0, -_t23*_t61 - _t26*_t37);
  const double _t63 = _t56/xc_powi(n_s, 14);
  const double _t64 = 0.00057108559250096608*_t30*_t49 + _t46 - 5.994373386870619e-6*_t47*_t63 - 0.016277030217526241*_t50*sigma_ss;
  const double _t65 = my_piecewise3(_t1, 0, (0.1e1 / 0.6e1)*_t11*_t12*_t13*_t22*_t44 - _t23*_t64 - _t42*_t45);
  const double _t66 = xc_powr(n_s, -5, 2);
  const double _t67 = (0.1e1 / 0.4e1)*_t66;
  const double _t68 = 0.61212517968749991*_t17*_t27;
  const double _t69 = xc_powi(n_s, -15);
  const double _t70 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t71 = _t40*_t53;
  const double _t72 = 0.062395282500517263*_t18*_t19*_t30*_t35 - 0.0018935995961874136*_t47*_t71 + 1.7983120160611859e-5*_t54*_t55*_t69*_t70 - _t68*sigma_ss;
  const double _t73 = my_piecewise3(_t1, 0, (0.1e1 / 0.2e1)*_t11*_t12*_t13*_t31*_t44 - _t15*_t67 - _t23*_t72 - _t25*_t51);
#endif
#if _KMAX >= 4
  const double _t74 = xc_powi(M_PI, -5);
  const double _t75 = xc_powi(_t7, -5);
  const double _t76 = xc_powi(n_s, -16);
  const double _t77 = _t74*_t75;
#endif

  const double f = my_piecewise3(_t1, 0, _t16*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t1, 0, _t24*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t1, 0, _t16 + _t33*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t1, 0, _t38*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t1, 0, _t24 + _t43*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t1, 0, 0.2e1*_t33 + _t52*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t1, 0, _t59*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t1, 0, _t38 + _t62*n_s);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t1, 0, 0.2e1*_t43 + _t65*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t1, 0, 0.3e1*_t52 + _t73*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, -_t23*(-2.6641659497202756e-6*_t57 + 5.9035731997170672e-8*_t69*_t74*_t75*sigma_ss)));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t1, 0, _t59 + n_s*my_piecewise3(_t1, 0, -_t23*(-1.7710719599151201e-7*_t30*_t76*_t77 - 0.00027051422802677337*_t41 + 1.3986871236031445e-5*_t54*_t55*_t60*sigma_ss) - _t26*_t58));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t1, 0, 0.2e1*_t62 + n_s*my_piecewise3(_t1, 0, (0.1e1 / 0.6e1)*_t11*_t12*_t13*_t37*_t44 - _t23*(-5.5947484944125782e-5*_t30*_t63 + 0.0018635424597399945*_t34*_t36*_t48*sigma_ss + 5.3132158797453593e-7*_t47*_t74*_t75/xc_powi(n_s, 17) - 0.018989868587113948*_t50) - _t45*_t61));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t1, 0, 0.3e1*_t65 + n_s*my_piecewise3(_t1, 0, (0.1e1 / 0.2e1)*_t11*_t12*_t13*_t42*_t44 - _t14*_t22*_t67 - _t23*(0.13835475684897305*_t18*_t19*_t35*sigma_ss - 0.0084460553417248126*_t30*_t71 + 0.00019781432176673043*_t47*_t54*_t55*_t69 - _t68 - 1.593964763923608e-6*_t70*_t77/xc_powi(n_s, 18)) - _t25*_t64));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t1, 0, 0.4e1*_t73 + n_s*my_piecewise3(_t1, 0, (0.5e1 / 0.8e1)*_t10*_t11*_t12*_t13/xc_powr(n_s, 7, 2) + _t11*_t12*_t13*_t44*_t51 - _t23*(-0.60225011804847095*_t20*_t30*_t39 + 3.6727510781249997*_t27*_t29*sigma_ss + 0.031018964813736678*_t40*_t47*_t60 - 0.0006473923257820269*_t56*_t70*_t76 + 4.7818942917708242e-6*_t77*xc_powi(sigma_ss, 5)/xc_powi(n_s, 19)) - 0.4e1 / 0.3e1*_t25*_t72 - _t32*_t66));
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