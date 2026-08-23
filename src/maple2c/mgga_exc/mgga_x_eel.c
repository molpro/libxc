/*
  Generated from python/mgga_exc/mgga_x_eel.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_eel
*/

#ifndef _MGGA_X_EEL_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_EEL_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_EEL_HELPER_BODIES
#include "mgga_x_eel.c"
#undef _MGGA_X_EEL_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_EEL_HELPER_BODIES
#include "mgga_x_eel.c"
#undef _MGGA_X_EEL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_EEL_HELPER_BODIES
#include "mgga_x_eel.c"
#undef _MGGA_X_EEL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_EEL_HELPER_BODIES
#include "mgga_x_eel.c"
#undef _MGGA_X_EEL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_EEL_HELPER_BODIES
#include "mgga_x_eel.c"
#undef _MGGA_X_EEL_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_eel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_eel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_eel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_eel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_eel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_eel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_eel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_eel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_eel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_eel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_EEL_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(eel_G_k, _KMAX)(const xc_func_type *p, double x, double *out) {
  const mgga_x_eel_params *params = (const mgga_x_eel_params *)(p->params);

  const double _t1 = params->x0 < x;
  const double _t2 = -params->x0 + x;
  const double _t3 = _t2 > 0;
  const double _t4 = my_piecewise3(_t3, _t2, 0);
  const double _t5 = xc_expm1(-params->c/xc_powr(_t4, 1, 4));
#if _KMAX >= 1
  const double _t6 = my_piecewise3(_t3, 0.1e1, 0);
  const double _t7 = _t5 + 0.1e1;
  const double _t8 = _t7*params->c;
#endif
#if _KMAX >= 2
  const double _t9 = (_t6 * _t6);
  const double _t10 = ((params->c) * (params->c));
  const double _t11 = _t10*_t7;
#endif
#if _KMAX >= 3
  const double _t12 = (_t6 * _t6 * _t6);
  const double _t13 = ((params->c) * (params->c) * (params->c));
#endif
#if _KMAX >= 4
  const double _t14 = (_t6 * _t6 * _t6 * _t6);
#endif

  const double f = 1.1739999999999999*my_piecewise3(_t1, -_t5, 0.1e1);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = 1.1739999999999999*my_piecewise3(_t1, -0.1e1 / 0.4e1*_t6*_t8/xc_powr(_t4, 5, 4), 0);
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 1.1739999999999999*my_piecewise3(_t1, -0.1e1 / 0.16e2*_t11*_t9/xc_powr(_t4, 5, 2) + (0.5e1 / 0.16e2)*_t7*_t9*params->c/xc_powr(_t4, 9, 4), 0);
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 1.1739999999999999*my_piecewise3(_t1, (0.15e2 / 0.64e2)*_t10*_t12*_t7/xc_powr(_t4, 7, 2) - 0.1e1 / 0.64e2*_t12*_t13*_t7/xc_powr(_t4, 15, 4) - 0.45e2 / 0.64e2*_t12*_t8/xc_powr(_t4, 13, 4), 0);
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 1.1739999999999999*my_piecewise3(_t1, -0.255e3 / 0.256e3*_t11*_t14/xc_powr(_t4, 9, 2) + (0.15e2 / 0.128e3)*_t13*_t14*_t7/xc_powr(_t4, 19, 4) - 0.1e1 / 0.256e3*_t14*_t7*((params->c) * (params->c) * (params->c) * (params->c))/xc_powi(_t4, 5) + (0.585e3 / 0.256e3)*_t14*_t7*params->c/xc_powr(_t4, 17, 4), 0);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(eel_k_k, _KMAX)(const xc_func_type *p, double a0, double *out) {

  const double _t1 = (0.1e1 / a0);
  const double _t2 = tanh(_t1);
  const double _t3 = (0.3e1 / 0.5e1)*_t2;
#if _KMAX >= 1
  const double _t5 = (_t2 * _t2);
  const double _t6 = 0.1e1 - _t5;
  const double _t7 = -0.3e1 / 0.5e1*_t1*_t6 + _t3;
#endif
#if _KMAX >= 2
  const double _t12 = (0.1e1 / (a0 * a0 * a0));
  const double _t13 = _t2*_t6;
  const double _t14 = _t12*_t13;
  const double _t15 = (_t7 * _t7);
#endif
#if _KMAX >= 3
  const double _t19 = xc_powi(a0, -5);
  const double _t20 = (_t6 * _t6);
  const double _t21 = (0.1e1 / (a0 * a0 * a0 * a0));
  const double _t24 = (_t7 * _t7 * _t7);
  const double _t25 = 1.0439999999999996*_t24;
  const double _t29 = _t14*_t7;
#endif
#if _KMAX >= 4
  const double _t30 = xc_powi(a0, -6);
  const double _t31 = _t20*_t30;
  const double _t32 = xc_powi(a0, -7);
  const double _t33 = (_t7 * _t7 * _t7 * _t7);
  const double _t35 = _t1*((0.3e1 / 0.5e1)*_t5 - 0.3e1 / 0.5e1);
  const double _t36 = _t14*_t15;
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(eel_G_k, _KMAX)(p, _t3*a0, _hc0);
  const double _t4 = _hc0[0] - 1.1739999999999999;
#if _KMAX >= 1
  const double _t8 = (0.1e1 / (_t4 * _t4));
  const double _t9 = 0.17399999999999993*_t8;
#endif
#if _KMAX >= 2
  const double _t10 = _hc0[1]*_t8;
  const double _t11 = 0.2087999999999999*_t10;
  const double _t16 = ((_hc0[1]) * (_hc0[1]));
  const double _t17 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t18 = _t16*_t17;
#endif
#if _KMAX >= 3
  const double _t22 = _t10*_t13;
  const double _t23 = _t10*_t6;
  const double _t26 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t27 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t26;
  const double _t28 = _hc0[2]*_t8;
#endif
#if _KMAX >= 4
  const double _t34 = _t17*_t33;
#endif

  const double f = -0.17399999999999993/_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_da0 = _hc0[1]*_t7*_t9;
  out[1] = df_da0;
#endif
#if _KMAX >= 2
  const double d2f_da02 = 0.17399999999999993*_hc0[2]*_t15*_t8 - _t11*_t14 - 0.34799999999999986*_t15*_t18;
  out[2] = d2f_da02;
#endif
#if _KMAX >= 3
  const double d3f_da03 = -_hc0[1]*_hc0[2]*_t17*_t25 + _hc0[3]*_t24*_t9 + _t11*_t19*_t20 + 1.2527999999999995*_t18*_t29 - 0.4175999999999998*_t19*_t23*_t5 + 0.62639999999999973*_t21*_t22 + _t25*_t27 - 0.62639999999999973*_t28*_t29;
  out[3] = d3f_da03;
#endif
#if _KMAX >= 4
  const double d4f_da04 = -4.1759999999999984*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t33/xc_powi(_t4, 5) + 7.5167999999999973*_hc0[1]*_hc0[2]*_t12*_t15*_t17*_t2*_t6 - 1.3919999999999995*_hc0[1]*_hc0[3]*_t34 + 1.6703999999999992*_hc0[1]*_t2*_t20*_t32*_t8 + 3.3407999999999989*_hc0[1]*_t30*_t5*_t6*_t8 - 1.0439999999999996*((_hc0[2]) * (_hc0[2]))*_t34 + 6.2639999999999976*_hc0[2]*_t16*_t26*_t33 + 0.83519999999999961*_hc0[2]*_t19*_t20*_t8*(_t3 + _t35) + 2.5055999999999989*_hc0[2]*_t2*_t21*_t6*_t7*_t8 + 0.75167999999999968*_hc0[2]*_t20*_t30*_t5*_t8 - 1.2527999999999995*_hc0[3]*_t36*_t8 + 0.17399999999999993*_hc0[4]*_t33*_t8 - 1.6703999999999994*_t10*_t31 - 5.0111999999999979*_t13*_t18*_t21*_t7 + _t16*_t17*_t19*_t20*(-1.0022399999999996*_t2 - 1.6703999999999992*_t35) + 3.3407999999999984*_t16*_t17*_t19*_t5*_t6*_t7 - 1.5033599999999994*_t18*_t31*_t5 - 2.5055999999999989*_t19*_t22 - 1.6703999999999992*_t19*_t28*_t5*_t6*_t7 - 0.83519999999999961*(_t2 * _t2 * _t2)*_t23*_t32 - 7.5167999999999964*_t27*_t36;
  out[4] = d4f_da04;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(eel_atilde_k, _KMAX)(const xc_func_type *p, double a, double *out) {
  const mgga_x_eel_params *params = (const mgga_x_eel_params *)(p->params);

  const double _t1 = (0.1e1 / (params->a0));
  const double _t2 = tanh(_t1*a);
#if _KMAX >= 1
  const double _t3 = (_t2 * _t2);
  const double _t4 = 0.1e1 - _t3;
#endif
#if _KMAX >= 3
  const double _t5 = (0.1e1 / ((params->a0) * (params->a0)));
  const double _t6 = (_t4 * _t4);
#endif
#if _KMAX >= 4
  const double _t7 = (0.1e1 / ((params->a0) * (params->a0) * (params->a0)));
#endif

  const double f = _t2*params->a0;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _t4;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = -0.2e1*_t1*_t2*_t4;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = 0.4e1*_t3*_t4*_t5 - 0.2e1*_t5*_t6;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -0.8e1*(_t2 * _t2 * _t2)*_t4*_t7 + 0.16e2*_t2*_t6*_t7;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {
  const mgga_x_eel_params *params = (const mgga_x_eel_params *)(p->params);

  const double _t1 = xc_powr(n_s, -8, 3);
  const double _t2 = _t1*sigma_ss;
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t5 = _t3*_t4;
  const double _t6 = (0.1e1 / 0.24e2)*_t5;
  const double _t7 = _t2*_t6;
  const double _t8 = xc_powr(n_s, -5, 3);
  const double _t9 = (0.5e1 / 0.9e1)*_t5;
  const double _t10 = (0.1e1 / (M_CBRTPI));
  const double _t11 = _t10*_t3;
  const double _t12 = (0.1e1 / 0.2e1)*_t11;
  const double _t13 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t22 = _t1*_t6;
  const double _t27 = xc_powr(n_s, -4, 3);
  const double _t31 = xc_powr(n_s, -11, 3);
  const double _t32 = _t31*_t5;
  const double _t33 = (0.1e1 / 0.9e1)*_t32;
  const double _t34 = _t33*sigma_ss;
  const double _t36 = (0.5e1 / 0.3e1)*_t1;
  const double _t37 = (0.1e1 / 0.3e1)*_t31*sigma_ss - _t36*tau_s;
#endif
#if _KMAX >= 2
  const double _t41 = xc_powr(n_s, -10, 3);
  const double _t42 = xc_powr(0.6e1, 2, 3);
  const double _t43 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t44 = _t42*_t43;
  const double _t50 = _t41*_t44;
  const double _t53 = xc_powr(n_s, -13, 3);
  const double _t59 = xc_powr(n_s, -16, 3);
  const double _t60 = _t44*_t59;
  const double _t78 = xc_powr(n_s, -19, 3);
  const double _t85 = xc_powr(n_s, -7, 3);
  const double _t88 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t92 = xc_powr(n_s, -14, 3);
  const double _t93 = _t92*sigma_ss;
  const double _t94 = _t5*_t93;
  const double _t95 = (0.11e2 / 0.27e2)*_t94;
  const double _t96 = (0.11e2 / 0.9e1)*_t93;
  const double _t97 = _t31*tau_s;
  const double _t98 = -_t96 + (0.40e2 / 0.9e1)*_t97;
  const double _t100 = (_t37 * _t37);
  const double _t104 = (sigma_ss * sigma_ss);
  const double _t105 = xc_powr(n_s, -22, 3);
#endif
#if _KMAX >= 3
  const double _t110 = xc_powi(n_s, -5);
  const double _t111 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t118 = _t110*_t111;
  const double _t122 = xc_powi(n_s, -6);
  const double _t130 = xc_powi(n_s, -7);
  const double _t138 = xc_powi(n_s, -8);
  const double _t139 = _t111*_t138;
  const double _t168 = xc_powi(n_s, -9);
  const double _t175 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t183 = (0.50e2 / 0.81e2)*_t8;
  const double _t190 = _t5*_t92;
  const double _t191 = (0.11e2 / 0.27e2)*_t190;
  const double _t203 = (0.1e1 / M_PI);
  const double _t210 = xc_powr(n_s, -17, 3);
  const double _t211 = _t210*sigma_ss;
  const double _t212 = (0.154e3 / 0.81e2)*_t5;
  const double _t213 = _t211*_t212;
  const double _t214 = (_t37 * _t37 * _t37);
  const double _t216 = _t92*tau_s;
  const double _t217 = (0.154e3 / 0.27e2)*_t210*sigma_ss - 0.440e3 / 0.27e2*_t216;
  const double _t219 = -0.22e2 / 0.9e1*_t93 + (0.80e2 / 0.9e1)*_t97;
  const double _t223 = (sigma_ss * sigma_ss * sigma_ss);
#endif
#if _KMAX >= 4
  const double _t229 = xc_powr(n_s, -20, 3);
  const double _t230 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t231 = _t230*_t3;
  const double _t239 = xc_powr(n_s, -23, 3);
  const double _t241 = _t231*_t239;
  const double _t242 = (0.25e2 / 0.324e3)*_t241;
  const double _t245 = xc_powr(n_s, -26, 3);
  const double _t246 = _t231*_t245;
  const double _t248 = xc_powr(n_s, -29, 3);
  const double _t249 = _t231/xc_powr(n_s, 32, 3);
  const double _t251 = (0.25e2 / 0.243e3)*_t78;
  const double _t282 = _t210*_t212;
  const double _t286 = _t229*sigma_ss;
  const double _t287 = (0.2618e4 / 0.243e3)*_t286*_t5;
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t13)) XC_CAT(eel_G_k, _KMAX)(p, _t7, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(eel_atilde_k, _KMAX)(p, _t9*(-0.1e1 / 0.8e1*_t2 + _t8*tau_s), _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t13)) XC_CAT(eel_G_k, _KMAX)(p, (0.3e1 / 0.5e1)*_hc1[0] + _t7, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t13)) XC_CAT(eel_k_k, _KMAX)(p, params->a0, _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t13)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t12/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc4);
  const double _t14 = _hc0[0] + _hc3[0]*(-_hc0[0] + _hc2[0]);
  const double _t15 = my_piecewise3(_t13, 0, _hc4[0]*_t14);
#if _KMAX >= 1
  const double _t16 = _hc1[1]*_t5;
  const double _t17 = (0.1e1 / 0.3e1)*_t16;
  const double _t18 = _t17*_t8;
  const double _t19 = _hc3[0]*_hc4[0];
  const double _t20 = _hc2[1]*_t19;
  const double _t21 = my_piecewise3(_t13, 0, _t18*_t20);
  const double _t23 = _hc0[1]*_t22;
  const double _t24 = -_hc1[1]*_t22 + (0.1e1 / 0.24e2)*_t1*_t3*_t4;
  const double _t25 = _hc3[0]*(_hc2[1]*_t24 - _t23) + _t23;
  const double _t26 = my_piecewise3(_t13, 0, _hc4[0]*_t25);
  const double _t28 = _hc4[2]*_t11;
  const double _t29 = _t27*_t28;
  const double _t30 = (0.1e1 / 0.6e1)*_t29;
  const double _t35 = _hc0[1]*_t34;
  const double _t38 = _t17*_t37 - _t34;
  const double _t39 = _hc3[0]*(_hc2[1]*_t38 + _t35) - _t35;
  const double _t40 = my_piecewise3(_t13, 0, _hc4[0]*_t39 - _t14*_t30);
#endif
#if _KMAX >= 2
  const double _t45 = _hc1[2]*_t44;
  const double _t46 = (0.5e1 / 0.27e2)*_t45;
  const double _t47 = _t41*_t46;
  const double _t48 = ((_hc1[1]) * (_hc1[1]));
  const double _t49 = (0.1e1 / 0.9e1)*_t48;
  const double _t51 = _t49*_t50;
  const double _t52 = my_piecewise3(_t13, 0, _hc2[2]*_t19*_t51 + _t20*_t47);
  const double _t54 = _t45*_t53;
  const double _t55 = (0.5e1 / 0.216e3)*_t54;
  const double _t56 = _hc2[2]*_t24;
  const double _t57 = -_hc2[1]*_t55 + _t18*_t56;
  const double _t58 = my_piecewise3(_t13, 0, _t19*_t57);
  const double _t61 = (0.1e1 / 0.576e3)*_hc0[2]*_t60;
  const double _t62 = _hc1[2]*_t60;
  const double _t63 = (0.5e1 / 0.1728e4)*_t62;
  const double _t64 = (_t24 * _t24);
  const double _t65 = _hc3[0]*(_hc2[1]*_t63 + _hc2[2]*_t64 - _t61) + _t61;
  const double _t66 = my_piecewise3(_t13, 0, _hc4[0]*_t65);
  const double _t67 = _hc2[1]*_hc3[0];
  const double _t68 = _hc1[1]*_t67;
  const double _t69 = (0.1e1 / 0.18e2)*_t68;
  const double _t70 = _hc4[2]*_t42/(M_PI * M_CBRTPI * M_CBRTPI);
  const double _t71 = -_hc1[1]*_t1*_t9 + (0.5e1 / 0.27e2)*_hc1[2]*_t37*_t42*_t43*_t8;
  const double _t72 = _hc2[2]*_t38;
  const double _t73 = _hc2[1]*_t71 + _t18*_t72;
  const double _t74 = my_piecewise3(_t13, 0, _hc3[0]*_hc4[0]*_t73 - _t69*_t70/(n_s * n_s * n_s));
  const double _t75 = _t37*_t45;
  const double _t76 = _t1*_t75;
  const double _t77 = (0.1e1 / 0.9e1)*_hc1[1]*_t3*_t31*_t4 - _t33 - 0.5e1 / 0.216e3*_t76;
  const double _t79 = _hc0[2]*_t44;
  const double _t80 = _t78*_t79;
  const double _t81 = _hc0[1]*_t33 + (0.1e1 / 0.216e3)*_t80*sigma_ss;
  const double _t82 = _hc3[0]*(_hc2[1]*_t77 + _t38*_t56 + _t81) - _t81;
  const double _t83 = my_piecewise3(_t13, 0, _hc4[0]*_t82 - _t25*_t30);
  const double _t84 = (0.2e1 / 0.9e1)*_t14;
  const double _t86 = _t28*_t85;
  const double _t87 = (0.1e1 / 0.36e2)*_t14;
  const double _t89 = _hc4[5]*_t42*_t88;
  const double _t90 = _t1*_t89;
  const double _t91 = (0.1e1 / 0.3e1)*_t29;
  const double _t99 = _t16*_t98;
  const double _t101 = _t100*_t45;
  const double _t102 = (0.5e1 / 0.27e2)*_t101 + _t95 + (0.1e1 / 0.3e1)*_t99;
  const double _t103 = (_t38 * _t38);
  const double _t106 = _t105*_t79;
  const double _t107 = _hc0[1]*_t95 + (0.1e1 / 0.81e2)*_t104*_t106;
  const double _t108 = _hc3[0]*(_hc2[1]*_t102 + _hc2[2]*_t103 - _t107) + _t107;
  const double _t109 = my_piecewise3(_t13, 0, _hc4[0]*_t108 - _t39*_t91 + _t84*_t86 + _t87*_t90);
#endif
#if _KMAX >= 3
  const double _t112 = _hc1[3]*_t111;
  const double _t113 = (0.50e2 / 0.81e2)*_t110*_t112;
  const double _t114 = _hc1[1]*_hc2[2];
  const double _t115 = _t111*_t114;
  const double _t116 = (0.10e2 / 0.9e1)*_hc1[2];
  const double _t117 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t119 = (0.2e1 / 0.9e1)*_t117*_t118;
  const double _t120 = _hc2[3]*_t19;
  const double _t121 = my_piecewise3(_t13, 0, _t110*_t115*_t116*_t19 + _t113*_t20 + _t119*_t120);
  const double _t123 = _t112*_t122;
  const double _t124 = (0.25e2 / 0.324e3)*_t123;
  const double _t125 = _hc1[2]*_t122;
  const double _t126 = (0.5e1 / 0.54e2)*_t125;
  const double _t127 = _hc2[3]*_t24;
  const double _t128 = -_hc2[1]*_t124 - _t115*_t126 + _t127*_t51 + _t47*_t56;
  const double _t129 = my_piecewise3(_t13, 0, _t128*_t19);
  const double _t131 = _t112*_t130;
  const double _t132 = (0.25e2 / 0.2592e4)*_t131;
  const double _t133 = (0.5e1 / 0.864e3)*_hc1[2]*_t130;
  const double _t134 = (0.5e1 / 0.108e3)*_t54;
  const double _t135 = _hc2[3]*_t64;
  const double _t136 = _hc2[1]*_t132 + _t115*_t133 - _t134*_t56 + _t135*_t18;
  const double _t137 = my_piecewise3(_t13, 0, _t136*_t19);
  const double _t140 = (0.1e1 / 0.2304e4)*_hc0[3]*_t139;
  const double _t141 = _hc1[3]*_t139;
  const double _t142 = (0.25e2 / 0.20736e5)*_t141;
  const double _t143 = (_t24 * _t24 * _t24);
  const double _t144 = _hc3[0]*((0.5e1 / 0.576e3)*_hc1[2]*_hc2[2]*_t24*_t42*_t43*_t59 - _hc2[1]*_t142 + _hc2[3]*_t143 - _t140) + _t140;
  const double _t145 = my_piecewise3(_t13, 0, _hc4[0]*_t144);
  const double _t146 = _hc4[2]/(M_PI * M_PI * M_PI);
  const double _t147 = _t146*_t92;
  const double _t148 = (0.5e1 / 0.27e2)*_hc1[2];
  const double _t149 = _hc2[2]*_hc3[0];
  const double _t150 = (0.50e2 / 0.81e2)*_hc1[3]*_t111*_t37*_t41 - 0.50e2 / 0.81e2*_t54;
  const double _t151 = _hc2[3]*_t38;
  const double _t152 = _hc2[2]*_t71;
  const double _t153 = (0.2e1 / 0.3e1)*_t16;
  const double _t154 = _t153*_t8;
  const double _t155 = _hc2[1]*_t150 + _t151*_t51 + _t152*_t154 + _t47*_t72;
  const double _t156 = my_piecewise3(_t13, 0, _hc3[0]*_hc4[0]*_t155 - _t147*_t148*_t67 - _t147*_t149*_t49);
  const double _t157 = _hc3[0]*_t30;
  const double _t158 = _t112*_t37;
  const double _t159 = _t158*_t53;
  const double _t160 = -0.25e2 / 0.324e3*_t159 + (0.65e2 / 0.648e3)*_t62;
  const double _t161 = _hc2[2]*_t77;
  const double _t162 = _t127*_t38;
  const double _t163 = _hc2[1]*_t160 + _t161*_t18 + _t162*_t18 - _t55*_t72 + _t56*_t71;
  const double _t164 = my_piecewise3(_t13, 0, -_t157*_t57 + _t163*_t19);
  const double _t165 = _t45*_t78;
  const double _t166 = (0.25e2 / 0.2592e4)*_hc1[3]*_t111*_t37*_t59 - 0.5e1 / 0.324e3*_t165;
  const double _t167 = 0.2e1*_t56;
  const double _t169 = _hc0[3]*_t111;
  const double _t170 = _t168*_t169;
  const double _t171 = (0.1e1 / 0.864e3)*_t170*sigma_ss + (0.1e1 / 0.108e3)*_t80;
  const double _t172 = _hc3[0]*(_hc2[1]*_t166 + _t135*_t38 + _t167*_t77 + _t171 + _t63*_t72) - _t171;
  const double _t173 = my_piecewise3(_t13, 0, _hc4[0]*_t172 - _t30*_t65);
  const double _t174 = _hc4[5]/(M_PI * M_PI);
  const double _t176 = _t68*_t70;
  const double _t177 = _hc3[0]*_t91;
  const double _t178 = _hc2[3]*_t103;
  const double _t179 = _hc2[2]*_t102;
  const double _t180 = (0.10e2 / 0.27e2)*_hc1[2]*_t37*_t42*_t43*_t8 - 0.10e2 / 0.9e1*_t1*_t16;
  const double _t181 = _hc1[1]*_t32;
  const double _t182 = _t100*_t112;
  const double _t184 = _t46*_t8;
  const double _t185 = (0.40e2 / 0.27e2)*_t181 + _t182*_t183 + _t184*_t98 - 0.50e2 / 0.81e2*_t76;
  const double _t186 = _hc2[1]*_t185 + _t178*_t18 + _t179*_t18 + _t180*_t72;
  const double _t187 = my_piecewise3(_t13, 0, _t174*_t53*_t69 + (0.2e1 / 0.27e2)*_t175*_t176 - _t177*_t73 + _t186*_t19);
  const double _t188 = (0.2e1 / 0.9e1)*_t86;
  const double _t189 = (0.1e1 / 0.36e2)*_t25;
  const double _t192 = _hc0[1]*_t191;
  const double _t193 = _t169/xc_powi(n_s, 10);
  const double _t194 = (0.1e1 / 0.324e3)*_t104*_t193;
  const double _t195 = (0.1e1 / 0.24e2)*_t106*sigma_ss;
  const double _t196 = (0.2e1 / 0.9e1)*_hc1[1]*_t3*_t31*_t4 - 0.2e1 / 0.9e1*_t32 - 0.5e1 / 0.108e3*_t76;
  const double _t197 = _t1*_t182;
  const double _t198 = _t1*_t45;
  const double _t199 = _t198*_t98;
  const double _t200 = -_hc1[1]*_t191 + (0.10e2 / 0.81e2)*_hc1[2]*_t31*_t37*_t42*_t43 - 0.25e2 / 0.324e3*_t197 - 0.5e1 / 0.216e3*_t199 + (0.11e2 / 0.27e2)*_t3*_t4*_t92;
  const double _t201 = _hc3[0]*(_hc2[1]*_t200 + _t102*_t56 + _t178*_t24 - _t192 - _t194 - _t195 + _t196*_t72) + _t192 + _t194 + _t195;
  const double _t202 = my_piecewise3(_t13, 0, _hc4[0]*_t201 + _t188*_t25 + _t189*_t90 - _t82*_t91);
  const double _t204 = _hc4[9]*_t175*_t203;
  const double _t205 = _t28*_t41;
  const double _t206 = (0.14e2 / 0.27e2)*_t205;
  const double _t207 = _t31*_t89;
  const double _t208 = (0.1e1 / 0.9e1)*_t207;
  const double _t209 = _hc4[2]*_t12*_t27;
  const double _t215 = _t112*_t214;
  const double _t218 = _t37*_t46;
  const double _t220 = _t17*_t217 - _t213 + (0.50e2 / 0.81e2)*_t215 + _t218*_t219 + _t218*_t98;
  const double _t221 = (_t38 * _t38 * _t38);
  const double _t222 = (0.10e2 / 0.27e2)*_t101 + (0.22e2 / 0.27e2)*_t94 + (0.2e1 / 0.3e1)*_t99;
  const double _t224 = _t169/xc_powi(n_s, 11);
  const double _t225 = _t79/xc_powr(n_s, 25, 3);
  const double _t226 = _hc0[1]*_t213 + (0.11e2 / 0.81e2)*_t104*_t225 + (0.2e1 / 0.243e3)*_t223*_t224;
  const double _t227 = _hc3[0]*(_hc2[1]*_t220 + _hc2[3]*_t221 + _t102*_t72 + _t222*_t72 + _t226) - _t226;
  const double _t228 = my_piecewise3(_t13, 0, _hc4[0]*_t227 + (0.2e1 / 0.3e1)*_hc4[2]*_t10*_t3*_t39*_t85 + (0.1e1 / 0.12e2)*_hc4[5]*_t1*_t39*_t42*_t88 - _t108*_t209 - _t14*_t206 - _t14*_t208 - _t204*_t87);
#endif
#if _KMAX >= 4
  const double _t232 = _hc1[4]*_t231;
  const double _t233 = (0.250e3 / 0.729e3)*_t232;
  const double _t234 = _hc1[3]*_t114;
  const double _t235 = _t231*_t234;
  const double _t236 = _t19*_t229;
  const double _t237 = ((_hc1[2]) * (_hc1[2]))*_hc2[2];
  const double _t238 = _t231*_t237;
  const double _t240 = _hc2[1]*_t232;
  const double _t243 = _hc2[3]*_t48;
  const double _t244 = _hc1[2]*_t243;
  const double _t247 = _hc2[4]*_t64;
  const double _t250 = (0.1e1 / 0.55296e5)*_hc0[4]*_t249;
  const double _t252 = _t3*_t67;
  const double _t253 = _hc4[2]/(M_PI * M_PI * M_PI * M_PI * M_CBRTPI);
  const double _t254 = _hc3[0]*_t253*_t3*_t78;
  const double _t255 = _hc1[1]*_t151;
  const double _t256 = _hc2[4]*_t38;
  const double _t257 = _hc2[2]*_t8;
  const double _t258 = _t232*_t37;
  const double _t259 = _t111*_t255;
  const double _t260 = _t153*_t257;
  const double _t261 = _hc2[3]*_t51;
  const double _t262 = _t127*_t154;
  const double _t263 = _t17*_t257;
  const double _t264 = (0.25e2 / 0.2592e4)*_t112;
  const double _t265 = (0.5e1 / 0.576e3)*_t62;
  const double _t266 = _hc0[4]*_t231;
  const double _t267 = (0.1e1 / 0.288e3)*_t170 + (0.1e1 / 0.20736e5)*_t266*sigma_ss/xc_powr(n_s, 35, 3);
  const double _t268 = _t146*_t210;
  const double _t269 = _t149*_t48;
  const double _t270 = _hc4[5]/(M_PI * M_PI * M_PI * M_CBRTPI);
  const double _t271 = _t112*_t98;
  const double _t272 = _hc3[0]*_t57;
  const double _t273 = (0.1e1 / 0.36e2)*_t90;
  const double _t274 = _hc2[4]*_t24;
  const double _t275 = _t100*_t232;
  const double _t276 = _t102*_t18;
  const double _t277 = _t151*_t18;
  const double _t278 = (0.43e2 / 0.2592e4)*_t193*sigma_ss;
  const double _t279 = (0.19e2 / 0.324e3)*_t106;
  const double _t280 = (0.1e1 / 0.7776e4)*_t104*_t266/xc_powr(n_s, 38, 3);
  const double _t281 = _t158*_t183;
  const double _t283 = (0.25e2 / 0.324e3)*_t1*_t158;
  const double _t284 = _hc0[1]*_t282 + (0.19e2 / 0.324e3)*_t104*_t224 + (0.1e1 / 0.2916e4)*_t223*_t266/xc_powr(n_s, 41, 3) + (0.341e3 / 0.972e3)*_t225*sigma_ss;
  const double _t285 = (0.44e2 / 0.243e3)*_t169*_t223/xc_powi(n_s, 12);
  const double _t288 = _hc0[1]*_t287;
  const double _t289 = (0.2e1 / 0.2187e4)*_t266*(sigma_ss * sigma_ss * sigma_ss * sigma_ss)/xc_powr(n_s, 44, 3);
  const double _t290 = (0.979e3 / 0.729e3)*_t104*_t79/xc_powr(n_s, 28, 3);
  const double _t291 = (0.10e2 / 0.27e2)*_t75;
  const double _t292 = (0.50e2 / 0.81e2)*_t182;
#endif

  const double f = my_piecewise3(_t13, 0, _t15*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t13, 0, _t21*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = 0;
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t13, 0, _t26*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t13, 0, _t15 + _t40*n_s);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = my_piecewise3(_t13, 0, _t52*n_s);
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = 0;
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = my_piecewise3(_t13, 0, _t58*n_s);
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = 0;
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t13, 0, _t66*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t13, 0, _t21 + _t74*n_s);
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = 0;
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t13, 0, _t26 + _t83*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t13, 0, _t109*n_s + 0.2e1*_t40);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = my_piecewise3(_t13, 0, _t121*n_s);
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = 0;
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = my_piecewise3(_t13, 0, _t129*n_s);
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = 0;
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = my_piecewise3(_t13, 0, _t137*n_s);
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = 0;
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t13, 0, _t145*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = my_piecewise3(_t13, 0, _t156*n_s + _t52);
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = 0;
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = my_piecewise3(_t13, 0, _t164*n_s + _t58);
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = 0;
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t13, 0, _t173*n_s + _t66);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t13, 0, _t187*n_s + 0.2e1*_t74);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = 0;
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t13, 0, _t202*n_s + 0.2e1*_t83);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t13, 0, 0.3e1*_t109 + _t228*n_s);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = my_piecewise3(_t13, 0, n_s*my_piecewise3(_t13, 0, (0.2e1 / 0.27e2)*((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_hc2[4]*_t231*_t236 + (0.20e2 / 0.27e2)*_hc1[2]*_t120*_t229*_t231*_t48 + _t20*_t229*_t233 + (0.200e3 / 0.243e3)*_t235*_t236 + (0.50e2 / 0.81e2)*_t236*_t238));
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = 0;
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = 0;
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = 0;
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = 0;
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = my_piecewise3(_t13, 0, n_s*my_piecewise3(_t13, 0, _t19*((0.10e2 / 0.9e1)*_hc1[1]*_hc1[2]*_hc2[3]*_t110*_t111*_t24 + (0.50e2 / 0.81e2)*_hc1[3]*_hc2[2]*_t110*_t111*_t24 + (0.2e1 / 0.9e1)*_hc2[4]*_t110*_t111*_t117*_t24 - _t234*_t242 - _t237*_t242 - 0.125e3 / 0.2916e4*_t239*_t240 - 0.5e1 / 0.108e3*_t241*_t244)));
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = 0;
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = my_piecewise3(_t13, 0, n_s*my_piecewise3(_t13, 0, _t19*(-0.5e1 / 0.27e2*_hc1[1]*_t111*_t125*_t127 - 0.25e2 / 0.162e3*_t123*_t56 + _t135*_t47 + (0.25e2 / 0.3888e4)*_t234*_t246 + (0.25e2 / 0.2592e4)*_t238*_t245 + (0.125e3 / 0.23328e5)*_t240*_t245 + (0.5e1 / 0.2592e4)*_t244*_t246 + _t247*_t51)));
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = 0;
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = my_piecewise3(_t13, 0, n_s*my_piecewise3(_t13, 0, _t19*((0.5e1 / 0.288e3)*_hc1[1]*_hc1[2]*_hc2[3]*_t111*_t130*_t24 + (0.1e1 / 0.3e1)*_hc1[1]*_hc2[4]*_t143*_t3*_t4*_t8 + (0.25e2 / 0.864e3)*_hc1[3]*_hc2[2]*_t111*_t130*_t24 - 0.5e1 / 0.72e2*_t135*_t54 - 0.25e2 / 0.62208e5*_t235*_t248 - 0.25e2 / 0.20736e5*_t238*_t248 - 0.125e3 / 0.186624e6*_t240*_t248)));
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = 0;
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t13, 0, n_s*my_piecewise3(_t13, 0, _hc4[0]*(_hc3[0]*((0.125e3 / 0.1492992e7)*_hc1[4]*_hc2[1]*_t249 + _hc2[4]*(_t24 * _t24 * _t24 * _t24) + (0.5e1 / 0.288e3)*_t135*_t62 - 0.25e2 / 0.5184e4*_t141*_t56 + (0.25e2 / 0.165888e6)*_t237*_t249 - _t250) + _t250)));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = my_piecewise3(_t13, 0, _t121 + n_s*my_piecewise3(_t13, 0, -_hc1[3]*_t251*_t252*_t253 - 0.1e1 / 0.27e2*_hc2[3]*_t117*_t254 + _hc3[0]*_hc4[0]*(_hc2[1]*((0.250e3 / 0.729e3)*_hc1[4]*_t110*_t230*_t3*_t37 - 0.250e3 / 0.81e2*_t123) + _t113*_t72 + _t116*_t118*_t255 + _t119*_t256 + _t150*_t16*_t257 + (0.5e1 / 0.9e1)*_t152*_t41*_t45 + (0.1e1 / 0.3e1)*_t243*_t50*_t71) - _t114*_t148*_t254));
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = 0;
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = my_piecewise3(_t13, 0, _t129 + n_s*my_piecewise3(_t13, 0, -_t128*_t157 + _t19*(_hc2[1]*(-0.125e3 / 0.2916e4*_t122*_t258 + (0.25e2 / 0.54e2)*_t131) - _t124*_t72 - _t126*_t259 - _t134*_t152 + _t150*_t56 + _t160*_t260 + _t161*_t47 + _t162*_t47 + _t24*_t256*_t51 + _t261*_t77 + _t262*_t71)));
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = 0;
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = my_piecewise3(_t13, 0, _t137 + n_s*my_piecewise3(_t13, 0, -_t136*_t157 + _t19*(_hc2[1]*((0.125e3 / 0.23328e5)*_hc1[4]*_t130*_t230*_t3*_t37 - 0.175e3 / 0.2592e4*_t141) + _t132*_t72 + _t133*_t259 - _t134*_t161 - _t134*_t162 + _t135*_t71 + _t152*_t63 + _t160*_t167 + _t166*_t263 + _t18*_t256*_t64 + _t262*_t77)));
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = 0;
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t13, 0, _t145 + n_s*my_piecewise3(_t13, 0, _hc4[0]*(_hc3[0]*(_hc2[1]*(-0.125e3 / 0.186624e6*_t138*_t258 + _t168*_t264) + 0.3e1*_t135*_t77 - _t142*_t72 + _t143*_t256 + _t161*_t265 + _t162*_t265 + 0.3e1*_t166*_t56 + _t267) - _t267) - _t144*_t30));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = my_piecewise3(_t13, 0, 0.2e1*_t156 + n_s*my_piecewise3(_t13, 0, (0.20e2 / 0.81e2)*_hc1[2]*_t268*_t67 + (0.1e1 / 0.54e2)*_t122*_t269*_t270*_t3 + (0.5e1 / 0.162e3)*_t125*_t252*_t270 - _t155*_t177 + _t19*(_hc2[1]*(_t100*_t233*_t41 - 0.1000e4 / 0.243e3*_t159 + (0.50e2 / 0.81e2)*_t271*_t41 + (0.650e3 / 0.243e3)*_t62) + _hc2[4]*_t103*_t51 + _t102*_t261 + _t151*_t154*_t180 + _t152*_t180 + _t178*_t47 + _t179*_t47 + _t185*_t260 + _t72*((0.100e3 / 0.81e2)*_hc1[3]*_t111*_t37*_t41 - 0.100e3 / 0.81e2*_t54)) + (0.4e1 / 0.27e2)*_t268*_t269));
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = 0;
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = my_piecewise3(_t13, 0, 0.2e1*_t164 + n_s*my_piecewise3(_t13, 0, -_t163*_t177 + _t188*_t272 + _t19*(_hc2[1]*((0.325e3 / 0.486e3)*_hc1[3]*_t111*_t37*_t59 - 0.130e3 / 0.243e3*_t165 - 0.25e2 / 0.324e3*_t271*_t53 - 0.125e3 / 0.2916e4*_t275*_t53) + _t103*_t18*_t274 + _t127*_t276 + _t152*_t196 + _t162*_t180 - _t178*_t55 - _t179*_t55 + _t185*_t56 + _t196*_t277 + _t200*_t263 + _t72*(-0.25e2 / 0.162e3*_t159 + (0.65e2 / 0.324e3)*_t62)) + _t272*_t273));
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = 0;
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t13, 0, 0.2e1*_t173 + n_s*my_piecewise3(_t13, 0, _hc4[0]*(_hc3[0]*(_hc2[1]*((0.95e2 / 0.972e3)*_t105*_t45 - _t158*_t251 + _t264*_t59*_t98 + (0.125e3 / 0.23328e5)*_t275*_t59) + _t102*_t135 + _t103*_t247 + _t161*_t196 + 0.2e1*_t162*_t196 + _t167*_t200 + _t178*_t63 + _t179*_t63 - _t278 - _t279 - _t280 + _t72*((0.25e2 / 0.1296e4)*_hc1[3]*_t111*_t37*_t59 - 0.5e1 / 0.162e3*_t165)) + _t278 + _t279 + _t280) - _t172*_t91 + _t188*_t65 + _t273*_t65));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t13, 0, 0.3e1*_t187 + n_s*my_piecewise3(_t13, 0, _hc3[0]*_hc4[0]*(_hc2[1]*(-0.440e3 / 0.81e2*_hc1[1]*_t190 + _t184*_t217 - 0.250e3 / 0.81e2*_t197 - 0.25e2 / 0.81e2*_t198*_t219 - 0.25e2 / 0.81e2*_t199 + _t214*_t233*_t8 + _t219*_t281 + _t281*_t98 + (0.200e3 / 0.81e2)*_t31*_t75) + _hc2[4]*_t18*_t221 + _t102*_t152 + _t151*_t276 + _t152*_t222 + _t178*((0.5e1 / 0.9e1)*_hc1[2]*_t37*_t42*_t43*_t8 - _t16*_t36) + _t185*_t72 + _t220*_t263 + _t222*_t277 + _t72*((0.80e2 / 0.27e2)*_t181 + (0.100e3 / 0.81e2)*_t182*_t8 + (0.10e2 / 0.27e2)*_t45*_t8*_t98 - 0.100e3 / 0.81e2*_t76)) + (0.2e1 / 0.3e1)*_hc3[0]*_hc4[2]*_t10*_t3*_t73*_t85 + (0.1e1 / 0.12e2)*_hc3[0]*_hc4[5]*_t1*_t42*_t73*_t88 - _hc3[0]*_t186*_t209 - 0.1e1 / 0.108e3*_hc4[9]*_t210*_t3*_t68/(M_PI * M_PI * M_CBRTPI) - 0.14e2 / 0.81e2*_t110*_t176 - 0.2e1 / 0.9e1*_t174*_t59*_t68));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = 0;
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t13, 0, 0.3e1*_t202 + n_s*my_piecewise3(_t13, 0, _hc4[0]*(_hc3[0]*(_hc2[1]*((0.154e3 / 0.81e2)*_hc1[1]*_t210*_t3*_t4 + (0.5e1 / 0.81e2)*_hc1[2]*_t219*_t31*_t42*_t43 + (0.5e1 / 0.81e2)*_hc1[2]*_t31*_t42*_t43*_t98 + (0.50e2 / 0.81e2)*_hc1[3]*_t100*_t111*_t31 - 0.125e3 / 0.2916e4*_t1*_t214*_t232 - 0.5e1 / 0.216e3*_t198*_t217 - _t219*_t283 - _t282 - _t283*_t98 - 0.55e2 / 0.81e2*_t75*_t92) + _t102*_t161 + _t102*_t162 + _t161*_t222 + _t162*_t222 + _t178*((0.1e1 / 0.3e1)*_hc1[1]*_t3*_t31*_t4 - 0.1e1 / 0.3e1*_t31*_t5 - 0.5e1 / 0.72e2*_t76) + _t200*_t72 + _t220*_t56 + _t221*_t274 + _t284 + _t72*(-0.22e2 / 0.27e2*_hc1[1]*_t190 + (0.20e2 / 0.81e2)*_hc1[2]*_t31*_t37*_t42*_t43 - 0.25e2 / 0.162e3*_t197 - 0.5e1 / 0.108e3*_t199 + (0.22e2 / 0.27e2)*_t3*_t4*_t92)) - _t284) + (0.2e1 / 0.3e1)*_hc4[2]*_t10*_t3*_t82*_t85 + (0.1e1 / 0.12e2)*_hc4[5]*_t1*_t42*_t82*_t88 - _t189*_t204 - _t201*_t209 - _t206*_t25 - _t208*_t25));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t13, 0, 0.4e1*_t228 + n_s*my_piecewise3(_t13, 0, _hc4[0]*(_hc3[0]*(_hc2[1]*(_t17*((0.6160e4 / 0.81e2)*_t210*tau_s - 0.2618e4 / 0.81e2*_t286) + _t217*_t291 + _t218*((0.308e3 / 0.27e2)*_t210*sigma_ss - 0.880e3 / 0.27e2*_t216) + _t219*_t292 + _t219*_t46*_t98 + _t233*(_t37 * _t37 * _t37 * _t37) + _t287 + _t292*_t98 + _t292*(-0.11e2 / 0.3e1*_t93 + (0.40e2 / 0.3e1)*_t97) + _t46*(_t98 * _t98)) + _hc2[2]*(_t102 * _t102) + _hc2[4]*(_t38 * _t38 * _t38 * _t38) + _t102*_t178 + _t178*_t222 + _t178*((0.5e1 / 0.9e1)*_t101 + _t5*_t96 + _t99) + _t179*_t222 + 0.2e1*_t220*_t72 - _t285 - _t288 - _t289 - _t290 + _t72*(_t153*_t217 - 0.308e3 / 0.81e2*_t211*_t5 + (0.100e3 / 0.81e2)*_t215 + _t219*_t291 + _t291*_t98)) + _t285 + _t288 + _t289 + _t290) + (0.1e1 / 0.216e3)*_hc4[14]*_t14*_t5*_t59 + _hc4[9]*_t110*_t203*_t84 + (0.4e1 / 0.3e1)*_t108*_t86 + (0.1e1 / 0.6e1)*_t108*_t90 + (0.140e3 / 0.81e2)*_t14*_t28*_t53 + (0.40e2 / 0.81e2)*_t14*_t89*_t92 - 0.1e1 / 0.9e1*_t204*_t39 - 0.56e2 / 0.27e2*_t205*_t39 - 0.4e1 / 0.9e1*_t207*_t39 - 0.2e1 / 0.3e1*_t227*_t29));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_eel_params *params = (const mgga_x_eel_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double ta = tau[0];

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, (0.1e1 / 0.2e1)*na, (0.1e1 / 0.4e1)*gaa, 0, (0.1e1 / 0.2e1)*ta, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc0[3];
  const double dF_dta = _hc0[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc0[14];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[13];
  const double d2F_dna_dta = (0.1e1 / 0.2e1)*_hc0[11];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc0[10];
  const double d2F_dgaa_dta = (0.1e1 / 0.4e1)*_hc0[8];
  const double d2F_dta2 = (0.1e1 / 0.2e1)*_hc0[5];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc0[34];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc0[33];
  const double d3F_dna2_dta = (0.1e1 / 0.4e1)*_hc0[31];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[30];
  const double d3F_dna_dgaa_dta = (0.1e1 / 0.8e1)*_hc0[28];
  const double d3F_dna_dta2 = (0.1e1 / 0.4e1)*_hc0[25];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc0[24];
  const double d3F_dgaa2_dta = (0.1e1 / 0.16e2)*_hc0[22];
  const double d3F_dgaa_dta2 = (0.1e1 / 0.8e1)*_hc0[19];
  const double d3F_dta3 = (0.1e1 / 0.4e1)*_hc0[15];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += d3F_dna_dgaa_dta;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 0] += d3F_dgaa2_dta;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 0] += d3F_dgaa_dta2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc0[69];
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc0[68];
  const double d4F_dna3_dta = (0.1e1 / 0.8e1)*_hc0[66];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc0[65];
  const double d4F_dna2_dgaa_dta = (0.1e1 / 0.16e2)*_hc0[63];
  const double d4F_dna2_dta2 = (0.1e1 / 0.8e1)*_hc0[60];
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[59];
  const double d4F_dna_dgaa2_dta = (0.1e1 / 0.32e2)*_hc0[57];
  const double d4F_dna_dgaa_dta2 = (0.1e1 / 0.16e2)*_hc0[54];
  const double d4F_dna_dta3 = (0.1e1 / 0.8e1)*_hc0[50];
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc0[49];
  const double d4F_dgaa3_dta = (0.1e1 / 0.64e2)*_hc0[47];
  const double d4F_dgaa2_dta2 = (0.1e1 / 0.32e2)*_hc0[44];
  const double d4F_dgaa_dta3 = (0.1e1 / 0.16e2)*_hc0[40];
  const double d4F_dta4 = (0.1e1 / 0.8e1)*_hc0[35];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += d4F_dna2_dgaa_dta;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += d4F_dna_dgaa2_dta;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += d4F_dna_dgaa_dta2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 0] += d4F_dgaa3_dta;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 0] += d4F_dgaa2_dta2;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 0] += d4F_dgaa_dta3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gbb = sigma[2];
  const double ta = tau[0];
  const double tb = tau[1];

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, 0, ta, _hc0);
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, 0, tb, _hc1);
  const double zk = (_hc0[0] + _hc1[0])/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dnb = _hc1[4];
  const double dF_dgaa = _hc0[3];
  const double dF_dgbb = _hc1[3];
  const double dF_dta = _hc0[1];
  const double dF_dtb = _hc1[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 1] += dF_dtb;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = _hc0[14];
  const double d2F_dnb2 = _hc1[14];
  const double d2F_dna_dgaa = _hc0[13];
  const double d2F_dnb_dgbb = _hc1[13];
  const double d2F_dna_dta = _hc0[11];
  const double d2F_dnb_dtb = _hc1[11];
  const double d2F_dgaa2 = _hc0[10];
  const double d2F_dgbb2 = _hc1[10];
  const double d2F_dgaa_dta = _hc0[8];
  const double d2F_dgbb_dtb = _hc1[8];
  const double d2F_dta2 = _hc0[5];
  const double d2F_dtb2 = _hc1[5];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 3] += d2F_dnb_dtb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 5] += d2F_dgbb_dtb;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 2] += d2F_dtb2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = _hc0[34];
  const double d3F_dnb3 = _hc1[34];
  const double d3F_dna2_dgaa = _hc0[33];
  const double d3F_dnb2_dgbb = _hc1[33];
  const double d3F_dna2_dta = _hc0[31];
  const double d3F_dnb2_dtb = _hc1[31];
  const double d3F_dna_dgaa2 = _hc0[30];
  const double d3F_dnb_dgbb2 = _hc1[30];
  const double d3F_dna_dgaa_dta = _hc0[28];
  const double d3F_dnb_dgbb_dtb = _hc1[28];
  const double d3F_dna_dta2 = _hc0[25];
  const double d3F_dnb_dtb2 = _hc1[25];
  const double d3F_dgaa3 = _hc0[24];
  const double d3F_dgbb3 = _hc1[24];
  const double d3F_dgaa2_dta = _hc0[22];
  const double d3F_dgbb2_dtb = _hc1[22];
  const double d3F_dgaa_dta2 = _hc0[19];
  const double d3F_dgbb_dtb2 = _hc1[19];
  const double d3F_dta3 = _hc0[15];
  const double d3F_dtb3 = _hc1[15];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 5] += d3F_dnb2_dtb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += d3F_dna_dgaa_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 11] += d3F_dnb_dgbb_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 5] += d3F_dnb_dtb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 0] += d3F_dgaa2_dta;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 11] += d3F_dgbb2_dtb;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 0] += d3F_dgaa_dta2;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 8] += d3F_dgbb_dtb2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 3] += d3F_dtb3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = _hc0[69];
  const double d4F_dnb4 = _hc1[69];
  const double d4F_dna3_dgaa = _hc0[68];
  const double d4F_dnb3_dgbb = _hc1[68];
  const double d4F_dna3_dta = _hc0[66];
  const double d4F_dnb3_dtb = _hc1[66];
  const double d4F_dna2_dgaa2 = _hc0[65];
  const double d4F_dnb2_dgbb2 = _hc1[65];
  const double d4F_dna2_dgaa_dta = _hc0[63];
  const double d4F_dnb2_dgbb_dtb = _hc1[63];
  const double d4F_dna2_dta2 = _hc0[60];
  const double d4F_dnb2_dtb2 = _hc1[60];
  const double d4F_dna_dgaa3 = _hc0[59];
  const double d4F_dnb_dgbb3 = _hc1[59];
  const double d4F_dna_dgaa2_dta = _hc0[57];
  const double d4F_dnb_dgbb2_dtb = _hc1[57];
  const double d4F_dna_dgaa_dta2 = _hc0[54];
  const double d4F_dnb_dgbb_dtb2 = _hc1[54];
  const double d4F_dna_dta3 = _hc0[50];
  const double d4F_dnb_dtb3 = _hc1[50];
  const double d4F_dgaa4 = _hc0[49];
  const double d4F_dgbb4 = _hc1[49];
  const double d4F_dgaa3_dta = _hc0[47];
  const double d4F_dgbb3_dtb = _hc1[47];
  const double d4F_dgaa2_dta2 = _hc0[44];
  const double d4F_dgbb2_dtb2 = _hc1[44];
  const double d4F_dgaa_dta3 = _hc0[40];
  const double d4F_dgbb_dtb3 = _hc1[40];
  const double d4F_dta4 = _hc0[35];
  const double d4F_dtb4 = _hc1[35];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 7] += d4F_dnb3_dtb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += d4F_dna2_dgaa_dta;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 17] += d4F_dnb2_dgbb_dtb;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 8] += d4F_dnb2_dtb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += d4F_dna_dgaa2_dta;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 23] += d4F_dnb_dgbb2_dtb;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += d4F_dna_dgaa_dta2;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 17] += d4F_dnb_dgbb_dtb2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 7] += d4F_dnb_dtb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 0] += d4F_dgaa3_dta;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 19] += d4F_dgbb3_dtb;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 0] += d4F_dgaa2_dta2;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 17] += d4F_dgbb2_dtb2;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 0] += d4F_dgaa_dta3;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 11] += d4F_dgbb_dtb3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 4] += d4F_dtb4;
#endif
#endif
}
#endif