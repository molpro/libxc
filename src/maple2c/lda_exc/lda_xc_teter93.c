/*
  Generated from python/lda_exc/lda_xc_teter93.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_xc_teter93
*/

#ifndef _LDA_XC_TETER93_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_XC_TETER93_KERNEL_BODY
#define _KMAX 0
#define _LDA_XC_TETER93_HELPER_BODIES
#include "lda_xc_teter93.c"
#undef _LDA_XC_TETER93_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_XC_TETER93_HELPER_BODIES
#include "lda_xc_teter93.c"
#undef _LDA_XC_TETER93_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_XC_TETER93_HELPER_BODIES
#include "lda_xc_teter93.c"
#undef _LDA_XC_TETER93_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_XC_TETER93_HELPER_BODIES
#include "lda_xc_teter93.c"
#undef _LDA_XC_TETER93_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_XC_TETER93_HELPER_BODIES
#include "lda_xc_teter93.c"
#undef _LDA_XC_TETER93_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_xc_teter93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_xc_teter93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_xc_teter93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_xc_teter93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_xc_teter93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_xc_teter93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_xc_teter93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_xc_teter93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_xc_teter93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_xc_teter93.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_XC_TETER93_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_zeta_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = (0.1e1 / (-0.2e1 + 0.2e1*M_CBRT2));
  const double _t2 = z + 0.1e1 <= p->zeta_threshold;
  const double _t3 = xc_powr(p->zeta_threshold, 4, 3) - 0.1e1;
  const double _t4 = p->zeta_threshold - 0.1e1;
  const double _t5 = z > _t4;
  const double _t6 = my_piecewise3(_t5, z, _t4);
  const double _t7 = xc_expm1((0.4e1 / 0.3e1)*xc_log1p(_t6));
  const double _t8 = 0.1e1 - z <= p->zeta_threshold;
  const double _t9 = -z;
  const double _t10 = _t9 > _t4;
  const double _t11 = my_piecewise3(_t10, _t9, _t4);
  const double _t12 = xc_expm1((0.4e1 / 0.3e1)*xc_log1p(_t11));
#if _KMAX >= 1
  const double _t13 = my_piecewise3(_t5, 0.1e1, 0);
  const double _t14 = _t6 + 0.1e1;
  const double _t15 = _t7 + 0.1e1;
  const double _t16 = my_piecewise3(_t10, -0.1e1, 0);
  const double _t17 = _t11 + 0.1e1;
  const double _t18 = _t12 + 0.1e1;
#endif

  const double f = _t1*(my_piecewise3(_t2, _t3, _t7) + my_piecewise3(_t8, _t3, _t12));
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t1*(my_piecewise3(_t2, 0, (0.4e1 / 0.3e1)*_t13*_t15/_t14) + my_piecewise3(_t8, 0, (0.4e1 / 0.3e1)*_t16*_t18/_t17));
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t1*(my_piecewise3(_t2, 0, (0.4e1 / 0.9e1)*(_t13 * _t13)*_t15/(_t14 * _t14)) + my_piecewise3(_t8, 0, (0.4e1 / 0.9e1)*(_t16 * _t16)*_t18/(_t17 * _t17)));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t1*(my_piecewise3(_t2, 0, -0.8e1 / 0.27e2*(_t13 * _t13 * _t13)*_t15/(_t14 * _t14 * _t14)) + my_piecewise3(_t8, 0, -0.8e1 / 0.27e2*(_t16 * _t16 * _t16)*_t18/(_t17 * _t17 * _t17)));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t1*(my_piecewise3(_t2, 0, (0.40e2 / 0.81e2)*(_t13 * _t13 * _t13 * _t13)*_t15/(_t14 * _t14 * _t14 * _t14)) + my_piecewise3(_t8, 0, (0.40e2 / 0.81e2)*(_t16 * _t16 * _t16 * _t16)*_t18/(_t17 * _t17 * _t17 * _t17)));
  out[4] = d4f_dz4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = (0.1e1 / M_PI);
  const double _t2 = _t1/na;
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = _t3/M_CBRTPI;
  const double _t5 = _t4/xc_powr(na, 1, 3);
  const double _t6 = xc_powr(0.6e1, 2, 3)/(M_CBRTPI * M_CBRTPI);
  const double _t7 = _t6/xc_powr(na, 2, 3);
  const double _t8 = -0.014761709089634985*_t2 - 1.1085293383318725*_t5 - 0.18513879338392632*_t7 - 0.4581652932831429;
  const double _t9 = xc_powr(na, -4, 3);
  const double _t10 = _t3/(M_PI * M_CBRTPI);
  const double _t11 = 0.0088473440678531476*_t10*_t9 + 0.833000522807187*_t2 + 0.5*_t5 + 1.1260327398566742*_t7;
  const double _t12 = (0.1e1 / _t11);
  const double _t13 = _t12*_t8;
  const double zk = _t13;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t14 = _t1/(na * na);
  const double _t15 = _t4*_t9;
  const double _t16 = _t6/xc_powr(na, 5, 3);
  const double _t17 = 0.014761709089634985*_t14 + 0.36950977944395751*_t15 + 0.12342586225595088*_t16;
  const double _t18 = _t12*_t17;
  const double _t19 = (0.1e1 / (_t11 * _t11));
  const double _t20 = _t19*_t8;
  const double _t21 = xc_powr(na, -7, 3);
  const double _t22 = _t10*_t21;
  const double _t23 = 0.833000522807187*_t14 + 0.16666666666666667*_t15 + 0.75068849323778283*_t16 + 0.01179645875713753*_t22;
  const double _t24 = _t23*na;
  const double dF_dna = _t13 + _t18*na + _t20*_t24;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t25 = _t1/(na * na * na);
  const double _t26 = _t21*_t4;
  const double _t27 = _t6/xc_powr(na, 8, 3);
  const double _t28 = -0.02952341817926997*_t25 - 0.49267970592527668*_t26 - 0.2057097704265848*_t27;
  const double _t29 = _t12*_t28;
  const double _t30 = xc_powr(na, -10, 3);
  const double _t31 = _t10*_t30;
  const double _t32 = -1.666001045614374*_t25 - 0.22222222222222222*_t26 - 1.251147488729638*_t27 - 0.027525070433320904*_t31;
  const double _t33 = _t20*_t32;
  const double _t34 = _t17*_t19;
  const double _t35 = 0.2e1*_t24;
  const double _t36 = (0.1e1 / (_t11 * _t11 * _t11));
  const double _t37 = _t36*_t8;
  const double _t38 = 1.666001045614374*_t14 + 0.33333333333333333*_t15 + 1.5013769864755657*_t16 + 0.023592917514275061*_t22;
  const double _t39 = _t24*_t38;
  const double d2F_dna2 = 0.2e1*_t18 + 0.2e1*_t20*_t23 + _t29*na + _t33*na + _t34*_t35 + _t37*_t39;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t40 = _t1/(na * na * na * na);
  const double _t41 = _t30*_t4;
  const double _t42 = _t6/xc_powr(na, 11, 3);
  const double _t43 = 0.088570254537809912*_t40 + 1.1495859804923122*_t41 + 0.54855938780422614*_t42;
  const double _t44 = _t12*_t43;
  const double _t45 = xc_powr(na, -13, 3);
  const double _t46 = _t10*_t45;
  const double _t47 = 4.998003136843122*_t40 + 0.51851851851851852*_t41 + 3.3363933032790348*_t42 + 0.091750234777736346*_t46;
  const double _t48 = _t20*_t47;
  const double _t49 = _t19*_t28;
  const double _t50 = _t32*_t34;
  const double _t51 = 0.3e1*na;
  const double _t52 = _t23*_t37;
  const double _t53 = -3.332002091228748*_t25 - 0.44444444444444444*_t26 - 2.5022949774592761*_t27 - 0.055050140866641808*_t31;
  const double _t54 = _t24*_t37;
  const double _t55 = _t17*_t36;
  const double _t56 = _t32*na;
  const double _t57 = _t37*_t38;
  const double _t58 = (0.1e1 / (_t11 * _t11 * _t11 * _t11));
  const double _t59 = 2.499001568421561*_t14 + 0.5*_t15 + 2.2520654797133485*_t16 + 0.03538937627141259*_t22;
  const double _t60 = _t58*_t59*_t8;
  const double d3F_dna3 = 0.6e1*_t23*_t34 + 0.3e1*_t24*_t49 + 0.3e1*_t29 + 0.3e1*_t33 + 0.3e1*_t38*_t52 + 0.3e1*_t39*_t55 + _t39*_t60 + _t44*na + _t48*na + _t50*_t51 + _t53*_t54 + 0.2e1*_t56*_t57;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double _t61 = _t1/xc_powi(na, 5);
  const double _t62 = _t4*_t45;
  const double _t63 = _t6/xc_powr(na, 14, 3);
  const double _t64 = 0.12e2*_t23;
  const double _t65 = 0.4e1*_t24;
  const double _t66 = _t38*_t55;
  const double _t67 = _t32*_t51;
  const double _t68 = _t38*_t60;
  const double _t69 = _t39*_t58;
  const double d4F_dna4 = _t12*na*(-0.35428101815123965*_t61 - 3.8319532683077074*_t62 - 2.0113844219488292*_t63) + 0.4e1*_t17*_t59*_t69 + _t19*_t43*_t65 + _t20*na*(-0.39758435070352417*_t10/xc_powr(na, 16, 3) - 19.992012547372488*_t61 - 1.7283950617283951*_t62 - 12.233442112023128*_t63) + 0.4e1*_t23*_t68 + 0.6e1*_t28*_t36*_t39 + 0.8e1*_t32*_t57 + 0.4e1*_t34*_t47*na + _t35*_t53*_t60 + _t37*_t53*_t67 + 0.4e1*_t44 + _t47*_t51*_t57 + 0.4e1*_t48 + 0.6e1*_t49*_t56 + _t49*_t64 + 0.12e2*_t50 + 0.4e1*_t52*_t53 + _t53*_t55*_t65 + _t54*(9.9960062736862441*_t40 + 1.037037037037037*_t41 + 6.6727866065580697*_t42 + 0.18350046955547269*_t46) + 0.8e1*_t56*_t66 + _t64*_t66 + _t67*_t68 + _t69*_t8*(-4.998003136843122*_t25 - 0.66666666666666667*_t26 - 3.7534424661889141*_t27 - 0.08257521129996271*_t31) + _t39*_t59*_t8*(3.332002091228748*_t14 + 0.66666666666666667*_t15 + 3.0027539729511313*_t16 + 0.047185835028550121*_t22)/xc_powi(_t11, 5);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na - nb;
  const double _t2 = na + nb;
  const double _t3 = (0.1e1 / _t2);
  const double _t5 = (0.1e1 / M_PI);
  const double _t6 = (0.3e1 / 0.4e1)*_t5;
  const double _t7 = _t3*_t6;
  const double _t9 = xc_powr(_t2, -1, 3);
  const double _t10 = xc_powr(0.6e1, 1, 3);
  const double _t11 = (0.1e1 / (M_CBRTPI));
  const double _t12 = _t10*_t11;
  const double _t13 = _t12*_t9;
  const double _t14 = xc_powr(_t2, -2, 3);
  const double _t15 = (0.1e1 / 0.4e1)*_t14;
  const double _t17 = xc_powr(0.6e1, 2, 3);
  const double _t18 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t19 = _t17*_t18;
  const double _t22 = 0.5*_t12;
  const double _t24 = xc_powr(_t2, -4, 3);
  const double _t26 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t27 = _t10*_t26;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k, _KMAX)(p, _t1*_t3, _hc0);
  const double _t4 = 0.003532336663397157*_hc0[0] + 0.01968227878617998;
  const double _t8 = 0.6157402568883345*_hc0[0] + 2.217058676663745;
  const double _t16 = 0.1574201515892867*_hc0[0] + 0.7405551735357053;
  const double _t20 = _t16*_t19;
  const double _t21 = -0.119086804055547*_hc0[0] - 0.1e1 / 0.2e1*_t13*_t8 - _t15*_t20 - _t4*_t7 - 0.4581652932831429;
  const double _t23 = 0.2052004607777787*_hc0[0] + 1.110667363742916;
  const double _t25 = 0.0042000050456913811*_hc0[0] + 0.02359291751427506;
  const double _t28 = _t25*_t27;
  const double _t29 = 0.2673612973836267*_hc0[0] + 4.5041309594266969;
  const double _t30 = _t19*_t29;
  const double _t31 = _t15*_t30 + _t22*_t9 + _t23*_t7 + (0.3e1 / 0.8e1)*_t24*_t28;
  const double _t32 = (0.1e1 / _t31);
  const double _t33 = _t21*_t32;
  const double zk = _t33;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t34 = -_t3;
  const double _t35 = (0.1e1 / (_t2 * _t2));
  const double _t36 = _t1*_t35;
  const double _t37 = -_t34 - _t36;
  const double _t43 = 0.30787012844416725*_t13;
  const double _t47 = xc_powr(_t2, -5, 3);
  const double _t53 = 0.0015750018921342679*_t24;
  const double _t54 = _t12*_t24;
  const double _t55 = xc_powr(_t2, -7, 3);
  const double _t62 = -_t3 - _t36;
  const double _t38 = 0.119086804055547*_hc0[1];
  const double _t39 = _hc0[1]*_t5;
  const double _t40 = _t3*_t39;
  const double _t41 = _t37*_t40;
  const double _t42 = _hc0[1]*_t37;
  const double _t44 = _hc0[1]*_t19;
  const double _t45 = _t14*_t44;
  const double _t46 = _t37*_t45;
  const double _t48 = -0.1e1 / 0.6e1*_t10*_t11*_t24*_t8 - 0.1e1 / 0.6e1*_t16*_t17*_t18*_t47 - 0.3e1 / 0.4e1*_t35*_t4*_t5;
  const double _t49 = -_t37*_t38 - 0.0026492524975478678*_t41 - _t42*_t43 - 0.039355037897321675*_t46 - _t48;
  const double _t50 = _t32*_t49;
  const double _t51 = _hc0[1]*_t27;
  const double _t52 = _t37*_t51;
  const double _t56 = _t28*_t55;
  const double _t57 = _t23*_t35*_t6 + (0.1e1 / 0.6e1)*_t30*_t47 + 0.16666666666666667*_t54 + (0.1e1 / 0.2e1)*_t56;
  const double _t58 = -0.15390034558333402*_t41 - 0.066840324345906674*_t46 - _t52*_t53 + _t57;
  const double _t59 = (0.1e1 / (_t31 * _t31));
  const double _t60 = _t21*_t59;
  const double _t61 = _t58*_t60;
  const double _t63 = _t40*_t62;
  const double _t64 = _hc0[1]*_t43;
  const double _t65 = _t45*_t62;
  const double _t66 = -_t38*_t62 - _t48 - _t62*_t64 - 0.0026492524975478678*_t63 - 0.039355037897321675*_t65;
  const double _t67 = _t32*_t66;
  const double _t68 = _t51*_t53;
  const double _t69 = _t57 - _t62*_t68 - 0.15390034558333402*_t63 - 0.066840324345906674*_t65;
  const double _t70 = _t60*_t69;
  const double dF_dna = _t2*_t50 + _t2*_t61 + _t33;
  const double dF_dnb = _t2*_t67 + _t2*_t70 + _t33;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t74 = 0.0031500037842685358*_t24;
  const double _t75 = (0.3e1 / 0.2e1)*_t5;
  const double _t84 = 0.2e1*_t35;
  const double _t85 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t86 = 0.2e1*_t1*_t85;
  const double _t87 = -_t84 + _t86;
  const double _t88 = (_t37 * _t37);
  const double _t92 = _t3*_t5;
  const double _t93 = 0.0026492524975478678*_t92;
  const double _t95 = _t14*_t19;
  const double _t97 = _t75*_t85;
  const double _t98 = _t12*_t55;
  const double _t99 = xc_powr(_t2, -8, 3);
  const double _t100 = (0.5e1 / 0.18e2)*_t99;
  const double _t104 = 0.15390034558333402*_t92;
  const double _t105 = _t27*_t53;
  const double _t107 = xc_powr(_t2, -10, 3);
  const double _t120 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t121 = _t1*_t120;
  const double _t124 = _t107*_t12;
  const double _t128 = xc_powr(_t2, -11, 3);
  const double _t131 = 0.039355037897321675*_t95;
  const double _t135 = xc_powr(_t2, -13, 3);
  const double _t138 = 0.066840324345906674*_t95;
  const double _t144 = _t84 + _t86;
  const double _t145 = (_t62 * _t62);
  const double _t71 = _t49*_t58;
  const double _t72 = _t2*_t59;
  const double _t73 = 0.2e1*_t72;
  const double _t76 = _t23*_t35;
  const double _t77 = _t30*_t47;
  const double _t78 = 0.33333333333333333*_t54 + _t56 + _t75*_t76 + (0.1e1 / 0.3e1)*_t77;
  const double _t79 = -0.30780069116666805*_t41 - 0.13368064869181335*_t46 - _t52*_t74 + _t78;
  const double _t80 = (0.1e1 / (_t31 * _t31 * _t31));
  const double _t81 = _t21*_t80;
  const double _t82 = _t58*_t81;
  const double _t83 = _t79*_t82;
  const double _t89 = 0.119086804055547*_hc0[2];
  const double _t90 = _t40*_t87;
  const double _t91 = _hc0[2]*_t88;
  const double _t94 = _t45*_t87;
  const double _t96 = _t91*_t95;
  const double _t101 = _t100*_t20 + _t4*_t97 + (0.2e1 / 0.9e1)*_t8*_t98;
  const double _t102 = 0.2052467522961115*_hc0[1]*_t10*_t11*_t24*_t37 + 0.052473383863095567*_hc0[1]*_t17*_t18*_t37*_t47 + 0.0052985049950957355*_hc0[1]*_t35*_t37*_t5 - _t101 - _t38*_t87 - _t43*_t91 - _t64*_t87 - _t88*_t89 - 0.0026492524975478678*_t90 - _t91*_t93 - 0.039355037897321675*_t94 - 0.039355037897321675*_t96;
  const double _t103 = _t102*_t32;
  const double _t106 = -0.0042000050456913812*_hc0[1]*_t10*_t26*_t37*_t55 - 0.0891204324612089*_hc0[1]*_t17*_t18*_t37*_t47 - 0.30780069116666805*_hc0[1]*_t35*_t37*_t5;
  const double _t108 = _t107*_t28;
  const double _t109 = _t100*_t30 + (0.7e1 / 0.6e1)*_t108 + _t23*_t97 + 0.22222222222222222*_t98;
  const double _t110 = -_t104*_t91 - _t105*_t91 - _t106 - _t109 - _t68*_t87 - 0.15390034558333402*_t90 - 0.066840324345906674*_t94 - 0.066840324345906674*_t96;
  const double _t111 = _t110*_t60;
  const double _t112 = _t49*_t69;
  const double _t113 = _t58*_t66;
  const double _t114 = _t51*_t62;
  const double _t115 = -_t114*_t74 - 0.30780069116666805*_t63 - 0.13368064869181335*_t65 + _t78;
  const double _t116 = _t115*_t82;
  const double _t117 = _t37*_t89;
  const double _t118 = _hc0[1]*_t85;
  const double _t119 = 0.238173608111094*_t118;
  const double _t122 = _hc0[1]*_t121;
  const double _t123 = _t122*_t5;
  const double _t125 = 0.6157402568883345*_hc0[1]*_t124;
  const double _t126 = _hc0[2]*_t37;
  const double _t127 = _t126*_t62;
  const double _t129 = _t128*_t44;
  const double _t130 = 0.07871007579464335*_t129;
  const double _t132 = 0.10262337614805575*_hc0[1]*_t10*_t11*_t24*_t37 + 0.10262337614805575*_hc0[1]*_t10*_t11*_t24*_t62 + 0.026236691931547784*_hc0[1]*_t17*_t18*_t37*_t47 + 0.026236691931547784*_hc0[1]*_t17*_t18*_t47*_t62 + 0.0026492524975478678*_hc0[1]*_t35*_t37*_t5 + 0.0026492524975478678*_hc0[1]*_t35*_t5*_t62 - _t1*_t119 - _t1*_t125 - _t1*_t130 - _t101 - _t117*_t62 - 0.0052985049950957355*_t123 - _t127*_t131 - _t127*_t43 - _t127*_t93;
  const double _t133 = _t132*_t32;
  const double _t134 = 0.13368064869181335*_t129;
  const double _t136 = _t135*_t51;
  const double _t137 = 0.0031500037842685358*_t136;
  const double _t139 = 0.0021000025228456906*_hc0[1]*_t10*_t26*_t37*_t55 + 0.0021000025228456905*_hc0[1]*_t10*_t26*_t55*_t62 + 0.04456021623060445*_hc0[1]*_t17*_t18*_t37*_t47 + 0.04456021623060445*_hc0[1]*_t17*_t18*_t47*_t62 + 0.15390034558333402*_hc0[1]*_t35*_t37*_t5 + 0.15390034558333402*_hc0[1]*_t35*_t5*_t62 - _t1*_t134 - _t1*_t137 - _t104*_t127 - _t105*_t127 - _t109 - 0.30780069116666805*_t123 - _t127*_t138;
  const double _t140 = _t139*_t60;
  const double _t141 = _t66*_t69;
  const double _t142 = _t69*_t81;
  const double _t143 = _t115*_t142;
  const double _t146 = _t144*_t40;
  const double _t147 = _hc0[2]*_t145;
  const double _t148 = _t144*_t45;
  const double _t149 = _t147*_t95;
  const double _t150 = 0.2052467522961115*_hc0[1]*_t10*_t11*_t24*_t62 + 0.052473383863095567*_hc0[1]*_t17*_t18*_t47*_t62 + 0.0052985049950957355*_hc0[1]*_t35*_t5*_t62 - _t101 - _t144*_t38 - _t144*_t64 - _t145*_t89 - 0.0026492524975478678*_t146 - _t147*_t43 - _t147*_t93 - 0.039355037897321675*_t148 - 0.039355037897321675*_t149;
  const double _t151 = _t150*_t32;
  const double _t152 = -0.0891204324612089*_hc0[1]*_t17*_t18*_t47*_t62 - 0.30780069116666805*_hc0[1]*_t35*_t5*_t62;
  const double _t153 = 0.0042000050456913812*_hc0[1]*_t10*_t26*_t55*_t62 - _t104*_t147 - _t105*_t147 - _t109 - _t144*_t68 - 0.15390034558333402*_t146 - 0.066840324345906674*_t148 - 0.066840324345906674*_t149 - _t152;
  const double _t154 = _t153*_t60;
  const double d2F_dna2 = _t103*_t2 + _t111*_t2 + _t2*_t83 + 0.2e1*_t50 + 0.2e1*_t61 + _t71*_t73;
  const double d2F_dna_dnb = _t112*_t72 + _t113*_t72 + _t116*_t2 + _t133*_t2 + _t140*_t2 + _t50 + _t61 + _t67 + _t70;
  const double d2F_dnb2 = _t141*_t73 + _t143*_t2 + _t151*_t2 + _t154*_t2 + 0.2e1*_t67 + 0.2e1*_t70;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t164 = 0.0047250056764028038*_t24;
  const double _t174 = 0.30780069116666805*_t92;
  const double _t185 = 0.6e1*_t85;
  const double _t186 = 0.6e1*_t121;
  const double _t187 = _t185 - _t186;
  const double _t189 = (_t37 * _t37 * _t37);
  const double _t194 = 0.4e1*_t35;
  const double _t195 = 0.4e1*_t1*_t85;
  const double _t196 = -_t194 + _t195;
  const double _t213 = -_t186 + 0.2e1*_t85;
  const double _t215 = -_t1*_t35;
  const double _t216 = _t215 + _t34;
  const double _t218 = 0.47634721622218801*_t85;
  const double _t221 = xc_powi(_t2, -5);
  const double _t232 = xc_powr(_t2, -14, 3);
  const double _t233 = 1.231480513776669*_t124;
  const double _t234 = _t128*_t19;
  const double _t243 = xc_powr(_t2, -16, 3);
  const double _t244 = _t135*_t27;
  const double _t245 = 0.0063000075685370716*_t244;
  const double _t256 = 0.13368064869181335*_t95;
  const double _t270 = (0.9e1 / 0.2e1)*_t120;
  const double _t271 = _t1*_t221;
  const double _t274 = (0.20e2 / 0.27e2)*_t128;
  const double _t275 = _t12*_t135;
  const double _t280 = _t35*_t5;
  const double _t284 = _t19*_t47;
  const double _t289 = _t215 + _t3;
  const double _t302 = 0.0021000025228456905*_t55;
  const double _t326 = -_t185 - _t186;
  const double _t328 = (_t62 * _t62 * _t62);
  const double _t333 = _t194 + _t195;
  const double _t155 = 0.6e1*_t59;
  const double _t156 = _t2*_t80;
  const double _t157 = _t156*_t79;
  const double _t158 = 0.3e1*_t157;
  const double _t159 = _t110*_t49;
  const double _t160 = 0.3e1*_t72;
  const double _t161 = (0.1e1 / (_t31 * _t31 * _t31 * _t31));
  const double _t162 = _t161*_t21;
  const double _t163 = _t162*_t58;
  const double _t165 = _t5*_t76;
  const double _t166 = (0.9e1 / 0.4e1)*_t165 + _t22*_t24 + (0.3e1 / 0.2e1)*_t56 + (0.1e1 / 0.2e1)*_t77;
  const double _t167 = -_t164*_t52 + _t166 - 0.46170103675000207*_t41 - 0.20052097303772002*_t46;
  const double _t168 = _t167*_t79;
  const double _t169 = _t163*_t168;
  const double _t170 = _t102*_t58;
  const double _t171 = _t110*_t79;
  const double _t172 = _t2*_t81;
  const double _t173 = 0.2e1*_t172;
  const double _t175 = _t51*_t87;
  const double _t176 = _t27*_t91;
  const double _t177 = _t23*_t5;
  const double _t178 = _t177*_t85;
  const double _t179 = _t30*_t99;
  const double _t180 = (0.7e1 / 0.3e1)*_t108 + 0.3e1*_t178 + (0.5e1 / 0.9e1)*_t179 + 0.44444444444444444*_t98;
  const double _t181 = 0.0084000100913827623*_hc0[1]*_t10*_t26*_t37*_t55 + 0.1782408649224178*_hc0[1]*_t17*_t18*_t37*_t47 + 0.6156013823333361*_hc0[1]*_t35*_t37*_t5 - _t174*_t91 - _t175*_t74 - _t176*_t74 - _t180 - 0.30780069116666805*_t90 - 0.13368064869181335*_t94 - 0.13368064869181335*_t96;
  const double _t182 = _t181*_t82;
  const double _t183 = _t118*_t5;
  const double _t184 = _t183*_t37;
  const double _t188 = _t187*_t40;
  const double _t190 = _hc0[3]*_t189;
  const double _t191 = _t187*_t45;
  const double _t192 = _t190*_t95;
  const double _t193 = _t107*_t52;
  const double _t197 = _t104*_t126;
  const double _t198 = _t44*_t99;
  const double _t199 = _t198*_t37;
  const double _t200 = _t126*_t138;
  const double _t201 = _t105*_t126;
  const double _t202 = -0.51851851851851852*_t10*_t107*_t11 - 0.35e2 / 0.9e1*_t10*_t135*_t25*_t26 - 0.9e1 / 0.2e1*_t120*_t23*_t5 - 0.20e2 / 0.27e2*_t128*_t17*_t18*_t29;
  const double _t203 = 0.0063000075685370717*_hc0[1]*_t10*_t26*_t55*_t87 + 0.13368064869181335*_hc0[1]*_t17*_t18*_t47*_t87 + 0.46170103675000207*_hc0[1]*_t35*_t5*_t87 + 0.0063000075685370717*_hc0[2]*_t10*_t26*_t55*_t88 + 0.13368064869181335*_hc0[2]*_t17*_t18*_t47*_t88 + 0.46170103675000207*_hc0[2]*_t35*_t5*_t88 - _t104*_t190 - _t105*_t190 - 0.92340207350000414*_t184 - _t187*_t68 - 0.15390034558333402*_t188 - 0.066840324345906674*_t191 - 0.066840324345906674*_t192 - 0.014700017659919834*_t193 - _t196*_t197 - _t196*_t200 - _t196*_t201 - _t197*_t87 - 0.22280108115302225*_t199 - _t200*_t87 - _t201*_t87 - _t202;
  const double _t204 = _t203*_t60;
  const double _t205 = 0.119086804055547*_hc0[3];
  const double _t206 = _t126*_t93;
  const double _t207 = _t42*_t98;
  const double _t208 = _t126*_t43;
  const double _t209 = _t126*_t131;
  const double _t210 = -0.14e2 / 0.27e2*_t10*_t107*_t11*_t8 - 0.9e1 / 0.2e1*_t120*_t4*_t5 - 0.20e2 / 0.27e2*_t128*_t16*_t17*_t18;
  const double _t211 = 0.30787012844416725*_hc0[1]*_t10*_t11*_t24*_t87 + 0.078710075794643352*_hc0[1]*_t17*_t18*_t47*_t87 + 0.0079477574926436032*_hc0[1]*_t35*_t5*_t87 + 0.30787012844416725*_hc0[2]*_t10*_t11*_t24*_t88 + 0.078710075794643352*_hc0[2]*_t17*_t18*_t47*_t88 + 0.0079477574926436032*_hc0[2]*_t35*_t5*_t88 - _t117*_t196 - _t117*_t87 - 0.015895514985287206*_t183*_t37 - _t187*_t38 - _t187*_t64 - 0.0026492524975478678*_t188 - _t189*_t205 - _t190*_t43 - _t190*_t93 - 0.039355037897321675*_t191 - 0.039355037897321675*_t192 - _t196*_t206 - _t196*_t208 - _t196*_t209 - 0.13118345965773892*_t199 - _t206*_t87 - 0.41049350459222301*_t207 - _t208*_t87 - _t209*_t87 - _t210;
  const double _t212 = _t211*_t32;
  const double _t214 = _t62*_t89;
  const double _t217 = _t205*_t88;
  const double _t219 = _t213*_t40;
  const double _t220 = _t183*_t62;
  const double _t222 = _hc0[1]*_t98;
  const double _t223 = _t222*_t62;
  const double _t224 = _hc0[2]*_t62;
  const double _t225 = _t224*_t87;
  const double _t226 = _hc0[3]*_t88;
  const double _t227 = _t216*_t226;
  const double _t228 = _t121*_t126;
  const double _t229 = _t228*_t5;
  const double _t230 = _t213*_t45;
  const double _t231 = _t198*_t62;
  const double _t235 = _t126*_t234;
  const double _t236 = 0.410493504592223*_hc0[1]*_t1*_t10*_t11*_t135 + 0.10494676772619113*_hc0[1]*_t1*_t17*_t18*_t232 + 0.010597009990191471*_hc0[1]*_t1*_t221*_t5 + 0.10262337614805575*_hc0[1]*_t10*_t11*_t24*_t87 + 0.026236691931547784*_hc0[1]*_t17*_t18*_t47*_t87 + 0.0026492524975478678*_hc0[1]*_t35*_t5*_t87 + 0.2052467522961115*_hc0[2]*_t10*_t11*_t24*_t37*_t62 + 0.10262337614805575*_hc0[2]*_t10*_t11*_t24*_t88 + 0.052473383863095567*_hc0[2]*_t17*_t18*_t37*_t47*_t62 + 0.026236691931547784*_hc0[2]*_t17*_t18*_t47*_t88 + 0.0052985049950957355*_hc0[2]*_t35*_t37*_t5*_t62 + 0.0026492524975478678*_hc0[2]*_t35*_t5*_t88 - _t1*_t126*_t218 - _t1*_t126*_t233 - 0.1574201515892867*_t1*_t235 - _t131*_t225 - _t131*_t227 - 0.010597009990191471*_t184 - 0.087455639771825945*_t199 - 0.27366233639481534*_t207 - _t210 - _t213*_t38 - _t213*_t64 - _t214*_t87 - _t216*_t217 - 0.0026492524975478678*_t219 - 0.0052985049950957355*_t220 - 0.13683116819740767*_t223 - _t225*_t43 - _t225*_t93 - _t227*_t43 - _t227*_t93 - 0.010597009990191471*_t229 - 0.039355037897321675*_t230 - 0.043727819885912972*_t231;
  const double _t237 = _t2*_t32;
  const double _t238 = 0.2e1*_t59;
  const double _t239 = 0.6156013823333361*_t184;
  const double _t240 = 0.14853405410201483*_t199;
  const double _t241 = 0.0098000117732798893*_t193;
  const double _t242 = _t107*_t114;
  const double _t246 = 0.0084000100913827623*_hc0[1]*_t1*_t10*_t243*_t26 + 0.1782408649224178*_hc0[1]*_t1*_t17*_t18*_t232 + 0.6156013823333361*_hc0[1]*_t1*_t221*_t5 + 0.0021000025228456906*_hc0[1]*_t10*_t26*_t55*_t87 + 0.04456021623060445*_hc0[1]*_t17*_t18*_t47*_t87 + 0.15390034558333402*_hc0[1]*_t35*_t5*_t87 + 0.0042000050456913812*_hc0[2]*_t10*_t26*_t37*_t55*_t62 + 0.0021000025228456906*_hc0[2]*_t10*_t26*_t55*_t88 + 0.0891204324612089*_hc0[2]*_t17*_t18*_t37*_t47*_t62 + 0.04456021623060445*_hc0[2]*_t17*_t18*_t47*_t88 + 0.30780069116666805*_hc0[2]*_t35*_t37*_t5*_t62 + 0.15390034558333402*_hc0[2]*_t35*_t5*_t88 - _t1*_t126*_t245 - 0.2673612973836267*_t1*_t235 - _t104*_t225 - _t104*_t227 - _t105*_t225 - _t105*_t227 - _t138*_t225 - _t138*_t227 - _t202 - _t213*_t68 - 0.15390034558333402*_t219 - 0.30780069116666805*_t220 - 0.6156013823333361*_t229 - 0.066840324345906674*_t230 - 0.074267027051007416*_t231 - _t239 - _t240 - _t241 - 0.0049000058866399445*_t242;
  const double _t247 = _t2*_t60;
  const double _t248 = _t110*_t66;
  const double _t249 = _t102*_t69;
  const double _t250 = _t139*_t49;
  const double _t251 = _t132*_t58;
  const double _t252 = _t139*_t79;
  const double _t253 = _t110*_t115;
  const double _t254 = 0.2673612973836267*_t129;
  const double _t255 = 0.0063000075685370716*_t136;
  const double _t257 = _t127*_t27;
  const double _t258 = 0.0042000050456913811*_hc0[1]*_t10*_t26*_t55*_t62 - _t1*_t254 - _t1*_t255 - _t106 - 0.6156013823333361*_t123 - _t127*_t174 - _t127*_t256 - _t152 - _t180 - _t257*_t74;
  const double _t259 = _t2*_t82;
  const double _t260 = _t113*_t79;
  const double _t261 = _t115*_t156;
  const double _t262 = 0.2e1*_t71;
  const double _t263 = -_t114*_t164 + _t166 - 0.46170103675000207*_t63 - 0.20052097303772002*_t65;
  const double _t264 = _t163*_t2;
  const double _t265 = _t264*_t79;
  const double _t266 = _t112*_t238 + _t113*_t238 + 0.2e1*_t116 + 0.2e1*_t133 + 0.2e1*_t140;
  const double _t267 = _hc0[1]*_t120;
  const double _t268 = _t267*_t5;
  const double _t269 = _t4*_t5;
  const double _t272 = _hc0[1]*_t271;
  const double _t273 = _t272*_t5;
  const double _t276 = _hc0[1]*_t275;
  const double _t277 = _t232*_t44;
  const double _t278 = _t1*_t277;
  const double _t279 = _t144*_t35*_t39;
  const double _t281 = _t147*_t280;
  const double _t282 = _t1*_t224;
  const double _t283 = _t144*_t44*_t47;
  const double _t285 = _t147*_t284;
  const double _t286 = _t121*_t224;
  const double _t287 = _t286*_t5;
  const double _t288 = _t234*_t282;
  const double _t290 = _t145*_t205;
  const double _t291 = _t127*_t280;
  const double _t292 = _hc0[3]*_t145;
  const double _t293 = _t289*_t292;
  const double _t294 = _t126*_t144;
  const double _t295 = _t127*_t284;
  const double _t296 = 0.10262337614805575*_hc0[1]*_t144*_t54 + 2.2577142752572265*_t1*_t276 - _t117*_t144 + _t119 + 0.71452082433328201*_t122 + (0.14e2 / 0.27e2)*_t124*_t8 + _t125 + 0.2052467522961115*_t127*_t54 + _t130 - _t131*_t293 - _t131*_t294 - _t144*_t206 + 0.10262337614805575*_t147*_t54 - 0.0052985049950957355*_t183*_t37 - 0.043727819885912973*_t199 + _t20*_t274 - 0.13683116819740767*_t207 - _t218*_t282 - 0.010597009990191471*_t220 - 0.27366233639481534*_t223 - 0.087455639771825945*_t231 - _t233*_t282 + 0.0052985049950957355*_t268 + _t269*_t270 + 0.026492524975478678*_t273 + 0.34107699511012118*_t278 + 0.0026492524975478678*_t279 + 0.0026492524975478678*_t281 + 0.026236691931547784*_t283 + 0.026236691931547784*_t285 - 0.010597009990191471*_t287 - 0.1574201515892867*_t288 - _t289*_t290 + 0.0052985049950957355*_t291 - _t293*_t43 - _t293*_t93 - _t294*_t43 + 0.052473383863095567*_t295;
  const double _t297 = _t135*_t28;
  const double _t298 = _t243*_t51;
  const double _t299 = _t1*_t298;
  const double _t300 = 0.6156013823333361*_t220;
  const double _t301 = 0.0098000117732798891*_t242;
  const double _t303 = _t144*_t51;
  const double _t304 = 0.14853405410201483*_t231;
  const double _t305 = _t147*_t27;
  const double _t306 = -_t104*_t293 - _t105*_t293 - _t105*_t294 + 0.51851851851851852*_t124 + _t134 + _t137 - _t138*_t293 - _t138*_t294 - _t144*_t197 + _t177*_t270 - 0.30780069116666805*_t184 - 0.0049000058866399447*_t193 - 0.074267027051007416*_t199 - _t245*_t282 + 0.0042000050456913812*_t257*_t55 + 0.30780069116666805*_t268 + 1.5390034558333403*_t273 + _t274*_t30 + 0.57928281099785785*_t278 + 0.15390034558333402*_t279 + 0.15390034558333402*_t281 + 0.04456021623060445*_t283 + 0.04456021623060445*_t285 - 0.6156013823333361*_t287 - 0.2673612973836267*_t288 + 0.30780069116666805*_t291 + 0.0891204324612089*_t295 + (0.35e2 / 0.9e1)*_t297 + 0.01785002144418837*_t299 - _t300 - _t301 + _t302*_t303 + _t302*_t305 - _t304;
  const double _t307 = _t153*_t49;
  const double _t308 = _t150*_t58;
  const double _t309 = _t66*_t72;
  const double _t310 = 0.2e1*_t309;
  const double _t311 = _t69*_t72;
  const double _t312 = 0.2e1*_t311;
  const double _t313 = 0.0084000100913827623*_hc0[1]*_t10*_t26*_t55*_t62 + 0.1782408649224178*_hc0[1]*_t17*_t18*_t47*_t62 + 0.6156013823333361*_hc0[1]*_t35*_t5*_t62 - 0.30780069116666805*_t146 - _t147*_t174 - 0.13368064869181335*_t148 - 0.13368064869181335*_t149 - _t180 - _t303*_t74 - _t305*_t74;
  const double _t314 = _t112*_t115;
  const double _t315 = _t115*_t172;
  const double _t316 = 0.2e1*_t315;
  const double _t317 = _t113*_t156;
  const double _t318 = 0.2e1*_t317;
  const double _t319 = _t115*_t263;
  const double _t320 = 0.3e1*_t141;
  const double _t321 = _t162*_t69;
  const double _t322 = _t319*_t321;
  const double _t323 = 0.3e1*_t309;
  const double _t324 = 0.3e1*_t311;
  const double _t325 = _t142*_t313;
  const double _t327 = _t326*_t40;
  const double _t329 = _hc0[3]*_t328;
  const double _t330 = _t326*_t45;
  const double _t331 = _t329*_t95;
  const double _t332 = _t104*_t224;
  const double _t334 = _t138*_t224;
  const double _t335 = _t105*_t224;
  const double _t336 = 0.0063000075685370717*_hc0[1]*_t10*_t144*_t26*_t55 + 0.13368064869181335*_hc0[1]*_t144*_t17*_t18*_t47 + 0.46170103675000207*_hc0[1]*_t144*_t35*_t5 + 0.0063000075685370717*_hc0[2]*_t10*_t145*_t26*_t55 + 0.13368064869181335*_hc0[2]*_t145*_t17*_t18*_t47 + 0.46170103675000207*_hc0[2]*_t145*_t35*_t5 - _t104*_t329 - _t105*_t329 - _t144*_t332 - _t144*_t334 - _t144*_t335 - _t202 - 0.92340207350000414*_t220 - 0.22280108115302225*_t231 - 0.014700017659919834*_t242 - _t326*_t68 - 0.15390034558333402*_t327 - 0.066840324345906674*_t330 - 0.066840324345906674*_t331 - _t332*_t333 - _t333*_t334 - _t333*_t335;
  const double _t337 = _t336*_t60;
  const double _t338 = _t224*_t93;
  const double _t339 = _t224*_t43;
  const double _t340 = _t131*_t224;
  const double _t341 = 0.30787012844416725*_hc0[1]*_t10*_t11*_t144*_t24 + 0.078710075794643352*_hc0[1]*_t144*_t17*_t18*_t47 + 0.0079477574926436032*_hc0[1]*_t144*_t35*_t5 + 0.30787012844416725*_hc0[2]*_t10*_t11*_t145*_t24 + 0.078710075794643352*_hc0[2]*_t145*_t17*_t18*_t47 + 0.0079477574926436032*_hc0[2]*_t145*_t35*_t5 - _t144*_t214 - _t144*_t338 - _t144*_t339 - _t144*_t340 - _t205*_t328 - _t210 - _t214*_t333 - 0.015895514985287206*_t220 - 0.41049350459222301*_t223 - 0.13118345965773892*_t231 - _t326*_t38 - _t326*_t64 - 0.0026492524975478678*_t327 - _t329*_t43 - _t329*_t93 - 0.039355037897321675*_t330 - 0.039355037897321675*_t331 - _t333*_t338 - _t333*_t339 - _t333*_t340;
  const double _t342 = _t32*_t341;
  const double d3F_dna3 = 0.3e1*_t103 + 0.3e1*_t111 + _t155*_t71 + _t158*_t71 + _t159*_t160 + _t160*_t170 + _t169*_t2 + _t171*_t173 + _t182*_t2 + _t2*_t204 + _t2*_t212 + 0.3e1*_t83;
  const double d3F_dna2_dnb = _t103 + _t111 + _t156*_t260 + _t172*_t252 + _t172*_t253 + _t236*_t237 + _t238*_t71 + _t246*_t247 + _t248*_t72 + _t249*_t72 + _t250*_t73 + _t251*_t73 + _t258*_t259 + _t261*_t262 + _t263*_t265 + _t266 + _t83;
  const double d3F_dna_dnb2 = _t115*_t318 + _t132*_t312 + _t139*_t310 + _t139*_t316 + _t141*_t238 + _t143 + _t151 + _t154 + _t156*_t314 + _t237*_t296 + _t247*_t306 + _t259*_t313 + _t264*_t319 + _t266 + _t307*_t72 + _t308*_t72;
  const double d3F_dnb3 = _t141*_t155 + 0.3e1*_t143 + _t150*_t324 + 0.3e1*_t151 + _t153*_t316 + _t153*_t323 + 0.3e1*_t154 + _t2*_t322 + _t2*_t325 + _t2*_t337 + _t2*_t342 + _t261*_t320;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t350 = 0.0063000075685370716*_t24;
  const double _t355 = 0.46170103675000207*_t92;
  const double _t367 = _t27*_t74;
  const double _t371 = _t5*_t85;
  const double _t373 = 0.24e2*_t120;
  const double _t374 = 0.24e2*_t271;
  const double _t375 = -_t373 + _t374;
  const double _t377 = (_t87 * _t87);
  const double _t379 = (_t37 * _t37 * _t37 * _t37);
  const double _t382 = _t19*_t99;
  const double _t385 = 0.029400035319839667*_t107;
  const double _t386 = 0.12e2*_t85;
  const double _t387 = 0.12e2*_t120;
  const double _t388 = _t1*_t387;
  const double _t389 = _t386 - _t388;
  const double _t391 = _t104*_t87;
  const double _t392 = 0.6e1*_t35;
  const double _t393 = 0.6e1*na - 0.6e1*nb;
  const double _t394 = -_t392 + _t393*_t85;
  const double _t396 = 0.4e1*na - 0.4e1*nb;
  const double _t397 = -_t194 + _t396*_t85;
  const double _t398 = 0.2e1*na - 0.2e1*nb;
  const double _t399 = _t398*_t85 - _t84;
  const double _t404 = 0.18e2*_t221;
  const double _t405 = (0.220e3 / 0.81e2)*_t232;
  const double _t411 = _t87*_t93;
  const double _t413 = 0.0052985049950957355*_t92;
  const double _t415 = 0.6157402568883345*_t13;
  const double _t417 = 0.07871007579464335*_t95;
  const double _t436 = 0.0094500113528056076*_t1;
  const double _t437 = 0.40104194607544005*_t1;
  const double _t444 = 1.2312027646666722*_t5;
  const double _t445 = 0.012600015137074143*_t244;
  const double _t446 = xc_powi(_t2, -6);
  const double _t448 = _t374 - _t387;
  const double _t450 = _t121*_t5;
  const double _t453 = xc_powr(_t2, -19, 3);
  const double _t455 = -_t388 + 0.4e1*_t85;
  const double _t456 = _t189*_t216;
  const double _t458 = 0.30780069116666805*_t450;
  const double _t461 = 0.014700017659919834*_t107;
  const double _t464 = 0.13368064869181335*_t234;
  const double _t466 = _t244*_t436;
  const double _t467 = 0.0031500037842685358*_t244;
  const double _t468 = 0.014700017659919834*_t107;
  const double _t469 = _t37*_t62;
  const double _t472 = _t234*_t437;
  const double _t478 = 0.238173608111094*_t85;
  const double _t479 = 0.71452082433328201*_t85;
  const double _t480 = _t1*_t479;
  const double _t481 = 0.0052985049950957355*_t450;
  const double _t484 = 0.23613022738393005*_t234;
  const double _t485 = 0.6157402568883345*_t124;
  const double _t486 = 1.8472207706650035*_t124;
  const double _t487 = 0.07871007579464335*_t234;
  const double _t509 = 0.0042000050456913811*_t55;
  const double _t518 = 0.0049000058866399447*_t107;
  const double _t520 = _t398*_t85 + _t84;
  const double _t522 = _t145*_t88;
  const double _t525 = 0.0049000058866399445*_t107;
  const double _t531 = 0.021194019980382942*_t5;
  const double _t549 = 0.92340207350000414*_t450;
  const double _t550 = _t289*_t328;
  const double _t556 = 0.015895514985287206*_t450;
  const double _t561 = _t373 + _t374;
  const double _t563 = (_t144 * _t144);
  const double _t565 = (_t62 * _t62 * _t62 * _t62);
  const double _t568 = -_t386 - _t388;
  const double _t569 = _t144*_t333;
  const double _t572 = _t194 + _t396*_t85;
  const double _t573 = _t392 + _t393*_t85;
  const double _t343 = _t71*_t80;
  const double _t344 = _t343*_t79;
  const double _t345 = 0.12e2*_t59;
  const double _t346 = 0.8e1*_t81;
  const double _t347 = _t168*_t2;
  const double _t348 = _t161*_t71;
  const double _t349 = _t156*_t71;
  const double _t351 = 0.3e1*_t165 + 0.66666666666666667*_t54 + 0.2e1*_t56 + (0.2e1 / 0.3e1)*_t77;
  const double _t352 = _t21/xc_powi(_t31, 5);
  const double _t353 = _t352*_t58;
  const double _t354 = _t347*_t353;
  const double _t356 = (0.7e1 / 0.2e1)*_t108 + (0.9e1 / 0.2e1)*_t178 + (0.5e1 / 0.6e1)*_t179 + 0.66666666666666667*_t98;
  const double _t357 = _t167*_t2;
  const double _t358 = _t162*_t357;
  const double _t359 = _t167*_t264;
  const double _t360 = _t110*_t72;
  const double _t361 = _t172*_t181;
  const double _t362 = _t49*_t72;
  const double _t363 = _t172*_t79;
  const double _t364 = _t126*_t174;
  const double _t365 = _t126*_t196;
  const double _t366 = _t126*_t87;
  const double _t368 = -1.037037037037037*_t10*_t107*_t11 - 0.70e2 / 0.9e1*_t10*_t135*_t25*_t26 - 0.9e1*_t120*_t23*_t5 - 0.40e2 / 0.27e2*_t128*_t17*_t18*_t29;
  const double _t369 = _t58*_t72;
  const double _t370 = _t183*_t87;
  const double _t372 = _t371*_t91;
  const double _t376 = _t375*_t40;
  const double _t378 = _hc0[2]*_t377;
  const double _t380 = _hc0[4]*_t379;
  const double _t381 = _t198*_t87;
  const double _t383 = _t382*_t91;
  const double _t384 = _t375*_t45;
  const double _t390 = _hc0[2]*_t196;
  const double _t395 = _t104*_t226;
  const double _t400 = _t126*_t187;
  const double _t401 = _t390*_t87;
  const double _t402 = _t138*_t226;
  const double _t403 = _t105*_t226;
  const double _t406 = _t177*_t404 + (0.455e3 / 0.27e2)*_t243*_t28 + 1.7283950617283951*_t275 + _t30*_t405;
  const double _t407 = 0.119086804055547*_hc0[4];
  const double _t408 = _t87*_t89;
  const double _t409 = _t222*_t87;
  const double _t410 = _t91*_t98;
  const double _t412 = _t226*_t93;
  const double _t414 = _t226*_t43;
  const double _t416 = _t131*_t226;
  const double _t418 = _t20*_t405 + _t269*_t404 + (0.140e3 / 0.81e2)*_t275*_t8;
  const double _t419 = _t115*_t343;
  const double _t420 = _t260*_t80;
  const double _t421 = 0.3e1*_t59;
  const double _t422 = 0.3e1*_t163;
  const double _t423 = _t263*_t79;
  const double _t424 = 0.2e1*_t81;
  const double _t425 = 0.3e1*_t81;
  const double _t426 = _t2*_t423;
  const double _t427 = _t161*_t260;
  const double _t428 = _t258*_t82;
  const double _t429 = 0.3e1*_t261;
  const double _t430 = -_t114*_t350 + _t351 - 0.6156013823333361*_t63 - 0.2673612973836267*_t65;
  const double _t431 = 0.2e1*_t157;
  const double _t432 = _t2*_t263;
  const double _t433 = _t162*_t432;
  const double _t434 = 0.2e1*_t433;
  const double _t435 = _t263*_t264;
  const double _t438 = _t102*_t72;
  const double _t439 = 0.3e1*_t139;
  const double _t440 = _t110*_t172;
  const double _t441 = 0.2e1*_t258;
  const double _t442 = _t246*_t60;
  const double _t443 = _t236*_t32;
  const double _t447 = _t1*_t39*_t446;
  const double _t449 = _t40*_t448;
  const double _t451 = _t226*_t450;
  const double _t452 = _t448*_t45;
  const double _t454 = _t1*_t453*_t51;
  const double _t457 = _hc0[4]*_t456;
  const double _t459 = _hc0[2]*_t87;
  const double _t460 = _t1*_t44/xc_powr(_t2, 17, 3);
  const double _t462 = _hc0[2]*_t1;
  const double _t463 = _t196*_t462;
  const double _t465 = _t462*_t87;
  const double _t470 = _hc0[3]*_t469;
  const double _t471 = _t196*_t470;
  const double _t473 = _t470*_t87;
  const double _t474 = _t127*_t371;
  const double _t475 = _t127*_t382;
  const double _t476 = _t406 + 0.92340207350000414*_t474 + 0.22280108115302225*_t475;
  const double _t477 = _t205*_t469;
  const double _t482 = _hc0[1]*_t1*_t12*_t243;
  const double _t483 = _t1*_t226;
  const double _t488 = _t127*_t98;
  const double _t489 = 0.015895514985287206*_t474 + 0.13118345965773892*_t475 + 0.41049350459222301*_t488;
  const double _t490 = _t314*_t80;
  const double _t491 = 0.4e1*_t115;
  const double _t492 = _t113*_t80;
  const double _t493 = 0.2e1*_t163;
  const double _t494 = _t313*_t82;
  const double _t495 = 0.4e1*_t59;
  const double _t496 = _t139*_t66;
  const double _t497 = _t2*_t319;
  const double _t498 = _t161*_t497;
  const double _t499 = 0.2e1*_t432;
  const double _t500 = _t132*_t69;
  const double _t501 = _t139*_t81;
  const double _t502 = _t156*_t313;
  const double _t503 = _t353*_t430;
  const double _t504 = 0.2e1*_t261;
  const double _t505 = 0.012600015137074143*_hc0[1]*_t10*_t26*_t55*_t62 + 0.2673612973836267*_hc0[1]*_t17*_t18*_t47*_t62 + 0.92340207350000414*_hc0[1]*_t35*_t5*_t62 - 0.46170103675000207*_t146 - _t147*_t355 - 0.20052097303772002*_t148 - 0.20052097303772002*_t149 - _t164*_t303 - _t164*_t305 - _t356;
  const double _t506 = _t156*_t491;
  const double _t507 = _t306*_t60;
  const double _t508 = _t296*_t32;
  const double _t510 = _t221*_t39;
  const double _t511 = _t144*_t183;
  const double _t512 = _t147*_t371;
  const double _t513 = _hc0[2]*(_t1 * _t1);
  const double _t514 = _t513/xc_powi(_t2, 7);
  const double _t515 = _t19*_t513/xc_powr(_t2, 20, 3);
  const double _t516 = _t144*_t198;
  const double _t517 = _t147*_t382;
  const double _t519 = _hc0[2]*_t144;
  const double _t521 = _t292*_t399;
  const double _t523 = _hc0[4]*_t522;
  const double _t524 = _t213*_t224;
  const double _t526 = _t144*_t459;
  const double _t527 = _t121*_t470;
  const double _t528 = _t1*_t470;
  const double _t529 = _t234*_t528;
  const double _t530 = 0.238173608111094*_t224;
  const double _t532 = _t144*_t222;
  const double _t533 = _t147*_t98;
  const double _t534 = 2.858083297333128*_t272 + _t418;
  const double _t535 = 0.6e1*_t115;
  const double _t536 = _t115*_t80;
  const double _t537 = _t153*_t66;
  const double _t538 = _t150*_t69;
  const double _t539 = _t115*_t153;
  const double _t540 = _t161*_t432;
  const double _t541 = _t115*_t505;
  const double _t542 = 0.6e1*_t261;
  const double _t543 = _t172*_t313;
  const double _t544 = _t174*_t224;
  const double _t545 = _t144*_t224;
  const double _t546 = _t224*_t333;
  const double _t547 = 0.012600015137074143*_hc0[1]*_t10*_t144*_t26*_t55 + 0.2673612973836267*_hc0[1]*_t144*_t17*_t18*_t47 + 0.92340207350000414*_hc0[1]*_t144*_t35*_t5 + 0.012600015137074143*_hc0[2]*_t10*_t145*_t26*_t55 + 0.2673612973836267*_hc0[2]*_t145*_t17*_t18*_t47 + 0.92340207350000414*_hc0[2]*_t145*_t35*_t5 - _t144*_t544 - _t174*_t329 - 1.8468041470000083*_t220 - 0.4456021623060445*_t231 - 0.029400035319839667*_t242 - _t256*_t545 - _t256*_t546 - _t27*_t329*_t74 - _t326*_t51*_t74 - 0.30780069116666805*_t327 - 0.13368064869181335*_t330 - 0.13368064869181335*_t331 - _t333*_t544 - _t367*_t545 - _t367*_t546 - _t368;
  const double _t548 = 0.3e1*_t315;
  const double _t551 = _hc0[4]*_t550;
  const double _t552 = _t144*_t462;
  const double _t553 = _t104*_t470;
  const double _t554 = _t138*_t470;
  const double _t555 = _t105*_t470;
  const double _t557 = _t1*_t292;
  const double _t558 = _t470*_t93;
  const double _t559 = _t43*_t470;
  const double _t560 = _t131*_t470;
  const double _t562 = _t40*_t561;
  const double _t564 = _hc0[2]*_t563;
  const double _t566 = _hc0[4]*_t565;
  const double _t567 = _t45*_t561;
  const double _t570 = _hc0[2]*_t569;
  const double _t571 = _t104*_t292;
  const double _t574 = _t138*_t292;
  const double _t575 = _t224*_t326;
  const double _t576 = _t105*_t292;
  const double _t577 = _t292*_t93;
  const double _t578 = _t292*_t43;
  const double _t579 = _t131*_t292;
  const double d4F_dna4 = 0.6e1*_t102*_t360 + 0.3e1*_t110*_t361 + 0.8e1*_t157*_t159 + 0.6e1*_t157*_t170 + _t159*_t345 + 0.4e1*_t169 + _t170*_t345 + _t171*_t346 + 0.3e1*_t171*_t358 + 0.4e1*_t181*_t349 + 0.2e1*_t181*_t359 + 0.4e1*_t182 + 0.4e1*_t203*_t362 + 0.3e1*_t203*_t363 + 0.4e1*_t204 + 0.4e1*_t211*_t369 + 0.4e1*_t212 + _t237*(1.2770909031758049*_hc0[1]*_t10*_t107*_t11*_t37 + 0.410493504592223*_hc0[1]*_t10*_t11*_t187*_t24 + 0.063582059941148825*_hc0[1]*_t120*_t37*_t5 + 0.4664300787830717*_hc0[1]*_t128*_t17*_t18*_t37 + 0.10494676772619113*_hc0[1]*_t17*_t18*_t187*_t47 + 0.010597009990191471*_hc0[1]*_t187*_t35*_t5 + 0.410493504592223*_hc0[2]*_t10*_t11*_t196*_t24*_t37 + 0.410493504592223*_hc0[2]*_t10*_t11*_t24*_t37*_t87 + 0.10494676772619113*_hc0[2]*_t17*_t18*_t196*_t37*_t47 + 0.10494676772619113*_hc0[2]*_t17*_t18*_t37*_t47*_t87 + 0.010597009990191471*_hc0[2]*_t196*_t35*_t37*_t5 + 0.010597009990191471*_hc0[2]*_t35*_t37*_t5*_t87 + 0.410493504592223*_hc0[3]*_t10*_t11*_t189*_t24 + 0.10494676772619113*_hc0[3]*_t17*_t18*_t189*_t47 + 0.010597009990191471*_hc0[3]*_t189*_t35*_t5 - _t117*_t389 - _t131*_t378 - _t131*_t380 - _t131*_t401 - _t196*_t408 - _t206*_t389 - _t208*_t389 - _t209*_t389 - _t217*_t394 - _t217*_t397 - _t217*_t399 - 0.031791029970574413*_t370 - 0.031791029970574413*_t372 - _t375*_t38 - _t375*_t64 - 0.0026492524975478678*_t376 - _t377*_t89 - _t378*_t43 - _t378*_t93 - _t379*_t407 - _t380*_t43 - _t380*_t93 - 0.26236691931547784*_t381 - 0.26236691931547784*_t383 - 0.039355037897321675*_t384 - _t390*_t411 - _t394*_t412 - _t394*_t414 - _t394*_t416 - _t397*_t412 - _t397*_t414 - _t397*_t416 - _t399*_t412 - _t399*_t414 - _t399*_t416 - _t400*_t413 - _t400*_t415 - _t400*_t417 - 0.238173608111094*_t400 - _t401*_t43 - 0.820987009184446*_t409 - 0.820987009184446*_t410 - _t418) + _t247*(0.065333411821865927*_hc0[1]*_t10*_t135*_t26*_t37 + 0.0084000100913827623*_hc0[1]*_t10*_t187*_t26*_t55 + 3.6936082940000166*_hc0[1]*_t120*_t37*_t5 + 0.79218162187741244*_hc0[1]*_t128*_t17*_t18*_t37 + 0.1782408649224178*_hc0[1]*_t17*_t18*_t187*_t47 + 0.6156013823333361*_hc0[1]*_t187*_t35*_t5 + 0.0084000100913827623*_hc0[2]*_t10*_t196*_t26*_t37*_t55 + 0.0084000100913827623*_hc0[2]*_t10*_t26*_t37*_t55*_t87 + 0.1782408649224178*_hc0[2]*_t17*_t18*_t196*_t37*_t47 + 0.1782408649224178*_hc0[2]*_t17*_t18*_t37*_t47*_t87 + 0.6156013823333361*_hc0[2]*_t196*_t35*_t37*_t5 + 0.6156013823333361*_hc0[2]*_t35*_t37*_t5*_t87 + 0.0084000100913827623*_hc0[3]*_t10*_t189*_t26*_t55 + 0.1782408649224178*_hc0[3]*_t17*_t18*_t189*_t47 + 0.6156013823333361*_hc0[3]*_t189*_t35*_t5 - _t104*_t378 - _t104*_t380 - _t105*_t378 - _t105*_t380 - _t105*_t401 - _t138*_t378 - _t138*_t380 - _t138*_t401 - _t174*_t400 - _t175*_t385 - _t176*_t385 - _t197*_t389 - _t200*_t389 - _t201*_t389 - _t256*_t400 - _t367*_t400 - 1.8468041470000083*_t370 - 1.8468041470000083*_t372 - _t375*_t68 - 0.15390034558333402*_t376 - 0.44560216230604449*_t381 - 0.44560216230604449*_t383 - 0.066840324345906674*_t384 - _t390*_t391 - _t394*_t395 - _t394*_t402 - _t394*_t403 - _t395*_t397 - _t395*_t399 - _t397*_t402 - _t397*_t403 - _t399*_t402 - _t399*_t403 - _t406) + _t259*(0.012600015137074143*_hc0[1]*_t10*_t26*_t55*_t87 + 0.2673612973836267*_hc0[1]*_t17*_t18*_t47*_t87 + 0.92340207350000414*_hc0[1]*_t35*_t5*_t87 + 0.012600015137074143*_hc0[2]*_t10*_t26*_t55*_t88 + 0.2673612973836267*_hc0[2]*_t17*_t18*_t47*_t88 + 0.92340207350000414*_hc0[2]*_t35*_t5*_t88 - _t174*_t190 - 1.8468041470000083*_t184 - _t187*_t51*_t74 - 0.30780069116666805*_t188 - _t190*_t27*_t74 - 0.13368064869181335*_t191 - 0.13368064869181335*_t192 - 0.029400035319839667*_t193 - _t196*_t364 - 0.4456021623060445*_t199 - _t256*_t365 - _t256*_t366 - _t364*_t87 - _t365*_t367 - _t366*_t367 - _t368) + _t265*(0.012600015137074143*_hc0[1]*_t10*_t26*_t37*_t55 + 0.2673612973836267*_hc0[1]*_t17*_t18*_t37*_t47 + 0.92340207350000414*_hc0[1]*_t35*_t37*_t5 - _t164*_t175 - _t164*_t176 - _t355*_t91 - _t356 - 0.46170103675000207*_t90 - 0.20052097303772002*_t94 - 0.20052097303772002*_t96) + 0.12e2*_t344 + 0.4e1*_t347*_t348 + _t354*(-_t350*_t52 + _t351 - 0.6156013823333361*_t41 - 0.2673612973836267*_t46);
  const double d4F_dna3_dnb = 0.3e1*_t132*_t360 + _t139*_t361 + _t155*_t250 + _t155*_t251 + _t158*_t250 + _t158*_t251 + _t159*_t421 + _t159*_t429 + _t169 + _t170*_t421 + _t170*_t429 + _t171*_t424 + _t171*_t434 + _t181*_t317 + _t181*_t435 + _t182 + _t203*_t309 + _t203*_t315 + _t204 + _t211*_t311 + _t212 + 0.3e1*_t236*_t369 + _t237*(0.95781817738185368*_hc0[1]*_t10*_t107*_t11*_t37 + 0.31927272579395122*_hc0[1]*_t10*_t107*_t11*_t62 + 0.10262337614805575*_hc0[1]*_t10*_t11*_t187*_t24 + 0.30787012844416725*_hc0[1]*_t10*_t11*_t213*_t24 + 0.047686544955861619*_hc0[1]*_t120*_t37*_t5 + 0.015895514985287206*_hc0[1]*_t120*_t5*_t62 + 0.34982255908730378*_hc0[1]*_t128*_t17*_t18*_t37 + 0.11660751969576793*_hc0[1]*_t128*_t17*_t18*_t62 + 0.026236691931547784*_hc0[1]*_t17*_t18*_t187*_t47 + 0.078710075794643352*_hc0[1]*_t17*_t18*_t213*_t47 + 0.0026492524975478678*_hc0[1]*_t187*_t35*_t5 + 0.0079477574926436032*_hc0[1]*_t213*_t35*_t5 + 1.231480513776669*_hc0[2]*_t1*_t10*_t11*_t135*_t37 + 0.31484030317857341*_hc0[2]*_t1*_t17*_t18*_t232*_t37 + 0.031791029970574413*_hc0[2]*_t1*_t221*_t37*_t5 + 0.10262337614805575*_hc0[2]*_t10*_t11*_t196*_t24*_t37 + 0.10262337614805575*_hc0[2]*_t10*_t11*_t24*_t37*_t87 + 0.30787012844416725*_hc0[2]*_t10*_t11*_t24*_t62*_t87 + 0.026236691931547784*_hc0[2]*_t17*_t18*_t196*_t37*_t47 + 0.026236691931547784*_hc0[2]*_t17*_t18*_t37*_t47*_t87 + 0.078710075794643352*_hc0[2]*_t17*_t18*_t47*_t62*_t87 + 0.0026492524975478678*_hc0[2]*_t196*_t35*_t37*_t5 + 0.0026492524975478678*_hc0[2]*_t35*_t37*_t5*_t87 + 0.0079477574926436032*_hc0[2]*_t35*_t5*_t62*_t87 + 0.10262337614805575*_hc0[3]*_t10*_t11*_t189*_t24 + 0.30787012844416725*_hc0[3]*_t10*_t11*_t216*_t24*_t88 + 0.026236691931547784*_hc0[3]*_t17*_t18*_t189*_t47 + 0.078710075794643352*_hc0[3]*_t17*_t18*_t216*_t47*_t88 + 0.0026492524975478678*_hc0[3]*_t189*_t35*_t5 + 0.0079477574926436032*_hc0[3]*_t216*_t35*_t5*_t88 - _t117*_t213 - _t117*_t455 - _t131*_t457 - _t131*_t471 - _t131*_t473 - _t187*_t214 - _t187*_t338 - _t187*_t339 - _t187*_t340 - _t196*_t477 - _t206*_t213 - _t206*_t455 - _t208*_t213 - _t208*_t455 - _t209*_t213 - _t209*_t455 - _t226*_t480 - 0.015895514985287206*_t370 - 0.015895514985287206*_t372 - _t38*_t448 - 0.13118345965773892*_t381 - 0.13118345965773892*_t383 - _t390*_t481 - _t407*_t456 - 0.410493504592223*_t409 - 0.410493504592223*_t410 - _t411*_t470 - _t418 - _t43*_t457 - _t43*_t471 - _t43*_t473 - 0.031791029970574413*_t447 - _t448*_t64 - 0.0026492524975478678*_t449 - 0.015895514985287206*_t451 - 0.039355037897321675*_t452 - _t457*_t93 - _t459*_t481 - 0.26236691931547784*_t460 - _t463*_t478 - _t463*_t485 - _t463*_t487 - _t465*_t478 - _t465*_t485 - _t465*_t487 - _t471*_t93 - _t477*_t87 - 0.82098700918444602*_t482 - _t483*_t484 - _t483*_t486 - _t489) + 0.3e1*_t246*_t362 + 0.2e1*_t246*_t363 + _t247*(0.049000058866399445*_hc0[1]*_t10*_t135*_t26*_t37 + 0.016333352955466482*_hc0[1]*_t10*_t135*_t26*_t62 + 0.0021000025228456906*_hc0[1]*_t10*_t187*_t26*_t55 + 0.0063000075685370717*_hc0[1]*_t10*_t213*_t26*_t55 + 2.7702062205000124*_hc0[1]*_t120*_t37*_t5 + 0.92340207350000415*_hc0[1]*_t120*_t5*_t62 + 0.59413621640805933*_hc0[1]*_t128*_t17*_t18*_t37 + 0.19804540546935311*_hc0[1]*_t128*_t17*_t18*_t62 + 0.04456021623060445*_hc0[1]*_t17*_t18*_t187*_t47 + 0.13368064869181335*_hc0[1]*_t17*_t18*_t213*_t47 + 0.15390034558333402*_hc0[1]*_t187*_t35*_t5 + 0.46170103675000207*_hc0[1]*_t213*_t35*_t5 + 0.025200030274148287*_hc0[2]*_t1*_t10*_t243*_t26*_t37 + 0.5347225947672534*_hc0[2]*_t1*_t17*_t18*_t232*_t37 + 1.8468041470000083*_hc0[2]*_t1*_t221*_t37*_t5 + 0.0021000025228456906*_hc0[2]*_t10*_t196*_t26*_t37*_t55 + 0.0021000025228456906*_hc0[2]*_t10*_t26*_t37*_t55*_t87 + 0.0063000075685370717*_hc0[2]*_t10*_t26*_t55*_t62*_t87 + 0.04456021623060445*_hc0[2]*_t17*_t18*_t196*_t37*_t47 + 0.04456021623060445*_hc0[2]*_t17*_t18*_t37*_t47*_t87 + 0.13368064869181335*_hc0[2]*_t17*_t18*_t47*_t62*_t87 + 0.15390034558333402*_hc0[2]*_t196*_t35*_t37*_t5 + 0.15390034558333402*_hc0[2]*_t35*_t37*_t5*_t87 + 0.46170103675000207*_hc0[2]*_t35*_t5*_t62*_t87 + 0.0021000025228456906*_hc0[3]*_t10*_t189*_t26*_t55 + 0.0063000075685370717*_hc0[3]*_t10*_t216*_t26*_t55*_t88 + 0.04456021623060445*_hc0[3]*_t17*_t18*_t189*_t47 + 0.13368064869181335*_hc0[3]*_t17*_t18*_t216*_t47*_t88 + 0.15390034558333402*_hc0[3]*_t189*_t35*_t5 + 0.46170103675000207*_hc0[3]*_t216*_t35*_t5*_t88 - _t104*_t457 - _t104*_t471 - _t105*_t457 - _t105*_t471 - _t105*_t473 - _t138*_t457 - _t138*_t471 - _t138*_t473 - _t175*_t461 - _t176*_t461 - _t187*_t332 - _t187*_t334 - _t187*_t335 - _t197*_t213 - _t197*_t455 - _t200*_t213 - _t200*_t455 - _t201*_t213 - _t201*_t455 - _t226*_t466 - _t226*_t472 - _t257*_t468 - 0.92340207350000414*_t370 - 0.92340207350000414*_t372 - 0.22280108115302225*_t381 - 0.22280108115302225*_t383 - _t390*_t458 - _t391*_t470 - 1.8468041470000083*_t447 - _t448*_t68 - 0.15390034558333402*_t449 - 0.92340207350000414*_t451 - 0.066840324345906674*_t452 - 0.029400035319839667*_t454 - _t458*_t459 - 0.4456021623060445*_t460 - _t463*_t464 - _t463*_t467 - _t464*_t465 - _t465*_t467 - _t476) + _t248*_t421 + _t248*_t431 + _t249*_t421 + _t252*_t358 + _t252*_t425 + _t253*_t425 + 0.3e1*_t258*_t349 + _t258*_t359 + _t259*(0.016800020182765525*_hc0[1]*_t1*_t10*_t243*_t26 + 0.3564817298448356*_hc0[1]*_t1*_t17*_t18*_t232 + 1.2312027646666722*_hc0[1]*_t1*_t221*_t5 + 0.0042000050456913812*_hc0[1]*_t10*_t26*_t55*_t87 + 0.0891204324612089*_hc0[1]*_t17*_t18*_t47*_t87 + 0.30780069116666805*_hc0[1]*_t35*_t5*_t87 + 0.0084000100913827623*_hc0[2]*_t10*_t26*_t37*_t55*_t62 + 0.0042000050456913812*_hc0[2]*_t10*_t26*_t55*_t88 + 0.1782408649224178*_hc0[2]*_t17*_t18*_t37*_t47*_t62 + 0.0891204324612089*_hc0[2]*_t17*_t18*_t47*_t88 + 0.6156013823333361*_hc0[2]*_t35*_t37*_t5*_t62 + 0.30780069116666805*_hc0[2]*_t35*_t5*_t88 - _t1*_t126*_t445 - 0.5347225947672534*_t1*_t235 - _t174*_t225 - _t174*_t227 - 1.2312027646666722*_t184 - 0.019600023546559779*_t193 - 0.29706810820402967*_t199 - _t213*_t51*_t74 - 0.30780069116666805*_t219 - _t225*_t256 - _t225*_t367 - _t227*_t256 - _t227*_t367 - _t228*_t444 - 0.13368064869181335*_t230 - _t300 - _t301 - _t304 - _t368) + _t265*(0.0063000075685370717*_hc0[1]*_t10*_t26*_t37*_t55 + 0.0063000075685370716*_hc0[1]*_t10*_t26*_t55*_t62 + 0.13368064869181335*_hc0[1]*_t17*_t18*_t37*_t47 + 0.13368064869181335*_hc0[1]*_t17*_t18*_t47*_t62 + 0.46170103675000207*_hc0[1]*_t35*_t37*_t5 + 0.46170103675000208*_hc0[1]*_t35*_t5*_t62 - 0.92340207350000414*_t123 - _t127*_t355 - 0.20052097303772002*_t127*_t95 - _t129*_t437 - _t136*_t436 - _t164*_t257 - _t356) + 0.3e1*_t344 + 0.3e1*_t348*_t426 + _t354*_t430 + _t357*_t427 + 0.6e1*_t419 + 0.3e1*_t420 + _t422*_t423 + 0.3e1*_t428 + _t438*_t439 + _t440*_t441 + 0.3e1*_t442 + 0.3e1*_t443;
  const double d4F_dna2_dnb2 = 0.4e1*_t132*_t139*_t72 + _t139*_t173*_t258 + _t150*_t360 + _t153*_t438 + _t157*_t308 + _t236*_t312 + _t237*(0.63854545158790245*_hc0[1]*_t10*_t107*_t11*_t37 + 0.63854545158790245*_hc0[1]*_t10*_t107*_t11*_t62 + 0.2052467522961115*_hc0[1]*_t10*_t11*_t213*_t24 + 0.031791029970574413*_hc0[1]*_t120*_t37*_t5 + 0.031791029970574413*_hc0[1]*_t120*_t5*_t62 + 0.23321503939153585*_hc0[1]*_t128*_t17*_t18*_t37 + 0.23321503939153585*_hc0[1]*_t128*_t17*_t18*_t62 + 0.052473383863095567*_hc0[1]*_t17*_t18*_t213*_t47 + 0.0052985049950957355*_hc0[1]*_t213*_t35*_t5 + 4.515428550514453*_hc0[2]*_t1*_t10*_t11*_t135*_t37 + 0.820987009184446*_hc0[2]*_t1*_t10*_t11*_t135*_t62 + 1.429041648666564*_hc0[2]*_t1*_t120*_t37 + 0.68215399022024237*_hc0[2]*_t1*_t17*_t18*_t232*_t37 + 0.20989353545238227*_hc0[2]*_t1*_t17*_t18*_t232*_t62 + 0.052985049950957356*_hc0[2]*_t1*_t221*_t37*_t5 + 0.021194019980382942*_hc0[2]*_t1*_t221*_t5*_t62 + 1.231480513776669*_hc0[2]*_t10*_t107*_t11*_t37 + 0.2052467522961115*_hc0[2]*_t10*_t11*_t144*_t24*_t37 + 0.2052467522961115*_hc0[2]*_t10*_t11*_t24*_t62*_t87 + 0.010597009990191471*_hc0[2]*_t120*_t37*_t5 + 0.1574201515892867*_hc0[2]*_t128*_t17*_t18*_t37 + 0.052473383863095567*_hc0[2]*_t144*_t17*_t18*_t37*_t47 + 0.0052985049950957355*_hc0[2]*_t144*_t35*_t37*_t5 + 0.052473383863095567*_hc0[2]*_t17*_t18*_t47*_t62*_t87 + 0.0052985049950957355*_hc0[2]*_t35*_t5*_t62*_t87 + 0.47634721622218801*_hc0[2]*_t37*_t85 + 0.2052467522961115*_hc0[3]*_t10*_t11*_t145*_t24*_t289 + 0.2052467522961115*_hc0[3]*_t10*_t11*_t216*_t24*_t88 + 0.052473383863095567*_hc0[3]*_t145*_t17*_t18*_t289*_t47 + 0.0052985049950957355*_hc0[3]*_t145*_t289*_t35*_t5 + 0.052473383863095567*_hc0[3]*_t17*_t18*_t216*_t47*_t88 + 0.0052985049950957355*_hc0[3]*_t216*_t35*_t5*_t88 - 2.462961027553338*_t12*_t453*_t513 - 2.462961027553338*_t124*_t528 - _t131*_t521 - _t131*_t523 - _t131*_t526 - _t144*_t408 - _t213*_t530 - _t217*_t520 - 0.410493504592223*_t276 - 0.10494676772619113*_t277 - _t290*_t399 - 0.0052985049950957355*_t370 - 0.0052985049950957355*_t372 - 0.043727819885912973*_t381 - 0.043727819885912973*_t383 - _t407*_t522 - 0.13683116819740767*_t409 - 0.13683116819740767*_t410 - _t411*_t519 - _t412*_t520 - _t413*_t524 - _t414*_t520 - _t415*_t524 - _t416*_t520 - _t417*_t524 - _t43*_t521 - _t43*_t523 - _t43*_t526 - 0.95269443244437602*_t446*_t513 - 0.13776112987248912*_t447 - 1.6091837718015974*_t460 - 0.021194019980382942*_t474 - 0.17491127954365189*_t475 - 9.7150129420159443*_t482 - 0.54732467278963068*_t488 - 0.010597009990191471*_t510 - 0.0052985049950957355*_t511 - 0.0052985049950957355*_t512 - _t514*_t531 - 0.3148403031785734*_t515 - 0.043727819885912972*_t516 - 0.043727819885912972*_t517 - _t521*_t93 - _t523*_t93 - _t527*_t531 - 0.95269443244437602*_t528*_t85 - 0.3148403031785734*_t529 - 0.13683116819740767*_t532 - 0.13683116819740767*_t533 - _t534) + _t238*_t248 + _t238*_t249 + _t238*_t307 + _t238*_t308 + _t246*_t310 + _t246*_t316 + _t247*(0.032666705910932964*_hc0[1]*_t10*_t135*_t26*_t37 + 0.032666705910932963*_hc0[1]*_t10*_t135*_t26*_t62 + 0.0042000050456913812*_hc0[1]*_t10*_t213*_t26*_t55 + 1.8468041470000083*_hc0[1]*_t120*_t37*_t5 + 1.8468041470000083*_hc0[1]*_t120*_t5*_t62 + 0.39609081093870623*_hc0[1]*_t128*_t17*_t18*_t37 + 0.39609081093870623*_hc0[1]*_t128*_t17*_t18*_t62 + 0.0891204324612089*_hc0[1]*_t17*_t18*_t213*_t47 + 0.30780069116666805*_hc0[1]*_t213*_t35*_t5 + 0.03570004288837674*_hc0[2]*_t1*_t10*_t243*_t26*_t37 + 0.016800020182765525*_hc0[2]*_t1*_t10*_t243*_t26*_t62 + 1.1585656219957157*_hc0[2]*_t1*_t17*_t18*_t232*_t37 + 0.3564817298448356*_hc0[2]*_t1*_t17*_t18*_t232*_t62 + 3.0780069116666805*_hc0[2]*_t1*_t221*_t37*_t5 + 1.2312027646666722*_hc0[2]*_t1*_t221*_t5*_t62 + 0.0063000075685370716*_hc0[2]*_t10*_t135*_t26*_t37 + 0.0042000050456913812*_hc0[2]*_t10*_t144*_t26*_t37*_t55 + 0.0042000050456913812*_hc0[2]*_t10*_t26*_t55*_t62*_t87 + 0.6156013823333361*_hc0[2]*_t120*_t37*_t5 + 0.2673612973836267*_hc0[2]*_t128*_t17*_t18*_t37 + 0.0891204324612089*_hc0[2]*_t144*_t17*_t18*_t37*_t47 + 0.30780069116666805*_hc0[2]*_t144*_t35*_t37*_t5 + 0.0891204324612089*_hc0[2]*_t17*_t18*_t47*_t62*_t87 + 0.30780069116666805*_hc0[2]*_t35*_t5*_t62*_t87 + 0.0042000050456913812*_hc0[3]*_t10*_t145*_t26*_t289*_t55 + 0.0042000050456913812*_hc0[3]*_t10*_t216*_t26*_t55*_t88 + 0.0891204324612089*_hc0[3]*_t145*_t17*_t18*_t289*_t47 + 0.30780069116666805*_hc0[3]*_t145*_t289*_t35*_t5 + 0.0891204324612089*_hc0[3]*_t17*_t18*_t216*_t47*_t88 + 0.30780069116666805*_hc0[3]*_t216*_t35*_t5*_t88 - _t104*_t521 - _t104*_t523 - _t105*_t521 - _t105*_t523 - _t105*_t526 - 0.019600023546559779*_t107*_t257 - _t138*_t521 - _t138*_t523 - _t138*_t526 - _t174*_t524 - _t175*_t518 - _t176*_t518 - _t256*_t524 - 0.1782408649224178*_t277 - 0.0084000100913827623*_t298 - _t303*_t525 - _t305*_t525 - _t367*_t524 - 0.30780069116666805*_t370 - 0.30780069116666805*_t372 - 0.074267027051007416*_t381 - 0.074267027051007416*_t383 - _t391*_t519 - _t395*_t520 - _t402*_t520 - _t403*_t520 - _t406 - _t444*_t514 - _t444*_t527 - _t445*_t528 - 8.0028179703333693*_t447 - 0.10220012277849027*_t454 - 2.7330265954770729*_t460 - 1.2312027646666722*_t474 - 0.29706810820402967*_t475 - 0.6156013823333361*_t510 - 0.30780069116666805*_t511 - 0.30780069116666805*_t512 - 0.5347225947672534*_t515 - 0.074267027051007416*_t516 - 0.074267027051007416*_t517 - 0.5347225947672534*_t529 - 0.012600015137074143*_t27*_t513/xc_powr(_t2, 22, 3)) + _t248*_t504 + _t249*_t261 + _t250*_t495 + _t250*_t506 + _t251*_t495 + _t251*_t506 + _t252*_t424 + _t252*_t434 + _t253*_t424 + _t253*_t433 + _t258*_t318 + _t259*(0.9e1*_t120*_t177 + 1.037037037037037*_t124 + 0.6156013823333361*_t126*_t280*_t62 + (0.40e2 / 0.27e2)*_t128*_t30 - _t144*_t364 - _t174*_t293 - 1.2312027646666722*_t220 - 0.29706810820402967*_t231 - _t239 - _t240 - _t241 - 0.019600023546559778*_t242 + _t254 + _t255 - _t256*_t293 - _t256*_t294 + 0.0084000100913827623*_t257*_t55 + 0.6156013823333361*_t268 + 3.0780069116666805*_t273 + 1.1585656219957157*_t278 + 0.30780069116666805*_t279 + 0.30780069116666805*_t281 - _t282*_t445 + 0.0891204324612089*_t283 + 0.0891204324612089*_t285 - _t286*_t444 - 0.5347225947672534*_t288 - _t293*_t367 - _t294*_t367 + 0.1782408649224178*_t295 + (0.70e2 / 0.9e1)*_t297 + 0.03570004288837674*_t299 + _t303*_t509 + _t305*_t509) + _t262*_t498 + _t262*_t502 + _t265*_t505 + 0.2e1*_t296*_t369 + 0.2e1*_t306*_t362 + _t306*_t363 + _t313*_t440 + _t319*_t493 + 0.4e1*_t419 + 0.2e1*_t420 + _t423*_t493 + _t426*_t503 + _t427*_t499 + 0.2e1*_t428 + _t431*_t496 + _t435*_t441 + 0.2e1*_t442 + 0.2e1*_t443 + 0.2e1*_t490 + _t491*_t492 + _t491*_t501 + 0.2e1*_t494 + _t495*_t496 + _t495*_t500 + 0.2e1*_t507 + 0.2e1*_t508;
  const double d4F_dna_dnb3 = _t112*_t502 + 0.3e1*_t113*_t498 + _t132*_t153*_t160 + _t139*_t150*_t160 + _t155*_t496 + _t155*_t500 + _t162*_t439*_t497 + _t237*(0.31927272579395122*_hc0[1]*_t10*_t107*_t11*_t37 + 0.95781817738185368*_hc0[1]*_t10*_t107*_t11*_t62 + 0.10262337614805575*_hc0[1]*_t10*_t11*_t24*_t326 + 0.015895514985287206*_hc0[1]*_t120*_t37*_t5 + 0.047686544955861619*_hc0[1]*_t120*_t5*_t62 + 0.11660751969576793*_hc0[1]*_t128*_t17*_t18*_t37 + 0.34982255908730378*_hc0[1]*_t128*_t17*_t18*_t62 + 0.026236691931547784*_hc0[1]*_t17*_t18*_t326*_t47 + 0.0026492524975478678*_hc0[1]*_t326*_t35*_t5 + 6.7731428257716795*_hc0[2]*_t1*_t10*_t11*_t135*_t62 + 2.1435624729998461*_hc0[2]*_t1*_t120*_t62 + 1.0232309853303636*_hc0[2]*_t1*_t17*_t18*_t232*_t62 + 0.079477574926436033*_hc0[2]*_t1*_t221*_t5*_t62 + 1.8472207706650035*_hc0[2]*_t10*_t107*_t11*_t62 + 0.30787012844416725*_hc0[2]*_t10*_t11*_t144*_t24*_t37 + 0.10262337614805575*_hc0[2]*_t10*_t11*_t144*_t24*_t62 + 0.10262337614805575*_hc0[2]*_t10*_t11*_t24*_t333*_t62 + 0.015895514985287206*_hc0[2]*_t120*_t5*_t62 + 0.23613022738393005*_hc0[2]*_t128*_t17*_t18*_t62 + 0.078710075794643352*_hc0[2]*_t144*_t17*_t18*_t37*_t47 + 0.026236691931547784*_hc0[2]*_t144*_t17*_t18*_t47*_t62 + 0.0079477574926436032*_hc0[2]*_t144*_t35*_t37*_t5 + 0.0026492524975478678*_hc0[2]*_t144*_t35*_t5*_t62 + 0.026236691931547784*_hc0[2]*_t17*_t18*_t333*_t47*_t62 + 0.0026492524975478678*_hc0[2]*_t333*_t35*_t5*_t62 + 0.71452082433328201*_hc0[2]*_t62*_t85 + 0.30787012844416725*_hc0[3]*_t10*_t11*_t145*_t24*_t289 + 0.10262337614805575*_hc0[3]*_t10*_t11*_t24*_t328 + 0.078710075794643352*_hc0[3]*_t145*_t17*_t18*_t289*_t47 + 0.0079477574926436032*_hc0[3]*_t145*_t289*_t35*_t5 + 0.026236691931547784*_hc0[3]*_t17*_t18*_t328*_t47 + 0.0026492524975478678*_hc0[3]*_t328*_t35*_t5 - _t117*_t326 - _t131*_t551 - _t144*_t477 - _t144*_t558 - _t144*_t559 - _t144*_t560 - _t206*_t326 - _t208*_t326 - _t209*_t326 - 1.429041648666564*_t267 - 4.3101817982183415*_t276 - 0.6296806063571468*_t277 - _t292*_t480 - _t292*_t556 - _t333*_t477 - _t333*_t558 - _t333*_t559 - _t333*_t560 - _t407*_t550 - _t43*_t551 - 0.14305963486758486*_t447 - 1.6791482836190581*_t460 - _t479*_t552 - 10.057090862509464*_t482 - _t484*_t552 - _t484*_t557 - _t486*_t552 - _t486*_t557 - _t489 - 0.04768654495586162*_t510 - 0.015895514985287206*_t511 - 0.015895514985287206*_t512 - 0.13118345965773892*_t516 - 0.13118345965773892*_t517 - _t519*_t556 - 0.41049350459222301*_t532 - 0.41049350459222301*_t533 - _t534 - _t551*_t93) + _t247*(0.016333352955466482*_hc0[1]*_t10*_t135*_t26*_t37 + 0.049000058866399445*_hc0[1]*_t10*_t135*_t26*_t62 + 0.0021000025228456905*_hc0[1]*_t10*_t26*_t326*_t55 + 0.92340207350000414*_hc0[1]*_t120*_t37*_t5 + 2.7702062205000124*_hc0[1]*_t120*_t5*_t62 + 0.19804540546935311*_hc0[1]*_t128*_t17*_t18*_t37 + 0.59413621640805933*_hc0[1]*_t128*_t17*_t18*_t62 + 0.04456021623060445*_hc0[1]*_t17*_t18*_t326*_t47 + 0.15390034558333402*_hc0[1]*_t326*_t35*_t5 + 0.05355006433256511*_hc0[2]*_t1*_t10*_t243*_t26*_t62 + 1.7378484329935736*_hc0[2]*_t1*_t17*_t18*_t232*_t62 + 4.6170103675000207*_hc0[2]*_t1*_t221*_t5*_t62 + 0.0094500113528056076*_hc0[2]*_t10*_t135*_t26*_t62 + 0.0063000075685370717*_hc0[2]*_t10*_t144*_t26*_t37*_t55 + 0.0021000025228456905*_hc0[2]*_t10*_t144*_t26*_t55*_t62 + 0.0021000025228456905*_hc0[2]*_t10*_t26*_t333*_t55*_t62 + 0.92340207350000414*_hc0[2]*_t120*_t5*_t62 + 0.40104194607544005*_hc0[2]*_t128*_t17*_t18*_t62 + 0.13368064869181335*_hc0[2]*_t144*_t17*_t18*_t37*_t47 + 0.04456021623060445*_hc0[2]*_t144*_t17*_t18*_t47*_t62 + 0.46170103675000207*_hc0[2]*_t144*_t35*_t37*_t5 + 0.15390034558333402*_hc0[2]*_t144*_t35*_t5*_t62 + 0.04456021623060445*_hc0[2]*_t17*_t18*_t333*_t47*_t62 + 0.15390034558333402*_hc0[2]*_t333*_t35*_t5*_t62 + 0.0063000075685370717*_hc0[3]*_t10*_t145*_t26*_t289*_t55 + 0.0021000025228456905*_hc0[3]*_t10*_t26*_t328*_t55 + 0.13368064869181335*_hc0[3]*_t145*_t17*_t18*_t289*_t47 + 0.46170103675000207*_hc0[3]*_t145*_t289*_t35*_t5 + 0.04456021623060445*_hc0[3]*_t17*_t18*_t328*_t47 + 0.15390034558333402*_hc0[3]*_t328*_t35*_t5 - _t104*_t551 - _t105*_t551 - _t138*_t551 - _t144*_t553 - _t144*_t554 - _t144*_t555 - _t197*_t326 - _t200*_t326 - _t201*_t326 - 0.40104194607544005*_t234*_t552 - 0.0094500113528056076*_t244*_t552 - _t257*_t461 - 1.0694451895345068*_t277 - _t292*_t466 - _t292*_t472 - _t292*_t549 - 0.031500037842685359*_t298 - _t303*_t468 - _t305*_t468 - _t333*_t553 - _t333*_t554 - _t333*_t555 - 8.3106186615000375*_t447 - 0.10500012614228453*_t454 - 2.8518538387586848*_t460 - _t476 - 2.7702062205000124*_t510 - 0.92340207350000414*_t511 - 0.92340207350000414*_t512 - 0.22280108115302225*_t516 - 0.22280108115302225*_t517 - _t519*_t549) + _t259*_t547 + _t264*_t541 + _t296*_t324 + _t306*_t323 + _t306*_t548 + _t307*_t421 + _t307*_t504 + _t308*_t421 + _t308*_t429 + 0.3e1*_t313*_t317 + 0.2e1*_t313*_t435 + _t314*_t540 + _t319*_t422 + _t320*_t536 + _t322 + _t325 + _t336*_t362 + _t337 + _t341*_t369 + _t342 + _t421*_t537 + _t421*_t538 + _t424*_t539 + _t429*_t500 + _t439*_t543 + 0.3e1*_t490 + _t492*_t535 + 0.3e1*_t494 + _t496*_t542 + _t497*_t503 + _t501*_t535 + 0.3e1*_t507 + 0.3e1*_t508;
  const double d4F_dnb4 = _t141*_t491*_t540 + 0.4e1*_t141*_t502 + 0.12e2*_t141*_t536 + _t142*_t2*_t547 + 0.6e1*_t150*_t153*_t72 + 0.3e1*_t153*_t543 + _t2*_t321*_t541 + _t237*(1.2770909031758049*_hc0[1]*_t10*_t107*_t11*_t62 + 0.410493504592223*_hc0[1]*_t10*_t11*_t24*_t326 + 0.063582059941148825*_hc0[1]*_t120*_t5*_t62 + 0.4664300787830717*_hc0[1]*_t128*_t17*_t18*_t62 + 0.10494676772619113*_hc0[1]*_t17*_t18*_t326*_t47 + 0.010597009990191471*_hc0[1]*_t326*_t35*_t5 + 0.410493504592223*_hc0[2]*_t10*_t11*_t144*_t24*_t62 + 0.410493504592223*_hc0[2]*_t10*_t11*_t24*_t333*_t62 + 0.10494676772619113*_hc0[2]*_t144*_t17*_t18*_t47*_t62 + 0.010597009990191471*_hc0[2]*_t144*_t35*_t5*_t62 + 0.10494676772619113*_hc0[2]*_t17*_t18*_t333*_t47*_t62 + 0.010597009990191471*_hc0[2]*_t333*_t35*_t5*_t62 + 0.410493504592223*_hc0[3]*_t10*_t11*_t24*_t328 + 0.10494676772619113*_hc0[3]*_t17*_t18*_t328*_t47 + 0.010597009990191471*_hc0[3]*_t328*_t35*_t5 - _t131*_t564 - _t131*_t566 - _t131*_t570 - _t214*_t568 - _t290*_t520 - _t290*_t572 - _t290*_t573 - _t326*_t530 - _t338*_t568 - _t339*_t568 - _t340*_t568 - _t38*_t561 - _t407*_t565 - _t413*_t575 - _t415*_t575 - _t417*_t575 - _t418 - _t43*_t564 - _t43*_t566 - _t43*_t570 - 0.031791029970574413*_t511 - 0.031791029970574413*_t512 - 0.26236691931547784*_t516 - 0.26236691931547784*_t517 - _t520*_t577 - _t520*_t578 - _t520*_t579 - 0.820987009184446*_t532 - 0.820987009184446*_t533 - _t561*_t64 - 0.0026492524975478678*_t562 - _t563*_t89 - _t564*_t93 - _t566*_t93 - 0.039355037897321675*_t567 - _t569*_t89 - _t570*_t93 - _t572*_t577 - _t572*_t578 - _t572*_t579 - _t573*_t577 - _t573*_t578 - _t573*_t579) + _t247*(0.065333411821865927*_hc0[1]*_t10*_t135*_t26*_t62 + 0.0084000100913827623*_hc0[1]*_t10*_t26*_t326*_t55 + 3.6936082940000166*_hc0[1]*_t120*_t5*_t62 + 0.79218162187741244*_hc0[1]*_t128*_t17*_t18*_t62 + 0.1782408649224178*_hc0[1]*_t17*_t18*_t326*_t47 + 0.6156013823333361*_hc0[1]*_t326*_t35*_t5 + 0.0084000100913827623*_hc0[2]*_t10*_t144*_t26*_t55*_t62 + 0.0084000100913827623*_hc0[2]*_t10*_t26*_t333*_t55*_t62 + 0.1782408649224178*_hc0[2]*_t144*_t17*_t18*_t47*_t62 + 0.6156013823333361*_hc0[2]*_t144*_t35*_t5*_t62 + 0.1782408649224178*_hc0[2]*_t17*_t18*_t333*_t47*_t62 + 0.6156013823333361*_hc0[2]*_t333*_t35*_t5*_t62 + 0.0084000100913827623*_hc0[3]*_t10*_t26*_t328*_t55 + 0.1782408649224178*_hc0[3]*_t17*_t18*_t328*_t47 + 0.6156013823333361*_hc0[3]*_t328*_t35*_t5 - _t104*_t564 - _t104*_t566 - _t104*_t570 - _t105*_t564 - _t105*_t566 - _t105*_t570 - _t138*_t564 - _t138*_t566 - _t138*_t570 - _t256*_t575 - _t303*_t385 - _t305*_t385 - _t326*_t544 - _t332*_t568 - _t334*_t568 - _t335*_t568 - _t367*_t575 - _t406 - 1.8468041470000083*_t511 - 1.8468041470000083*_t512 - 0.44560216230604449*_t516 - 0.44560216230604449*_t517 - _t520*_t571 - _t520*_t574 - _t520*_t576 - _t561*_t68 - 0.15390034558333402*_t562 - 0.066840324345906674*_t567 - _t571*_t572 - _t571*_t573 - _t572*_t574 - _t572*_t576 - _t573*_t574 - _t573*_t576) + 0.8e1*_t261*_t537 + _t263*_t321*_t491 + 0.4e1*_t309*_t336 + 0.4e1*_t311*_t341 + _t313*_t321*_t499 + 0.4e1*_t325 + _t336*_t548 + 0.4e1*_t337 + 0.4e1*_t342 + _t345*_t537 + _t345*_t538 + _t346*_t539 + _t352*_t430*_t497*_t69 + 0.3e1*_t433*_t539 + _t538*_t542;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif