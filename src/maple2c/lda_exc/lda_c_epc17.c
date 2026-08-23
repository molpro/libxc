/*
  Generated from python/lda_exc/lda_c_epc17.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_epc17
*/

#ifndef _LDA_C_EPC17_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_EPC17_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_EPC17_HELPER_BODIES
#include "lda_c_epc17.c"
#undef _LDA_C_EPC17_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_EPC17_HELPER_BODIES
#include "lda_c_epc17.c"
#undef _LDA_C_EPC17_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_EPC17_HELPER_BODIES
#include "lda_c_epc17.c"
#undef _LDA_C_EPC17_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_EPC17_HELPER_BODIES
#include "lda_c_epc17.c"
#undef _LDA_C_EPC17_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_EPC17_HELPER_BODIES
#include "lda_c_epc17.c"
#undef _LDA_C_EPC17_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_epc17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_epc17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_epc17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_epc17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_epc17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_epc17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_epc17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_epc17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_epc17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_epc17.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_EPC17_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(z_thr_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z + 0.1e1 <= p->zeta_threshold;
  const double _t2 = p->zeta_threshold - 0.1e1;
  const double _t3 = 0.1e1 - z <= p->zeta_threshold;
#if _KMAX >= 2
  const double _t4 = my_piecewise5(_t1, 0, _t3, 0, 0);
