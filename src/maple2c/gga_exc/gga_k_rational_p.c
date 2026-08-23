/*
  Generated from python/gga_exc/gga_k_rational_p.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_k_rational_p
*/

#ifndef _GGA_K_RATIONAL_P_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_K_RATIONAL_P_KERNEL_BODY
#define _KMAX 0
#define _GGA_K_RATIONAL_P_HELPER_BODIES
#include "gga_k_rational_p.c"
#undef _GGA_K_RATIONAL_P_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_K_RATIONAL_P_HELPER_BODIES
#include "gga_k_rational_p.c"
#undef _GGA_K_RATIONAL_P_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_K_RATIONAL_P_HELPER_BODIES
#include "gga_k_rational_p.c"
#undef _GGA_K_RATIONAL_P_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_K_RATIONAL_P_HELPER_BODIES
#include "gga_k_rational_p.c"
#undef _GGA_K_RATIONAL_P_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_K_RATIONAL_P_HELPER_BODIES
#include "gga_k_rational_p.c"
#undef _GGA_K_RATIONAL_P_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_k_rational_p.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_k_rational_p.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_k_rational_p.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_k_rational_p.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_k_rational_p.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_k_rational_p.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_k_rational_p.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_k_rational_p.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_k_rational_p.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_k_rational_p.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_K_RATIONAL_P_HELPER_BODIES)

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
  const gga_k_rational_p_params *params = (const gga_k_rational_p_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n5_3_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  const double _t1 = -p->dens_threshold + n_s <= 0;
  const double _t2 = (M_PI * M_CBRTPI);
  const double _t3 = xc_powr(0.3e1, 2, 3);
  const double _t4 = params->C2*sigma_ss;
  const double _t5 = (0.1e1 / _t2);
  const double _t6 = (0.1e1 / (params->p));
  const double _t7 = _t5*_t6;
  const double _t8 = (0.1e1 / 0.24e2)*xc_powr(0.6e1, 1, 3)*_t4*_t7/xc_powr(n_s, 8, 3) + 0.1e1;
  const double _t9 = pow(_t8, -params->p);
  const double _t10 = _hc0[0] + 0.1e1;
  const double _t11 = _t10*_t9;
  const double _t12 = _t11*_t3;
  const double _t13 = _t12*_t2;
  const double _t14 = my_piecewise3(_t1, 0, (0.3e1 / 0.20e2)*_t13*xc_powr(n_s, 2, 3));
#if _KMAX >= 1
  const double _t15 = (0.1e1 / _t8);
  const double _t16 = M_CBRT2;
  const double _t17 = _t11*_t16;
  const double _t18 = _t15*_t17;
  const double _t19 = _t18*params->C2;
  const double _t20 = my_piecewise3(_t1, 0, -0.3e1 / 0.160e3*_t19/(n_s * n_s));
  const double _t21 = (0.1e1 / (n_s * n_s * n_s));
  const double _t22 = _t18*_t4;
  const double _t23 = my_piecewise3(_t1, 0, (0.1e1 / 0.10e2)*_t13/xc_powr(n_s, 1, 3) + (0.1e1 / 0.20e2)*_t21*_t22);
#endif
#if _KMAX >= 2
  const double _t24 = xc_powr(0.12e2, 1, 3);
  const double _t25 = (0.1e1 / (_t8 * _t8));
  const double _t26 = ((params->C2) * (params->C2));
  const double _t27 = _t11*_t24*_t25*_t26;
  const double _t28 = _t27*_t5;
  const double _t29 = (0.1e1 / 0.1280e4)/xc_powr(n_s, 14, 3);
  const double _t30 = _t27*_t7;
  const double _t31 = my_piecewise3(_t1, 0, _t28*_t29 + _t29*_t30);
  const double _t32 = xc_powr(n_s, -17, 3);
  const double _t33 = _t28*_t32;
  const double _t34 = (0.1e1 / 0.480e3)*sigma_ss;
  const double _t35 = _t30*_t32;
  const double _t36 = my_piecewise3(_t1, 0, (0.3e1 / 0.80e2)*_t10*_t15*_t16*_t21*_t9*params->C2 - _t33*_t34 - _t34*_t35);
  const double _t37 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t38 = xc_powr(n_s, -20, 3);
  const double _t39 = (sigma_ss * sigma_ss);
  const double _t40 = my_piecewise3(_t1, 0, (0.1e1 / 0.180e3)*_t10*_t24*_t25*_t26*_t38*_t39*_t5*_t6*_t9 + (0.1e1 / 0.180e3)*_t10*_t24*_t25*_t26*_t38*_t39*_t5*_t9 - 0.1e1 / 0.30e2*_t13/xc_powr(n_s, 4, 3) - 0.7e1 / 0.60e2*_t22*_t37);
#endif
#if _KMAX >= 3
  const double _t41 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t42 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t43 = ((params->C2) * (params->C2) * (params->C2));
  const double _t44 = _t12*_t41*_t42*_t43;
  const double _t45 = _t44/xc_powr(n_s, 22, 3);
  const double _t46 = (0.1e1 / ((params->p) * (params->p)));
  const double _t47 = my_piecewise3(_t1, 0, -0.1e1 / 0.7680e4*_t45*_t46 - 0.1e1 / 0.5120e4*_t45*_t6 - 0.1e1 / 0.15360e5*_t45);
  const double _t48 = xc_powr(n_s, -25, 3);
  const double _t49 = _t44*_t48*sigma_ss;
  const double _t50 = my_piecewise3(_t1, 0, -0.7e1 / 0.1920e4*_t33 - 0.7e1 / 0.1920e4*_t35 + (0.1e1 / 0.2880e4)*_t46*_t49 + (0.1e1 / 0.1920e4)*_t49*_t6 + (0.1e1 / 0.5760e4)*_t49);
  const double _t51 = _t44/xc_powr(n_s, 28, 3);
  const double _t52 = _t39*_t51;
  const double _t53 = my_piecewise3(_t1, 0, (0.23e2 / 0.1440e4)*_t10*_t24*_t25*_t26*_t38*_t5*_t6*_t9*sigma_ss + (0.23e2 / 0.1440e4)*_t10*_t24*_t25*_t26*_t38*_t5*_t9*sigma_ss - 0.9e1 / 0.80e2*_t19*_t37 - 0.1e1 / 0.1080e4*_t46*_t52 - 0.1e1 / 0.720e3*_t52*_t6 - 0.1e1 / 0.2160e4*_t52);
  const double _t54 = xc_powi(n_s, -5);
  const double _t55 = xc_powr(n_s, -23, 3);
  const double _t56 = _t28*_t55;
  const double _t57 = (0.1e1 / 0.20e2)*_t39;
  const double _t58 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t59 = xc_powr(n_s, -31, 3);
  const double _t60 = _t44*_t58*_t59;
  const double _t61 = _t30*_t55;
  const double _t62 = my_piecewise3(_t1, 0, (0.2e1 / 0.45e2)*_t13/xc_powr(n_s, 7, 3) + (0.41e2 / 0.90e2)*_t22*_t54 + (0.1e1 / 0.405e3)*_t46*_t60 - _t56*_t57 - _t57*_t61 + (0.1e1 / 0.270e3)*_t6*_t60 + (0.1e1 / 0.810e3)*_t60);
#endif
#if _KMAX >= 4
  const double _t63 = _t17*((params->C2) * (params->C2) * (params->C2) * (params->C2))/((M_PI * M_PI * M_PI * M_PI)*(_t8 * _t8 * _t8 * _t8));
  const double _t64 = _t63/xc_powi(n_s, 10);
  const double _t65 = (0.1e1 / ((params->p) * (params->p) * (params->p)));
  const double _t66 = (0.1e1 / 0.20480e5)*_t64;
  const double _t67 = _t63*sigma_ss/xc_powi(n_s, 11);
  const double _t68 = (0.1e1 / 0.7680e4)*_t67;
  const double _t69 = _t51*sigma_ss;
  const double _t70 = _t39*_t63/xc_powi(n_s, 12);
  const double _t71 = (0.1e1 / 0.2880e4)*_t70;
  const double _t72 = (0.257e3 / 0.2160e4)*sigma_ss;
  const double _t73 = _t58*_t63/xc_powi(n_s, 13);
  const double _t74 = (0.1e1 / 0.1080e4)*_t73;
  const double _t75 = (0.703e3 / 0.1620e4)*_t39/xc_powr(n_s, 26, 3);
  const double _t76 = _t63*(sigma_ss * sigma_ss * sigma_ss * sigma_ss)/xc_powi(n_s, 14);
  const double _t77 = _t44*_t58/xc_powr(n_s, 34, 3);
  const double _t78 = (0.1e1 / 0.405e3)*_t76;
#endif

  const double f = my_piecewise3(_t1, 0, _t14*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t1, 0, _t20*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t1, 0, _t14 + _t23*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t1, 0, _t31*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t1, 0, _t20 + _t36*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t1, 0, 0.2e1*_t23 + _t40*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t1, 0, _t47*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t1, 0, _t31 + _t50*n_s);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t1, 0, 0.2e1*_t36 + _t53*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t1, 0, 0.3e1*_t40 + _t62*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, (0.11e2 / 0.122880e6)*_t46*_t64 + _t6*_t66 + (0.1e1 / 0.122880e6)*_t64 + _t65*_t66));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t1, 0, _t47 + n_s*my_piecewise3(_t1, 0, (0.11e2 / 0.11520e5)*_t10*_t3*_t41*_t42*_t43*_t46*_t48*_t9 + (0.11e2 / 0.7680e4)*_t10*_t3*_t41*_t42*_t43*_t48*_t6*_t9 + (0.11e2 / 0.23040e5)*_t10*_t3*_t41*_t42*_t43*_t48*_t9 - 0.11e2 / 0.46080e5*_t46*_t67 - _t6*_t68 - _t65*_t68 - 0.1e1 / 0.46080e5*_t67));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t1, 0, 0.2e1*_t50 + n_s*my_piecewise3(_t1, 0, (0.119e3 / 0.5760e4)*_t28*_t38 + (0.119e3 / 0.5760e4)*_t30*_t38 - 0.13e2 / 0.2880e4*_t46*_t69 + (0.11e2 / 0.17280e5)*_t46*_t70 - 0.13e2 / 0.1920e4*_t6*_t69 + _t6*_t71 + _t65*_t71 - 0.13e2 / 0.5760e4*_t69 + (0.1e1 / 0.17280e5)*_t70));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t1, 0, 0.3e1*_t53 + n_s*my_piecewise3(_t1, 0, (0.9e1 / 0.20e2)*_t10*_t15*_t16*_t54*_t9*params->C2 + (0.17e2 / 0.1080e4)*_t10*_t3*_t39*_t41*_t42*_t43*_t46*_t59*_t9 + (0.17e2 / 0.720e3)*_t10*_t3*_t39*_t41*_t42*_t43*_t59*_t6*_t9 + (0.17e2 / 0.2160e4)*_t10*_t3*_t39*_t41*_t42*_t43*_t59*_t9 - 0.11e2 / 0.6480e4*_t46*_t73 - _t56*_t72 - _t6*_t74 - _t61*_t72 - _t65*_t74 - 0.1e1 / 0.6480e4*_t73));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t1, 0, 0.4e1*_t62 + n_s*my_piecewise3(_t1, 0, -0.14e2 / 0.135e3*_t13/xc_powr(n_s, 10, 3) - 0.611e3 / 0.270e3*_t22/xc_powi(n_s, 6) + _t28*_t75 + _t30*_t75 + (0.11e2 / 0.2430e4)*_t46*_t76 - 0.58e2 / 0.1215e4*_t46*_t77 - 0.29e2 / 0.405e3*_t6*_t77 + _t6*_t78 + _t65*_t78 + (0.1e1 / 0.2430e4)*_t76 - 0.29e2 / 0.1215e4*_t77));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_k_rational_p_params *params = (const gga_k_rational_p_params *)(p->params);
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