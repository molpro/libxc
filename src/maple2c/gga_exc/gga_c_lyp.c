/*
  Generated from python/gga_exc/gga_c_lyp.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_lyp
*/

#ifndef _GGA_C_LYP_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_LYP_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_LYP_HELPER_BODIES
#include "gga_c_lyp.c"
#undef _GGA_C_LYP_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_LYP_HELPER_BODIES
#include "gga_c_lyp.c"
#undef _GGA_C_LYP_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_LYP_HELPER_BODIES
#include "gga_c_lyp.c"
#undef _GGA_C_LYP_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_LYP_HELPER_BODIES
#include "gga_c_lyp.c"
#undef _GGA_C_LYP_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_LYP_HELPER_BODIES
#include "gga_c_lyp.c"
#undef _GGA_C_LYP_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_lyp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_lyp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_lyp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_lyp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_lyp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_lyp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_lyp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_lyp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_lyp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_lyp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_LYP_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_m1_k, _KMAX)(const xc_func_type *p, double z, double n, double *out) {

  const double _t1 = z + 0.1e1 <= p->zeta_threshold;
  const double _t2 = pow(p->zeta_threshold, n);
  const double _t3 = p->zeta_threshold - 0.1e1;
  const double _t4 = z > _t3;
  const double _t5 = my_piecewise3(_t4, z, _t3);
  const double _t6 = xc_log1p(_t5);
  const double _t7 = _t6*n;
  const double _t8 = xc_expm1(_t7);
#if _KMAX >= 1
  const double _t9 = log(p->zeta_threshold);
  const double _t10 = _t8 + 0.1e1;
  const double _t11 = _t10*_t6;
  const double _t12 = _t5 + 0.1e1;
  const double _t13 = my_piecewise3(_t4, 0.1e1, 0);
  const double _t14 = _t13/_t12;
  const double _t15 = _t10*_t14;
#endif
#if _KMAX >= 2
  const double _t16 = _t10*(_t6 * _t6);
  const double _t17 = (_t13 * _t13)/(_t12 * _t12);
  const double _t18 = _t10*_t17;
  const double _t19 = _t18*n;
  const double _t20 = (n * n);
#endif
#if _KMAX >= 3
  const double _t21 = _t10*(_t6 * _t6 * _t6);
  const double _t22 = 0.2e1*_t11;
  const double _t23 = _t14*_t16;
  const double _t24 = _t18*_t7;
  const double _t25 = _t17*_t20;
  const double _t26 = (_t13 * _t13 * _t13)/(_t12 * _t12 * _t12);
  const double _t27 = _t10*_t26;
  const double _t28 = 0.2e1*_t27;
  const double _t29 = (n * n * n);
  const double _t30 = _t10*_t29;
  const double _t31 = 0.3e1*_t20;
  const double _t32 = _t27*_t31;
#endif
#if _KMAX >= 4
  const double _t33 = 0.6e1*n;
  const double _t34 = _t11*_t26;
  const double _t35 = (_t13 * _t13 * _t13 * _t13)/(_t12 * _t12 * _t12 * _t12);
  const double _t36 = _t10*_t35;
#endif

  const double f = my_piecewise3(_t1, _t2 - 0.1e1, _t8);
  out[0] = f;
#if _KMAX >= 1
  const double df_dn = my_piecewise3(_t1, _t2*_t9, _t11);
  out[1] = df_dn;
  const double df_dz = my_piecewise3(_t1, 0, _t15*n);
  out[2] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dn2 = my_piecewise3(_t1, _t2*(_t9 * _t9), _t16);
  out[3] = d2f_dn2;
  const double d2f_dz_dn = my_piecewise3(_t1, 0, _t15*_t7 + _t15);
  out[4] = d2f_dz_dn;
  const double d2f_dz2 = my_piecewise3(_t1, 0, _t18*_t20 - _t19);
  out[5] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dn3 = my_piecewise3(_t1, _t2*(_t9 * _t9 * _t9), _t21);
  out[6] = d3f_dn3;
  const double d3f_dz_dn2 = my_piecewise3(_t1, 0, _t14*_t22 + _t23*n);
  out[7] = d3f_dz_dn2;
  const double d3f_dz2_dn = my_piecewise3(_t1, 0, _t11*_t25 - _t18 + 0.2e1*_t19 - _t24);
  out[8] = d3f_dz2_dn;
  const double d3f_dz3 = my_piecewise3(_t1, 0, _t26*_t30 + _t28*n - _t32);
  out[9] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dn4 = my_piecewise3(_t1, _t2*(_t9 * _t9 * _t9 * _t9), _t10*(_t6 * _t6 * _t6 * _t6));
  out[10] = d4f_dn4;
  const double d4f_dz_dn3 = my_piecewise3(_t1, 0, _t14*_t21*n + 0.3e1*_t23);
  out[11] = d4f_dz_dn3;
  const double d4f_dz2_dn2 = my_piecewise3(_t1, 0, -_t16*_t17*n + _t16*_t25 - _t17*_t22 + 0.2e1*_t18 + 0.4e1*_t24);
  out[12] = d4f_dz2_dn2;
  const double d4f_dz3_dn = my_piecewise3(_t1, 0, -_t27*_t33 + _t28*_t7 + _t28 + _t29*_t34 - _t31*_t34 + _t32);
  out[13] = d4f_dz3_dn;
  const double d4f_dz4 = my_piecewise3(_t1, 0, 0.11e2*_t20*_t36 - 0.6e1*_t30*_t35 - _t33*_t36 + _t36*(n * n * n * n));
  out[14] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lyp_omega_k, _KMAX)(const xc_func_type *p, double rr, double *out) {
  const gga_c_lyp_params *params = (const gga_c_lyp_params *)(p->params);

  const double _t1 = params->d*rr + 0.1e1;
  const double _t2 = params->b*exp(-params->c*rr);
  const double _t3 = _t2/_t1;
#if _KMAX >= 1
  const double _t4 = _t2*params->d/(_t1 * _t1);
#endif
#if _KMAX >= 2
  const double _t5 = ((params->c) * (params->c));
  const double _t6 = _t2*((params->d) * (params->d))/(_t1 * _t1 * _t1);
#endif
#if _KMAX >= 3
  const double _t7 = ((params->c) * (params->c) * (params->c));
  const double _t8 = _t2*((params->d) * (params->d) * (params->d))/(_t1 * _t1 * _t1 * _t1);
#endif

  const double f = _t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_drr = -_t3*params->c - _t4;
  out[1] = df_drr;
#endif
#if _KMAX >= 2
  const double d2f_drr2 = _t3*_t5 + 0.2e1*_t4*params->c + 0.2e1*_t6;
  out[2] = d2f_drr2;
#endif
#if _KMAX >= 3
  const double d3f_drr3 = -_t3*_t7 - 0.3e1*_t4*_t5 - 0.6e1*_t6*params->c - 0.6e1*_t8;
  out[3] = d3f_drr3;
#endif
#if _KMAX >= 4
  const double d4f_drr4 = _t3*((params->c) * (params->c) * (params->c) * (params->c)) + 0.4e1*_t4*_t7 + 0.12e2*_t5*_t6 + 0.24e2*_t8*params->c + 0.24e2*_t2*((params->d) * (params->d) * (params->d) * (params->d))/xc_powi(_t1, 5);
  out[4] = d4f_drr4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lyp_delta_k, _KMAX)(const xc_func_type *p, double rr, double *out) {
  const gga_c_lyp_params *params = (const gga_c_lyp_params *)(p->params);

  const double _t1 = params->d*rr + 0.1e1;
  const double _t2 = params->c + params->d/_t1;
#if _KMAX >= 1
  const double _t3 = ((params->d) * (params->d))/(_t1 * _t1);
#endif
#if _KMAX >= 2
  const double _t4 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t5 = ((params->d) * (params->d) * (params->d));
#endif
#if _KMAX >= 3
  const double _t6 = ((params->d) * (params->d) * (params->d) * (params->d))/(_t1 * _t1 * _t1 * _t1);
#endif

  const double f = _t2*rr;
  out[0] = f;
#if _KMAX >= 1
  const double df_drr = _t2 - _t3*rr;
  out[1] = df_drr;
#endif
#if _KMAX >= 2
  const double d2f_drr2 = -0.2e1*_t3 + 0.2e1*_t4*_t5*rr;
  out[2] = d2f_drr2;
#endif
#if _KMAX >= 3
  const double d3f_drr3 = 0.6e1*_t4*_t5 - 0.6e1*_t6*rr;
  out[3] = d3f_drr3;
#endif
#if _KMAX >= 4
  const double d4f_drr4 = -0.24e2*_t6 + 0.24e2*xc_powi((params->d), 5)*rr/xc_powi(_t1, 5);
  out[4] = d4f_drr4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lyp_t6_k, _KMAX)(const xc_func_type *p, double z, double xs02, double xs12, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.8e1 / 0.3e1, _hc0);
  const double _t1 = -z;
  const double _t2 = _hc0[0] + 0.1e1;
  const double _t9 = (0.1e1 / 0.8e1)*M_CBRT2;
#if _KMAX >= 2
  const double _t13 = (0.1e1 / 0.4e1)*_t2;
  const double _t14 = (0.2e1 / 0.3e1)*_hc0[5];
#endif
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t1, 0.8e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t1, 0.2e1, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1, _hc3);
  const double _t3 = _hc1[0] + 0.1e1;
  const double _t4 = (0.1e1 / 0.4e1)*_hc2[0] + 0.1e1 / 0.4e1;
  const double _t5 = _t2*_t4;
  const double _t6 = _hc3[0] + 0.1e1;
  const double _t7 = (0.1e1 / 0.4e1)*_t3;
  const double _t8 = _t6*_t7;
#if _KMAX >= 1
  const double _t10 = (0.2e1 / 0.3e1)*_hc1[2];
  const double _t11 = _hc0[2]*_t4;
  const double _t12 = _hc3[2]*_t7;
#endif
#if _KMAX >= 2
  const double _t15 = (0.2e1 / 0.3e1)*_hc1[5];
  const double _t16 = (0.1e1 / 0.2e1)*_hc0[2]*_hc2[2];
  const double _t17 = (0.1e1 / 0.2e1)*_hc1[2]*_hc3[2];
  const double _t18 = _hc0[5]*_t4;
  const double _t19 = (0.1e1 / 0.4e1)*_t6;
  const double _t20 = _hc1[5]*_t19;
  const double _t21 = _hc2[5]*_t13;
  const double _t22 = _hc3[5]*_t7;
#endif
#if _KMAX >= 3
  const double _t23 = (0.2e1 / 0.3e1)*_hc1[9];
  const double _t24 = (0.3e1 / 0.4e1)*_hc0[2]*_hc2[5];
  const double _t25 = (0.3e1 / 0.4e1)*_hc1[5]*_hc3[2];
  const double _t26 = _hc0[9]*_t4;
  const double _t27 = _hc3[9]*_t7;
#endif

  const double f = -_t9*((0.2e1 / 0.3e1)*_t2*xs02 + (0.2e1 / 0.3e1)*_t3*xs12 - _t5*xs02 - _t8*xs12);
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs12 = -_t9*((0.2e1 / 0.3e1)*_hc1[0] - _t8 + 0.2e1 / 0.3e1);
  out[1] = df_dxs12;
  const double df_dxs02 = -_t9*((0.2e1 / 0.3e1)*_hc0[0] - _t5 + 0.2e1 / 0.3e1);
  out[2] = df_dxs02;
  const double df_dz = -_t9*((0.2e1 / 0.3e1)*_hc0[2]*xs02 + (0.1e1 / 0.4e1)*_hc1[2]*_t6*xs12 + (0.1e1 / 0.4e1)*_hc2[2]*_t2*xs02 - _t10*xs12 - _t11*xs02 - _t12*xs12);
  out[3] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dxs122 = 0;
  out[4] = d2f_dxs122;
  const double d2f_dxs02_dxs12 = 0;
  out[5] = d2f_dxs02_dxs12;
  const double d2f_dxs022 = 0;
  out[6] = d2f_dxs022;
  const double d2f_dz_dxs12 = -_t9*((0.1e1 / 0.4e1)*_hc1[2]*_t6 - _t10 - _t12);
  out[7] = d2f_dz_dxs12;
  const double d2f_dz_dxs02 = -_t9*((0.2e1 / 0.3e1)*_hc0[2] + _hc2[2]*_t13 - _t11);
  out[8] = d2f_dz_dxs02;
  const double d2f_dz2 = -_t9*(_t14*xs02 + _t15*xs12 + _t16*xs02 + _t17*xs12 - _t18*xs02 - _t20*xs12 - _t21*xs02 - _t22*xs12);
  out[9] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dxs123 = 0;
  out[10] = d3f_dxs123;
  const double d3f_dxs02_dxs122 = 0;
  out[11] = d3f_dxs02_dxs122;
  const double d3f_dxs022_dxs12 = 0;
  out[12] = d3f_dxs022_dxs12;
  const double d3f_dxs023 = 0;
  out[13] = d3f_dxs023;
  const double d3f_dz_dxs122 = 0;
  out[14] = d3f_dz_dxs122;
  const double d3f_dz_dxs02_dxs12 = 0;
  out[15] = d3f_dz_dxs02_dxs12;
  const double d3f_dz_dxs022 = 0;
  out[16] = d3f_dz_dxs022;
  const double d3f_dz2_dxs12 = -_t9*(_t15 + _t17 - _t20 - _t22);
  out[17] = d3f_dz2_dxs12;
  const double d3f_dz2_dxs02 = -_t9*(_t14 + _t16 - _t18 - _t21);
  out[18] = d3f_dz2_dxs02;
  const double d3f_dz3 = -_t9*((0.3e1 / 0.4e1)*_hc0[5]*_hc2[2]*xs02 + (0.2e1 / 0.3e1)*_hc0[9]*xs02 + (0.3e1 / 0.4e1)*_hc1[2]*_hc3[5]*xs12 + (0.1e1 / 0.4e1)*_hc1[9]*_t6*xs12 + (0.1e1 / 0.4e1)*_hc2[9]*_t2*xs02 - _t23*xs12 - _t24*xs02 - _t25*xs12 - _t26*xs02 - _t27*xs12);
  out[19] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dxs124 = 0;
  out[20] = d4f_dxs124;
  const double d4f_dxs02_dxs123 = 0;
  out[21] = d4f_dxs02_dxs123;
  const double d4f_dxs022_dxs122 = 0;
  out[22] = d4f_dxs022_dxs122;
  const double d4f_dxs023_dxs12 = 0;
  out[23] = d4f_dxs023_dxs12;
  const double d4f_dxs024 = 0;
  out[24] = d4f_dxs024;
  const double d4f_dz_dxs123 = 0;
  out[25] = d4f_dz_dxs123;
  const double d4f_dz_dxs02_dxs122 = 0;
  out[26] = d4f_dz_dxs02_dxs122;
  const double d4f_dz_dxs022_dxs12 = 0;
  out[27] = d4f_dz_dxs022_dxs12;
  const double d4f_dz_dxs023 = 0;
  out[28] = d4f_dz_dxs023;
  const double d4f_dz2_dxs122 = 0;
  out[29] = d4f_dz2_dxs122;
  const double d4f_dz2_dxs02_dxs12 = 0;
  out[30] = d4f_dz2_dxs02_dxs12;
  const double d4f_dz2_dxs022 = 0;
  out[31] = d4f_dz2_dxs022;
  const double d4f_dz3_dxs12 = -_t9*((0.3e1 / 0.4e1)*_hc1[2]*_hc3[5] + (0.1e1 / 0.4e1)*_hc1[9]*_t6 - _t23 - _t25 - _t27);
  out[32] = d4f_dz3_dxs12;
  const double d4f_dz3_dxs02 = -_t9*((0.3e1 / 0.4e1)*_hc0[5]*_hc2[2] + (0.2e1 / 0.3e1)*_hc0[9] + _hc2[9]*_t13 - _t24 - _t26);
  out[33] = d4f_dz3_dxs02;
  const double d4f_dz4 = -_t9*(-_hc0[14]*_t4*xs02 + (0.2e1 / 0.3e1)*_hc0[14]*xs02 + _hc0[2]*_hc2[9]*xs02 - 0.3e1 / 0.2e1*_hc0[5]*_hc2[5]*xs02 + _hc0[9]*_hc2[2]*xs02 - _hc1[14]*_t19*xs12 + (0.2e1 / 0.3e1)*_hc1[14]*xs12 + _hc1[2]*_hc3[9]*xs12 - 0.3e1 / 0.2e1*_hc1[5]*_hc3[5]*xs12 + _hc1[9]*_hc3[2]*xs12 - _hc2[14]*_t13*xs02 - _hc3[14]*_t7*xs12);
  out[34] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lyp_t6_z0_k, _KMAX)(const xc_func_type *p, double xs02, double xs12, double *out) {

  const double _t1 = M_CBRT2;
#if _KMAX >= 1
  const double _t2 = -0.5e1 / 0.96e2*_t1;
#endif

  const double f = -0.1e1 / 0.8e1*_t1*((0.5e1 / 0.12e2)*xs02 + (0.5e1 / 0.12e2)*xs12);
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs12 = _t2;
  out[1] = df_dxs12;
  const double df_dxs02 = _t2;
  out[2] = df_dxs02;
#endif
#if _KMAX >= 2
  const double d2f_dxs122 = 0;
  out[3] = d2f_dxs122;
  const double d2f_dxs02_dxs12 = 0;
  out[4] = d2f_dxs02_dxs12;
  const double d2f_dxs022 = 0;
  out[5] = d2f_dxs022;
#endif
#if _KMAX >= 3
  const double d3f_dxs123 = 0;
  out[6] = d3f_dxs123;
  const double d3f_dxs02_dxs122 = 0;
  out[7] = d3f_dxs02_dxs122;
  const double d3f_dxs022_dxs12 = 0;
  out[8] = d3f_dxs022_dxs12;
  const double d3f_dxs023 = 0;
  out[9] = d3f_dxs023;
#endif
#if _KMAX >= 4
  const double d4f_dxs124 = 0;
  out[10] = d4f_dxs124;
  const double d4f_dxs02_dxs123 = 0;
  out[11] = d4f_dxs02_dxs123;
  const double d4f_dxs022_dxs122 = 0;
  out[12] = d4f_dxs022_dxs122;
  const double d4f_dxs023_dxs12 = 0;
  out[13] = d4f_dxs023_dxs12;
  const double d4f_dxs024 = 0;
  out[14] = d4f_dxs024;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_c_lyp_params *params = (const gga_c_lyp_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = xc_powr(na, -1, 3);
  const double _t2 = xc_powr(na, -8, 3);
  const double _t3 = xc_powr(0.2e1, 2, 3);
  const double _t4 = _t2*_t3;
  const double _t5 = _t4*gaa;
  const double _t6 = _t1*params->d + 0.1e1;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lyp_delta_k, _KMAX)(p, _t1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lyp_t6_z0_k, _KMAX)(p, _t5, _t5, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lyp_omega_k, _KMAX)(p, _t1, _hc2);
  const double _t7 = _hc0[0] - 0.11e2;
  const double _t8 = (0.1e1 / 0.144e3)*_t2*_t7;
  const double _t9 = 0.5e1 / 0.2e1 - 0.1e1 / 0.18e2*_hc0[0];
  const double _t10 = (0.1e1 / 0.8e1)*_t2*_t9;
  const double _t11 = -0.7e1 / 0.72e2*_hc0[0] - 0.1e1 / 0.72e2;
  const double _t12 = _t11*_t2;
  const double _t13 = _hc1[0] + _t10*gaa - _t12*gaa + _t8*gaa - 0.3e1 / 0.10e2*xc_powr(0.3e1, 2, 3)*(M_PI * M_CBRTPI);
  const double _t14 = params->a*(_hc2[0]*_t13 - 0.1e1/_t6);
  const double zk = _t14;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t15 = xc_powr(na, -4, 3);
  const double _t16 = params->d/(_t6 * _t6);
  const double _t19 = (0.1e1 / (na * na * na * na));
  const double _t21 = xc_powr(na, -11, 3);
  const double _t23 = (0.8e1 / 0.3e1)*_t21*_t3;
  const double _t29 = na*params->a;
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lyp_t6_z0_k, _KMAX)(p, 0, 0, _hc3);
  const double _t17 = _hc2[1]*_t15;
  const double _t18 = (0.1e1 / 0.3e1)*_t17;
  const double _t20 = (0.7e1 / 0.216e3)*_hc0[1]*_t19;
  const double _t22 = (0.1e1 / 0.54e2)*_t21*_t7;
  const double _t24 = _hc3[1]*_t23;
  const double _t25 = _hc3[2]*_t23;
  const double _t26 = (0.1e1 / 0.3e1)*_t21*_t9;
  const double _t27 = (0.8e1 / 0.3e1)*_t11*_t21*gaa - _t20*gaa - _t22*gaa - _t24*gaa - _t25*gaa - _t26*gaa;
  const double _t28 = params->a*(_hc2[0]*_t27 - _t13*_t18 - 0.1e1 / 0.3e1*_t15*_t16);
  const double _t30 = _hc3[1]*_t4 + _hc3[2]*_t4 + _t10 - _t12 + _t8;
  const double _t31 = _hc2[0]*_t30;
  const double dF_dna = _t14 + _t28*na;
  const double dF_dgaa = _t29*_t31;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t32 = xc_powr(na, -7, 3);
  const double _t33 = (0.4e1 / 0.9e1)*_t32;
  const double _t34 = (0.1e1 / (_t6 * _t6 * _t6));
  const double _t35 = ((params->d) * (params->d));
  const double _t36 = _t34*_t35;
  const double _t39 = (0.1e1 / 0.9e1)*_t2;
  const double _t41 = xc_powi(na, -5);
  const double _t43 = xc_powr(na, -16, 3);
  const double _t45 = xc_powr(na, -14, 3);
  const double _t47 = (0.88e2 / 0.9e1)*_t45;
  const double _t48 = _t3*_t47;
  const double _t37 = _hc2[1]*_t13;
  const double _t38 = _hc2[2]*_t13;
  const double _t40 = (0.2e1 / 0.3e1)*_t17;
  const double _t42 = (0.35e2 / 0.162e3)*_hc0[1]*_t41;
  const double _t44 = (0.7e1 / 0.648e3)*_hc0[2]*_t43;
  const double _t46 = (0.11e2 / 0.162e3)*_t45*_t7;
  const double _t49 = _hc3[1]*_t48;
  const double _t50 = _hc3[2]*_t48;
  const double _t51 = (0.11e2 / 0.9e1)*_t45*_t9;
  const double _t52 = _t11*_t47;
  const double _t53 = _t42*gaa + _t44*gaa + _t46*gaa + _t49*gaa + _t50*gaa + _t51*gaa - _t52*gaa;
  const double _t54 = _hc2[0]*_t53 + _t16*_t33 - 0.2e1 / 0.9e1*_t2*_t36 - _t27*_t40 + _t33*_t37 + _t38*_t39;
  const double _t55 = (0.8e1 / 0.3e1)*_t11*_t21 - _t20 - _t22 - _t24 - _t25 - _t26;
  const double _t56 = _hc2[0]*_t55 - _t18*_t30;
  const double d2F_dna2 = 0.2e1*_t28 + _t29*_t54;
  const double d2F_dna_dgaa = _t29*_t56 + _t31*params->a;
  const double d2F_dgaa2 = 0;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t57 = 0.3e1*params->a;
  const double _t58 = xc_powr(na, -10, 3);
  const double _t59 = (0.28e2 / 0.27e2)*_t58;
  const double _t60 = ((params->d) * (params->d) * (params->d))/(_t6 * _t6 * _t6 * _t6);
  const double _t61 = (0.4e1 / 0.9e1)*_t21;
  const double _t66 = xc_powr(na, -20, 3);
  const double _t68 = xc_powr(na, -17, 3);
  const double _t70 = (0.1232e4 / 0.27e2)*_t3*_t68;
  const double _t62 = _hc2[3]*_t19;
  const double _t63 = (0.1e1 / 0.27e2)*_t62;
  const double _t64 = (0.679e3 / 0.486e3)*_hc0[1]/xc_powi(na, 6);
  const double _t65 = (0.7e1 / 0.54e2)*_hc0[2]/xc_powr(na, 19, 3);
  const double _t67 = (0.7e1 / 0.1944e4)*_hc0[3]*_t66;
  const double _t69 = (0.77e2 / 0.243e3)*_t68*_t7;
  const double _t71 = _hc3[1]*_t70;
  const double _t72 = _hc3[2]*_t70;
  const double _t73 = (0.154e3 / 0.27e2)*_t68*_t9;
  const double _t74 = (0.1232e4 / 0.27e2)*_t11*_t68*gaa - _t64*gaa - _t65*gaa - _t67*gaa - _t69*gaa - _t71*gaa - _t72*gaa - _t73*gaa;
  const double _t75 = _hc2[0]*_t74 + (0.4e1 / 0.3e1)*_hc2[1]*_t27*_t32 + (0.1e1 / 0.3e1)*_hc2[2]*_t2*_t27 - _t13*_t63 - _t16*_t59 - _t17*_t53 - 0.2e1 / 0.9e1*_t19*_t60 + (0.8e1 / 0.9e1)*_t21*_t34*_t35 - _t37*_t59 - _t38*_t61;
  const double _t76 = _hc2[1]*_t30;
  const double _t77 = _hc2[2]*_t30;
  const double _t78 = _t42 + _t44 + _t46 + _t49 + _t50 + _t51 - _t52;
  const double _t79 = _hc2[0]*_t78 + _t33*_t76 + _t39*_t77 - _t40*_t55;
  const double d3F_dna3 = _t29*_t75 + _t54*_t57;
  const double d3F_dna2_dgaa = _t29*_t79 + 0.2e1*_t56*params->a;
  const double d3F_dna_dgaa2 = 0;
  const double d3F_dgaa3 = 0;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t80 = (0.280e3 / 0.81e2)/xc_powr(na, 13, 3);
  const double _t81 = _t66*gaa;
  const double _t82 = (0.20944e5 / 0.81e2)*_t81;
  const double _t83 = _t3*_t82;
  const double d4F_dna4 = _t29*(_hc2[0]*((0.7189e4 / 0.729e3)*_hc0[1]*gaa/xc_powi(na, 7) + (0.938e3 / 0.729e3)*_hc0[2]*gaa/xc_powr(na, 22, 3) + (0.49e2 / 0.729e3)*_hc0[3]*gaa/xc_powr(na, 23, 3) + (0.7e1 / 0.5832e4)*_hc0[4]*gaa/xc_powi(na, 8) + _hc3[1]*_t83 + _hc3[2]*_t83 - _t11*_t82 + (0.1309e4 / 0.729e3)*_t7*_t81 + (0.2618e4 / 0.81e2)*_t81*_t9) - 0.112e3 / 0.27e2*_hc2[1]*_t27*_t58 + (0.8e1 / 0.3e1)*_hc2[1]*_t32*_t53 + (0.2e1 / 0.3e1)*_hc2[2]*_t2*_t53 - 0.16e2 / 0.9e1*_hc2[2]*_t21*_t27 + (0.8e1 / 0.27e2)*_hc2[3]*_t13*_t41 + (0.1e1 / 0.81e2)*_hc2[4]*_t13*_t43 + _t16*_t80 - 0.4e1 / 0.3e1*_t17*_t74 - 0.4e1 / 0.27e2*_t27*_t62 - 0.320e3 / 0.81e2*_t36*_t45 + _t37*_t80 + (0.160e3 / 0.81e2)*_t38*_t45 + (0.16e2 / 0.9e1)*_t41*_t60 - 0.8e1 / 0.27e2*_t43*((params->d) * (params->d) * (params->d) * (params->d))/xc_powi(_t6, 5)) + 0.4e1*_t75*params->a;
  const double d4F_dna3_dgaa = _t29*(_hc2[0]*((0.1232e4 / 0.27e2)*_t11*_t68 - _t64 - _t65 - _t67 - _t69 - _t71 - _t72 - _t73) + (0.4e1 / 0.3e1)*_hc2[1]*_t32*_t55 + (0.1e1 / 0.3e1)*_hc2[2]*_t2*_t55 - _t17*_t78 - _t30*_t63 - _t59*_t76 - _t61*_t77) + _t57*_t79;
  const double d4F_dna2_dgaa2 = 0;
  const double d4F_dna_dgaa3 = 0;
  const double d4F_dgaa4 = 0;
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
  const double gab = sigma[1];
  const double gbb = sigma[2];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(_t1, -1, 3);
  const double _t3 = na - nb;
  const double _t4 = (0.1e1 / _t1);
  const double _t5 = _t3*_t4;
  const double _t6 = -_t5;
  const double _t7 = xc_powr(na, -8, 3);
  const double _t8 = _t7*gaa;
  const double _t9 = xc_powr(nb, -8, 3);
  const double _t10 = _t9*gbb;
  const double _t11 = _t2*params->d + 0.1e1;
  const double _t12 = (0.1e1 / _t11);
  const double _t13 = (0.1e1 / (_t1 * _t1));
  const double _t14 = 0.4e1*_t13;
  const double _t15 = _t12*_t14;
  const double _t16 = _t15*nb;
  const double _t18 = xc_powr(0.3e1, 2, 3)*(M_PI * M_CBRTPI);
  const double _t19 = _t13*_t18;
  const double _t20 = (0.3e1 / 0.5e1)*_t19;
  const double _t22 = na*nb;
  const double _t23 = gaa + 0.2e1*gab + gbb;
  const double _t24 = xc_powr(_t1, -8, 3);
  const double _t31 = M_CBRT2;
  const double _t36 = (0.1e1 / 0.144e3)*_t13;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lyp_delta_k, _KMAX)(p, _t2, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t5, 0.8e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t6, 0.8e1 / 0.3e1, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t5, 0.11e2 / 0.3e1, _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t6, 0.11e2 / 0.3e1, _hc4);
  double _hc5[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(lyp_t6_k, _KMAX)(p, _t5, _t8, _t10, _hc5);
  double _hc6[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lyp_omega_k, _KMAX)(p, _t2, _hc6);
  const double _t17 = _hc1[0] + _hc2[0] + 0.2e1;
  const double _t21 = _t17*_t20;
  const double _t25 = 0.47e2 - 0.7e1*_hc0[0];
  const double _t26 = (0.1e1 / 0.18e2)*_t13*_t25;
  const double _t27 = _t26*nb;
  const double _t28 = _t27*na - 0.2e1 / 0.3e1;
  const double _t29 = _t24*_t28;
  const double _t30 = _hc0[0] - 0.11e2;
  const double _t32 = _hc3[0] + 0.1e1;
  const double _t33 = _hc4[0] + 0.1e1;
  const double _t34 = _t31*(_t10*_t33 + _t32*_t8);
  const double _t35 = _t30*_t34;
  const double _t37 = _t35*_t36;
  const double _t38 = _hc1[0] + 0.1e1;
  const double _t39 = _hc2[0] + 0.1e1;
  const double _t40 = _t10*_t39 + _t38*_t8;
  const double _t41 = _t31*(0.5e1 / 0.2e1 - 0.1e1 / 0.18e2*_hc0[0]);
  const double _t42 = _t13*_t41;
  const double _t43 = (0.1e1 / 0.8e1)*_t42;
  const double _t44 = _t40*_t43;
  const double _t45 = _hc5[0] - _t21*_t22 + _t22*_t37 + _t22*_t44 - _t23*_t29;
  const double _t46 = params->a*(_hc6[0]*_t45 - _t16*na);
  const double zk = _t46;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t47 = -_t4;
  const double _t48 = _t13*_t3;
  const double _t49 = _t47 + _t48;
  const double _t50 = -_t49;
  const double _t51 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t55 = xc_powr(_t1, -10, 3);
  const double _t60 = xc_powr(na, -11, 3);
  const double _t61 = (0.8e1 / 0.3e1)*_t60;
  const double _t66 = _t20*_t22;
  const double _t75 = _t31*_t36;
  const double _t76 = _t22*_t75;
  const double _t77 = xc_powr(_t1, -11, 3);
  const double _t94 = (0.1e1 / (_t11 * _t11));
  const double _t95 = _t94*params->d;
  const double _t96 = _t55*_t95;
  const double _t97 = (0.4e1 / 0.3e1)*_t96;
  const double _t98 = _t97*na;
  const double _t101 = _t4 + _t48;
  const double _t102 = -_t101;
  const double _t105 = xc_powr(nb, -11, 3);
  const double _t106 = (0.8e1 / 0.3e1)*_t105;
  const double _t120 = xc_powr(na, -5, 3);
  const double _t130 = xc_powr(nb, -5, 3);
  double _hc7[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(lyp_t6_k, _KMAX)(p, _t5, 0, 0, _hc7);
  const double _t52 = _t25*_t51;
  const double _t53 = (0.1e1 / 0.9e1)*_t52;
  const double _t54 = _t53*na;
  const double _t56 = _hc0[1]*_t55;
  const double _t57 = -_t54*nb + (0.7e1 / 0.54e2)*_t56*na*nb;
  const double _t58 = _t27 + _t57;
  const double _t59 = _t24*_t58;
  const double _t62 = _hc7[2]*_t61;
  const double _t63 = _hc1[2]*_t50;
  const double _t64 = _hc2[2]*_t49;
  const double _t65 = _t63 + _t64;
  const double _t67 = _t38*_t61;
  const double _t68 = _t10*_t64 + _t63*_t8 - _t67*gaa;
  const double _t69 = _t22*_t43;
  const double _t70 = _t32*_t61;
  const double _t71 = _hc3[2]*_t8;
  const double _t72 = _hc4[2]*_t10;
  const double _t73 = _t49*_t72 + _t50*_t71 - _t70*gaa;
  const double _t74 = _t30*_t73;
  const double _t78 = (0.8e1 / 0.3e1)*_t28*_t77;
  const double _t79 = _t41*_t51;
  const double _t80 = _t40*_t79;
  const double _t81 = (0.1e1 / 0.4e1)*_t80;
  const double _t82 = _t35*_t51;
  const double _t83 = (0.1e1 / 0.72e2)*_t82;
  const double _t84 = (0.1e1 / 0.432e3)*_t56;
  const double _t85 = _t22*_t84;
  const double _t86 = _t31*_t40;
  const double _t87 = _t17*_t18;
  const double _t88 = _t51*_t87;
  const double _t89 = (0.6e1 / 0.5e1)*_t88;
  const double _t90 = -_t22*_t81 - _t22*_t83 + _t22*_t89 + _t23*_t78 - _t34*_t85 + _t85*_t86;
  const double _t91 = _hc5[3]*_t50 - _t21*nb - _t23*_t59 + _t37*nb + _t44*nb - _t62*gaa - _t65*_t66 + _t68*_t69 + _t74*_t76 + _t90;
  const double _t92 = _hc6[1]/xc_powr(_t1, 4, 3);
  const double _t93 = (0.1e1 / 0.3e1)*_t92;
  const double _t99 = -0.8e1*_t12*_t51*na*nb + _t45*_t93 + _t98*nb;
  const double _t100 = params->a*(_hc6[0]*_t91 - _t16 - _t99);
  const double _t103 = _t26*na + _t57;
  const double _t104 = _t103*_t24;
  const double _t107 = _hc7[1]*_t106;
  const double _t108 = _hc2[2]*_t101;
  const double _t109 = _hc1[2]*_t102;
  const double _t110 = _t108 + _t109;
  const double _t111 = _t106*_t39;
  const double _t112 = _t10*_t108 + _t109*_t8 - _t111*gbb;
  const double _t113 = _t106*_t33;
  const double _t114 = _t101*_t72 + _t102*_t71 - _t113*gbb;
  const double _t115 = _t114*_t30;
  const double _t116 = _hc5[3]*_t102 - _t104*_t23 - _t107*gbb - _t110*_t66 + _t112*_t69 + _t115*_t76 - _t21*na + _t37*na + _t44*na + _t90;
  const double _t117 = params->a*(_hc6[0]*_t116 - _t15*na - _t99);
  const double _t118 = _t30*_t31;
  const double _t119 = _t118*_t36;
  const double _t121 = _t120*_t32;
  const double _t122 = _t119*_t121;
  const double _t123 = _t120*_t38;
  const double _t124 = _t123*_t43;
  const double _t125 = -_t29;
  const double _t126 = _hc7[2]*_t7 + _t122*nb + _t124*nb + _t125;
  const double _t127 = _hc6[0]*params->a;
  const double _t128 = _t126*_t127;
  const double _t129 = 0.2e1*_t127;
  const double _t131 = _t130*_t33;
  const double _t132 = _t119*_t131;
  const double _t133 = _t43*na;
  const double _t134 = _t130*_t39;
  const double _t135 = _hc7[1]*_t9 + _t125 + _t132*na + _t133*_t134;
  const double _t136 = _t127*_t135;
  const double dF_dna = _t1*_t100 + _t46;
  const double dF_dnb = _t1*_t117 + _t46;
  const double dF_dgaa = _t1*_t128;
  const double dF_dgab = -_t129*_t28/xc_powr(_t1, 5, 3);
  const double dF_dgbb = _t1*_t136;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t137 = 0.2e1*_t13;
  const double _t138 = 0.2e1*_t51;
  const double _t139 = _t138*_t3;
  const double _t140 = -_t137 + _t139;
  const double _t145 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t146 = xc_powr(_t1, -14, 3);
  const double _t150 = xc_powr(_t1, -13, 3);
  const double _t159 = xc_powr(na, -14, 3);
  const double _t160 = (0.88e2 / 0.9e1)*_t159;
  const double _t162 = (0.6e1 / 0.5e1)*_t19;
  const double _t170 = (0.1e1 / 0.72e2)*_t31;
  const double _t171 = _t13*_t170;
  const double _t176 = (_t50 * _t50);
  const double _t178 = -_t140;
  const double _t180 = (_t49 * _t49);
  const double _t185 = _t31*_t51;
  const double _t191 = (0.16e2 / 0.3e1)*_t60;
  const double _t203 = _t18*_t51;
  const double _t221 = 0.16e2*_t12*_t51;
  const double _t223 = (0.8e1 / 0.3e1)*_t96;
  const double _t225 = (0.1e1 / 0.9e1)*_t24;
  const double _t227 = xc_powr(_t1, -7, 3);
  const double _t228 = (0.4e1 / 0.9e1)*_t227;
  const double _t229 = 0.24e2*_t145;
  const double _t230 = _t12*_t229;
  const double _t231 = _t230*na;
  const double _t232 = _t231*nb;
  const double _t233 = (0.1e1 / (_t11 * _t11 * _t11));
  const double _t234 = ((params->d) * (params->d));
  const double _t235 = _t233*_t234;
  const double _t236 = _t146*_t235;
  const double _t237 = (0.8e1 / 0.9e1)*_t236;
  const double _t238 = _t237*na;
  const double _t239 = _t238*nb;
  const double _t240 = _t150*_t95;
  const double _t253 = _t20*na;
  const double _t254 = _t20*nb;
  const double _t268 = (0.1e1 / 0.4e1)*_t22;
  const double _t270 = _t170*_t51;
  const double _t271 = _t22*_t270;
  const double _t281 = _t101*_t49;
  const double _t282 = _t102*_t50;
  const double _t284 = (0.6e1 / 0.5e1)*_t22;
  const double _t288 = _t137 + _t139;
  const double _t292 = xc_powr(nb, -14, 3);
  const double _t293 = (0.88e2 / 0.9e1)*_t292;
  const double _t298 = (_t101 * _t101);
  const double _t301 = -_t288;
  const double _t303 = (_t102 * _t102);
  const double _t311 = (0.16e2 / 0.3e1)*_t105;
  const double _t322 = _t50*_t7;
  const double _t141 = _hc7[8]*_t61;
  const double _t142 = _t141*gaa;
  const double _t143 = _hc5[9]*_t50 - _t142;
  const double _t144 = (0.2e1 / 0.9e1)*_t52;
  const double _t147 = _hc0[2]*_t146;
  const double _t148 = (0.7e1 / 0.162e3)*_t147;
  const double _t149 = _t148*na;
  const double _t151 = _hc0[1]*_t150;
  const double _t152 = (0.56e2 / 0.81e2)*_t151;
  const double _t153 = _t152*na;
  const double _t154 = -0.1e1 / 0.3e1*_t145*_t25*na*nb + _t149*nb + _t153*nb;
  const double _t155 = (0.7e1 / 0.27e2)*_hc0[1]*_t55*nb - _t144*nb - _t154;
  const double _t156 = _t155*_t24;
  const double _t157 = _t58*_t77;
  const double _t158 = (0.16e2 / 0.3e1)*_t157;
  const double _t161 = _hc7[2]*_t160;
  const double _t163 = _t162*_t65;
  const double _t164 = (0.1e1 / 0.2e1)*_t80;
  const double _t165 = (0.1e1 / 0.36e2)*_t82;
  const double _t166 = (0.1e1 / 0.216e3)*_t56;
  const double _t167 = _t166*_t34;
  const double _t168 = (0.1e1 / 0.4e1)*_t42;
  const double _t169 = _t168*_t68;
  const double _t172 = _t171*_t74;
  const double _t173 = _t166*_t86;
  const double _t174 = (0.12e2 / 0.5e1)*_t88;
  const double _t175 = _hc1[2]*_t140;
  const double _t177 = _hc1[5]*_t176;
  const double _t179 = _hc2[2]*_t178;
  const double _t181 = _hc2[5]*_t180;
  const double _t182 = _t175 + _t177 + _t179 + _t181;
  const double _t183 = _t68*_t79;
  const double _t184 = (0.1e1 / 0.2e1)*_t183;
  const double _t186 = _t185*_t74;
  const double _t187 = (0.1e1 / 0.36e2)*_t186;
  const double _t188 = _t31*_t73;
  const double _t189 = _t166*_t188;
  const double _t190 = _t160*_t38;
  const double _t192 = _t191*_t63;
  const double _t193 = _t10*_t179 + _t10*_t181 + _t175*_t8 + _t177*_t8 + _t190*gaa - _t192*gaa;
  const double _t194 = _t160*_t32;
  const double _t195 = _hc3[2]*_t50;
  const double _t196 = _t191*_t195;
  const double _t197 = _hc3[5]*_t8;
  const double _t198 = _hc4[5]*_t10;
  const double _t199 = _t140*_t71 + _t176*_t197 + _t178*_t72 + _t180*_t198 + _t194*gaa - _t196*gaa;
  const double _t200 = _t119*_t22;
  const double _t201 = _t166*_t31;
  const double _t202 = _t22*_t68;
  const double _t204 = _t203*_t65;
  const double _t205 = (0.12e2 / 0.5e1)*_t204;
  const double _t206 = _t146*_t28;
  const double _t207 = (0.88e2 / 0.9e1)*_t206;
  const double _t208 = _t145*_t87;
  const double _t209 = (0.18e2 / 0.5e1)*_t208;
  const double _t210 = (0.1e1 / 0.81e2)*_t151;
  const double _t211 = _t22*_t86;
  const double _t212 = (0.1e1 / 0.1296e4)*_t147;
  const double _t213 = _t145*_t35;
  const double _t214 = (0.1e1 / 0.24e2)*_t213;
  const double _t215 = _t22*_t34;
  const double _t216 = _t40*_t41;
  const double _t217 = _t145*_t216;
  const double _t218 = (0.3e1 / 0.4e1)*_t217;
  const double _t219 = -_t207*_t23 - _t209*_t22 - _t210*_t211 + _t210*_t215 - _t211*_t212 + _t212*_t215 + _t214*_t22 + _t218*_t22;
  const double _t220 = _hc5[3]*_t140 - _t142*_t50 + _t143*_t50 - _t156*_t23 + _t158*_t23 + _t161*gaa - _t163*nb - _t164*nb - _t165*nb - _t167*nb + _t169*nb + _t172*nb + _t173*nb + _t174*nb - _t182*_t66 - _t184*_t22 - _t187*_t22 - _t189*_t22 + _t193*_t69 + _t199*_t200 + _t201*_t202 + _t205*_t22 + _t219;
  const double _t222 = (0.2e1 / 0.3e1)*_t92;
  const double _t224 = _hc6[2]*_t45;
  const double _t226 = _hc6[1]*_t45;
  const double _t241 = _t224*_t225 + _t226*_t228 - _t232 - _t239 + (0.64e2 / 0.9e1)*_t240*na*nb;
  const double _t242 = params->a*(_hc6[0]*_t220 + _t221*nb - _t222*_t91 - _t223*nb + _t241);
  const double _t243 = _hc7[7]*_t106;
  const double _t244 = _t243*gbb;
  const double _t245 = _hc5[9]*_t102 - _t244;
  const double _t246 = (0.7e1 / 0.54e2)*_hc0[1]*_t55*na + (0.7e1 / 0.54e2)*_hc0[1]*_t55*nb + (0.1e1 / 0.18e2)*_t13*_t25 - _t154 - _t53*nb - _t54;
  const double _t247 = _t24*_t246;
  const double _t248 = _t103*_t77;
  const double _t249 = (0.8e1 / 0.3e1)*_t248;
  const double _t250 = (0.8e1 / 0.3e1)*_t157;
  const double _t251 = _hc7[8]*_t102;
  const double _t252 = _t251*_t61;
  const double _t255 = _t34*na;
  const double _t256 = _t84*nb;
  const double _t257 = _t112*nb;
  const double _t258 = _t74*na;
  const double _t259 = _t115*nb;
  const double _t260 = _t86*na;
  const double _t261 = _hc1[2]*_t139;
  const double _t262 = _hc2[2]*_t139;
  const double _t263 = _hc2[5]*_t49;
  const double _t264 = _t101*_t263;
  const double _t265 = _hc1[5]*_t50;
  const double _t266 = _t102*_t265;
  const double _t267 = _t261 - _t262 + _t264 + _t266;
  const double _t269 = _t112*_t79;
  const double _t272 = _t31*_t84;
  const double _t273 = _t22*_t272;
  const double _t274 = _t106*_t64;
  const double _t275 = _t109*_t61;
  const double _t276 = -_t10*_t262 + _t10*_t264 + _t261*_t8 + _t266*_t8 - _t274*gbb - _t275*gaa;
  const double _t277 = _hc4[2]*_t106;
  const double _t278 = _t277*_t49;
  const double _t279 = _hc3[2]*_t102;
  const double _t280 = _t279*_t61;
  const double _t283 = _t139*_t71 - _t139*_t72 + _t197*_t282 + _t198*_t281 - _t278*gbb - _t280*gaa;
  const double _t285 = _t110*_t203;
  const double _t286 = _hc5[3]*_t139 - _t110*_t254 + _t112*_t273 - _t114*_t273 - _t115*_t271 + _t133*_t68 - _t183*_t268 - _t188*_t85 + _t200*_t283 + _t202*_t272 + _t204*_t284 - _t21 + _t219 - _t23*_t247 + _t23*_t249 + _t23*_t250 + _t245*_t50 - _t252*gaa - _t253*_t65 - _t255*_t84 - _t256*_t34 + _t256*_t86 + _t257*_t43 + _t258*_t75 + _t259*_t75 + _t260*_t84 - _t267*_t66 - _t268*_t269 - _t271*_t74 + _t276*_t69 + _t284*_t285 + _t37 + _t44 - _t81*na - _t81*nb - _t83*na - _t83*nb + _t89*na + _t89*nb;
  const double _t287 = params->a*(_hc6[0]*_t286 + (0.4e1 / 0.9e1)*_hc6[1]*_t227*_t45 + (0.1e1 / 0.9e1)*_hc6[2]*_t24*_t45 - _t116*_t93 + 0.8e1*_t12*_t51*na + 0.8e1*_t12*_t51*nb - _t15 + (0.64e2 / 0.9e1)*_t150*_t94*na*nb*params->d - _t232 - _t239 - _t91*_t93 - _t97*nb - _t98);
  const double _t289 = (0.7e1 / 0.27e2)*_hc0[1]*_t55*na - _t144*na - _t154;
  const double _t290 = _t24*_t289;
  const double _t291 = (0.16e2 / 0.3e1)*_t248;
  const double _t294 = _hc7[1]*_t293;
  const double _t295 = _t110*_t162;
  const double _t296 = _t112*_t168;
  const double _t297 = _t115*_t171;
  const double _t299 = _hc2[5]*_t298;
  const double _t300 = _hc1[2]*_t288;
  const double _t302 = _hc2[2]*_t301;
  const double _t304 = _hc1[5]*_t303;
  const double _t305 = _t299 + _t300 + _t302 + _t304;
  const double _t306 = (0.1e1 / 0.2e1)*_t269;
  const double _t307 = _t115*_t185;
  const double _t308 = (0.1e1 / 0.36e2)*_t307;
  const double _t309 = _t201*_t22;
  const double _t310 = _t293*_t39;
  const double _t312 = _t108*_t311;
  const double _t313 = _t10*_t299 + _t10*_t302 + _t300*_t8 + _t304*_t8 + _t310*gbb - _t312*gbb;
  const double _t314 = _t293*_t33;
  const double _t315 = _hc4[2]*_t101;
  const double _t316 = _t311*_t315;
  const double _t317 = _t197*_t303 + _t198*_t298 + _t288*_t71 + _t301*_t72 + _t314*gbb - _t316*gbb;
  const double _t318 = (0.12e2 / 0.5e1)*_t285;
  const double _t319 = _hc5[3]*_t288 - _t102*_t244 + _t102*_t245 + _t112*_t309 - _t114*_t309 - _t164*na - _t165*na - _t167*na + _t173*na + _t174*na + _t200*_t317 + _t219 - _t22*_t306 - _t22*_t308 + _t22*_t318 - _t23*_t290 + _t23*_t291 + _t294*gbb - _t295*na + _t296*na + _t297*na - _t305*_t66 + _t313*_t69;
  const double _t320 = params->a*(_hc6[0]*_t319 - _t116*_t222 + _t221*na - _t223*na + _t241);
  const double _t321 = -_t126*_t93;
  const double _t323 = _t63*_t7 - _t67;
  const double _t324 = _t43*nb;
  const double _t325 = _t38*_t7;
  const double _t326 = _hc3[2]*_t322 - _t70;
  const double _t327 = _t119*nb;
  const double _t328 = _t32*_t7;
  const double _t329 = -_t59 + _t78;
  const double _t330 = _t123*_t79;
  const double _t331 = (0.1e1 / 0.4e1)*_t330;
  const double _t332 = _t121*_t30;
  const double _t333 = _t270*_t332;
  const double _t334 = _t121*_t31;
  const double _t335 = _t123*_t31;
  const double _t336 = -_t256*_t334 + _t256*_t335 - _t331*nb - _t333*nb;
  const double _t337 = _hc7[8]*_t322 + _t200*_t326 + _t323*_t69 + _t324*_t325 + _t327*_t328 + _t329 + _t336 - _t62;
  const double _t338 = params->a*(_hc6[0]*_t337 + _t321);
  const double _t339 = _t129*_t29;
  const double _t340 = _hc6[1]*_t28;
  const double _t341 = (0.2e1 / 0.3e1)*_t145*_t340;
  const double _t342 = -0.16e2 / 0.3e1*_t28*_t77;
  const double _t343 = -_t342 - 0.2e1*_t59;
  const double _t344 = _hc6[0]*_t343 + _t341;
  const double _t345 = -_t135*_t93;
  const double _t346 = _hc7[7]*_t9;
  const double _t347 = _t130*_t64;
  const double _t348 = _t119*na;
  const double _t349 = _hc4[2]*_t49;
  const double _t350 = _t130*_t349;
  const double _t351 = _t134*_t79;
  const double _t352 = (0.1e1 / 0.4e1)*_t351;
  const double _t353 = _t131*_t30;
  const double _t354 = _t270*_t353;
  const double _t355 = _t131*_t272;
  const double _t356 = _t134*_t272;
  const double _t357 = -_t352*na - _t354*na - _t355*na + _t356*na;
  const double _t358 = _t132 + _t133*_t347 + _t134*_t43 + _t329 + _t346*_t50 + _t348*_t350 + _t357;
  const double _t359 = params->a*(_hc6[0]*_t358 + _t345);
  const double _t360 = _t109*_t120;
  const double _t361 = _t120*_t279;
  const double _t362 = -_t104 + _t78;
  const double _t363 = _t122 + _t124 + _t251*_t7 + _t324*_t360 + _t327*_t361 + _t336 + _t362;
  const double _t364 = params->a*(_hc6[0]*_t363 + _t321);
  const double _t365 = -0.2e1*_t104 - _t342;
  const double _t366 = _hc6[0]*_t365 + _t341;
  const double _t367 = _t108*_t9 - _t111;
  const double _t368 = _t39*_t9;
  const double _t369 = _hc4[2]*_t9;
  const double _t370 = _t101*_t369 - _t113;
  const double _t371 = _t33*_t9;
  const double _t372 = _t102*_t346 - _t107 + _t133*_t368 + _t200*_t370 + _t348*_t371 + _t357 + _t362 + _t367*_t69;
  const double _t373 = params->a*(_hc6[0]*_t372 + _t345);
  const double d2F_dna2 = _t1*_t242 + 0.2e1*_t100;
  const double d2F_dna_dnb = _t1*_t287 + _t100 + _t117;
  const double d2F_dnb2 = _t1*_t320 + 0.2e1*_t117;
  const double d2F_dna_dgaa = _t1*_t338 + _t128;
  const double d2F_dna_dgab = _t1*_t344*params->a - _t339;
  const double d2F_dna_dgbb = _t1*_t359 + _t136;
  const double d2F_dnb_dgaa = _t1*_t364 + _t128;
  const double d2F_dnb_dgab = _t1*_t366*params->a - _t339;
  const double d2F_dnb_dgbb = _t1*_t373 + _t136;
  const double d2F_dgaa2 = 0;
  const double d2F_dgaa_dgbb = 0;
  const double d2F_dgbb2 = 0;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 1] += d2F_dna_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 2] += d2F_dna_dgbb;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 3] += d2F_dnb_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 4] += d2F_dnb_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 2] += d2F_dgaa_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
#endif
#if _KMAX >= 3
  const double _t374 = 0.6e1*_t51;
  const double _t375 = _t145*_t3;
  const double _t376 = 0.6e1*_t375;
  const double _t377 = -_t374 + _t376;
  const double _t378 = -_t377;
  const double _t384 = 0.2e1*_t140;
  const double _t389 = xc_powi(_t1, -5);
  const double _t390 = _t389*nb;
  const double _t393 = xc_powi(_t1, -6);
  const double _t396 = xc_powr(_t1, -17, 3);
  const double _t399 = xc_powr(_t1, -16, 3);
  const double _t407 = xc_powr(na, -17, 3);
  const double _t408 = (0.1232e4 / 0.27e2)*_t407;
  const double _t416 = (0.176e3 / 0.9e1)*_t159*_t50;
  const double _t418 = (0.9e1 / 0.5e1)*_t19;
  const double _t440 = _t145*_t22;
  const double _t445 = (_t50 * _t50 * _t50);
  const double _t448 = (_t49 * _t49 * _t49);
  const double _t451 = 0.4e1*_t51;
  const double _t452 = _t3*_t451;
  const double _t453 = -_t14 + _t452;
  const double _t455 = -_t453;
  const double _t466 = _t145*_t31;
  const double _t467 = (0.1e1 / 0.8e1)*_t466;
  const double _t470 = _t159*gaa;
  const double _t471 = (0.88e2 / 0.3e1)*_t470;
  const double _t472 = 0.8e1*_t60;
  const double _t491 = (0.18e2 / 0.5e1)*_t22;
  const double _t505 = _t12*_t145;
  const double _t506 = 0.72e2*_t505;
  const double _t507 = (0.8e1 / 0.3e1)*_t236;
  const double _t510 = (0.4e1 / 0.9e1)*_t77;
  const double _t511 = (0.28e2 / 0.27e2)*_t55;
  const double _t512 = _t22*_t393;
  const double _t513 = (0.1e1 / (_t11 * _t11 * _t11 * _t11));
  const double _t514 = ((params->d) * (params->d) * (params->d));
  const double _t515 = _t513*_t514;
  const double _t516 = _t399*_t95;
  const double _t520 = _t376 - 0.2e1*_t51;
  const double _t521 = -_t520;
  const double _t539 = _t160*gaa;
  const double _t562 = -_t13*_t3;
  const double _t563 = _t47 + _t562;
  const double _t571 = _t22*_t31;
  const double _t573 = (0.32e2 / 0.3e1)*_t60;
  const double _t574 = _t573*gaa;
  const double _t577 = _t106*gbb;
  const double _t580 = (0.1e1 / 0.12e2)*_t466;
  const double _t582 = (0.1e1 / 0.24e2)*_t466;
  const double _t589 = _t101*_t180;
  const double _t592 = _t176*_t563;
  const double _t601 = (0.1e1 / 0.36e2)*_t185;
  const double _t604 = _t203*_t22;
  const double _t605 = (0.12e2 / 0.5e1)*_t604;
  const double _t608 = 0.48e2*_t505;
  const double _t609 = (0.16e2 / 0.9e1)*_t236;
  const double _t612 = _t1*params->a;
  const double _t634 = _t4 + _t562;
  const double _t640 = _t105*gbb;
  const double _t641 = (0.32e2 / 0.3e1)*_t640;
  const double _t644 = _t293*gbb;
  const double _t645 = _t61*gaa;
  const double _t646 = _t311*gbb;
  const double _t653 = _t298*_t49;
  const double _t654 = _t303*_t634;
  const double _t661 = _t374 + _t376;
  const double _t662 = -_t661;
  const double _t667 = xc_powr(nb, -17, 3);
  const double _t668 = (0.1232e4 / 0.27e2)*_t667;
  const double _t675 = (0.176e3 / 0.9e1)*_t102*_t292;
  const double _t684 = (_t101 * _t101 * _t101);
  const double _t688 = (_t102 * _t102 * _t102);
  const double _t690 = _t14 + _t452;
  const double _t691 = -_t690;
  const double _t700 = (0.88e2 / 0.3e1)*_t292;
  const double _t701 = _t700*gbb;
  const double _t702 = 0.8e1*_t105;
  const double _t729 = _t31*nb;
  const double _t731 = _t145*nb;
  const double _t736 = (0.3e1 / 0.4e1)*_t731;
  const double _t755 = _t31*na;
  const double _t757 = _t145*na;
  const double _t379 = _hc7[8]*_t160;
  const double _t380 = _hc7[18]*_t61;
  const double _t381 = _t380*gaa;
  const double _t382 = _hc5[19]*_t50 - _t381;
  const double _t383 = _hc5[9]*_t140 + _t379*gaa - _t381*_t50 + _t382*_t50;
  const double _t385 = _t145*_t25;
  const double _t386 = _t385*nb;
  const double _t387 = (0.56e2 / 0.27e2)*_t151;
  const double _t388 = (0.7e1 / 0.54e2)*_t147;
  const double _t391 = _t25*_t390;
  const double _t392 = (0.4e1 / 0.3e1)*_t391;
  const double _t394 = _hc0[3]*_t393;
  const double _t395 = _t394*nb;
  const double _t397 = _hc0[2]*_t396;
  const double _t398 = _t397*nb;
  const double _t400 = _hc0[1]*_t399;
  const double _t401 = _t400*nb;
  const double _t402 = -_t392*na + (0.7e1 / 0.486e3)*_t395*na + (0.35e2 / 0.81e2)*_t398*na + (0.917e3 / 0.243e3)*_t401*na;
  const double _t403 = _t386 - _t387*nb - _t388*nb + _t402;
  const double _t404 = _t24*_t403;
  const double _t405 = _t155*_t77;
  const double _t406 = 0.8e1*_t405;
  const double _t409 = _hc7[2]*_t408;
  const double _t410 = _t146*_t58;
  const double _t411 = (0.88e2 / 0.3e1)*_t410;
  const double _t412 = _hc7[8]*_t140;
  const double _t413 = _hc7[18]*_t176 + _t412;
  const double _t414 = _t413*_t61;
  const double _t415 = _hc7[8]*gaa;
  const double _t417 = (0.54e2 / 0.5e1)*_t208;
  const double _t419 = _t182*_t418;
  const double _t420 = (0.3e1 / 0.2e1)*_t183;
  const double _t421 = (0.1e1 / 0.12e2)*_t186;
  const double _t422 = (0.1e1 / 0.27e2)*_t151;
  const double _t423 = _t422*_t86;
  const double _t424 = _t170*_t56;
  const double _t425 = _t424*_t73;
  const double _t426 = (0.1e1 / 0.432e3)*_t147;
  const double _t427 = _t426*_t86;
  const double _t428 = (0.1e1 / 0.8e1)*_t213;
  const double _t429 = _t34*_t422;
  const double _t430 = _t118*_t13;
  const double _t431 = (0.1e1 / 0.48e2)*_t430;
  const double _t432 = _t199*_t431;
  const double _t433 = _t424*_t68;
  const double _t434 = _t34*_t426;
  const double _t435 = (0.3e1 / 0.8e1)*_t42;
  const double _t436 = _t193*_t435;
  const double _t437 = (0.9e1 / 0.4e1)*_t217;
  const double _t438 = (0.36e2 / 0.5e1)*_t204;
  const double _t439 = _t18*_t65;
  const double _t441 = _t439*_t440;
  const double _t442 = _t22*_t79;
  const double _t443 = _t193*_t442;
  const double _t444 = _hc1[2]*_t378;
  const double _t446 = _hc1[9]*_t445;
  const double _t447 = _hc2[2]*_t377;
  const double _t449 = _hc2[9]*_t448;
  const double _t450 = _t140*_t265;
  const double _t454 = _t265*_t453;
  const double _t456 = _t263*_t455;
  const double _t457 = _t178*_t263;
  const double _t458 = _t444 + _t446 + _t447 + _t449 + _t450 + _t454 + _t456 + _t457;
  const double _t459 = _t185*_t30;
  const double _t460 = (0.1e1 / 0.24e2)*_t459;
  const double _t461 = _t199*_t22;
  const double _t462 = _t31*_t422;
  const double _t463 = (0.1e1 / 0.144e3)*_t56;
  const double _t464 = _t31*_t463;
  const double _t465 = _t31*_t426;
  const double _t468 = _t22*_t74;
  const double _t469 = _t38*_t408;
  const double _t473 = _t175*_t472;
  const double _t474 = _t177*_t472;
  const double _t475 = _t10*_t447 + _t10*_t449 + _t10*_t456 + _t10*_t457 + _t444*_t8 + _t446*_t8 + _t450*_t8 + _t454*_t8 - _t469*gaa + _t471*_t63 - _t473*gaa - _t474*gaa;
  const double _t476 = _t188*_t22;
  const double _t477 = _t22*_t464;
  const double _t478 = _t32*_t408;
  const double _t479 = _hc3[9]*_t8;
  const double _t480 = _hc3[2]*_t140;
  const double _t481 = _t472*_t480;
  const double _t482 = _hc3[5]*_t176;
  const double _t483 = _t472*_t482;
  const double _t484 = _hc4[9]*_t10;
  const double _t485 = _t197*_t50;
  const double _t486 = _t198*_t49;
  const double _t487 = _t140*_t485 + _t178*_t486 + _t195*_t471 + _t377*_t72 + _t378*_t71 + _t445*_t479 + _t448*_t484 + _t453*_t485 + _t455*_t486 - _t478*gaa - _t481*gaa - _t483*gaa;
  const double _t488 = _t41*_t68;
  const double _t489 = _t440*_t488;
  const double _t490 = _t182*_t203;
  const double _t492 = (0.1232e4 / 0.27e2)*_t28*_t396;
  const double _t493 = _t216*_t390;
  const double _t494 = 0.3e1*_t493;
  const double _t495 = (0.131e3 / 0.1944e4)*_t401;
  const double _t496 = (0.5e1 / 0.648e3)*_t398;
  const double _t497 = _t35*_t390;
  const double _t498 = (0.1e1 / 0.6e1)*_t497;
  const double _t499 = (0.1e1 / 0.3888e4)*_t395;
  const double _t500 = _t390*_t87;
  const double _t501 = (0.72e2 / 0.5e1)*_t500;
  const double _t502 = _t23*_t492 - _t255*_t495 - _t255*_t496 - _t255*_t499 + _t260*_t495 + _t260*_t496 + _t260*_t499 - _t494*na - _t498*na + _t501*na;
  const double _t503 = _hc5[3]*_t378 + _t143*_t384 + _t193*_t477 + _t200*_t487 - _t202*_t462 - _t202*_t465 - _t23*_t404 + _t23*_t406 - _t23*_t411 + _t383*_t50 - _t409*gaa - _t414*gaa + _t415*_t416 - _t417*nb - _t419*nb - _t420*nb - _t421*nb + _t422*_t476 - _t423*nb - _t425*nb + _t426*_t476 - _t427*nb + _t428*nb + _t429*nb + _t432*nb + _t433*nb + _t434*nb + _t436*nb + _t437*nb + _t438*nb - 0.54e2 / 0.5e1*_t441 - 0.3e1 / 0.4e1*_t443 - _t458*_t66 - _t460*_t461 - _t461*_t464 + _t467*_t468 + _t475*_t69 + (0.9e1 / 0.4e1)*_t489 + _t490*_t491 + _t502;
  const double _t504 = _t220*_t92;
  const double _t508 = _hc6[3]*_t145;
  const double _t509 = (0.1e1 / 0.27e2)*_t508;
  const double _t517 = -0.96e2*_t12*_t389*na*nb + (0.1048e4 / 0.27e2)*_t22*_t516 + _t224*_t510 + _t226*_t511 - 0.80e2 / 0.9e1*_t233*_t234*_t396*na*nb + _t45*_t509 + (0.8e1 / 0.9e1)*_t512*_t515;
  const double _t518 = params->a*(_hc6[0]*_t503 + (0.4e1 / 0.3e1)*_hc6[1]*_t227*_t91 + (0.1e1 / 0.3e1)*_hc6[2]*_t24*_t91 + (0.64e2 / 0.3e1)*_t150*_t94*nb*params->d - _t504 - _t506*nb - _t507*nb - _t517);
  const double _t519 = 0.2e1*_t287;
  const double _t522 = _hc7[17]*_t106;
  const double _t523 = _t522*gbb;
  const double _t524 = _hc5[19]*_t102 - _t523;
  const double _t525 = _hc5[9]*_t139 - _t102*_t381 + _t50*_t524;
  const double _t526 = (0.112e3 / 0.81e2)*_t151;
  const double _t527 = (0.7e1 / 0.81e2)*_t147;
  const double _t528 = _t385*na;
  const double _t529 = -_t144 + _t402 + (0.7e1 / 0.27e2)*_t56;
  const double _t530 = -_t149 - _t153 + (0.2e1 / 0.3e1)*_t386 - _t526*nb - _t527*nb + (0.1e1 / 0.3e1)*_t528 + _t529;
  const double _t531 = _t24*_t530;
  const double _t532 = (0.176e3 / 0.9e1)*_t410;
  const double _t533 = _t103*_t146;
  const double _t534 = (0.88e2 / 0.9e1)*_t533;
  const double _t535 = _hc7[8]*_t139;
  const double _t536 = _hc7[18]*_t282 + _t535;
  const double _t537 = _t536*_t61;
  const double _t538 = (0.8e1 / 0.3e1)*_t405;
  const double _t540 = (0.36e2 / 0.5e1)*_t208;
  const double _t541 = _t162*_t267;
  const double _t542 = _t86*nb;
  const double _t543 = (0.2e1 / 0.81e2)*_t151;
  const double _t544 = (0.1e1 / 0.648e3)*_t147;
  const double _t545 = _t168*_t276;
  const double _t546 = (0.1e1 / 0.12e2)*_t213;
  const double _t547 = _t171*_t30;
  const double _t548 = _t283*_t547;
  const double _t549 = _t201*nb;
  const double _t550 = _t34*nb;
  const double _t551 = (0.3e1 / 0.2e1)*_t217;
  const double _t552 = _t110*_t18;
  const double _t553 = _t440*_t552;
  const double _t554 = _hc1[2]*_t521;
  const double _t555 = _hc2[2]*_t520;
  const double _t556 = _t265*_t452;
  const double _t557 = _t263*_t452;
  const double _t558 = _hc2[5]*_t101;
  const double _t559 = _t178*_t558;
  const double _t560 = _hc2[9]*_t180;
  const double _t561 = _t101*_t560;
  const double _t564 = _hc1[9]*_t176;
  const double _t565 = _t563*_t564;
  const double _t566 = _hc1[5]*_t102;
  const double _t567 = _t140*_t566;
  const double _t568 = _t554 + _t555 + _t556 - _t557 + _t559 + _t561 + _t565 + _t567;
  const double _t569 = _t202*_t31;
  const double _t570 = _t271*_t30;
  const double _t572 = _t112*_t571;
  const double _t575 = _hc1[2]*_t51;
  const double _t576 = _t574*_t575;
  const double _t578 = _t191*_t266;
  const double _t579 = _t10*_t555 - _t10*_t557 + _t10*_t559 + _t10*_t561 + _t109*_t539 - _t179*_t577 - _t181*_t577 - _t3*_t576 + _t554*_t8 + _t556*_t8 + _t565*_t8 + _t567*_t8 - _t578*gaa;
  const double _t581 = _t115*_t22;
  const double _t583 = _t114*_t571;
  const double _t584 = _hc3[2]*_t574;
  const double _t585 = _t51*_t584;
  const double _t586 = _t178*_t277;
  const double _t587 = _hc4[5]*_t180;
  const double _t588 = _t101*_t198;
  const double _t590 = _hc3[5]*_t282;
  const double _t591 = _t191*_t590;
  const double _t593 = _t102*_t197;
  const double _t594 = _t140*_t593 + _t178*_t588 + _t279*_t539 - _t3*_t585 + _t452*_t485 - _t452*_t486 + _t479*_t592 + _t484*_t589 + _t520*_t72 + _t521*_t71 - _t577*_t587 - _t586*gbb - _t591*gaa;
  const double _t595 = _t145*_t41;
  const double _t596 = _t22*_t595;
  const double _t597 = _t112*_t596;
  const double _t598 = (0.16e2 / 0.3e1)*_t246*_t77;
  const double _t599 = _t201*na;
  const double _t600 = _t276*_t79;
  const double _t602 = _t30*_t601;
  const double _t603 = _t22*_t602;
  const double _t606 = -_t114*_t549 - _t164 - _t165 - _t167 + _t173 + _t174 - _t184*na - _t187*na - _t189*na + _t201*_t257 + _t205*na - 0.1e1 / 0.2e1*_t22*_t600 + _t23*_t598 + _t267*_t605 + _t276*_t309 - _t283*_t309 - _t283*_t603 - _t306*nb - _t308*nb + _t318*nb + _t502 + _t599*_t68;
  const double _t607 = _hc5[3]*_t521 + _t133*_t193 + _t139*_t143 + _t140*_t245 - _t163 + _t169 + _t172 - _t182*_t253 - _t184*nb - _t187*nb - _t189*nb + _t193*_t273 - _t199*_t273 + _t199*_t348 - _t199*_t570 + _t200*_t594 + _t205*nb - _t209*na + _t210*_t255 - _t210*_t260 - _t210*_t572 + _t210*_t583 + _t212*_t255 - _t212*_t260 - _t212*_t572 + _t212*_t583 + _t214*na + _t218*na - _t23*_t531 - _t23*_t532 - _t23*_t534 + _t23*_t538 + _t251*_t539 + _t284*_t490 - 0.36e2 / 0.5e1*_t441 - 0.1e1 / 0.4e1*_t443 + _t468*_t580 + _t476*_t543 + _t476*_t544 + (0.3e1 / 0.2e1)*_t489 + _t50*_t525 - _t537*gaa - _t540*nb - _t541*nb - _t542*_t543 - _t542*_t544 + _t543*_t550 - _t543*_t569 + _t544*_t550 - _t544*_t569 + _t545*nb + _t546*nb + _t548*nb + _t549*_t68 + _t551*nb - 0.18e2 / 0.5e1*_t553 - _t568*_t66 + _t579*_t69 + _t581*_t582 + (0.3e1 / 0.4e1)*_t597 + _t606;
  const double _t610 = -0.16e2*_t12*_t51 + _t222*_t286 + _t223 + _t517;
  const double _t611 = _hc6[0]*_t607 + (0.4e1 / 0.9e1)*_hc6[1]*_t116*_t227 + (0.8e1 / 0.9e1)*_hc6[1]*_t227*_t91 + (0.1e1 / 0.9e1)*_hc6[2]*_t116*_t24 + (0.2e1 / 0.9e1)*_hc6[2]*_t24*_t91 + (0.64e2 / 0.9e1)*_t150*_t94*na*params->d + (0.128e3 / 0.9e1)*_t150*_t94*nb*params->d - _t231 - _t238 - 0.1e1 / 0.3e1*_t504 - _t608*nb - _t609*nb - _t610;
  const double _t613 = _hc7[7]*_t293;
  const double _t614 = _hc5[9]*_t288 - _t102*_t523 + _t102*_t524 + _t613*gbb;
  const double _t615 = -_t148*nb - _t152*nb + (0.1e1 / 0.3e1)*_t386 - _t526*na - _t527*na + (0.2e1 / 0.3e1)*_t528 + _t529;
  const double _t616 = _t24*_t615;
  const double _t617 = (0.176e3 / 0.9e1)*_t533;
  const double _t618 = (0.88e2 / 0.9e1)*_t410;
  const double _t619 = _hc7[8]*_t288;
  const double _t620 = _hc7[18]*_t303;
  const double _t621 = _t619 + _t620;
  const double _t622 = _t61*_t621;
  const double _t623 = _t289*_t77;
  const double _t624 = (0.8e1 / 0.3e1)*_t623;
  const double _t625 = _hc1[2]*_t138;
  const double _t626 = _hc2[2]*_t138;
  const double _t627 = _hc1[2]*_t376;
  const double _t628 = _hc2[2]*_t376;
  const double _t629 = _t452*_t558;
  const double _t630 = _t452*_t566;
  const double _t631 = _t265*_t288;
  const double _t632 = _hc2[9]*_t298;
  const double _t633 = _t49*_t632;
  const double _t635 = _hc1[9]*_t303;
  const double _t636 = _t634*_t635;
  const double _t637 = _t263*_t301;
  const double _t638 = -_t625 + _t626 - _t627 + _t628 - _t629 + _t630 + _t631 + _t633 + _t636 + _t637;
  const double _t639 = _t313*_t442;
  const double _t642 = _hc2[2]*_t51;
  const double _t643 = _t3*_t642;
  const double _t647 = _t10*_t626 + _t10*_t628 - _t10*_t629 + _t10*_t633 + _t10*_t637 - _t264*_t646 - _t300*_t645 - _t304*_t645 - _t625*_t8 - _t627*_t8 + _t630*_t8 + _t631*_t8 + _t636*_t8 + _t64*_t644 + _t641*_t643;
  const double _t648 = _hc4[2]*_t51;
  const double _t649 = _t3*_t648;
  const double _t650 = _hc3[2]*_t288;
  const double _t651 = _hc3[5]*_t303;
  const double _t652 = _hc4[5]*_t281;
  const double _t655 = -_t138*_t71 + _t138*_t72 + _t288*_t485 + _t301*_t486 + _t349*_t644 - _t376*_t71 + _t376*_t72 - _t452*_t588 + _t452*_t593 + _t479*_t654 + _t484*_t653 + _t641*_t649 - _t645*_t650 - _t645*_t651 - _t646*_t652;
  const double _t656 = (0.3e1 / 0.2e1)*_t112;
  const double _t657 = _t203*_t305;
  const double _t658 = -_hc5[3]*_t138 - _hc5[3]*_t376 + _t112*_t599 - _t114*_t599 + _t200*_t655 - _t209*nb + _t210*_t476 - _t210*_t542 + _t210*_t550 - _t210*_t569 + _t212*_t476 - _t212*_t542 + _t212*_t550 - _t212*_t569 + _t214*nb + _t218*nb - _t23*_t616 - _t23*_t617 - _t23*_t618 + _t23*_t624 + _t245*_t452 - _t254*_t305 + _t255*_t543 + _t255*_t544 - _t260*_t543 - _t260*_t544 + _t273*_t313 - _t273*_t317 + _t284*_t657 - _t295 + _t296 + _t297 - _t306*na - _t308*na + _t313*_t324 + _t317*_t327 - _t317*_t570 + _t318*na - 0.18e2 / 0.5e1*_t441 + _t468*_t582 + (0.3e1 / 0.4e1)*_t489 + _t50*_t614 - _t540*na - _t541*na - _t543*_t572 + _t543*_t583 - _t544*_t572 + _t544*_t583 + _t545*na + _t546*na + _t548*na + _t551*na - 0.36e2 / 0.5e1*_t553 + _t580*_t581 + _t596*_t656 + _t606 - _t622*gaa - _t638*_t66 - 0.1e1 / 0.4e1*_t639 + _t647*_t69;
  const double _t659 = _t319*_t92;
  const double _t660 = _hc6[0]*_t658 + (0.8e1 / 0.9e1)*_hc6[1]*_t116*_t227 + (0.4e1 / 0.9e1)*_hc6[1]*_t227*_t91 + (0.2e1 / 0.9e1)*_hc6[2]*_t116*_t24 + (0.1e1 / 0.9e1)*_hc6[2]*_t24*_t91 + (0.128e3 / 0.9e1)*_t150*_t94*na*params->d + (0.64e2 / 0.9e1)*_t150*_t94*nb*params->d - _t230*nb - _t237*nb - _t608*na - _t609*na - _t610 - 0.1e1 / 0.3e1*_t659;
  const double _t663 = 0.2e1*_t245;
  const double _t664 = -_t387*na - _t388*na + _t402 + _t528;
  const double _t665 = _t24*_t664;
  const double _t666 = 0.8e1*_t623;
  const double _t669 = _hc7[1]*_t668;
  const double _t670 = (0.88e2 / 0.3e1)*_t533;
  const double _t671 = _hc7[7]*_t288;
  const double _t672 = _hc7[17]*_t303 + _t671;
  const double _t673 = _t106*_t672;
  const double _t674 = _hc7[7]*gbb;
  const double _t676 = _t305*_t418;
  const double _t677 = (0.3e1 / 0.2e1)*_t269;
  const double _t678 = (0.1e1 / 0.12e2)*_t307;
  const double _t679 = _t114*_t424;
  const double _t680 = _t317*_t431;
  const double _t681 = _t112*_t424;
  const double _t682 = _t313*_t435;
  const double _t683 = (0.36e2 / 0.5e1)*_t285;
  const double _t685 = _hc2[9]*_t684;
  const double _t686 = _hc1[2]*_t662;
  const double _t687 = _hc2[2]*_t661;
  const double _t689 = _hc1[9]*_t688;
  const double _t692 = _t558*_t691;
  const double _t693 = _t301*_t558;
  const double _t694 = _t288*_t566;
  const double _t695 = _t566*_t690;
  const double _t696 = _t685 + _t686 + _t687 + _t689 + _t692 + _t693 + _t694 + _t695;
  const double _t697 = _t22*_t460;
  const double _t698 = _t112*_t22;
  const double _t699 = _t39*_t668;
  const double _t703 = _t299*_t702;
  const double _t704 = _t302*_t702;
  const double _t705 = _t10*_t685 + _t10*_t687 + _t10*_t692 + _t10*_t693 + _t108*_t701 + _t686*_t8 + _t689*_t8 + _t694*_t8 + _t695*_t8 - _t699*gbb - _t703*gbb - _t704*gbb;
  const double _t706 = _t114*_t22;
  const double _t707 = _t33*_t668;
  const double _t708 = _hc4[5]*_t298;
  const double _t709 = _t702*_t708;
  const double _t710 = _hc4[2]*_t301;
  const double _t711 = _t702*_t710;
  const double _t712 = _t288*_t593 + _t301*_t588 + _t315*_t701 + _t479*_t688 + _t484*_t684 + _t588*_t691 + _t593*_t690 + _t661*_t72 + _t662*_t71 - _t707*gbb - _t709*gbb - _t711*gbb;
  const double _t713 = _hc5[3]*_t662 + _t102*_t614 + _t200*_t712 - _t23*_t665 + _t23*_t666 - _t23*_t670 + _t288*_t663 + _t313*_t477 - _t317*_t477 - _t317*_t697 - _t417*na - _t423*na - _t427*na + _t428*na + _t429*na + _t434*na + _t437*na - _t462*_t698 + _t462*_t706 - _t465*_t698 + _t465*_t706 + _t467*_t581 + _t491*_t657 + _t502 - 0.54e2 / 0.5e1*_t553 + (0.9e1 / 0.4e1)*_t597 - 0.3e1 / 0.4e1*_t639 - _t66*_t696 - _t669*gbb - _t673*gbb + _t674*_t675 - _t676*na - _t677*na - _t678*na - _t679*na + _t680*na + _t681*na + _t682*na + _t683*na + _t69*_t705;
  const double _t714 = params->a*(_hc6[0]*_t713 + (0.4e1 / 0.3e1)*_hc6[1]*_t116*_t227 + (0.1e1 / 0.3e1)*_hc6[2]*_t116*_t24 + (0.64e2 / 0.3e1)*_t150*_t94*na*params->d - _t506*na - _t507*na - _t517 - _t659);
  const double _t715 = _hc7[18]*_t322;
  const double _t716 = -_t141 + _t715;
  const double _t717 = _t168*_t323;
  const double _t718 = _t326*_t547;
  const double _t719 = _t323*_t442;
  const double _t720 = (0.1e1 / 0.2e1)*_t79;
  const double _t721 = _t325*_t720;
  const double _t722 = _t602*nb;
  const double _t723 = _t175*_t7 + _t177*_t7 + _t190 - _t192;
  const double _t724 = _hc3[2]*_t7;
  const double _t725 = _hc3[5]*_t7;
  const double _t726 = _t140*_t724 + _t176*_t725 + _t194 - _t196;
  const double _t727 = -_t207;
  const double _t728 = -_t156 + _t158 + _t727;
  const double _t730 = _t123*_t729;
  const double _t732 = (0.1e1 / 0.24e2)*_t118;
  const double _t733 = _t731*_t732;
  const double _t734 = _t121*_t729;
  const double _t735 = _t123*_t41;
  const double _t737 = _t121*_t733 - _t210*_t730 + _t210*_t734 - _t212*_t730 + _t212*_t734 + _t735*_t736;
  const double _t738 = -_t141*_t50 + _t161 + _t200*_t726 + _t309*_t323 - _t309*_t326 + _t325*_t549 - _t326*_t603 - _t328*_t549 - _t328*_t722 + _t412*_t7 + _t50*_t716 + _t69*_t723 + _t717*nb + _t718*nb - 0.1e1 / 0.2e1*_t719 - _t721*nb + _t728 + _t737;
  const double _t739 = _hc6[2]*_t225;
  const double _t740 = _hc6[1]*_t228;
  const double _t741 = _t126*_t739 + _t126*_t740;
  const double _t742 = params->a*(_hc6[0]*_t738 - _t222*_t337 + _t741);
  const double _t743 = _t344*params->a;
  const double _t744 = (0.176e3 / 0.9e1)*_t206;
  const double _t745 = -0.2e1*_t156 + (0.32e2 / 0.3e1)*_t58*_t77 - _t744;
  const double _t746 = _hc6[2]*_t28;
  const double _t747 = (0.8e1 / 0.9e1)*_t340*_t389 + (0.2e1 / 0.9e1)*_t399*_t746;
  const double _t748 = params->a*(_hc6[0]*_t745 - _t222*_t343 - _t747);
  const double _t749 = _hc7[17]*_t9;
  const double _t750 = _t179*_t9 + _t181*_t9;
  const double _t751 = _hc4[5]*_t9;
  const double _t752 = _t178*_t369 + _t180*_t751;
  const double _t753 = _t720*na;
  const double _t754 = _t602*na;
  const double _t756 = _t134*_t755;
  const double _t758 = _t732*_t757;
  const double _t759 = _t131*_t755;
  const double _t760 = _t41*_t757;
  const double _t761 = (0.3e1 / 0.4e1)*_t760;
  const double _t762 = _t131*_t758 + _t134*_t761 - _t210*_t756 + _t210*_t759 - _t212*_t756 + _t212*_t759;
  const double _t763 = -_t131*_t201 + _t134*_t201 + _t140*_t346 + _t168*_t347 + _t176*_t749 + _t200*_t752 + _t347*_t599 - _t347*_t753 + _t350*_t547 - _t350*_t599 - _t350*_t754 - 0.1e1 / 0.2e1*_t351 - _t353*_t601 + _t69*_t750 + _t728 + _t762;
  const double _t764 = _t135*_t739 + _t135*_t740;
  const double _t765 = params->a*(_hc6[0]*_t763 - _t222*_t358 + _t764);
  const double _t766 = (0.1e1 / 0.4e1)*_t79;
  const double _t767 = _t766*nb;
  const double _t768 = _t270*_t30;
  const double _t769 = _t768*nb;
  const double _t770 = _t256*_t31;
  const double _t771 = _t261*_t7 + _t266*_t7 - _t275;
  const double _t772 = _hc3[5]*_t322;
  const double _t773 = _t102*_t772 + _t139*_t724 - _t280;
  const double _t774 = _t109*_t7;
  const double _t775 = _t102*_t724;
  const double _t776 = -_t247 + _t249 + _t250 + _t727;
  const double _t777 = _t102*_t715 + _t119*_t328 - _t121*_t272 + _t123*_t272 + _t133*_t323 + _t200*_t773 - _t252 + _t273*_t323 - _t273*_t326 + _t324*_t774 + _t325*_t43 - _t325*_t767 + _t325*_t770 + _t326*_t348 - _t326*_t570 + _t327*_t775 - _t328*_t769 - _t328*_t770 - _t331 - _t333 - _t360*_t767 + _t360*_t770 - _t361*_t769 - _t361*_t770 + _t535*_t7 + _t69*_t771 - 0.1e1 / 0.4e1*_t719 + _t737 + _t776;
  const double _t778 = _hc6[0]*_t777 - _t337*_t93 - _t363*_t93 + _t741;
  const double _t779 = _t366*params->a;
  const double _t780 = (0.16e2 / 0.3e1)*_t103*_t77 - 0.2e1*_t247 + (0.16e2 / 0.3e1)*_t58*_t77 - _t744;
  const double _t781 = _hc6[0]*_t780 - _t343*_t93 - _t365*_t93 - _t747;
  const double _t782 = _t102*_t749 - _t243;
  const double _t783 = _t367*_t442;
  const double _t784 = _t368*na;
  const double _t785 = _t371*na;
  const double _t786 = _hc2[5]*_t101*_t49*_t9 - _t262*_t9 - _t274;
  const double _t787 = _hc4[5]*_t101*_t49*_t9 - _t139*_t369 - _t278;
  const double _t788 = _t347*na;
  const double _t789 = _t350*na;
  const double _t790 = _t64*_t9;
  const double _t791 = _t369*_t49;
  const double _t792 = _t119*_t371 + _t133*_t790 + _t139*_t346 + _t200*_t787 + _t272*_t784 - _t272*_t785 + _t272*_t788 - _t272*_t789 + _t273*_t367 - _t273*_t370 + _t324*_t367 + _t327*_t370 + _t348*_t791 - _t352 - _t354 - _t355 + _t356 + _t368*_t43 - _t370*_t570 + _t50*_t782 + _t69*_t786 + _t762 - _t766*_t784 - _t766*_t788 - _t768*_t785 - _t768*_t789 + _t776 - 0.1e1 / 0.4e1*_t783;
  const double _t793 = _hc6[0]*_t792 - _t358*_t93 - _t372*_t93 + _t764;
  const double _t794 = _t300*_t7 + _t304*_t7;
  const double _t795 = _t288*_t724 + _t303*_t725;
  const double _t796 = _t720*nb;
  const double _t797 = -_t290 + _t291 + _t727;
  const double _t798 = -_t121*_t201 + _t123*_t201 + _t168*_t360 + _t200*_t795 - 0.1e1 / 0.2e1*_t330 - _t332*_t601 + _t360*_t549 - _t360*_t796 + _t361*_t547 - _t361*_t549 - _t361*_t722 + _t619*_t7 + _t620*_t7 + _t69*_t794 + _t737 + _t797;
  const double _t799 = params->a*(_hc6[0]*_t798 - _t222*_t363 + _t741);
  const double _t800 = (0.32e2 / 0.3e1)*_t103*_t77 - 0.2e1*_t290 - _t744;
  const double _t801 = params->a*(_hc6[0]*_t800 - _t222*_t365 - _t747);
  const double _t802 = _t168*_t367;
  const double _t803 = _t370*_t547;
  const double _t804 = _t299*_t9 + _t302*_t9 + _t310 - _t312;
  const double _t805 = _t298*_t751 + _t301*_t369 + _t314 - _t316;
  const double _t806 = -_t102*_t243 + _t102*_t782 + _t200*_t805 + _t294 + _t309*_t367 - _t309*_t370 + _t368*_t599 - _t368*_t753 - _t370*_t603 - _t371*_t599 - _t371*_t754 + _t671*_t9 + _t69*_t804 + _t762 - 0.1e1 / 0.2e1*_t783 + _t797 + _t802*na + _t803*na;
  const double _t807 = params->a*(_hc6[0]*_t806 - _t222*_t372 + _t764);
  const double d3F_dna3 = _t1*_t518 + 0.3e1*_t242;
  const double d3F_dna2_dnb = _t242 + _t519 + _t611*_t612;
  const double d3F_dna_dnb2 = _t320 + _t519 + _t612*_t660;
  const double d3F_dnb3 = _t1*_t714 + 0.3e1*_t320;
  const double d3F_dna2_dgaa = _t1*_t742 + 0.2e1*_t338;
  const double d3F_dna2_dgab = _t1*_t748 + 0.2e1*_t743;
  const double d3F_dna2_dgbb = _t1*_t765 + 0.2e1*_t359;
  const double d3F_dna_dnb_dgaa = _t338 + _t364 + _t612*_t778;
  const double d3F_dna_dnb_dgab = _t612*_t781 + _t743 + _t779;
  const double d3F_dna_dnb_dgbb = _t359 + _t373 + _t612*_t793;
  const double d3F_dnb2_dgaa = _t1*_t799 + 0.2e1*_t364;
  const double d3F_dnb2_dgab = _t1*_t801 + 0.2e1*_t779;
  const double d3F_dnb2_dgbb = _t1*_t807 + 0.2e1*_t373;
  const double d3F_dna_dgaa2 = 0;
  const double d3F_dna_dgaa_dgbb = 0;
  const double d3F_dna_dgbb2 = 0;
  const double d3F_dnb_dgaa2 = 0;
  const double d3F_dnb_dgaa_dgbb = 0;
  const double d3F_dnb_dgbb2 = 0;
  const double d3F_dgaa3 = 0;
  const double d3F_dgaa2_dgbb = 0;
  const double d3F_dgaa_dgbb2 = 0;
  const double d3F_dgbb3 = 0;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 1] += d3F_dna2_dgab;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 2] += d3F_dna2_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 3] += d3F_dna_dnb_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 4] += d3F_dna_dnb_dgab;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 5] += d3F_dna_dnb_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 6] += d3F_dnb2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 7] += d3F_dnb2_dgab;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 2] += d3F_dna_dgaa_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 5] += d3F_dna_dgbb2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 6] += d3F_dnb_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 8] += d3F_dnb_dgaa_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 2] += d3F_dgaa2_dgbb;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 5] += d3F_dgaa_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
#endif
#if _KMAX >= 4
  const double _t808 = 0.24e2*_t3*_t389;
  const double _t809 = -_t229 + _t808;
  const double _t810 = (0.176e3 / 0.9e1)*_t470;
  const double _t815 = _t22/xc_powr(_t1, 22, 3);
  const double _t817 = xc_powi(_t1, -7);
  const double _t818 = _t22*_t817;
  const double _t820 = xc_powr(_t1, -20, 3);
  const double _t821 = _t22*_t820;
  const double _t823 = xc_powr(_t1, -19, 3);
  const double _t824 = _t22*_t823;
  const double _t827 = _t23*_t24;
  const double _t828 = _t146*_t23;
  const double _t831 = 0.2e1*_t50;
  const double _t832 = _t23*_t77;
  const double _t834 = _t23*_t396;
  const double _t836 = (0.20944e5 / 0.81e2)*gaa/xc_powr(na, 20, 3);
  const double _t837 = (0.1e1 / 0.2e1)*_t31;
  const double _t845 = (0.12e2 / 0.5e1)*_t19;
  const double _t860 = _t390*na;
  const double _t863 = _t18*_t440;
  const double _t865 = (_t50 * _t50 * _t50 * _t50);
  const double _t868 = -_t809;
  const double _t870 = (_t49 * _t49 * _t49 * _t49);
  const double _t872 = (_t140 * _t140);
  const double _t874 = (_t178 * _t178);
  const double _t876 = 0.12e2*_t51;
  const double _t877 = 0.12e2*_t145;
  const double _t878 = _t3*_t877;
  const double _t879 = -_t876 + _t878;
  const double _t880 = -_t879;
  const double _t886 = 0.2e1*_t377;
  const double _t890 = 0.6e1*_t13;
  const double _t891 = 0.6e1*na;
  const double _t892 = 0.6e1*nb;
  const double _t893 = _t891 - _t892;
  const double _t894 = _t51*_t893 - _t890;
  const double _t896 = 0.4e1*na;
  const double _t897 = 0.4e1*nb;
  const double _t898 = _t896 - _t897;
  const double _t899 = -_t14 + _t51*_t898;
  const double _t901 = 0.2e1*na - 0.2e1*nb;
  const double _t902 = -_t137 + _t51*_t901;
  const double _t904 = _t3*_t374;
  const double _t905 = _t890 - _t904;
  const double _t920 = (0.4928e4 / 0.27e2)*_t407*gaa;
  const double _t921 = (0.176e3 / 0.3e1)*_t470;
  const double _t935 = (0.24e2 / 0.5e1)*_t604;
  const double _t943 = _t12*_t390;
  const double _t952 = _t516*nb;
  const double _t953 = _t393*_t515;
  const double _t954 = _t953*nb;
  const double _t955 = _t235*_t396;
  const double _t956 = _t955*nb;
  const double _t957 = 0.480e3*_t12*_t512;
  const double _t958 = (0.6176e4 / 0.81e2)*_t235*_t821;
  const double _t959 = (0.32e2 / 0.27e2)*_t815*((params->d) * (params->d) * (params->d) * (params->d))/xc_powi(_t11, 5);
  const double _t962 = _t808 - _t877;
  const double _t967 = 0.2e1*_t521;
  const double _t975 = _t408*gaa;
  const double _t976 = _t389*na;
  const double _t998 = _t203*nb;
  const double _t1006 = -_t962;
  const double _t1009 = _t139*_t453;
  const double _t1012 = _t139*_t455;
  const double _t1017 = -0.4e1*_t51 + _t878;
  const double _t1018 = -_t1017;
  const double _t1021 = _t101*_t448;
  const double _t1023 = _t445*_t563;
  const double _t1034 = (0.1e1 / 0.6e1)*_t390;
  const double _t1039 = _t3*_t921;
  const double _t1040 = _t472*gaa;
  const double _t1041 = _t3*_t51;
  const double _t1042 = _t60*gaa;
  const double _t1043 = 0.32e2*_t1042;
  const double _t1044 = _t1041*_t1043;
  const double _t1046 = _t49*_t577;
  const double _t1052 = _t203*_t284;
  const double _t1053 = _t203*_t491;
  const double _t1068 = _t953*na;
  const double _t1069 = _t516*na;
  const double _t1096 = (0.1e1 / 0.6e1)*_t466;
  const double _t1105 = _t203*na;
  const double _t1108 = _t892*_t976;
  const double _t1113 = _t176*_t303;
  const double _t1116 = _t137 + _t51*_t901;
  const double _t1119 = _t180*_t298;
  const double _t1129 = 0.8e1*(_t3 * _t3)*_t393;
  const double _t1134 = 0.8e1*_t1041;
  const double _t1144 = _t1043*_t375;
  const double _t1145 = _t191*gaa;
  const double _t1146 = (0.64e2 / 0.3e1)*_t1041;
  const double _t1147 = _t1042*_t1146;
  const double _t1148 = _t1146*_t640;
  const double _t1160 = _t12*_t389*na;
  const double _t1165 = _t955*na;
  const double _t1166 = 0.2e1*_t288;
  const double _t1170 = 0.18e2*_t375;
  const double _t1172 = 0.2e1*_t102;
  const double _t1187 = _t634*_t688;
  const double _t1190 = _t49*_t684;
  const double _t1209 = 0.16e2*_t640;
  const double _t1210 = _t668*gbb;
  const double _t1211 = 0.48e2*_t375*_t640;
  const double _t1212 = _t702*gbb;
  const double _t1213 = (0.176e3 / 0.3e1)*_t292*gbb;
  const double _t1214 = 0.32e2*_t1041*_t640;
  const double _t1219 = _t229 + _t808;
  const double _t1221 = (0.20944e5 / 0.81e2)*gbb/xc_powr(nb, 20, 3);
  const double _t1226 = (_t101 * _t101 * _t101 * _t101);
  const double _t1229 = -_t1219;
  const double _t1231 = (_t102 * _t102 * _t102 * _t102);
  const double _t1233 = (_t288 * _t288);
  const double _t1235 = (_t301 * _t301);
  const double _t1237 = _t876 + _t878;
  const double _t1240 = -_t890 - _t904;
  const double _t1244 = -_t1237;
  const double _t1250 = _t14 + _t51*_t898;
  const double _t1252 = _t51*_t893 + _t890;
  const double _t1254 = (0.4928e4 / 0.27e2)*_t667*gbb;
  const double _t1255 = _t101*_t641;
  const double _t1261 = (0.88e2 / 0.3e1)*_t159;
  const double _t1298 = 0.2e1*params->a;
  const double _t1304 = _t3*_t573;
  const double _t1342 = (0.32e2 / 0.3e1)*_t105;
  const double _t811 = _hc7[18]*_t140;
  const double _t812 = _hc7[33]*_t176 + _t811;
  const double _t813 = _hc7[18]*_t539;
  const double _t814 = _hc7[33]*_t645;
  const double _t816 = _hc0[4]*_t815;
  const double _t819 = _hc0[3]*_t818;
  const double _t822 = _hc0[2]*_t821;
  const double _t825 = _hc0[1]*_t824;
  const double _t826 = -0.20e2 / 0.3e1*_t25*_t393*na*nb + (0.7e1 / 0.1458e4)*_t816 + (0.56e2 / 0.243e3)*_t819 + (0.2702e4 / 0.729e3)*_t822 + (0.16940e5 / 0.729e3)*_t825;
  const double _t829 = _t155*_t828;
  const double _t830 = _hc7[8]*_t378;
  const double _t833 = _t403*_t832;
  const double _t835 = _t58*_t834;
  const double _t838 = _t731*_t74;
  const double _t839 = (0.1e1 / 0.2e1)*_t42;
  const double _t840 = _t193*nb;
  const double _t841 = 0.3e1*_t79;
  const double _t842 = _t488*_t731;
  const double _t843 = _t439*_t731;
  const double _t844 = (0.131e3 / 0.486e3)*_t401;
  const double _t846 = (0.5e1 / 0.162e3)*_t398;
  const double _t847 = _t68*_t729;
  const double _t848 = (0.4e1 / 0.27e2)*_t151;
  const double _t849 = _t459*nb;
  const double _t850 = _t199*_t849;
  const double _t851 = (0.1e1 / 0.36e2)*_t56;
  const double _t852 = _t199*_t729;
  const double _t853 = (0.1e1 / 0.108e3)*_t147;
  const double _t854 = (0.1e1 / 0.972e3)*_t395;
  const double _t855 = _t31*_t840;
  const double _t856 = (0.1e1 / 0.36e2)*_t430;
  const double _t857 = _t188*nb;
  const double _t858 = _t490*nb;
  const double _t859 = _t442*_t475;
  const double _t861 = _t488*_t860;
  const double _t862 = _t188*na;
  const double _t864 = _t182*_t863;
  const double _t866 = _hc1[14]*_t865;
  const double _t867 = _hc1[2]*_t809;
  const double _t869 = _hc2[2]*_t868;
  const double _t871 = _hc2[14]*_t870;
  const double _t873 = _hc1[5]*_t872;
  const double _t875 = _hc2[5]*_t874;
  const double _t881 = _t265*_t880;
  const double _t882 = 0.2e1*_t265*_t378;
  const double _t883 = _t263*_t879;
  const double _t884 = _hc1[5]*_t140;
  const double _t885 = _t453*_t884;
  const double _t887 = _t263*_t886;
  const double _t888 = _hc2[5]*_t178;
  const double _t889 = _t455*_t888;
  const double _t895 = _t564*_t894;
  const double _t900 = _t564*_t899;
  const double _t903 = _t564*_t902;
  const double _t906 = _t560*_t905;
  const double _t907 = _t455*_t560;
  const double _t908 = _t178*_t560;
  const double _t909 = _t258*_t390;
  const double _t910 = _t31*_t909;
  const double _t911 = (0.2e1 / 0.27e2)*_t151;
  const double _t912 = _t193*_t571;
  const double _t913 = (0.1e1 / 0.18e2)*_t459;
  const double _t914 = _t22*_t487;
  const double _t915 = (0.1e1 / 0.108e3)*_t56;
  const double _t916 = _t31*_t915;
  const double _t917 = (0.1e1 / 0.216e3)*_t147;
  const double _t918 = _t118*_t145;
  const double _t919 = _t268*_t918;
  const double _t922 = _t22*_t916;
  const double _t923 = _hc3[14]*_t8;
  const double _t924 = _hc4[14]*_t10;
  const double _t925 = _hc3[5]*_t50;
  const double _t926 = _t574*_t925;
  const double _t927 = _t140*_t197;
  const double _t928 = _t178*_t198;
  const double _t929 = _t176*_t479;
  const double _t930 = _t180*_t484;
  const double _t931 = _t31*_t461;
  const double _t932 = _t68*na;
  const double _t933 = _t31*_t932;
  const double _t934 = _t193*_t596;
  const double _t936 = _t439*_t860;
  const double _t937 = _t28*_t820;
  const double _t938 = (0.605e3 / 0.1458e4)*_t825;
  const double _t939 = (0.193e3 / 0.2916e4)*_t822;
  const double _t940 = (0.1e1 / 0.243e3)*_t819;
  const double _t941 = (0.1e1 / 0.11664e5)*_t816;
  const double _t942 = 0.15e2*_t216*_t512 - 0.20944e5 / 0.81e2*_t23*_t937 + _t34*_t938 + _t34*_t939 + _t34*_t940 + _t34*_t941 + (0.5e1 / 0.6e1)*_t35*_t512 - 0.72e2*_t512*_t87 - _t86*_t938 - _t86*_t939 - _t86*_t940 - _t86*_t941;
  const double _t944 = _hc6[1]*_t91;
  const double _t945 = _t55*_t944;
  const double _t946 = _hc6[2]*_t91;
  const double _t947 = _t77*_t946;
  const double _t948 = (0.4e1 / 0.3e1)*_t92;
  const double _t949 = _t508*_t91;
  const double _t950 = _hc6[2]*_t24;
  const double _t951 = _hc6[1]*_t227;
  const double _t960 = (0.8e1 / 0.27e2)*_hc6[3]*_t389*_t45 + (0.1e1 / 0.81e2)*_hc6[4]*_t399*_t45 + (0.160e3 / 0.81e2)*_t146*_t224 + (0.280e3 / 0.81e2)*_t150*_t226 + (0.128e3 / 0.9e1)*_t515*_t818 + (0.19360e5 / 0.81e2)*_t824*_t95 - _t957 - _t958 - _t959;
  const double _t961 = _t611*params->a;
  const double _t963 = _hc7[18]*_t139;
  const double _t964 = _hc7[33]*_t282 + _t963;
  const double _t965 = _hc7[32]*_t577;
  const double _t966 = _hc5[34]*_t102 - _t965;
  const double _t968 = _t25*_t389;
  const double _t969 = _t968*na;
  const double _t970 = -_t145*_t25 + _t387 + _t388 + _t826;
  const double _t971 = _t530*_t832;
  const double _t972 = _hc7[8]*_t521;
  const double _t973 = _t102*_t811;
  const double _t974 = _t103*_t834;
  const double _t977 = _t216*_t976;
  const double _t978 = (0.131e3 / 0.648e3)*_t401;
  const double _t979 = _t400*na;
  const double _t980 = (0.131e3 / 0.1944e4)*_t979;
  const double _t981 = (0.5e1 / 0.216e3)*_t398;
  const double _t982 = _t397*na;
  const double _t983 = (0.5e1 / 0.648e3)*_t982;
  const double _t984 = _t600*nb;
  const double _t985 = (0.3e1 / 0.4e1)*_t79;
  const double _t986 = _t193*na;
  const double _t987 = _t35*_t976;
  const double _t988 = _t283*_t849;
  const double _t989 = _t199*na;
  const double _t990 = _t424*nb;
  const double _t991 = (0.1e1 / 0.1296e4)*_t395;
  const double _t992 = _t394*na;
  const double _t993 = (0.1e1 / 0.3888e4)*_t992;
  const double _t994 = _t31*_t838;
  const double _t995 = _t431*nb;
  const double _t996 = _t435*nb;
  const double _t997 = _t490*na;
  const double _t999 = _t267*_t998;
  const double _t1000 = _t87*_t976;
  const double _t1001 = _t112*_t41;
  const double _t1002 = _t1001*_t860;
  const double _t1003 = _t114*_t755;
  const double _t1004 = _t442*_t579;
  const double _t1005 = _hc1[2]*_t962;
  const double _t1007 = _hc2[2]*_t1006;
  const double _t1008 = _t139*_t884;
  const double _t1010 = _hc1[5]*_t1009;
  const double _t1011 = _t564*_t904;
  const double _t1013 = _hc2[5]*_t1012;
  const double _t1014 = _t139*_t888;
  const double _t1015 = _t560*_t904;
  const double _t1016 = _t377*_t558;
  const double _t1019 = _t1018*_t265;
  const double _t1020 = _t265*_t521;
  const double _t1022 = _hc2[14]*_t1021;
  const double _t1024 = _hc1[14]*_t1023;
  const double _t1025 = _t263*_t520;
  const double _t1026 = _t1017*_t263;
  const double _t1027 = _t378*_t566;
  const double _t1028 = _hc2[9]*_t281;
  const double _t1029 = _t1028*_t455;
  const double _t1030 = _t1028*_t178;
  const double _t1031 = _hc1[9]*_t282;
  const double _t1032 = _t1031*_t140;
  const double _t1033 = _t1031*_t453;
  const double _t1035 = _t115*_t755;
  const double _t1036 = _t22*_t462;
  const double _t1037 = _t22*_t465;
  const double _t1038 = (0.1e1 / 0.8e1)*_t918;
  const double _t1045 = _hc3[2]*_t51;
  const double _t1047 = _hc4[5]*_t178;
  const double _t1048 = _hc3[5]*_t102;
  const double _t1049 = _t281*_t484;
  const double _t1050 = _t282*_t479;
  const double _t1051 = _t112*_t755;
  const double _t1054 = _t552*_t860;
  const double _t1055 = _t246*_t828;
  const double _t1056 = _t439*_t757;
  const double _t1057 = _t552*_t731;
  const double _t1058 = _t114*_t729;
  const double _t1059 = _t488*_t757;
  const double _t1060 = _t257*_t595;
  const double _t1061 = _t267*_t863;
  const double _t1062 = _t22*_t283;
  const double _t1063 = _t276*_t596;
  const double _t1064 = -_t1036*_t276 + _t1036*_t283 - _t1037*_t276 + _t1037*_t283 + _t1038*_t1062 - 0.88e2 / 0.3e1*_t1055 - 0.54e2 / 0.5e1*_t1056 - 0.54e2 / 0.5e1*_t1057 + _t1058*_t422 + _t1058*_t426 + (0.9e1 / 0.4e1)*_t1059 + (0.9e1 / 0.4e1)*_t1060 - 0.54e2 / 0.5e1*_t1061 + (0.9e1 / 0.4e1)*_t1063 - _t257*_t462 - _t257*_t465 + _t258*_t467 + _t259*_t467 - _t417 + _t422*_t862 - _t423 + _t426*_t862 - _t427 + _t428 + _t429 + _t434 + _t437 - _t462*_t932 - _t465*_t932;
  const double _t1065 = _t607*_t92;
  const double _t1066 = _hc6[2]*_t116;
  const double _t1067 = _hc6[1]*_t116;
  const double _t1070 = -0.280e3 / 0.81e2*_hc6[1]*_t150*_t45 - 0.4e1 / 0.3e1*_hc6[1]*_t227*_t286 - 0.160e3 / 0.81e2*_hc6[2]*_t146*_t45 - 0.1e1 / 0.3e1*_hc6[2]*_t24*_t286 - 0.8e1 / 0.27e2*_hc6[3]*_t389*_t45 - 0.1e1 / 0.81e2*_hc6[4]*_t399*_t45 - 0.64e2 / 0.3e1*_t150*_t94*params->d + _t506 + _t507 - 0.128e3 / 0.9e1*_t513*_t514*_t817*na*nb - 0.19360e5 / 0.81e2*_t823*_t94*na*nb*params->d + _t957 + _t958 + _t959;
  const double _t1071 = _t660*params->a;
  const double _t1072 = _hc7[18]*_t288;
  const double _t1073 = _hc7[33]*_t303;
  const double _t1074 = _t1072 + _t1073;
  const double _t1075 = _hc5[19]*_t288 + _hc7[17]*_t644 - _t102*_t965 + _t102*_t966;
  const double _t1076 = _t289*_t828;
  const double _t1077 = _hc7[8]*_t138;
  const double _t1078 = _hc7[8]*_t376;
  const double _t1079 = _hc7[18]*_t102*_t452;
  const double _t1080 = _t615*_t832;
  const double _t1081 = (0.4e1 / 0.81e2)*_t151;
  const double _t1082 = (0.1e1 / 0.324e3)*_t147;
  const double _t1083 = _t600*na;
  const double _t1084 = _t216*_t389;
  const double _t1085 = (0.131e3 / 0.972e3)*_t34;
  const double _t1086 = _t552*_t757;
  const double _t1087 = (0.5e1 / 0.324e3)*_t34;
  const double _t1088 = _t1081*_t31;
  const double _t1089 = _t313*nb;
  const double _t1090 = _t283*na;
  const double _t1091 = _t916*nb;
  const double _t1092 = _t1082*_t31;
  const double _t1093 = (0.1e1 / 0.1944e4)*_t34;
  const double _t1094 = _t168*na;
  const double _t1095 = _t168*nb;
  const double _t1097 = _t115*_t757;
  const double _t1098 = _t1097*_t31;
  const double _t1099 = _t547*na;
  const double _t1100 = _t547*nb;
  const double _t1101 = _t276*na;
  const double _t1102 = (0.1e1 / 0.1944e4)*_t86;
  const double _t1103 = (0.5e1 / 0.324e3)*_t86;
  const double _t1104 = _t305*_t998;
  const double _t1106 = _t1105*_t267;
  const double _t1107 = (0.131e3 / 0.972e3)*_t86;
  const double _t1109 = (0.131e3 / 0.972e3)*_t401;
  const double _t1110 = _t305*_t863;
  const double _t1111 = (0.5e1 / 0.324e3)*_t398;
  const double _t1112 = _t22*_t276;
  const double _t1114 = _hc1[14]*_t1113;
  const double _t1115 = _t288*_t884;
  const double _t1117 = _t1116*_t564;
  const double _t1118 = _t635*_t902;
  const double _t1120 = _hc2[14]*_t1119;
  const double _t1121 = _t301*_t888;
  const double _t1122 = _t178*_t632;
  const double _t1123 = _t301*_t560;
  const double _t1124 = _t265*_t451;
  const double _t1125 = _t566*_t967;
  const double _t1126 = 0.2e1*_t558;
  const double _t1127 = _t1126*_t520;
  const double _t1128 = _t263*_t451;
  const double _t1130 = _hc1[5]*_t1129;
  const double _t1131 = _hc2[5]*_t1129;
  const double _t1132 = _t265*_t878;
  const double _t1133 = _t263*_t878;
  const double _t1135 = _t1028*_t1134;
  const double _t1136 = _t1031*_t1134;
  const double _t1137 = _hc2[2]*_t808;
  const double _t1138 = _hc1[2]*_t808;
  const double _t1139 = -_t1137 + _t1138;
  const double _t1140 = _t442*_t647;
  const double _t1141 = _t1035*_t390;
  const double _t1142 = _t313*_t571;
  const double _t1143 = (0.1e1 / 0.1944e4)*_t395;
  const double _t1149 = -_t10*_t1137 + _t1138*_t8;
  const double _t1150 = (0.1e1 / 0.24e2)*_t918;
  const double _t1151 = (0.1e1 / 0.24e2)*_t317;
  const double _t1152 = _t22*_t918;
  const double _t1153 = _t317*_t571;
  const double _t1154 = _t303*_t479;
  const double _t1155 = _t298*_t484;
  const double _t1156 = 0.2e1*_t588;
  const double _t1157 = _t71*_t808 - _t72*_t808;
  const double _t1158 = _t313*_t596;
  const double _t1159 = _hc5[3]*_t808 + _t942;
  const double _t1161 = _t1067*_t55;
  const double _t1162 = _t1066*_t77;
  const double _t1163 = _t658*_t92;
  const double _t1164 = _t116*_t508;
  const double _t1167 = _hc7[17]*_t288;
  const double _t1168 = _hc7[32]*_t303 + _t1167;
  const double _t1169 = _hc5[9]*_t662 + _hc7[17]*_t675*gbb + _t102*_t1075 + _t1166*_t524 - _t1168*_t577 - _t668*_t674;
  const double _t1171 = _hc7[8]*_t662;
  const double _t1173 = _t664*_t832;
  const double _t1174 = (0.131e3 / 0.648e3)*_t979;
  const double _t1175 = (0.5e1 / 0.216e3)*_t982;
  const double _t1176 = _t313*na;
  const double _t1177 = (0.1e1 / 0.12e2)*_t459;
  const double _t1178 = _t317*na;
  const double _t1179 = _t463*_t729;
  const double _t1180 = (0.1e1 / 0.1296e4)*_t992;
  const double _t1181 = _t431*na;
  const double _t1182 = _t435*na;
  const double _t1183 = _t112*_t760;
  const double _t1184 = _t1105*_t305;
  const double _t1185 = _hc2[2]*_t877;
  const double _t1186 = _hc1[2]*_t877;
  const double _t1188 = _hc1[14]*_t1187;
  const double _t1189 = _t265*_t662;
  const double _t1191 = _hc2[14]*_t1190;
  const double _t1192 = _t263*_t661;
  const double _t1193 = _t374*_t566;
  const double _t1194 = _t374*_t558;
  const double _t1195 = _t1031*_t288;
  const double _t1196 = _t1031*_t690;
  const double _t1197 = _t1028*_t691;
  const double _t1198 = _t1028*_t301;
  const double _t1199 = _t1170*_t566;
  const double _t1200 = _hc2[5]*_t301;
  const double _t1201 = _t1200*_t904;
  const double _t1202 = _t632*_t904;
  const double _t1203 = _hc1[5]*_t288;
  const double _t1204 = _t1203*_t904;
  const double _t1205 = _t635*_t904;
  const double _t1206 = _t1170*_t558;
  const double _t1207 = _t442*_t705;
  const double _t1208 = _t1038*_t22;
  const double _t1215 = _hc4[5]*_t301;
  const double _t1216 = _t1048*_t645;
  const double _t1217 = _t198*_t301;
  const double _t1218 = _t197*_t288;
  const double _t1220 = _hc7[7]*_t662;
  const double _t1222 = (0.131e3 / 0.486e3)*_t979;
  const double _t1223 = (0.5e1 / 0.162e3)*_t982;
  const double _t1224 = _t755*_t851;
  const double _t1225 = (0.1e1 / 0.972e3)*_t992;
  const double _t1227 = _hc2[14]*_t1226;
  const double _t1228 = _hc1[2]*_t1219;
  const double _t1230 = _hc2[2]*_t1229;
  const double _t1232 = _hc1[14]*_t1231;
  const double _t1234 = _hc1[5]*_t1233;
  const double _t1236 = _hc2[5]*_t1235;
  const double _t1238 = _t1237*_t558;
  const double _t1239 = _t1126*_t661;
  const double _t1241 = _t1240*_t632;
  const double _t1242 = _t632*_t691;
  const double _t1243 = _t301*_t632;
  const double _t1245 = _t1244*_t566;
  const double _t1246 = _t1203*_t690;
  const double _t1247 = _t1200*_t691;
  const double _t1248 = 0.2e1*_t566*_t662;
  const double _t1249 = _t1116*_t635;
  const double _t1251 = _t1250*_t635;
  const double _t1253 = _t1252*_t635;
  const double _t1256 = _t323*nb;
  const double _t1257 = (0.3e1 / 0.2e1)*_t79;
  const double _t1258 = (0.1e1 / 0.12e2)*_t326;
  const double _t1259 = (0.3e1 / 0.4e1)*_t442;
  const double _t1260 = _t325*_t729;
  const double _t1262 = (0.1e1 / 0.8e1)*_t118;
  const double _t1263 = _t328*_t731;
  const double _t1264 = _t328*_t729;
  const double _t1265 = _hc3[9]*_t7;
  const double _t1266 = _t323*_t596;
  const double _t1267 = _t325*_t41;
  const double _t1268 = _t1267*_t731;
  const double _t1269 = -_t404 + _t406 - _t411 + _t492;
  const double _t1270 = -_t1034*_t118*_t121 - _t334*_t495 - _t334*_t496 - _t334*_t499 + _t335*_t495 + _t335*_t496 + _t335*_t499 - 0.3e1*_t390*_t735;
  const double _t1271 = _t738*_t92;
  const double _t1272 = _t126*_t509;
  const double _t1273 = _hc6[2]*_t510;
  const double _t1274 = _t126*_t1273;
  const double _t1275 = _hc6[1]*_t511;
  const double _t1276 = _t126*_t1275;
  const double _t1277 = _t1272 + _t1274 + _t1276;
  const double _t1278 = -0.2464e4 / 0.27e2*_t28*_t396;
  const double _t1279 = _t745*_t92;
  const double _t1280 = (0.1e1 / 0.3e1)*_t950;
  const double _t1281 = (0.4e1 / 0.3e1)*_t951;
  const double _t1282 = (0.2e1 / 0.27e2)*_hc6[3]*_t937 + (0.56e2 / 0.27e2)*_t340*_t393 + (0.8e1 / 0.9e1)*_t746*_t823;
  const double _t1283 = _t50*_t749;
  const double _t1284 = _t131*_t918;
  const double _t1285 = _t134*_t595;
  const double _t1286 = _hc4[9]*_t9;
  const double _t1287 = _t49*_t751;
  const double _t1288 = _t350*_t757;
  const double _t1289 = _t347*_t760;
  const double _t1290 = _t131*_t31;
  const double _t1291 = _t134*_t31;
  const double _t1292 = -0.1e1 / 0.6e1*_t118*_t131*_t976 - _t1290*_t980 - _t1290*_t983 - _t1290*_t993 + _t1291*_t980 + _t1291*_t983 + _t1291*_t993 - 0.3e1*_t134*_t41*_t976;
  const double _t1293 = _t763*_t92;
  const double _t1294 = _t135*_t509;
  const double _t1295 = _t1273*_t135;
  const double _t1296 = _t1275*_t135;
  const double _t1297 = _t1294 + _t1295 + _t1296;
  const double _t1299 = _t1298*_t778;
  const double _t1300 = _t121*_t918;
  const double _t1301 = _t123*_t595;
  const double _t1302 = _t323*_t571;
  const double _t1303 = (0.1e1 / 0.4e1)*_t442;
  const double _t1305 = (0.1e1 / 0.12e2)*_t118;
  const double _t1306 = _t102*_t725;
  const double _t1307 = _t326*_t571;
  const double _t1308 = _t360*_t729;
  const double _t1309 = _t361*_t729;
  const double _t1310 = _t360*_t41;
  const double _t1311 = _t492 + _t598;
  const double _t1312 = _t1311 - _t531 - _t532 - _t534 + _t538;
  const double _t1313 = (0.1e1 / 0.2e1)*_t442;
  const double _t1314 = _t1270 - _t1313*_t771 + _t201*_t325 - _t201*_t328 + _t309*_t771 - _t309*_t773 + _t323*_t599 - _t323*_t753 - _t326*_t599 - _t326*_t754 - _t328*_t602 + _t549*_t774 - _t549*_t775 - _t603*_t773 - _t721 - _t722*_t775 - _t774*_t796;
  const double _t1315 = (0.2e1 / 0.9e1)*_t950;
  const double _t1316 = (0.8e1 / 0.9e1)*_t951;
  const double _t1317 = -_t1272 - _t1274 - _t1276 - _t222*_t777;
  const double _t1318 = _t1298*_t781;
  const double _t1319 = _t1278 - 0.32e2 / 0.3e1*_t246*_t77;
  const double _t1320 = _t1282 - _t222*_t780;
  const double _t1321 = _t1298*_t793;
  const double _t1322 = _hc7[32]*_t102*_t9 - _t522;
  const double _t1323 = _t367*_t571;
  const double _t1324 = _t368*_t755;
  const double _t1325 = _t1150*_t22;
  const double _t1326 = _t370*_t571;
  const double _t1327 = _t371*_t755;
  const double _t1328 = _t101*_t751;
  const double _t1329 = _t367*_t596;
  const double _t1330 = _t347*_t755;
  const double _t1331 = _t350*_t755;
  const double _t1332 = _t1292 - _t1313*_t786 + _t201*_t368 - _t201*_t371 + _t309*_t786 - _t309*_t787 + _t367*_t549 - _t367*_t796 - _t368*_t720 - _t370*_t549 - _t370*_t722 - _t371*_t602 + _t599*_t790 - _t599*_t791 - _t603*_t787 - _t753*_t790 - _t754*_t791;
  const double _t1333 = -_t1294 - _t1295 - _t1296 - _t222*_t792;
  const double _t1334 = _t1072*_t7;
  const double _t1335 = _t1073*_t7 + _t1334;
  const double _t1336 = _t361*_t731;
  const double _t1337 = _t1310*_t731;
  const double _t1338 = _t1311 - _t616 - _t617 - _t618 + _t624;
  const double _t1339 = _t798*_t92;
  const double _t1340 = _t800*_t92;
  const double _t1341 = _t102*_t1322 - _t102*_t522 + _t1167*_t9 + _t613;
  const double _t1343 = _t371*_t757;
  const double _t1344 = _t368*_t760;
  const double _t1345 = _t806*_t92;
  const double _t1346 = _t492 - _t665 + _t666 - _t670;
  const double _t1347 = _t367*na;
  const double _t1348 = _t370*na;
  const double d4F_dna4 = 0.4e1*_t518 + _t612*(_hc6[0]*(_hc5[3]*_t809 + _hc7[2]*_t836 + 0.3e1*_t140*_t383 + 0.3e1*_t143*_t378 + _t199*_t919 + _t200*(-_hc3[9]*_t445*_t574 - _t140*_t926 + _t178*_t930 - _t195*_t920 + _t197*_t378*_t831 + _t197*_t872 + _t198*_t874 + _t32*_t836 - _t378*_t584 - _t453*_t926 + _t453*_t927 + _t455*_t928 + _t455*_t930 + _t480*_t921 + _t482*_t921 + _t485*_t880 + _t486*_t879 + _t486*_t886 + _t71*_t809 + _t72*_t868 + _t865*_t923 + _t870*_t924 + _t894*_t929 + _t899*_t929 + _t902*_t929 + _t905*_t930) - _t34*_t844 - _t34*_t846 - _t34*_t854 - 0.1232e4 / 0.9e1*_t407*_t415*_t50 + _t413*_t471 - _t458*_t845*nb + _t458*_t935 + _t475*_t839*nb + _t475*_t922 + _t487*_t856*nb - 0.12e2*_t493 - 0.2e1 / 0.3e1*_t497 + _t50*(_hc5[9]*_t378 + _hc7[18]*_t50*_t810 + _t382*_t384 - _t408*_t415 + _t50*(_hc5[19]*_t140 - _t50*_t814 + _t50*(_hc5[34]*_t50 - _t814) + _t813) - _t645*_t812) + (0.288e3 / 0.5e1)*_t500 - _t645*(_t50*_t812 + _t811*_t831 + _t830) - _t66*(_t866 + _t867 + _t869 + _t871 + _t873 + _t875 + _t881 + _t882 + _t883 + _t885 + _t887 + _t889 + _t895 + _t900 + _t903 + _t906 + _t907 + _t908) + _t69*(_t10*_t869 + _t10*_t871 + _t10*_t875 + _t10*_t883 + _t10*_t887 + _t10*_t889 + _t10*_t906 + _t10*_t907 + _t10*_t908 + _t175*_t921 + _t177*_t921 + _t38*_t836 - _t444*_t574 - _t446*_t574 - _t450*_t574 - _t454*_t574 - _t63*_t920 + _t8*_t866 + _t8*_t867 + _t8*_t873 + _t8*_t881 + _t8*_t882 + _t8*_t885 + _t8*_t895 + _t8*_t900 + _t8*_t903) - _t827*((0.3668e4 / 0.243e3)*_hc0[1]*_t399*nb + (0.140e3 / 0.81e2)*_hc0[2]*_t396*nb + (0.14e2 / 0.243e3)*_hc0[3]*_t393*nb - 0.16e2 / 0.3e1*_t391 - _t826) - 0.176e3 / 0.3e1*_t829 + (0.32e2 / 0.3e1)*_t833 + (0.4928e4 / 0.27e2)*_t835 + _t837*_t838 - _t840*_t841 + 0.9e1*_t842 - 0.216e3 / 0.5e1*_t843 + _t844*_t86 - _t844*_t862 + _t844*_t933 + _t846*_t86 - _t846*_t862 + _t846*_t933 - _t847*_t848 - _t847*_t853 + _t848*_t857 - 0.1e1 / 0.6e1*_t850 - _t851*_t852 + _t851*_t855 + _t853*_t857 + _t854*_t86 - _t854*_t862 + _t854*_t933 + (0.72e2 / 0.5e1)*_t858 - _t859 - 0.12e2*_t861 - 0.108e3 / 0.5e1*_t864 - 0.2e1 / 0.3e1*_t910 - _t911*_t912 + _t911*_t931 - _t912*_t917 - _t913*_t914 - _t914*_t916 + _t917*_t931 + (0.9e1 / 0.2e1)*_t934 + (0.288e3 / 0.5e1)*_t936 + _t942) + (0.2e1 / 0.3e1)*_t220*_t950 + (0.8e1 / 0.3e1)*_t220*_t951 - _t503*_t948 + 0.384e3*_t943 - 0.112e3 / 0.27e2*_t945 - 0.16e2 / 0.9e1*_t947 - 0.4e1 / 0.27e2*_t949 - 0.4192e4 / 0.27e2*_t952 - 0.32e2 / 0.9e1*_t954 + (0.320e3 / 0.9e1)*_t956 + _t960);
  const double d4F_dna3_dnb = _t518 + _t612*(_hc6[0]*(_hc5[3]*_t962 + (0.72e2 / 0.5e1)*_t1000 - 0.3e1*_t1002 - _t1003*_t495 - _t1003*_t496 - _t1003*_t499 - 0.3e1 / 0.4e1*_t1004 - _t1034*_t1035 - _t1036*_t193 - _t1037*_t193 + _t1038*_t461 + _t1051*_t495 + _t1051*_t496 + _t1051*_t499 + _t1052*_t458 + _t1053*_t568 + (0.72e2 / 0.5e1)*_t1054 + _t1064 + _t133*_t475 + _t139*_t383 + _t143*_t967 + _t200*(-_hc3[2]*_t1040*_t521 - _hc3[9]*_t1040*_t592 - _hc4[5]*_t1046*_t455 - _hc4[9]*_t448*_t577 + _t1006*_t72 + _t1009*_t197 - _t1012*_t198 + _t1017*_t486 + _t1018*_t485 + _t1021*_t924 + _t1023*_t923 + _t1039*_t1045 - _t1040*_t1048*_t140 - _t1044*_t925 - _t1046*_t1047 + _t1049*_t178 + _t1049*_t455 + _t1050*_t140 + _t1050*_t453 + _t139*_t927 - _t139*_t928 - _t277*_t377*gbb - _t279*_t975 + _t377*_t588 + _t378*_t593 + _t471*_t590 + _t485*_t521 + _t486*_t520 + _t71*_t962 + _t904*_t929 - _t904*_t930) + _t245*_t378 - _t251*_t975 - _t253*_t458 + _t273*_t475 - _t273*_t487 + _t276*_t990 - _t283*_t990 - _t34*_t978 - _t34*_t980 - _t34*_t981 - _t34*_t983 - _t34*_t991 - _t34*_t993 + _t348*_t487 + _t384*_t525 - _t418*_t568*nb - _t419 - _t420 - _t421 - _t425 + _t432 + _t433 + _t436 + _t438 - _t460*_t989 + _t461*_t462 + _t461*_t465 - _t463*_t852 + _t463*_t855 + _t464*_t986 - _t464*_t989 + _t477*_t579 - _t477*_t594 - _t487*_t570 - 0.9e1*_t493 - 0.1e1 / 0.2e1*_t497 + _t50*(_hc5[9]*_t521 + _t102*_t813 + _t139*_t382 + _t140*_t524 + _t50*(_hc5[19]*_t139 - _t102*_t814 + _t50*_t966) - _t645*_t964) + (0.216e3 / 0.5e1)*_t500 + _t536*_t810 + _t579*_t996 - _t594*_t697 + _t594*_t995 - _t645*(_t50*_t963 + _t50*_t964 + _t972 + _t973) - _t66*(_t1005 + _t1007 + _t1008 + _t1010 + _t1011 - _t1013 - _t1014 - _t1015 + _t1016 + _t1019 + _t1020 + _t1022 + _t1024 + _t1025 + _t1026 + _t1027 + _t1029 + _t1030 + _t1032 + _t1033) + _t69*(_t10*_t1007 - _t10*_t1013 - _t10*_t1014 - _t10*_t1015 + _t10*_t1016 + _t10*_t1022 + _t10*_t1025 + _t10*_t1026 + _t10*_t1029 + _t10*_t1030 + _t1005*_t8 + _t1008*_t8 + _t1010*_t8 + _t1011*_t8 + _t1019*_t8 + _t1020*_t8 + _t1024*_t8 + _t1027*_t8 + _t1032*_t8 + _t1033*_t8 + _t1039*_t575 - _t1040*_t554 - _t1040*_t565 - _t1040*_t567 - _t1044*_t265 - _t109*_t975 + _t266*_t471 - _t447*_t577 - _t449*_t577 - _t456*_t577 - _t457*_t577) - _t827*((0.917e3 / 0.243e3)*_hc0[1]*_t399*na + (0.917e3 / 0.81e2)*_hc0[1]*_t399*nb + (0.35e2 / 0.81e2)*_hc0[2]*_t396*na + (0.35e2 / 0.27e2)*_hc0[2]*_t396*nb + (0.7e1 / 0.486e3)*_hc0[3]*_t393*na + (0.7e1 / 0.162e3)*_hc0[3]*_t393*nb - _t897*_t968 - 0.4e1 / 0.3e1*_t969 - _t970) - 0.88e2 / 0.3e1*_t829 + (0.8e1 / 0.3e1)*_t833 + (0.1232e4 / 0.9e1)*_t835 - _t837*_t909 - _t840*_t985 + (0.9e1 / 0.2e1)*_t842 - 0.108e3 / 0.5e1*_t843 - _t847*_t911 - _t847*_t917 - 0.1e1 / 0.24e2*_t850 + _t857*_t911 + _t857*_t917 + (0.18e2 / 0.5e1)*_t858 - 0.1e1 / 0.4e1*_t859 + _t86*_t978 + _t86*_t980 + _t86*_t981 + _t86*_t983 + _t86*_t991 + _t86*_t993 - 0.9e1*_t861 - _t862*_t978 - _t862*_t981 - _t862*_t991 - 0.54e2 / 0.5e1*_t864 + _t933*_t978 + _t933*_t981 + _t933*_t991 + (0.9e1 / 0.4e1)*_t934 + (0.216e3 / 0.5e1)*_t936 + _t942 + 0.8e1*_t971 + (0.1232e4 / 0.27e2)*_t974 - 0.3e1*_t977 - 0.3e1 / 0.2e1*_t984 - _t985*_t986 - 0.1e1 / 0.6e1*_t987 - 0.1e1 / 0.12e2*_t988 + (0.1e1 / 0.4e1)*_t994 + (0.18e2 / 0.5e1)*_t997 + (0.36e2 / 0.5e1)*_t999) + (0.4e1 / 0.3e1)*_hc6[1]*_t220*_t227 + (0.1e1 / 0.3e1)*_hc6[2]*_t220*_t24 - _t1065 - _t1066*_t510 - _t1067*_t511 - 0.8e1 / 0.9e1*_t1068 - 0.1048e4 / 0.27e2*_t1069 - _t1070 - _t116*_t509 + 0.96e2*_t12*_t389*na + 0.288e3*_t12*_t389*nb + (0.80e2 / 0.9e1)*_t233*_t234*_t396*na + (0.80e2 / 0.3e1)*_t233*_t234*_t396*nb - _t503*_t93 - 0.28e2 / 0.9e1*_t945 - 0.4e1 / 0.3e1*_t947 - 0.1e1 / 0.9e1*_t949 - 0.1048e4 / 0.9e1*_t952 - 0.8e1 / 0.3e1*_t954) + 0.3e1*_t961;
  const double d4F_dna2_dnb2 = 0.2e1*_t1071 + _t612*(_hc6[0]*((0.144e3 / 0.5e1)*_t1000 - _t1001*_t1108 - _t1003*_t1109 - _t1003*_t1111 - _t1003*_t1143 + _t1003*_t543 + _t1003*_t544 - 0.1e1 / 0.2e1*_t1004 + _t1051*_t1109 + _t1051*_t1111 + _t1051*_t1143 - _t1051*_t543 - _t1051*_t544 + (0.144e3 / 0.5e1)*_t1054 - 0.352e3 / 0.9e1*_t1055 - 0.72e2 / 0.5e1*_t1056 - 0.72e2 / 0.5e1*_t1057 + _t1058*_t1081 + _t1058*_t1082 + 0.3e1*_t1059 + 0.3e1*_t1060 - 0.72e2 / 0.5e1*_t1061 + _t1062*_t1088 + _t1062*_t1092 + (0.1e1 / 0.6e1)*_t1062*_t918 + 0.3e1*_t1063 - 0.88e2 / 0.9e1*_t1076 + (0.16e2 / 0.3e1)*_t1080 + _t1081*_t34 - _t1081*_t86 + _t1081*_t862 + _t1082*_t34 - _t1082*_t86 + _t1082*_t862 - _t1083 - _t1084*_t891 - _t1084*_t892 - _t1085*_t401 - _t1085*_t979 - 0.36e2 / 0.5e1*_t1086 - _t1087*_t398 - _t1087*_t982 - _t1088*_t1112 - _t1088*_t257 - _t1088*_t932 - _t1089*_t720 - _t1090*_t913 - _t1090*_t916 + _t1091*_t276 - _t1091*_t283 - _t1092*_t1112 - _t1092*_t257 - _t1092*_t932 - _t1093*_t395 - _t1093*_t992 + _t1094*_t579 + _t1095*_t647 + _t1096*_t258 + _t1096*_t259 + (0.1e1 / 0.12e2)*_t1098 + _t1099*_t594 + _t1100*_t655 + _t1101*_t916 + _t1102*_t395 + _t1102*_t992 + _t1103*_t398 + _t1103*_t982 + (0.12e2 / 0.5e1)*_t1104 + (0.24e2 / 0.5e1)*_t1106 + _t1107*_t401 + _t1107*_t979 - _t1108*_t488 - _t1109*_t862 + _t1109*_t933 - 0.18e2 / 0.5e1*_t1110 - _t1111*_t862 + _t1111*_t933 + _t112*_t916 - _t114*_t916 - 0.1e1 / 0.2e1*_t1140 - 0.1e1 / 0.3e1*_t1141 - _t1142*_t210 - _t1142*_t212 - _t1143*_t862 + _t1143*_t933 + _t1150*_t461 + _t1151*_t1152 + _t1153*_t210 + _t1153*_t212 + (0.3e1 / 0.4e1)*_t1158 + _t1159 - _t138*_t143 + _t140*_t614 - _t143*_t376 - _t162*_t568*na - _t162*_t638*nb - _t183 - 0.1e1 / 0.18e2*_t186 - _t188*_t915 + _t193*_t599 - _t199*_t599 + _t200*(_hc3[2]*_t1144 - _hc3[9]*_t1145*_t654 + _hc4[2]*_t178*_t644 - _hc4[2]*_t520*_t646 + _hc4[5]*_t1148*_t49 - _hc4[9]*_t589*_t646 - _t101*_t1047*_t646 - _t1048*_t1147 - _t1049*_t1134 + _t1050*_t1134 + _t1113*_t923 + _t1116*_t929 + _t1119*_t924 + _t1129*_t197 + _t1129*_t198 - _t1145*_t288*_t925 + _t1154*_t902 + _t1155*_t178 + _t1156*_t520 + _t1157 + _t288*_t927 + _t301*_t928 + _t301*_t930 - _t451*_t485 + _t451*_t486 - _t485*_t878 + _t486*_t878 + _t539*_t650 + _t539*_t651 + _t585 + _t587*_t644 + _t593*_t967) + (0.24e2 / 0.5e1)*_t204 - 0.72e2 / 0.5e1*_t208 - _t210*_t912 + _t210*_t931 - _t212*_t912 + _t212*_t931 + (0.1e1 / 0.6e1)*_t213 + 0.3e1*_t217 - _t267*_t845 - _t269 + _t276*_t839 + _t283*_t856 + (0.24e2 / 0.5e1)*_t285 - 0.1e1 / 0.18e2*_t307 + _t309*_t579 - _t309*_t594 + _t309*_t647 - _t309*_t655 + _t313*_t549 - _t317*_t549 - _t317*_t722 + _t452*_t525 - 0.1e1 / 0.3e1*_t497 + _t50*(-_hc5[9]*_t138 - _hc5[9]*_t376 - _t1074*_t645 + _t1075*_t50 + 0.4e1*_t3*_t51*_t524) + (0.144e3 / 0.5e1)*_t500 + _t521*_t663 + _t539*_t621 - _t543*_t847 + _t543*_t857 - _t544*_t847 + _t544*_t857 + _t568*_t605 - _t594*_t603 - _t602*_t989 - _t603*_t655 + _t605*_t638 - _t645*(_t1074*_t50 - _t1077 - _t1078 + _t1079) + _t656*_t760 - _t66*(_t1114 + _t1115 + _t1117 + _t1118 + _t1120 + _t1121 + _t1122 + _t1123 - _t1124 + _t1125 + _t1127 + _t1128 + _t1130 + _t1131 - _t1132 + _t1133 - _t1135 + _t1136 + _t1139) + _t68*_t916 + _t69*(_hc1[2]*_t1144 + _t10*_t1120 + _t10*_t1121 + _t10*_t1122 + _t10*_t1123 + _t10*_t1127 + _t10*_t1128 + _t10*_t1131 + _t10*_t1133 - _t10*_t1135 + _t1114*_t8 + _t1115*_t8 + _t1117*_t8 + _t1118*_t8 - _t1124*_t8 + _t1125*_t8 + _t1130*_t8 - _t1132*_t8 + _t1136*_t8 - _t1145*_t631 - _t1145*_t636 - _t1147*_t566 + _t1148*_t263 + _t1149 + _t179*_t644 + _t181*_t644 + _t300*_t539 + _t304*_t539 - _t555*_t646 - _t559*_t646 - _t561*_t646 + _t576) - _t720*_t986 - _t827*((0.1834e4 / 0.243e3)*_hc0[1]*_t399*na + (0.1834e4 / 0.243e3)*_hc0[1]*_t399*nb + (0.70e2 / 0.81e2)*_hc0[2]*_t396*na + (0.70e2 / 0.81e2)*_hc0[2]*_t396*nb + (0.7e1 / 0.243e3)*_hc0[3]*_t393*na + (0.7e1 / 0.243e3)*_hc0[3]*_t393*nb + (0.4e1 / 0.3e1)*_t145*_t25 - 0.14e2 / 0.81e2*_t147 - 0.224e3 / 0.81e2*_t151 - 0.8e1 / 0.3e1*_t391 - _t826 - 0.8e1 / 0.3e1*_t969) - 0.88e2 / 0.9e1*_t829 + (0.2464e4 / 0.27e2)*_t835 + (0.3e1 / 0.2e1)*_t842 - 0.36e2 / 0.5e1*_t843 - 0.18e2 / 0.5e1*_t864 - 0.1e1 / 0.3e1*_t910 + (0.3e1 / 0.4e1)*_t934 + (0.144e3 / 0.5e1)*_t936 + (0.16e2 / 0.3e1)*_t971 + (0.2464e4 / 0.27e2)*_t974 - _t984 - 0.1e1 / 0.3e1*_t987 - 0.1e1 / 0.18e2*_t988 + (0.1e1 / 0.12e2)*_t994 + (0.12e2 / 0.5e1)*_t997 + (0.24e2 / 0.5e1)*_t999) - 0.2e1 / 0.3e1*_t1065 - 0.16e2 / 0.9e1*_t1068 - 0.2096e4 / 0.27e2*_t1069 + 0.192e3*_t1160 - 0.56e2 / 0.27e2*_t1161 - 0.8e1 / 0.9e1*_t1162 - 0.2e1 / 0.3e1*_t1163 - 0.2e1 / 0.27e2*_t1164 + (0.160e3 / 0.9e1)*_t1165 + _t220*_t739 + _t220*_t740 - 0.32e2 / 0.9e1*_t236 + (0.256e3 / 0.9e1)*_t240 + (0.4e1 / 0.9e1)*_t286*_t950 + (0.16e2 / 0.9e1)*_t286*_t951 + _t319*_t739 + _t319*_t740 - 0.96e2*_t505 + 0.192e3*_t943 - 0.56e2 / 0.27e2*_t945 - 0.8e1 / 0.9e1*_t947 - 0.2e1 / 0.27e2*_t949 - 0.2096e4 / 0.27e2*_t952 - 0.16e2 / 0.9e1*_t954 + (0.160e3 / 0.9e1)*_t956 + _t960) + 0.2e1*_t961;
  const double d4F_dna_dnb3 = 0.3e1*_t1071 + _t612*(_hc6[0]*(_hc5[3]*_t877 + (0.216e3 / 0.5e1)*_t1000 - 0.9e1*_t1002 + _t1003*_t911 + _t1003*_t917 - _t1003*_t978 - _t1003*_t981 - _t1003*_t991 - _t1036*_t313 + _t1036*_t317 - _t1037*_t313 + _t1037*_t317 - _t1051*_t911 - _t1051*_t917 + _t1051*_t978 + _t1051*_t981 + _t1051*_t991 + _t1052*_t696 + _t1053*_t638 + (0.216e3 / 0.5e1)*_t1054 + _t1064 - 0.88e2 / 0.3e1*_t1076 + 0.8e1*_t1080 - 0.3e1 / 0.2e1*_t1083 - 0.108e3 / 0.5e1*_t1086 - _t1089*_t985 - _t1090*_t1177 - _t1090*_t424 + (0.1e1 / 0.4e1)*_t1098 + _t1101*_t424 + (0.18e2 / 0.5e1)*_t1104 + (0.36e2 / 0.5e1)*_t1106 - 0.54e2 / 0.5e1*_t1110 - 0.3e1 / 0.4e1*_t1140 - _t115*_t837*_t860 - _t1151*_t849 + (0.9e1 / 0.4e1)*_t1158 + _t1159 + _t1169*_t50 - _t1170*_t245 + (0.8e1 / 0.3e1)*_t1173 - _t1174*_t34 + _t1174*_t86 - _t1175*_t34 + _t1175*_t86 + _t1176*_t464 - _t1176*_t985 - _t1178*_t460 - _t1178*_t464 + _t1179*_t313 - _t1179*_t317 - _t1180*_t34 + _t1180*_t86 + _t1181*_t655 + _t1182*_t647 + (0.9e1 / 0.2e1)*_t1183 + (0.18e2 / 0.5e1)*_t1184 - 0.1e1 / 0.4e1*_t1207 + _t1208*_t317 + _t200*(-_hc3[2]*_t645*_t662 - _hc3[9]*_t645*_t688 - _hc4[2]*_t1211 + _hc4[5]*_t101*_t1214 - _hc4[9]*_t1212*_t653 + _t1049*_t301 + _t1049*_t691 + _t1050*_t288 + _t1050*_t690 + _t1154*_t904 - _t1155*_t904 + _t1157 + _t1170*_t588 - _t1170*_t593 + _t1187*_t923 + _t1190*_t924 - _t1209*_t648 - _t1210*_t349 - _t1212*_t1215*_t49 - _t1213*_t649 - _t1216*_t288 - _t1216*_t690 - _t1217*_t904 + _t1218*_t904 + _t374*_t588 - _t374*_t593 + _t485*_t662 + _t486*_t661 + _t652*_t701 + _t71*_t877 - _t72*_t877) - _t245*_t374 - _t254*_t696 + _t273*_t705 - _t273*_t712 + _t324*_t705 + _t327*_t712 - _t34*_t495 - _t34*_t496 - _t34*_t499 - _t418*_t638*na + _t477*_t647 - _t477*_t655 - _t494 + _t495*_t86 - _t495*_t862 + _t495*_t933 + _t496*_t86 - _t496*_t862 + _t496*_t933 - _t498 + _t499*_t86 - _t499*_t862 + _t499*_t933 + _t501 - _t570*_t712 + _t614*_t904 - _t645*(_t102*_t1074 + _t1072*_t1172 + _t1171) - _t655*_t697 - _t66*(_t1139 - _t1185 + _t1186 + _t1188 + _t1189 + _t1191 + _t1192 - _t1193 + _t1194 + _t1195 + _t1196 + _t1197 + _t1198 - _t1199 - _t1201 - _t1202 + _t1204 + _t1205 + _t1206) - _t676 - _t677 - _t678 - _t679 + _t680 + _t681 + _t682 + _t683 + _t69*(-_hc2[2]*_t1211 - _t10*_t1185 + _t10*_t1191 + _t10*_t1192 + _t10*_t1194 + _t10*_t1197 + _t10*_t1198 - _t10*_t1201 - _t10*_t1202 + _t10*_t1206 + _t1149 + _t1186*_t8 + _t1188*_t8 + _t1189*_t8 - _t1193*_t8 + _t1195*_t8 + _t1196*_t8 - _t1199*_t8 + _t1204*_t8 + _t1205*_t8 - _t1209*_t642 - _t1210*_t64 - _t1212*_t633 - _t1212*_t637 - _t1213*_t643 + _t1214*_t558 + _t264*_t701 - _t645*_t686 - _t645*_t689 - _t645*_t694 - _t645*_t695) - _t827*((0.917e3 / 0.81e2)*_hc0[1]*_t399*na + (0.917e3 / 0.243e3)*_hc0[1]*_t399*nb + (0.35e2 / 0.27e2)*_hc0[2]*_t396*na + (0.35e2 / 0.81e2)*_hc0[2]*_t396*nb + (0.7e1 / 0.162e3)*_hc0[3]*_t393*na + (0.7e1 / 0.486e3)*_hc0[3]*_t393*nb - _t392 - _t896*_t968 - _t970) + (0.1232e4 / 0.27e2)*_t835 - 0.3e1*_t861 - 0.1e1 / 0.6e1*_t910 + (0.72e2 / 0.5e1)*_t936 + (0.1232e4 / 0.9e1)*_t974 - 0.9e1*_t977 - 0.1e1 / 0.2e1*_t987) + (0.4e1 / 0.3e1)*_hc6[1]*_t227*_t319 + (0.1e1 / 0.3e1)*_hc6[2]*_t24*_t319 - 0.8e1 / 0.3e1*_t1068 - 0.1048e4 / 0.9e1*_t1069 - _t1070 - 0.28e2 / 0.9e1*_t1161 - 0.4e1 / 0.3e1*_t1162 - _t1163 - 0.1e1 / 0.9e1*_t1164 + 0.288e3*_t12*_t389*na + 0.96e2*_t12*_t389*nb + (0.80e2 / 0.3e1)*_t233*_t234*_t396*na + (0.80e2 / 0.9e1)*_t233*_t234*_t396*nb - _t509*_t91 - _t510*_t946 - _t511*_t944 - _t713*_t93 - 0.1048e4 / 0.27e2*_t952 - 0.8e1 / 0.9e1*_t954) + _t714;
  const double d4F_dnb4 = _t612*(_hc6[0]*(_hc5[3]*_t1219 + _hc7[1]*_t1221 + (0.288e3 / 0.5e1)*_t1000 - 0.12e2*_t1002 - _t1003*_t844 - _t1003*_t846 + _t1003*_t848 + _t1003*_t853 - _t1003*_t854 + _t102*_t1169 - 0.1232e4 / 0.9e1*_t102*_t667*_t674 + _t1051*_t844 + _t1051*_t846 - _t1051*_t848 - _t1051*_t853 + _t1051*_t854 + (0.288e3 / 0.5e1)*_t1054 - 0.176e3 / 0.3e1*_t1076 - 0.216e3 / 0.5e1*_t1086 + _t1097*_t837 - 0.108e3 / 0.5e1*_t1110 - 0.2e1 / 0.3e1*_t1141 - _t1142*_t911 - _t1142*_t917 + _t1153*_t911 + _t1153*_t917 + (0.9e1 / 0.2e1)*_t1158 + (0.32e2 / 0.3e1)*_t1173 - _t1176*_t841 - 0.1e1 / 0.6e1*_t1178*_t459 + 0.9e1*_t1183 + (0.72e2 / 0.5e1)*_t1184 - _t1207 - _t1222*_t34 + _t1222*_t86 - _t1223*_t34 + _t1223*_t86 + _t1224*_t313 - _t1224*_t317 - _t1225*_t34 + _t1225*_t86 + _t200*(-_hc4[2]*_t641*_t661 - _hc4[5]*_t1255*_t691 - _hc4[9]*_t641*_t684 + _t1116*_t1154 + _t1154*_t1250 + _t1154*_t1252 + _t1155*_t1240 + _t1155*_t301 + _t1155*_t691 + _t1156*_t661 + _t1172*_t197*_t662 + _t1213*_t708 + _t1213*_t710 - _t1215*_t1255 + _t1217*_t691 + _t1218*_t690 + _t1219*_t71 + _t1221*_t33 + _t1226*_t924 + _t1229*_t72 + _t1231*_t923 + _t1233*_t197 + _t1235*_t198 + _t1237*_t588 + _t1244*_t593 - _t1254*_t315) - _t22*_t712*_t913 + 0.3e1*_t245*_t662 + 0.3e1*_t288*_t614 + _t317*_t919 - _t577*(_t102*_t1168 + _t1167*_t1172 + _t1220) - _t66*(_t1227 + _t1228 + _t1230 + _t1232 + _t1234 + _t1236 + _t1238 + _t1239 + _t1241 + _t1242 + _t1243 + _t1245 + _t1246 + _t1247 + _t1248 + _t1249 + _t1251 + _t1253) + _t672*_t701 + _t69*(_t10*_t1227 + _t10*_t1230 + _t10*_t1236 + _t10*_t1238 + _t10*_t1239 + _t10*_t1241 + _t10*_t1242 + _t10*_t1243 + _t10*_t1247 - _t108*_t1254 + _t1213*_t299 + _t1213*_t302 + _t1221*_t39 + _t1228*_t8 + _t1232*_t8 + _t1234*_t8 + _t1245*_t8 + _t1246*_t8 + _t1248*_t8 + _t1249*_t8 + _t1251*_t8 + _t1253*_t8 - _t641*_t685 - _t641*_t687 - _t641*_t692 - _t641*_t693) - _t696*_t845*na + _t696*_t935 + _t705*_t839*na + _t705*_t922 + _t712*_t856*na - _t712*_t922 - _t827*((0.3668e4 / 0.243e3)*_hc0[1]*_t399*na + (0.140e3 / 0.81e2)*_hc0[2]*_t396*na + (0.14e2 / 0.243e3)*_hc0[3]*_t393*na - _t826 - 0.16e2 / 0.3e1*_t969) + _t942 + (0.4928e4 / 0.27e2)*_t974 - 0.12e2*_t977 - 0.2e1 / 0.3e1*_t987) - 0.32e2 / 0.9e1*_t1068 - 0.4192e4 / 0.27e2*_t1069 + 0.384e3*_t1160 - 0.112e3 / 0.27e2*_t1161 - 0.16e2 / 0.9e1*_t1162 - 0.4e1 / 0.27e2*_t1164 + (0.320e3 / 0.9e1)*_t1165 + (0.2e1 / 0.3e1)*_t319*_t950 + (0.8e1 / 0.3e1)*_t319*_t951 - _t713*_t948 + _t960) + 0.4e1*_t714;
  const double d4F_dna3_dgaa = _t612*(_hc6[0]*(_hc7[8]*_t416 - _t1036*_t323 + _t1036*_t326 - _t1037*_t323 + _t1037*_t326 + _t1208*_t326 - _t1256*_t1257 - _t1258*_t849 - _t1259*_t723 - _t1260*_t422 - _t1260*_t426 + _t1262*_t1263 + _t1264*_t422 + _t1264*_t426 + (0.9e1 / 0.4e1)*_t1266 + (0.9e1 / 0.4e1)*_t1268 + _t1269 + _t1270 + _t200*(_t1261*_t195 + _t1265*_t445 + _t140*_t772 + _t378*_t724 + _t453*_t772 - _t478 - _t481 - _t483) + _t323*_t990 - _t326*_t990 + _t384*_t716 - _t409 - _t414 + _t477*_t723 - _t477*_t726 + _t50*(_t379 - _t380*_t50 + _t50*(_hc7[33]*_t50*_t7 - _t380) + _t7*_t811) + _t69*(_t1261*_t63 + _t444*_t7 + _t446*_t7 + _t450*_t7 + _t454*_t7 - _t469 - _t473 - _t474) - _t697*_t726 + _t7*_t830 + _t723*_t996 + _t726*_t995) + (0.4e1 / 0.3e1)*_hc6[1]*_t227*_t337 + (0.1e1 / 0.3e1)*_hc6[2]*_t24*_t337 - _t1271 - _t1277) + 0.3e1*_t742;
  const double d4F_dna3_dgab = _t612*(_hc6[0]*(-_t1278 + 0.16e2*_t155*_t77 - 0.2e1*_t404 - 0.176e3 / 0.3e1*_t410) - _t1279 + _t1280*_t343 + _t1281*_t343 + _t1282) + 0.3e1*_t748;
  const double d4F_dna3_dgbb = _t612*(_hc6[0]*(-_t1177*_t350 - _t1257*_t347 - _t1259*_t750 + _t1262*_t1288 + _t1269 + _t1283*_t384 + (0.1e1 / 0.8e1)*_t1284 + (0.9e1 / 0.4e1)*_t1285 + (0.9e1 / 0.4e1)*_t1289 + _t1292 + _t131*_t462 + _t131*_t465 - _t134*_t462 - _t134*_t465 + _t200*(_t1286*_t448 + _t1287*_t178 + _t1287*_t455 + _t369*_t377) + _t346*_t378 + _t347*_t424 - _t350*_t424 - _t462*_t788 + _t462*_t789 - _t465*_t788 + _t465*_t789 + _t477*_t750 - _t477*_t752 + _t50*(_hc7[32]*_t176*_t9 + _t140*_t749) + _t69*(_t447*_t9 + _t449*_t9 + _t456*_t9 + _t457*_t9) - _t697*_t752 + _t750*_t996 + _t752*_t995) + (0.4e1 / 0.3e1)*_hc6[1]*_t227*_t358 + (0.1e1 / 0.3e1)*_hc6[2]*_t24*_t358 - _t1293 - _t1297) + 0.3e1*_t765;
  const double d4F_dna2_dnb_dgaa = _t1299 + _t612*(_hc6[0]*(_t1095*_t771 + _t1100*_t773 + _t1152*_t1258 - _t1256*_t720 - _t1260*_t543 - _t1260*_t544 + _t1263*_t1305 + _t1264*_t543 + _t1264*_t544 + (0.3e1 / 0.2e1)*_t1266 + (0.3e1 / 0.2e1)*_t1268 + (0.1e1 / 0.24e2)*_t1300 + (0.3e1 / 0.4e1)*_t1301 - _t1302*_t543 - _t1302*_t544 - _t1303*_t723 + _t1307*_t543 + _t1307*_t544 - _t1308*_t210 - _t1308*_t212 + _t1309*_t210 + _t1309*_t212 + _t1310*_t736 + _t1312 + _t1314 + _t133*_t723 + _t139*_t716 + _t160*_t251 + _t200*(-_t1045*_t1304 + _t1265*_t592 + _t1306*_t140 + _t160*_t279 + _t452*_t772 + _t521*_t724 - _t591) + _t210*_t334 - _t210*_t335 + _t212*_t334 - _t212*_t335 + _t273*_t723 - _t273*_t726 + _t323*_t549 - _t326*_t549 - _t326*_t722 + _t348*_t726 + _t361*_t733 + _t50*(_hc7[33]*_t102*_t322 - _t102*_t380 + _t7*_t963) - _t537 - _t570*_t726 + _t69*(_t109*_t160 - _t1304*_t575 + _t554*_t7 + _t556*_t7 + _t565*_t7 + _t567*_t7 - _t578) + _t7*_t972 + _t7*_t973 + _t717 + _t718) - 0.1e1 / 0.3e1*_t1271 + _t1315*_t337 + _t1316*_t337 + _t1317 + _t363*_t739 + _t363*_t740) + _t742;
  const double d4F_dna2_dnb_dgab = _t1318 + _t612*(_hc6[0]*(-_t1319 + (0.16e2 / 0.3e1)*_t155*_t77 - 0.352e3 / 0.9e1*_t410 - 0.2e1*_t531 - _t617) - 0.1e1 / 0.3e1*_t1279 + _t1315*_t343 + _t1316*_t343 + _t1320 + _t365*_t739 + _t365*_t740) + _t748;
  const double d4F_dna2_dnb_dgbb = _t1321 + _t612*(_hc6[0]*(_t1095*_t786 + _t1100*_t787 + _t1283*_t139 + (0.1e1 / 0.12e2)*_t1284 + (0.3e1 / 0.2e1)*_t1285 + _t1288*_t1305 + (0.3e1 / 0.2e1)*_t1289 + _t1290*_t543 + _t1290*_t544 - _t1291*_t543 - _t1291*_t544 - _t1303*_t750 + _t1312 - _t1323*_t210 - _t1323*_t212 - _t1324*_t210 - _t1324*_t212 + _t1325*_t370 + _t1326*_t210 + _t1326*_t212 + _t1327*_t210 + _t1327*_t212 + (0.3e1 / 0.4e1)*_t1329 + _t133*_t750 - _t1330*_t543 - _t1330*_t544 + _t1331*_t543 + _t1331*_t544 + _t1332 + _t140*_t782 + _t168*_t790 + _t200*(-_t106*_t587 + _t1286*_t589 - _t1287*_t452 + _t1328*_t178 + _t369*_t520 - _t586) + _t201*_t347 - _t201*_t350 + _t273*_t750 - _t273*_t752 + _t346*_t521 - _t347*_t720 + _t348*_t752 - _t350*_t602 + _t368*_t761 + _t371*_t758 + _t50*(_t1322*_t50 + _t139*_t749) + _t547*_t791 - _t570*_t752 + _t69*(-_t106*_t179 - _t106*_t181 + _t555*_t9 - _t557*_t9 + _t559*_t9 + _t561*_t9)) - 0.1e1 / 0.3e1*_t1293 + _t1315*_t358 + _t1316*_t358 + _t1333 + _t372*_t739 + _t372*_t740) + _t765;
  const double d4F_dna_dnb2_dgaa = _t1299 + _t612*(_hc6[0]*(-_t1077*_t7 - _t1078*_t7 + _t1079*_t7 + _t1094*_t771 + _t1099*_t773 - _t1260*_t210 - _t1260*_t212 + _t1264*_t210 + _t1264*_t212 + (0.3e1 / 0.4e1)*_t1266 + _t1267*_t736 + (0.1e1 / 0.12e2)*_t1300 + (0.3e1 / 0.2e1)*_t1301 - _t1302*_t210 - _t1302*_t212 - _t1303*_t794 + _t1305*_t1336 + _t1307*_t210 + _t1307*_t212 - _t1308*_t543 - _t1308*_t544 + _t1309*_t543 + _t1309*_t544 + _t1314 + _t1325*_t326 + _t1335*_t50 + (0.3e1 / 0.2e1)*_t1337 + _t1338 + _t168*_t774 + _t200*(0.4e1*_hc3[5]*_t102*_t3*_t51*_t7 + _hc3[5]*_t288*_t50*_t7 + _hc3[9]*_t303*_t634*_t7 - _t138*_t724 - _t376*_t724 - _t61*_t650 - _t61*_t651) + _t201*_t360 - _t201*_t361 + _t273*_t794 - _t273*_t795 + _t324*_t794 + _t327*_t795 + _t328*_t733 + _t334*_t543 + _t334*_t544 - _t335*_t543 - _t335*_t544 - _t360*_t720 - _t361*_t602 + _t547*_t775 - _t570*_t795 - _t622 + _t69*(0.4e1*_hc1[5]*_t102*_t3*_t51*_t7 + _hc1[5]*_t288*_t50*_t7 + _hc1[9]*_t303*_t634*_t7 - _t300*_t61 - _t304*_t61 - _t625*_t7 - _t627*_t7)) + _t1315*_t363 + _t1316*_t363 + _t1317 - 0.1e1 / 0.3e1*_t1339 + _t337*_t739 + _t337*_t740) + _t799;
  const double d4F_dna_dnb2_dgab = _t1318 + _t612*(_hc6[0]*(-_t1319 + (0.16e2 / 0.3e1)*_t289*_t77 - _t532 - 0.352e3 / 0.9e1*_t533 - 0.2e1*_t616) + _t1315*_t365 + _t1316*_t365 + _t1320 - 0.1e1 / 0.3e1*_t1340 + _t343*_t739 + _t343*_t740) + _t801;
  const double d4F_dna_dnb2_dgbb = _t1321 + _t612*(_hc6[0]*(_t1094*_t786 + _t1099*_t787 + (0.1e1 / 0.12e2)*_t1152*_t370 + (0.1e1 / 0.24e2)*_t1284 + (0.3e1 / 0.4e1)*_t1285 + _t1290*_t210 + _t1290*_t212 - _t1291*_t210 - _t1291*_t212 - _t1303*_t804 + _t1305*_t1343 - _t1323*_t543 - _t1323*_t544 - _t1324*_t543 - _t1324*_t544 + _t1326*_t543 + _t1326*_t544 + _t1327*_t543 + _t1327*_t544 + (0.3e1 / 0.2e1)*_t1329 - _t1330*_t210 - _t1330*_t212 + _t1331*_t210 + _t1331*_t212 + _t1332 + _t1338 + _t1341*_t50 + (0.3e1 / 0.2e1)*_t1344 - _t138*_t346 + _t200*(_t1286*_t653 + _t1287*_t301 - _t1328*_t452 + _t1342*_t649 + _t138*_t369 + _t293*_t349 - _t311*_t652 + _t369*_t376) + _t273*_t804 - _t273*_t805 + _t324*_t804 + _t327*_t805 - _t346*_t376 + _t347*_t761 + _t350*_t758 + _t367*_t599 - _t367*_t753 - _t370*_t599 - _t370*_t754 + _t452*_t782 - _t570*_t805 + _t69*(_t1342*_t643 - _t264*_t311 + _t293*_t64 + _t626*_t9 + _t628*_t9 - _t629*_t9 + _t633*_t9 + _t637*_t9) + _t802 + _t803) + _t1315*_t372 + _t1316*_t372 + _t1333 - 0.1e1 / 0.3e1*_t1345 + _t358*_t739 + _t358*_t740) + _t807;
  const double d4F_dnb3_dgaa = _t612*(_hc6[0]*(_t102*_t1335 + _t1171*_t7 + _t1172*_t1334 - _t1177*_t361 + _t1181*_t795 + _t1182*_t794 + _t121*_t462 + _t121*_t465 - _t123*_t462 - _t123*_t465 - _t1257*_t360 - _t1259*_t794 + _t1262*_t1336 + _t1270 + (0.1e1 / 0.8e1)*_t1300 + (0.9e1 / 0.4e1)*_t1301 - _t1308*_t422 - _t1308*_t426 + _t1309*_t422 + _t1309*_t426 + (0.9e1 / 0.4e1)*_t1337 + _t1346 + _t200*(_t1265*_t688 + _t1306*_t288 + _t1306*_t690 + _t662*_t724) + _t360*_t424 - _t361*_t424 + _t477*_t794 - _t477*_t795 + _t69*(_t686*_t7 + _t689*_t7 + _t694*_t7 + _t695*_t7) - _t697*_t795) + (0.4e1 / 0.3e1)*_hc6[1]*_t227*_t363 + (0.1e1 / 0.3e1)*_hc6[2]*_t24*_t363 - _t1277 - _t1339) + 0.3e1*_t799;
  const double d4F_dnb3_dgab = _t612*(_hc6[0]*(-_t1278 + 0.16e2*_t289*_t77 - 0.176e3 / 0.3e1*_t533 - 0.2e1*_t665) + _t1280*_t365 + _t1281*_t365 + _t1282 - _t1340) + 0.3e1*_t801;
  const double d4F_dnb3_dgbb = _t612*(_hc6[0]*(_hc7[7]*_t675 + _t102*_t1341 - _t1036*_t367 + _t1036*_t370 - _t1037*_t367 + _t1037*_t370 + _t1166*_t782 - _t1177*_t1348 + _t1181*_t805 + _t1182*_t804 + _t1208*_t370 + _t1220*_t9 - _t1257*_t1347 - _t1259*_t804 + _t1262*_t1343 + _t1292 + (0.9e1 / 0.4e1)*_t1329 + (0.9e1 / 0.4e1)*_t1344 + _t1346 + _t1347*_t424 - _t1348*_t424 + _t200*(_t1286*_t684 + _t1328*_t301 + _t1328*_t691 + _t315*_t700 + _t369*_t661 - _t707 - _t709 - _t711) - _t462*_t784 + _t462*_t785 - _t465*_t784 + _t465*_t785 + _t477*_t804 - _t477*_t805 - _t669 - _t673 + _t69*(_t108*_t700 + _t685*_t9 + _t687*_t9 + _t692*_t9 + _t693*_t9 - _t699 - _t703 - _t704) - _t697*_t805) + (0.4e1 / 0.3e1)*_hc6[1]*_t227*_t372 + (0.1e1 / 0.3e1)*_hc6[2]*_t24*_t372 - _t1297 - _t1345) + 0.3e1*_t807;
  const double d4F_dna2_dgaa2 = 0;
  const double d4F_dna2_dgaa_dgbb = 0;
  const double d4F_dna2_dgbb2 = 0;
  const double d4F_dna_dnb_dgaa2 = 0;
  const double d4F_dna_dnb_dgaa_dgbb = 0;
  const double d4F_dna_dnb_dgbb2 = 0;
  const double d4F_dnb2_dgaa2 = 0;
  const double d4F_dnb2_dgaa_dgbb = 0;
  const double d4F_dnb2_dgbb2 = 0;
  const double d4F_dna_dgaa3 = 0;
  const double d4F_dna_dgaa2_dgbb = 0;
  const double d4F_dna_dgaa_dgbb2 = 0;
  const double d4F_dna_dgbb3 = 0;
  const double d4F_dnb_dgaa3 = 0;
  const double d4F_dnb_dgaa2_dgbb = 0;
  const double d4F_dnb_dgaa_dgbb2 = 0;
  const double d4F_dnb_dgbb3 = 0;
  const double d4F_dgaa4 = 0;
  const double d4F_dgaa3_dgbb = 0;
  const double d4F_dgaa2_dgbb2 = 0;
  const double d4F_dgaa_dgbb3 = 0;
  const double d4F_dgbb4 = 0;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 1] += d4F_dna3_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 2] += d4F_dna3_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 3] += d4F_dna2_dnb_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 4] += d4F_dna2_dnb_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 5] += d4F_dna2_dnb_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 6] += d4F_dna_dnb2_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 7] += d4F_dna_dnb2_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 8] += d4F_dna_dnb2_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 9] += d4F_dnb3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 10] += d4F_dnb3_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 2] += d4F_dna2_dgaa_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 5] += d4F_dna2_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 6] += d4F_dna_dnb_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 8] += d4F_dna_dnb_dgaa_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 11] += d4F_dna_dnb_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 12] += d4F_dnb2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 14] += d4F_dnb2_dgaa_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 2] += d4F_dna_dgaa2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 5] += d4F_dna_dgaa_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 9] += d4F_dna_dgbb3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 10] += d4F_dnb_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 12] += d4F_dnb_dgaa2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 15] += d4F_dnb_dgaa_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 2] += d4F_dgaa3_dgbb;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 5] += d4F_dgaa2_dgbb2;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 9] += d4F_dgaa_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
#endif
#endif
}
#endif