/*
  Generated from python/lda_exc/lda_x_2d.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_x_2d
*/

#ifndef _LDA_X_2D_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_X_2D_KERNEL_BODY
#define _KMAX 0
#define _LDA_X_2D_HELPER_BODIES
#include "lda_x_2d.c"
#undef _LDA_X_2D_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_X_2D_HELPER_BODIES
#include "lda_x_2d.c"
#undef _LDA_X_2D_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_X_2D_HELPER_BODIES
#include "lda_x_2d.c"
#undef _LDA_X_2D_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_X_2D_HELPER_BODIES
#include "lda_x_2d.c"
#undef _LDA_X_2D_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_X_2D_HELPER_BODIES
#include "lda_x_2d.c"
#undef _LDA_X_2D_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_x_2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_x_2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_x_2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_x_2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_x_2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_x_2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_x_2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_x_2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_x_2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_x_2d.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_X_2D_HELPER_BODIES)

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

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(na, 1, 2);
  const double _t2 = xc_powr(0.2e1, 1, 2)/xc_powr(M_PI, 1, 2);
  const double _t3 = _t1*_t2;
  const double zk = -0.4e1 / 0.3e1*_t3;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = -0.2e1*_t3;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = -_t2/_t1;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.2e1)*_t2/xc_powr(na, 3, 2);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = -0.3e1 / 0.4e1*_t2/xc_powr(na, 5, 2);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na - nb;
  const double _t2 = na + nb;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t1*_t3;
  const double _t5 = xc_powr(0.2e1, 1, 2);
  const double _t6 = xc_powr(M_PI, -1, 2);
  const double _t7 = _t5*_t6;
  const double _t8 = (0.4e1 / 0.3e1)*_t7;
  const double _t10 = xc_powr(_t2, 1, 2);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t4, 0.3e1 / 0.2e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -_t4, 0.3e1 / 0.2e1, _hc1);
  const double _t9 = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
  const double _t11 = _t10*_t9;
  const double zk = -_t11*_t8;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t12 = 0.2e1*_t7;
  const double _t14 = -_t3;
  const double _t15 = (0.1e1 / (_t2 * _t2));
  const double _t16 = _t1*_t15;
  const double _t17 = _t14 + _t16;
  const double _t18 = -_t17;
  const double _t22 = xc_powr(_t2, 3, 2);
  const double _t23 = _t22*_t8;
  const double _t24 = _t16 + _t3;
  const double _t25 = -_t24;
  const double _t13 = _t11*_t12;
  const double _t19 = (0.1e1 / 0.2e1)*_hc0[2];
  const double _t20 = (0.1e1 / 0.2e1)*_hc1[2];
  const double _t21 = _t17*_t20 + _t18*_t19;
  const double _t26 = _t19*_t25 + _t20*_t24;
  const double dF_dna = -_t13 - _t21*_t23;
  const double dF_dnb = -_t13 - _t23*_t26;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t27 = _t7/_t10;
  const double _t30 = 0.4e1*_t7;
  const double _t31 = 0.2e1*_t15;
  const double _t32 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t33 = 0.2e1*_t32;
  const double _t34 = _t1*_t33;
  const double _t35 = -_t31 + _t34;
  const double _t36 = (_t18 * _t18);
  const double _t38 = -_t35;
  const double _t39 = (_t17 * _t17);
  const double _t48 = (_t24 * _t24);
  const double _t49 = _t31 + _t34;
  const double _t50 = -_t49;
  const double _t51 = (_t25 * _t25);
  const double _t28 = _t27*_t9;
  const double _t29 = _t10*_t21;
  const double _t37 = (0.1e1 / 0.2e1)*_hc0[5];
  const double _t40 = (0.1e1 / 0.2e1)*_hc1[5];
  const double _t41 = _t19*_t35 + _t20*_t38 + _t36*_t37 + _t39*_t40;
  const double _t42 = _t10*_t26;
  const double _t43 = _hc0[2]*_t32;
  const double _t44 = _hc1[2]*_t32;
  const double _t45 = _t17*_t40;
  const double _t46 = _t18*_t37;
  const double _t47 = _t1*_t43 - _t1*_t44 + _t24*_t45 + _t25*_t46;
  const double _t52 = _t19*_t49 + _t20*_t50 + _t37*_t51 + _t40*_t48;
  const double d2F_dna2 = -_t23*_t41 - _t28 - _t29*_t30;
  const double d2F_dna_dnb = -_t12*_t29 - _t12*_t42 - _t23*_t47 - _t28;
  const double d2F_dnb2 = -_t23*_t52 - _t28 - _t30*_t42;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t53 = (0.1e1 / _t22);
  const double _t57 = 0.6e1*_t7;
  const double _t58 = 0.6e1*_t32;
  const double _t59 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t60 = 0.6e1*_t59;
  const double _t61 = _t1*_t60;
  const double _t62 = -_t58 + _t61;
  const double _t63 = -_t62;
  const double _t64 = (_t18 * _t18 * _t18);
  const double _t66 = (_t17 * _t17 * _t17);
  const double _t68 = 0.4e1*_t15;
  const double _t69 = 0.4e1*_t1*_t32;
  const double _t70 = -_t68 + _t69;
  const double _t71 = -_t70;
  const double _t74 = -0.2e1*_t32 + _t61;
  const double _t75 = -_t74;
  const double _t80 = -_t1*_t15;
  const double _t81 = _t14 + _t80;
  const double _t85 = _t10*_t30;
  const double _t88 = 0.3e1*_t1;
  const double _t89 = _t59*_t88;
  const double _t93 = _t3 + _t80;
  const double _t96 = (_t24 * _t24 * _t24);
  const double _t97 = _t58 + _t61;
  const double _t98 = -_t97;
  const double _t99 = (_t25 * _t25 * _t25);
  const double _t100 = _t68 + _t69;
  const double _t101 = -_t100;
  const double _t54 = -0.1e1 / 0.2e1*_t5*_t53*_t6*_t9;
  const double _t55 = _t21*_t27;
  const double _t56 = _t10*_t41;
  const double _t65 = (0.1e1 / 0.2e1)*_hc0[9];
  const double _t67 = (0.1e1 / 0.2e1)*_hc1[9];
  const double _t72 = _t19*_t63 + _t20*_t62 + _t35*_t46 + _t38*_t45 + _t45*_t71 + _t46*_t70 + _t64*_t65 + _t66*_t67;
  const double _t73 = _t26*_t27;
  const double _t76 = _hc0[5]*_t18;
  const double _t77 = _hc1[5]*_t17;
  const double _t78 = _t24*_t40;
  const double _t79 = _t39*_t67;
  const double _t82 = _t36*_t65;
  const double _t83 = _t25*_t37;
  const double _t84 = _t19*_t75 + _t20*_t74 + _t24*_t79 + _t34*_t76 - _t34*_t77 + _t35*_t83 + _t38*_t78 + _t81*_t82;
  const double _t86 = _t47*_t85 + _t54;
  const double _t87 = _t10*_t52;
  const double _t90 = _hc1[5]*_t24;
  const double _t91 = _hc0[5]*_t25;
  const double _t92 = _t48*_t67;
  const double _t94 = _t51*_t65;
  const double _t95 = -_hc0[2]*_t89 + _hc1[2]*_t89 + _t17*_t92 - _t34*_t90 + _t34*_t91 - _t43 + _t44 + _t45*_t50 + _t46*_t49 + _t93*_t94;
  const double _t102 = _t100*_t83 + _t101*_t78 + _t19*_t98 + _t20*_t97 + _t49*_t83 + _t50*_t78 + _t65*_t99 + _t67*_t96;
  const double d3F_dna3 = -_t23*_t72 - _t54 - 0.3e1*_t55 - _t56*_t57;
  const double d3F_dna2_dnb = -_t12*_t56 - _t23*_t84 - 0.2e1*_t55 - _t73 - _t86;
  const double d3F_dna_dnb2 = -_t12*_t87 - _t23*_t95 - _t55 - 0.2e1*_t73 - _t86;
  const double d3F_dnb3 = -_t102*_t23 - _t54 - _t57*_t87 - 0.3e1*_t73;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t106 = 0.8e1*_t7;
  const double _t108 = 0.24e2*_t59;
  const double _t109 = _t1/xc_powi(_t2, 5);
  const double _t110 = 0.24e2*_t109;
  const double _t111 = -_t108 + _t110;
  const double _t113 = 0.12e2*_t32;
  const double _t114 = 0.12e2*_t59;
  const double _t115 = _t1*_t114;
  const double _t116 = -_t113 + _t115;
  const double _t119 = 0.6e1*_t15;
  const double _t120 = 0.6e1*na - 0.6e1*nb;
  const double _t121 = 0.4e1*na - 0.4e1*nb;
  const double _t122 = 0.2e1*na - 0.2e1*nb;
  const double _t123 = _t122*_t32 - _t31;
  const double _t124 = _t1*_t58;
  const double _t125 = _t10*_t57;
  const double _t126 = _t110 - _t114;
  const double _t127 = _t1*_t32;
  const double _t129 = _t32*_t88;
  const double _t133 = _t115 - 0.4e1*_t32;
  const double _t134 = _t17*_t24;
  const double _t136 = _t18*_t25;
  const double _t141 = _t122*_t32 + _t31;
  const double _t142 = 0.4e1*(_t1 * _t1)/xc_powi(_t2, 6);
  const double _t143 = 0.12e2*_t109;
  const double _t146 = 0.3e1*_t32;
  const double _t147 = 0.9e1*_t1*_t59;
  const double _t148 = _t108 + _t110;
  const double _t149 = _t113 + _t115;
  const double _t103 = (0.3e1 / 0.4e1)*_t7*_t9/xc_powr(_t2, 5, 2);
  const double _t104 = _t27*_t41;
  const double _t105 = _t10*_t72;
  const double _t107 = (0.1e1 / 0.2e1)*_hc0[14];
  const double _t112 = (0.1e1 / 0.2e1)*_hc1[14];
  const double _t117 = _t35*_t37;
  const double _t118 = _t38*_t40;
  const double _t128 = _hc0[5]*_t127;
  const double _t130 = _hc0[9]*_t129;
  const double _t131 = _hc1[5]*_t127;
  const double _t132 = _hc1[9]*_t129;
  const double _t135 = _t134*_t67;
  const double _t137 = _t136*_t65;
  const double _t138 = _t27*_t47;
  const double _t139 = _t103 + 0.3e1*_t138;
  const double _t140 = _t27*_t52;
  const double _t144 = _hc0[2]*_t143 - _hc1[2]*_t143;
  const double _t145 = _t10*_t102;
  const double d4F_dna4 = -_t103 - 0.6e1*_t104 - _t105*_t106 + 0.2e1*_t21*_t5*_t53*_t6 - _t23*(_t107*(_t18 * _t18 * _t18 * _t18) + _t111*_t19 - _t111*_t20 + _t112*(_t17 * _t17 * _t17 * _t17) + _t116*_t45 - _t116*_t46 + _t117*_t70 + _t118*_t71 + _t123*_t82 + (_t35 * _t35)*_t37 + (_t38 * _t38)*_t40 + _t38*_t79 + _t62*_t77 + _t63*_t76 + _t71*_t79 + _t79*(_t119 - _t124) + _t82*(-_t119 + _t120*_t32) + _t82*(_t121*_t32 - _t68));
  const double d4F_dna3_dnb = -0.3e1*_t104 - _t105*_t12 - _t125*_t84 - _t139 + (0.3e1 / 0.2e1)*_t21*_t5*_t53*_t6 - _t23*(_t107*_t64*_t81 + _t112*_t24*_t66 + _t126*_t19 - _t126*_t20 + _t128*_t35 + _t128*_t70 + _t130*_t36 - _t131*_t38 - _t131*_t71 - _t132*_t39 + _t133*_t45 - _t133*_t46 + _t135*_t38 + _t135*_t71 + _t137*_t35 + _t137*_t70 + _t45*_t74 + _t46*_t75 + _t62*_t78 + _t63*_t83) + (0.1e1 / 0.2e1)*_t26*_t5*_t53*_t6;
  const double d4F_dna2_dnb2 = -_t103 - _t104 - 0.4e1*_t138 - _t140 + _t21*_t5*_t53*_t6 - _t23*(_hc0[5]*_t142 + _hc0[9]*_t136*_t69 + _hc1[5]*_t142 - _hc1[9]*_t134*_t69 + _t107*_t36*_t51 + _t112*_t39*_t48 + _t117*_t49 + _t118*_t50 + _t123*_t94 + _t141*_t82 + _t144 - _t33*_t76 + _t33*_t77 + _t38*_t92 + _t50*_t79 - _t61*_t76 + _t61*_t77 + _t74*_t90 + _t75*_t91) + _t26*_t5*_t53*_t6 - _t84*_t85 - _t85*_t95;
  const double d4F_dna_dnb3 = -_t12*_t145 - _t125*_t95 - _t139 - 0.3e1*_t140 + (0.1e1 / 0.2e1)*_t21*_t5*_t53*_t6 - _t23*(_hc0[2]*_t60 + _hc0[5]*_t129*_t49 - _hc1[2]*_t60 - _hc1[5]*_t129*_t50 + _t100*_t137 + _t101*_t135 + _t107*_t93*_t99 + _t112*_t17*_t96 + _t130*_t51 - _t132*_t48 + _t135*_t50 + _t137*_t49 + _t144 + _t146*_t90 - _t146*_t91 + _t147*_t90 - _t147*_t91 + _t45*_t97 + _t46*_t98) + (0.3e1 / 0.2e1)*_t26*_t5*_t53*_t6;
  const double d4F_dnb4 = -_t103 - _t106*_t145 - 0.6e1*_t140 - _t23*(_t100*_t37*_t49 + _t101*_t40*_t50 + _t101*_t92 + _t107*(_t25 * _t25 * _t25 * _t25) + _t112*(_t24 * _t24 * _t24 * _t24) + _t141*_t94 + _t148*_t19 - _t148*_t20 + _t149*_t78 - _t149*_t83 + _t37*(_t49 * _t49) + _t40*(_t50 * _t50) + _t50*_t92 + _t90*_t97 + _t91*_t98 + _t92*(-_t119 - _t124) + _t94*(_t119 + _t120*_t32) + _t94*(_t121*_t32 + _t68)) + 0.2e1*_t26*_t5*_t53*_t6;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif