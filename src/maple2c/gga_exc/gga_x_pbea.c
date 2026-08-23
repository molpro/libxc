/*
  Generated from python/gga_exc/gga_x_pbea.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_pbea
*/

#ifndef _GGA_X_PBEA_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_PBEA_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_PBEA_HELPER_BODIES
#include "gga_x_pbea.c"
#undef _GGA_X_PBEA_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_PBEA_HELPER_BODIES
#include "gga_x_pbea.c"
#undef _GGA_X_PBEA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_PBEA_HELPER_BODIES
#include "gga_x_pbea.c"
#undef _GGA_X_PBEA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_PBEA_HELPER_BODIES
#include "gga_x_pbea.c"
#undef _GGA_X_PBEA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_PBEA_HELPER_BODIES
#include "gga_x_pbea.c"
#undef _GGA_X_PBEA_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_pbea.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_pbea.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_pbea.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_pbea.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_pbea.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_pbea.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_pbea.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_pbea.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_pbea.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_pbea.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_PBEA_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_4_3_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z + 0.1e1;
  const double _t2 = _t1 <= p->zeta_threshold;

  const double f = my_piecewise3(_t2, xc_powr(p->zeta_threshold, 4, 3), xc_powr(_t1, 4, 3));
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise3(_t2, 0, (0.4e1 / 0.3e1)*xc_powr(_t1, 1, 3));
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise3(_t2, 0, (0.4e1 / 0.9e1)/xc_powr(_t1, 2, 3));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise3(_t2, 0, -(0.8e1 / 0.27e2)/xc_powr(_t1, 5, 3));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = my_piecewise3(_t2, 0, (0.40e2 / 0.81e2)/xc_powr(_t1, 8, 3));
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_spin_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_4_3_k, _KMAX)(p, z, _hc0);
  const double _t1 = xc_powr(0.6e1, 1, 3)*M_CBRT3/(M_CBRTPI*M_CBRTPI);
  const double _t2 = (0.3e1 / 0.16e2)*_t1;
  const double _t3 = _t2/rs;
#if _KMAX >= 1
  const double _t4 = _t2/(rs * rs);
#endif
#if _KMAX >= 2
  const double _t5 = _hc0[0]*_t1;
  const double _t6 = (0.3e1 / 0.8e1)/(rs * rs * rs);
#endif
#if _KMAX >= 3
  const double _t7 = _t1*_t6;
  const double _t8 = (0.9e1 / 0.8e1)/(rs * rs * rs * rs);
#endif

  const double f = -_hc0[0]*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = -_hc0[1]*_t3;
  out[1] = df_dz;
  const double df_drs = _hc0[0]*_t4;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = -_hc0[2]*_t3;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[1]*_t4;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = -_t5*_t6;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = -_hc0[3]*_t3;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc0[2]*_t4;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = -_hc0[1]*_t7;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _t5*_t8;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = -_hc0[4]*_t3;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc0[3]*_t4;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = -_hc0[2]*_t7;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc0[1]*_t1*_t8;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = -0.9e1 / 0.2e1*_t5/xc_powi(rs, 5);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbea_f_pf_k, _KMAX)(const xc_func_type *p, double x2, double *out) {

  const double _t1 = 0.0086399408095363247*x2;
  const double _t2 = xc_expm1(-0.52000000000000002*xc_log1p(_t1));
#if _KMAX >= 1
  const double _t3 = _t1 + 0.1e1;
  const double _t4 = _t2 + 0.1e1;
#endif

  const double f = 0.1e1 - 0.80400000000000005*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx2 = 0.003612186453650947*_t4/_t3;
  out[1] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dx22 = -4.7437797271880726e-5*_t4/(_t3 * _t3);
  out[2] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dx23 = 1.0328465966208597e-6*_t4/(_t3 * _t3 * _t3);
  out[3] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dx24 = -3.1411541779676145e-8*_t4/(_t3 * _t3 * _t3 * _t3);
  out[4] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = _t1/M_CBRTPI;
  const double _t3 = xc_powr(n_s, -8, 3);
  const double _t4 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t8 = xc_powr(n_s, -11, 3);
#endif
#if _KMAX >= 2
  const double _t13 = xc_powr(n_s, -16, 3);
  const double _t16 = xc_powr(n_s, -19, 3);
  const double _t18 = (0.8e1 / 0.3e1)*sigma_ss;
  const double _t19 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t21 = xc_powr(n_s, -14, 3);
  const double _t23 = xc_powr(n_s, -22, 3);
  const double _t25 = (sigma_ss * sigma_ss);
  const double _t26 = (0.64e2 / 0.9e1)*_t25;
  const double _t30 = xc_powi(n_s, -5);
  const double _t33 = (0.8e1 / 0.9e1)*sigma_ss;
#endif
#if _KMAX >= 3
  const double _t35 = xc_powi(n_s, -8);
  const double _t38 = xc_powi(n_s, -9);
  const double _t40 = xc_powr(n_s, -20, 3);
  const double _t42 = xc_powi(n_s, -10);
  const double _t45 = xc_powr(n_s, -23, 3);
  const double _t53 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t54 = (0.512e3 / 0.27e2)*_t53;
  const double _t60 = (0.2e1 / 0.9e1)*sigma_ss;
  const double _t62 = (0.32e2 / 0.9e1)*_t25;
#endif
#if _KMAX >= 4
  const double _t65 = xc_powr(n_s, -28, 3);
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t4)) XC_CAT(lda_x_spin_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t2/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pbea_f_pf_k, _KMAX)(p, _t3*sigma_ss, _hc1);
  const double _t5 = my_piecewise3(_t4, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t6 = _hc0[0]*_hc1[1];
  const double _t7 = my_piecewise3(_t4, 0, _t3*_t6);
  const double _t9 = (0.8e1 / 0.3e1)*_t6*_t8;
  const double _t10 = _hc0[2]*_t2;
  const double _t11 = (0.1e1 / 0.6e1)*_t10;
  const double _t12 = my_piecewise3(_t4, 0, -_hc1[0]*_t11/xc_powr(n_s, 4, 3) - _t9*sigma_ss);
#endif
#if _KMAX >= 2
  const double _t14 = _hc0[0]*_hc1[2];
  const double _t15 = my_piecewise3(_t4, 0, _t13*_t14);
  const double _t17 = _t14*_t16;
  const double _t20 = my_piecewise3(_t4, 0, -_hc1[1]*_t11*_t19 - _t17*_t18 - _t9);
  const double _t22 = (0.88e2 / 0.9e1)*_t21*_t6;
  const double _t24 = _t14*_t23;
  const double _t27 = (0.2e1 / 0.9e1)*_hc1[0];
  const double _t28 = (0.1e1 / 0.36e2)*_hc1[0];
  const double _t29 = xc_powr(0.6e1, 2, 3)*_hc0[5]/(M_CBRTPI * M_CBRTPI);
  const double _t31 = _hc1[1]*_t10;
  const double _t32 = _t30*_t31;
  const double _t34 = my_piecewise3(_t4, 0, _t10*_t27/xc_powr(n_s, 7, 3) + _t22*sigma_ss + _t24*_t26 + _t28*_t29*_t3 + _t32*_t33);
#endif
#if _KMAX >= 3
  const double _t36 = _hc0[0]*_hc1[3];
  const double _t37 = my_piecewise3(_t4, 0, _t35*_t36);
  const double _t39 = _t36*_t38;
  const double _t41 = my_piecewise3(_t4, 0, -_hc1[2]*_t11*_t40 - 0.16e2 / 0.3e1*_t17 - _t18*_t39);
  const double _t43 = _t36*_t42;
  const double _t44 = (0.1e1 / 0.36e2)*_hc1[1];
  const double _t46 = _hc1[2]*_t10;
  const double _t47 = _t45*_t46;
  const double _t48 = my_piecewise3(_t4, 0, _t13*_t29*_t44 + _t22 + 0.24e2*_t24*sigma_ss + _t26*_t43 + (0.10e2 / 0.9e1)*_t32 + _t33*_t47);
  const double _t49 = (0.1232e4 / 0.27e2)*_t6/xc_powr(n_s, 17, 3);
  const double _t50 = _hc0[9]/M_PI;
  const double _t51 = _t14/xc_powr(n_s, 25, 3);
  const double _t52 = _t36/xc_powi(n_s, 11);
  const double _t55 = _hc1[0]*_t10;
  const double _t56 = _hc1[0]*_t29;
  const double _t57 = _t31/xc_powi(n_s, 6);
  const double _t58 = _hc1[1]*_t29;
  const double _t59 = _t16*_t58;
  const double _t61 = _t46/xc_powr(n_s, 26, 3);
  const double _t63 = my_piecewise3(_t4, 0, -_t19*_t28*_t50 - 0.704e3 / 0.9e1*_t25*_t51 - _t49*sigma_ss - _t52*_t54 - 0.14e2 / 0.27e2*_t55/xc_powr(n_s, 10, 3) - 0.1e1 / 0.9e1*_t56*_t8 - 0.20e2 / 0.3e1*_t57*sigma_ss - _t59*_t60 - _t61*_t62);
#endif
#if _KMAX >= 4
  const double _t64 = _hc0[0]*_hc1[4];
  const double _t66 = _hc1[2]*_t29;
  const double _t67 = _hc1[3]*_t10;
#endif

  const double f = my_piecewise3(_t4, 0, _t5*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t4, 0, _t7*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t4, 0, _t12*n_s + _t5);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t4, 0, _t15*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t4, 0, _t20*n_s + _t7);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t4, 0, 0.2e1*_t12 + _t34*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t4, 0, _t37*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t4, 0, _t15 + _t41*n_s);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t4, 0, 0.2e1*_t20 + _t48*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t4, 0, 0.3e1*_t34 + _t63*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t4, 0, n_s*my_piecewise3(_t4, 0, _t64/xc_powr(n_s, 32, 3)));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t4, 0, _t37 + n_s*my_piecewise3(_t4, 0, -_hc1[3]*_t11*_t65 - _t18*_t64/xc_powr(n_s, 35, 3) - 0.8e1*_t39));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t4, 0, 0.2e1*_t41 + n_s*my_piecewise3(_t4, 0, (0.304e3 / 0.9e1)*_t24 + _t26*_t64/xc_powr(n_s, 38, 3) + _t33*_t67/xc_powr(n_s, 31, 3) + (0.1e1 / 0.36e2)*_t35*_t66 + (0.344e3 / 0.9e1)*_t43*sigma_ss + 0.2e1*_t47));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t4, 0, 0.3e1*_t48 + n_s*my_piecewise3(_t4, 0, -0.1216e4 / 0.9e1*_t25*_t52 - _t38*_t60*_t66 - _t40*_t44*_t50 - _t49 - 0.5456e4 / 0.27e2*_t51*sigma_ss - _t54*_t64/xc_powr(n_s, 41, 3) - 0.194e3 / 0.27e2*_t57 - 0.1e1 / 0.3e1*_t59 - 0.124e3 / 0.9e1*_t61*sigma_ss - _t62*_t67/xc_powr(n_s, 34, 3)));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t4, 0, 0.4e1*_t63 + n_s*my_piecewise3(_t4, 0, (0.1e1 / 0.216e3)*_hc0[14]*_hc1[0]*_t1*_t13/(M_PI * M_CBRTPI) + (0.8e1 / 0.27e2)*_hc1[1]*_t45*_t50*sigma_ss + (0.62656e5 / 0.81e2)*_t14*_t25*_t65 + (0.40e2 / 0.81e2)*_t21*_t56 + (0.76e2 / 0.27e2)*_t23*_t58*sigma_ss + (0.32e2 / 0.27e2)*_t25*_t42*_t66 + (0.1664e4 / 0.27e2)*_t25*_t46/xc_powr(n_s, 29, 3) + _t27*_t30*_t50 + (0.3968e4 / 0.81e2)*_t31*sigma_ss/xc_powi(n_s, 7) + (0.11264e5 / 0.27e2)*_t36*_t53/xc_powi(n_s, 12) + (0.20944e5 / 0.81e2)*_t40*_t6*sigma_ss + (0.1024e4 / 0.81e2)*_t53*_t67/xc_powr(n_s, 37, 3) + (0.140e3 / 0.81e2)*_t55/xc_powr(n_s, 13, 3) + (0.4096e4 / 0.81e2)*_t64*(sigma_ss * sigma_ss * sigma_ss * sigma_ss)/xc_powr(n_s, 44, 3)));
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