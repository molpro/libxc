/*
  Generated from python/lda_exc/lda_c_2d_prm.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_2d_prm
*/

#ifndef _LDA_C_2D_PRM_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_2D_PRM_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_2D_PRM_HELPER_BODIES
#include "lda_c_2d_prm.c"
#undef _LDA_C_2D_PRM_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_2D_PRM_HELPER_BODIES
#include "lda_c_2d_prm.c"
#undef _LDA_C_2D_PRM_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_2D_PRM_HELPER_BODIES
#include "lda_c_2d_prm.c"
#undef _LDA_C_2D_PRM_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_2D_PRM_HELPER_BODIES
#include "lda_c_2d_prm.c"
#undef _LDA_C_2D_PRM_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_2D_PRM_HELPER_BODIES
#include "lda_c_2d_prm.c"
#undef _LDA_C_2D_PRM_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_2d_prm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_2d_prm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_2d_prm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_2d_prm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_2d_prm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_2d_prm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_2d_prm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_2d_prm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_2d_prm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_2d_prm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_2D_PRM_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(beta_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(M_PI, -1, 2);
  const double _t2 = 3.9274*_t1;

  const double f = _t2/rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_t2/(rs * rs);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 7.8548*_t1/(rs * rs * rs);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -23.564399999999999*_t1/(rs * rs * rs * rs);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 94.257599999999996*_t1/xc_powi(rs, 5);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(phi_m1_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(beta_k, _KMAX)(p, rs, _hc0);
  const double _t1 = xc_powr(M_PI, 1, 2);
  const double _t2 = 0.2e1*_hc0[0] + _t1;
#if _KMAX >= 1
  const double _t3 = _hc0[1]*_t1;
  const double _t4 = (0.1e1 / (_t2 * _t2));
  const double _t5 = 0.2e1*_t4;
#endif
#if _KMAX >= 2
  const double _t6 = ((_hc0[1]) * (_hc0[1]));
  const double _t7 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t8 = _t1*_t7;
#endif
#if _KMAX >= 3
  const double _t9 = _t3*_t7;
  const double _t10 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
#endif

  const double f = -_t1/_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t3*_t5;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.2e1*_hc0[2]*_t1*_t4 - 0.8e1*_t6*_t8;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.48e2*((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t1*_t10 - 0.24e2*_hc0[2]*_t9 + _hc0[3]*_t1*_t5;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -0.384e3*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t1/xc_powi(_t2, 5) - 0.24e2*((_hc0[2]) * (_hc0[2]))*_t8 + 0.288e3*_hc0[2]*_t1*_t10*_t6 - 0.32e2*_hc0[3]*_t9 + 0.2e1*_hc0[4]*_t1*_t4;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(phi_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(phi_m1_k, _KMAX)(p, rs, _hc0);

  const double f = _hc0[0] + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _hc0[1];
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc0[2];
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = _hc0[3];
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _hc0[4];
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {
  const lda_c_2d_prm_params *params = (const lda_c_2d_prm_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(phi_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(phi_m1_k, _KMAX)(p, rs, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(beta_k, _KMAX)(p, rs, _hc2);
  const double _t1 = params->c + 0.1e1;
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = params->c + 0.2e1;
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = _hc0[0]*_t4;
  const double _t6 = xc_powr(_t1, -1, 2);
  const double _t7 = xc_powr(M_PI, 1, 2);
  const double _t8 = _hc1[0]*_t7;
  const double _t9 = _t6*_t8;
  const double _t10 = (0.1e1 / 0.2e1)*_t8;
  const double _t11 = xc_powr(_t3, -1, 2);
  const double _t12 = _hc2[0]*_t11;
  const double _t13 = pow(_t3, -1.5)*_t7;
  const double _t14 = _t13/_hc2[0];
  const double _t15 = ((_hc0[0]) * (_hc0[0]));
  const double _t16 = (0.1e1 / 0.4e1)*_t15;
#if _KMAX >= 1
  const double _t17 = _hc1[0]*_t4;
  const double _t18 = _hc1[1]*_t7;
  const double _t19 = _hc2[0]*_t6;
  const double _t20 = _hc2[1]*_t11;
  const double _t21 = (0.1e1 / 0.2e1)*_t12;
  const double _t22 = (0.1e1 / 0.2e1)*_t14;
  const double _t23 = _hc0[0]*_t22;
  const double _t24 = _t13/((_hc2[0]) * (_hc2[0]));
  const double _t25 = _t16*_t24;
#endif
#if _KMAX >= 2
  const double _t26 = _hc0[1]*_t4;
  const double _t27 = _t19*_t7;
  const double _t28 = _t10*_t11;
  const double _t29 = _t18*_t6;
  const double _t30 = 0.2e1*_hc2[1];
  const double _t31 = _t21*_t7;
  const double _t32 = ((_hc0[1]) * (_hc0[1]));
  const double _t33 = _hc2[1]*_t24;
  const double _t34 = _hc0[0]*_hc0[1];
  const double _t35 = _t13*_t15;
  const double _t36 = (0.1e1 / ((_hc2[0]) * (_hc2[0]) * (_hc2[0])));
  const double _t37 = ((_hc2[1]) * (_hc2[1]));
  const double _t38 = _t36*_t37;
#endif
#if _KMAX >= 3
  const double _t39 = 0.3e1*_hc1[2];
  const double _t40 = _hc1[1]*_t4;
  const double _t41 = 0.3e1*_hc0[2];
  const double _t42 = 0.3e1*_hc2[2];
  const double _t43 = _t11*_t18;
  const double _t44 = (0.3e1 / 0.2e1)*_hc2[2];
  const double _t45 = _t39*_t7;
  const double _t46 = _hc2[1]*_t6;
  const double _t47 = _t20*_t7;
  const double _t48 = (0.3e1 / 0.2e1)*_t14;
  const double _t49 = _hc0[1]*_hc0[2];
  const double _t50 = _t24*_t34;
  const double _t51 = (0.3e1 / 0.2e1)*_t33;
  const double _t52 = _hc0[0]*_hc0[2];
  const double _t53 = _t13*_t38;
  const double _t54 = _t35*_t36;
  const double _t55 = (0.3e1 / 0.2e1)*_t35;
  const double _t56 = (0.1e1 / ((_hc2[0]) * (_hc2[0]) * (_hc2[0]) * (_hc2[0])));
  const double _t57 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]))*_t56;
#endif
#if _KMAX >= 4
  const double _t58 = 0.4e1*_hc1[3];
  const double _t59 = 0.6e1*_hc1[2];
  const double _t60 = 0.2e1*_hc2[3];
  const double _t61 = _hc0[0]*_t24;
  const double _t62 = 0.12e2*_t13*_t34;
  const double _t63 = 0.6e1*_t53;
#endif

  const double f = _hc0[0]*_t2 + _hc1[0]*_t5 + _hc2[0]*_t9 + _t10*_t12 + _t14*_t16;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _hc0[1]*_t17 + _hc0[1]*_t2 + _hc0[1]*_t23 + _hc1[1]*_t5 - _hc2[1]*_t25 + _hc2[1]*_t9 + _t10*_t20 + _t18*_t19 + _t18*_t21;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc0[2]*_t17 + _hc0[2]*_t2 + _hc0[2]*_t23 + 0.2e1*_hc1[1]*_t26 + _hc1[2]*_t27 + _hc1[2]*_t31 + _hc1[2]*_t5 - _hc2[2]*_t25 + _hc2[2]*_t28 + _hc2[2]*_t9 + _t18*_t20 + _t22*_t32 + _t29*_t30 - _t33*_t34 + (0.1e1 / 0.2e1)*_t35*_t38;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = _hc0[3]*_t17 + _hc0[3]*_t2 + _hc0[3]*_t23 + (0.3e1 / 0.2e1)*_hc1[2]*_t47 + _hc1[3]*_t27 + _hc1[3]*_t31 + _hc1[3]*_t5 + _hc2[1]*_t44*_t54 - _hc2[3]*_t25 + _hc2[3]*_t28 + _hc2[3]*_t9 + _t26*_t39 + _t29*_t42 - _t32*_t51 + 0.3e1*_t34*_t53 + _t40*_t41 + _t43*_t44 - _t44*_t50 + _t45*_t46 + _t48*_t49 - _t51*_t52 - _t55*_t57;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.2e1*_hc0[1]*_hc0[3]*_t14 + ((_hc0[2]) * (_hc0[2]))*_t48 + _hc0[2]*_t4*_t59 - _hc0[3]*_t30*_t61 + 0.4e1*_hc0[3]*_t40 + _hc0[4]*_t17 + _hc0[4]*_t2 + _hc0[4]*_t23 + 0.2e1*_hc1[3]*_t47 + _hc1[4]*_t27 + _hc1[4]*_t31 + _hc1[4]*_t5 + _hc2[1]*_hc2[2]*_t36*_t62 + ((_hc2[2]) * (_hc2[2]))*_t36*_t55 + _hc2[2]*_t11*_t45 - 0.9e1*_hc2[2]*_t35*_t37*_t56 - _hc2[2]*_t41*_t61 + _hc2[2]*_t59*_t6*_t7 + 0.4e1*_hc2[3]*_t29 + _hc2[3]*_t30*_t54 - _hc2[4]*_t25 + _hc2[4]*_t28 + _hc2[4]*_t9 - _t24*_t32*_t42 + _t26*_t58 + _t32*_t63 - 0.6e1*_t33*_t49 + _t43*_t60 + _t46*_t58*_t7 - _t50*_t60 + _t52*_t63 - _t57*_t62 + 0.6e1*((_hc2[1]) * (_hc2[1]) * (_hc2[1]) * (_hc2[1]))*_t35/xc_powi((_hc2[0]), 5);
  out[4] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  assert(p->params != NULL);
  const lda_c_2d_prm_params *params = (const lda_c_2d_prm_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(M_PI, 1, 2);
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = xc_powr(na, -1, 2);
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f0_k, _KMAX)(p, _t2*_t3, _hc0);
  const double _t4 = 0.032416023070084253*M_PI*_hc0[0];
  const double zk = _t4;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t5 = _hc0[1]*_t1;
  const double dF_dna = -0.016208011535042127*_t3*_t5 + _t4;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = 0.0081040057675210633*_hc0[2]/(na * na) - 0.0081040057675210633*_t5/xc_powr(na, 3, 2);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t6 = xc_powr(na, -7, 2);
  const double _t7 = _hc0[3]*_t2;
  const double d3F_dna3 = 0.012156008651281594*_hc0[1]*_t1/xc_powr(na, 5, 2) - 0.012156008651281594*_hc0[2]/(na * na * na) - 0.0040520028837605316*_t6*_t7;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = 0.030390021628203985*_hc0[2]/(na * na * na * na) + 0.0020260014418802658*_hc0[4]/(M_PI*xc_powi(na, 5)) - 0.030390021628203985*_t5*_t6 + 0.020260014418802659*_t7/xc_powr(na, 9, 2);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = xc_powr(M_PI, 1, 2);
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = na + nb;
  const double _t4 = xc_powr(_t3, -1, 2);
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f0_k, _KMAX)(p, _t2*_t4, _hc0);
  const double _t5 = 0.032416023070084253*M_PI*_hc0[0];
  const double zk = _t5;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t6 = _hc0[1]*_t1;
  const double _t7 = -0.016208011535042127*_t4*_t6 + _t5;
  const double dF_dna = _t7;
  const double dF_dnb = _t7;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t8 = 0.0081040057675210633*_hc0[2]/(_t3 * _t3) - 0.0081040057675210633*_t6/xc_powr(_t3, 3, 2);
  const double d2F_dna2 = _t8;
  const double d2F_dna_dnb = _t8;
  const double d2F_dnb2 = _t8;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t9 = xc_powr(_t3, -7, 2);
  const double _t10 = _hc0[3]*_t2;
  const double _t11 = 0.012156008651281594*_hc0[1]*_t1/xc_powr(_t3, 5, 2) - 0.012156008651281594*_hc0[2]/(_t3 * _t3 * _t3) - 0.0040520028837605316*_t10*_t9;
  const double d3F_dna3 = _t11;
  const double d3F_dna2_dnb = _t11;
  const double d3F_dna_dnb2 = _t11;
  const double d3F_dnb3 = _t11;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t12 = 0.030390021628203985*_hc0[2]/(_t3 * _t3 * _t3 * _t3) + 0.0020260014418802658*_hc0[4]/(M_PI*xc_powi(_t3, 5)) + 0.020260014418802659*_t10/xc_powr(_t3, 9, 2) - 0.030390021628203985*_t6*_t9;
  const double d4F_dna4 = _t12;
  const double d4F_dna3_dnb = _t12;
  const double d4F_dna2_dnb2 = _t12;
  const double d4F_dna_dnb3 = _t12;
  const double d4F_dnb4 = _t12;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif