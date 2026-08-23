/*
  Generated from python/lda_exc/lda_k_tf.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_k_tf
*/

#ifndef _LDA_K_TF_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_K_TF_KERNEL_BODY
#define _KMAX 0
#define _LDA_K_TF_HELPER_BODIES
#include "lda_k_tf.c"
#undef _LDA_K_TF_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_K_TF_HELPER_BODIES
#include "lda_k_tf.c"
#undef _LDA_K_TF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_K_TF_HELPER_BODIES
#include "lda_k_tf.c"
#undef _LDA_K_TF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_K_TF_HELPER_BODIES
#include "lda_k_tf.c"
#undef _LDA_K_TF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_K_TF_HELPER_BODIES
#include "lda_k_tf.c"
#undef _LDA_K_TF_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_k_tf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_k_tf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_k_tf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_k_tf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_k_tf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_k_tf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_k_tf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_k_tf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_k_tf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_k_tf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_K_TF_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_zeta_k_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.5e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.5e1 / 0.3e1, _hc1);

  const double f = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = (0.1e1 / 0.2e1)*_hc0[2] - 0.1e1 / 0.2e1*_hc1[2];
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = (0.1e1 / 0.2e1)*_hc0[5] + (0.1e1 / 0.2e1)*_hc1[5];
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = (0.1e1 / 0.2e1)*_hc0[9] - 0.1e1 / 0.2e1*_hc1[9];
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = (0.1e1 / 0.2e1)*_hc0[14] + (0.1e1 / 0.2e1)*_hc1[14];
  out[4] = d4f_dz4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  assert(p->params != NULL);
  const lda_k_tf_params *params = (const lda_k_tf_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(0.6e1, 1, 3)*(M_CBRTPI * M_CBRTPI)*params->ax;
  const double _t2 = _t1*xc_powr(na, 2, 3);
  const double zk = (0.2e1 / 0.3e1)*_t2;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = (0.10e2 / 0.9e1)*_t2;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = (0.20e2 / 0.27e2)*_t1/xc_powr(na, 1, 3);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = -0.20e2 / 0.81e2*_t1/xc_powr(na, 4, 3);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.80e2 / 0.243e3)*_t1/xc_powr(na, 7, 3);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na - nb;
  const double _t2 = na + nb;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = xc_powr(_t2, 2, 3);
  const double _t5 = xc_powr(0.6e1, 1, 3)*(M_CBRTPI * M_CBRTPI)*params->ax;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k_k, _KMAX)(p, _t1*_t3, _hc0);
  const double _t6 = _hc0[0]*_t5;
  const double _t7 = _t4*_t6;
  const double zk = (0.2e1 / 0.3e1)*_t7;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t9 = xc_powr(_t2, 5, 3);
  const double _t10 = (0.2e1 / 0.3e1)*_t9;
  const double _t11 = -_t3;
  const double _t12 = (0.1e1 / (_t2 * _t2));
  const double _t13 = _t1*_t12;
  const double _t14 = -_t11 - _t13;
  const double _t17 = -_t13 - _t3;
  const double _t8 = (0.10e2 / 0.9e1)*_t7;
  const double _t15 = _hc0[1]*_t5;
  const double _t16 = _t14*_t15;
  const double _t18 = _t10*_t15;
  const double dF_dna = _t10*_t16 + _t8;
  const double dF_dnb = _t17*_t18 + _t8;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t19 = xc_powr(_t2, -1, 3);
  const double _t20 = (0.20e2 / 0.27e2)*_t19;
  const double _t23 = 0.2e1*_t12;
  const double _t24 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t25 = 0.2e1*_t1*_t24;
  const double _t26 = -_t23 + _t25;
  const double _t27 = (_t14 * _t14);
  const double _t28 = _t10*_t5;
  const double _t30 = xc_powr(_t2, -4, 3);
  const double _t36 = _t23 + _t25;
  const double _t37 = (_t17 * _t17);
  const double _t21 = _t20*_t6;
  const double _t22 = _t16*_t4;
  const double _t29 = _hc0[2]*_t28;
  const double _t31 = (0.4e1 / 0.3e1)*_t15;
  const double _t32 = _t30*_t31;
  const double _t33 = _t15*_t4;
  const double _t34 = _t17*_t33;
  const double _t35 = _t14*_t29;
  const double d2F_dna2 = _t18*_t26 + _t21 + (0.20e2 / 0.9e1)*_t22 + _t27*_t29;
  const double d2F_dna_dnb = _t1*_t32 + _t17*_t35 + _t21 + (0.10e2 / 0.9e1)*_t22 + (0.10e2 / 0.9e1)*_t34;
  const double d2F_dnb2 = _t18*_t36 + _t21 + _t29*_t37 + (0.20e2 / 0.9e1)*_t34;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t38 = (0.20e2 / 0.81e2)*_t30;
  const double _t42 = 0.6e1*_t24;
  const double _t43 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t44 = 0.6e1*_t1*_t43;
  const double _t45 = _t42 - _t44;
  const double _t46 = _t4*_t5;
  const double _t49 = (_t14 * _t14 * _t14);
  const double _t51 = 0.4e1*_t12;
  const double _t52 = 0.4e1*_t1*_t24;
  const double _t53 = -_t51 + _t52;
  const double _t54 = 0.2e1*_t24 - _t44;
  const double _t56 = xc_powr(_t2, -7, 3);
  const double _t60 = -_t1*_t12;
  const double _t61 = _t11 + _t60;
  const double _t70 = (0.4e1 / 0.9e1)*_t1;
  const double _t74 = _t3 + _t60;
  const double _t76 = _t1*_t17;
  const double _t77 = -_t42 - _t44;
  const double _t78 = (_t17 * _t17 * _t17);
  const double _t79 = _t51 + _t52;
  const double _t39 = -_t38*_t6;
  const double _t40 = _t16*_t19;
  const double _t41 = _t26*_t33;
  const double _t47 = _hc0[2]*_t46;
  const double _t48 = _t27*_t47;
  const double _t50 = _hc0[3]*_t28;
  const double _t55 = _t15*_t17;
  const double _t57 = _t15*_t56;
  const double _t58 = (0.40e2 / 0.9e1)*_t57;
  const double _t59 = _t17*_t29;
  const double _t62 = _t27*_t50;
  const double _t63 = _hc0[2]*_t5;
  const double _t64 = _t30*_t63;
  const double _t65 = (0.8e1 / 0.3e1)*_t64;
  const double _t66 = _t14*_t65;
  const double _t67 = _t14*_t47;
  const double _t68 = (0.20e2 / 0.9e1)*_t67;
  const double _t69 = _t17*_t68 + _t39;
  const double _t71 = _t33*_t36;
  const double _t72 = _t37*_t47;
  const double _t73 = _t19*_t55;
  const double _t75 = _t37*_t50;
  const double d3F_dna3 = _t18*_t45 + _t26*_t35 + _t35*_t53 + _t39 + (0.20e2 / 0.9e1)*_t40 + (0.10e2 / 0.3e1)*_t41 + (0.10e2 / 0.3e1)*_t48 + _t49*_t50;
  const double d3F_dna2_dnb = _t1*_t58 + _t1*_t66 + _t18*_t54 + _t20*_t55 + _t26*_t59 + (0.40e2 / 0.27e2)*_t40 + (0.10e2 / 0.9e1)*_t41 + (0.10e2 / 0.9e1)*_t48 + _t61*_t62 + _t69;
  const double d3F_dna_dnb2 = _t16*_t20 - _t32 + _t35*_t36 + _t57*_t70 + _t65*_t76 + _t69 + (0.10e2 / 0.9e1)*_t71 + (0.10e2 / 0.9e1)*_t72 + (0.40e2 / 0.27e2)*_t73 + _t74*_t75;
  const double d3F_dnb3 = _t18*_t77 + _t36*_t59 + _t39 + _t50*_t78 + _t59*_t79 + (0.10e2 / 0.3e1)*_t71 + (0.10e2 / 0.3e1)*_t72 + (0.20e2 / 0.9e1)*_t73;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t82 = (0.40e2 / 0.9e1)*_t19;
  const double _t85 = 0.24e2*_t43;
  const double _t86 = 0.24e2*_t1/xc_powi(_t2, 5);
  const double _t92 = 0.12e2*_t24;
  const double _t93 = 0.12e2*_t43;
  const double _t94 = _t1*_t93;
  const double _t96 = (0.4e1 / 0.3e1)*_t9;
  const double _t98 = 0.6e1*_t12;
  const double _t99 = 0.6e1*na - 0.6e1*nb;
  const double _t100 = 0.4e1*na - 0.4e1*nb;
  const double _t101 = 0.2e1*na - 0.2e1*nb;
  const double _t102 = _t101*_t24 - _t23;
  const double _t104 = (0.20e2 / 0.9e1)*_t19;
  const double _t113 = _t27*_t61;
  const double _t124 = _t37*_t74;
  const double _t126 = _t101*_t24 + _t23;
  const double _t80 = (0.80e2 / 0.243e3)*_t56*_t6;
  const double _t81 = _t16*_t30;
  const double _t83 = _t15*_t26;
  const double _t84 = _t33*_t45;
  const double _t87 = _t27*_t63;
  const double _t88 = _hc0[3]*_t46;
  const double _t89 = _t49*_t88;
  const double _t90 = _hc0[4]*_t28;
  const double _t91 = (0.40e2 / 0.9e1)*_t67;
  const double _t95 = _t14*_t63;
  const double _t97 = _t26*_t29;
  const double _t103 = _t33*_t54;
  const double _t105 = _t15/xc_powr(_t2, 10, 3);
  const double _t106 = _t1*_t105;
  const double _t107 = _hc0[3]*_t30*_t5;
  const double _t108 = 0.4e1*_t1*_t107;
  const double _t109 = (0.4e1 / 0.3e1)*_t1*_t64;
  const double _t110 = _t17*_t47;
  const double _t111 = _t110*_t26;
  const double _t112 = (0.10e2 / 0.3e1)*_t88;
  const double _t114 = (0.10e2 / 0.9e1)*_t67;
  const double _t115 = _t1*_t56*_t95;
  const double _t116 = _t14*_t17*_t50;
  const double _t117 = _t17*_t95;
  const double _t118 = _t104*_t117 + _t80;
  const double _t119 = _t30*_t55;
  const double _t120 = _t15*_t36;
  const double _t121 = _t37*_t63;
  const double _t122 = _t56*_t63*_t76;
  const double _t123 = (0.20e2 / 0.9e1)*_t88;
  const double _t125 = _t17*_t63*_t96;
  const double _t127 = 0.4e1*_t64;
  const double _t128 = _t33*_t77;
  const double _t129 = _t78*_t88;
  const double _t130 = (0.10e2 / 0.9e1)*_t110;
  const double _t131 = (0.40e2 / 0.9e1)*_t110;
  const double d4F_dna4 = _t102*_t62 + (_t14 * _t14 * _t14 * _t14)*_t90 + _t18*(-_t85 + _t86) + (_t26 * _t26)*_t29 + _t26*_t91 + _t35*(_t92 - _t94) + _t45*_t95*_t96 + _t53*_t91 + _t53*_t97 + _t62*(_t100*_t24 - _t51) + _t62*(_t24*_t99 - _t98) + _t80 - 0.80e2 / 0.81e2*_t81 + _t82*_t83 + _t82*_t87 + (0.40e2 / 0.9e1)*_t84 + (0.40e2 / 0.9e1)*_t89;
  const double d4F_dna3_dnb = (0.10e2 / 0.3e1)*_t103 + _t104*_t83 + _t104*_t87 + (0.40e2 / 0.9e1)*_t106 + _t108*_t27 + _t109*_t26 + _t109*_t53 + (0.10e2 / 0.3e1)*_t111 + _t112*_t113 + _t114*_t26 + _t114*_t53 + (0.40e2 / 0.3e1)*_t115 + _t116*_t26 + _t116*_t53 + _t118 + _t18*(_t86 - _t93) + _t35*_t54 + _t35*(0.4e1*_t24 - _t94) - _t38*_t55 + _t45*_t59 + _t49*_t61*_t90 - 0.20e2 / 0.27e2*_t81 + (0.10e2 / 0.9e1)*_t84 + (0.10e2 / 0.9e1)*_t89;
  const double d4F_dna2_dnb2 = (0.16e2 / 0.3e1)*(_t1 * _t1)*_t63/xc_powr(_t2, 13, 3) + _t102*_t75 + (0.20e2 / 0.9e1)*_t103 + (0.232e3 / 0.27e2)*_t106 + (0.16e2 / 0.3e1)*_t107*_t14*_t76 + (0.20e2 / 0.9e1)*_t111 + _t113*_t123 + (0.8e1 / 0.9e1)*_t115 + (0.80e2 / 0.27e2)*_t117*_t19 - 0.40e2 / 0.81e2*_t119 + _t120*_t20 + _t121*_t20 + (0.80e2 / 0.9e1)*_t122 + _t123*_t124 + _t125*_t54 + _t126*_t62 + _t20*_t83 + _t20*_t87 + _t27*_t37*_t90 + _t36*_t68 + _t36*_t97 - _t58 - _t66 + _t80 - 0.40e2 / 0.81e2*_t81;
  const double d4F_dna_dnb3 = _t1*_t127*_t36 + _t104*_t120 + _t104*_t121 + _t105*_t70 + _t108*_t37 + _t112*_t124 + _t116*_t36 + _t116*_t79 + _t118 - 0.20e2 / 0.27e2*_t119 + (0.4e1 / 0.3e1)*_t122 - _t127*_t17 + (0.10e2 / 0.9e1)*_t128 + (0.10e2 / 0.9e1)*_t129 + _t130*_t36 + _t130*_t79 - _t16*_t38 + _t31*_t56 + _t35*_t77 + (0.10e2 / 0.3e1)*_t36*_t67 + _t74*_t78*_t90;
  const double d4F_dnb4 = -0.80e2 / 0.81e2*_t119 + _t120*_t82 + _t121*_t82 + _t125*_t77 + _t126*_t75 + (0.40e2 / 0.9e1)*_t128 + (0.40e2 / 0.9e1)*_t129 + _t131*_t36 + _t131*_t79 + (_t17 * _t17 * _t17 * _t17)*_t90 + _t18*(_t85 + _t86) + _t29*(_t36 * _t36) + _t29*_t36*_t79 + _t59*(-_t92 - _t94) + _t75*(_t100*_t24 + _t51) + _t75*(_t24*_t99 + _t98) + _t80;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif