/*
  Generated from python/gga_exc/gga_x_2d_b88.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_2d_b88
*/

#ifndef _GGA_X_2D_B88_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_2D_B88_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_2D_B88_HELPER_BODIES
#include "gga_x_2d_b88.c"
#undef _GGA_X_2D_B88_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_2D_B88_HELPER_BODIES
#include "gga_x_2d_b88.c"
#undef _GGA_X_2D_B88_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_2D_B88_HELPER_BODIES
#include "gga_x_2d_b88.c"
#undef _GGA_X_2D_B88_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_2D_B88_HELPER_BODIES
#include "gga_x_2d_b88.c"
#undef _GGA_X_2D_B88_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_2D_B88_HELPER_BODIES
#include "gga_x_2d_b88.c"
#undef _GGA_X_2D_B88_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_2d_b88.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_2d_b88.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_2d_b88.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_2d_b88.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_2d_b88.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_2d_b88.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_2d_b88.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_2d_b88.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_2d_b88.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_2d_b88.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_2D_B88_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(_2d_b88_f_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = xc_powr(M_PI, 1, 2);
  const double _t2 = xc_asinh(x);
  const double _t3 = 0.056000000000000001*_t2;
  const double _t4 = _t3*x + 0.1e1;
  const double _t5 = _t1/_t4;
  const double _t6 = (x * x);
  const double _t7 = 0.0026250000000000002*_t6;
#if _KMAX >= 1
  const double _t8 = 0.0052500000000000003*_t5;
  const double _t9 = _t6 + 0.1e1;
  const double _t10 = xc_powr(_t9, -1, 2);
  const double _t11 = _t10*x;
  const double _t12 = -0.056000000000000001*_t11 - _t3;
  const double _t13 = _t1/(_t4 * _t4);
  const double _t14 = _t12*_t13;
#endif
#if _KMAX >= 2
  const double _t15 = 0.112*_t10;
  const double _t16 = xc_powr(_t9, -3, 2);
  const double _t17 = _t16*_t6;
  const double _t18 = -_t15 + 0.056000000000000001*_t17;
  const double _t19 = _t13*_t18;
  const double _t20 = -_t15*x - 0.112*_t2;
  const double _t21 = _t1/(_t4 * _t4 * _t4);
  const double _t22 = _t12*_t21;
  const double _t23 = _t20*_t22;
#endif
#if _KMAX >= 3
  const double _t24 = 0.01575*x;
  const double _t25 = xc_powr(_t9, -5, 2);
  const double _t26 = _t25*(x * x * x);
  const double _t27 = 0.224*_t16*x - 0.16800000000000001*_t26;
  const double _t28 = _t13*_t7;
  const double _t29 = 0.0052500000000000003*_t6;
  const double _t30 = _t18*_t21;
  const double _t31 = _t20*_t30;
  const double _t32 = 0.224*_t10;
  const double _t33 = 0.112*_t17 - _t32;
  const double _t34 = _t22*_t7;
  const double _t35 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t36 = -0.16800000000000001*_t11 - 0.16800000000000001*_t2;
  const double _t37 = _t1*_t35*_t36;
  const double _t38 = _t12*_t37;
  const double _t39 = _t20*_t7;
#endif
#if _KMAX >= 4
  const double _t40 = 0.021000000000000001*x;
  const double _t41 = 0.0078750000000000001*_t6;
  const double _t42 = _t20*_t41;
  const double _t43 = _t1*_t12*_t39;
#endif

  const double f = _t5*_t7 + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t14*_t7 + _t8*x;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 0.010500000000000001*_t14*x + _t19*_t7 + _t23*_t7 + _t8;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 0.01575*_t14 + _t19*_t24 + _t23*_t24 + _t27*_t28 + _t29*_t31 + _t33*_t34 + _t38*_t39;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = _t13*_t27*_t40 + _t18*_t37*_t42 + 0.0315*_t19 + _t20*_t38*_t40 + _t21*_t27*_t42 + _t22*_t33*_t40 + 0.0315*_t23 + _t28*(0.224*_t16 - 1.1760000000000002*_t25*_t6 + 0.84000000000000008*(x * x * x * x)/xc_powr(_t9, 7, 2)) + _t29*_t33*_t38 + _t30*_t33*_t41 + 0.042000000000000003*_t31*x + _t34*(0.44800000000000001*_t16*x - 0.33600000000000002*_t26) + _t35*_t43*(-0.33600000000000002*_t10 + 0.16800000000000001*_t17) + _t36*_t43*(-0.224*_t2 - _t32*x)/xc_powi(_t4, 5);
  out[4] = d4f_dx4;
#endif
}

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
  const double _t1 = xc_powr(n_s, -3, 2);
  const double _t2 = xc_powr(sigma_ss, 1, 2);
  const double _t3 = -p->dens_threshold + n_s <= 0;
  const double _t4 = xc_powr(n_s, 1, 2);
  const double _t5 = xc_powr(0.2e1, 1, 2);
  const double _t6 = xc_powr(M_PI, -1, 2);
  const double _t7 = _hc0[0] + 0.1e1;
  const double _t8 = _t5*_t6*_t7;
#if _KMAX >= 1
  const double _t13 = (0.1e1 / _t2);
  const double _t14 = (0.1e1 / 0.3e1)*_t13;
  const double _t16 = (0.1e1 / (n_s * n_s));
#endif
#if _KMAX >= 2
  const double _t18 = xc_powr(sigma_ss, 3, 2);
  const double _t19 = (0.1e1 / _t18);
  const double _t20 = (0.1e1 / 0.6e1)*_t19;
  const double _t21 = (0.1e1 / sigma_ss);
  const double _t22 = (0.1e1 / 0.6e1)*_t21;
  const double _t23 = xc_powr(n_s, -5, 2);
  const double _t27 = xc_powr(n_s, -7, 2);
  const double _t32 = (0.1e1 / (n_s * n_s * n_s));
#endif
#if _KMAX >= 3
  const double _t35 = (0.1e1 / 0.4e1)/xc_powr(sigma_ss, 5, 2);
  const double _t36 = (sigma_ss * sigma_ss);
  const double _t37 = (0.1e1 / _t36);
  const double _t38 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t42 = xc_powi(n_s, -5);
  const double _t47 = xc_powr(n_s, -11, 2);
#endif
#if _KMAX >= 4
  const double _t53 = xc_powr(n_s, -13, 2);
#endif
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t3)) XC_CAT(_2d_b88_f_k, _KMAX)(p, _t1*_t2, _hc1);
  const double _t9 = _hc1[0]*_t8;
  const double _t10 = my_piecewise3(_t3, 0, -0.2e1 / 0.3e1*_t4*_t9);
#if _KMAX >= 1
  const double _t11 = _hc1[1]*_t8;
  const double _t12 = _t11/n_s;
  const double _t15 = my_piecewise3(_t3, 0, -_t12*_t14);
  const double _t17 = my_piecewise3(_t3, 0, _hc1[1]*_t16*_t2*_t5*_t6*_t7 - 0.1e1 / 0.3e1*_t9/_t4);
#endif
#if _KMAX >= 2
  const double _t24 = _hc1[2]*_t8;
  const double _t25 = _t23*_t24;
  const double _t26 = my_piecewise3(_t3, 0, _t12*_t20 - _t22*_t25);
  const double _t28 = _t24*_t27;
  const double _t29 = _t11*_t16;
  const double _t30 = my_piecewise3(_t3, 0, _t14*_t29 + (0.1e1 / 0.2e1)*_t28);
  const double _t31 = _t24/xc_powr(n_s, 9, 2);
  const double _t33 = _t11*_t32;
  const double _t34 = my_piecewise3(_t3, 0, (0.1e1 / 0.6e1)*_hc1[0]*_t1*_t5*_t6*_t7 - 0.3e1 / 0.2e1*_t2*_t33 - 0.3e1 / 0.2e1*_t31*sigma_ss);
#endif
#if _KMAX >= 3
  const double _t39 = _hc1[3]*_t8;
  const double _t40 = _t38*_t39;
  const double _t41 = my_piecewise3(_t3, 0, (0.1e1 / 0.4e1)*_hc1[2]*_t23*_t37*_t5*_t6*_t7 - _t12*_t35 - 0.1e1 / 0.12e2*_t19*_t40);
  const double _t43 = _t39*_t42;
  const double _t44 = my_piecewise3(_t3, 0, (0.1e1 / 0.4e1)*_t13*_t43 - _t20*_t29 + _t22*_t28);
  const double _t45 = _t39/xc_powi(n_s, 6);
  const double _t46 = my_piecewise3(_t3, 0, -0.2e1 / 0.3e1*_t13*_t33 - 0.3e1 / 0.4e1*_t2*_t45 - 0.9e1 / 0.4e1*_t31);
  const double _t48 = _t24*_t47;
  const double _t49 = _t11*_t38;
  const double _t50 = _t39/xc_powi(n_s, 7);
  const double _t51 = my_piecewise3(_t3, 0, (0.9e1 / 0.4e1)*_t18*_t50 + (0.17e2 / 0.4e1)*_t2*_t49 - 0.1e1 / 0.4e1*_t23*_t9 + 0.9e1*_t48*sigma_ss);
#endif
#if _KMAX >= 4
  const double _t52 = _hc1[4]*_t8;
#endif

  const double f = my_piecewise3(_t3, 0, _t10*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t3, 0, _t15*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t3, 0, _t10 + _t17*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t3, 0, _t26*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t3, 0, _t15 + _t30*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t3, 0, 0.2e1*_t17 + _t34*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t3, 0, _t41*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t3, 0, _t26 + _t44*n_s);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t3, 0, 0.2e1*_t30 + _t46*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t3, 0, 0.3e1*_t34 + _t51*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, (0.5e1 / 0.8e1)*_t12/xc_powr(sigma_ss, 7, 2) - 0.5e1 / 0.8e1*_t25/(sigma_ss * sigma_ss * sigma_ss) + _t35*_t40 - 0.1e1 / 0.24e2*_t37*_t47*_t52));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t3, 0, _t41 + n_s*my_piecewise3(_t3, 0, -0.1e1 / 0.24e2*_t19*_t43 + (0.1e1 / 0.8e1)*_t21*_t52*_t53 - 0.1e1 / 0.4e1*_t28*_t37 + _t29*_t35));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t3, 0, 0.2e1*_t44 + n_s*my_piecewise3(_t3, 0, (0.1e1 / 0.3e1)*_hc1[1]*_t19*_t32*_t5*_t6*_t7 - 0.3e1 / 0.2e1*_t13*_t45 - 0.1e1 / 0.3e1*_t21*_t31 - 0.3e1 / 0.8e1*_t52/xc_powr(n_s, 15, 2)));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t3, 0, 0.3e1*_t46 + n_s*my_piecewise3(_t3, 0, 0.2e1*_t13*_t49 + (0.63e2 / 0.8e1)*_t2*_t50 + (0.89e2 / 0.8e1)*_t48 + (0.9e1 / 0.8e1)*_t52*sigma_ss/xc_powr(n_s, 17, 2)));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t3, 0, 0.4e1*_t51 + n_s*my_piecewise3(_t3, 0, (0.5e1 / 0.8e1)*_hc1[0]*_t27*_t5*_t6*_t7 - 0.133e3 / 0.8e1*_t11*_t2*_t42 - 0.117e3 / 0.4e1*_t18*_t39/xc_powi(n_s, 8) - 0.447e3 / 0.8e1*_t24*_t53*sigma_ss - 0.27e2 / 0.8e1*_t36*_t52/xc_powr(n_s, 19, 2)));
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