/*
  Generated from python/lda_exc/lda_x_rel.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_x_rel
*/

#ifndef _LDA_X_REL_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_X_REL_KERNEL_BODY
#define _KMAX 0
#define _LDA_X_REL_HELPER_BODIES
#include "lda_x_rel.c"
#undef _LDA_X_REL_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_X_REL_HELPER_BODIES
#include "lda_x_rel.c"
#undef _LDA_X_REL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_X_REL_HELPER_BODIES
#include "lda_x_rel.c"
#undef _LDA_X_REL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_X_REL_HELPER_BODIES
#include "lda_x_rel.c"
#undef _LDA_X_REL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_X_REL_HELPER_BODIES
#include "lda_x_rel.c"
#undef _LDA_X_REL_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_x_rel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_x_rel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_x_rel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_x_rel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_x_rel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_x_rel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_x_rel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_x_rel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_x_rel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_x_rel.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_X_REL_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(beta_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = M_CBRT2*xc_powr(0.3e1, 2, 3)*M_CBRTPI;
  const double _t2 = 0.0036486762701375229*_t1;

  const double f = _t2/rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_t2/(rs * rs);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.0072973525402750458*_t1/(rs * rs * rs);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.021892057620825137*_t1/(rs * rs * rs * rs);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.087568230483300549*_t1/xc_powi(rs, 5);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_rel_bracket_taylor_k, _KMAX)(const xc_func_type *p, double b, double *out) {

  const double _t1 = (b * b * b);
  const double _t2 = xc_powi(b, 5);
  const double _t3 = xc_powi(b, 7);
  const double _t4 = xc_powi(b, 9);
  const double _t5 = xc_powi(b, 11);
  const double _t6 = xc_powi(b, 13);
  const double _t7 = xc_powi(b, 15);
  const double _t8 = xc_powi(b, 17);
  const double _t9 = xc_powi(b, 19);
  const double _t10 = xc_powi(b, 21);
  const double _t11 = xc_powi(b, 23);
  const double _t12 = xc_powi(b, 25);
  const double _t13 = xc_powi(b, 27);
  const double _t14 = xc_powi(b, 29);
  const double _t15 = xc_powi(b, 31);
  const double _t16 = xc_powi(b, 33);
  const double _t17 = xc_powi(b, 35);
  const double _t18 = xc_powi(b, 37);
  const double _t19 = xc_powi(b, 39);
  const double _t20 = xc_powi(b, 41);
  const double _t21 = xc_powi(b, 43);
  const double _t22 = xc_powi(b, 45);
  const double _t23 = xc_powi(b, 47);
  const double _t24 = xc_powi(b, 49);
  const double _t25 = xc_powi(b, 51);
  const double _t26 = xc_powi(b, 53);
  const double _t27 = xc_powi(b, 55);
#if _KMAX >= 1
  const double _t28 = (b * b * b * b);
  const double _t29 = (b * b);
  const double _t30 = xc_powi(b, 6);
  const double _t31 = xc_powi(b, 8);
  const double _t32 = xc_powi(b, 10);
  const double _t33 = xc_powi(b, 12);
  const double _t34 = xc_powi(b, 14);
  const double _t35 = xc_powi(b, 16);
  const double _t36 = xc_powi(b, 18);
  const double _t37 = xc_powi(b, 20);
  const double _t38 = xc_powi(b, 22);
  const double _t39 = xc_powi(b, 24);
  const double _t40 = xc_powi(b, 26);
  const double _t41 = xc_powi(b, 28);
  const double _t42 = xc_powi(b, 30);
  const double _t43 = xc_powi(b, 32);
  const double _t44 = xc_powi(b, 34);
  const double _t45 = xc_powi(b, 36);
  const double _t46 = xc_powi(b, 38);
  const double _t47 = xc_powi(b, 40);
  const double _t48 = xc_powi(b, 42);
  const double _t49 = xc_powi(b, 44);
  const double _t50 = xc_powi(b, 46);
  const double _t51 = xc_powi(b, 48);
  const double _t52 = xc_powi(b, 50);
  const double _t53 = xc_powi(b, 52);
  const double _t54 = xc_powi(b, 54);
#endif

  const double f = (0.2e1 / 0.3e1)*_t1 - 0.12155e5 / 0.688128e6*_t10 + (0.46189e5 / 0.3014656e7)*_t11 - 0.88179e5 / 0.6553600e7*_t12 + (0.676039e6 / 0.56623104e8)*_t13 - 0.1300075e7 / 0.121634816e9*_t14 + (0.5014575e7 / 0.520093696e9)*_t15 - 0.3231615e7 / 0.369098752e9*_t16 + (0.60108039e8 / 0.7516192768e10)*_t17 - 0.583401555e9 / 0.79456894976e11*_t18 + (0.756261275e9 / 0.111669149696e12)*_t19 - 0.1e1 / 0.5e1*_t2 - 0.4418157975e10 / 0.704374636544e12*_t20 + (0.34461632205e11 / 0.5909874999296e13)*_t21 - 0.4485482287e10 / 0.824633720832e12*_t22 + (0.263012370465e12 / 0.51677046505472e14)*_t23 - 0.514589420475e12 / 0.107752139522048e15*_t24 + (0.2687300306925e13 / 0.598134325510144e15)*_t25 - 0.15801325804719e14 / 0.3729543441416192e16*_t26 + (0.61989816618513e14 / 0.15481123719086080e17)*_t27 + (0.3e1 / 0.28e2)*_t3 - 0.5e1 / 0.72e2*_t4 + (0.35e2 / 0.704e3)*_t5 - 0.63e2 / 0.1664e4*_t6 + (0.77e2 / 0.2560e4)*_t7 - 0.429e3 / 0.17408e5*_t8 + (0.6435e4 / 0.311296e6)*_t9 - 0.121683714103007e15 / 0.32088147345014784e17*xc_powi(b, 57);
  out[0] = f;
#if _KMAX >= 1
  const double df_db = -_t28 + 0.2e1*_t29 + (0.3e1 / 0.4e1)*_t30 - 0.5e1 / 0.8e1*_t31 + (0.35e2 / 0.64e2)*_t32 - 0.63e2 / 0.128e3*_t33 + (0.231e3 / 0.512e3)*_t34 - 0.429e3 / 0.1024e4*_t35 + (0.6435e4 / 0.16384e5)*_t36 - 0.12155e5 / 0.32768e5*_t37 + (0.46189e5 / 0.131072e6)*_t38 - 0.88179e5 / 0.262144e6*_t39 + (0.676039e6 / 0.2097152e7)*_t40 - 0.1300075e7 / 0.4194304e7*_t41 + (0.5014575e7 / 0.16777216e8)*_t42 - 0.9694845e7 / 0.33554432e8*_t43 + (0.300540195e9 / 0.1073741824e10)*_t44 - 0.583401555e9 / 0.2147483648e10*_t45 + (0.2268783825e10 / 0.8589934592e10)*_t46 - 0.4418157975e10 / 0.17179869184e11*_t47 + (0.34461632205e11 / 0.137438953472e12)*_t48 - 0.67282234305e11 / 0.274877906944e12*_t49 + (0.263012370465e12 / 0.1099511627776e13)*_t50 - 0.514589420475e12 / 0.2199023255552e13*_t51 + (0.8061900920775e13 / 0.35184372088832e14)*_t52 - 0.15801325804719e14 / 0.70368744177664e14*_t53 + (0.61989816618513e14 / 0.281474976710656e15)*_t54 - 0.121683714103007e15 / 0.562949953421312e15*xc_powi(b, 56);
  out[1] = df_db;
#endif
#if _KMAX >= 2
  const double d2f_db2 = -0.4e1*_t1 + (0.508079e6 / 0.65536e5)*_t10 - 0.264537e6 / 0.32768e5*_t11 + (0.8788507e7 / 0.1048576e7)*_t12 - 0.9100525e7 / 0.1048576e7*_t13 + (0.75218625e8 / 0.8388608e7)*_t14 - 0.9694845e7 / 0.1048576e7*_t15 + (0.5109183315e10 / 0.536870912e9)*_t16 - 0.5250613995e10 / 0.536870912e9*_t17 + (0.43106892675e11 / 0.4294967296e10)*_t18 - 0.22090789875e11 / 0.2147483648e10*_t19 + (0.9e1 / 0.2e1)*_t2 + (0.723694276305e12 / 0.68719476736e11)*_t20 - 0.740104577355e12 / 0.68719476736e11*_t21 + (0.6049284520695e13 / 0.549755813888e12)*_t22 - 0.1543768261425e13 / 0.137438953472e12*_t23 + (0.201547523019375e15 / 0.17592186044416e14)*_t24 - 0.205417235461347e15 / 0.17592186044416e14*_t25 + (0.1673725048699851e16 / 0.140737488355328e15)*_t26 - 0.851785998721049e15 / 0.70368744177664e14*_t27 - 0.5e1*_t3 + (0.175e3 / 0.32e2)*_t4 - 0.189e3 / 0.32e2*_t5 + (0.1617e4 / 0.256e3)*_t6 - 0.429e3 / 0.64e2*_t7 + (0.57915e5 / 0.8192e4)*_t8 - 0.60775e5 / 0.8192e4*_t9 + 0.4e1*b;
  out[2] = d2f_db2;
#endif
#if _KMAX >= 3
  const double d3f_db3 = (0.45e2 / 0.2e1)*_t28 - 0.12e2*_t29 - 0.35e2*_t30 + (0.1575e4 / 0.32e2)*_t31 - 0.2079e4 / 0.32e2*_t32 + (0.21021e5 / 0.256e3)*_t33 - 0.6435e4 / 0.64e2*_t34 + (0.984555e6 / 0.8192e4)*_t35 - 0.1154725e7 / 0.8192e4*_t36 + (0.10669659e8 / 0.65536e5)*_t37 - 0.6084351e7 / 0.32768e5*_t38 + (0.219712675e9 / 0.1048576e7)*_t39 - 0.245714175e9 / 0.1048576e7*_t40 + (0.2181340125e10 / 0.8388608e7)*_t41 - 0.300540195e9 / 0.1048576e7*_t42 + (0.168603049395e12 / 0.536870912e9)*_t43 - 0.183771489825e12 / 0.536870912e9*_t44 + (0.1594955028975e13 / 0.4294967296e10)*_t45 - 0.861540805125e12 / 0.2147483648e10*_t46 + (0.29671465328505e14 / 0.68719476736e11)*_t47 - 0.31824496826265e14 / 0.68719476736e11*_t48 + (0.272217803431275e15 / 0.549755813888e12)*_t49 - 0.72557108286975e14 / 0.137438953472e12*_t50 + (0.9875828627949375e16 / 0.17592186044416e14)*_t51 - 0.10476279008528697e17 / 0.17592186044416e14*_t52 + (0.88707427581092103e17 / 0.140737488355328e15)*_t53 - 0.46848229929657695e17 / 0.70368744177664e14*_t54 + 0.4e1;
  out[3] = d3f_db3;
#endif
#if _KMAX >= 4
  const double d4f_db4 = 0.90e2*_t1 - 0.66927861e8 / 0.16384e5*_t10 + (0.659138025e9 / 0.131072e6)*_t11 - 0.3194284275e10 / 0.524288e6*_t12 + (0.15269380875e11 / 0.2097152e7)*_t13 - 0.4508102925e10 / 0.524288e6*_t14 + (0.168603049395e12 / 0.16777216e8)*_t15 - 0.3124115327025e13 / 0.268435456e9*_t16 + (0.14354595260775e14 / 0.1073741824e10)*_t17 - 0.16369275297375e14 / 0.1073741824e10*_t18 + (0.148357326642525e15 / 0.8589934592e10)*_t19 - 0.210e3*_t2 - 0.668314433351565e15 / 0.34359738368e11*_t20 + (0.2994395837744025e16 / 0.137438953472e12)*_t21 - 0.1668813490600425e16 / 0.68719476736e11*_t22 + (0.29627485883848125e17 / 0.1099511627776e13)*_t23 - 0.261906975213217425e18 / 0.8796093022208e13*_t24 + (0.1153196558554197339e19 / 0.35184372088832e14)*_t25 - 0.1264902208100757765e19 / 0.35184372088832e14*_t26 + (0.1575e4 / 0.4e1)*_t3 - 0.10395e5 / 0.16e2*_t4 + (0.63063e5 / 0.64e2)*_t5 - 0.45045e5 / 0.32e2*_t6 + (0.984555e6 / 0.512e3)*_t7 - 0.10392525e8 / 0.4096e4*_t8 + (0.53348295e8 / 0.16384e5)*_t9 - 0.24e2*b;
  out[4] = d4f_db4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_rel_bracket_k, _KMAX)(const xc_func_type *p, double b, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_x_rel_bracket_taylor_k, _KMAX)(p, b, _hc0);
  const double _t1 = b < 0.1e1 / 0.2e1;
  const double _t2 = (b * b);
  const double _t3 = _t2 + 0.1e1;
  const double _t4 = xc_powr(_t3, 1, 2);
#if _KMAX >= 1
  const double _t5 = (0.1e1 / _t4);
#endif
#if _KMAX >= 2
  const double _t6 = xc_powr(_t3, -3, 2);
  const double _t7 = _t6*b;
  const double _t8 = 0.3e1*_t5;
  const double _t9 = (b * b * b);
#endif
#if _KMAX >= 3
  const double _t10 = xc_powr(_t3, -5, 2);
  const double _t11 = 0.3e1*_t10;
#endif
#if _KMAX >= 4
  const double _t12 = xc_powr(_t3, -7, 2);
#endif

  const double f = my_piecewise3(_t1, _hc0[0], _t4*b - xc_asinh(b));
  out[0] = f;
#if _KMAX >= 1
  const double df_db = my_piecewise3(_t1, _hc0[1], _t2*_t5 + _t4 - _t5);
  out[1] = df_db;
#endif
#if _KMAX >= 2
  const double d2f_db2 = my_piecewise3(_t1, _hc0[2], -_t6*_t9 + _t7 + _t8*b);
  out[2] = d2f_db2;
#endif
#if _KMAX >= 3
  const double d3f_db3 = my_piecewise3(_t1, _hc0[3], -_t11*_t2 + _t11*(b * b * b * b) - 0.6e1*_t2*_t6 + _t6 + _t8);
  out[3] = d3f_db3;
