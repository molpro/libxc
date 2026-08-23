/*
  Generated from python/lda_exc/lda_c_gk72.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_gk72
*/

#ifndef _LDA_C_GK72_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_GK72_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_GK72_HELPER_BODIES
#include "lda_c_gk72.c"
#undef _LDA_C_GK72_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_GK72_HELPER_BODIES
#include "lda_c_gk72.c"
#undef _LDA_C_GK72_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_GK72_HELPER_BODIES
#include "lda_c_gk72.c"
#undef _LDA_C_GK72_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_GK72_HELPER_BODIES
#include "lda_c_gk72.c"
#undef _LDA_C_GK72_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_GK72_HELPER_BODIES
#include "lda_c_gk72.c"
#undef _LDA_C_GK72_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_gk72.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_gk72.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_gk72.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_gk72.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_gk72.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_gk72.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_gk72.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_gk72.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_gk72.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_gk72.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_GK72_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_ls_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  const double _t1 = log(rs);
  const double _t2 = 0.0089999999999999993*_t1;
#if _KMAX >= 1
  const double _t3 = (0.1e1 / rs);
#endif
#if _KMAX >= 2
  const double _t4 = (0.1e1 / (rs * rs));
#endif
#if _KMAX >= 3
  const double _t5 = (0.1e1 / (rs * rs * rs));
#endif

  const double f = 0.031099999999999999*_t1 + _t2*rs - 0.01*rs - 0.048000000000000001;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = 0;
  out[1] = df_dzeta;
  const double df_drs = _t2 + 0.031099999999999999*_t3 - 0.0010000000000000009;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = 0;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = 0;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = 0.0089999999999999993*_t3 - 0.031099999999999999*_t4;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = 0;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = 0;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = 0;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = -0.0089999999999999993*_t4 + 0.062199999999999998*_t5;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dzeta4 = 0;
  out[10] = d4f_dzeta4;
  const double d4f_drs_dzeta3 = 0;
  out[11] = d4f_drs_dzeta3;
  const double d4f_drs2_dzeta2 = 0;
  out[12] = d4f_drs2_dzeta2;
  const double d4f_drs3_dzeta = 0;
  out[13] = d4f_drs3_dzeta;
  const double d4f_drs4 = 0.017999999999999999*_t5 - 0.18659999999999999/(rs * rs * rs * rs);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_ms_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {


  const double f = 0.01898*log(rs) - 0.061559999999999997;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = 0;
  out[1] = df_dzeta;
  const double df_drs = 0.01898/rs;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = 0;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = 0;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = -0.01898/(rs * rs);
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = 0;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = 0;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = 0;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = 0.037960000000000001/(rs * rs * rs);
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dzeta4 = 0;
  out[10] = d4f_dzeta4;
  const double d4f_drs_dzeta3 = 0;
  out[11] = d4f_drs_dzeta3;
  const double d4f_drs2_dzeta2 = 0;
  out[12] = d4f_drs2_dzeta2;
  const double d4f_drs3_dzeta = 0;
  out[13] = d4f_drs3_dzeta;
  const double d4f_drs4 = -0.11388000000000001/(rs * rs * rs * rs);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_hs_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  const double _t1 = xc_powr(rs, -5, 2);
  const double _t2 = (0.1e1 / (rs * rs));
#if _KMAX >= 1
  const double _t3 = xc_powr(rs, -7, 2);
  const double _t4 = (0.1e1 / (rs * rs * rs));
#endif
#if _KMAX >= 2
  const double _t5 = xc_powr(rs, -9, 2);
  const double _t6 = (0.1e1 / (rs * rs * rs * rs));
#endif
#if _KMAX >= 3
  const double _t7 = xc_powr(rs, -11, 2);
  const double _t8 = xc_powi(rs, -5);
#endif

  const double f = -0.40000000000000002*_t1 - 1.47*_t2 - 0.438/rs + 1.325/xc_powr(rs, 3, 2);
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = 0;
  out[1] = df_dzeta;
  const double df_drs = -1.9874999999999998*_t1 + 0.438*_t2 + 1.0*_t3 + 2.9399999999999999*_t4;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = 0;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = 0;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = 4.96875*_t3 - 0.876*_t4 - 3.5*_t5 - 8.8200000000000003*_t6;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = 0;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = 0;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = 0;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = -17.390625*_t5 + 2.6280000000000001*_t6 + 15.75*_t7 + 35.280000000000001*_t8;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dzeta4 = 0;
  out[10] = d4f_dzeta4;
  const double d4f_drs_dzeta3 = 0;
  out[11] = d4f_drs_dzeta3;
  const double d4f_drs2_dzeta2 = 0;
  out[12] = d4f_drs2_dzeta2;
  const double d4f_drs3_dzeta = 0;
  out[13] = d4f_drs3_dzeta;
  const double d4f_drs4 = 78.2578125*_t7 - 10.512*_t8 - 176.40000000000001/xc_powi(rs, 6) - 86.625/xc_powr(rs, 13, 2);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_ls_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = log(rs);
  const double _t2 = 0.0089999999999999993*_t1;
#if _KMAX >= 1
  const double _t3 = (0.1e1 / rs);
#endif
#if _KMAX >= 2
  const double _t4 = (0.1e1 / (rs * rs));
#endif
#if _KMAX >= 3
  const double _t5 = (0.1e1 / (rs * rs * rs));
#endif

  const double f = 0.031099999999999999*_t1 + _t2*rs - 0.01*rs - 0.048000000000000001;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t2 + 0.031099999999999999*_t3 - 0.0010000000000000009;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.0089999999999999993*_t3 - 0.031099999999999999*_t4;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.0089999999999999993*_t4 + 0.062199999999999998*_t5;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.017999999999999999*_t5 - 0.18659999999999999/(rs * rs * rs * rs);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_ms_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {


  const double f = 0.01898*log(rs) - 0.061559999999999997;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.01898/rs;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -0.01898/(rs * rs);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.037960000000000001/(rs * rs * rs);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -0.11388000000000001/(rs * rs * rs * rs);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_hs_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(rs, -5, 2);
  const double _t2 = (0.1e1 / (rs * rs));
#if _KMAX >= 1
  const double _t3 = xc_powr(rs, -7, 2);
  const double _t4 = (0.1e1 / (rs * rs * rs));
#endif
#if _KMAX >= 2
  const double _t5 = xc_powr(rs, -9, 2);
  const double _t6 = (0.1e1 / (rs * rs * rs * rs));
#endif
#if _KMAX >= 3
  const double _t7 = xc_powr(rs, -11, 2);
  const double _t8 = xc_powi(rs, -5);
#endif

  const double f = -0.40000000000000002*_t1 - 1.47*_t2 - 0.438/rs + 1.325/xc_powr(rs, 3, 2);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -1.9874999999999998*_t1 + 0.438*_t2 + 1.0*_t3 + 2.9399999999999999*_t4;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 4.96875*_t3 - 0.876*_t4 - 3.5*_t5 - 8.8200000000000003*_t6;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -17.390625*_t5 + 2.6280000000000001*_t6 + 15.75*_t7 + 35.280000000000001*_t8;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 78.2578125*_t7 - 10.512*_t8 - 176.40000000000001/xc_powi(rs, 6) - 86.625/xc_powr(rs, 13, 2);
  out[4] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = M_CBRTPI;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = xc_powr(na, 1, 3);
  const double _t5 = _t3/_t4;
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
  const double _t7 = _t1*_t6;
  const double _t8 = _t2*_t4;
  const double _t9 = 1.0*_t5*(0.5*_t1 - 0.69999999999999996*_t8) < 0;
  const double _t10 = _t6*(_t1 - 0.20e2*_t8) < 0;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_ls_zeta0_k, _KMAX)(p, _t7, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_ms_zeta0_k, _KMAX)(p, _t7, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_hs_zeta0_k, _KMAX)(p, _t7, _hc2);
  const double _t11 = my_piecewise5(_t9, _hc0[0], _t10, _hc1[0], _hc2[0]);
  const double zk = _t11;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t12 = _t1*_t3;
  const double _t14 = (0.1e1 / 0.6e1)/xc_powr(na, 4, 3);
  const double _t15 = _t12*_t14;
  const double _t13 = _hc0[1]*_t12;
  const double _t16 = my_piecewise5(_t9, -_t13*_t14, _t10, -_hc1[1]*_t15, -_hc2[1]*_t15);
  const double dF_dna = _t11 + _t16*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t17 = (0.2e1 / 0.9e1)/xc_powr(na, 7, 3);
  const double _t18 = xc_powr(0.6e1, 2, 3)/(M_CBRTPI * M_CBRTPI);
  const double _t20 = (0.1e1 / 0.36e2)/xc_powr(na, 8, 3);
  const double _t21 = _t12*_t17;
  const double _t22 = _t18*_t20;
  const double _t19 = _hc0[2]*_t18;
  const double _t23 = my_piecewise5(_t9, _t13*_t17 + _t19*_t20, _t10, _hc1[1]*_t21 + _hc1[2]*_t22, _hc2[1]*_t21 + _hc2[2]*_t22);
  const double d2F_dna2 = 0.2e1*_t16 + _t23*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t24 = (0.1e1 / M_PI);
  const double _t26 = (0.1e1 / 0.36e2)/(na * na * na * na);
  const double _t27 = (0.14e2 / 0.27e2)/xc_powr(na, 10, 3);
  const double _t28 = (0.1e1 / 0.9e1)/xc_powr(na, 11, 3);
  const double _t29 = _t24*_t26;
  const double _t30 = _t12*_t27;
  const double _t31 = _t18*_t28;
  const double _t25 = _hc0[3]*_t24;
  const double _t32 = my_piecewise5(_t9, -_t13*_t27 - _t19*_t28 - _t25*_t26, _t10, -_hc1[1]*_t30 - _hc1[2]*_t31 - _hc1[3]*_t29, -_hc2[1]*_t30 - _hc2[2]*_t31 - _hc2[3]*_t29);
  const double d3F_dna3 = 0.3e1*_t23 + _t32*na;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double _t33 = (0.2e1 / 0.9e1)/xc_powi(na, 5);
  const double _t34 = (0.1e1 / 0.216e3)*_t1/((M_PI * M_CBRTPI)*xc_powr(na, 16, 3));
  const double _t35 = (0.140e3 / 0.81e2)/xc_powr(na, 13, 3);
  const double _t36 = (0.40e2 / 0.81e2)/xc_powr(na, 14, 3);
  const double _t37 = _t24*_t33;
  const double _t38 = _t12*_t35;
  const double _t39 = _t18*_t36;
  const double d4F_dna4 = 0.4e1*_t32 + na*my_piecewise5(_t9, _hc0[4]*_t34 + _t13*_t35 + _t19*_t36 + _t25*_t33, _t10, _hc1[1]*_t38 + _hc1[2]*_t39 + _hc1[3]*_t37 + _hc1[4]*_t34, _hc2[1]*_t38 + _hc2[2]*_t39 + _hc2[3]*_t37 + _hc2[4]*_t34);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = M_CBRTPI;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = na + nb;
  const double _t5 = xc_powr(_t4, 1, 3);
  const double _t6 = _t3/_t5;
  const double _t7 = (0.1e1 / 0.2e1)*_t6;
  const double _t8 = _t1*_t7;
  const double _t9 = _t2*_t5;
  const double _t10 = 1.0*_t6*(0.5*_t1 - 0.69999999999999996*_t9) < 0;
  const double _t11 = _t7*(_t1 - 0.20e2*_t9) < 0;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_ls_k, _KMAX)(p, _t8, 0, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_ms_k, _KMAX)(p, _t8, 0, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_hs_k, _KMAX)(p, _t8, 0, _hc2);
  const double _t12 = my_piecewise5(_t10, _hc0[0], _t11, _hc1[0], _hc2[0]);
  const double zk = _t12;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t13 = _t1*_t3;
  const double _t15 = (0.1e1 / 0.6e1)/xc_powr(_t4, 4, 3);
  const double _t16 = _t13*_t15;
  const double _t14 = _hc0[2]*_t13;
  const double _t17 = my_piecewise5(_t10, -_t14*_t15, _t11, -_hc1[2]*_t16, -_hc2[2]*_t16);
  const double _t18 = _t12 + _t17*_t4;
  const double dF_dna = _t18;
  const double dF_dnb = _t18;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t19 = xc_powr(_t4, -7, 3);
  const double _t20 = (0.2e1 / 0.9e1)*_t19;
  const double _t21 = xc_powr(0.6e1, 2, 3)/(M_CBRTPI * M_CBRTPI);
  const double _t23 = (0.1e1 / 0.36e2)/xc_powr(_t4, 8, 3);
  const double _t24 = _t13*_t20;
  const double _t25 = _t21*_t23;
  const double _t22 = _hc0[5]*_t21;
  const double _t26 = my_piecewise5(_t10, _t14*_t20 + _t22*_t23, _t11, _hc1[2]*_t24 + _hc1[5]*_t25, _hc2[2]*_t24 + _hc2[5]*_t25);
  const double _t27 = 0.2e1*_t17 + _t26*_t4;
  const double d2F_dna2 = _t27;
  const double d2F_dna_dnb = _t27;
  const double d2F_dnb2 = _t27;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t28 = (0.14e2 / 0.27e2)/xc_powr(_t4, 10, 3);
  const double _t29 = (0.2e1 / 0.27e2)/xc_powr(_t4, 11, 3);
  const double _t31 = _t13*_t28;
  const double _t32 = _t21*_t29;
  const double _t30 = _hc0[5]*_t24 + _hc0[9]*_t25;
  const double _t33 = _hc1[5]*_t24 + _hc1[9]*_t25;
  const double _t34 = _hc2[5]*_t24 + _hc2[9]*_t25;
  const double _t35 = my_piecewise5(_t10, -_t14*_t28 - _t16*_t30 - _t22*_t29, _t11, -_hc1[2]*_t31 - _hc1[5]*_t32 - _t16*_t33, -_hc2[2]*_t31 - _hc2[5]*_t32 - _t16*_t34);
  const double _t36 = 0.3e1*_t26 + _t35*_t4;
  const double d3F_dna3 = _t36;
  const double d3F_dna2_dnb = _t36;
  const double d3F_dna_dnb2 = _t36;
  const double d3F_dnb3 = _t36;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t37 = (0.140e3 / 0.81e2)/xc_powr(_t4, 13, 3);
  const double _t38 = (0.7e1 / 0.27e2)/xc_powr(_t4, 14, 3);
  const double _t39 = (0.2e1 / 0.3e1)*_t13*_t19;
  const double _t40 = _t13*_t37;
  const double _t41 = _t21*_t38;
  const double _t42 = 0.4e1*_t35 + _t4*my_piecewise5(_t10, _t14*_t37 - _t16*(-_hc0[5]*_t31 - _hc0[9]*_t32 - _t16*(_hc0[14]*_t25 + _hc0[9]*_t24)) + _t22*_t38 + _t30*_t39, _t11, _hc1[2]*_t40 + _hc1[5]*_t41 - _t16*(-_hc1[5]*_t31 - _hc1[9]*_t32 - _t16*(_hc1[14]*_t25 + _hc1[9]*_t24)) + _t33*_t39, _hc2[2]*_t40 + _hc2[5]*_t41 - _t16*(-_hc2[5]*_t31 - _hc2[9]*_t32 - _t16*(_hc2[14]*_t25 + _hc2[9]*_t24)) + _t34*_t39);
  const double d4F_dna4 = _t42;
  const double d4F_dna3_dnb = _t42;
  const double d4F_dna2_dnb2 = _t42;
  const double d4F_dna_dnb3 = _t42;
  const double d4F_dnb4 = _t42;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif