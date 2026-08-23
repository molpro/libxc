/*
  Generated from python/lda_exc/lda_x_1d_exponential.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_x_1d_exponential
*/

#ifndef _LDA_X_1D_EXPONENTIAL_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_X_1D_EXPONENTIAL_KERNEL_BODY
#define _KMAX 0
#define _LDA_X_1D_EXPONENTIAL_HELPER_BODIES
#include "lda_x_1d_exponential.c"
#undef _LDA_X_1D_EXPONENTIAL_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_X_1D_EXPONENTIAL_HELPER_BODIES
#include "lda_x_1d_exponential.c"
#undef _LDA_X_1D_EXPONENTIAL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_X_1D_EXPONENTIAL_HELPER_BODIES
#include "lda_x_1d_exponential.c"
#undef _LDA_X_1D_EXPONENTIAL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_X_1D_EXPONENTIAL_HELPER_BODIES
#include "lda_x_1d_exponential.c"
#undef _LDA_X_1D_EXPONENTIAL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_X_1D_EXPONENTIAL_HELPER_BODIES
#include "lda_x_1d_exponential.c"
#undef _LDA_X_1D_EXPONENTIAL_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_x_1d_exponential.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_x_1d_exponential.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_x_1d_exponential.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_x_1d_exponential.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_x_1d_exponential.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_x_1d_exponential.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_x_1d_exponential.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_x_1d_exponential.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_x_1d_exponential.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_x_1d_exponential.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_X_1D_EXPONENTIAL_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(x1d_inter_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (x * x);
#if _KMAX >= 1
  const double _t2 = 0.2e1*xc_E1_scaled_d1(_t1);
#endif
#if _KMAX >= 2
  const double _t3 = xc_E1_scaled_d2(_t1);
#endif
#if _KMAX >= 3
  const double _t4 = 0.12e2*_t3;
  const double _t5 = xc_E1_scaled_d3(_t1);
#endif

  const double f = xc_E1_scaled(_t1);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t2*x;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 0.4e1*_t1*_t3 + _t2;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = _t4*x + 0.8e1*_t5*(x * x * x);
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0.48e2*_t1*_t5 + _t4 + 0.16e2*(x * x * x * x)*xc_E1_scaled_d4(_t1);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(x1d_R_k, _KMAX)(const xc_func_type *p, double rs, double *out) {
  const lda_x_1d_exponential_params *params = (const lda_x_1d_exponential_params *)(p->params);

  const double _t1 = M_PI*params->beta;
  const double _t2 = (0.1e1 / 0.2e1)*_t1;

  const double f = _t2/rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_t2/(rs * rs);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t1/(rs * rs * rs);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.3e1*_t1/(rs * rs * rs * rs);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.12e2*_t1/xc_powi(rs, 5);
  out[4] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  assert(p->params != NULL);
  const lda_x_1d_exponential_params *params = (const lda_x_1d_exponential_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(x1d_R_k, _KMAX)(p, (0.1e1 / 0.2e1)/na, _hc0);
  const double _t1 = 0.1e1 <= p->zeta_threshold || (0.1e1 / 0.2e1)*na <= p->dens_threshold;
  const double _t2 = xc_integrate(func2, NULL, 1e-20, _hc0[0]);
  const double _t3 = (0.1e1 / (_hc0[0]));
  const double _t4 = (0.1e1 / M_PI);
  const double _t5 = (0.1e1 / (params->beta));
  const double _t6 = _t4*_t5;
  const double _t7 = 0.25*_t6;
  const double _t8 = 0.2e1*my_piecewise3(_t1, 0, _t7*(_t2*_t3 - xc_integrate(func1, NULL, 1e-20, _hc0[0])));
  const double zk = _t8;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t9 = _t2*_t6;
  const double _t10 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t11 = _hc0[1]*_t10;
  const double _t12 = my_piecewise3(_t1, 0, 0.125*_t11*_t9/(na * na));
  const double _t13 = 0.2e1*na;
  const double dF_dna = _t12*_t13 + _t8;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(x1d_inter_k, _KMAX)(p, _hc0[0], _hc1);
  const double _t14 = (0.1e1 / (na * na * na * na));
  const double _t15 = _t10*_t9;
  const double _t16 = _hc0[2]*_t15;
  const double _t17 = ((_hc0[1]) * (_hc0[1]));
  const double _t18 = _t3*_t6;
  const double _t19 = _hc1[0]*_t18;
  const double _t20 = 0.0625*_t19;
  const double _t21 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t22 = my_piecewise3(_t1, 0, -_t11*_t2*_t7/(na * na * na) - 0.0625*_t14*_t16 + 0.125*_t14*_t17*_t2*_t21*_t4*_t5 - _t14*_t17*_t20);
  const double d2F_dna2 = 0.4e1*_t12 + _t13*_t22;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t23 = 0.75*_t9;
  const double _t24 = xc_powi(na, -5);
  const double _t25 = 0.375*_t24;
  const double _t26 = xc_powi(na, -6);
  const double _t27 = 0.03125*_t26;
  const double _t28 = _hc0[3]*_t15;
  const double _t29 = _hc0[1]*_hc0[2];
  const double _t30 = _t26*_t29;
  const double _t31 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t32 = _t26*_t31;
  const double _t33 = _t17*_t19;
  const double _t34 = _hc1[1]*_t18;
  const double _t35 = _t31*_t34;
  const double _t36 = _t9/((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t37 = my_piecewise3(_t1, 0, -0.09375*_hc1[0]*_t10*_t32*_t6 + _t11*_t14*_t23 + _t16*_t25 - _t17*_t21*_t23*_t24 + 0.09375*_t19*_t30 - 0.1875*_t21*_t30*_t9 + _t25*_t33 + _t27*_t28 + _t27*_t35 + 0.1875*_t32*_t36);
  const double d3F_dna3 = _t13*_t37 + 0.6e1*_t22;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double _t38 = 2.25*_t26;
  const double _t39 = xc_powi(na, -7);
  const double _t40 = 0.375*_t39;
  const double _t41 = xc_powi(na, -8);
  const double _t42 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t43 = _t41*_t42;
  const double _t44 = ((_hc0[2]) * (_hc0[2]));
  const double _t45 = _hc0[2]*_t17*_t41;
  const double d4F_dna4 = _t13*my_piecewise3(_t1, 0, 2.25*_hc0[1]*_hc0[2]*_t2*_t21*_t39*_t4*_t5 + 0.125*_hc0[1]*_hc0[3]*_t2*_t21*_t4*_t41*_t5 - _hc0[1]*_hc0[3]*_t20*_t41 + 0.28125*_hc0[2]*_hc1[0]*_t10*_t17*_t4*_t41*_t5 - 0.015625*_hc0[4]*_t15*_t41 + 1.125*_hc1[0]*_t10*_t31*_t39*_t4*_t5 - 0.1875*_hc1[0]*_t21*_t43*_t6 + 0.0625*_hc1[1]*_t10*_t4*_t41*_t42*_t5 - 0.015625*_hc1[2]*_t18*_t43 - 3.0*_t11*_t24*_t9 - _t16*_t38 + 4.5*_t17*_t2*_t21*_t26*_t4*_t5 - 1.125*_t19*_t29*_t39 - 0.046875*_t19*_t41*_t44 + 0.09375*_t2*_t21*_t4*_t41*_t44*_t5 - _t28*_t40 - 2.25*_t31*_t36*_t39 - _t33*_t38 - 0.09375*_t34*_t45 - _t35*_t40 - 0.5625*_t36*_t45 + 0.375*_t2*_t4*_t41*_t42*_t5/xc_powi((_hc0[0]), 5)) + 0.8e1*_t37;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = na - nb;
  const double _t4 = _t2*_t3;
  const double _t9 = 0.2e1*na;
  const double _t10 = na <= p->dens_threshold || _t2*_t9 <= p->zeta_threshold;
  const double _t14 = 0.25/(M_PI*params->beta);
  const double _t15 = 0.2e1*nb;
  const double _t16 = nb <= p->dens_threshold || _t15*_t2 <= p->zeta_threshold;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(x1d_R_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t2, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, _t4, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, -_t4, _hc2);
  const double _t5 = _hc1[0] + 0.1e1;
  const double _t6 = _hc0[0]*_t5;
  const double _t7 = _hc2[0] + 0.1e1;
  const double _t8 = _hc0[0]*_t7;
  const double _t11 = xc_integrate(func1, NULL, 1e-20, _t6);
  const double _t12 = (0.1e1 / (_hc0[0]));
  const double _t13 = xc_integrate(func2, NULL, 1e-20, _t6);
  const double _t17 = xc_integrate(func1, NULL, 1e-20, _t8);
  const double _t18 = xc_integrate(func2, NULL, 1e-20, _t8);
  const double _t19 = my_piecewise3(_t10, 0, _t14*(-_t11*_t5 + _t12*_t13)) + my_piecewise3(_t16, 0, _t14*(_t12*_t18 - _t17*_t7));
  const double zk = _t19;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t21 = (0.1e1 / (_t1 * _t1));
  const double _t23 = -_t2;
  const double _t24 = _t21*_t3;
  const double _t25 = _t23 + _t24;
  const double _t26 = -_t25;
  const double _t33 = _t2 + _t24;
  const double _t35 = -_t33;
  const double _t20 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t22 = -0.1e1 / 0.2e1*_hc0[1]*_t13*_t20*_t21;
  const double _t27 = _hc1[1]*_t11;
  const double _t28 = my_piecewise3(_t10, 0, _t14*(-_t22 - _t26*_t27));
  const double _t29 = -0.1e1 / 0.2e1*_hc0[1]*_t18*_t20*_t21;
  const double _t30 = _hc2[1]*_t17;
  const double _t31 = my_piecewise3(_t16, 0, _t14*(-_t25*_t30 - _t29));
  const double _t32 = _t28 + _t31;
  const double _t34 = my_piecewise3(_t16, 0, _t14*(-_t29 - _t30*_t33));
  const double _t36 = my_piecewise3(_t10, 0, _t14*(-_t22 - _t27*_t35));
  const double _t37 = _t34 + _t36;
  const double dF_dna = _t1*_t32 + _t19;
  const double dF_dnb = _t1*_t37 + _t19;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t38 = 0.2e1*_t21;
  const double _t39 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t40 = 0.2e1*_t39;
  const double _t41 = _t3*_t40;
  const double _t42 = -_t38 + _t41;
  const double _t43 = (_t26 * _t26);
  const double _t57 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t63 = -_t42;
  const double _t64 = (_t25 * _t25);
  const double _t87 = _t38 + _t41;
  const double _t88 = -_t87;
  const double _t89 = (_t33 * _t33);
  const double _t92 = (_t35 * _t35);
  const double _t44 = _hc1[2]*_t11;
  const double _t46 = _hc0[1]*_t21;
  const double _t47 = (0.1e1 / 0.2e1)*_t5;
  const double _t48 = -_t46*_t47;
  const double _t49 = _hc0[0]*_hc1[1];
  const double _t50 = _t26*_t49 + _t48;
  const double _t51 = _t26*_t50;
  const double _t53 = _hc0[1]*_t39;
  const double _t54 = _t20*_t53;
  const double _t55 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t56 = ((_hc0[1]) * (_hc0[1]));
  const double _t58 = _t13*_t20;
  const double _t59 = (0.1e1 / 0.4e1)*_hc0[2];
  const double _t60 = _t57*_t59;
  const double _t61 = _t13*_t54 - 0.1e1 / 0.2e1*_t13*_t55*_t56*_t57 + _t58*_t60;
  const double _t65 = _hc2[2]*_t17;
  const double _t67 = (0.1e1 / 0.2e1)*_t7;
  const double _t68 = -_t46*_t67;
  const double _t69 = _hc0[0]*_hc2[1];
  const double _t70 = _t25*_t69 + _t68;
  const double _t71 = _t25*_t70;
  const double _t73 = _t18*_t20;
  const double _t74 = _t18*_t54 - 0.1e1 / 0.2e1*_t18*_t55*_t56*_t57 + _t60*_t73;
  const double _t77 = _t33*_t69 + _t68;
  const double _t79 = _t25*_t65;
  const double _t82 = _t35*_t49 + _t48;
  const double _t84 = _t26*_t44;
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(x1d_inter_k, _KMAX)(p, _t6, _hc3);
  double _hc4[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(x1d_inter_k, _KMAX)(p, _t8, _hc4);
  const double _t45 = _hc1[1]*_hc3[0];
  const double _t52 = _t45*_t51;
  const double _t62 = my_piecewise3(_t10, 0, _t14*((0.1e1 / 0.2e1)*_hc0[1]*_hc3[0]*_t12*_t21*_t5*_t50 - _t27*_t42 - _t43*_t44 - _t52 - _t61));
  const double _t66 = _hc2[1]*_hc4[0];
  const double _t72 = _t66*_t71;
  const double _t75 = my_piecewise3(_t16, 0, _t14*((0.1e1 / 0.2e1)*_hc0[1]*_hc4[0]*_t12*_t21*_t7*_t70 - _t30*_t63 - _t64*_t65 - _t72 - _t74));
  const double _t76 = _t62 + _t75;
  const double _t78 = _t66*_t77;
  const double _t80 = -0.1e1 / 0.2e1*_hc0[1]*_hc4[0]*_t12*_t21*_t7*_t77 + _t74;
  const double _t81 = my_piecewise3(_t16, 0, _t14*(0.2e1*_hc2[1]*_t17*_t3*_t39 - _t25*_t78 - _t33*_t79 - _t80));
  const double _t83 = _t45*_t82;
  const double _t85 = -0.1e1 / 0.2e1*_hc0[1]*_hc3[0]*_t12*_t21*_t5*_t82 + _t61;
  const double _t86 = my_piecewise3(_t10, 0, _t14*(-_t26*_t83 - _t27*_t41 - _t35*_t84 - _t85));
  const double _t90 = _t33*_t78;
  const double _t91 = my_piecewise3(_t16, 0, _t14*(-_t30*_t88 - _t65*_t89 - _t80 - _t90));
  const double _t93 = _t35*_t83;
  const double _t94 = my_piecewise3(_t10, 0, _t14*(-_t27*_t87 - _t44*_t92 - _t85 - _t93));
  const double _t95 = _t91 + _t94;
  const double d2F_dna2 = _t1*_t76 + 0.2e1*_t28 + 0.2e1*_t31;
  const double d2F_dna_dnb = _t1*(_t81 + _t86) + _t32 + _t37;
  const double d2F_dnb2 = _t1*_t95 + 0.2e1*_t34 + 0.2e1*_t36;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t96 = 0.6e1*_t39;
  const double _t97 = _t3*_t57;
  const double _t98 = 0.6e1*_t97;
  const double _t99 = -_t96 + _t98;
  const double _t100 = -_t99;
  const double _t101 = (_t26 * _t26 * _t26);
  const double _t118 = 0.4e1*_t21;
  const double _t119 = 0.4e1*_t39;
  const double _t120 = _t119*_t3;
  const double _t121 = -_t118 + _t120;
  const double _t124 = -_t21*_t3;
  const double _t125 = _t124 + _t2;
  const double _t137 = xc_powi(_t1, -5);
  const double _t138 = 0.3e1*_t137;
  const double _t141 = xc_powi(_t1, -6);
  const double _t146 = (_t25 * _t25 * _t25);
  const double _t161 = -_t121;
  const double _t173 = -0.2e1*_t39 + _t98;
  const double _t187 = -_t173;
  const double _t194 = _t124 + _t23;
  const double _t214 = _t25*_t89;
  const double _t225 = _t125*_t92;
  const double _t230 = _t96 + _t98;
  const double _t231 = (_t33 * _t33 * _t33);
  const double _t234 = _t118 + _t120;
  const double _t235 = -_t234;
  const double _t239 = -_t230;
  const double _t240 = (_t35 * _t35 * _t35);
  const double _t102 = _hc1[3]*_t11;
  const double _t103 = _t42*_t49;
  const double _t104 = _hc1[1]*_t26;
  const double _t105 = _t104*_t46;
  const double _t106 = -_t105;
  const double _t107 = _hc0[0]*_hc1[2];
  const double _t108 = _t107*_t43;
  const double _t109 = _t5*_t53;
  const double _t110 = _t5*_t57;
  const double _t111 = _t110*_t59;
  const double _t112 = _t109 + _t111;
  const double _t113 = _t108 + _t112;
  const double _t114 = _t103 + _t106 + _t113;
  const double _t116 = (_t50 * _t50);
  const double _t123 = 0.2e1*_t50;
  const double _t126 = _t125*_t49 + _t48;
  const double _t127 = _hc1[2]*_t43;
  const double _t130 = _hc0[2]*_t57;
  const double _t131 = _t130*_t47;
  const double _t134 = _hc0[1]*_t40;
  const double _t135 = _t134*_t5;
  const double _t136 = _t55*_t56;
  const double _t139 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t140 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t142 = _hc0[1]*_t55;
  const double _t143 = (0.3e1 / 0.4e1)*_hc0[2]*_t141;
  const double _t144 = -0.3e1*_hc0[1]*_t13*_t20*_t57 - 0.3e1 / 0.2e1*_hc0[2]*_t13*_t137*_t20 - 0.1e1 / 0.8e1*_hc0[3]*_t13*_t141*_t20 + _t13*_t136*_t138 - 0.3e1 / 0.4e1*_t13*_t139*_t140*_t141 + _t13*_t142*_t143;
  const double _t147 = _hc2[3]*_t17;
  const double _t148 = _t63*_t69;
  const double _t149 = _hc0[0]*_hc2[2];
  const double _t150 = _t149*_t64;
  const double _t151 = _hc2[1]*_t25;
  const double _t152 = _t151*_t46;
  const double _t153 = _t53*_t7;
  const double _t154 = _t57*_t7;
  const double _t155 = _t154*_t59;
  const double _t156 = _t153 + _t155;
  const double _t157 = _t148 + _t150 - _t152 + _t156;
  const double _t159 = (_t70 * _t70);
  const double _t162 = 0.2e1*_t70;
  const double _t164 = _hc2[2]*_t64;
  const double _t166 = _t130*_t67;
  const double _t169 = _t134*_t7;
  const double _t170 = -0.3e1*_hc0[1]*_t18*_t20*_t57 - 0.3e1 / 0.2e1*_hc0[2]*_t137*_t18*_t20 - 0.1e1 / 0.8e1*_hc0[3]*_t141*_t18*_t20 + _t136*_t138*_t18 - 0.3e1 / 0.4e1*_t139*_t140*_t141*_t18 + _t142*_t143*_t18;
  const double _t174 = _hc2[1]*_t33;
  const double _t175 = _t174*_t46;
  const double _t176 = _hc0[0]*_hc2[2]*_t25*_t33 + _hc0[1]*_t39*_t7 + (0.1e1 / 0.4e1)*_hc0[2]*_t57*_t7 - 0.1e1 / 0.2e1*_t152 - 0.1e1 / 0.2e1*_t175 - _t41*_t69;
  const double _t178 = _t33*_t65;
  const double _t179 = _t147*_t64;
  const double _t180 = _hc2[1]*_t71;
  const double _t182 = _hc2[2]*_t33;
  const double _t184 = _t12*_t153;
  const double _t188 = _t107*_t26;
  const double _t189 = _t188*_t35;
  const double _t190 = _hc1[1]*_t35;
  const double _t191 = _t190*_t46;
  const double _t192 = _t112 + _t41*_t49;
  const double _t193 = -0.1e1 / 0.2e1*_t105 + _t189 - 0.1e1 / 0.2e1*_t191 + _t192;
  const double _t195 = _t194*_t49 + _t48;
  const double _t197 = _t35*_t44;
  const double _t198 = _t102*_t43;
  const double _t199 = _hc1[1]*_t51;
  const double _t201 = _hc1[2]*_t35;
  const double _t204 = _t109*_t12;
  const double _t210 = _t69*_t88;
  const double _t211 = _t149*_t89;
  const double _t212 = _t156 - _t175 + _t210 + _t211;
  const double _t213 = (_t77 * _t77);
  const double _t215 = _t182*_t25;
  const double _t219 = _t49*_t87;
  const double _t220 = -_t191;
  const double _t221 = _t107*_t92;
  const double _t222 = _t112 + _t221;
  const double _t223 = _t219 + _t220 + _t222;
  const double _t224 = (_t82 * _t82);
  const double _t227 = 0.2e1*_t82;
  const double _t244 = _hc1[2]*_t92;
  const double _t115 = _t26*_t45;
  const double _t117 = _hc3[1]*_t104;
  const double _t122 = _t42*_t45;
  const double _t128 = _hc3[0]*_t127;
  const double _t129 = 0.2e1*_t128;
  const double _t132 = _hc3[0]*_t50;
  const double _t133 = _t12*_t132;
  const double _t145 = my_piecewise3(_t10, 0, _t14*((0.1e1 / 0.2e1)*_hc0[1]*_hc1[1]*_hc3[0]*_t12*_t21*_t26*_t50 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[0]*_t114*_t12*_t21*_t5 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[1]*_t116*_t12*_t21*_t5 + (0.3e1 / 0.4e1)*_hc3[0]*_t20*_t5*_t50*_t56*_t57 - _t100*_t27 - _t101*_t102 - _t114*_t115 - _t116*_t117 - _t121*_t84 - _t122*_t123 - _t126*_t129 - _t131*_t133 - _t133*_t135 - _t144 - _t42*_t84));
  const double _t158 = _t25*_t66;
  const double _t160 = _hc4[1]*_t151;
  const double _t163 = _t63*_t66;
  const double _t165 = _hc4[0]*_t164;
  const double _t167 = _hc4[0]*_t70;
  const double _t168 = _t12*_t167;
  const double _t171 = my_piecewise3(_t16, 0, _t14*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[1]*_hc4[0]*_t12*_t21*_t25*_t70 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[0]*_t12*_t157*_t21*_t7 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[1]*_t12*_t159*_t21*_t7 + (0.3e1 / 0.4e1)*_hc4[0]*_t20*_t56*_t57*_t7*_t70 - _t146*_t147 - _t157*_t158 - _t159*_t160 - _t161*_t79 - _t162*_t163 - _t162*_t165 - _t166*_t168 - _t168*_t169 - _t170 - _t30*_t99 - _t63*_t79));
  const double _t172 = _t145 + _t171;
  const double _t177 = _hc4[0]*_t77;
  const double _t181 = _hc4[1]*_t77;
  const double _t183 = _hc4[0]*_t71;
  const double _t185 = _t12*_t177;
  const double _t186 = my_piecewise3(_t16, 0, _t14*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[1]*_hc4[0]*_t12*_t21*_t33*_t70 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[0]*_t12*_t176*_t21*_t7 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[1]*_t12*_t21*_t7*_t70*_t77 + 0.2e1*_hc2[1]*_hc4[0]*_t3*_t39*_t70 + 0.4e1*_hc2[2]*_t17*_t25*_t3*_t39 + (0.1e1 / 0.4e1)*_hc4[0]*_t20*_t56*_t57*_t7*_t70 + (0.1e1 / 0.2e1)*_hc4[0]*_t20*_t56*_t57*_t7*_t77 - _t155*_t168 - _t155*_t185 - _t158*_t176 - _t164*_t177 - _t167*_t184 - _t170 - _t173*_t30 - _t177*_t184 - _t178*_t63 - _t179*_t33 - _t180*_t181 - _t182*_t183 - _t63*_t78));
  const double _t196 = _hc3[0]*_t195;
  const double _t200 = _hc3[1]*_t82;
  const double _t202 = _hc3[0]*_t201;
  const double _t203 = _t45*_t50;
  const double _t205 = _hc3[0]*_t204;
  const double _t206 = _hc3[0]*_t82;
  const double _t207 = _t12*_t206;
  const double _t208 = my_piecewise3(_t10, 0, _t14*((0.1e1 / 0.2e1)*_hc0[1]*_hc1[1]*_hc3[0]*_t12*_t21*_t35*_t50 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[0]*_t12*_t193*_t21*_t5 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[1]*_t12*_t21*_t5*_t50*_t82 + (0.1e1 / 0.4e1)*_hc3[0]*_t20*_t5*_t50*_t56*_t57 + (0.1e1 / 0.2e1)*_hc3[0]*_t20*_t5*_t56*_t57*_t82 - _t111*_t133 - _t111*_t207 - _t115*_t193 - _t120*_t84 - _t127*_t196 - _t132*_t204 - _t144 - _t187*_t27 - _t194*_t198 - _t197*_t42 - _t199*_t200 - _t202*_t51 - _t203*_t41 - _t205*_t82 - _t42*_t83));
  const double _t209 = 0.2e1*_t81 + 0.2e1*_t86;
  const double _t216 = 0.2e1*_t177;
  const double _t217 = -0.1e1 / 0.2e1*_hc0[1]*_hc2[1]*_hc4[0]*_t12*_t21*_t33*_t77 - 0.1e1 / 0.2e1*_hc0[1]*_hc4[0]*_t12*_t21*_t212*_t7 - 0.1e1 / 0.2e1*_hc0[1]*_hc4[1]*_t12*_t21*_t213*_t7 - 0.3e1 / 0.4e1*_hc4[0]*_t20*_t56*_t57*_t7*_t77 + _t166*_t185 + _t169*_t185 + _t170;
  const double _t218 = my_piecewise3(_t16, 0, _t14*(0.4e1*_hc2[1]*_hc4[0]*_t3*_t39*_t77 + 0.4e1*_hc2[2]*_t17*_t3*_t33*_t39 - _t147*_t214 - _t158*_t212 - _t160*_t213 - _t215*_t216 - _t217 - _t30*_t40 - _t30*_t98 - _t79*_t88));
  const double _t226 = _t202*_t26;
  const double _t228 = -0.1e1 / 0.2e1*_hc0[1]*_hc1[1]*_hc3[0]*_t12*_t21*_t35*_t82 - 0.1e1 / 0.2e1*_hc0[1]*_hc3[0]*_t12*_t21*_t223*_t5 - 0.1e1 / 0.2e1*_hc0[1]*_hc3[1]*_t12*_t21*_t224*_t5 - 0.3e1 / 0.4e1*_hc3[0]*_t20*_t5*_t56*_t57*_t82 + _t131*_t207 + _t135*_t207 + _t144;
  const double _t229 = my_piecewise3(_t10, 0, _t14*(0.6e1*_hc1[1]*_t11*_t3*_t57 + 0.2e1*_hc1[1]*_t11*_t39 - _t102*_t225 - _t115*_t223 - _t117*_t224 - _t120*_t197 - _t120*_t83 - _t226*_t227 - _t228 - _t84*_t87));
  const double _t232 = _t212*_t66;
  const double _t233 = _hc4[1]*_t213;
  const double _t236 = 0.2e1*_t78;
  const double _t237 = _hc2[2]*_t177;
  const double _t238 = my_piecewise3(_t16, 0, _t14*(-_t147*_t231 - _t174*_t233 - _t178*_t235 - _t178*_t88 - _t217 - _t230*_t30 - _t232*_t33 - _t236*_t88 - 0.2e1*_t237*_t89));
  const double _t241 = _t223*_t45;
  const double _t242 = _hc3[1]*_t224;
  const double _t243 = 0.2e1*_t83;
  const double _t245 = 0.2e1*_t196;
  const double _t246 = my_piecewise3(_t10, 0, _t14*(-_t102*_t240 - _t190*_t242 - _t197*_t234 - _t197*_t87 - _t228 - _t239*_t27 - _t241*_t35 - _t243*_t87 - _t244*_t245));
  const double _t247 = _t238 + _t246;
  const double d3F_dna3 = _t1*_t172 + 0.3e1*_t62 + 0.3e1*_t75;
  const double d3F_dna2_dnb = _t1*(_t186 + _t208) + _t209 + _t76;
  const double d3F_dna_dnb2 = _t1*(_t218 + _t229) + _t209 + _t95;
  const double d3F_dnb3 = _t1*_t247 + 0.3e1*_t91 + 0.3e1*_t94;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t248 = 0.24e2*_t57;
  const double _t249 = _t137*_t3;
  const double _t250 = 0.24e2*_t249;
  const double _t251 = -_t248 + _t250;
  const double _t270 = 0.12e2*_t39;
  const double _t271 = 0.12e2*_t57;
  const double _t272 = _t271*_t3;
  const double _t273 = -_t270 + _t272;
  const double _t275 = 0.6e1*_t21;
  const double _t276 = 0.6e1*na - 0.6e1*nb;
  const double _t277 = 0.4e1*na - 0.4e1*nb;
  const double _t278 = -_t15 + _t9;
  const double _t279 = _t278*_t39 - _t38;
  const double _t309 = xc_powi(_t1, -7);
  const double _t310 = 0.9e1*_t309;
  const double _t314 = xc_powi(_t1, -8);
  const double _t330 = _t3*_t96;
  const double _t350 = _t250 - _t271;
  const double _t352 = _t33*_t64;
  const double _t360 = _t272 - 0.4e1*_t39;
  const double _t384 = _t194*_t43;
  const double _t394 = _t121*_t26;
  const double _t396 = _t26*_t42;
  const double _t401 = 0.8e1*_t3*_t39;
  const double _t415 = 0.8e1*_t141*(_t3 * _t3);
  const double _t426 = _t278*_t39 + _t38;
  const double _t443 = 0.3e1*_t88;
  const double _t446 = 0.18e2*_t97;
  const double _t453 = 0.3e1*_t87;
  const double _t460 = _t248 + _t250;
  const double _t461 = _t270 + _t272;
  const double _t252 = _hc1[4]*_t11;
  const double _t253 = _hc0[0]*_hc1[3];
  const double _t254 = _hc1[1]*_t46;
  const double _t255 = _t254*_t42;
  const double _t256 = (0.3e1 / 0.2e1)*_t46;
  const double _t257 = (0.3e1 / 0.4e1)*_t130;
  const double _t258 = 0.3e1*_hc0[1];
  const double _t259 = _t110*_t258;
  const double _t260 = _t137*_t5;
  const double _t261 = (0.3e1 / 0.2e1)*_hc0[2];
  const double _t262 = _t260*_t261;
  const double _t263 = _t141*_t5;
  const double _t264 = (0.1e1 / 0.8e1)*_hc0[3];
  const double _t265 = _t263*_t264;
  const double _t266 = -_t259 - _t262 - _t265;
  const double _t267 = _t100*_t49 + _t101*_t253 + _t104*_t257 + 0.3e1*_t104*_t53 + _t121*_t188 - _t127*_t256 + _t188*_t42 - 0.3e1 / 0.2e1*_t255 + _t266;
  const double _t268 = (_t50 * _t50 * _t50);
  const double _t274 = _t42*_t44;
  const double _t280 = 0.3e1*_t114;
  const double _t281 = _hc1[1]*_t42;
  const double _t284 = _t125*_t254;
  const double _t285 = _hc1[3]*_t101;
  const double _t288 = _hc0[1]*_t38;
  const double _t289 = _t131 + _t135;
  const double _t290 = 0.2e1*_t103 - _t104*_t288 + 0.2e1*_t108 + _t289;
  const double _t294 = _t20*_t56;
  const double _t295 = 0.7e1*_t294;
  const double _t298 = (0.3e1 / 0.4e1)*_hc0[2];
  const double _t299 = _t110*_t298;
  const double _t301 = _t12*_t53;
  const double _t303 = _t12*_t257;
  const double _t304 = _hc0[1]*_t20;
  const double _t305 = _hc0[2]*_t304;
  const double _t307 = 0.9e1*_hc0[2]*_t141;
  const double _t308 = _t139*_t140;
  const double _t311 = 0.12e2*_hc0[1]*_t137;
  const double _t312 = xc_powi((_hc0[0]), -5);
  const double _t313 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t315 = ((_hc0[2]) * (_hc0[2]));
  const double _t316 = (0.1e1 / 0.16e2)*_hc0[4]*_t314;
  const double _t317 = (0.3e1 / 0.2e1)*_hc0[3]*_t309;
  const double _t318 = (0.9e1 / 0.4e1)*_hc0[2]*_t139*_t56;
  const double _t319 = -0.9e1*_hc0[1]*_hc0[2]*_t13*_t309*_t55 - 0.1e1 / 0.2e1*_hc0[1]*_hc0[3]*_t13*_t314*_t55 - 0.18e2*_t13*_t141*_t55*_t56 + _t13*_t308*_t310 - 0.3e1 / 0.2e1*_t13*_t312*_t313*_t314 - 0.3e1 / 0.8e1*_t13*_t314*_t315*_t55 + _t13*_t314*_t318 + _t307*_t58 + _t311*_t58 + _t316*_t58 + _t317*_t58;
  const double _t320 = _hc2[4]*_t17;
  const double _t321 = _hc0[0]*_hc2[3];
  const double _t322 = _t149*_t25;
  const double _t323 = _t151*_t53;
  const double _t324 = _hc2[1]*_t63;
  const double _t325 = -_t137*_t261*_t7 - _t141*_t264*_t7 - _t154*_t258;
  const double _t326 = _t146*_t321 + _t151*_t257 + _t161*_t322 - _t164*_t256 - _t256*_t324 + _t322*_t63 + 0.3e1*_t323 + _t325 + _t69*_t99;
  const double _t327 = (_t70 * _t70 * _t70);
  const double _t329 = _t63*_t65;
  const double _t331 = 0.3e1*_t70;
  const double _t332 = 0.3e1*_t157;
  const double _t335 = _hc2[3]*_t146;
  const double _t337 = _t166 + _t169;
  const double _t338 = 0.2e1*_t148 + 0.2e1*_t150 - _t151*_t288 + _t337;
  const double _t345 = _t154*_t298;
  const double _t349 = -0.9e1*_hc0[1]*_hc0[2]*_t18*_t309*_t55 - 0.1e1 / 0.2e1*_hc0[1]*_hc0[3]*_t18*_t314*_t55 - 0.18e2*_t141*_t18*_t55*_t56 + _t18*_t308*_t310 - 0.3e1 / 0.2e1*_t18*_t312*_t313*_t314 - 0.3e1 / 0.8e1*_t18*_t314*_t315*_t55 + _t18*_t314*_t318 + _t307*_t73 + _t311*_t73 + _t316*_t73 + _t317*_t73;
  const double _t351 = _t149*_t33;
  const double _t353 = _t174*_t53;
  const double _t354 = (0.1e1 / 0.2e1)*_t130;
  const double _t355 = (0.1e1 / 0.2e1)*_t46;
  const double _t356 = _hc0[1]*_t249;
  const double _t357 = 0.2e1*_t356;
  const double _t358 = _hc2[1]*_t357 - _t215*_t46 + _t325;
  const double _t359 = -_t120*_t322 + _t134*_t151 + _t151*_t354 - _t164*_t355 + _t173*_t69 + _t174*_t60 + _t321*_t352 - _t324*_t355 + _t351*_t63 + _t353 + _t358;
  const double _t361 = 0.2e1*_t176;
  const double _t363 = 0.2e1*_hc0[0]*_hc2[2]*_t25*_t33 + 0.2e1*_hc0[1]*_t39*_t7 + (0.1e1 / 0.2e1)*_hc0[2]*_t57*_t7 - _t120*_t69 - _t152 - _t175;
  const double _t365 = _t147*_t25*_t33;
  const double _t368 = _t182*_t63;
  const double _t371 = 0.4e1*_t294;
  const double _t373 = _t12*_t60;
  const double _t375 = _t12*_t166;
  const double _t376 = _t12*_t169;
  const double _t377 = _t12*_t354;
  const double _t381 = _t12*_t134;
  const double _t383 = _t107*_t35;
  const double _t385 = _t190*_t53;
  const double _t386 = _hc1[1]*_t357;
  const double _t387 = _t201*_t26;
  const double _t388 = _t387*_t46;
  const double _t389 = _t104*_t134 + _t104*_t354 + _t120*_t188 - _t127*_t355 + _t187*_t49 + _t190*_t60 + _t253*_t384 - 0.1e1 / 0.2e1*_t255 + _t266 + _t383*_t42 + _t385 - _t386 - _t388;
  const double _t390 = 0.2e1*_t193;
  const double _t391 = _t194*_t254;
  const double _t392 = _t106 + _t120*_t49 + 0.2e1*_t189 + _t220 + _t289;
  const double _t397 = _t102*_t35;
  const double _t403 = _t12*_t131;
  const double _t404 = _t12*_t135;
  const double _t409 = -0.24e2*_hc2[1]*_t137*_t17*_t3;
  const double _t410 = _hc2[1]*_t88;
  const double _t411 = _hc2[2]*_t89;
  const double _t412 = -_t120*_t351 + _t134*_t174 + _t151*_t60 + _t174*_t354 + _t214*_t321 + _t322*_t88 + _t323 - _t355*_t410 - _t355*_t411 + _t358 + _t40*_t69 + _t69*_t98;
  const double _t413 = _t147*_t89;
  const double _t414 = 0.2e1*_t178;
  const double _t418 = _t12*_t155;
  const double _t419 = (0.3e1 / 0.2e1)*_t294;
  const double _t422 = (0.11e2 / 0.8e1)*_t305;
  const double _t423 = _t250*_t27;
  const double _t424 = _t254*_t87;
  const double _t425 = _hc0[0]*_hc1[2]*_t26*_t87 + 0.4e1*_hc0[0]*_hc1[2]*_t3*_t35*_t39 + _hc0[0]*_hc1[3]*_t125*_t92 + _hc0[1]*_hc1[1]*_t26*_t39 + 0.2e1*_hc0[1]*_hc1[1]*_t35*_t39 + (0.1e1 / 0.4e1)*_hc0[2]*_hc1[1]*_t26*_t57 + (0.1e1 / 0.2e1)*_hc0[2]*_hc1[1]*_t35*_t57 - _t244*_t355 - _t259 - _t262 - _t265 - _t386 - _t388 - _t40*_t49 - 0.1e1 / 0.2e1*_t424 - _t49*_t98;
  const double _t427 = _t222 - _t391 + _t426*_t49;
  const double _t428 = _t102*_t92;
  const double _t429 = 0.2e1*_t197;
  const double _t432 = _t120*_t50;
  const double _t434 = _t26*_t397;
  const double _t436 = _t111*_t12;
  const double _t439 = _t174*_t257 + _t230*_t69 + _t231*_t321 + _t235*_t351 - _t256*_t410 - _t256*_t411 + _t325 + _t351*_t88 + 0.3e1*_t353;
  const double _t440 = (_t77 * _t77 * _t77);
  const double _t441 = -_t174*_t288 + 0.2e1*_t210 + 0.2e1*_t211 + _t337;
  const double _t447 = _t12*_t345;
  const double _t448 = (0.7e1 / 0.4e1)*_t305;
  const double _t450 = _t190*_t257 + _t234*_t383 + _t239*_t49 + _t240*_t253 - _t244*_t256 + _t266 + _t383*_t87 + 0.3e1*_t385 - 0.3e1 / 0.2e1*_t424;
  const double _t451 = (_t82 * _t82 * _t82);
  const double _t452 = -_t190*_t288 + 0.2e1*_t219 + 0.2e1*_t221 + _t289;
  const double _t456 = _t44*_t87;
  const double _t458 = _t12*_t299;
  const double _t464 = 0.3e1*_t244;
  const double _t269 = _hc3[2]*_t104;
  const double _t282 = _hc3[1]*_t116;
  const double _t283 = 0.3e1*_t282;
  const double _t286 = _hc3[0]*_t126;
  const double _t287 = _hc3[1]*_t199;
  const double _t291 = _hc1[2]*_hc3[0];
  const double _t292 = _t291*_t51;
  const double _t293 = 0.3e1*_t292;
  const double _t296 = _t132*_t260;
  const double _t297 = _hc3[0]*_t114*_t12;
  const double _t300 = _t12*_t282;
  const double _t302 = _t301*_t52;
  const double _t306 = _t132*_t263*_t305;
  const double _t328 = _hc4[2]*_t151;
  const double _t333 = _hc4[1]*_t159;
  const double _t334 = 0.3e1*_t333;
  const double _t336 = _hc4[1]*_t180;
  const double _t339 = _hc2[2]*_t183;
  const double _t340 = 0.3e1*_t339;
  const double _t341 = _t167*_t7;
  const double _t342 = _t137*_t341;
  const double _t343 = _hc4[0]*_t157;
  const double _t344 = _t12*_t343;
  const double _t346 = _t12*_t333;
  const double _t347 = _t301*_t72;
  const double _t348 = _t141*_t305*_t341;
  const double _t362 = _t160*_t77;
  const double _t364 = _t237*_t25;
  const double _t366 = _t162*_t181;
  const double _t367 = _hc4[0]*_t162;
  const double _t369 = _t177*_t7;
  const double _t370 = _t294*_t369;
  const double _t372 = _t66*_t70;
  const double _t374 = _hc4[0]*_t176;
  const double _t378 = _t33*_t66;
  const double _t379 = _t378*_t70;
  const double _t380 = _t181*_t70;
  const double _t382 = _t349 + _t374*_t375 + _t374*_t376 + _t375*_t380 + _t376*_t380 + _t377*_t379 + _t379*_t381;
  const double _t393 = _t117*_t82;
  const double _t395 = _t291*_t82;
  const double _t398 = _t202*_t42;
  const double _t399 = _hc1[3]*_t286;
  const double _t400 = _t206*_t294;
  const double _t402 = _hc3[0]*_t193;
  const double _t405 = _t35*_t45;
  const double _t406 = _t405*_t50;
  const double _t407 = _t200*_t50;
  const double _t408 = _t319 + _t377*_t406 + _t381*_t406 + _t402*_t403 + _t402*_t404 + _t403*_t407 + _t404*_t407;
  const double _t416 = _hc2[3]*_t177;
  const double _t417 = _hc4[0]*_t212;
  const double _t420 = _t301*_t90;
  const double _t421 = _t141*_t369;
  const double _t430 = _t205*_t223;
  const double _t431 = _t204*_t242;
  const double _t433 = _t26*_t395;
  const double _t435 = _hc3[0]*_t223;
  const double _t437 = _t301*_t93;
  const double _t438 = _t206*_t263;
  const double _t442 = 0.3e1*_t417;
  const double _t444 = 0.3e1*_t233;
  const double _t445 = 0.3e1*_t416;
  const double _t449 = -_hc0[1]*_hc2[1]*_hc4[0]*_t12*_t21*_t212*_t33 - 0.1e1 / 0.2e1*_hc0[1]*_hc2[1]*_hc4[0]*_t12*_t21*_t77*_t88 - _hc0[1]*_hc2[1]*_hc4[1]*_t12*_t21*_t213*_t33 - 0.1e1 / 0.2e1*_hc0[1]*_hc2[2]*_hc4[0]*_t12*_t21*_t77*_t89 - 0.1e1 / 0.2e1*_hc0[1]*_hc4[0]*_t12*_t21*_t439*_t7 - 0.9e1*_hc0[1]*_hc4[0]*_t12*_t57*_t7*_t77 - 0.1e1 / 0.2e1*_hc0[1]*_hc4[1]*_t12*_t21*_t212*_t7*_t77 - 0.1e1 / 0.2e1*_hc0[1]*_hc4[1]*_t12*_t21*_t441*_t7*_t77 - 0.1e1 / 0.2e1*_hc0[1]*_hc4[2]*_t12*_t21*_t440*_t7 - 0.9e1 / 0.2e1*_hc0[2]*_hc4[0]*_t12*_t137*_t7*_t77 - 0.3e1 / 0.8e1*_hc0[3]*_hc4[0]*_t12*_t141*_t7*_t77 - _hc2[1]*_hc4[0]*_t20*_t33*_t56*_t57*_t77 - 0.3e1 / 0.2e1*_hc4[0]*_t140*_t141*_t55*_t7*_t77 - _hc4[0]*_t20*_t212*_t56*_t57*_t7 - _hc4[1]*_t20*_t213*_t56*_t57*_t7 + _t137*_t295*_t369 + _t184*_t442 + _t184*_t444 + _t233*_t447 + _t303*_t90 + _t349 + _t417*_t447 + 0.3e1*_t420 + _t421*_t448;
  const double _t454 = 0.3e1*_hc1[3]*_t196;
  const double _t455 = _hc1[1]*_t242;
  const double _t457 = _t202*_t82;
  const double _t459 = -_hc0[1]*_hc1[1]*_hc3[0]*_t12*_t21*_t223*_t35 - 0.1e1 / 0.2e1*_hc0[1]*_hc1[1]*_hc3[0]*_t12*_t21*_t82*_t87 - _hc0[1]*_hc1[1]*_hc3[1]*_t12*_t21*_t224*_t35 - 0.1e1 / 0.2e1*_hc0[1]*_hc1[2]*_hc3[0]*_t12*_t195*_t21*_t92 - 0.1e1 / 0.2e1*_hc0[1]*_hc3[0]*_t12*_t21*_t450*_t5 - 0.9e1*_hc0[1]*_hc3[0]*_t12*_t5*_t57*_t82 - 0.1e1 / 0.2e1*_hc0[1]*_hc3[1]*_t12*_t21*_t223*_t5*_t82 - 0.1e1 / 0.2e1*_hc0[1]*_hc3[1]*_t12*_t21*_t452*_t5*_t82 - 0.1e1 / 0.2e1*_hc0[1]*_hc3[2]*_t12*_t21*_t451*_t5 - 0.9e1 / 0.2e1*_hc0[2]*_hc3[0]*_t12*_t137*_t5*_t82 - 0.3e1 / 0.8e1*_hc0[3]*_hc3[0]*_t12*_t141*_t5*_t82 - _hc1[1]*_hc3[0]*_t20*_t35*_t56*_t57*_t82 - 0.3e1 / 0.2e1*_hc3[0]*_t140*_t141*_t5*_t55*_t82 - _hc3[0]*_t20*_t223*_t5*_t56*_t57 - _hc3[1]*_t20*_t224*_t5*_t56*_t57 + _t206*_t260*_t295 + _t242*_t458 + _t303*_t93 + _t319 + 0.3e1*_t430 + 0.3e1*_t431 + _t435*_t458 + 0.3e1*_t437 + _t438*_t448;
  const double _t462 = _t174*_t181;
  const double _t463 = _t177*_t182;
  const double _t465 = _t190*_t200;
  const double d4F_dna4 = _t1*(my_piecewise3(_t10, 0, _t14*(_hc0[1]*_hc1[1]*_hc3[0]*_t114*_t12*_t21*_t26 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[1]*_hc3[0]*_t12*_t21*_t42*_t50 + _hc0[1]*_hc1[1]*_hc3[1]*_t116*_t12*_t21*_t26 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[2]*_hc3[0]*_t12*_t126*_t21*_t43 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[0]*_t12*_t21*_t267*_t5 + 0.9e1*_hc0[1]*_hc3[0]*_t12*_t5*_t50*_t57 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[1]*_t114*_t12*_t21*_t5*_t50 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[1]*_t12*_t21*_t290*_t5*_t50 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[2]*_t12*_t21*_t268*_t5 + (0.9e1 / 0.2e1)*_hc0[2]*_hc3[0]*_t12*_t137*_t5*_t50 + (0.3e1 / 0.8e1)*_hc0[3]*_hc3[0]*_t12*_t141*_t5*_t50 + _hc1[1]*_hc3[0]*_t20*_t26*_t50*_t56*_t57 + _hc3[0]*_t114*_t20*_t5*_t56*_t57 + (0.3e1 / 0.2e1)*_hc3[0]*_t140*_t141*_t5*_t50*_t55 + _hc3[1]*_t116*_t20*_t5*_t56*_t57 - 0.3e1*_t100*_t203 - 0.2e1*_t100*_t84 - _t114*_t287 - _t115*_t267 - _t121*_t274 - _t121*_t293 - _t122*_t280 - _t127*_t283 - 0.3e1*_t128*(_t113 + _t279*_t49 - _t284) - _t198*_t279 - _t198*(-_t118 + _t277*_t39) - _t198*(-_t275 + _t276*_t39) - _t204*_t283 - _t205*_t280 - _t251*_t27 - _t252*(_t26 * _t26 * _t26 * _t26) - _t268*_t269 + _t273*_t84 - _t281*_t283 - 0.3e1*_t285*_t286 - _t287*_t290 - _t293*_t42 - _t295*_t296 - _t297*_t299 - _t299*_t300 - 0.3e1*_t302 - _t303*_t52 - 0.7e1 / 0.4e1*_t306 - _t319 - (_t42 * _t42)*_t44)) + my_piecewise3(_t16, 0, _t14*(_hc0[1]*_hc2[1]*_hc4[0]*_t12*_t157*_t21*_t25 + (0.1e1 / 0.2e1)*_hc0[1]*_hc2[1]*_hc4[0]*_t12*_t21*_t63*_t70 + _hc0[1]*_hc2[1]*_hc4[1]*_t12*_t159*_t21*_t25 + (0.1e1 / 0.2e1)*_hc0[1]*_hc2[2]*_hc4[0]*_t12*_t21*_t64*_t70 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[0]*_t12*_t21*_t326*_t7 + 0.9e1*_hc0[1]*_hc4[0]*_t12*_t57*_t7*_t70 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[1]*_t12*_t157*_t21*_t7*_t70 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[1]*_t12*_t21*_t338*_t7*_t70 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[2]*_t12*_t21*_t327*_t7 + (0.9e1 / 0.2e1)*_hc0[2]*_hc4[0]*_t12*_t137*_t7*_t70 + (0.3e1 / 0.8e1)*_hc0[3]*_hc4[0]*_t12*_t141*_t7*_t70 + _hc2[1]*_hc4[0]*_t20*_t25*_t56*_t57*_t70 + (0.3e1 / 0.2e1)*_hc4[0]*_t140*_t141*_t55*_t7*_t70 + _hc4[0]*_t157*_t20*_t56*_t57*_t7 - _hc4[0]*_t184*_t332 - _hc4[0]*_t331*_t335 + _hc4[1]*_t159*_t20*_t56*_t57*_t7 - _t157*_t336 - _t158*_t326 - _t161*_t179 - _t161*_t329 - _t161*_t340 - _t163*_t332 - _t164*_t334 - _t165*_t332 - _t179*_t63 - _t179*(_t275 - _t330) - _t184*_t334 - (_t25 * _t25 * _t25 * _t25)*_t320 + _t251*_t30 - _t273*_t79 - _t295*_t342 - _t303*_t72 - _t324*_t334 - _t327*_t328 - _t331*_t66*_t99 - _t336*_t338 - _t340*_t63 - _t344*_t345 - _t345*_t346 - 0.3e1*_t347 - 0.7e1 / 0.4e1*_t348 - _t349 - (_t63 * _t63)*_t65 - 0.2e1*_t79*_t99))) + 0.4e1*_t145 + 0.4e1*_t171;
  const double d4F_dna3_dnb = _t1*(my_piecewise3(_t10, 0, _t14*((0.1e1 / 0.2e1)*_hc0[1]*_hc1[1]*_hc3[0]*_t114*_t12*_t21*_t35 + _hc0[1]*_hc1[1]*_hc3[0]*_t12*_t137*_t3*_t50 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[1]*_hc3[0]*_t12*_t193*_t21*_t26 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[1]*_hc3[1]*_t116*_t12*_t21*_t35 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[1]*_hc3[1]*_t12*_t21*_t26*_t50*_t82 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[2]*_hc3[0]*_t12*_t21*_t26*_t35*_t50 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[0]*_t12*_t21*_t389*_t5 + 0.6e1*_hc0[1]*_hc3[0]*_t12*_t5*_t50*_t57 + 0.3e1*_hc0[1]*_hc3[0]*_t12*_t5*_t57*_t82 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[1]*_t114*_t12*_t21*_t5*_t82 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[1]*_t12*_t21*_t392*_t5*_t50 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[2]*_t116*_t12*_t21*_t5*_t82 + 0.3e1*_hc0[2]*_hc3[0]*_t12*_t137*_t5*_t50 + (0.3e1 / 0.2e1)*_hc0[2]*_hc3[0]*_t12*_t137*_t5*_t82 + (0.1e1 / 0.4e1)*_hc0[3]*_hc3[0]*_t12*_t141*_t5*_t50 + (0.1e1 / 0.8e1)*_hc0[3]*_hc3[0]*_t12*_t141*_t5*_t82 + (0.1e1 / 0.4e1)*_hc1[1]*_hc3[0]*_t20*_t26*_t50*_t56*_t57 + (0.3e1 / 0.4e1)*_hc1[1]*_hc3[0]*_t20*_t35*_t50*_t56*_t57 - _hc1[1]*_t282*_t41 + (0.1e1 / 0.4e1)*_hc3[0]*_t114*_t20*_t5*_t56*_t57 + (0.3e1 / 0.4e1)*_hc3[0]*_t140*_t141*_t5*_t50*_t55 + (0.3e1 / 0.4e1)*_hc3[0]*_t140*_t141*_t5*_t55*_t82 + (0.3e1 / 0.4e1)*_hc3[0]*_t193*_t20*_t5*_t56*_t57 + (0.1e1 / 0.4e1)*_hc3[1]*_t116*_t20*_t5*_t56*_t57 - 0.2e1*_hc3[1]*_t126*_t127*_t195 + (0.3e1 / 0.4e1)*_hc3[1]*_t20*_t5*_t50*_t56*_t57*_t82 - _t100*_t197 - _t100*_t83 - _t101*_t194*_t252 - _t111*_t297 - _t111*_t300 - _t114*_t205 - _t114*_t226 - _t114*_t393 - _t114*_t41*_t45 - _t115*_t389 - _t116*_t269*_t82 - _t121*_t41*_t44 - _t122*_t390 - _t123*_t187*_t45 - _t123*_t200*_t281 - _t123*_t398 - _t129*(_t107*_t125*_t194 + _t192 - 0.1e1 / 0.2e1*_t284 - 0.1e1 / 0.2e1*_t391) - _t187*_t84 - _t196*_t285 - _t198*_t330 - _t204*_t282 - 0.3e1 / 0.4e1*_t206*_t263*_t305 - 0.3e1*_t260*_t400 - _t27*_t350 - _t274*_t41 - _t282*_t387 - _t287*_t392 - _t292*_t401 - _t296*_t371 - _t302 - _t306 + _t360*_t84 - _t373*_t52 - 0.2e1*_t384*_t399 - _t394*_t395 - _t394*_t397 - _t395*_t396 - _t396*_t397 - _t408)) + my_piecewise3(_t16, 0, _t14*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[1]*_hc4[0]*_t12*_t157*_t21*_t33 + (0.1e1 / 0.2e1)*_hc0[1]*_hc2[1]*_hc4[0]*_t12*_t176*_t21*_t25 + (0.1e1 / 0.2e1)*_hc0[1]*_hc2[1]*_hc4[1]*_t12*_t159*_t21*_t33 + (0.1e1 / 0.2e1)*_hc0[1]*_hc2[1]*_hc4[1]*_t12*_t21*_t25*_t70*_t77 + (0.1e1 / 0.2e1)*_hc0[1]*_hc2[2]*_hc4[0]*_t12*_t21*_t25*_t33*_t70 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[0]*_t12*_t21*_t359*_t7 + 0.6e1*_hc0[1]*_hc4[0]*_t12*_t57*_t7*_t70 + 0.3e1*_hc0[1]*_hc4[0]*_t12*_t57*_t7*_t77 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[1]*_t12*_t157*_t21*_t7*_t77 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[1]*_t12*_t21*_t363*_t7*_t70 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[2]*_t12*_t159*_t21*_t7*_t77 + 0.3e1*_hc0[2]*_hc4[0]*_t12*_t137*_t7*_t70 + (0.3e1 / 0.2e1)*_hc0[2]*_hc4[0]*_t12*_t137*_t7*_t77 + (0.1e1 / 0.4e1)*_hc0[3]*_hc4[0]*_t12*_t141*_t7*_t70 + (0.1e1 / 0.8e1)*_hc0[3]*_hc4[0]*_t12*_t141*_t7*_t77 + 0.2e1*_hc2[1]*_hc4[0]*_t157*_t3*_t39 + (0.1e1 / 0.4e1)*_hc2[1]*_hc4[0]*_t20*_t25*_t56*_t57*_t70 + (0.3e1 / 0.4e1)*_hc2[1]*_hc4[0]*_t20*_t33*_t56*_t57*_t70 + 0.2e1*_hc2[1]*_hc4[1]*_t159*_t3*_t39 + 0.8e1*_hc2[2]*_hc4[0]*_t25*_t3*_t39*_t70 + 0.2e1*_hc2[2]*_t161*_t17*_t3*_t39 + 0.2e1*_hc2[2]*_t17*_t3*_t39*_t63 + 0.6e1*_hc2[3]*_t17*_t3*_t39*_t64 - _hc2[3]*_t352*_t367 + (0.3e1 / 0.4e1)*_hc4[0]*_t140*_t141*_t55*_t7*_t70 + (0.3e1 / 0.4e1)*_hc4[0]*_t140*_t141*_t55*_t7*_t77 + (0.1e1 / 0.4e1)*_hc4[0]*_t157*_t20*_t56*_t57*_t7 + (0.3e1 / 0.4e1)*_hc4[0]*_t176*_t20*_t56*_t57*_t7 + (0.1e1 / 0.4e1)*_hc4[1]*_t159*_t20*_t56*_t57*_t7 + (0.3e1 / 0.4e1)*_hc4[1]*_t20*_t56*_t57*_t7*_t70*_t77 - _t12*_t356*_t372 - _t138*_t370 - _t143*_t304*_t369 - _t146*_t320*_t33 - _t155*_t344 - _t155*_t346 - _t157*_t362 - _t158*_t359 - _t159*_t328*_t77 - _t161*_t364 - _t161*_t365 - _t162*_t173*_t66 - _t163*_t361 - _t164*_t366 - _t165*_t361 - _t173*_t79 - _t177*_t335 - _t178*_t99 - _t184*_t333 - _t184*_t343 - _t215*_t333 - _t215*_t343 + _t30*_t350 - _t324*_t366 - _t336*_t363 - _t342*_t371 - _t347 - _t348 - _t360*_t79 - _t364*_t63 - _t365*_t63 - _t367*_t368 - _t373*_t72 - _t382 - _t78*_t99))) + _t172 + 0.3e1*_t186 + 0.3e1*_t208;
  const double d4F_dna2_dnb2 = _t1*(my_piecewise3(_t10, 0, _t14*(_hc0[1]*_hc1[1]*_hc3[0]*_t12*_t193*_t21*_t35 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[1]*_hc3[0]*_t12*_t21*_t50*_t87 + _hc0[1]*_hc1[1]*_hc3[1]*_t12*_t21*_t35*_t50*_t82 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[2]*_hc3[0]*_t12*_t126*_t21*_t92 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[0]*_t12*_t21*_t425*_t5 + 0.3e1*_hc0[1]*_hc3[0]*_t12*_t5*_t50*_t57 + 0.6e1*_hc0[1]*_hc3[0]*_t12*_t5*_t57*_t82 + _hc0[1]*_hc3[1]*_t12*_t193*_t21*_t5*_t82 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[1]*_t12*_t21*_t223*_t5*_t50 + (0.1e1 / 0.2e1)*_hc0[1]*_hc3[2]*_t12*_t21*_t224*_t5*_t50 + (0.3e1 / 0.2e1)*_hc0[2]*_hc3[0]*_t12*_t137*_t5*_t50 + 0.3e1*_hc0[2]*_hc3[0]*_t12*_t137*_t5*_t82 + (0.1e1 / 0.8e1)*_hc0[3]*_hc3[0]*_t12*_t141*_t5*_t50 + (0.1e1 / 0.4e1)*_hc0[3]*_hc3[0]*_t12*_t141*_t5*_t82 + (0.1e1 / 0.2e1)*_hc1[1]*_hc3[0]*_t20*_t35*_t50*_t56*_t57 + (0.1e1 / 0.2e1)*_hc1[1]*_hc3[0]*_t20*_t35*_t56*_t57*_t82 + 0.6e1*_hc1[1]*_hc3[0]*_t3*_t50*_t57 + 0.2e1*_hc1[1]*_hc3[0]*_t39*_t50 - _hc1[1]*_t200*_t432 + 0.12e2*_hc1[2]*_t11*_t26*_t3*_t57 + 0.4e1*_hc1[2]*_t11*_t26*_t39 - _hc1[3]*_t245*_t384 + (0.1e1 / 0.4e1)*_hc3[0]*_t140*_t141*_t5*_t50*_t55 + (0.5e1 / 0.4e1)*_hc3[0]*_t140*_t141*_t5*_t55*_t82 + (0.1e1 / 0.2e1)*_hc3[0]*_t193*_t20*_t5*_t56*_t57 + (0.1e1 / 0.2e1)*_hc3[0]*_t20*_t223*_t5*_t56*_t57 + (0.1e1 / 0.2e1)*_hc3[1]*_t20*_t224*_t5*_t56*_t57 + (0.1e1 / 0.2e1)*_hc3[1]*_t20*_t5*_t50*_t56*_t57*_t82 - _hc3[2]*_t199*_t224 - _t115*_t425 - _t120*_t193*_t45 - _t127*_t242 - _t128*_t427 - _t187*_t243 - _t187*_t429 - _t198*_t426 - 0.2e1*_t200*_t201*_t51 - _t202*_t432 - _t223*_t287 - _t225*_t399 - _t226*_t390 - _t227*_t398 - _t241*_t42 - _t242*_t281 - _t242*_t436 - _t252*_t43*_t92 - 0.11e2 / 0.2e1*_t260*_t400 - _t274*_t87 - _t279*_t428 - _t292*_t87 - _t296*_t419 - 0.3e1 / 0.8e1*_t306 - _t373*_t93 - _t390*_t393 - _t401*_t433 - _t401*_t434 - _t408 - _t415*_t44 - _t422*_t438 - _t423 - _t430 - _t431 - _t435*_t436 - _t437)) + my_piecewise3(_t16, 0, _t14*(_hc0[1]*_hc2[1]*_hc4[0]*_t12*_t176*_t21*_t33 + (0.1e1 / 0.2e1)*_hc0[1]*_hc2[1]*_hc4[0]*_t12*_t21*_t70*_t88 + _hc0[1]*_hc2[1]*_hc4[1]*_t12*_t21*_t33*_t70*_t77 + (0.1e1 / 0.2e1)*_hc0[1]*_hc2[2]*_hc4[0]*_t12*_t21*_t70*_t89 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[0]*_t12*_t21*_t412*_t7 + 0.3e1*_hc0[1]*_hc4[0]*_t12*_t57*_t7*_t70 + 0.6e1*_hc0[1]*_hc4[0]*_t12*_t57*_t7*_t77 + _hc0[1]*_hc4[1]*_t12*_t176*_t21*_t7*_t77 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[1]*_t12*_t21*_t212*_t7*_t70 + (0.1e1 / 0.2e1)*_hc0[1]*_hc4[2]*_t12*_t21*_t213*_t7*_t70 + (0.3e1 / 0.2e1)*_hc0[2]*_hc4[0]*_t12*_t137*_t7*_t70 + 0.3e1*_hc0[2]*_hc4[0]*_t12*_t137*_t7*_t77 + (0.1e1 / 0.8e1)*_hc0[3]*_hc4[0]*_t12*_t141*_t7*_t70 + (0.1e1 / 0.4e1)*_hc0[3]*_hc4[0]*_t12*_t141*_t7*_t77 + 0.4e1*_hc2[1]*_hc4[0]*_t176*_t3*_t39 + (0.1e1 / 0.2e1)*_hc2[1]*_hc4[0]*_t20*_t33*_t56*_t57*_t70 + (0.1e1 / 0.2e1)*_hc2[1]*_hc4[0]*_t20*_t33*_t56*_t57*_t77 + 0.4e1*_hc2[1]*_hc4[1]*_t3*_t39*_t70*_t77 + 0.8e1*_hc2[2]*_hc4[0]*_t25*_t3*_t39*_t77 + 0.4e1*_hc2[2]*_hc4[0]*_t3*_t33*_t39*_t70 + 0.8e1*_hc2[3]*_t17*_t25*_t3*_t33*_t39 - _hc2[3]*_t183*_t89 + (0.1e1 / 0.4e1)*_hc4[0]*_t140*_t141*_t55*_t7*_t70 + (0.5e1 / 0.4e1)*_hc4[0]*_t140*_t141*_t55*_t7*_t77 + (0.1e1 / 0.2e1)*_hc4[0]*_t176*_t20*_t56*_t57*_t7 + (0.1e1 / 0.2e1)*_hc4[0]*_t20*_t212*_t56*_t57*_t7 - _hc4[0]*_t215*_t361 + (0.1e1 / 0.2e1)*_hc4[1]*_t20*_t213*_t56*_t57*_t7 + (0.1e1 / 0.2e1)*_hc4[1]*_t20*_t56*_t57*_t7*_t70*_t77 - _hc4[2]*_t180*_t213 - _t119*_t79 - 0.11e2 / 0.2e1*_t137*_t370 - _t158*_t412 - _t164*_t233 - _t165*_t212 - _t173*_t236 - _t173*_t414 - _t179*_t88 - 0.2e1*_t181*_t182*_t71 - _t184*_t233 - _t184*_t417 - _t212*_t336 - _t216*_t368 - _t232*_t63 - _t233*_t324 - _t233*_t418 - _t272*_t79 - _t320*_t64*_t89 - _t329*_t88 - _t339*_t88 - _t342*_t419 - 0.3e1 / 0.8e1*_t348 - 0.2e1*_t352*_t416 - _t361*_t362 - _t372*_t40 - _t372*_t98 - _t373*_t90 - _t382 - _t409 - _t413*_t63 - _t415*_t65 - _t417*_t418 - _t420 - _t421*_t422))) + 0.2e1*_t186 + 0.2e1*_t208 + 0.2e1*_t218 + 0.2e1*_t229;
  const double d4F_dna_dnb3 = _t1*(my_piecewise3(_t10, 0, _t14*(0.18e2*_hc1[1]*_hc3[0]*_t3*_t57*_t82 + 0.6e1*_hc1[1]*_hc3[0]*_t39*_t82 + 0.18e2*_hc1[2]*_t11*_t3*_t35*_t57 + 0.6e1*_hc1[2]*_t11*_t35*_t39 - _t115*_t450 - _t125*_t240*_t252 - 0.3e1*_t223*_t226 - _t223*_t393 - _t225*_t454 - _t234*_t434 - _t239*_t84 - _t241*_t330 - 0.3e1*_t242*_t387 - _t269*_t451 - _t27*_t271 - _t270*_t3*_t457 - _t330*_t428 - _t330*_t455 - _t330*_t456 - _t393*_t452 - _t423 - _t433*_t453 - _t434*_t87 - _t459)) + my_piecewise3(_t16, 0, _t14*(0.6e1*_hc2[1]*_hc4[0]*_t212*_t3*_t39 + 0.6e1*_hc2[1]*_hc4[1]*_t213*_t3*_t39 + 0.12e2*_hc2[1]*_t17*_t57 + 0.12e2*_hc2[2]*_hc4[0]*_t3*_t33*_t39*_t77 + 0.6e1*_hc2[2]*_t17*_t3*_t39*_t88 + 0.6e1*_hc2[3]*_t17*_t3*_t39*_t89 - _t158*_t439 - _t178*_t446 - _t178*_t96 - _t212*_t362 - _t214*_t445 - _t215*_t442 - _t215*_t444 - _t230*_t79 - _t231*_t25*_t320 - _t235*_t365 - _t328*_t440 - _t362*_t441 - _t364*_t443 - _t365*_t88 - _t409 - _t446*_t78 - _t449 - _t78*_t96))) + 0.3e1*_t218 + 0.3e1*_t229 + _t247;
  const double d4F_dnb4 = _t1*(my_piecewise3(_t10, 0, _t14*(-_hc3[0]*_t427*_t464 - _hc3[2]*_t190*_t451 + _t197*_t461 - _t223*_t465 - _t234*_t456 - 0.3e1*_t234*_t457 - _t239*_t429 - 0.3e1*_t239*_t83 - _t240*_t454 - _t241*_t453 - _t242*_t464 - _t252*(_t35 * _t35 * _t35 * _t35) - _t27*_t460 - _t405*_t450 - _t426*_t428 - _t428*(_t118 + _t277*_t39) - _t428*(_t275 + _t276*_t39) - _t44*(_t87 * _t87) - _t452*_t465 - _t453*_t455 - _t453*_t457 - _t459)) + my_piecewise3(_t16, 0, _t14*(-_hc4[2]*_t174*_t440 - _t178*_t461 - _t212*_t462 - _t230*_t414 - 0.3e1*_t230*_t78 - _t231*_t445 - _t232*_t443 - _t235*_t413 - 0.3e1*_t235*_t463 - _t235*_t65*_t88 + _t30*_t460 - _t320*(_t33 * _t33 * _t33 * _t33) - _t378*_t439 - _t410*_t444 - _t411*_t442 - _t411*_t444 - _t413*_t88 - _t413*(-_t275 - _t330) - _t441*_t462 - _t443*_t463 - _t449 - _t65*(_t88 * _t88)))) + 0.4e1*_t238 + 0.4e1*_t246;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif