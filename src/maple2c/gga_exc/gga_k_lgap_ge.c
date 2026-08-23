/*
  Generated from python/gga_exc/gga_k_lgap_ge.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_k_lgap_ge
*/

#ifndef _GGA_K_LGAP_GE_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_K_LGAP_GE_KERNEL_BODY
#define _KMAX 0
#define _GGA_K_LGAP_GE_HELPER_BODIES
#include "gga_k_lgap_ge.c"
#undef _GGA_K_LGAP_GE_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_K_LGAP_GE_HELPER_BODIES
#include "gga_k_lgap_ge.c"
#undef _GGA_K_LGAP_GE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_K_LGAP_GE_HELPER_BODIES
#include "gga_k_lgap_ge.c"
#undef _GGA_K_LGAP_GE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_K_LGAP_GE_HELPER_BODIES
#include "gga_k_lgap_ge.c"
#undef _GGA_K_LGAP_GE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_K_LGAP_GE_HELPER_BODIES
#include "gga_k_lgap_ge.c"
#undef _GGA_K_LGAP_GE_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_k_lgap_ge.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_k_lgap_ge.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_k_lgap_ge.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_k_lgap_ge.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_k_lgap_ge.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_k_lgap_ge.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_k_lgap_ge.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_k_lgap_ge.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_k_lgap_ge.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_k_lgap_ge.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_K_LGAP_GE_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(lgap_ge_f0_k, _KMAX)(const xc_func_type *p, double s, double *out) {
  const gga_k_lgap_ge_params *params = (const gga_k_lgap_ge_params *)(p->params);

  const double _t1 = (s * s);
#if _KMAX >= 1
  const double _t2 = 0.2e1*params->mu[1];
#endif
#if _KMAX >= 2
  const double _t3 = 0.6e1*params->mu[2];
#endif

  const double f = _t1*params->mu[1] + params->mu[0]*s + params->mu[2]*(s * s * s) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = 0.3e1*_t1*params->mu[2] + _t2*s + params->mu[0];
  out[1] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = _t2 + _t3*s;
  out[2] = d2f_ds2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = _t3;
  out[3] = d3f_ds3;
#endif
#if _KMAX >= 4
  const double d4f_ds4 = 0;
  out[4] = d4f_ds4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lgap_ge_f_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (0.1e1 / 0.12e2)*xc_powr(0.6e1, 2, 3)/(M_CBRTPI * M_CBRTPI);
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lgap_ge_f0_k, _KMAX)(p, _t1*x, _hc0);

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _hc0[1]*_t1;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = (0.1e1 / 0.24e2)*xc_powr(0.6e1, 1, 3)*_hc0[2]/(M_PI * M_CBRTPI);
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = (0.1e1 / 0.48e2)*_hc0[3]/(M_PI * M_PI);
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0;
  out[4] = d4f_dx4;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double *out) {
  const gga_k_lgap_ge_params *params = (const gga_k_lgap_ge_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n5_3_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  const double _t1 = xc_powr(n_s, -4, 3);
  const double _t2 = xc_powr(sigma_ss, 1, 2);
  const double _t3 = -p->dens_threshold + n_s <= 0;
  const double _t4 = xc_powr(n_s, 2, 3);
  const double _t5 = xc_powr(0.3e1, 2, 3);
  const double _t6 = (M_PI * M_CBRTPI);
  const double _t7 = _hc0[0] + 0.1e1;
  const double _t8 = _t5*_t6*_t7;
#if _KMAX >= 1
  const double _t11 = (0.1e1 / _t2);
  const double _t15 = xc_powr(n_s, -5, 3);
  const double _t17 = (0.1e1 / 0.5e1)*_t2;
#endif
#if _KMAX >= 2
  const double _t19 = xc_powr(sigma_ss, 3, 2);
  const double _t20 = (0.1e1 / _t19);
  const double _t21 = (0.1e1 / (n_s * n_s));
  const double _t22 = (0.1e1 / sigma_ss);
  const double _t24 = (0.1e1 / (n_s * n_s * n_s));
  const double _t27 = (0.1e1 / 0.20e2)*_t11;
#endif
#if _KMAX >= 3
  const double _t32 = xc_powr(sigma_ss, -5, 2);
  const double _t33 = (0.9e1 / 0.160e3)*_t32;
  const double _t34 = (sigma_ss * sigma_ss);
  const double _t35 = (0.1e1 / _t34);
  const double _t36 = xc_powr(n_s, -10, 3);
  const double _t40 = (0.1e1 / 0.40e2)*_t22;
  const double _t41 = xc_powr(n_s, -13, 3);
#endif
#if _KMAX >= 4
  const double _t49 = xc_powr(n_s, -14, 3);
#endif
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lgap_ge_f_k, _KMAX)(p, _t1*_t2, _hc1);
  const double _t9 = _hc1[0]*_t8;
  const double _t10 = my_piecewise3(_t3, 0, (0.3e1 / 0.20e2)*_t4*_t9);
#if _KMAX >= 1
  const double _t12 = _hc1[1]*_t8;
  const double _t13 = _t12/_t4;
  const double _t14 = my_piecewise3(_t3, 0, (0.3e1 / 0.40e2)*_t11*_t13);
  const double _t16 = _t12*_t15;
  const double _t18 = my_piecewise3(_t3, 0, -_t16*_t17 + (0.1e1 / 0.10e2)*_t9/xc_powr(n_s, 1, 3));
#endif
#if _KMAX >= 2
  const double _t23 = my_piecewise3(_t3, 0, (0.3e1 / 0.80e2)*_hc1[2]*_t21*_t22*_t5*_t6*_t7 - 0.3e1 / 0.80e2*_t13*_t20);
  const double _t25 = _hc1[2]*_t8;
  const double _t26 = _t24*_t25;
  const double _t28 = my_piecewise3(_t3, 0, -_t16*_t27 - 0.1e1 / 0.10e2*_t26);
  const double _t29 = _t25/(n_s * n_s * n_s * n_s);
  const double _t30 = _t12/xc_powr(n_s, 8, 3);
  const double _t31 = my_piecewise3(_t3, 0, -0.1e1 / 0.30e2*_t1*_t9 + _t17*_t30 + (0.4e1 / 0.15e2)*_t29*sigma_ss);
#endif
#if _KMAX >= 3
  const double _t37 = _hc1[3]*_t8;
  const double _t38 = _t36*_t37;
  const double _t39 = my_piecewise3(_t3, 0, _t13*_t33 + (0.3e1 / 0.160e3)*_t20*_t38 - 0.9e1 / 0.160e3*_t21*_t25*_t35);
  const double _t42 = my_piecewise3(_t3, 0, (0.1e1 / 0.40e2)*_hc1[1]*_t15*_t20*_t5*_t6*_t7 - _t26*_t40 - _t27*_t37*_t41);
  const double _t43 = _t37/xc_powr(n_s, 16, 3);
  const double _t44 = my_piecewise3(_t3, 0, (0.1e1 / 0.12e2)*_t11*_t30 + (0.2e1 / 0.15e2)*_t2*_t43 + (0.11e2 / 0.30e2)*_t29);
  const double _t45 = _t25/xc_powi(n_s, 5);
  const double _t46 = _t12/xc_powr(n_s, 11, 3);
  const double _t47 = _t37/xc_powr(n_s, 19, 3);
  const double _t48 = my_piecewise3(_t3, 0, (0.2e1 / 0.45e2)*_hc1[0]*_t5*_t6*_t7/xc_powr(n_s, 7, 3) - 0.16e2 / 0.45e2*_t19*_t47 - 0.22e2 / 0.45e2*_t2*_t46 - 0.4e1 / 0.3e1*_t45*sigma_ss);
#endif
#if _KMAX >= 4
  const double _t50 = _hc1[4]*_t8;
#endif

  const double f = my_piecewise3(_t3, 0, _t10*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t3, 0, _t14*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t3, 0, _t10 + _t18*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t3, 0, _t23*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t3, 0, _t14 + _t28*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t3, 0, 0.2e1*_t18 + _t31*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t3, 0, _t39*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t3, 0, _t23 + _t42*n_s);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t3, 0, 0.2e1*_t28 + _t44*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t3, 0, 0.3e1*_t31 + _t48*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, (0.9e1 / 0.64e2)*_hc1[2]*_t21*_t5*_t6*_t7/(sigma_ss * sigma_ss * sigma_ss) + (0.3e1 / 0.320e3)*_hc1[4]*_t35*_t49*_t5*_t6*_t7 - 0.9e1 / 0.64e2*_t13/xc_powr(sigma_ss, 7, 2) - _t33*_t38));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t3, 0, _t39 + n_s*my_piecewise3(_t3, 0, (0.3e1 / 0.80e2)*_hc1[2]*_t24*_t35*_t5*_t6*_t7 + (0.1e1 / 0.80e2)*_hc1[3]*_t20*_t41*_t5*_t6*_t7 - 0.3e1 / 0.80e2*_t16*_t32 - _t40*_t50/xc_powr(n_s, 17, 3)));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t3, 0, 0.2e1*_t42 + n_s*my_piecewise3(_t3, 0, (0.1e1 / 0.4e1)*_t11*_t43 - 0.1e1 / 0.24e2*_t20*_t30 + (0.1e1 / 0.24e2)*_t22*_t29 + (0.1e1 / 0.15e2)*_t50/xc_powr(n_s, 20, 3)));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t3, 0, 0.3e1*_t44 + n_s*my_piecewise3(_t3, 0, -0.2e1 / 0.9e1*_t11*_t46 - 0.6e1 / 0.5e1*_t2*_t47 - 0.71e2 / 0.45e2*_t45 - 0.8e1 / 0.45e2*_t50*sigma_ss/xc_powr(n_s, 23, 3)));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t3, 0, 0.4e1*_t48 + n_s*my_piecewise3(_t3, 0, (0.26e2 / 0.15e2)*_t12*_t2*_t49 + (0.544e3 / 0.135e3)*_t19*_t37/xc_powr(n_s, 22, 3) + (0.988e3 / 0.135e3)*_t25*sigma_ss/xc_powi(n_s, 6) + (0.64e2 / 0.135e3)*_t34*_t50/xc_powr(n_s, 26, 3) - 0.14e2 / 0.135e3*_t36*_t9));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_k_lgap_ge_params *params = (const gga_k_lgap_ge_params *)(p->params);
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