#endif

  const double f = my_piecewise5(_t1, _t2, _t3, -_t2, z);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise5(_t1, 0, _t3, 0, 0.1e1);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t4;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t4;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t4;
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(epc17_E_k, _KMAX)(const xc_func_type *p, double rho_ep, double *out) {
  const lda_c_epc17_params *params = (const lda_c_epc17_params *)(p->params);

  const double _t1 = xc_powr(rho_ep, 1, 2);
  const double _t2 = -_t1*params->b + params->a + params->c*rho_ep;
  const double _t3 = (0.1e1 / _t2);
#if _KMAX >= 1
  const double _t4 = (0.1e1 / (_t2 * _t2));
  const double _t5 = (0.1e1 / _t1);
  const double _t6 = _t5*params->b;
  const double _t7 = (0.1e1 / 0.2e1)*_t6;
  const double _t8 = _t7 - params->c;
  const double _t9 = _t4*_t8;
#endif
#if _KMAX >= 2
  const double _t10 = _t6 - 0.2e1*params->c;
  const double _t11 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t12 = _t11*_t8;
  const double _t13 = _t10*_t12;
#endif
#if _KMAX >= 3
  const double _t14 = xc_powr(rho_ep, -3, 2);
  const double _t15 = _t4*params->b;
  const double _t16 = _t10*_t11;
  const double _t17 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t18 = (0.3e1 / 0.2e1)*_t6 - 0.3e1*params->c;
  const double _t19 = _t17*_t18*_t8;
  const double _t20 = _t10*_t19;
#endif
#if _KMAX >= 4
  const double _t21 = _t14*params->b;
  const double _t22 = _t10*_t8;
  const double _t23 = (0.3e1 / 0.4e1)*_t17*_t6;
#endif

  const double f = -_t3*rho_ep;
  out[0] = f;
#if _KMAX >= 1
  const double df_drho_ep = -_t3 - _t9*rho_ep;
  out[1] = df_drho_ep;
#endif
#if _KMAX >= 2
  const double d2f_drho_ep2 = -_t13*rho_ep + (0.1e1 / 0.4e1)*_t4*_t5*params->b - 0.2e1*_t9;
  out[2] = d2f_drho_ep2;
#endif
#if _KMAX >= 3
  const double d3f_drho_ep3 = _t12*_t7 - 0.3e1*_t13 + (0.3e1 / 0.8e1)*_t14*_t15 + _t16*_t7 - _t20*rho_ep;
  out[3] = d3f_drho_ep3;
#endif
#if _KMAX >= 4
  const double d4f_drho_ep4 = _t10*_t18*_t23 - 0.3e1 / 0.8e1*_t11*((params->b) * (params->b))/(rho_ep * rho_ep) + (0.5e1 / 0.4e1)*_t12*_t21 - 0.9e1 / 0.16e2*_t15/xc_powr(rho_ep, 5, 2) + (0.7e1 / 0.8e1)*_t16*_t21 - _t18*_t22*rho_ep*(0.2e1*_t6 - 0.4e1*params->c)/xc_powi(_t2, 5) + _t19*_t6 - 0.4e1*_t20 + _t22*_t23;
  out[4] = d4f_drho_ep4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  assert(p->params != NULL);
  const lda_c_epc17_params *params = (const lda_c_epc17_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = (na * na);
  const double _t2 = -p->dens_threshold + (0.1e1 / 0.2e1)*na <= 0;
  const double _t3 = (0.1e1 / na);
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t2)) XC_CAT(epc17_E_k, _KMAX)(p, (0.1e1 / 0.4e1)*_t1, _hc0);
  const double _t4 = my_piecewise3(_t2, 0, _hc0[0]*_t3);
  const double zk = _t4;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t5 = (0.1e1 / _t1);
  const double _t6 = my_piecewise3(_t2, 0, -_hc0[0]*_t5 + (0.1e1 / 0.2e1)*_hc0[1]);
  const double dF_dna = _t4 + _t6*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t7 = (0.1e1 / 0.4e1)*na;
  const double _t8 = (na * na * na);
  const double _t9 = (0.1e1 / _t8);
  const double _t10 = my_piecewise3(_t2, 0, 0.2e1*_hc0[0]*_t9 - 0.1e1 / 0.2e1*_hc0[1]*_t3 + _hc0[2]*_t7);
  const double d2F_dna2 = _t10*na + 0.2e1*_t6;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t11 = my_piecewise3(_t2, 0, -0.6e1*_hc0[0]/(na * na * na * na) + (0.3e1 / 0.2e1)*_hc0[1]*_t5 + (0.1e1 / 0.8e1)*_hc0[3]*_t1);
  const double d3F_dna3 = 0.3e1*_t10 + _t11*na;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = 0.4e1*_t11 + na*my_piecewise3(_t2, 0, 0.24e2*_hc0[0]/xc_powi(na, 5) - 0.6e1*_hc0[1]*_t9 + (0.3e1 / 0.4e1)*_hc0[2]*_t3 + _hc0[3]*_t7 + (0.1e1 / 0.16e2)*_hc0[4]*_t8);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na - nb;
  const double _t2 = na + nb;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t1*_t3;
  const double _t5 = (_t2 * _t2);
  const double _t10 = na <= p->dens_threshold && nb <= p->dens_threshold;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, _t4, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, -_t4, _hc1);
  const double _t6 = _hc0[0] + 0.1e1;
  const double _t7 = _hc1[0] + 0.1e1;
  const double _t8 = _t6*_t7;
  const double _t9 = (0.1e1 / 0.4e1)*_t8;
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t10)) XC_CAT(epc17_E_k, _KMAX)(p, _t5*_t9, _hc2);
  const double _t11 = my_piecewise3(_t10, 0, _hc2[0]*_t3);
  const double zk = _t11;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t12 = (0.1e1 / _t5);
  const double _t14 = 0.2e1*na;
  const double _t15 = 0.2e1*nb;
  const double _t16 = _t14 + _t15;
  const double _t18 = -_t3;
  const double _t19 = _t1*_t12;
  const double _t20 = _t18 + _t19;
  const double _t21 = -_t20;
  const double _t24 = (0.1e1 / 0.4e1)*_t5;
  const double _t29 = _t19 + _t3;
  const double _t31 = -_t29;
  const double _t17 = _t16*_t9;
  const double _t22 = _hc0[1]*_t7;
  const double _t23 = _t21*_t22;
  const double _t25 = _hc1[1]*_t6;
  const double _t26 = _t20*_t25;
  const double _t27 = _t17 + _t23*_t24 + _t24*_t26;
  const double _t30 = _t25*_t29;
  const double _t32 = _t22*_t31;
  const double _t33 = _t17 + _t24*_t30 + _t24*_t32;
  const double _t13 = _hc2[0]*_t12;
  const double _t28 = my_piecewise3(_t10, 0, _hc2[1]*_t27*_t3 - _t13);
  const double _t34 = my_piecewise3(_t10, 0, _hc2[1]*_t3*_t33 - _t13);
  const double dF_dna = _t11 + _t2*_t28;
  const double dF_dnb = _t11 + _t2*_t34;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t35 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t36 = 0.2e1*_t35;
  const double _t38 = 0.2e1*_t12;
  const double _t43 = -_t38;
  const double _t44 = _t1*_t36;
  const double _t45 = _t43 + _t44;
  const double _t47 = (_t21 * _t21);
  const double _t50 = -_t45;
  const double _t52 = (_t20 * _t20);
  const double _t57 = _t20*_t21;
  const double _t82 = _t38 + _t44;
  const double _t84 = (_t31 * _t31);
  const double _t86 = -_t82;
  const double _t88 = (_t29 * _t29);
  const double _t40 = (_t27 * _t27);
  const double _t42 = (0.1e1 / 0.2e1)*_t8;
  const double _t46 = _t22*_t45;
  const double _t48 = _hc0[2]*_t7;
  const double _t49 = _t47*_t48;
  const double _t51 = _t25*_t50;
  const double _t53 = _hc1[2]*_t6;
  const double _t54 = _t52*_t53;
  const double _t55 = _hc1[1]*_t5;
  const double _t56 = _hc0[1]*_t55;
  const double _t58 = _t56*_t57;
  const double _t59 = _t16*_t23;
  const double _t60 = _t16*_t26;
  const double _t61 = (0.1e1 / 0.2e1)*_t59 + (0.1e1 / 0.2e1)*_t60;
  const double _t62 = _t24*_t46 + _t24*_t49 + _t24*_t51 + _t24*_t54 + _t42 + (0.1e1 / 0.2e1)*_t58 + _t61;
  const double _t67 = _t22*_t4;
  const double _t68 = _t25*_t4;
  const double _t69 = _t16*_t30;
  const double _t70 = _t16*_t32;
  const double _t71 = _t29*_t56;
  const double _t72 = (0.1e1 / 0.4e1)*_t71;
  const double _t73 = _t20*_t53;
  const double _t74 = _t29*_t73;
  const double _t75 = _t20*_t56;
  const double _t76 = _t31*_t75;
  const double _t77 = _t24*_t48;
  const double _t78 = _t21*_t77;
  const double _t79 = _t21*_t72 + _t24*_t74 + _t31*_t78 + _t42 + (0.1e1 / 0.4e1)*_t59 + (0.1e1 / 0.4e1)*_t60 + (0.1e1 / 0.2e1)*_t67 - 0.1e1 / 0.2e1*_t68 + (0.1e1 / 0.4e1)*_t69 + (0.1e1 / 0.4e1)*_t70 + (0.1e1 / 0.4e1)*_t76;
  const double _t81 = (_t33 * _t33);
  const double _t83 = _t22*_t82;
  const double _t85 = _t48*_t84;
  const double _t87 = _t25*_t86;
  const double _t89 = _t53*_t88;
  const double _t90 = _t31*_t71;
  const double _t91 = (0.1e1 / 0.2e1)*_t32;
  const double _t92 = (0.1e1 / 0.2e1)*_t30;
  const double _t93 = _t16*_t91 + _t16*_t92;
  const double _t94 = _t24*_t83 + _t24*_t85 + _t24*_t87 + _t24*_t89 + _t42 + (0.1e1 / 0.2e1)*_t90 + _t93;
  const double _t37 = _hc2[0]*_t36;
  const double _t39 = _hc2[1]*_t38;
  const double _t41 = _hc2[2]*_t3;
  const double _t63 = _hc2[1]*_t3;
  const double _t64 = my_piecewise3(_t10, 0, -_t27*_t39 + _t37 + _t40*_t41 + _t62*_t63);
  const double _t65 = _hc2[1]*_t12;
  const double _t66 = _t27*_t41;
  const double _t80 = my_piecewise3(_t10, 0, -_t27*_t65 - _t33*_t65 + _t33*_t66 + _t37 + _t63*_t79);
  const double _t95 = my_piecewise3(_t10, 0, -_t33*_t39 + _t37 + _t41*_t81 + _t63*_t94);
  const double d2F_dna2 = _t2*_t64 + 0.2e1*_t28;
  const double d2F_dna_dnb = _t2*_t80 + _t28 + _t34;
  const double d2F_dnb2 = _t2*_t95 + 0.2e1*_t34;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t96 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t97 = 0.6e1*_t96;
  const double _t99 = 0.6e1*_t35;
  const double _t113 = (_t20 * _t20 * _t20);
  const double _t116 = _t1*_t97;
  const double _t117 = _t116 - _t99;
  const double _t118 = -_t117;
  const double _t120 = (_t21 * _t21 * _t21);
  const double _t126 = (0.3e1 / 0.4e1)*_t16;
  const double _t138 = 0.4e1*_t12;
  const double _t139 = 0.4e1*_t35;
  const double _t140 = _t1*_t139;
  const double _t141 = -_t138 + _t140;
  const double _t142 = -_t141;
  const double _t147 = _t116 - 0.2e1*_t35;
  const double _t148 = -_t147;
  const double _t149 = (0.1e1 / 0.4e1)*_t16;
  const double _t151 = _t21*_t4;
  const double _t157 = _t24*_t52;
  const double _t160 = (0.1e1 / 0.4e1)*_t29;
  const double _t164 = -_t1*_t12;
  const double _t165 = _t164 + _t18;
  const double _t172 = (0.1e1 / 0.2e1)*_t29;
  const double _t196 = (0.1e1 / 0.2e1)*_t5;
  const double _t212 = _t31*_t4;
  const double _t218 = (0.1e1 / 0.4e1)*_t86;
  const double _t219 = (0.1e1 / 0.4e1)*_t82;
  const double _t220 = _t24*_t88;
  const double _t222 = _t20*_t84;
  const double _t224 = _t164 + _t3;
  const double _t225 = _t224*_t84;
  const double _t229 = _t20*_t29;
  const double _t230 = _t21*_t31;
  const double _t247 = (_t29 * _t29 * _t29);
  const double _t249 = _t116 + _t99;
  const double _t250 = -_t249;
  const double _t251 = (_t31 * _t31 * _t31);
  const double _t254 = _t138 + _t140;
  const double _t255 = -_t254;
  const double _t256 = _t31*_t82;
  const double _t257 = _t254*_t31;
  const double _t101 = (_t27 * _t27 * _t27);
  const double _t106 = (0.1e1 / 0.2e1)*_t46;
  const double _t107 = (0.1e1 / 0.2e1)*_t49;
  const double _t108 = (0.1e1 / 0.2e1)*_t51;
  const double _t109 = (0.1e1 / 0.2e1)*_t54;
  const double _t110 = _t106*_t5 + _t107*_t5 + _t108*_t5 + _t109*_t5 + _t58 + _t59 + _t60 + _t8;
  const double _t111 = (0.3e1 / 0.2e1)*_t23;
  const double _t112 = (0.3e1 / 0.2e1)*_t26;
  const double _t114 = (0.3e1 / 0.4e1)*_hc0[2];
  const double _t115 = _t114*_t55;
  const double _t119 = _t22*_t24;
  const double _t121 = _hc0[3]*_t7;
  const double _t122 = _t121*_t24;
  const double _t123 = _t24*_t25;
  const double _t124 = _hc1[3]*_t6;
  const double _t125 = _t113*_t124;
  const double _t127 = _t21*_t56;
  const double _t128 = _t127*_t50;
  const double _t129 = _t45*_t75;
  const double _t130 = _hc0[1]*_hc1[1];
  const double _t131 = _t130*_t20;
  const double _t132 = _t131*_t21;
  const double _t133 = _t132*_t16;
  const double _t134 = _hc1[2]*_t5;
  const double _t135 = (0.3e1 / 0.4e1)*_t134;
  const double _t136 = _hc0[1]*_t21;
  const double _t137 = _t136*_t52;
  const double _t143 = _t24*_t73;
  const double _t144 = _t111 + _t112 + _t113*_t115 + _t117*_t123 + _t118*_t119 + _t120*_t122 + _t125*_t24 + _t126*_t46 + _t126*_t49 + _t126*_t51 + _t126*_t54 + (0.3e1 / 0.4e1)*_t128 + (0.3e1 / 0.4e1)*_t129 + (0.3e1 / 0.2e1)*_t133 + _t135*_t137 + _t141*_t78 + _t142*_t143 + _t143*_t50 + _t45*_t78;
  const double _t150 = _t131*_t4;
  const double _t152 = _t151*_t48;
  const double _t153 = _t130*_t151;
  const double _t154 = _t4*_t73;
  const double _t155 = _t31*_t56;
  const double _t156 = (0.1e1 / 0.4e1)*_t155;
  const double _t158 = _hc0[1]*_t31;
  const double _t159 = _hc1[2]*_t158;
  const double _t161 = _hc0[2]*_t55;
  const double _t162 = _t161*_t47;
  const double _t163 = _t45*_t77;
  const double _t166 = _t122*_t47;
  const double _t167 = _t29*_t53;
  const double _t168 = _t167*_t24;
  const double _t169 = _t124*_t157;
  const double _t170 = _hc0[1]*_t134;
  const double _t171 = _t170*_t57;
  const double _t173 = _t161*_t57;
  const double _t174 = _t173*_t31;
  const double _t175 = _t130*_t29;
  const double _t176 = _t175*_t21;
  const double _t177 = _t16*_t176;
  const double _t178 = _t131*_t31;
  const double _t179 = _t16*_t178;
  const double _t180 = _t21*_t48;
  const double _t181 = _t16*_t180;
  const double _t182 = _t181*_t31;
  const double _t183 = _t16*_t73;
  const double _t184 = _t183*_t29;
  const double _t185 = (0.1e1 / 0.2e1)*_t177 + (0.1e1 / 0.2e1)*_t179 + (0.1e1 / 0.2e1)*_t182 + (0.1e1 / 0.2e1)*_t184;
  const double _t186 = _t16*_t22;
  const double _t187 = _t186*_t35;
  const double _t188 = _t1*_t187;
  const double _t189 = _t16*_t25;
  const double _t190 = _t189*_t35;
  const double _t191 = _t1*_t190;
  const double _t192 = _t188 - _t191 + _t23 + _t26;
  const double _t193 = _t119*_t148 + _t123*_t147 + (0.1e1 / 0.2e1)*_t133 + _t149*_t46 + _t149*_t49 + _t149*_t51 + _t149*_t54 + _t150 + _t152 - _t153 - _t154 + _t156*_t50 + _t157*_t159 + _t160*_t162 + _t163*_t31 + _t165*_t166 + _t168*_t50 + _t169*_t29 + _t171*_t172 + (0.1e1 / 0.2e1)*_t174 + _t185 + _t192 + _t45*_t72 + _t91 + _t92;
  const double _t195 = (0.1e1 / 0.2e1)*_t71;
  const double _t197 = _t180*_t31;
  const double _t198 = _t195*_t21 + _t196*_t197 + _t196*_t74 + _t61 + _t67 - _t68 + (0.1e1 / 0.2e1)*_t76 + _t8 + _t93;
  const double _t202 = _t33*_t38;
  const double _t205 = _t25*_t3;
  const double _t206 = _t22*_t3;
  const double _t207 = _t19*_t25;
  const double _t208 = _t19*_t22;
  const double _t209 = _t186*_t82;
  const double _t210 = _t189*_t86;
  const double _t211 = _t175*_t4;
  const double _t213 = _t212*_t48;
  const double _t214 = _t175*_t31;
  const double _t215 = _t16*_t214;
  const double _t216 = _t130*_t212;
  const double _t217 = _t167*_t4;
  const double _t221 = _hc1[2]*_t136;
  const double _t223 = (0.1e1 / 0.4e1)*_t161;
  const double _t226 = _t124*_t20;
  const double _t227 = (0.1e1 / 0.2e1)*_t134;
  const double _t228 = _t158*_t227;
  const double _t231 = _t161*_t172;
  const double _t232 = _t30 + _t32;
  const double _t233 = _t122*_t225 + _t127*_t218 + _t143*_t86 + _t149*_t85 + _t149*_t89 + _t185 + (0.1e1 / 0.2e1)*_t188 - 0.1e1 / 0.2e1*_t191 + (0.1e1 / 0.2e1)*_t205 - 0.1e1 / 0.2e1*_t206 + (0.1e1 / 0.2e1)*_t207 - 0.1e1 / 0.2e1*_t208 + (0.1e1 / 0.4e1)*_t209 + (0.1e1 / 0.4e1)*_t210 + _t211 + _t213 + (0.1e1 / 0.2e1)*_t215 - _t216 - _t217 + _t219*_t75 + _t220*_t221 + _t220*_t226 + _t222*_t223 + _t228*_t229 + (0.1e1 / 0.2e1)*_t23 + _t230*_t231 + _t232 + (0.1e1 / 0.2e1)*_t26 + _t78*_t82;
  const double _t239 = (_t33 * _t33 * _t33);
  const double _t240 = (0.1e1 / 0.2e1)*_t89;
  const double _t241 = (0.1e1 / 0.2e1)*_t83;
  const double _t242 = (0.1e1 / 0.2e1)*_t87;
  const double _t243 = (0.1e1 / 0.2e1)*_t85;
  const double _t244 = _t240*_t5 + _t241*_t5 + _t242*_t5 + _t243*_t5 + _t69 + _t70 + _t8 + _t90;
  const double _t245 = (0.3e1 / 0.2e1)*_t30;
  const double _t246 = (0.3e1 / 0.2e1)*_t32;
  const double _t248 = _t124*_t247;
  const double _t252 = (0.3e1 / 0.4e1)*_t71;
  const double _t253 = _t135*_t158;
  const double _t258 = _t115*_t247 + _t119*_t250 + _t122*_t251 + _t123*_t249 + _t126*_t85 + _t126*_t89 + (0.3e1 / 0.4e1)*_t155*_t86 + _t168*_t255 + _t168*_t86 + (0.3e1 / 0.4e1)*_t209 + (0.3e1 / 0.4e1)*_t210 + (0.3e1 / 0.2e1)*_t215 + _t24*_t248 + _t245 + _t246 + _t252*_t82 + _t253*_t88 + _t256*_t77 + _t257*_t77;
  const double _t98 = -_hc2[0]*_t97;
  const double _t100 = _hc2[1]*_t27;
  const double _t102 = _hc2[3]*_t3;
  const double _t103 = _hc2[2]*_t12;
  const double _t104 = _t103*_t40;
  const double _t105 = _t62*_t65;
  const double _t145 = my_piecewise3(_t10, 0, _t100*_t99 + _t101*_t102 - 0.3e1*_t104 - 0.3e1*_t105 + _t110*_t66 + _t144*_t63 + _t62*_t66 + _t98);
  const double _t146 = 0.2e1*_t80;
  const double _t194 = _hc2[1]*_t33;
  const double _t199 = _t33*_t41;
  const double _t200 = _t102*_t40;
  const double _t201 = _hc2[2]*_t27;
  const double _t203 = -_t201*_t202 - _t39*_t79 + _t98;
  const double _t204 = my_piecewise3(_t10, 0, _t100*_t139 - _t104 - _t105 + _t193*_t63 + _t194*_t36 + _t198*_t66 + _t199*_t62 + _t200*_t33 + _t203);
  const double _t234 = _t65*_t94;
  const double _t235 = _t103*_t81;
  const double _t236 = _t102*_t81;
  const double _t237 = 0.2e1*_t199;
  const double _t238 = my_piecewise3(_t10, 0, _t100*_t36 + _t139*_t194 + _t203 + _t233*_t63 - _t234 - _t235 + _t236*_t27 + _t237*_t79 + _t66*_t94);
  const double _t259 = my_piecewise3(_t10, 0, _t102*_t239 + _t194*_t99 + _t199*_t244 + _t199*_t94 - 0.3e1*_t234 - 0.3e1*_t235 + _t258*_t63 + _t98);
  const double d3F_dna3 = _t145*_t2 + 0.3e1*_t64;
  const double d3F_dna2_dnb = _t146 + _t2*_t204 + _t64;
  const double d3F_dna_dnb2 = _t146 + _t2*_t238 + _t95;
  const double d3F_dnb3 = _t2*_t259 + 0.3e1*_t95;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t260 = 0.24e2/xc_powi(_t2, 5);
  const double _t262 = 0.24e2*_t96;
  const double _t264 = 0.12e2*_t35;
  const double _t270 = (0.3e1 / 0.4e1)*_t5;
  const double _t285 = (_t20 * _t20 * _t20 * _t20);
  const double _t288 = _t1*_t260;
  const double _t289 = -_t262 + _t288;
  const double _t292 = _t113*_t16;
  const double _t303 = (0.3e1 / 0.2e1)*_t45;
  const double _t305 = 0.3e1*_t16;
  const double _t308 = 0.12e2*_t96;
  const double _t309 = _t1*_t308;
  const double _t310 = -_t264 + _t309;
  const double _t313 = _t14 - _t15;
  const double _t314 = -_t313*_t35;
  const double _t315 = _t314 + _t38;
  const double _t317 = 0.6e1*_t12;
  const double _t318 = 0.6e1*na - 0.6e1*nb;
  const double _t319 = 0.4e1*na - 0.4e1*nb;
  const double _t320 = _t313*_t35 - _t38;
  const double _t321 = _t1*_t99;
  const double _t322 = _t288 - _t308;
  const double _t325 = (0.1e1 / 0.2e1)*_t4;
  const double _t328 = _t4*_t47;
  const double _t331 = (0.3e1 / 0.2e1)*_t4;
  const double _t334 = _t309 - 0.4e1*_t35;
  const double _t338 = _t113*_t29;
  const double _t342 = _t126*_t45;
  const double _t343 = _t126*_t50;
  const double _t351 = (0.3e1 / 0.4e1)*_t165;
  const double _t354 = _t1*_t35;
  const double _t355 = 0.3e1*_t354;
  const double _t356 = _t16*_t355;
  const double _t362 = _t31*_t45;
  const double _t364 = _t29*_t50;
  const double _t367 = _t16*_t29;
  const double _t369 = _t16*_t31;
  const double _t373 = (0.3e1 / 0.2e1)*_t31;
  const double _t376 = 0.18e2*_t96;
  const double _t380 = _t165*_t47;
  const double _t393 = 0.8e1*_t35;
  const double _t399 = (0.1e1 / 0.2e1)*_t86;
  const double _t400 = (0.1e1 / 0.2e1)*_t82;
  const double _t401 = (0.1e1 / 0.2e1)*_t222;
  const double _t405 = (_t1 * _t1)*_t96;
  const double _t406 = 0.10e2*_t354;
  const double _t407 = 0.2e1*_t405;
  const double _t408 = _t1*_t96;
  const double _t409 = 0.3e1*_t408;
  const double _t410 = _t21*_t3;
  const double _t411 = _t16*_t44;
  const double _t412 = _t16*_t354;
  const double _t415 = (0.1e1 / 0.2e1)*_t16;
  const double _t416 = _t415*_t88;
  const double _t422 = 0.2e1*_t151;
  const double _t424 = _t314 + _t43;
  const double _t427 = _t313*_t35 + _t38;
  const double _t430 = _t20*_t212;
  const double _t436 = (0.3e1 / 0.2e1)*_t3;
  const double _t437 = _t3*_t373;
  const double _t443 = (0.3e1 / 0.2e1)*_t19;
  const double _t444 = (0.3e1 / 0.2e1)*_t408;
  const double _t445 = _t19*_t373;
  const double _t448 = _t20*_t247;
  const double _t449 = _t126*_t82;
  const double _t450 = _t126*_t86;
  const double _t451 = _t126*_t88;
  const double _t455 = (0.3e1 / 0.2e1)*_t82;
  const double _t459 = (_t29 * _t29 * _t29 * _t29);
  const double _t460 = _t262 + _t288;
  const double _t461 = (_t31 * _t31 * _t31 * _t31);
  const double _t462 = _t264 + _t309;
  const double _t269 = (0.3e1 / 0.2e1)*_t8;
  const double _t273 = (0.3e1 / 0.2e1)*_hc0[2];
  const double _t274 = _t273*_t55;
  const double _t275 = _t196*_t22;
  const double _t276 = _t121*_t196;
  const double _t277 = _t196*_t25;
  const double _t278 = (0.3e1 / 0.2e1)*_t46;
  const double _t279 = (0.3e1 / 0.2e1)*_t49;
  const double _t280 = (0.3e1 / 0.2e1)*_t51;
  const double _t281 = (0.3e1 / 0.2e1)*_t54;
  const double _t282 = 0.3e1*_t132;
  const double _t283 = _t180*_t196;
  const double _t284 = _t196*_t73;
  const double _t286 = _t134*_t273;
  const double _t287 = _hc0[3]*_t55;
  const double _t290 = _hc0[4]*_t24*_t7;
  const double _t291 = _t118*_t186;
  const double _t293 = _hc1[1]*_t292;
  const double _t294 = 0.3e1*_hc0[2];
  const double _t295 = _t121*_t16;
  const double _t296 = _t120*_t295;
  const double _t297 = _t117*_t189;
  const double _t298 = _hc1[4]*_t24*_t6;
  const double _t299 = _t24*_t53;
  const double _t300 = _t124*_t292;
  const double _t301 = _hc1[3]*_t5;
  const double _t302 = _t136*_t301;
  const double _t304 = _t50*_t56;
  const double _t306 = _t130*_t21;
  const double _t307 = _t306*_t50;
  const double _t311 = _t131*_t45;
  const double _t312 = _hc1[2]*_t137;
  const double _t316 = _t299*_t50;
  const double _t323 = _t148*_t186;
  const double _t324 = _t147*_t189;
  const double _t326 = _t325*_t48;
  const double _t327 = _t130*_t4;
  const double _t329 = _hc1[1]*_t273;
  const double _t330 = _t124*_t52;
  const double _t332 = _t325*_t53;
  const double _t333 = _hc1[3]*_t24;
  const double _t335 = _t31*_t77;
  const double _t336 = _t149*_t180;
  const double _t337 = _t149*_t73;
  const double _t339 = (0.3e1 / 0.2e1)*_t327;
  const double _t340 = _hc0[1]*_hc1[2];
  const double _t341 = _t331*_t340;
  const double _t344 = _t130*_t31;
  const double _t345 = _t159*_t52;
  const double _t346 = _hc0[2]*_t126;
  const double _t347 = _hc1[1]*_t29;
  const double _t348 = _t347*_t47;
  const double _t349 = _t114*_t134;
  const double _t350 = _t31*_t48;
  const double _t352 = _t295*_t47;
  const double _t353 = _t29*_t330;
  const double _t357 = _t340*_t57;
  const double _t358 = _hc1[1]*_t57;
  const double _t359 = _t159*_t20;
  const double _t360 = _t24*_t359;
  const double _t361 = _t160*_t161*_t21;
  const double _t363 = _t122*_t21;
  const double _t365 = _t226*_t24;
  const double _t366 = _t29*_t365;
  const double _t368 = _t357*_t367;
  const double _t370 = _hc0[1]*_t135*_t229;
  const double _t371 = _t115*_t230;
  const double _t372 = _t230*_t349;
  const double _t374 = _t131*_t373 + (0.3e1 / 0.2e1)*_t176 + _t180*_t373 + _t22*_t355 - _t25*_t355 + (0.3e1 / 0.2e1)*_t74;
  const double _t378 = (0.1e1 / 0.2e1)*_t155;
  const double _t379 = _t196*_t350;
  const double _t381 = _t167*_t196;
  const double _t382 = _t177 + _t179 + _t182 + _t184;
  const double _t394 = _t27*_t81;
  const double _t402 = _t226*_t88;
  const double _t403 = _t134*_t158;
  const double _t404 = _t161*_t29;
  const double _t413 = _t16*_t167;
  const double _t414 = _t16*_t48;
  const double _t417 = _hc0[2]*_t415;
  const double _t418 = _hc0[2]*_hc1[2];
  const double _t419 = _t306*_t86;
  const double _t420 = 0.2e1*_t340;
  const double _t421 = _hc0[2]*_t347;
  const double _t423 = _t131*_t82;
  const double _t425 = _t124*_t220;
  const double _t426 = _hc1[1]*_t222;
  const double _t428 = _t225*_t295;
  const double _t429 = _hc0[2]*_t31;
  const double _t431 = _t122*_t84;
  const double _t432 = _t158*_t301;
  const double _t433 = _t224*_t287;
  const double _t434 = (0.3e1 / 0.2e1)*_t85;
  const double _t435 = (0.3e1 / 0.2e1)*_t89;
  const double _t438 = _t186*_t250;
  const double _t439 = _t251*_t295;
  const double _t440 = _t189*_t249;
  const double _t441 = _t16*_t248;
  const double _t442 = _hc1[1]*_t247;
  const double _t446 = _t149*_t48;
  const double _t447 = _t149*_t167;
  const double _t452 = _t221*_t24*_t29;
  const double _t453 = _t20*_t223;
  const double _t456 = _t170*_t88;
  const double _t457 = _t56*_t86;
  const double _t458 = _t196*_t48;
  const double _t463 = _t29*_t403;
  const double _t261 = _hc2[0]*_t260;
  const double _t263 = _hc2[4]*_t3;
  const double _t265 = _hc2[2]*_t40;
  const double _t266 = _hc2[3]*_t138;
  const double _t267 = _hc2[1]*_t62;
  const double _t268 = _t138*_t201;
  const double _t271 = _t110*_t41;
  const double _t272 = _hc2[1]*_t138;
  const double _t375 = _hc2[3]*_t12;
  const double _t377 = 0.3e1*_t65;
  const double _t383 = _t41*_t62;
  const double _t384 = _t103*_t27;
  const double _t385 = 0.3e1*_t384;
  const double _t386 = _t103*_t33;
  const double _t387 = 0.3e1*_t375;
  const double _t388 = _t102*_t27*_t33;
  const double _t389 = _hc2[1]*_t79;
  const double _t390 = _t201*_t33;
  const double _t391 = _t261 + _t389*_t99 + _t390*_t99;
  const double _t392 = _hc2[2]*_t81;
  const double _t395 = _hc2[1]*_t94;
  const double _t396 = _t201*_t38;
  const double _t397 = _hc2[2]*_t33*_t79;
  const double _t398 = _t41*_t79;
  const double _t454 = _hc2[2]*_t138*_t33;
  const double d4F_dna4 = 0.4e1*_t145 + _t2*my_piecewise3(_t10, 0, -_t100*_t262 - _t101*_t266 + _t110*_t200 - _t110*_t268 - _t144*_t272 + 0.2e1*_t144*_t66 + _t200*_t62 + _t200*(_t111*_t16 + _t112*_t16 + _t269 + _t270*_t46 + _t270*_t49 + _t270*_t51 + _t270*_t54 + (0.3e1 / 0.2e1)*_t58) + _t261 + _t263*(_t27 * _t27 * _t27 * _t27) + _t264*_t265 + _t264*_t267 - _t268*_t62 + _t271*_t62 + _t41*(_t62 * _t62) + _t63*(_t113*_t302 + _t117*_t127 + _t117*_t284 + _t118*_t283 + _t118*_t75 + _t119*_t289 - _t123*_t289 + 0.6e1*_t132 + _t141*_t163 + _t141*_t173 + _t141*_t181 + _t142*_t169 + _t142*_t171 + _t142*_t183 + _t142*_t316 + _t143*_t310 + _t166*_t320 + _t166*(-_t138 + _t319*_t35) + _t166*(-_t317 + _t318*_t35) + _t169*_t50 + _t169*(_t317 - _t321) + _t170*_t303*_t52 + _t171*_t50 + _t173*_t45 + _t181*_t45 + _t183*_t50 + (_t21 * _t21 * _t21 * _t21)*_t290 + _t274*_t315*_t47 + _t285*_t286 - _t285*_t287 + _t285*_t298 + _t291 + _t293*_t294 + _t296 + _t297 + _t299*(_t50 * _t50) + _t300 + _t303*_t304 + _t305*_t307 + _t305*_t311 + _t305*_t312 - _t310*_t78 + (_t45 * _t45)*_t77 + 0.3e1*_t46 + 0.3e1*_t49 + 0.3e1*_t51 + 0.3e1*_t54) + _t66*(_t113*_t274 + _t117*_t277 + _t118*_t275 + _t120*_t276 + _t125*_t196 + (0.3e1 / 0.2e1)*_t128 + (0.3e1 / 0.2e1)*_t129 + (0.3e1 / 0.2e1)*_t134*_t137 + _t141*_t283 + _t142*_t284 + _t16*_t278 + _t16*_t279 + _t16*_t280 + _t16*_t281 + _t16*_t282 + 0.3e1*_t23 + 0.3e1*_t26 + _t283*_t45 + _t284*_t50));
  const double d4F_dna3_dnb = _t145 + _t2*my_piecewise3(_t10, 0, -_t100*_t376 + _t101*_t263*_t33 - _t101*_t375 - _t110*_t384 + _t110*_t388 + _t144*_t199 - _t144*_t65 - _t193*_t377 + _t193*_t66 - _t194*_t97 - _t198*_t385 + _t200*(_t197*_t270 + _t21*_t252 + _t269 + _t270*_t74 + (0.3e1 / 0.4e1)*_t59 + (0.3e1 / 0.4e1)*_t60 + (0.3e1 / 0.2e1)*_t67 - 0.3e1 / 0.2e1*_t68 + (0.3e1 / 0.4e1)*_t69 + (0.3e1 / 0.4e1)*_t70 + (0.3e1 / 0.4e1)*_t76) + _t265*_t99 + _t267*_t99 + _t271*_t79 - _t33*_t387*_t40 + _t383*_t79 - _t384*_t62 - 0.3e1*_t386*_t62 + _t388*_t62 + _t391 + _t63*(_t113*_t158*_t333 + _t113*_t287*_t351 + _t114*_t293 + _t115*_t20*_t362 + _t117*_t156 + _t117*_t168 + _t118*_t335 + _t118*_t72 + _t119*_t322 + _t120*_t160*_t287 + _t120*_t165*_t290 + (0.3e1 / 0.2e1)*_t121*_t328 + _t122*_t141*_t230 - _t123*_t322 + _t126*_t307 + _t126*_t311 + _t126*_t312 + _t126*_t345 + _t126*_t353 + (0.3e1 / 0.4e1)*_t127*_t147 + _t131*_t356 + _t135*_t136*_t364 + _t141*_t326 + _t141*_t336 + _t141*_t361 - _t142*_t332 + _t142*_t337 + _t142*_t360 + _t142*_t366 + _t143*_t147 + _t143*_t334 + (0.3e1 / 0.4e1)*_t148*_t75 + _t148*_t78 + _t167*_t343 + _t175*_t342 + _t181*_t355 - _t183*_t355 + _t278 + _t279 + _t280 + _t281 + _t282 + (0.3e1 / 0.4e1)*_t29*_t302*_t52 + (0.1e1 / 0.4e1)*_t291 + _t294*_t358*_t4 + (0.1e1 / 0.4e1)*_t296 + (0.1e1 / 0.4e1)*_t297 + _t298*_t338 + (0.1e1 / 0.4e1)*_t300 - _t303*_t327 - _t306*_t356 + (0.3e1 / 0.4e1)*_t323 + (0.3e1 / 0.4e1)*_t324 + _t326*_t45 - _t328*_t329 + _t329*_t369*_t57 - _t330*_t331 - _t332*_t50 - _t334*_t78 + _t336*_t45 + _t337*_t50 + _t338*_t349 + _t339*_t50 + _t341*_t52 + _t342*_t350 + _t343*_t344 + _t346*_t348 + _t351*_t352 - 0.3e1*_t357*_t4 + _t360*_t50 + _t361*_t45 + _t362*_t363 + _t364*_t365 + (0.3e1 / 0.2e1)*_t368 + _t370*_t45 + _t371*_t50 + _t372*_t52 + _t374) + _t66*(_t106*_t16 + _t107*_t16 + _t108*_t16 + _t109*_t16 + _t133 + _t147*_t277 + _t148*_t275 + 0.2e1*_t150 + 0.2e1*_t152 - 0.2e1*_t153 - 0.2e1*_t154 + _t162*_t172 + _t171*_t29 + _t174 + _t186*_t44 - _t189*_t44 + _t195*_t45 + _t196*_t353 + _t228*_t52 + 0.2e1*_t23 + _t232 + 0.2e1*_t26 + _t276*_t380 + _t378*_t50 + _t379*_t45 + _t381*_t50 + _t382)) + 0.3e1*_t204;
  const double d4F_dna2_dnb2 = _t2*my_piecewise3(_t10, 0, -_hc2[2]*_t202*_t62 - _hc2[3]*_t202*_t40 - _hc2[3]*_t38*_t394 - _t100*_t308 - _t138*_t397 + _t193*_t237 - _t193*_t39 - _t194*_t308 + 0.2e1*_t198*_t388 - _t198*_t396 + _t198*_t398 + _t200*_t94 - _t233*_t39 + _t236*_t62 + _t261 + _t263*_t40*_t81 + _t265*_t36 + _t267*_t36 + _t36*_t392 + _t36*_t395 + _t383*_t94 + _t389*_t393 + _t390*_t393 - _t396*_t94 + _t63*((0.1e1 / 0.2e1)*_hc0[1]*_t301*_t57*_t88 + 0.2e1*_hc0[2]*_hc1[1]*_t430 + _hc0[2]*_t358*_t369 - _hc1[1]*_t422*_t429 + _t106 + _t107 + _t108 + _t109 + _t121*_t31*_t422 - 0.4e1*_t130*_t405 + _t130*_t410 - _t131*_t19 - _t131*_t3 + _t131*_t412 + _t132 + _t134*_t29*_t429*_t57 + _t147*_t378 + _t147*_t381 + _t148*_t195 + _t148*_t379 - _t151*_t29*_t420 + _t157*_t340*_t82 + _t157*_t418*_t84 + _t16*_t230*_t421 + (0.1e1 / 0.4e1)*_t162*_t424 + _t163*_t82 + (0.1e1 / 0.2e1)*_t165*_t352 + _t166*_t427 + _t169*_t86 + _t171*_t399 + _t172*_t287*_t380 + _t172*_t432*_t52 + _t173*_t400 + _t175*_t411 + _t175*_t415*_t45 + 0.2e1*_t176 + 0.2e1*_t178 - _t180*_t19 + _t181*_t354 + _t181*_t400 - _t183*_t354 + _t183*_t399 - _t186*_t409 - _t187 + _t189*_t409 + _t19*_t306 + _t19*_t73 + _t190 + 0.2e1*_t197 + _t214 + _t218*_t45*_t56 + _t219*_t304 + _t22*_t406 + _t220*_t340*_t45 + _t220*_t418*_t47 + _t221*_t416 + _t223*_t315*_t84 - 0.2e1*_t226*_t29*_t4 + _t226*_t416 + _t228*_t364 + _t229*_t4*_t420 + _t231*_t362 + _t240 + _t241 + _t242 + _t243 - _t25*_t406 + _t290*_t47*_t84 + _t298*_t52*_t88 + _t3*_t73 - _t306*_t412 + _t31*_t414*_t44 + _t316*_t86 + _t320*_t431 + (0.1e1 / 0.2e1)*_t323 + (0.1e1 / 0.2e1)*_t324 - _t344*_t411 + _t344*_t415*_t50 + _t345*_t415 + _t348*_t417 + _t353*_t415 + _t359*_t367 + (0.1e1 / 0.2e1)*_t362*_t414 + _t368 + _t401*_t433 + _t407*_t48 + _t407*_t53 - _t410*_t48 - _t413*_t44 + (0.1e1 / 0.2e1)*_t413*_t50 + _t415*_t419 + _t415*_t423 + _t417*_t426 - _t420*_t430 + _t421*_t422 + _t425*_t50 + (0.1e1 / 0.2e1)*_t428 + 0.2e1*_t74) + _t66*(_t127*_t399 + _t136*_t227*_t88 + _t16*_t240 + _t16*_t243 + _t161*_t401 + _t192 + _t196*_t402 + _t205 - _t206 + _t207 - _t208 + (0.1e1 / 0.2e1)*_t209 + (0.1e1 / 0.2e1)*_t210 + 0.2e1*_t211 + 0.2e1*_t213 + _t215 - 0.2e1*_t216 - 0.2e1*_t217 + _t225*_t276 + _t229*_t403 + _t230*_t404 + _t283*_t82 + _t284*_t86 + 0.2e1*_t30 + 0.2e1*_t32 + _t382 + _t400*_t75)) + 0.2e1*_t204 + 0.2e1*_t238;
  const double d4F_dna_dnb3 = _t2*my_piecewise3(_t10, 0, -_t100*_t97 - _t194*_t376 + 0.3e1*_t199*_t233 - _t233*_t377 + 0.3e1*_t236*_t79 + _t239*_t263*_t27 - _t239*_t375 - _t244*_t386 + _t244*_t388 - _t258*_t65 + _t258*_t66 - _t317*_t397 - _t385*_t94 - _t386*_t94 - _t387*_t394 + _t388*_t94 + _t391 + _t392*_t99 + _t395*_t99 + 0.3e1*_t398*_t94 + _t63*(_t115*_t21*_t29*_t82 + _t12*_t22 - _t12*_t25 + _t121*_t331*_t84 - _t124*_t331*_t88 + _t126*_t402 + _t126*_t419 + _t126*_t423 + (0.1e1 / 0.4e1)*_t127*_t249 - _t130*_t373*_t412 + _t130*_t437 + _t130*_t445 + _t136*_t247*_t333 + _t143*_t249 + _t159*_t451 + _t167*_t436 + _t167*_t443 + (0.3e1 / 0.2e1)*_t175*_t412 - _t175*_t436 - _t175*_t443 + _t175*_t449 + _t180*_t449 - _t186*_t444 - 0.1e1 / 0.2e1*_t187 + _t189*_t444 + (0.1e1 / 0.2e1)*_t190 + (0.1e1 / 0.4e1)*_t20*_t251*_t287 + _t20*_t253*_t86 + _t20*_t340*_t367*_t373 + (0.3e1 / 0.4e1)*_t20*_t432*_t88 - 0.3e1*_t212*_t29*_t340 + _t212*_t294*_t347 + 0.3e1*_t214 + _t221*_t451 + _t224*_t251*_t290 + _t230*_t329*_t367 + (0.3e1 / 0.4e1)*_t247*_t433 + (0.1e1 / 0.4e1)*_t250*_t75 + _t250*_t78 + _t255*_t366 + _t255*_t447 + _t255*_t452 + _t256*_t363 + _t256*_t446 + _t256*_t453 + _t257*_t363 + _t257*_t446 + _t257*_t453 + _t298*_t448 - _t329*_t4*_t84 + _t331*_t48*_t82 - _t331*_t53*_t86 - _t339*_t82 + _t339*_t86 + _t341*_t88 + _t344*_t450 + _t346*_t426 + _t346*_t442 + _t349*_t448 + _t354*_t373*_t414 - 0.3e1 / 0.2e1*_t354*_t413 + _t366*_t86 + _t370*_t82 + _t371*_t86 + _t372*_t88 + _t374 + (0.3e1 / 0.4e1)*_t428 + _t434 + _t435 - _t437*_t48 + (0.1e1 / 0.4e1)*_t438 + (0.1e1 / 0.4e1)*_t439 + (0.1e1 / 0.4e1)*_t440 + (0.1e1 / 0.4e1)*_t441 - _t445*_t48 + _t447*_t86 + _t450*_t73 + _t452*_t86 + (0.3e1 / 0.2e1)*_t83 + (0.3e1 / 0.2e1)*_t87)) + 0.3e1*_t238 + _t259;
  const double d4F_dnb4 = _t2*my_piecewise3(_t10, 0, -_t194*_t262 + _t199*(_t16*_t434 + _t16*_t435 + _t196*_t248 + (0.3e1 / 0.2e1)*_t209 + (0.3e1 / 0.2e1)*_t210 + 0.3e1*_t215 + _t247*_t274 + _t249*_t277 + _t250*_t275 + _t251*_t276 + _t255*_t381 + _t256*_t458 + _t257*_t458 + 0.3e1*_t30 + 0.3e1*_t32 + _t373*_t456 + _t373*_t457 + _t381*_t86 + _t455*_t71) + _t236*_t244 + _t236*_t94 + _t236*(_t16*_t245 + _t16*_t246 + _t269 + _t270*_t83 + _t270*_t85 + _t270*_t87 + _t270*_t89 + (0.3e1 / 0.2e1)*_t90) + _t237*_t258 - _t239*_t266 + _t244*_t41*_t94 - _t244*_t454 - _t258*_t272 + _t261 + _t263*(_t33 * _t33 * _t33 * _t33) + _t264*_t392 + _t264*_t395 + _t41*(_t94 * _t94) - _t454*_t94 + _t63*(_t119*_t460 - _t123*_t460 + _t155*_t249 + _t159*_t305*_t88 + _t16*_t294*_t442 + _t168*_t462 + _t175*_t305*_t82 + 0.6e1*_t214 + _t247*_t432 + _t249*_t381 + _t250*_t379 + _t250*_t71 + _t254*_t77*_t82 + _t255*_t299*_t86 + _t255*_t413 + _t255*_t425 + _t255*_t463 + _t256*_t404 + _t256*_t414 + _t257*_t404 + _t257*_t414 + _t274*_t424*_t84 + _t286*_t461 - _t287*_t459 + _t290*_t461 + _t298*_t459 + _t299*(_t86 * _t86) + _t305*_t344*_t86 - _t335*_t462 + _t413*_t86 + _t425*_t86 + _t425*(-_t317 - _t321) + _t427*_t431 + _t431*(_t138 + _t319*_t35) + _t431*(_t317 + _t318*_t35) + _t438 + _t439 + _t440 + _t441 + _t455*_t456 + _t455*_t457 + _t463*_t86 + _t77*(_t82 * _t82) + 0.3e1*_t83 + 0.3e1*_t85 + 0.3e1*_t87 + 0.3e1*_t89)) + 0.4e1*_t259;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif