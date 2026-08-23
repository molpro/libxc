/*
  Generated from python/gga_exc/gga_c_pbe_erf_gws.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_pbe_erf_gws
*/

#ifndef _GGA_C_PBE_ERF_GWS_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_PBE_ERF_GWS_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_PBE_ERF_GWS_HELPER_BODIES
#include "gga_c_pbe_erf_gws.c"
#undef _GGA_C_PBE_ERF_GWS_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_PBE_ERF_GWS_HELPER_BODIES
#include "gga_c_pbe_erf_gws.c"
#undef _GGA_C_PBE_ERF_GWS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_PBE_ERF_GWS_HELPER_BODIES
#include "gga_c_pbe_erf_gws.c"
#undef _GGA_C_PBE_ERF_GWS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_PBE_ERF_GWS_HELPER_BODIES
#include "gga_c_pbe_erf_gws.c"
#undef _GGA_C_PBE_ERF_GWS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_PBE_ERF_GWS_HELPER_BODIES
#include "gga_c_pbe_erf_gws.c"
#undef _GGA_C_PBE_ERF_GWS_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_PBE_ERF_GWS_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_gen_k, _KMAX)(const xc_func_type *p, double z, double n, double *out) {

  const double _t1 = z + 0.1e1;
  const double _t2 = _t1 <= p->zeta_threshold;
  const double _t3 = pow(p->zeta_threshold, n);
  const double _t4 = pow(_t1, n);
#if _KMAX >= 1
  const double _t5 = log(p->zeta_threshold);
  const double _t6 = log(_t1);
  const double _t7 = _t4*_t6;
  const double _t8 = (0.1e1 / _t1);
  const double _t9 = _t4*_t8;
  const double _t10 = _t9*n;
#endif
#if _KMAX >= 2
  const double _t11 = _t4*(_t6 * _t6);
  const double _t12 = _t7*_t8;
  const double _t13 = (0.1e1 / (_t1 * _t1));
  const double _t14 = _t13*_t4;
  const double _t15 = _t14*n;
  const double _t16 = (n * n);
#endif
#if _KMAX >= 3
  const double _t17 = (_t6 * _t6 * _t6);
  const double _t18 = _t11*_t8;
  const double _t19 = _t13*_t7;
  const double _t20 = _t19*n;
  const double _t21 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t22 = _t21*_t4;
  const double _t23 = 0.2e1*_t22;
  const double _t24 = (n * n * n);
  const double _t25 = 0.3e1*_t16;
  const double _t26 = _t22*_t25;
#endif
#if _KMAX >= 4
  const double _t27 = _t11*_t13;
  const double _t28 = 0.6e1*n;
  const double _t29 = _t21*_t7;
  const double _t30 = _t4/(_t1 * _t1 * _t1 * _t1);
#endif

  const double f = my_piecewise3(_t2, _t3, _t4);
  out[0] = f;
#if _KMAX >= 1
  const double df_dn = my_piecewise3(_t2, _t3*_t5, _t7);
  out[1] = df_dn;
  const double df_dz = my_piecewise3(_t2, 0, _t10);
  out[2] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dn2 = my_piecewise3(_t2, _t3*(_t5 * _t5), _t11);
  out[3] = d2f_dn2;
  const double d2f_dz_dn = my_piecewise3(_t2, 0, _t12*n + _t9);
  out[4] = d2f_dz_dn;
  const double d2f_dz2 = my_piecewise3(_t2, 0, _t14*_t16 - _t15);
  out[5] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dn3 = my_piecewise3(_t2, _t3*(_t5 * _t5 * _t5), _t17*_t4);
  out[6] = d3f_dn3;
  const double d3f_dz_dn2 = my_piecewise3(_t2, 0, 0.2e1*_t12 + _t18*n);
  out[7] = d3f_dz_dn2;
  const double d3f_dz2_dn = my_piecewise3(_t2, 0, -_t14 + 0.2e1*_t15 + _t16*_t19 - _t20);
  out[8] = d3f_dz2_dn;
  const double d3f_dz3 = my_piecewise3(_t2, 0, _t22*_t24 + _t23*n - _t26);
  out[9] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dn4 = my_piecewise3(_t2, _t3*(_t5 * _t5 * _t5 * _t5), _t4*(_t6 * _t6 * _t6 * _t6));
  out[10] = d4f_dn4;
  const double d4f_dz_dn3 = my_piecewise3(_t2, 0, _t10*_t17 + 0.3e1*_t18);
  out[11] = d4f_dz_dn3;
  const double d4f_dz2_dn2 = my_piecewise3(_t2, 0, 0.2e1*_t14 + _t16*_t27 - 0.2e1*_t19 + 0.4e1*_t20 - _t27*n);
  out[12] = d4f_dz2_dn2;
  const double d4f_dz3_dn = my_piecewise3(_t2, 0, -_t22*_t28 + _t23 + _t24*_t29 - _t25*_t29 + _t26 + 0.2e1*_t29*n);
  out[13] = d4f_dz3_dn;
  const double d4f_dz4 = my_piecewise3(_t2, 0, 0.11e2*_t16*_t30 - 0.6e1*_t24*_t30 - _t28*_t30 + _t30*(n * n * n * n));
  out[14] = d4f_dz4;
#endif
}

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k, _KMAX)(p, zeta, _hc0);
  const double _t1 = 0.0132882934*rs + 0.062182000000000001;
  const double _t2 = -_t1;
  const double _t3 = pow(rs, 1.5);
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = (rs * rs);
  const double _t6 = 0.1018665524*_t3 + 0.4723158174*_t4 + 0.030651995080000001*_t5 + 0.2230841432*rs;
  const double _t7 = (0.1e1 / _t6);
  const double _t8 = xc_log1p(_t7);
  const double _t9 = _t2*_t8;
  const double _t10 = 0.029729901239999999*_t3 + 0.34979731799999997*_t4 + 0.016775883539999998*_t5 + 0.12236657939999999*rs;
  const double _t11 = (0.1e1 / _t10);
  const double _t12 = xc_log1p(_t11);
  const double _t13 = -0.0037573575*rs - 0.033773999999999998;
  const double _t14 = 0.58482233974552045*_t13;
  const double _t15 = _t12*_t14;
  const double _t16 = (zeta * zeta * zeta * zeta);
  const double _t17 = 0.0063883732000000002*rs + 0.03109;
  const double _t18 = -_t17;
  const double _t19 = 0.104655158*_t3 + 0.438956601*_t4 + 0.019436535299999998*_t5 + 0.19268649300000001*rs;
  const double _t20 = (0.1e1 / _t19);
  const double _t21 = xc_log1p(_t20);
  const double _t22 = _t15 + _t18*_t21 - _t9;
  const double _t23 = _t16*_t22;
#if _KMAX >= 1
  const double _t24 = _hc0[0]*_t22;
  const double _t25 = (zeta * zeta * zeta);
  const double _t26 = 0.4e1*_t25;
  const double _t27 = 0.0021973866044103793*_t12;
  const double _t28 = sqrt(rs);
  const double _t29 = (0.1e1 / _t4);
  const double _t30 = -0.15698273699999998*_t28 - 0.2194783005*_t29 - 0.038873070599999997*rs - 0.19268649300000001;
  const double _t31 = (0.1e1 / (_t19 * _t19));
  const double _t32 = _t20 + 0.1e1;
  const double _t33 = (0.1e1 / _t32);
  const double _t34 = -0.04459485186*_t28 - 0.17489865899999998*_t29 - 0.033551767079999996*rs - 0.12236657939999999;
  const double _t35 = (0.1e1 / (_t10 * _t10));
  const double _t36 = _t11 + 0.1e1;
  const double _t37 = (0.1e1 / _t36);
  const double _t38 = _t7 + 0.1e1;
  const double _t39 = (0.1e1 / _t38);
  const double _t40 = _t39/(_t6 * _t6);
  const double _t41 = -0.15279982860000002*_t28 - 0.2361579087*_t29 - 0.061303990160000002*rs - 0.2230841432;
  const double _t42 = _t2*_t41;
  const double _t43 = _t40*_t42 - 0.0132882934*_t8;
  const double _t44 = 0.58482233974552045*_t13*_t34*_t35*_t37 + _t18*_t30*_t31*_t33 - 0.0063883732000000002*_t21 - _t27 - _t43;
  const double _t45 = _t16*_t44;
  const double _t46 = _t35*_t37;
  const double _t47 = _t34*_t46;
  const double _t48 = _t14*_t47;
#endif
#if _KMAX >= 2
  const double _t49 = (zeta * zeta);
  const double _t50 = 0.12e2*_t49;
  const double _t51 = _t22*_t25;
  const double _t52 = 0.8e1*_hc0[1];
  const double _t53 = _hc0[0]*_t44;
  const double _t54 = 0.0265765868*_t40*_t41;
  const double _t55 = 0.0043947732088207587*_t47;
  const double _t56 = (0.1e1 / _t28);
  const double _t57 = xc_powr(rs, -3, 2);
  const double _t58 = -0.07639991430000001*_t56 + 0.11807895435*_t57 - 0.061303990160000002;
  const double _t59 = _t40*_t58;
  const double _t60 = _t2*_t59;
  const double _t61 = -0.02229742593*_t56 + 0.087449329499999992*_t57 - 0.033551767079999996;
  const double _t62 = _t46*_t61;
  const double _t63 = _t14*_t62;
  const double _t64 = (0.1e1 / (_t6 * _t6 * _t6 * _t6));
  const double _t65 = (0.1e1 / (_t38 * _t38));
  const double _t66 = (_t41 * _t41);
  const double _t67 = _t65*_t66;
  const double _t68 = _t64*_t67;
  const double _t69 = (0.1e1 / (_t10 * _t10 * _t10 * _t10));
  const double _t70 = (0.1e1 / (_t36 * _t36));
  const double _t71 = (_t34 * _t34);
  const double _t72 = _t70*_t71;
  const double _t73 = _t69*_t72;
  const double _t74 = _t14*_t73;
  const double _t75 = _t39/(_t6 * _t6 * _t6);
  const double _t76 = -0.30559965720000004*_t28 - 0.4723158174*_t29 - 0.12260798032*rs - 0.4461682864;
  const double _t77 = _t42*_t76;
  const double _t78 = _t75*_t77;
  const double _t79 = _t37/(_t10 * _t10 * _t10);
  const double _t80 = -0.089189703719999999*_t28 - 0.34979731799999997*_t29 - 0.067103534159999992*rs - 0.24473315879999999;
  const double _t81 = _t34*_t80;
  const double _t82 = _t79*_t81;
  const double _t83 = _t14*_t82;
  const double _t84 = _t31*_t33;
  const double _t85 = -0.078491368499999992*_t56 + 0.10973915025*_t57 - 0.038873070599999997;
  const double _t86 = _t84*_t85;
  const double _t87 = 0.0021973866044103793*rs + 0.019751789702565206;
  const double _t88 = (0.1e1 / (_t19 * _t19 * _t19 * _t19));
  const double _t89 = (0.1e1 / (_t32 * _t32));
  const double _t90 = (_t30 * _t30);
  const double _t91 = _t89*_t90;
  const double _t92 = _t88*_t91;
  const double _t93 = _t2*_t64;
  const double _t94 = _t33/(_t19 * _t19 * _t19);
  const double _t95 = -0.31396547399999997*_t28 - 0.438956601*_t29 - 0.077746141199999994*rs - 0.38537298600000003;
  const double _t96 = _t18*_t30;
  const double _t97 = _t95*_t96;
  const double _t98 = _t17*_t92 + _t18*_t86 - 0.0127767464*_t30*_t84 + _t54 - _t55 - _t60 + _t63 + _t67*_t93 + _t73*_t87 - _t78 + _t83 + _t94*_t97;
  const double _t99 = _t16*_t98;
#endif
#if _KMAX >= 3
  const double _t100 = 0.24e2*_t24;
  const double _t101 = _t22*_t49;
  const double _t102 = 0.36e2*_hc0[1];
  const double _t103 = 0.12e2*_hc0[2];
  const double _t104 = _t25*_t44;
  const double _t105 = _hc0[0]*_t98;
  const double _t106 = 0.039864880200000001*_t59;
  const double _t107 = 0.006592159813231138*_t62;
  const double _t108 = (0.1e1 / _t3);
  const double _t109 = xc_powr(rs, -5, 2);
  const double _t110 = 0.038199957150000005*_t108 - 0.17711843152500001*_t109;
  const double _t111 = _t110*_t40;
  const double _t112 = _t111*_t2;
  const double _t113 = 0.039864880200000001*_t68;
  const double _t114 = 0.011148712965*_t108 - 0.13117399424999998*_t109;
  const double _t115 = _t114*_t46;
  const double _t116 = _t115*_t14;
  const double _t117 = 0.006592159813231138*_t73;
  const double _t118 = 0.0265765868*rs + 0.124364;
  const double _t119 = (_t41 * _t41 * _t41);
  const double _t120 = (0.1e1 / (_t38 * _t38 * _t38));
  const double _t121 = xc_powi(_t6, -6);
  const double _t122 = _t120*_t121;
  const double _t123 = _t119*_t122;
  const double _t124 = (_t34 * _t34 * _t34);
  const double _t125 = (0.1e1 / (_t36 * _t36 * _t36));
  const double _t126 = xc_powi(_t10, -6);
  const double _t127 = _t125*_t126;
  const double _t128 = _t124*_t127;
  const double _t129 = 1.1696446794910409*_t13;
  const double _t130 = _t128*_t129;
  const double _t131 = _t41*_t75;
  const double _t132 = 0.039864880200000001*_t131*_t76;
  const double _t133 = 0.006592159813231138*_t82;
  const double _t134 = -0.15279982860000002*_t56 + 0.2361579087*_t57 - 0.12260798032;
  const double _t135 = _t42*_t75;
  const double _t136 = _t134*_t135;
  const double _t137 = _t64*_t65;
  const double _t138 = _t137*_t42;
  const double _t139 = _t134*_t138;
  const double _t140 = _t138*_t58;
  const double _t141 = _t75*_t76;
  const double _t142 = _t141*_t58;
  const double _t143 = 0.2e1*_t2;
  const double _t144 = _t142*_t143;
  const double _t145 = -0.04459485186*_t56 + 0.17489865899999998*_t57 - 0.067103534159999992;
  const double _t146 = _t69*_t70;
  const double _t147 = _t14*_t34;
  const double _t148 = _t146*_t147;
  const double _t149 = _t145*_t148;
  const double _t150 = _t146*_t61;
  const double _t151 = _t147*_t150;
  const double _t152 = _t145*_t79;
  const double _t153 = _t147*_t152;
  const double _t154 = _t79*_t80;
  const double _t155 = _t154*_t61;
  const double _t156 = _t129*_t155;
  const double _t157 = -0.61119931440000008*_t28 - 0.94463163480000001*_t29 - 0.24521596064000001*rs - 0.89233657280000001;
  const double _t158 = xc_powi(_t6, -5);
  const double _t159 = _t158*_t67;
  const double _t160 = _t159*_t2;
  const double _t161 = _t157*_t160;
  const double _t162 = _t160*_t76;
  const double _t163 = -0.17837940744*_t28 - 0.69959463599999994*_t29 - 0.13420706831999998*rs - 0.48946631759999998;
  const double _t164 = xc_powi(_t10, -5);
  const double _t165 = _t164*_t72;
  const double _t166 = _t14*_t165;
  const double _t167 = _t163*_t166;
  const double _t168 = _t166*_t80;
  const double _t169 = -0.45839948580000006*_t28 - 0.70847372610000003*_t29 - 0.18391197048000002*rs - 0.66925242959999998;
  const double _t170 = _t169*_t39;
  const double _t171 = _t170*_t64;
  const double _t172 = _t171*_t77;
  const double _t173 = -0.13378455557999999*_t28 - 0.52469597699999992*_t29 - 0.10065530123999999*rs - 0.36709973819999997;
  const double _t174 = _t173*_t37*_t69;
  const double _t175 = _t174*_t81;
  const double _t176 = _hc0[0]*_t14;
  const double _t177 = 0.039245684249999996*_t108 - 0.16460872537499999*_t109;
  const double _t178 = _t177*_t84;
  const double _t179 = (_t30 * _t30 * _t30);
  const double _t180 = (0.1e1 / (_t32 * _t32 * _t32));
  const double _t181 = xc_powi(_t19, -6);
  const double _t182 = _t180*_t181;
  const double _t183 = _t179*_t182;
  const double _t184 = _t30*_t94;
  const double _t185 = -0.15698273699999998*_t56 + 0.2194783005*_t57 - 0.077746141199999994;
  const double _t186 = _t185*_t96;
  const double _t187 = _t88*_t89;
  const double _t188 = _t187*_t85;
  const double _t189 = _t94*_t95;
  const double _t190 = _t189*_t85;
  const double _t191 = 0.2e1*_t18;
  const double _t192 = -0.62793094799999993*_t28 - 0.877913202*_t29 - 0.15549228239999999*rs - 0.77074597200000006;
  const double _t193 = xc_powi(_t19, -5);
  const double _t194 = _t193*_t91;
  const double _t195 = _t18*_t194;
  const double _t196 = -0.47094821099999995*_t28 - 0.65843490149999995*_t29 - 0.11661921179999998*rs - 0.57805947899999999;
  const double _t197 = _t196*_t33*_t88;
  const double _t198 = _t14*_t175;
  const double _t199 = _t106 - _t107 - _t112 - _t113 + _t116 + _t117 + _t118*_t123 + _t128*(-0.0043947732088207587*rs - 0.039503579405130412) + _t132 - _t133 - _t136 + _t139 + _t140 - _t144 - _t149 - _t151 + _t153 + _t156 + _t161 + _t162 - _t167 - _t168 - _t172 + _t178*_t18 + _t183*(-0.0127767464*rs - 0.062179999999999999) - 0.019165119600000002*_t184*_t95 - _t186*_t187 + _t186*_t94 - _t188*_t96 + _t190*_t191 - _t192*_t195 - _t195*_t95 + _t197*_t97 + _t198 - 0.019165119600000002*_t86 + 0.019165119600000002*_t92;
  const double _t200 = _t16*_t199;
#endif
#if _KMAX >= 4
  const double _t201 = 0.053153173599999999*_t111;
  const double _t202 = 0.0087895464176415174*_t115;
  const double _t203 = pow(rs, -2.5);
  const double _t204 = xc_powr(rs, -7, 2);
  const double _t205 = _t2*_t40*(-0.057299935725000008*_t203 + 0.44279607881250005*_t204);
  const double _t206 = 0.1063063472*_t123;
  const double _t207 = _t14*_t46*(-0.016723069447499999*_t203 + 0.32793498562499995*_t204);
  const double _t208 = 0.017579092835283035*_t128;
  const double _t209 = (_t58 * _t58)*_t65;
  const double _t210 = _t146*(_t61 * _t61);
  const double _t211 = 0.079729760400000002*rs + 0.37309199999999998;
  const double _t212 = (_t41 * _t41 * _t41 * _t41)/((_t38 * _t38 * _t38 * _t38)*xc_powi(_t6, 8));
  const double _t213 = (_t34 * _t34 * _t34 * _t34)/(xc_powi(_t10, 8)*(_t36 * _t36 * _t36 * _t36));
  const double _t214 = 0.053153173599999999*_t134;
  const double _t215 = _t137*_t41;
  const double _t216 = _t214*_t215;
  const double _t217 = 0.053153173599999999*_t215*_t58;
  const double _t218 = _t131*_t214;
  const double _t219 = 0.1063063472*_t142;
  const double _t220 = 0.0087895464176415174*_t34;
  const double _t221 = _t145*_t220;
  const double _t222 = _t146*_t221;
  const double _t223 = _t150*_t220;
  const double _t224 = _t221*_t79;
  const double _t225 = 0.017579092835283035*_t155;
  const double _t226 = _t134*_t58;
  const double _t227 = _t226*_t65*_t93;
  const double _t228 = 0.3e1*_t2;
  const double _t229 = _t226*_t228*_t75;
  const double _t230 = _t14*_t145;
  const double _t231 = _t150*_t230;
  const double _t232 = 1.7544670192365612*_t13;
  const double _t233 = _t232*_t61;
  const double _t234 = _t152*_t233;
  const double _t235 = 0.07639991430000001*_t108 - 0.35423686305000002*_t109;
  const double _t236 = _t135*_t235;
  const double _t237 = 0.032487183262504181*_t28 + 0.050210169272576204*_t29 + 0.013034006525388686*rs + 0.047430520763667439;
  const double _t238 = 0.01624359163125209*_t28 + 0.025105084636288102*_t29 + 0.0065170032626943432*rs + 0.023715260381833719;
  const double _t239 = 0.2e1*_t110*_t138;
  const double _t240 = _t138*_t235;
  const double _t241 = _t110*_t141*_t228;
  const double _t242 = _t114*_t129*_t146*_t34;
  const double _t243 = 0.02229742593*_t108 - 0.26234798849999996*_t109;
  const double _t244 = _t148*_t243;
  const double _t245 = _t114*_t154*_t232;
  const double _t246 = _t147*_t243*_t79;
  const double _t247 = 0.0087895464176415174*_t165;
  const double _t248 = _hc0[0]*_t163;
  const double _t249 = _hc0[0]*_t80;
  const double _t250 = -0.22919974290000003*_t56 + 0.35423686305000002*_t57 - 0.18391197048000002;
  const double _t251 = _t122*_t143*_t66;
  const double _t252 = _t250*_t251;
  const double _t253 = _t134*_t251;
  const double _t254 = _t251*_t58;
  const double _t255 = _t160*(-0.30559965720000004*_t56 + 0.4723158174*_t57 - 0.24521596064000001);
  const double _t256 = 0.2e1*_t134;
  const double _t257 = _t160*_t256;
  const double _t258 = -0.066892277789999996*_t56 + 0.26234798849999996*_t57 - 0.10065530123999999;
  const double _t259 = _t127*_t129*_t71;
  const double _t260 = _t258*_t259;
  const double _t261 = _t145*_t259;
  const double _t262 = _t259*_t61;
  const double _t263 = _t166*(-0.089189703719999999*_t56 + 0.34979731799999997*_t57 - 0.13420706831999998);
  const double _t264 = _t129*_t145;
  const double _t265 = _t165*_t264;
  const double _t266 = _t119*_t120*_t143/xc_powi(_t6, 7);
  const double _t267 = _t266*(-0.91679897160000012*_t28 - 1.4169474522000001*_t29 - 0.36782394096000004*rs - 1.3385048592);
  const double _t268 = _t157*_t266;
  const double _t269 = _t266*_t76;
  const double _t270 = _t124*_t125*_t129/xc_powi(_t10, 7);
  const double _t271 = _t270*(-0.26756911115999998*_t28 - 1.0493919539999998*_t29 - 0.20131060247999999*rs - 0.73419947639999994);
  const double _t272 = _t163*_t270;
  const double _t273 = _t270*_t80;
  const double _t274 = 0.053153173599999999*_t171*_t41*_t76;
  const double _t275 = 0.0087895464176415174*_t175;
  const double _t276 = _t250*_t39*_t64*_t77;
  const double _t277 = _t158*_t65;
  const double _t278 = _t157*_t42;
  const double _t279 = _t256*_t277*_t278;
  const double _t280 = _t134*_t277*_t77;
  const double _t281 = _t277*_t58;
  const double _t282 = _t278*_t281;
  const double _t283 = 0.2e1*_t281*_t77;
  const double _t284 = _t171*_t256*_t42;
  const double _t285 = 0.3e1*_t170*_t58*_t76*_t93;
  const double _t286 = _t264*_t34;
  const double _t287 = _t164*_t70;
  const double _t288 = _t286*_t287;
  const double _t289 = _t230*_t287*_t81;
  const double _t290 = _t287*_t61;
  const double _t291 = _t147*_t290;
  const double _t292 = _t129*_t290*_t81;
  const double _t293 = _t258*_t69;
  const double _t294 = _t37*_t81;
  const double _t295 = _t176*_t294;
  const double _t296 = _t174*_t286;
  const double _t297 = _t174*_t233;
  const double _t298 = _t121*_t2*_t67*(-0.76399914300000016*_t28 - 1.1807895435*_t29 - 0.3065199508*rs - 1.115420716);
  const double _t299 = _t157*_t298;
  const double _t300 = _t298*_t76;
  const double _t301 = _t121*_t169*_t2*_t67*_t76;
  const double _t302 = _t126*_t72*(-0.22297425930000001*_t28 - 0.87449329499999995*_t29 - 0.16775883539999997*rs - 0.61183289699999999);
  const double _t303 = _t176*_t302;
  const double _t304 = _t126*_t173*_t72*_t80;
  const double _t305 = _t157*_t158*_t170*_t77;
  const double _t306 = _t163*_t164*_t173;
  const double _t307 = 0.025553492800000001*_t30;
  const double _t308 = _t18*_t185;
  const double _t309 = _t96*(0.078491368499999992*_t108 - 0.32921745074999997*_t109);
  const double _t310 = 0.3e1*_t18;
  const double _t311 = -0.23547410549999997*_t56 + 0.32921745074999997*_t57 - 0.11661921179999998;
  const double _t312 = _t182*_t90;
  const double _t313 = _t191*_t312;
  const double _t314 = _t179*_t180*_t191/xc_powi(_t19, 7);
  const double _t315 = _t197*_t95;
  const double _t316 = _t33*_t97;
  const double _t317 = _t14*_t294;
  const double _t318 = _t193*_t89;
  const double _t319 = 0.2e1*_t186;
  const double _t320 = _t318*_t85;
  const double _t321 = _t14*_t302;
  const double _t322 = -0.78491368499999992*_t28 - 1.0973915025000001*_t29 - 0.19436535299999999*rs - 0.96343246500000013;
  const double _t323 = _t18*_t181*_t91;
  const double _t324 = _t323*_t95;
#endif

  const double f = -_hc0[0]*_t15 + _hc0[0]*_t23 + _t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = -_hc0[1]*_t15 + _hc0[1]*_t23 + _t24*_t26;
  out[1] = df_dzeta;
  const double df_drs = _hc0[0]*_t27 + _hc0[0]*_t45 - _hc0[0]*_t48 + _t43;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = -_hc0[2]*_t15 + _hc0[2]*_t23 + _t24*_t50 + _t51*_t52;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = _hc0[1]*_t27 + _hc0[1]*_t45 - _hc0[1]*_t48 + _t26*_t53;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = _hc0[0]*_t55 - _hc0[0]*_t63 + _hc0[0]*_t74 - _hc0[0]*_t83 + _hc0[0]*_t99 + _t1*_t68 - _t54 + _t60 + _t78;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = -_hc0[3]*_t15 + _hc0[3]*_t23 + _t100*zeta + _t101*_t102 + _t103*_t51;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = _hc0[2]*_t27 + _hc0[2]*_t45 - _hc0[2]*_t48 + _t104*_t52 + _t50*_t53;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = _hc0[1]*_t55 - _hc0[1]*_t63 + _hc0[1]*_t74 - _hc0[1]*_t83 + _hc0[1]*_t99 + _t105*_t26;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = _hc0[0]*_t107 - _hc0[0]*_t116 - _hc0[0]*_t117 - _hc0[0]*_t130 + _hc0[0]*_t133 + _hc0[0]*_t149 + _hc0[0]*_t151 - _hc0[0]*_t153 - _hc0[0]*_t156 + _hc0[0]*_t167 + _hc0[0]*_t168 + _hc0[0]*_t200 - _t106 + _t112 + _t113 - _t118*_t123 - _t132 + _t136 - _t139 - _t140 + _t144 - _t161 - _t162 + _t172 - _t175*_t176;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dzeta4 = 0.96e2*_hc0[1]*_t22*zeta + 0.72e2*_hc0[2]*_t101 + 0.16e2*_hc0[3]*_t51 - _hc0[4]*_t15 + _hc0[4]*_t23 + _t100;
  out[10] = d4f_dzeta4;
  const double d4f_drs_dzeta3 = _hc0[3]*_t27 + _hc0[3]*_t45 - _hc0[3]*_t48 + _t102*_t44*_t49 + _t103*_t104 + 0.24e2*_t53*zeta;
  out[11] = d4f_drs_dzeta3;
  const double d4f_drs2_dzeta2 = _hc0[2]*_t55 - _hc0[2]*_t63 + _hc0[2]*_t74 - _hc0[2]*_t83 + _hc0[2]*_t99 + _t105*_t50 + _t25*_t52*_t98;
  out[12] = d4f_drs2_dzeta2;
  const double d4f_drs3_dzeta = _hc0[0]*_t199*_t26 + _hc0[1]*_t107 - _hc0[1]*_t116 - _hc0[1]*_t117 - _hc0[1]*_t130 + _hc0[1]*_t133 + _hc0[1]*_t149 + _hc0[1]*_t151 - _hc0[1]*_t153 - _hc0[1]*_t156 + _hc0[1]*_t167 + _hc0[1]*_t168 - _hc0[1]*_t198 + _hc0[1]*_t200;
  out[13] = d4f_drs3_dzeta;
  const double d4f_drs4 = 3.5089340384731225*_hc0[0]*_t13*_t213 + _hc0[0]*_t16*(-_t14*_t304 + _t159*_t237 + _t159*_t238 - _t163*_t288 - _t163*_t291 - _t163*_t321 + _t165*(-0.0015678740816452686*_t28 - 0.0061491195266550206*_t29 - 0.0011796192565742263*rs - 0.0043021869184172654) + _t165*(-0.00078393704082263429*_t28 - 0.0030745597633275103*_t29 - 0.00058980962828711315*rs - 0.0021510934592086327) + _t17*_t187*(_t85 * _t85) - 0.2e1*_t177*_t187*_t96 + _t177*_t189*_t310 - 0.025553492800000001*_t178 + _t18*_t84*(-0.058868526374999994*_t203 + 0.41152181343749994*_t204) - 0.051106985600000002*_t183 - 0.025553492800000001*_t184*_t185 + _t185*_t187*_t307 - 0.2e1*_t185*_t195 - _t185*_t318*_t97 - _t187*_t309 + _t188*_t307 - _t188*_t308 - 0.051106985600000002*_t190 + _t192*_t193*_t196*_t316 + _t192*_t314 - _t192*_t318*_t319 - _t192*_t320*_t96 - _t192*_t322*_t323 + _t194*(-0.016045828958615175*_t28 - 0.022433748686331946*_t29 - 0.0039733709187639663*rs - 0.019695251646131003) + _t194*(-0.0080229144793075875*_t28 - 0.011216874343165973*_t29 - 0.0019866854593819832*rs - 0.0098476258230655016) - _t195*(-0.31396547399999997*_t56 + 0.438956601*_t57 - 0.15549228239999999) - _t196*_t324 + _t197*_t319 + _t201 - _t202 - _t205 + _t206 + _t207 - _t208 + _t209*_t93 + _t210*_t87 - _t211*_t212 + _t213*(0.013184319626462274*rs + 0.11851073821539124) - _t216 - _t217 + _t218 + _t219 + _t222 + _t223 - _t224 - _t225 + _t227 - _t229 - _t231 + _t234 - _t236 + _t239 + _t240 - _t241 - _t242 - _t244 + _t245 + _t246 - _t252 - _t253 - _t254 + _t255 + _t257 + _t260 + _t261 + _t262 - _t263 - _t265 - _t267 - _t268 - _t269 + _t271 + _t272 + _t273 + _t274 - _t275 - _t276 + _t279 + _t280 + _t282 + _t283 - _t284 - _t285 - _t289 - _t292 + _t293*_t317 + _t296 + _t297*_t80 + _t299 + _t300 + _t301 - _t305 + _t306*_t317 - _t307*_t315 + 0.2e1*_t308*_t312 + 0.3e1*_t308*_t85*_t94 + _t309*_t94 + _t310*_t315*_t85 + _t311*_t313 + _t311*_t316*_t88 + _t313*_t85 + _t314*_t95 + _t314*(-0.9418964219999999*_t28 - 1.3168698029999999*_t29 - 0.23323842359999997*rs - 1.156118958) - 0.2e1*_t320*_t97 - _t321*_t80 - _t322*_t324 + (_t30 * _t30 * _t30 * _t30)*(0.038330239200000005*rs + 0.18653999999999998)/(xc_powi(_t19, 8)*(_t32 * _t32 * _t32 * _t32))) + _hc0[0]*_t202 - _hc0[0]*_t207 + _hc0[0]*_t208 - _hc0[0]*_t222 - _hc0[0]*_t223 + _hc0[0]*_t224 + _hc0[0]*_t225 + _hc0[0]*_t231 - _hc0[0]*_t234 + _hc0[0]*_t242 + _hc0[0]*_t244 - _hc0[0]*_t245 - _hc0[0]*_t246 - _hc0[0]*_t260 - _hc0[0]*_t261 - _hc0[0]*_t262 + _hc0[0]*_t263 + _hc0[0]*_t265 - _hc0[0]*_t271 - _hc0[0]*_t272 - _hc0[0]*_t273 + _hc0[0]*_t275 + _hc0[0]*_t289 + _hc0[0]*_t292 - _hc0[0]*_t296 + _t1*_t209*_t64 - _t159*_t237 - _t159*_t238 + _t163*_t303 + _t176*_t210 + _t176*_t304 - _t201 + _t205 - _t206 + _t211*_t212 + _t216 + _t217 - _t218 - _t219 - _t227 + _t229 + _t236 - _t239 - _t240 + _t241 - _t247*_t248 - _t247*_t249 + _t248*_t288 + _t248*_t291 - _t249*_t297 + _t252 + _t253 + _t254 - _t255 - _t257 + _t267 + _t268 + _t269 - _t274 + _t276 - _t279 - _t280 - _t282 - _t283 + _t284 + _t285 - _t293*_t295 - _t295*_t306 - _t299 - _t300 - _t301 + _t303*_t80 + _t305;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {


  const double f = 0.78494900000000001*rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.78494900000000001;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_Q_num_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (x * x);
  const double _t2 = xc_powr(0.2e1, 2, 3)*M_CBRT3*(M_CBRTPI * M_CBRTPI)/(-0.4e1 + 0.4e1*M_LN2);
  const double _t3 = 3.4485100000000002 - _t2;

  const double f = _t1*_t3 + 3.91744*(x * x * x) + 5.84605*x + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = 11.752320000000001*_t1 + 0.2e1*_t3*x + 5.84605;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = -0.2e1*_t2 + 23.504640000000002*x + 6.8970200000000004;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 23.504640000000002;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_Q_den_k, _KMAX)(const xc_func_type *p, double x, double *out) {


  const double f = 3.4485100000000002*(x * x) + 5.84605*x + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = 6.8970200000000004*x + 5.84605;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 6.8970200000000004;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 0;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_Q_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_Q_den_k, _KMAX)(p, x, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_Q_num_k, _KMAX)(p, x, _hc1);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = -_hc0[0] + _hc1[0];
  const double _t3 = _t1*_t2;
  const double _t4 = (-0.2e1 + 0.2e1*M_LN2)/(M_PI * M_PI);
#if _KMAX >= 1
  const double _t5 = -_hc0[1] + _hc1[1];
  const double _t6 = _t1*_t5;
  const double _t7 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t8 = _t2*_t7;
  const double _t9 = -_hc0[1]*_t8 + _t6;
  const double _t10 = _t3 + 0.1e1;
  const double _t11 = _t4/_t10;
#endif
#if _KMAX >= 2
  const double _t12 = -_t9;
  const double _t13 = _t4/(_t10 * _t10);
  const double _t14 = _t13*_t9;
  const double _t15 = -_hc0[2] + _hc1[2];
  const double _t16 = _t1*_t15;
  const double _t17 = _hc0[1]*_t7;
  const double _t18 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t19 = ((_hc0[1]) * (_hc0[1]));
  const double _t20 = _t18*_t19;
  const double _t21 = _t2*_t20;
  const double _t22 = -_hc0[2]*_t8 + _t16 - 0.2e1*_t17*_t5 + 0.2e1*_t21;
#endif
#if _KMAX >= 3
  const double _t23 = 0.2e1*_hc0[1]*_t2*_t7 - 0.2e1*_t6;
  const double _t24 = (0.1e1 / (_t10 * _t10 * _t10));
  const double _t25 = _t12*_t24*_t4*_t9;
  const double _t26 = _hc0[2]*_t7;
  const double _t27 = 0.6e1*_t2;
  const double _t28 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t29 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t28;
  const double _t30 = _hc0[1]*_hc0[2]*_t18*_t27 + _hc1[3]*_t1 - 0.3e1*_t15*_t17 + 0.6e1*_t20*_t5 - 0.3e1*_t26*_t5 - _t27*_t29;
  const double _t31 = -_t22;
  const double _t32 = _t12*_t13;
#endif
#if _KMAX >= 4
  const double _t33 = 0.3e1*_t22;
  const double _t34 = _t23*_t24*_t4;
#endif

  const double f = _t4*xc_log1p(_t3);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t11*_t9;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = _t11*_t22 + _t12*_t14;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = _t11*_t30 + _t14*_t31 + 0.2e1*_t22*_t32 + _t23*_t25;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = _t11*(0.24e2*_hc0[1]*_hc0[2]*_t18*_t5 + 0.6e1*((_hc0[2]) * (_hc0[2]))*_t18*_t2 - 0.36e2*_hc0[2]*_t19*_t2*_t28 - 0.4e1*_hc1[3]*_t17 + 0.12e2*_t15*_t18*_t19 - 0.6e1*_t15*_t26 - 0.24e2*_t29*_t5 + 0.24e2*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t2/xc_powi((_hc0[0]), 5)) + _t12*_t33*_t34 + _t13*_t31*_t33 - _t14*_t30 + _t25*(0.4e1*_hc0[1]*_t5*_t7 + 0.2e1*_hc0[2]*_t2*_t7 - 0.2e1*_t16 - 0.4e1*_t21) + 0.3e1*_t30*_t32 + 0.2e1*_t31*_t34*_t9 + _t12*_t23*_t4*_t9*(0.3e1*_hc0[1]*_t2*_t7 - 0.3e1*_t6)/(_t10 * _t10 * _t10 * _t10);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_phin_k, _KMAX)(const xc_func_type *p, double n, double z, double *out) {

  const double _t1 = (0.1e1 / 0.3e1)*n;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_gen_k, _KMAX)(p, z, _t1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_gen_k, _KMAX)(p, -z, _t1, _hc1);

  const double f = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = (0.1e1 / 0.2e1)*_hc0[2] - 0.1e1 / 0.2e1*_hc1[2];
  out[1] = df_dz;
  const double df_dn = (0.1e1 / 0.6e1)*_hc0[1] + (0.1e1 / 0.6e1)*_hc1[1];
  out[2] = df_dn;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = (0.1e1 / 0.2e1)*_hc0[5] + (0.1e1 / 0.2e1)*_hc1[5];
  out[3] = d2f_dz2;
  const double d2f_dn_dz = (0.1e1 / 0.6e1)*_hc0[4] - 0.1e1 / 0.6e1*_hc1[4];
  out[4] = d2f_dn_dz;
  const double d2f_dn2 = (0.1e1 / 0.18e2)*_hc0[3] + (0.1e1 / 0.18e2)*_hc1[3];
  out[5] = d2f_dn2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = (0.1e1 / 0.2e1)*_hc0[9] - 0.1e1 / 0.2e1*_hc1[9];
  out[6] = d3f_dz3;
  const double d3f_dn_dz2 = (0.1e1 / 0.6e1)*_hc0[8] + (0.1e1 / 0.6e1)*_hc1[8];
  out[7] = d3f_dn_dz2;
  const double d3f_dn2_dz = (0.1e1 / 0.18e2)*_hc0[7] - 0.1e1 / 0.18e2*_hc1[7];
  out[8] = d3f_dn2_dz;
  const double d3f_dn3 = (0.1e1 / 0.54e2)*_hc0[6] + (0.1e1 / 0.54e2)*_hc1[6];
  out[9] = d3f_dn3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = (0.1e1 / 0.2e1)*_hc0[14] + (0.1e1 / 0.2e1)*_hc1[14];
  out[10] = d4f_dz4;
  const double d4f_dn_dz3 = (0.1e1 / 0.6e1)*_hc0[13] - 0.1e1 / 0.6e1*_hc1[13];
  out[11] = d4f_dn_dz3;
  const double d4f_dn2_dz2 = (0.1e1 / 0.18e2)*_hc0[12] + (0.1e1 / 0.18e2)*_hc1[12];
  out[12] = d4f_dn2_dz2;
  const double d4f_dn3_dz = (0.1e1 / 0.54e2)*_hc0[11] - 0.1e1 / 0.54e2*_hc1[11];
  out[13] = d4f_dn3_dz;
  const double d4f_dn4 = (0.1e1 / 0.162e3)*_hc0[10] + (0.1e1 / 0.162e3)*_hc1[10];
  out[14] = d4f_dn4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_g1_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = 0.040000000000000001*_t1 + 0.43190000000000001*rs + 0.1e1;
  const double _t4 = xc_powr(0.6e1, 1, 3);
  const double _t5 = (M_CBRTPI * M_CBRTPI);
  const double _t6 = _t4*_t5;
  const double _t7 = _t6/_t3;
  const double _t8 = _t2*_t7;
  const double _t9 = 0.1e1 - 0.022669999999999999*rs;
  const double _t10 = (0.3e1 / 0.5e1)*_t9;
#if _KMAX >= 1
  const double _t11 = (0.1e1 / (rs * rs * rs));
  const double _t12 = _t11*_t7;
  const double _t13 = -0.080000000000000002*rs - 0.43190000000000001;
  const double _t14 = (0.1e1 / (_t3 * _t3));
#endif
#if _KMAX >= 2
  const double _t15 = _t14*_t6;
  const double _t16 = _t15*_t2;
  const double _t17 = (0.1e1 / (rs * rs * rs * rs));
  const double _t18 = _t17*_t7;
  const double _t19 = (0.18e2 / 0.5e1)*_t9;
  const double _t20 = _t11*_t15;
  const double _t21 = _t6/(_t3 * _t3 * _t3);
  const double _t22 = _t2*_t21;
  const double _t23 = -0.16*rs - 0.86380000000000001;
  const double _t24 = _t13*_t23;
  const double _t25 = _t22*_t24;
#endif
#if _KMAX >= 3
  const double _t26 = xc_powi(rs, -5);
  const double _t27 = _t26*_t7;
  const double _t28 = _t22*_t9;
  const double _t29 = 0.096000000000000002*_t28;
  const double _t30 = _t11*_t21;
  const double _t31 = _t24*_t30;
  const double _t32 = -0.23999999999999999*rs - 1.2957000000000001;
  const double _t33 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
#endif
#if _KMAX >= 4
  const double _t34 = _t15*_t17;
  const double _t35 = 0.0087052799999999993*_t22;
  const double _t36 = 0.76800000000000002*_t30;
  const double _t37 = _t23*_t9;
  const double _t38 = _t13*_t9;
  const double _t39 = _t2*_t33*_t6;
  const double _t40 = _t32*_t39;
  const double _t41 = _t24*_t9;
  const double _t42 = _t32*_t6;
#endif

  const double f = _t10*_t8;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.6e1 / 0.5e1*_t12*_t9 + (0.3e1 / 0.5e1)*_t13*_t14*_t2*_t4*_t5*_t9 - 0.013602*_t8;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t10*_t25 + 0.054407999999999998*_t12 - 0.027203999999999999*_t13*_t16 - 0.12e2 / 0.5e1*_t13*_t20*_t9 - 0.048000000000000001*_t16*_t9 + _t18*_t19;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.16322399999999998*_t11*_t13*_t14*_t4*_t5 + 0.28800000000000003*_t11*_t14*_t4*_t5*_t9 + (0.54e2 / 0.5e1)*_t13*_t14*_t17*_t4*_t5*_t9 + (0.3e1 / 0.5e1)*_t13*_t2*_t23*_t32*_t33*_t4*_t5*_t9 - _t13*_t29 + 0.0032644799999999997*_t14*_t2*_t4*_t5 - 0.244836*_t18 - _t19*_t31 - _t23*_t29 - 0.040805999999999995*_t25 - 0.72e2 / 0.5e1*_t27*_t9;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _t10*_t2*_t24*_t42*(-0.32000000000000001*rs - 1.7276)/xc_powi(_t3, 5) - 0.24e2 / 0.5e1*_t11*_t33*_t41*_t42 - 0.97934399999999999*_t13*_t34 + _t13*_t35 - 0.288e3 / 0.5e1*_t15*_t26*_t38 + (0.108e3 / 0.5e1)*_t17*_t21*_t41 - 0.026115840000000001*_t20 + _t23*_t35 - 0.054407999999999998*_t24*_t40 + 1.3057920000000001*_t27 + 0.023040000000000001*_t28 + 0.32644799999999996*_t31 - 1.7280000000000002*_t34*_t9 + _t36*_t37 + _t36*_t38 - 0.14400000000000002*_t37*_t40 - 0.192*_t38*_t40 - 0.14399999999999999*_t39*_t41 + 0.72e2*_t7*_t9/xc_powi(rs, 6);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_g0_poly_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = (rs * rs * rs);

  const double f = 0.081930000000000003*_t1 - 0.01277*_t2 + 0.001859*(rs * rs * rs * rs) + 0.0207*rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.038309999999999997*_t1 + 0.0074359999999999999*_t2 + 0.16386000000000001*rs + 0.0207;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.022308000000000001*_t1 - 0.076619999999999994*rs + 0.16386000000000001;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.044616000000000003*rs - 0.076619999999999994;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.044616000000000003;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_g0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g0_poly_k, _KMAX)(p, rs, _hc0);
  const double _t1 = exp(-0.75239999999999996*rs);
  const double _t2 = _t1*((0.1e1 / 0.2e1)*_hc0[0] + 0.1e1 / 0.2e1);
#if _KMAX >= 1
  const double _t3 = (0.1e1 / 0.2e1)*_t1;
#endif
#if _KMAX >= 2
  const double _t4 = _hc0[1]*_t1;
#endif
#if _KMAX >= 3
  const double _t5 = _hc0[2]*_t1;
#endif

  const double f = _t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _hc0[1]*_t3 - 0.75239999999999996*_t2;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc0[2]*_t3 + 0.5661057599999999*_t2 - 0.75239999999999996*_t4;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = _hc0[3]*_t3 - 0.42593797382399989*_t2 + 0.84915863999999985*_t4 - 1.1286*_t5;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -1.5047999999999999*_hc0[3]*_t1 + _hc0[4]*_t3 + 0.3204757315051775*_t2 - 0.85187594764799979*_t4 + 1.6983172799999999*_t5;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_g0c_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g0_poly_k, _KMAX)(p, rs, _hc0);
  const double _t1 = xc_expm1(-0.75239999999999996*rs);
  const double _t2 = (0.1e1 / 0.2e1)*_hc0[0] + 0.1e1 / 0.2e1;
#if _KMAX >= 1
  const double _t3 = (0.1e1 / 0.2e1)*_hc0[1];
  const double _t4 = -0.75239999999999996*_t1 - 0.75239999999999996;
#endif
#if _KMAX >= 2
  const double _t5 = (0.1e1 / 0.2e1)*_hc0[2];
  const double _t6 = 0.5661057599999999*_t1 + 0.5661057599999999;
#endif
#if _KMAX >= 3
  const double _t7 = (0.1e1 / 0.2e1)*_hc0[3];
  const double _t8 = -0.42593797382399989*_t1 - 0.42593797382399989;
#endif
#if _KMAX >= 4
  const double _t9 = (0.1e1 / 0.2e1)*_hc0[4];
#endif

  const double f = (0.1e1 / 0.2e1)*_hc0[0] + _t1*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t1*_t3 + _t2*_t4 + _t3;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc0[1]*_t4 + _t1*_t5 + _t2*_t6 + _t5;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (0.3e1 / 0.2e1)*_hc0[1]*_t6 + (0.3e1 / 0.2e1)*_hc0[2]*_t4 + _t1*_t7 + _t2*_t8 + _t7;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.2e1*_hc0[1]*_t8 + 0.3e1*_hc0[2]*_t6 + 0.2e1*_hc0[3]*_t4 + _t1*_t9 + _t2*(0.3204757315051775*_t1 + 0.3204757315051775) + _t9;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_D2_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = 0.67600000000000005*_t1 - 0.38800000000000001*rs;
  const double _t3 = (0.1e1 / _t1);
  const double _t4 = exp(-0.54700000000000004*rs);
  const double _t5 = _t3*_t4;
  const double _t6 = _t2*_t5;
#if _KMAX >= 1
  const double _t7 = 1.3520000000000001*rs - 0.38800000000000001;
  const double _t8 = (0.1e1 / (rs * rs * rs));
  const double _t9 = _t4*_t8;
  const double _t10 = _t2*_t9;
#endif
#if _KMAX >= 2
  const double _t11 = _t5*_t7;
  const double _t12 = _t7*_t9;
  const double _t13 = (0.1e1 / (rs * rs * rs * rs));
  const double _t14 = _t13*_t4;
  const double _t15 = _t14*_t2;
#endif
#if _KMAX >= 3
  const double _t16 = _t4/xc_powi(rs, 5);
  const double _t17 = _t16*_t2;
#endif

  const double f = _t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.2e1*_t10 + _t3*_t4*_t7 - 0.54700000000000004*_t6;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 2.1880000000000002*_t10 - 1.0940000000000001*_t11 - 0.4e1*_t12 + 0.6e1*_t15 + 1.3520000000000001*_t5 + 0.29920900000000006*_t6;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -1.7952540000000003*_t10 + 0.18e2*_t13*_t4*_t7 - 9.8460000000000001*_t15 - 0.24e2*_t17 + 0.89762700000000017*_t3*_t4*_t7 + 6.5640000000000001*_t4*_t7*_t8 - 2.2186320000000004*_t5 - 0.16366732300000003*_t6 - 8.1120000000000001*_t9;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 1.3093385840000002*_t10 - 0.65466929200000012*_t11 - 7.1810160000000014*_t12 - 39.384*_t14*_t7 + 48.671999999999997*_t14 + 10.771524000000003*_t15 - 0.96e2*_t16*_t7 + 52.512*_t17 + 0.120e3*_t2*_t4/xc_powi(rs, 6) + 2.4271834080000008*_t5 + 0.089526025681000029*_t6 + 17.749056000000003*_t9;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_D3_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs) - 4.9500000000000002*rs;
  const double _t2 = (0.1e1 / (rs * rs * rs));
  const double _t3 = exp(-0.31*rs);
  const double _t4 = _t2*_t3;
  const double _t5 = _t1*_t4;
#if _KMAX >= 1
  const double _t6 = 0.2e1*rs - 4.9500000000000002;
  const double _t7 = (0.1e1 / (rs * rs * rs * rs));
  const double _t8 = _t3*_t7;
  const double _t9 = _t1*_t8;
#endif
#if _KMAX >= 2
  const double _t10 = _t4*_t6;
  const double _t11 = _t6*_t8;
  const double _t12 = xc_powi(rs, -5);
  const double _t13 = _t12*_t3;
  const double _t14 = _t1*_t13;
#endif
#if _KMAX >= 3
  const double _t15 = _t3/xc_powi(rs, 6);
  const double _t16 = _t1*_t15;
#endif

  const double f = _t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t2*_t3*_t6 - 0.31*_t5 - 0.3e1*_t9;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -0.62*_t10 - 0.6e1*_t11 + 0.12e2*_t14 + 0.2e1*_t4 + 0.096100000000000005*_t5 + 1.8599999999999999*_t9;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.36e2*_t12*_t3*_t6 - 11.16*_t14 - 0.60e2*_t16 + 0.2883*_t2*_t3*_t6 + 5.5800000000000001*_t3*_t6*_t7 - 1.8599999999999999*_t4 - 0.029791000000000002*_t5 - 0.18e2*_t8 - 0.8649*_t9;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.360e3*_t1*_t3/xc_powi(rs, 7) - 0.11916399999999999*_t10 - 3.4596*_t11 - 44.640000000000001*_t13*_t6 + 0.144e3*_t13 + 6.9192*_t14 - 0.240e3*_t15*_t6 + 74.400000000000006*_t16 + 1.1532*_t4 + 0.0092352100000000006*_t5 + 22.32*_t8 + 0.35749200000000003*_t9;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_C2_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g0c_k, _KMAX)(p, rs, _hc0);
  const double _t1 = z + 0.1e1;
  const double _t2 = (0.1e1 / (rs * rs * rs));
  const double _t3 = (0.3e1 / 0.8e1)*_t2;
  const double _t4 = 0.1e1 - z;
  const double _t5 = _hc0[0]*_t4;
  const double _t6 = _t3*_t5;
#if _KMAX >= 1
  const double _t7 = (0.1e1 / (rs * rs * rs * rs));
  const double _t8 = _hc0[0]*_t7;
  const double _t9 = (0.9e1 / 0.8e1)*_t8;
  const double _t10 = _t1*_t9;
  const double _t11 = _t1*_t3;
  const double _t12 = _hc0[1]*_t11;
#endif
#if _KMAX >= 2
  const double _t13 = (0.3e1 / 0.4e1)*_t2;
  const double _t14 = _t3*_t4;
  const double _t15 = xc_powi(rs, -5);
  const double _t16 = _hc0[0]*_t15;
  const double _t17 = (0.9e1 / 0.2e1)*_t16*_t4;
#endif
#if _KMAX >= 3
  const double _t18 = _hc0[1]*_t7;
  const double _t19 = xc_powi(rs, -6);
  const double _t20 = (0.45e2 / 0.2e1)*_t19;
  const double _t21 = _t1*_t20;
  const double _t22 = _t15*_t4;
  const double _t23 = (0.27e2 / 0.2e1)*_hc0[1];
  const double _t24 = _t22*_t23;
  const double _t25 = _hc0[2]*_t1;
  const double _t26 = (0.27e2 / 0.8e1)*_t7;
  const double _t27 = _t25*_t26;
  const double _t28 = _hc0[3]*_t11;
#endif

  const double f = -_t1*_t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = (0.3e1 / 0.8e1)*_hc0[0]*_t1*_t2 - _t6;
  out[1] = df_dz;
  const double df_drs = _t10*_t4 - _t12*_t4;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc0[0]*_t13;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = -_hc0[1]*_t14 - _t10 + _t12 + _t4*_t9;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = (0.9e1 / 0.4e1)*_hc0[1]*_t1*_t4*_t7 - _hc0[2]*_t11*_t4 - _t1*_t17;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = (0.3e1 / 0.4e1)*_hc0[1]*_t2 - 0.9e1 / 0.4e1*_t8;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = (0.9e1 / 0.2e1)*_hc0[0]*_t1*_t15 + (0.9e1 / 0.4e1)*_hc0[1]*_t4*_t7 + (0.3e1 / 0.8e1)*_hc0[2]*_t1*_t2 - _hc0[2]*_t14 - 0.9e1 / 0.4e1*_t1*_t18 - _t17;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = -_t1*_t24 + _t21*_t5 + _t27*_t4 - _t28*_t4;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = 0;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = 0;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc0[2]*_t13 + 0.9e1*_t16 - 0.9e1 / 0.2e1*_t18;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = -_hc0[0]*_t21 + _hc0[2]*_t26*_t4 - _hc0[3]*_t14 + _t1*_t15*_t23 + _t20*_t5 - _t24 - _t27 + _t28;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 0.90e2*_hc0[1]*_t1*_t19*_t4 + (0.9e1 / 0.2e1)*_hc0[3]*_t1*_t4*_t7 - _hc0[4]*_t11*_t4 - 0.135e3*_t1*_t5/xc_powi(rs, 7) - 0.27e2*_t22*_t25;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_C3_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g0_k, _KMAX)(p, rs, _hc0);
  const double _t1 = 0.1e1 - z;
  const double _t2 = z + 0.1e1;
  const double _t3 = (0.1e1 / (rs * rs * rs));
  const double _t4 = xc_powr(0.2e1, 1, 2);
  const double _t5 = xc_powr(M_PI, -1, 2);
  const double _t6 = _t4*_t5;
  const double _t7 = _t3*_t6;
  const double _t8 = _hc0[0]*_t7;
  const double _t9 = (0.1e1 / 0.2e1)*_t8;
#if _KMAX >= 1
  const double _t10 = (0.1e1 / (rs * rs * rs * rs));
  const double _t11 = _t10*_t6;
  const double _t12 = _hc0[0]*_t11;
  const double _t13 = (0.3e1 / 0.2e1)*_t12;
  const double _t14 = _t13*_t2;
  const double _t15 = (0.1e1 / 0.2e1)*_hc0[1]*_t7;
  const double _t16 = _t15*_t2;
#endif
#if _KMAX >= 2
  const double _t17 = xc_powi(rs, -5);
  const double _t18 = _hc0[0]*_t6;
  const double _t19 = _t17*_t18;
  const double _t20 = 0.6e1*_t1*_t19;
  const double _t21 = _hc0[2]*_t7;
  const double _t22 = (0.1e1 / 0.2e1)*_t21;
#endif
#if _KMAX >= 3
  const double _t23 = _hc0[1]*_t11;
  const double _t24 = _t18*_t2;
  const double _t25 = xc_powi(rs, -6);
  const double _t26 = 0.30e2*_t25;
  const double _t27 = _t24*_t26;
  const double _t28 = _t1*_t17*_t6;
  const double _t29 = 0.18e2*_hc0[1];
  const double _t30 = _t28*_t29;
  const double _t31 = _hc0[2]*_t2;
  const double _t32 = (0.9e1 / 0.2e1)*_t11;
  const double _t33 = _t31*_t32;
  const double _t34 = (0.1e1 / 0.2e1)*_t7;
  const double _t35 = _hc0[3]*_t2*_t34;
#endif
#if _KMAX >= 4
  const double _t36 = _t1*_t34;
#endif

  const double f = -_t1*_t2*_t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = (0.1e1 / 0.2e1)*_hc0[0]*_t2*_t3*_t4*_t5 - _t1*_t9;
  out[1] = df_dz;
  const double df_drs = _t1*_t14 - _t1*_t16;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t8;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _t1*_t13 - _t1*_t15 - _t14 + _t16;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = 0.3e1*_hc0[1]*_t1*_t10*_t2*_t4*_t5 - _t1*_t2*_t22 - _t2*_t20;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc0[1]*_t3*_t4*_t5 - 0.3e1*_t12;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = 0.6e1*_hc0[0]*_t17*_t2*_t4*_t5 + 0.3e1*_hc0[1]*_t1*_t10*_t4*_t5 + (0.1e1 / 0.2e1)*_hc0[2]*_t2*_t3*_t4*_t5 - _t1*_t22 - 0.3e1*_t2*_t23 - _t20;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _t1*_t27 + _t1*_t33 - _t1*_t35 - _t2*_t30;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = 0;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = 0;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = 0.12e2*_t19 + _t21 - 0.6e1*_t23;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc0[2]*_t1*_t32 - _hc0[3]*_t36 + _t1*_t18*_t26 + _t17*_t2*_t29*_t6 - _t27 - _t30 - _t33 + _t35;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 0.120e3*_hc0[1]*_t1*_t2*_t25*_t4*_t5 + 0.6e1*_hc0[3]*_t1*_t10*_t2*_t4*_t5 - _hc0[4]*_t2*_t36 - 0.180e3*_t1*_t24/xc_powi(rs, 7) - 0.36e2*_t28*_t31;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_c4_l_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  const double _t1 = z + 0.1e1;
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = xc_powr(_t2, 1, 3);
  const double _t4 = M_CBRT2;
  const double _t5 = _t4*rs;
  const double _t6 = _t3*_t5;
  const double _t7 = 0.1e1 - z;
  const double _t8 = (0.1e1 / _t7);
  const double _t9 = xc_powr(_t8, 1, 3);
  const double _t10 = _t5*_t9;
  const double _t11 = (0.1e1 / 0.2e1)*z;
  const double _t12 = _t11 + 0.1e1 / 0.2e1;
  const double _t13 = (_t12 * _t12);
  const double _t14 = _t11 - 0.1e1 / 0.2e1;
  const double _t15 = (_t14 * _t14);
  const double _t17 = xc_powr(0.2e1, 2, 3);
  const double _t18 = M_CBRT3*(M_CBRTPI * M_CBRTPI)*_t17;
  const double _t20 = (rs * rs);
  const double _t21 = (0.3e1 / 0.20e2)/_t20;
#if _KMAX >= 1
  const double _t22 = _t18*_t21;
  const double _t23 = (0.1e1 / 0.3e1)*_t2;
  const double _t26 = (0.1e1 / 0.3e1)*_t8;
  const double _t30 = (rs * rs * rs);
  const double _t31 = (0.3e1 / 0.10e2)/_t30;
  const double _t32 = _t3*_t4;
  const double _t34 = _t4*_t9;
#endif
#if _KMAX >= 2
  const double _t38 = (0.1e1 / (_t1 * _t1));
  const double _t39 = (0.4e1 / 0.9e1)*_t38;
  const double _t45 = (0.1e1 / 0.9e1)*_t20;
  const double _t46 = (0.1e1 / (_t7 * _t7));
  const double _t47 = (0.4e1 / 0.9e1)*_t46;
  const double _t51 = _t18*_t31;
  const double _t59 = (rs * rs * rs * rs);
  const double _t60 = (0.9e1 / 0.10e2)/_t59;
#endif
#if _KMAX >= 3
  const double _t61 = (0.2e1 / 0.27e2)*_t30;
  const double _t62 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t65 = (0.1e1 / (_t7 * _t7 * _t7 * _t7));
  const double _t68 = (0.4e1 / 0.3e1)*_t38;
  const double _t70 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t71 = (0.28e2 / 0.27e2)*_t70;
  const double _t73 = (0.1e1 / 0.3e1)*_t20;
  const double _t74 = _t38*_t73;
  const double _t75 = (0.4e1 / 0.3e1)*_t46;
  const double _t77 = (0.4e1 / 0.9e1)*_t20;
  const double _t78 = (0.1e1 / (_t7 * _t7 * _t7));
  const double _t79 = (0.28e2 / 0.27e2)*_t78;
  const double _t81 = _t46*_t73;
  const double _t84 = (0.2e1 / 0.9e1)*_t20;
  const double _t87 = (0.2e1 / 0.3e1)*_t2;
  const double _t88 = (0.2e1 / 0.3e1)*rs;
  const double _t90 = _t38*_t88;
  const double _t91 = (0.2e1 / 0.3e1)*_t8;
  const double _t93 = _t18*_t60;
  const double _t97 = (0.18e2 / 0.5e1)/xc_powi(rs, 5);
  const double _t98 = 0.2e1*_t8;
#endif
#if _KMAX >= 4
  const double _t100 = (0.8e1 / 0.27e2)*_t30;
  const double _t101 = xc_powi(_t1, -5);
  const double _t102 = (0.16e2 / 0.27e2)*_t30;
  const double _t104 = xc_powi(_t7, -5);
  const double _t105 = (0.16e2 / 0.9e1)*_t20;
  const double _t108 = (0.2e1 / 0.81e2)*_t59;
  const double _t109 = (0.160e3 / 0.81e2)*_t20;
  const double _t112 = (0.2e1 / 0.3e1)*_t20;
  const double _t113 = (0.10e2 / 0.9e1)*_t20;
  const double _t116 = 0.2e1*rs;
  const double _t117 = (0.4e1 / 0.3e1)*rs;
  const double _t118 = (0.16e2 / 0.9e1)*rs;
  const double _t119 = 0.2e1*_t2;
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g1_k, _KMAX)(p, _t6, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g1_k, _KMAX)(p, _t10, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_D2_k, _KMAX)(p, rs, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_phin_k, _KMAX)(p, 0.8e1, z, _hc3);
  const double _t16 = _hc2[0]*_t7;
  const double _t19 = _hc3[0]*_t18;
#if _KMAX >= 1
  const double _t24 = _hc0[1]*_t13;
  const double _t25 = _t24*_t6;
  const double _t27 = _hc1[1]*_t15;
  const double _t28 = _t10*_t27;
  const double _t29 = _hc2[1]*_t7;
  const double _t33 = _t24*_t32;
  const double _t35 = _t27*_t34;
#endif
#if _KMAX >= 2
  const double _t36 = _hc0[1]*_t6;
  const double _t37 = _t2*_t36;
  const double _t40 = _hc1[1]*_t10;
  const double _t41 = _t40*_t8;
  const double _t42 = _hc0[2]*_t17*xc_powr(_t2, 2, 3);
  const double _t43 = _t13*_t42;
  const double _t44 = _t38*_t43;
  const double _t48 = _hc1[2]*_t17*xc_powr(_t8, 2, 3);
  const double _t49 = _t15*_t48;
  const double _t50 = _t46*_t49;
  const double _t52 = _hc0[1]*_t32;
  const double _t53 = _t12*_t52;
  const double _t54 = _hc1[1]*_t34;
  const double _t55 = _t14*_t54;
  const double _t56 = _t43*rs;
  const double _t57 = _t49*rs;
  const double _t58 = _hc2[2]*_t7;
#endif
#if _KMAX >= 3
  const double _t63 = _hc0[3]*_t13;
  const double _t64 = _t62*_t63;
  const double _t66 = _hc1[3]*_t15;
  const double _t67 = _t65*_t66;
  const double _t69 = _t36*_t68;
  const double _t72 = _t12*_t42;
  const double _t76 = _t40*_t75;
  const double _t80 = _t14*_t48;
  const double _t82 = (0.1e1 / 0.2e1)*_t52;
  const double _t83 = (0.1e1 / 0.2e1)*_t54;
  const double _t85 = _t63*_t70;
  const double _t86 = _t66*_t78;
  const double _t89 = _t2*_t72;
  const double _t92 = _t8*_t80;
  const double _t94 = _t46*_t66;
  const double _t95 = _hc2[3]*_t7;
  const double _t96 = 0.2e1*_t63;
#endif
#if _KMAX >= 4
  const double _t99 = _hc0[3]*_t12;
  const double _t103 = _hc1[3]*_t14;
  const double _t106 = _hc0[4]*_t13;
  const double _t107 = _t106*_t32;
  const double _t110 = _hc1[4]*_t15;
  const double _t111 = _t110*_t34;
  const double _t114 = (0.1e1 / 0.2e1)*_t42;
  const double _t115 = (0.1e1 / 0.2e1)*_t48;
#endif

  const double f = _hc0[0]*_t13 + _hc1[0]*_t15 + _t1*_t16 - _t19*_t21;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc0[0]*_t12 + _hc1[0]*_t14 - _hc2[0]*_t1 - _hc3[1]*_t22 + _t16 - _t23*_t25 + _t26*_t28;
  out[1] = df_dz;
  const double df_drs = _t1*_t29 + _t19*_t31 + _t33 + _t35;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] - 0.2e1*_hc2[0] - _hc3[3]*_t22 - 0.2e1 / 0.3e1*_t12*_t37 + (0.2e1 / 0.3e1)*_t14*_t41 + _t25*_t39 + _t28*_t47 + _t44*_t45 + _t45*_t50;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = -_hc2[1]*_t1 + _hc3[1]*_t51 - _t23*_t33 - _t23*_t56 + _t26*_t35 + _t26*_t57 + _t29 + _t53 + _t55;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _t1*_t58 - _t19*_t60 + _t43 + _t49;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = -_hc3[6]*_t22 + _t12*_t69 + _t14*_t76 - _t25*_t71 + _t28*_t79 - 0.1e1 / 0.2e1*_t37 + (0.1e1 / 0.2e1)*_t41 - _t43*_t70*_t77 + _t49*_t77*_t78 - _t61*_t64 + _t61*_t67 + _t72*_t74 + _t80*_t81;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = -0.2e1*_hc2[1] + _hc3[3]*_t51 + _t33*_t39 + _t35*_t47 + _t43*_t90 + _t50*_t88 - _t53*_t87 + _t55*_t91 + _t82 + _t83 + _t84*_t85 + _t84*_t86 - _t88*_t89 + _t88*_t92;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = -_hc2[2]*_t1 - _hc3[1]*_t93 - _t43*_t87 + _t49*_t91 + _t58 - _t63*_t90 + _t72 + _t80 + _t88*_t94;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _t1*_t95 + _t19*_t97 + _t2*_t96 + _t66*_t98;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = -_hc3[10]*_t22 + _t100*_t103*_t65 - _t100*_t62*_t99 + _t101*_t102*_t63 + _t101*_t107*_t108 + _t102*_t104*_t66 + _t104*_t108*_t111 - _t105*_t70*_t72 + _t105*_t78*_t80 + _t109*_t43*_t62 + _t109*_t49*_t65 - 0.112e3 / 0.27e2*_t12*_t36*_t70 + (0.112e3 / 0.27e2)*_t14*_t40*_t78 + (0.280e3 / 0.81e2)*_t25*_t62 + (0.280e3 / 0.81e2)*_t28*_t65 + _t42*_t74 + _t48*_t81 + _t69 + _t76;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc3[6]*_t51 + _t103*_t112*_t78 - _t107*_t61*_t62 + _t111*_t61*_t65 + _t112*_t70*_t99 - _t113*_t64 + _t113*_t67 - _t114*_t2*rs + _t115*_t8*rs + _t116*_t38*_t72 + _t116*_t46*_t80 - _t2*_t82 - _t33*_t71 + _t35*_t79 + _t53*_t68 + _t55*_t75 - 0.52e2 / 0.27e2*_t56*_t70 + (0.52e2 / 0.27e2)*_t57*_t78 + _t8*_t83;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = -0.2e1*_hc2[2] - _hc3[3]*_t93 + _t103*_t117*_t46 + _t107*_t70*_t84 + _t111*_t78*_t84 + _t114 + _t115 - _t117*_t38*_t99 + _t118*_t85 + _t118*_t86 + (0.10e2 / 0.9e1)*_t44 + (0.10e2 / 0.9e1)*_t50 - 0.4e1 / 0.3e1*_t89 + (0.4e1 / 0.3e1)*_t92;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = -_hc2[3]*_t1 + _hc3[1]*_t18*_t97 + (0.2e1 / 0.3e1)*_t10*_t110*_t46 + _t103*_t98 - 0.2e1 / 0.3e1*_t106*_t38*_t6 + _t119*_t99 - _t38*_t96 + 0.2e1*_t94 + _t95;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = _hc2[4]*_t1*_t7 + _t107*_t119 + _t111*_t98 - 0.18e2*_t19/xc_powi(rs, 6);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_C4_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_c4_l_k, _KMAX)(p, rs, z, _hc0);
  const double _t1 = (0.9e1 / 0.64e2)/(rs * rs * rs);
#if _KMAX >= 1
  const double _t2 = (0.1e1 / (rs * rs * rs * rs));
  const double _t3 = (0.27e2 / 0.64e2)*_t2;
#endif
#if _KMAX >= 2
  const double _t4 = xc_powi(rs, -5);
  const double _t5 = (0.27e2 / 0.16e2)*_t4;
#endif
#if _KMAX >= 3
  const double _t6 = xc_powi(rs, -6);
  const double _t7 = (0.135e3 / 0.16e2)*_t6;
  const double _t8 = (0.81e2 / 0.16e2)*_t4;
  const double _t9 = (0.81e2 / 0.64e2)*_t2;
#endif

  const double f = -_hc0[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = -_hc0[1]*_t1;
  out[1] = df_dz;
  const double df_drs = _hc0[0]*_t3 - _hc0[2]*_t1;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = -_hc0[3]*_t1;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[1]*_t3 - _hc0[4]*_t1;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = -_hc0[0]*_t5 + (0.27e2 / 0.32e2)*_hc0[2]*_t2 - _hc0[5]*_t1;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = -_hc0[6]*_t1;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc0[3]*_t3 - _hc0[7]*_t1;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = -_hc0[1]*_t5 + (0.27e2 / 0.32e2)*_hc0[4]*_t2 - _hc0[8]*_t1;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[0]*_t7 - _hc0[2]*_t8 + _hc0[5]*_t9 - _hc0[9]*_t1;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = -_hc0[10]*_t1;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = -_hc0[11]*_t1 + (0.27e2 / 0.64e2)*_hc0[6]*_t2;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = -_hc0[12]*_t1 - _hc0[3]*_t5 + (0.27e2 / 0.32e2)*_hc0[7]*_t2;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc0[1]*_t7 - _hc0[13]*_t1 - _hc0[4]*_t8 + _hc0[8]*_t9;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = -0.405e3 / 0.8e1*_hc0[0]/xc_powi(rs, 7) - _hc0[14]*_t1 + (0.135e3 / 0.4e1)*_hc0[2]*_t6 - 0.81e2 / 0.8e1*_hc0[5]*_t4 + (0.27e2 / 0.16e2)*_hc0[9]*_t2;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_c5_l_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  const double _t1 = z + 0.1e1;
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = xc_powr(_t2, 1, 3);
  const double _t4 = M_CBRT2;
  const double _t5 = _t4*rs;
  const double _t6 = _t3*_t5;
  const double _t7 = 0.1e1 - z;
  const double _t8 = (0.1e1 / _t7);
  const double _t9 = xc_powr(_t8, 1, 3);
  const double _t10 = _t5*_t9;
  const double _t11 = (0.1e1 / 0.2e1)*z;
  const double _t12 = _t11 + 0.1e1 / 0.2e1;
  const double _t13 = (_t12 * _t12);
  const double _t14 = _t11 - 0.1e1 / 0.2e1;
  const double _t15 = (_t14 * _t14);
#if _KMAX >= 1
  const double _t17 = (0.1e1 / 0.3e1)*_t2;
  const double _t20 = (0.1e1 / 0.3e1)*_t8;
  const double _t24 = _t3*_t4;
  const double _t26 = _t4*_t9;
#endif
#if _KMAX >= 2
  const double _t30 = (0.1e1 / (_t1 * _t1));
  const double _t31 = (0.4e1 / 0.9e1)*_t30;
  const double _t34 = xc_powr(0.2e1, 2, 3);
  const double _t38 = (rs * rs);
  const double _t39 = (0.1e1 / 0.9e1)*_t38;
  const double _t40 = (0.1e1 / (_t7 * _t7));
  const double _t41 = (0.4e1 / 0.9e1)*_t40;
#endif
#if _KMAX >= 3
  const double _t52 = (rs * rs * rs);
  const double _t53 = (0.2e1 / 0.27e2)*_t52;
  const double _t54 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t57 = (0.1e1 / (_t7 * _t7 * _t7 * _t7));
  const double _t60 = (0.4e1 / 0.3e1)*_t30;
  const double _t62 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t63 = (0.28e2 / 0.27e2)*_t62;
  const double _t65 = (0.1e1 / 0.3e1)*_t38;
  const double _t66 = _t30*_t65;
  const double _t67 = (0.4e1 / 0.3e1)*_t40;
  const double _t69 = (0.4e1 / 0.9e1)*_t38;
  const double _t70 = (0.1e1 / (_t7 * _t7 * _t7));
  const double _t71 = (0.28e2 / 0.27e2)*_t70;
  const double _t73 = _t40*_t65;
  const double _t76 = (0.2e1 / 0.9e1)*_t38;
  const double _t79 = (0.2e1 / 0.3e1)*_t2;
  const double _t80 = (0.2e1 / 0.3e1)*rs;
  const double _t82 = _t30*_t80;
  const double _t83 = (0.2e1 / 0.3e1)*_t8;
  const double _t88 = 0.2e1*_t8;
#endif
#if _KMAX >= 4
  const double _t90 = (0.8e1 / 0.27e2)*_t52;
  const double _t91 = xc_powi(_t1, -5);
  const double _t92 = (0.16e2 / 0.27e2)*_t52;
  const double _t94 = xc_powi(_t7, -5);
  const double _t95 = (0.16e2 / 0.9e1)*_t38;
  const double _t98 = (0.2e1 / 0.81e2)*(rs * rs * rs * rs);
  const double _t99 = (0.160e3 / 0.81e2)*_t38;
  const double _t102 = (0.2e1 / 0.3e1)*_t38;
  const double _t103 = (0.10e2 / 0.9e1)*_t38;
  const double _t106 = 0.2e1*rs;
  const double _t107 = (0.4e1 / 0.3e1)*rs;
  const double _t108 = (0.16e2 / 0.9e1)*rs;
  const double _t109 = 0.2e1*_t2;
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g1_k, _KMAX)(p, _t6, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g1_k, _KMAX)(p, _t10, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_D3_k, _KMAX)(p, rs, _hc2);
  const double _t16 = _hc2[0]*_t7;
#if _KMAX >= 1
  const double _t18 = _hc0[1]*_t13;
  const double _t19 = _t18*_t6;
  const double _t21 = _hc1[1]*_t15;
  const double _t22 = _t10*_t21;
  const double _t23 = _hc2[1]*_t7;
  const double _t25 = _t18*_t24;
  const double _t27 = _t21*_t26;
#endif
#if _KMAX >= 2
  const double _t28 = _hc0[1]*_t6;
  const double _t29 = _t2*_t28;
  const double _t32 = _hc1[1]*_t10;
  const double _t33 = _t32*_t8;
  const double _t35 = _hc0[2]*xc_powr(_t2, 2, 3)*_t34;
  const double _t36 = _t13*_t35;
  const double _t37 = _t30*_t36;
  const double _t42 = _hc1[2]*_t34*xc_powr(_t8, 2, 3);
  const double _t43 = _t15*_t42;
  const double _t44 = _t40*_t43;
  const double _t45 = _hc0[1]*_t24;
  const double _t46 = _t12*_t45;
  const double _t47 = _hc1[1]*_t26;
  const double _t48 = _t14*_t47;
  const double _t49 = _t36*rs;
  const double _t50 = _t43*rs;
  const double _t51 = _hc2[2]*_t7;
#endif
#if _KMAX >= 3
  const double _t55 = _hc0[3]*_t13;
  const double _t56 = _t54*_t55;
  const double _t58 = _hc1[3]*_t15;
  const double _t59 = _t57*_t58;
  const double _t61 = _t28*_t60;
  const double _t64 = _t12*_t35;
  const double _t68 = _t32*_t67;
  const double _t72 = _t14*_t42;
  const double _t74 = (0.1e1 / 0.2e1)*_t45;
  const double _t75 = (0.1e1 / 0.2e1)*_t47;
  const double _t77 = _t55*_t62;
  const double _t78 = _t58*_t70;
  const double _t81 = _t2*_t64;
  const double _t84 = _t72*_t8;
  const double _t85 = _t40*_t58;
  const double _t86 = _hc2[3]*_t7;
  const double _t87 = 0.2e1*_t55;
#endif
#if _KMAX >= 4
  const double _t89 = _hc0[3]*_t12;
  const double _t93 = _hc1[3]*_t14;
  const double _t96 = _hc0[4]*_t13;
  const double _t97 = _t24*_t96;
  const double _t100 = _hc1[4]*_t15;
  const double _t101 = _t100*_t26;
  const double _t104 = (0.1e1 / 0.2e1)*_t35;
  const double _t105 = (0.1e1 / 0.2e1)*_t42;
#endif

  const double f = _hc0[0]*_t13 + _hc1[0]*_t15 + _t1*_t16;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc0[0]*_t12 + _hc1[0]*_t14 - _hc2[0]*_t1 + _t16 - _t17*_t19 + _t20*_t22;
  out[1] = df_dz;
  const double df_drs = _t1*_t23 + _t25 + _t27;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] - 0.2e1*_hc2[0] - 0.2e1 / 0.3e1*_t12*_t29 + (0.2e1 / 0.3e1)*_t14*_t33 + _t19*_t31 + _t22*_t41 + _t37*_t39 + _t39*_t44;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = -_hc2[1]*_t1 - _t17*_t25 - _t17*_t49 + _t20*_t27 + _t20*_t50 + _t23 + _t46 + _t48;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _t1*_t51 + _t36 + _t43;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t12*_t61 + _t14*_t68 - _t19*_t63 + _t22*_t71 - 0.1e1 / 0.2e1*_t29 + (0.1e1 / 0.2e1)*_t33 - _t36*_t62*_t69 + _t43*_t69*_t70 - _t53*_t56 + _t53*_t59 + _t64*_t66 + _t72*_t73;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = -0.2e1*_hc2[1] + _t25*_t31 + _t27*_t41 + _t36*_t82 + _t44*_t80 - _t46*_t79 + _t48*_t83 + _t74 + _t75 + _t76*_t77 + _t76*_t78 - _t80*_t81 + _t80*_t84;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = -_hc2[2]*_t1 - _t36*_t79 + _t43*_t83 + _t51 - _t55*_t82 + _t64 + _t72 + _t80*_t85;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _t1*_t86 + _t2*_t87 + _t58*_t88;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t101*_t94*_t98 - 0.112e3 / 0.27e2*_t12*_t28*_t62 + (0.112e3 / 0.27e2)*_t14*_t32*_t70 + (0.280e3 / 0.81e2)*_t19*_t54 + (0.280e3 / 0.81e2)*_t22*_t57 + _t35*_t66 + _t36*_t54*_t99 + _t42*_t73 + _t43*_t57*_t99 - _t54*_t89*_t90 + _t55*_t91*_t92 + _t57*_t90*_t93 + _t58*_t92*_t94 + _t61 - _t62*_t64*_t95 + _t68 + _t70*_t72*_t95 + _t91*_t97*_t98;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _t101*_t53*_t57 + _t102*_t62*_t89 + _t102*_t70*_t93 - _t103*_t56 + _t103*_t59 - _t104*_t2*rs + _t105*_t8*rs + _t106*_t30*_t64 + _t106*_t40*_t72 - _t2*_t74 - _t25*_t63 + _t27*_t71 + _t46*_t60 + _t48*_t67 - 0.52e2 / 0.27e2*_t49*_t62 + (0.52e2 / 0.27e2)*_t50*_t70 - _t53*_t54*_t97 + _t75*_t8;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = -0.2e1*_hc2[2] + _t101*_t70*_t76 + _t104 + _t105 - _t107*_t30*_t89 + _t107*_t40*_t93 + _t108*_t77 + _t108*_t78 + (0.10e2 / 0.9e1)*_t37 + (0.10e2 / 0.9e1)*_t44 + _t62*_t76*_t97 - 0.4e1 / 0.3e1*_t81 + (0.4e1 / 0.3e1)*_t84;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = -_hc2[3]*_t1 + (0.2e1 / 0.3e1)*_t10*_t100*_t40 + _t109*_t89 - 0.2e1 / 0.3e1*_t30*_t6*_t96 - _t30*_t87 + 0.2e1*_t85 + _t86 + _t88*_t93;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = _hc2[4]*_t1*_t7 + _t101*_t88 + _t109*_t97;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_C5_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_c5_l_k, _KMAX)(p, rs, z, _hc0);
  const double _t1 = xc_powr(0.2e1, 1, 2);
  const double _t2 = xc_powr(M_PI, -1, 2);
  const double _t3 = _t1*_t2;
  const double _t4 = _hc0[0]*_t3;
  const double _t5 = (0.9e1 / 0.80e2)/(rs * rs * rs);
#if _KMAX >= 1
  const double _t6 = _t3*_t5;
  const double _t7 = (0.1e1 / (rs * rs * rs * rs));
  const double _t8 = (0.27e2 / 0.80e2)*_t7;
#endif
#if _KMAX >= 2
  const double _t9 = _t3*_t8;
  const double _t10 = xc_powi(rs, -5);
  const double _t11 = (0.27e2 / 0.20e2)*_t10;
#endif
#if _KMAX >= 3
  const double _t12 = _t11*_t3;
  const double _t13 = xc_powi(rs, -6);
  const double _t14 = (0.27e2 / 0.4e1)*_t13;
  const double _t15 = (0.81e2 / 0.20e2)*_t10;
  const double _t16 = _hc0[5]*_t3;
  const double _t17 = (0.81e2 / 0.80e2)*_t7;
#endif

  const double f = -_t4*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = -_hc0[1]*_t6;
  out[1] = df_dz;
  const double df_drs = -_hc0[2]*_t6 + _t4*_t8;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = -_hc0[3]*_t6;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[1]*_t9 - _hc0[4]*_t6;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = (0.27e2 / 0.40e2)*_hc0[2]*_t1*_t2*_t7 - _hc0[5]*_t6 - _t11*_t4;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = -_hc0[6]*_t6;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc0[3]*_t9 - _hc0[7]*_t6;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = -_hc0[1]*_t12 + (0.27e2 / 0.40e2)*_hc0[4]*_t1*_t2*_t7 - _hc0[8]*_t6;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = -_hc0[2]*_t15*_t3 - _hc0[9]*_t6 + _t14*_t4 + _t16*_t17;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = -_hc0[10]*_t6;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = -_hc0[11]*_t6 + (0.27e2 / 0.80e2)*_hc0[6]*_t1*_t2*_t7;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = -_hc0[12]*_t6 - _hc0[3]*_t12 + (0.27e2 / 0.40e2)*_hc0[7]*_t1*_t2*_t7;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc0[1]*_t14*_t3 - _hc0[13]*_t6 - _hc0[4]*_t15*_t3 + _hc0[8]*_t17*_t3;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = -_hc0[14]*_t6 + 0.27e2*_hc0[2]*_t1*_t13*_t2 + (0.27e2 / 0.20e2)*_hc0[9]*_t1*_t2*_t7 - 0.81e2 / 0.10e2*_t10*_t16 - 0.81e2 / 0.2e1*_t4/xc_powi(rs, 7);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_a1_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_C5_k, _KMAX)(p, rs, z, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_C3_k, _KMAX)(p, rs, z, _hc2);
  const double _t1 = xc_powi((_hc0[0]), 8);
  const double _t2 = xc_powi((_hc0[0]), 6);
  const double _t3 = 0.4e1*_t2;
#if _KMAX >= 1
  const double _t4 = xc_powi((_hc0[0]), 5);
  const double _t5 = _hc0[1]*_t4;
  const double _t6 = 0.24e2*_t5;
  const double _t7 = xc_powi((_hc0[0]), 7)*_hc0[1];
  const double _t8 = 0.8e1*_t7;
#endif
#if _KMAX >= 2
  const double _t9 = 0.48e2*_t5;
  const double _t10 = 0.16e2*_t7;
  const double _t11 = ((_hc0[1]) * (_hc0[1]));
  const double _t12 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t13 = _t11*_t12;
  const double _t14 = 0.120e3*_t13;
  const double _t15 = _t11*_t2;
  const double _t16 = 0.56e2*_t15;
#endif
#if _KMAX >= 3
  const double _t17 = 0.72e2*_t5;
  const double _t18 = 0.24e2*_t7;
  const double _t19 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t20 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]))*_t19;
  const double _t21 = 0.480e3*_t20;
  const double _t22 = 0.360e3*_t13;
  const double _t23 = _t19*_t4;
  const double _t24 = 0.336e3*_t23;
  const double _t25 = 0.168e3*_t15;
#endif
#if _KMAX >= 4
  const double _t26 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
#endif

  const double f = _hc1[0]*_t1 + _hc2[0]*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc1[1]*_t1 + _hc2[1]*_t3;
  out[1] = df_dz;
  const double df_drs = _hc1[0]*_t8 + _hc1[2]*_t1 + _hc2[0]*_t6 + _hc2[2]*_t3;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc1[3]*_t1 + _hc2[3]*_t3;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc1[1]*_t8 + _hc1[4]*_t1 + _hc2[1]*_t6 + _hc2[4]*_t3;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc1[0]*_t16 + _hc1[2]*_t10 + _hc1[5]*_t1 + _hc2[0]*_t14 + _hc2[2]*_t9 + _hc2[5]*_t3;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc1[6]*_t1;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc1[3]*_t8 + _hc1[7]*_t1 + _hc2[3]*_t6 + _hc2[7]*_t3;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc1[1]*_t16 + _hc1[4]*_t10 + _hc1[8]*_t1 + _hc2[1]*_t14 + _hc2[4]*_t9 + _hc2[8]*_t3;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc1[0]*_t24 + _hc1[2]*_t25 + _hc1[5]*_t18 + _hc1[9]*_t1 + _hc2[0]*_t21 + _hc2[2]*_t22 + _hc2[5]*_t17 + _hc2[9]*_t3;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _hc1[10]*_t1;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc1[11]*_t1 + _hc1[6]*_t8;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc1[12]*_t1 + _hc1[3]*_t16 + _hc1[7]*_t10 + _hc2[12]*_t3 + _hc2[3]*_t14 + _hc2[7]*_t9;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc1[1]*_t24 + _hc1[13]*_t1 + _hc1[4]*_t25 + _hc1[8]*_t18 + _hc2[1]*_t21 + _hc2[13]*_t3 + _hc2[4]*_t22 + _hc2[8]*_t17;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 0.1440e4*((_hc0[0]) * (_hc0[0]))*_hc2[0]*_t26 + 0.1680e4*_hc1[0]*_t12*_t26 + _hc1[14]*_t1 + 0.1344e4*_hc1[2]*_t23 + 0.336e3*_hc1[5]*_t15 + 0.32e2*_hc1[9]*_t7 + _hc2[14]*_t3 + 0.1920e4*_hc2[2]*_t20 + 0.720e3*_hc2[5]*_t13 + 0.96e2*_hc2[9]*_t5;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_a2_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_C4_k, _KMAX)(p, rs, z, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_C2_k, _KMAX)(p, rs, z, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, rs, z, _hc3);
  const double _t1 = xc_powi((_hc0[0]), 8);
  const double _t2 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t3 = 0.6e1*_t2;
  const double _t4 = xc_powi((_hc0[0]), 6);
  const double _t5 = 0.4e1*_t4;
#if _KMAX >= 1
  const double _t6 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t7 = 0.24e2*_hc0[1];
  const double _t8 = _t6*_t7;
  const double _t9 = xc_powi((_hc0[0]), 5);
  const double _t10 = _t7*_t9;
  const double _t11 = xc_powi((_hc0[0]), 7)*_hc0[1];
  const double _t12 = 0.8e1*_t11;
#endif
#if _KMAX >= 2
  const double _t13 = 0.48e2*_hc0[1];
  const double _t14 = _t13*_t6;
  const double _t15 = _t13*_t9;
  const double _t16 = 0.16e2*_t11;
  const double _t17 = ((_hc0[1]) * (_hc0[1]));
  const double _t18 = ((_hc0[0]) * (_hc0[0]));
  const double _t19 = _t17*_t18;
  const double _t20 = 0.72e2*_t19;
  const double _t21 = _t17*_t2;
  const double _t22 = 0.120e3*_t21;
  const double _t23 = _t17*_t4;
  const double _t24 = 0.56e2*_t23;
#endif
#if _KMAX >= 3
  const double _t25 = 0.144e3*_hc3[0];
  const double _t26 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t27 = _hc0[0]*_t26;
  const double _t28 = 0.72e2*_hc0[1];
  const double _t29 = _t28*_t6;
  const double _t30 = _t28*_t9;
  const double _t31 = 0.24e2*_t11;
  const double _t32 = 0.216e3*_t19;
  const double _t33 = _t26*_t6;
  const double _t34 = 0.480e3*_t33;
  const double _t35 = 0.360e3*_t21;
  const double _t36 = _t26*_t9;
  const double _t37 = 0.336e3*_t36;
  const double _t38 = 0.168e3*_t23;
#endif
#if _KMAX >= 4
  const double _t39 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t40 = 0.96e2*_hc0[1];
#endif

  const double f = _hc1[0]*_t1 + _hc2[0]*_t5 + _hc3[0]*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc1[1]*_t1 + _hc2[1]*_t5 + _hc3[1]*_t3;
  out[1] = df_dz;
  const double df_drs = _hc1[0]*_t12 + _hc1[2]*_t1 + _hc2[0]*_t10 + _hc2[2]*_t5 + _hc3[0]*_t8 + _hc3[2]*_t3;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc1[3]*_t1 + _hc2[3]*_t5 + _hc3[3]*_t3;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc1[1]*_t12 + _hc1[4]*_t1 + _hc2[1]*_t10 + _hc2[4]*_t5 + _hc3[1]*_t8 + _hc3[4]*_t3;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc1[0]*_t24 + _hc1[2]*_t16 + _hc1[5]*_t1 + _hc2[0]*_t22 + _hc2[2]*_t15 + _hc2[5]*_t5 + _hc3[0]*_t20 + _hc3[2]*_t14 + _hc3[5]*_t3;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc1[6]*_t1 + _hc3[6]*_t3;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc1[3]*_t12 + _hc1[7]*_t1 + _hc2[3]*_t10 + _hc2[7]*_t5 + _hc3[3]*_t8 + _hc3[7]*_t3;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc1[1]*_t24 + _hc1[4]*_t16 + _hc1[8]*_t1 + _hc2[1]*_t22 + _hc2[4]*_t15 + _hc2[8]*_t5 + _hc3[1]*_t20 + _hc3[4]*_t14 + _hc3[8]*_t3;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc1[0]*_t37 + _hc1[2]*_t38 + _hc1[5]*_t31 + _hc1[9]*_t1 + _hc2[0]*_t34 + _hc2[2]*_t35 + _hc2[5]*_t30 + _hc2[9]*_t5 + _hc3[2]*_t32 + _hc3[5]*_t29 + _hc3[9]*_t3 + _t25*_t27;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _hc1[10]*_t1 + _hc3[10]*_t3;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc1[11]*_t1 + _hc1[6]*_t12 + _hc3[11]*_t3 + _hc3[6]*_t8;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc1[12]*_t1 + _hc1[3]*_t24 + _hc1[7]*_t16 + _hc2[12]*_t5 + _hc2[3]*_t22 + _hc2[7]*_t15 + _hc3[12]*_t3 + _hc3[3]*_t20 + _hc3[7]*_t14;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc1[1]*_t37 + _hc1[13]*_t1 + _hc1[4]*_t38 + _hc1[8]*_t31 + _hc2[1]*_t34 + _hc2[13]*_t5 + _hc2[4]*_t35 + _hc2[8]*_t30 + 0.144e3*_hc3[1]*_t27 + _hc3[13]*_t3 + _hc3[4]*_t32 + _hc3[8]*_t29;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 0.1680e4*_hc1[0]*_t2*_t39 + _hc1[14]*_t1 + 0.1344e4*_hc1[2]*_t36 + 0.336e3*_hc1[5]*_t23 + 0.32e2*_hc1[9]*_t11 + 0.1440e4*_hc2[0]*_t18*_t39 + _hc2[14]*_t5 + 0.1920e4*_hc2[2]*_t33 + 0.720e3*_hc2[5]*_t21 + _hc2[9]*_t40*_t9 + _hc3[14]*_t3 + 0.576e3*_hc3[2]*_t27 + 0.432e3*_hc3[5]*_t19 + _hc3[9]*_t40*_t6 + _t25*_t39;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_a3_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_C3_k, _KMAX)(p, rs, z, _hc1);
  const double _t1 = xc_powi((_hc0[0]), 8);
#if _KMAX >= 1
  const double _t2 = xc_powi((_hc0[0]), 7)*_hc0[1];
  const double _t3 = 0.8e1*_t2;
#endif
#if _KMAX >= 2
  const double _t4 = 0.16e2*_t2;
  const double _t5 = xc_powi((_hc0[0]), 6)*((_hc0[1]) * (_hc0[1]));
  const double _t6 = 0.56e2*_t5;
#endif
#if _KMAX >= 3
  const double _t7 = 0.24e2*_t2;
  const double _t8 = xc_powi((_hc0[0]), 5)*((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t9 = 0.336e3*_t8;
  const double _t10 = 0.168e3*_t5;
#endif

  const double f = _hc1[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc1[1]*_t1;
  out[1] = df_dz;
  const double df_drs = _hc1[0]*_t3 + _hc1[2]*_t1;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc1[3]*_t1;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc1[1]*_t3 + _hc1[4]*_t1;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc1[0]*_t6 + _hc1[2]*_t4 + _hc1[5]*_t1;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc1[3]*_t3 + _hc1[7]*_t1;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc1[1]*_t6 + _hc1[4]*_t4 + _hc1[8]*_t1;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc1[0]*_t9 + _hc1[2]*_t10 + _hc1[5]*_t7 + _hc1[9]*_t1;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = 0;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = 0;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc1[12]*_t1 + _hc1[3]*_t6 + _hc1[7]*_t4;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc1[1]*_t9 + _hc1[13]*_t1 + _hc1[4]*_t10 + _hc1[8]*_t7;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 0.1680e4*((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]))*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[0] + _hc1[14]*_t1 + 0.1344e4*_hc1[2]*_t8 + 0.336e3*_hc1[5]*_t5 + 0.32e2*_hc1[9]*_t2;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_a4_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_C2_k, _KMAX)(p, rs, z, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, rs, z, _hc2);
  const double _t1 = xc_powi((_hc0[0]), 8);
  const double _t2 = xc_powi((_hc0[0]), 6);
  const double _t3 = 0.4e1*_t2;
#if _KMAX >= 1
  const double _t4 = xc_powi((_hc0[0]), 5);
  const double _t5 = _hc0[1]*_t4;
  const double _t6 = 0.24e2*_t5;
  const double _t7 = xc_powi((_hc0[0]), 7)*_hc0[1];
  const double _t8 = 0.8e1*_t7;
#endif
#if _KMAX >= 2
  const double _t9 = 0.48e2*_t5;
  const double _t10 = 0.16e2*_t7;
  const double _t11 = ((_hc0[1]) * (_hc0[1]));
  const double _t12 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t13 = _t11*_t12;
  const double _t14 = 0.120e3*_t13;
  const double _t15 = _t11*_t2;
  const double _t16 = 0.56e2*_t15;
#endif
#if _KMAX >= 3
  const double _t17 = 0.72e2*_t5;
  const double _t18 = 0.24e2*_t7;
  const double _t19 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t20 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]))*_t19;
  const double _t21 = 0.480e3*_t20;
  const double _t22 = 0.360e3*_t13;
  const double _t23 = _t19*_t4;
  const double _t24 = 0.336e3*_t23;
  const double _t25 = 0.168e3*_t15;
#endif
#if _KMAX >= 4
  const double _t26 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
#endif

  const double f = _hc1[0]*_t1 + _hc2[0]*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc1[1]*_t1 + _hc2[1]*_t3;
  out[1] = df_dz;
  const double df_drs = _hc1[0]*_t8 + _hc1[2]*_t1 + _hc2[0]*_t6 + _hc2[2]*_t3;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc1[3]*_t1 + _hc2[3]*_t3;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc1[1]*_t8 + _hc1[4]*_t1 + _hc2[1]*_t6 + _hc2[4]*_t3;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc1[0]*_t16 + _hc1[2]*_t10 + _hc1[5]*_t1 + _hc2[0]*_t14 + _hc2[2]*_t9 + _hc2[5]*_t3;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc2[6]*_t3;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc1[3]*_t8 + _hc1[7]*_t1 + _hc2[3]*_t6 + _hc2[7]*_t3;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc1[1]*_t16 + _hc1[4]*_t10 + _hc1[8]*_t1 + _hc2[1]*_t14 + _hc2[4]*_t9 + _hc2[8]*_t3;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc1[0]*_t24 + _hc1[2]*_t25 + _hc1[5]*_t18 + _hc1[9]*_t1 + _hc2[0]*_t21 + _hc2[2]*_t22 + _hc2[5]*_t17 + _hc2[9]*_t3;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _hc2[10]*_t3;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc2[11]*_t3 + _hc2[6]*_t6;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc1[12]*_t1 + _hc1[3]*_t16 + _hc1[7]*_t10 + _hc2[12]*_t3 + _hc2[3]*_t14 + _hc2[7]*_t9;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc1[1]*_t24 + _hc1[13]*_t1 + _hc1[4]*_t25 + _hc1[8]*_t18 + _hc2[1]*_t21 + _hc2[13]*_t3 + _hc2[4]*_t22 + _hc2[8]*_t17;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 0.1440e4*((_hc0[0]) * (_hc0[0]))*_hc2[0]*_t26 + 0.1680e4*_hc1[0]*_t12*_t26 + _hc1[14]*_t1 + 0.1344e4*_hc1[2]*_t23 + 0.336e3*_hc1[5]*_t15 + 0.32e2*_hc1[9]*_t7 + _hc2[14]*_t3 + 0.1920e4*_hc2[2]*_t20 + 0.720e3*_hc2[5]*_t13 + 0.96e2*_hc2[9]*_t5;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_a5_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, rs, z, _hc1);
  const double _t1 = xc_powi((_hc0[0]), 8);
#if _KMAX >= 1
  const double _t2 = xc_powi((_hc0[0]), 7)*_hc0[1];
  const double _t3 = 0.8e1*_t2;
#endif
#if _KMAX >= 2
  const double _t4 = 0.16e2*_t2;
  const double _t5 = xc_powi((_hc0[0]), 6)*((_hc0[1]) * (_hc0[1]));
  const double _t6 = 0.56e2*_t5;
#endif
#if _KMAX >= 3
  const double _t7 = 0.24e2*_t2;
  const double _t8 = xc_powi((_hc0[0]), 5)*((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t9 = 0.336e3*_t8;
  const double _t10 = 0.168e3*_t5;
#endif

  const double f = _hc1[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc1[1]*_t1;
  out[1] = df_dz;
  const double df_drs = _hc1[0]*_t3 + _hc1[2]*_t1;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc1[3]*_t1;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc1[1]*_t3 + _hc1[4]*_t1;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc1[0]*_t6 + _hc1[2]*_t4 + _hc1[5]*_t1;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc1[6]*_t1;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc1[3]*_t3 + _hc1[7]*_t1;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc1[1]*_t6 + _hc1[4]*_t4 + _hc1[8]*_t1;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc1[0]*_t9 + _hc1[2]*_t10 + _hc1[5]*_t7 + _hc1[9]*_t1;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _hc1[10]*_t1;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc1[11]*_t1 + _hc1[6]*_t3;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc1[12]*_t1 + _hc1[3]*_t6 + _hc1[7]*_t4;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc1[1]*_t9 + _hc1[13]*_t1 + _hc1[4]*_t10 + _hc1[8]*_t7;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 0.1680e4*((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]))*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[0] + _hc1[14]*_t1 + 0.1344e4*_hc1[2]*_t8 + 0.336e3*_hc1[5]*_t5 + 0.32e2*_hc1[9]*_t2;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_f_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_a1_k, _KMAX)(p, rs, z, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_a2_k, _KMAX)(p, rs, z, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_a3_k, _KMAX)(p, rs, z, _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_a4_k, _KMAX)(p, rs, z, _hc4);
  double _hc5[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_a5_k, _KMAX)(p, rs, z, _hc5);
  double _hc6[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_phin_k, _KMAX)(p, 0.2e1, z, _hc6);
  const double _t1 = (0.1e1 / (_hc6[0]));
  const double _t2 = xc_powr(rs, 1, 2);
  const double _t3 = _t2*p->cam_omega;
  const double _t4 = _t1*_t3;
  const double _t5 = ((_hc0[0]) * (_hc0[0]));
  const double _t6 = ((p->cam_omega) * (p->cam_omega));
  const double _t7 = _t5*_t6 + 0.1e1;
  const double _t8 = (0.1e1 / (_t7 * _t7 * _t7 * _t7));
  const double _t9 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t10 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t11 = xc_powi((p->cam_omega), 5);
  const double _t12 = xc_powi((p->cam_omega), 6);
  const double _t13 = xc_powi((p->cam_omega), 8);
  const double _t14 = ((_hc6[0]) * (_hc6[0]) * (_hc6[0]));
#if _KMAX >= 1
  const double _t17 = ((_hc6[0]) * (_hc6[0]));
  const double _t18 = 0.3e1*_t17;
  const double _t22 = (0.1e1 / _t2);
  const double _t23 = _t22*p->cam_omega;
  const double _t26 = xc_powi(_t7, -5);
  const double _t27 = _t26*_t6;
  const double _t28 = 0.8e1*_t27;
  const double _t29 = _hc0[0]*_hc0[1];
  const double _t30 = _t28*_t29;
#endif
#if _KMAX >= 2
  const double _t31 = ((_hc6[1]) * (_hc6[1]));
  const double _t39 = (0.1e1 / 0.2e1)*_hc6[1];
  const double _t43 = ((_hc0[1]) * (_hc0[1]));
  const double _t45 = _t10/xc_powi(_t7, 6);
  const double _t46 = _t45*_t5;
  const double _t47 = 0.80e2*_t46;
  const double _t48 = _t27*_t29;
  const double _t49 = 0.16e2*_t48;
  const double _t50 = (0.1e1 / rs);
  const double _t52 = xc_powr(rs, 3, 2);
  const double _t53 = (0.1e1 / _t52);
#endif
#if _KMAX >= 3
  const double _t56 = ((_hc6[1]) * (_hc6[1]) * (_hc6[1]));
  const double _t57 = 0.18e2*_hc6[0];
  const double _t60 = _hc6[1]*_hc6[3];
  const double _t61 = 0.3e1*rs;
  const double _t63 = (0.1e1 / _t17);
  const double _t65 = (0.1e1 / _t14);
  const double _t74 = _t28*_t43;
  const double _t75 = _t43*_t47;
  const double _t76 = _t53*p->cam_omega;
  const double _t77 = _hc6[1]*_t1;
  const double _t80 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t82 = 0.240e3*_t45;
  const double _t83 = _hc0[0]*_t82;
  const double _t84 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t85 = xc_powi(_t7, -7);
  const double _t86 = 0.960e3*_t12*_t84*_t85;
  const double _t87 = 0.24e2*_t27*_t43;
  const double _t88 = _t43*_t5*_t82;
  const double _t89 = 0.24e2*_t48;
  const double _t91 = (rs * rs);
  const double _t92 = (0.1e1 / _t91);
  const double _t93 = xc_powr(rs, -5, 2);
  const double _t94 = (0.3e1 / 0.8e1)*_t93;
#endif
#if _KMAX >= 4
  const double _t96 = ((_hc6[3]) * (_hc6[3]));
  const double _t97 = 0.36e2*_hc6[3];
  const double _t98 = _hc6[1]*_hc6[6];
  const double _t100 = _hc6[3]*_t31;
  const double _t101 = 0.3e1*_t60;
  const double _t102 = (0.1e1 / 0.2e1)*_t76;
  const double _t103 = (0.1e1 / 0.4e1)*_t31;
  const double _t105 = (0.3e1 / 0.4e1)*_hc6[1];
  const double _t106 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
#endif
  double _hc7[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_Q_k, _KMAX)(p, _t4, _hc7);
  double _hc8[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, rs, z, _hc8);
  const double _t15 = _hc1[0]*_t9 + _hc2[0]*_t10 + _hc3[0]*_t11 + _hc4[0]*_t12 + _hc5[0]*_t13 + _hc7[0]*_t14;
#if _KMAX >= 1
  const double _t16 = _hc6[1]*_hc7[0];
  const double _t19 = _hc6[0]*_hc7[1];
  const double _t20 = _t19*_t3;
  const double _t21 = _hc1[1]*_t9 + _hc2[1]*_t10 + _hc3[1]*_t11 + _hc4[1]*_t12 + _hc5[1]*_t13 - _hc6[1]*_t20 + _t16*_t18;
  const double _t24 = _hc7[1]*_t17;
  const double _t25 = _hc1[2]*_t9 + _hc2[2]*_t10 + _hc3[2]*_t11 + _hc4[2]*_t12 + _hc5[2]*_t13 + (0.1e1 / 0.2e1)*_t23*_t24;
#endif
#if _KMAX >= 2
  const double _t32 = 0.6e1*_hc7[0];
  const double _t33 = _hc7[0]*_t18;
  const double _t34 = _hc7[1]*_t31;
  const double _t35 = _hc7[2]*_t6;
  const double _t36 = _t1*_t35;
  const double _t37 = _t31*_t36;
  const double _t38 = _hc1[3]*_t9 + _hc2[3]*_t10 + _hc3[3]*_t11 + _hc4[3]*_t12 + _hc5[3]*_t13 + _hc6[0]*_t31*_t32 - _hc6[3]*_t20 + _hc6[3]*_t33 - 0.4e1*_t3*_t34 + _t37*rs;
  const double _t40 = _t35*_t39;
  const double _t41 = _t19*_t23;
  const double _t42 = _hc1[4]*_t9 + _hc2[4]*_t10 + _hc3[4]*_t11 + _hc4[4]*_t12 + _hc5[4]*_t13 + _hc6[1]*_t41 - _t40;
  const double _t44 = _t15*_t43;
  const double _t51 = _hc6[0]*_t35;
  const double _t54 = _t24*p->cam_omega;
  const double _t55 = _hc1[5]*_t9 + _hc2[5]*_t10 + _hc3[5]*_t11 + _hc4[5]*_t12 + _hc5[5]*_t13 + (0.1e1 / 0.4e1)*_t50*_t51 - 0.1e1 / 0.4e1*_t53*_t54;
#endif
#if _KMAX >= 3
  const double _t58 = _hc7[1]*_t3;
  const double _t59 = 0.12e2*_t58;
  const double _t62 = _t36*_t61;
  const double _t64 = _t35*_t63;
  const double _t66 = _hc7[3]*_t9;
  const double _t67 = _t52*_t65*_t66;
  const double _t68 = _hc1[6]*_t9 + _hc2[6]*_t10 + _hc3[6]*_t11 + _hc4[6]*_t12 + _hc5[6]*_t13 + _hc6[3]*_t16*_t57 - _hc6[6]*_t20 + _hc6[6]*_t33 - 0.6e1*_hc7[1]*_t4*_t56 + _t32*_t56 + _t56*_t61*_t64 - _t56*_t67 - _t59*_t60 + _t60*_t62;
  const double _t69 = (0.1e1 / 0.2e1)*_t35;
  const double _t70 = _hc6[3]*_t69;
  const double _t71 = _t63*_t66;
  const double _t72 = _t2*_t71;
  const double _t73 = _hc1[7]*_t9 + _hc2[7]*_t10 + _hc3[7]*_t11 + _hc4[7]*_t12 + _hc5[7]*_t13 + _hc6[3]*_t41 + _t23*_t34 + (0.1e1 / 0.2e1)*_t31*_t72 - _t37 - _t70;
  const double _t78 = (0.1e1 / 0.4e1)*_t22*_t66;
  const double _t79 = _hc1[8]*_t9 + _hc2[8]*_t10 + _hc3[8]*_t11 + _hc4[8]*_t12 + _hc5[8]*_t13 - _t19*_t39*_t76 + _t40*_t50 - _t77*_t78;
  const double _t81 = _t15*_t80;
  const double _t90 = _t53*_t66;
  const double _t95 = _hc1[9]*_t9 + _hc2[9]*_t10 + _hc3[9]*_t11 + _hc4[9]*_t12 + _hc5[9]*_t13 - 0.3e1 / 0.8e1*_t51*_t92 + _t54*_t94 + (0.1e1 / 0.8e1)*_t90;
#endif
#if _KMAX >= 4
  const double _t99 = _hc7[4]*_t10;
  const double _t104 = _t21*_t80;
  const double _t107 = _t106*_t15;
#endif

  const double f = _hc8[0] - _t15*_t8;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc8[1] - _t21*_t8;
  out[1] = df_dz;
  const double df_drs = _hc8[2] + _t15*_t30 - _t25*_t8;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc8[3] - _t38*_t8;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc8[4] + _t21*_t30 - _t42*_t8;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc8[5] + _t25*_t49 + _t28*_t44 - _t44*_t47 - _t55*_t8;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc8[6] - _t68*_t8;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc8[7] + _t30*_t38 - _t73*_t8;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc8[8] + _t21*_t74 - _t21*_t75 + _t42*_t49 - _t79*_t8;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc8[9] + _t25*_t87 - _t25*_t88 + _t55*_t89 - _t8*_t95 - _t81*_t83 + _t81*_t86;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _hc8[10] - _t8*(_hc1[10]*_t9 + _hc2[10]*_t10 + _hc3[10]*_t11 + _hc4[10]*_t12 + _hc5[10]*_t13 + 0.24e2*_hc6[0]*_hc6[6]*_t16 - _hc6[10]*_t20 + _hc6[10]*_t33 + _hc7[0]*_t31*_t97 + _hc7[0]*_t57*_t96 + 0.18e2*_t100*_t64*rs - 0.6e1*_t100*_t67 - _t34*_t4*_t97 + 0.4e1*_t36*_t98*rs - 0.16e2*_t58*_t98 - _t59*_t96 + _t62*_t96 + ((_hc6[1]) * (_hc6[1]) * (_hc6[1]) * (_hc6[1]))*_t91*_t99/xc_powi((_hc6[0]), 5));
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc8[11] + _t30*_t68 - _t8*(_hc1[11]*_t9 + _hc2[11]*_t10 + _hc3[11]*_t11 + _hc4[11]*_t12 + _hc5[11]*_t13 + _hc6[6]*_t41 - _hc6[6]*_t69 + _hc7[1]*_t101*_t23 - _t101*_t36 + (0.3e1 / 0.2e1)*_t60*_t72 - 0.1e1 / 0.2e1*_t56*_t99*rs/((_hc6[0]) * (_hc6[0]) * (_hc6[0]) * (_hc6[0])));
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc8[12] + _t38*_t74 - _t38*_t75 + _t49*_t73 - _t8*(_hc1[12]*_t9 + _hc2[12]*_t10 + _hc3[12]*_t11 + _hc4[12]*_t12 + _hc5[12]*_t13 - _hc6[3]*_t1*_t78 - _hc6[3]*_t102*_t19 + _t1*_t31*_t50*_t69 - _t102*_t34 - _t103*_t22*_t71 + _t103*_t65*_t99 + _t50*_t70);
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc8[13] - _t104*_t83 + _t104*_t86 + _t42*_t87 - _t42*_t88 + _t79*_t89 - _t8*(_hc1[13]*_t9 + _hc2[13]*_t10 + _hc3[13]*_t11 + _hc4[13]*_t12 + _hc5[13]*_t13 - 0.1e1 / 0.8e1*_hc6[1]*_t50*_t63*_t99 + _t105*_t19*_t93*p->cam_omega - _t105*_t35*_t92 + (0.3e1 / 0.8e1)*_t77*_t90);
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = -0.13440e5*((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]))*_t107*_t13/xc_powi(_t7, 8) + 0.32e2*_hc0[0]*_hc0[1]*_t26*_t6*_t95 - 0.960e3*_hc0[0]*_t25*_t45*_t80 + _hc8[14] + 0.5760e4*_t106*_t12*_t15*_t5*_t85 - _t107*_t82 + 0.3840e4*_t12*_t25*_t80*_t84*_t85 + 0.48e2*_t26*_t43*_t55*_t6 - 0.480e3*_t43*_t46*_t55 - _t8*(_hc1[14]*_t9 + _hc2[14]*_t10 + _hc3[14]*_t11 + _hc4[14]*_t12 + _hc5[14]*_t13 + (0.1e1 / 0.16e2)*_t1*_t92*_t99 + (0.15e2 / 0.16e2)*_t51/(rs * rs * rs) - 0.15e2 / 0.16e2*_t54/xc_powr(rs, 7, 2) - _t66*_t94);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_c_erf_gws_beta_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {
  const gga_c_pbe_erf_gws_params *params = (const gga_c_pbe_erf_gws_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, rs, z, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_f_k, _KMAX)(p, rs, z, _hc1);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = params->beta*pow(_hc1[0]*_t1, params->a_c);
#if _KMAX >= 1
  const double _t3 = params->a_c/_hc1[0];
  const double _t4 = ((_hc0[0]) * (_hc0[0]));
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = _hc1[0]*_t5;
  const double _t7 = -_hc0[1]*_t6 + _hc1[1]*_t1;
  const double _t8 = _t2*_t7;
  const double _t9 = _hc0[0]*_t8;
  const double _t10 = -_hc0[2]*_t6 + _hc1[2]*_t1;
  const double _t11 = _t2*_t3;
  const double _t12 = _hc0[0]*_t11;
#endif
#if _KMAX >= 2
  const double _t13 = _t3*_t8;
  const double _t14 = _hc1[1]*params->a_c;
  const double _t15 = (0.1e1 / ((_hc1[0]) * (_hc1[0])));
  const double _t16 = _t15*_t9;
  const double _t17 = (_t7 * _t7);
  const double _t18 = _t15*_t2;
  const double _t19 = ((params->a_c) * (params->a_c));
  const double _t20 = _t19*_t4;
  const double _t21 = _t18*_t20;
  const double _t22 = _hc1[3]*_t1;
  const double _t23 = _hc0[1]*_t5;
  const double _t24 = _hc1[1]*_t23;
  const double _t25 = _hc0[3]*_t6;
  const double _t26 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t27 = (0.1e1 / _t26);
  const double _t28 = ((_hc0[1]) * (_hc0[1]));
  const double _t29 = _t27*_t28;
  const double _t30 = 0.2e1*_hc1[0];
  const double _t31 = _t22 - 0.2e1*_t24 - _t25 + _t29*_t30;
  const double _t32 = _t10*_t11;
  const double _t33 = _hc0[0]*_t18;
  const double _t34 = _t10*_t14;
  const double _t35 = _t15*_t8;
  const double _t36 = _t10*_t20;
  const double _t37 = _hc1[2]*_t5;
  const double _t38 = _hc0[1]*_t37;
  const double _t39 = _hc0[2]*_t5;
  const double _t40 = _hc1[1]*_t39;
  const double _t41 = _hc0[4]*_t6;
  const double _t42 = 0.2e1*_hc0[1]*_hc0[2]*_hc1[0]*_t27 + _hc1[4]*_t1 - _t38 - _t40 - _t41;
  const double _t43 = _t33*params->a_c;
  const double _t44 = _hc1[2]*_t10;
  const double _t45 = (_t10 * _t10);
  const double _t46 = _hc1[5]*_t1;
  const double _t47 = 0.2e1*_t37;
  const double _t48 = _hc0[5]*_t6;
  const double _t49 = ((_hc0[2]) * (_hc0[2]));
  const double _t50 = _t27*_t49;
  const double _t51 = -_hc0[2]*_t47 + _t30*_t50 + _t46 - _t48;
#endif
#if _KMAX >= 3
  const double _t52 = _t16*params->a_c;
  const double _t53 = 0.2e1*_hc0[1];
  const double _t54 = _t14*_t35;
  const double _t55 = (0.1e1 / ((_hc1[0]) * (_hc1[0]) * (_hc1[0])));
  const double _t56 = _t55*_t9;
  const double _t57 = ((_hc1[1]) * (_hc1[1]));
  const double _t58 = 0.2e1*params->a_c;
  const double _t59 = _t57*_t58;
  const double _t60 = _t2*(_t7 * _t7 * _t7);
  const double _t61 = ((params->a_c) * (params->a_c) * (params->a_c));
  const double _t62 = _t26*_t61;
  const double _t63 = _t55*_t62;
  const double _t64 = 0.3e1*_t17;
  const double _t65 = _t19*_t33;
  const double _t66 = _hc0[1]*_t65;
  const double _t67 = _t2*_t55;
  const double _t68 = _hc1[1]*_t20;
  const double _t69 = _t67*_t68;
  const double _t70 = _hc0[1]*_t11;
  const double _t71 = 0.2e1*_t70;
  const double _t72 = _t14*_t33;
  const double _t73 = 0.2e1*_t72;
  const double _t74 = _t20*_t35;
  const double _t75 = 0.4e1*_hc1[0];
  const double _t76 = 0.2e1*_t22 - 0.4e1*_t24 - 0.2e1*_t25 + _t29*_t75;
  const double _t77 = _hc0[6]*_t6;
  const double _t78 = _hc1[3]*_t23;
  const double _t79 = _hc1[1]*_t5;
  const double _t80 = _hc0[3]*_t79;
  const double _t81 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t82 = (0.1e1 / _t81);
  const double _t83 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t84 = _t82*_t83;
  const double _t85 = 0.6e1*_hc1[0];
  const double _t86 = 0.6e1*_hc0[1]*_hc0[3]*_hc1[0]*_t27 + 0.6e1*_hc1[1]*_t27*_t28 + _hc1[6]*_t1 - _t77 - 0.3e1*_t78 - 0.3e1*_t80 - _t84*_t85;
  const double _t87 = _t10*_t43;
  const double _t88 = _t18*_t34;
  const double _t89 = _hc0[0]*_t67;
  const double _t90 = _t10*_t89;
  const double _t91 = _t10*_t19;
  const double _t92 = _t16*_t91;
  const double _t93 = 0.3e1*_hc0[1];
  const double _t94 = _t2*_t63;
  const double _t95 = _t17*_t94;
  const double _t96 = _t55*_t8;
  const double _t97 = _t36*_t96;
  const double _t98 = 0.3e1*_hc1[1];
  const double _t99 = _t10*_t21;
  const double _t100 = 0.2e1*_t74;
  const double _t101 = _hc1[3]*_t39;
  const double _t102 = _hc0[3]*_t37;
  const double _t103 = _hc0[7]*_t6;
  const double _t104 = 0.2e1*_hc1[4];
  const double _t105 = 0.2e1*_t79;
  const double _t106 = _t82*_t85;
  const double _t107 = _hc0[2]*_t28;
  const double _t108 = 0.4e1*_hc0[1]*_hc0[2]*_hc1[1]*_t27 + 0.4e1*_hc0[1]*_hc0[4]*_hc1[0]*_t27 + 0.2e1*_hc0[2]*_hc0[3]*_hc1[0]*_t27 - _hc0[4]*_t105 + 0.2e1*_hc1[2]*_t27*_t28 + _hc1[7]*_t1 - _t101 - _t102 - _t103 - _t104*_t23 - _t106*_t107;
  const double _t109 = _t18*params->a_c;
  const double _t110 = _hc0[1]*_t44;
  const double _t111 = _t34*_t89;
  const double _t112 = 0.2e1*_hc1[2];
  const double _t113 = 0.2e1*_t45;
  const double _t114 = _t11*_t51;
  const double _t115 = _t63*_t8;
  const double _t116 = _hc1[2]*_t36;
  const double _t117 = _hc0[2]*_t11;
  const double _t118 = _hc1[2]*_t43;
  const double _t119 = 0.4e1*_hc0[1]*_hc0[2]*_hc1[0]*_t27 + 0.2e1*_hc1[4]*_t1 - 0.2e1*_t38 - 0.2e1*_t40 - 0.2e1*_t41;
  const double _t120 = _hc1[5]*_t5;
  const double _t121 = _hc0[1]*_t120;
  const double _t122 = _hc0[5]*_t5;
  const double _t123 = _hc1[1]*_t122;
  const double _t124 = _hc0[8]*_t6;
  const double _t125 = _hc0[1]*_t49;
  const double _t126 = 0.4e1*_hc0[1]*_hc0[2]*_hc1[2]*_t27 + 0.2e1*_hc0[1]*_hc0[5]*_hc1[0]*_t27 + 0.4e1*_hc0[2]*_hc0[4]*_hc1[0]*_t27 - _hc0[4]*_t47 + 0.2e1*_hc1[1]*_t27*_t49 + _hc1[8]*_t1 - _t104*_t39 - _t106*_t125 - _t121 - _t123 - _t124;
  const double _t127 = _t109*_t44;
  const double _t128 = 0.2e1*_hc0[2];
  const double _t129 = ((_hc1[2]) * (_hc1[2]));
  const double _t130 = _t129*_t58;
  const double _t131 = (_t10 * _t10 * _t10);
  const double _t132 = 0.3e1*_t45;
  const double _t133 = _t132*_t19;
  const double _t134 = _t20*_t67;
  const double _t135 = _hc1[2]*_t132;
  const double _t136 = 0.2e1*_t114;
  const double _t137 = 0.2e1*_t51;
  const double _t138 = 0.4e1*_t37;
  const double _t139 = -_hc0[2]*_t138 + 0.2e1*_t46 - 0.2e1*_t48 + _t50*_t75;
  const double _t140 = _hc0[9]*_t6;
  const double _t141 = 0.3e1*_t39;
  const double _t142 = 0.3e1*_t37;
  const double _t143 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t144 = _t143*_t82;
  const double _t145 = 0.6e1*_hc0[2]*_hc0[5]*_hc1[0]*_t27 - _hc0[5]*_t142 + 0.6e1*_hc1[2]*_t27*_t49 - _hc1[5]*_t141 + _hc1[9]*_t1 - _t140 - _t144*_t85;
#endif
#if _KMAX >= 4
  const double _t146 = 0.3e1*_hc1[3];
  const double _t147 = 0.3e1*_hc0[3];
  const double _t148 = 0.6e1*_hc1[3];
  const double _t149 = (0.1e1 / ((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0])));
  const double _t150 = 0.6e1*params->a_c;
  const double _t151 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_t150;
  const double _t152 = _t150*_t57;
  const double _t153 = _hc0[1]*_t152;
  const double _t154 = _t149*_t2;
  const double _t155 = _t81*((params->a_c) * (params->a_c) * (params->a_c) * (params->a_c));
  const double _t156 = _t154*_t155;
  const double _t157 = 0.4e1*_t17;
  const double _t158 = _hc0[3]*_t65;
  const double _t159 = _t18*_t19*_t28;
  const double _t160 = _hc0[1]*_t19;
  const double _t161 = _t160*_t89;
  const double _t162 = 0.14e2*_hc1[1];
  const double _t163 = _t4*_t61;
  const double _t164 = _hc0[1]*_t163;
  const double _t165 = 0.6e1*_t164;
  const double _t166 = _hc1[3]*_t134;
  const double _t167 = 0.6e1*_hc1[1];
  const double _t168 = _t167*_t62;
  const double _t169 = _t154*_t17;
  const double _t170 = 0.11e2*_t57;
  const double _t171 = _hc0[1]*_t31;
  const double _t172 = _t109*_t167;
  const double _t173 = _t152*_t89;
  const double _t174 = _t16*_t19;
  const double _t175 = 0.5e1*_t76;
  const double _t176 = 0.4e1*_hc1[1];
  const double _t177 = _t20*_t96;
  const double _t178 = _t68*_t96;
  const double _t179 = 0.3e1*_t70;
  const double _t180 = 0.3e1*_t72;
  const double _t181 = _t21*_t31;
  const double _t182 = 0.12e2*_hc1[0];
  const double _t183 = 0.4e1*_t23;
  const double _t184 = _hc0[3]*_t5;
  const double _t185 = 0.4e1*_t79;
  const double _t186 = 0.24e2*_hc1[1];
  const double _t187 = _hc0[1]*_t27;
  const double _t188 = 0.8e1*_t187;
  const double _t189 = xc_powi((_hc0[0]), -5);
  const double _t190 = 0.24e2*_hc1[0];
  const double _t191 = _t189*_t190;
  const double _t192 = _t27*_t85;
  const double _t193 = _hc1[0]*_t82;
  const double _t194 = _t193*_t28;
  const double _t195 = _t10*_t109;
  const double _t196 = _hc0[1]*_t195;
  const double _t197 = _hc0[0]*_t10*_t154;
  const double _t198 = _t10*_t67;
  const double _t199 = _t35*_t91;
  const double _t200 = _t56*_t91;
  const double _t201 = _t149*_t155;
  const double _t202 = _t149*_t8;
  const double _t203 = _t202*_t36;
  const double _t204 = _t11*_t42;
  const double _t205 = _t42*_t43;
  const double _t206 = _hc0[1]*_t42;
  const double _t207 = _t10*_t31;
  const double _t208 = _t31*_t67;
  const double _t209 = _hc1[1]*_t36;
  const double _t210 = 0.3e1*_t42;
  const double _t211 = _t10*_t115;
  const double _t212 = 0.3e1*_hc1[4];
  const double _t213 = _hc0[4]*_t5;
  const double _t214 = 0.6e1*_hc1[2];
  const double _t215 = _hc0[1]*_hc0[2];
  const double _t216 = 0.18e2*_t193*_t215;
  const double _t217 = _hc1[1]*_t82;
  const double _t218 = 0.18e2*_hc0[4];
  const double _t219 = _hc0[2]*_t195;
  const double _t220 = _hc0[4]*_hc1[1];
  const double _t221 = 0.2e1*_t195;
  const double _t222 = 0.4e1*_hc1[4];
  const double _t223 = _t44*_t89;
  const double _t224 = 0.4e1*_hc1[2];
  const double _t225 = _t224*_t67;
  const double _t226 = _t225*_t34;
  const double _t227 = _hc0[2]*_t198;
  const double _t228 = _t214*params->a_c;
  const double _t229 = _t161*_t45;
  const double _t230 = _t154*_t45;
  const double _t231 = _t20*_t230;
  const double _t232 = 0.2e1*_hc0[4];
  const double _t233 = _t43*_t51;
  const double _t234 = _t14*_t18;
  const double _t235 = _t51*_t53;
  const double _t236 = _t19*_t56;
  const double _t237 = _t51*_t89;
  const double _t238 = 0.5e1*_t45;
  const double _t239 = _hc1[1]*_t62;
  const double _t240 = _hc1[2]*_t109;
  const double _t241 = _t240*_t42;
  const double _t242 = _t128*_t42;
  const double _t243 = _t42*_t89;
  const double _t244 = _t14*_t224;
  const double _t245 = _hc0[2]*_t65;
  const double _t246 = _t45*_t94;
  const double _t247 = _t10*_t119;
  const double _t248 = _t119*_t67;
  const double _t249 = _t21*_t42;
  const double _t250 = 0.2e1*_t126;
  const double _t251 = _t107*_t82;
  const double _t252 = _hc0[4]*_hc1[2];
  const double _t253 = _t27*_t75;
  const double _t254 = _hc0[2]*_t27;
  const double _t255 = 0.8e1*_t254;
  const double _t256 = _t129*params->a_c;
  const double _t257 = _t198*_t256;
  const double _t258 = 0.3e1*_hc0[4];
  const double _t259 = _t45*_t65;
  const double _t260 = _t133*_t18;
  const double _t261 = _hc0[2]*_t19*_t45*_t89;
  const double _t262 = 0.3e1*_t131;
  const double _t263 = _t134*_t45;
  const double _t264 = _hc0[2]*_t137;
  const double _t265 = _t10*_t65;
  const double _t266 = _t209*_t67;
  const double _t267 = _t125*_t82;
  const double _t268 = _t193*_t49;
  const double _t269 = 0.3e1*_hc1[5];
  const double _t270 = 0.3e1*_hc0[5];
  const double _t271 = 0.6e1*_hc0[2];
  const double _t272 = _t10*_t245;
  const double _t273 = 0.5e1*_t139;
  const double _t274 = 0.3e1*_t145;
  const double _t275 = 0.6e1*_hc0[5];
  const double _t276 = 0.24e2*_hc1[2];
#endif

  const double f = _t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t3*_t9;
  out[1] = df_dz;
  const double df_drs = _t10*_t12;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc0[1]*_t13 + _t12*_t31 - _t14*_t16 + _t17*_t21;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[1]*_t32 + _t12*_t42 - _t33*_t34 + _t35*_t36;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[2]*_t32 + _t12*_t51 + _t21*_t45 - _t43*_t44;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc0[3]*_t13 - _hc1[3]*_t52 + _t12*_t86 + _t31*_t71 - _t31*_t73 + _t31*_t74 - _t53*_t54 + _t56*_t59 + _t60*_t63 + _t64*_t66 - _t64*_t69 + _t74*_t76;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc0[3]*_t32 - _hc1[3]*_t87 + _t10*_t95 + _t100*_t42 + _t108*_t12 + _t31*_t99 + _t42*_t71 - _t42*_t73 - _t53*_t88 + _t59*_t90 + _t92*_t93 - _t97*_t98;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc0[1]*_t114 - _hc0[2]*_t88 + _hc0[2]*_t92 + _hc0[4]*_t32 - _hc1[4]*_t87 - _t109*_t110 + _t111*_t112 + _t113*_t66 - _t113*_t69 + _t115*_t45 - _t116*_t96 + _t117*_t42 - _t118*_t42 + _t119*_t99 + _t12*_t126 - _t51*_t72 + _t51*_t74;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[2]*_t133*_t33 + _hc0[2]*_t136 + _hc0[5]*_t32 - _hc1[5]*_t87 - _t118*_t137 + _t12*_t145 - _t127*_t128 + _t130*_t90 + _t131*_t94 - _t134*_t135 + _t139*_t99 + _t51*_t99;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = -_hc0[1]*_t146*_t35*params->a_c + _hc0[6]*_t13 - _hc1[6]*_t52 + _t100*_t86 + _t11*_t147*_t31 + _t12*(((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t191 + _hc0[1]*_hc0[3]*_t186*_t27 - _hc0[10]*_t6 + ((_hc0[3]) * (_hc0[3]))*_t192 - 0.36e2*_hc0[3]*_t194 + _hc0[6]*_hc1[0]*_t188 - _hc0[6]*_t185 + _hc1[10]*_t1 + 0.12e2*_hc1[3]*_t29 - _hc1[6]*_t183 - _t148*_t184 - _t186*_t84) + _t14*_t148*_t56 - _t146*_t31*_t43 - _t147*_t54 - _t149*_t151*_t9 - _t149*_t168*_t60 + _t153*_t96 + _t156*(_t7 * _t7 * _t7 * _t7) + _t157*_t158 - _t157*_t166 + _t159*_t64 + _t16*_t160*_t175 - _t161*_t162*_t17 + _t165*_t55*_t60 + _t169*_t170*_t20 - _t171*_t172 + 0.4e1*_t171*_t174 + _t173*_t31 - _t175*_t178 - _t176*_t177*_t31 + _t179*_t86 - _t180*_t86 + _t181*_t76 + _t21*(_t31 * _t31) + _t31*_t95 + _t74*(0.12e2*_hc0[1]*_hc0[3]*_hc1[0]*_t27 + 0.12e2*_hc1[1]*_t27*_t28 + 0.2e1*_hc1[6]*_t1 - _t182*_t84 - 0.2e1*_t77 - 0.6e1*_t78 - 0.6e1*_t80) + _t76*_t95 + _t95*(0.3e1*_t22 - 0.6e1*_t24 - 0.3e1*_t25 + _t29*_t85);
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = -_hc0[1]*_t162*_t200 + 0.4e1*_hc0[3]*_t92 + _hc0[6]*_t32 - 0.4e1*_hc1[3]*_t97 - _hc1[6]*_t87 - _t10*_t168*_t169 + _t10*_t201*_t60 + _t108*_t179 - _t108*_t180 + 0.3e1*_t108*_t74 + _t111*_t148 + _t12*(0.6e1*_hc0[1]*_hc0[2]*_hc1[3]*_t27 + 0.6e1*_hc0[1]*_hc0[3]*_hc1[2]*_t27 + 0.12e2*_hc0[1]*_hc0[4]*_hc1[1]*_t27 + 0.6e1*_hc0[1]*_hc0[7]*_hc1[0]*_t27 - _hc0[11]*_t6 + 0.6e1*_hc0[2]*_hc0[3]*_hc1[1]*_t27 + 0.2e1*_hc0[2]*_hc0[6]*_hc1[0]*_t27 + 0.24e2*_hc0[2]*_hc1[0]*_t189*_t83 + 0.6e1*_hc0[3]*_hc0[4]*_hc1[0]*_t27 - _hc0[3]*_t216 - _hc0[6]*_t37 - 0.3e1*_hc0[7]*_t79 + _hc1[11]*_t1 + 0.6e1*_hc1[4]*_t27*_t28 - _hc1[6]*_t39 - 0.3e1*_hc1[7]*_t23 - 0.18e2*_t107*_t217 - _t146*_t213 - _t184*_t212 - _t194*_t218 - _t214*_t84) - _t146*_t196 - _t146*_t205 + _t147*_t204 - _t147*_t88 - _t151*_t197 + _t153*_t198 + _t165*_t17*_t198 + _t170*_t203 - _t172*_t206 + _t173*_t42 + 0.9e1*_t174*_t206 - 0.9e1*_t178*_t42 + _t181*_t210 + 0.3e1*_t199*_t28 + 0.5e1*_t207*_t66 - 0.5e1*_t208*_t209 + _t210*_t95 + _t211*_t31 + _t211*_t76 + _t86*_t99;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc0[1]*_t226 - _hc0[2]*_t200*_t98 + _hc0[3]*_t114 - _hc0[3]*_t127 + _hc0[7]*_t32 + 0.5e1*_hc1[1]*_t116*_t202 - 0.8e1*_hc1[1]*_t229 - _hc1[3]*_t219 + _hc1[3]*_t223*_t58 - _hc1[3]*_t233 - _hc1[7]*_t87 - _t104*_t196 - _t104*_t205 - _t104*_t97 + _t108*_t117 - _t108*_t118 - 0.3e1*_t110*_t236 + _t111*_t222 - _t112*_t177*_t42 + _t113*_t158 + _t113*_t159 - _t113*_t166 - _t116*_t208 + 0.2e1*_t119*_t211 + _t119*_t249 + _t12*(_hc0[1]*_hc0[8]*_t253 - _hc0[12]*_t6 + _hc0[2]*_hc0[7]*_t253 + _hc0[3]*_hc0[5]*_t27*_t30 - _hc0[3]*_t106*_t49 - _hc0[3]*_t120 + _hc0[3]*_t224*_t254 + ((_hc0[4]) * (_hc0[4]))*_t253 - _hc0[4]*_t190*_t215*_t82 - _hc0[5]*_t106*_t28 + _hc0[5]*_t176*_t187 - _hc0[7]*_t47 - _hc0[8]*_t105 + _hc1[12]*_t1 - 0.12e2*_hc1[2]*_t251 - _hc1[3]*_t122 + 0.2e1*_hc1[3]*_t50 + 0.8e1*_hc1[4]*_t215*_t27 + 0.2e1*_hc1[5]*_t29 - 0.2e1*_hc1[7]*_t39 - 0.2e1*_hc1[8]*_t23 - 0.12e2*_t125*_t217 + _t188*_t252 + _t191*_t28*_t49 - _t213*_t222 + _t220*_t255) + _t126*_t71 + _t156*_t17*_t45 + _t163*_t17*_t227 + _t164*_t238*_t96 - _t169*_t44*_t62 + _t174*_t242 + _t174*_t51*_t93 - _t176*_t248*_t36 - 0.3e1*_t178*_t51 + _t181*_t51 - _t197*_t228*_t57 + _t199*_t215 - _t202*_t238*_t239 + _t204*_t232 + _t207*_t245 - _t220*_t221 + _t227*_t59 + 0.6e1*_t231*_t57 + _t232*_t92 - _t234*_t235 - _t234*_t242 + _t237*_t59 - _t241*_t53 + _t243*_t244 + _t246*_t31 + 0.4e1*_t247*_t66 - _t250*_t72 + _t250*_t74 + _t51*_t95 + _t99*(0.8e1*_hc0[1]*_hc0[2]*_hc1[1]*_t27 + 0.8e1*_hc0[1]*_hc0[4]*_hc1[0]*_t27 + 0.4e1*_hc0[2]*_hc0[3]*_hc1[0]*_t27 - _hc0[4]*_t185 + 0.4e1*_hc1[2]*_t27*_t28 - _hc1[4]*_t183 + 0.2e1*_hc1[7]*_t1 - 0.2e1*_t101 - 0.2e1*_t102 - 0.2e1*_t103 - _t182*_t251);
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc0[2]*_t132*_t163*_t96 + _hc0[2]*_t226 + _hc0[4]*_t136 + _hc0[5]*_t204 - _hc0[5]*_t88 + _hc0[5]*_t92 + _hc0[8]*_t32 - _hc1[2]*_t137*_t177 + 0.9e1*_hc1[2]*_t230*_t68 + 0.2e1*_hc1[5]*_t111 - _hc1[5]*_t196 - _hc1[5]*_t205 - _hc1[5]*_t97 - _hc1[8]*_t87 - _t104*_t219 - _t104*_t233 - 0.3e1*_t116*_t248 + _t117*_t250 - _t118*_t250 + _t12*(0.6e1*_hc0[1]*_hc0[2]*_hc1[5]*_t27 + 0.6e1*_hc0[1]*_hc0[5]*_hc1[2]*_t27 + 0.2e1*_hc0[1]*_hc0[9]*_hc1[0]*_t27 + 0.24e2*_hc0[1]*_hc1[0]*_t143*_t189 - _hc0[13]*_t6 + 0.12e2*_hc0[2]*_hc0[4]*_hc1[2]*_t27 + 0.6e1*_hc0[2]*_hc0[5]*_hc1[1]*_t27 + 0.6e1*_hc0[2]*_hc0[8]*_hc1[0]*_t27 + 0.6e1*_hc0[4]*_hc0[5]*_hc1[0]*_t27 - _hc0[5]*_t216 - _hc0[8]*_t142 - _hc0[9]*_t79 + _hc1[13]*_t1 - 0.18e2*_hc1[2]*_t267 + 0.6e1*_hc1[4]*_t27*_t49 - _hc1[8]*_t141 - _hc1[9]*_t23 - _t120*_t258 - _t122*_t212 - _t144*_t167 - _t218*_t268) + _t126*_t99 - _t128*_t236*_t44 - _t128*_t241 + 0.2e1*_t129*_t203 + _t130*_t243 + _t131*_t201*_t8 - _t135*_t202*_t62 - _t137*_t266 + _t139*_t211 + _t139*_t249 + _t139*_t265*_t53 - 0.2e1*_t139*_t266 + _t145*_t70 - _t145*_t72 + _t145*_t74 - _t154*_t239*_t262 + _t164*_t262*_t67 - _t167*_t197*_t256 - _t167*_t261 + _t174*_t264 + _t211*_t51 - _t212*_t263 - _t214*_t229 + _t215*_t260 - _t221*_t252 + _t222*_t223*params->a_c - _t234*_t264 - _t235*_t240 + _t235*_t265 + _t237*_t244 + 0.3e1*_t245*_t247 + _t246*(0.6e1*_hc0[1]*_hc0[2]*_hc1[0]*_t27 + 0.3e1*_hc1[4]*_t1 - 0.3e1*_t38 - 0.3e1*_t40 - 0.3e1*_t41) + _t249*_t51 + _t257*_t53 + _t258*_t259 + _t99*(0.8e1*_hc0[1]*_hc0[2]*_hc1[2]*_t27 + 0.4e1*_hc0[1]*_hc0[5]*_hc1[0]*_t27 + 0.8e1*_hc0[2]*_hc0[4]*_hc1[0]*_t27 - _hc0[4]*_t138 + 0.4e1*_hc1[1]*_t27*_t49 + 0.2e1*_hc1[8]*_t1 - 0.2e1*_t121 - 0.2e1*_t123 - 0.2e1*_t124 - _t182*_t267 - _t222*_t39);
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = -_hc0[2]*_t109*_t214*_t51 + 0.4e1*_hc0[5]*_t259 + _hc0[9]*_t32 - ((_hc1[2]) * (_hc1[2]) * (_hc1[2]))*_t150*_t197 - 0.14e2*_hc1[2]*_t261 + _hc1[5]*_t228*_t90 - 0.4e1*_hc1[5]*_t263 - _hc1[9]*_t87 + (_t10 * _t10 * _t10 * _t10)*_t156 + _t114*_t270 - _t116*_t273*_t67 + _t117*_t274 - _t118*_t274 + _t12*(-_hc0[14]*_t6 + ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t191 + _hc0[2]*_hc0[5]*_t27*_t276 + ((_hc0[5]) * (_hc0[5]))*_t192 - 0.36e2*_hc0[5]*_t268 + _hc0[9]*_hc1[0]*_t255 - _hc0[9]*_t138 + _hc1[14]*_t1 + 0.12e2*_hc1[5]*_t50 - 0.4e1*_hc1[9]*_t39 - _t120*_t275 - _t144*_t276) - _t127*_t270 + _t129*_t150*_t237 + 0.11e2*_t129*_t231 - _t131*_t154*_t214*_t62 + _t131*_t163*_t271*_t67 + _t139*_t21*_t51 + _t139*_t246 + 0.2e1*_t145*_t99 + _t21*(_t51 * _t51) - _t219*_t269 - _t225*_t36*_t51 - _t233*_t269 + _t246*_t51 + _t246*(-_t271*_t37 + 0.3e1*_t46 - 0.3e1*_t48 + _t50*_t85) + _t257*_t271 + _t260*_t49 + _t272*_t273 + 0.4e1*_t272*_t51 + _t99*(0.12e2*_hc0[2]*_hc0[5]*_hc1[0]*_t27 + 0.12e2*_hc1[2]*_t27*_t49 - 0.6e1*_hc1[5]*_t39 + 0.2e1*_hc1[9]*_t1 - 0.2e1*_t140 - _t144*_t182 - _t275*_t37);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_c_erf_gws_E_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {
  const gga_c_pbe_erf_gws_params *params = (const gga_c_pbe_erf_gws_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.2e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_f_k, _KMAX)(p, rs, z, _hc2);
  const double _t1 = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
  const double _t2 = (0.1e1 / (params->gamma));
  const double _t3 = _t2/(_t1 * _t1 * _t1);
  const double _t4 = xc_expm1(-_hc2[0]*_t3);
#if _KMAX >= 1
  const double _t5 = _t4 + 0.1e1;
  const double _t6 = -0.3e1 / 0.2e1*_hc0[2] + (0.3e1 / 0.2e1)*_hc1[2];
  const double _t7 = _t2/(_t1 * _t1 * _t1 * _t1);
  const double _t8 = _hc2[0]*_t7;
  const double _t9 = -_hc2[1]*_t3 - _t6*_t8;
  const double _t10 = _t5*_t9;
  const double _t11 = _t3*_t5;
#endif
#if _KMAX >= 2
  const double _t12 = _t5*(_t9 * _t9);
  const double _t13 = _hc2[3]*_t3;
  const double _t14 = -0.3e1 / 0.2e1*_hc0[5] - 0.3e1 / 0.2e1*_hc1[5];
  const double _t15 = _t14*_t8;
  const double _t16 = _t6*_t7;
  const double _t17 = _hc2[1]*_t16;
  const double _t18 = xc_powi(_t1, -5);
  const double _t19 = -0.2e1*_hc0[2] + 0.2e1*_hc1[2];
  const double _t20 = _t18*_t19*_t2;
  const double _t21 = _hc2[0]*_t6;
  const double _t22 = _t20*_t21;
  const double _t23 = -_t13 - _t15 - 0.2e1*_t17 - _t22;
  const double _t24 = _t23*_t5;
  const double _t25 = _hc2[2]*_t5;
  const double _t26 = _hc2[2]*_t3;
  const double _t27 = ((_hc2[2]) * (_hc2[2]));
  const double _t28 = _t27*_t5;
  const double _t29 = xc_powi(_t1, -6);
  const double _t30 = (0.1e1 / ((params->gamma) * (params->gamma)));
  const double _t31 = _t29*_t30;
#endif
#if _KMAX >= 3
  const double _t32 = _t5*(_t9 * _t9 * _t9);
  const double _t33 = -0.2e1*_t13 - 0.2e1*_t15 - 0.4e1*_t17 - 0.2e1*_t22;
  const double _t34 = _t10*_t33;
  const double _t35 = _t10*_t23;
  const double _t36 = _hc2[6]*_t3;
  const double _t37 = -0.3e1 / 0.2e1*_hc0[9] + (0.3e1 / 0.2e1)*_hc1[9];
  const double _t38 = _t37*_t8;
  const double _t39 = _t14*_t7;
  const double _t40 = 0.3e1*_hc2[1];
  const double _t41 = _hc2[3]*_t16;
  const double _t42 = -0.2e1*_hc0[5] - 0.2e1*_hc1[5];
  const double _t43 = _t2*_t21;
  const double _t44 = _t18*_t43;
  const double _t45 = _t42*_t44;
  const double _t46 = _t14*_t20;
  const double _t47 = _hc2[0]*_t46;
  const double _t48 = _t20*_t6;
  const double _t49 = -0.5e1 / 0.2e1*_hc0[2] + (0.5e1 / 0.2e1)*_hc1[2];
  const double _t50 = _t19*_t29*_t43;
  const double _t51 = _t49*_t50;
  const double _t52 = -_t36 - _t38 - _t39*_t40 - _t40*_t48 - 0.3e1*_t41 - _t45 - 0.2e1*_t47 - _t51;
  const double _t53 = _t5*_t52;
  const double _t54 = _t16*_t5;
  const double _t55 = 0.2e1*_hc2[4];
  const double _t56 = 0.2e1*_t10;
  const double _t57 = _hc2[4]*_t3;
  const double _t58 = _hc2[2]*_t16;
  const double _t59 = _t25*_t31;
  const double _t60 = _hc2[5]*_t5;
  const double _t61 = xc_powi(_t1, -7);
  const double _t62 = -0.3e1*_hc0[2] + 0.3e1*_hc1[2];
  const double _t63 = _t61*_t62;
  const double _t64 = _t28*_t30;
  const double _t65 = _hc2[5]*_t3;
  const double _t66 = _t27*_t31;
  const double _t67 = (0.1e1 / ((params->gamma) * (params->gamma) * (params->gamma)));
  const double _t68 = _t67/xc_powi(_t1, 9);
  const double _t69 = ((_hc2[2]) * (_hc2[2]) * (_hc2[2]));
  const double _t70 = _t5*_t69;
#endif
#if _KMAX >= 4
  const double _t71 = 0.6e1*_t39;
  const double _t72 = 0.6e1*_t48;
  const double _t73 = _t37*_t7;
  const double _t74 = 0.4e1*_hc2[1];
  const double _t75 = 0.3e1*_hc2[0];
  const double _t76 = _t18*_t42;
  const double _t77 = _t14*_t2*_t75;
  const double _t78 = _t2*_t6;
  const double _t79 = _t74*_t78;
  const double _t80 = _t29*_t49;
  const double _t81 = _t19*_t80;
  const double _t82 = 0.3e1*_hc2[4];
  const double _t83 = _t5*_t82;
  const double _t84 = 0.3e1*_hc2[7];
  const double _t85 = _t25*_t78;
  const double _t86 = _t10*_t3;
  const double _t87 = 0.3e1*_t57;
  const double _t88 = 0.3e1*_hc2[2]*_t10;
  const double _t89 = _hc2[4]*_t10;
  const double _t90 = 0.3e1*_t58;
  const double _t91 = _t31*_t5;
  const double _t92 = _t30*_t63;
  const double _t93 = _t28*_t68;
#endif

  const double f = _t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t10;
  out[1] = df_dz;
  const double df_drs = -_hc2[2]*_t11;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t12 + _t24;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = -_hc2[4]*_t11 - _t10*_t26 - _t16*_t25;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = -_hc2[5]*_t11 + _t28*_t31;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t32 + _t34 + _t35 + _t53;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = -_hc2[7]*_t11 - _t12*_t26 - _t24*_t26 - _t25*_t39 - _t25*_t48 - _t54*_t55 - _t56*_t57 - _t56*_t58;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = -_hc2[8]*_t11 - _t10*_t65 + _t10*_t66 - _t16*_t60 + _t55*_t59 + _t63*_t64;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = 0.3e1*_hc2[2]*_hc2[5]*_t29*_t30*_t5 - _hc2[9]*_t11 - _t68*_t70;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t10*(-_hc2[1]*_t71 - _hc2[1]*_t72 - 0.2e1*_t36 - 0.2e1*_t38 - 0.6e1*_t41 - 0.2e1*_t45 - 0.4e1*_t47 - 0.2e1*_t51) + _t12*_t23 + _t12*_t33 + _t12*(-0.3e1*_t13 - 0.3e1*_t15 - 0.6e1*_t17 - 0.3e1*_t22) + (_t23 * _t23)*_t5 + _t24*_t33 + _t5*(_t9 * _t9 * _t9 * _t9) + _t5*(-0.8e1*_hc2[1]*_t46 - _hc2[10]*_t3 - _hc2[3]*_t71 - _hc2[3]*_t72 - 0.4e1*_hc2[6]*_t16 - _t19*_t43*_t49*_t63 - _t20*_t37*_t75 - 0.2e1*_t42*_t43*_t80 - _t44*(-0.2e1*_hc0[9] + 0.2e1*_hc1[9]) - _t50*(-0.5e1 / 0.2e1*_hc0[5] - 0.5e1 / 0.2e1*_hc1[5]) - _t73*_t74 - _t76*_t77 - _t76*_t79 - _t77*_t81 - _t79*_t81 - _t8*(-0.3e1 / 0.2e1*_hc0[14] - 0.3e1 / 0.2e1*_hc1[14])) + _t52*_t56;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = -_hc2[11]*_t11 - _t12*_t87 - _t12*_t90 - 0.6e1*_t16*_t89 - _t24*_t87 - _t24*_t90 - 0.2e1*_t25*_t46 - _t25*_t73 - _t26*_t32 - _t26*_t34 - _t26*_t35 - _t26*_t53 - _t39*_t83 - _t39*_t88 - _t48*_t83 - _t48*_t88 - _t54*_t84 - _t76*_t85 - _t81*_t85 - _t84*_t86;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = -_hc2[12]*_t11 + 0.4e1*_hc2[2]*_t31*_t89 + 0.2e1*((_hc2[4]) * (_hc2[4]))*_t91 + 0.4e1*_hc2[4]*_t25*_t92 - _hc2[5]*_t16*_t56 + 0.2e1*_hc2[7]*_t59 - _hc2[8]*_t3*_t56 - 0.2e1*_hc2[8]*_t54 - _t12*_t65 + _t12*_t66 - _t24*_t65 + _t24*_t66 + _t27*_t56*_t92 - _t39*_t60 - _t48*_t60 + _t61*_t64*(-0.3e1*_hc0[5] - 0.3e1*_hc1[5]) + _t62*_t64*(-0.7e1 / 0.2e1*_hc0[2] + (0.7e1 / 0.2e1)*_hc1[2])/xc_powi(_t1, 8);
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = -_hc2[13]*_t11 + 0.3e1*_hc2[2]*_hc2[5]*_t29*_t30*_t5*_t9 + 0.3e1*_hc2[2]*_hc2[5]*_t30*_t5*_t61*_t62 + 0.3e1*_hc2[2]*_hc2[8]*_t29*_t30*_t5 + 0.3e1*_hc2[4]*_hc2[5]*_t29*_t30*_t5 - _hc2[9]*_t54 - _hc2[9]*_t86 - _t10*_t68*_t69 - _t82*_t93 - _t67*_t70*(-0.9e1 / 0.2e1*_hc0[2] + (0.9e1 / 0.2e1)*_hc1[2])/xc_powi(_t1, 10);
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = -_hc2[14]*_t11 + ((_hc2[2]) * (_hc2[2]) * (_hc2[2]) * (_hc2[2]))*_t5/(xc_powi(_t1, 12)*((params->gamma) * (params->gamma) * (params->gamma) * (params->gamma))) + 0.3e1*((_hc2[5]) * (_hc2[5]))*_t91 - 0.6e1*_hc2[5]*_t93 + 0.4e1*_hc2[9]*_t59;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_c_erf_gws_H_k, _KMAX)(const xc_func_type *p, double rs, double z, double t, double *out) {
  const gga_c_pbe_erf_gws_params *params = (const gga_c_pbe_erf_gws_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.2e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pbe_c_erf_gws_beta_k, _KMAX)(p, rs, z, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pbe_c_erf_gws_E_k, _KMAX)(p, rs, z, _hc3);
  const double _t1 = _hc3[0]*params->gamma;
  const double _t2 = (t * t);
  const double _t3 = _hc2[0]*_t2;
  const double _t4 = _t1 + _t3;
  const double _t5 = ((_hc2[0]) * (_hc2[0]));
  const double _t6 = (t * t * t * t);
  const double _t7 = ((params->gamma) * (params->gamma));
  const double _t8 = ((_hc3[0]) * (_hc3[0]))*_t7 + _t1*_t3 + _t5*_t6;
  const double _t9 = (0.1e1 / _t8);
  const double _t10 = _hc3[0]*_t9;
  const double _t11 = _t10*_t3;
  const double _t12 = _t11*_t4;
  const double _t13 = xc_log1p(_t12);
  const double _t14 = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
  const double _t15 = (_t14 * _t14 * _t14)*params->gamma;
#if _KMAX >= 1
  const double _t16 = (t * t * t);
  const double _t17 = _t16*_t5;
  const double _t18 = 0.2e1*_t17;
  const double _t19 = 0.2e1*_hc2[0];
  const double _t20 = _t10*_t4;
  const double _t21 = _t19*_t20;
  const double _t22 = _hc2[0]*_t1;
  const double _t23 = 0.2e1*_t22;
  const double _t24 = 0.4e1*_t17;
  const double _t25 = -_t23*t - _t24;
  const double _t26 = _t3*_t4;
  const double _t27 = (0.1e1 / (_t8 * _t8));
  const double _t28 = _hc3[0]*_t27;
  const double _t29 = _t26*_t28;
  const double _t30 = _t25*_t29;
  const double _t31 = _t10*_t18 + _t21*t + _t30;
  const double _t32 = _t12 + 0.1e1;
  const double _t33 = (0.1e1 / _t32);
  const double _t34 = _t15*_t33;
  const double _t35 = (0.3e1 / 0.2e1)*_hc0[2] - 0.3e1 / 0.2e1*_hc1[2];
  const double _t36 = (_t14 * _t14)*params->gamma;
  const double _t37 = _t13*_t36;
  const double _t38 = _hc3[1]*params->gamma;
  const double _t39 = _hc2[1]*_t2;
  const double _t40 = _t38 + _t39;
  const double _t41 = _t11*_t40;
  const double _t42 = _hc3[1]*_t9;
  const double _t43 = _t26*_t42;
  const double _t44 = _t20*_t39;
  const double _t45 = 0.2e1*_t6;
  const double _t46 = _hc2[0]*_t45;
  const double _t47 = 0.2e1*_t7;
  const double _t48 = _hc3[0]*_t47;
  const double _t49 = _t3*_t38;
  const double _t50 = _t1*_t39;
  const double _t51 = -_hc2[1]*_t46 - _hc3[1]*_t48 - _t49 - _t50;
  const double _t52 = _t29*_t51;
  const double _t53 = _t41 + _t43 + _t44 + _t52;
  const double _t54 = _hc3[2]*params->gamma;
  const double _t55 = _hc2[2]*_t2;
  const double _t56 = _t54 + _t55;
  const double _t57 = _t11*_t56;
  const double _t58 = _t26*_t9;
  const double _t59 = _hc3[2]*_t58;
  const double _t60 = _t20*_t55;
  const double _t61 = _t3*_t54;
  const double _t62 = _t1*_t55;
  const double _t63 = -_hc2[2]*_t46 - _hc3[2]*_t48 - _t61 - _t62;
  const double _t64 = _t29*_t63;
  const double _t65 = _t57 + _t59 + _t60 + _t64;
#endif
#if _KMAX >= 2
  const double _t66 = (0.1e1 / (_t32 * _t32));
  const double _t67 = _t15*_t66;
  const double _t68 = -_t31;
  const double _t69 = _t31*_t68;
  const double _t70 = _t2*_t5;
  const double _t71 = 0.10e2*_t70;
  const double _t72 = _t25*_t28;
  const double _t73 = _t4*_t72;
  const double _t74 = 0.4e1*_hc2[0];
  const double _t75 = _t74*t;
  const double _t76 = -_t23 - 0.12e2*_t70;
  const double _t77 = _t29*_t76;
  const double _t78 = 0.4e1*_t22;
  const double _t79 = 0.8e1*_t17;
  const double _t80 = -_t78*t - _t79;
  const double _t81 = _t26*_t80;
  const double _t82 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t83 = _hc3[0]*_t82;
  const double _t84 = _t25*_t83;
  const double _t85 = _t81*_t84;
  const double _t86 = _t10*_t71 + _t21 + _t24*_t72 + _t73*_t75 + _t77 + _t85;
  const double _t87 = _t33*_t36;
  const double _t88 = _t35*_t87;
  const double _t89 = _t53*_t67;
  const double _t90 = _hc2[0]*_hc2[1];
  const double _t91 = 0.4e1*_t16;
  const double _t92 = _t10*_t91;
  const double _t93 = _t10*_t40;
  const double _t94 = _t19*_t93;
  const double _t95 = _t4*_t42;
  const double _t96 = _t19*_t95;
  const double _t97 = 0.2e1*_t20;
  const double _t98 = _hc2[1]*_t97;
  const double _t99 = _t3*_t40;
  const double _t100 = _t72*_t99;
  const double _t101 = _t26*_t27;
  const double _t102 = _hc3[1]*_t25;
  const double _t103 = _t101*_t102;
  const double _t104 = _t39*_t4;
  const double _t105 = _t19*_t38;
  const double _t106 = 0.2e1*_t1;
  const double _t107 = _hc2[1]*_t106;
  const double _t108 = 0.8e1*_t16;
  const double _t109 = _t108*_t90;
  const double _t110 = -_t105*t - _t107*t - _t109;
  const double _t111 = _t110*_t29;
  const double _t112 = _t18*_t28;
  const double _t113 = _t19*t;
  const double _t114 = _t28*_t51;
  const double _t115 = _t114*_t4;
  const double _t116 = _t51*_t83;
  const double _t117 = _t116*_t81;
  const double _t118 = _t100 + _t103 + _t104*_t72 + _t111 + _t112*_t51 + _t113*_t115 + _t117 + _t18*_t42 + _t90*_t92 + _t94*t + _t96*t + _t98*t;
  const double _t119 = (0.3e1 / 0.2e1)*_hc0[5] + (0.3e1 / 0.2e1)*_hc1[5];
  const double _t120 = _hc0[2] - _hc1[2];
  const double _t121 = _t120*_t35*params->gamma;
  const double _t122 = _t13*_t14;
  const double _t123 = 0.2e1*_t88;
  const double _t124 = -_t53;
  const double _t125 = _hc3[3]*params->gamma;
  const double _t126 = _hc2[3]*_t2;
  const double _t127 = _t125 + _t126;
  const double _t128 = _t11*_t127;
  const double _t129 = _hc3[3]*_t58;
  const double _t130 = _t126*_t20;
  const double _t131 = 0.2e1*_t99;
  const double _t132 = 0.2e1*_t39;
  const double _t133 = _hc3[1]*_t101;
  const double _t134 = 0.2e1*_t133;
  const double _t135 = _t125*_t3;
  const double _t136 = _t1*_t126;
  const double _t137 = ((_hc2[1]) * (_hc2[1]));
  const double _t138 = ((_hc3[1]) * (_hc3[1]));
  const double _t139 = 0.2e1*_t38;
  const double _t140 = -_hc2[3]*_t46 - _hc3[3]*_t48 - _t135 - _t136 - _t137*_t45 - _t138*_t47 - _t139*_t39;
  const double _t141 = _t140*_t29;
  const double _t142 = 0.4e1*_t6;
  const double _t143 = 0.4e1*_t7;
  const double _t144 = _hc3[0]*_t143;
  const double _t145 = -_hc3[1]*_t144 - _t142*_t90 - 0.2e1*_t49 - 0.2e1*_t50;
  const double _t146 = _t145*_t26;
  const double _t147 = _t116*_t146;
  const double _t148 = _t114*_t131 + _t115*_t132 + _t128 + _t129 + _t130 + _t131*_t42 + _t132*_t93 + _t132*_t95 + _t134*_t51 + _t141 + _t147;
  const double _t149 = _t65*_t67;
  const double _t150 = _hc2[0]*_hc2[2];
  const double _t151 = _hc3[2]*_t9;
  const double _t152 = _t10*_t56;
  const double _t153 = _t152*_t19;
  const double _t154 = _t151*_t4;
  const double _t155 = _t154*_t19;
  const double _t156 = _hc2[2]*_t97;
  const double _t157 = _t3*_t56;
  const double _t158 = _t157*_t72;
  const double _t159 = _hc3[2]*_t101;
  const double _t160 = _t159*_t25;
  const double _t161 = _t4*_t55;
  const double _t162 = _t161*_t72;
  const double _t163 = _t19*_t54;
  const double _t164 = _hc2[2]*_t106;
  const double _t165 = _t108*_t150;
  const double _t166 = -_t163*t - _t164*t - _t165;
  const double _t167 = _t166*_t29;
  const double _t168 = _t28*_t63;
  const double _t169 = _t168*_t4;
  const double _t170 = _t63*_t83;
  const double _t171 = _t170*_t81;
  const double _t172 = _t112*_t63 + _t113*_t169 + _t150*_t92 + _t151*_t18 + _t153*t + _t155*t + _t156*t + _t158 + _t160 + _t162 + _t167 + _t171;
  const double _t173 = _hc3[4]*params->gamma;
  const double _t174 = _hc2[4]*_t2;
  const double _t175 = _t173 + _t174;
  const double _t176 = _t11*_t175;
  const double _t177 = _t157*_t42;
  const double _t178 = _t151*_t3;
  const double _t179 = _t178*_t40;
  const double _t180 = _hc3[4]*_t58;
  const double _t181 = _t152*_t39;
  const double _t182 = _t154*_t39;
  const double _t183 = _t55*_t93;
  const double _t184 = _t55*_t95;
  const double _t185 = _t174*_t20;
  const double _t186 = _t114*_t157;
  const double _t187 = _t133*_t63;
  const double _t188 = _t159*_t51;
  const double _t189 = _t114*_t161;
  const double _t190 = _hc2[1]*_hc2[2];
  const double _t191 = _hc3[2]*_t47;
  const double _t192 = _t173*_t3;
  const double _t193 = _t39*_t54;
  const double _t194 = _t38*_t55;
  const double _t195 = _t1*_t174;
  const double _t196 = -_hc2[4]*_t46 - _hc3[1]*_t191 - _hc3[4]*_t48 - _t190*_t45 - _t192 - _t193 - _t194 - _t195;
  const double _t197 = _t196*_t29;
  const double _t198 = _t146*_t170;
  const double _t199 = _t104*_t168 + _t168*_t99 + _t176 + _t177 + _t179 + _t180 + _t181 + _t182 + _t183 + _t184 + _t185 + _t186 + _t187 + _t188 + _t189 + _t197 + _t198;
  const double _t200 = -_t65;
  const double _t201 = _hc3[5]*params->gamma;
  const double _t202 = _hc2[5]*_t2;
  const double _t203 = _t201 + _t202;
  const double _t204 = _t11*_t203;
  const double _t205 = _hc3[5]*_t58;
  const double _t206 = _t20*_t202;
  const double _t207 = 0.2e1*_t157;
  const double _t208 = 0.2e1*_t55;
  const double _t209 = 0.2e1*_t159;
  const double _t210 = 0.2e1*_t161;
  const double _t211 = _t201*_t3;
  const double _t212 = _t1*_t202;
  const double _t213 = ((_hc2[2]) * (_hc2[2]));
  const double _t214 = ((_hc3[2]) * (_hc3[2]));
  const double _t215 = 0.2e1*_t54;
  const double _t216 = -_hc2[5]*_t46 - _hc3[5]*_t48 - _t211 - _t212 - _t213*_t45 - _t214*_t47 - _t215*_t55;
  const double _t217 = _t216*_t29;
  const double _t218 = -_hc3[2]*_t144 - _t142*_t150 - 0.2e1*_t61 - 0.2e1*_t62;
  const double _t219 = _t170*_t26;
  const double _t220 = _t218*_t219;
  const double _t221 = _t151*_t207 + _t152*_t208 + _t154*_t208 + _t168*_t207 + _t168*_t210 + _t204 + _t205 + _t206 + _t209*_t63 + _t217 + _t220;
#endif
#if _KMAX >= 3
  const double _t222 = _t20*_t74;
  const double _t223 = -_t10*_t24 - _t222*t - 0.2e1*_t30;
  const double _t224 = (0.1e1 / (_t32 * _t32 * _t32));
  const double _t225 = _t15*_t224;
  const double _t226 = _t223*_t225;
  const double _t227 = _t67*_t68;
  const double _t228 = 0.2e1*_t227;
  const double _t229 = -_t86;
  const double _t230 = _t31*_t67;
  const double _t231 = 0.24e2*_t5;
  const double _t232 = _t10*_t231;
  const double _t233 = 0.24e2*_t16;
  const double _t234 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t235 = _t28*_t4;
  const double _t236 = _t234*_t235;
  const double _t237 = 0.6e1*_t17;
  const double _t238 = _t28*_t76;
  const double _t239 = 0.30e2*_t70;
  const double _t240 = 0.6e1*_hc2[0];
  const double _t241 = _t235*_t76;
  const double _t242 = 0.6e1*t;
  const double _t243 = _hc2[0]*_t242;
  const double _t244 = _t80*_t84;
  const double _t245 = _t244*_t4;
  const double _t246 = -0.24e2*_t70 - _t78;
  const double _t247 = _t246*_t26;
  const double _t248 = _t81*_t83;
  const double _t249 = 0.2e1*_t248;
  const double _t250 = 0.6e1*_t22;
  const double _t251 = 0.12e2*_t17;
  const double _t252 = -_t250*t - _t251;
  const double _t253 = (0.1e1 / (_t8 * _t8 * _t8 * _t8));
  const double _t254 = _hc3[0]*_t253;
  const double _t255 = _t252*_t254;
  const double _t256 = _t255*_t81;
  const double _t257 = _t232*t - _t233*_t236 + _t237*_t238 + _t237*_t244 + _t239*_t72 + _t240*_t73 + _t241*_t243 + _t243*_t245 + _t247*_t84 + _t249*_t76 + _t25*_t256;
  const double _t258 = _t36*_t66;
  const double _t259 = _t258*_t35;
  const double _t260 = _t226*_t53;
  const double _t261 = 0.20e2*_t11;
  const double _t262 = _t24*_t27;
  const double _t263 = _t24*_t28;
  const double _t264 = _t40*_t72;
  const double _t265 = _t102*_t27;
  const double _t266 = _t4*_t74;
  const double _t267 = _t266*t;
  const double _t268 = 0.4e1*_hc2[1];
  const double _t269 = _t268*t;
  const double _t270 = 0.24e2*_t3;
  const double _t271 = -_hc2[1]*_t270 - _t105 - _t107;
  const double _t272 = _t110*_t235;
  const double _t273 = _t19*_t4;
  const double _t274 = _t81*_t82;
  const double _t275 = _t24*_t80;
  const double _t276 = _t116*_t80;
  const double _t277 = _hc2[1]*_t261 + _t102*_t262 + _t102*_t274 + _t104*_t238 + _t104*_t244 + _t109*_t72 + _t110*_t249 + _t110*_t263 + _t114*_t273 + _t114*_t71 + _t116*_t247 + _t116*_t275 + _t133*_t76 + _t238*_t99 + _t244*_t99 + _t256*_t51 + _t264*_t75 + _t265*_t267 + _t267*_t276 + _t269*_t73 + _t271*_t29 + _t272*_t75 + _t42*_t71 + _t94 + _t96 + _t98;
  const double _t278 = _t119*_t87;
  const double _t279 = _t121*_t33;
  const double _t280 = _t14*_t279;
  const double _t281 = _t53*_t68;
  const double _t282 = 0.2e1*_t259;
  const double _t283 = _t124*_t67;
  const double _t284 = -_t118;
  const double _t285 = _hc2[0]*_hc2[3];
  const double _t286 = _t18*_t9;
  const double _t287 = _t10*_t137;
  const double _t288 = _t10*_t127;
  const double _t289 = _t19*_t288;
  const double _t290 = _t40*_t42;
  const double _t291 = _t290*_t74;
  const double _t292 = _hc3[3]*_t9;
  const double _t293 = _t292*_t4;
  const double _t294 = _t19*_t293;
  const double _t295 = _t268*_t93;
  const double _t296 = _t268*_t95;
  const double _t297 = _hc2[3]*_t97;
  const double _t298 = _t127*_t3;
  const double _t299 = _t101*_t25;
  const double _t300 = _t265*_t4;
  const double _t301 = _t110*_t28;
  const double _t302 = _hc3[1]*_t51;
  const double _t303 = _t40*_t74;
  const double _t304 = _t114*_t303;
  const double _t305 = _t27*_t302;
  const double _t306 = _t266*_t305;
  const double _t307 = _t115*_t268;
  const double _t308 = _t125*_t19;
  const double _t309 = 0.4e1*_t38;
  const double _t310 = _hc2[1]*_t309;
  const double _t311 = _hc2[3]*_t106;
  const double _t312 = _t108*_t285;
  const double _t313 = _t108*_t137;
  const double _t314 = -_t308*t - _t310*t - _t311*t - _t312 - _t313;
  const double _t315 = 0.2e1*_t274;
  const double _t316 = _t132*_t4;
  const double _t317 = _hc2[0]*_t309;
  const double _t318 = 0.4e1*_t1;
  const double _t319 = _hc2[1]*_t318;
  const double _t320 = 0.16e2*_t16;
  const double _t321 = _t320*_t90;
  const double _t322 = -_t317*t - _t319*t - _t321;
  const double _t323 = _t116*_t26;
  const double _t324 = _t146*_t83;
  const double _t325 = _t140*_t235;
  const double _t326 = _t145*_t18;
  const double _t327 = _t113*_t4;
  const double _t328 = _t116*_t145;
  const double _t329 = _t146*_t51;
  const double _t330 = _hc3[3]*_t286 + _hc3[3]*_t299 + _t109*_t114 + _t109*_t42 + _t110*_t134 + _t110*_t324 + _t112*_t140 + _t113*_t325 + _t116*_t326 + _t126*_t73 + _t131*_t265 + _t131*_t276 + _t131*_t301 + _t132*_t264 + _t132*_t272 + _t132*_t300 + _t140*_t248 + _t255*_t329 + _t262*_t302 + _t276*_t316 + _t285*_t92 + _t287*_t91 + _t289*t + _t29*_t314 + _t291*t + _t294*t + _t295*t + _t296*t + _t297*t + _t298*_t72 + _t302*_t315 + _t304*t + _t306*t + _t307*t + _t322*_t323 + _t327*_t328;
  const double _t331 = (0.3e1 / 0.2e1)*_hc0[9] - 0.3e1 / 0.2e1*_hc1[9];
  const double _t332 = _hc0[5] + _hc1[5];
  const double _t333 = _t122*params->gamma;
  const double _t334 = _t333*_t35;
  const double _t335 = (0.1e1 / 0.2e1)*_hc0[2] - 0.1e1 / 0.2e1*_hc1[2];
  const double _t336 = _t121*_t13;
  const double _t337 = _t119*_t120;
  const double _t338 = 0.2e1*_t337;
  const double _t339 = 0.3e1*_t278;
  const double _t340 = 0.3e1*_t280;
  const double _t341 = _t124*_t53;
  const double _t342 = 0.3e1*_t259;
  const double _t343 = -0.2e1*_t41 - 0.2e1*_t43 - 0.2e1*_t44 - 0.2e1*_t52;
  const double _t344 = _t225*_t343;
  const double _t345 = 0.3e1*_t88;
  const double _t346 = 0.2e1*_t283;
  const double _t347 = -_t148;
  const double _t348 = _hc3[6]*params->gamma;
  const double _t349 = _hc2[6]*_t2;
  const double _t350 = _t348 + _t349;
  const double _t351 = 0.3e1*_t298;
  const double _t352 = 0.3e1*_t292;
  const double _t353 = 0.3e1*_t39;
  const double _t354 = 0.6e1*_t39;
  const double _t355 = 0.3e1*_t126;
  const double _t356 = 0.6e1*_t99;
  const double _t357 = _hc3[3]*_t101;
  const double _t358 = 0.3e1*_t357;
  const double _t359 = _t114*_t40;
  const double _t360 = _t354*_t4;
  const double _t361 = _t140*_t28;
  const double _t362 = 0.3e1*_t99;
  const double _t363 = 0.3e1*_t133;
  const double _t364 = 0.6e1*_t6;
  const double _t365 = _hc2[1]*_hc2[3];
  const double _t366 = 0.6e1*_t7;
  const double _t367 = _hc3[1]*_t366;
  const double _t368 = _t3*_t348;
  const double _t369 = _t125*_t39;
  const double _t370 = _t126*_t38;
  const double _t371 = -_hc2[6]*_t46 - _hc3[3]*_t367 - _hc3[6]*_t48 - _t1*_t349 - _t364*_t365 - _t368 - 0.3e1*_t369 - 0.3e1*_t370;
  const double _t372 = _t302*_t82;
  const double _t373 = 0.3e1*_t372;
  const double _t374 = _t353*_t4;
  const double _t375 = -_hc3[3]*_t144 - 0.2e1*_t135 - 0.2e1*_t136 - _t137*_t142 - _t138*_t143 - _t142*_t285 - _t309*_t39;
  const double _t376 = 0.2e1*_t324;
  const double _t377 = -_hc3[0]*_t367 - _t364*_t90 - 0.3e1*_t49 - 0.3e1*_t50;
  const double _t378 = _t254*_t377;
  const double _t379 = _hc3[6]*_t58 + _t11*_t350 + _t114*_t351 + _t115*_t355 + _t140*_t363 + _t140*_t376 + _t146*_t373 + _t20*_t349 + _t288*_t353 + _t29*_t371 + _t290*_t354 + _t293*_t353 + _t305*_t356 + _t305*_t360 + _t323*_t375 + _t325*_t353 + _t328*_t362 + _t328*_t374 + _t329*_t378 + _t351*_t42 + _t352*_t99 + _t354*_t359 + _t355*_t93 + _t355*_t95 + _t358*_t51 + _t361*_t362;
  const double _t380 = _t226*_t65;
  const double _t381 = _hc3[2]*_t25;
  const double _t382 = _t56*_t72;
  const double _t383 = _t27*_t381;
  const double _t384 = 0.4e1*_hc2[2];
  const double _t385 = _t384*t;
  const double _t386 = -_hc2[2]*_t270 - _t163 - _t164;
  const double _t387 = _t235*_t75;
  const double _t388 = _t170*_t80;
  const double _t389 = _hc2[2]*_t261 + _t151*_t71 + _t153 + _t155 + _t156 + _t157*_t238 + _t157*_t244 + _t159*_t76 + _t161*_t238 + _t161*_t244 + _t165*_t72 + _t166*_t249 + _t166*_t263 + _t166*_t387 + _t168*_t273 + _t168*_t71 + _t170*_t275 + _t219*_t246 + _t256*_t63 + _t262*_t381 + _t267*_t383 + _t267*_t388 + _t274*_t381 + _t29*_t386 + _t382*_t75 + _t385*_t73;
  const double _t390 = _t259*_t65;
  const double _t391 = _t151*_t91;
  const double _t392 = _t42*_t91;
  const double _t393 = _hc2[0]*_t92;
  const double _t394 = _t10*_t175;
  const double _t395 = _t42*_t56;
  const double _t396 = _t151*_t40;
  const double _t397 = _hc3[4]*_t9;
  const double _t398 = _t397*_t4;
  const double _t399 = 0.2e1*_hc2[1];
  const double _t400 = _t152*_t399;
  const double _t401 = _t154*_t399;
  const double _t402 = 0.2e1*_hc2[2];
  const double _t403 = _t402*_t93;
  const double _t404 = _t402*_t95;
  const double _t405 = _hc2[4]*_t97;
  const double _t406 = _t3*_t72;
  const double _t407 = _t166*_t28;
  const double _t408 = _t168*_t91;
  const double _t409 = _t150*_t91;
  const double _t410 = _t18*_t27;
  const double _t411 = _hc3[1]*_t63;
  const double _t412 = _hc3[2]*_t51;
  const double _t413 = _t168*_t40;
  const double _t414 = _t114*_t56;
  const double _t415 = _t27*_t327;
  const double _t416 = _t169*_t399;
  const double _t417 = _t115*_t402;
  const double _t418 = _t173*_t19;
  const double _t419 = _hc2[1]*_t215;
  const double _t420 = _hc2[2]*_t139;
  const double _t421 = _hc2[4]*_t106;
  const double _t422 = _hc2[0]*_t108;
  const double _t423 = _hc2[4]*_t422;
  const double _t424 = _t108*_t190;
  const double _t425 = -_t418*t - _t419*t - _t420*t - _t421*t - _t423 - _t424;
  const double _t426 = _t196*_t235;
  const double _t427 = _t145*_t170;
  const double _t428 = _t146*_t63;
  const double _t429 = _hc2[4]*_t393 + _hc3[4]*_t286 + _hc3[4]*_t299 + _t104*_t383 + _t104*_t388 + _t104*_t407 + _t110*_t159 + _t112*_t196 + _t113*_t394 + _t113*_t395 + _t113*_t396 + _t113*_t398 + _t113*_t413 + _t113*_t414 + _t113*_t426 + _t114*_t409 + _t133*_t166 + _t150*_t392 + _t157*_t265 + _t157*_t276 + _t157*_t301 + _t161*_t265 + _t161*_t276 + _t161*_t301 + _t166*_t324 + _t170*_t326 + _t174*_t73 + _t175*_t406 + _t190*_t92 + _t196*_t248 + _t219*_t322 + _t255*_t428 + _t264*_t55 + _t274*_t411 + _t274*_t412 + _t29*_t425 + _t327*_t427 + _t382*_t39 + _t383*_t99 + _t388*_t99 + _t391*_t90 + _t400*t + _t401*t + _t403*t + _t404*t + _t405*t + _t407*_t99 + _t408*_t90 + _t410*_t411 + _t410*_t412 + _t411*_t415 + _t412*_t415 + _t416*t + _t417*t;
  const double _t430 = 0.2e1*_t390;
  const double _t431 = _t344*_t65;
  const double _t432 = _hc3[7]*params->gamma;
  const double _t433 = _hc2[7]*_t2;
  const double _t434 = _t432 + _t433;
  const double _t435 = _t3*_t42;
  const double _t436 = 0.2e1*_t175;
  const double _t437 = 0.2e1*_t174;
  const double _t438 = _t114*_t3;
  const double _t439 = _t131*_t27;
  const double _t440 = _hc3[4]*_t101;
  const double _t441 = 0.2e1*_t440;
  const double _t442 = _t27*_t411;
  const double _t443 = _t27*_t412;
  const double _t444 = _t196*_t28;
  const double _t445 = _t412*_t82;
  const double _t446 = _t411*_t82;
  const double _t447 = 0.2e1*_t146;
  const double _t448 = _hc2[4]*_t142;
  const double _t449 = _hc2[2]*_hc2[3];
  const double _t450 = _hc3[4]*_t143;
  const double _t451 = _t3*_t432;
  const double _t452 = _t125*_t55;
  const double _t453 = _t126*_t54;
  const double _t454 = 0.2e1*_t173;
  const double _t455 = -_hc2[1]*_t448 - _hc2[7]*_t46 - _hc3[1]*_t450 - _hc3[3]*_t191 - _hc3[7]*_t48 - _t1*_t433 - _t139*_t174 - _t39*_t454 - _t449*_t45 - _t451 - _t452 - _t453;
  const double _t456 = _hc3[7]*_t58 + _t11*_t434 + _t115*_t437 + _t126*_t152 + _t126*_t154 + _t126*_t169 + _t127*_t178 + _t131*_t397 + _t131*_t427 + _t131*_t444 + _t132*_t394 + _t132*_t395 + _t132*_t396 + _t132*_t398 + _t132*_t413 + _t132*_t414 + _t132*_t426 + _t134*_t196 + _t140*_t159 + _t146*_t445 + _t157*_t292 + _t157*_t328 + _t157*_t361 + _t161*_t328 + _t161*_t361 + _t168*_t298 + _t196*_t376 + _t20*_t433 + _t207*_t305 + _t208*_t290 + _t208*_t359 + _t210*_t305 + _t219*_t375 + _t288*_t55 + _t29*_t455 + _t293*_t55 + _t316*_t427 + _t316*_t442 + _t316*_t443 + _t357*_t63 + _t378*_t428 + _t411*_t439 + _t412*_t439 + _t435*_t436 + _t436*_t438 + _t437*_t93 + _t437*_t95 + _t441*_t51 + _t446*_t447;
  const double _t457 = _t200*_t67;
  const double _t458 = -_t172;
  const double _t459 = _hc2[0]*_hc2[5];
  const double _t460 = _t10*_t213;
  const double _t461 = _t10*_t203;
  const double _t462 = _t151*_t56;
  const double _t463 = _t462*_t74;
  const double _t464 = _hc3[5]*_t9;
  const double _t465 = _t4*_t464;
  const double _t466 = _t152*_t384;
  const double _t467 = _t154*_t384;
  const double _t468 = _hc2[5]*_t97;
  const double _t469 = _t203*_t3;
  const double _t470 = _hc3[2]*_t262;
  const double _t471 = _t168*_t56;
  const double _t472 = _hc3[2]*_t27;
  const double _t473 = _t472*_t63;
  const double _t474 = _t266*_t473;
  const double _t475 = _t19*_t201;
  const double _t476 = 0.4e1*_t54;
  const double _t477 = _hc2[2]*_t476;
  const double _t478 = _hc2[5]*_t106;
  const double _t479 = _hc2[5]*_t422;
  const double _t480 = _t108*_t213;
  const double _t481 = -_t475*t - _t477*t - _t478*t - _t479 - _t480;
  const double _t482 = _hc3[2]*_t315;
  const double _t483 = _hc2[0]*_t476;
  const double _t484 = _hc2[2]*_t318;
  const double _t485 = _t150*_t320;
  const double _t486 = -_t483*t - _t484*t - _t485;
  const double _t487 = _t218*_t26;
  const double _t488 = _t166*_t83;
  const double _t489 = _t216*_t235;
  const double _t490 = _t170*_t218;
  const double _t491 = _t487*_t63;
  const double _t492 = _hc3[5]*_t286 + _hc3[5]*_t299 + _t112*_t216 + _t113*_t461 + _t113*_t465 + _t113*_t489 + _t151*_t165 + _t165*_t168 + _t166*_t209 + _t169*_t385 + _t18*_t490 + _t202*_t73 + _t207*_t383 + _t207*_t388 + _t207*_t407 + _t208*_t382 + _t210*_t383 + _t210*_t388 + _t210*_t407 + _t216*_t248 + _t219*_t486 + _t255*_t491 + _t29*_t481 + _t327*_t490 + _t459*_t92 + _t460*_t91 + _t463*t + _t466*t + _t467*t + _t468*t + _t469*_t72 + _t470*_t63 + _t471*_t75 + _t474*t + _t482*_t63 + _t487*_t488;
  const double _t493 = -_t199;
  const double _t494 = _hc3[8]*params->gamma;
  const double _t495 = _hc2[8]*_t2;
  const double _t496 = _t494 + _t495;
  const double _t497 = _hc3[5]*_t101;
  const double _t498 = _t168*_t3;
  const double _t499 = _t216*_t28;
  const double _t500 = _hc3[2]*_t82;
  const double _t501 = _t500*_t63;
  const double _t502 = _hc2[1]*_hc2[5];
  const double _t503 = _hc3[5]*_t47;
  const double _t504 = _t3*_t494;
  const double _t505 = _t201*_t39;
  const double _t506 = _t202*_t38;
  const double _t507 = -_hc2[2]*_t448 - _hc2[8]*_t46 - _hc3[1]*_t503 - _hc3[2]*_t450 - _hc3[8]*_t48 - _t1*_t495 - _t174*_t215 - _t45*_t502 - _t454*_t55 - _t504 - _t505 - _t506;
  const double _t508 = _t196*_t83;
  const double _t509 = _hc3[1]*_t143;
  const double _t510 = -_hc2[0]*_t448 - _hc3[2]*_t509 - _hc3[4]*_t144 - _t142*_t190 - 0.2e1*_t192 - 0.2e1*_t193 - 0.2e1*_t194 - 0.2e1*_t195;
  const double _t511 = _hc3[8]*_t58 + _t104*_t490 + _t104*_t499 + _t11*_t496 + _t114*_t469 + _t115*_t202 + _t131*_t473 + _t132*_t462 + _t132*_t471 + _t133*_t216 + _t152*_t437 + _t154*_t437 + _t169*_t437 + _t178*_t436 + _t196*_t209 + _t20*_t495 + _t202*_t93 + _t202*_t95 + _t207*_t397 + _t207*_t427 + _t207*_t442 + _t207*_t443 + _t207*_t444 + _t208*_t394 + _t208*_t395 + _t208*_t396 + _t208*_t413 + _t208*_t414 + _t210*_t397 + _t210*_t427 + _t210*_t442 + _t210*_t443 + _t210*_t444 + _t216*_t324 + _t219*_t510 + _t29*_t507 + _t316*_t473 + _t378*_t491 + _t39*_t461 + _t39*_t465 + _t42*_t469 + _t436*_t498 + _t441*_t63 + _t446*_t487 + _t447*_t501 + _t464*_t99 + _t487*_t508 + _t490*_t99 + _t497*_t51 + _t499*_t99;
  const double _t512 = -0.2e1*_t57 - 0.2e1*_t59 - 0.2e1*_t60 - 0.2e1*_t64;
  const double _t513 = _t225*_t65;
  const double _t514 = _t200*_t513;
  const double _t515 = 0.2e1*_t457;
  const double _t516 = -_t221;
  const double _t517 = _hc3[9]*params->gamma;
  const double _t518 = _hc2[9]*_t2;
  const double _t519 = _t517 + _t518;
  const double _t520 = 0.3e1*_t178;
  const double _t521 = 0.3e1*_t464;
  const double _t522 = 0.3e1*_t55;
  const double _t523 = 0.6e1*_t55;
  const double _t524 = 0.3e1*_t202;
  const double _t525 = 0.3e1*_t469;
  const double _t526 = 0.6e1*_t473;
  const double _t527 = 0.3e1*_t497;
  const double _t528 = 0.3e1*_t157;
  const double _t529 = 0.3e1*_t159;
  const double _t530 = _hc2[2]*_hc2[5];
  const double _t531 = _hc3[2]*_t366;
  const double _t532 = _t3*_t517;
  const double _t533 = -_hc2[9]*_t46 - _hc3[5]*_t531 - _hc3[9]*_t48 - _t1*_t518 - _t201*_t522 - _t364*_t530 - _t524*_t54 - _t532;
  const double _t534 = 0.3e1*_t501;
  const double _t535 = _t4*_t522;
  const double _t536 = _hc2[0]*_t142;
  const double _t537 = -_hc2[5]*_t536 - _hc3[5]*_t144 - _t142*_t213 - _t143*_t214 - 0.2e1*_t211 - 0.2e1*_t212 - _t476*_t55;
  const double _t538 = _t216*_t83;
  const double _t539 = 0.2e1*_t538;
  const double _t540 = -_hc3[0]*_t531 - _t150*_t364 - 0.3e1*_t61 - 0.3e1*_t62;
  const double _t541 = _t254*_t491;
  const double _t542 = _hc3[9]*_t58 + _t11*_t519 + _t152*_t524 + _t154*_t524 + _t157*_t521 + _t157*_t526 + _t161*_t526 + _t168*_t525 + _t169*_t524 + _t20*_t518 + _t203*_t520 + _t216*_t529 + _t219*_t537 + _t29*_t533 + _t461*_t522 + _t462*_t523 + _t465*_t522 + _t471*_t523 + _t487*_t534 + _t487*_t539 + _t489*_t522 + _t490*_t528 + _t490*_t535 + _t499*_t528 + _t527*_t63 + _t540*_t541;
#endif
#if _KMAX >= 4
  const double _t543 = _t223*_t69;
  const double _t544 = _t15/(_t32 * _t32 * _t32 * _t32);
  const double _t545 = _t544*(-_t10*_t237 - _t20*_t243 - 0.3e1*_t30);
  const double _t546 = _t226*_t68;
  const double _t547 = 0.3e1*_t546;
  const double _t548 = 0.20e2*_t70;
  const double _t549 = 0.8e1*t;
  const double _t550 = _hc2[0]*_t549;
  const double _t551 = -_t10*_t548 - _t222 - _t550*_t73 - _t72*_t79 - 0.2e1*_t77 - 0.2e1*_t85;
  const double _t552 = _t225*_t551;
  const double _t553 = _t229*_t31;
  const double _t554 = 0.2e1*_t226;
  const double _t555 = _t229*_t67;
  const double _t556 = 0.3e1*_t555;
  const double _t557 = 0.3e1*_t227;
  const double _t558 = -_t257;
  const double _t559 = _t72*t;
  const double _t560 = 0.60e2*_t70;
  const double _t561 = 0.12e2*_hc2[0];
  const double _t562 = _t80*_t83;
  const double _t563 = _t16*_t234*_t4;
  const double _t564 = 0.48e2*_t563;
  const double _t565 = _t246*_t84;
  const double _t566 = 0.16e2*_t17;
  const double _t567 = _t562*_t76;
  const double _t568 = _t4*_t550;
  const double _t569 = 0.3e1*_t247;
  const double _t570 = _t79*_t80;
  const double _t571 = _t25*_t255;
  const double _t572 = _t571*_t80;
  const double _t573 = -_t250 - 0.36e2*_t70;
  const double _t574 = _t254*_t573;
  const double _t575 = _t25*_t81;
  const double _t576 = 0.2e1*_t247;
  const double _t577 = 0.3e1*_t256;
  const double _t578 = _hc3[0]/xc_powi(_t8, 5);
  const double _t579 = _t578*(-_t22*_t549 - _t566);
  const double _t580 = _t252*_t579;
  const double _t581 = _t224*_t35*_t36;
  const double _t582 = _t259*_t68;
  const double _t583 = 0.2e1*_t582;
  const double _t584 = _t223*_t545;
  const double _t585 = 0.2e1*_t260;
  const double _t586 = 0.48e2*_t10*t;
  const double _t587 = _t231*t;
  const double _t588 = _t233*_t234;
  const double _t589 = _t28*_t40;
  const double _t590 = _hc3[1]*_t27;
  const double _t591 = _t4*_t588;
  const double _t592 = 0.72e2*_t17*_t235;
  const double _t593 = 0.12e2*_t16;
  const double _t594 = _t593*_t90;
  const double _t595 = _t237*_t590;
  const double _t596 = 0.60e2*_t406;
  const double _t597 = _t237*_t28;
  const double _t598 = _t240*_t4;
  const double _t599 = 0.6e1*_t73;
  const double _t600 = _t238*_t40;
  const double _t601 = _t590*_t76;
  const double _t602 = _t243*_t4;
  const double _t603 = _hc2[1]*_t242;
  const double _t604 = _t235*_t271;
  const double _t605 = _t235*_t240;
  const double _t606 = _t102*_t82;
  const double _t607 = _t237*_t80;
  const double _t608 = _t110*_t562;
  const double _t609 = _t244*_t40;
  const double _t610 = _t606*_t80;
  const double _t611 = _hc3[1]*_t315;
  const double _t612 = _t561*t;
  const double _t613 = _t4*_t612;
  const double _t614 = 0.3e1*_t248;
  const double _t615 = _t110*_t83;
  const double _t616 = _t237*_t246;
  const double _t617 = _t116*_t246;
  const double _t618 = _t252*_t253;
  const double _t619 = _t618*_t81;
  const double _t620 = _t255*_t51;
  const double _t621 = _t620*_t80;
  const double _t622 = _t574*_t81;
  const double _t623 = _t580*_t81;
  const double _t624 = _t119*_t258;
  const double _t625 = _t121*_t14*_t66;
  const double _t626 = _t223*_t581;
  const double _t627 = 0.2e1*_t626;
  const double _t628 = _t124*_t226;
  const double _t629 = 0.2e1*_t628;
  const double _t630 = _t284*_t67;
  const double _t631 = 0.2e1*_t630;
  const double _t632 = -_t277;
  const double _t633 = 0.40e2*_hc2[1];
  const double _t634 = 0.20e2*_t2;
  const double _t635 = _t25*_t262;
  const double _t636 = _t110*_t590;
  const double _t637 = _t559*_t74;
  const double _t638 = _t40*_t550;
  const double _t639 = _t25*_t27;
  const double _t640 = _hc3[3]*_t639;
  const double _t641 = _hc2[1]*_t549;
  const double _t642 = _hc2[3]*t;
  const double _t643 = 0.4e1*_t73;
  const double _t644 = _t271*_t28;
  const double _t645 = _t25*_t274;
  const double _t646 = _t126*_t4;
  const double _t647 = 0.24e2*_t2;
  const double _t648 = 0.4e1*_t99;
  const double _t649 = _hc3[1]*_t274;
  const double _t650 = 0.4e1*_t39;
  const double _t651 = _t4*_t650;
  const double _t652 = _t26*_t322;
  const double _t653 = 0.2e1*_t652;
  const double _t654 = _t24*_t322;
  const double _t655 = _t145*_t24;
  const double _t656 = _t372*_t80;
  const double _t657 = _t276*_t4;
  const double _t658 = 0.48e2*_t3;
  const double _t659 = -_hc2[1]*_t658 - _t317 - _t319;
  const double _t660 = _t116*_t322;
  const double _t661 = _t145*_t615;
  const double _t662 = 0.2e1*_t619;
  const double _t663 = _t140*_t83;
  const double _t664 = _t110*_t146;
  const double _t665 = 0.2e1*_t255;
  const double _t666 = _t140*_t562;
  const double _t667 = _t145*_t267;
  const double _t668 = _t331*_t87;
  const double _t669 = _t332*_t35*params->gamma;
  const double _t670 = _t14*_t33;
  const double _t671 = _t31*_t670;
  const double _t672 = _t279*_t335;
  const double _t673 = _t338*params->gamma;
  const double _t674 = 0.3e1*_t281;
  const double _t675 = _t341*_t343;
  const double _t676 = 0.3e1*_t148;
  const double _t677 = _t284*_t53;
  const double _t678 = _t124*_t344;
  const double _t679 = -_t10*_t109 - 0.2e1*_t100 - 0.2e1*_t103 - 0.2e1*_t111 - _t114*_t24 - _t115*_t75 - 0.2e1*_t117 - _t132*_t73 - _t20*_t269 - _t24*_t42 - _t75*_t93 - _t75*_t95;
  const double _t680 = _t225*_t341;
  const double _t681 = _t347*_t67;
  const double _t682 = -_t330;
  const double _t683 = 0.12e2*_hc3[3];
  const double _t684 = _t683*_t9;
  const double _t685 = _t42*_t593;
  const double _t686 = _t10*_t593;
  const double _t687 = _t10*_t350;
  const double _t688 = _t127*_t42;
  const double _t689 = _t292*_t40;
  const double _t690 = _hc3[6]*_t9;
  const double _t691 = _t4*_t690;
  const double _t692 = _hc2[1]*t;
  const double _t693 = 0.12e2*_t290;
  const double _t694 = _hc2[3]*_t242;
  const double _t695 = _t97*t;
  const double _t696 = _t127*_t72;
  const double _t697 = _t354*_t40;
  const double _t698 = _t233*_t90;
  const double _t699 = _t114*_t593;
  const double _t700 = _t237*_t27;
  const double _t701 = _hc3[3]*_t51;
  const double _t702 = _t114*_t127;
  const double _t703 = _t305*_t40;
  const double _t704 = _t27*_t701;
  const double _t705 = 0.12e2*_t692;
  const double _t706 = _t305*_t4;
  const double _t707 = _t28*_t314;
  const double _t708 = _t235*_t353;
  const double _t709 = _t242*_t38;
  const double _t710 = _t106*t;
  const double _t711 = 0.3e1*_t274;
  const double _t712 = _t355*_t4;
  const double _t713 = _t361*_t40;
  const double _t714 = _t140*_t590;
  const double _t715 = _t145*_t372;
  const double _t716 = _t235*_t371;
  const double _t717 = _t328*_t40;
  const double _t718 = _t328*_t4;
  const double _t719 = _t125*t;
  const double _t720 = -_t137*_t320 - _t285*_t320 - _t318*_t642 - _t38*_t641 - _t719*_t74;
  const double _t721 = 0.3e1*_t140;
  const double _t722 = _t26*_t375;
  const double _t723 = _t145*_t620;
  const double _t724 = _t146*_t302;
  const double _t725 = 0.3e1*_t618;
  const double _t726 = _t18*_t375;
  const double _t727 = -_hc2[0]*_t709 - _t1*_t603 - _t698;
  const double _t728 = _t254*_t329;
  const double _t729 = _t378*_t51;
  const double _t730 = _t145*_t663;
  const double _t731 = _t116*_t375;
  const double _t732 = _t145*_t729;
  const double _t733 = _t255*_t447;
  const double _t734 = _t329*_t377;
  const double _t735 = _t13*_t335;
  const double _t736 = 0.3e1*_t333;
  const double _t737 = _t337*params->gamma;
  const double _t738 = 0.4e1*_t53;
  const double _t739 = _t669*_t670;
  const double _t740 = 0.6e1*_t341;
  const double _t741 = 0.6e1*_t148;
  const double _t742 = _t544*(-0.3e1*_t41 - 0.3e1*_t43 - 0.3e1*_t44 - 0.3e1*_t52);
  const double _t743 = _t124*_t259;
  const double _t744 = 0.4e1*_t133;
  const double _t745 = -_t114*_t648 - _t115*_t650 - 0.2e1*_t128 - 0.2e1*_t129 - 0.2e1*_t130 - 0.2e1*_t141 - 0.2e1*_t147 - _t42*_t648 - _t51*_t744 - _t650*_t93 - _t650*_t95;
  const double _t746 = 0.2e1*_t347;
  const double _t747 = 0.3e1*_t681;
  const double _t748 = 0.3e1*_t283;
  const double _t749 = -_t379;
  const double _t750 = _hc3[10]*params->gamma;
  const double _t751 = _hc2[10]*_t2;
  const double _t752 = 0.4e1*_t350;
  const double _t753 = 0.6e1*_t298;
  const double _t754 = 0.12e2*_t39;
  const double _t755 = _t39*_t40;
  const double _t756 = 0.6e1*_t126;
  const double _t757 = 0.4e1*_t349;
  const double _t758 = 0.12e2*_t305;
  const double _t759 = _t27*_t51;
  const double _t760 = _t683*_t759;
  const double _t761 = _hc3[6]*_t101;
  const double _t762 = 0.4e1*_t51;
  const double _t763 = 0.12e2*_t714;
  const double _t764 = _t28*_t371;
  const double _t765 = 0.12e2*_t715;
  const double _t766 = _t146*_t82;
  const double _t767 = 0.6e1*_t766;
  const double _t768 = 0.8e1*_t6;
  const double _t769 = _hc2[1]*_t768;
  const double _t770 = _hc3[1]*_t7;
  const double _t771 = 0.8e1*_t770;
  const double _t772 = 0.8e1*_t730;
  const double _t773 = 0.12e2*_t6;
  const double _t774 = -_hc2[6]*_t536 - _hc3[6]*_t144 - _t106*_t349 - _t365*_t773 - 0.2e1*_t368 - 0.6e1*_t369 - 0.6e1*_t370 - _t683*_t770;
  const double _t775 = 0.3e1*_t324;
  const double _t776 = _t253*_t377;
  const double _t777 = 0.3e1*_t722;
  const double _t778 = _hc3[3]*_t366;
  const double _t779 = -_hc3[0]*_t778 - 0.3e1*_t135 - 0.3e1*_t136 - _t137*_t364 - _t138*_t366 - _t285*_t364 - _t354*_t38;
  const double _t780 = _t146*_t378;
  const double _t781 = 0.2e1*_t722;
  const double _t782 = _t578*(-_hc3[0]*_t771 - 0.4e1*_t49 - 0.4e1*_t50 - _t768*_t90);
  const double _t783 = _t584*_t65;
  const double _t784 = _t513*_t551;
  const double _t785 = 0.2e1*_t380;
  const double _t786 = _t28*_t56;
  const double _t787 = _t150*_t593;
  const double _t788 = _hc3[2]*_t700;
  const double _t789 = _t238*_t56;
  const double _t790 = _t472*_t76;
  const double _t791 = _hc2[2]*_t242;
  const double _t792 = _t381*_t82;
  const double _t793 = _t488*_t80;
  const double _t794 = _t244*_t56;
  const double _t795 = _t792*_t80;
  const double _t796 = _t170*_t246;
  const double _t797 = _t255*_t63;
  const double _t798 = _t797*_t80;
  const double _t799 = _t65*_t68;
  const double _t800 = 0.20e2*_hc2[1];
  const double _t801 = 0.20e2*_hc2[2];
  const double _t802 = _hc2[2]*_t39;
  const double _t803 = _hc3[1]*_t262;
  const double _t804 = _t175*_t3;
  const double _t805 = _t56*_t75;
  const double _t806 = _t303*t;
  const double _t807 = _hc3[4]*_t639;
  const double _t808 = _t269*_t4;
  const double _t809 = _hc2[4]*t;
  const double _t810 = 0.4e1*_t809;
  const double _t811 = _t28*_t386;
  const double _t812 = _t166*_t590;
  const double _t813 = _t110*_t472;
  const double _t814 = _t166*_t235;
  const double _t815 = _t27*_t71;
  const double _t816 = _t27*_t273;
  const double _t817 = _hc3[1]*_t166;
  const double _t818 = _t267*_t80;
  const double _t819 = _t385*_t4;
  const double _t820 = _t170*_t322;
  const double _t821 = _t145*_t488;
  const double _t822 = _t267*_t63;
  const double _t823 = _t255*_t822;
  const double _t824 = _t624*_t65;
  const double _t825 = _t343*_t65;
  const double _t826 = _t124*_t825;
  const double _t827 = _t124*_t282;
  const double _t828 = _t124*_t513;
  const double _t829 = _hc2[4]*_t10*_t108;
  const double _t830 = _t10*_t434;
  const double _t831 = _t175*_t42;
  const double _t832 = _t127*_t151;
  const double _t833 = _t292*_t56;
  const double _t834 = _hc3[7]*_t9;
  const double _t835 = _t402*t;
  const double _t836 = 0.2e1*_t642;
  const double _t837 = _t3*_t436;
  const double _t838 = _t175*_t72;
  const double _t839 = _t132*_t56;
  const double _t840 = _t132*_t40;
  const double _t841 = _t208*_t40;
  const double _t842 = _t126*_t235;
  const double _t843 = _hc3[3]*_t63;
  const double _t844 = _hc3[4]*_t262;
  const double _t845 = _t127*_t168;
  const double _t846 = _t114*_t175;
  const double _t847 = _hc3[4]*_t759;
  const double _t848 = _t28*_t425;
  const double _t849 = _t132*_t235;
  const double _t850 = _t131*_t80;
  const double _t851 = _hc3[4]*_t51;
  const double _t852 = _t316*_t80;
  const double _t853 = _hc3[2]*_t140;
  const double _t854 = 0.2e1*_t766;
  const double _t855 = _t361*_t56;
  const double _t856 = _t140*_t472;
  const double _t857 = _t173*t;
  const double _t858 = _hc2[4]*_t320;
  const double _t859 = _t196*_t589;
  const double _t860 = _t196*_t590;
  const double _t861 = _t328*_t56;
  const double _t862 = _t145*_t445;
  const double _t863 = _t146*_t412;
  const double _t864 = _t145*_t797;
  const double _t865 = _t254*_t428;
  const double _t866 = _t378*_t63;
  const double _t867 = _t166*_t378;
  const double _t868 = _t170*_t375;
  const double _t869 = _t113*_t235;
  const double _t870 = _t145*_t866;
  const double _t871 = _t377*_t428;
  const double _t872 = 0.3e1*_t124;
  const double _t873 = _hc3[11]*params->gamma;
  const double _t874 = _hc2[11]*_t2;
  const double _t875 = 0.3e1*_t434;
  const double _t876 = _t397*_t40;
  const double _t877 = 0.3e1*_t174;
  const double _t878 = 0.6e1*_t174;
  const double _t879 = 0.3e1*_t433;
  const double _t880 = _t27*_t843;
  const double _t881 = _t101*_t51;
  const double _t882 = _t305*_t56;
  const double _t883 = 0.3e1*_t804;
  const double _t884 = 0.3e1*_t440;
  const double _t885 = _t145*_t356;
  const double _t886 = 0.3e1*_t766;
  const double _t887 = _t145*_t360;
  const double _t888 = _t28*_t455;
  const double _t889 = _hc3[1]*_t196;
  const double _t890 = 0.3e1*_t776;
  const double _t891 = _hc2[4]*_t364;
  const double _t892 = _t172*_t200;
  const double _t893 = 0.2e1*_t458;
  const double _t894 = _t172*_t67;
  const double _t895 = 0.40e2*_hc2[2];
  const double _t896 = _t166*_t472;
  const double _t897 = _t550*_t56;
  const double _t898 = _hc3[5]*_t639;
  const double _t899 = _hc2[2]*_t549;
  const double _t900 = _t383*_t4;
  const double _t901 = _hc2[5]*t;
  const double _t902 = 0.4e1*_t157;
  const double _t903 = 0.4e1*_hc3[2];
  const double _t904 = 0.4e1*_t161;
  const double _t905 = _t26*_t486;
  const double _t906 = 0.2e1*_t905;
  const double _t907 = _t170*_t486;
  const double _t908 = _t218*_t488;
  const double _t909 = _t501*_t80;
  const double _t910 = _t388*_t4;
  const double _t911 = _t487*_t83;
  const double _t912 = _t166*_t487;
  const double _t913 = _t216*_t562;
  const double _t914 = _t218*_t24;
  const double _t915 = _t200*_t65;
  const double _t916 = _t200*_t825;
  const double _t917 = _t199*_t200;
  const double _t918 = _t199*_t67;
  const double _t919 = _t90*_t91;
  const double _t920 = _t10*_t496;
  const double _t921 = _t203*_t42;
  const double _t922 = _t151*_t175;
  const double _t923 = _t397*_t56;
  const double _t924 = _t40*_t464;
  const double _t925 = _hc3[8]*_t9;
  const double _t926 = _t399*t;
  const double _t927 = 0.2e1*_t901;
  const double _t928 = _t203*_t72;
  const double _t929 = _t208*_t56;
  const double _t930 = _t202*_t235;
  const double _t931 = _t114*_t91;
  const double _t932 = _hc3[5]*_t51;
  const double _t933 = _t168*_t175;
  const double _t934 = _t114*_t203;
  const double _t935 = _hc3[4]*_t27;
  const double _t936 = _t28*_t481;
  const double _t937 = _t202*_t4;
  const double _t938 = _t207*_t80;
  const double _t939 = _hc3[4]*_t63;
  const double _t940 = _t210*_t80;
  const double _t941 = _hc3[1]*_t216;
  const double _t942 = _t487*_t82;
  const double _t943 = _t166*_t500;
  const double _t944 = _t40*_t499;
  const double _t945 = _t216*_t590;
  const double _t946 = _t18*_t218;
  const double _t947 = _t201*t;
  const double _t948 = _t196*_t786;
  const double _t949 = _t196*_t472;
  const double _t950 = _t40*_t490;
  const double _t951 = _t218*_t327;
  const double _t952 = _t4*_t490;
  const double _t953 = _hc2[2]*t;
  const double _t954 = _t218*_t797;
  const double _t955 = _t411*_t487;
  const double _t956 = 0.2e1*_hc3[2]*_t428;
  const double _t957 = _t26*_t488;
  const double _t958 = _t145*_t538;
  const double _t959 = _t170*_t18;
  const double _t960 = _t170*_t510;
  const double _t961 = _t146*_t216;
  const double _t962 = _t196*_t487;
  const double _t963 = _t26*_t510;
  const double _t964 = _t377*_t491;
  const double _t965 = 0.2e1*_t493;
  const double _t966 = 0.2e1*_t344;
  const double _t967 = _hc3[12]*params->gamma;
  const double _t968 = _hc2[12]*_t2;
  const double _t969 = 0.2e1*_t496;
  const double _t970 = 0.2e1*_t434;
  const double _t971 = 0.4e1*_t804;
  const double _t972 = _t4*_t925;
  const double _t973 = 0.4e1*_t55;
  const double _t974 = 0.2e1*_t126;
  const double _t975 = 0.4e1*_t174;
  const double _t976 = 0.2e1*_t202;
  const double _t977 = 0.2e1*_t433;
  const double _t978 = 0.2e1*_t495;
  const double _t979 = 0.2e1*_t473;
  const double _t980 = _t63*_t935;
  const double _t981 = _t101*_t63;
  const double _t982 = _t56*_t650;
  const double _t983 = _t40*_t473;
  const double _t984 = _t27*_t932;
  const double _t985 = _t40*_t973;
  const double _t986 = _t4*_t975;
  const double _t987 = 0.4e1*_t196;
  const double _t988 = _t131*_t218;
  const double _t989 = _t145*_t902;
  const double _t990 = _t145*_t501;
  const double _t991 = _t218*_t316;
  const double _t992 = _t145*_t904;
  const double _t993 = _t28*_t507;
  const double _t994 = 0.2e1*_t942;
  const double _t995 = 0.2e1*_t963;
  const double _t996 = _hc3[2]*_t143;
  const double _t997 = 0.2e1*_t378;
  const double _t998 = 0.4e1*_t173;
  const double _t999 = _t512*_t915;
  const double _t1000 = _t200*_t221;
  const double _t1001 = _t225*_t512;
  const double _t1002 = _t512*_t513;
  const double _t1003 = _t221*_t67;
  const double _t1004 = 0.12e2*_hc3[5];
  const double _t1005 = _t1004*_t9;
  const double _t1006 = _t151*_t593;
  const double _t1007 = _t10*_t519;
  const double _t1008 = _t151*_t203;
  const double _t1009 = _t464*_t56;
  const double _t1010 = _hc3[9]*_t9;
  const double _t1011 = 0.12e2*_t462;
  const double _t1012 = _hc2[5]*_t242;
  const double _t1013 = _t523*_t56;
  const double _t1014 = 0.6e1*_t896;
  const double _t1015 = _t150*_t233;
  const double _t1016 = _t168*_t593;
  const double _t1017 = _hc3[5]*_t63;
  const double _t1018 = _t168*_t203;
  const double _t1019 = _t473*_t56;
  const double _t1020 = _t1017*_t27;
  const double _t1021 = 0.12e2*_t953;
  const double _t1022 = _t4*_t473;
  const double _t1023 = _t235*_t522;
  const double _t1024 = _t242*_t54;
  const double _t1025 = 0.6e1*_t157;
  const double _t1026 = 0.6e1*_t161;
  const double _t1027 = _t4*_t524;
  const double _t1028 = 0.3e1*_t487;
  const double _t1029 = _t499*_t56;
  const double _t1030 = _t216*_t472;
  const double _t1031 = _t218*_t501;
  const double _t1032 = _t490*_t56;
  const double _t1033 = 0.2e1*_t911;
  const double _t1034 = _hc3[2]*_t491;
  const double _t1035 = _t254*_t540;
  const double _t1036 = _t1035*_t63;
  const double _t1037 = _t218*_t538;
  const double _t1038 = _t170*_t537;
  const double _t1039 = _t26*_t537;
  const double _t1040 = _t216*_t487;
  const double _t1041 = _t491*_t540;
  const double _t1042 = _hc3[13]*params->gamma;
  const double _t1043 = _hc2[13]*_t2;
  const double _t1044 = 0.3e1*_t495;
  const double _t1045 = _t28*_t533;
  const double _t1046 = _t218*_t528;
  const double _t1047 = _t218*_t535;
  const double _t1048 = 0.3e1*_t500;
  const double _t1049 = _t1036*_t218;
  const double _t1050 = _t253*_t540;
  const double _t1051 = _hc3[4]*_t366;
  const double _t1052 = _hc2[2]*_t768;
  const double _t1053 = _hc3[2]*_t7;
  const double _t1054 = 0.8e1*_t1053;
  const double _t1055 = 0.4e1*_t159;
  const double _t1056 = _hc3[14]*params->gamma;
  const double _t1057 = _hc2[14]*_t2;
  const double _t1058 = 0.4e1*_t519;
  const double _t1059 = 0.6e1*_t469;
  const double _t1060 = 0.4e1*_t1010;
  const double _t1061 = 0.12e2*_t55;
  const double _t1062 = _t55*_t56;
  const double _t1063 = 0.6e1*_t202;
  const double _t1064 = 0.4e1*_t518;
  const double _t1065 = 0.12e2*_t473;
  const double _t1066 = _t1004*_t27*_t63;
  const double _t1067 = 0.12e2*_t1030;
  const double _t1068 = 0.6e1*_t216;
  const double _t1069 = 0.12e2*_t1031;
  const double _t1070 = 0.6e1*_t201;
  const double _t1071 = 0.8e1*_t1037;
  const double _t1072 = 0.6e1*_t54;
#endif

  const double f = _t13*_t15;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t31*_t34;
  out[1] = df_dt;
  const double df_dz = _t34*_t53 + _t35*_t37;
  out[2] = df_dz;
  const double df_drs = _t34*_t65;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t34*_t86 + _t67*_t69;
  out[4] = d2f_dt2;
  const double d2f_dz_dt = _t118*_t34 + _t31*_t88 + _t68*_t89;
  out[5] = d2f_dz_dt;
  const double d2f_dz2 = _t119*_t37 + _t121*_t122 + _t123*_t53 + _t124*_t89 + _t148*_t34;
  out[6] = d2f_dz2;
  const double d2f_drs_dt = _t149*_t68 + _t172*_t34;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dz = _t124*_t149 + _t199*_t34 + _t65*_t88;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _t149*_t200 + _t221*_t34;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t226*_t69 + _t228*_t86 + _t229*_t230 + _t257*_t34;
  out[10] = d3f_dt3;
  const double d3f_dz_dt2 = _t118*_t228 + _t229*_t89 + _t259*_t69 + _t260*_t68 + _t277*_t34 + _t86*_t88;
  out[11] = d3f_dz_dt2;
  const double d3f_dz2_dt = _t118*_t123 + _t118*_t283 + _t124*_t260 + _t148*_t227 + _t278*_t31 + _t280*_t31 + _t281*_t282 + _t284*_t89 + _t330*_t34;
  out[12] = d3f_dz2_dt;
  const double d3f_dz3 = _t148*_t345 + _t148*_t346 + _t331*_t37 + _t332*_t334 + _t333*_t338 + _t335*_t336 + _t339*_t53 + _t34*_t379 + _t340*_t53 + _t341*_t342 + _t341*_t344 + _t347*_t89;
  out[13] = d3f_dz3;
  const double d3f_drs_dt2 = _t149*_t229 + _t172*_t228 + _t34*_t389 + _t380*_t68;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dz_dt = _t124*_t380 + _t149*_t284 + _t172*_t283 + _t172*_t88 + _t199*_t227 + _t34*_t429 + _t390*_t68;
  out[15] = d3f_drs_dz_dt;
  const double d3f_drs_dz2 = _t123*_t199 + _t124*_t430 + _t124*_t431 + _t149*_t347 + _t199*_t346 + _t278*_t65 + _t280*_t65 + _t34*_t456;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dt = _t149*_t458 + _t172*_t457 + _t200*_t380 + _t221*_t227 + _t34*_t492;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dz = _t149*_t493 + _t199*_t457 + _t200*_t390 + _t200*_t431 + _t221*_t283 + _t221*_t88 + _t34*_t511;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _t149*_t516 + _t221*_t515 + _t34*_t542 + _t512*_t514;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _t230*_t558 + _t257*_t557 + _t34*(-0.192e3*((_hc2[0]) * (_hc2[0]) * (_hc2[0]) * (_hc2[0]))*_t28*_t6 + 0.16e2*_hc2[0]*_t4*_t567*t - 0.216e3*_t2*_t236 + _t232 + _t238*_t560 + _t241*_t561 + _t244*_t560 + _t245*_t561 + 0.96e2*_t5*_t559 - 0.72e2*_t562*_t563 - _t564*_t84 + _t565*_t568 + _t565*_t79 + _t566*_t567 + _t568*_t572 + _t569*_t76*_t83 + _t570*_t571 + _t571*_t576 + _t574*_t575 + _t575*_t580 + _t577*_t76) + _t543*_t545 + _t547*_t86 + _t552*_t69 + _t553*_t554 + _t556*_t86;
  out[20] = d4f_dt4;
  const double d4f_dz_dt3 = _t118*_t547 + _t118*_t556 + _t229*_t585 + _t257*_t88 + _t259*_t553 + _t277*_t557 + _t281*_t552 + _t281*_t584 + _t34*(-_hc2[1]*_t592 + _hc2[1]*_t596 + _hc2[1]*_t599 + _t102*_t619 + _t104*_t565 + _t104*_t572 + _t110*_t577 + _t110*_t605 + _t114*_t587 - _t116*_t564 + _t116*_t616 + _t131*_t567 + _t238*_t594 + _t239*_t265 + _t239*_t276 + _t239*_t301 + _t240*_t264 + _t241*_t603 + _t243*_t600 + _t243*_t604 + _t243*_t609 + _t244*_t594 + _t245*_t603 + _t247*_t606 + _t251*_t608 + _t265*_t598 + _t271*_t597 + _t271*_t614 + _t276*_t598 + _t316*_t567 + _t42*_t587 + _t51*_t622 + _t51*_t623 + _t565*_t99 + _t569*_t615 + _t572*_t99 + _t576*_t620 + _t586*_t90 - _t588*_t589 - _t590*_t591 + _t595*_t76 + _t601*_t602 + _t602*_t610 + _t602*_t617 + _t602*_t621 + _t606*_t607 + _t607*_t620 + _t608*_t613 + _t611*_t76) + _t543*_t581 + _t558*_t89 + _t583*_t86;
  out[21] = d4f_dz_dt3;
  const double d4f_dz2_dt2 = 0.4e1*_t118*_t582 + _t118*_t629 + _t118*_t631 + _t123*_t277 + _t148*_t546 + _t148*_t555 + _t228*_t330 + _t229*_t282*_t53 + _t277*_t283 + _t278*_t86 + _t280*_t86 + _t281*_t627 + _t284*_t585 + _t34*(_hc2[3]*_t261 + _hc3[3]*_t635 + _hc3[3]*_t645 + 0.4e1*_t110*_t649 + _t116*_t654 + _t126*_t241 + _t127*_t637 + _t131*_t601 + _t131*_t610 + _t131*_t617 + _t131*_t621 + _t131*_t644 + _t132*_t600 + _t132*_t604 + _t132*_t609 + _t134*_t271 + _t140*_t256 + _t238*_t298 + _t244*_t298 + _t244*_t646 + _t247*_t663 + _t249*_t314 + _t263*_t314 + _t264*_t641 + _t265*_t321 + _t265*_t638 + _t267*_t640 + _t267*_t660 + _t267*_t661 + _t267*_t666 + _t271*_t324 + _t272*_t641 + _t273*_t328 + _t273*_t361 + _t275*_t663 + _t276*_t321 + _t276*_t638 + _t287*_t634 + _t289 + _t29*(-_hc2[3]*_t270 - _t137*_t647 - _t308 - _t310 - _t311) + _t291 + _t292*_t71 + _t294 + _t295 + _t296 + _t297 + _t300*_t641 + _t301*_t321 + _t301*_t638 + _t302*_t662 + _t304 + _t305*_t548 + _t306 + _t307 + _t312*_t72 + _t313*_t72 + _t314*_t387 + _t316*_t601 + _t316*_t610 + _t316*_t617 + _t316*_t621 + _t323*_t659 + _t328*_t71 + _t329*_t574 + _t329*_t580 + _t357*_t76 + _t361*_t71 + _t372*_t570 + _t372*_t576 + _t435*_t633 + _t438*_t633 + _t568*_t636 + _t568*_t656 + _t608*_t648 + _t608*_t651 + _t615*_t653 + _t615*_t655 + _t620*_t653 + _t620*_t655 + _t620*_t667 + _t636*_t79 + _t641*_t657 + _t642*_t643 + _t664*_t665) + _t341*_t552 + _t341*_t584 + _t624*_t69 + _t625*_t69 + _t632*_t89;
  out[22] = d4f_dz2_dt2;
  const double d4f_dz3_dt = _t118*_t124*_t342 + _t118*_t339 + _t118*_t340 + _t118*_t678 + _t118*_t681 + _t148*_t629 + _t148*_t631 + _t227*_t379 + _t260*_t347 + _t31*_t668 + _t31*_t672 + _t330*_t345 + _t330*_t346 + _t34*(_hc2[6]*_t393 + _hc2[6]*_t695 + 0.3e1*_hc3[1]*_t664*_t82 + _hc3[6]*_t286 + _hc3[6]*_t299 + _t110*_t358 + _t112*_t371 + _t113*_t687 + _t113*_t691 + _t113*_t716 + _t115*_t694 + _t116*_t726 + _t137*_t685 + _t137*_t699 + _t140*_t595 + _t140*_t733 + _t16*_t684*_t90 + _t237*_t715 + _t243*_t688 + _t243*_t689 + _t243*_t702 + _t243*_t713 + _t243*_t717 + _t248*_t371 + _t264*_t355 + _t265*_t351 + _t265*_t697 + _t267*_t730 + _t272*_t355 + _t276*_t351 + _t276*_t697 + _t276*_t712 + _t285*_t685 + _t285*_t699 + _t288*_t603 + _t29*(-_hc2[3]*_t709 - _hc2[6]*_t422 - _hc2[6]*_t710 - _t113*_t348 - _t125*_t603 - _t233*_t365) + _t293*_t603 + _t300*_t355 + _t301*_t351 + _t301*_t697 + _t305*_t698 + _t314*_t363 + _t314*_t376 + _t314*_t708 + _t323*_t720 + _t325*_t603 + _t326*_t729 + _t327*_t731 + _t327*_t732 + _t328*_t594 + _t349*_t73 + _t350*_t406 + _t353*_t696 + _t356*_t636 + _t356*_t656 + _t359*_t705 + _t360*_t636 + _t360*_t656 + _t361*_t594 + _t362*_t640 + _t362*_t660 + _t362*_t661 + _t362*_t666 + _t362*_t707 + _t362*_t723 + _t365*_t686 + _t373*_t652 + _t374*_t640 + _t374*_t660 + _t374*_t661 + _t374*_t666 + _t374*_t723 + _t378*_t664 + _t579*_t734 + _t602*_t704 + _t602*_t714 + _t602*_t715 + _t603*_t718 + _t612*_t703 + _t615*_t722 + _t620*_t722 + _t649*_t721 + _t652*_t729 + _t653*_t663 + _t655*_t663 + _t692*_t693 + _t694*_t93 + _t694*_t95 + _t700*_t701 + _t701*_t711 + _t705*_t706 + _t724*_t725 + _t727*_t728) + 0.3e1*_t341*_t626 + _t342*_t677 + _t344*_t677 + _t545*_t675 + _t582*_t676 + _t624*_t674 + _t625*_t674 + _t669*_t671 + _t671*_t673 + _t679*_t680 + _t682*_t89;
  out[23] = d4f_dz3_dt;
  const double d4f_dz4 = _t119*_t332*_t736 + _t120*_t331*_t736 + 0.8e1*_t148*_t743 + _t148*_t747 + _t259*_t347*_t738 + _t278*_t741 + _t280*_t741 + _t334*(_hc0[9] - _hc1[9]) + _t336*((0.1e1 / 0.2e1)*_hc0[5] + (0.1e1 / 0.2e1)*_hc1[5]) + _t34*(0.8e1*_hc3[1]*_t140*_t766 + _hc3[10]*_t58 + _t104*_t760 + _t104*_t763 + _t104*_t765 + _t104*_t772 + _t11*(_t750 + _t751) + _t115*_t757 + 0.12e2*_t126*_t359 + _t126*_t693 + 0.6e1*_t140*_t357 + _t20*_t751 + _t288*_t756 + _t29*(-_hc2[10]*_t46 - ((_hc2[3]) * (_hc2[3]))*_t364 - _hc2[6]*_t769 - _hc3[10]*_t48 - ((_hc3[3]) * (_hc3[3]))*_t366 - _hc3[6]*_t771 - _t1*_t751 - _t125*_t756 - _t3*_t750 - _t309*_t349 - _t348*_t650) + _t292*_t753 + _t293*_t756 + _t298*_t758 + 0.24e2*_t305*_t755 + _t323*_t774 + _t325*_t756 + _t328*_t753 + _t361*_t753 + _t371*_t744 + _t371*_t775 + 0.4e1*_t372*_t722 + _t435*_t752 + _t438*_t752 + _t646*_t758 + _t648*_t690 + _t648*_t731 + _t648*_t732 + _t648*_t764 + _t650*_t687 + _t650*_t691 + _t650*_t716 + _t651*_t731 + _t651*_t732 + _t663*_t777 + _t684*_t755 + _t688*_t754 + _t701*_t767 + _t702*_t754 + _t713*_t754 + _t717*_t754 + _t718*_t756 + _t721*_t780 + 0.4e1*_t724*_t776 + _t728*_t779 + _t729*_t781 + _t734*_t782 + _t757*_t93 + _t757*_t95 + _t760*_t99 + _t761*_t762 + _t763*_t99 + _t765*_t99 + _t772*_t99) + _t344*_t53*_t746 + _t37*((0.3e1 / 0.2e1)*_hc0[14] + (0.3e1 / 0.2e1)*_hc1[14]) + _t379*_t748 + 0.4e1*_t379*_t88 + 0.8e1*_t53*_t670*_t737 + 0.4e1*_t581*_t675 + _t624*_t740 + _t625*_t740 + _t668*_t738 + 0.2e1*_t669*_t735 + _t672*_t738 + _t675*_t742 + _t676*_t678 + _t680*_t745 + 0.3e1*_t735*_t737 + _t738*_t739 + _t749*_t89;
  out[24] = d4f_dz4;
  const double d4f_drs_dt3 = _t149*_t558 + _t172*_t547 + _t172*_t556 + _t229*_t785 + _t34*(-_hc2[2]*_t592 + _hc2[2]*_t596 + _hc2[2]*_t599 + _t150*_t586 + _t151*_t587 + _t157*_t565 + _t157*_t572 + _t161*_t565 + _t161*_t572 + _t166*_t577 + _t166*_t605 + _t168*_t587 - _t170*_t564 + _t170*_t616 + _t207*_t567 + _t210*_t567 + _t235*_t243*_t386 + _t238*_t787 + _t239*_t383 + _t239*_t388 + _t239*_t407 + _t240*_t382 + _t241*_t791 + _t243*_t789 + _t243*_t794 + _t244*_t787 + _t245*_t791 + _t247*_t792 + _t251*_t793 + _t381*_t619 + _t383*_t598 + _t386*_t597 + _t386*_t614 + _t388*_t598 - _t472*_t591 + _t482*_t76 + _t488*_t569 + _t576*_t797 - _t588*_t786 + _t602*_t790 + _t602*_t795 + _t602*_t796 + _t602*_t798 + _t607*_t792 + _t607*_t797 + _t613*_t793 + _t622*_t63 + _t623*_t63 + _t76*_t788) + _t389*_t557 + _t68*_t783 + _t68*_t784;
  out[25] = d4f_drs_dt3;
  const double d4f_drs_dz_dt2 = _t124*_t783 + _t124*_t784 + _t149*_t632 + _t172*_t583 + _t172*_t629 + _t172*_t631 + _t199*_t546 + _t199*_t555 + _t228*_t429 + _t229*_t390 + _t283*_t389 + _t284*_t785 + _t34*(_hc2[4]*_t261 + _hc3[4]*_t635 + _hc3[4]*_t645 + 0.20e2*_t10*_t802 + _t104*_t790 + _t104*_t795 + _t104*_t796 + _t104*_t798 + _t104*_t811 + _t109*_t383 + _t109*_t388 + _t109*_t407 + _t110*_t470 + _t110*_t482 + _t131*_t793 + _t133*_t386 + _t145*_t823 + _t157*_t601 + _t157*_t610 + _t157*_t617 + _t157*_t621 + _t157*_t644 + _t159*_t271 + _t161*_t601 + _t161*_t610 + _t161*_t617 + _t161*_t621 + _t161*_t644 + _t165*_t265 + _t165*_t276 + _t165*_t301 + _t166*_t733 + _t166*_t803 + _t170*_t654 + _t174*_t241 + _t174*_t245 + _t175*_t637 + _t178*_t800 + _t19*_t394 + _t19*_t395 + _t19*_t396 + _t19*_t413 + _t19*_t414 + _t196*_t256 + _t207*_t608 + _t210*_t608 + _t219*_t659 + _t238*_t804 + _t244*_t804 + _t247*_t445 + _t247*_t446 + _t247*_t508 + _t249*_t425 + _t263*_t425 + _t264*_t385 + _t265*_t805 + _t267*_t807 + _t267*_t812 + _t267*_t813 + _t267*_t820 + _t267*_t821 + _t269*_t382 + _t269*_t814 + _t272*_t385 + _t273*_t397 + _t273*_t427 + _t273*_t444 + _t275*_t445 + _t275*_t446 + _t275*_t508 + _t276*_t805 + _t276*_t819 + _t29*(-_hc2[4]*_t270 - _t418 - _t419 - _t420 - _t421 - 0.24e2*_t802) + _t300*_t385 + _t301*_t805 + _t315*_t817 + _t316*_t793 + _t324*_t386 + _t383*_t806 + _t383*_t808 + _t387*_t425 + _t388*_t806 + _t388*_t808 + _t39*_t789 + _t39*_t794 + _t397*_t71 + _t400 + _t401 + _t403 + _t404 + _t405 + _t407*_t806 + _t411*_t619 + _t411*_t815 + _t411*_t816 + _t412*_t619 + _t412*_t815 + _t412*_t816 + _t416 + _t417 + _t423*_t72 + _t424*_t72 + _t427*_t71 + _t428*_t574 + _t428*_t580 + _t435*_t801 + _t438*_t801 + _t440*_t76 + _t444*_t71 + _t445*_t818 + _t446*_t818 + _t488*_t653 + _t488*_t655 + _t498*_t800 + _t508*_t818 + _t55*_t600 + _t55*_t609 + _t653*_t797 + _t655*_t797 + _t73*_t810 + _t790*_t99 + _t795*_t99 + _t796*_t99 + _t798*_t99 + _t811*_t99) + _t389*_t88 + _t626*_t799;
  out[26] = d4f_drs_dz_dt2;
  const double d4f_drs_dz2_dt = _t123*_t429 + _t124*_t627*_t65 + _t149*_t682 + _t172*_t278 + _t172*_t280 + _t172*_t678 + _t172*_t681 + _t172*_t827 + _t199*_t583 + _t199*_t629 + _t199*_t631 + _t227*_t456 + _t284*_t430 + _t284*_t431 + _t34*(_hc2[1]*_t829 + _hc2[7]*_t393 + _hc2[7]*_t695 + _hc3[7]*_t286 + _hc3[7]*_t299 + _t109*_t397 + _t109*_t427 + _t109*_t442 + _t109*_t443 + _t109*_t444 + _t110*_t441 + _t112*_t455 + _t113*_t830 + _t113*_t832 + _t113*_t833 + _t113*_t845 + _t113*_t855 + _t113*_t861 + _t114*_t423 + _t114*_t424 + _t115*_t810 + _t126*_t382 + _t131*_t807 + _t131*_t812 + _t131*_t813 + _t131*_t820 + _t131*_t821 + _t131*_t848 + _t131*_t864 + _t132*_t838 + _t134*_t425 + _t137*_t391 + _t137*_t408 + _t146*_t867 + _t152*_t836 + _t154*_t836 + _t157*_t640 + _t157*_t660 + _t157*_t661 + _t157*_t666 + _t157*_t707 + _t157*_t723 + _t159*_t314 + _t161*_t640 + _t161*_t660 + _t161*_t661 + _t161*_t666 + _t161*_t707 + _t161*_t723 + _t165*_t305 + _t166*_t357 + _t166*_t842 + _t169*_t836 + _t170*_t726 + _t196*_t611 + _t196*_t733 + _t196*_t803 + _t207*_t636 + _t207*_t656 + _t210*_t636 + _t210*_t656 + _t219*_t720 + _t248*_t455 + _t264*_t437 + _t265*_t837 + _t265*_t839 + _t265*_t841 + _t267*_t847 + _t267*_t860 + _t269*_t394 + _t269*_t395 + _t269*_t396 + _t269*_t398 + _t269*_t413 + _t269*_t414 + _t269*_t426 + _t272*_t437 + _t274*_t843 + _t274*_t853 + _t276*_t837 + _t276*_t839 + _t276*_t841 + _t285*_t391 + _t285*_t408 + _t288*_t835 + _t29*(-_hc2[1]*_t858 - _hc2[7]*_t422 - _hc2[7]*_t710 - _t108*_t449 - _t113*_t432 - _t215*_t642 - _t268*_t857 - _t309*_t809 - _t402*_t719) + _t290*_t385 + _t292*_t409 + _t293*_t835 + _t298*_t383 + _t298*_t388 + _t298*_t407 + _t300*_t437 + _t301*_t837 + _t301*_t839 + _t301*_t841 + _t305*_t805 + _t315*_t851 + _t316*_t807 + _t316*_t812 + _t316*_t813 + _t316*_t820 + _t316*_t821 + _t316*_t864 + _t325*_t835 + _t326*_t445 + _t326*_t866 + _t327*_t834 + _t327*_t856 + _t327*_t862 + _t327*_t868 + _t327*_t870 + _t328*_t409 + _t359*_t385 + _t361*_t409 + _t376*_t425 + _t383*_t646 + _t383*_t840 + _t385*_t706 + _t388*_t646 + _t388*_t840 + _t397*_t806 + _t406*_t434 + _t407*_t840 + _t410*_t843 + _t410*_t853 + _t411*_t447*_t618 + _t415*_t843 + _t42*_t423 + _t42*_t424 + _t425*_t849 + _t427*_t806 + _t427*_t808 + _t433*_t73 + _t437*_t657 + _t442*_t806 + _t442*_t808 + _t443*_t806 + _t443*_t808 + _t445*_t652 + _t445*_t850 + _t445*_t852 + _t446*_t653 + _t446*_t655 + _t446*_t667 + _t446*_t850 + _t446*_t852 + _t449*_t92 + _t455*_t869 + _t488*_t722 + _t500*_t664 + _t508*_t653 + _t508*_t655 + _t508*_t667 + _t508*_t850 + _t508*_t852 + _t51*_t844 + _t55*_t696 + _t579*_t871 + _t618*_t863 + _t652*_t866 + _t718*_t835 + _t722*_t797 + _t727*_t865 + _t75*_t831 + _t75*_t846 + _t75*_t859 + _t810*_t93 + _t810*_t95 + _t817*_t854) + _t346*_t429 + _t347*_t380 + _t545*_t826 + _t625*_t799 + _t679*_t828 + _t68*_t824;
  out[27] = d4f_drs_dz2_dt;
  const double d4f_drs_dz3 = _t149*_t749 + _t199*_t339 + _t199*_t340 + 0.3e1*_t199*_t678 + 0.6e1*_t199*_t743 + _t199*_t747 + _t34*(_hc3[11]*_t58 + 0.3e1*_hc3[7]*_t881 + _t11*(_t873 + _t874) + _t115*_t879 + _t140*_t884 + _t146*_t411*_t890 + _t152*_t349 + _t154*_t349 + _t157*_t690 + _t157*_t731 + _t157*_t732 + _t157*_t764 + _t159*_t371 + _t161*_t690 + _t161*_t731 + _t161*_t732 + _t161*_t764 + _t169*_t349 + _t178*_t350 + _t196*_t358 + 0.3e1*_t196*_t780 + _t20*_t874 + _t207*_t730 + _t210*_t730 + _t219*_t774 + _t288*_t877 + _t29*(-_hc2[1]*_hc2[7]*_t364 - _hc2[11]*_t46 - _hc2[2]*_hc2[6]*_t45 - _hc2[3]*_t891 - _hc3[11]*_t48 - _hc3[4]*_t778 - _hc3[6]*_t191 - _hc3[7]*_t367 - _t1*_t874 - _t125*_t877 - _t173*_t355 - _t3*_t873 - _t348*_t55 - _t349*_t54 - _t353*_t432 - _t38*_t879) + _t290*_t878 + _t293*_t877 + 0.6e1*_t305*_t804 + _t325*_t877 + _t328*_t883 + _t350*_t498 + _t351*_t397 + _t351*_t427 + _t351*_t442 + _t351*_t443 + _t351*_t444 + _t352*_t804 + _t353*_t830 + _t353*_t832 + _t353*_t833 + _t353*_t845 + _t353*_t855 + _t353*_t861 + _t354*_t831 + _t354*_t846 + _t354*_t859 + _t354*_t876 + _t354*_t882 + _t355*_t394 + _t355*_t395 + _t355*_t396 + _t355*_t398 + _t355*_t413 + _t355*_t414 + _t355*_t426 + _t356*_t847 + _t356*_t860 + _t359*_t878 + _t360*_t847 + _t360*_t860 + _t361*_t883 + _t362*_t834 + _t362*_t856 + _t362*_t862 + _t362*_t868 + _t362*_t870 + _t362*_t880 + _t362*_t888 + _t363*_t455 + _t374*_t834 + _t374*_t856 + _t374*_t862 + _t374*_t868 + _t374*_t870 + _t374*_t880 + _t427*_t697 + _t427*_t712 + _t435*_t875 + _t438*_t875 + _t442*_t697 + _t442*_t712 + _t443*_t697 + _t443*_t712 + _t445*_t722 + _t446*_t777 + _t446*_t885 + _t446*_t887 + _t455*_t708 + _t455*_t775 + _t508*_t777 + _t508*_t885 + _t508*_t887 + _t522*_t688 + _t522*_t689 + _t522*_t702 + _t522*_t713 + _t522*_t717 + _t523*_t703 + _t528*_t704 + _t528*_t714 + _t528*_t715 + _t535*_t704 + _t535*_t714 + _t535*_t715 + _t55*_t687 + _t63*_t761 + _t706*_t878 + _t718*_t877 + _t767*_t889 + _t776*_t863 + _t779*_t865 + _t781*_t866 + _t782*_t871 + _t843*_t886 + _t851*_t886 + _t853*_t854 + _t879*_t93 + _t879*_t95) + _t345*_t456 + 0.3e1*_t347*_t390 + _t431*_t746 + _t456*_t748 + 0.3e1*_t581*_t826 + _t625*_t65*_t872 + _t65*_t668 + _t65*_t670*_t673 + _t65*_t672 + _t65*_t739 + _t742*_t826 + _t745*_t828 + _t824*_t872;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dt2 = -_t149*_t389 + _t200*_t783 + _t221*_t546 + _t221*_t555 + _t228*_t492 + _t34*(_hc2[5]*_t261 + _hc3[2]*_t63*_t662 + _hc3[5]*_t635 + _hc3[5]*_t645 + _t166*_t274*_t903 + _t169*_t384 + _t178*_t895 + _t19*_t461 + _t19*_t465 + _t202*_t241 + _t202*_t245 + _t203*_t637 + _t207*_t790 + _t207*_t795 + _t207*_t796 + _t207*_t798 + _t207*_t811 + _t208*_t789 + _t208*_t794 + _t209*_t386 + _t210*_t790 + _t210*_t795 + _t210*_t796 + _t210*_t798 + _t210*_t811 + _t216*_t256 + _t218*_t823 + _t219*(-_hc2[2]*_t658 - _t483 - _t484) + _t238*_t469 + _t24*_t907 + _t24*_t908 + _t244*_t469 + _t247*_t538 + _t249*_t481 + _t263*_t481 + _t267*_t898 + _t267*_t907 + _t267*_t908 + _t267*_t913 + _t273*_t490 + _t273*_t499 + _t275*_t538 + _t29*(-_hc2[5]*_t270 - _t213*_t647 - _t475 - _t477 - _t478) + _t382*_t899 + _t383*_t485 + _t383*_t897 + _t386*_t911 + _t387*_t481 + _t388*_t485 + _t388*_t897 + _t407*_t485 + _t407*_t897 + _t460*_t634 + _t463 + _t464*_t71 + _t466 + _t467 + _t468 + _t471*_t74 + _t473*_t548 + _t474 + _t479*_t72 + _t480*_t72 + _t488*_t906 + _t490*_t71 + _t491*_t580 + _t497*_t76 + _t498*_t895 + _t499*_t71 + _t501*_t570 + _t501*_t576 + _t541*_t573 + _t568*_t896 + _t568*_t909 + _t643*_t901 + _t665*_t912 + _t79*_t896 + _t793*_t902 + _t793*_t904 + _t797*_t906 + _t797*_t914 + _t814*_t899 + _t899*_t900 + _t899*_t910) + _t380*_t893 + _t389*_t457 + _t514*_t551 + _t554*_t892 + _t893*_t894;
  out[29] = d4f_drs2_dt2;
  const double d4f_drs2_dz_dt = -_t149*_t429 + _t221*_t582 + _t221*_t628 + _t221*_t630 + _t226*_t917 + _t227*_t511 + _t259*_t892 + _t283*_t492 + _t34*(_hc2[2]*_t829 + _hc2[8]*_t393 + _hc2[8]*_t695 + _hc3[8]*_t286 + _hc3[8]*_t299 + _t104*_t898 + _t104*_t907 + _t104*_t908 + _t104*_t913 + _t104*_t936 + _t104*_t954 + _t109*_t473 + _t110*_t497 + _t110*_t930 + _t112*_t507 + _t113*_t920 + _t113*_t921 + _t113*_t924 + _t113*_t934 + _t113*_t944 + _t113*_t950 + _t115*_t927 + _t131*_t896 + _t133*_t481 + _t151*_t423 + _t151*_t424 + _t152*_t810 + _t154*_t810 + _t165*_t397 + _t165*_t427 + _t165*_t442 + _t165*_t443 + _t165*_t444 + _t166*_t441 + _t168*_t423 + _t168*_t424 + _t169*_t810 + _t196*_t470 + _t196*_t482 + _t202*_t264 + _t202*_t300 + _t207*_t807 + _t207*_t812 + _t207*_t813 + _t207*_t820 + _t207*_t821 + _t207*_t848 + _t207*_t864 + _t208*_t838 + _t209*_t425 + _t210*_t807 + _t210*_t812 + _t210*_t813 + _t210*_t820 + _t210*_t821 + _t210*_t848 + _t210*_t864 + _t213*_t392 + _t213*_t931 + _t219*(-_hc2[0]*_t858 - _t190*_t320 - _t309*_t953 - _t318*_t809 - _t476*_t692 - _t74*_t857) + _t248*_t507 + _t255*_t961 + _t255*_t962 + _t265*_t469 + _t265*_t929 + _t267*_t949 + _t269*_t462 + _t269*_t471 + _t274*_t932 + _t274*_t941 + _t276*_t469 + _t276*_t929 + _t276*_t937 + _t29*(-_hc2[2]*_t858 - _hc2[8]*_t422 - _hc2[8]*_t710 - _t108*_t502 - _t113*_t494 - _t139*_t901 - _t384*_t857 - _t399*_t947 - _t476*_t809) + _t301*_t469 + _t301*_t929 + _t315*_t939 + _t316*_t896 + _t324*_t481 + _t326*_t538 + _t327*_t925 + _t327*_t945 + _t327*_t958 + _t327*_t960 + _t382*_t437 + _t383*_t837 + _t383*_t839 + _t383*_t841 + _t385*_t394 + _t385*_t395 + _t385*_t396 + _t385*_t398 + _t385*_t413 + _t385*_t414 + _t385*_t426 + _t388*_t837 + _t388*_t839 + _t388*_t841 + _t39*_t928 + _t392*_t459 + _t406*_t496 + _t407*_t837 + _t407*_t839 + _t407*_t841 + _t410*_t932 + _t410*_t941 + _t415*_t932 + _t425*_t911 + _t427*_t805 + _t427*_t819 + _t437*_t814 + _t437*_t900 + _t437*_t910 + _t442*_t805 + _t442*_t819 + _t443*_t805 + _t443*_t819 + _t445*_t938 + _t445*_t940 + _t446*_t905 + _t446*_t938 + _t446*_t940 + _t446*_t946 + _t446*_t951 + _t447*_t943 + _t459*_t931 + _t461*_t926 + _t464*_t919 + _t465*_t926 + _t473*_t806 + _t473*_t808 + _t487*_t867 + _t489*_t926 + _t490*_t919 + _t495*_t73 + _t499*_t919 + _t501*_t653 + _t501*_t655 + _t501*_t667 + _t501*_t850 + _t501*_t852 + _t502*_t92 + _t507*_t869 + _t508*_t905 + _t508*_t938 + _t508*_t940 + _t508*_t946 + _t508*_t951 + _t510*_t957 + _t510*_t959 + _t538*_t652 + _t541*_t727 + _t579*_t964 + _t618*_t955 + _t618*_t956 + _t63*_t844 + _t75*_t922 + _t75*_t923 + _t75*_t933 + _t75*_t948 + _t797*_t963 + _t817*_t942 + _t822*_t935 + _t866*_t905 + _t866*_t946 + _t866*_t951 + _t898*_t99 + _t907*_t99 + _t908*_t99 + _t913*_t99 + _t926*_t952 + _t927*_t93 + _t927*_t95 + _t936*_t99 + _t954*_t99) + _t344*_t892 + _t380*_t493 + _t390*_t458 + _t429*_t457 + _t431*_t458 + _t458*_t918 + _t492*_t88 + _t493*_t894 + _t514*_t679 + _t545*_t916 + _t626*_t915;
  out[30] = d4f_drs2_dz_dt;
  const double d4f_drs2_dz2 = _t123*_t511 - _t149*_t456 + _t200*_t824 + _t221*_t278 + _t221*_t280 + _t221*_t678 + _t221*_t681 + _t221*_t827 + _t282*_t917 + _t34*(_hc3[12]*_t58 + 0.2e1*_hc3[7]*_t981 + 0.2e1*_hc3[8]*_t881 + _t11*(_t967 + _t968) + _t115*_t978 + _t126*_t461 + _t126*_t465 + _t131*_t925 + _t131*_t945 + _t131*_t958 + _t131*_t960 + _t131*_t993 + _t132*_t920 + _t132*_t921 + _t132*_t924 + _t132*_t934 + _t132*_t972 + _t134*_t507 + _t140*_t497 + _t140*_t930 + _t146*_t500*_t987 + _t152*_t977 + _t154*_t977 + _t161*_t762*_t935 + _t169*_t977 + _t178*_t970 + _t20*_t968 + _t202*_t288 + _t202*_t293 + _t207*_t834 + _t207*_t856 + _t207*_t862 + _t207*_t868 + _t207*_t870 + _t207*_t880 + _t207*_t888 + _t208*_t830 + _t208*_t832 + _t208*_t833 + _t208*_t845 + _t208*_t855 + _t209*_t455 + _t210*_t834 + _t210*_t856 + _t210*_t862 + _t210*_t868 + _t210*_t870 + _t210*_t880 + _t210*_t888 + _t216*_t357 + _t216*_t842 + _t219*(-_hc2[4]*_t769 - _hc2[7]*_t536 - _hc3[3]*_t996 - _hc3[4]*_t771 - _hc3[7]*_t144 - _t106*_t433 - _t142*_t449 - _t173*_t650 - _t174*_t309 - 0.2e1*_t451 - 0.2e1*_t452 - 0.2e1*_t453) + _t29*(-_hc2[1]*_hc2[8]*_t142 - _hc2[12]*_t46 - _hc2[2]*_hc2[7]*_t142 - _hc2[3]*_hc2[5]*_t45 - ((_hc2[4]) * (_hc2[4]))*_t142 - _hc3[12]*_t48 - _hc3[3]*_t503 - ((_hc3[4]) * (_hc3[4]))*_t143 - _hc3[7]*_t996 - _hc3[8]*_t509 - _t1*_t968 - _t125*_t202 - _t126*_t201 - _t132*_t494 - _t139*_t495 - _t174*_t998 - _t208*_t432 - _t215*_t433 - _t3*_t967) + _t290*_t976 + _t292*_t469 + _t298*_t464 + _t298*_t490 + _t298*_t499 + _t298*_t979 + 0.2e1*_t305*_t469 + _t316*_t945 + _t316*_t958 + _t316*_t960 + _t316*_t984 + _t328*_t469 + _t328*_t929 + _t328*_t937 + _t359*_t976 + _t361*_t469 + _t376*_t507 + _t378*_t961 + _t394*_t975 + _t395*_t975 + _t396*_t975 + _t397*_t971 + _t398*_t975 + _t413*_t975 + _t414*_t975 + _t426*_t975 + _t427*_t971 + _t427*_t982 + _t427*_t985 + _t427*_t986 + _t435*_t969 + _t438*_t969 + _t439*_t932 + _t440*_t987 + _t442*_t971 + _t442*_t982 + _t442*_t985 + _t442*_t986 + _t443*_t971 + _t443*_t982 + _t443*_t985 + _t443*_t986 + _t444*_t971 + _t446*_t988 + _t446*_t989 + _t446*_t991 + _t446*_t992 + _t446*_t995 + _t455*_t911 + _t462*_t974 + _t471*_t974 + _t490*_t646 + _t490*_t840 + _t498*_t970 + _t499*_t840 + _t501*_t781 + _t507*_t849 + _t508*_t988 + _t508*_t989 + _t508*_t991 + _t508*_t992 + _t508*_t995 + _t538*_t722 + _t541*_t779 + _t646*_t979 + _t648*_t949 + _t648*_t980 + _t648*_t990 + _t650*_t922 + _t650*_t923 + _t650*_t933 + _t650*_t948 + _t650*_t983 + _t651*_t949 + _t651*_t980 + _t651*_t990 + _t706*_t976 + _t766*_t932 + 0.4e1*_t766*_t939 + 0.2e1*_t776*_t955 + _t776*_t956 + _t782*_t964 + _t831*_t973 + _t843*_t942 + _t846*_t973 + _t847*_t902 + _t854*_t941 + _t859*_t973 + _t860*_t902 + _t860*_t904 + _t866*_t988 + _t866*_t991 + _t866*_t995 + _t876*_t973 + _t882*_t973 + _t889*_t994 + _t93*_t978 + _t95*_t978 + _t962*_t997) + _t346*_t511 + _t390*_t965 + _t431*_t965 + _t456*_t457 + _t514*_t745 + 0.2e1*_t581*_t916 + _t625*_t915 + _t742*_t916 + _t917*_t966 + _t918*_t965;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dt = _t1000*_t554 + _t1001*_t892 + _t1002*_t458 + _t1003*_t893 - _t149*_t492 + _t227*_t542 + _t34*(_hc2[9]*_t393 + _hc2[9]*_t695 + _hc3[2]*_t216*_t711 + _hc3[9]*_t286 + _hc3[9]*_t299 + _t1005*_t150*_t16 + _t1006*_t213 + _t1006*_t459 + _t1007*_t113 + _t1008*_t243 + _t1009*_t243 + _t1010*_t327 + _t1011*_t953 + _t1012*_t152 + _t1012*_t154 + _t1012*_t169 + _t1013*_t383 + _t1013*_t388 + _t1013*_t407 + _t1014*_t157 + _t1014*_t161 + _t1015*_t473 + _t1016*_t213 + _t1016*_t459 + _t1017*_t700 + _t1017*_t711 + _t1018*_t243 + _t1019*_t612 + _t1020*_t602 + _t1021*_t1022 + _t1021*_t471 + _t1023*_t481 + _t1025*_t909 + _t1026*_t909 + _t1027*_t388 + _t1028*_t943 + _t1029*_t243 + _t1030*_t602 + _t1031*_t237 + _t1031*_t602 + _t1032*_t243 + _t1033*_t481 + _t1034*_t725 + _t1035*_t912 + _t1036*_t905 + _t1036*_t946 + _t1036*_t951 + _t1037*_t267 + _t1038*_t327 + _t1039*_t797 + _t1040*_t665 + _t1041*_t579 + _t112*_t533 + _t166*_t527 + _t216*_t788 + _t219*(-_t213*_t320 - _t318*_t901 - _t320*_t459 - _t54*_t899 - _t74*_t947) + _t248*_t533 + _t29*(-_hc2[5]*_t1024 - _hc2[9]*_t422 - _hc2[9]*_t710 - _t113*_t517 - _t201*_t791 - _t233*_t530) + _t382*_t524 + _t383*_t525 + _t388*_t525 + _t406*_t519 + _t407*_t525 + _t461*_t791 + _t465*_t791 + _t481*_t529 + _t489*_t791 + _t490*_t787 + _t499*_t787 + _t518*_t73 + _t522*_t928 + _t524*_t814 + _t524*_t900 + _t528*_t898 + _t528*_t907 + _t528*_t908 + _t528*_t913 + _t528*_t936 + _t528*_t954 + _t530*_t686 + _t533*_t869 + _t534*_t905 + _t535*_t898 + _t535*_t907 + _t535*_t908 + _t535*_t913 + _t535*_t954 + _t537*_t957 + _t537*_t959 + _t538*_t914 + _t539*_t905 + _t541*(-_hc2[0]*_t1024 - _t1*_t791 - _t1015) + _t791*_t952) + _t380*_t516 + _t492*_t515 + _t514*(-_t10*_t165 - _t151*_t24 - _t152*_t75 - _t154*_t75 - 0.2e1*_t158 - 0.2e1*_t160 - 0.2e1*_t162 - 0.2e1*_t167 - _t168*_t24 - _t169*_t75 - 0.2e1*_t171 - _t20*_t385) + _t516*_t894 + _t545*_t999;
  out[32] = d4f_drs3_dt;
  const double d4f_drs3_dz = _t1000*_t282 + _t1000*_t966 + _t1001*_t917 + _t1002*_t493 + _t1003*_t965 - _t149*_t511 + _t283*_t542 + _t34*(_hc3[13]*_t58 + 0.3e1*_hc3[8]*_t981 + _hc3[9]*_t881 + _t1007*_t39 + _t1008*_t353 + _t1009*_t353 + _t1010*_t104 + _t1010*_t99 + _t1013*_t427 + _t1013*_t442 + _t1013*_t443 + _t1017*_t886 + _t1018*_t353 + _t1019*_t354 + _t1020*_t362 + _t1020*_t374 + _t1022*_t878 + _t1023*_t507 + _t1025*_t949 + _t1025*_t980 + _t1025*_t990 + _t1026*_t949 + _t1026*_t980 + _t1026*_t990 + _t1027*_t427 + _t1027*_t442 + _t1027*_t443 + _t1029*_t353 + _t1030*_t362 + _t1030*_t374 + _t1031*_t362 + _t1031*_t374 + _t1032*_t353 + _t1033*_t507 + _t1034*_t890 + _t1035*_t962 + _t1036*_t963 + _t1038*_t104 + _t1038*_t99 + _t1039*_t446 + _t1039*_t508 + _t1039*_t866 + _t104*_t1045 + _t104*_t1049 + _t1040*_t997 + _t1041*_t782 + _t1043*_t20 + _t1044*_t152 + _t1044*_t154 + _t1044*_t169 + _t1045*_t99 + _t1046*_t446 + _t1046*_t508 + _t1046*_t866 + _t1047*_t446 + _t1047*_t508 + _t1047*_t866 + _t1048*_t961 + _t1048*_t962 + _t1049*_t99 + _t1050*_t955 + _t11*(_t1042 + _t1043) + _t115*_t518 + _t133*_t533 + _t196*_t527 + _t216*_t884 + _t219*(-_hc2[4]*_t1052 - _hc2[8]*_t536 - _hc3[4]*_t1054 - _hc3[5]*_t509 - _hc3[8]*_t144 - _t106*_t495 - _t142*_t502 - _t174*_t476 - 0.2e1*_t504 - 0.2e1*_t505 - 0.2e1*_t506 - _t55*_t998) + _t29*(-_hc2[1]*_hc2[9]*_t45 - _hc2[13]*_t46 - _hc2[2]*_hc2[8]*_t364 - _hc2[5]*_t891 - _hc3[1]*_hc3[9]*_t47 - _hc3[13]*_t48 - _hc3[5]*_t1051 - _hc3[8]*_t531 - _t1*_t1043 - _t1042*_t3 - _t1044*_t54 - _t173*_t524 - _t201*_t877 - _t38*_t518 - _t39*_t517 - _t494*_t522) + _t324*_t533 + _t394*_t524 + _t395*_t524 + _t396*_t524 + _t397*_t525 + _t398*_t524 + _t413*_t524 + _t414*_t524 + _t426*_t524 + _t427*_t525 + _t435*_t519 + _t438*_t519 + _t442*_t525 + _t443*_t525 + _t444*_t525 + _t461*_t877 + _t462*_t878 + _t465*_t877 + _t471*_t878 + _t489*_t877 + _t490*_t883 + 0.3e1*_t496*_t498 + _t496*_t520 + _t499*_t883 + _t507*_t529 + _t518*_t93 + _t518*_t95 + _t521*_t804 + _t522*_t920 + _t522*_t921 + _t522*_t924 + _t522*_t934 + _t522*_t944 + _t522*_t950 + _t522*_t972 + _t523*_t922 + _t523*_t923 + _t523*_t933 + _t523*_t948 + _t523*_t983 + _t526*_t804 + _t528*_t925 + _t528*_t945 + _t528*_t958 + _t528*_t960 + _t528*_t984 + _t528*_t993 + _t534*_t963 + _t535*_t945 + _t535*_t958 + _t535*_t960 + _t535*_t984 + _t538*_t988 + _t538*_t991 + _t539*_t963 + _t541*(-_hc2[0]*_t891 - _hc3[0]*_t1051 - _hc3[2]*_t367 - _t190*_t364 - 0.3e1*_t192 - 0.3e1*_t193 - 0.3e1*_t194 - 0.3e1*_t195) + _t877*_t952 + 0.3e1*_t939*_t942 + _t941*_t994) + _t390*_t516 + _t431*_t516 + _t511*_t515 + _t514*(-_t131*_t168 - _t132*_t169 - 0.2e1*_t176 - 0.2e1*_t177 - 0.2e1*_t179 - 0.2e1*_t180 - 0.2e1*_t181 - 0.2e1*_t182 - 0.2e1*_t183 - 0.2e1*_t184 - 0.2e1*_t185 - 0.2e1*_t186 - 0.2e1*_t187 - 0.2e1*_t188 - 0.2e1*_t189 - 0.2e1*_t197 - 0.2e1*_t198) + _t516*_t918 + _t542*_t88 + _t581*_t999 + _t742*_t999;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = 0.3e1*_t1000*_t1001 + 0.2e1*_t1002*_t516 + 0.3e1*_t1003*_t516 - _t149*_t542 + _t34*(_hc3[14]*_t58 + 0.4e1*_hc3[9]*_t981 + _t1005*_t1062 + _t1007*_t973 + _t1008*_t1061 + _t1011*_t202 + 0.6e1*_t1017*_t942 + _t1018*_t1061 + _t1028*_t1035*_t216 + _t1029*_t1061 + _t1032*_t1061 + 0.2e1*_t1036*_t1039 + _t1038*_t902 + _t1038*_t904 + 0.4e1*_t1039*_t501 + 0.3e1*_t1039*_t538 + 0.8e1*_t1040*_t500 + _t1041*_t578*(-_hc3[0]*_t1054 - _t150*_t768 - 0.4e1*_t61 - 0.4e1*_t62) + _t1045*_t902 + _t1045*_t904 + _t1049*_t902 + _t1049*_t904 + _t1050*_t491*_t903 + _t1055*_t533 + _t1057*_t20 + _t1058*_t178 + _t1058*_t498 + _t1059*_t464 + _t1059*_t490 + _t1059*_t499 + _t1060*_t157 + _t1060*_t161 + 0.24e2*_t1062*_t473 + _t1063*_t461 + _t1063*_t465 + _t1063*_t952 + _t1064*_t152 + _t1064*_t154 + _t1064*_t169 + _t1065*_t469 + _t1065*_t937 + _t1066*_t157 + _t1066*_t161 + _t1067*_t157 + _t1067*_t161 + _t1068*_t497 + _t1068*_t930 + _t1069*_t157 + _t1069*_t161 + _t1071*_t157 + _t1071*_t161 + _t11*(_t1056 + _t1057) + 0.12e2*_t202*_t471 + _t219*(-_hc2[9]*_t536 - _hc3[9]*_t144 - _t1004*_t1053 - _t106*_t518 - _t1070*_t55 - _t1072*_t202 - _t530*_t773 - 0.2e1*_t532) + _t29*(-_hc2[14]*_t46 - ((_hc2[5]) * (_hc2[5]))*_t364 - _hc2[9]*_t1052 - _hc3[14]*_t48 - ((_hc3[5]) * (_hc3[5]))*_t366 - _hc3[9]*_t1054 - _t1*_t1057 - _t1056*_t3 - _t1070*_t202 - _t476*_t518 - _t517*_t973) + 0.3e1*_t533*_t911 + _t541*(-_hc3[0]*_hc3[5]*_t366 - _t1072*_t55 - 0.3e1*_t211 - 0.3e1*_t212 - _t213*_t364 - _t214*_t366 - _t364*_t459)) + 0.3e1*_t457*_t542 + _t514*(-_t1055*_t63 - _t151*_t902 - _t152*_t973 - _t154*_t973 - _t168*_t902 - _t168*_t904 - 0.2e1*_t204 - 0.2e1*_t205 - 0.2e1*_t206 - 0.2e1*_t217 - 0.2e1*_t220) + _t544*_t999*(-0.3e1*_t57 - 0.3e1*_t59 - 0.3e1*_t60 - 0.3e1*_t64);
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_c5_l_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = M_CBRT2;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g1_k, _KMAX)(p, _t1*rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_D3_k, _KMAX)(p, rs, _hc1);

  const double f = (0.1e1 / 0.2e1)*_hc0[0] + _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = (0.1e1 / 0.2e1)*_hc0[1]*_t1 + _hc1[1];
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = (0.1e1 / 0.2e1)*xc_powr(0.2e1, 2, 3)*_hc0[2] + _hc1[2];
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = _hc0[3] + _hc1[3];
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _hc0[4]*_t1 + _hc1[4];
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_C5_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_c5_l_z0_k, _KMAX)(p, rs, _hc0);
  const double _t1 = xc_powr(0.2e1, 1, 2);
  const double _t2 = xc_powr(M_PI, -1, 2);
  const double _t3 = _t1*_t2;
  const double _t4 = _hc0[0]*_t3;
  const double _t5 = (0.9e1 / 0.80e2)/(rs * rs * rs);
#if _KMAX >= 1
  const double _t6 = (0.1e1 / (rs * rs * rs * rs));
  const double _t7 = _t3*_t5;
#endif
#if _KMAX >= 2
  const double _t8 = xc_powi(rs, -5);
#endif
#if _KMAX >= 3
  const double _t9 = xc_powi(rs, -6);
  const double _t10 = _hc0[2]*_t3;
#endif

  const double f = -_t4*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_hc0[1]*_t7 + (0.27e2 / 0.80e2)*_t4*_t6;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = (0.27e2 / 0.40e2)*_hc0[1]*_t1*_t2*_t6 - _hc0[2]*_t7 - 0.27e2 / 0.20e2*_t4*_t8;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.81e2 / 0.20e2*_hc0[1]*_t3*_t8 - _hc0[3]*_t7 + (0.81e2 / 0.80e2)*_t10*_t6 + (0.27e2 / 0.4e1)*_t4*_t9;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.27e2*_hc0[1]*_t1*_t2*_t9 + (0.27e2 / 0.20e2)*_hc0[3]*_t1*_t2*_t6 - _hc0[4]*_t7 - 0.81e2 / 0.10e2*_t10*_t8 - 0.81e2 / 0.2e1*_t4/xc_powi(rs, 7);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_C3_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g0_k, _KMAX)(p, rs, _hc0);
  const double _t1 = xc_powr(0.2e1, 1, 2);
  const double _t2 = xc_powr(M_PI, -1, 2);
  const double _t3 = _t1*_t2;
  const double _t4 = _hc0[0]*_t3;
  const double _t5 = (0.1e1 / 0.2e1)/(rs * rs * rs);
#if _KMAX >= 1
  const double _t6 = (0.1e1 / (rs * rs * rs * rs));
  const double _t7 = _hc0[1]*_t3;
#endif
#if _KMAX >= 2
  const double _t8 = xc_powi(rs, -5);
  const double _t9 = _t3*_t5;
#endif
#if _KMAX >= 3
  const double _t10 = xc_powi(rs, -6);
  const double _t11 = _hc0[2]*_t3;
#endif

  const double f = -_t4*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = (0.3e1 / 0.2e1)*_t4*_t6 - _t5*_t7;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.3e1*_hc0[1]*_t1*_t2*_t6 - _hc0[2]*_t9 - 0.6e1*_t4*_t8;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -_hc0[3]*_t9 + 0.30e2*_t10*_t4 + (0.9e1 / 0.2e1)*_t11*_t6 - 0.18e2*_t7*_t8;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.120e3*_hc0[1]*_t1*_t10*_t2 + 0.6e1*_hc0[3]*_t1*_t2*_t6 - _hc0[4]*_t9 - 0.36e2*_t11*_t8 - 0.180e3*_t4/xc_powi(rs, 7);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_a1_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_C5_z0_k, _KMAX)(p, rs, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_C3_z0_k, _KMAX)(p, rs, _hc2);
  const double _t1 = xc_powi((_hc0[0]), 8);
  const double _t2 = xc_powi((_hc0[0]), 6);
  const double _t3 = 0.4e1*_t2;
#if _KMAX >= 1
  const double _t4 = xc_powi((_hc0[0]), 5);
  const double _t5 = _hc0[1]*_t4;
  const double _t6 = xc_powi((_hc0[0]), 7)*_hc0[1];
#endif
#if _KMAX >= 2
  const double _t7 = ((_hc0[1]) * (_hc0[1]));
  const double _t8 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t9 = _t7*_t8;
  const double _t10 = _t2*_t7;
#endif
#if _KMAX >= 3
  const double _t11 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t12 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]))*_t11;
  const double _t13 = _t11*_t4;
#endif
#if _KMAX >= 4
  const double _t14 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
#endif

  const double f = _hc1[0]*_t1 + _hc2[0]*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.8e1*_hc1[0]*_t6 + _hc1[1]*_t1 + 0.24e2*_hc2[0]*_t5 + _hc2[1]*_t3;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.56e2*_hc1[0]*_t10 + 0.16e2*_hc1[1]*_t6 + _hc1[2]*_t1 + 0.120e3*_hc2[0]*_t9 + 0.48e2*_hc2[1]*_t5 + _hc2[2]*_t3;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.336e3*_hc1[0]*_t13 + 0.168e3*_hc1[1]*_t10 + 0.24e2*_hc1[2]*_t6 + _hc1[3]*_t1 + 0.480e3*_hc2[0]*_t12 + 0.360e3*_hc2[1]*_t9 + 0.72e2*_hc2[2]*_t5 + _hc2[3]*_t3;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.1440e4*((_hc0[0]) * (_hc0[0]))*_hc2[0]*_t14 + 0.1680e4*_hc1[0]*_t14*_t8 + 0.1344e4*_hc1[1]*_t13 + 0.336e3*_hc1[2]*_t10 + 0.32e2*_hc1[3]*_t6 + _hc1[4]*_t1 + 0.1920e4*_hc2[1]*_t12 + 0.720e3*_hc2[2]*_t9 + 0.96e2*_hc2[3]*_t5 + _hc2[4]*_t3;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_c4_l_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = M_CBRT2;
  const double _t2 = xc_powr(0.2e1, 2, 3);
  const double _t3 = M_CBRT3*(M_CBRTPI * M_CBRTPI)*_t2;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g1_k, _KMAX)(p, _t1*rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_D2_k, _KMAX)(p, rs, _hc1);

  const double f = (0.1e1 / 0.2e1)*_hc0[0] + _hc1[0] - 0.3e1 / 0.20e2*_t3/(rs * rs);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = (0.1e1 / 0.2e1)*_hc0[1]*_t1 + _hc1[1] + (0.3e1 / 0.10e2)*_t3/(rs * rs * rs);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = (0.1e1 / 0.2e1)*_hc0[2]*_t2 + _hc1[2] - 0.9e1 / 0.10e2*_t3/(rs * rs * rs * rs);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = _hc0[3] + _hc1[3] + (0.18e2 / 0.5e1)*_t3/xc_powi(rs, 5);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _hc0[4]*_t1 + _hc1[4] - 0.18e2*_t3/xc_powi(rs, 6);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_C4_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_c4_l_z0_k, _KMAX)(p, rs, _hc0);
  const double _t1 = (0.9e1 / 0.64e2)/(rs * rs * rs);
#if _KMAX >= 1
  const double _t2 = (0.1e1 / (rs * rs * rs * rs));
#endif
#if _KMAX >= 2
  const double _t3 = xc_powi(rs, -5);
#endif
#if _KMAX >= 3
  const double _t4 = xc_powi(rs, -6);
#endif

  const double f = -_hc0[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = (0.27e2 / 0.64e2)*_hc0[0]*_t2 - _hc0[1]*_t1;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -0.27e2 / 0.16e2*_hc0[0]*_t3 + (0.27e2 / 0.32e2)*_hc0[1]*_t2 - _hc0[2]*_t1;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (0.135e3 / 0.16e2)*_hc0[0]*_t4 - 0.81e2 / 0.16e2*_hc0[1]*_t3 + (0.81e2 / 0.64e2)*_hc0[2]*_t2 - _hc0[3]*_t1;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -0.405e3 / 0.8e1*_hc0[0]/xc_powi(rs, 7) + (0.135e3 / 0.4e1)*_hc0[1]*_t4 - 0.81e2 / 0.8e1*_hc0[2]*_t3 + (0.27e2 / 0.16e2)*_hc0[3]*_t2 - _hc0[4]*_t1;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_C2_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g0c_k, _KMAX)(p, rs, _hc0);
  const double _t1 = (0.3e1 / 0.8e1)/(rs * rs * rs);
#if _KMAX >= 1
  const double _t2 = (0.1e1 / (rs * rs * rs * rs));
#endif
#if _KMAX >= 2
  const double _t3 = xc_powi(rs, -5);
#endif
#if _KMAX >= 3
  const double _t4 = xc_powi(rs, -6);
#endif

  const double f = -_hc0[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = (0.9e1 / 0.8e1)*_hc0[0]*_t2 - _hc0[1]*_t1;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -0.9e1 / 0.2e1*_hc0[0]*_t3 + (0.9e1 / 0.4e1)*_hc0[1]*_t2 - _hc0[2]*_t1;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (0.45e2 / 0.2e1)*_hc0[0]*_t4 - 0.27e2 / 0.2e1*_hc0[1]*_t3 + (0.27e2 / 0.8e1)*_hc0[2]*_t2 - _hc0[3]*_t1;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -0.135e3*_hc0[0]/xc_powi(rs, 7) + 0.90e2*_hc0[1]*_t4 - 0.27e2*_hc0[2]*_t3 + (0.9e1 / 0.2e1)*_hc0[3]*_t2 - _hc0[4]*_t1;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = 0.0132882934*rs + 0.062182000000000001;
  const double _t2 = -_t1;
  const double _t3 = pow(rs, 1.5);
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = 0.1018665524*_t3 + 0.4723158174*_t4 + 0.030651995080000001*(rs * rs) + 0.2230841432*rs;
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = xc_log1p(_t6);
#if _KMAX >= 1
  const double _t8 = sqrt(rs);
  const double _t9 = (0.1e1 / _t4);
  const double _t10 = -0.15279982860000002*_t8 - 0.2361579087*_t9 - 0.061303990160000002*rs - 0.2230841432;
  const double _t11 = (0.1e1 / (_t5 * _t5));
  const double _t12 = _t6 + 0.1e1;
  const double _t13 = (0.1e1 / _t12);
#endif
#if _KMAX >= 2
  const double _t14 = _t11*_t13;
  const double _t15 = (0.1e1 / _t8);
  const double _t16 = xc_powr(rs, -3, 2);
  const double _t17 = -0.07639991430000001*_t15 + 0.11807895435*_t16 - 0.061303990160000002;
  const double _t18 = _t14*_t17;
  const double _t19 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t20 = (0.1e1 / (_t12 * _t12));
  const double _t21 = (_t10 * _t10);
  const double _t22 = _t20*_t21;
  const double _t23 = _t19*_t22;
  const double _t24 = _t13/(_t5 * _t5 * _t5);
  const double _t25 = -0.30559965720000004*_t8 - 0.4723158174*_t9 - 0.12260798032*rs - 0.4461682864;
  const double _t26 = _t10*_t2;
  const double _t27 = _t25*_t26;
#endif
#if _KMAX >= 3
  const double _t28 = (0.1e1 / _t3);
  const double _t29 = xc_powr(rs, -5, 2);
  const double _t30 = 0.038199957150000005*_t28 - 0.17711843152500001*_t29;
  const double _t31 = _t14*_t30;
  const double _t32 = (_t10 * _t10 * _t10);
  const double _t33 = (0.1e1 / (_t12 * _t12 * _t12));
  const double _t34 = xc_powi(_t5, -6);
  const double _t35 = _t33*_t34;
  const double _t36 = _t32*_t35;
  const double _t37 = _t10*_t24;
  const double _t38 = -0.15279982860000002*_t15 + 0.2361579087*_t16 - 0.12260798032;
  const double _t39 = _t26*_t38;
  const double _t40 = _t19*_t20;
  const double _t41 = _t17*_t40;
  const double _t42 = _t24*_t25;
  const double _t43 = _t17*_t42;
  const double _t44 = 0.2e1*_t2;
  const double _t45 = -0.61119931440000008*_t8 - 0.94463163480000001*_t9 - 0.24521596064000001*rs - 0.89233657280000001;
  const double _t46 = xc_powi(_t5, -5);
  const double _t47 = _t22*_t46;
  const double _t48 = _t2*_t47;
  const double _t49 = -0.45839948580000006*_t8 - 0.70847372610000003*_t9 - 0.18391197048000002*rs - 0.66925242959999998;
  const double _t50 = _t13*_t19*_t49;
#endif
#if _KMAX >= 4
  const double _t51 = 0.053153173599999999*_t10;
  const double _t52 = _t2*_t38;
  const double _t53 = _t26*(0.07639991430000001*_t28 - 0.35423686305000002*_t29);
  const double _t54 = 0.3e1*_t2;
  const double _t55 = -0.22919974290000003*_t15 + 0.35423686305000002*_t16 - 0.18391197048000002;
  const double _t56 = _t21*_t35;
  const double _t57 = _t44*_t56;
  const double _t58 = _t32*_t33*_t44/xc_powi(_t5, 7);
  const double _t59 = _t25*_t50;
  const double _t60 = _t13*_t27;
  const double _t61 = _t20*_t46;
  const double _t62 = 0.2e1*_t39;
  const double _t63 = _t17*_t61;
  const double _t64 = _t2*_t22*_t34*(-0.76399914300000016*_t8 - 1.1807895435*_t9 - 0.3065199508*rs - 1.115420716);
#endif

  const double f = _t2*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t10*_t11*_t13*_t2 - 0.0132882934*_t7;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t1*_t23 - 0.0265765868*_t10*_t14 + _t18*_t2 + _t24*_t27;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.039864880200000001*_t18 + _t2*_t31 + 0.039864880200000001*_t23 + _t24*_t39 - 0.039864880200000001*_t25*_t37 - _t25*_t48 - _t26*_t41 + _t27*_t50 + _t36*(-0.0265765868*rs - 0.124364) - _t39*_t40 + _t43*_t44 - _t45*_t48;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _t1*(_t17 * _t17)*_t40 + (_t10 * _t10 * _t10 * _t10)*(0.079729760400000002*rs + 0.37309199999999998)/((_t12 * _t12 * _t12 * _t12)*xc_powi(_t5, 8)) + _t14*_t2*(-0.057299935725000008*pow(rs, -2.5) + 0.44279607881250005/xc_powr(rs, 7, 2)) + 0.3e1*_t17*_t24*_t52 + _t17*_t54*_t59 + _t17*_t57 + _t19*_t55*_t60 - _t2*_t22*_t25*_t34*_t49 + _t24*_t53 + _t25*_t58 - _t25*_t64 - 0.2e1*_t26*_t30*_t40 - _t26*_t45*_t63 - _t27*_t38*_t61 - 0.2e1*_t27*_t63 + _t30*_t42*_t54 - 0.053153173599999999*_t31 - 0.1063063472*_t36 - 0.053153173599999999*_t37*_t38 + _t38*_t40*_t51 - 0.2e1*_t38*_t48 - _t40*_t53 + _t41*_t51 - _t41*_t52 - 0.1063063472*_t43 + _t45*_t46*_t49*_t60 + _t45*_t58 - _t45*_t61*_t62 - _t45*_t64 + _t47*(-0.032487183262504181*_t8 - 0.050210169272576204*_t9 - 0.013034006525388686*rs - 0.047430520763667439) + _t47*(-0.01624359163125209*_t8 - 0.025105084636288102*_t9 - 0.0065170032626943432*rs - 0.023715260381833719) - _t48*(-0.30559965720000004*_t15 + 0.4723158174*_t16 - 0.24521596064000001) + _t50*_t62 - _t51*_t59 + 0.2e1*_t52*_t56 + _t55*_t57 + _t58*(-0.91679897160000012*_t8 - 1.4169474522000001*_t9 - 0.36782394096000004*rs - 1.3385048592);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_a2_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_C4_z0_k, _KMAX)(p, rs, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_C2_z0_k, _KMAX)(p, rs, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, rs, _hc3);
  const double _t1 = xc_powi((_hc0[0]), 8);
  const double _t2 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t3 = 0.6e1*_t2;
  const double _t4 = xc_powi((_hc0[0]), 6);
  const double _t5 = 0.4e1*_t4;
#if _KMAX >= 1
  const double _t6 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t7 = 0.24e2*_hc0[1];
  const double _t8 = xc_powi((_hc0[0]), 5);
  const double _t9 = xc_powi((_hc0[0]), 7)*_hc0[1];
#endif
#if _KMAX >= 2
  const double _t10 = 0.48e2*_hc0[1];
  const double _t11 = ((_hc0[1]) * (_hc0[1]));
  const double _t12 = ((_hc0[0]) * (_hc0[0]));
  const double _t13 = _t11*_t12;
  const double _t14 = _t11*_t2;
  const double _t15 = _t11*_t4;
#endif
#if _KMAX >= 3
  const double _t16 = 0.144e3*_hc3[0];
  const double _t17 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t18 = _hc0[0]*_t17;
  const double _t19 = 0.72e2*_hc0[1];
  const double _t20 = _t17*_t6;
  const double _t21 = _t17*_t8;
#endif
#if _KMAX >= 4
  const double _t22 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t23 = 0.96e2*_hc0[1];
#endif

  const double f = _hc1[0]*_t1 + _hc2[0]*_t5 + _hc3[0]*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.8e1*_hc1[0]*_t9 + _hc1[1]*_t1 + _hc2[0]*_t7*_t8 + _hc2[1]*_t5 + _hc3[0]*_t6*_t7 + _hc3[1]*_t3;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.56e2*_hc1[0]*_t15 + 0.16e2*_hc1[1]*_t9 + _hc1[2]*_t1 + 0.120e3*_hc2[0]*_t14 + _hc2[1]*_t10*_t8 + _hc2[2]*_t5 + 0.72e2*_hc3[0]*_t13 + _hc3[1]*_t10*_t6 + _hc3[2]*_t3;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.336e3*_hc1[0]*_t21 + 0.168e3*_hc1[1]*_t15 + 0.24e2*_hc1[2]*_t9 + _hc1[3]*_t1 + 0.480e3*_hc2[0]*_t20 + 0.360e3*_hc2[1]*_t14 + _hc2[2]*_t19*_t8 + _hc2[3]*_t5 + 0.216e3*_hc3[1]*_t13 + _hc3[2]*_t19*_t6 + _hc3[3]*_t3 + _t16*_t18;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.1680e4*_hc1[0]*_t2*_t22 + 0.1344e4*_hc1[1]*_t21 + 0.336e3*_hc1[2]*_t15 + 0.32e2*_hc1[3]*_t9 + _hc1[4]*_t1 + 0.1440e4*_hc2[0]*_t12*_t22 + 0.1920e4*_hc2[1]*_t20 + 0.720e3*_hc2[2]*_t14 + _hc2[3]*_t23*_t8 + _hc2[4]*_t5 + 0.576e3*_hc3[1]*_t18 + 0.432e3*_hc3[2]*_t13 + _hc3[3]*_t23*_t6 + _hc3[4]*_t3 + _t16*_t22;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_a3_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_C3_z0_k, _KMAX)(p, rs, _hc1);
  const double _t1 = xc_powi((_hc0[0]), 8);
#if _KMAX >= 1
  const double _t2 = xc_powi((_hc0[0]), 7)*_hc0[1];
#endif
#if _KMAX >= 2
  const double _t3 = xc_powi((_hc0[0]), 6)*((_hc0[1]) * (_hc0[1]));
#endif
#if _KMAX >= 3
  const double _t4 = xc_powi((_hc0[0]), 5)*((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
#endif

  const double f = _hc1[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.8e1*_hc1[0]*_t2 + _hc1[1]*_t1;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.56e2*_hc1[0]*_t3 + 0.16e2*_hc1[1]*_t2 + _hc1[2]*_t1;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.336e3*_hc1[0]*_t4 + 0.168e3*_hc1[1]*_t3 + 0.24e2*_hc1[2]*_t2 + _hc1[3]*_t1;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.1680e4*((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]))*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[0] + 0.1344e4*_hc1[1]*_t4 + 0.336e3*_hc1[2]*_t3 + 0.32e2*_hc1[3]*_t2 + _hc1[4]*_t1;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_a4_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_C2_z0_k, _KMAX)(p, rs, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, rs, _hc2);
  const double _t1 = xc_powi((_hc0[0]), 8);
  const double _t2 = xc_powi((_hc0[0]), 6);
  const double _t3 = 0.4e1*_t2;
#if _KMAX >= 1
  const double _t4 = xc_powi((_hc0[0]), 5);
  const double _t5 = _hc0[1]*_t4;
  const double _t6 = xc_powi((_hc0[0]), 7)*_hc0[1];
#endif
#if _KMAX >= 2
  const double _t7 = ((_hc0[1]) * (_hc0[1]));
  const double _t8 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t9 = _t7*_t8;
  const double _t10 = _t2*_t7;
#endif
#if _KMAX >= 3
  const double _t11 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t12 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]))*_t11;
  const double _t13 = _t11*_t4;
#endif
#if _KMAX >= 4
  const double _t14 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
#endif

  const double f = _hc1[0]*_t1 + _hc2[0]*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.8e1*_hc1[0]*_t6 + _hc1[1]*_t1 + 0.24e2*_hc2[0]*_t5 + _hc2[1]*_t3;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.56e2*_hc1[0]*_t10 + 0.16e2*_hc1[1]*_t6 + _hc1[2]*_t1 + 0.120e3*_hc2[0]*_t9 + 0.48e2*_hc2[1]*_t5 + _hc2[2]*_t3;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.336e3*_hc1[0]*_t13 + 0.168e3*_hc1[1]*_t10 + 0.24e2*_hc1[2]*_t6 + _hc1[3]*_t1 + 0.480e3*_hc2[0]*_t12 + 0.360e3*_hc2[1]*_t9 + 0.72e2*_hc2[2]*_t5 + _hc2[3]*_t3;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.1440e4*((_hc0[0]) * (_hc0[0]))*_hc2[0]*_t14 + 0.1680e4*_hc1[0]*_t14*_t8 + 0.1344e4*_hc1[1]*_t13 + 0.336e3*_hc1[2]*_t10 + 0.32e2*_hc1[3]*_t6 + _hc1[4]*_t1 + 0.1920e4*_hc2[1]*_t12 + 0.720e3*_hc2[2]*_t9 + 0.96e2*_hc2[3]*_t5 + _hc2[4]*_t3;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_a5_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, rs, _hc1);
  const double _t1 = xc_powi((_hc0[0]), 8);
#if _KMAX >= 1
  const double _t2 = xc_powi((_hc0[0]), 7)*_hc0[1];
#endif
#if _KMAX >= 2
  const double _t3 = xc_powi((_hc0[0]), 6)*((_hc0[1]) * (_hc0[1]));
#endif
#if _KMAX >= 3
  const double _t4 = xc_powi((_hc0[0]), 5)*((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
#endif

  const double f = _hc1[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.8e1*_hc1[0]*_t2 + _hc1[1]*_t1;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.56e2*_hc1[0]*_t3 + 0.16e2*_hc1[1]*_t2 + _hc1[2]*_t1;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.336e3*_hc1[0]*_t4 + 0.168e3*_hc1[1]*_t3 + 0.24e2*_hc1[2]*_t2 + _hc1[3]*_t1;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.1680e4*((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]))*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[0] + 0.1344e4*_hc1[1]*_t4 + 0.336e3*_hc1[2]*_t3 + 0.32e2*_hc1[3]*_t2 + _hc1[4]*_t1;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_f_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_a1_z0_k, _KMAX)(p, rs, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_a2_z0_k, _KMAX)(p, rs, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_a3_z0_k, _KMAX)(p, rs, _hc3);
  double _hc4[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_a4_z0_k, _KMAX)(p, rs, _hc4);
  double _hc5[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_a5_z0_k, _KMAX)(p, rs, _hc5);
  const double _t1 = xc_powr(rs, 1, 2);
  const double _t2 = ((_hc0[0]) * (_hc0[0]));
  const double _t3 = ((p->cam_omega) * (p->cam_omega));
  const double _t4 = _t2*_t3 + 0.1e1;
  const double _t5 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t6 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t7 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t8 = xc_powi((p->cam_omega), 5);
  const double _t9 = xc_powi((p->cam_omega), 6);
  const double _t10 = xc_powi((p->cam_omega), 8);
#if _KMAX >= 1
  const double _t12 = xc_powi(_t4, -5);
  const double _t13 = _t12*_t3;
  const double _t14 = 0.8e1*_t13;
  const double _t15 = _hc0[0]*_hc0[1];
#endif
#if _KMAX >= 2
  const double _t18 = ((_hc0[1]) * (_hc0[1]));
  const double _t20 = _t7/xc_powi(_t4, 6);
  const double _t21 = _t2*_t20;
  const double _t22 = _t13*_t15;
  const double _t23 = xc_powr(rs, -3, 2);
#endif
#if _KMAX >= 3
  const double _t26 = 0.240e3*_t20;
  const double _t27 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t29 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t30 = xc_powi(_t4, -7);
  const double _t31 = (0.3e1 / 0.8e1)/xc_powr(rs, 5, 2);
  const double _t32 = (0.1e1 / (rs * rs));
#endif
#if _KMAX >= 4
  const double _t35 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
#endif
  double _hc6[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_Q_k, _KMAX)(p, _t1*p->cam_omega, _hc6);
  double _hc7[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, rs, _hc7);
  const double _t11 = _hc1[0]*_t6 + _hc2[0]*_t7 + _hc3[0]*_t8 + _hc4[0]*_t9 + _hc5[0]*_t10 + _hc6[0];
#if _KMAX >= 1
  const double _t16 = _hc6[1]*p->cam_omega;
  const double _t17 = _hc1[1]*_t6 + _hc2[1]*_t7 + _hc3[1]*_t8 + _hc4[1]*_t9 + _hc5[1]*_t10 + (0.1e1 / 0.2e1)*_t16/_t1;
#endif
#if _KMAX >= 2
  const double _t19 = _t11*_t18;
  const double _t24 = _hc6[2]*_t3;
  const double _t25 = _hc1[2]*_t6 + _hc2[2]*_t7 + _hc3[2]*_t8 + _hc4[2]*_t9 + _hc5[2]*_t10 - 0.1e1 / 0.4e1*_t16*_t23 + (0.1e1 / 0.4e1)*_t24/rs;
#endif
#if _KMAX >= 3
  const double _t28 = _t11*_t27;
  const double _t33 = _hc6[3]*_t6;
  const double _t34 = _hc1[3]*_t6 + _hc2[3]*_t7 + _hc3[3]*_t8 + _hc4[3]*_t9 + _hc5[3]*_t10 + _t16*_t31 + (0.1e1 / 0.8e1)*_t23*_t33 - 0.3e1 / 0.8e1*_t24*_t32;
#endif
#if _KMAX >= 4
  const double _t36 = _t11*_t35;
#endif

  const double f = _hc7[0] - _t11*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _hc7[1] + _t11*_t14*_t15 - _t17*_t5;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc7[2] + _t14*_t19 + 0.16e2*_t17*_t22 - 0.80e2*_t19*_t21 - _t25*_t5;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -_hc0[0]*_t26*_t28 + _hc7[3] + 0.24e2*_t13*_t17*_t18 - _t17*_t18*_t2*_t26 + 0.24e2*_t22*_t25 + 0.960e3*_t28*_t29*_t30*_t9 - _t34*_t5;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -0.13440e5*((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]))*_t10*_t36/xc_powi(_t4, 8) + 0.32e2*_hc0[0]*_hc0[1]*_t12*_t3*_t34 - 0.960e3*_hc0[0]*_t17*_t20*_t27 + _hc7[4] + 0.5760e4*_t11*_t2*_t30*_t35*_t9 + 0.48e2*_t12*_t18*_t25*_t3 + 0.3840e4*_t17*_t27*_t29*_t30*_t9 - 0.480e3*_t18*_t21*_t25 - _t26*_t36 - _t5*(_hc1[4]*_t6 + _hc2[4]*_t7 + _hc3[4]*_t8 + _hc4[4]*_t9 + _hc5[4]*_t10 + (0.1e1 / 0.16e2)*_hc6[4]*_t32*_t7 - 0.15e2 / 0.16e2*_t16/xc_powr(rs, 7, 2) + (0.15e2 / 0.16e2)*_t24/(rs * rs * rs) - _t31*_t33);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_c_erf_gws_beta_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {
  const gga_c_pbe_erf_gws_params *params = (const gga_c_pbe_erf_gws_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_f_z0_k, _KMAX)(p, rs, _hc1);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = params->beta*pow(_hc1[0]*_t1, params->a_c);
#if _KMAX >= 1
  const double _t3 = params->a_c/_hc1[0];
  const double _t4 = ((_hc0[0]) * (_hc0[0]));
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = _hc1[0]*_t5;
  const double _t7 = -_hc0[1]*_t6 + _hc1[1]*_t1;
  const double _t8 = _t2*_t7;
  const double _t9 = _hc0[0]*_t8;
#endif
#if _KMAX >= 2
  const double _t10 = _t3*_t8;
  const double _t11 = (0.1e1 / ((_hc1[0]) * (_hc1[0])));
  const double _t12 = _t11*params->a_c;
  const double _t13 = _t12*_t9;
  const double _t14 = _t2*(_t7 * _t7);
  const double _t15 = ((params->a_c) * (params->a_c));
  const double _t16 = _t15*_t4;
  const double _t17 = _t11*_t16;
  const double _t18 = _hc1[2]*_t1;
  const double _t19 = _hc0[1]*_t5;
  const double _t20 = 0.2e1*_hc1[1];
  const double _t21 = _hc0[2]*_t6;
  const double _t22 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t23 = (0.1e1 / _t22);
  const double _t24 = ((_hc0[1]) * (_hc0[1]));
  const double _t25 = _t23*_t24;
  const double _t26 = _hc1[0]*_t25;
  const double _t27 = _t18 - _t19*_t20 - _t21 + 0.2e1*_t26;
  const double _t28 = _t2*_t3;
  const double _t29 = _hc0[0]*_t28;
#endif
#if _KMAX >= 3
  const double _t30 = _t12*_t20;
  const double _t31 = _hc0[1]*_t8;
  const double _t32 = _t9*params->a_c;
  const double _t33 = (0.1e1 / ((_hc1[0]) * (_hc1[0]) * (_hc1[0])));
  const double _t34 = ((_hc1[1]) * (_hc1[1]));
  const double _t35 = _t33*_t34;
  const double _t36 = _t2*_t33;
  const double _t37 = (_t7 * _t7 * _t7);
  const double _t38 = ((params->a_c) * (params->a_c) * (params->a_c));
  const double _t39 = _t22*_t38;
  const double _t40 = _t37*_t39;
  const double _t41 = _t14*_t15;
  const double _t42 = _t11*_t41;
  const double _t43 = 0.3e1*_t42;
  const double _t44 = _hc0[0]*_hc0[1];
  const double _t45 = 0.3e1*_hc1[1];
  const double _t46 = _t14*_t33;
  const double _t47 = _t16*_t46;
  const double _t48 = _hc0[1]*_t28;
  const double _t49 = _hc0[0]*_t27;
  const double _t50 = _t17*_t8;
  const double _t51 = 0.4e1*_t19;
  const double _t52 = -_hc1[1]*_t51 + 0.2e1*_t18 - 0.2e1*_t21 + 0.4e1*_t26;
  const double _t53 = _hc0[3]*_t6;
  const double _t54 = _hc1[2]*_t19;
  const double _t55 = _hc0[2]*_t5;
  const double _t56 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t57 = (0.1e1 / _t56);
  const double _t58 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t57;
  const double _t59 = 0.6e1*_hc1[0];
  const double _t60 = 0.6e1*_hc0[1]*_hc0[2]*_hc1[0]*_t23 + 0.6e1*_hc1[1]*_t23*_t24 + _hc1[3]*_t1 - _t45*_t55 - _t53 - 0.3e1*_t54 - _t58*_t59;
#endif
#if _KMAX >= 4
  const double _t61 = 0.6e1*_hc1[1];
  const double _t62 = (0.1e1 / ((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0])));
  const double _t63 = _t2*_t62;
  const double _t64 = _hc1[1]*_t33;
  const double _t65 = 0.6e1*_t36;
  const double _t66 = 0.3e1*_t27;
  const double _t67 = _t12*_t2;
  const double _t68 = _hc0[0]*_t67;
  const double _t69 = _hc0[1]*_t27;
  const double _t70 = _t17*_t2;
  const double _t71 = _t11*_t15*_t9;
  const double _t72 = 0.5e1*_t52;
  const double _t73 = _t39*_t46;
  const double _t74 = 0.4e1*_hc1[1];
  const double _t75 = _t16*_t8;
  const double _t76 = 0.24e2*_hc1[1];
#endif

  const double f = _t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t3*_t9;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc0[1]*_t10 - _hc1[1]*_t13 + _t14*_t17 + _t27*_t29;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = _hc0[2]*_t10 - _hc1[2]*_t13 - _t2*_t30*_t49 + 0.2e1*_t27*_t48 + _t27*_t50 + _t29*_t60 - _t30*_t31 + 0.2e1*_t32*_t35 + _t36*_t40 + _t43*_t44 - _t45*_t47 + _t50*_t52;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.4e1*_hc0[0]*_hc0[2]*_t42 + _hc0[1]*_t37*_t38*_t4*_t65 + _hc0[1]*_t71*_t72 - _hc0[2]*_t12*_t45*_t8 + _hc0[2]*_t28*_t66 + _hc0[3]*_t10 - 0.6e1*((_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_t32*_t62 - 0.3e1*_hc1[2]*_t12*_t31 + _hc1[2]*_t32*_t33*_t61 - 0.4e1*_hc1[2]*_t47 - _hc1[2]*_t66*_t68 - _hc1[3]*_t13 + 0.11e2*_t14*_t16*_t34*_t62 + _t24*_t43 + (_t27 * _t27)*_t70 - _t27*_t33*_t74*_t75 + _t27*_t52*_t70 + _t27*_t73 + _t29*(_hc0[1]*_hc0[2]*_t23*_t76 + 0.8e1*_hc0[1]*_hc0[3]*_hc1[0]*_t23 + ((_hc0[2]) * (_hc0[2]))*_t23*_t59 - 0.36e2*_hc0[2]*_hc1[0]*_t24*_t57 - _hc0[3]*_t5*_t74 - _hc0[4]*_t6 + 0.12e2*_hc1[2]*_t25 - 0.6e1*_hc1[2]*_t55 - _hc1[3]*_t51 + _hc1[4]*_t1 - _t58*_t76 + 0.24e2*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[0]/xc_powi((_hc0[0]), 5)) + 0.6e1*_t31*_t35*params->a_c + _t34*_t49*_t65*params->a_c - _t40*_t61*_t63 - 0.14e2*_t41*_t44*_t64 - _t45*_t60*_t68 + 0.3e1*_t48*_t60 + 0.2e1*_t50*_t60 + _t50*(0.12e2*_hc0[1]*_hc0[2]*_hc1[0]*_t23 - 0.12e2*_hc1[0]*_t58 + 0.12e2*_hc1[1]*_t23*_t24 + 0.2e1*_hc1[3]*_t1 - 0.2e1*_t53 - 0.6e1*_t54 - _t55*_t61) + _t52*_t73 + _t56*_t63*(_t7 * _t7 * _t7 * _t7)*((params->a_c) * (params->a_c) * (params->a_c) * (params->a_c)) - _t61*_t67*_t69 - _t64*_t72*_t75 + 0.4e1*_t69*_t71 + _t73*(0.3e1*_t18 - _t19*_t61 - 0.3e1*_t21 + 0.6e1*_t26);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_c_erf_gws_E_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {
  const gga_c_pbe_erf_gws_params *params = (const gga_c_pbe_erf_gws_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_f_z0_k, _KMAX)(p, rs, _hc0);
  const double _t1 = (0.1e1 / (params->gamma));
  const double _t2 = xc_expm1(-_hc0[0]*_t1);
#if _KMAX >= 1
  const double _t3 = _t2 + 0.1e1;
  const double _t4 = _t1*_t3;
#endif
#if _KMAX >= 2
  const double _t5 = ((_hc0[1]) * (_hc0[1]));
  const double _t6 = (0.1e1 / ((params->gamma) * (params->gamma)));
  const double _t7 = _t3*_t6;
#endif
#if _KMAX >= 3
  const double _t8 = _t3/((params->gamma) * (params->gamma) * (params->gamma));
#endif

  const double f = _t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_hc0[1]*_t4;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -_hc0[2]*_t4 + _t5*_t7;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t8 + 0.3e1*_hc0[1]*_hc0[2]*_t3*_t6 - _hc0[3]*_t4;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t3/((params->gamma) * (params->gamma) * (params->gamma) * (params->gamma)) + 0.4e1*_hc0[1]*_hc0[3]*_t7 + 0.3e1*((_hc0[2]) * (_hc0[2]))*_t7 - 0.6e1*_hc0[2]*_t5*_t8 - _hc0[4]*_t4;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_c_erf_gws_H_z0_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {
  const gga_c_pbe_erf_gws_params *params = (const gga_c_pbe_erf_gws_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pbe_c_erf_gws_beta_z0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pbe_c_erf_gws_E_z0_k, _KMAX)(p, rs, _hc1);
  const double _t1 = _hc1[0]*params->gamma;
  const double _t2 = (t * t);
  const double _t3 = _hc0[0]*_t2;
  const double _t4 = _t1 + _t3;
  const double _t5 = ((_hc0[0]) * (_hc0[0]));
  const double _t6 = (t * t * t * t);
  const double _t7 = ((params->gamma) * (params->gamma));
  const double _t8 = ((_hc1[0]) * (_hc1[0]))*_t7 + _t1*_t3 + _t5*_t6;
  const double _t9 = (0.1e1 / _t8);
  const double _t10 = _hc1[0]*_t9;
  const double _t11 = _t10*_t3;
  const double _t12 = _t11*_t4;
#if _KMAX >= 1
  const double _t13 = (t * t * t);
  const double _t14 = _t13*_t5;
  const double _t15 = 0.2e1*_t10;
  const double _t16 = 0.2e1*_hc0[0];
  const double _t17 = _t10*_t4;
  const double _t18 = _t16*_t17;
  const double _t19 = _t1*_t16;
  const double _t20 = 0.4e1*_t14;
  const double _t21 = -_t19*t - _t20;
  const double _t22 = _t3*_t4;
  const double _t23 = (0.1e1 / (_t8 * _t8));
  const double _t24 = _hc1[0]*_t23;
  const double _t25 = _t22*_t24;
  const double _t26 = _t21*_t25;
  const double _t27 = _t14*_t15 + _t18*t + _t26;
  const double _t28 = _t12 + 0.1e1;
  const double _t29 = params->gamma/_t28;
  const double _t30 = _hc1[1]*params->gamma;
  const double _t31 = _hc0[1]*_t2;
  const double _t32 = _t30 + _t31;
  const double _t33 = _t11*_t32;
  const double _t34 = _hc1[1]*_t9;
  const double _t35 = _t22*_t34;
  const double _t36 = _t17*_t31;
  const double _t37 = _hc0[1]*_t6;
  const double _t38 = _hc1[0]*_t7;
  const double _t39 = 0.2e1*_hc1[1];
  const double _t40 = _t3*_t30;
  const double _t41 = _t1*_t31;
  const double _t42 = -_t16*_t37 - _t38*_t39 - _t40 - _t41;
  const double _t43 = _t25*_t42;
  const double _t44 = _t33 + _t35 + _t36 + _t43;
#endif
#if _KMAX >= 2
  const double _t45 = -_t27;
  const double _t46 = params->gamma/(_t28 * _t28);
  const double _t47 = _t45*_t46;
  const double _t48 = _t2*_t5;
  const double _t49 = 0.10e2*_t48;
  const double _t50 = _t21*_t24;
  const double _t51 = 0.4e1*_hc0[0];
  const double _t52 = _t51*t;
  const double _t53 = _t4*_t50;
  const double _t54 = -_t19 - 0.12e2*_t48;
  const double _t55 = _t25*_t54;
  const double _t56 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t57 = _hc1[0]*_t56;
  const double _t58 = _t1*_t51;
  const double _t59 = 0.8e1*_t14;
  const double _t60 = -_t58*t - _t59;
  const double _t61 = _t21*_t22;
  const double _t62 = _t60*_t61;
  const double _t63 = _t57*_t62;
  const double _t64 = _t10*_t49 + _t18 + _t20*_t50 + _t52*_t53 + _t55 + _t63;
  const double _t65 = 0.4e1*_t10;
  const double _t66 = _hc0[0]*_hc0[1];
  const double _t67 = _t13*_t66;
  const double _t68 = _t14*_t9;
  const double _t69 = _t10*_t16;
  const double _t70 = _t32*_t69;
  const double _t71 = _t16*_t4;
  const double _t72 = _t34*_t71;
  const double _t73 = _t15*_t4;
  const double _t74 = _hc0[1]*_t73;
  const double _t75 = _t3*_t32;
  const double _t76 = _t50*_t75;
  const double _t77 = _hc1[1]*_t23;
  const double _t78 = _t31*_t4;
  const double _t79 = _t50*_t78;
  const double _t80 = _t16*_t30;
  const double _t81 = 0.2e1*_t1;
  const double _t82 = _hc0[1]*_t81;
  const double _t83 = 0.8e1*_t13;
  const double _t84 = _t66*_t83;
  const double _t85 = -_t80*t - _t82*t - _t84;
  const double _t86 = _t25*_t85;
  const double _t87 = _t24*_t42;
  const double _t88 = 0.2e1*_t14;
  const double _t89 = _t71*_t87;
  const double _t90 = _t22*_t42;
  const double _t91 = _t57*_t60;
  const double _t92 = _t90*_t91;
  const double _t93 = _t39*_t68 + _t61*_t77 + _t65*_t67 + _t70*t + _t72*t + _t74*t + _t76 + _t79 + _t86 + _t87*_t88 + _t89*t + _t92;
  const double _t94 = -_t44;
  const double _t95 = _t44*_t46;
  const double _t96 = _hc1[2]*params->gamma;
  const double _t97 = _hc0[2]*_t2;
  const double _t98 = _t96 + _t97;
  const double _t99 = _t11*_t98;
  const double _t100 = _t22*_t9;
  const double _t101 = _hc1[2]*_t100;
  const double _t102 = _t39*_t9;
  const double _t103 = _t31*_t32;
  const double _t104 = 0.2e1*_t87;
  const double _t105 = _t23*_t39;
  const double _t106 = _t16*_t6;
  const double _t107 = 0.2e1*_t38;
  const double _t108 = _t3*_t96;
  const double _t109 = _t1*_t97;
  const double _t110 = ((_hc0[1]) * (_hc0[1]));
  const double _t111 = _t110*_t6;
  const double _t112 = ((_hc1[1]) * (_hc1[1]))*_t7;
  const double _t113 = _t30*_t31;
  const double _t114 = -_hc0[2]*_t106 - _hc1[2]*_t107 - _t108 - _t109 - 0.2e1*_t111 - 0.2e1*_t112 - 0.2e1*_t113;
  const double _t115 = _t114*_t25;
  const double _t116 = 0.4e1*_t38;
  const double _t117 = -_hc1[1]*_t116 - _t37*_t51 - 0.2e1*_t40 - 0.2e1*_t41;
  const double _t118 = _t57*_t90;
  const double _t119 = _t117*_t118;
  const double _t120 = _t101 + _t102*_t75 + _t102*_t78 + _t103*_t15 + _t104*_t75 + _t104*_t78 + _t105*_t90 + _t115 + _t119 + _t17*_t97 + _t99;
#endif
#if _KMAX >= 3
  const double _t121 = _t17*_t51;
  const double _t122 = -_t10*_t20 - _t121*t - 0.2e1*_t26;
  const double _t123 = params->gamma/(_t28 * _t28 * _t28);
  const double _t124 = _t122*_t123;
  const double _t125 = _t124*_t45;
  const double _t126 = 0.2e1*_t47;
  const double _t127 = -_t64;
  const double _t128 = _t27*_t46;
  const double _t129 = 0.24e2*_t5;
  const double _t130 = _t10*_t129;
  const double _t131 = 0.24e2*_t13;
  const double _t132 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t133 = _t24*_t4;
  const double _t134 = _t132*_t133;
  const double _t135 = 0.6e1*_t14;
  const double _t136 = _t24*_t54;
  const double _t137 = 0.30e2*_t48;
  const double _t138 = 0.6e1*_hc0[0];
  const double _t139 = _t133*_t54;
  const double _t140 = 0.6e1*t;
  const double _t141 = _hc0[0]*_t140;
  const double _t142 = _t21*_t91;
  const double _t143 = _t142*_t4;
  const double _t144 = -0.24e2*_t48 - _t58;
  const double _t145 = _t144*_t57;
  const double _t146 = _t54*_t91;
  const double _t147 = 0.2e1*_t146;
  const double _t148 = _hc0[0]*_t1;
  const double _t149 = 0.6e1*_t148;
  const double _t150 = 0.12e2*_t14;
  const double _t151 = -_t149*t - _t150;
  const double _t152 = (0.1e1 / (_t8 * _t8 * _t8 * _t8));
  const double _t153 = _hc1[0]*_t152;
  const double _t154 = _t151*_t153;
  const double _t155 = _t130*t - _t131*_t134 + _t135*_t136 + _t135*_t142 + _t137*_t50 + _t138*_t53 + _t139*_t141 + _t141*_t143 + _t145*_t61 + _t147*_t22 + _t154*_t62;
  const double _t156 = _hc0[1]*_t3;
  const double _t157 = 0.20e2*_t10;
  const double _t158 = _t20*_t77;
  const double _t159 = _t24*_t85;
  const double _t160 = _t32*_t51;
  const double _t161 = _t50*t;
  const double _t162 = _t4*_t77;
  const double _t163 = _t162*_t21;
  const double _t164 = _t54*_t77;
  const double _t165 = 0.4e1*_hc0[1];
  const double _t166 = _t165*_t4;
  const double _t167 = 0.24e2*_t3;
  const double _t168 = -_hc0[1]*_t167 - _t80 - _t82;
  const double _t169 = _t133*_t85;
  const double _t170 = _hc1[1]*_t56;
  const double _t171 = _t22*_t85;
  const double _t172 = 0.2e1*_t91;
  const double _t173 = _t42*_t91;
  const double _t174 = _t173*_t4;
  const double _t175 = _t60*_t90;
  const double _t176 = _t118*_t144 + _t136*_t75 + _t136*_t78 + _t142*_t75 + _t142*_t78 + _t154*_t175 + _t156*_t157 + _t158*_t21 + _t159*_t20 + _t160*_t161 + _t161*_t166 + _t163*_t52 + _t164*_t22 + _t168*_t25 + _t169*_t52 + _t170*_t62 + _t171*_t172 + _t173*_t20 + _t174*_t52 + _t34*_t49 + _t49*_t87 + _t50*_t84 + _t70 + _t72 + _t74 + _t89;
  const double _t177 = _t44*_t94;
  const double _t178 = _t46*_t94;
  const double _t179 = -_t93;
  const double _t180 = _t10*_t13;
  const double _t181 = _t180*_t51;
  const double _t182 = 0.2e1*_t68;
  const double _t183 = _t110*_t13;
  const double _t184 = _t69*_t98;
  const double _t185 = _t34*t;
  const double _t186 = _hc1[2]*_t9;
  const double _t187 = _t186*_t71;
  const double _t188 = _t10*_t32;
  const double _t189 = _t165*_t188;
  const double _t190 = _hc0[2]*_t73;
  const double _t191 = _t3*_t98;
  const double _t192 = _hc1[2]*_t23;
  const double _t193 = _t105*_t21;
  const double _t194 = 0.2e1*_t103;
  const double _t195 = 0.2e1*_t159;
  const double _t196 = _t87*t;
  const double _t197 = _t162*_t42;
  const double _t198 = _t16*_t96;
  const double _t199 = _t165*_t30;
  const double _t200 = _hc0[2]*_t81;
  const double _t201 = _hc0[0]*_t83;
  const double _t202 = _hc0[2]*_t201;
  const double _t203 = 0.8e1*_t183;
  const double _t204 = -_t198*t - _t199*t - _t200*t - _t202 - _t203;
  const double _t205 = 0.2e1*_t173;
  const double _t206 = _t39*_t56;
  const double _t207 = _t114*_t24;
  const double _t208 = _t30*_t51;
  const double _t209 = _t1*_t165;
  const double _t210 = 0.16e2*_t13;
  const double _t211 = _t210*_t66;
  const double _t212 = -_t208*t - _t209*t - _t211;
  const double _t213 = _t117*_t57;
  const double _t214 = _t207*_t71;
  const double _t215 = _t213*_t42;
  const double _t216 = _t71*t;
  const double _t217 = _t114*_t91;
  const double _t218 = _t117*_t90;
  const double _t219 = _hc0[2]*_t181 + _hc1[2]*_t182 + _t105*_t171 + _t118*_t212 + _t154*_t218 + _t158*_t42 + _t160*_t185 + _t160*_t196 + _t166*_t185 + _t166*_t196 + _t171*_t213 + _t175*_t206 + _t183*_t65 + _t184*t + _t187*t + _t189*t + _t190*t + _t191*_t50 + _t192*_t61 + _t193*_t75 + _t193*_t78 + _t194*_t50 + _t195*_t75 + _t195*_t78 + _t197*_t52 + _t204*_t25 + _t205*_t75 + _t205*_t78 + _t207*_t88 + _t214*t + _t215*_t216 + _t215*_t88 + _t217*_t22 + _t34*_t84 + _t53*_t97 + _t84*_t87;
  const double _t220 = -_t100*_t39 - _t31*_t73 - 0.2e1*_t33 - 0.2e1*_t43;
  const double _t221 = _t123*_t177;
  const double _t222 = 0.2e1*_t178;
  const double _t223 = -_t120;
  const double _t224 = _hc1[3]*params->gamma;
  const double _t225 = _hc0[3]*_t2;
  const double _t226 = _t224 + _t225;
  const double _t227 = 0.3e1*_t34;
  const double _t228 = 0.3e1*_t186;
  const double _t229 = _t10*_t98;
  const double _t230 = 0.3e1*_t31;
  const double _t231 = 0.6e1*_t103;
  const double _t232 = 0.3e1*_t97;
  const double _t233 = _t4*_t97;
  const double _t234 = 0.3e1*_t191;
  const double _t235 = _t42*_t77;
  const double _t236 = 0.6e1*_t235;
  const double _t237 = _t192*_t22;
  const double _t238 = 0.3e1*_t237;
  const double _t239 = _t4*_t87;
  const double _t240 = 0.3e1*_t207;
  const double _t241 = _t114*_t77;
  const double _t242 = 0.3e1*_t22;
  const double _t243 = 0.6e1*_t6;
  const double _t244 = _hc0[1]*_hc0[2];
  const double _t245 = 0.6e1*_t7;
  const double _t246 = _hc1[1]*_t245;
  const double _t247 = _t224*_t3;
  const double _t248 = _t31*_t96;
  const double _t249 = _t30*_t97;
  const double _t250 = -_hc0[3]*_t106 - _hc1[2]*_t246 - _hc1[3]*_t107 - _t1*_t225 - _t243*_t244 - _t247 - 0.3e1*_t248 - 0.3e1*_t249;
  const double _t251 = 0.3e1*_t75;
  const double _t252 = _t117*_t170;
  const double _t253 = 0.3e1*_t90;
  const double _t254 = 0.3e1*_t78;
  const double _t255 = _t51*_t6;
  const double _t256 = -_hc0[2]*_t255 - _hc1[2]*_t116 - 0.2e1*_t108 - 0.2e1*_t109 - 0.4e1*_t111 - 0.4e1*_t112 - 0.4e1*_t113;
  const double _t257 = _t114*_t22;
  const double _t258 = 0.2e1*_t257;
  const double _t259 = -_hc1[0]*_t246 - _t243*_t66 - 0.3e1*_t40 - 0.3e1*_t41;
  const double _t260 = _t153*_t218;
  const double _t261 = _hc1[3]*_t100 + _t11*_t226 + _t118*_t256 + _t17*_t225 + _t188*_t232 + _t191*_t227 + _t213*_t258 + _t215*_t251 + _t215*_t254 + _t227*_t233 + _t228*_t75 + _t228*_t78 + _t229*_t230 + _t231*_t34 + _t231*_t87 + _t232*_t239 + _t234*_t87 + _t236*_t75 + _t236*_t78 + _t238*_t42 + _t240*_t75 + _t240*_t78 + _t241*_t242 + _t25*_t250 + _t252*_t253 + _t259*_t260;
#endif
#if _KMAX >= 4
  const double _t262 = _t27*_t45;
  const double _t263 = params->gamma/(_t28 * _t28 * _t28 * _t28);
  const double _t264 = _t263*(-_t10*_t135 - _t141*_t17 - 0.3e1*_t26);
  const double _t265 = _t122*_t264;
  const double _t266 = 0.3e1*_t125;
  const double _t267 = 0.8e1*t;
  const double _t268 = _hc0[0]*_t267;
  const double _t269 = -_t121 - _t157*_t48 - _t268*_t53 - _t50*_t59 - 0.2e1*_t55 - 0.2e1*_t63;
  const double _t270 = _t123*_t269;
  const double _t271 = 0.2e1*_t127;
  const double _t272 = _t127*_t46;
  const double _t273 = 0.3e1*_t272;
  const double _t274 = 0.3e1*_t47;
  const double _t275 = -_t155;
  const double _t276 = 0.60e2*_t48;
  const double _t277 = 0.12e2*_hc0[0];
  const double _t278 = _t4*_t91;
  const double _t279 = _t13*_t132;
  const double _t280 = _t21*_t4;
  const double _t281 = 0.48e2*_t279*_t57;
  const double _t282 = _t145*_t21;
  const double _t283 = 0.16e2*_t14;
  const double _t284 = _t268*_t280;
  const double _t285 = _hc0[0]*t;
  const double _t286 = _t242*_t54;
  const double _t287 = _t154*_t60;
  const double _t288 = _t21*_t287;
  const double _t289 = -_t149 - 0.36e2*_t48;
  const double _t290 = _t153*_t289;
  const double _t291 = _t144*_t61;
  const double _t292 = 0.2e1*_t154;
  const double _t293 = _t151*_t62;
  const double _t294 = _hc1[0]/xc_powi(_t8, 5);
  const double _t295 = _t294*(-_t148*_t267 - _t283);
  const double _t296 = _t44*_t45;
  const double _t297 = _t124*_t44;
  const double _t298 = _t10*t;
  const double _t299 = _t131*_t132;
  const double _t300 = 0.12e2*_t67;
  const double _t301 = _t21*_t77;
  const double _t302 = _t168*_t24;
  const double _t303 = _t32*_t50;
  const double _t304 = _t141*_t32;
  const double _t305 = _hc0[1]*_t140;
  const double _t306 = _t170*_t60;
  const double _t307 = _t85*_t91;
  const double _t308 = _t206*_t60;
  const double _t309 = _t4*_t42;
  const double _t310 = _t277*t;
  const double _t311 = 0.3e1*_t171;
  const double _t312 = _t135*_t42;
  const double _t313 = _t141*_t309;
  const double _t314 = _hc1[1]*_t152;
  const double _t315 = _t144*_t90;
  const double _t316 = _t151*_t175;
  const double _t317 = _t93*_t94;
  const double _t318 = 0.2e1*_t124;
  const double _t319 = 0.2e1*_t179;
  const double _t320 = _t46*_t93;
  const double _t321 = 0.40e2*_t156;
  const double _t322 = _t110*_t2;
  const double _t323 = _t192*_t21;
  const double _t324 = _t77*_t85;
  const double _t325 = _t50*_t98;
  const double _t326 = 0.8e1*_hc1[1];
  const double _t327 = _t23*_t326;
  const double _t328 = _t285*_t327;
  const double _t329 = _t4*_t52;
  const double _t330 = _hc0[1]*_t267;
  const double _t331 = 0.4e1*_hc0[2]*t;
  const double _t332 = _t105*_t54;
  const double _t333 = _t268*_t32;
  const double _t334 = 0.2e1*_t302;
  const double _t335 = _t168*_t22;
  const double _t336 = _t204*_t24;
  const double _t337 = _hc1[2]*_t56;
  const double _t338 = _t21*_t308;
  const double _t339 = 0.4e1*_t75;
  const double _t340 = 0.4e1*_t31;
  const double _t341 = _t340*_t4;
  const double _t342 = _t306*_t42;
  const double _t343 = _t171*_t57;
  const double _t344 = 0.2e1*_t212;
  const double _t345 = _t42*_t57;
  const double _t346 = _t212*_t345;
  const double _t347 = _t20*_t213;
  const double _t348 = _t326*_t56;
  const double _t349 = _t42*_t75;
  const double _t350 = 0.2e1*_t145;
  const double _t351 = _t42*_t78;
  const double _t352 = _t212*_t57;
  const double _t353 = _t309*_t52;
  const double _t354 = _t213*_t85;
  const double _t355 = _t204*_t22;
  const double _t356 = 0.2e1*_t287;
  const double _t357 = _t154*_t90;
  const double _t358 = _t117*_t171;
  const double _t359 = _t117*_t42;
  const double _t360 = _t154*_t359;
  const double _t361 = _t117*_t154;
  const double _t362 = _t151*_t218;
  const double _t363 = _t177*_t220;
  const double _t364 = _t120*_t94;
  const double _t365 = _t123*_t220;
  const double _t366 = _t365*_t44;
  const double _t367 = _t185*_t4;
  const double _t368 = _t23*_t61;
  const double _t369 = _t120*_t46;
  const double _t370 = 0.12e2*_hc1[2];
  const double _t371 = _t370*_t9;
  const double _t372 = 0.12e2*_t34;
  const double _t373 = _hc0[0]*_hc0[2];
  const double _t374 = _t13*_t373;
  const double _t375 = _hc1[3]*_t9;
  const double _t376 = 0.12e2*_hc0[1];
  const double _t377 = _t32*_t376;
  const double _t378 = _t186*_t4;
  const double _t379 = _hc0[2]*_t140;
  const double _t380 = _hc0[3]*t;
  const double _t381 = _t226*_t3;
  const double _t382 = 0.6e1*_t324;
  const double _t383 = _t131*_t66;
  const double _t384 = 0.12e2*_t87;
  const double _t385 = _t140*_t30;
  const double _t386 = 0.6e1*_t342;
  const double _t387 = _t114*_t133;
  const double _t388 = _t24*_t250;
  const double _t389 = _t215*_t4;
  const double _t390 = _t114*_t242;
  const double _t391 = _t22*_t250;
  const double _t392 = _t256*_t345;
  const double _t393 = _t153*_t259;
  const double _t394 = _t393*_t90;
  const double _t395 = _t114*_t213;
  const double _t396 = _t359*_t393;
  const double _t397 = _t218*_t259;
  const double _t398 = 0.4e1*_t34;
  const double _t399 = _hc1[4]*params->gamma;
  const double _t400 = _hc0[4]*_t2;
  const double _t401 = 0.6e1*_t191;
  const double _t402 = _t31*_t98;
  const double _t403 = 0.6e1*_t97;
  const double _t404 = _t32*_t97;
  const double _t405 = 0.4e1*_t225;
  const double _t406 = _t4*_t405;
  const double _t407 = 0.12e2*_t235;
  const double _t408 = _t23*_t370;
  const double _t409 = 0.4e1*_t90;
  const double _t410 = 0.12e2*_t241;
  const double _t411 = 0.12e2*_t103;
  const double _t412 = 0.12e2*_t252;
  const double _t413 = 0.8e1*_t37;
  const double _t414 = _hc1[1]*_t7;
  const double _t415 = 0.8e1*_t395;
#endif

  const double f = params->gamma*xc_log1p(_t12);
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t27*_t29;
  out[1] = df_dt;
  const double df_drs = _t29*_t44;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t27*_t47 + _t29*_t64;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = _t29*_t93 + _t44*_t47;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = _t120*_t29 + _t94*_t95;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t125*_t27 + _t126*_t64 + _t127*_t128 + _t155*_t29;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = _t125*_t44 + _t126*_t93 + _t127*_t95 + _t176*_t29;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = _t120*_t47 + _t124*_t177 + _t178*_t93 + _t179*_t95 + _t219*_t29;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = _t120*_t222 + _t220*_t221 + _t223*_t95 + _t261*_t29;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _t124*_t27*_t271 + _t128*_t275 + _t155*_t274 + _t262*_t265 + _t262*_t270 + _t266*_t64 + _t273*_t64 + _t29*(-0.192e3*((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]))*_t24*_t6 + _t130 - 0.216e3*_t134*_t2 + _t136*_t276 + _t139*_t277 + _t142*_t276 + _t143*_t277 + _t145*_t284 + _t145*_t286 + _t146*_t283 + 0.96e2*_t161*_t5 - 0.72e2*_t278*_t279 + 0.16e2*_t278*_t285*_t54 - _t280*_t281 + _t282*_t59 + _t284*_t287 + _t286*_t287 + _t288*_t59 + _t290*_t62 + _t291*_t292 + _t293*_t295);
  out[10] = d4f_dt4;
  const double d4f_drs_dt3 = _t176*_t274 + _t265*_t296 + _t266*_t93 + _t270*_t296 + _t271*_t297 + _t273*_t93 + _t275*_t95 + _t29*(-0.72e2*_hc0[1]*_t133*_t14 + 0.6e1*_hc0[1]*_t53 + _t129*_t185 + _t129*_t196 + _t133*_t141*_t168 + _t135*_t164 + _t135*_t21*_t306 + _t135*_t302 + _t136*_t300 + _t136*_t304 + _t137*_t159 + _t137*_t173 + _t137*_t301 + _t138*_t163 + _t138*_t169 + _t138*_t174 + _t138*_t303 + _t139*_t305 + _t141*_t164*_t4 + _t141*_t280*_t306 + _t142*_t300 + _t142*_t304 + _t143*_t305 + _t145*_t311 + _t145*_t312 + _t145*_t313 + _t147*_t75 + _t147*_t78 + _t150*_t307 + 0.60e2*_t156*_t50 - _t162*_t299 + _t168*_t242*_t91 + _t170*_t291 + _t175*_t290 + _t22*_t308*_t54 - _t24*_t299*_t32 + _t278*_t310*_t85 - _t281*_t309 + _t282*_t75 + _t282*_t78 + _t287*_t311 + _t287*_t312 + _t287*_t313 + _t288*_t75 + _t288*_t78 + _t292*_t315 + _t293*_t314 + _t295*_t316 + 0.48e2*_t298*_t66);
  out[11] = d4f_drs_dt3;
  const double d4f_drs2_dt2 = _t120*_t125 + _t120*_t272 + _t126*_t219 + _t176*_t178 - _t176*_t95 + _t177*_t265 + _t221*_t269 + _t29*(_hc0[1]*_t280*_t327*t + 0.20e2*_hc0[2]*_t11 + _t105*_t335 + _t118*(-0.48e2*_t156 - _t208 - _t209) + _t133*_t204*_t52 + _t136*_t191 + _t136*_t194 + _t139*_t97 + _t142*_t191 + _t142*_t194 + _t142*_t233 + _t145*_t257 + _t152*_t316*_t39 + _t157*_t322 + _t159*_t211 + _t159*_t333 + _t160*_t34 + _t160*_t87 + _t166*_t34 + _t166*_t87 + _t169*_t330 + 0.4e1*_t171*_t306 + _t172*_t355 + _t173*_t211 + _t173*_t333 + _t174*_t330 + _t184 + _t186*_t49 + _t187 + _t189 + _t190 + _t197*_t51 + _t20*_t217 + _t20*_t323 + _t20*_t336 + _t20*_t346 + _t20*_t360 + _t202*_t50 + _t203*_t50 + _t206*_t315 + _t207*_t49 + _t21*_t32*_t328 + _t211*_t301 + _t213*_t335 + _t214 + _t215*_t49 + _t215*_t71 + _t217*_t329 + 0.20e2*_t235*_t48 + _t237*_t54 + _t25*(-_hc0[2]*_t167 - _t198 - _t199 - _t200 - 0.24e2*_t322) + _t257*_t287 + _t260*_t289 + _t285*_t309*_t348*_t60 + _t292*_t358 + _t295*_t362 + _t303*_t330 + _t307*_t339 + _t307*_t341 + _t321*_t34 + _t321*_t87 + _t323*_t329 + _t324*_t59 + _t325*_t52 + _t328*_t4*_t85 + _t329*_t354 + _t331*_t53 + _t332*_t75 + _t332*_t78 + _t334*_t75 + _t334*_t78 + _t337*_t62 + _t338*_t75 + _t338*_t78 + _t342*_t59 + _t343*_t344 + _t344*_t357 + _t347*_t85 + _t349*_t350 + _t349*_t356 + _t350*_t351 + _t351*_t356 + _t352*_t353 + _t353*_t361) + _t297*_t319 + _t317*_t318 + _t319*_t320;
  out[12] = d4f_drs2_dt2;
  const double d4f_drs3_dt = _t179*_t366 + _t219*_t222 - _t219*_t95 + _t221*(-_t10*_t84 - _t160*_t298 - _t165*_t17*t - _t20*_t34 - _t20*_t87 - _t239*_t52 - _t367*_t51 - _t368*_t39 - 0.2e1*_t76 - 0.2e1*_t79 - 0.2e1*_t86 - 0.2e1*_t92) + _t223*_t297 + _t223*_t320 + _t261*_t47 + _t264*_t363 + _t29*(0.6e1*_hc0[2]*_t367 + _hc0[3]*_t181 + _hc1[3]*_t182 + _hc1[3]*_t368 + _t114*_t141*_t162 + _t114*_t347 + _t118*(-_t1*_t331 - 0.16e2*_t183 - _t210*_t373 - _t30*_t330 - _t52*_t96) + _t135*_t241 + _t138*_t185*_t98 + _t141*_t87*_t98 + _t159*_t231 + _t159*_t234 + _t163*_t232 + _t169*_t232 + _t170*_t212*_t253 + _t173*_t231 + _t173*_t234 + _t174*_t232 + 0.3e1*_t175*_t337 + 0.12e2*_t180*_t244 + _t183*_t372 + _t183*_t384 + _t185*_t377 + _t186*_t304 + _t188*_t379 + _t192*_t312 + _t192*_t313 + _t196*_t377 + _t197*_t376*t + _t204*_t242*_t77 + _t207*_t300 + _t207*_t304 + _t212*_t394 + 0.2e1*_t213*_t355 + _t215*_t300 + _t215*_t304 + _t216*_t375 + _t216*_t388 + _t216*_t392 + _t216*_t396 + _t217*_t251 + _t217*_t254 + _t225*_t53 + _t226*_t69*t + _t229*_t305 + _t230*_t325 + _t231*_t301 + _t232*_t303 + _t234*_t301 + _t235*_t310*_t32 + _t235*_t383 + _t238*_t85 + _t239*_t379 + _t25*(-_hc0[2]*_t385 - _hc0[3]*_t201 - _t131*_t244 - _t16*_t224*t - _t305*_t96 - _t380*_t81) + _t251*_t323 + _t251*_t336 + _t251*_t346 + _t251*_t354 + _t251*_t360 + _t252*_t311 + _t252*_t312 + _t252*_t313 + _t254*_t323 + _t254*_t336 + _t254*_t346 + _t254*_t354 + _t254*_t360 + _t256*_t343 + _t256*_t357 + _t258*_t352 + _t258*_t361 + _t260*(-_hc0[0]*_t385 - _t1*_t305 - _t383) + _t295*_t397 + _t305*_t378 + _t305*_t387 + _t305*_t389 + _t306*_t390 + 0.3e1*_t314*_t362 + _t329*_t395 + _t358*_t393 + _t371*_t67 + _t372*_t374 + _t374*_t384 + _t380*_t73 + _t381*_t50 + _t382*_t75 + _t382*_t78 + _t386*_t75 + _t386*_t78 + _t388*_t88 + _t391*_t91 + _t392*_t88 + _t396*_t88) + _t317*_t365 + _t318*_t364 + _t319*_t369;
  out[13] = d4f_drs3_dt;
  const double d4f_drs4 = 0.3e1*_t178*_t261 + _t221*(-0.2e1*_t101 - _t103*_t65 - 0.2e1*_t115 - 0.2e1*_t119 - 0.4e1*_t22*_t235 - _t339*_t87 - _t34*_t341 - _t341*_t87 - _t398*_t75 - _t73*_t97 - 0.2e1*_t99) + 0.2e1*_t223*_t366 + 0.3e1*_t223*_t369 - _t261*_t95 + _t263*_t363*(-0.3e1*_t33 - 0.3e1*_t35 - 0.3e1*_t36 - 0.3e1*_t43) + _t29*(_hc1[3]*_t23*_t409 + _hc1[4]*_t100 + 0.24e2*_t103*_t235 + _t103*_t371 + _t11*(_t399 + _t400) + 0.6e1*_t114*_t237 + _t117*_t257*_t348 + _t117*_t259*_t314*_t409 + _t117*_t390*_t393 + _t118*(-0.12e2*_hc0[2]*_t37 - _hc0[3]*_t255 - _hc1[3]*_t116 - _t225*_t81 - 0.2e1*_t247 - 0.6e1*_t248 - 0.6e1*_t249 - _t370*_t414) + _t133*_t250*_t340 + _t17*_t400 + _t170*_t256*_t409 + _t186*_t401 + _t191*_t407 + _t207*_t401 + _t207*_t411 + _t213*_t242*_t250 + _t215*_t401 + _t215*_t411 + 0.6e1*_t218*_t337 + _t225*_t32*_t65 + _t226*_t31*_t65 + _t229*_t403 + _t233*_t407 + _t25*(-((_hc0[2]) * (_hc0[2]))*_t243 - _hc0[3]*_t413 - _hc0[4]*_t106 - ((_hc1[2]) * (_hc1[2]))*_t245 - 0.8e1*_hc1[3]*_t414 - _hc1[4]*_t107 - _t1*_t400 - _t224*_t340 - _t3*_t399 - _t30*_t405 - _t403*_t96) + _t256*_t390*_t57 + 0.2e1*_t256*_t394 + _t260*(-_hc1[0]*_hc1[2]*_t245 - 0.3e1*_t108 - 0.3e1*_t109 - 0.6e1*_t111 - 0.6e1*_t112 - 0.6e1*_t113 - _t243*_t373) + _t294*_t397*(-_hc0[0]*_t413 - _t326*_t38 - 0.4e1*_t40 - 0.4e1*_t41) + _t339*_t375 + _t339*_t388 + _t339*_t392 + _t339*_t396 + _t34*_t406 + _t341*_t375 + _t341*_t392 + _t341*_t396 + _t349*_t408 + _t349*_t412 + _t351*_t408 + _t351*_t412 + _t372*_t402 + _t372*_t404 + _t378*_t403 + _t381*_t398 + 0.4e1*_t381*_t87 + _t384*_t402 + _t384*_t404 + _t387*_t403 + _t389*_t403 + 0.4e1*_t391*_t77 + _t406*_t87 + _t410*_t75 + _t410*_t78 + _t415*_t75 + _t415*_t78) + 0.3e1*_t364*_t365;
  out[14] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_c_pbe_erf_gws_params *params = (const gga_c_pbe_erf_gws_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = M_CBRTPI;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t1*_t3;
  const double _t5 = (0.1e1 / 0.2e1)*_t4;
  const double _t6 = _t5/xc_powr(na, 1, 3);
  const double _t7 = xc_powr(na, -7, 6);
  const double _t8 = xc_powr(gaa, 1, 2);
  const double _t9 = xc_powr(0.3e1, 5, 6);
  const double _t10 = xc_powr(M_PI, 1, 6);
  const double _t11 = _t10*_t9;
  const double _t12 = _t11*_t8;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_f_z0_k, _KMAX)(p, _t6, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pbe_c_erf_gws_H_z0_k, _KMAX)(p, _t6, (0.1e1 / 0.12e2)*_t12*_t7, _hc1);
  const double _t13 = _hc0[0] + _hc1[0];
  const double zk = _t13;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t15 = xc_powr(na, -4, 3);
  const double _t16 = (0.1e1 / 0.6e1)*_t15;
  const double _t17 = _t16*_t4;
  const double _t19 = xc_powr(na, -13, 6);
  const double _t20 = (0.7e1 / 0.72e2)*_t19;
  const double _t21 = xc_powr(na, -1, 6);
  const double _t22 = (0.1e1 / _t8);
  const double _t23 = _t11*_t22;
  const double _t14 = _hc0[1]*_t4;
  const double _t18 = _hc1[1]*_t12;
  const double _t24 = _hc1[1]*_t23;
  const double _t25 = (0.1e1 / 0.24e2)*_t24;
  const double dF_dna = _t13 + na*(-_hc1[2]*_t17 - _t14*_t16 - _t18*_t20);
  const double dF_dgaa = _t21*_t25;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t26 = (0.1e1 / 0.3e1)*_t15;
  const double _t28 = xc_powr(na, -7, 3);
  const double _t29 = (0.2e1 / 0.9e1)*_t28;
  const double _t30 = (M_CBRTPI * M_CBRTPI);
  const double _t33 = xc_powr(na, -19, 6);
  const double _t34 = (0.91e2 / 0.432e3)*_t33;
  const double _t35 = _t12*_t20;
  const double _t38 = xc_powr(0.3e1, 2, 3);
  const double _t39 = _t2*_t38;
  const double _t41 = xc_powr(na, -10, 3);
  const double _t42 = (0.7e1 / 0.576e3)*_t41;
  const double _t44 = (0.7e1 / 0.144e3)*_t19;
  const double _t45 = xc_powr(na, -5, 2);
  const double _t46 = (0.1e1 / 0.48e2)*_t45;
  const double _t47 = M_CBRT2;
  const double _t48 = xc_powr(0.3e1, 1, 6);
  const double _t49 = (0.1e1 / _t10);
  const double _t50 = _t22*_t48*_t49;
  const double _t51 = _t47*_t50;
  const double _t53 = (0.1e1 / gaa);
  const double _t54 = xc_powr(gaa, -3, 2);
  const double _t55 = _t11*_t54;
  const double _t27 = _hc1[2]*_t4;
  const double _t31 = xc_powr(0.6e1, 2, 3)*_hc0[2]/_t30;
  const double _t32 = _t31/xc_powr(na, 8, 3);
  const double _t36 = -_hc1[4]*_t35 - _hc1[5]*_t17;
  const double _t37 = -_hc1[3]*_t35 - _hc1[4]*_t17;
  const double _t40 = _hc1[3]*_t39;
  const double _t43 = _t40*_t42;
  const double _t52 = _hc1[4]*_t51;
  const double _t56 = _hc1[1]*_t55;
  const double _t57 = (0.1e1 / 0.48e2)*_t56;
  const double d2F_dna2 = -_t14*_t26 - 0.7e1 / 0.36e2*_t18*_t19 - _t26*_t27 + na*(_t14*_t29 - _t17*_t36 + _t18*_t34 + _t27*_t29 + (0.1e1 / 0.36e2)*_t32 - _t35*_t37);
  const double d2F_dna_dgaa = _t25*_t7 + na*(-_t24*_t44 - _t43 - _t46*_t52);
  const double d2F_dgaa2 = (0.1e1 / 0.192e3)*_hc1[3]*_t15*_t2*_t38*_t53 - _t21*_t57;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t58 = (0.2e1 / 0.3e1)*_t28;
  const double _t59 = (0.91e2 / 0.144e3)*_t33;
  const double _t60 = _t15*_t5;
  const double _t62 = (0.7e1 / 0.24e2)*_t19;
  const double _t65 = (0.14e2 / 0.27e2)*_t41;
  const double _t66 = xc_powr(na, -11, 3);
  const double _t68 = xc_powr(na, -25, 6);
  const double _t69 = (0.1729e4 / 0.2592e4)*_t68;
  const double _t70 = _t29*_t4;
  const double _t71 = _t12*_t34;
  const double _t78 = xc_powr(na, -13, 3);
  const double _t79 = (0.91e2 / 0.3456e4)*_t78;
  const double _t80 = (0.91e2 / 0.864e3)*_t33;
  const double _t81 = xc_powr(na, -7, 2);
  const double _t82 = (0.1e1 / 0.36e2)*_t81;
  const double _t83 = _t23*_t44;
  const double _t84 = _t39*_t42;
  const double _t85 = _t46*_t51;
  const double _t88 = _t46*_t50;
  const double _t93 = (0.1e1 / 0.384e3)*_t66;
  const double _t94 = xc_powr(0.3e1, 1, 2);
  const double _t95 = xc_powr(M_PI, 1, 2);
  const double _t97 = _t22/xc_powr(na, 9, 2);
  const double _t98 = (0.7e1 / 0.4608e4)*_t97;
  const double _t99 = (0.7e1 / 0.1152e4)*_t53;
  const double _t101 = (0.1e1 / 0.1536e4)*_t54;
  const double _t102 = (0.1e1 / (gaa * gaa));
  const double _t103 = (0.1e1 / 0.128e3)*_t102;
  const double _t104 = xc_powr(gaa, -5, 2);
  const double _t61 = _t12*_t37;
  const double _t63 = _hc0[3]/M_PI;
  const double _t64 = _t63/(na * na * na * na);
  const double _t67 = _t31*_t66;
  const double _t72 = -_hc1[8]*_t35 - _hc1[9]*_t17;
  const double _t73 = -_hc1[7]*_t35 - _hc1[8]*_t17;
  const double _t74 = _hc1[4]*_t71 + _hc1[5]*_t70 - _t17*_t72 - _t35*_t73;
  const double _t75 = -_hc1[6]*_t35 - _hc1[7]*_t17;
  const double _t76 = _hc1[3]*_t71 + _hc1[4]*_t70 - _t17*_t73 - _t35*_t75;
  const double _t77 = _t40*_t41;
  const double _t86 = -_hc1[4]*_t83 - _hc1[7]*_t84 - _hc1[8]*_t85;
  const double _t87 = _hc1[7]*_t47;
  const double _t89 = -_hc1[3]*_t83 - _hc1[6]*_t84 - _t87*_t88;
  const double _t90 = _t28*_t40;
  const double _t91 = _hc1[7]*_t53;
  const double _t92 = _t47*_t91;
  const double _t96 = _hc1[6]*_t94*_t95;
  const double _t100 = _t45*_t96;
  const double _t105 = _hc1[1]*_t104*_t11;
  const double _t106 = (0.1e1 / 0.32e2)*_t105;
  const double d3F_dna3 = _t14*_t58 + _t18*_t59 + _t27*_t58 + (0.1e1 / 0.12e2)*_t32 - _t36*_t60 - _t61*_t62 + na*((0.4e1 / 0.9e1)*_t1*_t28*_t3*_t36 + (0.91e2 / 0.216e3)*_t10*_t33*_t37*_t8*_t9 - _t14*_t65 - _t17*_t74 - _t18*_t69 - _t27*_t65 - _t35*_t76 - 0.1e1 / 0.36e2*_t64 - 0.1e1 / 0.9e1*_t67);
  const double d3F_dna2_dgaa = -_t20*_t24 - 0.1e1 / 0.24e2*_t45*_t52 - 0.7e1 / 0.288e3*_t77 + na*(-_t17*_t86 + _t24*_t80 - _t35*_t89 - _t37*_t83 + _t40*_t79 + _t52*_t82);
  const double d3F_dna_dgaa2 = (0.1e1 / 0.192e3)*_t53*_t90 - _t57*_t7 + na*((0.7e1 / 0.288e3)*_hc1[1]*_t10*_t19*_t54*_t9 + (0.1e1 / 0.96e2)*_hc1[4]*_t45*_t47*_t48*_t49*_t54 - _t77*_t99 - _t92*_t93 - _t96*_t98);
  const double d3F_dgaa3 = _t100*_t101 - _t103*_t15*_t40 + _t106*_t21;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t107 = (0.56e2 / 0.27e2)*_t41;
  const double _t110 = xc_powr(na, -16, 3);
  const double _t111 = (0.140e3 / 0.81e2)*_t78;
  const double _t112 = xc_powr(na, -14, 3);
  const double _t113 = _t4*_t65;
  const double _t114 = _t12*_t69;
  const double _t119 = _t39*_t79;
  const double _t120 = _t23*_t80;
  const double _t125 = _t53*_t93;
  const double _t126 = _t94*_t95*_t98;
  const double _t127 = _t39*_t41;
  const double _t128 = M_CBRT3;
  const double _t108 = _t4*_t74;
  const double _t109 = _t12*_t76;
  const double _t115 = -_hc1[12]*_t35 - _hc1[13]*_t17;
  const double _t116 = -_hc1[11]*_t35 - _hc1[12]*_t17;
  const double _t117 = _hc1[7]*_t71 + _hc1[8]*_t70 - _t115*_t17 - _t116*_t35;
  const double _t118 = _hc1[4]*_t47*_t48*_t49;
  const double _t121 = _hc1[12]*_t47;
  const double _t122 = -_hc1[11]*_t84 - _hc1[7]*_t83 - _t121*_t88;
  const double _t123 = _hc1[11]*_t47;
  const double _t124 = _t118*_t54;
  const double d4F_dna4 = (0.16e2 / 0.9e1)*_t1*_t28*_t3*_t36 + (0.91e2 / 0.54e2)*_t10*_t33*_t37*_t8*_t9 - _t107*_t14 - _t107*_t27 - 0.2e1 / 0.3e1*_t108*_t15 - 0.7e1 / 0.18e2*_t109*_t19 - 0.1729e4 / 0.648e3*_t18*_t68 - 0.1e1 / 0.9e1*_t64 - 0.4e1 / 0.9e1*_t67 + na*((0.1e1 / 0.216e3)*_hc0[4]*_t1*_t110/(M_PI * M_CBRTPI) + _t108*_t58 + _t109*_t59 + _t111*_t14 + _t111*_t27 + (0.40e2 / 0.81e2)*_t112*_t31 - _t17*(-_hc1[4]*_t114 - _hc1[5]*_t113 + (0.4e1 / 0.9e1)*_t1*_t28*_t3*_t72 + (0.91e2 / 0.216e3)*_t10*_t33*_t73*_t8*_t9 - _t117*_t35 - _t17*(_hc1[8]*_t71 + _hc1[9]*_t70 - _t115*_t35 - _t17*(-_hc1[13]*_t35 - _hc1[14]*_t17))) + (0.43225e5 / 0.15552e5)*_t18/xc_powr(na, 31, 6) - _t35*(-_hc1[3]*_t114 - _hc1[4]*_t113 + (0.4e1 / 0.9e1)*_t1*_t28*_t3*_t73 + (0.91e2 / 0.216e3)*_t10*_t33*_t75*_t8*_t9 - _t117*_t17 - _t35*(_hc1[6]*_t71 + _hc1[7]*_t70 - _t116*_t17 - _t35*(-_hc1[10]*_t35 - _hc1[11]*_t17))) - 0.14e2 / 0.9e1*_t36*_t4*_t41 - 0.1729e4 / 0.864e3*_t61*_t68 + (0.2e1 / 0.9e1)*_t63/xc_powi(na, 5));
  const double d4F_dna3_dgaa = -_t12*_t62*_t89 - 0.7e1 / 0.48e2*_t19*_t23*_t37 + (0.91e2 / 0.288e3)*_t24*_t33 + (0.91e2 / 0.1152e4)*_t40*_t78 + (0.1e1 / 0.12e2)*_t52*_t81 - _t60*_t86 + na*((0.4e1 / 0.9e1)*_t1*_t28*_t3*_t86 + (0.91e2 / 0.432e3)*_t10*_t22*_t33*_t37*_t9 + (0.91e2 / 0.216e3)*_t10*_t33*_t8*_t89*_t9 - 0.1729e4 / 0.20736e5*_t110*_t40 - 0.7e1 / 0.108e3*_t118*_t97 - _t17*(_hc1[4]*_t120 + _hc1[7]*_t119 + _hc1[8]*_t51*_t82 - _t122*_t35 - _t17*(-_hc1[12]*_t84 - _hc1[13]*_t85 - _hc1[8]*_t83) - _t73*_t83) - 0.1729e4 / 0.5184e4*_t24*_t68 - _t35*(_hc1[3]*_t120 + _hc1[6]*_t119 - _t122*_t17 - _t35*(-_hc1[10]*_t84 - _hc1[6]*_t83 - _t123*_t88) + _t50*_t82*_t87 - _t75*_t83) - _t76*_t83);
  const double d4F_dna2_dgaa2 = _t124*_t46 - _t43*_t53 + _t44*_t56 - 0.1e1 / 0.192e3*_t66*_t92 - 0.7e1 / 0.2304e4*_t96*_t97 + na*((0.91e2 / 0.6912e4)*_hc1[3]*_t2*_t38*_t53*_t78 + (0.91e2 / 0.27648e5)*_hc1[6]*_t22*_t94*_t95/xc_powr(na, 11, 2) + (0.1e1 / 0.288e3)*_hc1[7]*_t112*_t47*_t53 + (0.7e1 / 0.288e3)*_t10*_t19*_t37*_t54*_t9 - 0.1e1 / 0.72e2*_t124*_t81 - _t17*(-_hc1[11]*_t126 + (0.7e1 / 0.288e3)*_hc1[4]*_t10*_t19*_t54*_t9 + (0.1e1 / 0.96e2)*_hc1[8]*_t45*_t47*_t48*_t49*_t54 - _t121*_t125 - 0.7e1 / 0.1152e4*_t127*_t91) - _t20*_t23*_t89 - 0.91e2 / 0.1728e4*_t33*_t56 - _t35*(-_hc1[10]*_t126 + (0.7e1 / 0.288e3)*_hc1[3]*_t10*_t19*_t54*_t9 - _hc1[6]*_t127*_t99 + (0.1e1 / 0.96e2)*_hc1[7]*_t45*_t47*_t48*_t49*_t54 - _t123*_t125));
  const double d4F_dna_dgaa3 = _t101*_t81*_t96 - _t103*_t90 + _t106*_t7 + na*(-0.7e1 / 0.36864e5*_hc1[10]*_t128*_t30*_t53/xc_powr(na, 17, 3) + (0.7e1 / 0.768e3)*_hc1[3]*_t102*_t2*_t38*_t41 + (0.1e1 / 0.256e3)*_hc1[7]*_t102*_t47*_t66 - 0.1e1 / 0.64e2*_t104*_t118*_t45 - 0.7e1 / 0.192e3*_t105*_t19 - 0.1e1 / 0.9216e4*_t123*_t55/xc_powr(na, 29, 6));
  const double d4F_dgaa4 = -0.5e1 / 0.64e2*_hc1[1]*_t11*_t21/xc_powr(gaa, 7, 2) + (0.1e1 / 0.12288e5)*_hc1[10]*_t102*_t128*_t30*_t66 + (0.5e1 / 0.256e3)*_hc1[3]*_t15*_t2*_t38/(gaa * gaa * gaa) - 0.1e1 / 0.512e3*_t100*_t104;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gab = sigma[1];
  const double gbb = sigma[2];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = M_CBRTPI;
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = _t2*_t4;
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
  const double _t7 = _t6/xc_powr(_t1, 1, 3);
  const double _t8 = na - nb;
  const double _t9 = (0.1e1 / _t1);
  const double _t10 = _t8*_t9;
  const double _t14 = xc_powr(_t1, -7, 6);
  const double _t15 = gaa + 0.2e1*gab + gbb;
  const double _t16 = xc_powr(_t15, 1, 2);
  const double _t17 = xc_powr(0.3e1, 5, 6);
  const double _t18 = xc_powr(M_PI, 1, 6);
  const double _t19 = _t17*_t18;
  const double _t20 = _t16*_t19;
  const double _t21 = _t14*_t20;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_f_k, _KMAX)(p, _t7, _t10, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t10, 0.2e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -_t10, 0.2e1 / 0.3e1, _hc2);
  const double _t11 = (0.1e1 / 0.2e1)*_hc1[0] + (0.1e1 / 0.2e1)*_hc2[0] + 0.1e1;
  const double _t12 = (0.1e1 / _t11);
  const double _t13 = (0.1e1 / 0.12e2)*_t12;
  double _hc3[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(pbe_c_erf_gws_H_k, _KMAX)(p, _t7, _t10, _t13*_t21, _hc3);
  const double _t22 = _hc0[0] + _hc3[0];
  const double zk = _t22;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t24 = xc_powr(_t1, -4, 3);
  const double _t25 = (0.1e1 / 0.6e1)*_t24;
  const double _t26 = _t25*_t5;
  const double _t28 = -_t9;
  const double _t29 = (0.1e1 / (_t1 * _t1));
  const double _t30 = _t29*_t8;
  const double _t31 = _t28 + _t30;
  const double _t32 = -_t31;
  const double _t35 = xc_powr(_t1, -13, 6);
  const double _t36 = (0.7e1 / 0.72e2)*_t35;
  const double _t43 = (0.1e1 / 0.12e2)*_t21;
  const double _t48 = _t30 + _t9;
  const double _t49 = -_t48;
  const double _t60 = (0.1e1 / _t16);
  const double _t65 = _t19*_t60;
  const double _t23 = _hc0[2]*_t5;
  const double _t33 = _hc0[1]*_t32;
  const double _t34 = _t12*_t20;
  const double _t37 = -_t34*_t36;
  const double _t38 = (0.1e1 / (_t11 * _t11));
  const double _t39 = _hc1[2]*_t32;
  const double _t40 = _hc2[2]*_t31;
  const double _t41 = -0.1e1 / 0.2e1*_t39 - 0.1e1 / 0.2e1*_t40;
  const double _t42 = _t38*_t41;
  const double _t44 = _t37 + _t42*_t43;
  const double _t50 = _hc0[1]*_t49;
  const double _t51 = _hc2[2]*_t48;
  const double _t52 = _hc1[2]*_t49;
  const double _t53 = -0.1e1 / 0.2e1*_t51 - 0.1e1 / 0.2e1*_t52;
  const double _t54 = _t38*_t43;
  const double _t55 = _t37 + _t53*_t54;
  const double _t61 = _t12*_t19;
  const double _t62 = _t60*_t61;
  const double _t63 = (0.1e1 / 0.24e2)*_t62;
  const double _t66 = _t13*_t65;
  const double _t27 = -_hc3[3]*_t26 - _t23*_t25;
  const double _t45 = _hc3[1]*_t44;
  const double _t46 = _hc3[2]*_t32;
  const double _t47 = _t33 + _t45 + _t46;
  const double _t56 = _hc3[1]*_t55;
  const double _t57 = _hc3[2]*_t49;
  const double _t58 = _t50 + _t56 + _t57;
  const double _t59 = _hc3[1]/xc_powr(_t1, 1, 6);
  const double _t64 = _t59*_t63;
  const double dF_dna = _t1*(_t27 + _t47) + _t22;
  const double dF_dnb = _t1*(_t27 + _t58) + _t22;
  const double dF_dgaa = _t64;
  const double dF_dgab = _t59*_t66;
  const double dF_dgbb = _t64;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t67 = xc_powr(_t1, -7, 3);
  const double _t68 = (0.2e1 / 0.9e1)*_t67;
  const double _t71 = 0.2e1*_t29;
  const double _t72 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t73 = 0.2e1*_t72;
  const double _t74 = _t73*_t8;
  const double _t75 = -_t71 + _t74;
  const double _t77 = xc_powr(_t1, -19, 6);
  const double _t78 = (0.91e2 / 0.432e3)*_t77;
  const double _t81 = (0.7e1 / 0.36e2)*_t35;
  const double _t87 = (_t32 * _t32);
  const double _t89 = -_t75;
  const double _t91 = (_t31 * _t31);
  const double _t113 = (0.1e1 / 0.3e1)*_t24;
  const double _t116 = _t20*_t36;
  const double _t138 = _t71 + _t74;
  const double _t140 = _t20*_t81;
  const double _t141 = (_t48 * _t48);
  const double _t144 = -_t138;
  const double _t146 = (_t49 * _t49);
  const double _t158 = M_CBRT2;
  const double _t160 = xc_powr(_t1, -5, 2);
  const double _t161 = xc_powr(0.3e1, 1, 6);
  const double _t162 = (0.1e1 / _t18);
  const double _t168 = (0.7e1 / 0.144e3)*_t35;
  const double _t170 = _t14*_t65;
  const double _t197 = xc_powr(0.3e1, 2, 3);
  const double _t198 = (0.1e1 / _t15);
  const double _t199 = xc_powr(_t15, -3, 2);
  const double _t204 = _t19*_t199;
  const double _t76 = _hc0[1]*_t75;
  const double _t79 = _t34*_t78;
  const double _t80 = _t20*_t42;
  const double _t82 = (0.1e1 / (_t11 * _t11 * _t11));
  const double _t83 = _t43*_t82;
  const double _t84 = -_t39 - _t40;
  const double _t85 = _t41*_t84;
  const double _t86 = _hc1[2]*_t75;
  const double _t88 = _hc1[5]*_t87;
  const double _t90 = _hc2[2]*_t89;
  const double _t92 = _hc2[5]*_t91;
  const double _t93 = -0.1e1 / 0.2e1*_t86 - 0.1e1 / 0.2e1*_t88 - 0.1e1 / 0.2e1*_t90 - 0.1e1 / 0.2e1*_t92;
  const double _t94 = _t54*_t93 + _t79 - _t80*_t81 + _t83*_t85;
  const double _t97 = -_hc0[4]*_t26;
  const double _t98 = _hc0[3]*_t32 + _t97;
  const double _t99 = _t32*_t98;
  const double _t108 = -_hc0[5]*_t26;
  const double _t109 = _hc0[4]*_t32 + _t108;
  const double _t115 = _t38*_t53;
  const double _t117 = -_t51 - _t52;
  const double _t118 = _t117*_t83;
  const double _t119 = _hc1[2]*_t72*_t8;
  const double _t120 = _hc2[5]*_t31;
  const double _t121 = _t120*_t48;
  const double _t122 = _hc1[5]*_t32;
  const double _t123 = _t122*_t49;
  const double _t124 = _hc2[2]*_t72*_t8 - _t119 - 0.1e1 / 0.2e1*_t121 - 0.1e1 / 0.2e1*_t123;
  const double _t125 = -_t115*_t116 + _t118*_t41 + _t124*_t54 - _t36*_t80 + _t79;
  const double _t127 = _hc0[3]*_t49 + _t97;
  const double _t128 = _t127*_t32;
  const double _t135 = _hc0[4]*_t49 + _t108;
  const double _t139 = _hc0[1]*_t138;
  const double _t142 = _hc2[5]*_t141;
  const double _t143 = _hc1[2]*_t138;
  const double _t145 = _hc2[2]*_t144;
  const double _t147 = _hc1[5]*_t146;
  const double _t148 = -0.1e1 / 0.2e1*_t142 - 0.1e1 / 0.2e1*_t143 - 0.1e1 / 0.2e1*_t145 - 0.1e1 / 0.2e1*_t147;
  const double _t149 = -_t115*_t140 + _t118*_t53 + _t148*_t54 + _t79;
  const double _t152 = _t127*_t49;
  const double _t163 = _t12*_t161*_t162;
  const double _t164 = _t163*_t60;
  const double _t165 = _t160*_t164;
  const double _t166 = (0.1e1 / 0.48e2)*_t165;
  const double _t169 = -_t168*_t62;
  const double _t171 = _t170*_t42;
  const double _t172 = _t169 + (0.1e1 / 0.24e2)*_t171;
  const double _t174 = _t14*_t63;
  const double _t178 = -_t36*_t62;
  const double _t179 = (0.1e1 / 0.12e2)*_t171 + _t178;
  const double _t181 = (0.1e1 / 0.24e2)*_t165;
  const double _t183 = _t14*_t66;
  const double _t187 = _t115*_t170;
  const double _t188 = _t169 + (0.1e1 / 0.24e2)*_t187;
  const double _t192 = _t178 + (0.1e1 / 0.12e2)*_t187;
  const double _t200 = _t199*_t61;
  const double _t205 = _t13*_t204;
  const double _t69 = _hc3[3]*_t5;
  const double _t70 = _t23*_t68 + _t68*_t69;
  const double _t95 = _hc3[1]*_t94;
  const double _t96 = _hc3[2]*_t75;
  const double _t100 = -_hc3[8]*_t26;
  const double _t101 = _hc3[5]*_t44 + _hc3[6]*_t32 + _t100;
  const double _t102 = _t101*_t32;
  const double _t103 = -_hc3[7]*_t26;
  const double _t104 = _hc3[5]*_t32;
  const double _t105 = _hc3[4]*_t44;
  const double _t106 = _t103 + _t104 + _t105;
  const double _t107 = _t106*_t44;
  const double _t110 = -_hc3[9]*_t26;
  const double _t111 = _hc3[7]*_t44 + _hc3[8]*_t32 + _t110;
  const double _t112 = _t102 + _t107 - _t109*_t26 - _t111*_t26 + _t76 + _t95 + _t96 + _t99;
  const double _t114 = -_t113*_t23 - _t113*_t69;
  const double _t126 = _hc3[1]*_t125;
  const double _t129 = _hc3[5]*_t55 + _hc3[6]*_t49 + _t100;
  const double _t130 = _t129*_t32;
  const double _t131 = _hc3[5]*_t49;
  const double _t132 = _hc3[4]*_t55;
  const double _t133 = _t103 + _t131 + _t132;
  const double _t134 = _t133*_t44;
  const double _t136 = _hc3[7]*_t55 + _hc3[8]*_t49 + _t110;
  const double _t137 = -_t135*_t26 - _t136*_t26 + _t70;
  const double _t150 = _hc3[1]*_t149;
  const double _t151 = _hc3[2]*_t138;
  const double _t153 = _t129*_t49;
  const double _t154 = _t133*_t55;
  const double _t155 = _t139 + _t150 + _t151 + _t152 + _t153 + _t154;
  const double _t156 = _hc3[1]*_t14;
  const double _t157 = _t156*_t63;
  const double _t159 = _hc3[7]*_t158;
  const double _t167 = -_t159*_t166;
  const double _t173 = _hc3[1]*_t172;
  const double _t175 = _t104*_t174 + _t105*_t174 + _t173;
  const double _t176 = _t1*(_t167 + _t175) + _t157;
  const double _t177 = _t156*_t66;
  const double _t180 = _hc3[1]*_t179;
  const double _t182 = -_t159*_t181;
  const double _t184 = _t105*_t183;
  const double _t185 = _t104*_t183;
  const double _t186 = _t182 + _t184 + _t185;
  const double _t189 = _hc3[1]*_t188;
  const double _t190 = _t131*_t174 + _t132*_t174 + _t189;
  const double _t191 = _t1*(_t167 + _t190) + _t157;
  const double _t193 = _hc3[1]*_t192;
  const double _t194 = _t132*_t183;
  const double _t195 = _t131*_t183;
  const double _t196 = _t182 + _t194 + _t195;
  const double _t201 = _t200*_t59;
  const double _t202 = (0.1e1 / 0.192e3)*_hc3[4]*_t197*_t198*_t24*_t3*_t38 - 0.1e1 / 0.48e2*_t201;
  const double _t203 = (0.1e1 / 0.96e2)*_hc3[4]*_t197*_t198*_t24*_t3*_t38 - 0.1e1 / 0.24e2*_t201;
  const double d2F_dna2 = _t1*(_t112 + _t70) + _t114 + 0.2e1*_t33 + 0.2e1*_t45 + 0.2e1*_t46;
  const double d2F_dna_dnb = _t1*(_hc0[1]*_t74 + _hc3[2]*_t74 + _t126 + _t128 + _t130 + _t134 + _t137) + _t114 + _t47 + _t58;
  const double d2F_dnb2 = _t1*(_t137 + _t155) + _t114 + 0.2e1*_t50 + 0.2e1*_t56 + 0.2e1*_t57;
  const double d2F_dna_dgaa = _t176;
  const double d2F_dna_dgab = _t1*(_t180 + _t186) + _t177;
  const double d2F_dna_dgbb = _t176;
  const double d2F_dnb_dgaa = _t191;
  const double d2F_dnb_dgab = _t1*(_t193 + _t196) + _t177;
  const double d2F_dnb_dgbb = _t191;
  const double d2F_dgaa2 = _t202;
  const double d2F_dgaa_dgab = _t203;
  const double d2F_dgaa_dgbb = _t202;
  const double d2F_dgab2 = (0.1e1 / 0.48e2)*_hc3[4]*_t197*_t198*_t24*_t3*_t38 - _t205*_t59;
  const double d2F_dgab_dgbb = _t203;
  const double d2F_dgbb2 = _t202;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 1] += d2F_dna_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 2] += d2F_dna_dgbb;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 3] += d2F_dnb_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 4] += d2F_dnb_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 1] += d2F_dgaa_dgab;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 2] += d2F_dgaa_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 3] += d2F_dgab2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 4] += d2F_dgab_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
#endif
#if _KMAX >= 3
  const double _t206 = xc_powr(_t1, -10, 3);
  const double _t207 = (0.14e2 / 0.27e2)*_t206;
  const double _t210 = (0.4e1 / 0.9e1)*_t67;
  const double _t211 = _t210*_t5;
  const double _t213 = 0.6e1*_t72;
  const double _t214 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t215 = 0.6e1*_t214;
  const double _t216 = _t215*_t8;
  const double _t217 = -_t213 + _t216;
  const double _t218 = -_t217;
  const double _t220 = xc_powr(_t1, -25, 6);
  const double _t221 = (0.1729e4 / 0.2592e4)*_t220;
  const double _t224 = _t20*_t35;
  const double _t225 = (0.7e1 / 0.24e2)*_t224;
  const double _t232 = (0.1e1 / 0.6e1)*_t21;
  const double _t238 = (_t32 * _t32 * _t32);
  const double _t241 = (_t31 * _t31 * _t31);
  const double _t244 = 0.4e1*_t29;
  const double _t245 = 0.4e1*_t72;
  const double _t246 = _t245*_t8;
  const double _t247 = -_t244 + _t246;
  const double _t249 = -_t247;
  const double _t256 = _t5*_t68;
  const double _t288 = 0.2e1*_t75;
  const double _t299 = _t24*_t6;
  const double _t300 = (0.2e1 / 0.3e1)*_t67;
  const double _t302 = _t216 - 0.2e1*_t72;
  const double _t303 = -_t302;
  const double _t311 = -_t29*_t8;
  const double _t312 = _t28 + _t311;
  const double _t362 = _t113*_t5;
  const double _t365 = _t214*_t8;
  const double _t370 = _t311 + _t9;
  const double _t396 = _t213 + _t216;
  const double _t397 = -_t396;
  const double _t401 = (_t48 * _t48 * _t48);
  const double _t405 = (_t49 * _t49 * _t49);
  const double _t407 = _t244 + _t246;
  const double _t408 = -_t407;
  const double _t416 = 0.2e1*_t138;
  const double _t418 = xc_powr(_t1, -7, 2);
  const double _t422 = (0.91e2 / 0.864e3)*_t77;
  const double _t513 = xc_powr(_t1, -11, 3);
  const double _t517 = _t160*_t199;
  const double _t522 = _t14*_t204;
  const double _t529 = _t197*_t3;
  const double _t594 = (0.1e1 / (_t15 * _t15));
  const double _t598 = xc_powr(_t15, -5, 2);
  const double _t209 = _t109*_t5;
  const double _t219 = _hc0[1]*_t218;
  const double _t222 = -_t221*_t34;
  const double _t223 = _t77*_t80;
  const double _t226 = _t82*_t85;
  const double _t227 = _t38*_t93;
  const double _t228 = -0.3e1 / 0.2e1*_t39 - 0.3e1 / 0.2e1*_t40;
  const double _t229 = (0.1e1 / (_t11 * _t11 * _t11 * _t11));
  const double _t230 = _t229*_t43;
  const double _t231 = _t230*_t85;
  const double _t233 = _t82*_t84;
  const double _t234 = _t233*_t93;
  const double _t235 = -_t86 - _t88 - _t90 - _t92;
  const double _t236 = _t41*_t83;
  const double _t237 = _hc1[2]*_t218;
  const double _t239 = _hc1[9]*_t238;
  const double _t240 = _hc2[2]*_t217;
  const double _t242 = _hc2[9]*_t241;
  const double _t243 = _t122*_t75;
  const double _t248 = _t122*_t247;
  const double _t250 = _t120*_t249;
  const double _t251 = _t120*_t89;
  const double _t252 = -0.1e1 / 0.2e1*_t237 - 0.1e1 / 0.2e1*_t239 - 0.1e1 / 0.2e1*_t240 - 0.1e1 / 0.2e1*_t242 - 0.1e1 / 0.2e1*_t243 - 0.1e1 / 0.2e1*_t248 - 0.1e1 / 0.2e1*_t250 - 0.1e1 / 0.2e1*_t251;
  const double _t253 = _t222 + (0.91e2 / 0.144e3)*_t223 - _t225*_t226 - _t225*_t227 + _t228*_t231 + _t232*_t234 + _t235*_t236 + _t252*_t54;
  const double _t257 = _hc0[4]*_t256;
  const double _t258 = -_hc0[8]*_t26;
  const double _t259 = _hc0[7]*_t32 + _t258;
  const double _t260 = -_hc0[7]*_t26;
  const double _t261 = _hc0[6]*_t32 + _t260;
  const double _t262 = _hc0[3]*_t75 + _t257 - _t259*_t26 + _t261*_t32;
  const double _t263 = _t262*_t32;
  const double _t289 = 0.2e1*_t94;
  const double _t290 = _hc0[5]*_t256;
  const double _t291 = -_hc0[9]*_t26;
  const double _t292 = _hc0[8]*_t32 + _t291;
  const double _t293 = _hc0[4]*_t75 + _t259*_t32 - _t26*_t292 + _t290;
  const double _t304 = _hc0[1]*_t303;
  const double _t305 = _hc1[2]*_t303;
  const double _t306 = _hc2[2]*_t302;
  const double _t307 = (0.1e1 / 0.2e1)*_hc2[5];
  const double _t308 = _t307*_t48;
  const double _t309 = _hc2[9]*_t91;
  const double _t310 = _t309*_t48;
  const double _t313 = _hc1[9]*_t87;
  const double _t314 = _t312*_t313;
  const double _t315 = (0.1e1 / 0.2e1)*_hc1[5];
  const double _t316 = _t315*_t49;
  const double _t317 = 0.2e1*_hc2[5]*_t31*_t72*_t8 - _t122*_t74 - 0.1e1 / 0.2e1*_t305 - 0.1e1 / 0.2e1*_t306 - _t308*_t89 - 0.1e1 / 0.2e1*_t310 - 0.1e1 / 0.2e1*_t314 - _t316*_t75;
  const double _t318 = _t115*_t20;
  const double _t319 = _t124*_t83;
  const double _t320 = -_hc1[2]*_t74 + 0.2e1*_hc2[2]*_t72*_t8 - _t121 - _t123;
  const double _t321 = -0.3e1 / 0.2e1*_t51 - 0.3e1 / 0.2e1*_t52;
  const double _t322 = _t124*_t38;
  const double _t323 = _t117*_t82;
  const double _t324 = _t323*_t41;
  const double _t325 = -_t140*_t322 - _t140*_t324 + _t222;
  const double _t326 = -_t116*_t226 - _t116*_t227 + _t118*_t93 + (0.91e2 / 0.216e3)*_t223 + _t231*_t321 + _t236*_t320 + _t317*_t54 + _t318*_t78 + _t319*_t84 + _t325;
  const double _t329 = _hc0[6]*_t49 + _t260;
  const double _t330 = _hc0[7]*_t49 + _t258;
  const double _t331 = _t257 - _t26*_t330;
  const double _t332 = _hc0[3]*_t74 + _t32*_t329 + _t331;
  const double _t333 = _t32*_t332;
  const double _t342 = _t127*_t75;
  const double _t356 = _hc0[8]*_t49 + _t291;
  const double _t357 = -_t26*_t356 + _t290;
  const double _t358 = _hc0[4]*_t74 + _t32*_t330 + _t357;
  const double _t364 = _t148*_t38;
  const double _t366 = _hc1[5]*_t49;
  const double _t367 = _t122*_t138;
  const double _t368 = _hc2[9]*_t141;
  const double _t369 = _t31*_t368;
  const double _t371 = _hc1[9]*_t146;
  const double _t372 = _t370*_t371;
  const double _t373 = _t120*_t144;
  const double _t374 = 0.3e1*_hc1[2]*_t214*_t8 + _hc1[2]*_t72 - 0.3e1*_hc2[2]*_t365 - _hc2[2]*_t72 + 0.2e1*_hc2[5]*_t48*_t72*_t8 - _t366*_t74 - 0.1e1 / 0.2e1*_t367 - 0.1e1 / 0.2e1*_t369 - 0.1e1 / 0.2e1*_t372 - 0.1e1 / 0.2e1*_t373;
  const double _t375 = _t318*_t77;
  const double _t376 = _t323*_t53;
  const double _t377 = _t232*_t323;
  const double _t378 = -_t142 - _t143 - _t145 - _t147;
  const double _t379 = _t230*_t41;
  const double _t380 = _t117*_t321;
  const double _t381 = -_t116*_t364 - _t116*_t376 + _t124*_t377 + _t236*_t378 + _t325 + _t374*_t54 + (0.91e2 / 0.216e3)*_t375 + _t379*_t380 + _t78*_t80;
  const double _t383 = _hc0[3]*_t138 + _t329*_t49 + _t331;
  const double _t384 = _t32*_t383;
  const double _t392 = _hc0[4]*_t138 + _t330*_t49 + _t357;
  const double _t398 = _hc0[1]*_t397;
  const double _t399 = _t230*_t380;
  const double _t400 = _t378*_t83;
  const double _t402 = _hc2[9]*_t401;
  const double _t403 = _hc1[2]*_t397;
  const double _t404 = _hc2[2]*_t396;
  const double _t406 = _hc1[9]*_t405;
  const double _t409 = -_t138*_t316 - _t144*_t308 - _t308*_t408 - _t316*_t407 - 0.1e1 / 0.2e1*_t402 - 0.1e1 / 0.2e1*_t403 - 0.1e1 / 0.2e1*_t404 - 0.1e1 / 0.2e1*_t406;
  const double _t410 = _t148*_t377 + _t222 - _t225*_t364 - _t225*_t376 + (0.91e2 / 0.144e3)*_t375 + _t399*_t53 + _t400*_t53 + _t409*_t54;
  const double _t413 = _t383*_t49;
  const double _t423 = _t422*_t62;
  const double _t424 = _t42*_t65;
  const double _t425 = -_t36*_t424;
  const double _t426 = _t170*_t226;
  const double _t427 = _t170*_t227;
  const double _t428 = _t423 + _t425 + (0.1e1 / 0.24e2)*_t426 + (0.1e1 / 0.24e2)*_t427;
  const double _t430 = _t158*_t166;
  const double _t445 = _t13*_t161*_t162;
  const double _t446 = _t445*_t60;
  const double _t448 = (0.1e1 / 0.6e1)*_t62;
  const double _t449 = _t14*_t448;
  const double _t452 = _t62*_t78;
  const double _t453 = -_t424*_t81 + (0.1e1 / 0.12e2)*_t426 + (0.1e1 / 0.12e2)*_t427 + _t452;
  const double _t455 = _t158*_t181;
  const double _t467 = _t115*_t65;
  const double _t468 = _t170*_t324;
  const double _t469 = _t170*_t322;
  const double _t470 = -_t168*_t424 - _t168*_t467 + _t423 + (0.1e1 / 0.24e2)*_t468 + (0.1e1 / 0.24e2)*_t469;
  const double _t478 = _t220*_t66;
  const double _t483 = -_t36*_t467;
  const double _t484 = _t425 + _t452 + (0.1e1 / 0.12e2)*_t468 + (0.1e1 / 0.12e2)*_t469 + _t483;
  const double _t494 = _t220*_t62;
  const double _t495 = (0.1e1 / 0.6e1)*_t494;
  const double _t498 = _t170*_t376;
  const double _t499 = _t170*_t364;
  const double _t500 = _t423 + _t483 + (0.1e1 / 0.24e2)*_t498 + (0.1e1 / 0.24e2)*_t499;
  const double _t507 = _t452 - _t467*_t81 + (0.1e1 / 0.12e2)*_t498 + (0.1e1 / 0.12e2)*_t499;
  const double _t514 = _t198*_t38;
  const double _t521 = -0.7e1 / 0.288e3*_t12*_t17*_t18*_t199*_t35;
  const double _t523 = _t42*_t522;
  const double _t524 = -_t521 - 0.1e1 / 0.48e2*_t523;
  const double _t526 = (0.1e1 / 0.48e2)*_t200;
  const double _t530 = _t514*_t529;
  const double _t531 = _t530*_t67;
  const double _t532 = (0.1e1 / 0.192e3)*_t531;
  const double _t539 = (0.1e1 / 0.24e2)*_t200;
  const double _t542 = (0.1e1 / 0.96e2)*_t531;
  const double _t547 = -0.7e1 / 0.144e3*_t12*_t17*_t18*_t199*_t35;
  const double _t548 = -0.1e1 / 0.24e2*_t523 - _t547;
  const double _t555 = (0.1e1 / 0.48e2)*_t531;
  const double _t560 = -0.7e1 / 0.72e2*_t12*_t17*_t18*_t199*_t35;
  const double _t561 = -0.1e1 / 0.12e2*_t523 - _t560;
  const double _t565 = _t115*_t522;
  const double _t566 = -_t521 - 0.1e1 / 0.48e2*_t565;
  const double _t568 = _t14*_t526;
  const double _t572 = _t14*_t539;
  const double _t578 = -_t547 - 0.1e1 / 0.24e2*_t565;
  const double _t582 = _t14*_t205;
  const double _t588 = -_t560 - 0.1e1 / 0.12e2*_t565;
  const double _t591 = xc_powr(0.3e1, 1, 2)*xc_powr(M_PI, 1, 2)*_t82;
  const double _t595 = _t38*_t594;
  const double _t599 = _t598*_t61;
  const double _t208 = -_t207*_t23 - _t207*_t69;
  const double _t212 = _t111*_t211 + _t209*_t210;
  const double _t254 = _hc3[1]*_t253;
  const double _t255 = _hc3[2]*_t218;
  const double _t264 = _hc3[8]*_t256;
  const double _t265 = -_hc3[18]*_t26;
  const double _t266 = _hc3[15]*_t44 + _hc3[16]*_t32 + _t265;
  const double _t267 = -_hc3[16]*_t26;
  const double _t268 = _hc3[12]*_t44 + _hc3[13]*_t32 + _t267;
  const double _t269 = -_hc3[15]*_t26;
  const double _t270 = _hc3[12]*_t32;
  const double _t271 = _hc3[11]*_t44;
  const double _t272 = _t269 + _t270 + _t271;
  const double _t273 = _hc3[5]*_t94 + _hc3[6]*_t75 - _t26*_t266 + _t264 + _t268*_t32 + _t272*_t44;
  const double _t274 = _t273*_t32;
  const double _t275 = _hc3[7]*_t256;
  const double _t276 = _hc3[5]*_t75;
  const double _t277 = -_hc3[17]*_t26;
  const double _t278 = _hc3[15]*_t32;
  const double _t279 = _hc3[14]*_t44;
  const double _t280 = _t277 + _t278 + _t279;
  const double _t281 = -_hc3[14]*_t26;
  const double _t282 = _hc3[11]*_t32;
  const double _t283 = _hc3[10]*_t44;
  const double _t284 = _t281 + _t282 + _t283;
  const double _t285 = _hc3[4]*_t94;
  const double _t286 = -_t26*_t280 + _t272*_t32 + _t275 + _t276 + _t284*_t44 + _t285;
  const double _t287 = _t286*_t44;
  const double _t294 = _hc3[9]*_t256;
  const double _t295 = -_hc3[19]*_t26;
  const double _t296 = _hc3[17]*_t44 + _hc3[18]*_t32 + _t295;
  const double _t297 = _hc3[7]*_t94 + _hc3[8]*_t75 - _t26*_t296 + _t266*_t32 + _t280*_t44 + _t294;
  const double _t298 = _t101*_t288 + _t106*_t289 + _t219 + _t254 + _t255 - _t26*_t293 - _t26*_t297 + _t263 + _t274 + _t287 + _t288*_t98;
  const double _t301 = _t23*_t300 + _t300*_t69;
  const double _t327 = _hc3[1]*_t326;
  const double _t328 = _hc3[2]*_t303;
  const double _t334 = _hc3[12]*_t55 + _hc3[13]*_t49 + _t267;
  const double _t335 = _hc3[12]*_t49;
  const double _t336 = _hc3[11]*_t55;
  const double _t337 = _t269 + _t335 + _t336;
  const double _t338 = _hc3[15]*_t55 + _hc3[16]*_t49 + _t265;
  const double _t339 = -_t26*_t338 + _t264;
  const double _t340 = _hc3[5]*_t125 + _hc3[6]*_t74 + _t32*_t334 + _t337*_t44 + _t339;
  const double _t341 = _t32*_t340;
  const double _t343 = _t129*_t75;
  const double _t344 = _hc3[4]*_t125;
  const double _t345 = _hc3[11]*_t49;
  const double _t346 = _hc3[10]*_t55;
  const double _t347 = _t281 + _t345 + _t346;
  const double _t348 = _hc3[15]*_t49;
  const double _t349 = _hc3[14]*_t55;
  const double _t350 = _t277 + _t348 + _t349;
  const double _t351 = -_t26*_t350 + _t275;
  const double _t352 = _hc3[5]*_t74 + _t32*_t337 + _t344 + _t347*_t44 + _t351;
  const double _t353 = _t352*_t44;
  const double _t354 = _t106*_t125;
  const double _t355 = _t133*_t94;
  const double _t359 = _hc3[17]*_t55 + _hc3[18]*_t49 + _t295;
  const double _t360 = -_t26*_t359 + _t294;
  const double _t361 = _hc3[7]*_t125 + _hc3[8]*_t74 + _t32*_t338 + _t350*_t44 + _t360;
  const double _t363 = _hc0[1]*_t246 + _hc3[2]*_t246 + 0.2e1*_t126 + 0.2e1*_t128 + 0.2e1*_t130 + 0.2e1*_t134;
  const double _t382 = _hc3[1]*_t381;
  const double _t385 = _hc3[5]*_t149 + _hc3[6]*_t138 + _t334*_t49 + _t337*_t55 + _t339;
  const double _t386 = _t32*_t385;
  const double _t387 = _hc3[4]*_t149;
  const double _t388 = _hc3[5]*_t138;
  const double _t389 = _t337*_t49 + _t347*_t55 + _t351 + _t387 + _t388;
  const double _t390 = _t389*_t44;
  const double _t391 = 0.2e1*_t133;
  const double _t393 = _hc3[7]*_t149 + _hc3[8]*_t138 + _t338*_t49 + _t350*_t55 + _t360;
  const double _t394 = _t135*_t211 + _t136*_t211 + _t208 - _t26*_t392 - _t26*_t393;
  const double _t395 = -_t135*_t299 - _t136*_t299 + _t301;
  const double _t411 = _hc3[1]*_t410;
  const double _t412 = _hc3[2]*_t397;
  const double _t414 = _t385*_t49;
  const double _t415 = _t389*_t55;
  const double _t417 = _t127*_t416 + _t129*_t416 + _t149*_t391 + _t398 + _t411 + _t412 + _t413 + _t414 + _t415;
  const double _t419 = _t159*_t164;
  const double _t420 = _t418*_t419;
  const double _t421 = (0.1e1 / 0.36e2)*_t420;
  const double _t429 = _hc3[1]*_t428;
  const double _t431 = -_hc3[15]*_t430;
  const double _t432 = _hc3[5]*_t172 + _t174*_t270 + _t174*_t271 + _t431;
  const double _t433 = _t32*_t432;
  const double _t434 = _hc3[14]*_t158;
  const double _t435 = -_t166*_t434;
  const double _t436 = _hc3[4]*_t172;
  const double _t437 = _t174*_t282 + _t174*_t283 + _t435 + _t436;
  const double _t438 = _t437*_t44;
  const double _t439 = _t106*_t172;
  const double _t440 = -_hc3[17]*_t430;
  const double _t441 = _hc3[7]*_t172 + _t174*_t278 + _t174*_t279 + _t440;
  const double _t442 = _t174*_t276 + _t174*_t285 - _t26*_t441 + _t429 + _t433 + _t438 + _t439;
  const double _t443 = _t1*(_t421 + _t442) + 0.2e1*_t173 + _t186;
  const double _t444 = _t159*_t160;
  const double _t447 = -_t444*_t446;
  const double _t450 = _t105*_t14;
  const double _t451 = (0.1e1 / 0.18e2)*_t420;
  const double _t454 = _hc3[1]*_t453;
  const double _t456 = -_hc3[15]*_t455;
  const double _t457 = _hc3[5]*_t179 + _t183*_t270 + _t183*_t271 + _t456;
  const double _t458 = _t32*_t457;
  const double _t459 = -_t181*_t434;
  const double _t460 = _hc3[4]*_t179;
  const double _t461 = _t183*_t282 + _t183*_t283 + _t459 + _t460;
  const double _t462 = _t44*_t461;
  const double _t463 = _t106*_t179;
  const double _t464 = -_hc3[17]*_t455;
  const double _t465 = _hc3[7]*_t179 + _t183*_t278 + _t183*_t279 + _t464;
  const double _t466 = _t183*_t276 + _t183*_t285 - _t26*_t465 + _t454 + _t458 + _t462 + _t463;
  const double _t471 = _hc3[1]*_t470;
  const double _t472 = _hc3[5]*_t188 + _t174*_t335 + _t174*_t336 + _t431;
  const double _t473 = _t32*_t472;
  const double _t474 = _hc3[4]*_t188;
  const double _t475 = _t174*_t345 + _t174*_t346 + _t435 + _t474;
  const double _t476 = _t44*_t475;
  const double _t477 = _t133*_t172;
  const double _t479 = _hc3[5]*_t478;
  const double _t480 = _hc3[7]*_t188 + _t174*_t348 + _t174*_t349 + _t440;
  const double _t481 = -_t26*_t480 + _t421;
  const double _t482 = _t1*(_t174*_t344 + _t471 + _t473 + _t476 + _t477 + _t479*_t8 + _t481) + _t175 + _t182 + _t190;
  const double _t485 = _hc3[1]*_t484;
  const double _t486 = _hc3[5]*_t192 + _t183*_t335 + _t183*_t336 + _t456;
  const double _t487 = _t32*_t486;
  const double _t488 = _hc3[4]*_t192;
  const double _t489 = _t183*_t345 + _t183*_t346 + _t459 + _t488;
  const double _t490 = _t44*_t489;
  const double _t491 = _t133*_t179;
  const double _t492 = _hc3[7]*_t192 + _t183*_t348 + _t183*_t349 + _t464;
  const double _t493 = -_t26*_t492 + _t451;
  const double _t496 = _hc3[5]*_t495;
  const double _t497 = _t183*_t344 + _t496*_t8;
  const double _t501 = _hc3[1]*_t500;
  const double _t502 = _t472*_t49;
  const double _t503 = _t475*_t55;
  const double _t504 = _t133*_t188;
  const double _t505 = _t174*_t387 + _t174*_t388 + _t501 + _t502 + _t503 + _t504;
  const double _t506 = _t1*(_t481 + _t505) + 0.2e1*_t189 + _t196;
  const double _t508 = _hc3[1]*_t507;
  const double _t509 = _t486*_t49;
  const double _t510 = _t489*_t55;
  const double _t511 = _t133*_t192;
  const double _t512 = _t183*_t387 + _t183*_t388 + _t508 + _t509 + _t510 + _t511;
  const double _t515 = _t434*_t514;
  const double _t516 = _t513*_t515;
  const double _t518 = _t159*_t163;
  const double _t519 = _t517*_t518;
  const double _t520 = -0.1e1 / 0.384e3*_t516 + (0.1e1 / 0.96e2)*_t519;
  const double _t525 = _hc3[1]*_t524;
  const double _t527 = _t104*_t14;
  const double _t528 = _t183*_t436;
  const double _t533 = _t282*_t532 + _t283*_t532 - _t450*_t526 + _t525 - _t526*_t527 + _t528;
  const double _t534 = _t156*_t200;
  const double _t535 = _hc3[4]*_t529;
  const double _t536 = _t514*_t535*_t67;
  const double _t537 = -0.1e1 / 0.48e2*_t534 + (0.1e1 / 0.192e3)*_t536;
  const double _t538 = _t1*(_t520 + _t533) + _t537;
  const double _t540 = -_t450*_t539;
  const double _t541 = -_t527*_t539;
  const double _t543 = _t283*_t542;
  const double _t544 = _t282*_t542;
  const double _t545 = -0.1e1 / 0.192e3*_t516 + (0.1e1 / 0.48e2)*_t519;
  const double _t546 = _t540 + _t541 + _t543 + _t544 + _t545;
  const double _t549 = _hc3[1]*_t548;
  const double _t550 = _t174*_t460 + _t528 + _t549;
  const double _t551 = -0.1e1 / 0.24e2*_t534 + (0.1e1 / 0.96e2)*_t536;
  const double _t552 = _t1*(_t546 + _t550) + _t551;
  const double _t553 = -_t205*_t450;
  const double _t554 = -_t205*_t527;
  const double _t556 = _t283*_t555;
  const double _t557 = _t282*_t555;
  const double _t558 = -0.1e1 / 0.96e2*_t516 + (0.1e1 / 0.24e2)*_t519;
  const double _t559 = _t553 + _t554 + _t556 + _t557 + _t558;
  const double _t562 = _hc3[1]*_t561;
  const double _t563 = _t449*_t460 + _t562;
  const double _t564 = -_t156*_t205 + (0.1e1 / 0.48e2)*_t536;
  const double _t567 = _hc3[1]*_t566;
  const double _t569 = _t183*_t474;
  const double _t570 = -_t131*_t568 - _t132*_t568 + _t345*_t532 + _t346*_t532 + _t567 + _t569;
  const double _t571 = _t1*(_t520 + _t570) + _t537;
  const double _t573 = -_t132*_t572;
  const double _t574 = -_t131*_t572;
  const double _t575 = _t346*_t542;
  const double _t576 = _t345*_t542;
  const double _t577 = _t545 + _t573 + _t574 + _t575 + _t576;
  const double _t579 = _hc3[1]*_t578;
  const double _t580 = _t174*_t488 + _t569 + _t579;
  const double _t581 = _t1*(_t577 + _t580) + _t551;
  const double _t583 = -_t132*_t582;
  const double _t584 = -_t131*_t582;
  const double _t585 = _t346*_t555;
  const double _t586 = _t345*_t555;
  const double _t587 = _t558 + _t583 + _t584 + _t585 + _t586;
  const double _t589 = _hc3[1]*_t588;
  const double _t590 = _t449*_t488 + _t589;
  const double _t592 = _hc3[10]*_t591;
  const double _t593 = _t517*_t592;
  const double _t596 = _t535*_t595;
  const double _t597 = _t24*_t596;
  const double _t600 = _t59*_t599;
  const double _t601 = (0.1e1 / 0.1536e4)*_t593 - 0.1e1 / 0.128e3*_t597 + (0.1e1 / 0.32e2)*_t600;
  const double _t602 = (0.1e1 / 0.768e3)*_t593 - 0.1e1 / 0.64e2*_t597 + (0.1e1 / 0.16e2)*_t600;
  const double _t603 = (0.1e1 / 0.384e3)*_t593 - 0.1e1 / 0.32e2*_t597 + (0.1e1 / 0.8e1)*_t600;
  const double d3F_dna3 = _t1*(_t208 + _t212 + _t298) + 0.3e1*_t102 + 0.3e1*_t107 - _t109*_t299 - _t111*_t299 + _t301 + 0.3e1*_t76 + 0.3e1*_t95 + 0.3e1*_t96 + 0.3e1*_t99;
  const double d3F_dna2_dnb = _t1*(_t101*_t74 + _t109*_t256 + _t111*_t256 + _t135*_t256 + _t136*_t256 + _t208 - _t26*_t358 - _t26*_t361 + _t304 + _t327 + _t328 + _t333 + _t341 + _t342 + _t343 + _t353 + _t354 + _t355 + _t74*_t98) + _t112 - _t135*_t362 - _t136*_t362 + _t301 + _t363;
  const double d3F_dna_dnb2 = _t1*(-_hc0[1]*_t216 - _hc0[1]*_t73 - _hc3[2]*_t216 - _hc3[2]*_t73 + _t125*_t391 + _t127*_t246 + _t129*_t246 + _t382 + _t384 + _t386 + _t390 + _t394) + _t155 + _t363 + _t395;
  const double d3F_dnb3 = _t1*(_t394 + _t417) + 0.3e1*_t139 + 0.3e1*_t150 + 0.3e1*_t151 + 0.3e1*_t152 + 0.3e1*_t153 + 0.3e1*_t154 + _t395;
  const double d3F_dna2_dgaa = _t443;
  const double d3F_dna2_dgab = _t1*(_t451 + _t466) + _t104*_t449 + 0.2e1*_t180 + _t447 + _t448*_t450;
  const double d3F_dna2_dgbb = _t443;
  const double d3F_dna_dnb_dgaa = _t482;
  const double d3F_dna_dnb_dgab = _t1*(_t485 + _t487 + _t490 + _t491 + _t493 + _t497) + _t180 + _t184 + _t185 + _t193 + _t194 + _t195 + _t447;
  const double d3F_dna_dnb_dgbb = _t482;
  const double d3F_dnb2_dgaa = _t506;
  const double d3F_dnb2_dgab = _t1*(_t493 + _t512) + _t131*_t449 + _t132*_t449 + 0.2e1*_t193 + _t447;
  const double d3F_dnb2_dgbb = _t506;
  const double d3F_dna_dgaa2 = _t538;
  const double d3F_dna_dgaa_dgab = _t552;
  const double d3F_dna_dgaa_dgbb = _t538;
  const double d3F_dna_dgab2 = _t1*(_t559 + _t563) + _t564;
  const double d3F_dna_dgab_dgbb = _t552;
  const double d3F_dna_dgbb2 = _t538;
  const double d3F_dnb_dgaa2 = _t571;
  const double d3F_dnb_dgaa_dgab = _t581;
  const double d3F_dnb_dgaa_dgbb = _t571;
  const double d3F_dnb_dgab2 = _t1*(_t587 + _t590) + _t564;
  const double d3F_dnb_dgab_dgbb = _t581;
  const double d3F_dnb_dgbb2 = _t571;
  const double d3F_dgaa3 = _t601;
  const double d3F_dgaa2_dgab = _t602;
  const double d3F_dgaa2_dgbb = _t601;
  const double d3F_dgaa_dgab2 = _t603;
  const double d3F_dgaa_dgab_dgbb = _t602;
  const double d3F_dgaa_dgbb2 = _t601;
  const double d3F_dgab3 = (0.1e1 / 0.192e3)*_t593 - 0.1e1 / 0.16e2*_t597 + (0.1e1 / 0.4e1)*_t600;
  const double d3F_dgab2_dgbb = _t603;
  const double d3F_dgab_dgbb2 = _t602;
  const double d3F_dgbb3 = _t601;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 1] += d3F_dna2_dgab;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 2] += d3F_dna2_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 3] += d3F_dna_dnb_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 4] += d3F_dna_dnb_dgab;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 5] += d3F_dna_dnb_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 6] += d3F_dnb2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 7] += d3F_dnb2_dgab;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 1] += d3F_dna_dgaa_dgab;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 2] += d3F_dna_dgaa_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 3] += d3F_dna_dgab2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 4] += d3F_dna_dgab_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 5] += d3F_dna_dgbb2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 6] += d3F_dnb_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 7] += d3F_dnb_dgaa_dgab;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 8] += d3F_dnb_dgaa_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 9] += d3F_dnb_dgab2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 10] += d3F_dnb_dgab_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 1] += d3F_dgaa2_dgab;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 2] += d3F_dgaa2_dgbb;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 3] += d3F_dgaa_dgab2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 4] += d3F_dgaa_dgab_dgbb;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 5] += d3F_dgaa_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 6] += d3F_dgab3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 7] += d3F_dgab2_dgbb;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 8] += d3F_dgab_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
#endif
#if _KMAX >= 4
  const double _t604 = 0.24e2*_t214;
  const double _t605 = xc_powi(_t1, -5);
  const double _t606 = _t605*_t8;
  const double _t607 = 0.24e2*_t606;
  const double _t608 = -_t604 + _t607;
  const double _t609 = xc_powr(_t1, -31, 6);
  const double _t612 = _t20*_t77;
  const double _t615 = (0.7e1 / 0.18e2)*_t224;
  const double _t618 = (0.7e1 / 0.9e1)*_t224;
  const double _t624 = (0.1e1 / 0.4e1)*_t21;
  const double _t632 = 0.12e2*_t72;
  const double _t633 = 0.12e2*_t214;
  const double _t634 = _t633*_t8;
  const double _t635 = -_t632 + _t634;
  const double _t640 = 0.6e1*_t29;
  const double _t641 = 0.6e1*na - 0.6e1*nb;
  const double _t643 = 0.4e1*na - 0.4e1*nb;
  const double _t644 = 0.2e1*na - 0.2e1*nb;
  const double _t645 = _t644*_t72 - _t71;
  const double _t646 = _t213*_t8;
  const double _t648 = _t207*_t5;
  const double _t705 = 0.3e1*_t75;
  const double _t706 = 0.3e1*_t218;
  const double _t707 = (0.14e2 / 0.9e1)*_t206;
  const double _t716 = _t300*_t5;
  const double _t717 = (0.140e3 / 0.81e2)/xc_powr(_t1, 13, 3);
  const double _t719 = 0.8e1*_t75;
  const double _t720 = (0.2e1 / 0.3e1)*_t24*_t5;
  const double _t721 = (0.16e2 / 0.9e1)*_t67;
  const double _t722 = (0.56e2 / 0.27e2)*_t206;
  const double _t724 = _t607 - _t633;
  const double _t726 = _t72*_t8;
  const double _t728 = 0.3e1*_t726;
  const double _t729 = _t634 - 0.4e1*_t72;
  const double _t787 = 0.2e1*_t303;
  const double _t789 = (0.28e2 / 0.27e2)*_t206;
  const double _t793 = (0.10e2 / 0.9e1)*_t67;
  const double _t795 = _t20*_t78;
  const double _t803 = _t644*_t72 + _t71;
  const double _t806 = 0.4e1*(_t8 * _t8)/xc_powi(_t1, 6);
  const double _t826 = _t5*_t789;
  const double _t831 = 0.8e1*_t726;
  const double _t833 = (0.4e1 / 0.3e1)*_t67;
  const double _t836 = 0.3e1*_t138;
  const double _t856 = 0.18e2*_t365;
  const double _t858 = _t632*_t8;
  const double _t860 = _t604 + _t607;
  const double _t861 = _t632 + _t634;
  const double _t862 = 0.3e1*_t397;
  const double _t863 = 0.8e1*_t138;
  const double _t875 = (0.1e1 / 0.24e2)*_t170;
  const double _t905 = (0.1e1 / 0.12e2)*_t170;
  const double _t974 = (0.1e1 / 0.6e1)*_t170;
  const double _t1003 = _t199*_t418;
  const double _t1066 = (0.1e1 / 0.32e2)*_t598;
  const double _t1067 = _t14*_t19;
  const double _t1121 = M_CBRT3;
  const double _t1122 = (M_CBRTPI * M_CBRTPI);
  const double _t1125 = (0.1e1 / (_t15 * _t15 * _t15));
  const double _t610 = (0.43225e5 / 0.15552e5)*_t34*_t609;
  const double _t611 = _t220*_t80;
  const double _t613 = _t226*_t612;
  const double _t614 = _t227*_t612;
  const double _t616 = _t228*_t229;
  const double _t617 = _t616*_t85;
  const double _t619 = _t235*_t82;
  const double _t620 = _t41*_t619;
  const double _t621 = _t43/xc_powi(_t11, 5);
  const double _t622 = _t621*_t85;
  const double _t623 = _t228*_t622;
  const double _t625 = _t624*_t93;
  const double _t626 = _t232*_t41;
  const double _t627 = _t252*_t38;
  const double _t628 = (0.1e1 / 0.2e1)*_hc1[14];
  const double _t629 = (0.1e1 / 0.2e1)*_hc1[2];
  const double _t630 = (0.1e1 / 0.2e1)*_hc2[2];
  const double _t631 = (0.1e1 / 0.2e1)*_hc2[14];
  const double _t636 = (0.1e1 / 0.2e1)*_t122;
  const double _t637 = (0.1e1 / 0.2e1)*_t120;
  const double _t638 = _t315*_t75;
  const double _t639 = _t307*_t89;
  const double _t642 = (0.1e1 / 0.2e1)*_t313;
  const double _t647 = (0.1e1 / 0.2e1)*_t309;
  const double _t649 = _hc0[4]*_t648;
  const double _t650 = -_t649;
  const double _t651 = _hc0[8]*_t256;
  const double _t652 = -_hc0[13]*_t26;
  const double _t653 = _hc0[12]*_t32 + _t652;
  const double _t654 = -_hc0[12]*_t26;
  const double _t655 = _hc0[11]*_t32 + _t654;
  const double _t656 = _hc0[7]*_t75 - _t26*_t653 + _t32*_t655 + _t651;
  const double _t657 = _hc0[7]*_t256;
  const double _t658 = -_hc0[11]*_t26;
  const double _t709 = _hc0[5]*_t648;
  const double _t710 = -_t709;
  const double _t711 = _hc0[9]*_t256;
  const double _t712 = -_hc0[14]*_t26;
  const double _t725 = _t317*_t38;
  const double _t727 = _hc1[5]*_t726;
  const double _t730 = (0.1e1 / 0.2e1)*_hc2[9]*_t31*_t48;
  const double _t731 = _hc1[9]*_t32*_t49;
  const double _t732 = (0.1e1 / 0.2e1)*_t731;
  const double _t733 = _t124*_t233;
  const double _t734 = _t323*_t93;
  const double _t735 = _t320*_t82;
  const double _t736 = _t225*_t41;
  const double _t737 = _t232*_t735;
  const double _t738 = _hc2[5]*_t48;
  const double _t739 = _t229*_t321;
  const double _t740 = _t739*_t85;
  const double _t741 = _t232*_t739;
  const double _t742 = _t741*_t84;
  const double _t743 = -0.2e1*_t51 - 0.2e1*_t52;
  const double _t744 = _t322*_t612;
  const double _t745 = _t324*_t612;
  const double _t746 = _t610 + (0.91e2 / 0.144e3)*_t744 + (0.91e2 / 0.144e3)*_t745;
  const double _t747 = _hc0[11]*_t49 + _t654;
  const double _t748 = _hc0[12]*_t49 + _t652;
  const double _t749 = -_t26*_t748 + _t651;
  const double _t750 = _hc0[7]*_t74 + _t32*_t747 + _t749;
  const double _t751 = _hc0[10]*_t49 + _t658;
  const double _t752 = -_t26*_t747 + _t657;
  const double _t790 = -_t26*(_hc0[13]*_t49 + _t712) + _t711;
  const double _t794 = _t220*_t318;
  const double _t796 = _t140*_t41;
  const double _t797 = _t229*_t380;
  const double _t798 = _t378*_t82;
  const double _t799 = _t124*_t323;
  const double _t800 = -0.3e1 / 0.2e1*_t142 - 0.3e1 / 0.2e1*_t143 - 0.3e1 / 0.2e1*_t145 - 0.3e1 / 0.2e1*_t147;
  const double _t801 = _t626*_t739;
  const double _t802 = _t374*_t38;
  const double _t804 = (0.1e1 / 0.2e1)*_t371;
  const double _t805 = (0.1e1 / 0.2e1)*_t368;
  const double _t807 = 0.12e2*_hc1[2]*_t606 - 0.12e2*_hc2[2]*_t605*_t8;
  const double _t808 = _hc0[7]*_t138 + _t49*_t747 + _t749;
  const double _t809 = _t26*_t808;
  const double _t810 = _hc0[6]*_t138 + _t49*_t751 + _t752;
  const double _t815 = 0.2e1*_t125;
  const double _t827 = _t26*(_hc0[8]*_t138 + _t49*_t748 + _t790);
  const double _t832 = _t135*_t5;
  const double _t835 = _t38*_t409;
  const double _t837 = _t364*_t612;
  const double _t838 = _t148*_t323;
  const double _t839 = _t53*_t798;
  const double _t840 = _t323*_t624;
  const double _t841 = _t624*_t798;
  const double _t842 = -_t138*_t366 - _t144*_t738 - _t366*_t407 - _t402 - _t403 - _t404 - _t406 - _t408*_t738;
  const double _t843 = _t376*_t612;
  const double _t844 = _t53*_t797;
  const double _t845 = _t624*_t797;
  const double _t846 = _t117*_t800;
  const double _t847 = _t380*_t621*_t743;
  const double _t848 = _hc0[3]*_t397 + _t211*_t330 + _t329*_t416 + _t49*_t810 + _t650 - _t809;
  const double _t849 = 0.2e1*_t149;
  const double _t865 = _t14*_t62;
  const double _t866 = (0.1e1 / 0.8e1)*_t865;
  const double _t869 = -0.1729e4 / 0.5184e4*_t494;
  const double _t870 = _t424*_t77;
  const double _t871 = _t226*_t65;
  const double _t872 = _t35*_t871;
  const double _t873 = _t227*_t65;
  const double _t874 = _t35*_t873;
  const double _t876 = _t170*_t234;
  const double _t877 = _t170*_t620;
  const double _t878 = _t170*_t627;
  const double _t879 = _t164*_t418;
  const double _t880 = (0.1e1 / 0.36e2)*_t879;
  const double _t902 = (0.1e1 / 0.4e1)*_t865;
  const double _t904 = -_t221*_t62;
  const double _t906 = (0.1e1 / 0.18e2)*_t879;
  const double _t923 = _t424*_t78;
  const double _t924 = _t170*_t725;
  const double _t925 = _t41*_t735;
  const double _t926 = _t322*_t65;
  const double _t927 = _t324*_t65;
  const double _t928 = -_t36*_t926 - _t36*_t927 + _t869;
  const double _t932 = _t478*_t8;
  const double _t944 = _t467*_t78;
  const double _t945 = -_t81*_t926 - _t81*_t927 + _t904;
  const double _t949 = _t495*_t8;
  const double _t961 = _t364*_t65;
  const double _t962 = _t170*_t802;
  const double _t963 = _t376*_t65;
  const double _t964 = _t41*_t798;
  const double _t965 = _t41*_t797;
  const double _t973 = _t467*_t77;
  const double _t980 = _t35*_t963;
  const double _t981 = _t35*_t961;
  const double _t982 = _t170*_t835;
  const double _t984 = (0.91e2 / 0.1728e4)*_t200*_t77;
  const double _t985 = -0.7e1 / 0.144e3*_t17*_t18*_t199*_t35*_t38*_t41;
  const double _t986 = _t226*_t522;
  const double _t987 = _t227*_t522;
  const double _t989 = _t513*_t514;
  const double _t990 = (0.1e1 / 0.384e3)*_t989;
  const double _t991 = _t163*_t517;
  const double _t992 = (0.1e1 / 0.96e2)*_t991;
  const double _t996 = _t158*_t990;
  const double _t998 = 0.2e1*_t172;
  const double _t1008 = _t200*_t422;
  const double _t1009 = -0.7e1 / 0.72e2*_t17*_t18*_t199*_t35*_t38*_t41;
  const double _t1010 = (0.1e1 / 0.192e3)*_t989;
  const double _t1011 = (0.1e1 / 0.48e2)*_t991;
  const double _t1014 = _t1010*_t158;
  const double _t1019 = _t200*_t78;
  const double _t1020 = (0.1e1 / 0.96e2)*_t989;
  const double _t1021 = (0.1e1 / 0.24e2)*_t991;
  const double _t1024 = _t1020*_t158;
  const double _t1026 = 0.2e1*_t179;
  const double _t1029 = (0.1e1 / 0.6e1)*_t200;
  const double _t1030 = (0.1e1 / 0.3e1)*_t865;
  const double _t1031 = (0.1e1 / 0.24e2)*_t531;
  const double _t1033 = _t324*_t522;
  const double _t1034 = _t322*_t522;
  const double _t1046 = -0.7e1 / 0.144e3*_t17*_t18*_t199*_t35*_t38*_t53;
  const double _t1052 = -0.7e1 / 0.72e2*_t17*_t18*_t199*_t35*_t38*_t53;
  const double _t1057 = _t376*_t522;
  const double _t1058 = _t364*_t522;
  const double _t1063 = _t1029*_t14;
  const double _t1064 = _t35*_t599;
  const double _t1065 = -0.7e1 / 0.192e3*_t1064;
  const double _t1068 = _t1067*_t42;
  const double _t1069 = _t14*_t200;
  const double _t1070 = (0.1e1 / 0.16e2)*_t1069;
  const double _t1071 = _t529*_t595*_t67;
  const double _t1072 = (0.1e1 / 0.128e3)*_t1071;
  const double _t1073 = (0.1e1 / 0.32e2)*_t599;
  const double _t1074 = (0.1e1 / 0.64e2)*_t531;
  const double _t1075 = _t1003*_t591;
  const double _t1076 = (0.1e1 / 0.1536e4)*_t1075;
  const double _t1087 = -0.7e1 / 0.96e2*_t1064;
  const double _t1088 = _t1068*_t598;
  const double _t1089 = (0.1e1 / 0.64e2)*_t1071;
  const double _t1090 = (0.1e1 / 0.16e2)*_t599;
  const double _t1091 = (0.1e1 / 0.768e3)*_t1075;
  const double _t1096 = -0.7e1 / 0.48e2*_t1064;
  const double _t1097 = (0.1e1 / 0.32e2)*_t1071;
  const double _t1098 = (0.1e1 / 0.8e1)*_t599;
  const double _t1099 = (0.1e1 / 0.384e3)*_t1075;
  const double _t1103 = -0.7e1 / 0.24e2*_t1064;
  const double _t1104 = (0.1e1 / 0.4e1)*_t1069;
  const double _t1105 = (0.1e1 / 0.16e2)*_t1071;
  const double _t1106 = (0.1e1 / 0.4e1)*_t599;
  const double _t1107 = (0.1e1 / 0.16e2)*_t531;
  const double _t1108 = (0.1e1 / 0.192e3)*_t1075;
  const double _t1111 = _t1067*_t115;
  const double _t1112 = _t1073*_t14;
  const double _t1114 = _t1111*_t598;
  const double _t1115 = _t1090*_t14;
  const double _t1118 = _t1098*_t14;
  const double _t1120 = _t1106*_t14;
  const double _t659 = -_hc3[8]*_t648;
  const double _t660 = _hc3[18]*_t256;
  const double _t661 = -_hc3[33]*_t26;
  const double _t662 = _hc3[30]*_t44 + _hc3[31]*_t32 + _t661;
  const double _t663 = -_hc3[31]*_t26;
  const double _t664 = _hc3[27]*_t44 + _hc3[28]*_t32 + _t663;
  const double _t665 = -_hc3[30]*_t26;
  const double _t666 = _hc3[27]*_t32;
  const double _t667 = _hc3[26]*_t44;
  const double _t668 = _t665 + _t666 + _t667;
  const double _t669 = _hc3[15]*_t94 + _hc3[16]*_t75 - _t26*_t662 + _t32*_t664 + _t44*_t668 + _t660;
  const double _t670 = _hc3[16]*_t256;
  const double _t671 = -_hc3[28]*_t26;
  const double _t672 = -_hc3[27]*_t26;
  const double _t673 = _hc3[23]*_t32;
  const double _t674 = _hc3[22]*_t44;
  const double _t675 = _t672 + _t673 + _t674;
  const double _t676 = _hc3[15]*_t256;
  const double _t677 = _hc3[12]*_t75;
  const double _t678 = -_hc3[26]*_t26;
  const double _t679 = _hc3[22]*_t32;
  const double _t680 = _hc3[21]*_t44;
  const double _t681 = _t678 + _t679 + _t680;
  const double _t682 = _hc3[11]*_t94;
  const double _t683 = -_t26*_t668 + _t32*_t675 + _t44*_t681 + _t676 + _t677 + _t682;
  const double _t684 = -_hc3[7]*_t648;
  const double _t685 = _hc3[5]*_t218;
  const double _t686 = _hc3[17]*_t256;
  const double _t687 = _hc3[15]*_t75;
  const double _t688 = -_hc3[32]*_t26;
  const double _t689 = _hc3[30]*_t32;
  const double _t690 = _hc3[29]*_t44;
  const double _t691 = _t688 + _t689 + _t690;
  const double _t692 = -_hc3[29]*_t26;
  const double _t693 = _hc3[26]*_t32;
  const double _t694 = _hc3[25]*_t44;
  const double _t695 = _t692 + _t693 + _t694;
  const double _t696 = _hc3[14]*_t94;
  const double _t697 = -_t26*_t691 + _t32*_t668 + _t44*_t695 + _t686 + _t687 + _t696;
  const double _t698 = _hc3[14]*_t256;
  const double _t699 = _hc3[11]*_t75;
  const double _t700 = -_hc3[25]*_t26;
  const double _t701 = _hc3[21]*_t32;
  const double _t702 = _hc3[20]*_t44;
  const double _t703 = _hc3[10]*_t94;
  const double _t704 = _hc3[4]*_t253;
  const double _t708 = _t111*_t5;
  const double _t713 = -_hc3[9]*_t648;
  const double _t714 = _hc3[19]*_t256;
  const double _t715 = -_hc3[34]*_t26;
  const double _t718 = _t23*_t717 + _t69*_t717;
  const double _t723 = -_t23*_t722 - _t69*_t722;
  const double _t753 = _hc3[27]*_t55 + _hc3[28]*_t49 + _t663;
  const double _t754 = _hc3[27]*_t49;
  const double _t755 = _hc3[26]*_t55;
  const double _t756 = _t665 + _t754 + _t755;
  const double _t757 = _hc3[30]*_t55 + _hc3[31]*_t49 + _t661;
  const double _t758 = -_t26*_t757 + _t660;
  const double _t759 = _hc3[15]*_t125 + _hc3[16]*_t74 + _t32*_t753 + _t44*_t756 + _t758;
  const double _t760 = _hc3[23]*_t55 + _hc3[24]*_t49 + _t671;
  const double _t761 = _hc3[23]*_t49;
  const double _t762 = _hc3[22]*_t55;
  const double _t763 = _t672 + _t761 + _t762;
  const double _t764 = -_t26*_t753 + _t670;
  const double _t765 = _hc3[11]*_t125;
  const double _t766 = _hc3[22]*_t49;
  const double _t767 = _hc3[21]*_t55;
  const double _t768 = _t678 + _t766 + _t767;
  const double _t769 = -_t26*_t756 + _t676;
  const double _t770 = _hc3[12]*_t74 + _t32*_t763 + _t44*_t768 + _t765 + _t769;
  const double _t771 = _hc3[5]*_t303;
  const double _t772 = _hc3[14]*_t125;
  const double _t773 = _hc3[26]*_t49;
  const double _t774 = _hc3[25]*_t55;
  const double _t775 = _t692 + _t773 + _t774;
  const double _t776 = _hc3[30]*_t49;
  const double _t777 = _hc3[29]*_t55;
  const double _t778 = _t688 + _t776 + _t777;
  const double _t779 = -_t26*_t778 + _t686;
  const double _t780 = _hc3[15]*_t74 + _t32*_t756 + _t44*_t775 + _t772 + _t779;
  const double _t781 = _hc3[10]*_t125;
  const double _t782 = _hc3[21]*_t49;
  const double _t783 = _hc3[20]*_t55;
  const double _t784 = _t700 + _t782 + _t783;
  const double _t785 = -_t26*_t775 + _t698;
  const double _t786 = _hc3[4]*_t326;
  const double _t788 = 0.2e1*_t106;
  const double _t791 = -_t26*(_hc3[32]*_t55 + _hc3[33]*_t49 + _t715) + _t714;
  const double _t792 = _t211*_t358 + _t211*_t361 + _t718;
  const double _t811 = _hc3[12]*_t149 + _hc3[13]*_t138 + _t49*_t760 + _t55*_t763 + _t764;
  const double _t812 = _hc3[11]*_t149;
  const double _t813 = _hc3[12]*_t138;
  const double _t814 = _t49*_t763 + _t55*_t768 + _t769 + _t812 + _t813;
  const double _t816 = _hc3[15]*_t149 + _hc3[16]*_t138 + _t49*_t753 + _t55*_t756 + _t758;
  const double _t817 = _t211*_t338 - _t26*_t816 + _t659;
  const double _t818 = _hc3[4]*_t381;
  const double _t819 = _hc3[10]*_t149;
  const double _t820 = _hc3[11]*_t138;
  const double _t821 = _t49*_t768 + _t55*_t784 + _t785 + _t819 + _t820;
  const double _t822 = _hc3[14]*_t149;
  const double _t823 = _hc3[15]*_t138;
  const double _t824 = _t49*_t756 + _t55*_t775 + _t779 + _t822 + _t823;
  const double _t825 = _t211*_t350 - _t26*_t824 + _t684;
  const double _t828 = _t211*_t359 - _t26*(_hc3[17]*_t149 + _hc3[18]*_t138 + _t49*_t757 + _t55*_t778 + _t791) + _t713;
  const double _t829 = _hc0[1]*_t607 + _hc3[2]*_t607;
  const double _t830 = _t125*_t133;
  const double _t834 = _t136*_t5;
  const double _t850 = _hc3[5]*_t410 + _hc3[6]*_t397 + _t334*_t416 + _t337*_t849 + _t49*_t811 + _t55*_t814 + _t817;
  const double _t851 = _hc3[4]*_t410;
  const double _t852 = _hc3[5]*_t397;
  const double _t853 = _t337*_t416 + _t347*_t849 + _t49*_t814 + _t55*_t821 + _t825 + _t851 + _t852;
  const double _t854 = 0.3e1*_t133;
  const double _t855 = 0.3e1*_t389;
  const double _t857 = -_t26*(_hc0[4]*_t397 + _t211*_t356 + _t330*_t416 + _t49*_t808 + _t710 - _t827) - _t26*(_hc3[7]*_t410 + _hc3[8]*_t397 + _t338*_t416 + _t350*_t849 + _t49*_t816 + _t55*_t824 + _t828) + _t392*_t716 + _t393*_t716 - _t707*_t832 - _t707*_t834 + _t718;
  const double _t859 = -_t392*_t720 - _t393*_t720 + _t721*_t832 + _t721*_t834 + _t723;
  const double _t864 = _t159*_t418*_t446;
  const double _t867 = _t419/xc_powr(_t1, 9, 2);
  const double _t868 = -0.7e1 / 0.108e3*_t867;
  const double _t881 = _hc3[17]*_t158;
  const double _t882 = _t880*_t881;
  const double _t883 = -_hc3[32]*_t430;
  const double _t884 = -_hc3[30]*_t430;
  const double _t885 = _hc3[15]*_t172 + _t174*_t666 + _t174*_t667 + _t884;
  const double _t886 = -_hc3[29]*_t430;
  const double _t887 = _hc3[14]*_t172;
  const double _t888 = _t174*_t693 + _t174*_t694 + _t886 + _t887;
  const double _t889 = _hc3[15]*_t158;
  const double _t890 = _t880*_t889;
  const double _t891 = -_hc3[27]*_t430;
  const double _t892 = _hc3[26]*_t158;
  const double _t893 = -_t166*_t892;
  const double _t894 = _hc3[11]*_t172;
  const double _t895 = _t174*_t679 + _t174*_t680 + _t893 + _t894;
  const double _t896 = _t434*_t880;
  const double _t897 = _hc3[4]*_t428;
  const double _t898 = -_hc3[25]*_t430;
  const double _t899 = _hc3[10]*_t172;
  const double _t900 = _t1*(_hc3[1]*(_t617*_t875 + _t869 + (0.91e2 / 0.288e3)*_t870 - 0.7e1 / 0.48e2*_t872 - 0.7e1 / 0.48e2*_t874 + (0.1e1 / 0.12e2)*_t876 + (0.1e1 / 0.24e2)*_t877 + (0.1e1 / 0.24e2)*_t878) + _t172*_t286 + _t174*_t685 + _t174*_t704 + _t211*_t441 - _t26*(_hc3[7]*_t428 + _t172*_t280 + _t174*_t687 + _t174*_t696 - _t26*(_hc3[17]*_t172 + _t174*_t689 + _t174*_t690 + _t883) + _t32*_t885 + _t44*_t888 + _t882) + _t288*_t432 + _t289*_t437 + _t32*(_hc3[5]*_t428 + _t172*_t272 + _t174*_t677 + _t174*_t682 - _t26*_t885 + _t32*(_hc3[12]*_t172 + _t174*_t673 + _t174*_t674 + _t891) + _t44*_t895 + _t890) + _t428*_t788 + _t44*(_t172*_t284 + _t174*_t699 + _t174*_t703 - _t26*_t888 + _t32*_t895 + _t44*(_t174*_t701 + _t174*_t702 + _t898 + _t899) + _t896 + _t897) + _t868) + _t276*_t866 + _t285*_t866 - _t299*_t441 + 0.3e1*_t429 + 0.3e1*_t433 + 0.3e1*_t438 + 0.3e1*_t439 + _t864;
  const double _t901 = (0.1e1 / 0.6e1)*_t420;
  const double _t903 = -0.7e1 / 0.54e2*_t867;
  const double _t907 = _t881*_t906;
  const double _t908 = -_hc3[32]*_t455;
  const double _t909 = -_hc3[30]*_t455;
  const double _t910 = _hc3[15]*_t179 + _t183*_t666 + _t183*_t667 + _t909;
  const double _t911 = -_hc3[29]*_t455;
  const double _t912 = _hc3[14]*_t179;
  const double _t913 = _t183*_t693 + _t183*_t694 + _t911 + _t912;
  const double _t914 = _t889*_t906;
  const double _t915 = -_hc3[27]*_t455;
  const double _t916 = -_t181*_t892;
  const double _t917 = _hc3[11]*_t179;
  const double _t918 = _t183*_t679 + _t183*_t680 + _t916 + _t917;
  const double _t919 = _t434*_t906;
  const double _t920 = _hc3[4]*_t453;
  const double _t921 = -_hc3[25]*_t455;
  const double _t922 = _hc3[10]*_t179;
  const double _t929 = _hc3[15]*_t188 + _t174*_t754 + _t174*_t755 + _t884;
  const double _t930 = _hc3[14]*_t188;
  const double _t931 = _t174*_t773 + _t174*_t774 + _t886 + _t930;
  const double _t933 = -_t26*(_hc3[17]*_t188 + _t174*_t776 + _t174*_t777 + _t883) + _t882;
  const double _t934 = _hc3[12]*_t188 + _t174*_t761 + _t174*_t762 + _t891;
  const double _t935 = _hc3[11]*_t188;
  const double _t936 = _t174*_t766 + _t174*_t767 + _t893 + _t935;
  const double _t937 = -_t26*_t929 + _t890;
  const double _t938 = _hc3[4]*_t470;
  const double _t939 = _hc3[10]*_t188;
  const double _t940 = _t174*_t782 + _t174*_t783 + _t898 + _t939;
  const double _t941 = -_t26*_t931 + _t896;
  const double _t942 = 0.2e1*_t471 + 0.2e1*_t473 + 0.2e1*_t476 + 0.2e1*_t477 + _t497;
  const double _t943 = _t1*(_hc3[1]*(-_t168*_t871 - _t168*_t873 + _t422*_t467 + _t733*_t875 + _t734*_t875 + _t740*_t875 + _t875*_t925 + _t923 + (0.1e1 / 0.24e2)*_t924 + _t928) + _t106*_t470 + _t125*_t437 + _t133*_t428 + _t172*_t352 + _t174*_t771 + _t174*_t786 + _t256*_t441 + _t256*_t480 - _t26*(_hc3[15]*_t932 + _hc3[7]*_t470 + _t172*_t350 + _t174*_t772 + _t32*_t929 + _t44*_t931 + _t933) + _t32*(_hc3[12]*_t932 + _hc3[5]*_t470 + _t172*_t337 + _t174*_t765 + _t32*_t934 + _t44*_t936 + _t937) + _t432*_t74 + _t44*(_hc3[11]*_t932 + _t172*_t347 + _t174*_t781 + _t32*_t936 + _t44*_t940 + _t938 + _t941) + _t472*_t75 + _t475*_t94 + _t868) - _t362*_t480 + _t442 + _t864 + _t942;
  const double _t946 = _hc3[15]*_t192 + _t183*_t754 + _t183*_t755 + _t909;
  const double _t947 = _hc3[14]*_t192;
  const double _t948 = _t183*_t773 + _t183*_t774 + _t911 + _t947;
  const double _t950 = -_t26*(_hc3[17]*_t192 + _t183*_t776 + _t183*_t777 + _t908) + _t907;
  const double _t951 = _hc3[12]*_t192 + _t183*_t761 + _t183*_t762 + _t915;
  const double _t952 = _hc3[11]*_t192;
  const double _t953 = _t183*_t766 + _t183*_t767 + _t916 + _t952;
  const double _t954 = -_t26*_t946 + _t914;
  const double _t955 = _hc3[4]*_t484;
  const double _t956 = _hc3[10]*_t192;
  const double _t957 = _t183*_t782 + _t183*_t783 + _t921 + _t956;
  const double _t958 = -_t26*_t948 + _t919;
  const double _t959 = _hc3[5]*_t8;
  const double _t960 = _t344*_t449 + 0.2e1*_t485 + 0.2e1*_t487 + 0.2e1*_t490 + 0.2e1*_t491 + (0.1e1 / 0.3e1)*_t494*_t959;
  const double _t966 = _hc3[5]*_t500 + _t174*_t812 + _t174*_t813 + _t188*_t337 + _t49*_t934 + _t55*_t936 + _t937;
  const double _t967 = _hc3[4]*_t500;
  const double _t968 = _t174*_t819 + _t174*_t820 + _t188*_t347 + _t49*_t936 + _t55*_t940 + _t941 + _t967;
  const double _t969 = _t609*_t62*_t959;
  const double _t970 = _t211*_t480 - _t26*(_hc3[7]*_t500 + _t174*_t822 + _t174*_t823 + _t188*_t350 + _t49*_t929 + _t55*_t931 + _t933) + _t868;
  const double _t971 = -_t299*_t480 + _t864;
  const double _t972 = _t1*(_hc3[1]*(-_t168*_t961 - _t168*_t963 + _t422*_t424 + _t799*_t905 + _t875*_t964 + _t875*_t965 + _t928 + _t944 + (0.1e1 / 0.24e2)*_t962) + _t172*_t389 + _t174*_t818 + _t246*_t472 + _t32*_t966 + _t391*_t470 + _t44*_t968 + _t475*_t815 - _t479 - 0.1e1 / 0.4e1*_t969 + _t970) + _t505 + _t942 + _t971;
  const double _t975 = _hc3[5]*_t507 + _t183*_t812 + _t183*_t813 + _t192*_t337 + _t49*_t951 + _t55*_t953 + _t954;
  const double _t976 = _hc3[4]*_t507;
  const double _t977 = _t183*_t819 + _t183*_t820 + _t192*_t347 + _t49*_t953 + _t55*_t957 + _t958 + _t976;
  const double _t978 = _t211*_t492 - _t26*(_hc3[7]*_t507 + _t183*_t822 + _t183*_t823 + _t192*_t350 + _t49*_t946 + _t55*_t948 + _t950) + _t903;
  const double _t979 = -_t299*_t492 + _t901;
  const double _t983 = _t1*(_hc3[1]*(_t838*_t905 + _t839*_t875 + _t844*_t875 + _t869 + (0.91e2 / 0.288e3)*_t973 - 0.7e1 / 0.48e2*_t980 - 0.7e1 / 0.48e2*_t981 + (0.1e1 / 0.24e2)*_t982) + _t174*_t851 + _t174*_t852 + _t188*_t389 + _t391*_t500 + _t416*_t472 + _t475*_t849 + _t49*_t966 + _t55*_t968 + _t970) + _t387*_t866 + _t388*_t866 + 0.3e1*_t501 + 0.3e1*_t502 + 0.3e1*_t503 + 0.3e1*_t504 + _t971;
  const double _t988 = _t183*_t894;
  const double _t993 = _t889*_t992 - _t892*_t990;
  const double _t994 = _hc3[4]*_t524;
  const double _t995 = _t183*_t899;
  const double _t997 = -_hc3[25]*_t996 + _t434*_t992;
  const double _t999 = _t183*_t887;
  const double _t1000 = -_hc3[29]*_t996 + _t881*_t992;
  const double _t1001 = _t183*_t897;
  const double _t1002 = _t515/xc_powr(_t1, 14, 3);
  const double _t1004 = _t1003*_t518;
  const double _t1005 = (0.1e1 / 0.288e3)*_t1002 - 0.1e1 / 0.72e2*_t1004;
  const double _t1006 = _t436*_t449;
  const double _t1007 = _t1*(_hc3[1]*(-_t984 - _t985 - 0.1e1 / 0.48e2*_t986 - 0.1e1 / 0.48e2*_t987) + _t1001 + _t1005 + _t106*_t524 - _t26*(_hc3[7]*_t524 + _t1000 - _t278*_t568 - _t279*_t568 + _t532*_t693 + _t532*_t694 + _t999) - _t276*_t568 - _t285*_t568 + _t32*(_hc3[5]*_t524 - _t270*_t568 - _t271*_t568 + _t532*_t679 + _t532*_t680 + _t988 + _t993) + _t437*_t998 + _t44*(-_t282*_t568 - _t283*_t568 + _t532*_t701 + _t532*_t702 + _t994 + _t995 + _t997) + _t532*_t699 + _t532*_t703) + _t1006 + 0.2e1*_t525 + _t546;
  const double _t1012 = -_t1010*_t892 + _t1011*_t889;
  const double _t1013 = _hc3[4]*_t548;
  const double _t1015 = -_hc3[25]*_t1014 + _t1011*_t434;
  const double _t1016 = -_hc3[29]*_t1014 + _t1011*_t881;
  const double _t1017 = (0.1e1 / 0.144e3)*_t1002 - 0.1e1 / 0.36e2*_t1004;
  const double _t1018 = _t1*(_hc3[1]*(-_t1008 - _t1009 - 0.1e1 / 0.24e2*_t986 - 0.1e1 / 0.24e2*_t987) + _t1001 + _t1017 + _t106*_t548 + _t172*_t461 + _t174*_t920 + _t179*_t437 - _t26*(_hc3[7]*_t548 + _t1016 + _t174*_t912 - _t278*_t572 - _t279*_t572 + _t542*_t693 + _t542*_t694 + _t999) - _t276*_t572 - _t285*_t572 + _t32*(_hc3[5]*_t548 + _t1012 + _t174*_t917 - _t270*_t572 - _t271*_t572 + _t542*_t679 + _t542*_t680 + _t988) + _t44*(_t1013 + _t1015 + _t174*_t922 - _t282*_t572 - _t283*_t572 + _t542*_t701 + _t542*_t702 + _t995) + _t542*_t699 + _t542*_t703) + _t1006 + _t183*_t460 + 0.2e1*_t549 + _t559;
  const double _t1022 = -_t1020*_t892 + _t1021*_t889;
  const double _t1023 = _hc3[4]*_t561;
  const double _t1025 = -_hc3[25]*_t1024 + _t1021*_t434;
  const double _t1027 = -_hc3[29]*_t1024 + _t1021*_t881;
  const double _t1028 = (0.1e1 / 0.72e2)*_t1002 - 0.1e1 / 0.18e2*_t1004;
  const double _t1032 = _t159*_t445*_t517 - 0.1e1 / 0.48e2*_t516;
  const double _t1035 = _t183*_t935;
  const double _t1036 = _hc3[5]*_t566 + _t1035 - _t335*_t568 - _t336*_t568 + _t532*_t766 + _t532*_t767 + _t993;
  const double _t1037 = _hc3[4]*_t566;
  const double _t1038 = _t183*_t939;
  const double _t1039 = _t1037 + _t1038 - _t345*_t568 - _t346*_t568 + _t532*_t782 + _t532*_t783 + _t997;
  const double _t1040 = _t220*_t959;
  const double _t1041 = _t183*_t938;
  const double _t1042 = _hc3[11]*_t530*_t8/xc_powr(_t1, 16, 3);
  const double _t1043 = _t183*_t930;
  const double _t1044 = _t1005 - _t26*(_hc3[7]*_t566 + _t1000 + _t1043 - _t348*_t568 - _t349*_t568 + _t532*_t773 + _t532*_t774);
  const double _t1045 = _t1*(_hc3[1]*(-0.1e1 / 0.48e2*_t1033 - 0.1e1 / 0.48e2*_t1034 + (0.7e1 / 0.288e3)*_t17*_t18*_t199*_t35*_t38*_t41 + (0.7e1 / 0.288e3)*_t17*_t18*_t199*_t35*_t38*_t53 - _t984) + _t1036*_t32 + _t1039*_t44 - _t1040*_t539 + _t1041 + (0.1e1 / 0.96e2)*_t1042 + _t1044 + _t133*_t524 - _t344*_t568 + _t475*_t998 + _t532*_t781) + _t533 + _t545 + _t570;
  const double _t1047 = _hc3[5]*_t578 + _t1012 + _t1035 + _t174*_t952 - _t335*_t572 - _t336*_t572 + _t542*_t766 + _t542*_t767;
  const double _t1048 = _hc3[4]*_t578;
  const double _t1049 = _t1015 + _t1038 + _t1048 + _t174*_t956 - _t345*_t572 - _t346*_t572 + _t542*_t782 + _t542*_t783;
  const double _t1050 = _t1017 - _t26*(_hc3[7]*_t578 + _t1016 + _t1043 + _t174*_t947 - _t348*_t572 - _t349*_t572 + _t542*_t773 + _t542*_t774);
  const double _t1051 = _t1*(_hc3[1]*(-_t1008 - 0.1e1 / 0.24e2*_t1033 - 0.1e1 / 0.24e2*_t1034 - _t1046 - _t985) - _t1040*_t205 + _t1041 + (0.1e1 / 0.48e2)*_t1042 + _t1047*_t32 + _t1049*_t44 + _t1050 + _t133*_t548 + _t172*_t489 + _t174*_t955 + _t179*_t475 - _t344*_t572 + _t542*_t781) + _t540 + _t541 + _t543 + _t544 + _t550 + _t558 + _t573 + _t574 + _t575 + _t576 + _t580;
  const double _t1053 = _hc3[5]*_t588 + _t1022 - _t335*_t582 - _t336*_t582 + _t449*_t952 + _t555*_t766 + _t555*_t767;
  const double _t1054 = _hc3[4]*_t588;
  const double _t1055 = _t1025 + _t1054 - _t345*_t582 - _t346*_t582 + _t449*_t956 + _t555*_t782 + _t555*_t783;
  const double _t1056 = _t1028 - _t26*(_hc3[7]*_t588 + _t1027 - _t348*_t582 - _t349*_t582 + _t449*_t947 + _t555*_t773 + _t555*_t774);
  const double _t1059 = _t183*_t967;
  const double _t1060 = _t449*_t474;
  const double _t1061 = _t1*(_hc3[1]*(-_t1046 - 0.1e1 / 0.48e2*_t1057 - 0.1e1 / 0.48e2*_t1058 - _t984) + _t1036*_t49 + _t1039*_t55 + _t1044 + _t1059 + _t133*_t566 + 0.2e1*_t188*_t475 - _t387*_t568 - _t388*_t568 + _t532*_t819 + _t532*_t820) + _t1060 + 0.2e1*_t567 + _t577;
  const double _t1062 = _t1*(_hc3[1]*(-_t1008 - _t1052 - 0.1e1 / 0.24e2*_t1057 - 0.1e1 / 0.24e2*_t1058) + _t1047*_t49 + _t1049*_t55 + _t1050 + _t1059 + _t133*_t578 + _t174*_t976 + _t188*_t489 + _t192*_t475 - _t387*_t572 - _t388*_t572 + _t542*_t819 + _t542*_t820) + _t1060 + _t183*_t488 + 0.2e1*_t579 + _t587;
  const double _t1077 = _t434*_t513*_t595;
  const double _t1078 = _t163*_t444;
  const double _t1079 = _t1078*_t598;
  const double _t1080 = _hc3[25]*_t158*_t204*_t82/xc_powr(_t1, 29, 6);
  const double _t1081 = (0.1e1 / 0.256e3)*_t1077 - 0.1e1 / 0.64e2*_t1079 - 0.1e1 / 0.9216e4*_t1080;
  const double _t1082 = _t596*_t67;
  const double _t1083 = _t156*_t599;
  const double _t1084 = _t1003*_t592;
  const double _t1085 = -0.1e1 / 0.128e3*_t1082 + (0.1e1 / 0.32e2)*_t1083 + (0.1e1 / 0.1536e4)*_t1084;
  const double _t1086 = _t1*(_hc3[1]*(_t1065 + _t1066*_t1068) - _t1070*_t436 - _t1072*_t282 - _t1072*_t283 + _t1073*_t450 + _t1073*_t527 + _t1074*_t899 + _t1076*_t701 + _t1076*_t702 + _t1081 + _t866*_t994) + _t1085;
  const double _t1092 = -_t436*_t582 + _t555*_t899;
  const double _t1093 = -_t1066*_t1078 + (0.1e1 / 0.128e3)*_t1077 - 0.1e1 / 0.4608e4*_t1080;
  const double _t1094 = -0.1e1 / 0.64e2*_t1082 + (0.1e1 / 0.16e2)*_t1083 + (0.1e1 / 0.768e3)*_t1084;
  const double _t1095 = _t1*(_hc3[1]*(_t1087 + (0.1e1 / 0.16e2)*_t1088) + _t1013*_t183 - _t1089*_t282 - _t1089*_t283 + _t1090*_t450 + _t1090*_t527 + _t1091*_t701 + _t1091*_t702 + _t1092 + _t1093 + _t183*_t994 - _t460*_t568 + _t532*_t922) + _t1094;
  const double _t1100 = (0.1e1 / 0.64e2)*_t1077 - 0.1e1 / 0.16e2*_t1079 - 0.1e1 / 0.2304e4*_t1080;
  const double _t1101 = -0.1e1 / 0.32e2*_t1082 + (0.1e1 / 0.8e1)*_t1083 + (0.1e1 / 0.384e3)*_t1084;
  const double _t1102 = _t1*(_hc3[1]*((0.1e1 / 0.8e1)*_t1088 + _t1096) + _t1013*_t449 + _t1023*_t174 + _t1092 - _t1097*_t282 - _t1097*_t283 + _t1098*_t450 + _t1098*_t527 + _t1099*_t701 + _t1099*_t702 + _t1100 - _t460*_t582 + _t555*_t922) + _t1101;
  const double _t1109 = (0.1e1 / 0.32e2)*_t1077 - 0.1e1 / 0.8e1*_t1079 - 0.1e1 / 0.1152e4*_t1080;
  const double _t1110 = -0.1e1 / 0.16e2*_t1082 + (0.1e1 / 0.4e1)*_t1083 + (0.1e1 / 0.192e3)*_t1084;
  const double _t1113 = _t1*(_hc3[1]*(_t1065 + _t1066*_t1111) + _t1037*_t866 - _t1070*_t474 - _t1072*_t345 - _t1072*_t346 + _t1074*_t939 + _t1076*_t782 + _t1076*_t783 + _t1081 + _t1112*_t131 + _t1112*_t132) + _t1085;
  const double _t1116 = -_t474*_t582 + _t555*_t939;
  const double _t1117 = _t1*(_hc3[1]*(_t1087 + (0.1e1 / 0.16e2)*_t1114) + _t1037*_t183 + _t1048*_t183 - _t1089*_t345 - _t1089*_t346 + _t1091*_t782 + _t1091*_t783 + _t1093 + _t1115*_t131 + _t1115*_t132 + _t1116 - _t488*_t568 + _t532*_t956) + _t1094;
  const double _t1119 = _t1*(_hc3[1]*(_t1096 + (0.1e1 / 0.8e1)*_t1114) + _t1048*_t449 + _t1054*_t174 - _t1097*_t345 - _t1097*_t346 + _t1099*_t782 + _t1099*_t783 + _t1100 + _t1116 + _t1118*_t131 + _t1118*_t132 - _t488*_t582 + _t555*_t956) + _t1101;
  const double _t1123 = _t160*_t592;
  const double _t1124 = _t1123*_t598;
  const double _t1126 = _t59*_t61/xc_powr(_t15, 7, 2);
  const double _t1127 = (0.1e1 / 0.12288e5)*_hc3[20]*_t1121*_t1122*_t229*_t513*_t594 + (0.5e1 / 0.256e3)*_hc3[4]*_t1125*_t197*_t24*_t3*_t38 - 0.1e1 / 0.512e3*_t1124 - 0.5e1 / 0.64e2*_t1126;
  const double _t1128 = (0.1e1 / 0.6144e4)*_hc3[20]*_t1121*_t1122*_t229*_t513*_t594 + (0.5e1 / 0.128e3)*_hc3[4]*_t1125*_t197*_t24*_t3*_t38 - 0.1e1 / 0.256e3*_t1124 - 0.5e1 / 0.32e2*_t1126;
  const double _t1129 = (0.1e1 / 0.3072e4)*_hc3[20]*_t1121*_t1122*_t229*_t513*_t594 + (0.5e1 / 0.64e2)*_hc3[4]*_t1125*_t197*_t24*_t3*_t38 - 0.1e1 / 0.128e3*_t1124 - 0.5e1 / 0.16e2*_t1126;
  const double _t1130 = (0.1e1 / 0.1536e4)*_hc3[20]*_t1121*_t1122*_t229*_t513*_t594 + (0.5e1 / 0.32e2)*_hc3[4]*_t1125*_t197*_t24*_t3*_t38 - 0.1e1 / 0.64e2*_t1124 - 0.5e1 / 0.8e1*_t1126;
  const double d4F_dna4 = _t1*(_hc0[1]*_t608 + _hc3[1]*(_t231*(-0.3e1 / 0.2e1*_t86 - 0.3e1 / 0.2e1*_t88 - 0.3e1 / 0.2e1*_t90 - 0.3e1 / 0.2e1*_t92) + _t233*_t252*_t624 - _t234*_t618 + _t235*_t616*_t626 + _t236*(-_t237 - _t239 - _t240 - _t242 - _t243 - _t248 - _t250 - _t251) + _t54*(-_t120*_t217 - _t122*_t218 - _t247*_t638 - _t249*_t639 - _t249*_t647 - _t307*(_t89 * _t89) - (_t31 * _t31 * _t31 * _t31)*_t631 - _t315*(_t75 * _t75) - (_t32 * _t32 * _t32 * _t32)*_t628 - _t608*_t629 + _t608*_t630 + _t635*_t636 - _t635*_t637 - _t642*_t645 - _t642*(-_t244 + _t643*_t72) - _t642*(-_t640 + _t641*_t72) - _t647*_t89 - _t647*(_t640 - _t646)) + _t610 - 0.1729e4 / 0.648e3*_t611 + (0.91e2 / 0.72e2)*_t613 + (0.91e2 / 0.72e2)*_t614 - _t615*_t617 - _t615*_t620 - _t615*_t627 + _t616*_t625*_t84 + _t619*_t625 + _t623*(-0.2e1*_t39 - 0.2e1*_t40)) + _hc3[2]*_t608 + _t101*_t706 + 0.3e1*_t106*_t253 - _t209*_t707 - _t26*(_hc0[4]*_t218 + _t211*_t292 + _t259*_t288 - _t26*(_hc0[8]*_t75 - _t26*(_hc0[13]*_t32 + _t712) + _t32*_t653 + _t711) + _t32*_t656 + _t710) - _t26*(_hc3[7]*_t253 + _hc3[8]*_t218 + _t211*_t296 - _t26*(_hc3[17]*_t94 + _hc3[18]*_t75 - _t26*(_hc3[32]*_t44 + _hc3[33]*_t32 + _t715) + _t32*_t662 + _t44*_t691 + _t714) + _t266*_t288 + _t280*_t289 + _t32*_t669 + _t44*_t697 + _t713) + _t262*_t705 + _t273*_t705 + 0.3e1*_t286*_t94 + _t293*_t716 + _t297*_t716 + _t32*(_hc0[3]*_t218 + _t211*_t259 - _t26*_t656 + _t261*_t288 + _t32*(_hc0[6]*_t75 - _t26*_t655 + _t32*(_hc0[10]*_t32 + _t658) + _t657) + _t650) + _t32*(_hc3[5]*_t253 + _hc3[6]*_t218 + _t211*_t266 - _t26*_t669 + _t268*_t288 + _t272*_t289 + _t32*(_hc3[12]*_t94 + _hc3[13]*_t75 - _t26*_t664 + _t32*(_hc3[23]*_t44 + _hc3[24]*_t32 + _t671) + _t44*_t675 + _t670) + _t44*_t683 + _t659) + _t44*(_t211*_t280 - _t26*_t697 + _t272*_t288 + _t284*_t289 + _t32*_t683 + _t44*(-_t26*_t695 + _t32*_t681 + _t44*(_t700 + _t701 + _t702) + _t698 + _t699 + _t703) + _t684 + _t685 + _t704) + _t706*_t98 - _t707*_t708 + _t718) + _t101*_t719 + 0.8e1*_t106*_t94 + _t209*_t721 + 0.4e1*_t219 + 0.4e1*_t254 + 0.4e1*_t255 + 0.4e1*_t263 + 0.4e1*_t274 + 0.4e1*_t287 - _t293*_t720 - _t297*_t720 + _t708*_t721 + _t719*_t98 + _t723;
  const double d4F_dna3_dnb = _t1*(_hc0[1]*_t724 + _hc3[1]*(-_t116*_t617 - _t116*_t620 - _t116*_t627 + _t118*_t252 + _t124*_t228*_t230*_t84 - _t140*_t234 - _t221*_t318 - _t225*_t725 - _t225*_t733 - _t225*_t734 - _t225*_t740 + _t228*_t320*_t379 + _t231*(0.3e1*_hc2[2]*_t72*_t8 - 0.3e1*_t119 - 0.3e1 / 0.2e1*_t121 - 0.3e1 / 0.2e1*_t123) + _t232*_t233*_t317 + _t235*_t319 + _t235*_t321*_t379 + _t236*(0.4e1*_hc2[5]*_t31*_t72*_t8 - _t122*_t246 - _t305 - _t306 - _t310 - _t314 - _t366*_t75 - _t738*_t89) + _t54*(_hc2[5]*_t249*_t72*_t8 + _hc2[5]*_t72*_t8*_t89 + 0.3e1*_hc2[9]*_t72*_t8*_t91 - _t217*_t308 - _t218*_t316 - _t238*_t312*_t628 - _t241*_t48*_t631 - _t247*_t727 - _t247*_t732 - _t249*_t730 - _t302*_t637 - _t303*_t636 - _t313*_t728 - _t629*_t724 + _t630*_t724 + _t636*_t729 - _t637*_t729 - _t727*_t75 - _t730*_t89 - _t732*_t75) - 0.1729e4 / 0.864e3*_t611 + (0.91e2 / 0.144e3)*_t613 + (0.91e2 / 0.144e3)*_t614 + _t623*_t743 - _t735*_t736 + _t737*_t93 + _t742*_t93 + _t746) + _hc3[2]*_t724 + _t101*_t787 + _t125*_t286 + _t127*_t218 + _t129*_t218 + _t133*_t253 - _t135*_t648 - _t136*_t648 - _t209*_t789 + _t256*_t293 + _t256*_t297 - _t26*(_hc0[4]*_t303 + _t256*_t292 + _t256*_t356 + _t259*_t74 - _t26*(_hc0[8]*_t74 + _t32*_t748 + _t790) + _t32*_t750 + _t330*_t75 + _t710) - _t26*(_hc3[7]*_t326 + _hc3[8]*_t303 + _t125*_t280 + _t256*_t296 + _t256*_t359 - _t26*(_hc3[17]*_t125 + _hc3[18]*_t74 + _t32*_t757 + _t44*_t778 + _t791) + _t266*_t74 + _t32*_t759 + _t338*_t75 + _t350*_t94 + _t44*_t780 + _t713) + _t262*_t74 + _t273*_t74 + _t288*_t332 + _t288*_t340 + _t289*_t352 + _t32*(_hc0[3]*_t303 + _t256*_t259 + _t256*_t330 - _t26*_t750 + _t261*_t74 + _t32*(_hc0[6]*_t74 + _t32*_t751 + _t752) + _t329*_t75 + _t650) + _t32*(_hc3[5]*_t326 + _hc3[6]*_t303 + _t125*_t272 + _t256*_t266 + _t256*_t338 - _t26*_t759 + _t268*_t74 + _t32*(_hc3[12]*_t125 + _hc3[13]*_t74 + _t32*_t760 + _t44*_t763 + _t764) + _t334*_t75 + _t337*_t94 + _t44*_t770 + _t659) + _t326*_t788 + _t44*(_t125*_t284 + _t256*_t280 + _t256*_t350 - _t26*_t780 + _t272*_t74 + _t32*_t770 + _t337*_t75 + _t347*_t94 + _t44*(_hc3[11]*_t74 + _t32*_t768 + _t44*_t784 + _t781 + _t785) + _t684 + _t771 + _t786) - _t708*_t789 + _t787*_t98 + _t792) + _t101*_t646 + _t135*_t716 + _t136*_t716 + _t209*_t793 + _t298 - _t299*_t358 - _t299*_t361 + 0.3e1*_t304 + 0.3e1*_t327 + 0.3e1*_t328 + 0.3e1*_t333 + 0.3e1*_t341 + 0.3e1*_t342 + 0.3e1*_t343 + 0.3e1*_t353 + 0.3e1*_t354 + 0.3e1*_t355 + _t646*_t98 + _t708*_t793 + _t723;
  const double d4F_dna2_dnb2 = -_hc0[1]*_t245 - _hc0[1]*_t634 - _hc3[2]*_t245 - _hc3[2]*_t634 + _t1*(_hc3[1]*(_t124*_t737 + _t124*_t742 - _t140*_t725 - _t140*_t733 - _t140*_t734 - _t140*_t740 - _t140*_t802 + _t226*_t795 + _t227*_t795 + _t231*_t800 + _t236*(0.6e1*_hc1[2]*_t214*_t8 + 0.2e1*_hc1[2]*_t72 - _hc2[2]*_t216 - _hc2[2]*_t73 + 0.4e1*_hc2[5]*_t48*_t72*_t8 - _t246*_t366 - _t367 - _t369 - _t372 - _t373) + _t317*_t377 + _t320*_t801 + _t321*_t622*_t743 + _t364*_t795 + _t374*_t83*_t84 + _t376*_t795 + _t399*_t93 + _t400*_t93 + _t54*(0.6e1*_hc1[5]*_t214*_t32*_t8 + 0.2e1*_hc1[5]*_t32*_t72 - _hc1[5]*_t806 - _hc2[5]*_t806 + 0.4e1*_hc2[9]*_t31*_t48*_t72*_t8 - _t120*_t216 - _t120*_t73 - _t138*_t638 - _t141*_t631*_t91 - _t144*_t639 - _t144*_t647 - _t146*_t628*_t87 - _t246*_t731 - _t302*_t738 - _t303*_t366 - _t642*_t803 - _t645*_t804 - _t805*_t89 - _t807) + _t610 - 0.1729e4 / 0.1296e4*_t611 - _t615*_t799 - _t735*_t796 + (0.91e2 / 0.108e3)*_t744 + (0.91e2 / 0.108e3)*_t745 - 0.1729e4 / 0.1296e4*_t794 - _t796*_t797 - _t796*_t798) - _t101*_t216 - _t101*_t73 + _t106*_t381 - _t111*_t648 + _t127*_t787 + _t129*_t787 - _t135*_t826 - _t136*_t826 - _t207*_t209 - _t216*_t98 + _t246*_t332 + _t246*_t340 + _t256*_t392 + _t256*_t393 - _t26*(-_hc0[4]*_t216 - _hc0[4]*_t73 + (0.4e1 / 0.9e1)*_t2*_t356*_t4*_t67 + _t32*_t808 + 0.4e1*_t330*_t72*_t8 - _t709 - _t827) - _t26*(_hc3[7]*_t381 - _hc3[8]*_t216 - _hc3[8]*_t73 + _t246*_t338 + _t32*_t816 + _t350*_t815 + _t44*_t824 + _t828) + _t32*(-_hc0[3]*_t216 - _hc0[3]*_t73 + (0.4e1 / 0.9e1)*_t2*_t330*_t4*_t67 + _t32*_t810 + 0.4e1*_t329*_t72*_t8 - _t649 - _t809) + _t32*(_hc3[5]*_t381 - _hc3[6]*_t216 - _hc3[6]*_t73 + _t246*_t334 + _t32*_t811 + _t337*_t815 + _t44*_t814 + _t817) + _t326*_t391 + _t352*_t815 + _t383*_t75 + _t385*_t75 + _t389*_t94 + _t44*(-_hc3[5]*_t216 - _hc3[5]*_t73 + _t246*_t337 + _t32*_t814 + _t347*_t815 + _t44*_t821 + _t818 + _t825) - _t73*_t98 + _t792 + _t829) + _t101*_t246 + _t127*_t831 + _t129*_t831 + _t212 + _t246*_t98 + 0.2e1*_t304 + 0.2e1*_t327 + 0.2e1*_t328 + 0.2e1*_t333 + 0.2e1*_t341 + 0.2e1*_t342 + 0.2e1*_t343 + 0.2e1*_t353 + 0.2e1*_t354 + 0.2e1*_t355 - _t358*_t362 - _t361*_t362 - _t362*_t392 - _t362*_t393 + 0.2e1*_t382 + 0.2e1*_t384 + 0.2e1*_t386 + 0.2e1*_t390 + _t723 + 0.4e1*_t830 + _t832*_t833 + _t833*_t834;
  const double d4F_dna_dnb3 = -_hc0[1]*_t213 - _hc0[1]*_t856 - _hc3[2]*_t213 - _hc3[2]*_t856 + _t1*(_hc0[1]*_t633 + _hc3[1]*(-_t116*_t835 - _t116*_t839 - _t116*_t844 + _t124*_t841 + _t124*_t845 - _t140*_t838 - _t221*_t80 - 0.7e1 / 0.12e2*_t224*_t799 - _t225*_t802 + _t236*_t842 + _t374*_t840 + _t378*_t801 + _t379*_t846 + _t41*_t847 + _t54*(-_hc1[2]*_t215 + 0.9e1*_hc1[5]*_t214*_t49*_t8 + 0.3e1*_hc1[5]*_t49*_t72 + 0.6e1*_hc2[2]*_t214 + 0.3e1*_hc2[5]*_t144*_t72*_t8 + 0.3e1*_hc2[9]*_t141*_t72*_t8 - _t138*_t732 - _t144*_t730 - _t31*_t401*_t631 - 0.9e1*_t365*_t738 - _t370*_t405*_t628 - _t371*_t728 - _t396*_t637 - _t397*_t636 - _t407*_t732 - _t408*_t730 - 0.3e1*_t72*_t738 - _t727*_t836 - _t807) - _t736*_t797 - _t736*_t798 + _t746 - 0.1729e4 / 0.864e3*_t794 + (0.91e2 / 0.144e3)*_t837 + (0.91e2 / 0.144e3)*_t843) + _hc3[2]*_t633 + _t125*_t855 - _t127*_t213 - _t127*_t856 - _t129*_t213 - _t129*_t856 + _t32*_t848 + _t32*_t850 + _t381*_t854 + _t383*_t646 + _t385*_t646 + _t44*_t853 + _t829 + _t857) + _t127*_t858 + _t129*_t858 + 0.3e1*_t382 + 0.3e1*_t384 + 0.3e1*_t386 + 0.3e1*_t390 + _t417 + 0.6e1*_t830 + _t859;
  const double d4F_dnb4 = _t1*(_hc0[1]*_t860 + _hc3[1]*(_t148*_t841 + _t148*_t845 + _t230*_t53*_t846 + _t378*_t53*_t741 + _t409*_t840 + _t53*_t83*_t842 + _t53*_t847 + _t54*(-(_t138 * _t138)*_t315 - _t138*_t315*_t407 - (_t144 * _t144)*_t307 - _t144*_t307*_t408 - _t144*_t805 - _t308*_t861 + _t316*_t861 - _t366*_t397 - _t396*_t738 - _t408*_t805 - (_t48 * _t48 * _t48 * _t48)*_t631 - (_t49 * _t49 * _t49 * _t49)*_t628 - _t629*_t860 + _t630*_t860 - _t803*_t804 - _t804*(_t244 + _t643*_t72) - _t804*(_t640 + _t641*_t72) - _t805*(-_t640 - _t646)) + _t610 - _t615*_t835 - _t615*_t839 - _t615*_t844 - _t618*_t838 - 0.1729e4 / 0.648e3*_t794 + (0.91e2 / 0.72e2)*_t837 + (0.91e2 / 0.72e2)*_t843) + _hc3[2]*_t860 + _t127*_t862 + _t129*_t862 + _t149*_t855 + _t383*_t836 + _t385*_t836 + _t410*_t854 + _t49*_t848 + _t49*_t850 + _t55*_t853 + _t857) + _t127*_t863 + _t129*_t863 + 0.8e1*_t133*_t149 + 0.4e1*_t398 + 0.4e1*_t411 + 0.4e1*_t412 + 0.4e1*_t413 + 0.4e1*_t414 + 0.4e1*_t415 + _t859;
  const double d4F_dna3_dgaa = _t900;
  const double d4F_dna3_dgab = _t1*(_hc3[1]*(_t617*_t905 + (0.91e2 / 0.144e3)*_t870 - 0.7e1 / 0.24e2*_t872 - 0.7e1 / 0.24e2*_t874 + (0.1e1 / 0.6e1)*_t876 + (0.1e1 / 0.12e2)*_t877 + (0.1e1 / 0.12e2)*_t878 + _t904) + _t179*_t286 + _t183*_t685 + _t183*_t704 + _t211*_t465 - _t26*(_hc3[7]*_t453 + _t179*_t280 + _t183*_t687 + _t183*_t696 - _t26*(_hc3[17]*_t179 + _t183*_t689 + _t183*_t690 + _t908) + _t32*_t910 + _t44*_t913 + _t907) + _t288*_t457 + _t289*_t461 + _t32*(_hc3[5]*_t453 + _t179*_t272 + _t183*_t677 + _t183*_t682 - _t26*_t910 + _t32*(_hc3[12]*_t179 + _t183*_t673 + _t183*_t674 + _t915) + _t44*_t918 + _t914) + _t44*(_t179*_t284 + _t183*_t699 + _t183*_t703 - _t26*_t913 + _t32*_t918 + _t44*(_t183*_t701 + _t183*_t702 + _t921 + _t922) + _t919 + _t920) + _t453*_t788 + _t903) + _t276*_t902 + _t285*_t902 - _t299*_t465 + 0.3e1*_t454 + 0.3e1*_t458 + 0.3e1*_t462 + 0.3e1*_t463 + _t901;
  const double d4F_dna3_dgbb = _t900;
  const double d4F_dna2_dnb_dgaa = _t943;
  const double d4F_dna2_dnb_dgab = _t1*(_hc3[1]*(-_t36*_t871 - _t36*_t873 + _t733*_t905 + _t734*_t905 + _t740*_t905 + (0.91e2 / 0.216e3)*_t870 + _t905*_t925 + (0.1e1 / 0.12e2)*_t924 + _t944 + _t945) + _t106*_t484 + _t125*_t461 + _t133*_t453 + _t179*_t352 + _t183*_t771 + _t183*_t786 + _t256*_t465 + _t256*_t492 - _t26*(_hc3[15]*_t949 + _hc3[7]*_t484 + _t179*_t350 + _t183*_t772 + _t32*_t946 + _t44*_t948 + _t950) + _t32*(_hc3[12]*_t949 + _hc3[5]*_t484 + _t179*_t337 + _t183*_t765 + _t32*_t951 + _t44*_t953 + _t954) + _t44*(_hc3[11]*_t949 + _t179*_t347 + _t183*_t781 + _t32*_t953 + _t44*_t957 + _t955 + _t958) + _t457*_t74 + _t486*_t75 + _t489*_t94 + _t903) - _t362*_t492 + _t466 + _t901 + _t960;
  const double d4F_dna2_dnb_dgbb = _t943;
  const double d4F_dna_dnb2_dgaa = _t972;
  const double d4F_dna_dnb2_dgab = _t1*(_hc3[1]*(-_t36*_t961 - _t36*_t963 + _t799*_t974 + _t905*_t964 + _t905*_t965 + _t923 + _t945 + (0.1e1 / 0.12e2)*_t962 + (0.91e2 / 0.216e3)*_t973) + _t179*_t389 + _t183*_t818 + _t246*_t486 + _t32*_t975 + _t391*_t484 + _t44*_t977 + _t489*_t815 - _t496 - 0.1e1 / 0.2e1*_t969 + _t978) + _t512 + _t960 + _t979;
  const double d4F_dna_dnb2_dgbb = _t972;
  const double d4F_dnb3_dgaa = _t983;
  const double d4F_dnb3_dgab = _t1*(_hc3[1]*(_t838*_t974 + _t839*_t905 + _t844*_t905 + _t904 + (0.91e2 / 0.144e3)*_t973 - 0.7e1 / 0.24e2*_t980 - 0.7e1 / 0.24e2*_t981 + (0.1e1 / 0.12e2)*_t982) + _t183*_t851 + _t183*_t852 + _t192*_t389 + _t391*_t507 + _t416*_t486 + _t489*_t849 + _t49*_t975 + _t55*_t977 + _t978) + _t387*_t902 + _t388*_t902 + 0.3e1*_t508 + 0.3e1*_t509 + 0.3e1*_t510 + 0.3e1*_t511 + _t979;
  const double d4F_dnb3_dgbb = _t983;
  const double d4F_dna2_dgaa2 = _t1007;
  const double d4F_dna2_dgaa_dgab = _t1018;
  const double d4F_dna2_dgaa_dgbb = _t1007;
  const double d4F_dna2_dgab2 = _t1*(_hc3[1]*(-_t1019 + (0.7e1 / 0.36e2)*_t17*_t18*_t199*_t35*_t38*_t41 - 0.1e1 / 0.12e2*_t986 - 0.1e1 / 0.12e2*_t987) + _t1026*_t461 + _t1028 + _t106*_t561 - _t26*(_hc3[7]*_t561 + _t1027 - _t278*_t582 - _t279*_t582 + _t449*_t912 + _t555*_t693 + _t555*_t694) - _t276*_t582 - _t285*_t582 + _t32*(_hc3[5]*_t561 + _t1022 - _t270*_t582 - _t271*_t582 + _t449*_t917 + _t555*_t679 + _t555*_t680) + _t44*(_t1023 + _t1025 - _t282*_t582 - _t283*_t582 + _t449*_t922 + _t555*_t701 + _t555*_t702) + _t449*_t920 + _t555*_t699 + _t555*_t703) - _t1029*_t450 - _t1029*_t527 + _t1030*_t460 + _t1031*_t282 + _t1031*_t283 + _t1032 + 0.2e1*_t562;
  const double d4F_dna2_dgab_dgbb = _t1018;
  const double d4F_dna2_dgbb2 = _t1007;
  const double d4F_dna_dnb_dgaa2 = _t1045;
  const double d4F_dna_dnb_dgaa_dgab = _t1051;
  const double d4F_dna_dnb_dgaa_dgbb = _t1045;
  const double d4F_dna_dnb_dgab2 = _t1*(_hc3[1]*(-_t1009 - _t1019 - 0.1e1 / 0.12e2*_t1033 - 0.1e1 / 0.12e2*_t1034 - _t1052) + _t1026*_t489 - _t1029*_t1040 + (0.1e1 / 0.24e2)*_t1042 + _t1053*_t32 + _t1055*_t44 + _t1056 + _t133*_t561 - _t344*_t582 + _t449*_t955 + _t555*_t781) + _t1032 + _t553 + _t554 + _t556 + _t557 + _t563 + _t583 + _t584 + _t585 + _t586 + _t590;
  const double d4F_dna_dnb_dgab_dgbb = _t1051;
  const double d4F_dna_dnb_dgbb2 = _t1045;
  const double d4F_dnb2_dgaa2 = _t1061;
  const double d4F_dnb2_dgaa_dgab = _t1062;
  const double d4F_dnb2_dgaa_dgbb = _t1061;
  const double d4F_dnb2_dgab2 = _t1*(_hc3[1]*(-_t1019 - 0.1e1 / 0.12e2*_t1057 - 0.1e1 / 0.12e2*_t1058 + (0.7e1 / 0.36e2)*_t17*_t18*_t199*_t35*_t38*_t53) + _t1053*_t49 + _t1055*_t55 + _t1056 + _t133*_t588 + 0.2e1*_t192*_t489 - _t387*_t582 - _t388*_t582 + _t449*_t976 + _t555*_t819 + _t555*_t820) + _t1030*_t488 + _t1031*_t345 + _t1031*_t346 + _t1032 - _t1063*_t131 - _t1063*_t132 + 0.2e1*_t589;
  const double d4F_dnb2_dgab_dgbb = _t1062;
  const double d4F_dnb2_dgbb2 = _t1061;
  const double d4F_dna_dgaa3 = _t1086;
  const double d4F_dna_dgaa2_dgab = _t1095;
  const double d4F_dna_dgaa2_dgbb = _t1086;
  const double d4F_dna_dgaa_dgab2 = _t1102;
  const double d4F_dna_dgaa_dgab_dgbb = _t1095;
  const double d4F_dna_dgaa_dgbb2 = _t1086;
  const double d4F_dna_dgab3 = _t1*(_hc3[1]*((0.1e1 / 0.4e1)*_t1088 + _t1103) + _t1023*_t902 - _t1104*_t460 - _t1105*_t282 - _t1105*_t283 + _t1106*_t450 + _t1106*_t527 + _t1107*_t922 + _t1108*_t701 + _t1108*_t702 + _t1109) + _t1110;
  const double d4F_dna_dgab2_dgbb = _t1102;
  const double d4F_dna_dgab_dgbb2 = _t1095;
  const double d4F_dna_dgbb3 = _t1086;
  const double d4F_dnb_dgaa3 = _t1113;
  const double d4F_dnb_dgaa2_dgab = _t1117;
  const double d4F_dnb_dgaa2_dgbb = _t1113;
  const double d4F_dnb_dgaa_dgab2 = _t1119;
  const double d4F_dnb_dgaa_dgab_dgbb = _t1117;
  const double d4F_dnb_dgaa_dgbb2 = _t1113;
  const double d4F_dnb_dgab3 = _t1*(_hc3[1]*(_t1103 + (0.1e1 / 0.4e1)*_t1114) + _t1054*_t902 - _t1104*_t488 - _t1105*_t345 - _t1105*_t346 + _t1107*_t956 + _t1108*_t782 + _t1108*_t783 + _t1109 + _t1120*_t131 + _t1120*_t132) + _t1110;
  const double d4F_dnb_dgab2_dgbb = _t1119;
  const double d4F_dnb_dgab_dgbb2 = _t1117;
  const double d4F_dnb_dgbb3 = _t1113;
  const double d4F_dgaa4 = _t1127;
  const double d4F_dgaa3_dgab = _t1128;
  const double d4F_dgaa3_dgbb = _t1127;
  const double d4F_dgaa2_dgab2 = _t1129;
  const double d4F_dgaa2_dgab_dgbb = _t1128;
  const double d4F_dgaa2_dgbb2 = _t1127;
  const double d4F_dgaa_dgab3 = _t1130;
  const double d4F_dgaa_dgab2_dgbb = _t1129;
  const double d4F_dgaa_dgab_dgbb2 = _t1128;
  const double d4F_dgaa_dgbb3 = _t1127;
  const double d4F_dgab4 = (0.1e1 / 0.768e3)*_hc3[20]*_t1121*_t1122*_t229*_t513*_t594 + (0.5e1 / 0.16e2)*_hc3[4]*_t1125*_t197*_t24*_t3*_t38 - _t1066*_t1123 - 0.5e1 / 0.4e1*_t1126;
  const double d4F_dgab3_dgbb = _t1130;
  const double d4F_dgab2_dgbb2 = _t1129;
  const double d4F_dgab_dgbb3 = _t1128;
  const double d4F_dgbb4 = _t1127;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 1] += d4F_dna3_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 2] += d4F_dna3_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 3] += d4F_dna2_dnb_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 4] += d4F_dna2_dnb_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 5] += d4F_dna2_dnb_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 6] += d4F_dna_dnb2_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 7] += d4F_dna_dnb2_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 8] += d4F_dna_dnb2_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 9] += d4F_dnb3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 10] += d4F_dnb3_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 1] += d4F_dna2_dgaa_dgab;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 2] += d4F_dna2_dgaa_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 3] += d4F_dna2_dgab2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 4] += d4F_dna2_dgab_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 5] += d4F_dna2_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 6] += d4F_dna_dnb_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 7] += d4F_dna_dnb_dgaa_dgab;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 8] += d4F_dna_dnb_dgaa_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 9] += d4F_dna_dnb_dgab2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 10] += d4F_dna_dnb_dgab_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 11] += d4F_dna_dnb_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 12] += d4F_dnb2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 13] += d4F_dnb2_dgaa_dgab;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 14] += d4F_dnb2_dgaa_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 15] += d4F_dnb2_dgab2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 16] += d4F_dnb2_dgab_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 1] += d4F_dna_dgaa2_dgab;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 2] += d4F_dna_dgaa2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 3] += d4F_dna_dgaa_dgab2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 4] += d4F_dna_dgaa_dgab_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 5] += d4F_dna_dgaa_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 6] += d4F_dna_dgab3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 7] += d4F_dna_dgab2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 8] += d4F_dna_dgab_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 9] += d4F_dna_dgbb3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 10] += d4F_dnb_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 11] += d4F_dnb_dgaa2_dgab;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 12] += d4F_dnb_dgaa2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 13] += d4F_dnb_dgaa_dgab2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 14] += d4F_dnb_dgaa_dgab_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 15] += d4F_dnb_dgaa_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 16] += d4F_dnb_dgab3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 17] += d4F_dnb_dgab2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 18] += d4F_dnb_dgab_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 1] += d4F_dgaa3_dgab;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 2] += d4F_dgaa3_dgbb;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 3] += d4F_dgaa2_dgab2;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 4] += d4F_dgaa2_dgab_dgbb;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 5] += d4F_dgaa2_dgbb2;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 6] += d4F_dgaa_dgab3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 7] += d4F_dgaa_dgab2_dgbb;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 8] += d4F_dgaa_dgab_dgbb2;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 9] += d4F_dgaa_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 10] += d4F_dgab4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 11] += d4F_dgab3_dgbb;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 12] += d4F_dgab2_dgbb2;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 13] += d4F_dgab_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
#endif
#endif
}
#endif