/*
  Generated from python/gga_exc/gga_k_apbe.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_k_apbe
*/

#ifndef _GGA_K_APBE_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_K_APBE_KERNEL_BODY
#define _KMAX 0
#define _GGA_K_APBE_HELPER_BODIES
#include "gga_k_apbe.c"
#undef _GGA_K_APBE_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_K_APBE_HELPER_BODIES
#include "gga_k_apbe.c"
#undef _GGA_K_APBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_K_APBE_HELPER_BODIES
#include "gga_k_apbe.c"
#undef _GGA_K_APBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_K_APBE_HELPER_BODIES
#include "gga_k_apbe.c"
#undef _GGA_K_APBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_K_APBE_HELPER_BODIES
#include "gga_k_apbe.c"
#undef _GGA_K_APBE_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_k_apbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_k_apbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_k_apbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_k_apbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_k_apbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_k_apbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_k_apbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_k_apbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_k_apbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_k_apbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_K_APBE_HELPER_BODIES)

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
  const gga_k_apbe_params *params = (const gga_k_apbe_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n5_3_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  const double _t1 = -p->dens_threshold + n_s <= 0;
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = _t2*sigma_ss;
  const double _t4 = (M_PI * M_CBRTPI);
  const double _t5 = params->mu/_t4;
  const double _t6 = _t3*_t5;
  const double _t7 = (0.1e1 / 0.24e2)/xc_powr(n_s, 8, 3);
  const double _t8 = _t6*_t7;
  const double _t9 = _t8 + params->kappa;
  const double _t10 = (0.1e1 / _t9);
  const double _t11 = _t10*params->kappa;
  const double _t12 = xc_powr(0.3e1, 2, 3)*_t4*(_hc0[0] + 0.1e1);
  const double _t13 = _t12*(_t11*_t8 + 0.1e1);
  const double _t14 = (0.3e1 / 0.20e2)*xc_powr(n_s, 2, 3);
  const double _t15 = my_piecewise3(_t1, 0, _t13*_t14);
#if _KMAX >= 1
  const double _t16 = _t2*params->kappa;
  const double _t17 = _t10*_t16*_t5;
  const double _t18 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t19 = (0.1e1 / (_t9 * _t9));
  const double _t20 = ((params->mu) * (params->mu));
  const double _t21 = xc_powr(0.6e1, 2, 3);
  const double _t22 = _t21*params->kappa;
  const double _t23 = _t18*_t19*_t20*_t22;
  const double _t24 = _t23/xc_powr(n_s, 16, 3);
  const double _t25 = _t17*_t7 - 0.1e1 / 0.576e3*_t24*sigma_ss;
  const double _t26 = _t12*_t14;
  const double _t27 = my_piecewise3(_t1, 0, _t25*_t26);
  const double _t28 = xc_powr(n_s, -1, 3);
  const double _t29 = (0.1e1 / 0.10e2)*_t28;
  const double _t30 = (0.1e1 / 0.9e1)/xc_powr(n_s, 11, 3);
  const double _t31 = _t11*_t6;
  const double _t32 = xc_powr(n_s, -19, 3);
  const double _t33 = (sigma_ss * sigma_ss);
  const double _t34 = (0.1e1 / 0.216e3)*_t18*_t19*_t20*_t21*_t32*_t33*params->kappa - _t30*_t31;
  const double _t35 = my_piecewise3(_t1, 0, _t13*_t29 + _t26*_t34);
#endif
#if _KMAX >= 2
  const double _t36 = params->kappa*((params->mu) * (params->mu) * (params->mu))/((M_PI * M_PI * M_PI * M_PI)*(_t9 * _t9 * _t9));
  const double _t37 = _t36/xc_powi(n_s, 8);
  const double _t38 = -0.1e1 / 0.288e3*_t24 + (0.1e1 / 0.1152e4)*_t37*sigma_ss;
  const double _t39 = my_piecewise3(_t1, 0, _t26*_t38);
  const double _t40 = _t12*_t29;
  const double _t41 = _t36/xc_powi(n_s, 9);
  const double _t42 = -_t17*_t30 + (0.1e1 / 0.72e2)*_t18*_t19*_t20*_t21*_t32*params->kappa*sigma_ss - 0.1e1 / 0.432e3*_t33*_t41;
  const double _t43 = my_piecewise3(_t1, 0, _t25*_t40 + _t26*_t42);
  const double _t44 = xc_powr(n_s, -4, 3);
  const double _t45 = (0.1e1 / 0.30e2)*_t44;
  const double _t46 = _t12*_t34;
  const double _t47 = (0.1e1 / 0.5e1)*_t28;
  const double _t48 = (0.11e2 / 0.27e2)/xc_powr(n_s, 14, 3);
  const double _t49 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t50 = _t36/xc_powi(n_s, 10);
  const double _t51 = _t23/xc_powr(n_s, 22, 3);
  const double _t52 = _t31*_t48 - 0.1e1 / 0.24e2*_t33*_t51 + (0.1e1 / 0.162e3)*_t49*_t50;
  const double _t53 = my_piecewise3(_t1, 0, -_t13*_t45 + _t26*_t52 + _t46*_t47);
#endif
#if _KMAX >= 3
  const double _t54 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t55 = (0.1e1 / (_t9 * _t9 * _t9 * _t9));
  const double _t56 = ((params->mu) * (params->mu) * (params->mu) * (params->mu));
  const double _t57 = _t54*_t55*_t56;
  const double _t58 = _t57/xc_powr(n_s, 32, 3);
  const double _t59 = -0.1e1 / 0.9216e4*_t3*_t58*params->kappa + (0.1e1 / 0.384e3)*_t37;
  const double _t60 = my_piecewise3(_t1, 0, _t26*_t59);
  const double _t61 = xc_powr(n_s, -35, 3);
  const double _t62 = _t16*_t57;
  const double _t63 = _t33*_t62;
  const double _t64 = (0.1e1 / 0.54e2)*_t23*_t32 - 0.5e1 / 0.432e3*_t41*sigma_ss + (0.1e1 / 0.3456e4)*_t61*_t63;
  const double _t65 = my_piecewise3(_t1, 0, _t26*_t64 + _t38*_t40);
  const double _t66 = _t12*_t45;
  const double _t67 = _t12*_t47;
  const double _t68 = xc_powr(n_s, -38, 3);
  const double _t69 = _t17*_t48 + (0.17e2 / 0.432e3)*_t33*_t50 - 0.1e1 / 0.1296e4*_t49*_t62*_t68 - 0.65e2 / 0.648e3*_t51*sigma_ss;
  const double _t70 = my_piecewise3(_t1, 0, -_t25*_t66 + _t26*_t69 + _t42*_t67);
  const double _t71 = xc_powr(n_s, -7, 3);
  const double _t72 = (0.2e1 / 0.45e2)*_t71;
  const double _t73 = (0.1e1 / 0.10e2)*_t44;
  const double _t74 = _t12*_t52;
  const double _t75 = (0.3e1 / 0.10e2)*_t28;
  const double _t76 = (0.154e3 / 0.81e2)/xc_powr(n_s, 17, 3);
  const double _t77 = _t36/xc_powi(n_s, 11);
  const double _t78 = xc_powr(n_s, -41, 3);
  const double _t79 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t80 = xc_powr(n_s, -25, 3);
  const double _t81 = (0.341e3 / 0.972e3)*_t18*_t19*_t20*_t21*_t33*_t80*params->kappa + (0.1e1 / 0.486e3)*_t2*_t54*_t55*_t56*_t78*_t79*params->kappa - _t31*_t76 - 0.19e2 / 0.162e3*_t49*_t77;
  const double _t82 = my_piecewise3(_t1, 0, _t13*_t72 + _t26*_t81 - _t46*_t73 + _t74*_t75);
#endif
#if _KMAX >= 4
  const double _t83 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t84 = xc_powi((params->mu), 5);
  const double _t85 = xc_powi(_t9, -5);
  const double _t86 = _t22*_t83*_t84*_t85;
#endif

  const double f = my_piecewise3(_t1, 0, _t15*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t1, 0, _t27*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t1, 0, _t15 + _t35*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t1, 0, _t39*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t1, 0, _t27 + _t43*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t1, 0, 0.2e1*_t35 + _t53*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t1, 0, _t60*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t1, 0, _t39 + _t65*n_s);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t1, 0, 0.2e1*_t43 + _t70*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t1, 0, 0.3e1*_t53 + _t82*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, _t26*(-0.1e1 / 0.2304e4*_t16*_t58 + (0.1e1 / 0.55296e5)*_t21*_t83*_t84*_t85*params->kappa*sigma_ss/xc_powr(n_s, 40, 3))));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t1, 0, _t60 + n_s*my_piecewise3(_t1, 0, _t26*((0.7e1 / 0.3456e4)*_t2*_t54*_t55*_t56*_t61*params->kappa*sigma_ss - 0.1e1 / 0.20736e5*_t33*_t86/xc_powr(n_s, 43, 3) - 0.1e1 / 0.48e2*_t41) + _t40*_t59));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t1, 0, 0.2e1*_t65 + n_s*my_piecewise3(_t1, 0, _t26*((0.1e1 / 0.7776e4)*_t49*_t86/xc_powr(n_s, 46, 3) + (0.167e3 / 0.1296e4)*_t50*sigma_ss - 0.19e2 / 0.162e3*_t51 - 0.25e2 / 0.3456e4*_t63*_t68) - _t38*_t66 + _t64*_t67));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t1, 0, 0.3e1*_t70 + n_s*my_piecewise3(_t1, 0, _t12*_t25*_t72 - _t12*_t42*_t73 + _t12*_t69*_t75 + _t26*(-_t17*_t76 + (0.253e3 / 0.324e3)*_t18*_t19*_t20*_t21*_t80*params->kappa*sigma_ss + (0.89e2 / 0.3888e4)*_t2*_t49*_t54*_t55*_t56*_t78*params->kappa - 0.1025e4 / 0.1944e4*_t33*_t77 - 0.1e1 / 0.2916e4*_t79*_t86/xc_powr(n_s, 49, 3))));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t1, 0, 0.4e1*_t82 + n_s*my_piecewise3(_t1, 0, (0.2e1 / 0.5e1)*_t12*_t28*_t81 - 0.14e2 / 0.135e3*_t13/xc_powr(n_s, 10, 3) + _t26*(-0.3047e4 / 0.972e3*_t23*_t33/xc_powr(n_s, 28, 3) + (0.2618e4 / 0.243e3)*_t31/xc_powr(n_s, 20, 3) + (0.2563e4 / 0.1458e4)*_t36*_t49/xc_powi(n_s, 12) - 0.49e2 / 0.729e3*_t62*_t79/xc_powr(n_s, 44, 3) + (0.2e1 / 0.2187e4)*_t86*xc_powi(sigma_ss, 5)/xc_powr(n_s, 52, 3)) - 0.1e1 / 0.5e1*_t44*_t74 + (0.8e1 / 0.45e2)*_t46*_t71));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_k_apbe_params *params = (const gga_k_apbe_params *)(p->params);
  (void)params;
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