/*
  Generated from python/mgga_exc/mgga_x_2d_prhg07.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_2d_prhg07
*/

#ifndef _MGGA_X_2D_PRHG07_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_2D_PRHG07_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_2D_PRHG07_HELPER_BODIES
#include "mgga_x_2d_prhg07.c"
#undef _MGGA_X_2D_PRHG07_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_2D_PRHG07_HELPER_BODIES
#include "mgga_x_2d_prhg07.c"
#undef _MGGA_X_2D_PRHG07_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_2D_PRHG07_HELPER_BODIES
#include "mgga_x_2d_prhg07.c"
#undef _MGGA_X_2D_PRHG07_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_2D_PRHG07_HELPER_BODIES
#include "mgga_x_2d_prhg07.c"
#undef _MGGA_X_2D_PRHG07_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_2D_PRHG07_HELPER_BODIES
#include "mgga_x_2d_prhg07.c"
#undef _MGGA_X_2D_PRHG07_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_2d_prhg07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_2d_prhg07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_2d_prhg07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_2d_prhg07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_2d_prhg07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_2d_prhg07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_2d_prhg07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_2d_prhg07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_2d_prhg07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_2d_prhg07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_2D_PRHG07_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_m1_n3_2_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z - p->zeta_threshold + 0.1e1;
  const double _t2 = _t1 <= 0;
  const double _t3 = _t1 > 0;
  const double _t4 = my_piecewise3(_t3, z, p->zeta_threshold - 0.1e1);
  const double _t5 = xc_expm1((0.3e1 / 0.2e1)*xc_log1p(_t4));
#if _KMAX >= 1
  const double _t6 = my_piecewise3(_t3, 0.1e1, 0);
  const double _t7 = _t4 + 0.1e1;
  const double _t8 = _t5 + 0.1e1;
#endif

  const double f = my_piecewise3(_t2, xc_powr(p->zeta_threshold, 3, 2) - 0.1e1, _t5);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise3(_t2, 0, (0.3e1 / 0.2e1)*_t6*_t8/_t7);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise3(_t2, 0, (0.3e1 / 0.4e1)*(_t6 * _t6)*_t8/(_t7 * _t7));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise3(_t2, 0, -0.3e1 / 0.8e1*(_t6 * _t6 * _t6)*_t8/(_t7 * _t7 * _t7));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = my_piecewise3(_t2, 0, (0.9e1 / 0.16e2)*(_t6 * _t6 * _t6 * _t6)*_t8/(_t7 * _t7 * _t7 * _t7));
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(prhg07_C_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double t, double *out) {


  const double f = -t + (0.1e1 / 0.4e1)*u + (0.1e1 / 0.8e1)*x2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -0.1e1;
  out[1] = df_dt;
  const double df_du = 0.1e1 / 0.4e1;
  out[2] = df_du;
  const double df_dx2 = 0.1e1 / 0.8e1;
  out[3] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dx2_dt = 0;
  out[7] = d2f_dx2_dt;
  const double d2f_dx2_du = 0;
  out[8] = d2f_dx2_du;
  const double d2f_dx22 = 0;
  out[9] = d2f_dx22;
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
  const double d3f_dx2_dt2 = 0;
  out[14] = d3f_dx2_dt2;
  const double d3f_dx2_du_dt = 0;
  out[15] = d3f_dx2_du_dt;
  const double d3f_dx2_du2 = 0;
  out[16] = d3f_dx2_du2;
  const double d3f_dx22_dt = 0;
  out[17] = d3f_dx22_dt;
  const double d3f_dx22_du = 0;
  out[18] = d3f_dx22_du;
  const double d3f_dx23 = 0;
  out[19] = d3f_dx23;
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
  const double d4f_dx2_dt3 = 0;
  out[25] = d4f_dx2_dt3;
  const double d4f_dx2_du_dt2 = 0;
  out[26] = d4f_dx2_du_dt2;
  const double d4f_dx2_du2_dt = 0;
  out[27] = d4f_dx2_du2_dt;
  const double d4f_dx2_du3 = 0;
  out[28] = d4f_dx2_du3;
  const double d4f_dx22_dt2 = 0;
  out[29] = d4f_dx22_dt2;
  const double d4f_dx22_du_dt = 0;
  out[30] = d4f_dx22_du_dt;
  const double d4f_dx22_du2 = 0;
  out[31] = d4f_dx22_du2;
  const double d4f_dx23_dt = 0;
  out[32] = d4f_dx23_dt;
  const double d4f_dx23_du = 0;
  out[33] = d4f_dx23_du;
  const double d4f_dx24 = 0;
  out[34] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(prhg07_f_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(prhg07_C_pf_k, _KMAX)(p, x2, u, t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(prhg07_y_k, _KMAX)(p, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(prhg07_v_k, _KMAX)(p, _hc1[0], _hc2);
#if _KMAX >= 1
  const double _t1 = (0.1e1 / 0.2e1)*_hc2[1];
  const double _t2 = _hc0[1]*_hc1[1];
  const double _t3 = _hc1[1]*_t1;
#endif
#if _KMAX >= 2
  const double _t4 = ((_hc0[1]) * (_hc0[1]));
  const double _t5 = _hc1[2]*_t1;
  const double _t6 = (0.1e1 / 0.2e1)*_t4;
  const double _t7 = ((_hc1[1]) * (_hc1[1]));
  const double _t8 = _hc2[2]*_t7;
  const double _t9 = _hc0[1]*_hc0[2];
  const double _t10 = (0.1e1 / 0.2e1)*_t8;
  const double _t11 = ((_hc0[2]) * (_hc0[2]));
  const double _t12 = _hc0[1]*_hc0[3];
  const double _t13 = _hc0[2]*_hc0[3];
  const double _t14 = ((_hc0[3]) * (_hc0[3]));
#endif
#if _KMAX >= 3
  const double _t15 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t16 = _hc1[3]*_t1;
  const double _t17 = (0.3e1 / 0.2e1)*_hc2[2];
  const double _t18 = _hc1[2]*_t17;
  const double _t19 = _hc1[1]*_t15;
  const double _t20 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_hc2[3];
  const double _t21 = (0.1e1 / 0.2e1)*_t15;
  const double _t22 = _t16*_t4;
  const double _t23 = _hc1[1]*_t18;
  const double _t24 = _t23*_t4;
  const double _t25 = _t20*_t6;
  const double _t26 = _hc0[1]*_t11;
  const double _t27 = _t18*_t2;
  const double _t28 = (0.1e1 / 0.2e1)*_t20;
  const double _t29 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t30 = _hc0[3]*_t9;
  const double _t31 = _hc0[3]*_t11;
  const double _t32 = _hc0[1]*_t14;
  const double _t33 = _hc0[2]*_t14;
  const double _t34 = ((_hc0[3]) * (_hc0[3]) * (_hc0[3]));
#endif
#if _KMAX >= 4
  const double _t35 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t36 = _hc1[4]*_t1;
  const double _t37 = 0.2e1*_hc1[3]*_hc2[2];
  const double _t38 = _hc1[1]*_t37;
  const double _t39 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_hc2[4];
  const double _t40 = (0.1e1 / 0.2e1)*_t39;
  const double _t41 = ((_hc1[2]) * (_hc1[2]))*_t17;
  const double _t42 = 0.3e1*_hc1[2]*_hc2[3]*_t7;
  const double _t43 = _hc0[2]*_t15;
  const double _t44 = _t19*_t37;
  const double _t45 = _t21*_t39;
  const double _t46 = _t11*_t4;
  const double _t47 = _t39*_t6;
  const double _t48 = _hc0[1]*_t29;
  const double _t49 = _t2*_t37;
  const double _t50 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t51 = _hc0[3]*_t15;
  const double _t52 = _t13*_t4;
  const double _t53 = _t11*_t12;
  const double _t54 = _hc0[3]*_t29;
  const double _t55 = _t14*_t4;
  const double _t56 = _t14*_t9;
  const double _t57 = _t11*_t14;
  const double _t58 = _hc0[1]*_t34;
  const double _t59 = _hc0[2]*_t34;
  const double _t60 = ((_hc0[3]) * (_hc0[3]) * (_hc0[3]) * (_hc0[3]));
#endif

  const double f = (0.1e1 / 0.2e1)*_hc2[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t1*_t2;
  out[1] = df_dt;
  const double df_du = _hc0[2]*_t3;
  out[2] = df_du;
  const double df_dx2 = _hc0[3]*_t3;
  out[3] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t4*_t5 + _t6*_t8;
  out[4] = d2f_dt2;
  const double d2f_du_dt = _t10*_t9 + _t5*_t9;
  out[5] = d2f_du_dt;
  const double d2f_du2 = _t10*_t11 + _t11*_t5;
  out[6] = d2f_du2;
  const double d2f_dx2_dt = _t10*_t12 + _t12*_t5;
  out[7] = d2f_dx2_dt;
  const double d2f_dx2_du = _t10*_t13 + _t13*_t5;
  out[8] = d2f_dx2_du;
  const double d2f_dx22 = _t10*_t14 + _t14*_t5;
  out[9] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t15*_t16 + _t18*_t19 + _t20*_t21;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = _hc0[2]*_t22 + _hc0[2]*_t24 + _hc0[2]*_t25;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = _t11*_t27 + _t16*_t26 + _t26*_t28;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = _t16*_t29 + _t23*_t29 + _t28*_t29;
  out[13] = d3f_du3;
  const double d3f_dx2_dt2 = _hc0[3]*_t22 + _hc0[3]*_t24 + _hc0[3]*_t25;
  out[14] = d3f_dx2_dt2;
  const double d3f_dx2_du_dt = _t13*_t27 + _t16*_t30 + _t28*_t30;
  out[15] = d3f_dx2_du_dt;
  const double d3f_dx2_du2 = _t16*_t31 + _t23*_t31 + _t28*_t31;
  out[16] = d3f_dx2_du2;
  const double d3f_dx22_dt = _t14*_t27 + _t16*_t32 + _t28*_t32;
  out[17] = d3f_dx22_dt;
  const double d3f_dx22_du = _t16*_t33 + _t23*_t33 + _t28*_t33;
  out[18] = d3f_dx22_du;
  const double d3f_dx23 = _t16*_t34 + _t23*_t34 + _t28*_t34;
  out[19] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _t35*_t36 + _t35*_t38 + _t35*_t40 + _t35*_t41 + _t35*_t42;
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = _hc0[2]*_t44 + _hc0[2]*_t45 + _t36*_t43 + _t41*_t43 + _t42*_t43;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = _t11*_t47 + _t36*_t46 + _t38*_t46 + _t41*_t46 + _t42*_t46;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = _t29*_t49 + _t36*_t48 + _t40*_t48 + _t41*_t48 + _t42*_t48;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = _t36*_t50 + _t38*_t50 + _t40*_t50 + _t41*_t50 + _t42*_t50;
  out[24] = d4f_du4;
  const double d4f_dx2_dt3 = _hc0[3]*_t44 + _hc0[3]*_t45 + _t36*_t51 + _t41*_t51 + _t42*_t51;
  out[25] = d4f_dx2_dt3;
  const double d4f_dx2_du_dt2 = _t13*_t47 + _t36*_t52 + _t38*_t52 + _t41*_t52 + _t42*_t52;
  out[26] = d4f_dx2_du_dt2;
  const double d4f_dx2_du2_dt = _t31*_t49 + _t36*_t53 + _t40*_t53 + _t41*_t53 + _t42*_t53;
  out[27] = d4f_dx2_du2_dt;
  const double d4f_dx2_du3 = _t36*_t54 + _t38*_t54 + _t40*_t54 + _t41*_t54 + _t42*_t54;
  out[28] = d4f_dx2_du3;
  const double d4f_dx22_dt2 = _t14*_t47 + _t36*_t55 + _t38*_t55 + _t41*_t55 + _t42*_t55;
  out[29] = d4f_dx22_dt2;
  const double d4f_dx22_du_dt = _t33*_t49 + _t36*_t56 + _t40*_t56 + _t41*_t56 + _t42*_t56;
  out[30] = d4f_dx22_du_dt;
  const double d4f_dx22_du2 = _t36*_t57 + _t38*_t57 + _t40*_t57 + _t41*_t57 + _t42*_t57;
  out[31] = d4f_dx22_du2;
  const double d4f_dx23_dt = _t34*_t49 + _t36*_t58 + _t40*_t58 + _t41*_t58 + _t42*_t58;
  out[32] = d4f_dx23_dt;
  const double d4f_dx23_du = _t36*_t59 + _t38*_t59 + _t40*_t59 + _t41*_t59 + _t42*_t59;
  out[33] = d4f_dx23_du;
  const double d4f_dx24 = _t36*_t60 + _t38*_t60 + _t40*_t60 + _t41*_t60 + _t42*_t60;
  out[34] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n3_2_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  const double _t1 = (0.1e1 / (n_s * n_s * n_s));
  const double _t2 = (0.1e1 / (n_s * n_s));
  const double _t3 = -p->dens_threshold + n_s <= 0;
  const double _t4 = xc_powr(n_s, 1, 2);
  const double _t5 = xc_powr(0.2e1, 1, 2);
  const double _t6 = xc_powr(M_PI, -1, 2);
  const double _t7 = _hc0[0] + 0.1e1;
  const double _t8 = _t5*_t6*_t7;
  const double _t9 = (0.2e1 / 0.3e1)*_t8;
  const double _t10 = _t4*_t9;
#if _KMAX >= 1
  const double _t12 = xc_powr(n_s, -3, 2);
  const double _t13 = (0.2e1 / 0.3e1)*_t12*_t8;
  const double _t16 = _t8/xc_powr(n_s, 5, 2);
  const double _t18 = _t8/_t4;
  const double _t19 = 0.2e1*_t1;
  const double _t22 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t23 = 0.3e1*_t22;
#endif
#if _KMAX >= 2
  const double _t27 = xc_powr(n_s, -7, 2);
  const double _t28 = _t27*_t9;
  const double _t32 = xc_powr(n_s, -9, 2);
  const double _t33 = _t32*_t9;
  const double _t36 = xc_powr(n_s, -11, 2);
  const double _t37 = _t36*_t9;
  const double _t39 = (0.1e1 / 0.3e1)*_t16;
  const double _t40 = xc_powi(n_s, -5);
  const double _t41 = 0.2e1*_t40;
  const double _t44 = 0.3e1*sigma_ss;
  const double _t45 = xc_powi(n_s, -6);
  const double _t49 = _t41*lapl_s;
  const double _t53 = (0.1e1 / 0.3e1)*_t8;
  const double _t54 = 0.2e1*tau_s;
  const double _t55 = 0.2e1*lapl_s;
  const double _t56 = xc_powi(n_s, -7);
  const double _t57 = _t44*_t56;
  const double _t60 = (0.2e1 / 0.3e1)*_t18;
  const double _t61 = 0.6e1*_t22;
  const double _t64 = 0.12e2*_t40;
#endif
#if _KMAX >= 3
  const double _t86 = xc_powr(n_s, -13, 2);
  const double _t87 = _t86*_t9;
  const double _t91 = xc_powr(n_s, -15, 2);
  const double _t92 = _t9*_t91;
  const double _t95 = xc_powr(n_s, -17, 2);
  const double _t96 = _t9*_t95;
  const double _t98 = _t32*_t53;
  const double _t99 = 0.4e1*_t40;
  const double _t100 = _t54*_t56;
  const double _t101 = _t55*_t56;
  const double _t102 = xc_powi(n_s, -8);
  const double _t103 = _t102*_t44;
  const double _t110 = _t36*_t53;
  const double _t111 = 0.5e1*_t45;
  const double _t112 = _t102*_t54;
  const double _t113 = _t102*_t55;
  const double _t114 = xc_powi(n_s, -9);
  const double _t115 = _t114*_t44;
  const double _t120 = _t53*_t86;
  const double _t121 = 0.6e1*_t56;
  const double _t124 = xc_powi(n_s, -10);
  const double _t128 = 0.6e1*_t45;
  const double _t130 = 0.12e2*sigma_ss;
  const double _t131 = _t130*_t56;
  const double _t132 = _t41*tau_s;
  const double _t133 = _t44*_t45;
  const double _t135 = _t19*lapl_s;
  const double _t139 = _t19*tau_s;
  const double _t142 = _t128*lapl_s;
  const double _t151 = _t45*_t54;
  const double _t152 = _t45*_t55;
  const double _t156 = _t23*sigma_ss;
  const double _t161 = 0.24e2*_t40;
  const double _t164 = 0.60e2*_t45;
#endif
#if _KMAX >= 4
  const double _t211 = xc_powr(n_s, -19, 2);
  const double _t212 = _t211*_t9;
  const double _t213 = _t9/xc_powr(n_s, 21, 2);
  const double _t214 = _t114*_t54;
  const double _t215 = _t114*_t55;
  const double _t216 = _t124*_t44;
  const double _t217 = _t53*_t91;
  const double _t218 = 0.7e1*_t102;
  const double _t219 = _t124*_t54;
  const double _t220 = _t124*_t55;
  const double _t221 = xc_powi(n_s, -11);
  const double _t222 = _t221*_t44;
  const double _t223 = _t53*_t95;
  const double _t224 = 0.8e1*_t114;
  const double _t225 = _t221*_t54;
  const double _t226 = _t221*_t55;
  const double _t227 = xc_powi(n_s, -12);
  const double _t228 = _t227*_t44;
  const double _t229 = 0.12e2*_t45;
  const double _t230 = 0.6e1*_t102;
  const double _t233 = _t114*_t130;
  const double _t234 = 0.4e1*_t1;
  const double _t240 = 0.6e1*_t124;
  const double _t246 = (0.1e1 / 0.4e1)*_t8;
  const double _t247 = _t246*_t32;
  const double _t248 = 0.24e2*_t56;
  const double _t250 = 0.60e2*sigma_ss;
  const double _t251 = _t102*_t250;
  const double _t252 = _t128*tau_s;
  const double _t261 = 0.24e2*_t102;
  const double _t264 = _t102*_t130;
  const double _t268 = 0.120e3*_t45;
  const double _t269 = 0.72e2*_t40;
  const double _t270 = 0.18e2*_t22;
  const double _t272 = _t164*sigma_ss;
  const double _t273 = _t61*tau_s;
  const double _t274 = _t64*sigma_ss;
  const double _t281 = _t61*lapl_s;
#endif
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t3)) XC_CAT(prhg07_f_pf_k, _KMAX)(p, _t1*sigma_ss, _t2*lapl_s, _t2*tau_s, _hc1);
  const double _t11 = my_piecewise3(_t3, 0, -_hc1[0]*_t10);
#if _KMAX >= 1
  const double _t14 = my_piecewise3(_t3, 0, -_hc1[1]*_t13);
  const double _t15 = my_piecewise3(_t3, 0, -_hc1[2]*_t13);
  const double _t17 = my_piecewise3(_t3, 0, -0.2e1 / 0.3e1*_hc1[3]*_t16);
  const double _t20 = _hc1[1]*_t19;
  const double _t21 = _hc1[2]*_t19;
  const double _t24 = _hc1[3]*_t23;
  const double _t25 = -_t20*tau_s - _t21*lapl_s - _t24*sigma_ss;
  const double _t26 = my_piecewise3(_t3, 0, -0.1e1 / 0.3e1*_hc1[0]*_t18 - _t10*_t25);
#endif
#if _KMAX >= 2
  const double _t29 = my_piecewise3(_t3, 0, -_hc1[4]*_t28);
  const double _t30 = my_piecewise3(_t3, 0, -_hc1[5]*_t28);
  const double _t31 = my_piecewise3(_t3, 0, -_hc1[6]*_t28);
  const double _t34 = my_piecewise3(_t3, 0, -_hc1[7]*_t33);
  const double _t35 = my_piecewise3(_t3, 0, -_hc1[8]*_t33);
  const double _t38 = my_piecewise3(_t3, 0, -_hc1[9]*_t37);
  const double _t42 = _hc1[4]*tau_s;
  const double _t43 = _hc1[5]*_t41;
  const double _t46 = _hc1[7]*_t45;
  const double _t47 = -_t20 - _t41*_t42 - _t43*lapl_s - _t44*_t46;
  const double _t48 = my_piecewise3(_t3, 0, -_hc1[1]*_t39 - _t10*_t47);
  const double _t50 = _hc1[8]*_t45;
  const double _t51 = -_hc1[6]*_t49 - _t21 - _t43*tau_s - _t44*_t50;
  const double _t52 = my_piecewise3(_t3, 0, -_hc1[2]*_t39 - _t10*_t51);
  const double _t58 = -_hc1[9]*_t57 - _t24 - _t46*_t54 - _t50*_t55;
  const double _t59 = my_piecewise3(_t3, 0, -_hc1[3]*_t27*_t53 - _t10*_t58);
  const double _t62 = _hc1[1]*_t61;
  const double _t63 = _hc1[2]*_t61;
  const double _t65 = _hc1[3]*_t64;
  const double _t66 = _hc1[5]*_t19;
  const double _t67 = _hc1[6]*_t19;
  const double _t68 = _hc1[8]*_t23;
  const double _t69 = -_t66*tau_s - _t67*lapl_s - _t68*sigma_ss;
  const double _t70 = _t19*_t69;
  const double _t71 = _hc1[7]*_t19;
  const double _t72 = _hc1[8]*_t19;
  const double _t73 = _hc1[9]*_t23;
  const double _t74 = -_t71*tau_s - _t72*lapl_s - _t73*sigma_ss;
  const double _t75 = _t23*_t74;
  const double _t76 = _hc1[4]*_t19;
  const double _t77 = _hc1[7]*_t23;
  const double _t78 = -_t66*lapl_s - _t76*tau_s - _t77*sigma_ss;
  const double _t79 = _t19*_t78;
  const double _t80 = _t62*tau_s + _t63*lapl_s + _t65*sigma_ss - _t70*lapl_s - _t75*sigma_ss - _t79*tau_s;
  const double _t81 = my_piecewise3(_t3, 0, (0.1e1 / 0.6e1)*_hc1[0]*_t12*_t5*_t6*_t7 - _t10*_t80 - _t25*_t60);
#endif
#if _KMAX >= 3
  const double _t82 = my_piecewise3(_t3, 0, -_hc1[10]*_t37);
  const double _t83 = my_piecewise3(_t3, 0, -_hc1[11]*_t37);
  const double _t84 = my_piecewise3(_t3, 0, -_hc1[12]*_t37);
  const double _t85 = my_piecewise3(_t3, 0, -_hc1[13]*_t37);
  const double _t88 = my_piecewise3(_t3, 0, -_hc1[14]*_t87);
  const double _t89 = my_piecewise3(_t3, 0, -_hc1[15]*_t87);
  const double _t90 = my_piecewise3(_t3, 0, -_hc1[16]*_t87);
  const double _t93 = my_piecewise3(_t3, 0, -_hc1[17]*_t92);
  const double _t94 = my_piecewise3(_t3, 0, -_hc1[18]*_t92);
  const double _t97 = my_piecewise3(_t3, 0, -_hc1[19]*_t96);
  const double _t104 = -_hc1[10]*_t100 - _hc1[11]*_t101 - _hc1[14]*_t103 - _hc1[4]*_t99;
  const double _t105 = my_piecewise3(_t3, 0, -_hc1[4]*_t98 - _t10*_t104);
  const double _t106 = -_hc1[11]*_t100 - _hc1[12]*_t101 - _hc1[15]*_t103 - _hc1[5]*_t99;
  const double _t107 = my_piecewise3(_t3, 0, -_hc1[5]*_t98 - _t10*_t106);
  const double _t108 = -_hc1[12]*_t100 - _hc1[13]*_t101 - _hc1[16]*_t103 - _hc1[6]*_t99;
  const double _t109 = my_piecewise3(_t3, 0, -_hc1[6]*_t98 - _t10*_t108);
  const double _t116 = -_hc1[14]*_t112 - _hc1[15]*_t113 - _hc1[17]*_t115 - _hc1[7]*_t111;
  const double _t117 = my_piecewise3(_t3, 0, -_hc1[7]*_t110 - _t10*_t116);
  const double _t118 = -_hc1[15]*_t112 - _hc1[16]*_t113 - _hc1[18]*_t115 - _hc1[8]*_t111;
  const double _t119 = my_piecewise3(_t3, 0, -_hc1[8]*_t110 - _t10*_t118);
  const double _t122 = _hc1[17]*_t54;
  const double _t123 = _hc1[18]*_t55;
  const double _t125 = _hc1[19]*_t124;
  const double _t126 = -_hc1[9]*_t121 - _t114*_t122 - _t114*_t123 - _t125*_t44;
  const double _t127 = my_piecewise3(_t3, 0, -_hc1[9]*_t120 - _t10*_t126);
  const double _t129 = _hc1[5]*_t128;
  const double _t134 = -_hc1[11]*_t132 - _hc1[12]*_t49 - _hc1[15]*_t133 - _t66;
  const double _t136 = -_hc1[14]*_t132 - _hc1[15]*_t49 - _hc1[17]*_t133 - _t71;
  const double _t137 = _t136*_t23;
  const double _t138 = -_hc1[10]*_t132 - _hc1[11]*_t49 - _hc1[14]*_t133 - _t76;
  const double _t140 = _hc1[7]*_t131 + _t128*_t42 + _t129*lapl_s - _t134*_t135 - _t137*sigma_ss - _t138*_t139 + _t62 - _t79;
  const double _t141 = my_piecewise3(_t3, 0, (0.1e1 / 0.6e1)*_hc1[1]*_t27*_t5*_t6*_t7 - _t10*_t140 - _t47*_t60);
  const double _t143 = -_hc1[12]*_t132 - _hc1[13]*_t49 - _hc1[16]*_t133 - _t67;
  const double _t144 = -_hc1[15]*_t132 - _hc1[16]*_t49 - _hc1[18]*_t133 - _t72;
  const double _t145 = _t144*_t23;
  const double _t146 = _hc1[6]*_t142 + _hc1[8]*_t131 + _t129*tau_s - _t134*_t139 - _t135*_t143 - _t145*sigma_ss + _t63 - _t70;
  const double _t147 = my_piecewise3(_t3, 0, (0.1e1 / 0.6e1)*_hc1[2]*_t27*_t5*_t6*_t7 - _t10*_t146 - _t51*_t60);
  const double _t148 = _hc1[7]*tau_s;
  const double _t149 = _hc1[8]*lapl_s;
  const double _t150 = _hc1[9]*_t102;
  const double _t153 = -_hc1[15]*_t151 - _hc1[16]*_t152 - _hc1[18]*_t57 - _t68;
  const double _t154 = _t153*_t19;
  const double _t155 = -_hc1[19]*_t57 - _t122*_t45 - _t123*_t45 - _t73;
  const double _t157 = -_hc1[14]*_t151 - _hc1[15]*_t152 - _hc1[17]*_t57 - _t77;
  const double _t158 = _t157*_t19;
  const double _t159 = _t121*_t148 + _t121*_t149 + _t130*_t150 - _t154*lapl_s - _t155*_t156 - _t158*tau_s + _t65 - _t75;
  const double _t160 = my_piecewise3(_t3, 0, (0.1e1 / 0.6e1)*_hc1[3]*_t32*_t5*_t6*_t7 - _t10*_t159 - _t58*_t60);
  const double _t162 = _hc1[1]*_t161;
  const double _t163 = _hc1[2]*_t161;
  const double _t165 = _hc1[3]*_t164;
  const double _t166 = _hc1[5]*_t61;
  const double _t167 = _hc1[6]*_t61;
  const double _t168 = _hc1[8]*_t64;
  const double _t169 = _hc1[12]*_t19;
  const double _t170 = _hc1[13]*_t19;
  const double _t171 = _hc1[16]*_t23;
  const double _t172 = -_t169*tau_s - _t170*lapl_s - _t171*sigma_ss;
  const double _t173 = _t172*_t19;
  const double _t174 = _hc1[15]*_t19;
  const double _t175 = _hc1[16]*_t19;
  const double _t176 = _hc1[18]*_t23;
  const double _t177 = -_t174*tau_s - _t175*lapl_s - _t176*sigma_ss;
  const double _t178 = _t177*_t23;
  const double _t179 = _hc1[11]*_t19;
  const double _t180 = _hc1[15]*_t23;
  const double _t181 = -_t169*lapl_s - _t179*tau_s - _t180*sigma_ss;
  const double _t182 = _t181*_t19;
  const double _t183 = _t166*tau_s + _t167*lapl_s + _t168*sigma_ss - _t173*lapl_s - _t178*sigma_ss - _t182*tau_s;
  const double _t184 = _t183*_t19;
  const double _t185 = _hc1[7]*_t61;
  const double _t186 = _hc1[8]*_t61;
  const double _t187 = _hc1[9]*_t64;
  const double _t188 = _t177*_t19;
  const double _t189 = _hc1[17]*_t19;
  const double _t190 = _hc1[18]*_t19;
  const double _t191 = _hc1[19]*_t23;
  const double _t192 = -_t189*tau_s - _t190*lapl_s - _t191*sigma_ss;
  const double _t193 = _t192*_t23;
  const double _t194 = _hc1[14]*_t19;
  const double _t195 = _hc1[17]*_t23;
  const double _t196 = -_t174*lapl_s - _t194*tau_s - _t195*sigma_ss;
  const double _t197 = _t19*_t196;
  const double _t198 = _t185*tau_s + _t186*lapl_s + _t187*sigma_ss - _t188*lapl_s - _t193*sigma_ss - _t197*tau_s;
  const double _t199 = _t198*_t23;
  const double _t200 = _hc1[4]*_t61;
  const double _t201 = _hc1[7]*_t64;
  const double _t202 = _t196*_t23;
  const double _t203 = _hc1[10]*_t19;
  const double _t204 = _hc1[14]*_t23;
  const double _t205 = -_t179*lapl_s - _t203*tau_s - _t204*sigma_ss;
  const double _t206 = _t19*_t205;
  const double _t207 = _t166*lapl_s - _t182*lapl_s + _t200*tau_s + _t201*sigma_ss - _t202*sigma_ss - _t206*tau_s;
  const double _t208 = _t19*_t207;
  const double _t209 = -_t162*tau_s - _t163*lapl_s - _t165*sigma_ss - _t184*lapl_s - _t199*sigma_ss - _t208*tau_s + 0.12e2*_t22*_t69*lapl_s + 0.12e2*_t22*_t78*tau_s + 0.24e2*_t40*_t74*sigma_ss;
  const double _t210 = my_piecewise3(_t3, 0, -0.1e1 / 0.4e1*_hc1[0]*_t16 - _t10*_t209 + (0.1e1 / 0.2e1)*_t12*_t25*_t5*_t6*_t7 - _t18*_t80);
#endif
#if _KMAX >= 4
  const double _t231 = _hc1[10]*tau_s;
  const double _t232 = _hc1[11]*_t230;
  const double _t235 = -_hc1[11]*_t99 - _hc1[21]*_t100 - _hc1[22]*_t101 - _hc1[26]*_t103;
  const double _t236 = _hc1[12]*_t230;
  const double _t237 = -_hc1[12]*_t99 - _hc1[22]*_t100 - _hc1[23]*_t101 - _hc1[27]*_t103;
  const double _t238 = _hc1[13]*lapl_s;
  const double _t239 = -_hc1[15]*_t111 - _hc1[26]*_t112 - _hc1[27]*_t113 - _hc1[30]*_t115;
  const double _t241 = _hc1[17]*tau_s;
  const double _t242 = _hc1[18]*lapl_s;
  const double _t243 = _hc1[19]*_t130;
  const double _t244 = _hc1[18]*_t121;
  const double _t245 = _hc1[17]*_t121;
  const double _t249 = _hc1[5]*_t248;
  const double _t253 = -_hc1[22]*_t132 - _hc1[23]*_t49 - _hc1[27]*_t133 - _t169;
  const double _t254 = -_hc1[26]*_t132 - _hc1[27]*_t49 - _hc1[30]*_t133 - _t174;
  const double _t255 = -_hc1[21]*_t132 - _hc1[22]*_t49 - _hc1[26]*_t133 - _t179;
  const double _t256 = _hc1[11]*_t252 + _hc1[12]*_t142 + _hc1[15]*_t131 - _t135*_t253 - _t139*_t255 - _t156*_t254 + _t166 - _t182;
  const double _t257 = _hc1[14]*tau_s;
  const double _t258 = -_hc1[25]*_t132 - _hc1[26]*_t49 - _hc1[29]*_t133 - _t194;
  const double _t259 = _hc1[6]*lapl_s;
  const double _t260 = -_hc1[27]*_t132 - _hc1[28]*_t49 - _hc1[31]*_t133 - _t175;
  const double _t262 = _hc1[15]*_t121;
  const double _t263 = _hc1[16]*lapl_s;
  const double _t265 = -_hc1[30]*_t151 - _hc1[31]*_t152 - _hc1[33]*_t57 - _t176;
  const double _t266 = -_hc1[26]*_t151 - _hc1[27]*_t152 - _hc1[30]*_t57 - _t180;
  const double _t267 = -_hc1[29]*_t151 - _hc1[30]*_t152 - _hc1[32]*_t57 - _t195;
  const double _t271 = _hc1[5]*_t161;
  const double _t275 = -_hc1[27]*_t139 - _hc1[28]*_t135 - _hc1[31]*_t156;
  const double _t276 = -_hc1[22]*_t139 - _hc1[23]*_t135 - _hc1[27]*_t156;
  const double _t277 = _hc1[15]*_t61;
  const double _t278 = -_hc1[30]*_t139 - _hc1[31]*_t135 - _hc1[33]*_t156;
  const double _t279 = -_hc1[26]*_t139 - _hc1[27]*_t135 - _hc1[30]*_t156;
  const double _t280 = _hc1[18]*_t274 - _t135*_t275 - _t139*_t279 - _t156*_t278 + _t263*_t61 + _t277*tau_s;
  const double _t282 = -_hc1[21]*_t139 - _hc1[22]*_t135 - _hc1[26]*_t156;
  const double _t283 = _hc1[11]*_t273 + _hc1[12]*_t281 + _hc1[15]*_t274 - _t135*_t276 - _t139*_t282 - _t156*_t279;
  const double _t284 = -_hc1[29]*_t139 - _hc1[30]*_t135 - _hc1[32]*_t156;
  const double _t285 = -_hc1[25]*_t139 - _hc1[26]*_t135 - _hc1[29]*_t156;
  const double _t286 = _hc1[17]*_t274 - _t135*_t279 - _t139*_t285 - _t156*_t284 + _t257*_t61 + _t277*lapl_s;
#endif

  const double f = my_piecewise3(_t3, 0, _t11*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t3, 0, _t14*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = my_piecewise3(_t3, 0, _t15*n_s);
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t3, 0, _t17*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t3, 0, _t11 + _t26*n_s);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = my_piecewise3(_t3, 0, _t29*n_s);
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = my_piecewise3(_t3, 0, _t30*n_s);
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = my_piecewise3(_t3, 0, _t31*n_s);
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = my_piecewise3(_t3, 0, _t34*n_s);
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = my_piecewise3(_t3, 0, _t35*n_s);
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t3, 0, _t38*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t3, 0, _t14 + _t48*n_s);
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = my_piecewise3(_t3, 0, _t15 + _t52*n_s);
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t3, 0, _t17 + _t59*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t3, 0, 0.2e1*_t26 + _t81*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = my_piecewise3(_t3, 0, _t82*n_s);
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = my_piecewise3(_t3, 0, _t83*n_s);
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = my_piecewise3(_t3, 0, _t84*n_s);
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = my_piecewise3(_t3, 0, _t85*n_s);
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = my_piecewise3(_t3, 0, _t88*n_s);
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = my_piecewise3(_t3, 0, _t89*n_s);
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = my_piecewise3(_t3, 0, _t90*n_s);
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = my_piecewise3(_t3, 0, _t93*n_s);
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = my_piecewise3(_t3, 0, _t94*n_s);
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t3, 0, _t97*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = my_piecewise3(_t3, 0, _t105*n_s + _t29);
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = my_piecewise3(_t3, 0, _t107*n_s + _t30);
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = my_piecewise3(_t3, 0, _t109*n_s + _t31);
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = my_piecewise3(_t3, 0, _t117*n_s + _t34);
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = my_piecewise3(_t3, 0, _t119*n_s + _t35);
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t3, 0, _t127*n_s + _t38);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t3, 0, _t141*n_s + 0.2e1*_t48);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = my_piecewise3(_t3, 0, _t147*n_s + 0.2e1*_t52);
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t3, 0, _t160*n_s + 0.2e1*_t59);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t3, 0, _t210*n_s + 0.3e1*_t81);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[20]*_t92));
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[21]*_t92));
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[22]*_t92));
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[23]*_t92));
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[24]*_t92));
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[25]*_t96));
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[26]*_t96));
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[27]*_t96));
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[28]*_t96));
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[29]*_t212));
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[30]*_t212));
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[31]*_t212));
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[32]*_t213));
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[33]*_t213));
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t3, 0, n_s*my_piecewise3(_t3, 0, -_hc1[34]*_t9/xc_powr(n_s, 23, 2)));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = my_piecewise3(_t3, 0, _t82 + n_s*my_piecewise3(_t3, 0, -_hc1[10]*_t120 - _t10*(-_hc1[10]*_t121 - _hc1[20]*_t214 - _hc1[21]*_t215 - _hc1[25]*_t216)));
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = my_piecewise3(_t3, 0, _t83 + n_s*my_piecewise3(_t3, 0, -_hc1[11]*_t120 - _t10*(-_hc1[11]*_t121 - _hc1[21]*_t214 - _hc1[22]*_t215 - _hc1[26]*_t216)));
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = my_piecewise3(_t3, 0, _t84 + n_s*my_piecewise3(_t3, 0, -_hc1[12]*_t120 - _t10*(-_hc1[12]*_t121 - _hc1[22]*_t214 - _hc1[23]*_t215 - _hc1[27]*_t216)));
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = my_piecewise3(_t3, 0, _t85 + n_s*my_piecewise3(_t3, 0, -_hc1[13]*_t120 - _t10*(-_hc1[13]*_t121 - _hc1[23]*_t214 - _hc1[24]*_t215 - _hc1[28]*_t216)));
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = my_piecewise3(_t3, 0, _t88 + n_s*my_piecewise3(_t3, 0, -_hc1[14]*_t217 - _t10*(-_hc1[14]*_t218 - _hc1[25]*_t219 - _hc1[26]*_t220 - _hc1[29]*_t222)));
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = my_piecewise3(_t3, 0, _t89 + n_s*my_piecewise3(_t3, 0, -_hc1[15]*_t217 - _t10*(-_hc1[15]*_t218 - _hc1[26]*_t219 - _hc1[27]*_t220 - _hc1[30]*_t222)));
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = my_piecewise3(_t3, 0, _t90 + n_s*my_piecewise3(_t3, 0, -_hc1[16]*_t217 - _t10*(-_hc1[16]*_t218 - _hc1[27]*_t219 - _hc1[28]*_t220 - _hc1[31]*_t222)));
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = my_piecewise3(_t3, 0, _t93 + n_s*my_piecewise3(_t3, 0, -_hc1[17]*_t223 - _t10*(-_hc1[17]*_t224 - _hc1[29]*_t225 - _hc1[30]*_t226 - _hc1[32]*_t228)));
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = my_piecewise3(_t3, 0, _t94 + n_s*my_piecewise3(_t3, 0, -_hc1[18]*_t223 - _t10*(-_hc1[18]*_t224 - _hc1[30]*_t225 - _hc1[31]*_t226 - _hc1[33]*_t228)));
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t3, 0, _t97 + n_s*my_piecewise3(_t3, 0, -_hc1[19]*_t211*_t53 - _t10*(-_hc1[32]*_t227*_t54 - _hc1[33]*_t227*_t55 - _hc1[34]*_t44/xc_powi(n_s, 13) - 0.9e1*_t125)));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = my_piecewise3(_t3, 0, 0.2e1*_t105 + n_s*my_piecewise3(_t3, 0, (0.1e1 / 0.6e1)*_hc1[4]*_t36*_t5*_t6*_t7 - _t10*(_hc1[14]*_t233 + _hc1[4]*_t229 - _t135*_t235 - _t138*_t234 - _t139*(-_hc1[10]*_t99 - _hc1[20]*_t100 - _hc1[21]*_t101 - _hc1[25]*_t103) - _t156*(-_hc1[14]*_t99 - _hc1[25]*_t100 - _hc1[26]*_t101 - _hc1[29]*_t103) + _t230*_t231 + _t232*lapl_s) - _t104*_t60));
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = my_piecewise3(_t3, 0, 0.2e1*_t107 + n_s*my_piecewise3(_t3, 0, (0.1e1 / 0.6e1)*_hc1[5]*_t36*_t5*_t6*_t7 - _t10*(_hc1[15]*_t233 + _hc1[5]*_t229 - _t134*_t234 - _t135*_t237 - _t139*_t235 - _t156*(-_hc1[15]*_t99 - _hc1[26]*_t100 - _hc1[27]*_t101 - _hc1[30]*_t103) + _t232*tau_s + _t236*lapl_s) - _t106*_t60));
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = my_piecewise3(_t3, 0, 0.2e1*_t109 + n_s*my_piecewise3(_t3, 0, (0.1e1 / 0.6e1)*_hc1[6]*_t36*_t5*_t6*_t7 - _t10*(_hc1[16]*_t233 + _hc1[6]*_t229 - _t135*(-_hc1[13]*_t99 - _hc1[23]*_t100 - _hc1[24]*_t101 - _hc1[28]*_t103) - _t139*_t237 - _t143*_t234 - _t156*(-_hc1[16]*_t99 - _hc1[27]*_t100 - _hc1[28]*_t101 - _hc1[31]*_t103) + _t230*_t238 + _t236*tau_s) - _t108*_t60));
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = my_piecewise3(_t3, 0, 0.2e1*_t117 + n_s*my_piecewise3(_t3, 0, (0.1e1 / 0.6e1)*_hc1[7]*_t5*_t6*_t7*_t86 - _t10*(0.6e1*_hc1[14]*_t114*tau_s + 0.6e1*_hc1[15]*_t114*lapl_s + 0.12e2*_hc1[17]*_t124*sigma_ss + 0.18e2*_hc1[7]*_t56 - _t135*_t239 - _t137 - _t139*(-_hc1[14]*_t111 - _hc1[25]*_t112 - _hc1[26]*_t113 - _hc1[29]*_t115) - _t156*(-_hc1[17]*_t111 - _hc1[29]*_t112 - _hc1[30]*_t113 - _hc1[32]*_t115) - _t158) - _t116*_t60));
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = my_piecewise3(_t3, 0, 0.2e1*_t119 + n_s*my_piecewise3(_t3, 0, (0.1e1 / 0.6e1)*_hc1[8]*_t5*_t6*_t7*_t86 - _t10*(0.6e1*_hc1[15]*_t114*tau_s + 0.6e1*_hc1[16]*_t114*lapl_s + 0.12e2*_hc1[18]*_t124*sigma_ss + 0.18e2*_hc1[8]*_t56 - _t135*(-_hc1[16]*_t111 - _hc1[27]*_t112 - _hc1[28]*_t113 - _hc1[31]*_t115) - _t139*_t239 - _t145 - _t154 - _t156*(-_hc1[18]*_t111 - _hc1[30]*_t112 - _hc1[31]*_t113 - _hc1[33]*_t115)) - _t118*_t60));
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t3, 0, 0.2e1*_t127 + n_s*my_piecewise3(_t3, 0, (0.1e1 / 0.6e1)*_hc1[9]*_t5*_t6*_t7*_t91 - _t10*(-_t135*(-_hc1[30]*_t214 - _hc1[31]*_t215 - _hc1[33]*_t216 - _t244) - _t139*(-_hc1[29]*_t214 - _hc1[30]*_t215 - _hc1[32]*_t216 - _t245) + 0.24e2*_t150 - _t155*_t61 - _t156*(-_hc1[19]*_t121 - _hc1[32]*_t214 - _hc1[33]*_t215 - _hc1[34]*_t216) + _t221*_t243 + _t240*_t241 + _t240*_t242) - _t126*_t60));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t3, 0, 0.3e1*_t141 + n_s*my_piecewise3(_t3, 0, -_hc1[1]*_t247 - _t10*(-_hc1[7]*_t251 + 0.12e2*_t134*_t22*lapl_s - _t135*_t256 + 0.24e2*_t136*_t40*sigma_ss + 0.12e2*_t138*_t22*tau_s - _t139*(_hc1[11]*_t142 + _hc1[14]*_t131 + _t128*_t231 - _t135*_t255 - _t139*(-_hc1[20]*_t132 - _hc1[21]*_t49 - _hc1[25]*_t133 - _t203) - _t156*_t258 + _t200 - _t206) - _t156*(_hc1[15]*_t142 + _hc1[17]*_t131 + _t128*_t257 - _t135*_t254 - _t139*_t258 - _t156*(-_hc1[29]*_t132 - _hc1[30]*_t49 - _hc1[32]*_t133 - _t189) + _t185 - _t197) - _t162 - _t208 + 0.12e2*_t22*_t78 - _t248*_t42 - _t249*lapl_s) + (0.1e1 / 0.2e1)*_t12*_t47*_t5*_t6*_t7 - _t140*_t18));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = my_piecewise3(_t3, 0, 0.3e1*_t147 + n_s*my_piecewise3(_t3, 0, -_hc1[2]*_t247 - _t10*(-_hc1[8]*_t251 + 0.12e2*_t134*_t22*tau_s - _t135*(_hc1[12]*_t252 + _hc1[13]*_t142 + _hc1[16]*_t131 - _t135*(-_hc1[23]*_t132 - _hc1[24]*_t49 - _hc1[28]*_t133 - _t170) - _t139*_t253 - _t156*_t260 + _t167 - _t173) - _t139*_t256 + 0.12e2*_t143*_t22*lapl_s + 0.24e2*_t144*_t40*sigma_ss - _t156*(_hc1[15]*_t252 + _hc1[16]*_t142 + _hc1[18]*_t131 - _t135*_t260 - _t139*_t254 - _t156*(-_hc1[30]*_t132 - _hc1[31]*_t49 - _hc1[33]*_t133 - _t190) + _t186 - _t188) - _t163 - _t184 + 0.12e2*_t22*_t69 - _t248*_t259 - _t249*tau_s) + (0.1e1 / 0.2e1)*_t12*_t5*_t51*_t6*_t7 - _t146*_t18));
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t3, 0, 0.3e1*_t160 + n_s*my_piecewise3(_t3, 0, -_hc1[3]*_t246*_t36 - _t10*(-_hc1[9]*_t114*_t250 - _t135*(_hc1[18]*_t264 + _t121*_t263 - _t135*(-_hc1[27]*_t151 - _hc1[28]*_t152 - _hc1[31]*_t57 - _t171) - _t139*_t266 - _t156*_t265 + _t168 - _t178 + _t262*tau_s) - _t139*(_hc1[17]*_t264 + _t121*_t257 - _t135*_t266 - _t139*(-_hc1[25]*_t151 - _hc1[26]*_t152 - _hc1[29]*_t57 - _t204) - _t156*_t267 + _t201 - _t202 + _t262*lapl_s) - _t148*_t261 - _t149*_t261 + 0.12e2*_t153*_t22*lapl_s + 0.24e2*_t155*_t40*sigma_ss - _t156*(_t102*_t243 - _t135*_t265 - _t139*_t267 - _t156*(-_hc1[32]*_t151 - _hc1[33]*_t152 - _hc1[34]*_t57 - _t191) + _t187 - _t193 + _t244*lapl_s + _t245*tau_s) + 0.12e2*_t157*_t22*tau_s - _t165 - _t199 + 0.24e2*_t40*_t74) + (0.1e1 / 0.2e1)*_t12*_t5*_t58*_t6*_t7 - _t159*_t18));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t3, 0, 0.4e1*_t210 + n_s*my_piecewise3(_t3, 0, (0.5e1 / 0.8e1)*_hc1[0]*_t27*_t5*_t6*_t7 - _t10*(_hc1[1]*_t268*tau_s + _hc1[2]*_t268*lapl_s + 0.360e3*_hc1[3]*_t56*sigma_ss - _t135*(-_hc1[8]*_t272 - _t135*(_hc1[12]*_t273 + _hc1[16]*_t274 - _t135*(-_hc1[23]*_t139 - _hc1[24]*_t135 - _hc1[28]*_t156) - _t139*_t276 - _t156*_t275 + _t238*_t61) - _t139*_t283 - _t156*_t280 - _t161*_t259 + 0.12e2*_t172*_t22*lapl_s + 0.24e2*_t177*_t40*sigma_ss + 0.12e2*_t181*_t22*tau_s - _t271*tau_s) - _t139*(-_hc1[7]*_t272 - _t135*_t283 - _t139*(_hc1[11]*_t281 + _hc1[14]*_t274 - _t135*_t282 - _t139*(-_hc1[20]*_t139 - _hc1[21]*_t135 - _hc1[25]*_t156) - _t156*_t285 + _t231*_t61) - _t156*_t286 - _t161*_t42 + 0.12e2*_t181*_t22*lapl_s + 0.24e2*_t196*_t40*sigma_ss + 0.12e2*_t205*_t22*tau_s - _t271*lapl_s) - _t156*(-_hc1[9]*_t272 - _t135*_t280 - _t139*_t286 - _t148*_t161 - _t149*_t161 - _t156*(_hc1[19]*_t274 - _t135*_t278 - _t139*_t284 - _t156*(-_hc1[32]*_t139 - _hc1[33]*_t135 - _hc1[34]*_t156) + _t241*_t61 + _t242*_t61) + 0.12e2*_t177*_t22*lapl_s + 0.24e2*_t192*_t40*sigma_ss + 0.12e2*_t196*_t22*tau_s) + _t183*_t270*lapl_s + 0.36e2*_t198*_t40*sigma_ss + _t207*_t270*tau_s - _t269*_t69*lapl_s - _t269*_t78*tau_s - 0.180e3*_t45*_t74*sigma_ss) + _t12*_t5*_t6*_t7*_t80 - _t16*_t25 - 0.4e1 / 0.3e1*_t18*_t209));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double ta = tau[0];

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, (0.1e1 / 0.2e1)*na, (0.1e1 / 0.4e1)*gaa, (0.1e1 / 0.2e1)*la, (0.1e1 / 0.2e1)*ta, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc0[3];
  const double dF_dla = _hc0[2];
  const double dF_dta = _hc0[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc0[14];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[13];
  const double d2F_dna_dla = (0.1e1 / 0.2e1)*_hc0[12];
  const double d2F_dna_dta = (0.1e1 / 0.2e1)*_hc0[11];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc0[10];
  const double d2F_dgaa_dla = (0.1e1 / 0.4e1)*_hc0[9];
  const double d2F_dgaa_dta = (0.1e1 / 0.4e1)*_hc0[8];
  const double d2F_dla2 = (0.1e1 / 0.2e1)*_hc0[7];
  const double d2F_dla_dta = (0.1e1 / 0.2e1)*_hc0[6];
  const double d2F_dta2 = (0.1e1 / 0.2e1)*_hc0[5];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 0] += d2F_dgaa_dla;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
  if(out->v2lapltau != NULL) out->v2lapltau[ip*p->dim.v2lapltau + 0] += d2F_dla_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc0[34];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc0[33];
  const double d3F_dna2_dla = (0.1e1 / 0.4e1)*_hc0[32];
  const double d3F_dna2_dta = (0.1e1 / 0.4e1)*_hc0[31];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[30];
  const double d3F_dna_dgaa_dla = (0.1e1 / 0.8e1)*_hc0[29];
  const double d3F_dna_dgaa_dta = (0.1e1 / 0.8e1)*_hc0[28];
  const double d3F_dna_dla2 = (0.1e1 / 0.4e1)*_hc0[27];
  const double d3F_dna_dla_dta = (0.1e1 / 0.4e1)*_hc0[26];
  const double d3F_dna_dta2 = (0.1e1 / 0.4e1)*_hc0[25];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc0[24];
  const double d3F_dgaa2_dla = (0.1e1 / 0.16e2)*_hc0[23];
  const double d3F_dgaa2_dta = (0.1e1 / 0.16e2)*_hc0[22];
  const double d3F_dgaa_dla2 = (0.1e1 / 0.8e1)*_hc0[21];
  const double d3F_dgaa_dla_dta = (0.1e1 / 0.8e1)*_hc0[20];
  const double d3F_dgaa_dta2 = (0.1e1 / 0.8e1)*_hc0[19];
  const double d3F_dla3 = (0.1e1 / 0.4e1)*_hc0[18];
  const double d3F_dla2_dta = (0.1e1 / 0.4e1)*_hc0[17];
  const double d3F_dla_dta2 = (0.1e1 / 0.4e1)*_hc0[16];
  const double d3F_dta3 = (0.1e1 / 0.4e1)*_hc0[15];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 0] += d3F_dna_dgaa_dla;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += d3F_dna_dgaa_dta;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 0] += d3F_dna_dla_dta;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 0] += d3F_dgaa2_dla;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 0] += d3F_dgaa2_dta;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 0] += d3F_dgaa_dla2;
  if(out->v3sigmalapltau != NULL) out->v3sigmalapltau[ip*p->dim.v3sigmalapltau + 0] += d3F_dgaa_dla_dta;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 0] += d3F_dgaa_dta2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
  if(out->v3lapl2tau != NULL) out->v3lapl2tau[ip*p->dim.v3lapl2tau + 0] += d3F_dla2_dta;
  if(out->v3lapltau2 != NULL) out->v3lapltau2[ip*p->dim.v3lapltau2 + 0] += d3F_dla_dta2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc0[69];
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc0[68];
  const double d4F_dna3_dla = (0.1e1 / 0.8e1)*_hc0[67];
  const double d4F_dna3_dta = (0.1e1 / 0.8e1)*_hc0[66];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc0[65];
  const double d4F_dna2_dgaa_dla = (0.1e1 / 0.16e2)*_hc0[64];
  const double d4F_dna2_dgaa_dta = (0.1e1 / 0.16e2)*_hc0[63];
  const double d4F_dna2_dla2 = (0.1e1 / 0.8e1)*_hc0[62];
  const double d4F_dna2_dla_dta = (0.1e1 / 0.8e1)*_hc0[61];
  const double d4F_dna2_dta2 = (0.1e1 / 0.8e1)*_hc0[60];
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[59];
  const double d4F_dna_dgaa2_dla = (0.1e1 / 0.32e2)*_hc0[58];
  const double d4F_dna_dgaa2_dta = (0.1e1 / 0.32e2)*_hc0[57];
  const double d4F_dna_dgaa_dla2 = (0.1e1 / 0.16e2)*_hc0[56];
  const double d4F_dna_dgaa_dla_dta = (0.1e1 / 0.16e2)*_hc0[55];
  const double d4F_dna_dgaa_dta2 = (0.1e1 / 0.16e2)*_hc0[54];
  const double d4F_dna_dla3 = (0.1e1 / 0.8e1)*_hc0[53];
  const double d4F_dna_dla2_dta = (0.1e1 / 0.8e1)*_hc0[52];
  const double d4F_dna_dla_dta2 = (0.1e1 / 0.8e1)*_hc0[51];
  const double d4F_dna_dta3 = (0.1e1 / 0.8e1)*_hc0[50];
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc0[49];
  const double d4F_dgaa3_dla = (0.1e1 / 0.64e2)*_hc0[48];
  const double d4F_dgaa3_dta = (0.1e1 / 0.64e2)*_hc0[47];
  const double d4F_dgaa2_dla2 = (0.1e1 / 0.32e2)*_hc0[46];
  const double d4F_dgaa2_dla_dta = (0.1e1 / 0.32e2)*_hc0[45];
  const double d4F_dgaa2_dta2 = (0.1e1 / 0.32e2)*_hc0[44];
  const double d4F_dgaa_dla3 = (0.1e1 / 0.16e2)*_hc0[43];
  const double d4F_dgaa_dla2_dta = (0.1e1 / 0.16e2)*_hc0[42];
  const double d4F_dgaa_dla_dta2 = (0.1e1 / 0.16e2)*_hc0[41];
  const double d4F_dgaa_dta3 = (0.1e1 / 0.16e2)*_hc0[40];
  const double d4F_dla4 = (0.1e1 / 0.8e1)*_hc0[39];
  const double d4F_dla3_dta = (0.1e1 / 0.8e1)*_hc0[38];
  const double d4F_dla2_dta2 = (0.1e1 / 0.8e1)*_hc0[37];
  const double d4F_dla_dta3 = (0.1e1 / 0.8e1)*_hc0[36];
  const double d4F_dta4 = (0.1e1 / 0.8e1)*_hc0[35];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 0] += d4F_dna2_dgaa_dla;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += d4F_dna2_dgaa_dta;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 0] += d4F_dna2_dla_dta;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 0] += d4F_dna_dgaa2_dla;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += d4F_dna_dgaa2_dta;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 0] += d4F_dna_dgaa_dla2;
  if(out->v4rhosigmalapltau != NULL) out->v4rhosigmalapltau[ip*p->dim.v4rhosigmalapltau + 0] += d4F_dna_dgaa_dla_dta;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += d4F_dna_dgaa_dta2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 0] += d4F_dna_dla2_dta;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 0] += d4F_dna_dla_dta2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 0] += d4F_dgaa3_dla;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 0] += d4F_dgaa3_dta;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 0] += d4F_dgaa2_dla2;
  if(out->v4sigma2lapltau != NULL) out->v4sigma2lapltau[ip*p->dim.v4sigma2lapltau + 0] += d4F_dgaa2_dla_dta;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 0] += d4F_dgaa2_dta2;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 0] += d4F_dgaa_dla3;
  if(out->v4sigmalapl2tau != NULL) out->v4sigmalapl2tau[ip*p->dim.v4sigmalapl2tau + 0] += d4F_dgaa_dla2_dta;
  if(out->v4sigmalapltau2 != NULL) out->v4sigmalapltau2[ip*p->dim.v4sigmalapltau2 + 0] += d4F_dgaa_dla_dta2;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 0] += d4F_dgaa_dta3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 0] += d4F_dla4;
  if(out->v4lapl3tau != NULL) out->v4lapl3tau[ip*p->dim.v4lapl3tau + 0] += d4F_dla3_dta;
  if(out->v4lapl2tau2 != NULL) out->v4lapl2tau2[ip*p->dim.v4lapl2tau2 + 0] += d4F_dla2_dta2;
  if(out->v4lapltau3 != NULL) out->v4lapltau3[ip*p->dim.v4lapltau3 + 0] += d4F_dla_dta3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gbb = sigma[2];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double lb = (lapl != NULL) ? lapl[1] : 0.0;
  const double ta = tau[0];
  const double tb = tau[1];

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, la, ta, _hc0);
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, lb, tb, _hc1);
  const double zk = (_hc0[0] + _hc1[0])/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dnb = _hc1[4];
  const double dF_dgaa = _hc0[3];
  const double dF_dgbb = _hc1[3];
  const double dF_dla = _hc0[2];
  const double dF_dlb = _hc1[2];
  const double dF_dta = _hc0[1];
  const double dF_dtb = _hc1[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 1] += dF_dlb;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 1] += dF_dtb;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = _hc0[14];
  const double d2F_dnb2 = _hc1[14];
  const double d2F_dna_dgaa = _hc0[13];
  const double d2F_dnb_dgbb = _hc1[13];
  const double d2F_dna_dla = _hc0[12];
  const double d2F_dnb_dlb = _hc1[12];
  const double d2F_dna_dta = _hc0[11];
  const double d2F_dnb_dtb = _hc1[11];
  const double d2F_dgaa2 = _hc0[10];
  const double d2F_dgbb2 = _hc1[10];
  const double d2F_dgaa_dla = _hc0[9];
  const double d2F_dgbb_dlb = _hc1[9];
  const double d2F_dgaa_dta = _hc0[8];
  const double d2F_dgbb_dtb = _hc1[8];
  const double d2F_dla2 = _hc0[7];
  const double d2F_dlb2 = _hc1[7];
  const double d2F_dla_dta = _hc0[6];
  const double d2F_dlb_dtb = _hc1[6];
  const double d2F_dta2 = _hc0[5];
  const double d2F_dtb2 = _hc1[5];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 3] += d2F_dnb_dlb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 3] += d2F_dnb_dtb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 0] += d2F_dgaa_dla;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 5] += d2F_dgbb_dlb;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 5] += d2F_dgbb_dtb;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 2] += d2F_dlb2;
  if(out->v2lapltau != NULL) out->v2lapltau[ip*p->dim.v2lapltau + 0] += d2F_dla_dta;
  if(out->v2lapltau != NULL) out->v2lapltau[ip*p->dim.v2lapltau + 3] += d2F_dlb_dtb;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 2] += d2F_dtb2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = _hc0[34];
  const double d3F_dnb3 = _hc1[34];
  const double d3F_dna2_dgaa = _hc0[33];
  const double d3F_dnb2_dgbb = _hc1[33];
  const double d3F_dna2_dla = _hc0[32];
  const double d3F_dnb2_dlb = _hc1[32];
  const double d3F_dna2_dta = _hc0[31];
  const double d3F_dnb2_dtb = _hc1[31];
  const double d3F_dna_dgaa2 = _hc0[30];
  const double d3F_dnb_dgbb2 = _hc1[30];
  const double d3F_dna_dgaa_dla = _hc0[29];
  const double d3F_dnb_dgbb_dlb = _hc1[29];
  const double d3F_dna_dgaa_dta = _hc0[28];
  const double d3F_dnb_dgbb_dtb = _hc1[28];
  const double d3F_dna_dla2 = _hc0[27];
  const double d3F_dnb_dlb2 = _hc1[27];
  const double d3F_dna_dla_dta = _hc0[26];
  const double d3F_dnb_dlb_dtb = _hc1[26];
  const double d3F_dna_dta2 = _hc0[25];
  const double d3F_dnb_dtb2 = _hc1[25];
  const double d3F_dgaa3 = _hc0[24];
  const double d3F_dgbb3 = _hc1[24];
  const double d3F_dgaa2_dla = _hc0[23];
  const double d3F_dgbb2_dlb = _hc1[23];
  const double d3F_dgaa2_dta = _hc0[22];
  const double d3F_dgbb2_dtb = _hc1[22];
  const double d3F_dgaa_dla2 = _hc0[21];
  const double d3F_dgbb_dlb2 = _hc1[21];
  const double d3F_dgaa_dla_dta = _hc0[20];
  const double d3F_dgbb_dlb_dtb = _hc1[20];
  const double d3F_dgaa_dta2 = _hc0[19];
  const double d3F_dgbb_dtb2 = _hc1[19];
  const double d3F_dla3 = _hc0[18];
  const double d3F_dlb3 = _hc1[18];
  const double d3F_dla2_dta = _hc0[17];
  const double d3F_dlb2_dtb = _hc1[17];
  const double d3F_dla_dta2 = _hc0[16];
  const double d3F_dlb_dtb2 = _hc1[16];
  const double d3F_dta3 = _hc0[15];
  const double d3F_dtb3 = _hc1[15];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 5] += d3F_dnb2_dlb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 5] += d3F_dnb2_dtb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 0] += d3F_dna_dgaa_dla;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 11] += d3F_dnb_dgbb_dlb;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += d3F_dna_dgaa_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 11] += d3F_dnb_dgbb_dtb;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 5] += d3F_dnb_dlb2;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 0] += d3F_dna_dla_dta;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 7] += d3F_dnb_dlb_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 5] += d3F_dnb_dtb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 0] += d3F_dgaa2_dla;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 11] += d3F_dgbb2_dlb;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 0] += d3F_dgaa2_dta;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 11] += d3F_dgbb2_dtb;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 0] += d3F_dgaa_dla2;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 8] += d3F_dgbb_dlb2;
  if(out->v3sigmalapltau != NULL) out->v3sigmalapltau[ip*p->dim.v3sigmalapltau + 0] += d3F_dgaa_dla_dta;
  if(out->v3sigmalapltau != NULL) out->v3sigmalapltau[ip*p->dim.v3sigmalapltau + 11] += d3F_dgbb_dlb_dtb;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 0] += d3F_dgaa_dta2;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 8] += d3F_dgbb_dtb2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 3] += d3F_dlb3;
  if(out->v3lapl2tau != NULL) out->v3lapl2tau[ip*p->dim.v3lapl2tau + 0] += d3F_dla2_dta;
  if(out->v3lapl2tau != NULL) out->v3lapl2tau[ip*p->dim.v3lapl2tau + 5] += d3F_dlb2_dtb;
  if(out->v3lapltau2 != NULL) out->v3lapltau2[ip*p->dim.v3lapltau2 + 0] += d3F_dla_dta2;
  if(out->v3lapltau2 != NULL) out->v3lapltau2[ip*p->dim.v3lapltau2 + 5] += d3F_dlb_dtb2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 3] += d3F_dtb3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = _hc0[69];
  const double d4F_dnb4 = _hc1[69];
  const double d4F_dna3_dgaa = _hc0[68];
  const double d4F_dnb3_dgbb = _hc1[68];
  const double d4F_dna3_dla = _hc0[67];
  const double d4F_dnb3_dlb = _hc1[67];
  const double d4F_dna3_dta = _hc0[66];
  const double d4F_dnb3_dtb = _hc1[66];
  const double d4F_dna2_dgaa2 = _hc0[65];
  const double d4F_dnb2_dgbb2 = _hc1[65];
  const double d4F_dna2_dgaa_dla = _hc0[64];
  const double d4F_dnb2_dgbb_dlb = _hc1[64];
  const double d4F_dna2_dgaa_dta = _hc0[63];
  const double d4F_dnb2_dgbb_dtb = _hc1[63];
  const double d4F_dna2_dla2 = _hc0[62];
  const double d4F_dnb2_dlb2 = _hc1[62];
  const double d4F_dna2_dla_dta = _hc0[61];
  const double d4F_dnb2_dlb_dtb = _hc1[61];
  const double d4F_dna2_dta2 = _hc0[60];
  const double d4F_dnb2_dtb2 = _hc1[60];
  const double d4F_dna_dgaa3 = _hc0[59];
  const double d4F_dnb_dgbb3 = _hc1[59];
  const double d4F_dna_dgaa2_dla = _hc0[58];
  const double d4F_dnb_dgbb2_dlb = _hc1[58];
  const double d4F_dna_dgaa2_dta = _hc0[57];
  const double d4F_dnb_dgbb2_dtb = _hc1[57];
  const double d4F_dna_dgaa_dla2 = _hc0[56];
  const double d4F_dnb_dgbb_dlb2 = _hc1[56];
  const double d4F_dna_dgaa_dla_dta = _hc0[55];
  const double d4F_dnb_dgbb_dlb_dtb = _hc1[55];
  const double d4F_dna_dgaa_dta2 = _hc0[54];
  const double d4F_dnb_dgbb_dtb2 = _hc1[54];
  const double d4F_dna_dla3 = _hc0[53];
  const double d4F_dnb_dlb3 = _hc1[53];
  const double d4F_dna_dla2_dta = _hc0[52];
  const double d4F_dnb_dlb2_dtb = _hc1[52];
  const double d4F_dna_dla_dta2 = _hc0[51];
  const double d4F_dnb_dlb_dtb2 = _hc1[51];
  const double d4F_dna_dta3 = _hc0[50];
  const double d4F_dnb_dtb3 = _hc1[50];
  const double d4F_dgaa4 = _hc0[49];
  const double d4F_dgbb4 = _hc1[49];
  const double d4F_dgaa3_dla = _hc0[48];
  const double d4F_dgbb3_dlb = _hc1[48];
  const double d4F_dgaa3_dta = _hc0[47];
  const double d4F_dgbb3_dtb = _hc1[47];
  const double d4F_dgaa2_dla2 = _hc0[46];
  const double d4F_dgbb2_dlb2 = _hc1[46];
  const double d4F_dgaa2_dla_dta = _hc0[45];
  const double d4F_dgbb2_dlb_dtb = _hc1[45];
  const double d4F_dgaa2_dta2 = _hc0[44];
  const double d4F_dgbb2_dtb2 = _hc1[44];
  const double d4F_dgaa_dla3 = _hc0[43];
  const double d4F_dgbb_dlb3 = _hc1[43];
  const double d4F_dgaa_dla2_dta = _hc0[42];
  const double d4F_dgbb_dlb2_dtb = _hc1[42];
  const double d4F_dgaa_dla_dta2 = _hc0[41];
  const double d4F_dgbb_dlb_dtb2 = _hc1[41];
  const double d4F_dgaa_dta3 = _hc0[40];
  const double d4F_dgbb_dtb3 = _hc1[40];
  const double d4F_dla4 = _hc0[39];
  const double d4F_dlb4 = _hc1[39];
  const double d4F_dla3_dta = _hc0[38];
  const double d4F_dlb3_dtb = _hc1[38];
  const double d4F_dla2_dta2 = _hc0[37];
  const double d4F_dlb2_dtb2 = _hc1[37];
  const double d4F_dla_dta3 = _hc0[36];
  const double d4F_dlb_dtb3 = _hc1[36];
  const double d4F_dta4 = _hc0[35];
  const double d4F_dtb4 = _hc1[35];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 7] += d4F_dnb3_dlb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 7] += d4F_dnb3_dtb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 0] += d4F_dna2_dgaa_dla;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 17] += d4F_dnb2_dgbb_dlb;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += d4F_dna2_dgaa_dta;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 17] += d4F_dnb2_dgbb_dtb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 8] += d4F_dnb2_dlb2;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 0] += d4F_dna2_dla_dta;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 11] += d4F_dnb2_dlb_dtb;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 8] += d4F_dnb2_dtb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 0] += d4F_dna_dgaa2_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 23] += d4F_dnb_dgbb2_dlb;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += d4F_dna_dgaa2_dta;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 23] += d4F_dnb_dgbb2_dtb;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 0] += d4F_dna_dgaa_dla2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 17] += d4F_dnb_dgbb_dlb2;
  if(out->v4rhosigmalapltau != NULL) out->v4rhosigmalapltau[ip*p->dim.v4rhosigmalapltau + 0] += d4F_dna_dgaa_dla_dta;
  if(out->v4rhosigmalapltau != NULL) out->v4rhosigmalapltau[ip*p->dim.v4rhosigmalapltau + 23] += d4F_dnb_dgbb_dlb_dtb;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += d4F_dna_dgaa_dta2;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 17] += d4F_dnb_dgbb_dtb2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 7] += d4F_dnb_dlb3;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 0] += d4F_dna_dla2_dta;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 11] += d4F_dnb_dlb2_dtb;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 0] += d4F_dna_dla_dta2;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 11] += d4F_dnb_dlb_dtb2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 7] += d4F_dnb_dtb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 0] += d4F_dgaa3_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 19] += d4F_dgbb3_dlb;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 0] += d4F_dgaa3_dta;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 19] += d4F_dgbb3_dtb;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 0] += d4F_dgaa2_dla2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 17] += d4F_dgbb2_dlb2;
  if(out->v4sigma2lapltau != NULL) out->v4sigma2lapltau[ip*p->dim.v4sigma2lapltau + 0] += d4F_dgaa2_dla_dta;
  if(out->v4sigma2lapltau != NULL) out->v4sigma2lapltau[ip*p->dim.v4sigma2lapltau + 23] += d4F_dgbb2_dlb_dtb;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 0] += d4F_dgaa2_dta2;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 17] += d4F_dgbb2_dtb2;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 0] += d4F_dgaa_dla3;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 11] += d4F_dgbb_dlb3;
  if(out->v4sigmalapl2tau != NULL) out->v4sigmalapl2tau[ip*p->dim.v4sigmalapl2tau + 0] += d4F_dgaa_dla2_dta;
  if(out->v4sigmalapl2tau != NULL) out->v4sigmalapl2tau[ip*p->dim.v4sigmalapl2tau + 17] += d4F_dgbb_dlb2_dtb;
  if(out->v4sigmalapltau2 != NULL) out->v4sigmalapltau2[ip*p->dim.v4sigmalapltau2 + 0] += d4F_dgaa_dla_dta2;
  if(out->v4sigmalapltau2 != NULL) out->v4sigmalapltau2[ip*p->dim.v4sigmalapltau2 + 17] += d4F_dgbb_dlb_dtb2;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 0] += d4F_dgaa_dta3;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 11] += d4F_dgbb_dtb3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 0] += d4F_dla4;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 4] += d4F_dlb4;
  if(out->v4lapl3tau != NULL) out->v4lapl3tau[ip*p->dim.v4lapl3tau + 0] += d4F_dla3_dta;
  if(out->v4lapl3tau != NULL) out->v4lapl3tau[ip*p->dim.v4lapl3tau + 7] += d4F_dlb3_dtb;
  if(out->v4lapl2tau2 != NULL) out->v4lapl2tau2[ip*p->dim.v4lapl2tau2 + 0] += d4F_dla2_dta2;
  if(out->v4lapl2tau2 != NULL) out->v4lapl2tau2[ip*p->dim.v4lapl2tau2 + 8] += d4F_dlb2_dtb2;
  if(out->v4lapltau3 != NULL) out->v4lapltau3[ip*p->dim.v4lapltau3 + 0] += d4F_dla_dta3;
  if(out->v4lapltau3 != NULL) out->v4lapltau3[ip*p->dim.v4lapltau3 + 7] += d4F_dlb_dtb3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 4] += d4F_dtb4;
#endif
#endif
}
#endif