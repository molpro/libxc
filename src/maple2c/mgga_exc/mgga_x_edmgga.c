/*
  Generated from python/mgga_exc/mgga_x_edmgga.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_edmgga
*/

#ifndef _MGGA_X_EDMGGA_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_EDMGGA_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_EDMGGA_HELPER_BODIES
#include "mgga_x_edmgga.c"
#undef _MGGA_X_EDMGGA_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_EDMGGA_HELPER_BODIES
#include "mgga_x_edmgga.c"
#undef _MGGA_X_EDMGGA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_EDMGGA_HELPER_BODIES
#include "mgga_x_edmgga.c"
#undef _MGGA_X_EDMGGA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_EDMGGA_HELPER_BODIES
#include "mgga_x_edmgga.c"
#undef _MGGA_X_EDMGGA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_EDMGGA_HELPER_BODIES
#include "mgga_x_edmgga.c"
#undef _MGGA_X_EDMGGA_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_edmgga.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_edmgga.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_edmgga.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_edmgga.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_edmgga.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_edmgga.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_edmgga.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_edmgga.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_edmgga.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_edmgga.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_EDMGGA_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_4_3_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z + 0.1e1;
  const double _t2 = _t1 <= p->zeta_threshold;

  const double f = my_piecewise3(_t2, xc_powr(p->zeta_threshold, 4, 3), xc_powr(_t1, 4, 3));
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise3(_t2, 0, (0.4e1 / 0.3e1)*xc_powr(_t1, 1, 3));
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise3(_t2, 0, (0.4e1 / 0.9e1)/xc_powr(_t1, 2, 3));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise3(_t2, 0, -(0.8e1 / 0.27e2)/xc_powr(_t1, 5, 3));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = my_piecewise3(_t2, 0, (0.40e2 / 0.81e2)/xc_powr(_t1, 8, 3));
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_spin_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_4_3_k, _KMAX)(p, z, _hc0);
  const double _t1 = xc_powr(0.6e1, 1, 3)*M_CBRT3/(M_CBRTPI*M_CBRTPI);
  const double _t2 = (0.3e1 / 0.16e2)*_t1;
  const double _t3 = _t2/rs;
#if _KMAX >= 1
  const double _t4 = _t2/(rs * rs);
#endif
#if _KMAX >= 2
  const double _t5 = _hc0[0]*_t1;
  const double _t6 = (0.3e1 / 0.8e1)/(rs * rs * rs);
#endif
#if _KMAX >= 3
  const double _t7 = _t1*_t6;
  const double _t8 = (0.9e1 / 0.8e1)/(rs * rs * rs * rs);
#endif

  const double f = -_hc0[0]*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = -_hc0[1]*_t3;
  out[1] = df_dz;
  const double df_drs = _hc0[0]*_t4;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = -_hc0[2]*_t3;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[1]*_t4;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = -_t5*_t6;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = -_hc0[3]*_t3;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc0[2]*_t4;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = -_hc0[1]*_t7;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _t5*_t8;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = -_hc0[4]*_t3;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc0[3]*_t4;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = -_hc0[2]*_t7;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc0[1]*_t1*_t8;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = -0.9e1 / 0.2e1*_t5/xc_powi(rs, 5);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(edmgga_x_exact_k, _KMAX)(const xc_func_type *p, double y, double *out) {

  const double _t1 = (y * y);
  const double _t2 = _t1 + 0.1e1;
  const double _t3 = xc_powr(_t2, 1, 2);
#if _KMAX >= 1
  const double _t4 = (0.1e1 / _t3);
#endif
#if _KMAX >= 2
  const double _t5 = xc_powr(_t2, -3, 2);
#endif
#if _KMAX >= 3
  const double _t6 = 0.3e1*_t5;
  const double _t7 = xc_powr(_t2, -5, 2);
#endif

  const double f = _t3 + y;
  out[0] = f;
#if _KMAX >= 1
  const double df_dy = _t4*y + 0.1e1;
  out[1] = df_dy;
#endif
#if _KMAX >= 2
  const double d2f_dy2 = -_t1*_t5 + _t4;
  out[2] = d2f_dy2;
#endif
#if _KMAX >= 3
  const double d3f_dy3 = -_t6*y + 0.3e1*_t7*(y * y * y);
  out[3] = d3f_dy3;
#endif
#if _KMAX >= 4
  const double d4f_dy4 = 0.18e2*_t1*_t7 - _t6 - 0.15e2*(y * y * y * y)/xc_powr(_t2, 7, 2);
  out[4] = d4f_dy4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(edmgga_x_large_k, _KMAX)(const xc_func_type *p, double y, double *out) {

  const double _t1 = xc_powi(y, -7);
  const double _t2 = xc_powi(y, -5);
  const double _t3 = (0.1e1 / (y * y * y));
#if _KMAX >= 1
  const double _t4 = xc_powi(y, -8);
  const double _t5 = xc_powi(y, -6);
  const double _t6 = (0.1e1 / (y * y * y * y));
#endif
#if _KMAX >= 2
  const double _t7 = xc_powi(y, -9);
#endif

  const double f = (0.5e1 / 0.128e3)*_t1 - 0.1e1 / 0.16e2*_t2 + (0.1e1 / 0.8e1)*_t3 - (0.1e1 / 0.2e1)/y;
  out[0] = f;
#if _KMAX >= 1
  const double df_dy = -0.35e2 / 0.128e3*_t4 + (0.5e1 / 0.16e2)*_t5 - 0.3e1 / 0.8e1*_t6 + (0.1e1 / 0.2e1)/(y * y);
  out[1] = df_dy;
#endif
#if _KMAX >= 2
  const double d2f_dy2 = -0.15e2 / 0.8e1*_t1 + (0.3e1 / 0.2e1)*_t2 - _t3 + (0.35e2 / 0.16e2)*_t7;
  out[2] = d2f_dy2;
#endif
#if _KMAX >= 3
  const double d3f_dy3 = (0.105e3 / 0.8e1)*_t4 - 0.15e2 / 0.2e1*_t5 + 0.3e1*_t6 - (0.315e3 / 0.16e2)/xc_powi(y, 10);
  out[3] = d3f_dy3;
#endif
#if _KMAX >= 4
  const double d4f_dy4 = 0.45e2*_t1 - 0.12e2*_t2 - 0.105e3*_t7 + (0.1575e4 / 0.8e1)/xc_powi(y, 11);
  out[4] = d4f_dy4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(edmgga_x_k, _KMAX)(const xc_func_type *p, double Qb, double *out) {

  const double _t1 = 0.70399999999999996*Qb;
  const double _t2 = _t1 > -0.00014204545454545457;
  const double _t3 = Qb < -14204.545454545456;
#if _KMAX >= 1
  const double _t4 = my_piecewise3(_t2, 0, 0.70399999999999996);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(edmgga_x_large_k, _KMAX)(p, my_piecewise3(_t2, -0.00014204545454545457, _t1), _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(edmgga_x_exact_k, _KMAX)(p, _t1, _hc1);

  const double f = my_piecewise3(_t3, _hc0[0], _hc1[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_dQb = my_piecewise3(_t3, _hc0[1]*_t4, 0.70399999999999996*_hc1[1]);
  out[1] = df_dQb;
#endif
#if _KMAX >= 2
  const double d2f_dQb2 = my_piecewise3(_t3, _hc0[2]*(_t4 * _t4), 0.49561599999999995*_hc1[2]);
  out[2] = d2f_dQb2;
#endif
#if _KMAX >= 3
  const double d3f_dQb3 = my_piecewise3(_t3, _hc0[3]*(_t4 * _t4 * _t4), 0.34891366399999996*_hc1[3]);
  out[3] = d3f_dQb3;
#endif
#if _KMAX >= 4
  const double d4f_dQb4 = my_piecewise3(_t3, _hc0[4]*(_t4 * _t4 * _t4 * _t4), 0.24563521945599995*_hc1[4]);
  out[4] = d4f_dQb4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(edmgga_f_x_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = xc_powr(0.6e1, 2, 3)*(M_CBRTPI * M_CBRTPI);
  const double _t2 = (0.1e1 / 0.9e1)*_t1;
  const double _t3 = 0.1e1 - _t2;
  const double _t4 = xc_powr(x, 1, 2);
  const double _t5 = xc_powr(0.30e2, 1, 2);
  const double _t6 = 1.186591757935306 - 0.13184352865947843*_t1;
  const double _t7 = x - 0.1e1;
  const double _t8 = (M_PI * M_PI);
  const double _t9 = (_t6 * _t6);
  const double _t10 = -0.020651399999999997 + (0.135e3 / 0.32e2)*_t9/_t8;
  const double _t11 = _t5*_t6*xc_asinh((0.128e3 / 0.6075e4)*(M_PI * M_PI * M_PI)*_t10*_t5*_t7/(_t6 * _t6 * _t6))/M_PI;
  const double _t12 = (0.3e1 / 0.8e1)*_t11;
  const double _t13 = _t12*_t4 + 0.1e1;
  const double _t14 = _t3/_t13;
#if _KMAX >= 1
  const double _t15 = (0.1e1 / _t4);
  const double _t16 = (0.3e1 / 0.16e2)*_t11;
  const double _t17 = (0.32768e5 / 0.2460375e7)*xc_powi(M_PI, 6)*(_t10 * _t10)*(_t7 * _t7)/xc_powi(_t6, 6) + 0.1e1;
  const double _t18 = _t10*_t8/(xc_powr(_t17, 1, 2)*_t9);
  const double _t19 = (0.32e2 / 0.135e3)*_t18;
  const double _t20 = -_t15*_t16 - _t19*_t4;
  const double _t21 = _t3/(_t13 * _t13);
  const double _t22 = _t20*_t21;
#endif
#if _KMAX >= 2
  const double _t23 = xc_powr(x, -3, 2);
  const double _t24 = _t11*_t23;
  const double _t25 = xc_powi(M_PI, 8)*(_t10 * _t10 * _t10)/(xc_powr(_t17, 3, 2)*xc_powi(_t6, 8));
  const double _t26 = _t25*_t4;
  const double _t27 = -_t15*_t19 + (0.3e1 / 0.32e2)*_t24 + _t26*((0.1048576e7 / 0.332150625e9)*x - 0.1048576e7 / 0.332150625e9);
  const double _t28 = _t21*_t27;
  const double _t29 = (0.1e1 / (_t13 * _t13 * _t13));
  const double _t30 = _t20*_t3;
  const double _t31 = _t29*_t30;
  const double _t32 = (0.64e2 / 0.135e3)*_t18;
  const double _t33 = -_t12*_t15 - _t32*_t4;
  const double _t34 = _t33*x;
#endif
#if _KMAX >= 3
  const double _t35 = -_t15*_t32 + _t16*_t23 + _t26*((0.2097152e7 / 0.332150625e9)*x - 0.2097152e7 / 0.332150625e9);
  const double _t36 = _t31*_t35;
  const double _t37 = 0.2e1*x;
  const double _t38 = _t29*_t3;
  const double _t39 = _t27*_t38;
  const double _t40 = _t33*_t39;
  const double _t41 = xc_powr(x, -5, 2);
  const double _t42 = _t11*_t41;
  const double _t43 = _t18*_t23;
  const double _t44 = (0.524288e6 / 0.110716875e9)*x - 0.524288e6 / 0.110716875e9;
  const double _t45 = _t15*_t25;
  const double _t46 = _t37 - 0.2e1;
  const double _t47 = (_t46 * _t46);
  const double _t48 = xc_powi(M_PI, 14)*xc_powi(_t10, 5)/(xc_powr(_t17, 5, 2)*xc_powi(_t6, 14));
  const double _t49 = _t4*_t48;
  const double _t50 = _t47*_t49;
  const double _t51 = (0.1048576e7 / 0.332150625e9)*_t26 - 0.9e1 / 0.64e2*_t42 + (0.8e1 / 0.45e2)*_t43 + _t44*_t45 - 0.8589934592e10 / 0.272405031328125e15*_t50;
  const double _t52 = _t21*_t51;
  const double _t53 = (0.1e1 / (_t13 * _t13 * _t13 * _t13));
  const double _t54 = _t11*_t15;
  const double _t55 = (0.32e2 / 0.45e2)*_t18;
  const double _t56 = -_t4*_t55 - 0.9e1 / 0.16e2*_t54;
  const double _t57 = _t30*_t53*_t56;
#endif
#if _KMAX >= 4
  const double _t58 = (0.1048576e7 / 0.110716875e9)*x - 0.1048576e7 / 0.110716875e9;
  const double _t59 = _t30*_t34;
  const double _t60 = 0.3e1*_t34;
#endif

  const double f = _t14*x + _t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t14 + _t22*x;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 0.2e1*_t22 + _t28*x + _t31*_t34;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 0.3e1*_t28 + 0.3e1*_t31*_t33 + _t34*_t57 + _t36*x + _t37*_t40 + _t52*x;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = _t21*x*((0.140737488355328e15 / 0.134043705790787109375e21)*xc_powi(M_PI, 20)*xc_powi(_t10, 7)*_t4*(_t46 * _t46 * _t46)/(xc_powr(_t17, 7, 2)*xc_powi(_t6, 20)) + (0.45e2 / 0.128e3)*_t11/xc_powr(x, 7, 2) - 0.17179869184e11 / 0.272405031328125e15*_t15*_t47*_t48 - 0.16e2 / 0.45e2*_t18*_t41 - _t23*_t25*_t44 + (0.2097152e7 / 0.332150625e9)*_t45 + _t49*(0.34359738368e11 / 0.272405031328125e15 - 0.34359738368e11 / 0.272405031328125e15*x) + _t49*(0.68719476736e11 / 0.272405031328125e15 - 0.68719476736e11 / 0.272405031328125e15*x)) + _t27*_t3*_t53*_t56*_t60 + _t31*x*((0.2097152e7 / 0.332150625e9)*_t26 - 0.9e1 / 0.32e2*_t42 + (0.16e2 / 0.45e2)*_t43 + _t45*_t58 - 0.17179869184e11 / 0.272405031328125e15*_t50) + 0.4e1*_t33*_t57 + _t35*_t37*_t57 + 0.3e1*_t35*_t39*x + 0.4e1*_t36 + _t38*_t51*_t60 + 0.8e1*_t40 + 0.4e1*_t52 + _t53*_t59*(-_t15*_t55 + (0.9e1 / 0.32e2)*_t24 + _t26*_t58) + _t56*_t59*(-0.128e3 / 0.135e3*_t18*_t4 - 0.3e1 / 0.4e1*_t54)/xc_powi(_t13, 5);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(b98_q_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double t, double *out) {

  const double _t1 = (M_PI * M_CBRTPI);
  const double _t2 = xc_powr(0.6e1, 1, 3)/_t1;
  const double _t3 = (0.5e1 / 0.9e1)*_t2;

  const double f = _t3*((0.3e1 / 0.10e2)*xc_powr(0.6e1, 2, 3)*_t1 - t + (0.1e1 / 0.4e1)*u + (0.1e1 / 0.8e1)*x2);
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -_t3;
  out[1] = df_dt;
  const double df_du = (0.5e1 / 0.36e2)*_t2;
  out[2] = df_du;
  const double df_dx2 = (0.5e1 / 0.72e2)*_t2;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(edmgga_f_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(b98_q_pf_k, _KMAX)(p, x2, u, t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(edmgga_x_k, _KMAX)(p, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(edmgga_f_x_k, _KMAX)(p, _hc1[0], _hc2);
#if _KMAX >= 1
  const double _t1 = _hc1[1]*_hc2[1];
#endif
#if _KMAX >= 2
  const double _t2 = ((_hc0[1]) * (_hc0[1]));
  const double _t3 = _hc1[2]*_hc2[1];
  const double _t4 = ((_hc1[1]) * (_hc1[1]));
  const double _t5 = _hc2[2]*_t4;
  const double _t6 = _hc0[1]*_hc0[2];
  const double _t7 = ((_hc0[2]) * (_hc0[2]));
  const double _t8 = _hc0[1]*_hc0[3];
  const double _t9 = _hc0[2]*_hc0[3];
  const double _t10 = ((_hc0[3]) * (_hc0[3]));
#endif
#if _KMAX >= 3
  const double _t11 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t12 = _hc1[3]*_hc2[1];
  const double _t13 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_hc2[3];
  const double _t14 = 0.3e1*_hc2[2];
  const double _t15 = _hc1[1]*_hc1[2]*_t14;
  const double _t16 = _hc0[2]*_t2;
  const double _t17 = _hc0[1]*_t7;
  const double _t18 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t19 = _hc0[3]*_t2;
  const double _t20 = _hc0[3]*_t6;
  const double _t21 = _hc0[3]*_t7;
  const double _t22 = _hc0[1]*_t10;
  const double _t23 = _hc0[2]*_t10;
  const double _t24 = ((_hc0[3]) * (_hc0[3]) * (_hc0[3]));
#endif
#if _KMAX >= 4
  const double _t25 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t26 = _hc1[4]*_hc2[1];
  const double _t27 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_hc2[4];
  const double _t28 = 0.4e1*_hc1[1]*_hc1[3]*_hc2[2];
  const double _t29 = ((_hc1[2]) * (_hc1[2]))*_t14;
  const double _t30 = 0.6e1*_hc1[2]*_hc2[3]*_t4;
  const double _t31 = _hc0[2]*_t11;
  const double _t32 = _t2*_t7;
  const double _t33 = _hc0[1]*_t18;
  const double _t34 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t35 = _hc0[3]*_t11;
  const double _t36 = _t2*_t9;
  const double _t37 = _t7*_t8;
  const double _t38 = _hc0[3]*_t18;
  const double _t39 = _t10*_t2;
  const double _t40 = _t10*_t6;
  const double _t41 = _t10*_t7;
  const double _t42 = _hc0[1]*_t24;
  const double _t43 = _hc0[2]*_t24;
  const double _t44 = ((_hc0[3]) * (_hc0[3]) * (_hc0[3]) * (_hc0[3]));
#endif

  const double f = _hc2[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[1]*_t1;
  out[1] = df_dt;
  const double df_du = _hc0[2]*_t1;
  out[2] = df_du;
  const double df_dx2 = _hc0[3]*_t1;
  out[3] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t2*_t3 + _t2*_t5;
  out[4] = d2f_dt2;
  const double d2f_du_dt = _t3*_t6 + _t5*_t6;
  out[5] = d2f_du_dt;
  const double d2f_du2 = _t3*_t7 + _t5*_t7;
  out[6] = d2f_du2;
  const double d2f_dx2_dt = _t3*_t8 + _t5*_t8;
  out[7] = d2f_dx2_dt;
  const double d2f_dx2_du = _t3*_t9 + _t5*_t9;
  out[8] = d2f_dx2_du;
  const double d2f_dx22 = _t10*_t3 + _t10*_t5;
  out[9] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t11*_t12 + _t11*_t13 + _t11*_t15;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = _t12*_t16 + _t13*_t16 + _t15*_t16;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = _t12*_t17 + _t13*_t17 + _t15*_t17;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = _t12*_t18 + _t13*_t18 + _t15*_t18;
  out[13] = d3f_du3;
  const double d3f_dx2_dt2 = _t12*_t19 + _t13*_t19 + _t15*_t19;
  out[14] = d3f_dx2_dt2;
  const double d3f_dx2_du_dt = _t12*_t20 + _t13*_t20 + _t15*_t20;
  out[15] = d3f_dx2_du_dt;
  const double d3f_dx2_du2 = _t12*_t21 + _t13*_t21 + _t15*_t21;
  out[16] = d3f_dx2_du2;
  const double d3f_dx22_dt = _t12*_t22 + _t13*_t22 + _t15*_t22;
  out[17] = d3f_dx22_dt;
  const double d3f_dx22_du = _t12*_t23 + _t13*_t23 + _t15*_t23;
  out[18] = d3f_dx22_du;
  const double d3f_dx23 = _t12*_t24 + _t13*_t24 + _t15*_t24;
  out[19] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _t25*_t26 + _t25*_t27 + _t25*_t28 + _t25*_t29 + _t25*_t30;
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = _t26*_t31 + _t27*_t31 + _t28*_t31 + _t29*_t31 + _t30*_t31;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = _t26*_t32 + _t27*_t32 + _t28*_t32 + _t29*_t32 + _t30*_t32;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = _t26*_t33 + _t27*_t33 + _t28*_t33 + _t29*_t33 + _t30*_t33;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = _t26*_t34 + _t27*_t34 + _t28*_t34 + _t29*_t34 + _t30*_t34;
  out[24] = d4f_du4;
  const double d4f_dx2_dt3 = _t26*_t35 + _t27*_t35 + _t28*_t35 + _t29*_t35 + _t30*_t35;
  out[25] = d4f_dx2_dt3;
  const double d4f_dx2_du_dt2 = _t26*_t36 + _t27*_t36 + _t28*_t36 + _t29*_t36 + _t30*_t36;
  out[26] = d4f_dx2_du_dt2;
  const double d4f_dx2_du2_dt = _t26*_t37 + _t27*_t37 + _t28*_t37 + _t29*_t37 + _t30*_t37;
  out[27] = d4f_dx2_du2_dt;
  const double d4f_dx2_du3 = _t26*_t38 + _t27*_t38 + _t28*_t38 + _t29*_t38 + _t30*_t38;
  out[28] = d4f_dx2_du3;
  const double d4f_dx22_dt2 = _t26*_t39 + _t27*_t39 + _t28*_t39 + _t29*_t39 + _t30*_t39;
  out[29] = d4f_dx22_dt2;
  const double d4f_dx22_du_dt = _t26*_t40 + _t27*_t40 + _t28*_t40 + _t29*_t40 + _t30*_t40;
  out[30] = d4f_dx22_du_dt;
  const double d4f_dx22_du2 = _t26*_t41 + _t27*_t41 + _t28*_t41 + _t29*_t41 + _t30*_t41;
  out[31] = d4f_dx22_du2;
  const double d4f_dx23_dt = _t26*_t42 + _t27*_t42 + _t28*_t42 + _t29*_t42 + _t30*_t42;
  out[32] = d4f_dx23_dt;
  const double d4f_dx23_du = _t26*_t43 + _t27*_t43 + _t28*_t43 + _t29*_t43 + _t30*_t43;
  out[33] = d4f_dx23_du;
  const double d4f_dx24 = _t26*_t44 + _t27*_t44 + _t28*_t44 + _t29*_t44 + _t30*_t44;
  out[34] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {

  const double _t1 = xc_powr(n_s, -8, 3);
  const double _t2 = xc_powr(n_s, -5, 3);
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = (0.1e1 / (M_CBRTPI));
  const double _t5 = _t3*_t4;
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
  const double _t7 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t13 = xc_powr(n_s, -4, 3);
  const double _t16 = (0.5e1 / 0.3e1)*_t1;
  const double _t19 = xc_powr(n_s, -11, 3);
  const double _t20 = (0.8e1 / 0.3e1)*_t19;
#endif
#if _KMAX >= 2
  const double _t24 = xc_powr(n_s, -10, 3);
  const double _t29 = xc_powr(n_s, -13, 3);
  const double _t33 = xc_powr(n_s, -16, 3);
  const double _t36 = (0.5e1 / 0.3e1)*_t29;
  const double _t39 = (0.8e1 / 0.3e1)*sigma_ss;
  const double _t43 = _t36*lapl_s;
  const double _t47 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t48 = (0.5e1 / 0.3e1)*tau_s;
  const double _t49 = (0.5e1 / 0.3e1)*lapl_s;
  const double _t50 = xc_powr(n_s, -19, 3);
  const double _t51 = _t39*_t50;
  const double _t55 = xc_powr(n_s, -7, 3);
  const double _t58 = xc_powr(0.6e1, 2, 3);
  const double _t59 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t63 = (0.1e1 / 0.3e1)*_t13;
  const double _t64 = (0.40e2 / 0.9e1)*_t19;
  const double _t67 = xc_powr(n_s, -14, 3);
  const double _t68 = (0.88e2 / 0.9e1)*_t67;
#endif
#if _KMAX >= 3
  const double _t86 = xc_powi(n_s, -5);
  const double _t92 = xc_powi(n_s, -6);
  const double _t97 = xc_powi(n_s, -7);
  const double _t101 = xc_powi(n_s, -8);
  const double _t104 = (0.10e2 / 0.3e1)*_t29;
  const double _t105 = _t48*_t92;
  const double _t106 = _t49*_t92;
  const double _t107 = _t39*_t97;
  const double _t114 = xc_powr(n_s, -17, 3);
  const double _t116 = (0.13e2 / 0.3e1)*_t33;
  const double _t117 = _t48*_t97;
  const double _t118 = _t49*_t97;
  const double _t119 = _t101*_t39;
  const double _t124 = xc_powr(n_s, -20, 3);
  const double _t125 = (0.16e2 / 0.3e1)*_t50;
  const double _t128 = xc_powi(n_s, -9);
  const double _t137 = (0.40e2 / 0.9e1)*_t33;
  const double _t140 = (0.88e2 / 0.9e1)*sigma_ss;
  const double _t141 = _t36*tau_s;
  const double _t142 = _t33*_t39;
  const double _t144 = _t16*lapl_s;
  const double _t148 = _t16*tau_s;
  const double _t151 = _t137*lapl_s;
  const double _t158 = (0.40e2 / 0.9e1)*tau_s;
  const double _t159 = (0.40e2 / 0.9e1)*lapl_s;
  const double _t160 = xc_powr(n_s, -22, 3);
  const double _t162 = _t33*_t48;
  const double _t163 = _t33*_t49;
  const double _t167 = _t20*sigma_ss;
  const double _t177 = (0.440e3 / 0.27e2)*_t67;
  const double _t180 = (0.1232e4 / 0.27e2)*_t114;
#endif
#if _KMAX >= 4
  const double _t228 = xc_powr(n_s, -23, 3);
  const double _t230 = xc_powr(n_s, -26, 3);
  const double _t232 = xc_powr(n_s, -29, 3);
  const double _t234 = xc_powr(n_s, -32, 3);
  const double _t236 = 0.5e1*_t92;
  const double _t237 = _t228*_t48;
  const double _t238 = _t228*_t49;
  const double _t239 = _t230*_t39;
  const double _t241 = 0.6e1*_t97;
  const double _t242 = _t230*_t48;
  const double _t243 = _t230*_t49;
  const double _t244 = _t232*_t39;
  const double _t245 = xc_powr(n_s, -25, 3);
  const double _t247 = 0.7e1*_t101;
  const double _t248 = _t232*_t48;
  const double _t249 = _t232*_t49;
  const double _t250 = _t234*_t39;
  const double _t256 = (0.80e2 / 0.9e1)*_t33;
  const double _t257 = _t158*_t97;
  const double _t258 = _t159*_t97;
  const double _t259 = _t101*_t140;
  const double _t260 = (0.10e2 / 0.3e1)*_t1;
  const double _t269 = _t101*_t48;
  const double _t270 = _t101*_t49;
  const double _t271 = _t128*_t39;
  const double _t276 = (0.440e3 / 0.27e2)*_t50;
  const double _t278 = (0.1232e4 / 0.27e2)*sigma_ss;
  const double _t280 = _t137*tau_s;
  const double _t281 = _t140*_t50;
  const double _t291 = _t158*_t50;
  const double _t292 = _t159*_t50;
  const double _t293 = _t140*_t160;
  const double _t297 = (0.6160e4 / 0.81e2)*_t114;
  const double _t298 = (0.440e3 / 0.9e1)*_t67;
  const double _t299 = (0.40e2 / 0.3e1)*_t19;
  const double _t300 = _t177*tau_s;
  const double _t301 = _t180*sigma_ss;
  const double _t302 = _t64*tau_s;
  const double _t303 = _t64*lapl_s;
  const double _t304 = _t68*sigma_ss;
  const double _t312 = _t177*lapl_s;
#endif
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t7)) XC_CAT(edmgga_f_pf_k, _KMAX)(p, _t1*sigma_ss, _t2*lapl_s, _t2*tau_s, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t7)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t6/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc1);
  const double _t8 = my_piecewise3(_t7, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t9 = _hc1[0]*_t2;
  const double _t10 = my_piecewise3(_t7, 0, _hc0[1]*_t9);
  const double _t11 = my_piecewise3(_t7, 0, _hc0[2]*_t9);
  const double _t12 = my_piecewise3(_t7, 0, _hc0[3]*_hc1[0]*_t1);
  const double _t14 = _hc1[2]*_t5;
  const double _t15 = (0.1e1 / 0.6e1)*_t14;
  const double _t17 = _hc0[1]*_t16;
  const double _t18 = _hc0[2]*_t16;
  const double _t21 = _hc0[3]*_t20;
  const double _t22 = -_t17*tau_s - _t18*lapl_s - _t21*sigma_ss;
  const double _t23 = my_piecewise3(_t7, 0, -_hc0[0]*_t13*_t15 + _hc1[0]*_t22);
#endif
#if _KMAX >= 2
  const double _t25 = _hc1[0]*_t24;
  const double _t26 = my_piecewise3(_t7, 0, _hc0[4]*_t25);
  const double _t27 = my_piecewise3(_t7, 0, _hc0[5]*_t25);
  const double _t28 = my_piecewise3(_t7, 0, _hc0[6]*_t25);
  const double _t30 = _hc1[0]*_t29;
  const double _t31 = my_piecewise3(_t7, 0, _hc0[7]*_t30);
  const double _t32 = my_piecewise3(_t7, 0, _hc0[8]*_t30);
  const double _t34 = my_piecewise3(_t7, 0, _hc0[9]*_hc1[0]*_t33);
  const double _t35 = _t15/(n_s * n_s * n_s);
  const double _t37 = _hc0[4]*tau_s;
  const double _t38 = _hc0[5]*_t36;
  const double _t40 = _hc0[7]*_t33;
  const double _t41 = -_t17 - _t36*_t37 - _t38*lapl_s - _t39*_t40;
  const double _t42 = my_piecewise3(_t7, 0, -_hc0[1]*_t35 + _hc1[0]*_t41);
  const double _t44 = _hc0[8]*_t33;
  const double _t45 = -_hc0[6]*_t43 - _t18 - _t38*tau_s - _t39*_t44;
  const double _t46 = my_piecewise3(_t7, 0, -_hc0[2]*_t35 + _hc1[0]*_t45);
  const double _t52 = -_hc0[9]*_t51 - _t21 - _t40*_t48 - _t44*_t49;
  const double _t53 = my_piecewise3(_t7, 0, -_hc0[3]*_t15*_t47 + _hc1[0]*_t52);
  const double _t54 = (0.2e1 / 0.9e1)*_hc0[0];
  const double _t56 = _t14*_t55;
  const double _t57 = (0.1e1 / 0.36e2)*_hc0[0];
  const double _t60 = _hc1[5]*_t58*_t59;
  const double _t61 = _t1*_t60;
  const double _t62 = _t14*_t22;
  const double _t65 = _hc0[1]*_t64;
  const double _t66 = _hc0[2]*_t64;
  const double _t69 = _hc0[3]*_t68;
  const double _t70 = _hc0[5]*_t16;
  const double _t71 = _hc0[6]*_t16;
  const double _t72 = _hc0[8]*_t20;
  const double _t73 = -_t70*tau_s - _t71*lapl_s - _t72*sigma_ss;
  const double _t74 = _t16*_t73;
  const double _t75 = _hc0[7]*_t16;
  const double _t76 = _hc0[8]*_t16;
  const double _t77 = _hc0[9]*_t20;
  const double _t78 = -_t75*tau_s - _t76*lapl_s - _t77*sigma_ss;
  const double _t79 = _t20*_t78;
  const double _t80 = _hc0[4]*_t16;
  const double _t81 = _hc0[7]*_t20;
  const double _t82 = -_t70*lapl_s - _t80*tau_s - _t81*sigma_ss;
  const double _t83 = _t16*_t82;
  const double _t84 = _t65*tau_s + _t66*lapl_s + _t69*sigma_ss - _t74*lapl_s - _t79*sigma_ss - _t83*tau_s;
  const double _t85 = my_piecewise3(_t7, 0, _hc1[0]*_t84 + _t54*_t56 + _t57*_t61 - _t62*_t63);
#endif
#if _KMAX >= 3
  const double _t87 = _hc1[0]*_t86;
  const double _t88 = my_piecewise3(_t7, 0, _hc0[10]*_t87);
  const double _t89 = my_piecewise3(_t7, 0, _hc0[11]*_t87);
  const double _t90 = my_piecewise3(_t7, 0, _hc0[12]*_t87);
  const double _t91 = my_piecewise3(_t7, 0, _hc0[13]*_t87);
  const double _t93 = _hc1[0]*_t92;
  const double _t94 = my_piecewise3(_t7, 0, _hc0[14]*_t93);
  const double _t95 = my_piecewise3(_t7, 0, _hc0[15]*_t93);
  const double _t96 = my_piecewise3(_t7, 0, _hc0[16]*_t93);
  const double _t98 = _hc1[0]*_t97;
  const double _t99 = my_piecewise3(_t7, 0, _hc0[17]*_t98);
  const double _t100 = my_piecewise3(_t7, 0, _hc0[18]*_t98);
  const double _t102 = my_piecewise3(_t7, 0, _hc0[19]*_hc1[0]*_t101);
  const double _t103 = _t15*_t67;
  const double _t108 = -_hc0[10]*_t105 - _hc0[11]*_t106 - _hc0[14]*_t107 - _hc0[4]*_t104;
  const double _t109 = my_piecewise3(_t7, 0, -_hc0[4]*_t103 + _hc1[0]*_t108);
  const double _t110 = -_hc0[11]*_t105 - _hc0[12]*_t106 - _hc0[15]*_t107 - _hc0[5]*_t104;
  const double _t111 = my_piecewise3(_t7, 0, -_hc0[5]*_t103 + _hc1[0]*_t110);
  const double _t112 = -_hc0[12]*_t105 - _hc0[13]*_t106 - _hc0[16]*_t107 - _hc0[6]*_t104;
  const double _t113 = my_piecewise3(_t7, 0, -_hc0[6]*_t103 + _hc1[0]*_t112);
  const double _t115 = _t114*_t15;
  const double _t120 = -_hc0[14]*_t117 - _hc0[15]*_t118 - _hc0[17]*_t119 - _hc0[7]*_t116;
  const double _t121 = my_piecewise3(_t7, 0, -_hc0[7]*_t115 + _hc1[0]*_t120);
  const double _t122 = -_hc0[15]*_t117 - _hc0[16]*_t118 - _hc0[18]*_t119 - _hc0[8]*_t116;
  const double _t123 = my_piecewise3(_t7, 0, -_hc0[8]*_t115 + _hc1[0]*_t122);
  const double _t126 = _hc0[17]*_t48;
  const double _t127 = _hc0[18]*_t49;
  const double _t129 = _hc0[19]*_t128;
  const double _t130 = -_hc0[9]*_t125 - _t101*_t126 - _t101*_t127 - _t129*_t39;
  const double _t131 = my_piecewise3(_t7, 0, -_hc0[9]*_t124*_t15 + _hc1[0]*_t130);
  const double _t132 = (0.2e1 / 0.9e1)*_t14;
  const double _t133 = _t132*_t47;
  const double _t134 = (0.1e1 / 0.36e2)*_t60;
  const double _t135 = _t134*_t29;
  const double _t136 = _t14*_t63;
  const double _t138 = _hc0[5]*_t137;
  const double _t139 = _hc0[7]*_t50;
  const double _t143 = -_hc0[11]*_t141 - _hc0[12]*_t43 - _hc0[15]*_t142 - _t70;
  const double _t145 = -_hc0[14]*_t141 - _hc0[15]*_t43 - _hc0[17]*_t142 - _t75;
  const double _t146 = _t145*_t20;
  const double _t147 = -_hc0[10]*_t141 - _hc0[11]*_t43 - _hc0[14]*_t142 - _t80;
  const double _t149 = _t137*_t37 + _t138*lapl_s + _t139*_t140 - _t143*_t144 - _t146*sigma_ss - _t147*_t148 + _t65 - _t83;
  const double _t150 = my_piecewise3(_t7, 0, _hc0[1]*_t133 + _hc0[1]*_t135 + _hc1[0]*_t149 - _t136*_t41);
  const double _t152 = _hc0[8]*_t50;
  const double _t153 = -_hc0[12]*_t141 - _hc0[13]*_t43 - _hc0[16]*_t142 - _t71;
  const double _t154 = -_hc0[15]*_t141 - _hc0[16]*_t43 - _hc0[18]*_t142 - _t76;
  const double _t155 = _t154*_t20;
  const double _t156 = _hc0[6]*_t151 + _t138*tau_s + _t140*_t152 - _t143*_t148 - _t144*_t153 - _t155*sigma_ss + _t66 - _t74;
  const double _t157 = my_piecewise3(_t7, 0, _hc0[2]*_t133 + _hc0[2]*_t135 + _hc1[0]*_t156 - _t136*_t45);
  const double _t161 = _hc0[9]*_t160;
  const double _t164 = -_hc0[15]*_t162 - _hc0[16]*_t163 - _hc0[18]*_t51 - _t72;
  const double _t165 = _t16*_t164;
  const double _t166 = -_hc0[19]*_t51 - _t126*_t33 - _t127*_t33 - _t77;
  const double _t168 = -_hc0[14]*_t162 - _hc0[15]*_t163 - _hc0[17]*_t51 - _t81;
  const double _t169 = _t16*_t168;
  const double _t170 = _t139*_t158 + _t140*_t161 + _t152*_t159 - _t165*lapl_s - _t166*_t167 - _t169*tau_s + _t69 - _t79;
  const double _t171 = my_piecewise3(_t7, 0, _hc0[3]*_t132*_t86 + _hc0[3]*_t134*_t33 + _hc1[0]*_t170 - _t136*_t52);
  const double _t172 = _hc1[9]/M_PI;
  const double _t173 = _t172*_t47;
  const double _t174 = (0.14e2 / 0.27e2)*_t14;
  const double _t175 = (0.1e1 / 0.9e1)*_t60;
  const double _t176 = _hc1[2]*_t13*_t6;
  const double _t178 = _hc0[1]*_t177;
  const double _t179 = _hc0[2]*_t177;
  const double _t181 = _hc0[3]*_t180;
  const double _t182 = _hc0[5]*_t64;
  const double _t183 = _hc0[6]*_t64;
  const double _t184 = _hc0[8]*_t68;
  const double _t185 = _hc0[12]*_t16;
  const double _t186 = _hc0[13]*_t16;
  const double _t187 = _hc0[16]*_t20;
  const double _t188 = -_t185*tau_s - _t186*lapl_s - _t187*sigma_ss;
  const double _t189 = _t16*_t188;
  const double _t190 = _hc0[15]*_t16;
  const double _t191 = _hc0[16]*_t16;
  const double _t192 = _hc0[18]*_t20;
  const double _t193 = -_t190*tau_s - _t191*lapl_s - _t192*sigma_ss;
  const double _t194 = _t193*_t20;
  const double _t195 = _hc0[11]*_t16;
  const double _t196 = _hc0[15]*_t20;
  const double _t197 = -_t185*lapl_s - _t195*tau_s - _t196*sigma_ss;
  const double _t198 = _t16*_t197;
  const double _t199 = _t182*tau_s + _t183*lapl_s + _t184*sigma_ss - _t189*lapl_s - _t194*sigma_ss - _t198*tau_s;
  const double _t200 = _t16*_t199;
  const double _t201 = _hc0[7]*_t64;
  const double _t202 = _hc0[8]*_t64;
  const double _t203 = _hc0[9]*_t68;
  const double _t204 = _t16*_t193;
  const double _t205 = _hc0[17]*_t16;
  const double _t206 = _hc0[18]*_t16;
  const double _t207 = _hc0[19]*_t20;
  const double _t208 = -_t205*tau_s - _t206*lapl_s - _t207*sigma_ss;
  const double _t209 = _t20*_t208;
  const double _t210 = _hc0[14]*_t16;
  const double _t211 = _hc0[17]*_t20;
  const double _t212 = -_t190*lapl_s - _t210*tau_s - _t211*sigma_ss;
  const double _t213 = _t16*_t212;
  const double _t214 = _t201*tau_s + _t202*lapl_s + _t203*sigma_ss - _t204*lapl_s - _t209*sigma_ss - _t213*tau_s;
  const double _t215 = _t20*_t214;
  const double _t216 = _hc0[4]*_t64;
  const double _t217 = _hc0[7]*_t68;
  const double _t218 = _t20*_t212;
  const double _t219 = _hc0[10]*_t16;
  const double _t220 = _hc0[14]*_t20;
  const double _t221 = -_t195*lapl_s - _t219*tau_s - _t220*sigma_ss;
  const double _t222 = _t16*_t221;
  const double _t223 = _t182*lapl_s - _t198*lapl_s + _t216*tau_s + _t217*sigma_ss - _t218*sigma_ss - _t222*tau_s;
  const double _t224 = _t16*_t223;
  const double _t225 = -_t178*tau_s - _t179*lapl_s - _t181*sigma_ss + (0.80e2 / 0.9e1)*_t19*_t73*lapl_s + (0.80e2 / 0.9e1)*_t19*_t82*tau_s - _t200*lapl_s - _t215*sigma_ss - _t224*tau_s + (0.176e3 / 0.9e1)*_t67*_t78*sigma_ss;
  const double _t226 = my_piecewise3(_t7, 0, -_hc0[0]*_t174*_t24 - _hc0[0]*_t175*_t19 + _hc1[0]*_t225 + (0.2e1 / 0.3e1)*_hc1[2]*_t22*_t3*_t4*_t55 + (0.1e1 / 0.12e2)*_hc1[5]*_t1*_t22*_t58*_t59 - _t173*_t57 - _t176*_t84);
#endif
#if _KMAX >= 4
  const double _t227 = _hc1[0]*_t124;
  const double _t229 = _hc1[0]*_t228;
  const double _t231 = _hc1[0]*_t230;
  const double _t233 = _hc1[0]*_t232;
  const double _t235 = _t15*_t50;
  const double _t240 = _t15*_t160;
  const double _t246 = _t15*_t245;
  const double _t251 = _hc0[32]*_t48;
  const double _t252 = _hc0[33]*_t49;
  const double _t253 = _hc0[34]*_t39;
  const double _t254 = _t114*_t132;
  const double _t255 = _t134*_t92;
  const double _t261 = -_hc0[11]*_t104 - _hc0[21]*_t105 - _hc0[22]*_t106 - _hc0[26]*_t107;
  const double _t262 = -_hc0[12]*_t104 - _hc0[22]*_t105 - _hc0[23]*_t106 - _hc0[27]*_t107;
  const double _t263 = _t124*_t132;
  const double _t264 = _t134*_t97;
  const double _t265 = -_hc0[15]*_t116 - _hc0[26]*_t117 - _hc0[27]*_t118 - _hc0[30]*_t119;
  const double _t266 = _hc0[17]*_t158;
  const double _t267 = _hc0[18]*_t159;
  const double _t268 = _hc0[19]*_t140;
  const double _t272 = (0.1e1 / 0.36e2)*_t172;
  const double _t273 = _t114*_t272;
  const double _t274 = _t174*_t86;
  const double _t275 = _t175*_t33;
  const double _t277 = _hc0[5]*_t276;
  const double _t279 = _hc0[7]*_t160;
  const double _t282 = -_hc0[22]*_t141 - _hc0[23]*_t43 - _hc0[27]*_t142 - _t185;
  const double _t283 = -_hc0[26]*_t141 - _hc0[27]*_t43 - _hc0[30]*_t142 - _t190;
  const double _t284 = -_hc0[21]*_t141 - _hc0[22]*_t43 - _hc0[26]*_t142 - _t195;
  const double _t285 = _hc0[11]*_t280 + _hc0[12]*_t151 + _hc0[15]*_t281 - _t144*_t282 - _t148*_t284 - _t167*_t283 + _t182 - _t198;
  const double _t286 = -_hc0[25]*_t141 - _hc0[26]*_t43 - _hc0[29]*_t142 - _t210;
  const double _t287 = _hc0[6]*lapl_s;
  const double _t288 = _hc0[8]*_t160;
  const double _t289 = -_hc0[27]*_t141 - _hc0[28]*_t43 - _hc0[31]*_t142 - _t191;
  const double _t290 = _hc0[3]*_t124;
  const double _t294 = -_hc0[30]*_t162 - _hc0[31]*_t163 - _hc0[33]*_t51 - _t192;
  const double _t295 = -_hc0[26]*_t162 - _hc0[27]*_t163 - _hc0[30]*_t51 - _t196;
  const double _t296 = -_hc0[29]*_t162 - _hc0[30]*_t163 - _hc0[32]*_t51 - _t211;
  const double _t305 = -_hc0[27]*_t148 - _hc0[28]*_t144 - _hc0[31]*_t167;
  const double _t306 = -_hc0[22]*_t148 - _hc0[23]*_t144 - _hc0[27]*_t167;
  const double _t307 = -_hc0[30]*_t148 - _hc0[31]*_t144 - _hc0[33]*_t167;
  const double _t308 = -_hc0[26]*_t148 - _hc0[27]*_t144 - _hc0[30]*_t167;
  const double _t309 = _hc0[15]*_t302 + _hc0[16]*_t303 + _hc0[18]*_t304 - _t144*_t305 - _t148*_t308 - _t167*_t307;
  const double _t310 = -_hc0[21]*_t148 - _hc0[22]*_t144 - _hc0[26]*_t167;
  const double _t311 = _hc0[11]*_t302 + _hc0[12]*_t303 + _hc0[15]*_t304 - _t144*_t306 - _t148*_t310 - _t167*_t308;
  const double _t313 = -_hc0[29]*_t148 - _hc0[30]*_t144 - _hc0[32]*_t167;
  const double _t314 = -_hc0[25]*_t148 - _hc0[26]*_t144 - _hc0[29]*_t167;
  const double _t315 = _hc0[14]*_t302 + _hc0[15]*_t303 + _hc0[17]*_t304 - _t144*_t308 - _t148*_t314 - _t167*_t313;
#endif

  const double f = my_piecewise3(_t7, 0, _t8*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t7, 0, _t10*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = my_piecewise3(_t7, 0, _t11*n_s);
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t7, 0, _t12*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t7, 0, _t23*n_s + _t8);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = my_piecewise3(_t7, 0, _t26*n_s);
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = my_piecewise3(_t7, 0, _t27*n_s);
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = my_piecewise3(_t7, 0, _t28*n_s);
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = my_piecewise3(_t7, 0, _t31*n_s);
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = my_piecewise3(_t7, 0, _t32*n_s);
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t7, 0, _t34*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t7, 0, _t10 + _t42*n_s);
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = my_piecewise3(_t7, 0, _t11 + _t46*n_s);
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t7, 0, _t12 + _t53*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t7, 0, 0.2e1*_t23 + _t85*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = my_piecewise3(_t7, 0, _t88*n_s);
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = my_piecewise3(_t7, 0, _t89*n_s);
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = my_piecewise3(_t7, 0, _t90*n_s);
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = my_piecewise3(_t7, 0, _t91*n_s);
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = my_piecewise3(_t7, 0, _t94*n_s);
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = my_piecewise3(_t7, 0, _t95*n_s);
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = my_piecewise3(_t7, 0, _t96*n_s);
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = my_piecewise3(_t7, 0, _t99*n_s);
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = my_piecewise3(_t7, 0, _t100*n_s);
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t7, 0, _t102*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = my_piecewise3(_t7, 0, _t109*n_s + _t26);
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = my_piecewise3(_t7, 0, _t111*n_s + _t27);
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = my_piecewise3(_t7, 0, _t113*n_s + _t28);
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = my_piecewise3(_t7, 0, _t121*n_s + _t31);
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = my_piecewise3(_t7, 0, _t123*n_s + _t32);
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t7, 0, _t131*n_s + _t34);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t7, 0, _t150*n_s + 0.2e1*_t42);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = my_piecewise3(_t7, 0, _t157*n_s + 0.2e1*_t46);
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t7, 0, _t171*n_s + 0.2e1*_t53);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t7, 0, _t226*n_s + 0.3e1*_t85);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[20]*_t227));
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[21]*_t227));
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[22]*_t227));
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[23]*_t227));
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[24]*_t227));
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[25]*_t229));
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[26]*_t229));
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[27]*_t229));
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[28]*_t229));
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[29]*_t231));
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[30]*_t231));
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[31]*_t231));
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[32]*_t233));
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[33]*_t233));
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[34]*_hc1[0]*_t234));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = my_piecewise3(_t7, 0, _t88 + n_s*my_piecewise3(_t7, 0, -_hc0[10]*_t235 + _hc1[0]*(-_hc0[10]*_t236 - _hc0[20]*_t237 - _hc0[21]*_t238 - _hc0[25]*_t239)));
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = my_piecewise3(_t7, 0, _t89 + n_s*my_piecewise3(_t7, 0, -_hc0[11]*_t235 + _hc1[0]*(-_hc0[11]*_t236 - _hc0[21]*_t237 - _hc0[22]*_t238 - _hc0[26]*_t239)));
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = my_piecewise3(_t7, 0, _t90 + n_s*my_piecewise3(_t7, 0, -_hc0[12]*_t235 + _hc1[0]*(-_hc0[12]*_t236 - _hc0[22]*_t237 - _hc0[23]*_t238 - _hc0[27]*_t239)));
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = my_piecewise3(_t7, 0, _t91 + n_s*my_piecewise3(_t7, 0, -_hc0[13]*_t235 + _hc1[0]*(-_hc0[13]*_t236 - _hc0[23]*_t237 - _hc0[24]*_t238 - _hc0[28]*_t239)));
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = my_piecewise3(_t7, 0, _t94 + n_s*my_piecewise3(_t7, 0, -_hc0[14]*_t240 + _hc1[0]*(-_hc0[14]*_t241 - _hc0[25]*_t242 - _hc0[26]*_t243 - _hc0[29]*_t244)));
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = my_piecewise3(_t7, 0, _t95 + n_s*my_piecewise3(_t7, 0, -_hc0[15]*_t240 + _hc1[0]*(-_hc0[15]*_t241 - _hc0[26]*_t242 - _hc0[27]*_t243 - _hc0[30]*_t244)));
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = my_piecewise3(_t7, 0, _t96 + n_s*my_piecewise3(_t7, 0, -_hc0[16]*_t240 + _hc1[0]*(-_hc0[16]*_t241 - _hc0[27]*_t242 - _hc0[28]*_t243 - _hc0[31]*_t244)));
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = my_piecewise3(_t7, 0, _t99 + n_s*my_piecewise3(_t7, 0, -_hc0[17]*_t246 + _hc1[0]*(-_hc0[17]*_t247 - _hc0[29]*_t248 - _hc0[30]*_t249 - _hc0[32]*_t250)));
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = my_piecewise3(_t7, 0, _t100 + n_s*my_piecewise3(_t7, 0, -_hc0[18]*_t246 + _hc1[0]*(-_hc0[18]*_t247 - _hc0[30]*_t248 - _hc0[31]*_t249 - _hc0[33]*_t250)));
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t7, 0, _t102 + n_s*my_piecewise3(_t7, 0, -_hc0[19]*_t15/xc_powr(n_s, 28, 3) + _hc1[0]*(-0.8e1*_t129 - _t234*_t251 - _t234*_t252 - _t253/xc_powr(n_s, 35, 3))));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = my_piecewise3(_t7, 0, 0.2e1*_t109 + n_s*my_piecewise3(_t7, 0, _hc0[4]*_t254 + _hc0[4]*_t255 + _hc1[0]*(_hc0[10]*_t257 + _hc0[11]*_t258 + _hc0[14]*_t259 + _hc0[4]*_t256 - _t144*_t261 - _t147*_t260 - _t148*(-_hc0[10]*_t104 - _hc0[20]*_t105 - _hc0[21]*_t106 - _hc0[25]*_t107) - _t167*(-_hc0[14]*_t104 - _hc0[25]*_t105 - _hc0[26]*_t106 - _hc0[29]*_t107)) - _t108*_t136));
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = my_piecewise3(_t7, 0, 0.2e1*_t111 + n_s*my_piecewise3(_t7, 0, _hc0[5]*_t254 + _hc0[5]*_t255 + _hc1[0]*(_hc0[11]*_t257 + _hc0[12]*_t258 + _hc0[15]*_t259 + _hc0[5]*_t256 - _t143*_t260 - _t144*_t262 - _t148*_t261 - _t167*(-_hc0[15]*_t104 - _hc0[26]*_t105 - _hc0[27]*_t106 - _hc0[30]*_t107)) - _t110*_t136));
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = my_piecewise3(_t7, 0, 0.2e1*_t113 + n_s*my_piecewise3(_t7, 0, _hc0[6]*_t254 + _hc0[6]*_t255 + _hc1[0]*(_hc0[12]*_t257 + _hc0[13]*_t258 + _hc0[16]*_t259 + _hc0[6]*_t256 - _t144*(-_hc0[13]*_t104 - _hc0[23]*_t105 - _hc0[24]*_t106 - _hc0[28]*_t107) - _t148*_t262 - _t153*_t260 - _t167*(-_hc0[16]*_t104 - _hc0[27]*_t105 - _hc0[28]*_t106 - _hc0[31]*_t107)) - _t112*_t136));
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = my_piecewise3(_t7, 0, 0.2e1*_t121 + n_s*my_piecewise3(_t7, 0, _hc0[7]*_t263 + _hc0[7]*_t264 + _hc1[0]*((0.40e2 / 0.9e1)*_hc0[14]*_t101*tau_s + (0.40e2 / 0.9e1)*_hc0[15]*_t101*lapl_s + (0.88e2 / 0.9e1)*_hc0[17]*_t128*sigma_ss + (0.128e3 / 0.9e1)*_hc0[7]*_t50 - _t144*_t265 - _t146 - _t148*(-_hc0[14]*_t116 - _hc0[25]*_t117 - _hc0[26]*_t118 - _hc0[29]*_t119) - _t167*(-_hc0[17]*_t116 - _hc0[29]*_t117 - _hc0[30]*_t118 - _hc0[32]*_t119) - _t169) - _t120*_t136));
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = my_piecewise3(_t7, 0, 0.2e1*_t123 + n_s*my_piecewise3(_t7, 0, _hc0[8]*_t263 + _hc0[8]*_t264 + _hc1[0]*((0.40e2 / 0.9e1)*_hc0[15]*_t101*tau_s + (0.40e2 / 0.9e1)*_hc0[16]*_t101*lapl_s + (0.88e2 / 0.9e1)*_hc0[18]*_t128*sigma_ss + (0.128e3 / 0.9e1)*_hc0[8]*_t50 - _t144*(-_hc0[16]*_t116 - _hc0[27]*_t117 - _hc0[28]*_t118 - _hc0[31]*_t119) - _t148*_t265 - _t155 - _t165 - _t167*(-_hc0[18]*_t116 - _hc0[30]*_t117 - _hc0[31]*_t118 - _hc0[33]*_t119)) - _t122*_t136));
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t7, 0, 0.2e1*_t131 + n_s*my_piecewise3(_t7, 0, _hc0[9]*_t101*_t134 + _hc0[9]*_t132*_t228 + _hc1[0]*(_t128*_t266 + _t128*_t267 - _t144*(-_hc0[18]*_t125 - _hc0[30]*_t269 - _hc0[31]*_t270 - _hc0[33]*_t271) - _t148*(-_hc0[17]*_t125 - _hc0[29]*_t269 - _hc0[30]*_t270 - _hc0[32]*_t271) + (0.176e3 / 0.9e1)*_t161 - 0.16e2 / 0.3e1*_t166*_t19 - _t167*(-_hc0[19]*_t125 - _t101*_t251 - _t101*_t252 - _t128*_t253) + _t268/xc_powi(n_s, 10)) - _t130*_t136));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t7, 0, 0.3e1*_t150 + n_s*my_piecewise3(_t7, 0, -_hc0[1]*_t273 - _hc0[1]*_t274 - _hc0[1]*_t275 + _hc1[0]*((0.80e2 / 0.9e1)*_t143*_t19*lapl_s - _t144*_t285 + (0.176e3 / 0.9e1)*_t145*_t67*sigma_ss + (0.80e2 / 0.9e1)*_t147*_t19*tau_s - _t148*(_hc0[10]*_t280 + _hc0[11]*_t151 + _hc0[14]*_t281 - _t144*_t284 - _t148*(-_hc0[20]*_t141 - _hc0[21]*_t43 - _hc0[25]*_t142 - _t219) - _t167*_t286 + _t216 - _t222) - _t167*(_hc0[14]*_t280 + _hc0[15]*_t151 + _hc0[17]*_t281 - _t144*_t283 - _t148*_t286 - _t167*(-_hc0[29]*_t141 - _hc0[30]*_t43 - _hc0[32]*_t142 - _t205) + _t201 - _t213) - _t178 + (0.80e2 / 0.9e1)*_t19*_t82 - _t224 - _t276*_t37 - _t277*lapl_s - _t278*_t279) + (0.2e1 / 0.3e1)*_hc1[2]*_t3*_t4*_t41*_t55 + (0.1e1 / 0.12e2)*_hc1[5]*_t1*_t41*_t58*_t59 - _t149*_t176));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = my_piecewise3(_t7, 0, 0.3e1*_t157 + n_s*my_piecewise3(_t7, 0, -_hc0[2]*_t273 - _hc0[2]*_t274 - _hc0[2]*_t275 + _hc1[0]*((0.80e2 / 0.9e1)*_t143*_t19*tau_s - _t144*(_hc0[12]*_t280 + _hc0[13]*_t151 + _hc0[16]*_t281 - _t144*(-_hc0[23]*_t141 - _hc0[24]*_t43 - _hc0[28]*_t142 - _t186) - _t148*_t282 - _t167*_t289 + _t183 - _t189) - _t148*_t285 + (0.80e2 / 0.9e1)*_t153*_t19*lapl_s + (0.176e3 / 0.9e1)*_t154*_t67*sigma_ss - _t167*(_hc0[15]*_t280 + _hc0[16]*_t151 + _hc0[18]*_t281 - _t144*_t289 - _t148*_t283 - _t167*(-_hc0[30]*_t141 - _hc0[31]*_t43 - _hc0[33]*_t142 - _t206) + _t202 - _t204) - _t179 + (0.80e2 / 0.9e1)*_t19*_t73 - _t200 - _t276*_t287 - _t277*tau_s - _t278*_t288) + (0.2e1 / 0.3e1)*_hc1[2]*_t3*_t4*_t45*_t55 + (0.1e1 / 0.12e2)*_hc1[5]*_t1*_t45*_t58*_t59 - _t156*_t176));
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t7, 0, 0.3e1*_t171 + n_s*my_piecewise3(_t7, 0, -_hc0[3]*_t174*_t92 - _hc0[3]*_t175*_t50 + _hc1[0]*(-_hc0[9]*_t245*_t278 - _t144*(_hc0[15]*_t291 + _hc0[16]*_t292 + _hc0[18]*_t293 - _t144*(-_hc0[27]*_t162 - _hc0[28]*_t163 - _hc0[31]*_t51 - _t187) - _t148*_t295 - _t167*_t294 + _t184 - _t194) - _t148*(_hc0[14]*_t291 + _hc0[15]*_t292 + _hc0[17]*_t293 - _t144*_t295 - _t148*(-_hc0[25]*_t162 - _hc0[26]*_t163 - _hc0[29]*_t51 - _t220) - _t167*_t296 + _t217 - _t218) + (0.80e2 / 0.9e1)*_t164*_t19*lapl_s + (0.176e3 / 0.9e1)*_t166*_t67*sigma_ss - _t167*(-_t144*_t294 - _t148*_t296 + _t160*_t268 - _t167*(-_hc0[32]*_t162 - _hc0[33]*_t163 - _hc0[34]*_t51 - _t207) + _t203 - _t209 + _t266*_t50 + _t267*_t50) + (0.80e2 / 0.9e1)*_t168*_t19*tau_s - _t181 - _t215 - 0.440e3 / 0.27e2*_t279*tau_s - 0.440e3 / 0.27e2*_t288*lapl_s + (0.176e3 / 0.9e1)*_t67*_t78) + (0.2e1 / 0.3e1)*_hc1[2]*_t3*_t4*_t52*_t55 + (0.1e1 / 0.12e2)*_hc1[5]*_t1*_t52*_t58*_t59 - _t170*_t176 - _t272*_t290));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t7, 0, 0.4e1*_t226 + n_s*my_piecewise3(_t7, 0, (0.1e1 / 0.216e3)*_hc0[0]*_hc1[14]*_t3*_t33/(M_PI * M_CBRTPI) + (0.140e3 / 0.81e2)*_hc0[0]*_t14*_t29 + (0.40e2 / 0.81e2)*_hc0[0]*_t60*_t67 + _hc1[0]*(_hc0[1]*_t297*tau_s + _hc0[2]*_t297*lapl_s - 0.1232e4 / 0.9e1*_t114*_t78*sigma_ss - _t144*(-_hc0[5]*_t300 - _hc0[8]*_t301 - _t144*(_hc0[12]*_t302 + _hc0[13]*_t303 + _hc0[16]*_t304 - _t144*(-_hc0[23]*_t148 - _hc0[24]*_t144 - _hc0[28]*_t167) - _t148*_t306 - _t167*_t305) - _t148*_t311 - _t167*_t309 - _t177*_t287 + (0.80e2 / 0.9e1)*_t188*_t19*lapl_s + (0.80e2 / 0.9e1)*_t19*_t197*tau_s + (0.176e3 / 0.9e1)*_t193*_t67*sigma_ss) - _t148*(-_hc0[5]*_t312 - _hc0[7]*_t301 - _t144*_t311 - _t148*(_hc0[10]*_t302 + _hc0[11]*_t303 + _hc0[14]*_t304 - _t144*_t310 - _t148*(-_hc0[20]*_t148 - _hc0[21]*_t144 - _hc0[25]*_t167) - _t167*_t314) - _t167*_t315 - _t177*_t37 + (0.80e2 / 0.9e1)*_t19*_t197*lapl_s + (0.80e2 / 0.9e1)*_t19*_t221*tau_s + (0.176e3 / 0.9e1)*_t212*_t67*sigma_ss) - _t167*(-_hc0[7]*_t300 - _hc0[8]*_t312 - _hc0[9]*_t301 - _t144*_t309 - _t148*_t315 - _t167*(_hc0[17]*_t302 + _hc0[18]*_t303 + _hc0[19]*_t304 - _t144*_t307 - _t148*_t313 - _t167*(-_hc0[32]*_t148 - _hc0[33]*_t144 - _hc0[34]*_t167)) + (0.80e2 / 0.9e1)*_t19*_t193*lapl_s + (0.80e2 / 0.9e1)*_t19*_t212*tau_s + (0.176e3 / 0.9e1)*_t208*_t67*sigma_ss) + _t199*_t299*lapl_s + (0.88e2 / 0.3e1)*_t214*_t67*sigma_ss + _t223*_t299*tau_s + (0.20944e5 / 0.81e2)*_t290*sigma_ss - _t298*_t73*lapl_s - _t298*_t82*tau_s) - 0.2e1 / 0.3e1*_t13*_t14*_t225 + _t172*_t54*_t86 - 0.1e1 / 0.9e1*_t173*_t22 - 0.4e1 / 0.9e1*_t19*_t22*_t60 - 0.56e2 / 0.27e2*_t24*_t62 + (0.4e1 / 0.3e1)*_t56*_t84 + (0.1e1 / 0.6e1)*_t61*_t84));
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