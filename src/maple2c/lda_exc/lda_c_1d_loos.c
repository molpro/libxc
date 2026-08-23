/*
  Generated from python/lda_exc/lda_c_1d_loos.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_1d_loos
*/

#ifndef _LDA_C_1D_LOOS_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_1D_LOOS_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_1D_LOOS_HELPER_BODIES
#include "lda_c_1d_loos.c"
#undef _LDA_C_1D_LOOS_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_1D_LOOS_HELPER_BODIES
#include "lda_c_1d_loos.c"
#undef _LDA_C_1D_LOOS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_1D_LOOS_HELPER_BODIES
#include "lda_c_1d_loos.c"
#undef _LDA_C_1D_LOOS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_1D_LOOS_HELPER_BODIES
#include "lda_c_1d_loos.c"
#undef _LDA_C_1D_LOOS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_1D_LOOS_HELPER_BODIES
#include "lda_c_1d_loos.c"
#undef _LDA_C_1D_LOOS_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_1d_loos.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_1d_loos.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_1d_loos.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_1d_loos.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_1d_loos.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_1d_loos.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_1d_loos.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_1d_loos.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_1d_loos.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_1d_loos.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_1D_LOOS_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(t_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = 1.657016*rs + 0.1e1;
  const double _t2 = xc_powr(_t1, 1, 2);
  const double _t3 = _t2 + 0.1e1;
#if _KMAX >= 1
  const double _t4 = (0.1e1 / (_t3 * _t3));
#endif
#if _KMAX >= 2
  const double _t5 = xc_powr(_t1, -3, 2);
  const double _t6 = (0.1e1 / (_t3 * _t3 * _t3));
#endif
#if _KMAX >= 3
  const double _t7 = xc_powr(_t1, -5, 2);
  const double _t8 = (0.1e1 / (_t1 * _t1));
  const double _t9 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
#endif

  const double f = 0.2e1/_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -1.657016*_t4/_t2;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 1.372851012128*_t4*_t5 + 2.745702024256*_t6/_t1;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -3.4122541390684349*_t4*_t7 - 6.8245082781368698*_t5*_t9 - 6.8245082781368698*_t6*_t8;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 33.924958227015729*_t7*_t9 + 22.616638818010486*_t8/xc_powi(_t3, 5) + 28.270798522513108*_t6/(_t1 * _t1 * _t1) + 14.135399261256556*_t4/xc_powr(_t1, 7, 2);
  out[4] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = (0.1e1 / na);
  const double _t4 = 0.020398113234875219 - 0.1e1 / 0.72e2*(M_PI * M_PI);
  const double _t6 = log(xc_powr(0.2e1, 1, 2)*xc_powr(M_PI, 1, 2));
  const double _t7 = 0.31069049999999998 - 0.41425400000000001*_t6;
  const double _t9 = 1.3387289587889073 - 1.657016*_t6;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(t_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t1, _hc0);
  const double _t2 = ((_hc0[0]) * (_hc0[0]));
  const double _t3 = 0.1e1 - _hc0[0];
  const double _t5 = _t2*_t4;
  const double _t8 = (_t3 * _t3);
  const double _t10 = _t8*_t9;
  const double _t11 = 0.0084499999999999992*((_hc0[0]) * (_hc0[0]) * (_hc0[0])) + _hc0[0]*_t10 + (_t3 * _t3 * _t3)*_t7 + _t3*_t5;
  const double _t12 = _t11*_t2;
  const double zk = _t12;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t15 = (0.1e1 / (na * na));
  const double _t13 = _hc0[0]*_hc0[1];
  const double _t14 = _t1*_t13;
  const double _t16 = _hc0[1]*_t2;
  const double _t17 = _hc0[1]*_t15;
  const double _t18 = (0.1e1 / 0.2e1)*_t17;
  const double _t19 = _t13*_t15;
  const double _t20 = _t3*_t4;
  const double _t21 = _t3*_t9;
  const double _t22 = _t7*_t8;
  const double _t23 = -_t10*_t18 - 0.012674999999999999*_t15*_t16 + (0.3e1 / 0.2e1)*_t17*_t22 + _t18*_t5 - _t19*_t20 + _t19*_t21;
  const double _t24 = _t2*_t23;
  const double dF_dna = -_t11*_t14 + _t12 + _t24*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t26 = (0.1e1 / (na * na * na));
  const double _t31 = (0.1e1 / (na * na * na * na));
  const double _t38 = 0.2e1*_t26;
  const double _t42 = (0.1e1 / 0.2e1)*_t9;
  const double _t25 = (0.1e1 / 0.2e1)*_t11;
  const double _t27 = _hc0[0]*_hc0[2];
  const double _t28 = _t26*_t27;
  const double _t29 = ((_hc0[1]) * (_hc0[1]));
  const double _t30 = _t26*_t29;
  const double _t32 = _t29*_t31;
  const double _t33 = _hc0[0]*_t32;
  const double _t34 = _hc0[2]*_t2;
  const double _t35 = _hc0[1]*_t26;
  const double _t36 = _hc0[2]*_t31;
  const double _t37 = (0.1e1 / 0.4e1)*_t36;
  const double _t39 = _t13*_t20;
  const double _t40 = (0.1e1 / 0.2e1)*_t20;
  const double _t41 = _hc0[0]*_t36;
  const double _t43 = _t13*_t21;
  const double _t44 = (0.3e1 / 0.2e1)*_t32;
  const double _t45 = _t3*_t7;
  const double _t46 = _t10*_t35 + _t10*_t37 + 0.025349999999999998*_t16*_t26 - _t21*_t32 - 0.1e1 / 0.2e1*_t21*_t41 - 0.3e1*_t22*_t35 - 0.3e1 / 0.4e1*_t22*_t36 + 0.0063374999999999994*_t31*_t34 + _t32*_t40 - _t33*_t4 + _t33*_t42 + 0.012674999999999999*_t33 - _t35*_t5 - _t37*_t5 + _t38*_t39 - _t38*_t43 + _t40*_t41 + _t44*_t45;
  const double d2F_dna2 = -0.2e1*_t14*_t23 + _t2*_t46*na + 0.2e1*_t24 + _t25*_t28 + _t25*_t30;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t47 = xc_powi(na, -5);
  const double _t54 = xc_powi(na, -6);
  const double _t48 = _hc0[0]*_hc0[3];
  const double _t49 = _t11*_t48;
  const double _t50 = _hc0[2]*_t47;
  const double _t51 = (0.3e1 / 0.4e1)*_hc0[1];
  const double _t52 = 0.3e1*_t46;
  const double _t53 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t55 = _t53*_t54;
  const double _t56 = 0.019012499999999998*_hc0[2];
  const double _t57 = _t13*_t54;
  const double _t58 = _hc0[0]*_t29;
  const double _t59 = _t47*_t58;
  const double _t60 = _hc0[3]*_t2;
  const double _t61 = 0.3e1*_t20;
  const double _t62 = _t27*_t47;
  const double _t63 = _hc0[2]*_t54;
  const double _t64 = _t29*_t47;
  const double _t65 = _hc0[1]*_t63;
  const double _t66 = (0.3e1 / 0.2e1)*_t10;
  const double _t67 = (0.3e1 / 0.2e1)*_hc0[0]*_hc0[1]*_hc0[2]*_t4*_t54 + 0.6e1*_hc0[0]*_hc0[1]*_t3*_t31*_t9 + 0.3e1*_hc0[0]*_hc0[2]*_t3*_t47*_t9 + (0.1e1 / 0.4e1)*_hc0[0]*_hc0[3]*_t3*_t54*_t9 + 0.6e1*_hc0[0]*_t29*_t4*_t47 + (0.3e1 / 0.2e1)*_hc0[1]*_hc0[2]*_t3*_t54*_t9 - 0.3e1*_hc0[1]*_t10*_t31 + 0.3e1*_hc0[1]*_t2*_t31*_t4 + 0.9e1*_hc0[1]*_t31*_t7*_t8 + (0.3e1 / 0.2e1)*_hc0[2]*_t2*_t4*_t47 + (0.9e1 / 0.2e1)*_hc0[2]*_t47*_t7*_t8 - 0.3e1 / 0.4e1*_hc0[2]*_t57*_t9 - 0.1e1 / 0.8e1*_hc0[3]*_t10*_t54 + (0.1e1 / 0.8e1)*_hc0[3]*_t2*_t4*_t54 + (0.3e1 / 0.8e1)*_hc0[3]*_t54*_t7*_t8 - 0.076049999999999993*_t16*_t31 - 0.1e1 / 0.4e1*_t20*_t48*_t54 - _t20*_t51*_t63 + 0.6e1*_t29*_t3*_t47*_t9 - 0.6e1*_t31*_t39 - 0.038024999999999996*_t34*_t47 + (0.3e1 / 0.4e1)*_t4*_t53*_t54 - 0.9e1*_t45*_t64 - 0.9e1 / 0.4e1*_t45*_t65 - _t50*_t66 + (0.3e1 / 0.4e1)*_t53*_t54*_t7 - 0.0031687499999999997*_t54*_t60 - 0.3e1 / 0.4e1*_t55*_t9 - 0.0063374999999999994*_t55 - _t56*_t57 - 0.3e1*_t59*_t9 - 0.076049999999999993*_t59 - _t61*_t62 - _t61*_t64;
  const double d3F_dna3 = (0.3e1 / 0.2e1)*_hc0[0]*_hc0[2]*_t23*_t26 - 0.3e1 / 0.2e1*_t11*_t41 - _t11*_t44 - _t11*_t50*_t51 - _t14*_t52 + 0.3e1*_t2*_t46 + _t2*_t67*na + (0.3e1 / 0.2e1)*_t23*_t26*_t29 - 0.1e1 / 0.4e1*_t47*_t49;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double _t69 = xc_powi(na, -7);
  const double _t79 = xc_powi(na, -8);
  const double _t93 = 0.24e2*_t47;
  const double _t68 = 0.6e1*_t11;
  const double _t70 = _t11*_t69;
  const double _t71 = (0.1e1 / 0.8e1)*_hc0[0];
  const double _t72 = _hc0[3]*_t69;
  const double _t73 = ((_hc0[2]) * (_hc0[2]));
  const double _t74 = 0.6e1*_t23;
  const double _t75 = _t23*_t47;
  const double _t76 = _t53*_t69;
  const double _t77 = _hc0[2]*_t69;
  const double _t78 = _t13*_t77;
  const double _t80 = _hc0[3]*_t79;
  const double _t81 = _t13*_t80;
  const double _t82 = _t54*_t58;
  const double _t83 = _t73*_t79;
  const double _t84 = _hc0[0]*_t83;
  const double _t85 = _hc0[4]*_t79;
  const double _t86 = _t29*_t79;
  const double _t87 = 0.9e1*_t76;
  const double _t88 = _hc0[1]*_t47;
  const double _t89 = 0.12e2*_t88;
  const double _t90 = 0.9e1*_t63;
  const double _t91 = (0.1e1 / 0.16e2)*_t85;
  const double _t92 = (0.9e1 / 0.4e1)*_hc0[2]*_t86;
  const double _t94 = 0.18e2*_t20;
  const double _t95 = _t27*_t54;
  const double _t96 = _t48*_t69;
  const double _t97 = _t71*_t85;
  const double _t98 = _hc0[1]*_t77;
  const double _t99 = _hc0[1]*_t80;
  const double _t100 = _t29*_t54;
  const double _t101 = _hc0[1]*_t21;
  const double d4F_dna4 = -0.3e1*_hc0[1]*_hc0[2]*_t75 + _hc0[1]*_t25*_t72 + _hc0[4]*_t70*_t71 - 0.4e1*_t14*_t67 + 0.4e1*_t2*_t67 + _t2*na*(_t10*_t89 + _t10*_t90 + _t10*_t91 - 0.36e2*_t100*_t21 + 0.54e2*_t100*_t45 + _t100*_t94 - 0.18e2*_t101*_t77 - _t101*_t80 + 0.30419999999999997*_t16*_t47 + 0.0015843749999999998*_t2*_t85 + (0.3e1 / 0.8e1)*_t20*_t83 + _t20*_t97 + 0.9e1*_t20*_t98 - 0.3e1 / 0.4e1*_t21*_t83 - 0.18e2*_t21*_t95 - 0.3e1*_t21*_t96 - _t21*_t97 - 0.27e2*_t22*_t63 - 0.9e1 / 0.2e1*_t22*_t72 - 0.3e1 / 0.16e2*_t22*_t85 - 0.36e2*_t22*_t88 + 0.22814999999999999*_t34*_t54 + _t39*_t93 - 0.18e2*_t4*_t78 - _t4*_t81 - 0.36e2*_t4*_t82 - 0.3e1 / 0.4e1*_t4*_t84 - _t4*_t87 - _t4*_t92 + _t40*_t99 + _t42*_t81 - _t43*_t93 + (0.9e1 / 0.8e1)*_t45*_t83 + 0.27e2*_t45*_t98 + (0.3e1 / 0.2e1)*_t45*_t99 - 0.3e1 / 0.2e1*_t5*_t72 - _t5*_t89 - _t5*_t90 - _t5*_t91 + _t56*_t86 + 0.038024999999999996*_t60*_t69 + _t61*_t96 + _t66*_t72 - _t7*_t87 - _t7*_t92 + 0.076049999999999993*_t76 + 0.9e1*_t78*_t9 + 0.22814999999999996*_t78 + 0.012674999999999999*_t81 + 0.18e2*_t82*_t9 + 0.45629999999999998*_t82 + (0.3e1 / 0.8e1)*_t84*_t9 + 0.0095062499999999991*_t84 + _t87*_t9 + _t9*_t92 + _t94*_t95) + _t28*_t52 + _t30*_t52 - _t32*_t74 - _t41*_t74 - _t48*_t75 + 0.2e1*_t49*_t54 + _t62*_t68 + _t64*_t68 + _t65*_t68 + (0.3e1 / 0.8e1)*_t70*_t73;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = (0.1e1 / _t1);
  const double _t5 = 0.020398113234875219 - 0.1e1 / 0.72e2*(M_PI * M_PI);
  const double _t7 = log(xc_powr(0.2e1, 1, 2)*xc_powr(M_PI, 1, 2));
  const double _t8 = 0.31069049999999998 - 0.41425400000000001*_t7;
  const double _t10 = 1.3387289587889073 - 1.657016*_t7;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(t_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t2, _hc0);
  const double _t3 = ((_hc0[0]) * (_hc0[0]));
  const double _t4 = 0.1e1 - _hc0[0];
  const double _t6 = _t3*_t5;
  const double _t9 = (_t4 * _t4);
  const double _t11 = _t10*_t9;
  const double _t12 = 0.0084499999999999992*((_hc0[0]) * (_hc0[0]) * (_hc0[0])) + _hc0[0]*_t11 + (_t4 * _t4 * _t4)*_t8 + _t4*_t6;
  const double _t13 = _t12*_t3;
  const double zk = _t13;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t16 = (0.1e1 / (_t1 * _t1));
  const double _t14 = _hc0[0]*_hc0[1];
  const double _t15 = _t14*_t2;
  const double _t17 = _hc0[1]*_t3;
  const double _t18 = _hc0[1]*_t16;
  const double _t19 = (0.1e1 / 0.2e1)*_t18;
  const double _t20 = _t14*_t16;
  const double _t21 = _t4*_t5;
  const double _t22 = _t10*_t4;
  const double _t23 = _t8*_t9;
  const double _t24 = -_t11*_t19 - 0.012674999999999999*_t16*_t17 + (0.3e1 / 0.2e1)*_t18*_t23 + _t19*_t6 - _t20*_t21 + _t20*_t22;
  const double _t25 = _t24*_t3;
  const double _t26 = _t1*_t25 - _t12*_t15 + _t13;
  const double dF_dna = _t26;
  const double dF_dnb = _t26;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t28 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t33 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t40 = 0.2e1*_t28;
  const double _t44 = (0.1e1 / 0.2e1)*_t10;
  const double _t27 = (0.1e1 / 0.2e1)*_t12;
  const double _t29 = _hc0[0]*_hc0[2];
  const double _t30 = _t28*_t29;
  const double _t31 = ((_hc0[1]) * (_hc0[1]));
  const double _t32 = _t28*_t31;
  const double _t34 = _t31*_t33;
  const double _t35 = _hc0[0]*_t34;
  const double _t36 = _hc0[2]*_t3;
  const double _t37 = _hc0[1]*_t28;
  const double _t38 = _hc0[2]*_t33;
  const double _t39 = (0.1e1 / 0.4e1)*_t38;
  const double _t41 = _t14*_t21;
  const double _t42 = (0.1e1 / 0.2e1)*_t21;
  const double _t43 = _hc0[0]*_t38;
  const double _t45 = _t14*_t22;
  const double _t46 = (0.3e1 / 0.2e1)*_t34;
  const double _t47 = _t4*_t8;
  const double _t48 = _t11*_t37 + _t11*_t39 + 0.025349999999999998*_t17*_t28 - _t22*_t34 - 0.1e1 / 0.2e1*_t22*_t43 - 0.3e1*_t23*_t37 - 0.3e1 / 0.4e1*_t23*_t38 + 0.0063374999999999994*_t33*_t36 + _t34*_t42 + _t35*_t44 - _t35*_t5 + 0.012674999999999999*_t35 - _t37*_t6 - _t39*_t6 + _t40*_t41 - _t40*_t45 + _t42*_t43 + _t46*_t47;
  const double _t49 = _t1*_t3*_t48 - 0.2e1*_t15*_t24 + 0.2e1*_t25 + _t27*_t30 + _t27*_t32;
  const double d2F_dna2 = _t49;
  const double d2F_dna_dnb = _t49;
  const double d2F_dnb2 = _t49;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t50 = xc_powi(_t1, -5);
  const double _t57 = xc_powi(_t1, -6);
  const double _t51 = _hc0[0]*_hc0[3];
  const double _t52 = _t12*_t51;
  const double _t53 = _hc0[2]*_t50;
  const double _t54 = (0.3e1 / 0.4e1)*_hc0[1];
  const double _t55 = 0.3e1*_t48;
  const double _t56 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t58 = _t56*_t57;
  const double _t59 = 0.019012499999999998*_hc0[2];
  const double _t60 = _t14*_t57;
  const double _t61 = _hc0[0]*_t31;
  const double _t62 = _t50*_t61;
  const double _t63 = _hc0[3]*_t3;
  const double _t64 = 0.3e1*_t21;
  const double _t65 = _t29*_t50;
  const double _t66 = _hc0[2]*_t57;
  const double _t67 = _t31*_t50;
  const double _t68 = _hc0[1]*_t66;
  const double _t69 = (0.3e1 / 0.2e1)*_t11;
  const double _t70 = (0.3e1 / 0.2e1)*_hc0[0]*_hc0[1]*_hc0[2]*_t5*_t57 + 0.6e1*_hc0[0]*_hc0[1]*_t10*_t33*_t4 + 0.3e1*_hc0[0]*_hc0[2]*_t10*_t4*_t50 + (0.1e1 / 0.4e1)*_hc0[0]*_hc0[3]*_t10*_t4*_t57 + 0.6e1*_hc0[0]*_t31*_t5*_t50 + (0.3e1 / 0.2e1)*_hc0[1]*_hc0[2]*_t10*_t4*_t57 - 0.3e1*_hc0[1]*_t11*_t33 + 0.3e1*_hc0[1]*_t3*_t33*_t5 + 0.9e1*_hc0[1]*_t33*_t8*_t9 - 0.3e1 / 0.4e1*_hc0[2]*_t10*_t60 + (0.3e1 / 0.2e1)*_hc0[2]*_t3*_t5*_t50 + (0.9e1 / 0.2e1)*_hc0[2]*_t50*_t8*_t9 - 0.1e1 / 0.8e1*_hc0[3]*_t11*_t57 + (0.1e1 / 0.8e1)*_hc0[3]*_t3*_t5*_t57 + (0.3e1 / 0.8e1)*_hc0[3]*_t57*_t8*_t9 + 0.6e1*_t10*_t31*_t4*_t50 - 0.3e1 / 0.4e1*_t10*_t58 - 0.3e1*_t10*_t62 - 0.076049999999999993*_t17*_t33 - 0.1e1 / 0.4e1*_t21*_t51*_t57 - _t21*_t54*_t66 - 0.6e1*_t33*_t41 - 0.038024999999999996*_t36*_t50 - 0.9e1*_t47*_t67 - 0.9e1 / 0.4e1*_t47*_t68 + (0.3e1 / 0.4e1)*_t5*_t56*_t57 - _t53*_t69 + (0.3e1 / 0.4e1)*_t56*_t57*_t8 - 0.0031687499999999997*_t57*_t63 - 0.0063374999999999994*_t58 - _t59*_t60 - 0.076049999999999993*_t62 - _t64*_t65 - _t64*_t67;
  const double _t71 = (0.3e1 / 0.2e1)*_hc0[0]*_hc0[2]*_t24*_t28 + _t1*_t3*_t70 - 0.3e1 / 0.2e1*_t12*_t43 - _t12*_t46 - _t12*_t53*_t54 - _t15*_t55 + (0.3e1 / 0.2e1)*_t24*_t28*_t31 + 0.3e1*_t3*_t48 - 0.1e1 / 0.4e1*_t50*_t52;
  const double d3F_dna3 = _t71;
  const double d3F_dna2_dnb = _t71;
  const double d3F_dna_dnb2 = _t71;
  const double d3F_dnb3 = _t71;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t73 = xc_powi(_t1, -7);
  const double _t83 = xc_powi(_t1, -8);
  const double _t97 = 0.24e2*_t50;
  const double _t72 = 0.6e1*_t12;
  const double _t74 = _t12*_t73;
  const double _t75 = (0.1e1 / 0.8e1)*_hc0[0];
  const double _t76 = _hc0[3]*_t73;
  const double _t77 = ((_hc0[2]) * (_hc0[2]));
  const double _t78 = 0.6e1*_t24;
  const double _t79 = _t24*_t50;
  const double _t80 = _t56*_t73;
  const double _t81 = _hc0[2]*_t73;
  const double _t82 = _t14*_t81;
  const double _t84 = _hc0[3]*_t83;
  const double _t85 = _t14*_t84;
  const double _t86 = _t57*_t61;
  const double _t87 = _t77*_t83;
  const double _t88 = _hc0[0]*_t87;
  const double _t89 = _hc0[4]*_t83;
  const double _t90 = _t31*_t83;
  const double _t91 = 0.9e1*_t80;
  const double _t92 = _hc0[1]*_t50;
  const double _t93 = 0.12e2*_t92;
  const double _t94 = 0.9e1*_t66;
  const double _t95 = (0.1e1 / 0.16e2)*_t89;
  const double _t96 = (0.9e1 / 0.4e1)*_hc0[2]*_t90;
  const double _t98 = 0.18e2*_t21;
  const double _t99 = _t29*_t57;
  const double _t100 = _t51*_t73;
  const double _t101 = _t75*_t89;
  const double _t102 = _hc0[1]*_t81;
  const double _t103 = _hc0[1]*_t84;
  const double _t104 = _t31*_t57;
  const double _t105 = _hc0[1]*_t22;
  const double _t106 = -0.3e1*_hc0[1]*_hc0[2]*_t79 + _hc0[1]*_t27*_t76 + _hc0[4]*_t74*_t75 + _t1*_t3*(0.9e1*_t10*_t82 + 0.18e2*_t10*_t86 + (0.3e1 / 0.8e1)*_t10*_t88 + _t10*_t91 + _t10*_t96 - 0.3e1*_t100*_t22 + _t100*_t64 + _t101*_t21 - _t101*_t22 + 0.9e1*_t102*_t21 + 0.27e2*_t102*_t47 + _t103*_t42 + (0.3e1 / 0.2e1)*_t103*_t47 - 0.36e2*_t104*_t22 + 0.54e2*_t104*_t47 + _t104*_t98 - 0.18e2*_t105*_t81 - _t105*_t84 + _t11*_t93 + _t11*_t94 + _t11*_t95 + 0.30419999999999997*_t17*_t50 + (0.3e1 / 0.8e1)*_t21*_t87 - 0.3e1 / 0.4e1*_t22*_t87 - 0.18e2*_t22*_t99 - 0.27e2*_t23*_t66 - 0.9e1 / 0.2e1*_t23*_t76 - 0.3e1 / 0.16e2*_t23*_t89 - 0.36e2*_t23*_t92 + 0.0015843749999999998*_t3*_t89 + 0.22814999999999999*_t36*_t57 + _t41*_t97 + _t44*_t85 - _t45*_t97 + (0.9e1 / 0.8e1)*_t47*_t87 - 0.18e2*_t5*_t82 - _t5*_t85 - 0.36e2*_t5*_t86 - 0.3e1 / 0.4e1*_t5*_t88 - _t5*_t91 - _t5*_t96 + _t59*_t90 - 0.3e1 / 0.2e1*_t6*_t76 - _t6*_t93 - _t6*_t94 - _t6*_t95 + 0.038024999999999996*_t63*_t73 + _t69*_t76 - _t8*_t91 - _t8*_t96 + 0.076049999999999993*_t80 + 0.22814999999999996*_t82 + 0.012674999999999999*_t85 + 0.45629999999999998*_t86 + 0.0095062499999999991*_t88 + _t98*_t99) - 0.4e1*_t15*_t70 + 0.4e1*_t3*_t70 + _t30*_t55 + _t32*_t55 - _t34*_t78 - _t43*_t78 - _t51*_t79 + 0.2e1*_t52*_t57 + _t65*_t72 + _t67*_t72 + _t68*_t72 + (0.3e1 / 0.8e1)*_t74*_t77;
  const double d4F_dna4 = _t106;
  const double d4F_dna3_dnb = _t106;
  const double d4F_dna2_dnb2 = _t106;
  const double d4F_dna_dnb3 = _t106;
  const double d4F_dnb4 = _t106;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif