/*
  Generated from python/mgga_exc/mgga_x_gdme.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_gdme
*/

#ifndef _MGGA_X_GDME_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_GDME_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_GDME_HELPER_BODIES
#include "mgga_x_gdme.c"
#undef _MGGA_X_GDME_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_GDME_HELPER_BODIES
#include "mgga_x_gdme.c"
#undef _MGGA_X_GDME_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_GDME_HELPER_BODIES
#include "mgga_x_gdme.c"
#undef _MGGA_X_GDME_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_GDME_HELPER_BODIES
#include "mgga_x_gdme.c"
#undef _MGGA_X_GDME_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_GDME_HELPER_BODIES
#include "mgga_x_gdme.c"
#undef _MGGA_X_GDME_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_gdme.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_gdme.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_gdme.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_gdme.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_gdme.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_gdme.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_gdme.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_gdme.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_gdme.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_gdme.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_GDME_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(gdme_f_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double t, double *out) {
  const mgga_x_gdme_params *params = (const mgga_x_gdme_params *)(p->params);

  const double _t1 = M_CBRTPI/M_CBRT3;
  const double _t2 = ((params->a) * (params->a)) - params->a + 0.1e1 / 0.2e1;
  const double _t3 = M_CBRT2*xc_powr(0.3e1, 2, 3)*_t1*params->BB/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t4 = (0.2e1 / 0.27e2)*_t3;

  const double f = (0.4e1 / 0.9e1)*M_CBRT3*_t1*(params->AA + (0.3e1 / 0.5e1)*params->BB)/(M_PI * M_CBRTPI) + _t4*(_t2*u - 0.2e1*t);
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -0.4e1 / 0.27e2*_t3;
  out[1] = df_dt;
  const double df_du = _t2*_t4;
  out[2] = df_du;
  const double df_dx2 = 0;
  out[3] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dx2_dt = 0;
  out[7] = d2f_dx2_dt;
  const double d2f_dx2_du = 0;
  out[8] = d2f_dx2_du;
  const double d2f_dx22 = 0;
  out[9] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[13] = d3f_du3;
  const double d3f_dx2_dt2 = 0;
  out[14] = d3f_dx2_dt2;
  const double d3f_dx2_du_dt = 0;
  out[15] = d3f_dx2_du_dt;
  const double d3f_dx2_du2 = 0;
  out[16] = d3f_dx2_du2;
  const double d3f_dx22_dt = 0;
  out[17] = d3f_dx22_dt;
  const double d3f_dx22_du = 0;
  out[18] = d3f_dx22_du;
  const double d3f_dx23 = 0;
  out[19] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[24] = d4f_du4;
  const double d4f_dx2_dt3 = 0;
  out[25] = d4f_dx2_dt3;
  const double d4f_dx2_du_dt2 = 0;
  out[26] = d4f_dx2_du_dt2;
  const double d4f_dx2_du2_dt = 0;
  out[27] = d4f_dx2_du2_dt;
  const double d4f_dx2_du3 = 0;
  out[28] = d4f_dx2_du3;
  const double d4f_dx22_dt2 = 0;
  out[29] = d4f_dx22_dt2;
  const double d4f_dx22_du_dt = 0;
  out[30] = d4f_dx22_du_dt;
  const double d4f_dx22_du2 = 0;
  out[31] = d4f_dx22_du2;
  const double d4f_dx23_dt = 0;
  out[32] = d4f_dx23_dt;
  const double d4f_dx23_du = 0;
  out[33] = d4f_dx23_du;
  const double d4f_dx24 = 0;
  out[34] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {
  const mgga_x_gdme_params *params = (const mgga_x_gdme_params *)(p->params);

  const double _t1 = xc_powr(n_s, -5, 3);
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = (0.1e1 / 0.2e1)*_t4;
  const double _t6 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t11 = xc_powr(n_s, -4, 3);
  const double _t14 = xc_powr(n_s, -8, 3);
  const double _t15 = (0.5e1 / 0.3e1)*_t14;
#endif
#if _KMAX >= 2
  const double _t25 = xc_powr(n_s, -7, 3);
  const double _t28 = xc_powr(0.6e1, 2, 3);
  const double _t29 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t32 = xc_powr(n_s, -11, 3);
  const double _t33 = (0.40e2 / 0.9e1)*_t32;
#endif
#if _KMAX >= 3
  const double _t39 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t40 = (0.7e1 / 0.9e1)*_t39;
  const double _t42 = xc_powr(n_s, -13, 3);
  const double _t50 = xc_powr(n_s, -10, 3);
  const double _t53 = xc_powr(n_s, -14, 3);
  const double _t54 = (0.440e3 / 0.27e2)*_t53;
#endif
#if _KMAX >= 4
  const double _t58 = xc_powr(n_s, -17, 3);
  const double _t60 = xc_powi(n_s, -5);
  const double _t61 = (0.104e3 / 0.27e2)*_t60;
  const double _t62 = xc_powr(n_s, -16, 3);
  const double _t64 = (0.6160e4 / 0.81e2)*_t58;
#endif
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(gdme_f_pf_k, _KMAX)(p, 0, _t1*lapl_s, _t1*tau_s, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t6)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t5/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc1);
  const double _t7 = my_piecewise3(_t6, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t8 = _hc1[0]*_t1;
  const double _t9 = my_piecewise3(_t6, 0, _hc0[1]*_t8);
  const double _t10 = my_piecewise3(_t6, 0, _hc0[2]*_t8);
  const double _t12 = _hc1[2]*_t4;
  const double _t13 = (0.1e1 / 0.6e1)*_t12;
  const double _t16 = _hc0[1]*tau_s;
  const double _t17 = _hc0[2]*_t15;
  const double _t18 = -_t15*_t16 - _t17*lapl_s;
  const double _t19 = my_piecewise3(_t6, 0, -_hc0[0]*_t11*_t13 + _hc1[0]*_t18);
#endif
#if _KMAX >= 2
  const double _t20 = _hc0[1]*_hc1[0];
  const double _t21 = _t13/(n_s * n_s * n_s);
  const double _t22 = my_piecewise3(_t6, 0, -_hc0[1]*_t21 - _t15*_t20);
  const double _t23 = my_piecewise3(_t6, 0, -_hc0[2]*_t21 - _hc1[0]*_t17);
  const double _t24 = (0.2e1 / 0.9e1)*_hc0[0];
  const double _t26 = _t12*_t25;
  const double _t27 = (0.1e1 / 0.36e2)*_hc0[0];
  const double _t30 = _hc1[5]*_t28*_t29;
  const double _t31 = _t14*_t30;
  const double _t34 = _hc0[2]*_t33;
  const double _t35 = _t16*_t33 + _t34*lapl_s;
  const double _t36 = _t12*_t18;
  const double _t37 = my_piecewise3(_t6, 0, _hc1[0]*_t35 - 0.1e1 / 0.3e1*_t11*_t36 + _t24*_t26 + _t27*_t31);
#endif
#if _KMAX >= 3
  const double _t38 = _hc0[1]*_t12;
  const double _t41 = (0.1e1 / 0.36e2)*_hc0[1];
  const double _t43 = _t30*_t42;
  const double _t44 = my_piecewise3(_t6, 0, _t20*_t33 + _t38*_t40 + _t41*_t43);
  const double _t45 = _hc0[2]*_t12;
  const double _t46 = (0.1e1 / 0.36e2)*_hc0[2];
  const double _t47 = my_piecewise3(_t6, 0, _hc1[0]*_t34 + _t40*_t45 + _t43*_t46);
  const double _t48 = _hc1[9]/M_PI;
  const double _t49 = _t39*_t48;
  const double _t51 = _hc0[0]*_t12;
  const double _t52 = _t30*_t32;
  const double _t55 = _hc0[2]*_t54;
  const double _t56 = -_t16*_t54 - _t55*lapl_s;
  const double _t57 = my_piecewise3(_t6, 0, -0.1e1 / 0.9e1*_hc0[0]*_t52 + _hc1[0]*_t56 - _hc1[2]*_t11*_t35*_t5 + (0.2e1 / 0.3e1)*_hc1[2]*_t18*_t2*_t25*_t3 + (0.1e1 / 0.12e2)*_hc1[5]*_t14*_t18*_t28*_t29 - _t27*_t49 - 0.14e2 / 0.27e2*_t50*_t51);
#endif
#if _KMAX >= 4
  const double _t59 = _t48*_t58;
  const double _t63 = (0.1e1 / 0.4e1)*_t30*_t62;
#endif

  const double f = my_piecewise3(_t6, 0, _t7*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t6, 0, _t9*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = my_piecewise3(_t6, 0, _t10*n_s);
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = 0;
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t6, 0, _t19*n_s + _t7);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = 0;
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = 0;
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = 0;
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = 0;
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = 0;
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t6, 0, _t22*n_s + _t9);
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = my_piecewise3(_t6, 0, _t10 + _t23*n_s);
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = 0;
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t6, 0, 0.2e1*_t19 + _t37*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = 0;
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = 0;
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = 0;
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = 0;
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = 0;
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = 0;
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = 0;
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = 0;
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = 0;
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = 0;
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = 0;
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = 0;
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t6, 0, 0.2e1*_t22 + _t44*n_s);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = my_piecewise3(_t6, 0, 0.2e1*_t23 + _t47*n_s);
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = 0;
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t6, 0, 0.3e1*_t37 + _t57*n_s);
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
  const double d4f_dlapl_s4 = 0;
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = 0;
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = 0;
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = 0;
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = 0;
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = 0;
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = 0;
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = 0;
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = 0;
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = 0;
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = 0;
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = 0;
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = 0;
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = 0;
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = 0;
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = 0;
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = 0;
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = 0;
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = 0;
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = 0;
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t6, 0, 0.3e1*_t44 + n_s*my_piecewise3(_t6, 0, -_hc0[1]*_t63 - _t20*_t54 - _t38*_t61 - _t41*_t59));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = my_piecewise3(_t6, 0, 0.3e1*_t47 + n_s*my_piecewise3(_t6, 0, -_hc0[2]*_t63 - _hc1[0]*_t55 - _t45*_t61 - _t46*_t59));
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = 0;
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t6, 0, 0.4e1*_t57 + n_s*my_piecewise3(_t6, 0, (0.1e1 / 0.216e3)*_hc0[0]*_hc1[14]*_t2*_t62/(M_PI * M_CBRTPI) + (0.40e2 / 0.81e2)*_hc0[0]*_t30*_t53 + _hc1[0]*(_hc0[2]*_t64*lapl_s + _t16*_t64) - 0.2e1 / 0.3e1*_t11*_t12*_t56 - 0.1e1 / 0.9e1*_t18*_t49 - 0.4e1 / 0.9e1*_t18*_t52 + _t24*_t48*_t60 + (0.4e1 / 0.3e1)*_t26*_t35 + (0.1e1 / 0.6e1)*_t31*_t35 - 0.56e2 / 0.27e2*_t36*_t50 + (0.140e3 / 0.81e2)*_t42*_t51));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_gdme_params *params = (const mgga_x_gdme_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double ta = tau[0];

  const double _t1 = (0.1e1 / 0.2e1)*na;
  const double _t2 = (0.1e1 / 0.2e1)*la;
  const double _t3 = (0.1e1 / 0.2e1)*ta;
  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, 0, _t2, _t3, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, 0, 0, 0, _hc1);
  const double dF_dna = _hc0[4];
  const double dF_dla = _hc1[2];
  const double dF_dta = _hc1[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  double _hc2[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, (0.1e1 / 0.4e1)*gaa, _t2, _t3, _hc2);
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc2[14];
  const double d2F_dna_dla = (0.1e1 / 0.2e1)*_hc0[12];
  const double d2F_dna_dta = (0.1e1 / 0.2e1)*_hc0[11];
  const double d2F_dla2 = (0.1e1 / 0.2e1)*_hc1[7];
  const double d2F_dla_dta = (0.1e1 / 0.2e1)*_hc1[6];
  const double d2F_dta2 = (0.1e1 / 0.2e1)*_hc1[5];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
  if(out->v2lapltau != NULL) out->v2lapltau[ip*p->dim.v2lapltau + 0] += d2F_dla_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc2[34];
  const double d3F_dna2_dla = (0.1e1 / 0.4e1)*_hc2[32];
  const double d3F_dna2_dta = (0.1e1 / 0.4e1)*_hc2[31];
  const double d3F_dna_dla2 = (0.1e1 / 0.4e1)*_hc0[27];
  const double d3F_dna_dla_dta = (0.1e1 / 0.4e1)*_hc0[26];
  const double d3F_dna_dta2 = (0.1e1 / 0.4e1)*_hc0[25];
  const double d3F_dla3 = (0.1e1 / 0.4e1)*_hc1[18];
  const double d3F_dla2_dta = (0.1e1 / 0.4e1)*_hc1[17];
  const double d3F_dla_dta2 = (0.1e1 / 0.4e1)*_hc1[16];
  const double d3F_dta3 = (0.1e1 / 0.4e1)*_hc1[15];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 0] += d3F_dna_dla_dta;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
  if(out->v3lapl2tau != NULL) out->v3lapl2tau[ip*p->dim.v3lapl2tau + 0] += d3F_dla2_dta;
  if(out->v3lapltau2 != NULL) out->v3lapltau2[ip*p->dim.v3lapltau2 + 0] += d3F_dla_dta2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc2[69];
  const double d4F_dna3_dla = (0.1e1 / 0.8e1)*_hc2[67];
  const double d4F_dna3_dta = (0.1e1 / 0.8e1)*_hc2[66];
  const double d4F_dna2_dla2 = (0.1e1 / 0.8e1)*_hc2[62];
  const double d4F_dna2_dla_dta = (0.1e1 / 0.8e1)*_hc2[61];
  const double d4F_dna2_dta2 = (0.1e1 / 0.8e1)*_hc2[60];
  const double d4F_dna_dla3 = (0.1e1 / 0.8e1)*_hc0[53];
  const double d4F_dna_dla2_dta = (0.1e1 / 0.8e1)*_hc0[52];
  const double d4F_dna_dla_dta2 = (0.1e1 / 0.8e1)*_hc0[51];
  const double d4F_dna_dta3 = (0.1e1 / 0.8e1)*_hc0[50];
  const double d4F_dla4 = (0.1e1 / 0.8e1)*_hc1[39];
  const double d4F_dla3_dta = (0.1e1 / 0.8e1)*_hc1[38];
  const double d4F_dla2_dta2 = (0.1e1 / 0.8e1)*_hc1[37];
  const double d4F_dla_dta3 = (0.1e1 / 0.8e1)*_hc1[36];
  const double d4F_dta4 = (0.1e1 / 0.8e1)*_hc1[35];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 0] += d4F_dna2_dla_dta;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 0] += d4F_dna_dla2_dta;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 0] += d4F_dna_dla_dta2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 0] += d4F_dla4;
  if(out->v4lapl3tau != NULL) out->v4lapl3tau[ip*p->dim.v4lapl3tau + 0] += d4F_dla3_dta;
  if(out->v4lapl2tau2 != NULL) out->v4lapl2tau2[ip*p->dim.v4lapl2tau2 + 0] += d4F_dla2_dta2;
  if(out->v4lapltau3 != NULL) out->v4lapltau3[ip*p->dim.v4lapltau3 + 0] += d4F_dla_dta3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gbb = sigma[2];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double lb = (lapl != NULL) ? lapl[1] : 0.0;
  const double ta = tau[0];
  const double tb = tau[1];

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, 0, la, ta, _hc0);
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, 0, lb, tb, _hc1);
  const double zk = (_hc0[0] + _hc1[0])/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  double _hc2[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, 0, 0, 0, _hc2);
  double _hc3[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, 0, 0, 0, _hc3);
  const double dF_dna = _hc0[4];
  const double dF_dnb = _hc1[4];
  const double dF_dla = _hc2[2];
  const double dF_dlb = _hc3[2];
  const double dF_dta = _hc2[1];
  const double dF_dtb = _hc3[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 1] += dF_dlb;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 1] += dF_dtb;
#endif
#if _KMAX >= 2
  double _hc4[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, la, ta, _hc4);
  double _hc5[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, lb, tb, _hc5);
  const double d2F_dna2 = _hc4[14];
  const double d2F_dnb2 = _hc5[14];
  const double d2F_dna_dla = _hc0[12];
  const double d2F_dnb_dlb = _hc1[12];
  const double d2F_dna_dta = _hc0[11];
  const double d2F_dnb_dtb = _hc1[11];
  const double d2F_dla2 = _hc2[7];
  const double d2F_dlb2 = _hc3[7];
  const double d2F_dla_dta = _hc2[6];
  const double d2F_dlb_dtb = _hc3[6];
  const double d2F_dta2 = _hc2[5];
  const double d2F_dtb2 = _hc3[5];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 3] += d2F_dnb_dlb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 3] += d2F_dnb_dtb;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 2] += d2F_dlb2;
  if(out->v2lapltau != NULL) out->v2lapltau[ip*p->dim.v2lapltau + 0] += d2F_dla_dta;
  if(out->v2lapltau != NULL) out->v2lapltau[ip*p->dim.v2lapltau + 3] += d2F_dlb_dtb;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 2] += d2F_dtb2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = _hc4[34];
  const double d3F_dnb3 = _hc5[34];
  const double d3F_dna2_dla = _hc4[32];
  const double d3F_dnb2_dlb = _hc5[32];
  const double d3F_dna2_dta = _hc4[31];
  const double d3F_dnb2_dtb = _hc5[31];
  const double d3F_dna_dla2 = _hc0[27];
  const double d3F_dnb_dlb2 = _hc1[27];
  const double d3F_dna_dla_dta = _hc0[26];
  const double d3F_dnb_dlb_dtb = _hc1[26];
  const double d3F_dna_dta2 = _hc0[25];
  const double d3F_dnb_dtb2 = _hc1[25];
  const double d3F_dla3 = _hc2[18];
  const double d3F_dlb3 = _hc3[18];
  const double d3F_dla2_dta = _hc2[17];
  const double d3F_dlb2_dtb = _hc3[17];
  const double d3F_dla_dta2 = _hc2[16];
  const double d3F_dlb_dtb2 = _hc3[16];
  const double d3F_dta3 = _hc2[15];
  const double d3F_dtb3 = _hc3[15];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 5] += d3F_dnb2_dlb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 5] += d3F_dnb2_dtb;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 5] += d3F_dnb_dlb2;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 0] += d3F_dna_dla_dta;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 7] += d3F_dnb_dlb_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 5] += d3F_dnb_dtb2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 3] += d3F_dlb3;
  if(out->v3lapl2tau != NULL) out->v3lapl2tau[ip*p->dim.v3lapl2tau + 0] += d3F_dla2_dta;
  if(out->v3lapl2tau != NULL) out->v3lapl2tau[ip*p->dim.v3lapl2tau + 5] += d3F_dlb2_dtb;
  if(out->v3lapltau2 != NULL) out->v3lapltau2[ip*p->dim.v3lapltau2 + 0] += d3F_dla_dta2;
  if(out->v3lapltau2 != NULL) out->v3lapltau2[ip*p->dim.v3lapltau2 + 5] += d3F_dlb_dtb2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 3] += d3F_dtb3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = _hc4[69];
  const double d4F_dnb4 = _hc5[69];
  const double d4F_dna3_dla = _hc4[67];
  const double d4F_dnb3_dlb = _hc5[67];
  const double d4F_dna3_dta = _hc4[66];
  const double d4F_dnb3_dtb = _hc5[66];
  const double d4F_dna2_dla2 = _hc4[62];
  const double d4F_dnb2_dlb2 = _hc5[62];
  const double d4F_dna2_dla_dta = _hc4[61];
  const double d4F_dnb2_dlb_dtb = _hc5[61];
  const double d4F_dna2_dta2 = _hc4[60];
  const double d4F_dnb2_dtb2 = _hc5[60];
  const double d4F_dna_dla3 = _hc0[53];
  const double d4F_dnb_dlb3 = _hc1[53];
  const double d4F_dna_dla2_dta = _hc0[52];
  const double d4F_dnb_dlb2_dtb = _hc1[52];
  const double d4F_dna_dla_dta2 = _hc0[51];
  const double d4F_dnb_dlb_dtb2 = _hc1[51];
  const double d4F_dna_dta3 = _hc0[50];
  const double d4F_dnb_dtb3 = _hc1[50];
  const double d4F_dla4 = _hc2[39];
  const double d4F_dlb4 = _hc3[39];
  const double d4F_dla3_dta = _hc2[38];
  const double d4F_dlb3_dtb = _hc3[38];
  const double d4F_dla2_dta2 = _hc2[37];
  const double d4F_dlb2_dtb2 = _hc3[37];
  const double d4F_dla_dta3 = _hc2[36];
  const double d4F_dlb_dtb3 = _hc3[36];
  const double d4F_dta4 = _hc2[35];
  const double d4F_dtb4 = _hc3[35];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 7] += d4F_dnb3_dlb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 7] += d4F_dnb3_dtb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 8] += d4F_dnb2_dlb2;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 0] += d4F_dna2_dla_dta;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 11] += d4F_dnb2_dlb_dtb;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 8] += d4F_dnb2_dtb2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 7] += d4F_dnb_dlb3;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 0] += d4F_dna_dla2_dta;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 11] += d4F_dnb_dlb2_dtb;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 0] += d4F_dna_dla_dta2;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 11] += d4F_dnb_dlb_dtb2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 7] += d4F_dnb_dtb3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 0] += d4F_dla4;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 4] += d4F_dlb4;
  if(out->v4lapl3tau != NULL) out->v4lapl3tau[ip*p->dim.v4lapl3tau + 0] += d4F_dla3_dta;
  if(out->v4lapl3tau != NULL) out->v4lapl3tau[ip*p->dim.v4lapl3tau + 7] += d4F_dlb3_dtb;
  if(out->v4lapl2tau2 != NULL) out->v4lapl2tau2[ip*p->dim.v4lapl2tau2 + 0] += d4F_dla2_dta2;
  if(out->v4lapl2tau2 != NULL) out->v4lapl2tau2[ip*p->dim.v4lapl2tau2 + 8] += d4F_dlb2_dtb2;
  if(out->v4lapltau3 != NULL) out->v4lapltau3[ip*p->dim.v4lapltau3 + 0] += d4F_dla_dta3;
  if(out->v4lapltau3 != NULL) out->v4lapltau3[ip*p->dim.v4lapltau3 + 7] += d4F_dlb_dtb3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 4] += d4F_dtb4;
#endif
#endif
}
#endif