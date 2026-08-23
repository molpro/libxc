/*
  Generated from python/mgga_exc/mgga_x_task.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_task
*/

#ifndef _MGGA_X_TASK_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_TASK_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_TASK_HELPER_BODIES
#include "mgga_x_task.c"
#undef _MGGA_X_TASK_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_TASK_HELPER_BODIES
#include "mgga_x_task.c"
#undef _MGGA_X_TASK_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_TASK_HELPER_BODIES
#include "mgga_x_task.c"
#undef _MGGA_X_TASK_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_TASK_HELPER_BODIES
#include "mgga_x_task.c"
#undef _MGGA_X_TASK_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_TASK_HELPER_BODIES
#include "mgga_x_task.c"
#undef _MGGA_X_TASK_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_task.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_task.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_task.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_task.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_task.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_task.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_task.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_task.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_task.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_task.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_TASK_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(m_one_minus_recexp_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = -0.1e1/log(XC_EPSILON);
  const double _t2 = x <= _t1;
  const double _t3 = _t1 > x;
  const double _t4 = my_piecewise3(_t3, _t1, x);
  const double _t5 = xc_expm1(-0.1e1/_t4);
#if _KMAX >= 1
  const double _t6 = my_piecewise3(_t3, 0, 0.1e1);
  const double _t7 = _t5 + 0.1e1;
#endif
#if _KMAX >= 2
  const double _t8 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t9 = (_t6 * _t6)*_t7;
#endif
#if _KMAX >= 3
  const double _t10 = xc_powi(_t4, -6);
  const double _t11 = (_t6 * _t6 * _t6);
  const double _t12 = _t11*_t7;
  const double _t13 = xc_powi(_t4, -5);
#endif
#if _KMAX >= 4
  const double _t14 = (_t6 * _t6 * _t6 * _t6)*_t7;
#endif

  const double f = my_piecewise3(_t2, 0.1e1, -_t5);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = my_piecewise3(_t2, 0, -_t6*_t7/(_t4 * _t4));
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = my_piecewise3(_t2, 0, -_t8*_t9 + 0.2e1*_t9/(_t4 * _t4 * _t4));
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = my_piecewise3(_t2, 0, -_t10*_t12 + 0.6e1*_t11*_t13*_t7 - 0.6e1*_t12*_t8);
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = my_piecewise3(_t2, 0, -0.36e2*_t10*_t14 + 0.24e2*_t13*_t14 + 0.12e2*_t14/xc_powi(_t4, 7) - _t14/xc_powi(_t4, 8));
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(task_gx_k, _KMAX)(const xc_func_type *p, double x, double *out) {
  const mgga_x_task_params *params = (const mgga_x_task_params *)(p->params);

  const double _t1 = (0.1e1 / (params->task_c));
#if _KMAX >= 2
  const double _t3 = (0.1e1 / ((params->task_c) * (params->task_c)));
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(m_one_minus_recexp_k, _KMAX)(p, _t1*xc_powr(x, 1, 4), _hc0);
#if _KMAX >= 1
  const double _t2 = _hc0[1]*_t1;
#endif
#if _KMAX >= 3
  const double _t4 = _hc0[3]/((params->task_c) * (params->task_c) * (params->task_c));
#endif

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = (0.1e1 / 0.4e1)*_t2/xc_powr(x, 3, 4);
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = (0.1e1 / 0.16e2)*_hc0[2]*_t3/xc_powr(x, 3, 2) - 0.3e1 / 0.16e2*_t2/xc_powr(x, 7, 4);
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = -0.9e1 / 0.64e2*_hc0[2]*_t3/xc_powr(x, 5, 2) + (0.21e2 / 0.64e2)*_t2/xc_powr(x, 11, 4) + (0.1e1 / 0.64e2)*_t4/xc_powr(x, 9, 4);
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = (0.111e3 / 0.256e3)*_hc0[2]*_t3/xc_powr(x, 7, 2) + (0.1e1 / 0.256e3)*_hc0[4]/(((params->task_c) * (params->task_c) * (params->task_c) * (params->task_c))*(x * x * x)) - 0.231e3 / 0.256e3*_t2/xc_powr(x, 15, 4) - 0.9e1 / 0.128e3*_t4/xc_powr(x, 13, 4);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(task_hx1_k, _KMAX)(const xc_func_type *p, double r, double *out) {
  const mgga_x_task_params *params = (const mgga_x_task_params *)(p->params);

  const double _t1 = r + 0.1e1;
  const double _t2 = params->task_anu[1]/_t1;
  const double _t3 = 0.2e1*r;
  const double _t4 = (r * r);
  const double _t5 = _t3 + _t4 + 0.1e1;
  const double _t6 = params->task_anu[2]/_t5;
  const double _t7 = 0.2e1*_t6;
  const double _t8 = 0.4e1*r;
  const double _t9 = _t6*_t8;
#if _KMAX >= 1
  const double _t10 = params->task_anu[1]/(_t1 * _t1);
  const double _t11 = 0.4e1*_t6;
  const double _t12 = -_t3 - 0.2e1;
  const double _t13 = params->task_anu[2]/(_t5 * _t5);
  const double _t14 = _t12*_t13;
  const double _t15 = 0.2e1*_t14;
#endif
#if _KMAX >= 2
  const double _t16 = params->task_anu[1]/(_t1 * _t1 * _t1);
  const double _t17 = 0.4e1*_t13;
  const double _t18 = 0.8e1*r;
  const double _t19 = (0.1e1 / (_t5 * _t5 * _t5));
  const double _t20 = _t19*params->task_anu[2];
  const double _t21 = -_t8 - 0.4e1;
  const double _t22 = _t12*_t21;
  const double _t23 = _t20*_t22;
  const double _t24 = 0.2e1*_t23;
#endif
#if _KMAX >= 3
  const double _t25 = params->task_anu[1]/(_t1 * _t1 * _t1 * _t1);
  const double _t26 = 0.6e1*r;
  const double _t27 = 0.24e2*_t13;
  const double _t28 = 0.8e1*_t20;
  const double _t29 = _t21*_t28;
  const double _t30 = _t12*_t28;
  const double _t31 = _t20*r;
  const double _t32 = 0.16e2*_t31;
  const double _t33 = 0.12e2*_t22;
  const double _t34 = -_t26 - 0.6e1;
  const double _t35 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t36 = _t35*params->task_anu[2];
  const double _t37 = _t34*_t36;
  const double _t38 = _t22*_t37;
  const double _t39 = 0.2e1*_t38;
#endif
#if _KMAX >= 4
  const double _t40 = xc_powi(_t1, -5);
  const double _t41 = 0.64e2*_t31;
  const double _t42 = 0.12e2*_t21*_t37;
  const double _t43 = 0.16e2*_t37;
  const double _t44 = _t12*_t43;
  const double _t45 = _t33*_t36;
  const double _t46 = -_t18 - 0.8e1;
  const double _t47 = xc_powi(_t5, -5);
#endif

  const double f = _t2*r - _t2 + _t4*_t7 + _t7 - _t9 + params->task_anu[0] - params->task_anu[2];
  out[0] = f;
#if _KMAX >= 1
  const double df_dr = -_t10*r + _t10 - _t11 - _t14*_t8 + _t15*_t4 + _t15 + _t2 + _t9;
  out[1] = df_dr;
#endif
#if _KMAX >= 2
  const double d2f_dr2 = -0.2e1*_t10 + _t11 + _t13*_t18 + _t14*_t18 - 0.8e1*_t14 + _t16*_t3 - 0.2e1*_t16 - _t17*_t4 - _t17 - _t23*_t8 + _t24*_t4 + _t24;
  out[2] = d2f_dr2;
#endif
#if _KMAX >= 3
  const double d3f_dr3 = _t12*_t32 + 0.12e2*_t14 + 0.6e1*_t16 + _t21*_t32 - 0.12e2*_t23 - _t25*_t26 + 0.6e1*_t25 - _t27*r + _t27 - _t29*_t4 - _t29 - _t30*_t4 - _t30 + _t31*_t33 - _t38*_t8 + _t39*_t4 + _t39;
  out[3] = d3f_dr3;
#endif
#if _KMAX >= 4
  const double d4f_dr4 = 0.24e2*_t12*_t19*_t21*params->task_anu[2] + 0.64e2*_t12*_t19*params->task_anu[2] + 0.16e2*_t12*_t21*_t34*_t35*params->task_anu[2]*r + 0.2e1*_t12*_t21*_t34*_t4*_t46*_t47*params->task_anu[2] + 0.2e1*_t12*_t21*_t34*_t46*_t47*params->task_anu[2] + 0.24e2*_t12*_t21*_t35*params->task_anu[2]*r + 0.32e2*_t12*_t34*_t35*params->task_anu[2]*r - _t12*_t41 - 0.48e2*_t13 + 0.64e2*_t19*_t21*params->task_anu[2] + 0.48e2*_t19*_t4*params->task_anu[2] + 0.48e2*_t19*params->task_anu[2] + 0.24e2*_t21*_t34*_t35*params->task_anu[2]*r - _t21*_t41 - _t22*_t34*_t46*_t47*_t8*params->task_anu[2] - _t22*_t43 - 0.24e2*_t25 - 0.96e2*_t31 - _t4*_t42 - _t4*_t44 - _t4*_t45 + 0.24e2*_t40*params->task_anu[1]*r - 0.24e2*_t40*params->task_anu[1] - _t42 - _t44 - _t45;
  out[4] = d4f_dr4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(task_fx_k, _KMAX)(const xc_func_type *p, double r, double *out) {
  const mgga_x_task_params *params = (const mgga_x_task_params *)(p->params);

  const double _t1 = r + 0.1e1;
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = _t2*params->task_bnu[1];
  const double _t4 = 0.3e1*params->task_bnu[3];
  const double _t5 = _t2*_t4;
  const double _t6 = 0.3e1*r;
  const double _t7 = _t6*params->task_bnu[3];
  const double _t8 = 0.2e1*r;
  const double _t9 = (r * r);
  const double _t10 = _t8 + _t9 + 0.1e1;
  const double _t11 = (0.1e1 / _t10);
  const double _t12 = _t11*params->task_bnu[2];
  const double _t13 = 0.2e1*_t12;
  const double _t14 = 0.8e1*params->task_bnu[4];
  const double _t15 = _t11*_t14;
  const double _t16 = 0.4e1*r;
  const double _t17 = _t12*_t16;
  const double _t18 = 0.16e2*params->task_bnu[4];
  const double _t19 = _t11*_t18;
  const double _t20 = _t19*r;
  const double _t21 = (r * r * r);
  const double _t22 = 0.3e1*_t9;
  const double _t23 = _t21 + _t22 + _t6 + 0.1e1;
  const double _t24 = params->task_bnu[3]/_t23;
  const double _t25 = 0.12e2*r;
  const double _t26 = 0.12e2*_t9;
  const double _t27 = _t24*_t26;
  const double _t28 = 0.4e1*_t21;
  const double _t29 = (r * r * r * r);
  const double _t30 = 0.6e1*_t9;
  const double _t31 = _t16 + _t28 + _t29 + _t30 + 0.1e1;
  const double _t32 = (0.1e1 / _t31);
  const double _t33 = _t14*_t32;
  const double _t34 = _t32*params->task_bnu[4];
  const double _t35 = 0.32e2*_t34;
  const double _t36 = 0.48e2*_t9;
  const double _t37 = _t21*_t35;
#if _KMAX >= 1
  const double _t38 = (0.1e1 / (_t1 * _t1));
  const double _t39 = _t38*params->task_bnu[1];
  const double _t40 = 0.4e1*_t12;
  const double _t41 = -_t8 - 0.2e1;
  const double _t42 = (0.1e1 / (_t10 * _t10));
  const double _t43 = _t42*params->task_bnu[2];
  const double _t44 = _t41*_t43;
  const double _t45 = 0.2e1*_t44;
  const double _t46 = _t14*_t41;
  const double _t47 = _t42*_t46;
  const double _t48 = 0.24e2*r;
  const double _t49 = _t24*_t48;
  const double _t50 = _t18*_t42;
  const double _t51 = _t41*r;
  const double _t52 = 0.96e2*_t34;
  const double _t53 = _t52*_t9;
  const double _t54 = 0.6e1*r;
  const double _t55 = -_t22 - _t54 - 0.3e1;
  const double _t56 = params->task_bnu[3]/(_t23 * _t23);
  const double _t57 = 0.4e1*_t56;
  const double _t58 = _t55*_t56;
  const double _t59 = (0.1e1 / (_t31 * _t31));
  const double _t60 = -_t25 - _t26 - _t28 - 0.4e1;
  const double _t61 = _t59*_t60;
  const double _t62 = _t14*_t61;
  const double _t63 = _t61*params->task_bnu[4];
  const double _t64 = 0.32e2*_t63;
#endif
#if _KMAX >= 2
  const double _t65 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t66 = _t65*params->task_bnu[1];
  const double _t67 = 0.6e1*params->task_bnu[3];
  const double _t68 = 0.4e1*_t43;
  const double _t69 = 0.8e1*r;
  const double _t70 = _t42*params->task_bnu[4];
  const double _t71 = 0.32e2*_t70;
  const double _t72 = _t71*r;
  const double _t73 = 0.24e2*_t24;
  const double _t74 = -_t54 - 0.6e1;
  const double _t75 = (0.1e1 / (_t10 * _t10 * _t10));
  const double _t76 = _t75*params->task_bnu[2];
  const double _t77 = -_t16 - 0.4e1;
  const double _t78 = _t41*_t77;
  const double _t79 = _t76*_t78;
  const double _t80 = 0.2e1*_t79;
  const double _t81 = _t75*_t77;
  const double _t82 = _t46*_t81;
  const double _t83 = 0.192e3*_t34;
  const double _t84 = _t83*r;
  const double _t85 = _t56*_t74;
  const double _t86 = _t18*_t51;
  const double _t87 = 0.24e2*_t56;
  const double _t88 = 0.48e2*r;
  const double _t89 = 0.24e2*_t9;
  const double _t90 = -_t26 - _t48 - 0.12e2;
  const double _t91 = _t59*_t90;
  const double _t92 = _t14*_t91;
  const double _t93 = _t91*params->task_bnu[4];
  const double _t94 = 0.32e2*_t93;
  const double _t95 = 0.64e2*_t63;
  const double _t96 = -_t25 - _t30 - 0.6e1;
  const double _t97 = (0.1e1 / (_t23 * _t23 * _t23));
  const double _t98 = _t97*params->task_bnu[3];
  const double _t99 = _t55*_t98;
  const double _t100 = 0.4e1*_t99;
  const double _t101 = 0.192e3*params->task_bnu[4];
  const double _t102 = _t101*_t59;
  const double _t103 = _t102*_t60;
  const double _t104 = _t96*_t99;
  const double _t105 = (0.1e1 / (_t31 * _t31 * _t31));
  const double _t106 = 0.8e1*_t21;
  const double _t107 = -_t106 - _t48 - _t89 - 0.8e1;
  const double _t108 = _t105*_t107;
  const double _t109 = _t108*_t60;
  const double _t110 = _t109*_t14;
  const double _t111 = _t109*params->task_bnu[4];
  const double _t112 = 0.32e2*_t111;
#endif
#if _KMAX >= 3
  const double _t113 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t114 = _t113*params->task_bnu[1];
  const double _t115 = 0.18e2*params->task_bnu[3];
  const double _t116 = 0.18e2*r;
  const double _t117 = 0.96e2*_t70;
  const double _t118 = 0.8e1*_t76;
  const double _t119 = _t118*_t77;
  const double _t120 = _t118*_t41;
  const double _t121 = _t75*params->task_bnu[4];
  const double _t122 = 0.32e2*_t121;
  const double _t123 = _t122*_t77;
  const double _t124 = _t122*_t41;
  const double _t125 = 0.48e2*_t41;
  const double _t126 = 0.72e2*r;
  const double _t127 = _t126*_t56;
  const double _t128 = _t76*r;
  const double _t129 = 0.16e2*_t128;
  const double _t130 = _t121*r;
  const double _t131 = 0.64e2*_t130;
  const double _t132 = 0.72e2*_t56;
  const double _t133 = _t125*_t77;
  const double _t134 = _t121*_t78;
  const double _t135 = 0.36e2*_t9;
  const double _t136 = -_t48 - 0.24e2;
  const double _t137 = _t136*_t59;
  const double _t138 = _t137*_t14;
  const double _t139 = (0.1e1 / (_t10 * _t10 * _t10 * _t10));
  const double _t140 = _t139*params->task_bnu[2];
  const double _t141 = _t140*_t74;
  const double _t142 = _t141*_t78;
  const double _t143 = 0.2e1*_t142;
  const double _t144 = _t74*_t77;
  const double _t145 = _t139*_t144;
  const double _t146 = _t145*_t46;
  const double _t147 = _t137*params->task_bnu[4];
  const double _t148 = 0.32e2*_t147;
  const double _t149 = 0.96e2*_t93;
  const double _t150 = -_t25 - 0.12e2;
  const double _t151 = _t96*_t98;
  const double _t152 = _t151*_t74;
  const double _t153 = 0.288e3*_t93;
  const double _t154 = _t150*_t99;
  const double _t155 = 0.288e3*_t63;
  const double _t156 = 0.576e3*r;
  const double _t157 = _t126*params->task_bnu[3];
  const double _t158 = _t96*_t97;
  const double _t159 = -_t88 - _t89 - 0.24e2;
  const double _t160 = _t105*_t159;
  const double _t161 = _t14*_t60;
  const double _t162 = _t160*_t161;
  const double _t163 = _t108*_t90;
  const double _t164 = _t163*_t18;
  const double _t165 = (0.1e1 / (_t23 * _t23 * _t23 * _t23));
  const double _t166 = -_t116 - 0.9e1*_t9 - 0.9e1;
  const double _t167 = _t165*_t166*_t96*params->task_bnu[3];
  const double _t168 = 0.4e1*_t55;
  const double _t169 = _t160*params->task_bnu[4];
  const double _t170 = _t169*_t60;
  const double _t171 = 0.32e2*_t170;
  const double _t172 = _t163*params->task_bnu[4];
  const double _t173 = 0.64e2*_t172;
  const double _t174 = _t167*_t55;
  const double _t175 = _t172*_t9;
  const double _t176 = 0.96e2*_t111;
  const double _t177 = 0.288e3*_t111;
  const double _t178 = (0.1e1 / (_t31 * _t31 * _t31 * _t31));
  const double _t179 = 0.36e2*r;
  const double _t180 = 0.12e2*_t21;
  const double _t181 = -_t135 - _t179 - _t180 - 0.12e2;
  const double _t182 = _t178*_t181;
  const double _t183 = _t107*_t182;
  const double _t184 = _t161*_t183;
  const double _t185 = _t60*params->task_bnu[4];
  const double _t186 = _t183*_t185;
  const double _t187 = 0.32e2*r;
  const double _t188 = 0.32e2*_t21;
#endif
#if _KMAX >= 4
  const double _t189 = xc_powi(_t1, -5);
  const double _t190 = _t189*params->task_bnu[1];
  const double _t191 = 0.72e2*params->task_bnu[3];
  const double _t192 = _t101*_t75;
  const double _t193 = 0.288e3*_t56;
  const double _t194 = 0.64e2*_t76;
  const double _t195 = 0.256e3*_t121;
  const double _t196 = _t195*_t77;
  const double _t197 = _t195*_t41;
  const double _t198 = 0.64e2*_t128;
  const double _t199 = 0.144e3*_t85;
  const double _t200 = _t141*_t77;
  const double _t201 = 0.16e2*_t141;
  const double _t202 = _t201*_t41;
  const double _t203 = _t140*_t78;
  const double _t204 = _t139*params->task_bnu[4];
  const double _t205 = _t144*_t204;
  const double _t206 = _t204*_t74;
  const double _t207 = 0.64e2*_t206;
  const double _t208 = _t207*_t41;
  const double _t209 = _t59*params->task_bnu[4];
  const double _t210 = 0.768e3*_t209;
  const double _t211 = 0.96e2*r;
  const double _t212 = _t51*_t77;
  const double _t213 = _t158*_t191;
  const double _t214 = 0.48e2*_t99;
  const double _t215 = 0.128e3*_t147;
  const double _t216 = 0.12e2*_t74;
  const double _t217 = _t150*_t98;
  const double _t218 = 0.216e3*_t151;
  const double _t219 = 0.144e3*_t99;
  const double _t220 = 0.384e3*_t147;
  const double _t221 = _t217*_t74;
  const double _t222 = 0.576e3*_t93;
  const double _t223 = 0.96e2*_t152;
  const double _t224 = (-_t69 - 0.8e1)/xc_powi(_t10, 5);
  const double _t225 = _t224*_t74*_t78*params->task_bnu[2];
  const double _t226 = 0.2e1*_t225;
  const double _t227 = _t144*_t224;
  const double _t228 = _t227*_t46;
  const double _t229 = 0.1152e4*r;
  const double _t230 = 0.768e3*_t63;
  const double _t231 = 0.144e3*_t104;
  const double _t232 = _t105*(-_t88 - 0.48e2);
  const double _t233 = _t161*_t232;
  const double _t234 = 0.24e2*params->task_bnu[4];
  const double _t235 = _t108*_t136;
  const double _t236 = _t234*_t235;
  const double _t237 = _t169*_t90;
  const double _t238 = 0.24e2*_t237;
  const double _t239 = _t165*params->task_bnu[3];
  const double _t240 = _t96*(-_t116 - 0.18e2);
  const double _t241 = _t239*_t55;
  const double _t242 = _t150*_t166*_t241;
  const double _t243 = _t185*_t232;
  const double _t244 = _t235*params->task_bnu[4];
  const double _t245 = _t240*_t241;
  const double _t246 = _t167*_t74;
  const double _t247 = 0.144e3*_t9;
  const double _t248 = 0.96e2*_t21;
  const double _t249 = 0.128e3*_t170;
  const double _t250 = 0.256e3*_t172;
  const double _t251 = 0.384e3*_t170;
  const double _t252 = 0.576e3*_t111;
  const double _t253 = _t166*_t90*_t96*params->task_bnu[3]/xc_powi(_t23, 5);
  const double _t254 = _t253*_t55;
  const double _t255 = _t107*_t161;
  const double _t256 = _t178*(-_t126 - _t135 - 0.36e2);
  const double _t257 = _t255*_t256;
  const double _t258 = _t159*_t182;
  const double _t259 = _t18*_t258*_t60;
  const double _t260 = _t183*_t90;
  const double _t261 = _t234*_t260;
  const double _t262 = _t107*_t185;
  const double _t263 = _t256*_t262;
  const double _t264 = _t185*_t258;
  const double _t265 = 0.64e2*_t264;
  const double _t266 = _t260*params->task_bnu[4];
  const double _t267 = 0.128e3*_t186;
  const double _t268 = 0.384e3*_t186;
  const double _t269 = _t181*(-0.16e2*_t21 - _t36 - _t88 - 0.16e2)/xc_powi(_t31, 5);
  const double _t270 = _t255*_t269;
  const double _t271 = _t262*_t269;
#endif

  const double f = _t13*_t9 + _t13 - _t15*_t9 - _t15 - _t17 - _t2*_t7 + _t20 + _t24*_t25 + _t24*_t28 - 0.4e1*_t24 - _t27 + _t29*_t33 + _t3*r - _t3 + _t33 + _t34*_t36 - _t35*r - _t37 + _t5 + params->task_bnu[0] - params->task_bnu[2] + params->task_bnu[4];
  out[0] = f;
#if _KMAX >= 1
  const double df_dr = -_t16*_t44 + _t17 + _t19 - _t20 - _t21*_t64 + 0.12e2*_t24 + _t25*_t58 - _t26*_t58 + _t27 + _t28*_t58 + _t29*_t62 + _t3 - _t35 + _t36*_t63 + _t37 - _t38*_t4 + _t38*_t7 - _t39*r + _t39 - _t40 + _t45*_t9 + _t45 - _t47*_t9 - _t47 - _t49 - _t5 + _t50*_t51 + _t52*r - _t53 - _t55*_t57 + _t62 - _t64*r;
  out[1] = df_dr;
#endif
#if _KMAX >= 2
  const double d2f_dr2 = -_t100*_t96 - _t103*_t9 + _t103*r + _t104*_t25 - _t104*_t26 + _t104*_t28 + _t110*_t29 + _t110 + _t111*_t36 - _t112*_t21 - _t112*r - _t16*_t79 - _t19 - _t21*_t94 + _t21*_t95 + _t25*_t85 - _t26*_t85 + _t28*_t85 + _t29*_t92 + _t36*_t93 + _t38*_t67 - 0.2e1*_t39 + _t40 + _t41*_t71 - _t41*_t72 + _t43*_t69 + _t44*_t69 - 0.8e1*_t44 + _t49 + _t50*_t9 + _t50 + _t52 + _t53 - _t54*_t65*params->task_bnu[3] + _t55*_t87 - _t57*_t74 - _t58*_t88 + _t58*_t89 + _t65*_t67 + _t66*_t8 - 0.2e1*_t66 - _t68*_t9 - _t68 - _t72 - _t73 + _t80*_t9 + _t80 + _t81*_t86 - _t82*_t9 - _t82 - _t84 + _t92 - _t94*r - _t95;
  out[2] = d2f_dr2;
#endif
#if _KMAX >= 3
  const double d3f_dr3 = -_t100*_t150 + _t104*_t135 + 0.36e2*_t104 + _t106*_t152 - _t113*_t115 + _t113*_t116*params->task_bnu[3] - _t114*_t54 + 0.6e1*_t114 - _t115*_t65 + _t117*r - _t117 - _t119*_t9 - _t119 - _t120*_t9 - _t120 + _t121*_t133 + _t123*_t9 + _t123 + _t124*_t9 + _t124 - _t125*_t70 + _t127*_t55 - _t127*_t74 - _t127 + _t129*_t41 + _t129*_t77 - _t131*_t41 - _t131*_t77 - _t132*_t55 + _t132*_t9 - _t134*_t88 + _t135*_t85 + _t138*_t29 + _t138 - _t142*_t16 + _t143*_t9 + _t143 + _t145*_t86 - _t146*_t9 - _t146 + _t147*_t36 - _t148*_t21 - _t148*r + _t149*_t21 - _t149 + _t152*_t48 - _t152*_t89 - 0.8e1*_t152 - _t153*_t9 + _t153*r + _t154*_t25 - _t154*_t26 + _t154*_t28 + _t155*_t9 + _t155 - _t156*_t63 - _t157*_t158*_t55 + _t162*_t29 + _t162 + _t164*_t29 + _t164 - _t167*_t168 + _t170*_t36 - _t171*_t21 - _t171*r - _t173*_t21 - _t173*r + _t174*_t25 - _t174*_t26 + _t174*_t28 + 0.96e2*_t175 + _t176*_t21 - _t176 - _t177*_t9 + _t177*r + _t184*_t29 + _t184 - _t186*_t187 - _t186*_t188 + _t186*_t36 - _t21*_t87 + _t25*_t79 - _t43*_t48 + 0.24e2*_t43 + 0.12e2*_t44 + 0.6e1*_t66 + _t73 - 0.12e2*_t79 - _t83 + _t84 + 0.36e2*_t85 + _t87;
  out[3] = d3f_dr3;
#endif
#if _KMAX >= 4
  const double d4f_dr4 = -_t102*_t29 - _t102 + _t106*_t242 - _t111*_t229 + _t113*_t191 - 0.24e2*_t114 - 0.96e2*_t128 + 0.384e3*_t130 + _t133*_t204 - 0.96e2*_t134 - _t135*_t221 - _t135*_t246 + 0.32e2*_t141*_t51 + _t150*_t214 - 0.192e3*_t152*r - _t154*_t211 + _t154*_t36 + _t156*_t56 - _t157*_t189 - _t16*_t225 - _t167*_t216 - _t168*_t239*_t240 - _t168*_t253 + 0.768e3*_t172*r - _t174*_t211 + _t174*_t36 + 0.48e2*_t174 - 0.768e3*_t175 + _t179*_t221 + _t179*_t246 + _t180*_t221 + _t180*_t246 - _t187*_t243 - _t187*_t263 - _t187*_t271 - _t188*_t243 - _t188*_t263 - _t188*_t271 + _t189*_t191 + _t190*_t48 - 0.24e2*_t190 - _t192*_t9 - _t192 - _t193*_t9 - _t193 + _t194*_t41 + _t194*_t77 + _t196*r - _t196 + _t197*r - _t197 - _t198*_t41 - _t198*_t77 + _t199*r - _t199 - _t200*_t26 + _t200*_t48 - 0.12e2*_t200 + _t201*_t212 - _t201*_t78 - _t202*_t9 - _t202 - _t203*_t26 + _t203*_t48 - 0.12e2*_t203 - 0.96e2*_t204*_t212 + _t204*_t36*_t78 - _t205*_t211 + _t205*_t36 - 0.64e2*_t205*_t51 + 0.48e2*_t205 - 0.128e3*_t206*_t51 + _t207*_t78 + _t208*_t9 + _t208 - 0.1152e4*_t209*_t9 + _t21*_t210 - _t21*_t213 - _t21*_t214 + _t21*_t215 + _t21*_t249 + _t21*_t250 - _t21*_t265 + _t21*_t267 + _t210*r - _t211*_t237 - _t211*_t244 - _t211*_t266 + _t213 + _t214 - _t215 - _t216*_t217 + _t218*_t9 - _t218*r + _t219*_t9 - _t219*r - _t220*_t9 + _t220*r + _t222*_t9 + _t222 + _t223*_t9 + _t223 + _t226*_t9 + _t226 + _t227*_t86 - _t228*_t9 - _t228 - _t229*_t93 + _t230*r - _t230 + _t231*r - _t231 + _t233*_t29 + _t233 + _t236*_t29 + _t236 + _t237*_t247 - _t237*_t248 + _t238*_t29 + _t238 + _t242*_t48 - _t242*_t89 - 0.8e1*_t242 + _t243*_t36 + _t244*_t247 - _t244*_t248 + _t245*_t25 - _t245*_t26 + _t245*_t28 + _t247*_t266 - _t248*_t266 - _t249 + _t25*_t254 - _t250 - _t251*_t9 + _t251*r + _t252*_t9 + _t252 - _t254*_t26 + _t254*_t28 + _t257*_t29 + _t257 + _t259*_t29 + _t259 + _t261*_t29 + _t261 + _t263*_t36 + 0.96e2*_t264*_t9 - _t265*r - _t267 - _t268*_t9 + _t268*r + _t270*_t29 + _t270 + _t271*_t36 + _t36*_t76 - 0.48e2*_t43 + 0.96e2*_t58 + 0.192e3*_t70 + 0.48e2*_t76 + 0.24e2*_t79 + _t83;
  out[4] = d4f_dr4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {
  const mgga_x_task_params *params = (const mgga_x_task_params *)(p->params);

  const double _t1 = xc_powr(n_s, -8, 3);
  const double _t2 = _t1*sigma_ss;
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t5 = _t3*_t4;
  const double _t6 = (0.1e1 / 0.24e2)*_t5;
  const double _t7 = _t2*_t6;
  const double _t8 = xc_powr(XC_EPSILON, 2, 3);
  const double _t9 = 0.8e1*tau_s;
  const double _t10 = (0.1e1 / tau_s);
  const double _t11 = (0.1e1 / n_s);
  const double _t12 = (0.1e1 / 0.8e1)*_t11;
  const double _t13 = _t10*_t12;
  const double _t14 = _t13*(-_t8*_t9*n_s + 0.8e1*n_s*tau_s - sigma_ss) > 0;
  const double _t15 = xc_powr(n_s, 5, 3);
  const double _t16 = (0.1e1 / _t15);
  const double _t17 = _t16*_t9 - _t2;
  const double _t18 = _t10*_t17;
  const double _t19 = (0.1e1 / 0.8e1)*_t15;
  const double _t20 = my_piecewise3(_t14, _t18*_t19, _t8);
  const double _t21 = _t16*_t5;
  const double _t22 = (0.5e1 / 0.9e1)*_t21;
  const double _t23 = _t20*_t22;
  const double _t24 = xc_powr(n_s, -1, 3);
  const double _t25 = (0.1e1 / (M_CBRTPI));
  const double _t26 = _t25*_t3;
  const double _t27 = (0.1e1 / 0.2e1)*_t26;
  const double _t28 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t36 = (tau_s * tau_s);
  const double _t37 = (0.1e1 / _t36);
  const double _t38 = _t17*_t37;
  const double _t39 = my_piecewise3(_t14, _t10 - _t19*_t38, 0);
  const double _t40 = _t22*tau_s;
  const double _t41 = _t23 + _t39*_t40;
  const double _t46 = _t1*_t6;
  const double _t53 = my_piecewise3(_t14, -_t13, 0);
  const double _t57 = xc_powr(n_s, -4, 3);
  const double _t62 = xc_powr(n_s, -11, 3);
  const double _t63 = _t5*_t62*sigma_ss;
  const double _t65 = (0.1e1 / 0.9e1)*_t63;
  const double _t66 = _t20*_t5;
  const double _t67 = _t1*tau_s;
  const double _t68 = (0.25e2 / 0.27e2)*_t67;
  const double _t69 = xc_powr(n_s, 2, 3);
  const double _t70 = (0.5e1 / 0.24e2)*_t69;
  const double _t71 = (0.8e1 / 0.3e1)*_t62*sigma_ss - 0.40e2 / 0.3e1*_t67;
  const double _t72 = _t19*_t71;
  const double _t73 = my_piecewise3(_t14, _t10*_t72 + _t18*_t70, 0);
  const double _t74 = _t22*_t73;
  const double _t75 = -_t66*_t68 + _t74*tau_s;
#endif
#if _KMAX >= 2
  const double _t79 = (_t41 * _t41);
  const double _t82 = _t21*_t39;
  const double _t83 = (tau_s * tau_s * tau_s);
  const double _t84 = (0.1e1 / _t83);
  const double _t85 = (0.1e1 / 0.4e1)*_t84;
  const double _t86 = _t15*_t17;
  const double _t87 = my_piecewise3(_t14, -0.2e1*_t37 + _t85*_t86, 0);
  const double _t88 = _t40*_t87 + (0.10e2 / 0.9e1)*_t82;
  const double _t90 = my_piecewise3(_t14, _t12*_t37, 0);
  const double _t98 = _t40*_t53;
  const double _t102 = xc_powr(n_s, -16, 3);
  const double _t103 = xc_powr(0.6e1, 2, 3);
  const double _t104 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t105 = _t103*_t104;
  const double _t106 = _t102*_t105;
  const double _t107 = (0.1e1 / 0.576e3)*_t106;
  const double _t119 = ((params->task_d) * (params->task_d));
  const double _t123 = xc_powr(n_s, -13, 3);
  const double _t124 = _t105*_t123;
  const double _t125 = (0.5e1 / 0.108e3)*_t124;
  const double _t127 = xc_powr(n_s, -10, 3);
  const double _t128 = _t105*_t127;
  const double _t130 = (_t53 * _t53);
  const double _t131 = _t130*_t36;
  const double _t132 = (0.25e2 / 0.81e2)*_t131;
  const double _t133 = _t125*tau_s;
  const double _t141 = _t1*_t5;
  const double _t142 = (0.25e2 / 0.27e2)*_t141;
  const double _t143 = _t5*_t68;
  const double _t144 = my_piecewise3(_t14, -_t37*_t72 - _t38*_t70, 0);
  const double _t145 = -_t142*_t20 - _t143*_t39 + _t144*_t40 + _t74;
  const double _t149 = _t5*_t62;
  const double _t150 = xc_powr(n_s, -19, 3);
  const double _t153 = (0.1e1 / 0.216e3)*sigma_ss;
  const double _t156 = (0.1e1 / 0.108e3)*sigma_ss;
  const double _t157 = _t105*_t150;
  const double _t158 = _t156*_t157;
  const double _t160 = (0.1e1 / 0.9e1)*_t149;
  const double _t161 = _t153*_t157;
  const double _t163 = (0.1e1 / (n_s * n_s));
  const double _t164 = (0.1e1 / 0.8e1)*_t163;
  const double _t165 = my_piecewise3(_t14, _t10*_t164, 0);
  const double _t166 = _t165*_t22;
  const double _t167 = -_t143*_t53 + _t166*tau_s;
  const double _t173 = xc_powr(n_s, -7, 3);
  const double _t176 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t180 = xc_powr(n_s, -14, 3);
  const double _t181 = _t180*sigma_ss;
  const double _t184 = xc_powr(n_s, -22, 3);
  const double _t186 = (sigma_ss * sigma_ss);
  const double _t187 = (0.1e1 / 0.81e2)*_t186;
  const double _t191 = _t105*_t184;
  const double _t193 = (0.2e1 / 0.81e2)*_t186;
  const double _t194 = (0.11e2 / 0.27e2)*_t5;
  const double _t195 = _t181*_t194;
  const double _t196 = _t187*_t191;
  const double _t198 = (_t75 * _t75);
  const double _t201 = (0.2e1 / 0.9e1)*_t63;
  const double _t203 = _t62*tau_s;
  const double _t204 = (0.200e3 / 0.81e2)*_t203;
  const double _t205 = _t5*_t67;
  const double _t206 = (0.50e2 / 0.27e2)*_t205;
  const double _t207 = (0.5e1 / 0.36e2)*_t24;
  const double _t208 = (0.5e1 / 0.12e2)*_t69;
  const double _t209 = _t10*_t71;
  const double _t210 = -0.88e2 / 0.9e1*_t181 + (0.320e3 / 0.9e1)*_t203;
  const double _t211 = _t19*_t210;
  const double _t212 = my_piecewise3(_t14, _t10*_t211 + _t18*_t207 + _t208*_t209, 0);
  const double _t213 = _t212*_t22;
  const double _t214 = _t204*_t66 - _t206*_t73 + _t213*tau_s;
#endif
#if _KMAX >= 3
  const double _t218 = (_t41 * _t41 * _t41);
  const double _t221 = _t21*_t87;
  const double _t222 = (0.5e1 / 0.3e1)*_t221;
  const double _t223 = (tau_s * tau_s * tau_s * tau_s);
  const double _t224 = (0.1e1 / _t223);
  const double _t225 = (0.3e1 / 0.4e1)*_t224;
  const double _t226 = my_piecewise3(_t14, -_t225*_t86 + 0.6e1*_t84, 0);
  const double _t227 = _t222 + _t226*_t40;
  const double _t229 = (0.10e2 / 0.9e1)*_t221*tau_s + (0.20e2 / 0.9e1)*_t82;
  const double _t231 = (0.10e2 / 0.9e1)*_t21;
  const double _t232 = my_piecewise3(_t14, -_t11*_t85, 0);
  const double _t239 = _t231*_t53;
  const double _t240 = _t231*tau_s;
  const double _t249 = (0.50e2 / 0.81e2)*_t128;
  const double _t252 = _t249*_t36;
  const double _t257 = (0.1e1 / 0.288e3)*_t106;
  const double _t260 = _t41*_t53;
  const double _t264 = _t128*_t132;
  const double _t270 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t271 = xc_powi(n_s, -8);
  const double _t272 = _t270*_t271;
  const double _t273 = (0.1e1 / 0.768e3)*_t272;
  const double _t279 = _t119*_t273;
  const double _t282 = ((params->task_d) * (params->task_d) * (params->task_d));
  const double _t283 = xc_powi(n_s, -7);
  const double _t284 = _t270*_t283;
  const double _t285 = (0.5e1 / 0.288e3)*_t284;
  const double _t289 = xc_powi(n_s, -6);
  const double _t290 = _t270*_t289;
  const double _t291 = (0.25e2 / 0.108e3)*_t290;
  const double _t293 = (0.5e1 / 0.144e3)*_t284;
  const double _t295 = xc_powi(n_s, -5);
  const double _t298 = (_t53 * _t53 * _t53);
  const double _t299 = _t298*_t83;
  const double _t300 = (0.250e3 / 0.243e3)*_t299;
  const double _t301 = _t285*tau_s;
  const double _t304 = _t131*_t291;
  const double _t309 = (0.1e1 / 0.9e1)*_t79;
  const double _t315 = (0.50e2 / 0.27e2)*_t141;
  const double _t316 = _t144*_t231;
  const double _t317 = _t17*_t84;
  const double _t318 = _t15*_t71;
  const double _t319 = my_piecewise3(_t14, _t208*_t317 + _t318*_t85, 0);
  const double _t320 = -_t143*_t87 - _t315*_t39 + _t316 + _t319*_t40;
  const double _t326 = (0.5e1 / 0.81e2)*sigma_ss;
  const double _t329 = _t326*tau_s;
  const double _t330 = _t106*_t329;
  const double _t335 = _t157*sigma_ss;
  const double _t341 = my_piecewise3(_t14, -_t164*_t37, 0);
  const double _t342 = -_t142*_t53 - _t143*_t90 + _t166 + _t341*_t40;
  const double _t344 = _t22*_t53;
  const double _t347 = _t41*_t75;
  const double _t352 = xc_powi(n_s, -9);
  const double _t355 = (0.1e1 / 0.864e3)*sigma_ss;
  const double _t360 = _t270*_t352;
  const double _t361 = _t360*sigma_ss;
  const double _t362 = (0.1e1 / 0.288e3)*_t361;
  const double _t364 = (0.1e1 / 0.54e2)*_t157;
  const double _t366 = _t119*_t362;
  const double _t367 = _t355*_t360;
  const double _t369 = (0.1e1 / 0.108e3)*_t157;
  const double _t370 = (0.1e1 / 0.432e3)*_t361;
  const double _t377 = (0.5e1 / 0.162e3)*sigma_ss;
  const double _t378 = _t272*_t377;
  const double _t381 = (0.1e1 / 0.12e2)*_t141;
  const double _t387 = _t125*_t75;
  const double _t398 = _t191*_t193;
  const double _t402 = -_t20*_t315 - _t206*_t39 + _t231*_t73 + _t316*tau_s;
  const double _t404 = (0.200e3 / 0.81e2)*_t149;
  const double _t405 = _t204*_t5;
  const double _t406 = _t37*_t71;
  const double _t407 = my_piecewise3(_t14, -_t207*_t38 - _t208*_t406 - _t211*_t37, 0);
  const double _t408 = -_t144*_t206 + _t20*_t404 + _t213 - _t315*_t73 + _t39*_t405 + _t40*_t407;
  const double _t413 = xc_powi(n_s, -10);
  const double _t415 = (0.1e1 / 0.324e3)*_t186;
  const double _t416 = (0.1e1 / 0.24e2)*sigma_ss;
  const double _t418 = _t186*_t413;
  const double _t419 = (0.1e1 / 0.108e3)*_t418;
  const double _t420 = _t270*_t419;
  const double _t422 = (0.1e1 / 0.12e2)*sigma_ss;
  const double _t423 = _t180*_t194;
  const double _t424 = _t119*_t420;
  const double _t425 = _t413*_t415;
  const double _t426 = _t270*_t425;
  const double _t427 = _t191*_t416;
  const double _t429 = _t270*_t418;
  const double _t430 = (0.1e1 / 0.162e3)*_t429;
  const double _t432 = (0.10e2 / 0.243e3)*_t186;
  const double _t435 = (0.55e2 / 0.243e3)*_t157;
  const double _t437 = _t186*_t360;
  const double _t438 = (0.20e2 / 0.243e3)*_t437;
  const double _t440 = _t360*_t432;
  const double _t443 = sigma_ss*tau_s;
  const double _t444 = _t435*_t443;
  const double _t447 = (0.1e1 / 0.4e1)/(n_s * n_s * n_s);
  const double _t448 = my_piecewise3(_t14, -_t10*_t447, 0);
  const double _t449 = _t22*_t448;
  const double _t450 = -_t165*_t206 + _t405*_t53 + _t449*tau_s;
  const double _t453 = (0.1e1 / 0.54e2)*_t335;
  const double _t457 = (0.10e2 / 0.81e2)*sigma_ss;
  const double _t458 = _t106*_t457;
  const double _t459 = _t53*_t75;
  const double _t462 = _t165*_t231;
  const double _t463 = -_t206*_t53 + _t462*tau_s;
  const double _t468 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t469 = (0.1e1 / M_PI);
  const double _t476 = xc_powi(n_s, -11);
  const double _t478 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t479 = (0.2e1 / 0.243e3)*_t478;
  const double _t480 = xc_powr(n_s, -17, 3);
  const double _t481 = _t480*sigma_ss;
  const double _t483 = xc_powr(n_s, -25, 3);
  const double _t485 = (0.11e2 / 0.81e2)*_t186;
  const double _t489 = _t476*_t478;
  const double _t490 = _t270*_t489;
  const double _t491 = (0.2e1 / 0.81e2)*_t490;
  const double _t492 = _t105*_t483;
  const double _t494 = _t119*_t491;
  const double _t495 = _t270*_t476*_t479;
  const double _t496 = _t481*_t5;
  const double _t497 = _t485*_t492;
  const double _t498 = (_t75 * _t75 * _t75);
  const double _t500 = (0.11e2 / 0.9e1)*_t5;
  const double _t501 = _t181*_t500;
  const double _t502 = (0.1e1 / 0.27e2)*_t186;
  const double _t504 = (0.2e1 / 0.27e2)*_t186;
  const double _t505 = _t191*_t504;
  const double _t506 = _t191*_t502;
  const double _t508 = _t180*tau_s;
  const double _t509 = (0.2200e4 / 0.243e3)*_t66;
  const double _t510 = (0.200e3 / 0.27e2)*_t73;
  const double _t511 = _t203*_t5;
  const double _t512 = (0.25e2 / 0.9e1)*_t205;
  const double _t513 = (0.5e1 / 0.12e2)*_t24;
  const double _t514 = _t10*_t210;
  const double _t515 = (0.5e1 / 0.8e1)*_t69;
  const double _t516 = (0.1232e4 / 0.27e2)*_t480*sigma_ss - 0.3520e4 / 0.27e2*_t508;
  const double _t517 = _t19*_t516;
  const double _t518 = my_piecewise3(_t14, _t10*_t517 - 0.5e1 / 0.108e3*_t18*_t57 + _t209*_t513 + _t514*_t515, 0);
  const double _t519 = _t22*_t518;
  const double _t520 = -_t212*_t512 - _t508*_t509 + _t510*_t511 + _t519*tau_s;
  const double _t523 = _t203*_t66;
  const double _t524 = (0.100e3 / 0.27e2)*_t205;
  const double _t525 = _t212*_t231;
  const double _t526 = (0.400e3 / 0.81e2)*_t523 - _t524*_t73 + _t525*tau_s;
#endif
#if _KMAX >= 4
  const double _t531 = (0.20e2 / 0.9e1)*_t21;
  const double _t533 = (0.5e1 / 0.3e1)*_t21;
  const double _t538 = _t533*tau_s;
  const double _t539 = _t53*_t533;
  const double _t540 = _t538*_t90;
  const double _t546 = _t260*_t40;
  const double _t548 = (0.5e1 / 0.54e2)*_t124;
  const double _t549 = _t90*tau_s;
  const double _t556 = _t41*_t548;
  const double _t560 = _t130*tau_s;
  const double _t561 = (0.100e3 / 0.81e2)*_t128;
  const double _t565 = _t36*_t90;
  const double _t569 = (0.25e2 / 0.54e2)*_t290;
  const double _t579 = (0.1e1 / 0.2304e4)*_t272;
  const double _t588 = (0.1e1 / 0.1152e4)*_t272*params->task_d;
  const double _t590 = _t282*_t579;
  const double _t597 = _t270*_t295*_t300;
  const double _t600 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t601 = xc_powr(n_s, -32, 3);
  const double _t602 = _t3*_t600;
  const double _t603 = _t601*_t602;
  const double _t605 = (0.1e1 / 0.9216e4)*_t603;
  const double _t615 = ((params->task_d) * (params->task_d) * (params->task_d) * (params->task_d));
  const double _t619 = xc_powr(n_s, -29, 3);
  const double _t620 = _t602*_t619;
  const double _t621 = (0.5e1 / 0.5184e4)*_t620;
  const double _t623 = xc_powr(n_s, -26, 3);
  const double _t624 = _t602*_t623;
  const double _t625 = (0.25e2 / 0.1296e4)*_t624;
  const double _t626 = _t299*_t602;
  const double _t627 = (0.125e3 / 0.729e3)/xc_powr(n_s, 23, 3);
  const double _t628 = (0.5e1 / 0.1728e4)*_t620;
  const double _t630 = _t628*tau_s;
  const double _t632 = xc_powr(n_s, -20, 3);
  const double _t643 = _t218*_t65;
  const double _t644 = _t65*_t88;
  const double _t646 = _t229*_t65;
  const double _t648 = (0.25e2 / 0.9e1)*_t141;
  const double _t649 = 0.3e1*_t145;
  const double _t651 = _t231*_t341;
  const double _t653 = _t240*_t90;
  const double _t654 = _t40*_t459;
  const double _t656 = (0.100e3 / 0.243e3)*_t284*sigma_ss;
  const double _t657 = _t272*_t329;
  const double _t660 = (0.10e2 / 0.81e2)*_t106;
  const double _t671 = (0.50e2 / 0.243e3)*_t131*_t284*sigma_ss;
  const double _t685 = xc_powr(n_s, -35, 3);
  const double _t686 = _t685*sigma_ss;
  const double _t687 = (0.1e1 / 0.20736e5)*_t686;
  const double _t689 = (0.1e1 / 0.96e2)*_t360;
  const double _t690 = _t119*_t689;
  const double _t691 = (0.1e1 / 0.288e3)*_t360;
  const double _t693 = _t602*_t686;
  const double _t694 = (0.1e1 / 0.5184e4)*_t693;
  const double _t695 = (0.1e1 / 0.3456e4)*_t693;
  const double _t702 = _t602*_t687;
  const double _t711 = (0.1e1 / 0.192e3)*_t106;
  const double _t714 = (0.5e1 / 0.36e2)*_t124;
  const double _t722 = (0.100e3 / 0.27e2)*_t141;
  const double _t723 = (0.400e3 / 0.81e2)*_t149;
  const double _t724 = _t231*_t407;
  const double _t725 = (0.5e1 / 0.6e1)*_t69;
  const double _t726 = _t435*sigma_ss;
  const double _t731 = _t40*_t90;
  const double _t733 = (0.43e2 / 0.2592e4)*sigma_ss;
  const double _t734 = xc_powr(n_s, -38, 3);
  const double _t735 = _t186*_t734;
  const double _t736 = (0.1e1 / 0.7776e4)*_t735;
  const double _t737 = _t270*_t413;
  const double _t738 = _t737*sigma_ss;
  const double _t739 = (0.43e2 / 0.864e3)*_t738;
  const double _t742 = _t119*_t739;
  const double _t743 = _t733*_t737;
  const double _t744 = _t602*_t735;
  const double _t745 = (0.1e1 / 0.1944e4)*_t744;
  const double _t746 = (0.1e1 / 0.1296e4)*_t744;
  const double _t747 = (0.19e2 / 0.324e3)*_t191;
  const double _t753 = _t602*_t736;
  const double _t755 = (0.1e1 / 0.2592e4)*_t744;
  const double _t758 = (0.110e3 / 0.243e3)*tau_s;
  const double _t759 = _t157*_t758;
  const double _t760 = (0.550e3 / 0.729e3)*_t272;
  const double _t761 = _t186*_t685;
  const double _t762 = (0.5e1 / 0.1458e4)*_t761;
  const double _t763 = _t361*tau_s;
  const double _t764 = _t186*_t603;
  const double _t765 = (0.50e2 / 0.2187e4)*_t764;
  const double _t767 = _t602*_t761;
  const double _t768 = (0.5e1 / 0.486e3)*_t767;
  const double _t772 = _t602*_t762;
  const double _t781 = (0.1e1 / 0.144e3)*_t361;
  const double _t794 = _t131*_t656;
  const double _t800 = (0.400e3 / 0.81e2)*_t511;
  const double _t801 = _t5*_t508;
  const double _t802 = (0.2200e4 / 0.243e3)*_t801;
  const double _t803 = (0.200e3 / 0.27e2)*_t511;
  const double _t804 = (0.19e2 / 0.324e3)*_t186;
  const double _t805 = (0.341e3 / 0.972e3)*sigma_ss;
  const double _t806 = xc_powr(n_s, -41, 3);
  const double _t807 = _t478*_t806;
  const double _t808 = (0.1e1 / 0.2916e4)*_t807;
  const double _t809 = _t270*_t476;
  const double _t810 = _t186*_t809;
  const double _t811 = (0.19e2 / 0.108e3)*_t810;
  const double _t812 = _t602*_t807;
  const double _t813 = (0.1e1 / 0.729e3)*_t812;
  const double _t814 = (0.1e1 / 0.486e3)*_t812;
  const double _t816 = _t804*_t809;
  const double _t818 = _t492*_t805;
  const double _t819 = _t602*_t808;
  const double _t820 = (0.10e2 / 0.729e3)*_t478*_t602*_t734;
  const double _t822 = _t180*_t500;
  const double _t824 = (0.1e1 / 0.8e1)*sigma_ss;
  const double _t825 = (0.1e1 / 0.36e2)*_t429;
  const double _t828 = _t191*_t824;
  const double _t830 = _t437*_t459;
  const double _t832 = _t478/xc_powi(n_s, 12);
  const double _t833 = (0.44e2 / 0.243e3)*_t832;
  const double _t834 = _t632*sigma_ss;
  const double _t835 = (0.2618e4 / 0.243e3)*_t834;
  const double _t836 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss)/xc_powr(n_s, 44, 3);
  const double _t837 = (0.2e1 / 0.2187e4)*_t836;
  const double _t838 = _t186/xc_powr(n_s, 28, 3);
  const double _t839 = (0.979e3 / 0.729e3)*_t838;
  const double _t840 = _t270*_t832;
  const double _t841 = (0.44e2 / 0.81e2)*_t840;
  const double _t842 = _t602*_t836;
  const double _t843 = (0.8e1 / 0.2187e4)*_t842;
  const double _t844 = (0.4e1 / 0.729e3)*_t842;
  const double _t845 = _t119*_t841;
  const double _t846 = _t270*_t833;
  const double _t850 = _t602*_t837;
  const double _t851 = _t105*_t839;
  const double _t853 = (0.2e1 / 0.729e3)*_t842;
  const double _t854 = (0.8e1 / 0.243e3)*_t489;
  const double _t855 = (0.616e3 / 0.81e2)*_t496;
  const double _t856 = (0.22e2 / 0.9e1)*_t181*_t5;
  const double _t857 = (0.4e1 / 0.9e1)*_t63;
  const double _t858 = (0.44e2 / 0.81e2)*_t186;
  const double _t859 = (0.8e1 / 0.81e2)*_t490;
  const double _t861 = _t270*_t854;
  const double _t866 = _t492*_t858;
  const double _t871 = (0.50e2 / 0.9e1)*_t205;
  const double _t873 = _t480*tau_s;
  const double _t874 = (0.400e3 / 0.27e2)*_t511;
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t28)) XC_CAT(task_gx_k, _KMAX)(p, _t7, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t28)) XC_CAT(task_fx_k, _KMAX)(p, _t23*tau_s, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t28)) XC_CAT(task_hx1_k, _KMAX)(p, _t7, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t28)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t24*_t27, 0.1e1 - p->zeta_threshold, _hc3);
  const double _t29 = 1.0 - _hc1[0];
  const double _t30 = pow(_hc0[0], params->task_d);
  const double _t31 = _hc2[0] - params->task_h0x;
  const double _t32 = _t30*_t31;
  const double _t33 = _t29*_t32;
  const double _t34 = _hc0[0]*params->task_h0x + _t33;
  const double _t35 = my_piecewise3(_t28, 0, _hc3[0]*_t34);
#if _KMAX >= 1
  const double _t42 = _hc1[1]*_t32;
  const double _t43 = _hc3[0]*_t42;
  const double _t44 = my_piecewise3(_t28, 0, -_t41*_t43);
  const double _t45 = _hc0[1]*params->task_h0x;
  const double _t47 = _t29*_t30;
  const double _t48 = _hc2[1]*_t47;
  const double _t49 = (0.1e1 / (_hc0[0]));
  const double _t50 = _t49*params->task_d;
  const double _t51 = _hc0[1]*_t50;
  const double _t52 = _t33*_t51;
  const double _t54 = _t42*_t53;
  const double _t55 = -_t40*_t54 + _t45*_t46 + _t46*_t48 + _t46*_t52;
  const double _t56 = my_piecewise3(_t28, 0, _hc3[0]*_t55);
  const double _t58 = _hc3[2]*_t26;
  const double _t59 = _t57*_t58;
  const double _t60 = (0.1e1 / 0.6e1)*_t59;
  const double _t61 = (0.1e1 / 0.9e1)*_t45;
  const double _t64 = (0.1e1 / 0.9e1)*_t48;
  const double _t76 = _t42*_t75;
  const double _t77 = -_t52*_t65 - _t61*_t63 - _t63*_t64 - _t76;
  const double _t78 = my_piecewise3(_t28, 0, _hc3[0]*_t77 - _t34*_t60);
#endif
#if _KMAX >= 2
  const double _t80 = _hc1[2]*_t32;
  const double _t81 = _hc3[0]*_t80;
  const double _t89 = my_piecewise3(_t28, 0, -_t43*_t88 - _t79*_t81);
  const double _t91 = _t42*_t90;
  const double _t92 = _hc1[1]*_t30;
  const double _t93 = _t41*_t92;
  const double _t94 = _hc2[1]*_t46;
  const double _t95 = _t41*_t42;
  const double _t96 = _t46*_t51;
  const double _t97 = _t41*_t80;
  const double _t99 = -_t22*_t54 - _t40*_t91 - _t93*_t94 - _t95*_t96 - _t97*_t98;
  const double _t100 = my_piecewise3(_t28, 0, _hc3[0]*_t99);
  const double _t101 = _hc0[2]*params->task_h0x;
  const double _t108 = _hc2[2]*_t47;
  const double _t109 = _t48*params->task_d;
  const double _t110 = (0.1e1 / 0.288e3)*_t109;
  const double _t111 = _hc0[1]*_t49;
  const double _t112 = _t33*_t50;
  const double _t113 = _hc0[2]*_t112;
  const double _t114 = _t33*params->task_d;
  const double _t115 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t116 = ((_hc0[1]) * (_hc0[1]));
  const double _t117 = _t115*_t116;
  const double _t118 = _t107*_t117;
  const double _t120 = _t119*_t33;
  const double _t121 = _t53*_t92;
  const double _t122 = _hc2[1]*_t121;
  const double _t126 = _t122*_t125;
  const double _t129 = _t128*_t80;
  const double _t134 = _t51*_t54;
  const double _t135 = _t101*_t107 + _t106*_t110*_t111 + _t107*_t108 + _t107*_t113 - _t114*_t118 + _t118*_t120 - _t126*tau_s - _t129*_t132 - _t133*_t134;
  const double _t136 = my_piecewise3(_t28, 0, _hc3[0]*_t135);
  const double _t137 = _hc2[1]*_t93;
  const double _t138 = _t51*_t95;
  const double _t139 = _t75*_t80;
  const double _t140 = _t139*_t41;
  const double _t146 = _t145*_t42;
  const double _t147 = _t137*_t65 + _t138*_t65 - _t140 - _t146;
  const double _t148 = my_piecewise3(_t28, 0, _hc3[0]*_t147 + _t60*_t95);
  const double _t151 = _t101*_t105;
  const double _t152 = _t150*_t151;
  const double _t154 = _t105*_t108;
  const double _t155 = _t150*_t154;
  const double _t159 = _t109*_t111;
  const double _t162 = _t117*_t120;
  const double _t168 = _t167*_t42;
  const double _t169 = _t75*_t92;
  const double _t170 = (0.5e1 / 0.81e2)*_hc0[1]*_hc1[1]*_t102*_t103*_t104*_t30*_t31*_t49*_t53*params->task_d*sigma_ss*tau_s + (0.5e1 / 0.81e2)*_hc1[1]*_hc2[1]*_t102*_t103*_t104*_t30*_t53*sigma_ss*tau_s + (0.1e1 / 0.216e3)*_t103*_t104*_t115*_t116*_t150*_t29*_t30*_t31*params->task_d*sigma_ss - _t113*_t161 - _t139*_t98 - _t149*_t61 - _t149*_t64 - _t152*_t153 - _t153*_t155 - _t158*_t159 - _t160*_t52 - _t161*_t162 - _t168 - _t169*_t94 - _t76*_t96;
  const double _t171 = my_piecewise3(_t28, 0, _hc3[0]*_t170 - _t55*_t60);
  const double _t172 = (0.2e1 / 0.9e1)*_t34;
  const double _t174 = _t173*_t58;
  const double _t175 = (0.1e1 / 0.36e2)*_t34;
  const double _t177 = _hc3[5]*_t103*_t176;
  const double _t178 = _t1*_t177;
  const double _t179 = (0.1e1 / 0.3e1)*_t59;
  const double _t182 = _t45*_t5;
  const double _t183 = (0.11e2 / 0.27e2)*_t182;
  const double _t185 = _t151*_t184;
  const double _t188 = _t48*_t5;
  const double _t189 = (0.11e2 / 0.27e2)*_t188;
  const double _t190 = _t154*_t184;
  const double _t192 = _t159*_t191;
  const double _t197 = _t114*_t117;
  const double _t199 = _t198*_t80;
  const double _t200 = _hc2[1]*_t169;
  const double _t202 = _t51*_t76;
  const double _t215 = _t214*_t42;
  const double _t216 = _t113*_t196 + _t162*_t196 + _t181*_t183 + _t181*_t189 + _t185*_t187 + _t187*_t190 + _t192*_t193 + _t195*_t52 - _t196*_t197 - _t199 + _t200*_t201 + _t201*_t202 - _t215;
  const double _t217 = my_piecewise3(_t28, 0, _hc3[0]*_t216 + _t172*_t174 + _t175*_t178 - _t179*_t77);
#endif
#if _KMAX >= 3
  const double _t219 = _hc1[3]*_t32;
  const double _t220 = _hc3[0]*_t219;
  const double _t228 = _t41*_t81;
  const double _t230 = my_piecewise3(_t28, 0, -_t218*_t220 - _t227*_t43 - _t228*_t229 - _t228*_t88);
  const double _t233 = _t232*_t42;
  const double _t234 = _hc1[2]*_t30;
  const double _t235 = _t234*_t94;
  const double _t236 = _t92*_t94;
  const double _t237 = _t79*_t80;
  const double _t238 = _t42*_t88;
  const double _t241 = _t90*_t97;
  const double _t242 = _t219*_t79;
  const double _t243 = _t80*_t88;
  const double _t244 = -_t231*_t91 - _t233*_t40 - _t235*_t79 - _t236*_t88 - _t237*_t96 - _t238*_t96 - _t239*_t97 - _t240*_t241 - _t242*_t98 - _t243*_t98;
  const double _t245 = my_piecewise3(_t28, 0, _hc3[0]*_t244);
  const double _t246 = _hc2[1]*_t92;
  const double _t247 = _t246*_t90;
  const double _t248 = _t130*_t80;
  const double _t250 = _t248*_t249;
  const double _t251 = _t51*_t91;
  const double _t253 = _t252*_t80;
  const double _t254 = _t253*_t53;
  const double _t255 = _hc2[2]*_t107;
  const double _t256 = _t137*_t51;
  const double _t258 = _hc0[2]*_t50;
  const double _t259 = _t107*_t258;
  const double _t261 = _hc2[1]*_t234;
  const double _t262 = _t261*tau_s;
  const double _t263 = _t125*_t262;
  const double _t265 = _t219*_t41;
  const double _t266 = _t53*_t97;
  const double _t267 = _t266*_t51;
  const double _t268 = (0.1e1 / 0.576e3)*_hc1[1]*_t102*_t103*_t104*_t115*_t116*_t30*_t31*_t41*params->task_d - _t118*_t119*_t95 - _t125*_t134 - _t126 - _t133*_t247 - _t133*_t251 - _t133*_t267 - _t250*tau_s - _t254*_t90 - _t255*_t93 - _t256*_t257 - _t259*_t95 - _t260*_t263 - _t264*_t265;
  const double _t269 = my_piecewise3(_t28, 0, _hc3[0]*_t268);
  const double _t274 = _hc0[2]*_t273;
  const double _t275 = _t114*_t115;
  const double _t276 = _hc0[1]*_t275;
  const double _t277 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t278 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t280 = _t277*_t278;
  const double _t281 = _t280*_t33;
  const double _t286 = _hc2[2]*_t121;
  const double _t287 = _t285*_t286;
  const double _t288 = _t131*_t261;
  const double _t292 = _t122*_t51;
  const double _t294 = _t292*_t293;
  const double _t296 = _t219*_t270;
  const double _t297 = _t295*_t296;
  const double _t302 = _t301*_t54;
  const double _t303 = _t117*_t119;
  const double _t305 = _t51*_t80;
  const double _t306 = (0.1e1 / 0.768e3)*_hc0[1]*_hc0[2]*_t115*_t119*_t270*_t271*_t29*_t30*_t31 + (0.1e1 / 0.768e3)*_hc0[1]*_hc2[2]*_t270*_t271*_t29*_t30*_t49*params->task_d + (0.1e1 / 0.768e3)*_hc0[2]*_hc2[1]*_t270*_t271*_t29*_t30*_t49*params->task_d + (0.1e1 / 0.2304e4)*_hc0[3]*_t270*_t271*_t29*_t30*_t31*_t49*params->task_d + (0.1e1 / 0.2304e4)*_hc0[3]*_t270*_t271*params->task_h0x + (0.5e1 / 0.288e3)*_hc1[1]*_t115*_t116*_t270*_t283*_t30*_t31*_t53*params->task_d*tau_s + (0.1e1 / 0.768e3)*_hc2[1]*_t115*_t116*_t119*_t270*_t271*_t29*_t30 + (0.1e1 / 0.2304e4)*_hc2[3]*_t270*_t271*_t29*_t30 - _t109*_t117*_t273 - _t258*_t302 + (0.1e1 / 0.2304e4)*_t270*_t271*_t277*_t278*_t282*_t29*_t30*_t31 + (0.1e1 / 0.1152e4)*_t270*_t271*_t277*_t278*_t29*_t30*_t31*params->task_d - _t274*_t276 - _t279*_t281 - _t287*tau_s - _t288*_t291 - _t294*tau_s - _t297*_t300 - _t302*_t303 - _t304*_t305;
  const double _t307 = my_piecewise3(_t28, 0, _hc3[0]*_t306);
  const double _t308 = _t42*_t60;
  const double _t310 = _t261*_t63;
  const double _t311 = _t246*_t65;
  const double _t312 = _t51*_t65;
  const double _t313 = _t242*_t75;
  const double _t314 = _t139*_t88;
  const double _t321 = _t320*_t42;
  const double _t322 = 0.2e1*_t97;
  const double _t323 = -_t145*_t322 + _t238*_t312 + _t305*_t309*_t63 + _t309*_t310 + _t311*_t88 - _t313 - _t314 - _t321;
  const double _t324 = my_piecewise3(_t28, 0, _hc3[0]*_t323 + _t237*_t60 + _t308*_t88);
  const double _t325 = _t106*_t122;
  const double _t327 = _t106*_t247*tau_s;
  const double _t328 = _t106*_t134;
  const double _t331 = _hc2[1]*_t149;
  const double _t332 = _hc2[2]*_t105;
  const double _t333 = _t150*_t332;
  const double _t334 = (0.1e1 / 0.108e3)*_t93;
  const double _t336 = _t258*_t95;
  const double _t337 = _t117*params->task_d;
  const double _t338 = _t161*_t95;
  const double _t339 = _t106*_t262;
  const double _t340 = _t260*_t339;
  const double _t343 = _t342*_t42;
  const double _t345 = _t139*_t90;
  const double _t346 = _t167*_t97;
  const double _t348 = _t219*_t347;
  const double _t349 = _t145*_t80;
  const double _t350 = _hc2[1]*_t334*_t335*_t51 - _t139*_t344 - _t140*_t96 - _t145*_t236 - _t146*_t96 + _t153*_t333*_t93 + _t160*_t51*_t95 + _t161*_t336 - _t235*_t347 + _t251*_t330 + _t267*_t330 + _t303*_t338 + _t325*_t326 + _t326*_t327 + _t326*_t328 + _t326*_t340 + (0.1e1 / 0.9e1)*_t331*_t93 - _t337*_t338 - _t343 - _t345*_t40 - _t346 - _t348*_t98 - _t349*_t98;
  const double _t351 = my_piecewise3(_t28, 0, _hc3[0]*_t350 - _t60*_t99);
  const double _t353 = _hc0[3]*_t270*params->task_h0x;
  const double _t354 = _t352*_t353;
  const double _t356 = _hc2[3]*_t47;
  const double _t357 = _t270*_t356;
  const double _t358 = _t352*_t357;
  const double _t359 = _t108*_t51;
  const double _t363 = _hc0[2]*_t49;
  const double _t365 = _t117*_t48;
  const double _t368 = _hc0[3]*_t112;
  const double _t371 = _t281*params->task_d;
  const double _t372 = _hc0[1]*_t115;
  const double _t373 = _hc0[2]*_t372;
  const double _t374 = _t120*_t373;
  const double _t375 = _t281*_t282;
  const double _t376 = _t117*_t369;
  const double _t379 = _t378*_t54;
  const double _t380 = _t337*_t379;
  const double _t382 = _t167*_t246;
  const double _t383 = _t381*_t51;
  const double _t384 = _t167*_t80;
  const double _t385 = _t240*_t384;
  const double _t386 = _t257*_t51;
  const double _t388 = _t262*_t387;
  const double _t389 = _t219*_t75;
  const double _t390 = _t133*_t51;
  const double _t391 = _t139*_t53;
  const double _t392 = (0.1e1 / 0.288e3)*_hc0[1]*_hc0[2]*_t115*_t270*_t29*_t30*_t31*_t352*params->task_d*sigma_ss + (0.5e1 / 0.81e2)*_hc0[1]*_hc1[1]*_hc2[1]*_t270*_t271*_t30*_t49*_t53*params->task_d*sigma_ss*tau_s + (0.10e2 / 0.81e2)*_hc0[1]*_hc1[1]*_t102*_t103*_t104*_t30*_t31*_t49*_t53*params->task_d*tau_s + (0.50e2 / 0.243e3)*_hc0[1]*_hc1[2]*_t130*_t270*_t283*_t30*_t31*_t36*_t49*params->task_d*sigma_ss + (0.5e1 / 0.162e3)*_hc0[2]*_hc1[1]*_t270*_t271*_t30*_t31*_t49*_t53*params->task_d*sigma_ss*tau_s + (0.10e2 / 0.81e2)*_hc1[1]*_hc2[1]*_t102*_t103*_t104*_t30*_t53*tau_s + (0.5e1 / 0.162e3)*_hc1[1]*_hc2[2]*_t270*_t271*_t30*_t53*sigma_ss*tau_s + (0.1e1 / 0.576e3)*_hc1[1]*_t102*_t103*_t104*_t115*_t116*_t30*_t31*_t75*params->task_d + (0.5e1 / 0.162e3)*_hc1[1]*_t115*_t116*_t119*_t270*_t271*_t30*_t31*_t53*sigma_ss*tau_s + (0.50e2 / 0.243e3)*_hc1[2]*_hc2[1]*_t130*_t270*_t283*_t30*_t36*sigma_ss + (0.1e1 / 0.288e3)*_hc2[1]*_t115*_t116*_t270*_t29*_t30*_t352*params->task_d*sigma_ss + (0.1e1 / 0.108e3)*_t103*_t104*_t115*_t116*_t150*_t29*_t30*_t31*params->task_d - _t110*_t361*_t363 - _t113*_t369 - _t118*_t119*_t76 + (0.1e1 / 0.288e3)*_t119*_t270*_t277*_t278*_t29*_t30*_t31*_t352*sigma_ss - _t120*_t376 - 0.1e1 / 0.108e3*_t152 - 0.1e1 / 0.108e3*_t155 - _t159*_t364 - _t168*_t383 - _t169*_t255 - _t200*_t386 - _t259*_t76 - _t264*_t389 - _t354*_t355 - _t355*_t358 - _t359*_t362 - _t362*_t374 - _t365*_t366 - _t367*_t368 - _t367*_t375 - _t370*_t371 - _t380*tau_s - _t381*_t382 - _t385*_t53 - _t388*_t53 - _t390*_t391;
  const double _t393 = my_piecewise3(_t28, 0, _hc3[0]*_t392 - _t135*_t60);
  const double _t394 = (0.2e1 / 0.9e1)*_t174;
  const double _t395 = (0.1e1 / 0.36e2)*_t178;
  const double _t396 = _t184*_t332;
  const double _t397 = _t187*_t396;
  const double _t399 = _t198*_t219;
  const double _t400 = _t399*_t41;
  const double _t401 = _t214*_t97;
  const double _t403 = _t139*_t402;
  const double _t409 = _t408*_t42;
  const double _t410 = (0.2e1 / 0.9e1)*_hc0[1]*_hc1[1]*_t145*_t3*_t30*_t31*_t4*_t49*_t62*params->task_d*sigma_ss + (0.2e1 / 0.9e1)*_hc0[1]*_hc1[2]*_t3*_t30*_t31*_t4*_t41*_t49*_t62*_t75*params->task_d*sigma_ss + (0.2e1 / 0.9e1)*_hc1[1]*_hc2[1]*_t145*_t3*_t30*_t4*_t62*sigma_ss + (0.1e1 / 0.81e2)*_hc1[1]*_t103*_t104*_t115*_t116*_t184*_t186*_t30*_t31*_t41*params->task_d + (0.2e1 / 0.9e1)*_hc1[2]*_hc2[1]*_t3*_t30*_t4*_t41*_t62*_t75*sigma_ss - _t137*_t195 - _t138*_t195 - _t196*_t303*_t95 - _t196*_t336 - _t256*_t398 - _t397*_t93 - _t400 - _t401 - _t403 - _t409;
  const double _t411 = my_piecewise3(_t28, 0, _hc3[0]*_t410 - _t147*_t179 - _t394*_t95 - _t395*_t95);
  const double _t412 = (0.1e1 / 0.36e2)*_t55;
  const double _t414 = _t353*_t413;
  const double _t417 = _t357*_t413;
  const double _t421 = _t109*_t420;
  const double _t428 = _hc0[2]*_t276;
  const double _t431 = _t286*_t360;
  const double _t433 = _t431*_t432;
  const double _t434 = _t122*sigma_ss;
  const double _t436 = _t434*_t435;
  const double _t439 = _t292*_t438;
  const double _t441 = _t440*_t54;
  const double _t442 = _t258*_t441;
  const double _t445 = _t337*_t54;
  const double _t446 = _t303*_t441;
  const double _t451 = _t42*_t450;
  const double _t452 = _t169*_t333;
  const double _t454 = _t200*_t51;
  const double _t455 = _t149*_t51;
  const double _t456 = _t158*_t76;
  const double _t460 = _t262*_t459;
  const double _t461 = _t51*tau_s;
  const double _t464 = _t139*_t463;
  const double _t465 = _t214*_t80;
  const double _t466 = _t113*_t427 - _t117*_t421 - _t134*_t444 + _t156*_t452 + _t162*_t427 + _t168*_t201*_t51 + (0.2e1 / 0.9e1)*_t169*_t331 + _t180*_t183 + _t180*_t189 + _t185*_t416 + _t190*_t416 + _t192*_t422 - _t197*_t427 - _t198*_t235 - _t199*_t96 + _t201*_t382 - _t214*_t236 - _t215*_t96 + _t258*_t456 - _t281*_t424 + _t303*_t456 - _t337*_t456 + _t359*_t420 + _t363*_t421 + _t365*_t424 + _t368*_t426 + _t371*_t430 + _t374*_t420 + _t375*_t426 + _t391*_t458*_t461 - _t399*_t98 + _t414*_t415 + _t415*_t417 - _t420*_t428 + _t423*_t52 - _t433*tau_s - _t436*tau_s - _t439*tau_s + _t440*_t445*tau_s - _t442*tau_s - _t446*tau_s - _t451 + _t453*_t454 + (0.2e1 / 0.9e1)*_t455*_t76 + _t458*_t460 - _t464 - _t465*_t98;
  const double _t467 = my_piecewise3(_t28, 0, _hc3[0]*_t466 - _t170*_t179 + _t178*_t412 + _t394*_t55);
  const double _t470 = _hc3[9]*_t468*_t469;
  const double _t471 = _t127*_t58;
  const double _t472 = (0.14e2 / 0.27e2)*_t471;
  const double _t473 = _t177*_t62;
  const double _t474 = (0.1e1 / 0.9e1)*_t473;
  const double _t475 = _hc3[2]*_t27*_t57;
  const double _t477 = _t353*_t476;
  const double _t482 = (0.154e3 / 0.81e2)*_t182;
  const double _t484 = _t151*_t483;
  const double _t486 = _t357*_t476;
  const double _t487 = (0.154e3 / 0.81e2)*_t188;
  const double _t488 = _t154*_t483;
  const double _t493 = _t159*_t492;
  const double _t499 = _t219*_t498;
  const double _t503 = _t169*_t396;
  const double _t507 = _t506*_t76;
  const double _t521 = _t42*_t520;
  const double _t522 = _t139*_t214;
  const double _t527 = _t139*_t526;
  const double _t528 = (0.2e1 / 0.81e2)*_hc0[1]*_hc0[2]*_t115*_t270*_t29*_t30*_t31*_t476*_t478*params->task_d + (0.1e1 / 0.3e1)*_hc0[1]*_hc1[1]*_t214*_t3*_t30*_t31*_t4*_t49*_t62*params->task_d*sigma_ss + (0.1e1 / 0.3e1)*_hc0[1]*_hc1[2]*_t198*_t3*_t30*_t31*_t4*_t49*_t62*params->task_d*sigma_ss + (0.1e1 / 0.3e1)*_hc1[1]*_hc2[1]*_t214*_t3*_t30*_t4*_t62*sigma_ss + (0.1e1 / 0.27e2)*_hc1[1]*_t103*_t104*_t115*_t116*_t184*_t186*_t30*_t31*_t75*params->task_d + (0.1e1 / 0.3e1)*_hc1[2]*_hc2[1]*_t198*_t3*_t30*_t4*_t62*sigma_ss + (0.2e1 / 0.81e2)*_hc2[1]*_t115*_t116*_t270*_t29*_t30*_t476*_t478*params->task_d + (0.11e2 / 0.81e2)*_t103*_t104*_t115*_t116*_t186*_t29*_t30*_t31*_t483*params->task_d - _t109*_t363*_t491 - _t113*_t497 + (0.2e1 / 0.81e2)*_t119*_t270*_t277*_t278*_t29*_t30*_t31*_t476*_t478 - _t162*_t497 - 0.22e2 / 0.81e2*_t186*_t493 - _t200*_t501 - _t202*_t501 - _t258*_t507 - _t303*_t507 - _t359*_t491 - _t365*_t494 - _t368*_t495 - 0.4e1 / 0.243e3*_t371*_t490 - _t374*_t491 - _t375*_t495 - _t454*_t505 - _t477*_t479 - _t479*_t486 - _t481*_t482 - _t481*_t487 - _t484*_t485 - _t485*_t488 - 0.154e3 / 0.81e2*_t496*_t52 - _t499 - _t502*_t503 - _t521 - _t522 - _t527;
  const double _t529 = my_piecewise3(_t28, 0, _hc3[0]*_t528 + (0.2e1 / 0.3e1)*_hc3[2]*_t173*_t25*_t3*_t77 + (0.1e1 / 0.12e2)*_hc3[5]*_t1*_t103*_t176*_t77 - _t175*_t470 - _t216*_t475 - _t34*_t472 - _t34*_t474);
#endif
#if _KMAX >= 4
  const double _t530 = _hc1[4]*_t32;
  const double _t532 = _t220*_t79;
  const double _t534 = _hc1[3]*_t30;
  const double _t535 = _t534*_t94;
  const double _t536 = _t218*_t219;
  const double _t537 = _t227*_t42;
  const double _t541 = _t530*_t98;
  const double _t542 = _t80*_t98;
  const double _t543 = _t235*_t41;
  const double _t544 = _t96*_t97;
  const double _t545 = _t219*_t88;
  const double _t547 = _t219*_t546;
  const double _t550 = _t234*_t255;
  const double _t551 = _t88*_t92;
  const double _t552 = _t261*_t79;
  const double _t553 = _t246*_t88;
  const double _t554 = _t118*_t119;
  const double _t555 = _t261*_t53;
  const double _t557 = _hc2[1]*_t534;
  const double _t558 = _t133*_t53*_t557;
  const double _t559 = _t263*_t53;
  const double _t562 = _t51*_t97;
  const double _t563 = _t530*_t79;
  const double _t564 = _t390*_t53;
  const double _t566 = _t219*_t260;
  const double _t567 = _hc2[2]*_t92;
  const double _t568 = _t549*_t567;
  const double _t570 = _t130*_t262;
  const double _t571 = _t247*_t461;
  const double _t572 = (0.250e3 / 0.81e2)*_t297;
  const double _t573 = _t285*_t54;
  const double _t574 = _t301*_t91;
  const double _t575 = _t248*_t461;
  const double _t576 = _t555*_t565;
  const double _t577 = _t53*_t80;
  const double _t578 = _t51*_t565*_t577;
  const double _t580 = _hc2[3]*_t579;
  const double _t581 = _hc2[2]*_t51;
  const double _t582 = _t273*_t581;
  const double _t583 = _t274*_t50;
  const double _t584 = _t117*_t137;
  const double _t585 = _hc0[3]*_t50;
  const double _t586 = _t579*_t585;
  const double _t587 = _t280*_t95;
  const double _t589 = _t279*_t373;
  const double _t591 = _hc2[2]*_t234;
  const double _t592 = _t301*_t591;
  const double _t593 = _t41*_t557;
  const double _t594 = _t260*_t262;
  const double _t595 = _t293*_t51;
  const double _t596 = _t41*_t530;
  const double _t598 = _t266*_t301;
  const double _t599 = (0.25e2 / 0.108e3)*_t131*_t289*_t296*_t51;
  const double _t604 = _t373*_t603;
  const double _t606 = _t280*_t603;
  const double _t607 = _t119*_t48;
  const double _t608 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t609 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t610 = _t608*_t609;
  const double _t611 = _t114*_t610;
  const double _t612 = ((_hc0[2]) * (_hc0[2]));
  const double _t613 = _t275*_t612;
  const double _t614 = _t33*_t610;
  const double _t616 = _t116*_t277;
  const double _t617 = _hc0[2]*_t616;
  const double _t618 = _hc2[3]*_t121*tau_s;
  const double _t622 = _t131*_t591;
  const double _t629 = _t286*_t461;
  const double _t631 = _t122*_t630;
  const double _t633 = _t288*_t51;
  const double _t634 = _t54*tau_s;
  const double _t635 = _t585*_t634;
  const double _t636 = _t280*_t634;
  const double _t637 = _t636*params->task_d;
  const double _t638 = _t282*_t636;
  const double _t639 = _t219*_t51;
  const double _t640 = _t131*_t80;
  const double _t641 = _t625*_t640;
  const double _t642 = _t60*_t97;
  const double _t645 = _t261*_t41;
  const double _t647 = _t530*_t75;
  const double _t650 = _t161*_t337;
  const double _t652 = _t235*_t75;
  const double _t655 = _t261*_t381;
  const double _t658 = _t91*tau_s;
  const double _t659 = _t378*_t658;
  const double _t661 = _hc2[3]*_t93;
  const double _t662 = _t584*params->task_d;
  const double _t663 = _t585*_t95;
  const double _t664 = _t95*params->task_d;
  const double _t665 = _t373*_t664;
  const double _t666 = _t587*params->task_d;
  const double _t667 = _t373*_t95;
  const double _t668 = _t282*_t587;
  const double _t669 = _t591*tau_s;
  const double _t670 = _t260*_t669;
  const double _t672 = _t51*_t594;
  const double _t673 = _t266*tau_s;
  const double _t674 = _t378*_t673;
  const double _t675 = _t246*_t381;
  const double _t676 = _t125*_t51;
  const double _t677 = _t219*_t459;
  const double _t678 = _t240*_t577;
  const double _t679 = _t167*_t219;
  const double _t680 = _t261*_t347;
  const double _t681 = _t118*params->task_d;
  const double _t682 = _t145*_t246;
  const double _t683 = _t219*_t264;
  const double _t684 = _hc0[4]*_t602*params->task_h0x;
  const double _t688 = _hc2[4]*_t47*_t602;
  const double _t692 = _t356*_t51;
  const double _t696 = _t108*_t258;
  const double _t697 = _hc0[3]*_t109*_t49;
  const double _t698 = _t280*_t693;
  const double _t699 = _hc0[2]*_t33;
  const double _t700 = _t282*_t48;
  const double _t701 = _hc0[4]*_t112;
  const double _t703 = _t114*_t617;
  const double _t704 = _t120*_t372;
  const double _t705 = _t120*_t610;
  const double _t706 = _t614*_t615;
  const double _t707 = _t115*_t120*_t612;
  const double _t708 = _t282*_t616*_t699;
  const double _t709 = _t443*_t54;
  const double _t710 = _t167*_t567;
  const double _t712 = _t382*_t51;
  const double _t713 = _t168*_t711;
  const double _t715 = _t280*_t76;
  const double _t716 = _t557*_t75;
  const double _t717 = _t301*_t391;
  const double _t718 = _t398*_t51;
  const double _t719 = _t195*_t51;
  const double _t720 = _t196*_t258;
  const double _t721 = _t196*_t303;
  const double _t727 = _t440*_t658;
  const double _t728 = _t334*_t429;
  const double _t729 = _hc2[1]*_t728;
  const double _t730 = _t440*_t673;
  const double _t732 = _t219*_t654;
  const double _t740 = _t109*_t363;
  const double _t741 = _t109*_t117;
  const double _t748 = _t373*_t744;
  const double _t749 = _t280*_t744;
  const double _t750 = _t108*_t337;
  const double _t751 = (0.1e1 / 0.648e3)*_t607;
  const double _t752 = _t108*_t303;
  const double _t754 = _hc0[3]*_t745;
  const double _t756 = _t282*_t614;
  const double _t757 = _t120*_t617;
  const double _t766 = (0.5e1 / 0.18e2)*_t361*_t634;
  const double _t769 = _t258*tau_s;
  const double _t770 = _t122*_t768;
  const double _t771 = _t770*tau_s;
  const double _t773 = _t373*params->task_d;
  const double _t774 = _t634*_t768;
  const double _t775 = _t119*_t636;
  const double _t776 = _t640*_t765;
  const double _t777 = _t168*_t453;
  const double _t778 = (0.20e2 / 0.81e2)*_t339;
  const double _t779 = (0.20e2 / 0.81e2)*_t51;
  const double _t780 = _hc2[3]*_t169;
  const double _t782 = _t169*_t581;
  const double _t783 = _t200*_t781;
  const double _t784 = _t200*_t337;
  const double _t785 = _t198*_t261;
  const double _t786 = _t585*_t76;
  const double _t787 = _t76*params->task_d;
  const double _t788 = _t373*_t781;
  const double _t789 = _t364*_t76;
  const double _t790 = _t715*params->task_d;
  const double _t791 = _t119*_t76;
  const double _t792 = _t119*_t715;
  const double _t793 = _t282*_t715;
  const double _t795 = _t391*_t657;
  const double _t796 = _t214*_t246;
  const double _t797 = _t501*_t51;
  const double _t798 = _t140*_t506;
  const double _t799 = _t146*_t506;
  const double _t815 = _t5*_t52;
  const double _t817 = _t280*_t812;
  const double _t821 = _t168*_t506;
  const double _t823 = _t270*_t780;
  const double _t826 = _t200*_t825;
  const double _t827 = _t258*_t76;
  const double _t829 = (0.1e1 / 0.72e2)*_t335*_t337;
  const double _t831 = (0.10e2 / 0.81e2)*_t391*_t437;
  const double _t847 = _t373*_t842;
  const double _t848 = _t280*_t842;
  const double _t849 = (0.8e1 / 0.729e3)*_t607;
  const double _t852 = _hc0[3]*_t843;
  const double _t860 = _t200*_t859;
  const double _t862 = (0.4e1 / 0.27e2)*_t186*_t191*_t51;
  const double _t863 = _t373*_t859;
  const double _t864 = _t51*_t856;
  const double _t865 = _t51*_t857;
  const double _t867 = _t76*_t866;
  const double _t868 = _t258*_t505;
  const double _t869 = _t337*_t505;
  const double _t870 = _t303*_t505;
  const double _t872 = (0.4e1 / 0.9e1)*_t310*_t75;
#endif

  const double f = my_piecewise3(_t28, 0, _t35*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t28, 0, _t44*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = 0;
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t28, 0, _t56*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t28, 0, _t35 + _t78*n_s);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = my_piecewise3(_t28, 0, _t89*n_s);
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = 0;
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = my_piecewise3(_t28, 0, _t100*n_s);
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = 0;
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t28, 0, _t136*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t28, 0, _t148*n_s + _t44);
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = 0;
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t28, 0, _t171*n_s + _t56);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t28, 0, _t217*n_s + 0.2e1*_t78);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = my_piecewise3(_t28, 0, _t230*n_s);
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = 0;
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = my_piecewise3(_t28, 0, _t245*n_s);
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = 0;
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = my_piecewise3(_t28, 0, _t269*n_s);
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = 0;
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t28, 0, _t307*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = my_piecewise3(_t28, 0, _t324*n_s + _t89);
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = 0;
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = my_piecewise3(_t28, 0, _t100 + _t351*n_s);
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = 0;
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t28, 0, _t136 + _t393*n_s);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t28, 0, 0.2e1*_t148 + _t411*n_s);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = 0;
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t28, 0, 0.2e1*_t171 + _t467*n_s);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t28, 0, 0.3e1*_t217 + _t529*n_s);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = my_piecewise3(_t28, 0, n_s*my_piecewise3(_t28, 0, -_hc3[0]*(_t41 * _t41 * _t41 * _t41)*_t530 - 0.2e1*_t227*_t228 - _t228*((0.10e2 / 0.3e1)*_t221 + _t226*_t240) - _t229*_t532 - _t229*_t81*_t88 - _t43*(_t226*_t531 + _t40*my_piecewise3(_t14, -0.24e2*_t224 + 0.3e1*_t86/xc_powi(tau_s, 5), 0)) - _t532*_t88 - _t532*(_t222*tau_s + (0.10e2 / 0.3e1)*_t82) - _t81*(_t88 * _t88)));
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = 0;
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = 0;
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = 0;
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = 0;
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = my_piecewise3(_t28, 0, n_s*my_piecewise3(_t28, 0, _hc3[0]*(-0.10e2 / 0.3e1*_t21*_t241 - _t218*_t535 - _t218*_t541 - _t227*_t236 - _t227*_t542 - _t229*_t543 - _t229*_t544 - _t229*_t547 - _t232*_t538*_t97 - _t233*_t533 - _t242*_t539 - _t242*_t540 - _t243*_t539 - _t243*_t540 - _t40*_t42*my_piecewise3(_t14, _t11*_t225, 0) - _t536*_t96 - _t537*_t96 - _t543*_t88 - _t544*_t88 - _t545*_t546)));
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = 0;
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = my_piecewise3(_t28, 0, n_s*my_piecewise3(_t28, 0, _hc3[0]*((0.1e1 / 0.576e3)*_hc1[1]*_t102*_t103*_t104*_t115*_t116*_t30*_t31*_t88*params->task_d + (0.1e1 / 0.576e3)*_hc1[2]*_t102*_t103*_t104*_t115*_t116*_t30*_t31*_t79*params->task_d - 0.200e3 / 0.81e2*_t129*_t53*_t549 - _t133*_t232*_t246 - _t232*_t254 - _t233*_t390 - _t237*_t259 - _t237*_t554 - _t238*_t259 - _t238*_t554 - _t242*_t564 - _t243*_t564 - _t247*_t548 - _t250 - _t251*_t548 - _t253*(_t90 * _t90) - _t255*_t551 - _t262*_t556*_t90 - _t264*_t545 - _t264*_t563 - _t265*_t560*_t561 - _t267*_t548 - _t386*_t552 - _t386*_t553 - _t548*_t549*_t562 - _t550*_t79 - _t555*_t556 - _t558*_t79 - _t559*_t88 - _t561*_t565*_t566)));
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = 0;
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = my_piecewise3(_t28, 0, n_s*my_piecewise3(_t28, 0, _hc3[0]*((0.1e1 / 0.768e3)*_hc0[1]*_hc0[2]*_hc1[1]*_t115*_t270*_t271*_t30*_t31*_t41*params->task_d + (0.1e1 / 0.768e3)*_hc1[1]*_hc2[1]*_t115*_t116*_t270*_t271*_t30*_t41*params->task_d + (0.5e1 / 0.288e3)*_hc1[1]*_t115*_t116*_t270*_t283*_t30*_t31*_t53*params->task_d + (0.5e1 / 0.288e3)*_hc1[1]*_t115*_t116*_t270*_t283*_t30*_t31*_t90*params->task_d*tau_s + (0.1e1 / 0.768e3)*_hc1[1]*_t119*_t270*_t271*_t277*_t278*_t30*_t31*_t41 + (0.5e1 / 0.288e3)*_hc1[2]*_t115*_t116*_t270*_t283*_t30*_t31*_t41*_t53*params->task_d*tau_s - _t117*_t119*_t573 - _t130*_t572*_t83*_t90 - _t137*_t583 - _t258*_t573 - _t258*_t574 - _t258*_t598 - _t260*_t592 - _t279*_t584 - _t285*_t568 - _t287 - _t293*_t571 - _t294 - _t298*_t36*_t572 - _t303*_t574 - _t303*_t598 - _t304*_t593 - _t41*_t599 - _t569*_t570 - _t569*_t575 - _t569*_t576 - _t569*_t578 - _t580*_t93 - _t582*_t93 - _t586*_t95 - _t587*_t588 - _t587*_t590 - _t589*_t95 - _t594*_t595 - _t596*_t597)));
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = 0;
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t28, 0, n_s*my_piecewise3(_t28, 0, _hc3[0]*((0.5e1 / 0.1728e4)*_hc0[1]*_hc0[2]*_hc1[1]*_t115*_t3*_t30*_t31*_t53*_t600*_t619*params->task_d*tau_s + (0.1e1 / 0.4608e4)*_hc0[1]*_hc0[2]*_hc2[1]*_t115*_t119*_t29*_t3*_t30*_t600*_t601 + (0.1e1 / 0.13824e5)*_hc0[1]*_hc0[3]*_t115*_t119*_t29*_t3*_t30*_t31*_t600*_t601 + (0.1e1 / 0.13824e5)*_hc0[1]*_hc2[3]*_t29*_t3*_t30*_t49*_t600*_t601*params->task_d + (0.1e1 / 0.9216e4)*_hc0[2]*_hc2[2]*_t29*_t3*_t30*_t49*_t600*_t601*params->task_d + (0.1e1 / 0.9216e4)*_hc0[2]*_t116*_t277*_t282*_t29*_t3*_t30*_t31*_t600*_t601 + (0.1e1 / 0.4608e4)*_hc0[2]*_t116*_t277*_t29*_t3*_t30*_t31*_t600*_t601*params->task_d + (0.1e1 / 0.13824e5)*_hc0[3]*_hc2[1]*_t29*_t3*_t30*_t49*_t600*_t601*params->task_d - 0.1e1 / 0.13824e5*_hc0[3]*_t276*_t603 + (0.1e1 / 0.55296e5)*_hc0[4]*_t29*_t3*_t30*_t31*_t49*_t600*_t601*params->task_d + (0.1e1 / 0.55296e5)*_hc0[4]*_t3*_t600*_t601*params->task_h0x + (0.5e1 / 0.1728e4)*_hc1[1]*_hc2[1]*_t115*_t116*_t3*_t30*_t53*_t600*_t619*params->task_d*tau_s + (0.5e1 / 0.1728e4)*_hc1[1]*_t119*_t277*_t278*_t3*_t30*_t31*_t53*_t600*_t619*tau_s + (0.25e2 / 0.1296e4)*_hc1[2]*_t115*_t116*_t130*_t3*_t30*_t31*_t36*_t600*_t623*params->task_d + (0.1e1 / 0.13824e5)*_hc2[1]*_t277*_t278*_t282*_t29*_t3*_t30*_t600*_t601 + (0.1e1 / 0.6912e4)*_hc2[1]*_t277*_t278*_t29*_t3*_t30*_t600*_t601*params->task_d + (0.1e1 / 0.9216e4)*_hc2[2]*_t115*_t116*_t119*_t29*_t3*_t30*_t600*_t601 + (0.1e1 / 0.55296e5)*_hc2[4]*_t29*_t3*_t30*_t600*_t601 - _t108*_t337*_t605 - 0.1e1 / 0.4608e4*_t109*_t604 + (0.1e1 / 0.18432e5)*_t115*_t119*_t29*_t3*_t30*_t31*_t600*_t601*_t612 + (0.11e2 / 0.55296e5)*_t119*_t29*_t3*_t30*_t31*_t600*_t601*_t608*_t609 - _t119*_t373*_t54*_t630 - 0.1e1 / 0.3072e4*_t120*_t603*_t617 - 0.1250e4 / 0.2187e4*_t223*(_t53 * _t53 * _t53 * _t53)*_t530*_t602*_t632 - _t258*_t631 - _t258*_t641 - _t282*_t605*_t614 + (0.1e1 / 0.55296e5)*_t29*_t3*_t30*_t31*_t600*_t601*_t608*_t609*_t615 - _t303*_t631 - _t303*_t641 - _t557*_t626*_t627 - 0.1e1 / 0.18432e5*_t603*_t613 - _t605*_t611 - 0.1e1 / 0.4608e4*_t606*_t607 - _t618*_t621 - 0.5e1 / 0.2592e4*_t620*_t637 - _t621*_t635 - _t621*_t638 - _t622*_t625 - 0.25e2 / 0.648e3*_t624*_t633 - _t626*_t627*_t639 - _t628*_t629)));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = my_piecewise3(_t28, 0, _t230 + n_s*my_piecewise3(_t28, 0, _hc3[0]*(-_t139*_t227 - _t218*_t647 + _t227*_t311 - _t229*_t348 - _t242*_t649 - _t243*_t649 + _t312*_t537 - 0.3e1*_t320*_t97 - _t347*_t545 - _t42*(-_t143*_t226 + _t319*_t533 + _t40*my_piecewise3(_t14, -0.5e1 / 0.4e1*_t17*_t224*_t69 - _t225*_t318, 0) - _t648*_t87) + _t557*_t643 + _t562*_t644 + _t562*_t646 + _t639*_t643 + _t644*_t645 + _t645*_t646) + _t227*_t308 + _t229*_t642 + _t536*_t60 + _t642*_t88));
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = 0;
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = my_piecewise3(_t28, 0, _t245 + n_s*my_piecewise3(_t28, 0, _hc3[0]*((0.1e1 / 0.108e3)*_hc0[1]*_hc1[1]*_hc2[1]*_t103*_t104*_t150*_t30*_t49*_t88*params->task_d*sigma_ss + (0.5e1 / 0.81e2)*_hc0[1]*_hc1[1]*_t102*_t103*_t104*_t232*_t30*_t31*_t49*params->task_d*sigma_ss*tau_s + (0.10e2 / 0.81e2)*_hc0[1]*_hc1[1]*_t102*_t103*_t104*_t30*_t31*_t49*_t90*params->task_d*sigma_ss + (0.1e1 / 0.9e1)*_hc0[1]*_hc1[1]*_t3*_t30*_t31*_t4*_t49*_t62*_t88*params->task_d + (0.1e1 / 0.108e3)*_hc0[1]*_hc1[2]*_hc2[1]*_t103*_t104*_t150*_t30*_t49*_t79*params->task_d*sigma_ss + (0.10e2 / 0.81e2)*_hc0[1]*_hc1[2]*_t102*_t103*_t104*_t30*_t31*_t41*_t49*_t53*params->task_d*sigma_ss + (0.10e2 / 0.81e2)*_hc0[1]*_hc1[2]*_t102*_t103*_t104*_t30*_t31*_t41*_t49*_t90*params->task_d*sigma_ss*tau_s + (0.5e1 / 0.81e2)*_hc0[1]*_hc1[2]*_t102*_t103*_t104*_t30*_t31*_t49*_t53*_t88*params->task_d*sigma_ss*tau_s + (0.1e1 / 0.9e1)*_hc0[1]*_hc1[2]*_t3*_t30*_t31*_t4*_t49*_t62*_t79*params->task_d + (0.5e1 / 0.81e2)*_hc0[1]*_hc1[3]*_t102*_t103*_t104*_t30*_t31*_t49*_t53*_t79*params->task_d*sigma_ss*tau_s + (0.1e1 / 0.216e3)*_hc0[2]*_hc1[1]*_t103*_t104*_t150*_t30*_t31*_t49*_t88*params->task_d*sigma_ss + (0.1e1 / 0.216e3)*_hc0[2]*_hc1[2]*_t103*_t104*_t150*_t30*_t31*_t49*_t79*params->task_d*sigma_ss + (0.5e1 / 0.81e2)*_hc1[1]*_hc2[1]*_t102*_t103*_t104*_t232*_t30*sigma_ss*tau_s + (0.10e2 / 0.81e2)*_hc1[1]*_hc2[1]*_t102*_t103*_t104*_t30*_t90*sigma_ss + (0.1e1 / 0.9e1)*_hc1[1]*_hc2[1]*_t3*_t30*_t4*_t62*_t88 + (0.1e1 / 0.216e3)*_hc1[1]*_hc2[2]*_t103*_t104*_t150*_t30*_t88*sigma_ss + (0.1e1 / 0.216e3)*_hc1[1]*_t103*_t104*_t115*_t116*_t119*_t150*_t30*_t31*_t88*sigma_ss + (0.10e2 / 0.81e2)*_hc1[2]*_hc2[1]*_t102*_t103*_t104*_t30*_t41*_t53*sigma_ss + (0.10e2 / 0.81e2)*_hc1[2]*_hc2[1]*_t102*_t103*_t104*_t30*_t41*_t90*sigma_ss*tau_s + (0.5e1 / 0.81e2)*_hc1[2]*_hc2[1]*_t102*_t103*_t104*_t30*_t53*_t88*sigma_ss*tau_s + (0.1e1 / 0.9e1)*_hc1[2]*_hc2[1]*_t3*_t30*_t4*_t62*_t79 + (0.1e1 / 0.216e3)*_hc1[2]*_hc2[2]*_t103*_t104*_t150*_t30*_t79*sigma_ss + (0.1e1 / 0.216e3)*_hc1[2]*_t103*_t104*_t115*_t116*_t119*_t150*_t30*_t31*_t79*sigma_ss + (0.5e1 / 0.81e2)*_hc1[3]*_hc2[1]*_t102*_t103*_t104*_t30*_t53*_t79*sigma_ss*tau_s - _t139*_t232*_t40 - _t145*_t240*_t566 - _t145*_t383*_t97 - _t145*_t41*_t655 - _t167*_t242 - _t167*_t243 - _t231*_t345 - _t236*_t320 - _t237*_t650 - _t238*_t650 - _t239*_t348 - _t239*_t349 - _t313*_t96 - _t314*_t96 - _t320*_t542 - _t321*_t96 - _t322*_t342 - _t348*_t653 - _t349*_t653 - _t42*(-_t143*_t232 - _t315*_t90 + _t40*my_piecewise3(_t14, _t163*_t85, 0) + _t651) - _t535*_t75*_t79 - _t545*_t654 - _t647*_t79*_t98 - _t652*_t88) - _t244*_t60));
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = 0;
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = my_piecewise3(_t28, 0, _t269 + n_s*my_piecewise3(_t28, 0, _hc3[0]*(_t119*_t376*_t95 + _t137*_t258*_t362 - _t139*_t549*_t676 - _t140*_t259 - _t140*_t554 + _t140*_t681 - _t145*_t255*_t92 - _t145*_t559 - _t145*_t683 - _t146*_t259 - _t146*_t554 + _t146*_t681 - _t167*_t41*_t655 - _t239*_t384 - _t240*_t260*_t679 + _t247*_t51*_t657 - _t249*_t389*_t560 + _t251*_t660*tau_s - _t252*_t677*_t90 + _t256*_t364 + _t258*_t379 + _t258*_t659 + _t258*_t674 - _t264*_t41*_t647 + _t265*_t51*_t671 + _t266*_t461*_t660 + _t272*_t286*_t377 + _t272*_t292*_t326 + _t272*_t326*_t672 + _t303*_t379 + _t303*_t659 + _t303*_t674 + (0.10e2 / 0.81e2)*_t325 + (0.10e2 / 0.81e2)*_t327 + (0.10e2 / 0.81e2)*_t328 + _t333*_t334 + _t336*_t369 - _t337*_t659 - _t337*_t674 + (0.10e2 / 0.81e2)*_t340 - _t342*_t675 - _t342*_t678 - _t343*_t383 - _t346*_t383 - _t347*_t550 - _t347*_t558 - _t348*_t564 - _t349*_t564 + _t362*_t581*_t93 - _t362*_t662 - _t362*_t665 + _t366*_t584 - _t366*_t587 + _t366*_t667 + _t367*_t661 + _t367*_t663 + _t367*_t668 + _t370*_t666 - _t376*_t664 + _t378*_t568 + _t378*_t670 - _t380 - _t385*_t90 - _t386*_t680 - _t386*_t682 - _t387*_t555 - _t388*_t90 - _t391*_t676 + _t570*_t656 + _t575*_t656 + _t576*_t656 + _t578*_t656 + _t593*_t671) - _t268*_t60));
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = 0;
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t28, 0, _t307 + n_s*my_piecewise3(_t28, 0, _hc3[0]*((0.5e1 / 0.864e3)*_hc0[1]*_hc0[2]*_hc1[1]*_t115*_t119*_t3*_t30*_t31*_t53*_t600*_t601*sigma_ss*tau_s + (0.1e1 / 0.768e3)*_hc0[1]*_hc0[2]*_hc1[1]*_t115*_t270*_t271*_t30*_t31*_t75*params->task_d + (0.1e1 / 0.1728e4)*_hc0[1]*_hc0[2]*_hc2[1]*_t115*_t29*_t3*_t30*_t600*_t685*params->task_d*sigma_ss + (0.1e1 / 0.96e2)*_hc0[1]*_hc0[2]*_t115*_t270*_t29*_t30*_t31*_t352*params->task_d + (0.1e1 / 0.5184e4)*_hc0[1]*_hc0[3]*_t115*_t29*_t3*_t30*_t31*_t600*_t685*params->task_d*sigma_ss + (0.5e1 / 0.27e2)*_hc0[1]*_hc1[1]*_hc2[1]*_t270*_t271*_t30*_t49*_t53*params->task_d*tau_s + (0.5e1 / 0.864e3)*_hc0[1]*_hc1[1]*_hc2[2]*_t3*_t30*_t49*_t53*_t600*_t601*params->task_d*sigma_ss*tau_s + (0.25e2 / 0.486e3)*_hc0[1]*_hc1[2]*_hc2[1]*_t130*_t3*_t30*_t36*_t49*_t600*_t619*params->task_d*sigma_ss + (0.50e2 / 0.81e2)*_hc0[1]*_hc1[2]*_t130*_t270*_t283*_t30*_t31*_t36*_t49*params->task_d + (0.250e3 / 0.2187e4)*_hc0[1]*_hc1[3]*_t298*_t3*_t30*_t31*_t49*_t600*_t623*_t83*params->task_d*sigma_ss + (0.5e1 / 0.864e3)*_hc0[2]*_hc1[1]*_hc2[1]*_t3*_t30*_t49*_t53*_t600*_t601*params->task_d*sigma_ss*tau_s + (0.5e1 / 0.54e2)*_hc0[2]*_hc1[1]*_t270*_t271*_t30*_t31*_t49*_t53*params->task_d*tau_s + (0.25e2 / 0.972e3)*_hc0[2]*_hc1[2]*_t130*_t3*_t30*_t31*_t36*_t49*_t600*_t619*params->task_d*sigma_ss + (0.1e1 / 0.1152e4)*_hc0[2]*_t116*_t119*_t277*_t29*_t3*_t30*_t31*_t600*_t685*sigma_ss + (0.5e1 / 0.2592e4)*_hc0[3]*_hc1[1]*_t3*_t30*_t31*_t49*_t53*_t600*_t601*params->task_d*sigma_ss*tau_s - _hc0[3]*_t694*_t704 + (0.5e1 / 0.864e3)*_hc1[1]*_hc2[1]*_t115*_t116*_t119*_t3*_t30*_t53*_t600*_t601*sigma_ss*tau_s + (0.1e1 / 0.768e3)*_hc1[1]*_hc2[1]*_t115*_t116*_t270*_t271*_t30*_t75*params->task_d + (0.5e1 / 0.54e2)*_hc1[1]*_hc2[2]*_t270*_t271*_t30*_t53*tau_s + (0.5e1 / 0.2592e4)*_hc1[1]*_hc2[3]*_t3*_t30*_t53*_t600*_t601*sigma_ss*tau_s + (0.1e1 / 0.192e3)*_hc1[1]*_t102*_t103*_t104*_t115*_t116*_t167*_t30*_t31*params->task_d + (0.5e1 / 0.54e2)*_hc1[1]*_t115*_t116*_t119*_t270*_t271*_t30*_t31*_t53*tau_s + (0.1e1 / 0.768e3)*_hc1[1]*_t119*_t270*_t271*_t277*_t278*_t30*_t31*_t75 + (0.5e1 / 0.2592e4)*_hc1[1]*_t277*_t278*_t282*_t3*_t30*_t31*_t53*_t600*_t601*sigma_ss*tau_s + (0.5e1 / 0.1296e4)*_hc1[1]*_t277*_t278*_t3*_t30*_t31*_t53*_t600*_t601*params->task_d*sigma_ss*tau_s + (0.50e2 / 0.81e2)*_hc1[2]*_hc2[1]*_t130*_t270*_t283*_t30*_t36 + (0.25e2 / 0.972e3)*_hc1[2]*_hc2[2]*_t130*_t3*_t30*_t36*_t600*_t619*sigma_ss + (0.25e2 / 0.972e3)*_hc1[2]*_t115*_t116*_t119*_t130*_t3*_t30*_t31*_t36*_t600*_t619*sigma_ss + (0.5e1 / 0.288e3)*_hc1[2]*_t115*_t116*_t270*_t283*_t30*_t31*_t53*_t75*params->task_d*tau_s + (0.250e3 / 0.2187e4)*_hc1[3]*_hc2[1]*_t298*_t3*_t30*_t600*_t623*_t83*sigma_ss + (0.1e1 / 0.96e2)*_hc2[1]*_t115*_t116*_t270*_t29*_t30*_t352*params->task_d + (0.1e1 / 0.1728e4)*_hc2[1]*_t119*_t277*_t278*_t29*_t3*_t30*_t600*_t685*sigma_ss + (0.1e1 / 0.3456e4)*_hc2[2]*_t115*_t116*_t29*_t3*_t30*_t600*_t685*params->task_d*sigma_ss - 0.1e1 / 0.96e2*_t106*_t712 - _t108*_t303*_t695 - _t109*_t363*_t689 - 0.1e1 / 0.2592e4*_t109*_t698 + (0.1e1 / 0.6912e4)*_t115*_t29*_t3*_t30*_t31*_t600*_t612*_t685*params->task_d*sigma_ss - _t117*_t200*_t279 + (0.1e1 / 0.96e2)*_t119*_t270*_t277*_t278*_t29*_t30*_t31*_t352 - 0.5e1 / 0.864e3*_t119*_t606*_t709 - 0.25e2 / 0.27e2*_t128*_t131*_t679 - _t167*_t262*_t53*_t714 - _t169*_t580 - _t169*_t582 - _t200*_t583 - _t258*_t713 - _t258*_t717 - 0.5e1 / 0.54e2*_t272*_t445*tau_s + (0.1e1 / 0.3456e4)*_t282*_t29*_t3*_t30*_t31*_t600*_t608*_t609*_t685*sigma_ss + (0.1e1 / 0.3456e4)*_t29*_t3*_t30*_t31*_t600*_t608*_t609*_t685*params->task_d*sigma_ss - _t303*_t713 - _t303*_t717 - _t304*_t716 - 0.5e1 / 0.864e3*_t337*_t434*_t603*tau_s - 0.25e2 / 0.972e3*_t337*_t620*_t640*sigma_ss - 0.1e1 / 0.288e3*_t354 - 0.1e1 / 0.288e3*_t358 - _t359*_t689 - 0.1e1 / 0.144e3*_t360*_t371 - _t365*_t690 - _t368*_t691 - _t372*_t690*_t699 - 0.1e1 / 0.1728e4*_t373*_t607*_t693 - _t375*_t691 - _t384*_t461*_t53*_t714 - _t459*_t592 - _t460*_t595 - _t586*_t76 - _t588*_t715 - _t589*_t76 - _t590*_t715 - _t597*_t647 - _t599*_t75 - 0.5e1 / 0.864e3*_t604*_t709*params->task_d - _t684*_t687 - _t687*_t688 - _t692*_t694 - 0.1e1 / 0.1728e4*_t693*_t703 - 0.11e2 / 0.20736e5*_t693*_t705 - 0.1e1 / 0.6912e4*_t693*_t707 - _t694*_t697 - _t695*_t696 - _t695*_t708 - 0.1e1 / 0.5184e4*_t698*_t700 - _t701*_t702 - _t702*_t706 - _t710*_t711) - _t306*_t60));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = my_piecewise3(_t28, 0, 0.2e1*_t324 + n_s*my_piecewise3(_t28, 0, _hc3[0]*((0.2e1 / 0.9e1)*_hc0[1]*_hc1[1]*_t3*_t30*_t31*_t320*_t4*_t49*_t62*params->task_d*sigma_ss + (0.4e1 / 0.9e1)*_hc0[1]*_hc1[2]*_t145*_t3*_t30*_t31*_t4*_t41*_t49*_t62*params->task_d*sigma_ss + (0.2e1 / 0.9e1)*_hc0[1]*_hc1[2]*_t3*_t30*_t31*_t4*_t49*_t62*_t75*_t88*params->task_d*sigma_ss + (0.2e1 / 0.9e1)*_hc0[1]*_hc1[3]*_t3*_t30*_t31*_t4*_t49*_t62*_t75*_t79*params->task_d*sigma_ss + (0.2e1 / 0.9e1)*_hc1[1]*_hc2[1]*_t3*_t30*_t320*_t4*_t62*sigma_ss + (0.1e1 / 0.81e2)*_hc1[1]*_t103*_t104*_t115*_t116*_t184*_t186*_t30*_t31*_t88*params->task_d + (0.4e1 / 0.9e1)*_hc1[2]*_hc2[1]*_t145*_t3*_t30*_t4*_t41*_t62*sigma_ss + (0.2e1 / 0.9e1)*_hc1[2]*_hc2[1]*_t3*_t30*_t4*_t62*_t75*_t88*sigma_ss + (0.1e1 / 0.81e2)*_hc1[2]*_t103*_t104*_t115*_t116*_t184*_t186*_t30*_t31*_t79*params->task_d + (0.2e1 / 0.9e1)*_hc1[3]*_hc2[1]*_t3*_t30*_t4*_t62*_t75*_t79*sigma_ss - _t139*(_t144*_t531 - _t206*_t87 + _t240*_t319 - _t39*_t722) - _t195*_t552 - _t195*_t553 - _t198*_t563 - _t214*_t242 - _t214*_t243 - _t234*_t397*_t79 - _t237*_t719 - _t237*_t720 - _t237*_t721 - _t238*_t719 - _t238*_t720 - _t238*_t721 - _t322*_t408 - 0.2e1*_t348*_t402 - _t349*_t402 - _t397*_t551 - _t399*_t88 - _t42*(-_t144*_t722 - _t206*_t319 + _t39*_t723 + _t40*my_piecewise3(_t14, _t15*_t210*_t85 + (0.5e1 / 0.18e2)*_t24*_t317 + _t71*_t725*_t84, 0) + _t405*_t87 + _t724) - _t552*_t718 - _t553*_t718) - _t179*_t323 - _t237*_t394 - _t237*_t395 - _t238*_t394 - _t238*_t395));
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = 0;
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = my_piecewise3(_t28, 0, 0.2e1*_t351 + n_s*my_piecewise3(_t28, 0, _hc3[0]*((0.1e1 / 0.108e3)*_hc0[1]*_hc0[2]*_hc1[1]*_t115*_t186*_t270*_t30*_t31*_t41*_t413*params->task_d + (0.1e1 / 0.54e2)*_hc0[1]*_hc1[1]*_hc2[1]*_t103*_t104*_t145*_t150*_t30*_t49*params->task_d*sigma_ss + (0.2e1 / 0.9e1)*_hc0[1]*_hc1[1]*_t145*_t3*_t30*_t31*_t4*_t49*_t62*params->task_d + (0.2e1 / 0.9e1)*_hc0[1]*_hc1[1]*_t3*_t30*_t31*_t342*_t4*_t49*_t62*params->task_d*sigma_ss + (0.1e1 / 0.54e2)*_hc0[1]*_hc1[2]*_hc2[1]*_t103*_t104*_t150*_t30*_t41*_t49*_t75*params->task_d*sigma_ss + (0.10e2 / 0.81e2)*_hc0[1]*_hc1[2]*_t102*_t103*_t104*_t145*_t30*_t31*_t49*_t53*params->task_d*sigma_ss*tau_s + (0.10e2 / 0.81e2)*_hc0[1]*_hc1[2]*_t102*_t103*_t104*_t30*_t31*_t49*_t53*_t75*params->task_d*sigma_ss + (0.10e2 / 0.81e2)*_hc0[1]*_hc1[2]*_t102*_t103*_t104*_t30*_t31*_t49*_t75*_t90*params->task_d*sigma_ss*tau_s + (0.2e1 / 0.9e1)*_hc0[1]*_hc1[2]*_t167*_t3*_t30*_t31*_t4*_t41*_t49*_t62*params->task_d*sigma_ss + (0.2e1 / 0.9e1)*_hc0[1]*_hc1[2]*_t3*_t30*_t31*_t4*_t41*_t49*_t62*_t75*params->task_d + (0.10e2 / 0.81e2)*_hc0[1]*_hc1[3]*_t102*_t103*_t104*_t30*_t31*_t41*_t49*_t53*_t75*params->task_d*sigma_ss*tau_s + (0.1e1 / 0.108e3)*_hc0[2]*_hc1[1]*_t103*_t104*_t145*_t150*_t30*_t31*_t49*params->task_d*sigma_ss + (0.1e1 / 0.108e3)*_hc0[2]*_hc1[2]*_t103*_t104*_t150*_t30*_t31*_t41*_t49*_t75*params->task_d*sigma_ss + (0.1e1 / 0.108e3)*_hc1[1]*_hc2[1]*_t115*_t116*_t186*_t270*_t30*_t41*_t413*params->task_d + (0.2e1 / 0.9e1)*_hc1[1]*_hc2[1]*_t145*_t3*_t30*_t4*_t62 + (0.2e1 / 0.9e1)*_hc1[1]*_hc2[1]*_t3*_t30*_t342*_t4*_t62*sigma_ss + (0.1e1 / 0.108e3)*_hc1[1]*_hc2[2]*_t103*_t104*_t145*_t150*_t30*sigma_ss + (0.1e1 / 0.108e3)*_hc1[1]*_t103*_t104*_t115*_t116*_t119*_t145*_t150*_t30*_t31*sigma_ss + (0.1e1 / 0.24e2)*_hc1[1]*_t103*_t104*_t115*_t116*_t184*_t30*_t31*_t41*params->task_d*sigma_ss + (0.10e2 / 0.243e3)*_hc1[1]*_t115*_t116*_t186*_t270*_t30*_t31*_t352*_t53*params->task_d + (0.10e2 / 0.243e3)*_hc1[1]*_t115*_t116*_t186*_t270*_t30*_t31*_t352*_t90*params->task_d*tau_s + (0.1e1 / 0.108e3)*_hc1[1]*_t119*_t186*_t270*_t277*_t278*_t30*_t31*_t41*_t413 + (0.10e2 / 0.81e2)*_hc1[2]*_hc2[1]*_t102*_t103*_t104*_t145*_t30*_t53*sigma_ss*tau_s + (0.10e2 / 0.81e2)*_hc1[2]*_hc2[1]*_t102*_t103*_t104*_t30*_t53*_t75*sigma_ss + (0.10e2 / 0.81e2)*_hc1[2]*_hc2[1]*_t102*_t103*_t104*_t30*_t75*_t90*sigma_ss*tau_s + (0.2e1 / 0.9e1)*_hc1[2]*_hc2[1]*_t167*_t3*_t30*_t4*_t41*_t62*sigma_ss + (0.2e1 / 0.9e1)*_hc1[2]*_hc2[1]*_t3*_t30*_t4*_t41*_t62*_t75 + (0.1e1 / 0.108e3)*_hc1[2]*_hc2[2]*_t103*_t104*_t150*_t30*_t41*_t75*sigma_ss + (0.1e1 / 0.108e3)*_hc1[2]*_t103*_t104*_t115*_t116*_t119*_t150*_t30*_t31*_t41*_t75*sigma_ss + (0.10e2 / 0.243e3)*_hc1[2]*_t115*_t116*_t186*_t270*_t30*_t31*_t352*_t41*_t53*params->task_d*tau_s + (0.10e2 / 0.81e2)*_hc1[3]*_hc2[1]*_t102*_t103*_t104*_t30*_t41*_t53*_t75*sigma_ss*tau_s - _t134*_t726 - _t137*_t423 - _t138*_t423 - _t139*(-_t206*_t90 - _t315*_t53 + _t462 + _t651*tau_s) - _t140*_t158*_t337 - _t146*_t158*_t337 - _t191*_t256*_t422 - _t198*_t41*_t535 - _t198*_t596*_t98 - _t214*_t543 - _t214*_t547 - _t236*_t408 - _t247*_t444 - _t251*_t444 - _t258*_t727 - _t258*_t729 - _t258*_t730 - _t267*_t444 - _t270*_t425*_t661 - _t303*_t427*_t95 - _t303*_t727 - _t303*_t729 - _t303*_t730 - _t336*_t427 - _t344*_t399 - _t344*_t465 - _t348*_t463 - _t349*_t463 - _t396*_t416*_t93 - _t399*_t731 - _t400*_t96 - _t401*_t96 - _t402*_t652 - _t402*_t732 - _t403*_t96 - _t408*_t542 - _t409*_t96 - _t42*(-_t165*_t315 - _t206*_t341 + _t40*my_piecewise3(_t14, _t37*_t447, 0) + _t404*_t53 + _t405*_t90 + _t449) - _t424*_t667 - _t426*_t663 - _t426*_t668 - _t430*_t666 - _t433 - _t436 - _t438*_t571 - _t438*_t672 - _t439 - _t440*_t568 - _t440*_t670 - _t442 - _t446 - _t450*_t97 - _t465*_t731 - _t581*_t728 - _t594*_t726) - _t179*_t350 + _t394*_t99 + _t395*_t99));
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = 0;
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t28, 0, 0.2e1*_t393 + n_s*my_piecewise3(_t28, 0, _hc3[0]*(_t106*_t384*_t443*_t53*_t779 + (0.20e2 / 0.81e2)*_t106*_t391*_t461 - 0.1e1 / 0.648e3*_t109*_t748 + (0.1e1 / 0.972e3)*_t109*_t749 + _t113*_t747 - _t119*_t373*_t774 - _t122*_t759 - _t131*_t305*_t760*sigma_ss - _t134*_t759 + _t153*_t360*_t790 + (0.1e1 / 0.27e2)*_t157*_t454 + _t162*_t747 + (0.4e1 / 0.9e1)*_t167*_t331*_t92 + _t167*_t53*_t778*sigma_ss + (0.4e1 / 0.9e1)*_t168*_t455 + (0.19e2 / 0.324e3)*_t185 + (0.19e2 / 0.324e3)*_t190 + (0.19e2 / 0.162e3)*_t192 - _t197*_t747 - _t198*_t264*_t530 - _t198*_t550 - _t198*_t558 - _t199*_t259 - _t199*_t554 + _t199*_t681 - _t214*_t255*_t92 - _t214*_t559 - _t214*_t683 - _t215*_t259 - _t215*_t554 + _t215*_t681 - _t240*_t463*_t677 - _t258*_t766 - _t258*_t776 + _t258*_t777 + _t258*_t783 + _t258*_t789 + _t258*_t795 + _t272*_t457*_t460*_t51 - _t276*_t754 - _t281*_t742 - _t288*_t760*sigma_ss - 0.5e1 / 0.9e1*_t292*_t763 - _t303*_t766 - _t303*_t771 - _t303*_t776 + _t303*_t777 + _t303*_t783 + _t303*_t789 + _t303*_t795 + (0.1e1 / 0.27e2)*_t335*_t712 + _t337*_t771 + _t337*_t776 - _t337*_t777 - _t337*_t789 - _t337*_t795 + _t359*_t739 + _t365*_t742 + _t368*_t743 + _t370*_t780 + _t370*_t786 + _t370*_t793 + (0.43e2 / 0.1296e4)*_t371*_t738 + _t374*_t739 + _t375*_t743 - _t383*_t451 - _t383*_t464 - _t384*_t463 - _t386*_t785 - _t386*_t796 + _t389*_t51*_t794 - _t399*_t564 + _t414*_t733 + _t417*_t733 - _t428*_t739 - 0.5e1 / 0.18e2*_t431*_t443 + (0.5e1 / 0.18e2)*_t445*_t763 - _t450*_t675 - _t450*_t678 + (0.1e1 / 0.54e2)*_t452 + _t453*_t710 + _t459*_t591*_t657 + _t459*_t778 - _t463*_t655*_t75 - _t465*_t564 - _t602*_t618*_t762 - _t611*_t746 - _t613*_t755 - _t622*_t765 - _t629*_t768 - 0.100e3 / 0.2187e4*_t633*_t764 - _t635*_t772 - 0.5e1 / 0.729e3*_t637*_t767 - _t638*_t772 + _t684*_t736 + _t688*_t736 + _t692*_t745 + _t696*_t746 + _t697*_t745 + (0.1e1 / 0.1944e4)*_t700*_t749 + _t701*_t753 + (0.1e1 / 0.648e3)*_t703*_t744 + _t704*_t754 + (0.11e2 / 0.7776e4)*_t705*_t744 + _t706*_t753 + _t707*_t755 + _t708*_t746 + _t716*_t794 + _t739*_t740 - _t739*_t741 - 0.1e1 / 0.432e3*_t744*_t757 - _t746*_t750 + _t746*_t752 - _t746*_t756 + _t748*_t751 - _t749*_t751 + _t768*_t775 - _t769*_t770 + _t773*_t774 + _t781*_t782 - _t781*_t784 - _t781*_t792 - _t787*_t788 + _t788*_t791) + _t135*_t394 + _t135*_t395 - _t179*_t392));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t28, 0, 0.3e1*_t411 + n_s*my_piecewise3(_t28, 0, _hc3[0]*((0.2e1 / 0.81e2)*_hc0[1]*_hc0[2]*_hc1[1]*_t115*_t119*_t270*_t30*_t31*_t41*_t476*_t478 + (0.22e2 / 0.81e2)*_hc0[1]*_hc1[1]*_hc2[1]*_t103*_t104*_t186*_t30*_t41*_t483*_t49*params->task_d + (0.2e1 / 0.81e2)*_hc0[1]*_hc1[1]*_hc2[2]*_t270*_t30*_t41*_t476*_t478*_t49*params->task_d + (0.1e1 / 0.3e1)*_hc0[1]*_hc1[1]*_t3*_t30*_t31*_t4*_t408*_t49*_t62*params->task_d*sigma_ss + (0.154e3 / 0.81e2)*_hc0[1]*_hc1[1]*_t3*_t30*_t31*_t4*_t41*_t480*_t49*params->task_d*sigma_ss + (0.1e1 / 0.3e1)*_hc0[1]*_hc1[2]*_t214*_t3*_t30*_t31*_t4*_t41*_t49*_t62*params->task_d*sigma_ss + (0.1e1 / 0.3e1)*_hc0[1]*_hc1[2]*_t3*_t30*_t31*_t4*_t402*_t49*_t62*_t75*params->task_d*sigma_ss + (0.1e1 / 0.3e1)*_hc0[1]*_hc1[3]*_t198*_t3*_t30*_t31*_t4*_t41*_t49*_t62*params->task_d*sigma_ss + (0.2e1 / 0.81e2)*_hc0[2]*_hc1[1]*_hc2[1]*_t270*_t30*_t41*_t476*_t478*_t49*params->task_d + (0.11e2 / 0.81e2)*_hc0[2]*_hc1[1]*_t103*_t104*_t186*_t30*_t31*_t41*_t483*_t49*params->task_d + (0.2e1 / 0.243e3)*_hc0[3]*_hc1[1]*_t270*_t30*_t31*_t41*_t476*_t478*_t49*params->task_d + (0.2e1 / 0.81e2)*_hc1[1]*_hc2[1]*_t115*_t116*_t119*_t270*_t30*_t41*_t476*_t478 + (0.1e1 / 0.3e1)*_hc1[1]*_hc2[1]*_t3*_t30*_t4*_t408*_t62*sigma_ss + (0.154e3 / 0.81e2)*_hc1[1]*_hc2[1]*_t3*_t30*_t4*_t41*_t480*sigma_ss + (0.11e2 / 0.81e2)*_hc1[1]*_hc2[2]*_t103*_t104*_t186*_t30*_t41*_t483 + (0.2e1 / 0.243e3)*_hc1[1]*_hc2[3]*_t270*_t30*_t41*_t476*_t478 + (0.11e2 / 0.81e2)*_hc1[1]*_t103*_t104*_t115*_t116*_t119*_t186*_t30*_t31*_t41*_t483 + (0.1e1 / 0.27e2)*_hc1[1]*_t103*_t104*_t115*_t116*_t145*_t184*_t186*_t30*_t31*params->task_d + (0.2e1 / 0.243e3)*_hc1[1]*_t270*_t277*_t278*_t282*_t30*_t31*_t41*_t476*_t478 + (0.4e1 / 0.243e3)*_hc1[1]*_t270*_t277*_t278*_t30*_t31*_t41*_t476*_t478*params->task_d + (0.1e1 / 0.3e1)*_hc1[2]*_hc2[1]*_t214*_t3*_t30*_t4*_t41*_t62*sigma_ss + (0.1e1 / 0.3e1)*_hc1[2]*_hc2[1]*_t3*_t30*_t4*_t402*_t62*_t75*sigma_ss + (0.1e1 / 0.27e2)*_hc1[2]*_t103*_t104*_t115*_t116*_t184*_t186*_t30*_t31*_t41*_t75*params->task_d + (0.1e1 / 0.3e1)*_hc1[3]*_hc2[1]*_t198*_t3*_t30*_t4*_t41*_t62*sigma_ss - _t139*_t408 - _t139*(-_t144*_t524 + _t20*_t723 + _t39*_t800 + _t525 - _t722*_t73 + _t724*tau_s) - _t140*_t797 - _t145*_t506*_t567 - _t146*_t797 - _t214*_t348 - _t214*_t349 - _t234*_t347*_t396*_t502 - _t258*_t798 - _t258*_t799 - _t303*_t798 - _t303*_t799 - _t337*_t497*_t95 - _t348*_t526 - _t349*_t526 - _t399*(_t144*_t538 - _t20*_t648 - _t39*_t512 + _t533*_t73) - _t42*(_t144*_t803 + _t149*_t510 - _t180*_t509 - _t212*_t648 - _t39*_t802 + _t40*my_piecewise3(_t14, (0.5e1 / 0.108e3)*_t17*_t37*_t57 - _t210*_t37*_t515 - _t37*_t517 - _t406*_t513, 0) - _t407*_t512 + _t519) - _t491*_t662 - _t491*_t665 - _t494*_t587 - _t498*_t596 - _t501*_t680 - _t501*_t682 - _t505*_t51*_t680 - _t505*_t51*_t682 - _t520*_t97) + (0.2e1 / 0.3e1)*_t147*_t174 + (0.1e1 / 0.12e2)*_t147*_t178 - _t410*_t475 + (0.1e1 / 0.36e2)*_t470*_t95 + _t472*_t95 + _t474*_t95));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = 0;
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t28, 0, 0.3e1*_t467 + n_s*my_piecewise3(_t28, 0, _hc3[0]*((0.10e2 / 0.729e3)*_hc0[1]*_hc0[2]*_hc1[1]*_t115*_t119*_t3*_t30*_t31*_t478*_t53*_t600*_t734*tau_s + (0.1e1 / 0.36e2)*_hc0[1]*_hc0[2]*_hc1[1]*_t115*_t186*_t270*_t30*_t31*_t413*_t75*params->task_d + (0.1e1 / 0.243e3)*_hc0[1]*_hc0[2]*_hc2[1]*_t115*_t29*_t3*_t30*_t478*_t600*_t806*params->task_d + (0.19e2 / 0.108e3)*_hc0[1]*_hc0[2]*_t115*_t186*_t270*_t29*_t30*_t31*_t476*params->task_d + (0.1e1 / 0.729e3)*_hc0[1]*_hc0[3]*_t115*_t29*_t3*_t30*_t31*_t478*_t600*_t806*params->task_d + (0.1e1 / 0.36e2)*_hc0[1]*_hc1[1]*_hc2[1]*_t103*_t104*_t150*_t214*_t30*_t49*params->task_d*sigma_ss + (0.220e3 / 0.243e3)*_hc0[1]*_hc1[1]*_hc2[1]*_t186*_t270*_t30*_t413*_t49*_t53*params->task_d*tau_s + (0.10e2 / 0.729e3)*_hc0[1]*_hc1[1]*_hc2[2]*_t3*_t30*_t478*_t49*_t53*_t600*_t734*params->task_d*tau_s + (0.770e3 / 0.729e3)*_hc0[1]*_hc1[1]*_t103*_t104*_t184*_t30*_t31*_t49*_t53*params->task_d*sigma_ss*tau_s + (0.1e1 / 0.3e1)*_hc0[1]*_hc1[1]*_t214*_t3*_t30*_t31*_t4*_t49*_t62*params->task_d + (0.1e1 / 0.3e1)*_hc0[1]*_hc1[1]*_t3*_t30*_t31*_t4*_t450*_t49*_t62*params->task_d*sigma_ss + (0.1e1 / 0.36e2)*_hc0[1]*_hc1[2]*_hc2[1]*_t103*_t104*_t150*_t198*_t30*_t49*params->task_d*sigma_ss + (0.5e1 / 0.27e2)*_hc0[1]*_hc1[2]*_t102*_t103*_t104*_t214*_t30*_t31*_t49*_t53*params->task_d*sigma_ss*tau_s + (0.1e1 / 0.3e1)*_hc0[1]*_hc1[2]*_t198*_t3*_t30*_t31*_t4*_t49*_t62*params->task_d + (0.1e1 / 0.3e1)*_hc0[1]*_hc1[2]*_t3*_t30*_t31*_t4*_t463*_t49*_t62*_t75*params->task_d*sigma_ss + (0.5e1 / 0.27e2)*_hc0[1]*_hc1[3]*_t102*_t103*_t104*_t198*_t30*_t31*_t49*_t53*params->task_d*sigma_ss*tau_s + (0.10e2 / 0.729e3)*_hc0[2]*_hc1[1]*_hc2[1]*_t3*_t30*_t478*_t49*_t53*_t600*_t734*params->task_d*tau_s + (0.1e1 / 0.72e2)*_hc0[2]*_hc1[1]*_t103*_t104*_t150*_t214*_t30*_t31*_t49*params->task_d*sigma_ss + (0.110e3 / 0.243e3)*_hc0[2]*_hc1[1]*_t186*_t270*_t30*_t31*_t413*_t49*_t53*params->task_d*tau_s + (0.1e1 / 0.72e2)*_hc0[2]*_hc1[2]*_t103*_t104*_t150*_t198*_t30*_t31*_t49*params->task_d*sigma_ss + (0.1e1 / 0.162e3)*_hc0[2]*_t116*_t119*_t277*_t29*_t3*_t30*_t31*_t478*_t600*_t806 + (0.10e2 / 0.2187e4)*_hc0[3]*_hc1[1]*_t3*_t30*_t31*_t478*_t49*_t53*_t600*_t734*params->task_d*tau_s - _hc0[3]*_t704*_t813 + (0.770e3 / 0.729e3)*_hc1[1]*_hc2[1]*_t103*_t104*_t184*_t30*_t53*sigma_ss*tau_s + (0.10e2 / 0.729e3)*_hc1[1]*_hc2[1]*_t115*_t116*_t119*_t3*_t30*_t478*_t53*_t600*_t734*tau_s + (0.1e1 / 0.36e2)*_hc1[1]*_hc2[1]*_t115*_t116*_t186*_t270*_t30*_t413*_t75*params->task_d + (0.1e1 / 0.3e1)*_hc1[1]*_hc2[1]*_t214*_t3*_t30*_t4*_t62 + (0.1e1 / 0.3e1)*_hc1[1]*_hc2[1]*_t3*_t30*_t4*_t450*_t62*sigma_ss + (0.1e1 / 0.72e2)*_hc1[1]*_hc2[2]*_t103*_t104*_t150*_t214*_t30*sigma_ss + (0.110e3 / 0.243e3)*_hc1[1]*_hc2[2]*_t186*_t270*_t30*_t413*_t53*tau_s + (0.10e2 / 0.2187e4)*_hc1[1]*_hc2[3]*_t3*_t30*_t478*_t53*_t600*_t734*tau_s + (0.1e1 / 0.72e2)*_hc1[1]*_t103*_t104*_t115*_t116*_t119*_t150*_t214*_t30*_t31*sigma_ss + (0.1e1 / 0.27e2)*_hc1[1]*_t103*_t104*_t115*_t116*_t167*_t184*_t186*_t30*_t31*params->task_d + (0.1e1 / 0.8e1)*_hc1[1]*_t103*_t104*_t115*_t116*_t184*_t30*_t31*_t75*params->task_d*sigma_ss + (0.110e3 / 0.243e3)*_hc1[1]*_t115*_t116*_t119*_t186*_t270*_t30*_t31*_t413*_t53*tau_s + (0.1e1 / 0.36e2)*_hc1[1]*_t119*_t186*_t270*_t277*_t278*_t30*_t31*_t413*_t75 + (0.10e2 / 0.2187e4)*_hc1[1]*_t277*_t278*_t282*_t3*_t30*_t31*_t478*_t53*_t600*_t734*tau_s + (0.20e2 / 0.2187e4)*_hc1[1]*_t277*_t278*_t3*_t30*_t31*_t478*_t53*_t600*_t734*params->task_d*tau_s + (0.5e1 / 0.27e2)*_hc1[2]*_hc2[1]*_t102*_t103*_t104*_t214*_t30*_t53*sigma_ss*tau_s + (0.1e1 / 0.3e1)*_hc1[2]*_hc2[1]*_t198*_t3*_t30*_t4*_t62 + (0.1e1 / 0.3e1)*_hc1[2]*_hc2[1]*_t3*_t30*_t4*_t463*_t62*_t75*sigma_ss + (0.1e1 / 0.72e2)*_hc1[2]*_hc2[2]*_t103*_t104*_t150*_t198*_t30*sigma_ss + (0.1e1 / 0.72e2)*_hc1[2]*_t103*_t104*_t115*_t116*_t119*_t150*_t198*_t30*_t31*sigma_ss + (0.10e2 / 0.81e2)*_hc1[2]*_t115*_t116*_t186*_t270*_t30*_t31*_t352*_t53*_t75*params->task_d*tau_s + (0.5e1 / 0.27e2)*_hc1[3]*_hc2[1]*_t102*_t103*_t104*_t198*_t30*_t53*sigma_ss*tau_s + (0.19e2 / 0.108e3)*_hc2[1]*_t115*_t116*_t186*_t270*_t29*_t30*_t476*params->task_d + (0.1e1 / 0.243e3)*_hc2[1]*_t119*_t277*_t278*_t29*_t3*_t30*_t478*_t600*_t806 + (0.1e1 / 0.486e3)*_hc2[2]*_t115*_t116*_t29*_t3*_t30*_t478*_t600*_t806*params->task_d + (0.341e3 / 0.972e3)*_t103*_t104*_t115*_t116*_t29*_t30*_t31*_t483*params->task_d*sigma_ss - 0.2e1 / 0.729e3*_t109*_t817 - _t113*_t818 + (0.1e1 / 0.972e3)*_t115*_t29*_t3*_t30*_t31*_t478*_t600*_t612*_t806*params->task_d + (0.19e2 / 0.108e3)*_t119*_t186*_t270*_t277*_t278*_t29*_t30*_t31*_t476 - _t119*_t365*_t811 - _t122*_t337*_t820*tau_s - _t139*_t450 - _t139*(-_t165*_t524 + _t240*_t448 + _t53*_t800) - 0.55e2 / 0.81e2*_t157*_t391*_t443*_t51 - _t162*_t818 - _t168*_t797 - 0.1e1 / 0.4e1*_t191*_t454*sigma_ss - _t199*_t829 - _t200*_t822 - _t202*_t822 - _t214*_t384 - _t214*_t652 - _t214*_t732 - _t215*_t829 - _t236*_t520 - _t258*_t821 - _t258*_t826 - _t262*_t779*_t830 + (0.1e1 / 0.486e3)*_t282*_t29*_t3*_t30*_t31*_t478*_t600*_t608*_t609*_t806 + (0.1e1 / 0.486e3)*_t29*_t3*_t30*_t31*_t478*_t600*_t608*_t609*_t806*params->task_d - _t303*_t76*_t828 - _t303*_t821 - _t303*_t826 - _t303*_t831*tau_s - 0.55e2 / 0.81e2*_t335*_t460 - _t359*_t811 - _t368*_t816 - 0.19e2 / 0.162e3*_t371*_t810 - 0.1e1 / 0.243e3*_t373*_t607*_t812 - _t373*_t791*_t825 - _t374*_t811 - _t375*_t816 - _t382*_t501 - _t384*_t526 - _t399*(_t165*_t538 - _t512*_t53) - _t419*_t823 - _t42*(_t165*_t803 + _t40*my_piecewise3(_t14, (0.3e1 / 0.4e1)*_t10*_t468, 0) - _t448*_t512 - _t53*_t802) - _t420*_t786 - _t420*_t793 - _t429*_t445*_t758 - 0.1e1 / 0.54e2*_t429*_t790 - _t477*_t804 - _t480*_t482 - _t480*_t487 - 0.154e3 / 0.81e2*_t480*_t815 - _t484*_t805 - _t486*_t804 - _t488*_t805 - 0.341e3 / 0.486e3*_t493*sigma_ss - _t498*_t535 - _t498*_t541 - _t499*_t96 - _t503*_t824 - _t505*_t712 - _t506*_t710 - _t520*_t542 - _t521*_t96 - _t522*_t96 - _t526*_t652 - _t526*_t732 - _t527*_t96 - _t634*_t773*_t820 - 0.10e2 / 0.81e2*_t669*_t830 - _t684*_t808 - _t688*_t808 - _t692*_t813 - _t696*_t814 - _t697*_t813 - 0.1e1 / 0.729e3*_t700*_t817 - _t701*_t819 - 0.1e1 / 0.243e3*_t703*_t812 - 0.11e2 / 0.2916e4*_t705*_t812 - _t706*_t819 - 0.1e1 / 0.972e3*_t707*_t812 - _t708*_t814 - _t740*_t811 - _t752*_t814 - _t769*_t831 - _t775*_t820 - _t782*_t825 - _t827*_t828) + (0.2e1 / 0.3e1)*_hc3[2]*_t170*_t173*_t25*_t3 + (0.1e1 / 0.12e2)*_hc3[5]*_t1*_t103*_t170*_t176 - _t412*_t470 - _t466*_t475 - _t472*_t55 - _t474*_t55));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t28, 0, 0.4e1*_t529 + n_s*my_piecewise3(_t28, 0, _hc3[0]*((0.1958e4 / 0.729e3)*_t105*_t159*_t838 - 0.8e1 / 0.729e3*_t109*_t847 + (0.16e2 / 0.2187e4)*_t109*_t848 + _t113*_t851 - 0.2e1*_t139*_t520 - _t139*(-_t212*_t871 + _t240*_t518 - 0.4400e4 / 0.243e3*_t508*_t66 + _t73*_t874) + _t151*_t839 + _t154*_t839 + _t162*_t851 + _t169*_t332*_t483*_t858 + _t182*_t835 + (0.88e2 / 0.81e2)*_t186*_t454*_t492 + _t188*_t835 - _t197*_t851 - _t198*_t234*_t396*_t504 - _t199*_t864 - _t199*_t868 + _t199*_t869 - _t199*_t870 + _t200*_t855 + _t202*_t855 - (_t214 * _t214)*_t80 - _t214*_t399 - _t214*_t505*_t567 + _t214*_t872 - _t215*_t864 - _t215*_t868 + _t215*_t869 - _t215*_t870 + _t246*_t520*_t857 + _t258*_t860 - _t276*_t852 - _t281*_t845 + _t303*_t860 + _t303*_t867 - _t337*_t867 + _t353*_t833 + _t357*_t833 + _t359*_t841 + _t365*_t845 + _t368*_t846 + (0.88e2 / 0.243e3)*_t371*_t840 + _t374*_t841 + _t375*_t846 - _t399*_t526 - _t399*(_t212*_t538 + (0.200e3 / 0.27e2)*_t523 - _t73*_t871) - _t42*(_t212*_t874 + _t40*my_piecewise3(_t14, _t10*_t19*(-0.20944e5 / 0.81e2*_t834 + (0.49280e5 / 0.81e2)*_t873) + _t10*_t516*_t725 + (0.5e1 / 0.81e2)*_t173*_t18 - 0.5e1 / 0.27e2*_t209*_t57 + (0.5e1 / 0.6e1)*_t24*_t514, 0) - _t518*_t524 + (0.30800e5 / 0.729e3)*_t66*_t873 - 0.8800e4 / 0.243e3*_t73*_t801) - _t428*_t841 - _t465*_t526 + (0.16e2 / 0.243e3)*_t490*_t790 + _t498*_t557*_t857 + _t499*_t865 + _t521*_t865 + _t522*_t865 + _t526*_t872 + _t527*_t865 - _t530*(_t75 * _t75 * _t75 * _t75) - _t611*_t844 - _t613*_t853 + _t684*_t837 + _t688*_t837 + _t692*_t843 + _t696*_t844 + _t697*_t843 + (0.8e1 / 0.2187e4)*_t700*_t848 + _t701*_t850 + (0.8e1 / 0.729e3)*_t703*_t842 + _t704*_t852 + (0.22e2 / 0.2187e4)*_t705*_t842 + _t706*_t850 + _t707*_t853 + _t708*_t844 + _t740*_t841 - _t741*_t841 - _t750*_t844 + _t752*_t844 - _t756*_t844 - 0.4e1 / 0.243e3*_t757*_t842 + _t782*_t859 - _t784*_t859 - _t785*_t856 - _t785*_t862 + _t786*_t861 - _t787*_t863 + _t791*_t863 - _t792*_t859 + _t793*_t861 - _t796*_t856 - _t796*_t862 + _t815*_t835 + _t823*_t854 + _t827*_t866 + _t847*_t849 - _t848*_t849) + (0.1e1 / 0.216e3)*_hc3[14]*_t102*_t34*_t5 + _hc3[9]*_t172*_t295*_t469 + (0.140e3 / 0.81e2)*_t123*_t34*_t58 + (0.4e1 / 0.3e1)*_t174*_t216 + (0.40e2 / 0.81e2)*_t177*_t180*_t34 + (0.1e1 / 0.6e1)*_t178*_t216 - 0.1e1 / 0.9e1*_t470*_t77 - 0.56e2 / 0.27e2*_t471*_t77 - 0.4e1 / 0.9e1*_t473*_t77 - 0.2e1 / 0.3e1*_t528*_t59));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_task_params *params = (const mgga_x_task_params *)(p->params);
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