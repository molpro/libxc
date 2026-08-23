/*
  Generated from python/mgga_vxc/mgga_x_2d_prp10.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_2d_prp10
*/

#ifndef _MGGA_X_2D_PRP10_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_2D_PRP10_KERNEL_BODY
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_2D_PRP10_HELPER_BODIES
#include "mgga_x_2d_prp10.c"
#undef _MGGA_X_2D_PRP10_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_2D_PRP10_HELPER_BODIES
#include "mgga_x_2d_prp10.c"
#undef _MGGA_X_2D_PRP10_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_2D_PRP10_HELPER_BODIES
#include "mgga_x_2d_prp10.c"
#undef _MGGA_X_2D_PRP10_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_2D_PRP10_HELPER_BODIES
#include "mgga_x_2d_prp10.c"
#undef _MGGA_X_2D_PRP10_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_2d_prp10.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_2d_prp10.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_2d_prp10.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_2d_prp10.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_2d_prp10.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_2d_prp10.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_2d_prp10.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_2d_prp10.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_2D_PRP10_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(prhg07_C_k, _KMAX)(const xc_func_type *p, double x, double u, double t, double *out) {


  const double f = -t + (0.1e1 / 0.4e1)*u + (0.1e1 / 0.8e1)*(x * x);
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -0.1e1;
  out[1] = df_dt;
  const double df_du = 0.1e1 / 0.4e1;
  out[2] = df_du;
  const double df_dx = (0.1e1 / 0.4e1)*x;
  out[3] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dx_dt = 0;
  out[7] = d2f_dx_dt;
  const double d2f_dx_du = 0;
  out[8] = d2f_dx_du;
  const double d2f_dx2 = 0.1e1 / 0.4e1;
  out[9] = d2f_dx2;
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
  const double d3f_dx_dt2 = 0;
  out[14] = d3f_dx_dt2;
  const double d3f_dx_du_dt = 0;
  out[15] = d3f_dx_du_dt;
  const double d3f_dx_du2 = 0;
  out[16] = d3f_dx_du2;
  const double d3f_dx2_dt = 0;
  out[17] = d3f_dx2_dt;
  const double d3f_dx2_du = 0;
  out[18] = d3f_dx2_du;
  const double d3f_dx3 = 0;
  out[19] = d3f_dx3;
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
  const double d4f_dx_dt3 = 0;
  out[25] = d4f_dx_dt3;
  const double d4f_dx_du_dt2 = 0;
  out[26] = d4f_dx_du_dt2;
  const double d4f_dx_du2_dt = 0;
  out[27] = d4f_dx_du2_dt;
  const double d4f_dx_du3 = 0;
  out[28] = d4f_dx_du3;
  const double d4f_dx2_dt2 = 0;
  out[29] = d4f_dx2_dt2;
  const double d4f_dx2_du_dt = 0;
  out[30] = d4f_dx2_du_dt;
  const double d4f_dx2_du2 = 0;
  out[31] = d4f_dx2_du2;
  const double d4f_dx3_dt = 0;
  out[32] = d4f_dx3_dt;
  const double d4f_dx3_du = 0;
  out[33] = d4f_dx3_du;
  const double d4f_dx4 = 0;
  out[34] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(prhg07_y_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = exp(-0.1e1);
  const double _t2 = (0.1e1 / M_PI);
  const double _t3 = _t2*x;
  const double _t4 = _t3 > -0.99999999989999999;
  const double _t5 = _t1*my_piecewise3(_t4, _t3, -0.99999999989999999);
#if _KMAX >= 1
  const double _t6 = my_piecewise3(_t4, _t2, 0);
#endif

  const double f = LambertW(_t5) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t1*_t6*xc_lambertw_d1(_t5);
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = (_t6 * _t6)*xc_lambertw_d2(_t5)*exp(-0.2e1);
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = (_t6 * _t6 * _t6)*xc_lambertw_d3(_t5)*exp(-0.3e1);
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = (_t6 * _t6 * _t6 * _t6)*xc_lambertw_d4(_t5)*exp(-0.4e1);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(prhg07_v_k, _KMAX)(const xc_func_type *p, double y, double *out) {

  const double _t1 = xc_powr(M_PI, 3, 2);
  const double _t2 = (0.1e1 / 0.2e1)*y;
  const double _t3 = xc_bessel_I0(_t2);
#if _KMAX >= 1
  const double _t4 = xc_bessel_I1(_t2);
  const double _t5 = (0.3e1 / 0.16e2)*_t1;
#endif
#if _KMAX >= 2
  const double _t6 = (0.1e1 / y);
  const double _t7 = _t4*_t6;
  const double _t8 = (0.1e1 / 0.2e1)*_t3 - _t7;
#endif
#if _KMAX >= 3
  const double _t9 = (0.1e1 / (y * y));
  const double _t10 = _t4*_t9 + (0.1e1 / 0.4e1)*_t4 - _t6*_t8;
#endif

  const double f = (0.3e1 / 0.8e1)*_t1*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dy = _t4*_t5;
  out[1] = df_dy;
#endif
#if _KMAX >= 2
  const double d2f_dy2 = _t5*_t8;
  out[2] = d2f_dy2;
#endif
#if _KMAX >= 3
  const double d3f_dy3 = _t10*_t5;
  out[3] = d3f_dy3;
#endif
#if _KMAX >= 4
  const double d4f_dy4 = _t5*(-_t10*_t6 + (0.1e1 / 0.8e1)*_t3 - 0.2e1*_t4/(y * y * y) - 0.1e1 / 0.4e1*_t7 + 0.2e1*_t8*_t9);
  out[4] = d4f_dy4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double la = lapl[0];
  const double ta = tau[0];

  const double _t1 = xc_powr(gaa, 1, 2);
  const double _t2 = xc_powr(0.2e1, 1, 2);
  const double _t3 = xc_powr(na, -3, 2);
  const double _t4 = _t2*_t3;
  const double _t5 = _t1*_t4;
  const double _t6 = (0.1e1 / (na * na));
  const double _t7 = 0.2e1*_t6;
  const double _t8 = xc_powr(M_PI, -1, 2);
  const double _t9 = (0.8e1 / 0.3e1)*_t8;
  const double _t10 = (0.1e1 / M_PI);
  const double _t11 = xc_powr(XC_EPSILON, 2, 3);
  const double _t12 = (na * na * na);
  const double _t13 = (0.1e1 / _t12);
  const double _t14 = (0.1e1 / 0.4e1)*_t13;
  const double _t15 = _t14*(-0.4e1*_t11*_t12 - gaa + 0.8e1*na*ta) > 0;
  const double _t16 = my_piecewise3(_t15, -_t14*gaa + 0.2e1*_t6*ta, _t11);
  const double _t17 = xc_powr(_t16, 1, 2);
  const double _t20 = xc_powr(na, 1, 2);
  const double _t21 = (0.1e1 / 0.2e1)*_t20;
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(prhg07_C_k, _KMAX)(p, _t5, _t7*la, _t7*ta, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(prhg07_y_k, _KMAX)(p, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(prhg07_v_k, _KMAX)(p, _hc1[0], _hc2);
  const double _t18 = -_hc2[0]*_t9 + (0.4e1 / 0.3e1)*_t10*_t17;
  const double _t19 = _t18*_t2;
  const double vrho_0 = _t19*_t21;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += vrho_0;
#if _KMAX >= 2
  const double _t22 = (0.1e1 / _t20);
  const double _t23 = (0.1e1 / 0.4e1)*_t22;
  const double _t25 = 0.4e1*_t13;
  const double _t26 = _t25*ta;
  const double _t30 = xc_powr(na, -5, 2);
  const double _t31 = (0.3e1 / 0.2e1)*_t30;
  const double _t34 = (0.1e1 / (na * na * na * na));
  const double _t35 = (0.3e1 / 0.4e1)*_t34;
  const double _t36 = my_piecewise3(_t15, -_t26 + _t35*gaa, 0);
  const double _t37 = (0.1e1 / _t17);
  const double _t39 = _t2*_t21;
  const double _t44 = (0.1e1 / _t1);
  const double _t45 = (0.4e1 / 0.3e1)*_t44;
  const double _t46 = my_piecewise3(_t15, -_t14, 0);
  const double _t49 = (0.16e2 / 0.3e1)*_t6;
  const double _t51 = my_piecewise3(_t15, _t7, 0);
  double _hc3[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(prhg07_C_k, _KMAX)(p, 0, 0, 0, _hc3);
  double _hc4[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(prhg07_C_k, _KMAX)(p, _t5, 0, 0, _hc4);
  const double _t24 = _hc2[1]*_t9;
  const double _t27 = _hc3[2]*la;
  const double _t28 = _hc4[3]*_t2;
  const double _t29 = _t1*_t28;
  const double _t32 = -_hc3[1]*_t26 - _t25*_t27 - _t29*_t31;
  const double _t33 = _hc1[1]*_t32;
  const double _t38 = (0.2e1 / 0.3e1)*_t10*_t36*_t37 - _t24*_t33;
  const double _t40 = _hc2[1]*_t8;
  const double _t41 = _hc1[1]*_t40;
  const double _t42 = _hc4[3]*_t4;
  const double _t43 = _t41*_t42;
  const double _t47 = (0.2e1 / 0.3e1)*_t10*_t37*_t46 - _t43*_t45;
  const double _t48 = _hc1[1]*_t24;
  const double _t50 = _hc3[1]*_t41;
  const double _t52 = (0.2e1 / 0.3e1)*_t10*_t37*_t51 - _t49*_t50;
  const double v2rho2_0 = _t19*_t23 + _t38*_t39;
  const double v2rhosigma_0 = _t39*_t47;
  const double v2rholapl_0 = -_hc3[2]*_t4*_t48;
  const double v2rhotau_0 = _t39*_t52;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += v2rho2_0;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += v2rhosigma_0;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += v2rholapl_0;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += v2rhotau_0;
#endif
#if _KMAX >= 3
  const double _t53 = (0.1e1 / 0.8e1)*_t4;
  const double _t54 = _t2*_t22;
  const double _t55 = (0.1e1 / 0.2e1)*_t54;
  const double _t61 = 0.12e2*_t34;
  const double _t62 = xc_powi(na, -5);
  const double _t65 = xc_powr(na, -7, 2);
  const double _t68 = 0.3e1*_t62;
  const double _t69 = my_piecewise3(_t15, 0.12e2*_t34*ta - _t68*gaa, 0);
  const double _t70 = xc_powr(_t16, -3, 2);
  const double _t71 = (0.1e1 / 0.3e1)*_t70;
  const double _t72 = (_t36 * _t36);
  const double _t74 = _t2*_t23;
  const double _t82 = my_piecewise3(_t15, _t35, 0);
  const double _t83 = _t10*_t36;
  const double _t84 = _t71*_t83;
  const double _t93 = my_piecewise3(_t15, -_t25, 0);
  const double _t95 = (0.1e1 / gaa);
  const double _t97 = (0.4e1 / 0.3e1)*_t13;
  const double _t100 = _t95*_t97;
  const double _t101 = xc_powr(gaa, -3, 2);
  const double _t102 = (_t46 * _t46);
  const double _t103 = _t10*_t71;
  const double _t109 = _t103*_t46;
  const double _t112 = (0.16e2 / 0.3e1)*_t2*_t65;
  const double _t116 = (0.32e2 / 0.3e1)*_t34;
  const double _t118 = (_t51 * _t51);
  const double _t56 = (_t32 * _t32);
  const double _t57 = _hc1[2]*_t24;
  const double _t58 = ((_hc1[1]) * (_hc1[1]));
  const double _t59 = _hc2[2]*_t58;
  const double _t60 = _t59*_t9;
  const double _t63 = _hc3[9]*_t62;
  const double _t64 = _t63*gaa;
  const double _t66 = _t29*_t65;
  const double _t67 = _hc3[1]*_t61*ta + _t27*_t61 + (0.9e1 / 0.2e1)*_t64 + (0.15e2 / 0.4e1)*_t66;
  const double _t73 = (0.2e1 / 0.3e1)*_t10*_t37*_t69 - _t10*_t71*_t72 - _t48*_t67 - _t56*_t57 - _t56*_t60;
  const double _t75 = _hc3[9]*_t34;
  const double _t76 = _t28*_t44;
  const double _t77 = -0.3e1 / 0.4e1*_t30*_t76 - 0.3e1 / 0.2e1*_t75;
  const double _t78 = _hc1[2]*_t40;
  const double _t79 = _t42*_t45;
  const double _t80 = _t32*_t79;
  const double _t81 = _t59*_t8;
  const double _t85 = (0.2e1 / 0.3e1)*_t10*_t37*_t82 - _t46*_t84 - _t48*_t77 - _t78*_t80 - _t80*_t81;
  const double _t86 = _hc3[2]*_t41;
  const double _t87 = _t2*_t86;
  const double _t88 = _t32*_t49;
  const double _t89 = _hc3[2]*_t78;
  const double _t90 = _t81*_t88;
  const double _t91 = (0.32e2 / 0.3e1)*_hc1[1]*_hc2[1]*_hc3[2]*_t13*_t8 - _hc3[2]*_t90 - _t88*_t89;
  const double _t92 = _hc3[1]*_t78;
  const double _t94 = (0.32e2 / 0.3e1)*_hc1[1]*_hc2[1]*_hc3[1]*_t13*_t8 - _hc3[1]*_t90 + (0.2e1 / 0.3e1)*_t10*_t37*_t93 - _t51*_t84 - _t88*_t92;
  const double _t96 = _hc3[9]*_t95;
  const double _t98 = _t96*_t97;
  const double _t99 = ((_hc4[3]) * (_hc4[3]));
  const double _t104 = (0.2e1 / 0.3e1)*_hc1[1]*_hc2[1]*_hc4[3]*_t101*_t2*_t3*_t8 - _t100*_t78*_t99 - _t100*_t81*_t99 - _t102*_t103 - _t41*_t98;
  const double _t105 = _t65*_t76;
  const double _t106 = _hc3[2]*_t105;
  const double _t107 = -_t106*_t57 - _t106*_t60;
  const double _t108 = _hc3[1]*_t105;
  const double _t110 = -_t108*_t57 - _t108*_t60 - _t109*_t51;
  const double _t111 = ((_hc3[2]) * (_hc3[2]));
  const double _t113 = _t112*_t81;
  const double _t114 = _hc3[1]*_hc3[2];
  const double _t115 = ((_hc3[1]) * (_hc3[1]));
  const double _t117 = _t115*_t116;
  const double _t119 = -_t103*_t118 - _t117*_t78 - _t117*_t81;
  const double v3rho3_0 = -_t18*_t53 + _t38*_t55 + _t39*_t73;
  const double v3rho2sigma_0 = _t39*_t85 + _t47*_t74;
  const double v3rho2lapl_0 = (0.1e1 / 0.2e1)*_t2*_t20*_t91 - 0.4e1 / 0.3e1*_t30*_t87;
  const double v3rho2tau_0 = _t39*_t94 + _t52*_t74;
  const double v3rhosigma2_0 = _t104*_t39;
  const double v3rhosigmalapl_0 = _t107*_t39;
  const double v3rhosigmatau_0 = _t110*_t39;
  const double v3rholapl2_0 = -_t111*_t112*_t78 - _t111*_t113;
  const double v3rholapltau_0 = -_hc3[1]*_t112*_t89 - _t113*_t114;
  const double v3rhotau2_0 = _t119*_t39;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += v3rho3_0;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += v3rho2sigma_0;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += v3rho2lapl_0;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += v3rho2tau_0;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += v3rhosigma2_0;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 0] += v3rhosigmalapl_0;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += v3rhosigmatau_0;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += v3rholapl2_0;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 0] += v3rholapltau_0;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += v3rhotau2_0;
#endif
#if _KMAX >= 4
  const double _t127 = 0.48e2*_t62;
  const double _t128 = _t127*ta;
  const double _t129 = xc_powi(na, -6);
  const double _t130 = _t129*gaa;
  const double _t131 = xc_powr(na, -9, 2);
  const double _t133 = 0.24e2*_t34;
  const double _t136 = xc_powr(_t16, -5, 2);
  const double _t137 = _t70*_t83;
  const double _t144 = (0.2e1 / 0.3e1)*_t137;
  const double _t145 = 0.32e2*_t34;
  const double _t156 = _t103*_t51;
  const double _t163 = (0.2e1 / 0.3e1)*_t10*_t70;
  const double _t169 = _t131*_t2;
  const double _t174 = (0.1e1 / (gaa * gaa));
  const double _t185 = xc_powr(na, -11, 2);
  const double _t197 = 0.32e2*_t185;
  const double _t198 = (0.32e2 / 0.3e1)*_t2;
  const double _t199 = _t197*_t2;
  const double _t120 = (_t32 * _t32 * _t32);
  const double _t121 = _hc1[3]*_t24;
  const double _t122 = _hc1[2]*_hc2[2]*_t8;
  const double _t123 = _hc1[1]*_t122;
  const double _t124 = 0.8e1*_t123;
  const double _t125 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_hc2[3];
  const double _t126 = _t125*_t9;
  const double _t132 = _t32*_t57;
  const double _t134 = _hc3[1]*_t133*ta + _t133*_t27 + 0.9e1*_t64 + (0.15e2 / 0.2e1)*_t66;
  const double _t135 = _t32*_t60;
  const double _t138 = _hc1[3]*_t40;
  const double _t139 = _t56*_t79;
  const double _t140 = _t42*_t44;
  const double _t141 = _t125*_t8;
  const double _t142 = _t67*_t79;
  const double _t143 = -_t31*_t76 - 0.3e1*_t75;
  const double _t146 = _t49*_t56;
  const double _t147 = _hc3[2]*_t138;
  const double _t148 = _hc3[2]*_t123;
  const double _t149 = 0.16e2*_t56*_t6;
  const double _t150 = _t141*_t146;
  const double _t151 = _t49*_t67;
  const double _t152 = _hc3[2]*_t81;
  const double _t153 = _hc3[1]*_t138;
  const double _t154 = _hc3[1]*_t123;
  const double _t155 = _hc3[1]*_t81;
  const double _t157 = _t140*_t77;
  const double _t158 = _t32*_t98;
  const double _t159 = _t138*_t32;
  const double _t160 = _t100*_t99;
  const double _t161 = _t122*_t33;
  const double _t162 = _t141*_t32;
  const double _t164 = _t49*_t77;
  const double _t165 = _t106*_t32;
  const double _t166 = 0.8e1*_t161;
  const double _t167 = _hc3[1]*_t32;
  const double _t168 = _t105*_t167;
  const double _t170 = _t111*_t169;
  const double _t171 = _t111*_t116;
  const double _t172 = _t145*_t161;
  const double _t173 = _t114*_t169;
  const double _t175 = 0.2e1*_hc3[9]*_t101*_t131*_t28;
  const double _t176 = ((_hc4[3]) * (_hc4[3]) * (_hc4[3]))*_t169;
  const double _t177 = (0.2e1 / 0.3e1)*_t101*_t176;
  const double _t178 = _hc3[2]*_t95;
  const double _t179 = _t178*_t63;
  const double _t180 = _t62*_t99;
  const double _t181 = _t178*_t180;
  const double _t182 = _hc3[1]*_t95;
  const double _t183 = _t182*_t63;
  const double _t184 = _t180*_t182;
  const double _t186 = _t138*_t185;
  const double _t187 = (0.16e2 / 0.3e1)*_t76;
  const double _t188 = _t111*_t187;
  const double _t189 = _t111*_t185;
  const double _t190 = 0.16e2*_t123*_t76;
  const double _t191 = _t141*_t185;
  const double _t192 = _t147*_t185;
  const double _t193 = _t185*_t190;
  const double _t194 = _t115*_t187;
  const double _t195 = ((_hc3[2]) * (_hc3[2]) * (_hc3[2]))*_t2;
  const double _t196 = (0.32e2 / 0.3e1)*_t195;
  const double _t200 = _t191*_t198;
  const double _t201 = ((_hc3[1]) * (_hc3[1]) * (_hc3[1]))*_t129;
  const double _t202 = (0.64e2 / 0.3e1)*_t201;
  const double v4rho4_0 = (0.3e1 / 0.16e2)*_t19*_t30 - 0.3e1 / 0.8e1*_t38*_t4 + _t39*((0.1e1 / 0.2e1)*_t10*_t136*(_t36 * _t36 * _t36) + (0.2e1 / 0.3e1)*_t10*_t37*my_piecewise3(_t15, -_t128 + 0.15e2*_t130, 0) - _t120*_t121 - _t120*_t124 - _t120*_t126 - _t132*_t134 - _t132*_t67 - _t134*_t135 - _t135*_t67 - _t137*_t69 - _t48*(-_hc3[1]*_t128 - 0.135e3 / 0.4e1*_hc3[9]*_t130 - _t127*_t27 - 0.105e3 / 0.8e1*_t131*_t29)) + (0.3e1 / 0.4e1)*_t54*_t73;
  const double v4rho3sigma_0 = _t39*((0.1e1 / 0.2e1)*_t10*_t136*_t46*_t72 + (0.2e1 / 0.3e1)*_t10*_t37*my_piecewise3(_t15, -_t68, 0) - _t109*_t69 - 0.4e1*_t123*_t140*_t56 - _t132*_t143 - _t135*_t143 - _t138*_t139 - _t139*_t141 - _t142*_t78 - _t142*_t81 - _t144*_t82 - _t48*((0.15e2 / 0.8e1)*_t105 + (0.33e2 / 0.4e1)*_t63)) - _t47*_t53 + _t55*_t85;
  const double v4rho3lapl_0 = _t39*((0.64e2 / 0.3e1)*_hc1[2]*_hc2[1]*_hc3[2]*_t13*_t32*_t8 + (0.64e2 / 0.3e1)*_hc2[2]*_hc3[2]*_t13*_t32*_t58*_t8 - _hc3[2]*_t150 - _t145*_t86 - _t146*_t147 - _t148*_t149 - _t151*_t152 - _t151*_t89) + _t55*_t91 + (0.2e1 / 0.3e1)*_t65*_t87;
  const double v4rho3tau_0 = _t39*((0.64e2 / 0.3e1)*_hc1[2]*_hc2[1]*_hc3[1]*_t13*_t32*_t8 + (0.64e2 / 0.3e1)*_hc2[2]*_hc3[1]*_t13*_t32*_t58*_t8 - _hc3[1]*_t150 + (0.1e1 / 0.2e1)*_t10*_t136*_t51*_t72 + (0.2e1 / 0.3e1)*_t10*_t37*my_piecewise3(_t15, _t61, 0) - _t144*_t93 - _t145*_t50 - _t146*_t153 - _t149*_t154 - _t151*_t155 - _t151*_t92 - _t156*_t69) - _t52*_t53 + _t55*_t94;
  const double v4rho2sigma2_0 = _t104*_t74 + _t39*((0.2e1 / 0.3e1)*_hc1[2]*_hc2[1]*_hc4[3]*_t101*_t2*_t3*_t32*_t8 + (0.2e1 / 0.3e1)*_hc2[2]*_hc4[3]*_t101*_t2*_t3*_t32*_t58*_t8 + (0.1e1 / 0.2e1)*_t10*_t102*_t136*_t36 - _t157*_t57 - _t157*_t60 - _t158*_t78 - _t158*_t81 - _t159*_t160 - _t160*_t162 - _t161*_t25*_t95*_t99 - _t163*_t46*_t82 - _t48*((0.3e1 / 0.8e1)*_hc4[3]*_t101*_t2*_t30 - _t35*_t96));
  const double v4rho2sigmalapl_0 = _t107*_t74 + _t39*((0.16e2 / 0.3e1)*_hc1[2]*_hc2[1]*_hc3[2]*_hc4[3]*_t131*_t2*_t44*_t8 + (0.16e2 / 0.3e1)*_hc2[2]*_hc3[2]*_hc4[3]*_t131*_t2*_t44*_t58*_t8 - _t106*_t166 - _t121*_t165 - _t126*_t165 - _t152*_t164 - _t164*_t89);
  const double v4rho2sigmatau_0 = _t110*_t74 + _t39*((0.16e2 / 0.3e1)*_hc1[2]*_hc2[1]*_hc3[1]*_hc4[3]*_t131*_t2*_t44*_t8 + (0.16e2 / 0.3e1)*_hc2[2]*_hc3[1]*_hc4[3]*_t131*_t2*_t44*_t58*_t8 + (0.1e1 / 0.2e1)*_t10*_t136*_t36*_t46*_t51 - _t108*_t166 - _t109*_t93 - _t121*_t168 - _t126*_t168 - _t155*_t164 - _t156*_t82 - _t164*_t92);
  const double v4rho2lapl2_0 = -_t170*_t57 - _t170*_t60 + (0.1e1 / 0.2e1)*_t2*_t20*((0.128e3 / 0.3e1)*_hc1[2]*_hc2[1]*_t111*_t62*_t8 + (0.128e3 / 0.3e1)*_hc2[2]*_t111*_t58*_t62*_t8 - _t111*_t172 - _t159*_t171 - _t162*_t171);
  const double v4rho2lapltau_0 = -_t173*_t57 - _t173*_t60 + (0.1e1 / 0.2e1)*_t2*_t20*((0.128e3 / 0.3e1)*_hc1[2]*_hc2[1]*_hc3[1]*_hc3[2]*_t62*_t8 + (0.128e3 / 0.3e1)*_hc2[2]*_hc3[1]*_hc3[2]*_t58*_t62*_t8 - _t114*_t116*_t162 - _t114*_t172 - _t116*_t147*_t167);
  const double v4rho2tau2_0 = _t119*_t74 + _t39*((0.128e3 / 0.3e1)*_hc1[2]*_hc2[1]*_t115*_t62*_t8 + (0.128e3 / 0.3e1)*_hc2[2]*_t115*_t58*_t62*_t8 + (0.1e1 / 0.2e1)*_t10*_t118*_t136*_t36 - _t115*_t172 - _t117*_t159 - _t117*_t162 - _t163*_t51*_t93);
  const double v4rhosigma3_0 = _t39*(0.2e1*_hc1[1]*_hc2[1]*_hc3[9]*_t13*_t174*_t8 + 0.2e1*_hc1[2]*_hc2[1]*_t13*_t174*_t8*_t99 + 0.2e1*_hc2[2]*_t13*_t174*_t58*_t8*_t99 + (0.1e1 / 0.2e1)*_t10*_t136*(_t46 * _t46 * _t46) - 0.2e1*_t101*_t123*_t176 - _t138*_t177 - _t141*_t177 - _t175*_t78 - _t175*_t81 - _t43/xc_powr(gaa, 5, 2));
  const double v4rhosigma2lapl_0 = _t39*((0.4e1 / 0.3e1)*_hc1[2]*_hc2[1]*_hc3[2]*_hc4[3]*_t101*_t2*_t65*_t8 + (0.4e1 / 0.3e1)*_hc2[2]*_hc3[2]*_hc4[3]*_t101*_t2*_t58*_t65*_t8 - _t121*_t181 - _t124*_t181 - _t126*_t181 - _t179*_t57 - _t179*_t60);
  const double v4rhosigma2tau_0 = _t39*((0.4e1 / 0.3e1)*_hc1[2]*_hc2[1]*_hc3[1]*_hc4[3]*_t101*_t2*_t65*_t8 + (0.4e1 / 0.3e1)*_hc2[2]*_hc3[1]*_hc4[3]*_t101*_t2*_t58*_t65*_t8 + (0.1e1 / 0.2e1)*_t10*_t102*_t136*_t51 - _t121*_t184 - _t124*_t184 - _t126*_t184 - _t183*_t57 - _t183*_t60);
  const double v4rhosigmalapl2_0 = _t39*(-_t186*_t188 - _t188*_t191 - _t189*_t190);
  const double v4rhosigmalapltau_0 = _t39*(-_hc3[1]*_t187*_t192 - _t114*_t187*_t191 - _t114*_t193);
  const double v4rhosigmatau2_0 = _t39*((0.1e1 / 0.2e1)*_t10*_t118*_t136*_t46 - _t115*_t193 - _t186*_t194 - _t191*_t194);
  const double v4rholapl3_0 = -_t123*_t195*_t197 - _t186*_t196 - _t191*_t196;
  const double v4rholapl2tau_0 = -_hc3[1]*_t111*_t200 - _t111*_t154*_t199 - _t153*_t189*_t198;
  const double v4rholapltau2_0 = -_hc3[2]*_t115*_t200 - _t115*_t148*_t199 - _t115*_t192*_t198;
  const double v4rhotau3_0 = _t39*((0.1e1 / 0.2e1)*_t10*_t136*(_t51 * _t51 * _t51) - 0.64e2*_t123*_t201 - _t138*_t202 - _t141*_t202);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += v4rho4_0;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += v4rho3sigma_0;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += v4rho3lapl_0;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += v4rho3tau_0;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += v4rho2sigma2_0;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 0] += v4rho2sigmalapl_0;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += v4rho2sigmatau_0;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += v4rho2lapl2_0;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 0] += v4rho2lapltau_0;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += v4rho2tau2_0;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += v4rhosigma3_0;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 0] += v4rhosigma2lapl_0;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += v4rhosigma2tau_0;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 0] += v4rhosigmalapl2_0;
  if(out->v4rhosigmalapltau != NULL) out->v4rhosigmalapltau[ip*p->dim.v4rhosigmalapltau + 0] += v4rhosigmalapltau_0;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += v4rhosigmatau2_0;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += v4rholapl3_0;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 0] += v4rholapl2tau_0;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 0] += v4rholapltau2_0;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += v4rhotau3_0;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gbb = sigma[2];
  const double la = lapl[0];
  const double lb = lapl[1];
  const double ta = tau[0];
  const double tb = tau[1];

  const double _t1 = xc_powr(gaa, 1, 2);
  const double _t2 = xc_powr(na, -3, 2);
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / (na * na));
  const double _t5 = xc_powr(gbb, 1, 2);
  const double _t6 = xc_powr(nb, -3, 2);
  const double _t7 = _t5*_t6;
  const double _t8 = (0.1e1 / (nb * nb));
  const double _t9 = xc_powr(na, 1, 2);
  const double _t10 = xc_powr(M_PI, -1, 2);
  const double _t11 = (0.8e1 / 0.3e1)*_t10;
  const double _t12 = (0.1e1 / M_PI);
  const double _t13 = (na * na * na);
  const double _t14 = xc_powr(XC_EPSILON, 2, 3);
  const double _t15 = 0.8e1*_t14;
  const double _t16 = (0.1e1 / _t13);
  const double _t17 = (0.1e1 / 0.8e1)*_t16;
  const double _t18 = _t17*(-_t13*_t15 - gaa + 0.8e1*na*ta) > 0;
  const double _t19 = my_piecewise3(_t18, -_t17*gaa + _t4*ta, _t14);
  const double _t20 = xc_powr(_t19, 1, 2);
  const double _t22 = xc_powr(nb, 1, 2);
  const double _t23 = (nb * nb * nb);
  const double _t24 = (0.1e1 / _t23);
  const double _t25 = (0.1e1 / 0.8e1)*_t24;
  const double _t26 = _t25*(-_t15*_t23 - gbb + 0.8e1*nb*tb) > 0;
  const double _t27 = my_piecewise3(_t26, -_t25*gbb + _t8*tb, _t14);
  const double _t28 = xc_powr(_t27, 1, 2);
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(prhg07_C_k, _KMAX)(p, _t3, _t4*la, _t4*ta, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(prhg07_y_k, _KMAX)(p, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(prhg07_v_k, _KMAX)(p, _hc1[0], _hc2);
  double _hc3[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(prhg07_C_k, _KMAX)(p, _t7, _t8*lb, _t8*tb, _hc3);
  double _hc4[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(prhg07_y_k, _KMAX)(p, _hc3[0], _hc4);
  double _hc5[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(prhg07_v_k, _KMAX)(p, _hc4[0], _hc5);
  const double _t21 = -_hc2[0]*_t11 + (0.4e1 / 0.3e1)*_t12*_t20;
  const double _t29 = -_hc5[0]*_t11 + (0.4e1 / 0.3e1)*_t12*_t28;
  const double vrho_0 = _t21*_t9;
  const double vrho_1 = _t22*_t29;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += vrho_0;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += vrho_1;
#if _KMAX >= 2
  const double _t30 = (0.1e1 / _t9);
  const double _t31 = (0.1e1 / 0.2e1)*_t30;
  const double _t33 = 0.2e1*_t16;
  const double _t34 = _t33*ta;
  const double _t37 = xc_powr(na, -5, 2);
  const double _t38 = (0.3e1 / 0.2e1)*_t37;
  const double _t41 = (0.1e1 / (na * na * na * na));
  const double _t42 = (0.3e1 / 0.8e1)*_t41;
  const double _t43 = my_piecewise3(_t18, -_t34 + _t42*gaa, 0);
  const double _t44 = (0.1e1 / _t20);
  const double _t46 = (0.1e1 / _t22);
  const double _t47 = (0.1e1 / 0.2e1)*_t46;
  const double _t49 = 0.2e1*_t24;
  const double _t50 = _t49*tb;
  const double _t53 = xc_powr(nb, -5, 2);
  const double _t54 = (0.3e1 / 0.2e1)*_t53;
  const double _t57 = (0.1e1 / (nb * nb * nb * nb));
  const double _t58 = (0.3e1 / 0.8e1)*_t57;
  const double _t59 = my_piecewise3(_t26, -_t50 + _t58*gbb, 0);
  const double _t60 = (0.1e1 / _t28);
  const double _t63 = _t10*_t2;
  const double _t65 = (0.1e1 / _t1);
  const double _t68 = my_piecewise3(_t18, -_t17, 0);
  const double _t71 = _t10*_t6;
  const double _t73 = (0.1e1 / _t5);
  const double _t76 = my_piecewise3(_t26, -_t25, 0);
  const double _t81 = my_piecewise3(_t18, _t4, 0);
  const double _t84 = my_piecewise3(_t26, _t8, 0);
  double _hc6[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(prhg07_C_k, _KMAX)(p, 0, 0, 0, _hc6);
  double _hc7[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(prhg07_C_k, _KMAX)(p, _t3, 0, 0, _hc7);
  double _hc8[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(prhg07_C_k, _KMAX)(p, _t7, 0, 0, _hc8);
  const double _t32 = _hc2[1]*_t11;
  const double _t35 = _hc6[2]*la;
  const double _t36 = _hc7[3]*_t1;
  const double _t39 = -_hc6[1]*_t34 - _t33*_t35 - _t36*_t38;
  const double _t40 = _hc1[1]*_t39;
  const double _t45 = (0.2e1 / 0.3e1)*_t12*_t43*_t44 - _t32*_t40;
  const double _t48 = _hc5[1]*_t11;
  const double _t51 = _hc6[2]*lb;
  const double _t52 = _hc8[3]*_t5;
  const double _t55 = -_hc6[1]*_t50 - _t49*_t51 - _t52*_t54;
  const double _t56 = _hc4[1]*_t55;
  const double _t61 = (0.2e1 / 0.3e1)*_t12*_t59*_t60 - _t48*_t56;
  const double _t62 = _hc1[1]*_hc2[1];
  const double _t64 = _t62*_t63;
  const double _t66 = _hc7[3]*_t65;
  const double _t67 = (0.4e1 / 0.3e1)*_t66;
  const double _t69 = (0.2e1 / 0.3e1)*_t12*_t44*_t68 - _t64*_t67;
  const double _t70 = _hc4[1]*_hc5[1];
  const double _t72 = _t70*_t71;
  const double _t74 = _hc8[3]*_t73;
  const double _t75 = (0.4e1 / 0.3e1)*_t74;
  const double _t77 = (0.2e1 / 0.3e1)*_t12*_t60*_t76 - _t72*_t75;
  const double _t78 = _hc1[1]*_t32;
  const double _t79 = _hc4[1]*_t48;
  const double _t80 = _hc6[1]*_t4;
  const double _t82 = (0.2e1 / 0.3e1)*_t12*_t44*_t81 - _t78*_t80;
  const double _t83 = _hc6[1]*_t8;
  const double _t85 = (0.2e1 / 0.3e1)*_t12*_t60*_t84 - _t79*_t83;
  const double v2rho2_0 = _t21*_t31 + _t45*_t9;
  const double v2rho2_2 = _t22*_t61 + _t29*_t47;
  const double v2rhosigma_0 = _t69*_t9;
  const double v2rhosigma_5 = _t22*_t77;
  const double v2rholapl_0 = -_hc6[2]*_t2*_t78;
  const double v2rholapl_3 = -_hc6[2]*_t6*_t79;
  const double v2rhotau_0 = _t82*_t9;
  const double v2rhotau_3 = _t22*_t85;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += v2rho2_0;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += v2rho2_2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += v2rhosigma_0;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += v2rhosigma_5;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += v2rholapl_0;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 3] += v2rholapl_3;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += v2rhotau_0;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 3] += v2rhotau_3;
#endif
#if _KMAX >= 3
  const double _t86 = (0.1e1 / 0.4e1)*_t2;
  const double _t92 = 0.6e1*_t41;
  const double _t94 = xc_powi(na, -5);
  const double _t95 = _t94*gaa;
  const double _t96 = xc_powr(na, -7, 2);
  const double _t99 = (0.3e1 / 0.2e1)*_t94;
  const double _t100 = my_piecewise3(_t18, 0.6e1*_t41*ta - _t99*gaa, 0);
  const double _t101 = (_t43 * _t43);
  const double _t102 = xc_powr(_t19, -3, 2);
  const double _t103 = (0.1e1 / 0.3e1)*_t12;
  const double _t104 = _t102*_t103;
  const double _t106 = (0.1e1 / 0.4e1)*_t6;
  const double _t112 = 0.6e1*_t57;
  const double _t113 = xc_powi(nb, -5);
  const double _t114 = _t113*gbb;
  const double _t115 = xc_powr(nb, -7, 2);
  const double _t118 = (0.3e1 / 0.2e1)*_t113;
  const double _t119 = my_piecewise3(_t26, -_t118*gbb + 0.6e1*_t57*tb, 0);
  const double _t120 = (_t59 * _t59);
  const double _t121 = xc_powr(_t27, -3, 2);
  const double _t122 = _t103*_t121;
  const double _t130 = my_piecewise3(_t18, _t42, 0);
  const double _t131 = _t104*_t43;
  const double _t137 = my_piecewise3(_t26, _t58, 0);
  const double _t138 = _t122*_t59;
  const double _t152 = my_piecewise3(_t18, -_t33, 0);
  const double _t154 = my_piecewise3(_t26, -_t49, 0);
  const double _t156 = (0.1e1 / gaa);
  const double _t158 = (0.2e1 / 0.3e1)*_t10;
  const double _t160 = xc_powr(gaa, -3, 2);
  const double _t163 = (_t68 * _t68);
  const double _t165 = (0.1e1 / gbb);
  const double _t168 = xc_powr(gbb, -3, 2);
  const double _t171 = (_t76 * _t76);
  const double _t182 = _t104*_t68;
  const double _t185 = _t122*_t76;
  const double _t195 = (_t81 * _t81);
  const double _t198 = (_t84 * _t84);
  const double _t87 = (_t39 * _t39);
  const double _t88 = _hc1[2]*_t32;
  const double _t89 = ((_hc1[1]) * (_hc1[1]));
  const double _t90 = _hc2[2]*_t89;
  const double _t91 = _t11*_t87;
  const double _t93 = (0.9e1 / 0.4e1)*_hc6[9];
  const double _t97 = _t36*_t96;
  const double _t98 = _hc6[1]*_t92*ta + _t35*_t92 + _t93*_t95 + (0.15e2 / 0.4e1)*_t97;
  const double _t105 = (0.2e1 / 0.3e1)*_t100*_t12*_t44 - _t101*_t104 - _t78*_t98 - _t87*_t88 - _t90*_t91;
  const double _t107 = (_t55 * _t55);
  const double _t108 = _hc4[2]*_t48;
  const double _t109 = ((_hc4[1]) * (_hc4[1]));
  const double _t110 = _hc5[2]*_t109;
  const double _t111 = _t107*_t11;
  const double _t116 = _t115*_t52;
  const double _t117 = _hc6[1]*_t112*tb + _t112*_t51 + _t114*_t93 + (0.15e2 / 0.4e1)*_t116;
  const double _t123 = -_t107*_t108 - _t110*_t111 - _t117*_t79 + (0.2e1 / 0.3e1)*_t119*_t12*_t60 - _t120*_t122;
  const double _t124 = (0.3e1 / 0.4e1)*_hc6[9];
  const double _t125 = -_t124*_t41 - 0.3e1 / 0.4e1*_t37*_t66;
  const double _t126 = _hc1[2]*_hc2[1];
  const double _t127 = _t126*_t39;
  const double _t128 = _t63*_t67;
  const double _t129 = _t39*_t90;
  const double _t132 = (0.2e1 / 0.3e1)*_t12*_t130*_t44 - _t125*_t78 - _t127*_t128 - _t128*_t129 - _t131*_t68;
  const double _t133 = -_t124*_t57 - 0.3e1 / 0.4e1*_t53*_t74;
  const double _t134 = _hc4[2]*_hc5[1];
  const double _t135 = _t71*_t75;
  const double _t136 = _t135*_t55;
  const double _t139 = -_t110*_t136 + (0.2e1 / 0.3e1)*_t12*_t137*_t60 - _t133*_t79 - _t134*_t136 - _t138*_t76;
  const double _t140 = _hc6[2]*_t10;
  const double _t141 = (0.4e1 / 0.3e1)*_t140;
  const double _t142 = _t39*_t88;
  const double _t143 = _hc6[2]*_t4;
  const double _t144 = _t11*_t90;
  const double _t145 = _t144*_t39;
  const double _t146 = (0.16e2 / 0.3e1)*_hc1[1]*_hc2[1]*_hc6[2]*_t10*_t16 - _t142*_t143 - _t143*_t145;
  const double _t147 = _t108*_t55;
  const double _t148 = _hc6[2]*_t8;
  const double _t149 = _t11*_t110;
  const double _t150 = _t149*_t55;
  const double _t151 = (0.16e2 / 0.3e1)*_hc4[1]*_hc5[1]*_hc6[2]*_t10*_t24 - _t147*_t148 - _t148*_t150;
  const double _t153 = (0.16e2 / 0.3e1)*_hc1[1]*_hc2[1]*_hc6[1]*_t10*_t16 + (0.2e1 / 0.3e1)*_t12*_t152*_t44 - _t131*_t81 - _t142*_t80 - _t145*_t80;
  const double _t155 = (0.16e2 / 0.3e1)*_hc4[1]*_hc5[1]*_hc6[1]*_t10*_t24 + (0.2e1 / 0.3e1)*_t12*_t154*_t60 - _t138*_t84 - _t147*_t83 - _t150*_t83;
  const double _t157 = _hc6[9]*_t156;
  const double _t159 = _t157*_t158;
  const double _t161 = ((_hc7[3]) * (_hc7[3]));
  const double _t162 = _t156*_t158*_t16*_t161;
  const double _t164 = (0.2e1 / 0.3e1)*_hc1[1]*_hc2[1]*_hc7[3]*_t10*_t160*_t2 - _t104*_t163 - _t126*_t162 - _t159*_t16*_t62 - _t162*_t90;
  const double _t166 = _hc6[9]*_t165;
  const double _t167 = _t158*_t166;
  const double _t169 = ((_hc8[3]) * (_hc8[3]));
  const double _t170 = _t158*_t165*_t169*_t24;
  const double _t172 = (0.2e1 / 0.3e1)*_hc4[1]*_hc5[1]*_hc8[3]*_t10*_t168*_t6 - _t110*_t170 - _t122*_t171 - _t134*_t170 - _t167*_t24*_t70;
  const double _t173 = _t66*_t96;
  const double _t174 = _t141*_t173;
  const double _t175 = -_t126*_t174 - _t174*_t90;
  const double _t176 = _t115*_t74;
  const double _t177 = _t141*_t176;
  const double _t178 = -_t110*_t177 - _t134*_t177;
  const double _t179 = _hc6[1]*_t10;
  const double _t180 = (0.4e1 / 0.3e1)*_t179;
  const double _t181 = _t173*_t180;
  const double _t183 = -_t126*_t181 - _t181*_t90 - _t182*_t81;
  const double _t184 = _t176*_t180;
  const double _t186 = -_t110*_t184 - _t134*_t184 - _t185*_t84;
  const double _t187 = ((_hc6[2]) * (_hc6[2]));
  const double _t188 = _t187*_t96;
  const double _t189 = _t115*_t187;
  const double _t190 = _hc6[1]*_hc6[2];
  const double _t191 = _t190*_t96;
  const double _t192 = _t115*_t190;
  const double _t193 = ((_hc6[1]) * (_hc6[1]));
  const double _t194 = _t193*_t41;
  const double _t196 = -_t104*_t195 - _t144*_t194 - _t194*_t88;
  const double _t197 = _t193*_t57;
  const double _t199 = -_t108*_t197 - _t122*_t198 - _t149*_t197;
  const double v3rho3_0 = _t105*_t9 - _t21*_t86 + _t30*_t45;
  const double v3rho3_3 = -_t106*_t29 + _t123*_t22 + _t46*_t61;
  const double v3rho2sigma_0 = _t132*_t9 + _t31*_t69;
  const double v3rho2sigma_8 = _t139*_t22 + _t47*_t77;
  const double v3rho2lapl_0 = -_t141*_t37*_t62 + _t146*_t9;
  const double v3rho2lapl_5 = -_t141*_t53*_t70 + _t151*_t22;
  const double v3rho2tau_0 = _t153*_t9 + _t31*_t82;
  const double v3rho2tau_5 = _t155*_t22 + _t47*_t85;
  const double v3rhosigma2_0 = _t164*_t9;
  const double v3rhosigma2_11 = _t172*_t22;
  const double v3rhosigmalapl_0 = _t175*_t9;
  const double v3rhosigmalapl_11 = _t178*_t22;
  const double v3rhosigmatau_0 = _t183*_t9;
  const double v3rhosigmatau_11 = _t186*_t22;
  const double v3rholapl2_0 = -_t144*_t188 - _t188*_t88;
  const double v3rholapl2_5 = -_t108*_t189 - _t149*_t189;
  const double v3rholapltau_0 = -_t144*_t191 - _t191*_t88;
  const double v3rholapltau_7 = -_t108*_t192 - _t149*_t192;
  const double v3rhotau2_0 = _t196*_t9;
  const double v3rhotau2_5 = _t199*_t22;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += v3rho3_0;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += v3rho3_3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += v3rho2sigma_0;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += v3rho2sigma_8;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += v3rho2lapl_0;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 5] += v3rho2lapl_5;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += v3rho2tau_0;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 5] += v3rho2tau_5;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += v3rhosigma2_0;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += v3rhosigma2_11;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 0] += v3rhosigmalapl_0;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 11] += v3rhosigmalapl_11;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += v3rhosigmatau_0;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 11] += v3rhosigmatau_11;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += v3rholapl2_0;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 5] += v3rholapl2_5;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 0] += v3rholapltau_0;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 7] += v3rholapltau_7;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += v3rhotau2_0;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 5] += v3rhotau2_5;
#endif
#if _KMAX >= 4
  const double _t202 = 0.8e1*_t10;
  const double _t208 = 0.24e2*_t94;
  const double _t209 = _t208*ta;
  const double _t210 = xc_powi(na, -6);
  const double _t211 = _t210*gaa;
  const double _t213 = xc_powr(na, -9, 2);
  const double _t214 = 0.12e2*_t41;
  const double _t217 = xc_powr(_t19, -5, 2);
  const double _t218 = _t102*_t43;
  const double _t226 = 0.24e2*_t113;
  const double _t227 = _t226*tb;
  const double _t228 = xc_powi(nb, -6);
  const double _t229 = _t228*gbb;
  const double _t230 = xc_powr(nb, -9, 2);
  const double _t231 = 0.12e2*_t57;
  const double _t233 = xc_powr(_t27, -5, 2);
  const double _t234 = _t121*_t59;
  const double _t243 = (0.2e1 / 0.3e1)*_t12;
  const double _t244 = _t218*_t243;
  const double _t250 = _t234*_t243;
  const double _t252 = 0.16e2*_t41;
  const double _t258 = 0.16e2*_t57;
  const double _t264 = _t104*_t81;
  const double _t266 = _t122*_t84;
  const double _t271 = _t102*_t243;
  const double _t277 = _t121*_t243;
  const double _t309 = (0.1e1 / (gaa * gaa));
  const double _t312 = (0.1e1 / 0.3e1)*_t10;
  const double _t315 = (0.1e1 / (gbb * gbb));
  const double _t320 = (0.2e1 / 0.3e1)*_t94;
  const double _t326 = (0.2e1 / 0.3e1)*_t113;
  const double _t337 = xc_powr(na, -11, 2);
  const double _t343 = xc_powr(nb, -11, 2);
  const double _t200 = (_t39 * _t39 * _t39);
  const double _t201 = _hc1[3]*_t32;
  const double _t203 = _hc1[2]*_hc2[2];
  const double _t204 = _hc1[1]*_t203;
  const double _t205 = _t202*_t204;
  const double _t206 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_hc2[3];
  const double _t207 = _t11*_t206;
  const double _t212 = (0.135e3 / 0.8e1)*_hc6[9];
  const double _t215 = (0.9e1 / 0.2e1)*_hc6[9];
  const double _t216 = _hc6[1]*_t214*ta + _t214*_t35 + _t215*_t95 + (0.15e2 / 0.2e1)*_t97;
  const double _t219 = (_t55 * _t55 * _t55);
  const double _t220 = _hc4[3]*_t48;
  const double _t221 = _hc4[2]*_hc5[2];
  const double _t222 = _hc4[1]*_t221;
  const double _t223 = _t202*_t222;
  const double _t224 = ((_hc4[1]) * (_hc4[1]) * (_hc4[1]))*_hc5[3];
  const double _t225 = _t11*_t224;
  const double _t232 = _hc6[1]*_t231*tb + _t114*_t215 + (0.15e2 / 0.2e1)*_t116 + _t231*_t51;
  const double _t235 = (0.33e2 / 0.8e1)*_hc6[9];
  const double _t236 = _hc1[3]*_hc2[1];
  const double _t237 = _t128*_t87;
  const double _t238 = _t204*_t87;
  const double _t239 = 0.4e1*_t66;
  const double _t240 = _t128*_t98;
  const double _t241 = (0.3e1 / 0.2e1)*_hc6[9];
  const double _t242 = -_t241*_t41 - _t38*_t66;
  const double _t245 = _hc4[3]*_hc5[1];
  const double _t246 = _t107*_t135;
  const double _t247 = 0.4e1*_t74;
  const double _t248 = _t117*_t135;
  const double _t249 = -_t241*_t57 - _t54*_t74;
  const double _t251 = _t140*_t62;
  const double _t253 = _t201*_t87;
  const double _t254 = 0.8e1*_t140;
  const double _t255 = _t206*_t91;
  const double _t256 = _t143*_t98;
  const double _t257 = _t140*_t70;
  const double _t259 = _t107*_t220;
  const double _t260 = _t222*_t254;
  const double _t261 = _t111*_t224;
  const double _t262 = _t117*_t148;
  const double _t263 = _t80*_t98;
  const double _t265 = _t117*_t83;
  const double _t267 = _t125*_t2;
  const double _t268 = _t162*_t39;
  const double _t269 = _t203*_t40;
  const double _t270 = _t156*_t161;
  const double _t272 = _t133*_t6;
  const double _t273 = _t167*_t24*_t55;
  const double _t274 = _t170*_t55;
  const double _t275 = _t221*_t56;
  const double _t276 = _t165*_t169;
  const double _t278 = _t125*_t143;
  const double _t279 = _t174*_t39;
  const double _t280 = 0.4e1*_t140;
  const double _t281 = _t173*_t269;
  const double _t282 = _t133*_t148;
  const double _t283 = _t177*_t55;
  const double _t284 = _t176*_t275;
  const double _t285 = _t125*_t80;
  const double _t286 = _t181*_t39;
  const double _t287 = 0.4e1*_t179;
  const double _t288 = _t133*_t83;
  const double _t289 = _t184*_t55;
  const double _t290 = _t10*_t187;
  const double _t291 = (0.4e1 / 0.3e1)*_t290;
  const double _t292 = _t126*_t213;
  const double _t293 = _t213*_t90;
  const double _t294 = _t201*_t39;
  const double _t295 = _t187*_t41;
  const double _t296 = _t202*_t269;
  const double _t297 = _t207*_t39;
  const double _t298 = _t230*_t291;
  const double _t299 = _t220*_t55;
  const double _t300 = _t187*_t57;
  const double _t301 = _t202*_t275;
  const double _t302 = _t225*_t55;
  const double _t303 = _hc6[1]*_t141;
  const double _t304 = _t190*_t41;
  const double _t305 = _hc6[1]*_t140;
  const double _t306 = 0.8e1*_t305;
  const double _t307 = _t230*_t303;
  const double _t308 = _t190*_t57;
  const double _t310 = _hc6[9]*_t10;
  const double _t311 = _hc7[3]*_t160*_t310;
  const double _t313 = ((_hc7[3]) * (_hc7[3]) * (_hc7[3]))*_t160*_t213;
  const double _t314 = _t312*_t313;
  const double _t316 = _hc8[3]*_t168;
  const double _t317 = _t230*_t310;
  const double _t318 = ((_hc8[3]) * (_hc8[3]) * (_hc8[3]))*_t168*_t230;
  const double _t319 = _t312*_t318;
  const double _t321 = _t157*_t320;
  const double _t322 = _t270*_t320;
  const double _t323 = _t140*_t322;
  const double _t324 = 0.2e1*_t140;
  const double _t325 = _t204*_t270*_t94;
  const double _t327 = _t140*_t326;
  const double _t328 = _t166*_t327;
  const double _t329 = _t276*_t327;
  const double _t330 = _t113*_t222*_t276;
  const double _t331 = _t179*_t321;
  const double _t332 = _t179*_t322;
  const double _t333 = 0.2e1*_t179;
  const double _t334 = _t179*_t326;
  const double _t335 = _t166*_t334;
  const double _t336 = _t276*_t334;
  const double _t338 = _t236*_t337;
  const double _t339 = _t291*_t66;
  const double _t340 = _t204*_t337;
  const double _t341 = _t239*_t340;
  const double _t342 = _t206*_t337;
  const double _t344 = _t245*_t343;
  const double _t345 = _t291*_t74;
  const double _t346 = _t222*_t343;
  const double _t347 = _t247*_t346;
  const double _t348 = _t224*_t343;
  const double _t349 = _t303*_t66;
  const double _t350 = _t303*_t74;
  const double _t351 = _t10*_t193;
  const double _t352 = _t351*_t67;
  const double _t353 = _t351*_t75;
  const double _t354 = ((_hc6[2]) * (_hc6[2]) * (_hc6[2]));
  const double _t355 = _t337*_t354;
  const double _t356 = _t343*_t354;
  const double _t357 = _hc6[1]*_t187;
  const double _t358 = _t201*_t337;
  const double _t359 = 0.8e1*_t179*_t187;
  const double _t360 = _t207*_t337;
  const double _t361 = _t343*_t357;
  const double _t362 = _hc6[2]*_t193;
  const double _t363 = _t343*_t362;
  const double _t364 = ((_hc6[1]) * (_hc6[1]) * (_hc6[1]));
  const double _t365 = _t210*_t364;
  const double _t366 = _t228*_t364;
  const double v4rho4_0 = (0.3e1 / 0.2e1)*_t105*_t30 - 0.3e1 / 0.4e1*_t2*_t45 + (0.3e1 / 0.8e1)*_t21*_t37 + _t9*(-_t100*_t12*_t218 + (0.1e1 / 0.2e1)*_t12*_t217*(_t43 * _t43 * _t43) + (0.2e1 / 0.3e1)*_t12*_t44*my_piecewise3(_t18, -_t209 + (0.15e2 / 0.2e1)*_t211, 0) - _t142*_t216 - _t142*_t98 - _t145*_t216 - _t145*_t98 - _t200*_t201 - _t200*_t205 - _t200*_t207 - _t78*(-_hc6[1]*_t209 - _t208*_t35 - _t211*_t212 - 0.105e3 / 0.8e1*_t213*_t36));
  const double v4rho4_4 = (0.3e1 / 0.2e1)*_t123*_t46 + _t22*(-_t117*_t147 - _t117*_t150 - _t119*_t12*_t234 + (0.1e1 / 0.2e1)*_t12*_t233*(_t59 * _t59 * _t59) + (0.2e1 / 0.3e1)*_t12*_t60*my_piecewise3(_t26, -_t227 + (0.15e2 / 0.2e1)*_t229, 0) - _t147*_t232 - _t150*_t232 - _t219*_t220 - _t219*_t223 - _t219*_t225 - _t79*(-_hc6[1]*_t227 - _t212*_t229 - _t226*_t51 - 0.105e3 / 0.8e1*_t230*_t52)) + (0.3e1 / 0.8e1)*_t29*_t53 - 0.3e1 / 0.4e1*_t6*_t61;
  const double v4rho3sigma_0 = _t132*_t30 - _t69*_t86 + _t9*(-_t100*_t182 + (0.1e1 / 0.2e1)*_t101*_t12*_t217*_t68 + (0.2e1 / 0.3e1)*_t12*_t44*my_piecewise3(_t18, -_t99, 0) - _t126*_t240 - _t130*_t244 - _t142*_t242 - _t145*_t242 - _t206*_t237 - _t236*_t237 - _t238*_t239*_t63 - _t240*_t90 - _t78*((0.15e2 / 0.8e1)*_t173 + _t235*_t94));
  const double v4rho3sigma_11 = -_t106*_t77 + _t139*_t46 + _t22*(-_t107*_t222*_t247*_t71 - _t110*_t248 - _t119*_t185 + (0.1e1 / 0.2e1)*_t12*_t120*_t233*_t76 + (0.2e1 / 0.3e1)*_t12*_t60*my_piecewise3(_t26, -_t118, 0) - _t134*_t248 - _t137*_t250 - _t147*_t249 - _t150*_t249 - _t224*_t246 - _t245*_t246 - _t79*(_t113*_t235 + (0.15e2 / 0.8e1)*_t176));
  const double v4rho3lapl_0 = _t146*_t30 + (0.2e1 / 0.3e1)*_t251*_t96 + _t9*((0.32e2 / 0.3e1)*_hc1[2]*_hc2[1]*_hc6[2]*_t10*_t16*_t39 + (0.32e2 / 0.3e1)*_hc2[2]*_hc6[2]*_t10*_t16*_t39*_t89 - _t143*_t253 - _t143*_t255 - _t144*_t256 - _t238*_t254*_t4 - _t251*_t252 - _t256*_t88);
  const double v4rho3lapl_7 = (0.2e1 / 0.3e1)*_t115*_t257 + _t151*_t46 + _t22*((0.32e2 / 0.3e1)*_hc4[2]*_hc5[1]*_hc6[2]*_t10*_t24*_t55 + (0.32e2 / 0.3e1)*_hc5[2]*_hc6[2]*_t10*_t109*_t24*_t55 - _t107*_t260*_t8 - _t108*_t262 - _t148*_t259 - _t148*_t261 - _t149*_t262 - _t257*_t258);
  const double v4rho3tau_0 = _t153*_t30 - _t82*_t86 + _t9*((0.32e2 / 0.3e1)*_hc1[2]*_hc2[1]*_hc6[1]*_t10*_t16*_t39 + (0.32e2 / 0.3e1)*_hc2[2]*_hc6[1]*_t10*_t16*_t39*_t89 - _t100*_t264 + (0.1e1 / 0.2e1)*_t101*_t12*_t217*_t81 + (0.2e1 / 0.3e1)*_t12*_t44*my_piecewise3(_t18, _t92, 0) - _t144*_t263 - _t152*_t244 - _t179*_t252*_t62 - _t205*_t80*_t87 - _t253*_t80 - _t255*_t80 - _t263*_t88);
  const double v4rho3tau_7 = -_t106*_t85 + _t155*_t46 + _t22*((0.32e2 / 0.3e1)*_hc4[2]*_hc5[1]*_hc6[1]*_t10*_t24*_t55 + (0.32e2 / 0.3e1)*_hc5[2]*_hc6[1]*_t10*_t109*_t24*_t55 - _t107*_t223*_t83 - _t108*_t265 - _t119*_t266 + (0.1e1 / 0.2e1)*_t12*_t120*_t233*_t84 + (0.2e1 / 0.3e1)*_t12*_t60*my_piecewise3(_t26, _t112, 0) - _t149*_t265 - _t154*_t250 - _t179*_t258*_t70 - _t259*_t83 - _t261*_t83);
  const double v4rho2sigma2_0 = _t164*_t31 + _t9*((0.2e1 / 0.3e1)*_hc1[2]*_hc2[1]*_hc7[3]*_t10*_t160*_t2*_t39 + (0.2e1 / 0.3e1)*_hc2[2]*_hc7[3]*_t10*_t160*_t2*_t39*_t89 - _t10*_t269*_t270*_t33 + (0.1e1 / 0.2e1)*_t12*_t163*_t217*_t43 - _t127*_t159*_t16 - _t129*_t159*_t16 - _t130*_t271*_t68 - _t144*_t267*_t66 - _t206*_t268 - _t236*_t268 - _t267*_t66*_t88 - _t78*((0.3e1 / 0.8e1)*_hc7[3]*_t160*_t37 - _t157*_t42));
  const double v4rho2sigma2_17 = _t172*_t47 + _t22*((0.2e1 / 0.3e1)*_hc4[2]*_hc5[1]*_hc8[3]*_t10*_t168*_t55*_t6 + (0.2e1 / 0.3e1)*_hc5[2]*_hc8[3]*_t10*_t109*_t168*_t55*_t6 - _t10*_t275*_t276*_t49 - _t108*_t272*_t74 - _t110*_t273 + (0.1e1 / 0.2e1)*_t12*_t171*_t233*_t59 - _t134*_t273 - _t137*_t277*_t76 - _t149*_t272*_t74 - _t224*_t274 - _t245*_t274 - _t79*((0.3e1 / 0.8e1)*_hc8[3]*_t168*_t53 - _t166*_t58));
  const double v4rho2sigmalapl_0 = _t175*_t31 + _t9*((0.8e1 / 0.3e1)*_hc1[2]*_hc2[1]*_hc6[2]*_hc7[3]*_t10*_t213*_t65 + (0.8e1 / 0.3e1)*_hc2[2]*_hc6[2]*_hc7[3]*_t10*_t213*_t65*_t89 - _t144*_t278 - _t206*_t279 - _t236*_t279 - _t278*_t88 - _t280*_t281);
  const double v4rho2sigmalapl_17 = _t178*_t47 + _t22*((0.8e1 / 0.3e1)*_hc4[2]*_hc5[1]*_hc6[2]*_hc8[3]*_t10*_t230*_t73 + (0.8e1 / 0.3e1)*_hc5[2]*_hc6[2]*_hc8[3]*_t10*_t109*_t230*_t73 - _t108*_t282 - _t149*_t282 - _t224*_t283 - _t245*_t283 - _t280*_t284);
  const double v4rho2sigmatau_0 = _t183*_t31 + _t9*((0.8e1 / 0.3e1)*_hc1[2]*_hc2[1]*_hc6[1]*_hc7[3]*_t10*_t213*_t65 + (0.8e1 / 0.3e1)*_hc2[2]*_hc6[1]*_hc7[3]*_t10*_t213*_t65*_t89 + (0.1e1 / 0.2e1)*_t12*_t217*_t43*_t68*_t81 - _t130*_t264 - _t144*_t285 - _t152*_t182 - _t206*_t286 - _t236*_t286 - _t281*_t287 - _t285*_t88);
  const double v4rho2sigmatau_17 = _t186*_t47 + _t22*((0.8e1 / 0.3e1)*_hc4[2]*_hc5[1]*_hc6[1]*_hc8[3]*_t10*_t230*_t73 + (0.8e1 / 0.3e1)*_hc5[2]*_hc6[1]*_hc8[3]*_t10*_t109*_t230*_t73 - _t108*_t288 + (0.1e1 / 0.2e1)*_t12*_t233*_t59*_t76*_t84 - _t137*_t266 - _t149*_t288 - _t154*_t185 - _t224*_t289 - _t245*_t289 - _t284*_t287);
  const double v4rho2lapl2_0 = -_t291*_t292 - _t291*_t293 + _t9*((0.32e2 / 0.3e1)*_hc1[2]*_hc2[1]*_t10*_t187*_t94 + (0.32e2 / 0.3e1)*_hc2[2]*_t10*_t187*_t89*_t94 - _t294*_t295 - _t295*_t296 - _t295*_t297);
  const double v4rho2lapl2_8 = -_t110*_t298 - _t134*_t298 + _t22*((0.32e2 / 0.3e1)*_hc4[2]*_hc5[1]*_t10*_t113*_t187 + (0.32e2 / 0.3e1)*_hc5[2]*_t10*_t109*_t113*_t187 - _t299*_t300 - _t300*_t301 - _t300*_t302);
  const double v4rho2lapltau_0 = -_t292*_t303 - _t293*_t303 + _t9*((0.32e2 / 0.3e1)*_hc1[2]*_hc2[1]*_hc6[1]*_hc6[2]*_t10*_t94 + (0.32e2 / 0.3e1)*_hc2[2]*_hc6[1]*_hc6[2]*_t10*_t89*_t94 - _t269*_t306*_t41 - _t294*_t304 - _t297*_t304);
  const double v4rho2lapltau_11 = -_t110*_t307 - _t134*_t307 + _t22*((0.32e2 / 0.3e1)*_hc4[2]*_hc5[1]*_hc6[1]*_hc6[2]*_t10*_t113 + (0.32e2 / 0.3e1)*_hc5[2]*_hc6[1]*_hc6[2]*_t10*_t109*_t113 - _t275*_t306*_t57 - _t299*_t308 - _t302*_t308);
  const double v4rho2tau2_0 = _t196*_t31 + _t9*((0.32e2 / 0.3e1)*_hc1[2]*_hc2[1]*_t10*_t193*_t94 + (0.32e2 / 0.3e1)*_hc2[2]*_t10*_t193*_t89*_t94 + (0.1e1 / 0.2e1)*_t12*_t195*_t217*_t43 - _t152*_t271*_t81 - _t194*_t294 - _t194*_t296 - _t194*_t297);
  const double v4rho2tau2_8 = _t199*_t47 + _t22*((0.32e2 / 0.3e1)*_hc4[2]*_hc5[1]*_t10*_t113*_t193 + (0.32e2 / 0.3e1)*_hc5[2]*_t10*_t109*_t113*_t193 + (0.1e1 / 0.2e1)*_t12*_t198*_t233*_t59 - _t154*_t277*_t84 - _t197*_t299 - _t197*_t301 - _t197*_t302);
  const double v4rhosigma3_0 = _t9*(_hc1[1]*_hc2[1]*_hc6[9]*_t10*_t16*_t309 + _hc1[2]*_hc2[1]*_t10*_t16*_t161*_t309 + _hc2[2]*_t10*_t16*_t161*_t309*_t89 - _hc7[3]*_t64/xc_powr(gaa, 5, 2) - _t10*_t204*_t313 + (0.1e1 / 0.2e1)*_t12*_t217*(_t68 * _t68 * _t68) - _t206*_t314 - _t236*_t314 - _t292*_t311 - _t293*_t311);
  const double v4rhosigma3_19 = _t22*(_hc4[1]*_hc5[1]*_hc6[9]*_t10*_t24*_t315 + _hc4[2]*_hc5[1]*_t10*_t169*_t24*_t315 + _hc5[2]*_t10*_t109*_t169*_t24*_t315 - _hc8[3]*_t72/xc_powr(gbb, 5, 2) - _t10*_t222*_t318 - _t110*_t316*_t317 + (0.1e1 / 0.2e1)*_t12*_t233*(_t76 * _t76 * _t76) - _t134*_t316*_t317 - _t224*_t319 - _t245*_t319);
  const double v4rhosigma2lapl_0 = _t9*((0.2e1 / 0.3e1)*_hc1[2]*_hc2[1]*_hc6[2]*_hc7[3]*_t10*_t160*_t96 + (0.2e1 / 0.3e1)*_hc2[2]*_hc6[2]*_hc7[3]*_t10*_t160*_t89*_t96 - _t126*_t140*_t321 - _t140*_t321*_t90 - _t206*_t323 - _t236*_t323 - _t324*_t325);
  const double v4rhosigma2lapl_23 = _t22*((0.2e1 / 0.3e1)*_hc4[2]*_hc5[1]*_hc6[2]*_hc8[3]*_t10*_t115*_t168 + (0.2e1 / 0.3e1)*_hc5[2]*_hc6[2]*_hc8[3]*_t10*_t109*_t115*_t168 - _t110*_t328 - _t134*_t328 - _t224*_t329 - _t245*_t329 - _t324*_t330);
  const double v4rhosigma2tau_0 = _t9*((0.2e1 / 0.3e1)*_hc1[2]*_hc2[1]*_hc6[1]*_hc7[3]*_t10*_t160*_t96 + (0.2e1 / 0.3e1)*_hc2[2]*_hc6[1]*_hc7[3]*_t10*_t160*_t89*_t96 + (0.1e1 / 0.2e1)*_t12*_t163*_t217*_t81 - _t126*_t331 - _t206*_t332 - _t236*_t332 - _t325*_t333 - _t331*_t90);
  const double v4rhosigma2tau_23 = _t22*((0.2e1 / 0.3e1)*_hc4[2]*_hc5[1]*_hc6[1]*_hc8[3]*_t10*_t115*_t168 + (0.2e1 / 0.3e1)*_hc5[2]*_hc6[1]*_hc8[3]*_t10*_t109*_t115*_t168 - _t110*_t335 + (0.1e1 / 0.2e1)*_t12*_t171*_t233*_t84 - _t134*_t335 - _t224*_t336 - _t245*_t336 - _t330*_t333);
  const double v4rhosigmalapl2_0 = _t9*(-_t290*_t341 - _t338*_t339 - _t339*_t342);
  const double v4rhosigmalapl2_17 = _t22*(-_t290*_t347 - _t344*_t345 - _t345*_t348);
  const double v4rhosigmalapltau_0 = _t9*(-_t305*_t341 - _t338*_t349 - _t342*_t349);
  const double v4rhosigmalapltau_23 = _t22*(-_t305*_t347 - _t344*_t350 - _t348*_t350);
  const double v4rhosigmatau2_0 = _t9*((0.1e1 / 0.2e1)*_t12*_t195*_t217*_t68 - _t338*_t352 - _t341*_t351 - _t342*_t352);
  const double v4rhosigmatau2_17 = _t22*((0.1e1 / 0.2e1)*_t12*_t198*_t233*_t76 - _t344*_t353 - _t347*_t351 - _t348*_t353);
  const double v4rholapl3_0 = -_t201*_t355 - _t205*_t355 - _t207*_t355;
  const double v4rholapl3_7 = -_t220*_t356 - _t223*_t356 - _t225*_t356;
  const double v4rholapl2tau_0 = -_t340*_t359 - _t357*_t358 - _t357*_t360;
  const double v4rholapl2tau_11 = -_t220*_t361 - _t225*_t361 - _t346*_t359;
  const double v4rholapltau2_0 = -_t193*_t254*_t340 - _t358*_t362 - _t360*_t362;
  const double v4rholapltau2_11 = -_t193*_t260*_t343 - _t220*_t363 - _t225*_t363;
  const double v4rhotau3_0 = _t9*((0.1e1 / 0.2e1)*_t12*_t217*(_t81 * _t81 * _t81) - _t201*_t365 - _t205*_t365 - _t207*_t365);
  const double v4rhotau3_7 = _t22*((0.1e1 / 0.2e1)*_t12*_t233*(_t84 * _t84 * _t84) - _t220*_t366 - _t223*_t366 - _t225*_t366);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += v4rho4_0;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += v4rho4_4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += v4rho3sigma_0;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += v4rho3sigma_11;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += v4rho3lapl_0;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 7] += v4rho3lapl_7;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += v4rho3tau_0;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 7] += v4rho3tau_7;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += v4rho2sigma2_0;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += v4rho2sigma2_17;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 0] += v4rho2sigmalapl_0;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 17] += v4rho2sigmalapl_17;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += v4rho2sigmatau_0;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 17] += v4rho2sigmatau_17;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += v4rho2lapl2_0;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 8] += v4rho2lapl2_8;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 0] += v4rho2lapltau_0;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 11] += v4rho2lapltau_11;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += v4rho2tau2_0;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 8] += v4rho2tau2_8;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += v4rhosigma3_0;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += v4rhosigma3_19;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 0] += v4rhosigma2lapl_0;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 23] += v4rhosigma2lapl_23;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += v4rhosigma2tau_0;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 23] += v4rhosigma2tau_23;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 0] += v4rhosigmalapl2_0;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 17] += v4rhosigmalapl2_17;
  if(out->v4rhosigmalapltau != NULL) out->v4rhosigmalapltau[ip*p->dim.v4rhosigmalapltau + 0] += v4rhosigmalapltau_0;
  if(out->v4rhosigmalapltau != NULL) out->v4rhosigmalapltau[ip*p->dim.v4rhosigmalapltau + 23] += v4rhosigmalapltau_23;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += v4rhosigmatau2_0;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 17] += v4rhosigmatau2_17;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += v4rholapl3_0;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 7] += v4rholapl3_7;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 0] += v4rholapl2tau_0;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 11] += v4rholapl2tau_11;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 0] += v4rholapltau2_0;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 11] += v4rholapltau2_11;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += v4rhotau3_0;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 7] += v4rhotau3_7;
#endif
#endif
}
#endif