/*
  Generated from python/gga_vxc/gga_x_lb.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_lb
*/

#ifndef _GGA_X_LB_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_LB_KERNEL_BODY
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_LB_HELPER_BODIES
#include "gga_x_lb.c"
#undef _GGA_X_LB_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_LB_HELPER_BODIES
#include "gga_x_lb.c"
#undef _GGA_X_LB_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_LB_HELPER_BODIES
#include "gga_x_lb.c"
#undef _GGA_X_LB_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_LB_HELPER_BODIES
#include "gga_x_lb.c"
#undef _GGA_X_LB_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_lb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_lb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_lb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_lb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_lb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_lb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_lb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_lb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_LB_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(lb_f0_k, _KMAX)(const xc_func_type *p, double rs, double z, double x, double *out) {
  const gga_x_lb_params *params = (const gga_x_lb_params *)(p->params);

  const double _t1 = x < 0.300e3;
  const double _t2 = (x * x);
  const double _t3 = params->gamma*x;
  const double _t4 = params->beta*xc_asinh(_t3);
  const double _t5 = 0.3e1*_t4;
  const double _t6 = _t5*x + 0.1e1;
  const double _t7 = params->beta/_t6;
  const double _t8 = log(0.2e1*_t3);
  const double _t9 = (0.1e1 / 0.3e1)/_t8;
#if _KMAX >= 1
  const double _t10 = 0.2e1*_t7;
  const double _t11 = _t2*((params->gamma) * (params->gamma)) + 0.1e1;
  const double _t12 = params->beta/xc_powr(_t11, 1, 2);
  const double _t13 = _t12*_t3;
  const double _t14 = -0.3e1*_t13 - _t5;
  const double _t15 = params->beta/(_t6 * _t6);
  const double _t16 = _t15*_t2;
  const double _t17 = (0.1e1 / (_t8 * _t8));
  const double _t18 = (0.1e1 / 0.3e1)*_t17;
#endif
#if _KMAX >= 2
  const double _t19 = _t14*_t15;
  const double _t20 = _t12*params->gamma;
  const double _t21 = xc_powr(_t11, -3, 2);
  const double _t22 = ((params->gamma) * (params->gamma) * (params->gamma));
  const double _t23 = _t21*_t22;
  const double _t24 = _t2*params->beta;
  const double _t25 = _t23*_t24;
  const double _t26 = -0.6e1*_t20 + 0.3e1*_t25;
  const double _t27 = (0.1e1 / (_t6 * _t6 * _t6));
  const double _t28 = _t24*_t27;
  const double _t29 = -0.6e1*_t13 - 0.6e1*_t4;
  const double _t30 = _t14*_t29;
  const double _t31 = (0.1e1 / x);
  const double _t32 = (0.1e1 / (_t8 * _t8 * _t8));
#endif
#if _KMAX >= 3
  const double _t33 = _t15*_t26;
  const double _t34 = 0.6e1*x;
  const double _t35 = (x * x * x);
  const double _t36 = xc_powi((params->gamma), 5)/xc_powr(_t11, 5, 2);
  const double _t37 = _t35*_t36*params->beta;
  const double _t38 = 0.12e2*_t21*_t22*params->beta*x - 0.9e1*_t37;
  const double _t39 = _t27*_t30;
  const double _t40 = -0.12e2*_t20 + 0.6e1*_t25;
  const double _t41 = _t14*_t28;
  const double _t42 = _t28*_t29;
  const double _t43 = -0.9e1*_t13 - 0.9e1*_t4;
  const double _t44 = (0.1e1 / (_t6 * _t6 * _t6 * _t6));
  const double _t45 = _t24*_t30*_t44;
  const double _t46 = (0.1e1 / _t2);
  const double _t47 = (0.1e1 / (_t8 * _t8 * _t8 * _t8));
#endif
#if _KMAX >= 4
  const double _t48 = 0.8e1*x;
  const double _t49 = 0.12e2*params->beta;
  const double _t50 = _t14*_t40;
  const double _t51 = _t48*params->beta;
  const double _t52 = _t43*_t44;
  const double _t53 = 0.3e1*_t26;
  const double _t54 = _t24*_t52;
  const double _t55 = (0.1e1 / _t35);
#endif

  const double f = -my_piecewise3(_t1, _t2*_t7, _t9*x);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = -my_piecewise3(_t1, _t10*x + _t14*_t16, -_t18 + _t9);
  out[1] = df_dx;
  const double df_dz = 0;
  out[2] = df_dz;
  const double df_drs = 0;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = -my_piecewise3(_t1, _t10 + _t16*_t26 + 0.4e1*_t19*x + _t28*_t30, -_t18*_t31 + (0.2e1 / 0.3e1)*_t31*_t32);
  out[4] = d2f_dx2;
  const double d2f_dz_dx = 0;
  out[5] = d2f_dz_dx;
  const double d2f_dz2 = 0;
  out[6] = d2f_dz2;
  const double d2f_drs_dx = 0;
  out[7] = d2f_drs_dx;
  const double d2f_drs_dz = 0;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = 0;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = -my_piecewise3(_t1, _t16*_t38 + 0.6e1*_t19 + 0.2e1*_t26*_t42 + _t33*_t34 + _t34*_t39*params->beta + _t40*_t41 + _t43*_t45, _t18*_t46 - 0.2e1*_t46*_t47);
  out[10] = d3f_dx3;
  const double d3f_dz_dx2 = 0;
  out[11] = d3f_dz_dx2;
  const double d3f_dz2_dx = 0;
  out[12] = d3f_dz2_dx;
  const double d3f_dz3 = 0;
  out[13] = d3f_dz3;
  const double d3f_drs_dx2 = 0;
  out[14] = d3f_drs_dx2;
  const double d3f_drs_dz_dx = 0;
  out[15] = d3f_drs_dz_dx;
  const double d3f_drs_dz2 = 0;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dx = 0;
  out[17] = d3f_drs2_dx;
  const double d3f_drs2_dz = 0;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = 0;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = -my_piecewise3(_t1, _t15*_t38*_t48 + _t16*(_t23*_t49 - 0.63e2*_t24*_t36 + 0.45e2*params->beta*xc_powi((params->gamma), 7)*(x * x * x * x)/xc_powr(_t11, 7, 2)) + _t24*_t30*_t43*(-0.12e2*_t13 - 0.12e2*_t4)/xc_powi(_t6, 5) + 0.16e2*_t26*_t27*_t29*params->beta*x + _t27*_t50*_t51 + _t28*_t40*_t53 + _t29*_t53*_t54 + _t30*_t51*_t52 + 0.12e2*_t33 + 0.3e1*_t38*_t42 + _t39*_t49 + _t41*(0.24e2*_t21*_t22*params->beta*x - 0.18e2*_t37) + _t45*(-0.18e2*_t20 + 0.9e1*_t25) + 0.2e1*_t50*_t54, -0.2e1 / 0.3e1*_t17*_t55 - 0.2e1 / 0.3e1*_t32*_t55 + 0.4e1*_t47*_t55 + 0.8e1*_t55/xc_powi(_t8, 5));
  out[20] = d4f_dx4;
  const double d4f_dz_dx3 = 0;
  out[21] = d4f_dz_dx3;
  const double d4f_dz2_dx2 = 0;
  out[22] = d4f_dz2_dx2;
  const double d4f_dz3_dx = 0;
  out[23] = d4f_dz3_dx;
  const double d4f_dz4 = 0;
  out[24] = d4f_dz4;
  const double d4f_drs_dx3 = 0;
  out[25] = d4f_drs_dx3;
  const double d4f_drs_dz_dx2 = 0;
  out[26] = d4f_drs_dz_dx2;
  const double d4f_drs_dz2_dx = 0;
  out[27] = d4f_drs_dz2_dx;
  const double d4f_drs_dz3 = 0;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dx2 = 0;
  out[29] = d4f_drs2_dx2;
  const double d4f_drs2_dz_dx = 0;
  out[30] = d4f_drs2_dz_dx;
  const double d4f_drs2_dz2 = 0;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dx = 0;
  out[32] = d4f_drs3_dx;
  const double d4f_drs3_dz = 0;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = 0;
  out[34] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_x_lb_params *params = (const gga_x_lb_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = M_CBRT2;
  const double _t2 = xc_powr(gaa, 1, 2);
  const double _t3 = _t1*_t2;
  const double _t4 = xc_powr(0.2e1, 2, 3);
  const double _t7 = xc_powr(na, 1, 3);
  const double _t8 = (0.1e1 / 0.2e1)*_t7;
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(lb_f0_k, _KMAX)(p, 0, 0, _t3/xc_powr(na, 4, 3), _hc0);
  const double _t5 = -M_CBRT3*_t1*params->alpha/M_CBRTPI + _hc0[0];
  const double _t6 = _t4*_t5;
  const double vrho_0 = _t6*_t8;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += vrho_0;
#if _KMAX >= 2
  const double _t9 = (0.1e1 / (na * na));
  const double _t11 = xc_powr(na, -2, 3);
  const double _t12 = (0.1e1 / na);
  const double _t13 = (0.1e1 / _t2);
  const double _t10 = _hc0[1]*_t2;
  const double _t14 = _hc0[1]*_t13;
  const double v2rho2_0 = -0.4e1 / 0.3e1*_t10*_t9 + (0.1e1 / 0.6e1)*_t11*_t4*_t5;
  const double v2rhosigma_0 = (0.1e1 / 0.2e1)*_t12*_t14;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += v2rho2_0;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += v2rhosigma_0;
#endif
#if _KMAX >= 3
  const double _t15 = (0.1e1 / (na * na * na));
  const double _t17 = xc_powr(na, -14, 3);
  const double _t20 = (0.16e2 / 0.9e1)*gaa;
  const double _t22 = xc_powr(na, -10, 3);
  const double _t23 = (0.28e2 / 0.9e1)*_t22;
  const double _t25 = xc_powr(na, -11, 3);
  const double _t26 = (0.2e1 / 0.3e1)*_t25;
  const double _t27 = xc_powr(na, -7, 3);
  const double _t28 = _t1*_t27;
  const double _t30 = _t4*_t8;
  const double _t31 = xc_powr(gaa, -3, 2);
  const double _t33 = (0.1e1 / gaa);
  const double _t16 = (0.8e1 / 0.9e1)*_t10;
  const double _t18 = _hc0[4]*_t4;
  const double _t19 = _t17*_t18;
  const double _t21 = _hc0[1]*_t3;
  const double _t24 = _t19*_t20 + _t21*_t23;
  const double _t29 = -0.2e1 / 0.3e1*_t14*_t28 - _t18*_t26;
  const double _t32 = _hc0[1]*_t31;
  const double v3rho3_0 = -_t15*_t16 + (0.1e1 / 0.2e1)*_t24*_t4*_t7 - 0.1e1 / 0.9e1*_t6/xc_powr(na, 5, 3);
  const double v3rho2sigma_0 = (0.1e1 / 0.6e1)*_t14*_t9 + _t29*_t30;
  const double v3rhosigma2_0 = (0.1e1 / 0.4e1)*_hc0[4]*_t1*_t27*_t33 - 0.1e1 / 0.4e1*_t12*_t32;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += v3rho3_0;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += v3rho2sigma_0;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += v3rhosigma2_0;
#endif
#if _KMAX >= 4
  const double _t34 = _t11*_t4;
  const double _t36 = (0.4e1 / 0.3e1)*_t27*_t3;
  const double _t37 = _t1*_t22;
  const double _t38 = (0.2e1 / 0.3e1)*_t13;
  const double _t35 = _hc0[10]*_t4;
  const double _t39 = _hc0[4]*_t28;
  const double v4rho4_0 = _t16/(na * na * na * na) + (0.1e1 / 0.2e1)*_t24*_t34 + _t30*(-0.224e3 / 0.27e2*_t18*gaa/xc_powr(na, 17, 3) - 0.280e3 / 0.27e2*_t21/xc_powr(na, 13, 3) - _t36*(_hc0[4]*_t23*_t3 + _t17*_t20*_t35)) + (0.5e1 / 0.27e2)*_t6/xc_powr(na, 8, 3);
  const double v4rho3sigma_0 = -0.1e1 / 0.9e1*_t14*_t15 + (0.1e1 / 0.3e1)*_t29*_t34 + _t30*((0.14e2 / 0.9e1)*_t14*_t37 + (0.22e2 / 0.9e1)*_t19 - _t36*(-_t26*_t35 - _t38*_t39));
  const double v4rho2sigma2_0 = (0.1e1 / 0.12e2)*_hc0[4]*_t33*_t37 + _t30*((0.1e1 / 0.3e1)*_hc0[1]*_t1*_t27*_t31 - _hc0[10]*_t38/xc_powi(na, 5) - 0.1e1 / 0.3e1*_t18*_t25*_t33) - 0.1e1 / 0.12e2*_t32*_t9;
  const double v4rhosigma3_0 = (0.3e1 / 0.8e1)*_hc0[1]*_t12/xc_powr(gaa, 5, 2) + (0.1e1 / 0.8e1)*_t25*_t31*_t35 - 0.3e1 / 0.8e1*_t39/(gaa * gaa);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += v4rho4_0;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += v4rho3sigma_0;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += v4rho2sigma2_0;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += v4rhosigma3_0;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gbb = sigma[2];

  const double _t1 = xc_powr(gaa, 1, 2);
  const double _t2 = xc_powr(gbb, 1, 2);
  const double _t3 = xc_powr(na, 1, 3);
  const double _t4 = M_CBRT2*M_CBRT3*params->alpha/M_CBRTPI;
  const double _t6 = xc_powr(nb, 1, 3);
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(lb_f0_k, _KMAX)(p, 0, 0, _t1/xc_powr(na, 4, 3), _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(lb_f0_k, _KMAX)(p, 0, 0, _t2/xc_powr(nb, 4, 3), _hc1);
  const double _t5 = _hc0[0] - _t4;
  const double _t7 = _hc1[0] - _t4;
  const double vrho_0 = _t3*_t5;
  const double vrho_1 = _t6*_t7;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += vrho_0;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += vrho_1;
#if _KMAX >= 2
  const double _t8 = (0.1e1 / (na * na));
  const double _t10 = xc_powr(na, -2, 3);
  const double _t11 = (0.1e1 / (nb * nb));
  const double _t13 = xc_powr(nb, -2, 3);
  const double _t14 = (0.1e1 / na);
  const double _t15 = (0.1e1 / _t1);
  const double _t17 = (0.1e1 / nb);
  const double _t18 = (0.1e1 / _t2);
  const double _t9 = _hc0[1]*_t1;
  const double _t12 = _hc1[1]*_t2;
  const double _t16 = _hc0[1]*_t15;
  const double _t19 = _hc1[1]*_t18;
  const double v2rho2_0 = (0.1e1 / 0.3e1)*_t10*_t5 - 0.4e1 / 0.3e1*_t8*_t9;
  const double v2rho2_2 = -0.4e1 / 0.3e1*_t11*_t12 + (0.1e1 / 0.3e1)*_t13*_t7;
  const double v2rhosigma_0 = (0.1e1 / 0.2e1)*_t14*_t16;
  const double v2rhosigma_5 = (0.1e1 / 0.2e1)*_t17*_t19;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += v2rho2_0;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += v2rho2_2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += v2rhosigma_0;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += v2rhosigma_5;
#endif
#if _KMAX >= 3
  const double _t20 = (0.1e1 / (na * na * na));
  const double _t22 = xc_powr(na, -14, 3);
  const double _t24 = (0.16e2 / 0.9e1)*gaa;
  const double _t25 = xc_powr(na, -10, 3);
  const double _t26 = (0.28e2 / 0.9e1)*_t25;
  const double _t28 = (0.1e1 / (nb * nb * nb));
  const double _t30 = xc_powr(nb, -14, 3);
  const double _t32 = (0.16e2 / 0.9e1)*gbb;
  const double _t33 = xc_powr(nb, -10, 3);
  const double _t34 = (0.28e2 / 0.9e1)*_t33;
  const double _t36 = xc_powr(na, -11, 3);
  const double _t37 = (0.2e1 / 0.3e1)*_t36;
  const double _t38 = xc_powr(na, -7, 3);
  const double _t39 = (0.2e1 / 0.3e1)*_t38;
  const double _t41 = xc_powr(nb, -11, 3);
  const double _t42 = (0.2e1 / 0.3e1)*_t41;
  const double _t43 = xc_powr(nb, -7, 3);
  const double _t44 = (0.2e1 / 0.3e1)*_t43;
  const double _t46 = xc_powr(gaa, -3, 2);
  const double _t48 = (0.1e1 / gaa);
  const double _t49 = xc_powr(gbb, -3, 2);
  const double _t51 = (0.1e1 / gbb);
  const double _t21 = (0.8e1 / 0.9e1)*_t9;
  const double _t23 = _hc0[4]*_t22;
  const double _t27 = _t23*_t24 + _t26*_t9;
  const double _t29 = (0.8e1 / 0.9e1)*_t12;
  const double _t31 = _hc1[4]*_t30;
  const double _t35 = _t12*_t34 + _t31*_t32;
  const double _t40 = -_hc0[4]*_t37 - _t16*_t39;
  const double _t45 = -_hc1[4]*_t42 - _t19*_t44;
  const double _t47 = _hc0[1]*_t46;
  const double _t50 = _hc1[1]*_t49;
  const double v3rho3_0 = -_t20*_t21 + _t27*_t3 - 0.2e1 / 0.9e1*_t5/xc_powr(na, 5, 3);
  const double v3rho3_3 = -_t28*_t29 + _t35*_t6 - 0.2e1 / 0.9e1*_t7/xc_powr(nb, 5, 3);
  const double v3rho2sigma_0 = (0.1e1 / 0.6e1)*_t16*_t8 + _t3*_t40;
  const double v3rho2sigma_8 = (0.1e1 / 0.6e1)*_t11*_t19 + _t45*_t6;
  const double v3rhosigma2_0 = (0.1e1 / 0.4e1)*_hc0[4]*_t38*_t48 - 0.1e1 / 0.4e1*_t14*_t47;
  const double v3rhosigma2_11 = (0.1e1 / 0.4e1)*_hc1[4]*_t43*_t51 - 0.1e1 / 0.4e1*_t17*_t50;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += v3rho3_0;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += v3rho3_3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += v3rho2sigma_0;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += v3rho2sigma_8;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += v3rhosigma2_0;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += v3rhosigma2_11;
#endif
#if _KMAX >= 4
  const double _t52 = (0.4e1 / 0.3e1)*_t1*_t38;
  const double _t53 = (0.4e1 / 0.3e1)*_t2*_t43;
  const double _t54 = _hc0[4]*_t48;
  const double _t55 = _hc1[4]*_t51;
  const double v4rho4_0 = _t10*_t27 + _t21/(na * na * na * na) + _t3*(-0.224e3 / 0.27e2*_hc0[4]*gaa/xc_powr(na, 17, 3) - _t52*(_hc0[10]*_t22*_t24 + _hc0[4]*_t1*_t26) - 0.280e3 / 0.27e2*_t9/xc_powr(na, 13, 3)) + (0.10e2 / 0.27e2)*_t5/xc_powr(na, 8, 3);
  const double v4rho4_4 = _t13*_t35 + _t29/(nb * nb * nb * nb) + _t6*(-0.224e3 / 0.27e2*_hc1[4]*gbb/xc_powr(nb, 17, 3) - 0.280e3 / 0.27e2*_t12/xc_powr(nb, 13, 3) - _t53*(_hc1[10]*_t30*_t32 + _hc1[4]*_t2*_t34)) + (0.10e2 / 0.27e2)*_t7/xc_powr(nb, 8, 3);
  const double v4rho3sigma_0 = (0.2e1 / 0.3e1)*_t10*_t40 - 0.1e1 / 0.9e1*_t16*_t20 + _t3*((0.14e2 / 0.9e1)*_t16*_t25 + (0.22e2 / 0.9e1)*_t23 - _t52*(-_hc0[10]*_t37 - _hc0[4]*_t15*_t39));
  const double v4rho3sigma_11 = (0.2e1 / 0.3e1)*_t13*_t45 - 0.1e1 / 0.9e1*_t19*_t28 + _t6*((0.14e2 / 0.9e1)*_t19*_t33 + (0.22e2 / 0.9e1)*_t31 - _t53*(-_hc1[10]*_t42 - _hc1[4]*_t18*_t44));
  const double v4rho2sigma2_0 = (0.1e1 / 0.12e2)*_t25*_t54 + _t3*((0.1e1 / 0.3e1)*_hc0[1]*_t38*_t46 - 0.1e1 / 0.3e1*_hc0[10]*_t15/xc_powi(na, 5) - 0.1e1 / 0.3e1*_t36*_t54) - 0.1e1 / 0.12e2*_t47*_t8;
  const double v4rho2sigma2_17 = -0.1e1 / 0.12e2*_t11*_t50 + (0.1e1 / 0.12e2)*_t33*_t55 + _t6*((0.1e1 / 0.3e1)*_hc1[1]*_t43*_t49 - 0.1e1 / 0.3e1*_hc1[10]*_t18/xc_powi(nb, 5) - 0.1e1 / 0.3e1*_t41*_t55);
  const double v4rhosigma3_0 = (0.3e1 / 0.8e1)*_hc0[1]*_t14/xc_powr(gaa, 5, 2) + (0.1e1 / 0.8e1)*_hc0[10]*_t36*_t46 - 0.3e1 / 0.8e1*_hc0[4]*_t38/(gaa * gaa);
  const double v4rhosigma3_19 = (0.3e1 / 0.8e1)*_hc1[1]*_t17/xc_powr(gbb, 5, 2) + (0.1e1 / 0.8e1)*_hc1[10]*_t41*_t49 - 0.3e1 / 0.8e1*_hc1[4]*_t43/(gbb * gbb);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += v4rho4_0;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += v4rho4_4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += v4rho3sigma_0;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += v4rho3sigma_11;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += v4rho2sigma2_0;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += v4rho2sigma2_17;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += v4rhosigma3_0;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += v4rhosigma3_19;
#endif
#endif
}
#endif