#endif
#if _KMAX >= 4
  const double d4f_db4 = my_piecewise3(_t1, _hc0[4], 0.30e2*_t10*_t9 - 0.9e1*_t10*b + 0.15e2*_t12*_t9 - 0.15e2*_t12*xc_powi(b, 5) - 0.15e2*_t7);
  out[4] = d4f_db4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(phi_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(beta_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_x_rel_bracket_k, _KMAX)(p, _hc0[0], _hc1);
  const double _t1 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t2 = ((_hc1[0]) * (_hc1[0]));
#if _KMAX >= 1
  const double _t3 = 3.0*_t1;
  const double _t4 = _hc1[0]*_hc1[1];
  const double _t5 = xc_powi((_hc0[0]), -5);
#endif
#if _KMAX >= 2
  const double _t6 = _t3*_t4;
  const double _t7 = ((_hc0[1]) * (_hc0[1]));
  const double _t8 = 3.0*_t7;
  const double _t9 = _hc1[0]*_hc1[2];
  const double _t10 = _t1*_t9;
  const double _t11 = xc_powi((_hc0[0]), -6);
  const double _t12 = _t11*_t2;
  const double _t13 = ((_hc1[1]) * (_hc1[1]));
  const double _t14 = _t1*_t13;
#endif
#if _KMAX >= 3
  const double _t15 = _hc0[1]*_hc0[2];
  const double _t16 = 9.0*_t1;
  const double _t17 = _t16*_t9;
  const double _t18 = _hc0[1]*_t11*_t2;
  const double _t19 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t20 = _t11*_t4;
  const double _t21 = 9.0*_t14;
  const double _t22 = _hc1[0]*_hc1[3];
  const double _t23 = _hc1[1]*_hc1[2];
  const double _t24 = xc_powi((_hc0[0]), -7);
#endif
#if _KMAX >= 4
  const double _t25 = 12.0*_hc0[1]*_hc0[3];
  const double _t26 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t27 = 360.0*_t11*_t26;
  const double _t28 = ((_hc0[2]) * (_hc0[2]));
  const double _t29 = _hc0[2]*_t7;
  const double _t30 = _t1*_t29;
#endif

  const double f = -1.5*_t1*_t2 + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 6.0*_hc0[1]*_t2*_t5 - _hc0[1]*_t3*_t4;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 6.0*_hc0[2]*_t2*_t5 - _hc0[2]*_t6 + 24.0*_hc1[0]*_hc1[1]*_t5*_t7 - _t10*_t8 - 30.0*_t12*_t7 - _t14*_t8;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 72.0*_hc0[1]*_hc0[2]*_hc1[0]*_hc1[1]*_t5 - 90.0*_hc0[2]*_t18 + 6.0*_hc0[3]*_t2*_t5 - _hc0[3]*_t6 + 36.0*_hc1[0]*_hc1[2]*_t19*_t5 + 36.0*_t13*_t19*_t5 - _t15*_t17 - _t15*_t21 - _t16*_t19*_t23 + 180.0*_t19*_t2*_t24 - 180.0*_t19*_t20 - _t19*_t22*_t3;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 96.0*_hc0[1]*_hc0[3]*_hc1[0]*_hc1[1]*_t5 + 216.0*_hc0[2]*_hc1[0]*_hc1[2]*_t5*_t7 + 216.0*_hc0[2]*_t13*_t5*_t7 + 1080.0*_hc0[2]*_t2*_t24*_t7 - 120.0*_hc0[3]*_t18 + 6.0*_hc0[4]*_t2*_t5 - _hc0[4]*_t6 + 1440.0*_hc1[0]*_hc1[1]*_t24*_t26 + 72.0*_hc1[0]*_hc1[1]*_t28*_t5 + 48.0*_hc1[0]*_hc1[3]*_t26*_t5 - _hc1[0]*_hc1[4]*_t26*_t3 + 144.0*_hc1[1]*_hc1[2]*_t26*_t5 - 12.0*_hc1[1]*_hc1[3]*_t1*_t26 - ((_hc1[2]) * (_hc1[2]))*_t16*_t26 - _t10*_t25 - 90.0*_t12*_t28 - _t13*_t27 - _t14*_t25 - _t17*_t28 - 1080.0*_t20*_t29 - _t21*_t28 - 18.0*_t22*_t30 - 54.0*_t23*_t30 - _t27*_t9 - 1260.0*_t2*_t26/xc_powi((_hc0[0]), 8);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_spin_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3)*M_CBRT3/(M_CBRTPI*M_CBRTPI);
  const double _t2 = (0.3e1 / 0.16e2)*_t1;

  const double f = -_t2/rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t2/(rs * rs);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -0.3e1 / 0.8e1*_t1/(rs * rs * rs);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (0.9e1 / 0.8e1)*_t1/(rs * rs * rs * rs);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -0.9e1 / 0.2e1*_t1/xc_powi(rs, 5);
  out[4] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = _t1/M_CBRTPI;
  const double _t3 = _t2/xc_powr(na, 1, 3);
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = -p->dens_threshold + (0.1e1 / 0.2e1)*na <= 0;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_x_spin_z0_k, _KMAX)(p, _t4, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(phi_k, _KMAX)(p, _t4, _hc1);
  const double _t6 = my_piecewise3(_t5, 0, _hc0[0]);
  const double _t7 = 0.2e1*_hc1[0];
  const double _t8 = _t6*_t7;
  const double zk = _t8;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t10 = xc_powr(na, -4, 3);
  const double _t9 = _hc1[1]*_t3;
  const double _t11 = _hc0[1]*_t2;
  const double _t12 = my_piecewise3(_t5, 0, -0.1e1 / 0.6e1*_t10*_t11);
  const double _t13 = _t7*na;
  const double dF_dna = _t12*_t13 - 0.1e1 / 0.3e1*_t6*_t9 + _t8;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t17 = xc_powr(na, -5, 3);
  const double _t19 = xc_powr(0.6e1, 2, 3)/(M_CBRTPI * M_CBRTPI);
  const double _t23 = xc_powr(na, -7, 3);
  const double _t24 = xc_powr(na, -8, 3);
  const double _t14 = (0.2e1 / 0.9e1)*_t6;
  const double _t15 = _hc1[1]*_t2;
  const double _t16 = _t10*_t15;
  const double _t18 = (0.1e1 / 0.18e2)*_t6;
  const double _t20 = _hc1[2]*_t19;
  const double _t21 = _t18*_t20;
  const double _t22 = (0.2e1 / 0.3e1)*_t12;
  const double _t25 = _hc0[2]*_t19;
  const double _t26 = my_piecewise3(_t5, 0, (0.2e1 / 0.9e1)*_t11*_t23 + (0.1e1 / 0.36e2)*_t24*_t25);
  const double d2F_dna2 = 0.4e1*_hc1[0]*_t12 + _t13*_t26 - _t14*_t16 + _t17*_t21 - _t22*_t9;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t27 = (0.1e1 / M_PI);
  const double _t31 = (0.1e1 / (na * na * na * na));
  const double _t33 = xc_powr(na, -10, 3);
  const double _t34 = xc_powr(na, -11, 3);
  const double _t28 = _hc1[3]*_t27/(na * na * na);
  const double _t29 = _t15*_t6;
  const double _t30 = _t17*_t20;
  const double _t32 = _hc0[3]*_t27;
  const double _t35 = my_piecewise3(_t5, 0, -0.14e2 / 0.27e2*_t11*_t33 - 0.1e1 / 0.9e1*_t25*_t34 - 0.1e1 / 0.36e2*_t31*_t32);
  const double d3F_dna3 = 0.6e1*_hc1[0]*_t26 + (0.1e1 / 0.6e1)*_t12*_t30 + _t13*_t35 - _t16*_t22 - _t18*_t28 - _t21*_t24 + (0.8e1 / 0.27e2)*_t23*_t29 - _t26*_t9;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double _t36 = xc_powr(na, -13, 3);
  const double _t37 = _t1/(M_PI * M_CBRTPI);
  const double _t38 = (0.2e1 / 0.9e1)*_t12;
  const double d4F_dna4 = 0.8e1*_hc1[0]*_t35 + _hc1[3]*_t14*_t27*_t31 + (0.1e1 / 0.108e3)*_hc1[4]*_t36*_t37*_t6 + (0.32e2 / 0.27e2)*_t12*_t15*_t23 + _t13*my_piecewise3(_t5, 0, (0.1e1 / 0.216e3)*_hc0[4]*_t37/xc_powr(na, 16, 3) + (0.140e3 / 0.81e2)*_t11*_t36 + (0.40e2 / 0.81e2)*_t25/xc_powr(na, 14, 3) + (0.2e1 / 0.9e1)*_t32/xc_powi(na, 5)) - 0.4e1 / 0.3e1*_t16*_t26 - _t20*_t24*_t38 + (0.8e1 / 0.81e2)*_t20*_t34*_t6 + (0.1e1 / 0.3e1)*_t26*_t30 - _t28*_t38 - 0.56e2 / 0.81e2*_t29*_t33 - 0.4e1 / 0.3e1*_t35*_t9;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = _t4/xc_powr(_t1, 1, 3);
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
  const double _t7 = -nb;
  const double _t8 = _t7 + na;
  const double _t9 = (0.1e1 / _t1);
  const double _t10 = _t8*_t9;
  const double _t11 = -p->dens_threshold + na <= 0;
  const double _t12 = -_t7 - p->dens_threshold <= 0;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t11)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t6, _t10, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t12)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t6, -_t10, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(phi_k, _KMAX)(p, _t6, _hc2);
  const double _t13 = my_piecewise3(_t11, 0, _hc0[0]) + my_piecewise3(_t12, 0, _hc1[0]);
  const double _t14 = _hc2[0]*_t13;
  const double zk = _t14;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t16 = xc_powr(_t1, -4, 3);
  const double _t17 = (0.1e1 / 0.6e1)*_t16;
  const double _t19 = (0.1e1 / (_t1 * _t1));
  const double _t20 = _t19*_t8;
  const double _t21 = _t20 - _t9;
  const double _t22 = -_t21;
  const double _t23 = _t17*_t4;
  const double _t30 = _t20 + _t9;
  const double _t31 = -_t30;
  const double _t15 = _hc0[2]*_t4;
  const double _t18 = -_t15*_t17;
  const double _t24 = -_hc1[2]*_t23;
  const double _t25 = my_piecewise3(_t11, 0, _hc0[1]*_t22 + _t18) + my_piecewise3(_t12, 0, _hc1[1]*_t21 + _t24);
  const double _t26 = _hc2[0]*_t25;
  const double _t27 = _hc2[1]*_t5;
  const double _t28 = (0.1e1 / 0.6e1)*_t27;
  const double _t29 = -_t13*_t28 + _t14;
  const double _t32 = my_piecewise3(_t11, 0, _hc0[1]*_t31 + _t18) + my_piecewise3(_t12, 0, _hc1[1]*_t30 + _t24);
  const double _t33 = _hc2[0]*_t32;
  const double dF_dna = _t1*_t26 + _t29;
  const double dF_dnb = _t1*_t33 + _t29;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t34 = xc_powr(_t1, -7, 3);
  const double _t35 = (0.2e1 / 0.9e1)*_t34;
  const double _t37 = 0.2e1*_t19;
  const double _t38 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t39 = 0.2e1*_t38;
  const double _t40 = _t39*_t8;
  const double _t41 = -_t37 + _t40;
  const double _t46 = _t35*_t4;
  const double _t48 = -_t41;
  const double _t59 = xc_powr(_t1, -5, 3);
  const double _t72 = _t37 + _t40;
  const double _t73 = -_t72;
  const double _t36 = _t15*_t35;
  const double _t42 = -_hc0[5]*_t23;
  const double _t43 = _hc0[4]*_t22 + _t42;
  const double _t44 = -_hc0[4]*_t23;
  const double _t45 = _hc0[3]*_t22 + _t44;
  const double _t47 = _hc1[2]*_t46;
  const double _t49 = -_hc1[5]*_t23;
  const double _t50 = _hc1[4]*_t21 + _t49;
  const double _t51 = -_hc1[4]*_t23;
  const double _t52 = _hc1[3]*_t21 + _t51;
  const double _t53 = my_piecewise3(_t11, 0, _hc0[1]*_t41 + _t22*_t45 - _t23*_t43 + _t36) + my_piecewise3(_t12, 0, _hc1[1]*_t48 + _t21*_t52 - _t23*_t50 + _t47);
  const double _t54 = _hc2[0]*_t53;
  const double _t55 = (0.1e1 / 0.3e1)*_t27;
  const double _t56 = (0.1e1 / 0.9e1)*_t13;
  const double _t57 = _hc2[1]*_t4;
  const double _t58 = _t16*_t57;
  const double _t60 = (0.1e1 / 0.36e2)*_t13;
  const double _t61 = xc_powr(0.6e1, 2, 3)*_hc2[2]/(M_CBRTPI * M_CBRTPI);
  const double _t62 = _t60*_t61;
  const double _t63 = -_t56*_t58 + _t59*_t62;
  const double _t64 = _hc1[4]*_t30 + _t49;
  const double _t65 = _t23*_t64;
  const double _t66 = _hc1[3]*_t30 + _t51;
  const double _t67 = _hc0[3]*_t31 + _t44;
  const double _t68 = _hc0[4]*_t31 + _t42;
  const double _t69 = -_t23*_t68 + _t36;
  const double _t70 = my_piecewise3(_t11, 0, _hc0[1]*_t40 + _t22*_t67 + _t69) + my_piecewise3(_t12, 0, -_hc1[1]*_t40 + (0.2e1 / 0.9e1)*_hc1[2]*_t2*_t3*_t34 + _t21*_t66 - _t65);
  const double _t71 = _hc2[0]*_t70;
  const double _t74 = my_piecewise3(_t11, 0, _hc0[1]*_t72 + _t31*_t67 + _t69) + my_piecewise3(_t12, 0, _hc1[1]*_t73 + _t30*_t66 + _t47 - _t65);
  const double _t75 = _hc2[0]*_t74;
  const double d2F_dna2 = _t1*_t54 - _t25*_t55 + 0.2e1*_t26 + _t63;
  const double d2F_dna_dnb = _t1*_t71 - _t25*_t28 + _t26 - _t28*_t32 + _t33 + _t63;
  const double d2F_dnb2 = _t1*_t75 - _t32*_t55 + 0.2e1*_t33 + _t63;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t76 = xc_powr(_t1, -10, 3);
  const double _t77 = (0.14e2 / 0.27e2)*_t76;
  const double _t80 = 0.6e1*_t38;
  const double _t81 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t82 = _t8*_t81;
  const double _t83 = 0.6e1*_t82;
  const double _t84 = -_t80 + _t83;
  const double _t85 = -_t84;
  const double _t87 = (0.4e1 / 0.9e1)*_t34;
  const double _t88 = 0.2e1*_t41;
  const double _t99 = _t4*_t77;
  const double _t101 = _t4*_t87;
  const double _t102 = 0.2e1*_t48;
  const double _t119 = (0.1e1 / M_PI);
  const double _t121 = xc_powr(_t1, -8, 3);
  const double _t122 = _t34*_t4;
  const double _t126 = -0.2e1*_t38 + _t83;
  const double _t134 = -_t126;
  const double _t148 = 0.4e1*_t38*_t8;
  const double _t155 = _t80 + _t83;
  const double _t157 = -_t155;
  const double _t78 = _t15*_t77;
  const double _t79 = -_t78;
  const double _t86 = _t4*_t43;
  const double _t89 = _hc0[5]*_t46;
  const double _t90 = -_hc0[9]*_t23;
  const double _t91 = _hc0[8]*_t22 + _t90;
  const double _t92 = -_hc0[8]*_t23;
  const double _t93 = _hc0[7]*_t22 + _t92;
  const double _t94 = _hc0[4]*_t41 + _t22*_t93 - _t23*_t91 + _t89;
  const double _t95 = _hc0[4]*_t46;
  const double _t96 = -_hc0[7]*_t23;
  const double _t97 = _hc0[6]*_t22 + _t96;
  const double _t98 = _hc0[3]*_t41 + _t22*_t97 - _t23*_t93 + _t95;
  const double _t100 = -_hc1[2]*_t99;
  const double _t103 = _hc1[5]*_t46;
  const double _t104 = -_hc1[9]*_t23;
  const double _t105 = _hc1[8]*_t21 + _t104;
  const double _t106 = -_hc1[8]*_t23;
  const double _t107 = _hc1[7]*_t21 + _t106;
  const double _t108 = _hc1[4]*_t48 + _t103 - _t105*_t23 + _t107*_t21;
  const double _t109 = _hc1[4]*_t46;
  const double _t110 = -_hc1[7]*_t23;
  const double _t111 = _hc1[6]*_t21 + _t110;
  const double _t112 = _hc1[3]*_t48 - _t107*_t23 + _t109 + _t111*_t21;
  const double _t113 = my_piecewise3(_t11, 0, _hc0[1]*_t85 + _t22*_t98 - _t23*_t94 + _t45*_t88 + _t79 + _t86*_t87) + my_piecewise3(_t12, 0, _hc1[1]*_t84 + _t100 + _t101*_t50 + _t102*_t52 - _t108*_t23 + _t112*_t21);
  const double _t114 = _hc2[0]*_t113;
  const double _t115 = _hc2[1]*_t6;
  const double _t116 = _t25*_t58;
  const double _t117 = _t59*_t61;
  const double _t118 = _t117*_t25;
  const double _t120 = _hc2[3]*_t119*_t38;
  const double _t123 = _hc2[1]*_t122;
  const double _t124 = (0.4e1 / 0.27e2)*_t123;
  const double _t125 = -_t120*_t60 - _t121*_t62 + _t124*_t13;
  const double _t127 = _hc1[8]*_t30 + _t104;
  const double _t128 = _t127*_t23;
  const double _t129 = _hc1[7]*_t30 + _t106;
  const double _t130 = -_hc1[4]*_t40 + (0.2e1 / 0.9e1)*_hc1[5]*_t2*_t3*_t34 - _t128 + _t129*_t21;
  const double _t131 = _t129*_t23;
  const double _t132 = _hc1[6]*_t30 + _t110;
  const double _t133 = -_hc1[3]*_t40 + (0.2e1 / 0.9e1)*_hc1[4]*_t2*_t3*_t34 - _t131 + _t132*_t21;
  const double _t135 = _hc0[7]*_t31 + _t92;
  const double _t136 = _hc0[8]*_t31 + _t90;
  const double _t137 = -_t136*_t23 + _t89;
  const double _t138 = _hc0[4]*_t40 + _t135*_t22 + _t137;
  const double _t139 = _hc0[6]*_t31 + _t96;
  const double _t140 = -_t135*_t23 + _t95;
  const double _t141 = _hc0[3]*_t40 + _t139*_t22 + _t140;
  const double _t142 = my_piecewise3(_t11, 0, _hc0[1]*_t134 - _t138*_t23 + _t141*_t22 + _t40*_t45 + _t41*_t67 + _t43*_t46 + _t46*_t68 + _t79) + my_piecewise3(_t12, 0, _hc1[1]*_t126 + _t100 - _t130*_t23 + _t133*_t21 - _t40*_t52 + _t46*_t50 + _t46*_t64 + _t48*_t66);
  const double _t143 = _hc2[0]*_t1;
  const double _t144 = _t32*_t58;
  const double _t145 = _t117*_t32;
  const double _t146 = _t125 - _t55*_t70 + 0.2e1*_t71;
  const double _t147 = _hc1[3]*_t73 + _t109 - _t131 + _t132*_t30;
  const double _t149 = _hc1[4]*_t73 + _t103 - _t128 + _t129*_t30;
  const double _t150 = _t100 + _t101*_t64 - _t149*_t23;
  const double _t151 = _hc0[4]*_t72 + _t135*_t31 + _t137;
  const double _t152 = _t151*_t23;
  const double _t153 = _hc0[3]*_t72 + _t139*_t31 + _t140;
  const double _t154 = my_piecewise3(_t11, 0, -_hc0[1]*_t39 - _hc0[1]*_t83 - _t152 + _t153*_t22 + (0.4e1 / 0.9e1)*_t2*_t3*_t34*_t68 + 0.4e1*_t38*_t67*_t8 - _t78) + my_piecewise3(_t12, 0, _hc1[1]*_t39 + _hc1[1]*_t83 + _t147*_t21 - _t148*_t66 + _t150);
  const double _t156 = 0.2e1*_t66;
  const double _t158 = 0.2e1*_t67;
  const double _t159 = my_piecewise3(_t11, 0, _hc0[1]*_t157 + _t101*_t68 - _t152 + _t153*_t31 + _t158*_t72 + _t79) + my_piecewise3(_t12, 0, _hc1[1]*_t155 + _t147*_t30 + _t150 + _t156*_t73);
  const double _t160 = _hc2[0]*_t159;
  const double d3F_dna3 = _t1*_t114 - _t115*_t53 - 0.1e1 / 0.3e1*_t116 + (0.1e1 / 0.12e2)*_t118 + _t125 + 0.3e1*_t54;
  const double d3F_dna2_dnb = -0.2e1 / 0.9e1*_t116 + (0.1e1 / 0.18e2)*_t118 + _t142*_t143 - 0.1e1 / 0.9e1*_t144 + (0.1e1 / 0.36e2)*_t145 + _t146 - _t28*_t53 + _t54;
  const double d3F_dna_dnb2 = -0.1e1 / 0.9e1*_t116 + (0.1e1 / 0.36e2)*_t118 + _t143*_t154 - 0.2e1 / 0.9e1*_t144 + (0.1e1 / 0.18e2)*_t145 + _t146 - _t28*_t74 + _t75;
  const double d3F_dnb3 = _t1*_t160 - _t115*_t74 + _t125 - 0.1e1 / 0.3e1*_t144 + (0.1e1 / 0.12e2)*_t145 + 0.3e1*_t75;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t161 = xc_powr(_t1, -13, 3);
  const double _t162 = (0.140e3 / 0.81e2)*_t161;
  const double _t164 = 0.24e2*_t81;
  const double _t165 = 0.24e2*_t8/xc_powi(_t1, 5);
  const double _t166 = -_t164 + _t165;
  const double _t167 = (0.14e2 / 0.9e1)*_t76;
  const double _t168 = (0.2e1 / 0.3e1)*_t122;
  const double _t206 = 0.12e2*_t81;
  const double _t207 = _t165 - _t206;
  const double _t214 = (0.28e2 / 0.27e2)*_t76;
  const double _t236 = _t214*_t4;
  const double _t246 = _t167*_t4;
  const double _t248 = _t8*_t80;
  const double _t249 = 0.2e1*_t73;
  const double _t252 = 0.2e1*_t72;
  const double _t255 = _t164 + _t165;
  const double _t163 = _t15*_t162;
  const double _t169 = _hc0[5]*_t99;
  const double _t170 = -_t169;
  const double _t171 = _hc0[9]*_t46;
  const double _t172 = -_hc0[14]*_t23;
  const double _t173 = -_hc0[13]*_t23;
  const double _t174 = _hc0[12]*_t22 + _t173;
  const double _t175 = _hc0[8]*_t46;
  const double _t176 = -_hc0[12]*_t23;
  const double _t177 = _hc0[11]*_t22 + _t176;
  const double _t178 = _hc0[7]*_t41 - _t174*_t23 + _t175 + _t177*_t22;
  const double _t179 = _hc0[4]*_t99;
  const double _t180 = -_t179;
  const double _t181 = _hc0[7]*_t46;
  const double _t182 = -_hc0[11]*_t23;
  const double _t183 = _hc1[2]*_t162*_t4;
  const double _t184 = _t4*_t50;
  const double _t185 = -_hc1[5]*_t99;
  const double _t186 = _hc1[9]*_t46;
  const double _t187 = -_hc1[14]*_t23;
  const double _t188 = -_hc1[13]*_t23;
  const double _t189 = _hc1[12]*_t21 + _t188;
  const double _t190 = _hc1[8]*_t46;
  const double _t191 = -_hc1[12]*_t23;
  const double _t192 = _hc1[11]*_t21 + _t191;
  const double _t193 = _hc1[7]*_t48 - _t189*_t23 + _t190 + _t192*_t21;
  const double _t194 = -_hc1[4]*_t99;
  const double _t195 = _hc1[7]*_t46;
  const double _t196 = -_hc1[11]*_t23;
  const double _t197 = _t120*_t25;
  const double _t198 = _t53*_t58;
  const double _t199 = (0.2e1 / 0.3e1)*_t27;
  const double _t200 = _t121*_t61;
  const double _t201 = _t200*_t25;
  const double _t202 = _t117*_t53;
  const double _t203 = _t123*_t25;
  const double _t204 = _hc2[3]*_t119*_t56*_t81 + (0.1e1 / 0.216e3)*_hc2[4]*_t13*_t161*_t2/(M_PI * M_CBRTPI) - 0.28e2 / 0.81e2*_t13*_t57*_t76 + (0.4e1 / 0.81e2)*_t13*_t61/xc_powr(_t1, 11, 3);
  const double _t205 = _hc2[0]*_t142;
  const double _t208 = _hc1[12]*_t30 + _t188;
  const double _t209 = _t208*_t23;
  const double _t210 = _hc1[11]*_t30 + _t191;
  const double _t211 = -_hc1[7]*_t40 + (0.2e1 / 0.9e1)*_hc1[8]*_t2*_t3*_t34 - _t209 + _t21*_t210;
  const double _t212 = _t210*_t23;
  const double _t213 = _hc1[10]*_t30 + _t196;
  const double _t215 = _t23*(_hc1[13]*_t30 + _t187);
  const double _t216 = _t101*_t130 + _t183;
  const double _t217 = _hc0[11]*_t31 + _t176;
  const double _t218 = _hc0[12]*_t31 + _t173;
  const double _t219 = _t175 - _t218*_t23;
  const double _t220 = _hc0[7]*_t40 + _t217*_t22 + _t219;
  const double _t221 = _hc0[10]*_t31 + _t182;
  const double _t222 = _t181 - _t217*_t23;
  const double _t223 = _t171 - _t23*(_hc0[13]*_t31 + _t172);
  const double _t224 = _t101*_t138 + _t163;
  const double _t225 = _t120*_t32;
  const double _t226 = _t200*_t32;
  const double _t227 = _hc2[1]*_t101;
  const double _t228 = _t58*_t70;
  const double _t229 = _t117*_t70;
  const double _t230 = _t204 - 0.1e1 / 0.3e1*_t228 + (0.1e1 / 0.12e2)*_t229;
  const double _t231 = _hc2[0]*_t154;
  const double _t232 = _hc1[6]*_t73 + _t195 - _t212 + _t213*_t30;
  const double _t233 = _hc1[7]*_t73 + _t190 - _t209 + _t210*_t30;
  const double _t234 = _t101*_t129 + _t194 - _t23*_t233;
  const double _t235 = _hc1[1]*_t165;
  const double _t237 = _t101*_t127 + _t185 - _t23*(_hc1[8]*_t73 + _t186 + _t208*_t30 - _t215);
  const double _t238 = _hc0[1]*_t165;
  const double _t239 = _hc0[7]*_t72 + _t217*_t31 + _t219;
  const double _t240 = _t23*_t239;
  const double _t241 = _hc0[6]*_t72 + _t221*_t31 + _t222;
  const double _t242 = _t23*(_hc0[8]*_t72 + _t218*_t31 + _t223);
  const double _t243 = _t58*_t74;
  const double _t244 = _t117*_t74;
  const double _t245 = _t123*_t32;
  const double _t247 = _t246*_t64;
  const double _t250 = _t23*(_hc1[4]*_t155 + _t129*_t249 + _t233*_t30 + _t237);
  const double _t251 = _hc1[3]*_t155 + _t132*_t249 + _t232*_t30 + _t234;
  const double _t253 = _hc0[3]*_t157 + _t101*_t135 + _t139*_t252 + _t180 - _t240 + _t241*_t31;
  const double _t254 = _t151*_t168 + _t163 - _t23*(_hc0[4]*_t157 + _t101*_t136 + _t135*_t252 + _t170 + _t239*_t31 - _t242) - _t246*_t68;
  const double d4F_dna4 = -_t113*_t199 + 0.4e1*_t114 + _t143*(my_piecewise3(_t11, 0, _hc0[1]*_t166 + _t163 - _t167*_t86 + _t168*_t94 + _t22*(_hc0[3]*_t85 + _t101*_t93 - _t178*_t23 + _t180 + _t22*(_hc0[6]*_t41 - _t177*_t23 + _t181 + _t22*(_hc0[10]*_t22 + _t182)) + _t88*_t97) - _t23*(_hc0[4]*_t85 + _t101*_t91 + _t170 + _t178*_t22 - _t23*(_hc0[8]*_t41 + _t171 + _t174*_t22 - _t23*(_hc0[13]*_t22 + _t172)) + _t88*_t93) + 0.3e1*_t41*_t98 + 0.3e1*_t45*_t85) + my_piecewise3(_t12, 0, -_hc1[1]*_t166 + _t108*_t168 + 0.3e1*_t112*_t48 - _t167*_t184 + _t183 + _t21*(_hc1[3]*_t84 + _t101*_t107 + _t102*_t111 - _t193*_t23 + _t194 + _t21*(_hc1[6]*_t48 - _t192*_t23 + _t195 + _t21*(_hc1[10]*_t21 + _t196))) - _t23*(_hc1[4]*_t84 + _t101*_t105 + _t102*_t107 + _t185 + _t193*_t21 - _t23*(_hc1[8]*_t48 + _t186 + _t189*_t21 - _t23*(_hc1[13]*_t21 + _t187))) + 0.3e1*_t52*_t84)) - 0.1e1 / 0.9e1*_t197 - 0.2e1 / 0.3e1*_t198 - 0.1e1 / 0.9e1*_t201 + (0.1e1 / 0.6e1)*_t202 + (0.16e2 / 0.27e2)*_t203 + _t204;
  const double d4F_dna3_dnb = -_t113*_t28 + _t114 - _t115*_t142 + _t124*_t32 + _t143*(my_piecewise3(_t11, 0, _hc0[1]*_t207 + 0.2e1*_t134*_t45 + _t141*_t88 - _t214*_t86 + _t22*(_hc0[3]*_t134 + _t135*_t46 + _t139*_t41 + _t180 + _t22*(_hc0[6]*_t40 + _t22*_t221 + _t222) - _t220*_t23 + _t40*_t97 + _t46*_t93) + _t224 - _t23*(_hc0[4]*_t134 + _t135*_t41 + _t136*_t46 + _t170 + _t22*_t220 - _t23*(_hc0[8]*_t40 + _t218*_t22 + _t223) + _t40*_t93 + _t46*_t91) + _t40*_t98 + _t46*_t94 + _t67*_t85 - _t68*_t99) + my_piecewise3(_t12, 0, -_hc1[1]*_t207 + _t102*_t133 + _t108*_t46 - _t112*_t40 + 0.2e1*_t126*_t52 - _t184*_t214 + _t21*(_hc1[3]*_t126 + _t107*_t46 - _t111*_t40 + _t129*_t46 + _t132*_t48 + _t194 + _t21*(-_hc1[6]*_t40 + (0.2e1 / 0.9e1)*_hc1[7]*_t2*_t3*_t34 + _t21*_t213 - _t212) - _t211*_t23) + _t216 - _t23*(_hc1[4]*_t126 + _t105*_t46 - _t107*_t40 + _t127*_t46 + _t129*_t48 + _t185 + _t21*_t211 - _t23*(-_hc1[8]*_t40 + (0.2e1 / 0.9e1)*_hc1[9]*_t2*_t3*_t34 + _t208*_t21 - _t215)) - _t64*_t99 + _t66*_t84)) - 0.1e1 / 0.12e2*_t197 - 0.1e1 / 0.3e1*_t198 - 0.1e1 / 0.12e2*_t201 + (0.1e1 / 0.12e2)*_t202 + 0.3e1*_t205 - 0.1e1 / 0.36e2*_t225 - 0.1e1 / 0.36e2*_t226 + _t227*_t25 + _t230;
  const double d4F_dna2_dnb2 = -_t142*_t55 + _t143*(my_piecewise3(_t11, 0, _t134*_t158 + _t141*_t148 + _t151*_t46 + _t153*_t41 + _t22*(-_hc0[3]*_t39 - _hc0[3]*_t83 + (0.4e1 / 0.9e1)*_t135*_t2*_t3*_t34 + 0.4e1*_t139*_t38*_t8 - _t179 + _t22*_t241 - _t240) + _t224 - _t23*(-_hc0[4]*_t39 - _hc0[4]*_t83 + 0.4e1*_t135*_t38*_t8 + (0.4e1 / 0.9e1)*_t136*_t2*_t3*_t34 - _t169 + _t22*_t239 - _t242) - _t236*_t68 + _t238 - _t39*_t45 - _t45*_t83 - _t77*_t86) + my_piecewise3(_t12, 0, _t126*_t156 - _t133*_t148 + _t147*_t48 + _t149*_t46 + _t21*(_hc1[3]*_t39 + _hc1[3]*_t83 - _t132*_t148 + _t21*_t232 + _t234) + _t216 - _t23*(_hc1[4]*_t39 + _hc1[4]*_t83 - _t129*_t148 + _t21*_t233 + _t237) - _t235 - _t236*_t64 + _t39*_t52 - _t50*_t99 + _t52*_t83)) - _t154*_t55 - 0.1e1 / 0.18e2*_t197 - 0.1e1 / 0.9e1*_t198 - 0.1e1 / 0.18e2*_t201 + (0.1e1 / 0.36e2)*_t202 + (0.8e1 / 0.27e2)*_t203 + _t204 + 0.2e1*_t205 - 0.1e1 / 0.18e2*_t225 - 0.1e1 / 0.18e2*_t226 - 0.4e1 / 0.9e1*_t228 + (0.1e1 / 0.9e1)*_t229 + 0.2e1*_t231 - 0.1e1 / 0.9e1*_t243 + (0.1e1 / 0.36e2)*_t244 + (0.8e1 / 0.27e2)*_t245;
  const double d4F_dna_dnb3 = -_t115*_t154 + _t124*_t25 + _t143*(my_piecewise3(_t11, 0, _hc0[1]*_t206 + _t153*_t248 + _t22*_t253 + _t238 + _t254 - _t67*_t80 - 0.18e2*_t67*_t82) + my_piecewise3(_t12, 0, -_hc1[1]*_t206 + (0.140e3 / 0.81e2)*_hc1[2]*_t161*_t2*_t3 - _t147*_t248 + (0.2e1 / 0.3e1)*_t149*_t2*_t3*_t34 + _t21*_t251 - _t235 - _t247 - _t250 + 0.6e1*_t38*_t66 + 0.18e2*_t66*_t8*_t81)) - _t159*_t28 + _t160 - 0.1e1 / 0.36e2*_t197 - 0.1e1 / 0.36e2*_t201 - 0.1e1 / 0.12e2*_t225 - 0.1e1 / 0.12e2*_t226 + _t227*_t32 + _t230 + 0.3e1*_t231 - 0.1e1 / 0.3e1*_t243 + (0.1e1 / 0.12e2)*_t244;
  const double d4F_dnb4 = _t143*(my_piecewise3(_t11, 0, _hc0[1]*_t255 + 0.3e1*_t153*_t72 + 0.3e1*_t157*_t67 + _t253*_t31 + _t254) + my_piecewise3(_t12, 0, -_hc1[1]*_t255 + 0.3e1*_t147*_t73 + _t149*_t168 + 0.3e1*_t155*_t66 + _t183 - _t247 - _t250 + _t251*_t30)) - _t159*_t199 + 0.4e1*_t160 + _t204 - 0.1e1 / 0.9e1*_t225 - 0.1e1 / 0.9e1*_t226 - 0.2e1 / 0.3e1*_t243 + (0.1e1 / 0.6e1)*_t244 + (0.16e2 / 0.27e2)*_t245;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif