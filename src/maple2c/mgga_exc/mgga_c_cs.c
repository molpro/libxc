/*
  Generated from python/mgga_exc/mgga_c_cs.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_c_cs
*/

#ifndef _MGGA_C_CS_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_C_CS_KERNEL_BODY
#define _KMAX 0
#define _MGGA_C_CS_HELPER_BODIES
#include "mgga_c_cs.c"
#undef _MGGA_C_CS_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_C_CS_HELPER_BODIES
#include "mgga_c_cs.c"
#undef _MGGA_C_CS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_C_CS_HELPER_BODIES
#include "mgga_c_cs.c"
#undef _MGGA_C_CS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_C_CS_HELPER_BODIES
#include "mgga_c_cs.c"
#undef _MGGA_C_CS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_C_CS_HELPER_BODIES
#include "mgga_c_cs.c"
#undef _MGGA_C_CS_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_c_cs.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_c_cs.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_c_cs.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_c_cs.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_c_cs.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_c_cs.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_c_cs.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_c_cs.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_c_cs.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_c_cs.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_C_CS_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(cs_thf_k, _KMAX)(const xc_func_type *p, double z, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.8e1 / 0.3e1, _hc0);
  const double _t1 = t - 0.1e1 / 0.8e1*u;
  const double _t2 = M_CBRT2;
  const double _t3 = _t2*(_hc0[0] + 0.1e1);
  const double _t4 = (0.1e1 / 0.8e1)*_t3;
#if _KMAX >= 1
  const double _t5 = _hc0[2]*_t2;
  const double _t6 = (0.1e1 / 0.8e1)*_t5;
#endif
#if _KMAX >= 2
  const double _t7 = _hc0[5]*_t2;
  const double _t8 = (0.1e1 / 0.8e1)*_t7;
#endif
#if _KMAX >= 3
  const double _t9 = _hc0[9]*_t2;
  const double _t10 = (0.1e1 / 0.8e1)*_t9;
#endif

  const double f = _t1*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t4;
  out[1] = df_dt;
  const double df_du = -0.1e1 / 0.64e2*_t3;
  out[2] = df_du;
  const double df_dz = _t1*_t6;
  out[3] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dz_dt = _t6;
  out[7] = d2f_dz_dt;
  const double d2f_dz_du = -0.1e1 / 0.64e2*_t5;
  out[8] = d2f_dz_du;
  const double d2f_dz2 = _t1*_t8;
  out[9] = d2f_dz2;
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
  const double d3f_dz_dt2 = 0;
  out[14] = d3f_dz_dt2;
  const double d3f_dz_du_dt = 0;
  out[15] = d3f_dz_du_dt;
  const double d3f_dz_du2 = 0;
  out[16] = d3f_dz_du2;
  const double d3f_dz2_dt = _t8;
  out[17] = d3f_dz2_dt;
  const double d3f_dz2_du = -0.1e1 / 0.64e2*_t7;
  out[18] = d3f_dz2_du;
  const double d3f_dz3 = _t1*_t10;
  out[19] = d3f_dz3;
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
  const double d4f_dz_dt3 = 0;
  out[25] = d4f_dz_dt3;
  const double d4f_dz_du_dt2 = 0;
  out[26] = d4f_dz_du_dt2;
  const double d4f_dz_du2_dt = 0;
  out[27] = d4f_dz_du2_dt;
  const double d4f_dz_du3 = 0;
  out[28] = d4f_dz_du3;
  const double d4f_dz2_dt2 = 0;
  out[29] = d4f_dz2_dt2;
  const double d4f_dz2_du_dt = 0;
  out[30] = d4f_dz2_du_dt;
  const double d4f_dz2_du2 = 0;
  out[31] = d4f_dz2_du2;
  const double d4f_dz3_dt = _t10;
  out[32] = d4f_dz3_dt;
  const double d4f_dz3_du = -0.1e1 / 0.64e2*_t9;
  out[33] = d4f_dz3_du;
  const double d4f_dz4 = (0.1e1 / 0.8e1)*_hc0[14]*_t1*_t2;
  out[34] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(cs_thf_z0_k, _KMAX)(const xc_func_type *p, double u, double t, double *out) {

  const double _t1 = M_CBRT2;
  const double _t2 = (0.1e1 / 0.8e1)*_t1;

  const double f = _t2*(t - 0.1e1 / 0.8e1*u);
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t2;
  out[1] = df_dt;
  const double df_du = -0.1e1 / 0.64e2*_t1;
  out[2] = df_du;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[3] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[4] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[5] = d2f_du2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[6] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[7] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[8] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[9] = d3f_du3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[10] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[11] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[12] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[13] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[14] = d4f_du4;
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

  const double _t1 = xc_powr(na, -5, 3);
  const double _t2 = xc_powr(0.2e1, 2, 3);
  const double _t3 = _t1*_t2;
  const double _t4 = xc_powr(na, -8, 3);
  const double _t5 = (0.1e1 / 0.8e1)*_t1;
  const double _t7 = xc_powr(na, -1, 3);
  const double _t8 = exp(-0.25329999999999997*_t7);
  const double _t9 = 0.26400000000000001*_t8;
  const double _t11 = 0.34899999999999998*_t7 + 0.1e1;
  const double _t12 = (0.1e1 / _t11);
  const double _t13 = 0.049180000000000001*_t12;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(cs_thf_z0_k, _KMAX)(p, _t3*la, _t3*ta, _hc0);
  const double _t6 = 0.2e1*_hc0[0] - 0.1e1 / 0.8e1*_t4*gaa + _t5*la;
  const double _t10 = _t6*_t9 + 0.1e1;
  const double _t14 = _t10*_t13;
  const double zk = -_t14;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t15 = (0.1e1 / (_t11 * _t11));
  const double _t16 = _t15*_t7;
  const double _t17 = xc_powr(na, -4, 3);
  const double _t18 = _t17*_t8;
  const double _t19 = 0.022290399999999998*_t18;
  const double _t20 = xc_powr(na, -11, 3);
  const double _t21 = (0.5e1 / 0.24e2)*_t4;
  const double _t22 = (0.10e2 / 0.3e1)*_t4;
  const double _t29 = _t13*na;
  const double _t30 = _t12*_t8;
  const double _t31 = 0.0016229400000000002*_t30;
  const double _t34 = 0.025967040000000004*_t30;
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(cs_thf_z0_k, _KMAX)(p, 0, 0, _hc1);
  const double _t23 = _hc1[1]*_t2;
  const double _t24 = _t23*ta;
  const double _t25 = _hc1[2]*_t2;
  const double _t26 = _t22*_t25;
  const double _t27 = (0.1e1 / 0.3e1)*_t20*gaa - _t21*la - _t22*_t24 - _t26*la;
  const double _t28 = _t19*_t6 + _t27*_t9;
  const double _t32 = 0.2e1*_hc1[2]*_t3 + _t5;
  const double _t33 = 0.012983520000000002*_t30*_t32;
  const double dF_dna = -0.005721273333333333*_t10*_t16 - _t14 - _t28*_t29;
  const double dF_dgaa = _t1*_t31;
  const double dF_dla = -_t33*na;
  const double dF_dta = -_t23*_t34/xc_powr(na, 2, 3);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  const double _t35 = (0.1e1 / (_t11 * _t11 * _t11));
  const double _t38 = 0.098360000000000003*_t12;
  const double _t41 = 0.0018820527733333329*_t4;
  const double _t42 = xc_powr(na, -7, 3);
  const double _t43 = 0.02972053333333333*_t42;
  const double _t44 = xc_powr(na, -14, 3);
  const double _t45 = (0.5e1 / 0.9e1)*_t20;
  const double _t46 = (0.80e2 / 0.9e1)*_t20;
  const double _t49 = 0.044580799999999997*_t18;
  const double _t51 = (0.1e1 / (na * na * na));
  const double _t52 = _t51*_t8;
  const double _t53 = _t15*_t52;
  const double _t54 = (0.1e1 / (na * na * na * na));
  const double _t55 = _t54*_t8;
  const double _t56 = 0.087999999999999995*_t20*_t8 - 0.0027862999999999998*_t55;
  const double _t36 = _t10*_t35;
  const double _t37 = _t10*_t15;
  const double _t39 = 0.011442546666666666*_t28;
  const double _t40 = _t6*_t8;
  const double _t47 = _t25*_t46;
  const double _t48 = _t24*_t46 - 0.11e2 / 0.9e1*_t44*gaa + _t45*la + _t47*la;
  const double _t50 = _t27*_t49 + _t40*_t41 - _t40*_t43 + _t48*_t9;
  const double _t57 = _t32*_t8;
  const double _t58 = -_t21 - _t26;
  const double _t59 = _t19*_t32 + _t58*_t9;
  const double _t60 = _t23*_t8;
  const double _t61 = 0.044580799999999997*_t23*_t52 - 0.88000000000000012*_t4*_t60;
  const double d2F_dna2 = -0.0013311495955555552*_t1*_t36 - _t16*_t39 - 0.0038141822222222221*_t17*_t37 - _t28*_t38 - _t29*_t50;
  const double d2F_dna_dgaa = -_t29*_t56 + _t31*_t4 + 0.00018880201999999999*_t53;
  const double d2F_dna_dla = -0.0015104161599999999*_t16*_t57 - _t29*_t59 - _t33;
  const double d2F_dna_dta = -_hc1[1]*_t3*_t34 - 0.0030208323199999998*_t15*_t60/(na * na) - _t29*_t61;
  const double d2F_dla2 = 0;
  const double d2F_dla_dta = 0;
  const double d2F_dta2 = 0;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
  if(out->v2lapltau != NULL) out->v2lapltau[ip*p->dim.v2lapltau + 0] += d2F_dla_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
#endif
#if _KMAX >= 3
  const double _t62 = (0.1e1 / (_t11 * _t11 * _t11 * _t11));
  const double _t63 = 0.003993448786666666*_t1;
  const double _t64 = _t15*_t17;
  const double _t65 = 0.14754*_t12;
  const double _t66 = 0.01716382*_t16;
  const double _t67 = 0.0001589079891617777*_t55;
  const double _t68 = _t20*_t8;
  const double _t69 = 0.0075282110933333306*_t68;
  const double _t70 = xc_powr(na, -10, 3);
  const double _t71 = 0.069347911111111105*_t70;
  const double _t72 = xc_powr(na, -17, 3);
  const double _t73 = (0.55e2 / 0.27e2)*_t44;
  const double _t74 = (0.880e3 / 0.27e2)*_t44;
  const double _t78 = 0.0056461583199999988*_t4;
  const double _t79 = 0.089161599999999994*_t42;
  const double _t80 = 0.066871199999999992*_t18;
  const double _t82 = xc_powr(na, -13, 3);
  const double _t83 = 0.011442546666666666*_t16;
  const double _t84 = _t8/xc_powr(na, 16, 3);
  const double _t85 = xc_powi(na, -5);
  const double _t86 = _t44*_t8;
  const double _t87 = 0.018575333333333333*_t8*_t85 - 0.00023525659666666661*_t84 - 0.32266666666666671*_t86;
  const double _t88 = _t35*_t8;
  const double _t75 = _t25*_t74;
  const double _t76 = -_t24*_t74 + (0.154e3 / 0.27e2)*_t72*gaa - _t73*la - _t75*la;
  const double _t77 = _t27*_t8;
  const double _t81 = _t40*_t71 + _t48*_t80 + _t6*_t67 - _t6*_t69 + _t76*_t9 + _t77*_t78 - _t77*_t79;
  const double _t89 = _t45 + _t47;
  const double _t90 = _t41*_t57 - _t43*_t57 + _t49*_t58 + _t89*_t9;
  const double _t91 = -0.20804373333333331*_t23*_t55 + 2.3466666666666667*_t23*_t68 + 0.0037641055466666657*_t60*_t82;
  const double d3F_dna3 = 0.0050855762962962962*_t10*_t15*_t42 + 0.0013311495955555554*_t10*_t35*_t4 - 0.00046457120884888875*_t10*_t51*_t62 - _t28*_t35*_t63 - _t29*_t81 - _t39*_t64 - _t50*_t65 - _t50*_t66;
  const double d3F_dna2_dgaa = 0.00012586801333333333*_t15*_t54*_t8 - _t29*_t87 + 4.3927936653333326e-5*_t35*_t8*_t82 - _t38*_t56 - _t56*_t83;
  const double d3F_dna2_dla = -0.00035142349322666661*_t1*_t32*_t88 - 0.0010069441066666667*_t15*_t18*_t32 - _t29*_t90 - _t38*_t59 - _t59*_t83;
  const double d3F_dna2_dta = -0.0020138882133333333*_t23*_t53 - 0.00070284698645333322*_t23*_t70*_t88 - _t29*_t91 - _t38*_t61 - _t61*_t83;
  const double d3F_dna_dla2 = 0;
  const double d3F_dna_dla_dta = 0;
  const double d3F_dna_dta2 = 0;
  const double d3F_dla3 = 0;
  const double d3F_dla2_dta = 0;
  const double d3F_dla_dta2 = 0;
  const double d3F_dta3 = 0;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 0] += d3F_dna_dla_dta;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
  if(out->v3lapl2tau != NULL) out->v3lapl2tau[ip*p->dim.v3lapl2tau + 0] += d3F_dla2_dta;
  if(out->v3lapltau2 != NULL) out->v3lapltau2[ip*p->dim.v3lapltau2 + 0] += d3F_dla_dta2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
#endif
#if _KMAX >= 4
  const double _t92 = _t8*_t85;
  const double _t93 = xc_powr(na, -20, 3);
  const double _t94 = _t72*la;
  const double _t96 = _t35*_t63;
  const double _t97 = 0.011442546666666666*_t64;
  const double _t95 = _t48*_t8;
  const double _t98 = _t58*_t8;
  const double _t99 = _t23*_t86;
  const double d4F_dna4 = -0.0079868975733333319*_t1*_t35*_t50 + 0.0018582848353955552*_t10*_t54*_t62 - 0.00021618046918434953*_t10*_t82/xc_powi(_t11, 5) - 0.19672000000000001*_t12*_t81 + 0.020342305185185185*_t15*_t28*_t42 - 0.022885093333333332*_t16*_t81 - 0.0023664881698765424*_t20*_t36 + 0.0053245983822222216*_t28*_t35*_t4 - 0.001858284835395555*_t28*_t51*_t62 - _t29*(0.089161599999999994*_t18*_t76 + 0.00063563195664711081*_t27*_t55 - 0.030112844373333326*_t27*_t68 + 0.011292316639999998*_t4*_t95 - 0.2311597037037037*_t40*_t82 - 0.17832319999999996*_t42*_t95 + 1.3417131218226094e-5*_t6*_t84 + 0.03345871597037036*_t6*_t86 - 0.0012712639132942216*_t6*_t92 + 0.27739164444444442*_t70*_t77 + _t9*((0.12320e5 / 0.81e2)*_t24*_t72 + (0.12320e5 / 0.81e2)*_t25*_t94 - 0.2618e4 / 0.81e2*_t93*gaa + (0.770e3 / 0.81e2)*_t94)) - 0.011866344691358026*_t37*_t70 - 0.022885093333333328*_t50*_t64;
  const double d4F_dna3_dgaa = -0.00016782401777777777*_t15*_t92 - _t29*(1.5057777777777777*_t72*_t8 - 1.9863498645222213e-5*_t8*_t93 - 0.12012048888888888*_t8/xc_powi(na, 6) + 0.0028230791599999994*_t8/xc_powr(na, 19, 3)) - 4.3927936653333333e-5*_t35*_t84 - _t56*_t96 - _t56*_t97 + 1.5330849892013331e-5*_t62*_t72*_t8 - _t65*_t87 - _t66*_t87;
  const double d4F_dna3_dla = 0.0013425921422222222*_t15*_t32*_t42*_t8 - _t29*(_t32*_t67 - _t32*_t69 + _t57*_t71 + _t78*_t98 - _t79*_t98 + _t80*_t89 + _t9*(-_t73 - _t75)) + 0.00035142349322666666*_t32*_t35*_t4*_t8 - 0.00012264679913610664*_t32*_t52*_t62 - _t59*_t96 - _t59*_t97 - _t65*_t90 - _t66*_t90;
  const double d4F_dna3_dta = 0.0026851842844444443*_hc1[1]*_t15*_t2*_t54*_t8 + 0.00070284698645333332*_hc1[1]*_t2*_t35*_t8*_t82 - _t29*(0.00031781597832355541*_t23*_t72*_t8 - 0.033876949919999996*_t23*_t84 + 1.0303118222222221*_t23*_t92 - 8.6044444444444448*_t99) - _t61*_t96 - _t61*_t97 - 0.00024529359827221329*_t62*_t99 - _t65*_t91 - _t66*_t91;
  const double d4F_dna2_dla2 = 0;
  const double d4F_dna2_dla_dta = 0;
  const double d4F_dna2_dta2 = 0;
  const double d4F_dna_dla3 = 0;
  const double d4F_dna_dla2_dta = 0;
  const double d4F_dna_dla_dta2 = 0;
  const double d4F_dna_dta3 = 0;
  const double d4F_dla4 = 0;
  const double d4F_dla3_dta = 0;
  const double d4F_dla2_dta2 = 0;
  const double d4F_dla_dta3 = 0;
  const double d4F_dta4 = 0;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 0] += d4F_dna2_dla_dta;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 0] += d4F_dna_dla2_dta;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 0] += d4F_dna_dla_dta2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
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
  const double gab = sigma[1];
  const double gbb = sigma[2];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double lb = (lapl != NULL) ? lapl[1] : 0.0;
  const double ta = tau[0];
  const double tb = tau[1];

  const double _t1 = na - nb;
  const double _t2 = na + nb;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t1*_t3;
  const double _t5 = -_t4;
  const double _t6 = xc_powr(na, -5, 3);
  const double _t7 = _t6*la;
  const double _t8 = xc_powr(nb, -5, 3);
  const double _t9 = _t8*lb;
  const double _t10 = (0.1e1 / (_t2 * _t2));
  const double _t11 = xc_powr(_t2, -1, 3);
  const double _t12 = 0.34899999999999998*_t11 + 0.1e1;
  const double _t13 = (0.1e1 / _t12);
  const double _t14 = xc_powr(_t2, -8, 3);
  const double _t15 = gaa + 0.2e1*gab + gbb;
  const double _t18 = M_CBRT2;
  const double _t19 = (0.1e1 / 0.32e2)*_t18;
  const double _t21 = exp(-0.25329999999999997*_t11);
  const double _t22 = 0.26400000000000001*_t21;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t4, 0.5e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t5, 0.5e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(cs_thf_k, _KMAX)(p, _t4, _t7, _t6*ta, _hc2);
  double _hc3[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(cs_thf_k, _KMAX)(p, _t5, _t9, _t8*tb, _hc3);
  const double _t16 = _hc0[0] + 0.1e1;
  const double _t17 = _hc1[0] + 0.1e1;
  const double _t20 = _hc2[0] + _hc3[0] - 0.1e1 / 0.8e1*_t14*_t15 + _t19*(_t16*_t7 + _t17*_t9);
  const double _t23 = _t20*_t22 + 0.1e1;
  const double _t24 = _t13*_t23;
  const double _t25 = 0.19672000000000001*_t24;
  const double _t26 = -_t10*_t25*na*nb;
  const double zk = _t26;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t28 = 0.19672000000000001*_t3;
  const double _t29 = _t21/xc_powr(_t2, 4, 3);
  const double _t30 = 0.022290399999999998*_t29;
  const double _t32 = xc_powr(na, -8, 3);
  const double _t33 = (0.5e1 / 0.3e1)*_t32;
  const double _t36 = xc_powr(_t2, -11, 3);
  const double _t37 = (0.1e1 / 0.3e1)*_t15*_t36;
  const double _t38 = -_t3;
  const double _t39 = _t1*_t10;
  const double _t40 = _t38 + _t39;
  const double _t41 = -_t40;
  const double _t50 = xc_powr(_t2, -7, 3);
  const double _t51 = (0.1e1 / (_t12 * _t12));
  const double _t57 = xc_powr(nb, -8, 3);
  const double _t58 = (0.5e1 / 0.3e1)*_t57;
  const double _t61 = _t3 + _t39;
  const double _t62 = -_t61;
  const double _t69 = _t21*_t36;
  const double _t70 = _t13*_t69;
  const double _t71 = 0.0064917600000000009*_t70*na*nb;
  const double _t74 = _t13*_t3;
  const double _t75 = 0.051934080000000007*_t74;
  const double _t77 = na*nb;
  const double _t81 = _t21*_t75;
  const double _t82 = xc_powr(na, -2, 3);
  const double _t85 = xc_powr(nb, -2, 3);
  double _hc4[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(cs_thf_k, _KMAX)(p, _t4, 0, 0, _hc4);
  double _hc5[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(cs_thf_k, _KMAX)(p, _t5, 0, 0, _hc5);
  const double _t27 = _t25*_t3;
  const double _t31 = _t20*_t30;
  const double _t34 = _hc4[1]*_t33;
  const double _t35 = _hc4[2]*_t33;
  const double _t42 = _t16*_t33;
  const double _t43 = _hc0[2]*_t7;
  const double _t44 = _hc1[2]*_t9;
  const double _t45 = _hc2[3]*_t41 + _hc3[3]*_t40 + _t19*(_t40*_t44 + _t41*_t43 - _t42*la) - _t34*ta - _t35*la + _t37;
  const double _t46 = _t22*_t45 + _t31;
  const double _t47 = _t13*_t46;
  const double _t48 = _t47*na;
  const double _t49 = _t28*_t48;
  const double _t52 = _t23*_t51;
  const double _t53 = _t50*_t52;
  const double _t54 = 0.022885093333333332*_t53;
  const double _t55 = _t54*na;
  const double _t56 = _t26 + _t55*nb;
  const double _t59 = _hc5[1]*_t58;
  const double _t60 = _hc5[2]*_t58;
  const double _t63 = _t17*_t58;
  const double _t64 = _hc2[3]*_t62 + _hc3[3]*_t61 + _t19*(_t43*_t62 + _t44*_t61 - _t63*lb) + _t37 - _t59*tb - _t60*lb;
  const double _t65 = _t22*_t64 + _t31;
  const double _t66 = _t13*_t65;
  const double _t67 = _t66*nb;
  const double _t68 = _t28*_t67;
  const double _t72 = _hc4[2]*_t6 + _t16*_t19*_t6;
  const double _t73 = _t21*_t72;
  const double _t76 = _t73*_t75;
  const double _t78 = _hc5[2]*_t8 + _t17*_t19*_t8;
  const double _t79 = _t21*_t78;
  const double _t80 = _t75*_t79;
  const double _t83 = _hc4[1]*_t82;
  const double _t84 = _t81*_t83;
  const double _t86 = _hc5[1]*_t85;
  const double _t87 = _t81*_t86;
  const double dF_dna = -_t27*nb - _t49*nb - _t56;
  const double dF_dnb = -_t27*na - _t56 - _t68*na;
  const double dF_dgaa = _t71;
  const double dF_dgab = 0.012983520000000002*_t70*na*nb;
  const double dF_dgbb = _t71;
  const double dF_dla = -_t76*_t77;
  const double dF_dlb = -_t77*_t80;
  const double dF_dta = -_t84*nb;
  const double dF_dtb = -_t87*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 1] += dF_dlb;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 1] += dF_dtb;
#endif
#if _KMAX >= 2
  const double _t88 = 0.39344000000000001*_t3;
  const double _t91 = 0.19672000000000001*_t74;
  const double _t92 = xc_powr(na, -11, 3);
  const double _t93 = (0.40e2 / 0.9e1)*_t92;
  const double _t96 = xc_powr(_t2, -14, 3);
  const double _t97 = -0.11e2 / 0.9e1*_t15*_t96;
  const double _t98 = 0.2e1*_t10;
  const double _t99 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t100 = 0.2e1*_t99;
  const double _t101 = _t1*_t100;
  const double _t102 = _t101 - _t98;
  const double _t103 = -_t102;
  const double _t104 = (_t40 * _t40);
  const double _t113 = (_t41 * _t41);
  const double _t117 = 0.044580799999999997*_t29;
  const double _t119 = 0.0018820527733333329*_t14;
  const double _t120 = 0.02972053333333333*_t50;
  const double _t125 = _t50*_t51;
  const double _t132 = (0.1e1 / (_t12 * _t12 * _t12));
  const double _t137 = xc_powr(_t2, -10, 3);
  const double _t139 = _t91*nb;
  const double _t151 = _t41*_t62;
  const double _t155 = 0.022885093333333332*_t77;
  const double _t158 = xc_powr(nb, -11, 3);
  const double _t159 = (0.40e2 / 0.9e1)*_t158;
  const double _t162 = _t101 + _t98;
  const double _t163 = -_t162;
  const double _t164 = (_t62 * _t62);
  const double _t169 = (_t61 * _t61);
  const double _t176 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t177 = _t176*_t21;
  const double _t178 = -0.0027862999999999998*_t177 + 0.087999999999999995*_t21*_t36;
  const double _t179 = _t139*_t178;
  const double _t180 = _t21*_t96;
  const double _t181 = _t13*_t180;
  const double _t182 = 0.0064917600000000009*_t181;
  const double _t183 = _t182*na;
  const double _t184 = xc_powi(_t2, -5);
  const double _t185 = _t179*na + _t183*nb - 0.00075520807999999995*_t184*_t21*_t51*na*nb;
  const double _t186 = 0.0064917600000000009*_t13*_t21*_t36*nb - _t185;
  const double _t187 = -0.0055725999999999996*_t177 + 0.17599999999999999*_t21*_t36;
  const double _t188 = _t139*_t187;
  const double _t189 = 0.012983520000000002*_t181;
  const double _t190 = _t189*nb;
  const double _t191 = -0.0015104161599999999*_t184*_t21*_t51*na*nb + _t188*na + _t190*na;
  const double _t192 = 0.0064917600000000009*_t13*_t21*_t36*na - _t185;
  const double _t194 = _t41*_t6;
  const double _t198 = 0.0060416646399999996*_t125;
  const double _t214 = _t61*_t8;
  const double _t89 = _t47*_t88;
  const double _t90 = 0.045770186666666664*_t53;
  const double _t94 = _hc4[1]*_t93;
  const double _t95 = _hc4[2]*_t93;
  const double _t105 = _hc4[7]*_t33;
  const double _t106 = _t105*ta;
  const double _t107 = _hc4[8]*_t33;
  const double _t108 = _t107*la;
  const double _t109 = _hc2[9]*_t41 - _t106 - _t108;
  const double _t110 = _t16*_t93;
  const double _t111 = _hc0[2]*_t32;
  const double _t112 = (0.10e2 / 0.3e1)*_t111*_t41;
  const double _t114 = _hc0[5]*_t7;
  const double _t115 = _hc1[5]*_t9;
  const double _t116 = _hc2[3]*_t102 + _hc3[3]*_t103 + _hc3[9]*_t104 - _t106*_t41 - _t108*_t41 + _t109*_t41 + _t19*(_t102*_t43 + _t103*_t44 + _t104*_t115 + _t110*la - _t112*la + _t113*_t114) + _t94*ta + _t95*la + _t97;
  const double _t118 = _t20*_t21;
  const double _t121 = _t118*_t119 - _t118*_t120;
  const double _t122 = _t116*_t22 + _t117*_t45 + _t121;
  const double _t123 = _t122*na;
  const double _t124 = _t123*_t91;
  const double _t126 = _t125*_t46;
  const double _t127 = 0.045770186666666664*_t126;
  const double _t128 = _t127*na;
  const double _t129 = _t24*_t99;
  const double _t130 = 0.39344000000000001*_t129;
  const double _t131 = _t130*na;
  const double _t133 = _t132*_t23;
  const double _t134 = _t133*_t36;
  const double _t135 = 0.0053245983822222207*_t134;
  const double _t136 = _t135*na;
  const double _t138 = _t131*nb + _t136*nb - 0.076283644444444437*_t137*_t23*_t51*na*nb;
  const double _t140 = _hc2[9]*_t41;
  const double _t141 = _hc5[7]*_t58;
  const double _t142 = _t141*tb;
  const double _t143 = _hc5[8]*_t58;
  const double _t144 = _t143*lb;
  const double _t145 = _hc3[9]*_t61 - _t142 - _t144;
  const double _t146 = _hc1[2]*_t58;
  const double _t147 = _t146*_t40;
  const double _t148 = _hc0[2]*_t62;
  const double _t149 = _t148*_t33;
  const double _t150 = _t115*_t40;
  const double _t152 = _hc2[3]*_t101 - _hc3[3]*_t101 - _t106*_t62 - _t108*_t62 + _t140*_t62 + _t145*_t40 + _t19*(_t101*_t43 - _t101*_t44 + _t114*_t151 - _t147*lb - _t149*la + _t150*_t61) + _t97;
  const double _t153 = _t121 + _t152*_t22 + _t30*_t45 + _t30*_t64;
  const double _t154 = _t153*na;
  const double _t156 = _t125*_t65;
  const double _t157 = _t66*_t88;
  const double _t160 = _hc5[1]*_t159;
  const double _t161 = _hc5[2]*_t159;
  const double _t165 = _t159*_t17;
  const double _t166 = _hc1[2]*_t57;
  const double _t167 = (0.10e2 / 0.3e1)*_t166;
  const double _t168 = _t167*_t61;
  const double _t170 = _hc1[5]*_t169;
  const double _t171 = _hc2[3]*_t162 + _hc2[9]*_t164 + _hc3[3]*_t163 - _t142*_t61 - _t144*_t61 + _t145*_t61 + _t160*tb + _t161*lb + _t19*(_t114*_t164 + _t162*_t43 + _t163*_t44 + _t165*lb - _t168*lb + _t170*_t9) + _t97;
  const double _t172 = _t117*_t64 + _t121 + _t171*_t22;
  const double _t173 = _t139*_t172;
  const double _t174 = 0.045770186666666664*_t156;
  const double _t175 = _t174*nb;
  const double _t193 = _t30*_t72;
  const double _t195 = _hc4[8]*_t194 + _t19*(_hc0[2]*_t194 - _t42) - _t35;
  const double _t196 = _t193 + _t195*_t22;
  const double _t197 = _t196*na;
  const double _t199 = _t73*_t77;
  const double _t200 = -0.051934080000000007*_t10*_t13*_t21*_t72*na*nb + _t198*_t199;
  const double _t201 = _t30*_t78;
  const double _t202 = _hc5[8]*_t8;
  const double _t203 = _hc1[2]*_t8;
  const double _t204 = _t19*_t203*_t40 + _t202*_t40;
  const double _t205 = _t201 + _t204*_t22;
  const double _t206 = _t205*na;
  const double _t207 = _t198*_t79;
  const double _t208 = -0.051934080000000007*_t10*_t13*_t21*_t78*na*nb + _t207*_t77;
  const double _t209 = _hc4[8]*_t6;
  const double _t210 = _hc0[2]*_t6;
  const double _t211 = _t19*_t210*_t62 + _t209*_t62;
  const double _t212 = _t193 + _t211*_t22;
  const double _t213 = _t139*_t212;
  const double _t215 = _t19*(_hc1[2]*_t214 - _t63) + _t202*_t61 - _t60;
  const double _t216 = _t201 + _t215*_t22;
  const double _t217 = _t139*_t216;
  const double _t218 = _hc4[1]*_t6;
  const double _t219 = _t218*_t30;
  const double _t220 = _hc4[7]*_t41*_t6 - _t34;
  const double _t221 = _t219 + _t22*_t220;
  const double _t222 = _t221*na;
  const double _t223 = _t21*_t218;
  const double _t224 = _t223*_t75;
  const double _t225 = _t21*_t83;
  const double _t226 = _t198*_t225;
  const double _t227 = -0.051934080000000007*_hc4[1]*_t10*_t13*_t21*_t82*nb + _t226*nb;
  const double _t228 = _hc5[1]*_t8;
  const double _t229 = _t228*_t30;
  const double _t230 = _hc5[7]*_t8;
  const double _t231 = _t230*_t40;
  const double _t232 = _t22*_t231 + _t229;
  const double _t233 = _t232*na;
  const double _t234 = _t21*_t86;
  const double _t235 = _t198*_t234;
  const double _t236 = -0.051934080000000007*_hc5[1]*_t10*_t13*_t21*_t85*na + _t235*na;
  const double _t237 = _hc4[7]*_t6;
  const double _t238 = _t237*_t62;
  const double _t239 = _t219 + _t22*_t238;
  const double _t240 = _t139*_t239;
  const double _t241 = _hc5[7]*_t61*_t8 - _t59;
  const double _t242 = _t22*_t241 + _t229;
  const double _t243 = _t139*_t242;
  const double _t244 = _t21*_t228;
  const double _t245 = _t244*_t75;
  const double d2F_dna2 = 0.39344000000000001*_t10*_t13*_t23*nb + 0.39344000000000001*_t10*_t13*_t46*na*nb - _t124*nb - _t128*nb - _t138 - _t89*nb - _t90*nb;
  const double d2F_dna_dnb = 0.19672000000000001*_t10*_t13*_t23*na + 0.19672000000000001*_t10*_t13*_t23*nb + 0.19672000000000001*_t10*_t13*_t46*na*nb + 0.19672000000000001*_t10*_t13*_t65*na*nb - _t126*_t155 - _t138 - _t139*_t154 - _t155*_t156 - _t27 - _t49 - _t54*nb - _t55 - _t68;
  const double d2F_dnb2 = 0.39344000000000001*_t10*_t13*_t23*na + 0.39344000000000001*_t10*_t13*_t65*na*nb - _t138 - _t157*na - _t173*na - _t175*na - _t90*na;
  const double d2F_dna_dgaa = _t186;
  const double d2F_dna_dgab = 0.012983520000000002*_t13*_t21*_t36*nb - _t191;
  const double d2F_dna_dgbb = _t186;
  const double d2F_dnb_dgaa = _t192;
  const double d2F_dnb_dgab = 0.012983520000000002*_t13*_t21*_t36*na - _t191;
  const double d2F_dnb_dgbb = _t192;
  const double d2F_dna_dla = -_t139*_t197 - _t200 - _t76*nb;
  const double d2F_dna_dlb = -_t139*_t206 - _t208 - _t80*nb;
  const double d2F_dnb_dla = -_t200 - _t213*na - _t76*na;
  const double d2F_dnb_dlb = -_t208 - _t217*na - _t80*na;
  const double d2F_dna_dta = -_t139*_t222 - _t224*nb - _t227;
  const double d2F_dna_dtb = -_t139*_t233 - _t236 - _t87;
  const double d2F_dnb_dta = -_t227 - _t240*na - _t84;
  const double d2F_dnb_dtb = -_t236 - _t243*na - _t245*na;
  const double d2F_dla2 = 0;
  const double d2F_dlb2 = 0;
  const double d2F_dla_dta = 0;
  const double d2F_dlb_dtb = 0;
  const double d2F_dta2 = 0;
  const double d2F_dtb2 = 0;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 1] += d2F_dna_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 2] += d2F_dna_dgbb;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 3] += d2F_dnb_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 4] += d2F_dnb_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 1] += d2F_dna_dlb;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 2] += d2F_dnb_dla;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 3] += d2F_dnb_dlb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 1] += d2F_dna_dtb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 2] += d2F_dnb_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 3] += d2F_dnb_dtb;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 2] += d2F_dlb2;
  if(out->v2lapltau != NULL) out->v2lapltau[ip*p->dim.v2lapltau + 0] += d2F_dla_dta;
  if(out->v2lapltau != NULL) out->v2lapltau[ip*p->dim.v2lapltau + 3] += d2F_dlb_dtb;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 2] += d2F_dtb2;
#endif
#if _KMAX >= 3
  const double _t247 = 0.59016000000000002*_t74;
  const double _t251 = xc_powr(na, -14, 3);
  const double _t252 = (0.440e3 / 0.27e2)*_t251;
  const double _t255 = xc_powr(_t2, -17, 3);
  const double _t256 = (0.154e3 / 0.27e2)*_t15*_t255;
  const double _t257 = 0.6e1*_t99;
  const double _t258 = _t1*_t176;
  const double _t259 = 0.6e1*_t258;
  const double _t260 = -_t257 + _t259;
  const double _t261 = -_t260;
  const double _t262 = (_t40 * _t40 * _t40);
  const double _t264 = (0.80e2 / 0.9e1)*_t92;
  const double _t265 = _t264*_t41;
  const double _t267 = 0.4e1*_t10;
  const double _t268 = 0.4e1*_t99;
  const double _t269 = _t1*_t268;
  const double _t270 = -_t267 + _t269;
  const double _t271 = -_t270;
  const double _t279 = 0.2e1*_t102;
  const double _t292 = (0.40e2 / 0.3e1)*_t92;
  const double _t293 = _t292*la;
  const double _t295 = (_t41 * _t41 * _t41);
  const double _t300 = 0.5e1*_t32;
  const double _t305 = 0.066871199999999992*_t29;
  const double _t309 = 0.069347911111111105*_t137;
  const double _t310 = 0.0001589079891617777*_t177;
  const double _t311 = 0.0075282110933333306*_t69;
  const double _t314 = _t139*na;
  const double _t316 = _t132*_t36;
  const double _t319 = 1.18032*_t99;
  const double _t323 = xc_powr(_t2, -13, 3);
  const double _t327 = _t184*nb;
  const double _t328 = (0.1e1 / (_t12 * _t12 * _t12 * _t12));
  const double _t331 = 0.001858284835395555*na;
  const double _t333 = _t13*_t88;
  const double _t337 = _t259 - 0.2e1*_t99;
  const double _t338 = -_t337;
  const double _t351 = (0.20e2 / 0.3e1)*la;
  const double _t354 = _t93*la;
  const double _t356 = _t58*lb;
  const double _t361 = (0.10e2 / 0.3e1)*_t32;
  const double _t363 = -_t1*_t10;
  const double _t364 = _t363 + _t38;
  const double _t365 = _t113*_t364;
  const double _t371 = 0.39344000000000001*_t99;
  const double _t374 = 0.78688000000000002*_t99;
  const double _t379 = 0.022885093333333332*nb;
  const double _t384 = _t3 + _t363;
  const double _t385 = _t164*_t384;
  const double _t389 = _t1*_t99;
  const double _t392 = _t159*lb;
  const double _t394 = _t33*la;
  const double _t397 = _t57*lb;
  const double _t399 = (0.10e2 / 0.3e1)*_t61;
  const double _t401 = _t162*_t41;
  const double _t409 = 0.022885093333333332*na;
  const double _t412 = xc_powr(nb, -14, 3);
  const double _t413 = (0.440e3 / 0.27e2)*_t412;
  const double _t416 = _t257 + _t259;
  const double _t417 = -_t416;
  const double _t418 = (_t62 * _t62 * _t62);
  const double _t420 = (0.80e2 / 0.9e1)*_t158*_t61;
  const double _t422 = _t267 + _t269;
  const double _t431 = (0.40e2 / 0.3e1)*_t158;
  const double _t432 = _t431*lb;
  const double _t434 = (_t61 * _t61 * _t61);
  const double _t436 = 0.5e1*_t57;
  const double _t438 = 0.5e1*_t163;
  const double _t440 = -_t422;
  const double _t444 = 0.015973795146666664*_t316;
  const double _t448 = _t178*_t333;
  const double _t449 = -0.0015104161599999999*_t184*_t21*_t51*nb + _t190;
  const double _t450 = xc_powr(_t2, -16, 3);
  const double _t451 = _t21*_t450;
  const double _t452 = -0.32266666666666671*_t180 + 0.018575333333333333*_t184*_t21 - 0.00023525659666666661*_t451;
  const double _t453 = _t139*_t452;
  const double _t454 = xc_powi(_t2, -6);
  const double _t455 = _t21*_t454;
  const double _t456 = _t455*_t51;
  const double _t457 = _t456*nb;
  const double _t458 = 0.0025173602666666663*_t457;
  const double _t459 = _t178*nb;
  const double _t460 = 0.045770186666666664*_t125;
  const double _t461 = _t459*_t460;
  const double _t462 = xc_powr(_t2, -19, 3);
  const double _t463 = -0.39344000000000001*_t10*_t13*_t178*na*nb - 0.012983520000000002*_t13*_t21*_t255*na*nb - 0.0001757117466133333*_t132*_t21*_t462*na*nb + _t453*na + _t458*na + _t461*na;
  const double _t464 = -_t448*nb - _t449 - _t463;
  const double _t465 = _t187*_t333;
  const double _t466 = 0.025967040000000004*_t181;
  const double _t467 = -0.64533333333333343*_t180 + 0.037150666666666665*_t184*_t21 - 0.00047051319333333322*_t451;
  const double _t468 = _t139*_t467;
  const double _t469 = 0.0050347205333333327*_t457;
  const double _t470 = _t187*nb;
  const double _t471 = _t460*_t470;
  const double _t472 = -0.39344000000000001*_t10*_t13*_t187*na*nb - 0.025967040000000004*_t13*_t21*_t255*na*nb - 0.00035142349322666661*_t132*_t21*_t462*na*nb + _t468*na + _t469*na + _t471*na;
  const double _t473 = _t91*na;
  const double _t474 = 0.0064917600000000009*_t13*_t21*_t36 - _t178*_t473 - _t179 - _t182*nb - _t183 + 0.00075520807999999995*_t184*_t21*_t51*na + 0.00075520807999999995*_t184*_t21*_t51*nb - _t463;
  const double _t475 = -0.0015104161599999999*_t184*_t21*_t51*na + _t189*na;
  const double _t476 = -_t448*na - _t463 - _t475;
  const double _t478 = 0.012083329279999999*_t125;
  const double _t488 = _t13*_t77;
  const double _t489 = 0.10386816000000001*_t488*_t99;
  const double _t490 = _t132*_t69;
  const double _t492 = 0.0014056939729066664*_t77;
  const double _t496 = _t104*_t8;
  const double _t510 = _t125*_t409;
  const double _t516 = _t164*_t6;
  const double _t535 = _t13*_t99;
  const double _t536 = 0.10386816000000001*_t535;
  const double _t538 = 0.0014056939729066664*nb;
  const double _t548 = 0.0014056939729066664*na;
  const double _t246 = 0.015973795146666664*_t134;
  const double _t248 = _t122*_t247;
  const double _t249 = 1.18032*_t129;
  const double _t250 = 0.13731056*_t126;
  const double _t253 = _hc4[1]*_t252;
  const double _t254 = _hc4[2]*_t252;
  const double _t263 = _hc4[7]*ta;
  const double _t266 = _hc4[8]*la;
  const double _t272 = _hc3[9]*_t40;
  const double _t273 = _hc4[8]*_t102;
  const double _t274 = _hc4[18]*_t113 + _t273;
  const double _t275 = _t274*_t33;
  const double _t276 = _hc4[7]*_t102;
  const double _t277 = _hc4[17]*_t113 + _t276;
  const double _t278 = _t277*_t33;
  const double _t280 = _hc4[7]*_t93;
  const double _t281 = _t280*ta;
  const double _t282 = _hc4[8]*_t93;
  const double _t283 = _t282*la;
  const double _t284 = _hc2[9]*_t102;
  const double _t285 = _hc4[17]*_t33;
  const double _t286 = _t285*ta;
  const double _t287 = _hc4[18]*_t33;
  const double _t288 = _t287*la;
  const double _t289 = _hc2[19]*_t41 - _t286 - _t288;
  const double _t290 = _t281 + _t283 + _t284 - _t286*_t41 - _t288*_t41 + _t289*_t41;
  const double _t291 = _t16*_t252;
  const double _t294 = _hc0[2]*_t41;
  const double _t296 = _hc0[9]*_t7;
  const double _t297 = 0.5e1*_t111;
  const double _t298 = _t102*_t297;
  const double _t299 = _hc0[5]*_t113;
  const double _t301 = _t299*_t300;
  const double _t302 = _hc1[9]*_t9;
  const double _t303 = _t114*_t41;
  const double _t304 = _hc2[3]*_t261 + _hc3[19]*_t262 + _hc3[3]*_t260 + _t103*_t272 + _t109*_t279 + _t19*(_t102*_t303 + _t103*_t150 + _t150*_t271 + _t260*_t44 + _t261*_t43 + _t262*_t302 + _t270*_t303 - _t291*la + _t293*_t294 + _t295*_t296 - _t298*la - _t301*la) - _t253*ta - _t254*la + _t256 + _t263*_t265 + _t265*_t266 + _t271*_t272 - _t275*la - _t278*ta + _t290*_t41;
  const double _t306 = _t21*_t45;
  const double _t307 = _t14*_t306;
  const double _t308 = _t306*_t50;
  const double _t312 = _t118*_t309 + _t20*_t310 - _t20*_t311;
  const double _t313 = _t116*_t305 + _t22*_t304 + 0.0056461583199999988*_t307 - 0.089161599999999994*_t308 + _t312;
  const double _t315 = _t46*nb;
  const double _t317 = _t315*_t316;
  const double _t318 = _t317*na;
  const double _t320 = _t319*_t48;
  const double _t321 = _t123*_t125;
  const double _t322 = 0.068655279999999999*_t321;
  const double _t324 = _t323*_t52;
  const double _t325 = _t324*nb;
  const double _t326 = 0.30004900148148145*_t325;
  const double _t329 = _t23*_t328;
  const double _t330 = _t327*_t329;
  const double _t332 = -1.18032*_t13*_t176*_t23*na*nb - 0.037272188675555547*_t132*_t23*_t96*na*nb + _t326*na + _t330*_t331;
  const double _t334 = _t153*_t333;
  const double _t335 = 0.78688000000000002*_t129;
  const double _t336 = 0.010649196764444441*_t134;
  const double _t339 = _hc5[17]*_t58;
  const double _t340 = _t339*tb;
  const double _t341 = _hc5[18]*_t58;
  const double _t342 = _t341*lb;
  const double _t343 = _hc3[19]*_t61 - _t340 - _t342;
  const double _t344 = _hc4[18]*_t151 + _hc4[8]*_t101;
  const double _t345 = _t33*_t344;
  const double _t346 = _hc4[17]*_t151 + _hc4[7]*_t101;
  const double _t347 = _t33*_t346;
  const double _t348 = _t286*_t62;
  const double _t349 = _t288*_t62;
  const double _t350 = _hc2[19]*_t41*_t62 + _hc2[9]*_t101 - _t348 - _t349;
  const double _t352 = _t111*_t351;
  const double _t353 = _t352*_t99;
  const double _t355 = _t103*_t146;
  const double _t357 = _hc1[5]*_t104;
  const double _t358 = _t115*_t61;
  const double _t359 = _t104*_t302;
  const double _t360 = _hc0[5]*_t151;
  const double _t362 = _t360*_t361;
  const double _t366 = _t114*_t62;
  const double _t367 = _hc2[3]*_t338 + _hc3[3]*_t337 + _t101*_t109 + _t103*_t145 + _t104*_t343 + _t19*(-_t1*_t353 + _t102*_t366 + _t103*_t358 + _t148*_t354 - _t150*_t269 + _t269*_t303 + _t296*_t365 + _t337*_t44 + _t338*_t43 - _t355*lb - _t356*_t357 + _t359*_t61 - _t362*la) + _t256 - _t269*_t272 + _t281*_t62 + _t283*_t62 + _t284*_t62 - _t345*la - _t347*ta + _t350*_t41;
  const double _t368 = _t21*_t64;
  const double _t369 = _t117*_t152 + _t312;
  const double _t370 = _t116*_t30 + _t119*_t368 - _t120*_t368 + _t22*_t367 + 0.0037641055466666657*_t307 - 0.05944106666666666*_t308 + _t369;
  const double _t372 = _t67*na;
  const double _t373 = _t48*nb;
  const double _t375 = _t65*nb;
  const double _t376 = _t375*na;
  const double _t377 = _t316*_t376;
  const double _t378 = 0.010649196764444441*_t317;
  const double _t380 = _t153*nb;
  const double _t381 = _t125*_t380;
  const double _t382 = -0.39344000000000001*_t10*_t13*_t153*na*nb - 0.39344000000000001*_t10*_t13*_t23 - 0.39344000000000001*_t10*_t13*_t46*na - 0.39344000000000001*_t10*_t13*_t65*nb + _t128 + _t175 + _t332 + 0.045770186666666664*_t381*na + _t90;
  const double _t383 = _hc2[9]*_t62;
  const double _t386 = _hc5[7]*_t159;
  const double _t387 = _hc5[8]*_t159;
  const double _t388 = _hc3[9]*_t163 - _t340*_t61 - _t342*_t61 + _t343*_t61 + _t386*tb + _t387*lb;
  const double _t390 = _t166*lb;
  const double _t391 = (0.20e2 / 0.3e1)*_t390;
  const double _t393 = _hc1[2]*_t40;
  const double _t395 = _hc0[2]*_t162;
  const double _t396 = _hc0[5]*_t164;
  const double _t398 = _hc1[5]*_t40;
  const double _t400 = _t398*_t399;
  const double _t402 = _t169*_t302;
  const double _t403 = _hc2[19]*_t385 - _hc2[3]*_t100 - _hc2[3]*_t259 + _hc3[3]*_t100 + _hc3[3]*_t259 - _t106*_t162 - _t108*_t162 + _t140*_t162 - _t145*_t269 - _t164*_t286 - _t164*_t288 + _t19*(-_t100*_t43 + _t100*_t44 + _t114*_t401 + _t150*_t163 - _t259*_t43 + _t259*_t44 - _t269*_t358 + _t269*_t366 + _t296*_t385 + _t389*_t391 + _t392*_t393 - _t394*_t395 - _t394*_t396 - _t397*_t400 + _t40*_t402) + _t256 + _t269*_t383 + _t388*_t40;
  const double _t404 = _t14*_t368;
  const double _t405 = _t368*_t50;
  const double _t406 = _t119*_t306 - _t120*_t306 + _t171*_t30 + _t22*_t403 + _t369 + 0.0037641055466666657*_t404 - 0.05944106666666666*_t405;
  const double _t407 = _t172*nb;
  const double _t408 = _t125*_t407;
  const double _t410 = _t172*_t247;
  const double _t411 = 0.13731056*_t156;
  const double _t414 = _hc5[1]*_t413;
  const double _t415 = _hc5[2]*_t413;
  const double _t419 = _hc5[7]*tb;
  const double _t421 = _hc5[8]*lb;
  const double _t423 = _hc5[8]*_t163;
  const double _t424 = _hc5[18]*_t169 + _t423;
  const double _t425 = _t424*_t58;
  const double _t426 = _hc5[7]*_t163;
  const double _t427 = _hc5[17]*_t169 + _t426;
  const double _t428 = _t427*_t58;
  const double _t429 = 0.2e1*_t145;
  const double _t430 = _t17*_t413;
  const double _t433 = _hc1[2]*_t61;
  const double _t435 = _hc1[9]*_t434;
  const double _t437 = _t170*_t436;
  const double _t439 = _t166*_t438;
  const double _t441 = _hc2[19]*_t418 + _hc2[3]*_t417 + _hc3[3]*_t416 + _t162*_t383 + _t163*_t429 + _t19*(_t162*_t366 + _t163*_t358 + _t296*_t418 + _t358*_t440 + _t366*_t422 + _t416*_t44 + _t417*_t43 - _t430*lb + _t432*_t433 + _t435*_t9 - _t437*lb - _t439*lb) + _t256 + _t383*_t422 + _t388*_t61 - _t414*tb - _t415*lb + _t419*_t420 + _t420*_t421 - _t425*lb - _t428*tb;
  const double _t442 = _t171*_t305 + _t22*_t441 + _t312 + 0.0056461583199999988*_t404 - 0.089161599999999994*_t405;
  const double _t443 = _t139*_t442;
  const double _t445 = _t375*_t444;
  const double _t446 = _t319*_t67;
  const double _t447 = 0.068655279999999999*_t408;
  const double _t477 = _t196*_t333;
  const double _t479 = _t478*_t73;
  const double _t480 = _hc4[18]*_t194;
  const double _t481 = -_t107 + _t480;
  const double _t482 = _hc0[5]*_t6;
  const double _t483 = -_t107*_t41 + _t19*(_t102*_t210 + _t110 - _t112 + _t113*_t482) + _t273*_t6 + _t41*_t481 + _t95;
  const double _t484 = _t119*_t73 - _t120*_t73;
  const double _t485 = _t117*_t195 + _t22*_t483 + _t484;
  const double _t486 = _t196*nb;
  const double _t487 = _t460*_t486;
  const double _t491 = _t490*_t72;
  const double _t493 = -0.020138882133333331*_t137*_t21*_t51*_t72*na*nb + _t489*_t73 + _t491*_t492;
  const double _t494 = _t205*_t333;
  const double _t495 = _t478*_t79;
  const double _t497 = _hc5[18]*_t496 + _t103*_t202 + _t19*(_hc1[5]*_t496 + _t103*_t203);
  const double _t498 = _t119*_t79 - _t120*_t79;
  const double _t499 = _t117*_t204 + _t22*_t497 + _t498;
  const double _t500 = _t205*nb;
  const double _t501 = _t460*_t500;
  const double _t502 = _t490*_t78;
  const double _t503 = -0.020138882133333331*_t137*_t21*_t51*_t78*na*nb + _t489*_t79 + _t492*_t502;
  const double _t504 = _t73*na;
  const double _t505 = _t73*nb;
  const double _t506 = _hc0[5]*_t194;
  const double _t507 = _t101*_t209 - _t107*_t62 + _t19*(_t101*_t210 - _t149 + _t506*_t62) + _t480*_t62;
  const double _t508 = _t195*_t30 + _t211*_t30 + _t22*_t507 + _t484;
  const double _t509 = _t212*nb;
  const double _t511 = _hc5[18]*_t214 - _t143;
  const double _t512 = -_t101*_t202 + _t19*(_hc1[5]*_t40*_t61*_t8 - _t101*_t203 - _t147) + _t40*_t511;
  const double _t513 = _t204*_t30 + _t215*_t30 + _t22*_t512 + _t498;
  const double _t514 = _t216*nb;
  const double _t515 = _t212*_t333;
  const double _t517 = _hc4[18]*_t516 + _t162*_t209 + _t19*(_t162*_t210 + _t164*_t482);
  const double _t518 = _t117*_t211 + _t22*_t517 + _t484;
  const double _t519 = _t139*_t518;
  const double _t520 = _t460*_t509;
  const double _t521 = _t216*_t333;
  const double _t522 = -_t143*_t61 + _t161 + _t19*(_t163*_t203 + _t165 - _t168 + _t170*_t8) + _t423*_t8 + _t511*_t61;
  const double _t523 = _t117*_t215 + _t22*_t522 + _t498;
  const double _t524 = _t139*_t523;
  const double _t525 = _t460*_t514;
  const double _t526 = _t221*_t333;
  const double _t527 = _hc4[17]*_t194;
  const double _t528 = -_t105 + _t527;
  const double _t529 = -_t105*_t41 + _t276*_t6 + _t41*_t528 + _t94;
  const double _t530 = _t119*_t223 - _t120*_t223;
  const double _t531 = _t117*_t220 + _t22*_t529 + _t530;
  const double _t532 = _t221*nb;
  const double _t533 = _t460*_t532;
  const double _t534 = _t223*_t478;
  const double _t537 = _t225*_t536;
  const double _t539 = _t490*_t83;
  const double _t540 = -0.020138882133333331*_hc4[1]*_t137*_t21*_t51*_t82*nb + _t537*nb + _t538*_t539;
  const double _t541 = _t232*_t333;
  const double _t542 = _hc5[17]*_t496 + _t103*_t230;
  const double _t543 = _t119*_t244 - _t120*_t244;
  const double _t544 = _t117*_t231 + _t22*_t542 + _t543;
  const double _t545 = _t232*nb;
  const double _t546 = _t460*_t545;
  const double _t547 = _t234*_t536;
  const double _t549 = _t490*_t86;
  const double _t550 = -0.020138882133333331*_hc5[1]*_t137*_t21*_t51*_t85*na + _t547*na + _t548*_t549;
  const double _t551 = _t101*_t237 - _t105*_t62 + _t527*_t62;
  const double _t552 = _t22*_t551 + _t220*_t30 + _t238*_t30 + _t530;
  const double _t553 = _t239*nb;
  const double _t554 = _t223*nb;
  const double _t555 = _hc5[17]*_t214 - _t141;
  const double _t556 = -_t101*_t230 + _t40*_t555;
  const double _t557 = _t22*_t556 + _t231*_t30 + _t241*_t30 + _t543;
  const double _t558 = _t242*nb;
  const double _t559 = _t244*na;
  const double _t560 = _t239*_t333;
  const double _t561 = _hc4[17]*_t516 + _t162*_t237;
  const double _t562 = _t117*_t238 + _t22*_t561 + _t530;
  const double _t563 = _t139*_t562;
  const double _t564 = _t460*_t553;
  const double _t565 = _t242*_t333;
  const double _t566 = -_t141*_t61 + _t160 + _t426*_t8 + _t555*_t61;
  const double _t567 = _t117*_t241 + _t22*_t566 + _t543;
  const double _t568 = _t139*_t567;
  const double _t569 = _t460*_t558;
  const double _t570 = _t244*_t478;
  const double d3F_dna3 = 0.59016000000000002*_t10*_t122*_t13*na*nb + 1.18032*_t10*_t13*_t46*nb + 0.22885093333333331*_t137*_t23*_t51*nb + 0.22885093333333331*_t137*_t46*_t51*na*nb - _t246*nb - _t248*nb - _t249*nb - _t250*nb - _t313*_t314 - 0.015973795146666664*_t318 - _t320*nb - _t322*nb - _t332;
  const double d3F_dna2_dnb = 0.19672000000000001*_t10*_t122*_t13*na*nb + 0.39344000000000001*_t10*_t13*_t46*nb - _t124 - _t127*nb - _t131 - _t136 + 0.076283644444444437*_t137*_t23*_t51*na + 0.15256728888888887*_t137*_t23*_t51*nb + 0.15256728888888887*_t137*_t46*_t51*na*nb + 0.076283644444444437*_t137*_t51*_t65*na*nb - _t314*_t370 - _t321*_t379 - _t334*nb - _t335*nb - _t336*nb - _t371*_t372 - _t373*_t374 - 0.0053245983822222207*_t377 - _t378*na - _t382 - _t89;
  const double d3F_dna_dnb2 = 0.19672000000000001*_t10*_t13*_t172*na*nb + 0.39344000000000001*_t10*_t13*_t65*na - _t130*nb - _t135*nb + 0.15256728888888887*_t137*_t23*_t51*na + 0.076283644444444437*_t137*_t23*_t51*nb + 0.076283644444444437*_t137*_t46*_t51*na*nb + 0.15256728888888887*_t137*_t51*_t65*na*nb - _t157 - _t173 - _t174*na - _t314*_t406 - 0.0053245983822222207*_t318 - _t334*na - _t335*na - _t336*na - _t371*_t373 - _t372*_t374 - 0.010649196764444441*_t377 - _t382 - _t408*_t409;
  const double d3F_dnb3 = 0.59016000000000002*_t10*_t13*_t172*na*nb + 1.18032*_t10*_t13*_t65*na + 0.22885093333333331*_t137*_t23*_t51*na + 0.22885093333333331*_t137*_t51*_t65*na*nb - _t246*na - _t249*na - _t332 - _t410*na - _t411*na - _t443*na - _t445*na - _t446*na - _t447*na;
  const double d3F_dna2_dgaa = _t464;
  const double d3F_dna2_dgab = 0.0030208323199999998*_t184*_t21*_t51*nb - _t465*nb - _t466*nb - _t472;
  const double d3F_dna2_dgbb = _t464;
  const double d3F_dna_dnb_dgaa = _t474;
  const double d3F_dna_dnb_dgab = 0.012983520000000002*_t13*_t21*_t36 - _t187*_t473 - _t188 - _t449 - _t472 - _t475;
  const double d3F_dna_dnb_dgbb = _t474;
  const double d3F_dnb2_dgaa = _t476;
  const double d3F_dnb2_dgab = 0.0030208323199999998*_t184*_t21*_t51*na - _t465*na - _t466*na - _t472;
  const double d3F_dnb2_dgbb = _t476;
  const double d3F_dna2_dla = 0.39344000000000001*_t10*_t13*_t196*na*nb + 0.10386816000000001*_t10*_t13*_t21*_t72*nb - _t314*_t485 - _t477*nb - _t479*nb - _t487*na - _t493;
  const double d3F_dna2_dlb = 0.39344000000000001*_t10*_t13*_t205*na*nb + 0.10386816000000001*_t10*_t13*_t21*_t78*nb - _t314*_t499 - _t494*nb - _t495*nb - _t501*na - _t503;
  const double d3F_dna_dnb_dla = 0.19672000000000001*_t10*_t13*_t196*na*nb + 0.051934080000000007*_t10*_t13*_t21*_t72*na + 0.051934080000000007*_t10*_t13*_t21*_t72*nb + 0.19672000000000001*_t10*_t13*_t212*na*nb - _t196*_t473 - _t198*_t504 - _t198*_t505 - _t213 - _t314*_t508 - _t486*_t510 - _t493 - _t509*_t510 - _t76;
  const double d3F_dna_dnb_dlb = 0.19672000000000001*_t10*_t13*_t205*na*nb + 0.051934080000000007*_t10*_t13*_t21*_t78*na + 0.051934080000000007*_t10*_t13*_t21*_t78*nb + 0.19672000000000001*_t10*_t13*_t216*na*nb - _t205*_t473 - _t207*na - _t207*nb - _t217 - _t314*_t513 - _t500*_t510 - _t503 - _t510*_t514 - _t80;
  const double d3F_dnb2_dla = 0.10386816000000001*_t10*_t13*_t21*_t72*na + 0.39344000000000001*_t10*_t13*_t212*na*nb - _t479*na - _t493 - _t515*na - _t519*na - _t520*na;
  const double d3F_dnb2_dlb = 0.10386816000000001*_t10*_t13*_t21*_t78*na + 0.39344000000000001*_t10*_t13*_t216*na*nb - _t495*na - _t503 - _t521*na - _t524*na - _t525*na;
  const double d3F_dna2_dta = 0.10386816000000001*_hc4[1]*_t10*_t13*_t21*_t6*nb + 0.39344000000000001*_t10*_t13*_t221*na*nb - _t314*_t531 - _t526*nb - _t533*na - _t534*nb - _t540;
  const double d3F_dna2_dtb = 0.10386816000000001*_hc5[1]*_t10*_t13*_t21*_t85 + 0.39344000000000001*_t10*_t13*_t232*na*nb - _t234*_t478 - _t314*_t544 - _t541*nb - _t546*na - _t550;
  const double d3F_dna_dnb_dta = 0.051934080000000007*_hc4[1]*_t10*_t13*_t21*_t6*nb + 0.051934080000000007*_hc4[1]*_t10*_t13*_t21*_t82 + 0.19672000000000001*_t10*_t13*_t221*na*nb + 0.19672000000000001*_t10*_t13*_t239*na*nb - _t198*_t554 - _t221*_t473 - _t224 - _t226 - _t240 - _t314*_t552 - _t510*_t532 - _t510*_t553 - _t540;
  const double d3F_dna_dnb_dtb = 0.051934080000000007*_hc5[1]*_t10*_t13*_t21*_t8*na + 0.051934080000000007*_hc5[1]*_t10*_t13*_t21*_t85 + 0.19672000000000001*_t10*_t13*_t232*na*nb + 0.19672000000000001*_t10*_t13*_t242*na*nb - _t198*_t559 - _t232*_t473 - _t235 - _t243 - _t245 - _t314*_t557 - _t510*_t545 - _t510*_t558 - _t550;
  const double d3F_dnb2_dta = 0.10386816000000001*_hc4[1]*_t10*_t13*_t21*_t82 + 0.39344000000000001*_t10*_t13*_t239*na*nb - _t225*_t478 - _t540 - _t560*na - _t563*na - _t564*na;
  const double d3F_dnb2_dtb = 0.10386816000000001*_hc5[1]*_t10*_t13*_t21*_t8*na + 0.39344000000000001*_t10*_t13*_t242*na*nb - _t550 - _t565*na - _t568*na - _t569*na - _t570*na;
  const double d3F_dna_dla2 = 0;
  const double d3F_dna_dlb2 = 0;
  const double d3F_dnb_dla2 = 0;
  const double d3F_dnb_dlb2 = 0;
  const double d3F_dna_dla_dta = 0;
  const double d3F_dna_dlb_dtb = 0;
  const double d3F_dnb_dla_dta = 0;
  const double d3F_dnb_dlb_dtb = 0;
  const double d3F_dna_dta2 = 0;
  const double d3F_dna_dtb2 = 0;
  const double d3F_dnb_dta2 = 0;
  const double d3F_dnb_dtb2 = 0;
  const double d3F_dla3 = 0;
  const double d3F_dlb3 = 0;
  const double d3F_dla2_dta = 0;
  const double d3F_dlb2_dtb = 0;
  const double d3F_dla_dta2 = 0;
  const double d3F_dlb_dtb2 = 0;
  const double d3F_dta3 = 0;
  const double d3F_dtb3 = 0;
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
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 1] += d3F_dna2_dlb;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 2] += d3F_dna_dnb_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 3] += d3F_dna_dnb_dlb;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 4] += d3F_dnb2_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 5] += d3F_dnb2_dlb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 1] += d3F_dna2_dtb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 2] += d3F_dna_dnb_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 3] += d3F_dna_dnb_dtb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 4] += d3F_dnb2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 5] += d3F_dnb2_dtb;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 2] += d3F_dna_dlb2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 3] += d3F_dnb_dla2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 5] += d3F_dnb_dlb2;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 0] += d3F_dna_dla_dta;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 3] += d3F_dna_dlb_dtb;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 4] += d3F_dnb_dla_dta;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 7] += d3F_dnb_dlb_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 2] += d3F_dna_dtb2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 3] += d3F_dnb_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 5] += d3F_dnb_dtb2;
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
  const double _t571 = 0.78688000000000002*_t74;
  const double _t575 = (0.6160e4 / 0.81e2)/xc_powr(na, 17, 3);
  const double _t576 = _t575*la;
  const double _t577 = xc_powr(_t2, -20, 3);
  const double _t578 = (0.2618e4 / 0.81e2)*_t15*_t577;
  const double _t579 = -_t578;
  const double _t580 = 0.24e2*_t176;
  const double _t581 = 0.24e2*_t1*_t184;
  const double _t582 = -_t580 + _t581;
  const double _t583 = -_t582;
  const double _t584 = (_t40 * _t40 * _t40 * _t40);
  const double _t585 = (_t103 * _t103);
  const double _t586 = (0.440e3 / 0.9e1)*_t251*_t41;
  const double _t587 = 0.12e2*_t99;
  const double _t588 = 0.12e2*_t176;
  const double _t589 = _t1*_t588;
  const double _t590 = -_t587 + _t589;
  const double _t591 = 0.2e1*_t260;
  const double _t592 = _t103*_t271;
  const double _t593 = 0.6e1*_t10;
  const double _t594 = _t1*_t257;
  const double _t595 = _t593 - _t594;
  const double _t599 = 0.2e1*_t41;
  const double _t604 = _t33*ta;
  const double _t609 = _t264*la;
  const double _t616 = _t102*la;
  const double _t617 = (0.80e2 / 0.3e1)*_t92;
  const double _t619 = _t32*_t351;
  const double _t624 = 0.6e1*na - 0.6e1*nb;
  const double _t626 = 0.4e1*na - 0.4e1*nb;
  const double _t627 = 0.2e1*na - 0.2e1*nb;
  const double _t628 = _t627*_t99 - _t98;
  const double _t633 = 0.089161599999999994*_t29;
  const double _t636 = _t184*_t21;
  const double _t641 = 2.3606400000000001*_t99;
  const double _t643 = _t323*_t51;
  const double _t645 = 0.091540373333333327*_t125;
  const double _t646 = _t184*_t328;
  const double _t649 = _t247*nb;
  const double _t652 = _t581 - _t588;
  const double _t653 = -_t652;
  const double _t655 = _t589 - 0.4e1*_t99;
  const double _t656 = _t58*tb;
  const double _t660 = 0.2e1*_t338;
  const double _t671 = _t389*la;
  const double _t672 = _t32*_t671;
  const double _t684 = 0.068655279999999999*_t125;
  const double _t686 = _t327*_t328;
  const double _t691 = _t333*na;
  const double _t692 = _t333*nb;
  const double _t694 = 1.57376*_t99;
  const double _t697 = 0.021298393528888883*_t316;
  const double _t701 = 0.8e1*(_t1 * _t1)*_t454;
  const double _t702 = 0.2e1*_t62;
  const double _t704 = 0.8e1*_t389;
  const double _t705 = _t269*_t62;
  const double _t709 = _t627*_t99 + _t98;
  const double _t712 = 0.2e1*_t61;
  const double _t714 = _t397*_t399;
  const double _t727 = _t247*na;
  const double _t729 = 0.18e2*_t258;
  const double _t734 = 0.2e1*_t163;
  const double _t737 = (0.80e2 / 0.3e1)*_t158*lb;
  const double _t745 = (0.6160e4 / 0.81e2)/xc_powr(nb, 17, 3);
  const double _t746 = _t745*lb;
  const double _t747 = _t580 + _t581;
  const double _t748 = -_t747;
  const double _t749 = (_t62 * _t62 * _t62 * _t62);
  const double _t750 = (_t162 * _t162);
  const double _t751 = (0.440e3 / 0.9e1)*_t412*_t61;
  const double _t752 = _t587 + _t589;
  const double _t753 = -_t752;
  const double _t754 = _t267 + _t626*_t99;
  const double _t755 = _t593 + _t624*_t99;
  const double _t758 = (0.20e2 / 0.3e1)*_t397;
  const double _t760 = 0.13731056*_t125;
  const double _t761 = _t21*_t577;
  const double _t762 = -1.5057777777777777*_t21*_t255 + 0.12012048888888888*_t455 + 1.9863498645222213e-5*_t761;
  const double _t763 = _t459*na;
  const double _t764 = _t13*_t319;
  const double _t765 = _t132*_t21*_t77/xc_powr(_t2, 22, 3);
  const double _t766 = _t488*_t761;
  const double _t767 = xc_powi(_t2, -7);
  const double _t768 = xc_powr(_t2, -23, 3);
  const double _t769 = -0.59016000000000002*_t10*_t13*_t452*na*nb - 0.22885093333333331*_t137*_t178*_t51*na*nb - 6.1323399568053322e-5*_t21*_t328*_t768*na*nb - 0.0099016170488888874*_t21*_t51*_t767*na*nb + _t444*_t763 + _t452*_t684*_t77 + _t763*_t764 + 0.0012299822262933332*_t765 + 0.038950560000000002*_t766;
  const double _t770 = _t314*(0.0028230791599999994*_t21*_t462 - _t762) + _t769;
  const double _t771 = 1.18032*_t10*_t13*_t178*nb + 0.038950560000000002*_t13*_t21*_t255*nb + 0.00052713523983999994*_t132*_t21*_t462*nb - _t452*_t649 - 0.0075520807999999995*_t457 - _t459*_t760 - _t770;
  const double _t772 = -3.0115555555555553*_t21*_t255 + 0.24024097777777775*_t455 + 3.9726997290444426e-5*_t761;
  const double _t773 = _t470*na;
  const double _t774 = -0.59016000000000002*_t10*_t13*_t467*na*nb - 0.22885093333333331*_t137*_t187*_t51*na*nb - 0.00012264679913610664*_t21*_t328*_t768*na*nb - 0.019803234097777775*_t21*_t51*_t767*na*nb + _t444*_t773 + _t467*_t684*_t77 + _t764*_t773 + 0.0024599644525866663*_t765 + 0.077901120000000004*_t766;
  const double _t775 = _t314*(0.0056461583199999988*_t21*_t462 - _t772) + _t774;
  const double _t776 = _t456*na;
  const double _t777 = _t178*na;
  const double _t778 = -0.025967040000000004*_t13*_t21*_t255*nb - 0.00035142349322666661*_t132*_t21*_t462*nb + _t469;
  const double _t779 = -0.0015104161599999999*_t184*_t21*_t51 + _t189 + _t314*(0.002823079159999999*_t21*_t462 - _t762) + _t448 + _t769;
  const double _t780 = 0.39344000000000001*_t10*_t13*_t178*na + 0.78688000000000002*_t10*_t13*_t178*nb + 0.012983520000000002*_t13*_t21*_t255*na + 0.0001757117466133333*_t132*_t21*_t462*na - _t452*_t473 - _t452*_t692 - _t459*_t645 - _t460*_t777 - 0.0025173602666666663*_t776 - _t778 - _t779;
  const double _t781 = _t187*na;
  const double _t782 = -0.025967040000000004*_t13*_t21*_t255*na - 0.00035142349322666661*_t132*_t21*_t462*na + 0.0050347205333333327*_t776;
  const double _t783 = -0.0030208323199999998*_t184*_t21*_t51 + _t314*(0.0056461583199999979*_t21*_t462 - _t772) + _t465 + _t466 + _t774;
  const double _t784 = 0.78688000000000002*_t10*_t13*_t178*na + 0.39344000000000001*_t10*_t13*_t178*nb + 0.012983520000000002*_t13*_t21*_t255*nb + 0.0001757117466133333*_t132*_t21*_t462*nb - _t452*_t691 - _t453 - _t458 - _t461 - _t645*_t777 - _t779 - _t782;
  const double _t785 = 1.18032*_t10*_t13*_t178*na + 0.038950560000000002*_t13*_t21*_t255*na + 0.00052713523983999994*_t132*_t21*_t462*na - _t452*_t727 - _t760*_t777 - _t770 - 0.0075520807999999995*_t776;
  const double _t788 = 0.0056461583199999988*_t14;
  const double _t789 = 0.089161599999999994*_t50;
  const double _t792 = 0.0042170819187199995*nb;
  const double _t793 = 0.31160448000000002*_t535;
  const double _t794 = 0.0792129363911111*_t643;
  const double _t795 = 0.00049058719654442658*_t328*_t636;
  const double _t797 = _t262*_t8;
  const double _t798 = _t40*_t8;
  const double _t806 = (0.20e2 / 0.3e1)*_t389;
  const double _t809 = 0.0037641055466666657*_t14;
  const double _t810 = 0.05944106666666666*_t50;
  const double _t813 = _t13*_t371;
  const double _t814 = _t13*_t374;
  const double _t815 = 0.0053245983822222207*_t316;
  const double _t816 = 0.010649196764444441*_t316;
  const double _t817 = 0.20773632000000003*_t535;
  const double _t818 = 0.0028113879458133329*nb;
  const double _t819 = _t125*_t155;
  const double _t829 = _t6*_t62;
  const double _t831 = 0.0028113879458133329*na;
  const double _t834 = _t418*_t6;
  const double _t835 = 0.0042170819187199995*na;
  const double _t572 = _t313*nb;
  const double _t573 = _t47*_t99*nb;
  const double _t574 = _t122*_t125*nb;
  const double _t596 = _hc3[19]*_t104;
  const double _t597 = _hc4[8]*_t261;
  const double _t598 = _hc4[18]*_t102;
  const double _t600 = _hc4[33]*_t113 + _t598;
  const double _t601 = _hc4[7]*_t261;
  const double _t602 = _hc4[17]*_t102;
  const double _t603 = _hc4[32]*_t113 + _t602;
  const double _t605 = _t252*_t263;
  const double _t606 = _t252*_t266;
  const double _t607 = _hc2[9]*_t261;
  const double _t608 = _hc4[17]*ta;
  const double _t610 = _t608*_t93;
  const double _t611 = _hc4[18]*_t354;
  const double _t612 = _hc2[19]*_t102;
  const double _t613 = _hc4[32]*_t604;
  const double _t614 = _hc4[33]*_t394;
  const double _t615 = _hc0[14]*_t7;
  const double _t618 = _hc0[2]*_t617;
  const double _t620 = _hc1[14]*_t9;
  const double _t621 = _hc0[5]*_t41;
  const double _t622 = _t619*_t621;
  const double _t623 = _t102*_t114;
  const double _t625 = _t113*_t296;
  const double _t629 = _t137*_t306;
  const double _t630 = _t116*_t21;
  const double _t631 = _t14*_t630;
  const double _t632 = _t177*_t45;
  const double _t634 = _t50*_t630;
  const double _t635 = _t45*_t69;
  const double _t637 = -0.2311597037037037*_t118*_t323 + 0.03345871597037036*_t180*_t20 + 1.3417131218226094e-5*_t20*_t451 - 0.0012712639132942216*_t20*_t636;
  const double _t638 = _t123*nb;
  const double _t639 = _t316*_t638;
  const double _t640 = _t13*_t638;
  const double _t642 = _t315*na;
  const double _t644 = _t642*_t643;
  const double _t647 = _t642*_t646;
  const double _t648 = 0.24374828149728389*_t133*_t255*_t77 - 0.022299418024746661*_t23*_t328*_t454*na*nb - 1.4375228997530862*_t23*_t450*_t51*na*nb + 4.7212800000000001*_t24*_t327*na + 0.00086472187673739811*_t23*_t462*_t77/xc_powi(_t12, 5);
  const double _t650 = _t324*na;
  const double _t651 = _t184*_t329;
  const double _t654 = _hc3[9]*_t101;
  const double _t657 = _hc5[32]*_t656;
  const double _t658 = _hc5[33]*_t356;
  const double _t659 = _hc3[34]*_t61 - _t657 - _t658;
  const double _t661 = _t343*_t40;
  const double _t662 = _hc4[8]*_t338;
  const double _t663 = _hc4[18]*_t101;
  const double _t664 = _t598*_t62;
  const double _t665 = _hc4[33]*_t151 + _t663;
  const double _t666 = _hc4[7]*_t338;
  const double _t667 = _hc4[17]*_t101;
  const double _t668 = _t602*_t62;
  const double _t669 = _hc4[32]*_t151 + _t667;
  const double _t670 = _hc2[9]*_t338;
  const double _t673 = _t101*_t115;
  const double _t674 = _hc0[9]*la;
  const double _t675 = _t356*_t398;
  const double _t676 = _hc0[5]*_t62;
  const double _t677 = _t302*_t40*_t61;
  const double _t678 = _t151*_t296;
  const double _t679 = _t152*_t21;
  const double _t680 = _t14*_t679;
  const double _t681 = _t50*_t679;
  const double _t682 = _t637 + 0.0056461583199999988*_t680 - 0.089161599999999994*_t681;
  const double _t683 = _t370*_t77;
  const double _t685 = _t376*_t643;
  const double _t687 = _t46*na;
  const double _t688 = _t380*na;
  const double _t689 = _t13*_t688;
  const double _t690 = -0.22885093333333331*_t137*_t153*_t51*na*nb - 0.22885093333333331*_t137*_t23*_t51 - 0.22885093333333331*_t137*_t46*_t51*na - 0.22885093333333331*_t137*_t51*_t65*nb + _t246 + _t249 + _t319*_t689 + _t320 + _t444*_t687 + _t444*_t688 + _t445 + _t446 + _t648;
  const double _t693 = _t66*_t99*na;
  const double _t695 = _t65*na;
  const double _t696 = _t316*_t695;
  const double _t698 = _t125*_t154;
  const double _t699 = _t651*na;
  const double _t700 = _hc3[3]*_t581;
  const double _t703 = _hc2[19]*_t164;
  const double _t706 = _hc4[33]*_t385;
  const double _t707 = _hc5[17]*tb;
  const double _t708 = _hc3[19]*_t163 + _hc5[18]*_t392 + _t159*_t707 - _t61*_t657 - _t61*_t658 + _t61*_t659;
  const double _t710 = _t164*_t296;
  const double _t711 = _t115*_t163;
  const double _t713 = _t115*_t712;
  const double _t715 = _hc1[9]*_t104;
  const double _t716 = _t397*_t398;
  const double _t717 = _t43*_t581 - _t44*_t581;
  const double _t718 = _t137*_t368;
  const double _t719 = _t177*_t64;
  const double _t720 = _t171*_t21;
  const double _t721 = _t64*_t69;
  const double _t722 = _t407*na;
  const double _t723 = _t13*_t722;
  const double _t724 = _t316*_t722;
  const double _t725 = _t406*_t77;
  const double _t726 = _t686*_t695;
  const double _t728 = _t125*_t172*na;
  const double _t730 = _hc5[18]*_t163;
  const double _t731 = _hc5[33]*_t169 + _t730;
  const double _t732 = _hc5[17]*_t163;
  const double _t733 = _hc5[32]*_t169 + _t732;
  const double _t735 = _hc3[9]*_t416 + _hc5[18]*_t420*lb + _t343*_t734 - _t356*_t731 - _t413*_t419 - _t413*_t421 + _t420*_t707 + _t61*_t708 - _t656*_t733;
  const double _t736 = _hc1[9]*_t169;
  const double _t738 = _hc1[2]*_t737;
  const double _t739 = _t394*_t676;
  const double _t740 = _t114*_t162;
  const double _t741 = _hc1[5]*_t61;
  const double _t742 = _t14*_t720;
  const double _t743 = _t50*_t720;
  const double _t744 = _t442*na;
  const double _t756 = _hc5[8]*_t416;
  const double _t757 = _hc5[7]*_t416;
  const double _t759 = _t741*_t758;
  const double _t786 = _hc0[9]*_t6;
  const double _t787 = _t195*_t21;
  const double _t790 = _t309*_t73 + _t310*_t72 - _t311*_t72;
  const double _t791 = _t486*na;
  const double _t796 = -0.31160448000000002*_t13*_t176*_t21*_t72*na*nb - 0.0098398578103466652*_t132*_t21*_t72*_t96*na*nb + _t199*_t794 + _t72*_t77*_t795;
  const double _t799 = _hc5[18]*_t798;
  const double _t800 = _t398*_t8;
  const double _t801 = _t204*_t21;
  const double _t802 = _t309*_t79 + _t310*_t78 - _t311*_t78;
  const double _t803 = _t500*na;
  const double _t804 = _t79*nb;
  const double _t805 = -0.31160448000000002*_t13*_t176*_t21*_t78*na*nb - 0.0098398578103466652*_t132*_t21*_t78*_t96*na*nb + _t77*_t78*_t795 + _t77*_t79*_t794;
  const double _t807 = _t482*_t62;
  const double _t808 = _t21*_t211;
  const double _t811 = _t117*_t507 + _t790;
  const double _t812 = _t509*na;
  const double _t820 = -0.39344000000000001*_t10*_t13*_t196*na - 0.10386816000000001*_t10*_t13*_t21*_t72 - 0.39344000000000001*_t10*_t13*_t212*nb - 0.39344000000000001*_t10*_t13*_t508*na*nb + _t197*_t460 + _t460*_t508*_t77 + _t479 + _t520 + _t796;
  const double _t821 = _hc5[33]*_t61*_t8 - _t341;
  const double _t822 = _hc1[5]*_t214;
  const double _t823 = _t21*_t215;
  const double _t824 = _t117*_t512 + _t802;
  const double _t825 = _t514*na;
  const double _t826 = _t79*na;
  const double _t827 = -0.39344000000000001*_t10*_t13*_t205*na - 0.10386816000000001*_t10*_t13*_t21*_t78 - 0.39344000000000001*_t10*_t13*_t216*nb - 0.39344000000000001*_t10*_t13*_t513*na*nb + _t206*_t460 + _t460*_t513*_t77 + _t495 + _t525 + _t805;
  const double _t828 = _t212*na;
  const double _t830 = _hc4[18]*_t829;
  const double _t832 = _t216*na;
  const double _t833 = -_t341*_t61 + _t387 + _t61*_t821 + _t730*_t8;
  const double _t836 = _t21*_t220;
  const double _t837 = _t218*_t310 - _t218*_t311 + _t223*_t309;
  const double _t838 = _t532*na;
  const double _t839 = _t218*_t490;
  const double _t840 = -0.31160448000000002*_hc4[1]*_t13*_t176*_t21*_t82*nb - 0.0098398578103466652*_hc4[1]*_t132*_t21*_t82*_t96*nb + _t225*_t794*nb + _t795*_t83*nb;
  const double _t841 = _hc5[17]*_t798;
  const double _t842 = _t21*_t231;
  const double _t843 = _t228*_t310 - _t228*_t311 + _t244*_t309;
  const double _t844 = _t545*na;
  const double _t845 = -0.31160448000000002*_hc5[1]*_t13*_t176*_t21*_t85*na - 0.0098398578103466652*_hc5[1]*_t132*_t21*_t85*_t96*na + _t234*_t794*na + _t795*_t86*na;
  const double _t846 = _t21*_t238;
  const double _t847 = _t117*_t551 + _t837;
  const double _t848 = _t553*na;
  const double _t849 = -0.10386816000000001*_hc4[1]*_t10*_t13*_t21*_t6 - 0.39344000000000001*_t10*_t13*_t221*na - 0.39344000000000001*_t10*_t13*_t239*nb - 0.39344000000000001*_t10*_t13*_t552*na*nb + _t222*_t460 + _t460*_t552*_t77 + _t534 + _t564 + _t840;
  const double _t850 = _hc5[32]*_t61*_t8 - _t339;
  const double _t851 = _t21*_t241;
  const double _t852 = _t117*_t556 + _t843;
  const double _t853 = _t558*na;
  const double _t854 = _t228*_t490;
  const double _t855 = -0.10386816000000001*_hc5[1]*_t10*_t13*_t21*_t8 - 0.39344000000000001*_t10*_t13*_t232*na - 0.39344000000000001*_t10*_t13*_t242*nb - 0.39344000000000001*_t10*_t13*_t557*na*nb + _t233*_t460 + _t460*_t557*_t77 + _t569 + _t570 + _t845;
  const double _t856 = _t239*na;
  const double _t857 = _t242*na;
  const double _t858 = -_t339*_t61 + _t386 + _t61*_t850 + _t732*_t8;
  const double _t859 = _hc4[17]*_t829;
  const double d4F_dna4 = 2.3606400000000001*_t10*_t122*_t13*nb + 0.78688000000000002*_t10*_t13*_t313*na*nb + 0.45770186666666662*_t122*_t137*_t51*na*nb + 4.7212800000000001*_t13*_t176*_t23*nb + 4.7212800000000001*_t13*_t176*_t46*na*nb + 0.14908875470222219*_t132*_t23*_t96*nb + 0.14908875470222219*_t132*_t46*_t96*na*nb + 0.91540373333333325*_t137*_t46*_t51*nb - _t314*(_t22*(_hc2[3]*_t582 + _hc3[3]*_t583 + _hc3[34]*_t584 + _hc3[9]*_t585 + _hc3[9]*_t592 + _hc4[1]*_t575*ta + _hc4[2]*_t576 + 0.3e1*_t102*_t290 + _t103*_t596 + 0.3e1*_t109*_t261 + _t19*(-_hc0[9]*_t295*_t619 + (_t102 * _t102)*_t114 - _t102*_t622 + _t103*_t359 + _t114*_t261*_t599 + _t115*_t585 + _t115*_t592 + _t150*_t590 + _t150*_t591 + _t16*_t576 - 0.1760e4 / 0.27e2*_t251*_t294*la - _t261*_t352 - _t270*_t622 + _t270*_t623 + _t271*_t359 + _t299*_t617*la - _t303*_t590 + _t359*_t595 + (_t41 * _t41 * _t41 * _t41)*_t615 + _t43*_t582 + _t44*_t583 + _t584*_t620 + _t616*_t618 + _t625*_t628 + _t625*(-_t267 + _t626*_t99) + _t625*(-_t593 + _t624*_t99)) - _t263*_t586 - _t266*_t586 + _t271*_t596 + _t272*_t590 + _t272*_t591 + _t274*_t293 + _t277*_t292*ta - _t394*(_t41*_t600 + _t597 + _t598*_t599) + _t41*(_hc4[18]*_t41*_t609 + _t265*_t608 + _t279*_t289 - _t394*_t600 + _t41*(-_t41*_t613 - _t41*_t614 + _t41*(_hc2[34]*_t41 - _t613 - _t614) + _t610 + _t611 + _t612) - _t603*_t604 - _t605 - _t606 + _t607) + _t579 + _t595*_t596 - _t604*(_t41*_t603 + _t599*_t602 + _t601)) + _t304*_t633 + 0.27739164444444442*_t629 + 0.011292316639999998*_t631 + 0.00063563195664711081*_t632 - 0.17832319999999996*_t634 - 0.030112844373333326*_t635 + _t637) - 0.063895180586666656*_t317 - 1.2001960059259258*_t325 - 0.00743313934158222*_t330 - _t571*_t572 - _t572*_t645*na - 4.7212800000000001*_t573 - 0.27462112*_t574 - 0.031947590293333328*_t639 - _t640*_t641 - 1.2001960059259258*_t644 - 0.00743313934158222*_t647 - _t648;
  const double d4F_dna3_dnb = 0.59016000000000002*_t10*_t122*_t13*na + 0.59016000000000002*_t10*_t122*_t13*nb + 1.18032*_t10*_t13*_t153*nb + 0.19672000000000001*_t10*_t13*_t313*na*nb + 0.59016000000000002*_t10*_t13*_t370*na*nb + 1.18032*_t10*_t13*_t46 + 0.22885093333333334*_t122*_t137*_t51*na*nb + 1.18032*_t13*_t176*_t23*na + 3.5409600000000001*_t13*_t176*_t23*nb + 3.5409600000000001*_t13*_t176*_t46*na*nb + 1.18032*_t13*_t176*_t65*na*nb + 0.037272188675555547*_t132*_t23*_t96*na + 0.11181656602666665*_t132*_t23*_t96*nb + 0.11181656602666665*_t132*_t46*_t96*na*nb + 0.037272188675555547*_t132*_t65*_t96*na*nb + 0.45770186666666668*_t137*_t46*_t51*nb - _t248 - _t250 - _t313*_t473 - _t314*(_t22*(_hc2[3]*_t652 + _hc3[3]*_t653 + _t101*_t290 - _t103*_t654 + _t103*_t661 + _t109*_t660 + _t145*_t260 + _t19*(-_hc1[9]*_t262*_t356 + _t101*_t114*_t270 + _t101*_t623 + _t102*_t678 - _t103*_t673 - _t103*_t675 + _t103*_t677 - _t146*_t260*lb - _t148*_t252*la + _t150*_t337 + _t150*_t655 + _t260*_t358 + _t261*_t366 + _t262*_t61*_t620 + _t270*_t678 - _t271*_t673 - _t271*_t675 + _t271*_t677 + _t293*_t360 + _t295*_t364*_t615 - _t297*_t338*la - _t300*_t365*_t674 - _t300*_t616*_t676 + _t303*_t338 - _t303*_t655 - _t359*_t594 + _t43*_t652 + _t44*_t653 + _t594*_t625 + _t618*_t671 - 0.20e2*_t621*_t672) + _t262*_t659 + _t264*_t346*ta - _t271*_t654 + _t271*_t661 + _t272*_t337 + _t272*_t655 + _t279*_t350 + _t344*_t609 - _t394*(_t41*_t663 + _t41*_t665 + _t662 + _t664) + _t41*(_t101*_t289 - _t394*_t665 + _t41*(_hc2[19]*_t101 + _hc2[34]*_t41*_t62 - _t613*_t62 - _t614*_t62) - _t604*_t669 + _t610*_t62 + _t611*_t62 + _t612*_t62 + _t670) + _t579 - _t594*_t596 - _t604*(_t41*_t667 + _t41*_t669 + _t666 + _t668) - _t605*_t62 - _t606*_t62 + _t607*_t62) + _t30*_t304 + _t305*_t367 + _t309*_t368 + _t310*_t64 - _t311*_t64 + 0.20804373333333334*_t629 + 0.0056461583199999979*_t631 + 0.00047672396748533314*_t632 - 0.08916159999999998*_t634 - 0.022584633279999995*_t635 + _t682) - 0.031947590293333328*_t317 - _t319*_t640 - _t322 - 0.9001470044444444*_t325 - 0.0055748545061866652*_t330 - _t331*_t65*_t686 - _t331*_t651 - _t370*_t649 - 0.13731056*_t381 - _t444*_t638 - _t510*_t572 - 2.3606400000000001*_t573 - 0.068655279999999985*_t574 - 0.9001470044444444*_t644 - 0.0055748545061866652*_t647 - 0.30004900148148145*_t650 - _t683*_t684 - 0.30004900148148145*_t685 - _t690;
  const double d4F_dna2_dnb2 = 0.39344000000000001*_t10*_t122*_t13*na + 0.78688000000000002*_t10*_t13*_t153*na + 0.78688000000000002*_t10*_t13*_t153*nb + 0.39344000000000001*_t10*_t13*_t172*nb + 0.39344000000000001*_t10*_t13*_t370*na*nb + 0.39344000000000001*_t10*_t13*_t406*na*nb + 0.78688000000000002*_t10*_t13*_t46 + 0.78688000000000002*_t10*_t13*_t65 + 0.076283644444444437*_t122*_t137*_t51*na*nb - 0.091540373333333327*_t126 - 1.57376*_t129 + 2.3606400000000001*_t13*_t176*_t23*na + 2.3606400000000001*_t13*_t176*_t23*nb + 2.3606400000000001*_t13*_t176*_t46*na*nb + 2.3606400000000001*_t13*_t176*_t65*na*nb + 0.074544377351111094*_t132*_t23*_t96*na + 0.074544377351111094*_t132*_t23*_t96*nb + 0.074544377351111094*_t132*_t46*_t96*na*nb + 0.074544377351111094*_t132*_t65*_t96*na*nb - 0.021298393528888883*_t134 + 0.30513457777777775*_t137*_t153*_t51*na*nb + 0.076283644444444437*_t137*_t172*_t51*na*nb + 0.30513457777777775*_t137*_t23*_t51 + 0.30513457777777775*_t137*_t46*_t51*na + 0.15256728888888887*_t137*_t46*_t51*nb + 0.15256728888888887*_t137*_t51*_t65*na + 0.30513457777777775*_t137*_t51*_t65*nb - _t153*_t571 - 0.091540373333333327*_t156 - _t314*(_t117*_t367 + _t117*_t403 + _t119*_t630 + _t119*_t720 - _t120*_t630 - _t120*_t720 + _t22*(_hc2[3]*_t581 + _hc3[9]*_t701 - _t100*_t109 + _t103*_t388 + _t104*_t708 - _t109*_t259 + _t162*_t281 + _t162*_t283 + _t162*_t284 + _t164*_t610 + _t164*_t611 + _t19*(-_hc0[5]*_t361*_t401*la + _hc1[2]*_t103*_t392 - _hc1[5]*_t103*_t714 + _t103*_t402 + _t103*_t711 + _t104*_t169*_t620 + 0.20e2*_t111*_t258*la + _t113*_t164*_t615 + _t114*_t701 + _t115*_t701 + _t150*_t268 + _t150*_t589 + _t162*_t623 + _t163*_t359 - _t167*_t337*lb - _t268*_t303 - _t303*_t589 + _t337*_t713 + _t353 + _t354*_t395 + _t354*_t396 + _t357*_t392 - _t361*_t385*_t674 + _t366*_t660 + (0.40e2 / 0.3e1)*_t389*_t716 + _t625*_t709 + _t628*_t710 - 0.40e2 / 0.3e1*_t672*_t676 - _t677*_t704 + _t678*_t704 - _t714*_t715 + _t717) + _t268*_t272 + _t269*_t350 + _t272*_t589 + _t337*_t429 - _t394*(_hc4[18]*_t401 + _hc4[18]*_t705 - _hc4[8]*_t100 - _hc4[8]*_t259 + _t706) + _t41*(0.4e1*_hc2[19]*_t1*_t62*_t99 + _hc2[19]*_t162*_t41 + _hc2[34]*_t164*_t384 - _hc2[9]*_t100 - _hc2[9]*_t259 - _t162*_t286 - _t162*_t288 - _t164*_t613 - _t164*_t614) + _t579 - _t604*(_hc4[17]*_t401 + _hc4[17]*_t705 + _hc4[32]*_t385 - _hc4[7]*_t100 - _hc4[7]*_t259) + _t628*_t703 - _t661*_t704 + _t670*_t702 - _t700) + 0.13869582222222221*_t629 + 0.00031781597832355541*_t632 - 0.015056422186666661*_t635 + _t637 + 0.0075282110933333314*_t680 - 0.11888213333333332*_t681 + 0.13869582222222221*_t718 + 0.00031781597832355541*_t719 - 0.015056422186666661*_t721) - 0.045770186666666664*_t321 - 0.6000980029629629*_t325 - 0.00371656967079111*_t330 - _t370*_t691 - _t371*_t640 - _t371*_t723 - _t375*_t697 - _t378 - 0.091540373333333327*_t381 - _t406*_t692 - 0.045770186666666664*_t408 - _t460*_t683 - _t460*_t725 - _t48*_t694 - 0.78688000000000002*_t573 - 0.0053245983822222207*_t639 - 0.6000980029629629*_t644 - 0.00371656967079111*_t647 - _t648 - 0.6000980029629629*_t650 - _t67*_t694 - 0.6000980029629629*_t685 - _t687*_t697 - _t688*_t697 - _t689*_t694 - 0.78688000000000002*_t693 - 0.010649196764444441*_t696 - 0.091540373333333327*_t698 - 0.00371656967079111*_t699 - 0.0053245983822222207*_t724 - 0.00371656967079111*_t726;
  const double d4F_dna_dnb3 = 1.18032*_t10*_t13*_t153*na + 0.59016000000000002*_t10*_t13*_t172*na + 0.59016000000000002*_t10*_t13*_t172*nb + 0.59016000000000002*_t10*_t13*_t406*na*nb + 0.19672000000000001*_t10*_t13*_t442*na*nb + 1.18032*_t10*_t13*_t65 - _t125*_t379*_t744 + 3.5409600000000001*_t13*_t176*_t23*na + 1.18032*_t13*_t176*_t23*nb + 1.18032*_t13*_t176*_t46*na*nb + 3.5409600000000001*_t13*_t176*_t65*na*nb + 0.11181656602666665*_t132*_t23*_t96*na + 0.037272188675555547*_t132*_t23*_t96*nb + 0.037272188675555547*_t132*_t46*_t96*na*nb + 0.11181656602666665*_t132*_t65*_t96*na*nb + 0.22885093333333331*_t137*_t172*_t51*na*nb + 0.45770186666666662*_t137*_t51*_t65*na - _t314*(_t22*(0.6e1*_hc2[19]*_t1*_t164*_t99 + _hc2[19]*_t162*_t41*_t62 + _hc2[19]*_t41*_t422*_t62 + 0.24e2*_hc2[3]*_t1*_t184 + 0.12e2*_hc2[3]*_t176 + _hc2[34]*_t384*_t418 + 0.6e1*_hc2[9]*_t1*_t162*_t99 + _hc2[9]*_t41*_t417 - _hc3[3]*_t588 + 0.18e2*_t1*_t145*_t176 - _t106*_t417 - _t108*_t417 + 0.6e1*_t145*_t99 - _t162*_t348 - _t162*_t349 + (0.1e1 / 0.32e2)*_t18*(-_hc0[2]*_t394*_t417 - _hc0[9]*_t394*_t418 + _t150*_t416 + _t162*_t678 - _t162*_t739 + _t163*_t677 + _t257*_t358 - _t257*_t366 - 0.30e2*_t258*_t390 + _t303*_t417 + _t358*_t729 - _t366*_t729 + _t384*_t418*_t615 + 0.20e2*_t389*_t397*_t741 - _t389*_t738 - 0.10e2*_t390*_t99 - _t393*_t413*lb + _t398*_t432*_t61 + _t40*_t434*_t620 - _t40*_t436*_t736*lb - _t402*_t594 + _t422*_t678 - _t422*_t739 + _t43*_t588 - _t438*_t716 - _t44*_t588 + _t440*_t677 + _t594*_t710 - _t594*_t711 + _t594*_t740 + _t717) - _t257*_t383 - _t348*_t422 - _t349*_t422 - _t383*_t729 - _t388*_t594 + _t40*_t735 - _t418*_t613 - _t418*_t614 - _t578 - _t700) + _t30*_t441 + _t305*_t403 + _t306*_t309 + _t310*_t45 - _t311*_t45 + _t682 + 0.20804373333333331*_t718 + 0.00047672396748533314*_t719 - 0.022584633279999992*_t721 + 0.0056461583199999988*_t742 - 0.089161599999999994*_t743) - _t315*_t331*_t646 - _t319*_t723 - _t326 - 0.001858284835395555*_t330 - _t406*_t727 - _t410 - _t411 - _t443 - _t444*_t722 - _t447 - 0.30004900148148145*_t644 - 0.9001470044444444*_t650 - _t684*_t725 - 0.9001470044444444*_t685 - _t690 - 2.3606400000000001*_t693 - 0.031947590293333328*_t696 - 0.13731056*_t698 - 0.0055748545061866652*_t699 - 0.0055748545061866652*_t726 - 0.068655279999999999*_t728;
  const double d4F_dnb4 = 2.3606400000000001*_t10*_t13*_t172*na + 0.78688000000000002*_t10*_t13*_t442*na*nb + 4.7212800000000001*_t13*_t176*_t23*na + 4.7212800000000001*_t13*_t176*_t65*na*nb + 0.14908875470222219*_t132*_t23*_t96*na + 0.14908875470222219*_t132*_t65*_t96*na*nb + 0.45770186666666662*_t137*_t172*_t51*na*nb + 0.91540373333333325*_t137*_t51*_t65*na - _t314*(_t22*(_hc2[3]*_t747 + _hc2[34]*_t749 + _hc2[9]*_t162*_t422 + _hc2[9]*_t750 + _hc3[3]*_t748 + _hc5[1]*_t745*tb + _hc5[2]*_t746 + 0.3e1*_t145*_t416 + 0.3e1*_t163*_t388 + _t19*(_t114*_t417*_t702 + _t114*_t750 + _t115*(_t163 * _t163) + _t163*_t402 + _t163*_t738 - _t163*_t759 + _t17*_t746 + _t170*_t737 + _t358*_t752 + _t366*_t753 - _t391*_t416 + _t402*_t440 + _t402*(-_t593 - _t594) - 0.1760e4 / 0.27e2*_t412*_t433*lb + _t416*_t713 + _t422*_t740 + _t43*_t747 - _t435*_t758 + _t44*_t748 + _t440*_t711 - _t440*_t759 + (_t61 * _t61 * _t61 * _t61)*_t620 + _t615*_t749 + _t709*_t710 + _t710*_t754 + _t710*_t755) - _t356*(_t61*_t731 + _t712*_t730 + _t756) + 0.2e1*_t383*_t417 + _t383*_t753 - _t419*_t751 - _t421*_t751 + _t424*_t432 + _t427*_t431*tb + _t579 + _t61*_t735 - _t656*(_t61*_t733 + _t712*_t732 + _t757) + _t703*_t709 + _t703*_t754 + _t703*_t755) + _t441*_t633 + _t637 + 0.27739164444444442*_t718 + 0.00063563195664711081*_t719 - 0.030112844373333326*_t721 + 0.011292316639999998*_t742 - 0.17832319999999996*_t743) - _t571*_t744 - _t641*_t723 - _t645*_t744*nb - _t648 - 1.2001960059259258*_t650 - 1.2001960059259258*_t685 - 4.7212800000000001*_t693 - 0.063895180586666656*_t696 - 0.00743313934158222*_t699 - 0.031947590293333328*_t724 - 0.00743313934158222*_t726 - 0.27462112*_t728;
  const double d4F_dna3_dgaa = _t771;
  const double d4F_dna3_dgab = 1.18032*_t10*_t13*_t187*nb + 0.077901120000000004*_t13*_t21*_t255*nb + 0.0010542704796799999*_t132*_t21*_t462*nb - 0.015104161599999999*_t457 - _t467*_t649 - _t470*_t760 - _t775;
  const double d4F_dna3_dgbb = _t771;
  const double d4F_dna2_dnb_dgaa = _t780;
  const double d4F_dna2_dnb_dgab = 0.39344000000000001*_t10*_t13*_t187*na + 0.78688000000000002*_t10*_t13*_t187*nb + 0.051934080000000007*_t13*_t21*_t255*nb + 0.00070284698645333322*_t132*_t21*_t462*nb - 0.010069441066666665*_t457 - _t460*_t781 - _t467*_t473 - _t467*_t692 - _t470*_t645 - _t782 - _t783;
  const double d4F_dna2_dnb_dgbb = _t780;
  const double d4F_dna_dnb2_dgaa = _t784;
  const double d4F_dna_dnb2_dgab = 0.78688000000000002*_t10*_t13*_t187*na + 0.39344000000000001*_t10*_t13*_t187*nb + 0.051934080000000007*_t13*_t21*_t255*na + 0.00070284698645333322*_t132*_t21*_t462*na - _t467*_t691 - _t468 - _t471 - _t645*_t781 - 0.010069441066666665*_t776 - _t778 - _t783;
  const double d4F_dna_dnb2_dgbb = _t784;
  const double d4F_dnb3_dgaa = _t785;
  const double d4F_dnb3_dgab = 1.18032*_t10*_t13*_t187*na + 0.077901120000000004*_t13*_t21*_t255*na + 0.0010542704796799999*_t132*_t21*_t462*na - _t467*_t727 - _t760*_t781 - _t775 - 0.015104161599999999*_t776;
  const double d4F_dnb3_dgbb = _t785;
  const double d4F_dna3_dla = 1.18032*_t10*_t13*_t196*nb + 0.59016000000000002*_t10*_t13*_t485*na*nb + 0.22885093333333331*_t137*_t196*_t51*na*nb + 0.060416646399999996*_t137*_t21*_t51*_t72*nb - _t314*(_t22*(_hc4[8]*_t265 + _t19*(_t102*_t506 + _t210*_t261 + _t270*_t506 - _t291 + _t292*_t294 + _t295*_t786 - _t298 - _t301) - _t254 - _t275 + _t279*_t481 + _t41*(_t282 - _t287*_t41 + _t41*(_hc4[33]*_t41*_t6 - _t287) + _t598*_t6) + _t597*_t6) + _t305*_t483 + _t787*_t788 - _t787*_t789 + _t790) - _t444*_t791 - _t485*_t649 - _t485*_t684*_t77 - _t486*_t760 - _t491*_t792 - _t505*_t793 - _t764*_t791 - _t796;
  const double d4F_dna3_dlb = 1.18032*_t10*_t13*_t205*nb + 0.59016000000000002*_t10*_t13*_t499*na*nb + 0.22885093333333331*_t137*_t205*_t51*na*nb + 0.060416646399999996*_t137*_t21*_t51*_t78*nb - _t314*(_t22*(_hc5[33]*_t797 + _t103*_t799 + _t19*(_hc1[9]*_t797 + _t103*_t800 + _t203*_t260 + _t271*_t800) + _t202*_t260 + _t271*_t799) + _t305*_t497 + _t788*_t801 - _t789*_t801 + _t802) - _t444*_t803 - _t499*_t649 - _t499*_t684*_t77 - _t500*_t760 - _t502*_t792 - _t764*_t803 - _t793*_t804 - _t805;
  const double d4F_dna2_dnb_dla = 0.39344000000000001*_t10*_t13*_t196*nb + 0.19672000000000001*_t10*_t13*_t485*na*nb + 0.15256728888888887*_t137*_t196*_t51*na*nb + 0.020138882133333331*_t137*_t21*_t51*_t72*na + 0.040277764266666662*_t137*_t21*_t51*_t72*nb + 0.076283644444444437*_t137*_t212*_t51*na*nb - _t314*(_t119*_t808 - _t120*_t808 + _t22*(_t101*_t481 + _t19*(_t102*_t807 - _t111*_t806 + _t148*_t93 + _t210*_t338 + _t269*_t506 - _t362 + _t365*_t786) + _t282*_t62 - _t345 + _t41*(_hc4[33]*_t194*_t62 - _t287*_t62 + _t6*_t663) + _t6*_t662 + _t6*_t664) + _t30*_t483 + _t787*_t809 - _t787*_t810 + _t811) - _t473*_t485 - _t477 - _t485*_t819 - _t487 - _t491*_t548 - _t491*_t818 - _t504*_t536 - _t505*_t817 - _t508*_t692 - _t791*_t814 - _t791*_t816 - _t812*_t813 - _t812*_t815 - _t820;
  const double d4F_dna2_dnb_dlb = 0.39344000000000001*_t10*_t13*_t205*nb + 0.19672000000000001*_t10*_t13*_t499*na*nb + 0.15256728888888887*_t137*_t205*_t51*na*nb + 0.020138882133333331*_t137*_t21*_t51*_t78*na + 0.040277764266666662*_t137*_t21*_t51*_t78*nb + 0.076283644444444437*_t137*_t216*_t51*na*nb - _t314*(_t119*_t823 - _t120*_t823 + _t22*(_t103*_t511 + _t104*_t821 + _t19*(_t103*_t822 + _t203*_t337 + _t214*_t715 - _t269*_t800 - _t355 - _t357*_t58) + _t202*_t337 - _t269*_t799) + _t30*_t497 + _t801*_t809 - _t801*_t810 + _t824) - _t473*_t499 - _t494 - _t499*_t819 - _t501 - _t502*_t548 - _t502*_t818 - _t513*_t692 - _t536*_t826 - _t803*_t814 - _t803*_t816 - _t804*_t817 - _t813*_t825 - _t815*_t825 - _t827;
  const double d4F_dna_dnb2_dla = 0.39344000000000001*_t10*_t13*_t212*na + 0.19672000000000001*_t10*_t13*_t518*na*nb + 0.076283644444444437*_t137*_t196*_t51*na*nb + 0.040277764266666662*_t137*_t21*_t51*_t72*na + 0.020138882133333331*_t137*_t21*_t51*_t72*nb + 0.15256728888888887*_t137*_t212*_t51*na*nb - _t314*(_t119*_t787 - _t120*_t787 + _t22*(-_t100*_t209 - _t107*_t162 + _t162*_t480 - _t164*_t287 + _t19*(0.4e1*_hc0[5]*_t1*_t6*_t62*_t99 + _hc0[5]*_t162*_t41*_t6 + _hc0[9]*_t164*_t384*_t6 - _t100*_t210 - _t210*_t259 - _t33*_t395 - _t33*_t396) - _t209*_t259 + _t269*_t830 + _t6*_t706) + _t30*_t517 + _t808*_t809 - _t808*_t810 + _t811) - _t460*_t828 - _t491*_t538 - _t491*_t831 - _t504*_t817 - _t505*_t536 - _t508*_t691 - _t515 - _t518*_t819 - _t519 - _t791*_t813 - _t791*_t815 - _t812*_t814 - _t812*_t816 - _t820;
  const double d4F_dna_dnb2_dlb = 0.39344000000000001*_t10*_t13*_t216*na + 0.19672000000000001*_t10*_t13*_t523*na*nb + 0.076283644444444437*_t137*_t205*_t51*na*nb + 0.040277764266666662*_t137*_t21*_t51*_t78*na + 0.020138882133333331*_t137*_t21*_t51*_t78*nb + 0.15256728888888887*_t137*_t216*_t51*na*nb - _t314*(_t119*_t801 - _t120*_t801 + _t22*(_t100*_t202 + _t19*(_t100*_t203 + _t159*_t393 + _t163*_t800 + _t166*_t806 + _t203*_t259 - _t269*_t822 - _t400*_t57 + _t736*_t798) + _t202*_t259 - _t269*_t511 + _t40*_t833) + _t30*_t522 + _t809*_t823 - _t810*_t823 + _t824) - _t460*_t832 - _t502*_t538 - _t502*_t831 - _t513*_t691 - _t521 - _t523*_t819 - _t524 - _t536*_t804 - _t803*_t813 - _t803*_t815 - _t814*_t825 - _t816*_t825 - _t817*_t826 - _t827;
  const double d4F_dnb3_dla = 1.18032*_t10*_t13*_t212*na + 0.59016000000000002*_t10*_t13*_t518*na*nb + 0.060416646399999996*_t137*_t21*_t51*_t72*na + 0.22885093333333331*_t137*_t212*_t51*na*nb - _t314*(_t22*(_hc4[33]*_t834 + _t162*_t830 + _t19*(_t162*_t807 + _t210*_t417 + _t418*_t786 + _t422*_t807) + _t209*_t417 + _t422*_t830) + _t305*_t517 + _t788*_t808 - _t789*_t808 + _t790) - _t444*_t812 - _t491*_t835 - _t504*_t793 - _t518*_t684*_t77 - _t518*_t727 - _t760*_t828 - _t764*_t812 - _t796;
  const double d4F_dnb3_dlb = 1.18032*_t10*_t13*_t216*na + 0.59016000000000002*_t10*_t13*_t523*na*nb + 0.060416646399999996*_t137*_t21*_t51*_t78*na + 0.22885093333333331*_t137*_t216*_t51*na*nb - _t314*(_t22*(_hc5[8]*_t420 + _t19*(_t163*_t822 + _t203*_t416 - _t430 + _t431*_t433 + _t435*_t8 - _t437 - _t439 + _t440*_t822) - _t415 - _t425 + _t511*_t734 + _t61*_t833 + _t756*_t8) + _t305*_t522 + _t788*_t823 - _t789*_t823 + _t802) - _t444*_t825 - _t502*_t835 - _t523*_t684*_t77 - _t523*_t727 - _t760*_t832 - _t764*_t825 - _t793*_t826 - _t805;
  const double d4F_dna3_dta = 0.060416646399999996*_hc4[1]*_t137*_t21*_t51*_t6*nb + 1.18032*_t10*_t13*_t221*nb + 0.59016000000000002*_t10*_t13*_t531*na*nb + 0.22885093333333331*_t137*_t221*_t51*na*nb - _t314*(_t22*(_hc4[7]*_t265 - _t253 - _t278 + _t279*_t528 + _t41*(_t280 - _t285*_t41 + _t41*(_hc4[32]*_t41*_t6 - _t285) + _t6*_t602) + _t6*_t601) + _t305*_t529 + _t788*_t836 - _t789*_t836 + _t837) - _t444*_t838 - _t531*_t649 - _t531*_t684*_t77 - _t532*_t760 - _t554*_t793 - _t764*_t838 - _t792*_t839 - _t840;
  const double d4F_dna3_dtb = 0.060416646399999996*_hc5[1]*_t137*_t21*_t51*_t85 + 1.18032*_t10*_t13*_t232*nb + 0.59016000000000002*_t10*_t13*_t544*na*nb + 0.22885093333333331*_t137*_t232*_t51*na*nb - _t234*_t793 - _t314*(_t22*(_hc5[32]*_t797 + _t103*_t841 + _t230*_t260 + _t271*_t841) + _t305*_t542 + _t788*_t842 - _t789*_t842 + _t843) - _t444*_t844 - _t544*_t649 - _t544*_t684*_t77 - _t545*_t760 - 0.0042170819187199995*_t549 - _t764*_t844 - _t845;
  const double d4F_dna2_dnb_dta = 0.040277764266666662*_hc4[1]*_t137*_t21*_t51*_t6*nb + 0.020138882133333331*_hc4[1]*_t137*_t21*_t51*_t82 + 0.39344000000000001*_t10*_t13*_t221*nb + 0.19672000000000001*_t10*_t13*_t531*na*nb + 0.15256728888888887*_t137*_t221*_t51*na*nb + 0.076283644444444437*_t137*_t239*_t51*na*nb - _t314*(_t119*_t846 - _t120*_t846 + _t22*(_t101*_t528 + _t280*_t62 - _t347 + _t41*(_hc4[32]*_t194*_t62 - _t285*_t62 + _t6*_t667) + _t6*_t666 + _t6*_t668) + _t30*_t529 + _t809*_t836 - _t810*_t836 + _t847) - _t473*_t531 - _t526 - _t531*_t819 - _t533 - _t537 - 0.0014056939729066664*_t539 - _t552*_t692 - _t554*_t817 - _t813*_t848 - _t814*_t838 - _t815*_t848 - _t816*_t838 - _t818*_t839 - _t849;
  const double d4F_dna2_dnb_dtb = 0.020138882133333331*_hc5[1]*_t137*_t21*_t51*_t8*na + 0.040277764266666662*_hc5[1]*_t137*_t21*_t51*_t85 + 0.39344000000000001*_t10*_t13*_t232*nb + 0.19672000000000001*_t10*_t13*_t544*na*nb + 0.15256728888888887*_t137*_t232*_t51*na*nb + 0.076283644444444437*_t137*_t242*_t51*na*nb - _t234*_t817 - _t314*(_t119*_t851 - _t120*_t851 + _t22*(_t103*_t555 + _t104*_t850 + _t230*_t337 - _t269*_t841) + _t30*_t542 + _t809*_t842 - _t810*_t842 + _t852) - _t473*_t544 - _t536*_t559 - _t541 - _t544*_t819 - _t546 - _t548*_t854 - 0.0028113879458133329*_t549 - _t557*_t692 - _t813*_t853 - _t814*_t844 - _t815*_t853 - _t816*_t844 - _t855;
  const double d4F_dna_dnb2_dta = 0.020138882133333331*_hc4[1]*_t137*_t21*_t51*_t6*nb + 0.040277764266666662*_hc4[1]*_t137*_t21*_t51*_t82 + 0.39344000000000001*_t10*_t13*_t239*na + 0.19672000000000001*_t10*_t13*_t562*na*nb + 0.076283644444444437*_t137*_t221*_t51*na*nb + 0.15256728888888887*_t137*_t239*_t51*na*nb - _t225*_t817 - _t314*(_t119*_t836 - _t120*_t836 + _t22*(0.4e1*_hc4[17]*_t1*_t6*_t62*_t99 + _hc4[17]*_t162*_t41*_t6 + _hc4[32]*_t164*_t384*_t6 - _t100*_t237 - _t105*_t162 - _t164*_t285 - _t237*_t259) + _t30*_t561 + _t809*_t846 - _t810*_t846 + _t847) - _t460*_t856 - _t536*_t554 - _t538*_t839 - 0.0028113879458133329*_t539 - _t552*_t691 - _t560 - _t562*_t819 - _t563 - _t813*_t838 - _t814*_t848 - _t815*_t838 - _t816*_t848 - _t849;
  const double d4F_dna_dnb2_dtb = 0.040277764266666662*_hc5[1]*_t137*_t21*_t51*_t8*na + 0.020138882133333331*_hc5[1]*_t137*_t21*_t51*_t85 + 0.39344000000000001*_t10*_t13*_t242*na + 0.19672000000000001*_t10*_t13*_t567*na*nb + 0.076283644444444437*_t137*_t232*_t51*na*nb + 0.15256728888888887*_t137*_t242*_t51*na*nb - _t314*(_t119*_t842 - _t120*_t842 + _t22*(_t100*_t230 + _t230*_t259 - _t269*_t555 + _t40*_t858) + _t30*_t566 + _t809*_t851 - _t810*_t851 + _t852) - _t460*_t857 - _t547 - 0.0014056939729066664*_t549 - _t557*_t691 - _t559*_t817 - _t565 - _t567*_t819 - _t568 - _t813*_t844 - _t814*_t853 - _t815*_t844 - _t816*_t853 - _t831*_t854 - _t855;
  const double d4F_dnb3_dta = 0.060416646399999996*_hc4[1]*_t137*_t21*_t51*_t82 + 1.18032*_t10*_t13*_t239*na + 0.59016000000000002*_t10*_t13*_t562*na*nb + 0.22885093333333331*_t137*_t239*_t51*na*nb - _t225*_t793 - _t314*(_t22*(_hc4[32]*_t834 + _t162*_t859 + _t237*_t417 + _t422*_t859) + _t305*_t561 + _t788*_t846 - _t789*_t846 + _t837) - _t444*_t848 - 0.0042170819187199995*_t539 - _t562*_t684*_t77 - _t562*_t727 - _t760*_t856 - _t764*_t848 - _t840;
  const double d4F_dnb3_dtb = 0.060416646399999996*_hc5[1]*_t137*_t21*_t51*_t8*na + 1.18032*_t10*_t13*_t242*na + 0.59016000000000002*_t10*_t13*_t567*na*nb + 0.22885093333333331*_t137*_t242*_t51*na*nb - _t314*(_t22*(_hc5[7]*_t420 - _t414 - _t428 + _t555*_t734 + _t61*_t858 + _t757*_t8) + _t305*_t566 + _t788*_t851 - _t789*_t851 + _t843) - _t444*_t853 - _t559*_t793 - _t567*_t684*_t77 - _t567*_t727 - _t760*_t857 - _t764*_t853 - _t835*_t854 - _t845;
  const double d4F_dna2_dla2 = 0;
  const double d4F_dna2_dlb2 = 0;
  const double d4F_dna_dnb_dla2 = 0;
  const double d4F_dna_dnb_dlb2 = 0;
  const double d4F_dnb2_dla2 = 0;
  const double d4F_dnb2_dlb2 = 0;
  const double d4F_dna2_dla_dta = 0;
  const double d4F_dna2_dlb_dtb = 0;
  const double d4F_dna_dnb_dla_dta = 0;
  const double d4F_dna_dnb_dlb_dtb = 0;
  const double d4F_dnb2_dla_dta = 0;
  const double d4F_dnb2_dlb_dtb = 0;
  const double d4F_dna2_dta2 = 0;
  const double d4F_dna2_dtb2 = 0;
  const double d4F_dna_dnb_dta2 = 0;
  const double d4F_dna_dnb_dtb2 = 0;
  const double d4F_dnb2_dta2 = 0;
  const double d4F_dnb2_dtb2 = 0;
  const double d4F_dna_dla3 = 0;
  const double d4F_dna_dlb3 = 0;
  const double d4F_dnb_dla3 = 0;
  const double d4F_dnb_dlb3 = 0;
  const double d4F_dna_dla2_dta = 0;
  const double d4F_dna_dlb2_dtb = 0;
  const double d4F_dnb_dla2_dta = 0;
  const double d4F_dnb_dlb2_dtb = 0;
  const double d4F_dna_dla_dta2 = 0;
  const double d4F_dna_dlb_dtb2 = 0;
  const double d4F_dnb_dla_dta2 = 0;
  const double d4F_dnb_dlb_dtb2 = 0;
  const double d4F_dna_dta3 = 0;
  const double d4F_dna_dtb3 = 0;
  const double d4F_dnb_dta3 = 0;
  const double d4F_dnb_dtb3 = 0;
  const double d4F_dla4 = 0;
  const double d4F_dlb4 = 0;
  const double d4F_dla3_dta = 0;
  const double d4F_dlb3_dtb = 0;
  const double d4F_dla2_dta2 = 0;
  const double d4F_dlb2_dtb2 = 0;
  const double d4F_dla_dta3 = 0;
  const double d4F_dlb_dtb3 = 0;
  const double d4F_dta4 = 0;
  const double d4F_dtb4 = 0;
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
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 1] += d4F_dna3_dlb;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 2] += d4F_dna2_dnb_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 3] += d4F_dna2_dnb_dlb;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 4] += d4F_dna_dnb2_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 5] += d4F_dna_dnb2_dlb;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 6] += d4F_dnb3_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 7] += d4F_dnb3_dlb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 1] += d4F_dna3_dtb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 2] += d4F_dna2_dnb_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 3] += d4F_dna2_dnb_dtb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 4] += d4F_dna_dnb2_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 5] += d4F_dna_dnb2_dtb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 6] += d4F_dnb3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 7] += d4F_dnb3_dtb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 2] += d4F_dna2_dlb2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 3] += d4F_dna_dnb_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 5] += d4F_dna_dnb_dlb2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 6] += d4F_dnb2_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 8] += d4F_dnb2_dlb2;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 0] += d4F_dna2_dla_dta;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 3] += d4F_dna2_dlb_dtb;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 4] += d4F_dna_dnb_dla_dta;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 7] += d4F_dna_dnb_dlb_dtb;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 8] += d4F_dnb2_dla_dta;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 11] += d4F_dnb2_dlb_dtb;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 2] += d4F_dna2_dtb2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 3] += d4F_dna_dnb_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 5] += d4F_dna_dnb_dtb2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 6] += d4F_dnb2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 8] += d4F_dnb2_dtb2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 3] += d4F_dna_dlb3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 4] += d4F_dnb_dla3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 7] += d4F_dnb_dlb3;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 0] += d4F_dna_dla2_dta;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 5] += d4F_dna_dlb2_dtb;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 6] += d4F_dnb_dla2_dta;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 11] += d4F_dnb_dlb2_dtb;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 0] += d4F_dna_dla_dta2;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 5] += d4F_dna_dlb_dtb2;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 6] += d4F_dnb_dla_dta2;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 11] += d4F_dnb_dlb_dtb2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 3] += d4F_dna_dtb3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 4] += d4F_dnb_dta3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 7] += d4F_dnb_dtb3;
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