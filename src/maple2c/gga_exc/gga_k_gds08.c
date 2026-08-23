/*
  Generated from python/gga_exc/gga_k_gds08.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_k_gds08
*/

#ifndef _GGA_K_GDS08_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_K_GDS08_KERNEL_BODY
#define _KMAX 0
#define _GGA_K_GDS08_HELPER_BODIES
#include "gga_k_gds08.c"
#undef _GGA_K_GDS08_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_K_GDS08_HELPER_BODIES
#include "gga_k_gds08.c"
#undef _GGA_K_GDS08_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_K_GDS08_HELPER_BODIES
#include "gga_k_gds08.c"
#undef _GGA_K_GDS08_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_K_GDS08_HELPER_BODIES
#include "gga_k_gds08.c"
#undef _GGA_K_GDS08_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_K_GDS08_HELPER_BODIES
#include "gga_k_gds08.c"
#undef _GGA_K_GDS08_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_k_gds08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_k_gds08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_k_gds08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_k_gds08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_k_gds08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_k_gds08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_k_gds08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_k_gds08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_k_gds08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_k_gds08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_K_GDS08_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(z_thr_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z + 0.1e1 <= p->zeta_threshold;
  const double _t2 = p->zeta_threshold - 0.1e1;
  const double _t3 = 0.1e1 - z <= p->zeta_threshold;
#if _KMAX >= 2
  const double _t4 = my_piecewise5(_t1, 0, _t3, 0, 0);
#endif

  const double f = my_piecewise5(_t1, _t2, _t3, -_t2, z);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise5(_t1, 0, _t3, 0, 0.1e1);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t4;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t4;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t4;
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(gds08_base_k, _KMAX)(const xc_func_type *p, double p_, double *out) {
  const gga_k_gds08_params *params = (const gga_k_gds08_params *)(p->params);

  const double _t1 = (0.5e1 / 0.72e2)*xc_powr(0.6e1, 1, 3)*params->lambda/(M_PI * M_CBRTPI);

  const double f = _t1*p_ + params->gamma;
  out[0] = f;
#if _KMAX >= 1
  const double df_dp_ = _t1;
  out[1] = df_dp_;
#endif
#if _KMAX >= 2
  const double d2f_dp_2 = 0;
  out[2] = d2f_dp_2;
#endif
#if _KMAX >= 3
  const double d3f_dp_3 = 0;
  out[3] = d3f_dp_3;
#endif
#if _KMAX >= 4
  const double d4f_dp_4 = 0;
  out[4] = d4f_dp_4;
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
  const gga_k_gds08_params *params = (const gga_k_gds08_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n5_3_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(gds08_base_k, _KMAX)(p, sigma_ss/xc_powr(n_s, 8, 3), _hc1);
  const double _t1 = -p->dens_threshold + n_s <= 0;
  const double _t2 = xc_powr(0.3e1, 2, 3);
  const double _t3 = (M_PI * M_CBRTPI);
  const double _t4 = _hc0[0] + 0.1e1;
  const double _t5 = _t2*_t3*_t4;
  const double _t6 = (0.3e1 / 0.20e2)*_t5;
  const double _t7 = my_piecewise3(_t1, 0, _hc1[0]*_t6*xc_powr(n_s, 2, 3));
#if _KMAX >= 1
  const double _t8 = my_piecewise3(_t1, 0, _hc1[1]*_t6/(n_s * n_s));
  const double _t9 = _hc1[0]*_t5;
  const double _t10 = _hc1[1]*_t5;
  const double _t11 = _t10/(n_s * n_s * n_s);
  const double _t12 = my_piecewise3(_t1, 0, -0.2e1 / 0.5e1*_t11*sigma_ss + (0.1e1 / 0.10e2)*_t9/xc_powr(n_s, 1, 3));
#endif
#if _KMAX >= 2
  const double _t13 = my_piecewise3(_t1, 0, -0.3e1 / 0.10e2*_t11);
  const double _t14 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t15 = my_piecewise3(_t1, 0, (0.14e2 / 0.15e2)*_hc1[1]*_t14*_t2*_t3*_t4*sigma_ss - 0.1e1 / 0.30e2*_t9/xc_powr(n_s, 4, 3));
#endif
#if _KMAX >= 3
  const double _t16 = my_piecewise3(_t1, 0, (0.9e1 / 0.10e2)*_t10*_t14);
  const double _t17 = _t10/xc_powi(n_s, 5);
  const double _t18 = my_piecewise3(_t1, 0, -0.164e3 / 0.45e2*_t17*sigma_ss + (0.2e1 / 0.45e2)*_t9/xc_powr(n_s, 7, 3));
#endif

  const double f = my_piecewise3(_t1, 0, _t7*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t1, 0, _t8*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t1, 0, _t12*n_s + _t7);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = 0;
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t1, 0, _t13*n_s + _t8);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t1, 0, 0.2e1*_t12 + _t15*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = 0;
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = 0;
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t1, 0, 0.2e1*_t13 + _t16*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t1, 0, 0.3e1*_t15 + _t18*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = 0;
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = 0;
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = 0;
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t1, 0, 0.3e1*_t16 + n_s*my_piecewise3(_t1, 0, -0.18e2 / 0.5e1*_t17));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t1, 0, 0.4e1*_t18 + n_s*my_piecewise3(_t1, 0, (0.2444e4 / 0.135e3)*_hc1[1]*_t2*_t3*_t4*sigma_ss/xc_powi(n_s, 6) - 0.14e2 / 0.135e3*_t9/xc_powr(n_s, 10, 3)));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_k_gds08_params *params = (const gga_k_gds08_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = (0.1e1 / 0.2e1)*na;
  const double _t2 = (0.1e1 / na);
  const double _t3 = -p->dens_threshold + (0.1e1 / 0.2e1)*na <= 0;
  const double _t4 = log(na);
  const double _t5 = (0.1e1 / 0.2e1)*params->B;
  const double _t6 = 0.2e1*my_piecewise3(_t3, 0, (0.1e1 / 0.2e1)*(_t4 * _t4)*params->C + _t4*_t5 + (0.1e1 / 0.2e1)*params->A);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, (0.1e1 / 0.4e1)*gaa, _hc0);
  const double zk = _t2*(0.2e1*_hc0[0] + _t6*na);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t7 = _t4*params->C;
  const double _t8 = my_piecewise3(_t3, 0, _t2*_t5 + _t2*_t7);
  const double _t9 = 0.2e1*na;
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, 0, _hc1);
  const double dF_dna = _hc0[2] + _t6 + _t8*_t9;
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc1[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t10 = (0.1e1 / (na * na));
  const double _t11 = my_piecewise3(_t3, 0, -_t10*_t4*params->C - _t10*_t5 + _t10*params->C);
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc0[5] + _t11*_t9 + 0.4e1*_t8;
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[4];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc1[3];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t12 = (0.1e1 / (na * na * na));
  const double _t13 = my_piecewise3(_t3, 0, 0.2e1*_t12*_t7 + _t12*params->B - 0.3e1*_t12*params->C);
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc0[9] + 0.6e1*_t11 + _t13*_t9;
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc0[8];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[7];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc1[6];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t14 = (0.1e1 / (na * na * na * na));
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc0[14] + 0.8e1*_t13 + _t9*my_piecewise3(_t3, 0, -0.6e1*_t14*_t7 - 0.3e1*_t14*params->B + 0.11e2*_t14*params->C);
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc0[13];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc0[12];
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[11];
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc1[10];
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

  const double _t1 = -nb;
  const double _t2 = _t1 + na;
  const double _t3 = na + nb;
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = _t2*_t4;
  const double _t6 = -p->dens_threshold + na <= 0;
  const double _t11 = -_t1 - p->dens_threshold <= 0;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, _t5, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, -_t5, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, _hc3);
  const double _t7 = (0.1e1 / 0.2e1)*_hc0[0] + 0.1e1 / 0.2e1;
  const double _t8 = _hc0[0] + 0.1e1;
  const double _t9 = log(_t3*_t8);
  const double _t10 = (_t9 * _t9)*params->C + _t9*params->B + params->A;
  const double _t12 = (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1 / 0.2e1;
  const double _t13 = _hc1[0] + 0.1e1;
  const double _t14 = log(_t13*_t3);
  const double _t15 = (_t14 * _t14)*params->C + _t14*params->B + params->A;
  const double _t16 = my_piecewise3(_t11, 0, _t12*_t15) + my_piecewise3(_t6, 0, _t10*_t7);
  const double zk = _t4*(_hc2[0] + _hc3[0] + _t16*_t3);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t17 = -_t4;
  const double _t18 = (0.1e1 / (_t3 * _t3));
  const double _t19 = _t18*_t2;
  const double _t20 = _t17 + _t19;
  const double _t21 = -_t20;
  const double _t24 = _t4*params->B;
  const double _t29 = _t4*params->C;
  const double _t30 = 0.2e1*_t29;
  const double _t43 = _t19 + _t4;
  const double _t48 = -_t43;
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, 0, _hc4);
  double _hc5[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, 0, _hc5);
  const double _t22 = _hc0[1]*_t21;
  const double _t23 = (0.1e1 / 0.2e1)*_t10;
  const double _t25 = (0.1e1 / _t8);
  const double _t26 = _t22*_t3 + _t8;
  const double _t27 = _t25*_t26;
  const double _t28 = _t27*_t9;
  const double _t31 = _t24*_t27 + _t28*_t30;
  const double _t32 = my_piecewise3(_t6, 0, _t22*_t23 + _t31*_t7);
  const double _t33 = _hc1[1]*_t20;
  const double _t34 = (0.1e1 / 0.2e1)*_t15;
  const double _t35 = _t13 + _t3*_t33;
  const double _t36 = (0.1e1 / _t13);
  const double _t37 = _t24*_t36;
  const double _t38 = _t14*_t30;
  const double _t39 = _t36*_t38;
  const double _t40 = _t35*_t37 + _t35*_t39;
  const double _t41 = my_piecewise3(_t11, 0, _t12*_t40 + _t33*_t34);
  const double _t42 = _t32 + _t41;
  const double _t44 = _hc1[1]*_t43;
  const double _t45 = _t13 + _t3*_t44;
  const double _t46 = _t37*_t45 + _t39*_t45;
  const double _t47 = my_piecewise3(_t11, 0, _t12*_t46 + _t34*_t44);
  const double _t49 = _hc0[1]*_t48;
  const double _t50 = _t3*_t49 + _t8;
  const double _t51 = _t24*_t25;
  const double _t52 = _t25*_t50;
  const double _t53 = _t30*_t9;
  const double _t54 = _t50*_t51 + _t52*_t53;
  const double _t55 = my_piecewise3(_t6, 0, _t23*_t49 + _t54*_t7);
  const double _t56 = _t47 + _t55;
  const double dF_dna = _hc2[2] + _t16 + _t3*_t42;
  const double dF_dnb = _hc3[2] + _t16 + _t3*_t56;
  const double dF_dgaa = _hc4[1];
  const double dF_dgbb = _hc5[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t57 = 0.2e1*_t18;
  const double _t58 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t59 = 0.2e1*_t58;
  const double _t60 = _t2*_t59;
  const double _t61 = -_t57 + _t60;
  const double _t63 = (_t21 * _t21);
  const double _t77 = _t18*params->B;
  const double _t78 = _t57*params->C;
  const double _t82 = -_t61;
  const double _t84 = (_t20 * _t20);
  const double _t110 = 0.2e1*_t19;
  const double _t134 = (_t43 * _t43);
  const double _t136 = _t57 + _t60;
  const double _t137 = -_t136;
  const double _t148 = (_t48 * _t48);
  const double _t62 = _hc0[1]*_t61;
  const double _t64 = _hc0[2]*_t63;
  const double _t65 = 0.2e1*_t22;
  const double _t66 = _t3*_t62;
  const double _t67 = _t3*_t64;
  const double _t68 = _t65 + _t66 + _t67;
  const double _t69 = (0.1e1 / (_t8 * _t8));
  const double _t70 = (_t26 * _t26);
  const double _t71 = -0.2e1*_t18*_t69*_t70*params->C;
  const double _t72 = _t24*_t69;
  const double _t73 = _t22*_t26;
  const double _t74 = _t26*_t69;
  const double _t75 = _t29*_t9;
  const double _t76 = _t74*_t75;
  const double _t79 = _t27*_t77 + _t28*_t78;
  const double _t80 = 0.2e1*_t25*_t4*_t68*_t9*params->C + _t25*_t4*_t68*params->B - _t65*_t76 - _t71 - _t72*_t73 - _t79;
  const double _t81 = my_piecewise3(_t6, 0, _t22*_t31 + _t23*_t62 + _t23*_t64 + _t7*_t80);
  const double _t83 = _hc1[1]*_t82;
  const double _t85 = _hc1[2]*_t84;
  const double _t86 = 0.2e1*_t33;
  const double _t87 = _t3*_t83;
  const double _t88 = _t3*_t85;
  const double _t89 = _t86 + _t87 + _t88;
  const double _t90 = (0.1e1 / (_t13 * _t13));
  const double _t91 = (_t35 * _t35);
  const double _t92 = _t24*_t90;
  const double _t93 = _t33*_t35;
  const double _t94 = _t35*_t90;
  const double _t95 = _t14*_t29;
  const double _t96 = _t94*_t95;
  const double _t97 = _t36*_t77;
  const double _t98 = _t14*_t78;
  const double _t99 = _t36*_t98;
  const double _t100 = _t35*_t97 + _t35*_t99;
  const double _t101 = -_t100 + 0.2e1*_t14*_t36*_t4*_t89*params->C + 0.2e1*_t18*_t90*_t91*params->C + _t36*_t4*_t89*params->B - _t86*_t96 - _t92*_t93;
  const double _t102 = my_piecewise3(_t11, 0, _t101*_t12 + _t33*_t40 + _t34*_t83 + _t34*_t85);
  const double _t103 = _t102 + _t81;
  const double _t104 = _hc1[1]*_t15;
  const double _t105 = _t104*_t58;
  const double _t106 = _hc1[2]*_t20;
  const double _t107 = _t106*_t43;
  const double _t108 = (0.1e1 / 0.2e1)*_t46;
  const double _t109 = (0.1e1 / 0.2e1)*_t44;
  const double _t111 = _hc1[2]*_t3;
  const double _t112 = _t111*_t20;
  const double _t113 = _t112*_t43;
  const double _t114 = -_hc1[1]*_t110 + _t113 + _t33 + _t44;
  const double _t115 = _t44*_t92;
  const double _t116 = 0.2e1*_t44;
  const double _t117 = -_t100 + 0.2e1*_t114*_t14*_t36*_t4*params->C + _t114*_t36*_t4*params->B - _t115*_t35 - _t116*_t96 + 0.2e1*_t18*_t35*_t45*_t90*params->C;
  const double _t118 = my_piecewise3(_t11, 0, -_t105*_t2 + _t107*_t34 + _t108*_t33 + _t109*_t40 + _t117*_t12);
  const double _t119 = _hc0[1]*_t10;
  const double _t120 = _t119*_t58;
  const double _t121 = _hc0[2]*_t21;
  const double _t122 = _t121*_t48;
  const double _t123 = (0.1e1 / 0.2e1)*_t49;
  const double _t124 = (0.1e1 / 0.2e1)*_t54;
  const double _t125 = _hc0[1]*_t110;
  const double _t126 = _hc0[2]*_t3;
  const double _t127 = _t126*_t21;
  const double _t128 = _t127*_t48;
  const double _t129 = _t125 + _t128 + _t22 + _t49;
  const double _t130 = _t49*_t72;
  const double _t131 = 0.2e1*_t49;
  const double _t132 = 0.2e1*_t129*_t25*_t4*_t9*params->C + _t129*_t25*_t4*params->B - _t130*_t26 - _t131*_t76 + 0.2e1*_t18*_t26*_t50*_t69*params->C - _t79;
  const double _t133 = my_piecewise3(_t6, 0, _t120*_t2 + _t122*_t23 + _t123*_t31 + _t124*_t22 + _t132*_t7);
  const double _t135 = _hc1[2]*_t134;
  const double _t138 = _hc1[1]*_t137;
  const double _t139 = (_t45 * _t45);
  const double _t140 = _t45*_t90;
  const double _t141 = _t116*_t95;
  const double _t142 = _t135*_t3;
  const double _t143 = _t138*_t3;
  const double _t144 = _t116 + _t142 + _t143;
  const double _t145 = -_t115*_t45 + 0.2e1*_t139*_t18*_t90*params->C + 0.2e1*_t14*_t144*_t36*_t4*params->C - _t140*_t141 + _t144*_t36*_t4*params->B - _t45*_t97 - _t45*_t99;
  const double _t146 = my_piecewise3(_t11, 0, _t12*_t145 + _t135*_t34 + _t138*_t34 + _t44*_t46);
  const double _t147 = _hc0[1]*_t136;
  const double _t149 = _hc0[2]*_t148;
  const double _t150 = _t25*_t77;
  const double _t151 = (_t50 * _t50);
  const double _t152 = -0.2e1*_t151*_t18*_t69*params->C;
  const double _t153 = _t78*_t9;
  const double _t154 = _t50*_t69;
  const double _t155 = _t131*_t75;
  const double _t156 = _t147*_t3;
  const double _t157 = _t149*_t3;
  const double _t158 = _t131 + _t156 + _t157;
  const double _t159 = -_t130*_t50 - _t150*_t50 - _t152 - _t153*_t52 - _t154*_t155 + 0.2e1*_t158*_t25*_t4*_t9*params->C + _t158*_t25*_t4*params->B;
  const double _t160 = my_piecewise3(_t6, 0, _t147*_t23 + _t149*_t23 + _t159*_t7 + _t49*_t54);
  const double _t161 = _t146 + _t160;
  const double d2F_dna2 = _hc2[5] + _t103*_t3 + 0.2e1*_t32 + 0.2e1*_t41;
  const double d2F_dna_dnb = _t3*(_t118 + _t133) + _t42 + _t56;
  const double d2F_dnb2 = _hc3[5] + _t161*_t3 + 0.2e1*_t47 + 0.2e1*_t55;
  const double d2F_dna_dgaa = _hc2[4];
  const double d2F_dnb_dgbb = _hc3[4];
  const double d2F_dgaa2 = _hc4[3];
  const double d2F_dgbb2 = _hc5[3];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
#endif
#if _KMAX >= 3
  const double _t162 = 0.6e1*_t58;
  const double _t163 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t164 = 0.6e1*_t163;
  const double _t165 = _t164*_t2;
  const double _t166 = -_t162 + _t165;
  const double _t167 = -_t166;
  const double _t169 = (_t21 * _t21 * _t21);
  const double _t172 = 0.4e1*_t18;
  const double _t173 = 0.4e1*_t58;
  const double _t174 = _t173*_t2;
  const double _t175 = -_t172 + _t174;
  const double _t177 = -_t18*_t2;
  const double _t178 = _t177 + _t4;
  const double _t193 = _t162*params->C;
  const double _t195 = _t57*params->B;
  const double _t197 = _t172*params->C;
  const double _t204 = 0.6e1*_t18;
  const double _t205 = _t204*params->C;
  const double _t210 = 0.2e1*_t24;
  const double _t222 = _t59*params->B;
  const double _t223 = _t173*params->C;
  const double _t228 = (_t20 * _t20 * _t20);
  const double _t230 = -_t175;
  const double _t272 = _t165 - 0.2e1*_t58;
  const double _t277 = _t43*_t84;
  const double _t283 = 0.4e1*_t19;
  const double _t291 = _t59*params->C;
  const double _t297 = _t163*_t2;
  const double _t298 = 0.2e1*params->B;
  const double _t299 = _t297*_t298;
  const double _t304 = _t20*_t43;
  const double _t305 = 0.4e1*_t297;
  const double _t311 = -_t272;
  const double _t314 = _t17 + _t177;
  const double _t315 = _t314*_t63;
  const double _t345 = 0.3e1*_t297;
  const double _t347 = _t134*_t20;
  const double _t369 = _t148*_t178;
  const double _t391 = (_t43 * _t43 * _t43);
  const double _t393 = _t162 + _t165;
  const double _t395 = _t172 + _t174;
  const double _t396 = -_t395;
  const double _t421 = -_t393;
  const double _t423 = (_t48 * _t48 * _t48);
  const double _t168 = _hc0[1]*_t167;
  const double _t170 = _hc0[3]*_t169;
  const double _t171 = _t121*_t61;
  const double _t176 = _t121*_t175;
  const double _t179 = _hc0[1]*_t178;
  const double _t180 = _t179*_t3 + _t8;
  const double _t181 = _t25*_t53;
  const double _t182 = _t180*_t181 + _t180*_t51;
  const double _t183 = (0.3e1 / 0.2e1)*_t64;
  const double _t184 = (0.3e1 / 0.2e1)*_t62;
  const double _t185 = (0.3e1 / 0.2e1)*_t22;
  const double _t186 = 0.3e1*_t62;
  const double _t187 = 0.3e1*_t64;
  const double _t188 = _t168*_t3;
  const double _t189 = _t170*_t3;
  const double _t190 = _t127*_t61;
  const double _t191 = _t127*_t175;
  const double _t192 = _t186 + _t187 + _t188 + _t189 + _t190 + _t191;
  const double _t194 = _t69*_t70;
  const double _t196 = _t25*_t68;
  const double _t198 = _t69*_t78;
  const double _t199 = _t198*_t26;
  const double _t200 = 0.4e1*_t22;
  const double _t201 = _t200 + 0.2e1*_t66 + 0.2e1*_t67;
  const double _t202 = _t26*_t72;
  const double _t203 = _t180*_t72;
  const double _t206 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t207 = _t206*_t70;
  const double _t208 = _t68*_t72;
  const double _t209 = _t69*_t73;
  const double _t211 = ((_hc0[1]) * (_hc0[1]));
  const double _t212 = _t180*_t206;
  const double _t213 = _t211*_t212*_t63;
  const double _t214 = _t68*_t69;
  const double _t215 = _t214*_t75;
  const double _t216 = 0.2e1*_t62;
  const double _t217 = 0.2e1*_t64;
  const double _t218 = _t69*_t75;
  const double _t219 = _t180*_t218;
  const double _t220 = _t197*_t9;
  const double _t221 = 0.4e1*_t75;
  const double _t224 = _t222*_t27 + _t223*_t28;
  const double _t225 = _t181*_t192 + _t192*_t51 - _t193*_t194 - _t195*_t196 + _t195*_t209 - _t196*_t197*_t9 + _t199*_t201 + _t199*_t68 - _t200*_t215 - _t202*_t62 - _t203*_t64 - _t205*_t207*_t22 - _t208*_t65 + _t209*_t220 + _t210*_t213 + _t213*_t221 - _t216*_t76 - _t217*_t219 + _t224;
  const double _t226 = my_piecewise3(_t6, 0, _t168*_t23 + _t170*_t23 + _t171*_t23 + _t176*_t23 + _t182*_t183 + _t184*_t31 + _t185*_t80 + _t225*_t7);
  const double _t227 = _hc1[1]*_t166;
  const double _t229 = _hc1[3]*_t228;
  const double _t231 = _t106*_t230;
  const double _t232 = _t106*_t82;
  const double _t233 = (0.3e1 / 0.2e1)*_t40;
  const double _t234 = (0.3e1 / 0.2e1)*_t33;
  const double _t235 = 0.3e1*_t83;
  const double _t236 = 0.3e1*_t85;
  const double _t237 = _t227*_t3;
  const double _t238 = _t229*_t3;
  const double _t239 = _t112*_t230;
  const double _t240 = _t112*_t82;
  const double _t241 = _t235 + _t236 + _t237 + _t238 + _t239 + _t240;
  const double _t242 = _t90*_t91;
  const double _t243 = _t195*_t36;
  const double _t244 = _t36*_t89;
  const double _t245 = _t14*_t197;
  const double _t246 = _t78*_t90;
  const double _t247 = _t246*_t35;
  const double _t248 = 0.4e1*_t33;
  const double _t249 = _t248 + 0.2e1*_t87 + 0.2e1*_t88;
  const double _t250 = _t35*_t92;
  const double _t251 = (0.1e1 / (_t13 * _t13 * _t13));
  const double _t252 = _t251*_t91;
  const double _t253 = _t89*_t92;
  const double _t254 = _t90*_t93;
  const double _t255 = ((_hc1[1]) * (_hc1[1]));
  const double _t256 = _t255*_t84;
  const double _t257 = _t251*_t35;
  const double _t258 = _t210*_t257;
  const double _t259 = _t89*_t90;
  const double _t260 = _t259*_t95;
  const double _t261 = 0.2e1*_t83;
  const double _t262 = 0.2e1*_t85;
  const double _t263 = _t256*_t257;
  const double _t264 = 0.4e1*_t95;
  const double _t265 = _t222*_t36;
  const double _t266 = _t14*_t36;
  const double _t267 = _t223*_t35;
  const double _t268 = _t265*_t35 + _t266*_t267;
  const double _t269 = -_t193*_t242 + _t195*_t254 - _t205*_t252*_t33 + _t241*_t37 + _t241*_t39 - _t243*_t89 - _t244*_t245 + _t245*_t254 + _t247*_t249 + _t247*_t89 - _t248*_t260 - _t250*_t83 - _t250*_t85 - _t253*_t86 + _t256*_t258 - _t261*_t96 - _t262*_t96 + _t263*_t264 + _t268;
  const double _t270 = my_piecewise3(_t11, 0, _t101*_t234 + _t12*_t269 + _t227*_t34 + _t229*_t34 + _t231*_t34 + _t232*_t34 + _t233*_t83 + _t233*_t85);
  const double _t271 = _t226 + _t270;
  const double _t273 = (0.1e1 / 0.2e1)*_t104;
  const double _t274 = _t106*_t15;
  const double _t275 = _hc1[2]*_t43;
  const double _t276 = _t275*_t82;
  const double _t278 = _hc1[3]*_t277;
  const double _t279 = _hc1[1]*_t60;
  const double _t280 = _hc1[1]*_t174;
  const double _t281 = _hc1[1]*_t3;
  const double _t282 = _t272*_t281;
  const double _t284 = 0.2e1*_t107;
  const double _t285 = _t111*_t43;
  const double _t286 = _t285*_t82;
  const double _t287 = _hc1[3]*_t3;
  const double _t288 = _t277*_t287;
  const double _t289 = -_t106*_t283 - _t280 + _t282 + _t284 + _t286 + _t288 + _t83 + _t85;
  const double _t290 = _t114*_t36;
  const double _t292 = _t45*_t94;
  const double _t293 = _t246*_t45;
  const double _t294 = -_hc1[1]*_t283 + 0.2e1*_t113 + _t116 + _t86;
  const double _t295 = _t114*_t92;
  const double _t296 = _hc1[1]*_t94;
  const double _t300 = _t251*_t93;
  const double _t301 = _t45*_t78;
  const double _t302 = _t114*_t90*_t95;
  const double _t303 = _t14*_t44;
  const double _t306 = _t14*_t296;
  const double _t307 = _t306*params->C;
  const double _t308 = _t255*_t257;
  const double _t309 = -_t107*_t250 - _t114*_t97 - _t115*_t89 + _t14*_t246*_t93 - _t141*_t259 - _t197*_t252*_t44 - _t223*_t242 - _t244*_t98 + _t247*_t294 + _t247*_t303 + _t254*_t77 + _t255*_t258*_t304 + _t264*_t304*_t308 + _t268 - _t284*_t96 + _t289*_t37 + _t289*_t39 - _t290*_t98 - _t291*_t292 + _t293*_t89 - _t295*_t33 + _t296*_t299 - _t300*_t301 - _t302*_t86 + _t305*_t307 + _t44*_t77*_t94 - _t89*_t97;
  const double _t310 = my_piecewise3(_t11, 0, _t101*_t109 + _t107*_t40 + _t108*_t83 + _t108*_t85 + _t117*_t33 + _t12*_t309 + _t272*_t273 - _t274*_t60 + _t276*_t34 + _t278*_t34 - _t279*_t40);
  const double _t312 = (0.1e1 / 0.2e1)*_t119;
  const double _t313 = _t10*_t121;
  const double _t316 = _hc0[3]*_t315;
  const double _t317 = _hc0[2]*_t48;
  const double _t318 = _t317*_t61;
  const double _t319 = _hc0[1]*_t60;
  const double _t320 = _hc0[1]*_t314;
  const double _t321 = _t3*_t320 + _t8;
  const double _t322 = _t181*_t321 + _t321*_t51;
  const double _t323 = (0.1e1 / 0.2e1)*_t322;
  const double _t324 = _hc0[1]*_t74;
  const double _t325 = _t50*_t74;
  const double _t326 = _t206*_t50;
  const double _t327 = _t326*_t78;
  const double _t328 = 0.2e1*_t122;
  const double _t329 = _t129*_t25;
  const double _t330 = _t129*_t72;
  const double _t331 = _t129*_t69;
  const double _t332 = _t331*_t75;
  const double _t333 = _hc0[1]*_t283 + 0.2e1*_t128 + _t131 + _t65;
  const double _t334 = _hc0[1]*_t174;
  const double _t335 = _hc0[1]*_t3;
  const double _t336 = _t311*_t335;
  const double _t337 = _hc0[3]*_t3;
  const double _t338 = _t315*_t337;
  const double _t339 = _t126*_t48;
  const double _t340 = _t339*_t61;
  const double _t341 = _t121*_t283 + _t328 + _t334 + _t336 + _t338 + _t340 + _t62 + _t64;
  const double _t342 = 0.2e1*_hc0[1]*_t18*_t21*_t26*_t69*_t9*params->C + _hc0[1]*_t18*_t21*_t26*_t69*params->B + 0.2e1*_hc0[1]*_t18*_t26*_t48*_t69*_t9*params->C + _hc0[1]*_t18*_t26*_t48*_t69*params->B - _t122*_t202 - _t129*_t150 - _t130*_t68 - _t150*_t68 - _t153*_t196 - _t153*_t329 - _t155*_t214 + 0.2e1*_t18*_t26*_t333*_t69*params->C + 0.2e1*_t18*_t50*_t68*_t69*params->C - _t194*_t223 - _t197*_t207*_t49 + 0.4e1*_t206*_t21*_t211*_t26*_t4*_t48*_t9*params->C + 0.2e1*_t206*_t21*_t211*_t26*_t4*_t48*params->B - _t22*_t330 + 0.4e1*_t25*_t26*_t58*_t9*params->C + 0.2e1*_t25*_t26*_t58*params->B + 0.2e1*_t25*_t341*_t4*_t9*params->C + _t25*_t341*_t4*params->B - _t291*_t325 - _t299*_t324 - _t305*_t324*_t9*params->C - _t327*_t73 - _t328*_t76 - _t332*_t65;
  const double _t343 = my_piecewise3(_t6, 0, _t122*_t31 + _t123*_t80 + _t124*_t62 + _t132*_t22 + _t23*_t316 + _t23*_t318 + _t31*_t319 + _t311*_t312 + _t313*_t60 + _t323*_t64 + _t342*_t7);
  const double _t344 = 0.2e1*_t118 + 0.2e1*_t133;
  const double _t346 = _t15*_t275;
  const double _t348 = _hc1[3]*_t347;
  const double _t349 = _t106*_t137;
  const double _t350 = (0.1e1 / 0.2e1)*_t40;
  const double _t351 = (0.1e1 / 0.2e1)*_t145;
  const double _t352 = _t287*_t347;
  const double _t353 = _t112*_t137;
  const double _t354 = _hc1[1]*_t57 + _t135 + _t138 - _t275*_t283 + _t279 + _t284 + _t352 + _t353;
  const double _t355 = _t114*_t140;
  const double _t356 = _t195*_t44;
  const double _t357 = _t134*_t255;
  const double _t358 = _t205*_t44;
  const double _t359 = _t358*_t45;
  const double _t360 = 0.4e1*_t44;
  const double _t361 = 0.2e1*_t138;
  const double _t362 = 0.2e1*_t135;
  const double _t363 = _t44*_t94;
  const double _t364 = _t257*_t357;
  const double _t365 = -_t114*_t243 - _t116*_t295 - _t135*_t250 - _t138*_t250 + _t144*_t247 - _t193*_t292 + _t197*_t355 - _t245*_t290 + _t245*_t363 - _t257*_t359 + _t258*_t357 + _t264*_t364 + _t268 - _t302*_t360 + _t354*_t37 + _t354*_t39 + _t356*_t94 - _t361*_t96 - _t362*_t96;
  const double _t366 = my_piecewise3(_t11, 0, _t104*_t345 + _t105 + _t107*_t46 + _t117*_t44 + _t12*_t365 + _t135*_t350 + _t138*_t350 - _t279*_t46 + _t33*_t351 + _t34*_t348 + _t34*_t349 - _t346*_t60);
  const double _t367 = _t10*_t317;
  const double _t368 = _t121*_t136;
  const double _t370 = _hc0[3]*_t369;
  const double _t371 = (0.1e1 / 0.2e1)*_t147;
  const double _t372 = (0.1e1 / 0.2e1)*_t149;
  const double _t373 = (0.1e1 / 0.2e1)*_t159;
  const double _t374 = _t127*_t136;
  const double _t375 = _t337*_t369;
  const double _t376 = -_hc0[1]*_t57 + _t147 + _t149 + _t283*_t317 - _t319 + _t328 + _t374 + _t375;
  const double _t377 = _t195*_t25;
  const double _t378 = _t129*_t154;
  const double _t379 = _t195*_t49;
  const double _t380 = _t148*_t211;
  const double _t381 = _t210*_t380;
  const double _t382 = _t26*_t326;
  const double _t383 = _t205*_t49;
  const double _t384 = 0.4e1*_t49;
  const double _t385 = 0.2e1*_t147;
  const double _t386 = 0.2e1*_t149;
  const double _t387 = _t49*_t74;
  const double _t388 = _t212*_t380;
  const double _t389 = -_t129*_t377 - _t131*_t330 - _t147*_t202 - _t149*_t203 + _t158*_t199 + _t181*_t376 - _t193*_t325 + _t197*_t378 + _t212*_t381 - _t219*_t386 - _t220*_t329 + _t220*_t387 + _t221*_t388 + _t224 - _t332*_t384 + _t376*_t51 + _t379*_t74 - _t382*_t383 - _t385*_t76;
  const double _t390 = my_piecewise3(_t6, 0, -_t119*_t345 - _t120 + _t122*_t54 + _t132*_t49 + _t182*_t372 + _t22*_t373 + _t23*_t368 + _t23*_t370 + _t31*_t371 + _t319*_t54 + _t367*_t60 + _t389*_t7);
  const double _t392 = _hc1[3]*_t391;
  const double _t394 = _hc1[1]*_t393;
  const double _t397 = _t275*_t396;
  const double _t398 = _t137*_t275;
  const double _t399 = (0.3e1 / 0.2e1)*_t46;
  const double _t400 = (0.3e1 / 0.2e1)*_t44;
  const double _t401 = _t266*_t45;
  const double _t402 = _t139*_t251;
  const double _t403 = _t45*_t92;
  const double _t404 = _t357*_t45;
  const double _t405 = _t140*_t44;
  const double _t406 = _t140*_t95;
  const double _t407 = _t251*_t404;
  const double _t408 = _t116*_t92;
  const double _t409 = _t144*_t90;
  const double _t410 = _t360*_t95;
  const double _t411 = 0.2e1*_t142 + 0.2e1*_t143 + _t360;
  const double _t412 = 0.3e1*_t135;
  const double _t413 = 0.3e1*_t138;
  const double _t414 = _t3*_t392;
  const double _t415 = _t3*_t394;
  const double _t416 = _t285*_t396;
  const double _t417 = _t137*_t285;
  const double _t418 = _t412 + _t413 + _t414 + _t415 + _t416 + _t417;
  const double _t419 = -_t135*_t403 - _t138*_t403 - _t139*_t193*_t90 + _t140*_t356 - _t144*_t243 - _t144*_t245*_t36 + _t144*_t293 - _t144*_t408 + _t210*_t251*_t404 + _t223*_t401 + _t245*_t405 + _t264*_t407 + _t265*_t45 + _t293*_t411 - _t358*_t402 - _t361*_t406 - _t362*_t406 + _t37*_t418 + _t39*_t418 - _t409*_t410;
  const double _t420 = my_piecewise3(_t11, 0, _t12*_t419 + _t135*_t399 + _t138*_t399 + _t145*_t400 + _t34*_t392 + _t34*_t394 + _t34*_t397 + _t34*_t398);
  const double _t422 = _hc0[1]*_t421;
  const double _t424 = _hc0[3]*_t423;
  const double _t425 = _t136*_t317;
  const double _t426 = _t317*_t395;
  const double _t427 = (0.3e1 / 0.2e1)*_t147;
  const double _t428 = (0.3e1 / 0.2e1)*_t149;
  const double _t429 = (0.3e1 / 0.2e1)*_t49;
  const double _t430 = _t223*_t9;
  const double _t431 = _t147*_t72;
  const double _t432 = _t149*_t72;
  const double _t433 = _t151*_t206;
  const double _t434 = _t154*_t49;
  const double _t435 = _t218*_t386;
  const double _t436 = _t206*_t321*_t380;
  const double _t437 = _t131*_t72;
  const double _t438 = _t198*_t50;
  const double _t439 = _t158*_t69*_t75;
  const double _t440 = 0.2e1*_t156 + 0.2e1*_t157 + _t384;
  const double _t441 = 0.3e1*_t147;
  const double _t442 = 0.3e1*_t149;
  const double _t443 = _t3*_t422;
  const double _t444 = _t3*_t424;
  const double _t445 = _t136*_t339;
  const double _t446 = _t339*_t395;
  const double _t447 = _t441 + _t442 + _t443 + _t444 + _t445 + _t446;
  const double _t448 = -_t151*_t193*_t69 + _t154*_t379 - _t154*_t385*_t75 - _t158*_t220*_t25 - _t158*_t377 - _t158*_t437 + _t158*_t438 + _t181*_t447 - _t205*_t433*_t49 + _t206*_t321*_t381 + _t220*_t434 + _t221*_t436 + _t222*_t25*_t50 - _t321*_t432 - _t321*_t435 - _t384*_t439 + _t430*_t52 - _t431*_t50 + _t438*_t440 + _t447*_t51;
  const double _t449 = my_piecewise3(_t6, 0, _t159*_t429 + _t23*_t422 + _t23*_t424 + _t23*_t425 + _t23*_t426 + _t322*_t428 + _t427*_t54 + _t448*_t7);
  const double _t450 = _t420 + _t449;
  const double d3F_dna3 = _hc2[9] + 0.3e1*_t102 + _t271*_t3 + 0.3e1*_t81;
  const double d3F_dna2_dnb = _t103 + _t3*(_t310 + _t343) + _t344;
  const double d3F_dna_dnb2 = _t161 + _t3*(_t366 + _t390) + _t344;
  const double d3F_dnb3 = _hc3[9] + 0.3e1*_t146 + 0.3e1*_t160 + _t3*_t450;
  const double d3F_dna2_dgaa = _hc2[8];
  const double d3F_dnb2_dgbb = _hc3[8];
  const double d3F_dna_dgaa2 = _hc2[7];
  const double d3F_dnb_dgbb2 = _hc3[7];
  const double d3F_dgaa3 = _hc4[6];
  const double d3F_dgbb3 = _hc5[6];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
#endif
#if _KMAX >= 4
  const double _t451 = 0.24e2*_t163;
  const double _t452 = xc_powi(_t3, -5);
  const double _t453 = _t2*_t452;
  const double _t454 = 0.24e2*_t453;
  const double _t455 = -_t451 + _t454;
  const double _t456 = (_t21 * _t21 * _t21 * _t21);
  const double _t458 = (_t61 * _t61);
  const double _t460 = 0.12e2*_t58;
  const double _t461 = 0.12e2*_t163;
  const double _t462 = _t2*_t461;
  const double _t463 = -_t460 + _t462;
  const double _t464 = -_t463;
  const double _t467 = 0.6e1*na - 0.6e1*nb;
  const double _t468 = -_t204 + _t467*_t58;
  const double _t471 = 0.4e1*na - 0.4e1*nb;
  const double _t472 = -_t172 + _t471*_t58;
  const double _t473 = 0.2e1*na - 0.2e1*nb;
  const double _t474 = _t473*_t58 - _t57;
  const double _t491 = _t58*params->C;
  const double _t492 = 0.8e1*_t491;
  const double _t495 = 0.10e2*_t491;
  const double _t498 = _t162*params->B;
  const double _t499 = _t204*params->B;
  const double _t500 = 0.6e1*_t24;
  const double _t503 = _t18*params->C;
  const double _t504 = 0.8e1*_t503;
  const double _t509 = 0.10e2*_t503;
  const double _t510 = _t460*params->C;
  const double _t512 = 0.12e2*_t503;
  const double _t516 = _t164*params->B;
  const double _t517 = _t461*params->C;
  const double _t519 = -_t455;
  const double _t520 = (_t20 * _t20 * _t20 * _t20);
  const double _t522 = (_t82 * _t82);
  const double _t526 = _t162*_t2;
  const double _t527 = _t204 - _t526;
  const double _t555 = _t454 - _t461;
  const double _t556 = _t2*_t58;
  const double _t560 = _t462 - 0.4e1*_t58;
  const double _t561 = -_t560;
  const double _t562 = _t169*_t314;
  const double _t564 = _t21*_t48;
  const double _t576 = _t2*_t460;
  const double _t578 = 0.6e1*_t19;
  const double _t581 = 0.8e1*_t2;
  const double _t582 = 0.8e1*_t19;
  const double _t588 = 0.4e1*params->B;
  const double _t589 = _t297*_t588;
  const double _t590 = _t173*params->B;
  const double _t591 = 0.12e2*_t453;
  const double _t602 = _t163*params->C;
  const double _t610 = -_t555;
  const double _t615 = _t228*_t43;
  const double _t637 = 0.8e1*_t453;
  const double _t647 = (_t2 * _t2);
  const double _t649 = 0.4e1/xc_powi(_t3, 6);
  const double _t652 = _t134*_t84;
  const double _t657 = 0.8e1*_t452;
  const double _t658 = _t58*_t581;
  const double _t667 = _t473*_t58 + _t57;
  const double _t668 = _t148*_t63;
  const double _t686 = 0.3e1*_t58;
  const double _t687 = 0.9e1*_t297;
  const double _t688 = _t20*_t391;
  const double _t691 = 0.18e2*_t491;
  const double _t692 = _t391*_t500;
  const double _t697 = 0.18e2*_t503;
  const double _t699 = _t178*_t423;
  const double _t704 = _t423*_t500;
  const double _t710 = (_t43 * _t43 * _t43 * _t43);
  const double _t711 = _t451 + _t454;
  const double _t712 = -_t711;
  const double _t713 = (_t137 * _t137);
  const double _t714 = _t460 + _t462;
  const double _t715 = -_t204 - _t526;
  const double _t716 = _t137*_t396;
  const double _t725 = (_t136 * _t136);
  const double _t726 = (_t48 * _t48 * _t48 * _t48);
  const double _t727 = -_t714;
  const double _t728 = _t136*_t395;
  const double _t729 = _t172 + _t471*_t58;
  const double _t730 = _t204 + _t467*_t58;
  const double _t457 = _hc0[4]*_t23;
  const double _t459 = _hc0[2]*_t23;
  const double _t465 = _t121*_t23;
  const double _t466 = _t459*_t61;
  const double _t469 = _hc0[3]*_t63;
  const double _t470 = _t23*_t469;
  const double _t475 = 0.2e1*_t170;
  const double _t476 = 0.2e1*_t31;
  const double _t477 = 0.2e1*_t179;
  const double _t478 = _t335*_t474 + _t477 + _t67;
  const double _t479 = _t153*_t25;
  const double _t480 = _t150*_t180 + _t180*_t479;
  const double _t481 = -_t179*_t203 - _t219*_t477 + 0.2e1*_t25*_t4*_t478*_t9*params->C + _t25*_t4*_t478*params->B - _t480 - _t71;
  const double _t482 = _hc0[4]*_t3;
  const double _t483 = _t126*_t61;
  const double _t484 = _t337*_t63;
  const double _t485 = _t126*_t458 + 0.2e1*_t127*_t167 + _t127*_t464 + 0.4e1*_t168 + 0.4e1*_t170 + 0.4e1*_t171 + _t175*_t483 + 0.4e1*_t176 + _t335*_t455 + _t456*_t482 + _t468*_t484 + _t472*_t484 + _t474*_t484;
  const double _t486 = _t150*_t192;
  const double _t487 = 0.6e1*_t62;
  const double _t488 = 0.6e1*_t64;
  const double _t489 = _t192*_t25;
  const double _t490 = _t205*_t9;
  const double _t493 = _t68*_t74;
  const double _t494 = _t201*_t74;
  const double _t496 = (0.1e1 / (_t8 * _t8 * _t8 * _t8));
  const double _t497 = _t22*_t72;
  const double _t501 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t496;
  const double _t502 = _t180*_t501;
  const double _t505 = _t207*_t504;
  const double _t506 = _t53*_t74;
  const double _t507 = 0.6e1*_t218;
  const double _t508 = _t206*_t73;
  const double _t511 = _t510*_t9;
  const double _t513 = _t512*_t9;
  const double _t514 = 0.12e2*_t75;
  const double _t515 = _t502*_t514;
  const double _t518 = _t27*_t516 + _t28*_t517;
  const double _t521 = _hc1[4]*_t34;
  const double _t523 = _hc1[2]*_t34;
  const double _t524 = _t106*_t34;
  const double _t525 = _t523*_t82;
  const double _t528 = _hc1[3]*_t84;
  const double _t529 = _t34*_t528;
  const double _t530 = 0.2e1*_t40;
  const double _t531 = _hc1[4]*_t3;
  const double _t532 = _t111*_t82;
  const double _t533 = _t287*_t84;
  const double _t534 = _t111*_t522 + 0.2e1*_t112*_t166 + _t112*_t463 + 0.4e1*_t227 + 0.4e1*_t229 + _t230*_t532 + _t230*_t533 + 0.4e1*_t231 + 0.4e1*_t232 + _t281*_t519 + _t520*_t531 + _t527*_t533 + _t533*_t82;
  const double _t535 = _t241*_t97;
  const double _t536 = 0.6e1*_t83;
  const double _t537 = 0.6e1*_t85;
  const double _t538 = _t205*_t266;
  const double _t539 = _t492*_t94;
  const double _t540 = _t495*_t94;
  const double _t541 = (0.1e1 / (_t13 * _t13 * _t13 * _t13));
  const double _t542 = _t33*_t92;
  const double _t543 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t544 = _t35*_t541*_t543;
  const double _t545 = _t252*_t504;
  const double _t546 = _t38*_t94;
  const double _t547 = _t90*_t95;
  const double _t548 = 0.6e1*_t547;
  const double _t549 = _t14*_t510;
  const double _t550 = _t14*_t512;
  const double _t551 = 0.12e2*_t95;
  const double _t552 = _t544*_t551;
  const double _t553 = _t36*_t516;
  const double _t554 = _t266*_t35*_t517 + _t35*_t553;
  const double _t557 = _t10*_t556;
  const double _t558 = _hc0[2]*_t557;
  const double _t559 = 0.3e1*_t557;
  const double _t563 = _t23*_t317;
  const double _t565 = _hc0[3]*_t564;
  const double _t566 = _t23*_t565;
  const double _t567 = _hc0[1]*_t311;
  const double _t568 = (0.3e1 / 0.2e1)*_t31;
  const double _t569 = _hc0[1]*_t58;
  const double _t570 = 0.3e1*_t569;
  const double _t571 = _t2*_t570;
  const double _t572 = (0.3e1 / 0.2e1)*_t122;
  const double _t573 = _t125 + _t126*_t178*_t314 + _t179 + _t320;
  const double _t574 = 0.2e1*_t320;
  const double _t575 = 0.2e1*_t18*_t180*_t321*_t69*params->C - _t203*_t320 - _t219*_t574 + 0.2e1*_t25*_t4*_t573*_t9*params->C + _t25*_t4*_t573*params->B - _t480;
  const double _t577 = _hc0[2]*_t110;
  const double _t579 = _t337*_t564;
  const double _t580 = _t121*_t576 + _t127*_t311 + _t127*_t561 + _t167*_t339 + _t168 + _t170 + _t171 + _t175*_t577 + _t175*_t579 + _t176 + 0.3e1*_t316 + 0.3e1*_t318 + _t335*_t555 + _t469*_t578 + _t482*_t562 + 0.3e1*_t567 + _t577*_t61 + _t579*_t61;
  const double _t583 = 0.4e1*_t122;
  const double _t584 = _t154*_t68;
  const double _t585 = _t333*_t74;
  const double _t586 = _t573*_t72;
  const double _t587 = _hc0[1]*_t214;
  const double _t592 = 0.2e1*_t567;
  const double _t593 = _t180*_t206*_t321;
  const double _t594 = _t218*_t573;
  const double _t595 = _t197*_t68;
  const double _t596 = _t22*_t326;
  const double _t597 = _t206*_t26;
  const double _t598 = _t49*_t597;
  const double _t599 = _t218*_t341;
  const double _t600 = _t589*_t74;
  const double _t601 = _t500*_t502;
  const double _t603 = _t581*_t602*_t9;
  const double _t604 = _t492*_t9;
  const double _t605 = 0.2e1*_t318;
  const double _t606 = 0.2e1*_t316;
  const double _t607 = _t603*_t74;
  const double _t608 = _t211*_t564;
  const double _t609 = -0.4e1*_hc0[1]*_t129*_t18*_t21*_t69*_t9*params->C - 0.2e1*_hc0[1]*_t129*_t18*_t21*_t69*params->B - 0.4e1*_hc0[1]*_t18*_t48*_t68*_t69*_t9*params->C - 0.2e1*_hc0[1]*_t18*_t48*_t68*_t69*params->B - 0.4e1*_hc0[2]*_t18*_t21*_t26*_t48*_t69*_t9*params->C - 0.2e1*_hc0[2]*_t18*_t21*_t26*_t48*_t69*params->B + _t172*_t597*_t608*params->B + _t220*_t25*_t341 + _t341*_t377 + _t504*_t597*_t608*_t9 + _t518;
  const double _t611 = _t15*_t556;
  const double _t612 = _hc1[2]*_t611;
  const double _t613 = 0.3e1*_t611;
  const double _t614 = _t275*_t34;
  const double _t616 = _hc1[3]*_t304;
  const double _t617 = _t34*_t616;
  const double _t618 = _hc1[1]*_t272;
  const double _t619 = _hc1[1]*_t58;
  const double _t620 = 0.3e1*_t619;
  const double _t621 = _t2*_t620;
  const double _t622 = (0.3e1 / 0.2e1)*_t107;
  const double _t623 = (0.3e1 / 0.2e1)*_t117;
  const double _t624 = _hc1[2]*_t110;
  const double _t625 = _t287*_t304;
  const double _t626 = -_t106*_t576 + _t112*_t272 + _t112*_t560 + _t166*_t285 + _t227 + _t229 - _t230*_t624 + _t230*_t625 + _t231 + _t232 + 0.3e1*_t276 + 0.3e1*_t278 + _t281*_t610 - _t528*_t578 + _t531*_t615 + 0.3e1*_t618 - _t624*_t82 + _t625*_t82;
  const double _t627 = 0.4e1*_t107;
  const double _t628 = _t140*_t89;
  const double _t629 = _t267*_t90;
  const double _t630 = _t257*_t301;
  const double _t631 = 0.2e1*_t618;
  const double _t632 = _t197*_t89;
  const double _t633 = _t257*_t44;
  const double _t634 = _t251*_t45;
  const double _t635 = _t33*_t634;
  const double _t636 = _t500*_t544;
  const double _t638 = _t14*_t254;
  const double _t639 = _t308*params->B;
  const double _t640 = _t163*_t581*_t639;
  const double _t641 = 0.2e1*_t276;
  const double _t642 = 0.2e1*_t278;
  const double _t643 = _t14*_t308;
  const double _t644 = 0.16e2*_t297*_t643*params->C;
  const double _t645 = -0.4e1*_hc1[1]*_t114*_t14*_t18*_t20*_t90*params->C - 0.2e1*_hc1[1]*_t114*_t18*_t20*_t90*params->B - 0.4e1*_hc1[1]*_t14*_t18*_t43*_t89*_t90*params->C - 0.2e1*_hc1[1]*_t18*_t43*_t89*_t90*params->B - 0.4e1*_hc1[2]*_t14*_t18*_t20*_t35*_t43*_t90*params->C - 0.2e1*_hc1[2]*_t18*_t20*_t35*_t43*_t90*params->B + _t172*_t304*_t639 + _t243*_t289 + _t245*_t289*_t36 + _t304*_t504*_t643 + _t554;
  const double _t646 = -_t104*_t591;
  const double _t648 = _hc1[2]*_t647;
  const double _t650 = _hc1[3]*_t134;
  const double _t651 = _t34*_t650;
  const double _t653 = _hc1[1]*_t40;
  const double _t654 = _t106*_t174;
  const double _t655 = (0.1e1 / 0.2e1)*_t101;
  const double _t656 = _t354*_t97;
  const double _t659 = 0.2e1*_t348;
  const double _t660 = 0.2e1*_t349;
  const double _t661 = 0.2e1*_t285;
  const double _t662 = _t134*_t287;
  const double _t663 = _hc1[1]*_t173 - _hc1[1]*_t462 + _t106*_t172 + _t137*_t532 + _t137*_t533 + _t272*_t661 - _t275*_t658 + _t531*_t652 - _t582*_t616 + _t631 + _t641 + _t642 + _t648*_t657 + _t654 + _t659 + _t660 + _t662*_t82;
  const double _t664 = _t197*_t252;
  const double _t665 = _t119*_t591;
  const double _t666 = _hc0[2]*_t647;
  const double _t669 = _hc0[3]*_t148;
  const double _t670 = _t23*_t669;
  const double _t671 = _hc0[1]*_t31;
  const double _t672 = _t121*_t174;
  const double _t673 = _t321*_t72;
  const double _t674 = _t218*_t321;
  const double _t675 = _t157 + _t335*_t667 + _t574;
  const double _t676 = -_t150*_t321 - _t152 + 0.2e1*_t25*_t4*_t675*_t9*params->C + _t25*_t4*_t675*params->B - _t320*_t673 - _t321*_t479 - _t574*_t674;
  const double _t677 = _t150*_t376;
  const double _t678 = 0.2e1*_t368;
  const double _t679 = 0.2e1*_t370;
  const double _t680 = 0.2e1*_t339;
  const double _t681 = _t148*_t337;
  const double _t682 = -_hc0[1]*_t173 + _hc0[1]*_t462 - _t121*_t172 + _t136*_t483 + _t311*_t680 + _t317*_t658 + _t474*_t681 + _t482*_t668 + _t484*_t667 + _t565*_t582 + _t592 + _t605 + _t606 + _t657*_t666 - _t672 + _t678 + _t679;
  const double _t683 = _t158*_t74;
  const double _t684 = _t197*_t207;
  const double _t685 = _hc0[1]*_t331;
  const double _t689 = _t275*_t526;
  const double _t690 = -_hc1[1]*_t162 - _hc1[1]*_t165 - _hc1[2]*_t137*_t578 + _t112*_t393 + _t137*_t625 + _t204*_t275 + 0.3e1*_t348 + 0.3e1*_t349 + _t392 + _t394 + _t396*_t625 + _t397 + _t398 + _t531*_t688 - _t578*_t650 + _t689;
  const double _t693 = _t44*_t548;
  const double _t694 = 0.6e1*_t138;
  const double _t695 = 0.6e1*_t135;
  const double _t696 = _t257*_t45*_t504;
  const double _t698 = _t44*_t634;
  const double _t700 = (0.1e1 / 0.2e1)*_t31;
  const double _t701 = _t317*_t526;
  const double _t702 = _hc0[1]*_t162 + _hc0[1]*_t165 + _hc0[2]*_t136*_t578 + _t127*_t421 + _t136*_t579 - _t204*_t317 + 0.3e1*_t368 + 0.3e1*_t370 + _t395*_t579 + _t422 + _t424 + _t425 + _t426 + _t482*_t699 + _t578*_t669 - _t701;
  const double _t703 = _t25*_t490;
  const double _t705 = 0.2e1*_t424;
  const double _t706 = _t49*_t507;
  const double _t707 = 0.6e1*_t147;
  const double _t708 = 0.6e1*_t149;
  const double _t709 = _t326*_t49;
  const double _t717 = 0.2e1*_t46;
  const double _t718 = _t45*_t541*_t543;
  const double _t719 = _t402*_t504;
  const double _t720 = _t140*_t38;
  const double _t721 = _t144*_t92;
  const double _t722 = _t409*_t95;
  const double _t723 = 0.3e1*_t418;
  const double _t724 = _t111*_t713 + _t111*_t716 + _t137*_t662 + _t281*_t712 + _t285*_t714 + 0.4e1*_t392 + _t393*_t661 + 0.4e1*_t394 + _t396*_t662 + 0.4e1*_t397 + 0.4e1*_t398 + _t531*_t710 + _t662*_t715;
  const double _t731 = 0.2e1*_t54;
  const double _t732 = _t50*_t72;
  const double _t733 = _t433*_t504;
  const double _t734 = _t321*_t501;
  const double _t735 = _t154*_t53;
  const double _t736 = 0.3e1*_t447;
  const double _t737 = _t126*_t725 + _t126*_t728 + _t335*_t711 + _t339*_t727 + _t421*_t680 + 0.4e1*_t422 + 0.4e1*_t424 + 0.4e1*_t425 + 0.4e1*_t426 + _t482*_t726 + _t667*_t681 + _t681*_t729 + _t681*_t730;
  const double d4F_dna4 = _hc2[14] + 0.4e1*_t226 + 0.4e1*_t270 + _t3*(my_piecewise3(_t11, 0, _t101*_t235 + _t101*_t236 + _t12*(0.12e2*_hc1[1]*_hc1[2]*_t14*_t228*_t251*_t35*_t4*params->C + 0.6e1*_hc1[1]*_hc1[2]*_t228*_t251*_t35*_t4*params->B + 0.12e2*_hc1[1]*_t14*_t18*_t20*_t89*_t90*params->C + 0.6e1*_hc1[1]*_t14*_t18*_t35*_t82*_t90*params->C + 0.6e1*_hc1[1]*_t18*_t20*_t89*_t90*params->B + 0.3e1*_hc1[1]*_t18*_t35*_t82*_t90*params->B + 0.28e2*_hc1[1]*_t20*_t251*_t58*_t91*params->C + 0.6e1*_hc1[2]*_t14*_t18*_t35*_t84*_t90*params->C + 0.3e1*_hc1[2]*_t18*_t35*_t84*_t90*params->B + 0.4e1*_t14*_t20*_t230*_t251*_t255*_t35*_t4*params->C + 0.4e1*_t14*_t20*_t251*_t255*_t35*_t4*_t82*params->C + 0.12e2*_t14*_t251*_t255*_t4*_t84*_t89*params->C + 0.2e1*_t14*_t36*_t4*_t534*params->C + 0.12e2*_t14*_t36*_t58*_t89*params->C + 0.22e2*_t163*_t90*_t91*params->C + 0.4e1*_t18*_t241*_t35*_t90*params->C + 0.2e1*_t18*_t249*_t89*_t90*params->C + 0.22e2*_t18*_t255*_t541*_t84*_t91*params->C + 0.2e1*_t18*_t35*_t90*params->C*(0.2e1*_t237 + 0.2e1*_t238 + 0.2e1*_t239 + 0.2e1*_t240 + _t536 + _t537) + 0.2e1*_t18*(_t89 * _t89)*_t90*params->C + 0.2e1*_t20*_t230*_t251*_t255*_t35*_t4*params->B + 0.2e1*_t20*_t251*_t255*_t35*_t4*_t82*params->B - _t227*_t250 - _t227*_t546 - _t228*_t500*_t544 - _t228*_t552 - _t229*_t250 - _t229*_t546 - _t231*_t250 - _t231*_t546 - _t232*_t250 - _t232*_t546 - _t235*_t253 - _t236*_t253 - _t241*_t33*_t548 - _t241*_t538 - 0.3e1*_t241*_t542 - _t249*_t300*_t509 - _t249*_t540 + 0.6e1*_t251*_t255*_t4*_t84*_t89*params->B - _t254*_t498 - _t254*_t549 - _t260*_t536 - _t260*_t537 - _t263*_t499 - _t263*_t550 - _t300*_t504*_t89 + _t36*_t4*_t534*params->B + 0.6e1*_t36*_t58*_t89*params->B - 0.3e1*_t535 - _t539*_t89 - _t545*_t83 - _t545*_t85 - _t554) + _t166*_t274 + _t227*_t530 + _t229*_t530 + _t230*_t525 + _t230*_t529 + _t231*_t530 + _t232*_t530 + _t269*_t86 + _t273*_t519 + _t463*_t524 + _t520*_t521 + _t522*_t523 + _t527*_t529 + _t529*_t82) + my_piecewise3(_t6, 0, _t167*_t313 + _t168*_t476 + _t171*_t476 + _t175*_t466 + _t176*_t476 + _t182*_t475 + _t186*_t80 + _t187*_t481 + _t225*_t65 + _t312*_t455 + _t456*_t457 + _t458*_t459 + _t464*_t465 + _t468*_t470 + _t470*_t472 + _t470*_t474 + _t7*(0.12e2*_hc0[1]*_hc0[2]*_t169*_t180*_t206*_t4*_t9*params->C + 0.6e1*_hc0[1]*_hc0[2]*_t169*_t180*_t206*_t4*params->B + 0.12e2*_hc0[1]*_t18*_t21*_t68*_t69*_t9*params->C + 0.6e1*_hc0[1]*_t18*_t21*_t68*_t69*params->B + 0.6e1*_hc0[1]*_t18*_t26*_t61*_t69*_t9*params->C + 0.3e1*_hc0[1]*_t18*_t26*_t61*_t69*params->B + 0.28e2*_hc0[1]*_t206*_t21*_t58*_t70*params->C + 0.6e1*_hc0[2]*_t18*_t180*_t63*_t69*_t9*params->C + 0.3e1*_hc0[2]*_t18*_t180*_t63*_t69*params->B + 0.22e2*_t163*_t69*_t70*params->C - _t168*_t202 - _t168*_t506 - _t169*_t500*_t502 - _t169*_t515 - _t170*_t203 - _t171*_t202 - _t171*_t506 + 0.4e1*_t175*_t206*_t21*_t211*_t26*_t4*_t9*params->C + 0.2e1*_t175*_t206*_t21*_t211*_t26*_t4*params->B - _t176*_t202 - _t176*_t506 + 0.4e1*_t18*_t192*_t26*_t69*params->C + 0.2e1*_t18*_t201*_t68*_t69*params->C + 0.22e2*_t18*_t211*_t496*_t63*_t70*params->C + 0.2e1*_t18*_t26*_t69*params->C*(0.2e1*_t188 + 0.2e1*_t189 + 0.2e1*_t190 + 0.2e1*_t191 + _t487 + _t488) + 0.2e1*_t18*(_t68 * _t68)*_t69*params->C - _t186*_t208 - _t187*_t478*_t72 - _t192*_t22*_t507 - 0.3e1*_t192*_t497 - _t201*_t508*_t509 + 0.4e1*_t206*_t21*_t211*_t26*_t4*_t61*_t9*params->C + 0.2e1*_t206*_t21*_t211*_t26*_t4*_t61*params->B + 0.12e2*_t206*_t211*_t4*_t478*_t63*_t9*params->C + 0.6e1*_t206*_t211*_t4*_t478*_t63*params->B - _t209*_t498 - _t209*_t511 - _t213*_t499 - _t213*_t513 - _t215*_t487 - _t218*_t478*_t488 - _t219*_t475 + 0.2e1*_t25*_t4*_t485*_t9*params->C + _t25*_t4*_t485*params->B + 0.12e2*_t25*_t58*_t68*_t9*params->C + 0.6e1*_t25*_t58*_t68*params->B - 0.3e1*_t486 - _t489*_t490 - _t492*_t493 - _t494*_t495 - _t504*_t508*_t68 - _t505*_t62 - _t505*_t64 - _t518)));
  const double d4F_dna3_dnb = _t271 + _t3*(my_piecewise3(_t11, 0, -_t101*_t621 + _t101*_t622 - _t106*_t40*_t526 + _t108*_t227 + _t108*_t229 + _t108*_t231 + _t108*_t232 + _t109*_t269 + _t12*(0.12e2*_hc1[1]*_hc1[2]*_t14*_t251*_t35*_t4*_t43*_t84*params->C + 0.6e1*_hc1[1]*_hc1[2]*_t251*_t35*_t4*_t43*_t84*params->B + 0.8e1*_hc1[1]*_t14*_t163*_t2*_t89*_t90*params->C + 0.4e1*_hc1[1]*_t14*_t18*_t20*_t89*_t90*params->C + 0.2e1*_hc1[1]*_t14*_t18*_t35*_t82*_t90*params->C + 0.4e1*_hc1[1]*_t163*_t2*_t89*_t90*params->B + 0.2e1*_hc1[1]*_t18*_t20*_t89*_t90*params->B + _hc1[1]*_t18*_t35*_t82*_t90*params->B + 0.12e2*_hc1[1]*_t2*_t251*_t452*_t91*params->C + 0.4e1*_hc1[1]*_t20*_t251*_t35*_t45*_t58*params->C + 0.12e2*_hc1[1]*_t20*_t251*_t58*_t91*params->C + 0.12e2*_hc1[1]*_t251*_t43*_t58*_t91*params->C + 0.8e1*_hc1[2]*_t14*_t163*_t2*_t20*_t35*_t90*params->C + 0.2e1*_hc1[2]*_t14*_t18*_t35*_t84*_t90*params->C + 0.4e1*_hc1[2]*_t163*_t2*_t20*_t35*_t90*params->B + _hc1[2]*_t18*_t35*_t84*_t90*params->B - _t107*_t205*_t252 + 0.4e1*_t114*_t14*_t251*_t255*_t4*_t84*params->C + 0.4e1*_t114*_t14*_t36*_t58*params->C + 0.2e1*_t114*_t18*_t249*_t90*params->C + 0.2e1*_t114*_t18*_t89*_t90*params->C + 0.2e1*_t114*_t251*_t255*_t4*_t84*params->B + 0.2e1*_t114*_t36*_t58*params->B - _t115*_t241 + 0.8e1*_t14*_t20*_t251*_t255*_t4*_t43*_t89*params->C + 0.4e1*_t14*_t251*_t255*_t35*_t4*_t43*_t82*params->C + 0.2e1*_t14*_t36*_t4*_t626*params->C + 0.8e1*_t14*_t36*_t58*_t89*params->C - _t141*_t241*_t90 + 0.4e1*_t163*_t35*_t45*_t90*params->C + 0.18e2*_t163*_t90*_t91*params->C + 0.18e2*_t18*_t20*_t255*_t43*_t541*_t91*params->C + 0.2e1*_t18*_t241*_t45*_t90*params->C + 0.4e1*_t18*_t255*_t35*_t45*_t541*_t84*params->C + 0.2e1*_t18*_t289*_t35*_t90*params->C + 0.2e1*_t18*_t35*_t90*params->C*(-_t106*_t582 + _t261 + _t262 + 0.2e1*_t282 + 0.2e1*_t286 + 0.2e1*_t288 - _t581*_t619 + _t627) - _t193*_t294*_t94 - _t195*_t263 - _t197*_t249*_t633 + 0.4e1*_t20*_t251*_t255*_t4*_t43*_t89*params->B - _t20*_t640 - _t20*_t644 - _t205*_t294*_t300 - _t222*_t363 - _t223*_t628 - _t241*_t99 - _t245*_t263 - _t248*_t289*_t547 - _t249*_t629 - _t250*_t276 - _t250*_t278 - _t250*_t618 + 0.2e1*_t251*_t255*_t35*_t4*_t43*_t82*params->B - _t253*_t284 - _t254*_t590 - _t260*_t627 - _t261*_t302 - _t262*_t302 - _t277*_t552 - _t277*_t636 - _t289*_t86*_t92 - _t295*_t83 - _t295*_t85 - _t296*_t453*_t588 - _t303*_t629 - _t307*_t637 + _t36*_t4*_t626*params->B + 0.4e1*_t36*_t58*_t89*params->B - _t492*_t638 - _t535 - _t629*_t89 - _t630*_t83 - _t630*_t85 - _t631*_t96 - _t632*_t633 - _t632*_t635 - _t641*_t96 - _t642*_t96 - _t645) + _t166*_t614 - _t230*_t612 + _t230*_t617 + _t233*_t276 + _t233*_t278 + _t233*_t618 + _t234*_t309 + _t272*_t524 + _t273*_t610 + _t521*_t615 + _t524*_t560 - _t528*_t613 - _t612*_t82 + _t617*_t82 + _t623*_t83 + _t623*_t85) + my_piecewise3(_t6, 0, _t121*_t31*_t526 + _t123*_t225 + _t124*_t168 + _t124*_t171 + _t124*_t176 + _t132*_t184 + _t167*_t563 + _t170*_t323 + _t175*_t558 + _t175*_t566 + (0.3e1 / 0.2e1)*_t182*_t316 + _t183*_t575 + _t185*_t342 + _t311*_t465 + _t312*_t555 + _t318*_t568 + _t457*_t562 + _t465*_t561 + _t469*_t559 + _t558*_t61 + _t566*_t61 + _t567*_t568 + _t571*_t80 + _t572*_t80 + _t7*(0.12e2*_hc0[1]*_hc0[2]*_t180*_t206*_t314*_t4*_t63*_t9*params->C + 0.6e1*_hc0[1]*_hc0[2]*_t180*_t206*_t314*_t4*_t63*params->B + 0.4e1*_hc0[1]*_t18*_t21*_t68*_t69*_t9*params->C + 0.2e1*_hc0[1]*_t18*_t21*_t68*_t69*params->B + 0.2e1*_hc0[1]*_t18*_t26*_t61*_t69*_t9*params->C + _hc0[1]*_t18*_t26*_t61*_t69*params->B + 0.8e1*_hc0[1]*_t2*_t26*_t452*_t69*_t9*params->C + 0.4e1*_hc0[1]*_t2*_t26*_t452*_t69*params->B + 0.4e1*_hc0[1]*_t206*_t21*_t26*_t50*_t58*params->C + 0.12e2*_hc0[1]*_t206*_t21*_t58*_t70*params->C + 0.12e2*_hc0[1]*_t206*_t48*_t58*_t70*params->C - _hc0[1]*_t207*_t591*params->C + 0.2e1*_hc0[2]*_t18*_t180*_t63*_t69*_t9*params->C + _hc0[2]*_t18*_t180*_t63*_t69*params->B - _t121*_t600 - _t121*_t607 - _t122*_t205*_t207 + 0.2e1*_t129*_t18*_t201*_t69*params->C + 0.2e1*_t129*_t18*_t68*_t69*params->C + 0.4e1*_t129*_t25*_t58*_t9*params->C + 0.2e1*_t129*_t25*_t58*params->B - _t130*_t192 - _t153*_t489 - _t155*_t192*_t69 + 0.16e2*_t163*_t2*_t206*_t21*_t211*_t26*_t9*params->C + 0.8e1*_t163*_t2*_t206*_t21*_t211*_t26*params->B + 0.4e1*_t163*_t26*_t50*_t69*params->C + 0.18e2*_t163*_t69*_t70*params->C + 0.4e1*_t18*_t180*_t211*_t321*_t496*_t63*params->C + 0.2e1*_t18*_t192*_t50*_t69*params->C + 0.18e2*_t18*_t21*_t211*_t48*_t496*_t70*params->C + 0.2e1*_t18*_t26*_t341*_t69*params->C + 0.2e1*_t18*_t26*_t69*params->C*(_t121*_t582 + _t216 + _t217 + 0.2e1*_t336 + 0.2e1*_t338 + 0.2e1*_t340 + _t569*_t581 + _t583) - _t193*_t585 - _t195*_t213 - _t197*_t201*_t598 - _t200*_t599 - _t202*_t318 - _t202*_t567 - _t203*_t316 - _t205*_t333*_t508 + 0.8e1*_t206*_t21*_t211*_t4*_t48*_t68*_t9*params->C + 0.4e1*_t206*_t21*_t211*_t4*_t48*_t68*params->B + 0.4e1*_t206*_t211*_t26*_t4*_t48*_t61*_t9*params->C + 0.2e1*_t206*_t211*_t26*_t4*_t48*_t61*params->B + 0.4e1*_t206*_t211*_t4*_t573*_t63*_t9*params->C + 0.2e1*_t206*_t211*_t4*_t573*_t63*params->B - _t208*_t328 - _t209*_t590 - _t209*_t604 - _t213*_t220 - _t215*_t583 - _t216*_t332 - _t217*_t594 - _t219*_t606 - _t222*_t387 - _t223*_t493 - _t223*_t494 - _t223*_t584 + 0.2e1*_t25*_t4*_t580*_t9*params->C + _t25*_t4*_t580*params->B + 0.8e1*_t25*_t58*_t68*_t9*params->C + 0.4e1*_t25*_t58*_t68*params->B - _t26*_t327*_t62 - _t315*_t515 - _t315*_t601 - _t330*_t62 - _t341*_t65*_t72 - _t387*_t430 - _t486 - _t586*_t64 - _t587*_t589 - _t587*_t603 - _t592*_t76 - _t593*_t64*_t78 - _t595*_t596 - _t595*_t598 - _t605*_t76 - _t609))) + 0.3e1*_t310 + 0.3e1*_t343;
  const double d4F_dna2_dnb2 = _t3*(my_piecewise3(_t11, 0, -_t117*_t280 + _t117*_t284 + _t12*(0.12e2*_hc1[1]*_hc1[2]*_t134*_t14*_t20*_t251*_t35*_t4*params->C + 0.6e1*_hc1[1]*_hc1[2]*_t134*_t20*_t251*_t35*_t4*params->B + 0.8e1*_hc1[1]*_t114*_t14*_t163*_t2*_t90*params->C + 0.4e1*_hc1[1]*_t114*_t14*_t18*_t43*_t90*params->C + 0.4e1*_hc1[1]*_t114*_t163*_t2*_t90*params->B + 0.2e1*_hc1[1]*_t114*_t18*_t43*_t90*params->B + 0.2e1*_hc1[1]*_t137*_t14*_t18*_t35*_t90*params->C + _hc1[1]*_t137*_t18*_t35*_t90*params->B + 0.8e1*_hc1[1]*_t2*_t251*_t35*_t45*_t452*params->C + 0.6e1*_hc1[1]*_t20*_t251*_t35*_t45*_t58*params->C + 0.6e1*_hc1[1]*_t251*_t35*_t43*_t45*_t58*params->C + 0.16e2*_hc1[1]*_t251*_t43*_t58*_t91*params->C + 0.2e1*_hc1[2]*_t134*_t14*_t18*_t35*_t90*params->C + _hc1[2]*_t134*_t18*_t35*_t90*params->B + 0.8e1*_hc1[2]*_t14*_t163*_t2*_t35*_t43*_t90*params->C + 0.4e1*_hc1[2]*_t163*_t2*_t35*_t43*_t90*params->B - _t107*_t197*_t257*_t45 + 0.8e1*_t114*_t14*_t20*_t251*_t255*_t4*_t43*params->C + 0.8e1*_t114*_t14*_t36*_t58*params->C + 0.2e1*_t114*_t18*_t294*_t90*params->C - _t114*_t197*_t635 + 0.4e1*_t114*_t20*_t251*_t255*_t4*_t43*params->B + 0.4e1*_t114*_t36*_t58*params->B + 0.4e1*_t134*_t14*_t251*_t255*_t4*_t89*params->C + 0.12e2*_t134*_t18*_t255*_t541*_t91*params->C + 0.2e1*_t134*_t251*_t255*_t4*_t89*params->B - _t135*_t253 - _t135*_t664 + 0.4e1*_t137*_t14*_t20*_t251*_t255*_t35*_t4*params->C + 0.2e1*_t137*_t20*_t251*_t255*_t35*_t4*params->B - _t138*_t253 - _t138*_t664 + 0.2e1*_t14*_t36*_t4*_t663*params->C + 0.4e1*_t14*_t36*_t58*_t89*params->C + 0.2e1*_t144*_t18*_t89*_t90*params->C - _t144*_t291*_t94 - _t144*_t300*_t78 - _t163*_t296*_t298 + 0.10e2*_t163*_t35*_t45*_t90*params->C + 0.12e2*_t163*_t90*_t91*params->C + 0.10e2*_t18*_t20*_t255*_t35*_t43*_t45*_t541*params->C + 0.4e1*_t18*_t289*_t45*_t90*params->C + 0.2e1*_t18*_t35*_t90*params->C*(_hc1[1]*_t172 - _t275*_t582 + _t280 + 0.2e1*_t352 + 0.2e1*_t353 + _t361 + _t362 + _t627) - _t193*_t628 - _t195*_t364 - _t222*_t254 - _t223*_t355 - _t223*_t638 - _t245*_t364 - _t250*_t348 - _t250*_t349 - _t251*_t359*_t89 - _t260*_t361 - _t260*_t362 - _t284*_t295 - _t289*_t408 - _t289*_t410*_t90 - _t294*_t504*_t633 - _t294*_t539 - 0.10e2*_t296*_t453*params->B - _t302*_t627 - _t303*_t539 - 0.4e1*_t306*_t602 - 0.20e2*_t307*_t453 - _t347*_t552 - _t347*_t636 - _t354*_t542 - _t354*_t547*_t86 - _t354*_t99 + _t36*_t4*_t663*params->B + 0.2e1*_t36*_t58*_t89*params->B - _t363*_t590 - _t43*_t640 - _t43*_t644 - _t645 - _t656 - _t659*_t96 - _t660*_t96) + _t135*_t655 + _t137*_t525 + _t137*_t529 + _t138*_t655 - _t15*_t174*_t616 + _t15*_t648*_t649 + _t165*_t274 + _t165*_t653 - _t174*_t275*_t40 + _t272*_t346 + _t274*_t59 + _t276*_t46 + _t278*_t46 + _t309*_t44 + _t33*_t365 + _t348*_t40 + _t349*_t40 + _t351*_t83 + _t351*_t85 + _t46*_t618 - _t46*_t654 + _t521*_t652 + _t59*_t653 + _t646 + _t651*_t82) + my_piecewise3(_t6, 0, _t10*_t174*_t565 + _t10*_t649*_t666 + _t132*_t328 + _t132*_t334 + _t136*_t466 - _t165*_t313 - _t165*_t671 + _t174*_t31*_t317 + _t182*_t370 + _t22*_t389 + _t31*_t368 + _t311*_t367 - _t313*_t59 + _t316*_t322 + _t318*_t54 + _t342*_t49 + _t371*_t80 + _t372*_t481 + _t373*_t62 + _t457*_t668 + _t470*_t667 + _t474*_t670 + _t54*_t567 + _t54*_t672 - _t59*_t671 + (0.1e1 / 0.2e1)*_t64*_t676 + _t665 + _t7*(0.12e2*_hc0[1]*_hc0[2]*_t148*_t178*_t180*_t206*_t4*_t9*params->C + 0.6e1*_hc0[1]*_hc0[2]*_t148*_t178*_t180*_t206*_t4*params->B + 0.4e1*_hc0[1]*_t129*_t18*_t48*_t69*_t9*params->C + 0.2e1*_hc0[1]*_t129*_t18*_t48*_t69*params->B + 0.2e1*_hc0[1]*_t136*_t18*_t26*_t69*_t9*params->C + _hc0[1]*_t136*_t18*_t26*_t69*params->B + 0.4e1*_hc0[1]*_t163*_t26*_t69*_t9*params->C + 0.2e1*_hc0[1]*_t163*_t26*_t69*params->B + 0.20e2*_hc0[1]*_t2*_t26*_t452*_t69*_t9*params->C + 0.10e2*_hc0[1]*_t2*_t26*_t452*_t69*params->B + 0.6e1*_hc0[1]*_t206*_t21*_t26*_t50*_t58*params->C + 0.6e1*_hc0[1]*_t206*_t26*_t48*_t50*_t58*params->C + 0.16e2*_hc0[1]*_t206*_t48*_t58*_t70*params->C - _hc0[1]*_t382*_t637*params->C + 0.2e1*_hc0[2]*_t148*_t18*_t180*_t69*_t9*params->C + _hc0[2]*_t148*_t18*_t180*_t69*params->B - _t122*_t197*_t382 + 0.2e1*_t129*_t18*_t333*_t69*params->C - _t129*_t197*_t596 + 0.8e1*_t129*_t206*_t21*_t211*_t4*_t48*_t9*params->C + 0.4e1*_t129*_t206*_t21*_t211*_t4*_t48*params->B + 0.8e1*_t129*_t25*_t58*_t9*params->C + 0.4e1*_t129*_t25*_t58*params->B + 0.4e1*_t136*_t206*_t21*_t211*_t26*_t4*_t9*params->C + 0.2e1*_t136*_t206*_t21*_t211*_t26*_t4*params->B - _t147*_t684 + 0.12e2*_t148*_t18*_t211*_t496*_t70*params->C + 0.4e1*_t148*_t206*_t211*_t4*_t478*_t9*params->C + 0.2e1*_t148*_t206*_t211*_t4*_t478*params->B - _t149*_t684 + 0.2e1*_t158*_t18*_t68*_t69*params->C - _t158*_t508*_t78 + 0.16e2*_t163*_t2*_t206*_t211*_t26*_t48*_t9*params->C + 0.8e1*_t163*_t2*_t206*_t211*_t26*_t48*params->B + 0.10e2*_t163*_t26*_t50*_t69*params->C + 0.12e2*_t163*_t69*_t70*params->C + 0.10e2*_t18*_t21*_t211*_t26*_t48*_t496*_t50*params->C + 0.2e1*_t18*_t26*_t69*params->C*(-_hc0[1]*_t172 + _t317*_t582 - _t334 + 0.2e1*_t374 + 0.2e1*_t375 + _t385 + _t386 + _t583) + 0.4e1*_t18*_t341*_t50*_t69*params->C - _t193*_t584 - _t195*_t388 - _t202*_t368 - _t203*_t370 - _t209*_t222 - _t209*_t430 - _t215*_t385 - _t218*_t376*_t65 - _t219*_t679 - _t220*_t388 - _t223*_t378 + 0.2e1*_t25*_t4*_t682*_t9*params->C + _t25*_t4*_t682*params->B + 0.4e1*_t25*_t58*_t68*_t9*params->C + 0.2e1*_t25*_t58*_t68*params->B - _t291*_t683 - _t317*_t600 - _t317*_t607 - _t326*_t383*_t68 - _t328*_t330 - _t332*_t583 - _t333*_t504*_t598 - _t341*_t437 - _t369*_t515 - _t369*_t601 - _t376*_t479 - _t376*_t497 - _t384*_t599 - _t387*_t590 - _t387*_t604 - _t431*_t68 - _t432*_t478 - _t435*_t478 - _t492*_t585 - _t589*_t685 - _t603*_t685 - _t609 - _t677 - _t678*_t76))) + 0.2e1*_t310 + 0.2e1*_t343 + 0.2e1*_t366 + 0.2e1*_t390;
  const double d4F_dna_dnb3 = _t3*(my_piecewise3(_t11, 0, _hc1[1]*_t46*_t687 - _t104*_t164 + _t12*(0.12e2*_hc1[1]*_hc1[2]*_t14*_t251*_t35*_t391*_t4*params->C + 0.6e1*_hc1[1]*_hc1[2]*_t251*_t35*_t391*_t4*params->B + 0.12e2*_hc1[1]*_t114*_t14*_t18*_t43*_t90*params->C + 0.6e1*_hc1[1]*_t114*_t18*_t43*_t90*params->B + 0.6e1*_hc1[1]*_t137*_t14*_t18*_t35*_t90*params->C + 0.3e1*_hc1[1]*_t137*_t18*_t35*_t90*params->B + 0.28e2*_hc1[1]*_t251*_t35*_t43*_t45*_t58*params->C + 0.6e1*_hc1[2]*_t134*_t14*_t18*_t35*_t90*params->C + 0.3e1*_hc1[2]*_t134*_t18*_t35*_t90*params->B + 0.12e2*_t114*_t134*_t14*_t251*_t255*_t4*params->C + 0.6e1*_t114*_t134*_t251*_t255*_t4*params->B + 0.12e2*_t114*_t14*_t36*_t58*params->C + 0.6e1*_t114*_t144*_t18*_t90*params->C + 0.6e1*_t114*_t36*_t58*params->B - _t114*_t697*_t698 - 0.3e1*_t115*_t354 + 0.22e2*_t134*_t18*_t255*_t35*_t45*_t541*params->C - _t135*_t696 + 0.4e1*_t137*_t14*_t251*_t255*_t35*_t4*_t43*params->C + 0.2e1*_t137*_t251*_t255*_t35*_t4*_t43*params->B - _t138*_t696 + 0.4e1*_t14*_t251*_t255*_t35*_t396*_t4*_t43*params->C + 0.2e1*_t14*_t36*_t4*_t690*params->C - _t144*_t509*_t633 - _t144*_t540 + 0.22e2*_t163*_t35*_t45*_t90*params->C + 0.2e1*_t18*_t35*_t418*_t90*params->C + 0.6e1*_t18*_t354*_t45*_t90*params->C - _t250*_t392 - _t250*_t394 - _t250*_t397 - _t250*_t398 + 0.2e1*_t251*_t255*_t35*_t396*_t4*_t43*params->B - _t295*_t412 - _t295*_t413 - _t302*_t694 - _t302*_t695 - _t354*_t538 - _t354*_t693 - _t355*_t691 + _t36*_t4*_t690*params->B - _t363*_t498 - _t363*_t549 - _t364*_t499 - _t364*_t550 - _t391*_t552 - _t392*_t546 - _t394*_t546 - _t397*_t546 - _t398*_t546 - _t544*_t692 - _t554 - 0.3e1*_t656) + _t135*_t623 - 0.3e1*_t137*_t612 + _t137*_t617 + _t138*_t623 - _t145*_t621 + _t145*_t622 + (0.1e1 / 0.2e1)*_t33*_t419 + _t346*_t686 + _t346*_t687 + _t348*_t399 + _t349*_t399 + _t350*_t392 + _t350*_t394 + _t350*_t397 + _t350*_t398 + _t365*_t400 + _t393*_t524 + _t396*_t617 + _t46*_t620 - _t46*_t689 + _t521*_t688 - _t613*_t650 + _t646) + my_piecewise3(_t6, 0, -_hc0[1]*_t54*_t687 + _t119*_t164 + _t132*_t427 + 0.3e1*_t136*_t558 + _t136*_t566 + _t159*_t571 + _t159*_t572 + (0.1e1 / 0.2e1)*_t182*_t424 + (0.1e1 / 0.2e1)*_t22*_t448 + (0.3e1 / 0.2e1)*_t322*_t370 - _t367*_t686 - _t367*_t687 + (0.3e1 / 0.2e1)*_t368*_t54 + _t389*_t429 + _t395*_t566 + _t421*_t465 + _t422*_t700 + _t425*_t700 + _t426*_t700 + _t428*_t575 + _t457*_t699 - _t54*_t570 + _t54*_t701 + _t559*_t669 + _t665 + _t7*(0.12e2*_hc0[1]*_hc0[2]*_t180*_t206*_t4*_t423*_t9*params->C + 0.6e1*_hc0[1]*_hc0[2]*_t180*_t206*_t4*_t423*params->B + 0.12e2*_hc0[1]*_t129*_t18*_t48*_t69*_t9*params->C + 0.6e1*_hc0[1]*_t129*_t18*_t48*_t69*params->B + 0.6e1*_hc0[1]*_t136*_t18*_t26*_t69*_t9*params->C + 0.3e1*_hc0[1]*_t136*_t18*_t26*_t69*params->B + 0.28e2*_hc0[1]*_t206*_t26*_t48*_t50*_t58*params->C + 0.6e1*_hc0[2]*_t148*_t18*_t180*_t69*_t9*params->C + 0.3e1*_hc0[2]*_t148*_t18*_t180*_t69*params->B + 0.6e1*_t129*_t158*_t18*_t69*params->C + 0.12e2*_t129*_t25*_t58*_t9*params->C + 0.6e1*_t129*_t25*_t58*params->B - _t129*_t697*_t709 - 0.3e1*_t130*_t376 + 0.4e1*_t136*_t206*_t211*_t26*_t4*_t48*_t9*params->C + 0.2e1*_t136*_t206*_t211*_t26*_t4*_t48*params->B - _t147*_t382*_t504 + 0.22e2*_t148*_t18*_t180*_t211*_t321*_t496*params->C + 0.12e2*_t148*_t206*_t211*_t4*_t573*_t9*params->C + 0.6e1*_t148*_t206*_t211*_t4*_t573*params->B - _t149*_t504*_t593 - _t158*_t509*_t598 + 0.22e2*_t163*_t26*_t50*_t69*params->C + 0.2e1*_t18*_t26*_t447*_t69*params->C + 0.6e1*_t18*_t376*_t50*_t69*params->C - _t202*_t422 - _t202*_t425 - _t202*_t426 - _t203*_t424 + 0.4e1*_t206*_t211*_t26*_t395*_t4*_t48*_t9*params->C + 0.2e1*_t206*_t211*_t26*_t395*_t4*_t48*params->B - _t219*_t705 + 0.2e1*_t25*_t4*_t702*_t9*params->C + _t25*_t4*_t702*params->B - _t330*_t441 - _t332*_t707 - _t376*_t703 - _t376*_t706 - _t378*_t691 - _t387*_t498 - _t387*_t511 - _t388*_t499 - _t388*_t513 - _t422*_t506 - _t423*_t515 - _t425*_t506 - _t426*_t506 - _t442*_t586 - _t495*_t683 - _t502*_t704 - _t518 - _t594*_t708 - 0.3e1*_t677))) + 0.3e1*_t366 + 0.3e1*_t390 + _t450;
  const double d4F_dnb4 = _hc3[14] + _t3*(my_piecewise3(_t11, 0, _t116*_t419 + _t12*(0.12e2*_hc1[1]*_hc1[2]*_t14*_t251*_t391*_t4*_t45*params->C + 0.6e1*_hc1[1]*_hc1[2]*_t251*_t391*_t4*_t45*params->B + 0.6e1*_hc1[1]*_t137*_t14*_t18*_t45*_t90*params->C + 0.3e1*_hc1[1]*_t137*_t18*_t45*_t90*params->B + 0.28e2*_hc1[1]*_t139*_t251*_t43*_t58*params->C + 0.12e2*_hc1[1]*_t14*_t144*_t18*_t43*_t90*params->C + 0.6e1*_hc1[1]*_t144*_t18*_t43*_t90*params->B + 0.6e1*_hc1[2]*_t134*_t14*_t18*_t45*_t90*params->C + 0.3e1*_hc1[2]*_t134*_t18*_t45*_t90*params->B - _t115*_t723 + 0.22e2*_t134*_t139*_t18*_t255*_t541*params->C + 0.12e2*_t134*_t14*_t144*_t251*_t255*_t4*params->C + 0.6e1*_t134*_t144*_t251*_t255*_t4*params->B - _t135*_t719 + 0.4e1*_t137*_t14*_t251*_t255*_t4*_t43*_t45*params->C + 0.2e1*_t137*_t251*_t255*_t4*_t43*_t45*params->B - _t138*_t719 + 0.22e2*_t139*_t163*_t90*params->C + 0.12e2*_t14*_t144*_t36*_t58*params->C + 0.4e1*_t14*_t251*_t255*_t396*_t4*_t43*_t45*params->C + 0.2e1*_t14*_t36*_t4*_t724*params->C - _t140*_t144*_t492 - _t140*_t411*_t495 + 0.2e1*(_t144 * _t144)*_t18*_t90*params->C + 0.2e1*_t144*_t18*_t411*_t90*params->C + 0.6e1*_t144*_t36*_t58*params->B - _t144*_t504*_t698 + 0.4e1*_t18*_t418*_t45*_t90*params->C + 0.2e1*_t18*_t45*_t90*params->C*(0.2e1*_t414 + 0.2e1*_t415 + 0.2e1*_t416 + 0.2e1*_t417 + _t694 + _t695) + 0.2e1*_t251*_t255*_t396*_t4*_t43*_t45*params->B + _t36*_t4*_t724*params->B - _t391*_t551*_t718 - _t392*_t403 - _t392*_t720 - _t394*_t403 - _t394*_t720 - _t397*_t403 - _t397*_t720 - _t398*_t403 - _t398*_t720 - _t401*_t517 - _t405*_t498 - _t405*_t549 - _t407*_t499 - _t407*_t550 - _t411*_t509*_t698 - _t412*_t721 - _t413*_t721 - _t418*_t538 - _t418*_t693 - _t45*_t553 - _t692*_t718 - _t694*_t722 - _t695*_t722 - _t723*_t97) + _t137*_t651 + _t145*_t412 + _t145*_t413 + _t273*_t712 + _t346*_t393 + _t392*_t717 + _t394*_t717 + _t396*_t651 + _t397*_t717 + _t398*_t717 + _t521*_t710 + _t523*_t713 + _t523*_t716 + _t614*_t714 + _t651*_t715) + my_piecewise3(_t6, 0, _t131*_t448 + _t159*_t441 + _t312*_t711 + _t322*_t705 + _t367*_t421 + _t422*_t731 + _t425*_t731 + _t426*_t731 + _t442*_t676 + _t457*_t726 + _t459*_t725 + _t459*_t728 + _t563*_t727 + _t667*_t670 + _t670*_t729 + _t670*_t730 + _t7*(0.12e2*_hc0[1]*_hc0[2]*_t206*_t321*_t4*_t423*_t9*params->C + 0.6e1*_hc0[1]*_hc0[2]*_t206*_t321*_t4*_t423*params->B + 0.6e1*_hc0[1]*_t136*_t18*_t50*_t69*_t9*params->C + 0.3e1*_hc0[1]*_t136*_t18*_t50*_t69*params->B + 0.28e2*_hc0[1]*_t151*_t206*_t48*_t58*params->C + 0.12e2*_hc0[1]*_t158*_t18*_t48*_t69*_t9*params->C + 0.6e1*_hc0[1]*_t158*_t18*_t48*_t69*params->B + 0.6e1*_hc0[2]*_t148*_t18*_t321*_t69*_t9*params->C + 0.3e1*_hc0[2]*_t148*_t18*_t321*_t69*params->B - _t130*_t736 + 0.4e1*_t136*_t206*_t211*_t4*_t48*_t50*_t9*params->C + 0.2e1*_t136*_t206*_t211*_t4*_t48*_t50*params->B - _t147*_t733 + 0.22e2*_t148*_t151*_t18*_t211*_t496*params->C + 0.12e2*_t148*_t206*_t211*_t4*_t675*_t9*params->C + 0.6e1*_t148*_t206*_t211*_t4*_t675*params->B - _t149*_t733 - _t150*_t736 + 0.22e2*_t151*_t163*_t69*params->C - _t154*_t158*_t492 - _t154*_t440*_t495 + 0.2e1*(_t158 * _t158)*_t18*_t69*params->C + 0.2e1*_t158*_t18*_t440*_t69*params->C + 0.12e2*_t158*_t25*_t58*_t9*params->C + 0.6e1*_t158*_t25*_t58*params->B - _t158*_t441*_t72 - _t158*_t504*_t709 + 0.4e1*_t18*_t447*_t50*_t69*params->C + 0.2e1*_t18*_t50*_t69*params->C*(0.2e1*_t443 + 0.2e1*_t444 + 0.2e1*_t445 + 0.2e1*_t446 + _t707 + _t708) + 0.4e1*_t206*_t211*_t395*_t4*_t48*_t50*_t9*params->C + 0.2e1*_t206*_t211*_t395*_t4*_t48*_t50*params->B - _t218*_t675*_t708 + 0.2e1*_t25*_t4*_t737*_t9*params->C + _t25*_t4*_t737*params->B - _t422*_t732 - _t422*_t735 - _t423*_t514*_t734 - _t424*_t673 - _t425*_t732 - _t425*_t735 - _t426*_t732 - _t426*_t735 - _t434*_t498 - _t434*_t511 - _t436*_t499 - _t436*_t513 - _t439*_t707 - _t440*_t509*_t709 - _t442*_t675*_t72 - _t447*_t703 - _t447*_t706 - _t516*_t52 - _t517*_t52*_t9 - _t674*_t705 - _t704*_t734))) + 0.4e1*_t420 + 0.4e1*_t449;
  const double d4F_dna3_dgaa = _hc2[13];
  const double d4F_dnb3_dgbb = _hc3[13];
  const double d4F_dna2_dgaa2 = _hc2[12];
  const double d4F_dnb2_dgbb2 = _hc3[12];
  const double d4F_dna_dgaa3 = _hc2[11];
  const double d4F_dnb_dgbb3 = _hc3[11];
  const double d4F_dgaa4 = _hc4[10];
  const double d4F_dgbb4 = _hc5[10];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
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