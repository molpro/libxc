/*
  Generated from python/gga_exc/gga_c_ft97.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_ft97
*/

#ifndef _GGA_C_FT97_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_FT97_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_FT97_HELPER_BODIES
#include "gga_c_ft97.c"
#undef _GGA_C_FT97_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_FT97_HELPER_BODIES
#include "gga_c_ft97.c"
#undef _GGA_C_FT97_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_FT97_HELPER_BODIES
#include "gga_c_ft97.c"
#undef _GGA_C_FT97_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_FT97_HELPER_BODIES
#include "gga_c_ft97.c"
#undef _GGA_C_FT97_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_FT97_HELPER_BODIES
#include "gga_c_ft97.c"
#undef _GGA_C_FT97_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_ft97.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_ft97.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_ft97.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_ft97.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_ft97.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_ft97.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_ft97.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_ft97.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_ft97.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_ft97.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_FT97_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(kssp0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = pow(rs, 0.4e1 / 0.5e1);
  const double _t2 = xc_expm1(-0.083275879999999997*_t1);
#if _KMAX >= 1
  const double _t3 = _t2 + 0.1e1;
#endif

  const double f = 0.34906417299999998*_t2 + 1.291551074;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.023254900946437791*_t3/pow(rs, 0.1e1 / 0.5e1);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.001549257872501952*_t3/pow(rs, 0.2e1 / 0.5e1) + 0.0046509801892875586*_t3/pow(rs, 0.6e1 / 0.5e1);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.00010321265014362229*_t3/pow(rs, 0.3e1 / 0.5e1) - 0.00092955472350117127*_t3/pow(rs, 0.7e1 / 0.5e1) - 0.0055811762271450703*_t3/pow(rs, 0.11e2 / 0.5e1);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.00012385518017234674*_t3/pow(rs, 0.8e1 / 0.5e1) + 0.0016731985023021082*_t3/pow(rs, 0.12e2 / 0.5e1) + 0.012278587699719156*_t3/pow(rs, 0.16e2 / 0.5e1) + 6.8760994142738185e-6*_t3/_t1;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(fssp_k, _KMAX)(const xc_func_type *p, double rs, double gr, double *out) {

  const double _t1 = (gr * gr);
  const double _t2 = 0.24005891623762179*_t1;
  const double _t3 = _t2 + 1.6221187669999999*gr + 0.1e1;
  const double _t4 = (0.1e1 / rs);
  const double _t5 = 1.379021941*_t4;
  const double _t6 = _t5*gr + 0.1e1;
  const double _t7 = xc_powr(_t6, -1, 2);
  const double _t8 = exp(-_t2);
  const double _t9 = _t7*_t8;
  const double _t10 = _t3*_t9;
#if _KMAX >= 1
  const double _t11 = 0.48011783247524359*gr;
  const double _t12 = _t11 + 1.6221187669999999;
  const double _t13 = xc_powr(_t6, -3, 2);
  const double _t14 = _t13*_t8;
  const double _t15 = _t14*_t3;
  const double _t16 = 0.68951097049999999*_t15;
  const double _t17 = (0.1e1 / (rs * rs));
#endif
#if _KMAX >= 2
  const double _t18 = _t12*_t9;
  const double _t19 = _t18*gr;
  const double _t20 = _t12*_t14;
  const double _t21 = xc_powr(_t6, -5, 2);
  const double _t22 = _t21*_t8;
  const double _t23 = _t17*_t22;
  const double _t24 = 1.4262761353195557*_t3;
  const double _t25 = _t15*_t4;
  const double _t26 = (0.1e1 / (rs * rs * rs));
  const double _t27 = _t22*_t26;
  const double _t28 = 0.33104651262436163*_t17;
  const double _t29 = _t15*_t26;
  const double _t30 = 1.379021941*_t29;
  const double _t31 = (0.1e1 / (rs * rs * rs * rs));
  const double _t32 = _t1*_t31;
#endif
#if _KMAX >= 3
  const double _t33 = 0.99313953787308495*_t14;
  const double _t34 = (gr * gr * gr);
  const double _t35 = _t26*_t3;
  const double _t36 = xc_powr(_t6, -7, 2);
  const double _t37 = _t36*_t8;
  const double _t38 = 4.9171652113258801*_t37;
  const double _t39 = 2.0543418198023771*gr;
  const double _t40 = _t23*_t3;
  const double _t41 = 0.47682400226909061*_t1;
  const double _t42 = _t14*gr;
  const double _t43 = _t17*_t20;
  const double _t44 = _t12*_t26;
  const double _t45 = _t22*_t35;
  const double _t46 = _t3*_t31;
  const double _t47 = _t17*_t3*_t33;
  const double _t48 = _t15*_t17;
  const double _t49 = _t20*_t26;
  const double _t50 = _t3*_t38;
  const double _t51 = xc_powi(rs, -5);
  const double _t52 = _t1*_t51;
  const double _t53 = 0.68478060660079232*_t22;
  const double _t54 = 8.5576568119173331*_t22;
  const double _t55 = _t52*_t54;
  const double _t56 = xc_powi(rs, -6);
#endif
#if _KMAX >= 4
  const double _t57 = 0.66404079481315925*_t1;
  const double _t58 = 4.1086836396047541*_t23;
  const double _t59 = 1.9072960090763624*_t4;
  const double _t60 = _t20*_t4;
  const double _t61 = (gr * gr * gr * gr);
  const double _t62 = 23.733075498791017*_t8/xc_powr(_t6, 9, 2);
  const double _t63 = _t37*gr;
  const double _t64 = _t15*gr;
  const double _t65 = _t3*_t51;
  const double _t66 = _t65*gr;
  const double _t67 = _t1*_t46;
  const double _t68 = _t12*_t31;
  const double _t69 = _t3*_t56;
  const double _t70 = _t1*_t69;
  const double _t71 = _t3*_t62;
  const double _t72 = _t34/xc_powi(rs, 7);
#endif

  const double f = _t10;
  out[0] = f;
#if _KMAX >= 1
  const double df_dgr = -_t10*_t11 + _t12*_t7*_t8 - _t16*_t4;
  out[1] = df_dgr;
  const double df_drs = _t16*_t17*gr;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dgr2 = 0.23051313306072607*_t1*_t10 - 0.48011783247524359*_t10 - 0.96023566495048718*_t19 - _t20*_t5 + _t23*_t24 + 0.66209302524872327*_t25*gr + 0.48011783247524359*_t9;
  out[3] = d2f_dgr2;
  const double d2f_drs_dgr = -_t1*_t15*_t28 + 0.68951097049999999*_t12*_t13*_t17*_t8*gr + 0.68951097049999999*_t13*_t17*_t3*_t8 - _t24*_t27*gr;
  out[4] = d2f_drs_dgr;
  const double d2f_drs2 = _t22*_t24*_t32 - _t30*gr;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dgr3 = 0.69153939918217822*_t1*_t12*_t7*_t8 - 0.11067346580219321*_t10*_t34 + 1.9862790757461699*_t12*_t13*_t4*_t8*gr + 4.2788284059586665*_t12*_t17*_t21*_t8 + 0.99313953787308495*_t13*_t3*_t4*_t8 - 1.4403534974257308*_t18 - _t25*_t41 + 0.69153939918217822*_t3*_t7*_t8*gr - _t33*_t4 - _t35*_t38 - _t39*_t40 - 0.69153939918217822*_t9*gr;
  out[6] = d3f_dgr3;
  const double d3f_drs_dgr2 = -0.66209302524872327*_t1*_t43 + 1.3695612132015846*_t1*_t45 - 2.8525522706391113*_t22*_t44*gr + _t28*_t42 + 0.15894133408969688*_t34*_t48 + _t38*_t46*gr + 1.379021941*_t43 - 2.8525522706391113*_t45 - _t47*gr;
  out[7] = d3f_drs_dgr2;
  const double d3f_drs2_dgr = 1.4262761353195557*_t1*_t12*_t21*_t31*_t8 + 0.66209302524872327*_t1*_t13*_t26*_t3*_t8 + 5.7051045412782226*_t21*_t3*_t31*_t8*gr - _t30 - _t34*_t46*_t53 - 1.379021941*_t49*gr - _t50*_t52;
  out[8] = d3f_drs2_dgr;
  const double d3f_drs3 = 4.1370658230000004*_t15*_t31*gr - _t3*_t55 + _t34*_t50*_t56;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dgr4 = 1.9726522833735294*_t1*_t40 - 1.9072960090763627*_t1*_t60 - _t10*_t57 + 0.053136304513472003*_t10*_t61 + 0.69153939918217822*_t10 - 8.2173672792095083*_t12*_t23*gr - 0.44269386320877285*_t18*_t34 + 2.7661575967287129*_t19 + 0.3052422752554752*_t25*_t34 - _t3*_t58 + 9.443274812737819*_t35*_t63 - 19.668660845303521*_t37*_t44 + _t42*_t59 + _t46*_t62 + _t57*_t9 + _t58 - _t59*_t64 + 3.9725581514923398*_t60 - 1.3830787983643564*_t9;
  out[10] = d4f_dgr4;
  const double d4f_drs_dgr3 = 4.1086836396047541*_t1*_t12*_t21*_t26*_t8 + 0.95364800453818122*_t1*_t13*_t17*_t3*_t8 + 0.47682400226909061*_t12*_t13*_t17*_t34*_t8 + 14.75149563397764*_t12*_t31*_t36*_t8*gr + 0.99313953787308495*_t13*_t17*_t8 - _t14*_t17*_t41 + 6.1630254594071312*_t21*_t26*_t3*_t8*gr - _t27*_t39 + 14.75149563397764*_t3*_t31*_t36*_t8 - 0.9863261416867648*_t34*_t45 - 7.0824561095533642*_t37*_t67 - 2.9794186136192549*_t43*gr - _t44*_t54 - _t47 - 0.076310568813868815*_t48*_t61 - _t62*_t66;
  out[11] = d4f_drs_dgr3;
  const double d4f_drs2_dgr2 = 1.3241860504974465*_t1*_t49 - 9.8343304226517603*_t12*_t37*_t52 - 1.3695612132015846*_t22*_t34*_t68 + 0.32877538056225492*_t22*_t46*_t61 - 6.1630254594071312*_t22*_t67 + 11.410209082556445*_t22*_t68*gr - 0.66209302524872327*_t26*_t42 - 0.31788266817939376*_t29*_t34 + 1.9862790757461699*_t29*gr + _t32*_t53 + 4.7216374063689095*_t34*_t37*_t65 + _t46*_t54 - 2.7580438819999999*_t49 + _t62*_t70 - 29.502991267955281*_t63*_t65;
  out[12] = d4f_drs2_dgr2;
  const double d4f_drs3_dgr = 44.254486901932921*_t1*_t3*_t36*_t56*_t8 + 4.1370658230000004*_t12*_t13*_t31*_t8*gr + 4.9171652113258801*_t12*_t34*_t36*_t56*_t8 - _t12*_t55 + 4.1370658230000004*_t13*_t3*_t31*_t8 - 1.9862790757461699*_t15*_t32 + 4.1086836396047532*_t21*_t3*_t34*_t51*_t8 - 25.672970435751999*_t22*_t66 - 2.3608187031844547*_t37*_t61*_t69 - _t71*_t72;
  out[13] = d4f_drs3_dgr;
  const double d4f_drs4 = 51.345940871503998*_t22*_t70 - 59.005982535910562*_t3*_t37*_t72 - 16.548263292000001*_t51*_t64 + _t61*_t71/xc_powi(rs, 8);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_factor_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = xc_powr(rs, 1, 2);
  const double _t3 = 0.93901599999999996*_t2;
  const double _t4 = _t3 + 1.7331700000000001*rs;
  const double _t5 = (0.1e1 / (_t4 * _t4));
  const double _t6 = exp(-_t1*_t5);
#if _KMAX >= 1
  const double _t7 = 0.2e1*_t5;
  const double _t8 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t9 = (0.1e1 / _t2);
  const double _t10 = -0.93901599999999996*_t9 - 3.4663400000000002;
  const double _t11 = _t10*_t8;
  const double _t12 = -_t1*_t11 - _t7*rs;
  const double _t13 = _t12*_t6;
#endif
#if _KMAX >= 2
  const double _t14 = (_t12 * _t12)*_t6;
  const double _t15 = _t2*_t8;
  const double _t16 = _t11*rs;
  const double _t17 = -1.4085239999999999*_t9 - 5.1995100000000001;
  const double _t18 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t19 = _t10*_t18;
  const double _t20 = _t17*_t19;
  const double _t21 = _t1*_t20;
  const double _t22 = -0.46950799999999998*_t15 - 0.4e1*_t16 - _t21 - _t7;
  const double _t23 = _t22*_t6;
#endif
#if _KMAX >= 3
  const double _t24 = -0.8e1*_t16 - 0.2e1*_t21 - _t3*_t8 - 0.4e1*_t5;
  const double _t25 = _t8*_t9;
  const double _t26 = _t17*_t18;
  const double _t27 = _t19*_t2;
  const double _t28 = xc_powi(_t4, -5);
  const double _t29 = -1.8780319999999999*_t9 - 6.9326800000000004;
  const double _t30 = _t17*_t28*_t29;
  const double _t31 = _t10*_t30;
  const double _t32 = _t1*_t31;
  const double _t33 = -0.6e1*_t11 - 0.6e1*_t20*rs - 2.1127859999999998*_t25 - _t26*_t3 - 0.70426199999999994*_t27 - _t32;
#endif
#if _KMAX >= 4
  const double _t34 = 0.12e2*_t11;
  const double _t35 = 0.12e2*_t20;
  const double _t36 = 1.4085239999999999*_t2;
  const double _t37 = _t10*_t28;
#endif

  const double f = _t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t13;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t14 + _t23;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (_t12 * _t12 * _t12)*_t6 + _t13*_t22 + _t13*_t24 + _t33*_t6;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = (_t12 * _t12 * _t12 * _t12)*_t6 + 0.2e1*_t13*_t33 + _t13*(-1.8780319999999999*_t2*_t26 - 4.2255719999999997*_t25 - 1.4085239999999999*_t27 - 0.2e1*_t32 - _t34 - _t35*rs) + _t14*_t22 + _t14*_t24 + _t14*(-1.4085239999999999*_t15 - 0.3e1*_t21 - _t34*rs - 0.6e1*_t5) + (_t22 * _t22)*_t6 + _t23*_t24 + _t6*(-_t1*_t10*_t17*_t29*(-2.34754*_t9 - 8.6658500000000007)/xc_powi(_t4, 6) - _t17*_t3*_t37 - 0.99196992928799987*_t18/rs - 4.5777029999999996*_t19*_t9 - 5.399341999999999*_t26*_t9 - _t29*_t36*_t37 - _t30*_t36 - 0.8e1*_t31*rs - _t35 - 1.7606549999999999*_t8/xc_powr(rs, 3, 2));
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(kss0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_expm1(-0.65563882299999998*pow(rs, 0.2e1 / 0.5e1));
  const double _t2 = xc_powr(rs, 1, 2);
  const double _t3 = xc_expm1(-1.0893388479999999*_t2);
#if _KMAX >= 1
  const double _t4 = _t1 + 0.1e1;
  const double _t5 = _t3 + 0.1e1;
#endif
#if _KMAX >= 2
  const double _t6 = _t5/xc_powr(rs, 3, 2);
#endif
#if _KMAX >= 3
  const double _t7 = _t5/xc_powr(rs, 5, 2);
  const double _t8 = _t5/(rs * rs);
#endif

  const double f = 0.81290434499999997*_t1 - 0.85961444499999995*_t3 + 1.2008017740000001;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.21318865918695437*_t4/pow(rs, 0.3e1 / 0.5e1) + 0.46820570462022959*_t5/_t2;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.055909904634513161*_t4/pow(rs, 0.6e1 / 0.5e1) + 0.12791319551217262*_t4/pow(rs, 0.8e1 / 0.5e1) - 0.25501733144901456*_t5/rs - 0.2341028523101148*_t6;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.014662681627445781*_t4/pow(rs, 0.9e1 / 0.5e1) - 0.10063782834212369*_t4/pow(rs, 0.11e2 / 0.5e1) - 0.20466111281947619*_t4/pow(rs, 0.13e2 / 0.5e1) + 0.13890014303035184*_t6 + 0.35115427846517222*_t7 + 0.38252599717352187*_t8;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.0038453693296969108*_t4/pow(rs, 0.12e2 / 0.5e1) + 0.052785653858804814*_t4/pow(rs, 0.14e2 / 0.5e1) + 0.27507673080180478*_t4/pow(rs, 0.16e2 / 0.5e1) + 0.53211889333063811*_t4/pow(rs, 0.18e2 / 0.5e1) - 0.95631499293380462*_t5/(rs * rs * rs) - 0.87788569616293055*_t5/xc_powr(rs, 7, 2) - 0.41670042909105554*_t7 - 0.075654660897859341*_t8;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(fss_k, _KMAX)(const xc_func_type *p, double rs, double gr, double *out) {

  const double _t1 = (gr * gr);
  const double _t2 = 24.465699223035507*_t1;
  const double _t3 = _t2 + 0.1e1;
  const double _t4 = (0.1e1 / rs);
  const double _t5 = _t4*gr;
  const double _t6 = 3.6006120589999999*_t5 + 0.1e1;
  const double _t7 = xc_powr(_t6, -1, 2);
  const double _t8 = exp(-_t2);
  const double _t9 = _t7*_t8;
  const double _t10 = _t3*_t9;
#if _KMAX >= 1
  const double _t11 = 48.931398446071015*_t10;
  const double _t12 = xc_powr(_t6, -3, 2);
  const double _t13 = _t12*_t8;
  const double _t14 = _t13*_t4;
  const double _t15 = 1.8003060295*_t3;
  const double _t16 = (0.1e1 / (rs * rs));
  const double _t17 = _t13*_t16;
#endif
#if _KMAX >= 2
  const double _t18 = _t1*_t9;
  const double _t19 = 176.18298330865716*_t13;
  const double _t20 = _t19*_t5;
  const double _t21 = _t1*_t10;
  const double _t22 = xc_powr(_t6, -5, 2);
  const double _t23 = _t22*_t8;
  const double _t24 = _t16*_t23;
  const double _t25 = 9.7233053995621646*_t3;
  const double _t26 = (0.1e1 / (rs * rs * rs));
  const double _t27 = _t26*gr;
  const double _t28 = _t23*_t25;
  const double _t29 = _t1*_t17;
  const double _t30 = _t26*_t3;
  const double _t31 = _t13*_t30;
  const double _t32 = 3.6006120589999999*_t31;
  const double _t33 = (0.1e1 / (rs * rs * rs * rs));
  const double _t34 = _t1*_t33;
#endif
#if _KMAX >= 3
  const double _t35 = 14365.690523328965*_t9;
  const double _t36 = (gr * gr * gr);
  const double _t37 = 264.27447496298572*_t13;
  const double _t38 = xc_powr(_t6, -7, 2);
  const double _t39 = _t38*_t8;
  const double _t40 = 87.524626687508359*_t39;
  const double _t41 = _t16*_t37;
  const double _t42 = _t41*gr;
  const double _t43 = _t1*_t26;
  const double _t44 = _t17*_t36;
  const double _t45 = _t23*_t30;
  const double _t46 = _t3*_t33;
  const double _t47 = _t3*_t40;
  const double _t48 = xc_powi(rs, -5);
  const double _t49 = _t1*_t48;
  const double _t50 = _t23*_t36;
  const double _t51 = _t23*_t3;
  const double _t52 = xc_powi(rs, -6);
#endif
#if _KMAX >= 4
  const double _t53 = (gr * gr * gr * gr);
  const double _t54 = 2854.64958431286*_t24;
  const double _t55 = 17130.809529160368*_t39;
  const double _t56 = _t13*_t5;
  const double _t57 = _t1*_t24;
  const double _t58 = _t14*_t36;
  const double _t59 = 1102.9977920868055*_t8/xc_powr(_t6, 9, 2);
  const double _t60 = 4281.9743764692903*_t23;
  const double _t61 = _t3*_t59;
  const double _t62 = _t48*gr;
  const double _t63 = 528.54894992597144*_t13;
  const double _t64 = _t39*_t48;
  const double _t65 = 8565.4047645801838*_t36*_t64;
  const double _t66 = _t23*_t46;
  const double _t67 = _t1*_t52;
  const double _t68 = _t1*_t46;
  const double _t69 = _t36/xc_powi(rs, 7);
#endif

  const double f = _t10;
  out[0] = f;
#if _KMAX >= 1
  const double df_dgr = -_t11*gr - _t14*_t15 + 48.931398446071015*_t7*_t8*gr;
  out[1] = df_dgr;
  const double df_drs = _t15*_t17*gr;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dgr2 = -_t11 - 4788.5635077763218*_t18 + _t20*_t3 - _t20 + 2394.2817538881609*_t21 + _t24*_t25 + 48.931398446071015*_t9;
  out[3] = d2f_dgr2;
  const double d2f_drs_dgr = 88.091491654328578*_t1*_t12*_t16*_t8 + 1.8003060295*_t12*_t16*_t3*_t8 - _t27*_t28 - 88.091491654328578*_t29*_t3;
  out[4] = d2f_drs_dgr;
  const double d2f_drs2 = _t28*_t34 - _t32*gr;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dgr3 = 25862.639267080147*_t1*_t12*_t4*_t8 - 12931.319633540073*_t1*_t14*_t3 - 117155.55449165934*_t10*_t36 + 264.27447496298572*_t12*_t3*_t4*_t8 + 1427.32479215643*_t16*_t22*_t8*gr - 1427.32479215643*_t24*_t3*gr + 7182.8452616644827*_t3*_t7*_t8*gr - _t30*_t40 - _t35*gr + 351466.66347497801*_t36*_t7*_t8 - _t37*_t4;
  out[6] = d3f_dgr3;
  const double d3f_drs_dgr2 = 951.54986143762005*_t1*_t45 - 951.54986143762005*_t23*_t43 - _t3*_t42 + 4310.4398778466912*_t3*_t44 + _t40*_t46*gr + _t42 - 8620.8797556933823*_t44 - 19.446610799124329*_t45;
  out[7] = d3f_drs_dgr2;
  const double d3f_drs2_dgr = 176.18298330865716*_t1*_t12*_t26*_t3*_t8 - _t19*_t43 + 38.893221598248658*_t22*_t3*_t33*_t8*gr + 475.77493071881003*_t22*_t33*_t36*_t8 - 475.77493071881003*_t3*_t33*_t50 - _t32 - _t47*_t49;
  out[8] = d3f_drs2_dgr;
  const double d3f_drs3 = 10.801836177*_t13*_t46*gr + _t36*_t47*_t52 - 58.339832397372987*_t49*_t51;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dgr4 = 5732585.1170017673*_t10*_t53 + 7182.8452616644827*_t10 + 2108799.9808498682*_t18 - 702933.32694995601*_t21 - _t27*_t55 - _t3*_t54 - 51725.278534160294*_t3*_t56 + 139681.99623392354*_t3*_t57 + 843663.40456300043*_t3*_t58 + _t30*_t55*gr - _t35 + _t46*_t59 - 22930340.468007073*_t53*_t9 + _t54 + 103450.55706832059*_t56 - 279363.99246784707*_t57 - 2530990.2136890013*_t58;
  out[10] = d4f_dgr4;
  const double d4f_drs_dgr3 = 25862.639267080147*_t1*_t12*_t16*_t3*_t8 + 12848.107146870278*_t1*_t33*_t38*_t8 - 12848.107146870278*_t1*_t39*_t46 + 632747.55342225032*_t12*_t16*_t53*_t8 + 264.27447496298572*_t12*_t16*_t8 - 210915.85114075011*_t17*_t3*_t53 + 4281.9743764692903*_t22*_t26*_t3*_t8*gr + 139681.99623392354*_t22*_t26*_t36*_t8 - _t27*_t60 - 51725.278534160294*_t29 + 262.57388006252506*_t3*_t33*_t38*_t8 - _t3*_t41 - 69840.998116961768*_t36*_t45 - _t61*_t62;
  out[11] = d4f_drs_dgr3;
  const double d4f_drs2_dgr2 = 17241.759511386765*_t13*_t26*_t36 - 46560.665411307848*_t23*_t33*_t53 - _t27*_t63 - 525.14776012505013*_t3*_t64*gr + _t3*_t65 - 8620.8797556933823*_t31*_t36 + 528.54894992597144*_t31*gr + _t34*_t60 + 23280.332705653924*_t53*_t66 - _t60*_t68 + _t61*_t67 - _t65 + 58.339832397372987*_t66;
  out[12] = d4f_drs2_dgr2;
  const double d4f_drs3_dgr = 528.54894992597144*_t1*_t12*_t33*_t8 + 787.72164018757519*_t1*_t3*_t38*_t52*_t8 + 10.801836177*_t12*_t3*_t33*_t8 + 2854.64958431286*_t22*_t3*_t36*_t48*_t8 - 4282.7023822900919*_t3*_t39*_t52*_t53 + 4282.7023822900919*_t38*_t52*_t53*_t8 - 2854.64958431286*_t48*_t50 - 175.01949719211896*_t51*_t62 - _t61*_t69 - _t63*_t68;
  out[13] = d4f_drs3_dgr;
  const double d4f_drs4 = -43.207344708000001*_t13*_t3*_t62 - 1050.2955202501003*_t3*_t39*_t69 + 350.03899438423798*_t51*_t67 + _t53*_t61/xc_powi(rs, 8);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(eq15_k, _KMAX)(const xc_func_type *p, double mu, double *out) {

  const double _t1 = xc_powr(mu, 1, 2);
  const double _t2 = 0.2e1*_t1 + 0.2e1*mu + 0.3e1;
  const double _t3 = 0.6e1*_t1 + 0.6e1*mu + 0.3e1;
  const double _t4 = (0.1e1 / _t3);
#if _KMAX >= 1
  const double _t5 = (0.1e1 / _t1);
  const double _t6 = _t5 + 0.2e1;
  const double _t7 = (0.1e1 / (_t3 * _t3));
  const double _t8 = -0.3e1*_t5 - 0.6e1;
  const double _t9 = _t7*_t8;
#endif
#if _KMAX >= 2
  const double _t10 = xc_powr(mu, -3, 2);
  const double _t11 = _t2*_t7;
  const double _t12 = (0.3e1 / 0.2e1)*_t10;
  const double _t13 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t14 = _t13*_t2;
  const double _t15 = -0.6e1*_t5 - 0.12e2;
  const double _t16 = _t15*_t8;
#endif
#if _KMAX >= 3
  const double _t17 = xc_powr(mu, -5, 2);
  const double _t18 = (0.9e1 / 0.2e1)*_t7;
  const double _t19 = _t10*_t6;
  const double _t20 = _t13*_t16;
  const double _t21 = 0.3e1*_t10;
  const double _t22 = _t14*_t15;
  const double _t23 = _t14*_t8;
  const double _t24 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t25 = -0.9e1*_t5 - 0.18e2;
  const double _t26 = _t16*_t24*_t25;
#endif
#if _KMAX >= 4
  const double _t27 = xc_powr(mu, -7, 2);
  const double _t28 = (0.1e1 / (mu * mu * mu));
  const double _t29 = 0.12e2*_t13*_t19;
  const double _t30 = _t2*_t25;
  const double _t31 = _t10*_t24;
  const double _t32 = _t30*_t31;
#endif

  const double f = _t2*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dmu = _t2*_t9 + _t4*_t6;
  out[1] = df_dmu;
#endif
#if _KMAX >= 2
  const double d2f_dmu2 = -0.1e1 / 0.2e1*_t10*_t4 + _t11*_t12 + _t14*_t16 + 0.2e1*_t6*_t9;
  out[2] = d2f_dmu2;
#endif
#if _KMAX >= 3
  const double d3f_dmu3 = -0.9e1 / 0.4e1*_t11*_t17 - _t12*_t9 + (0.3e1 / 0.4e1)*_t17*_t4 + _t18*_t19 + _t2*_t26 + 0.3e1*_t20*_t6 + _t21*_t22 + _t21*_t23;
  out[3] = d3f_dmu3;
#endif
#if _KMAX >= 4
  const double d4f_dmu4 = (0.45e2 / 0.8e1)*_t11*_t27 + (0.27e2 / 0.2e1)*_t14*_t28 + _t15*_t29 + (0.9e1 / 0.2e1)*_t15*_t32 + (0.9e1 / 0.2e1)*_t16*_t2*_t31 + _t16*_t30*(-0.12e2*_t5 - 0.24e2)/xc_powi(_t3, 5) - 0.27e2 / 0.4e1*_t17*_t22 - 0.9e1 / 0.2e1*_t17*_t23 - 0.9e1*_t17*_t6*_t7 + 0.3e1*_t17*_t9 - _t18*_t28 - _t20*_t21 + 0.4e1*_t26*_t6 - 0.15e2 / 0.8e1*_t27*_t4 + _t29*_t8 + 0.6e1*_t32*_t8;
  out[4] = d4f_dmu4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_eab_k, _KMAX)(const xc_func_type *p, double mu, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(eq15_k, _KMAX)(p, mu, _hc0);
  const double _t1 = 0.2e1*_hc0[0];
  const double _t2 = xc_E1_scaled(mu);
  const double _t3 = _t1*mu + 0.1e1;
  const double _t4 = (0.1e1 / 0.2e1)*(0.1e1 - M_LN2)/(M_PI * M_PI);
#if _KMAX >= 1
  const double _t5 = xc_E1_scaled_d1(mu);
  const double _t6 = 0.2e1*_hc0[1]*mu + _t1;
#endif
#if _KMAX >= 2
  const double _t7 = xc_E1_scaled_d2(mu);
  const double _t8 = 0.4e1*_hc0[1] + 0.2e1*_hc0[2]*mu;
#endif
#if _KMAX >= 3
  const double _t9 = xc_E1_scaled_d3(mu);
  const double _t10 = 0.6e1*_hc0[2] + 0.2e1*_hc0[3]*mu;
#endif

  const double f = _t4*(_t1 - _t2*_t3);
  out[0] = f;
#if _KMAX >= 1
  const double df_dmu = _t4*(0.2e1*_hc0[1] - _t2*_t6 - _t3*_t5);
  out[1] = df_dmu;
#endif
#if _KMAX >= 2
  const double d2f_dmu2 = _t4*(0.2e1*_hc0[2] - _t2*_t8 - _t3*_t7 - 0.2e1*_t5*_t6);
  out[2] = d2f_dmu2;
#endif
#if _KMAX >= 3
  const double d3f_dmu3 = _t4*(0.2e1*_hc0[3] - _t10*_t2 - _t3*_t9 - 0.3e1*_t5*_t8 - 0.3e1*_t6*_t7);
  out[3] = d3f_dmu3;
#endif
#if _KMAX >= 4
  const double d4f_dmu4 = _t4*(0.2e1*_hc0[4] - 0.4e1*_t10*_t5 - _t2*(0.8e1*_hc0[3] + 0.2e1*_hc0[4]*mu) - _t3*xc_E1_scaled_d4(mu) - 0.4e1*_t6*_t9 - 0.6e1*_t7*_t8);
  out[4] = d4f_dmu4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mu_ba_k, _KMAX)(const xc_func_type *p, double rsa, double ga2, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(fssp_k, _KMAX)(p, rsa, ga2, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(kssp0_k, _KMAX)(p, rsa, _hc1);
  const double _t1 = ((_hc0[0]) * (_hc0[0]));
  const double _t2 = ((_hc1[0]) * (_hc1[0]));
  const double _t3 = _t1*_t2;
  const double _t4 = _t3 > 9.9999999999999997e-61;
  const double _t5 = my_piecewise3(_t4, _t3, 9.9999999999999997e-61);
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = (0.1e1 / (M_PI * M_PI));
  const double _t8 = 0.1e1 - M_LN2;
  const double _t9 = _t7*_t8;
  const double _t10 = (0.2e1 / 0.3e1)*_t9;
#if _KMAX >= 1
  const double _t11 = 0.2e1*_t2;
  const double _t12 = _hc0[0]*_t11;
  const double _t13 = my_piecewise3(_t4, _hc0[1]*_t12, 0);
  const double _t14 = (0.1e1 / (_t5 * _t5));
  const double _t15 = _t10*_t14;
  const double _t16 = _t13*_t15;
  const double _t17 = 0.2e1*_t1;
  const double _t18 = _hc1[0]*_t17;
  const double _t19 = my_piecewise3(_t4, _hc0[2]*_t12 + _hc1[1]*_t18, 0);
  const double _t20 = _t15*rsa;
#endif
#if _KMAX >= 2
  const double _t21 = (0.1e1 / (_t5 * _t5 * _t5));
  const double _t22 = (_t13 * _t13);
  const double _t23 = ((_hc0[1]) * (_hc0[1]));
  const double _t24 = my_piecewise3(_t4, _hc0[3]*_t12 + _t11*_t23, 0);
  const double _t25 = _t15*_t24;
  const double _t26 = _hc1[0]*_hc1[1];
  const double _t27 = _hc0[0]*_t26;
  const double _t28 = 0.4e1*_t27;
  const double _t29 = _hc0[2]*_t11;
  const double _t30 = my_piecewise3(_t4, _hc0[1]*_t28 + _hc0[1]*_t29 + _hc0[4]*_t12, 0);
  const double _t31 = (0.4e1 / 0.3e1)*_t9;
  const double _t32 = _t14*_t31;
  const double _t33 = (_t19 * _t19);
  const double _t34 = 0.8e1*_t27;
  const double _t35 = ((_hc1[1]) * (_hc1[1]));
  const double _t36 = ((_hc0[2]) * (_hc0[2]));
  const double _t37 = my_piecewise3(_t4, _hc0[2]*_t34 + _hc0[5]*_t12 + _hc1[2]*_t18 + _t11*_t36 + _t17*_t35, 0);
#endif
#if _KMAX >= 3
  const double _t38 = (_t13 * _t13 * _t13);
  const double _t39 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t40 = 0.4e1*_t9;
  const double _t41 = _t39*_t40;
  const double _t42 = _t38*_t41;
  const double _t43 = 0.6e1*_t2;
  const double _t44 = _hc0[1]*_t43;
  const double _t45 = my_piecewise3(_t4, _hc0[3]*_t44 + _hc0[6]*_t12, 0);
  const double _t46 = _t15*_t45;
  const double _t47 = _t41*rsa;
  const double _t48 = _t22*_t47;
  const double _t49 = 0.4e1*_t2;
  const double _t50 = _hc0[4]*_t49;
  const double _t51 = 0.4e1*_t23;
  const double _t52 = my_piecewise3(_t4, _hc0[1]*_t50 + _hc0[3]*_t28 + _hc0[3]*_t29 + _hc0[7]*_t12 + _t26*_t51, 0);
  const double _t53 = _t33*_t47;
  const double _t54 = _hc1[0]*_hc1[2];
  const double _t55 = _hc0[0]*_t54;
  const double _t56 = 0.4e1*_t55;
  const double _t57 = _hc0[1]*_hc0[2];
  const double _t58 = 0.8e1*_t26;
  const double _t59 = _hc0[0]*_t35;
  const double _t60 = 0.4e1*_t59;
  const double _t61 = _hc0[5]*_t11;
  const double _t62 = my_piecewise3(_t4, _hc0[1]*_t56 + _hc0[1]*_t60 + _hc0[1]*_t61 + _hc0[2]*_t50 + _hc0[4]*_t34 + _hc0[8]*_t12 + _t57*_t58, 0);
  const double _t63 = (_t19 * _t19 * _t19);
  const double _t64 = _t14*_t9;
  const double _t65 = 0.2e1*_t64;
  const double _t66 = 0.12e2*_t55;
  const double _t67 = 0.12e2*_t26;
  const double _t68 = _hc0[0]*_hc0[5];
  const double _t69 = 0.12e2*_t59;
  const double _t70 = 0.6e1*_t1;
  const double _t71 = _hc1[1]*_hc1[2];
  const double _t72 = _hc0[2]*_t43;
  const double _t73 = my_piecewise3(_t4, _hc0[2]*_t66 + _hc0[2]*_t69 + _hc0[5]*_t72 + _hc0[9]*_t12 + _hc1[3]*_t18 + _t36*_t67 + _t67*_t68 + _t70*_t71, 0);
#endif
#if _KMAX >= 4
  const double _t74 = 0.16e2*_t9;
  const double _t75 = xc_powi(_t5, -5);
  const double _t76 = _t75*rsa;
  const double _t77 = _t74*_t76;
  const double _t78 = _t21*_t40;
  const double _t79 = _t78*rsa;
  const double _t80 = 0.8e1*_t2;
  const double _t81 = _t13*_t9;
  const double _t82 = (0.16e2 / 0.3e1)*_t81;
  const double _t83 = _t22*_t39;
  const double _t84 = _t9*rsa;
  const double _t85 = _t83*_t84;
  const double _t86 = _hc0[1]*_t67;
  const double _t87 = _hc0[4]*_t43;
  const double _t88 = _t19*_t9;
  const double _t89 = _t39*rsa;
  const double _t90 = 0.12e2*_t13*_t88*_t89;
  const double _t91 = (0.8e1 / 0.3e1)*_t21;
  const double _t92 = _t91*rsa;
  const double _t93 = _t9*_t92;
  const double _t94 = 0.8e1*_t88;
  const double _t95 = _t21*_t30;
  const double _t96 = _t21*_t31*rsa;
  const double _t97 = _hc0[4]*_t26;
  const double _t98 = _t33*_t39;
  const double _t99 = 0.12e2*_t98;
  const double _t100 = _t63*_t74;
  const double _t101 = _hc0[0]*_hc0[1];
  const double _t102 = _hc1[0]*_hc1[3];
  const double _t103 = 0.12e2*_t57;
  const double _t104 = _hc0[0]*_hc0[2];
  const double _t105 = 0.24e2*_t54;
  const double _t106 = 0.24e2*_t35;
#endif

  const double f = _t10*_t6*rsa;
  out[0] = f;
#if _KMAX >= 1
  const double df_dga2 = -_t16*rsa;
  out[1] = df_dga2;
  const double df_drsa = -_t19*_t20 + (0.2e1 / 0.3e1)*_t6*_t7*_t8;
  out[2] = df_drsa;
#endif
#if _KMAX >= 2
  const double d2f_dga22 = (0.4e1 / 0.3e1)*_t21*_t22*_t7*_t8*rsa - _t25*rsa;
  out[3] = d2f_dga22;
  const double d2f_drsa_dga2 = (0.4e1 / 0.3e1)*_t13*_t19*_t21*_t7*_t8*rsa - _t16 - _t20*_t30;
  out[4] = d2f_drsa_dga2;
  const double d2f_drsa2 = -_t19*_t32 - _t20*_t37 + (0.4e1 / 0.3e1)*_t21*_t33*_t7*_t8*rsa;
  out[5] = d2f_drsa2;
#endif
#if _KMAX >= 3
  const double d3f_dga23 = 0.4e1*_t13*_t21*_t24*_t7*_t8*rsa - _t42*rsa - _t46*rsa;
  out[6] = d3f_dga23;
  const double d3f_drsa_dga22 = (0.8e1 / 0.3e1)*_t13*_t21*_t30*_t7*_t8*rsa + (0.4e1 / 0.3e1)*_t19*_t21*_t24*_t7*_t8*rsa - _t19*_t48 - _t20*_t52 + (0.4e1 / 0.3e1)*_t21*_t22*_t7*_t8 - _t25;
  out[7] = d3f_drsa_dga22;
  const double d3f_drsa2_dga2 = (0.8e1 / 0.3e1)*_t13*_t19*_t21*_t7*_t8 + (0.4e1 / 0.3e1)*_t13*_t21*_t37*_t7*_t8*rsa - _t13*_t53 + (0.8e1 / 0.3e1)*_t19*_t21*_t30*_t7*_t8*rsa - _t20*_t62 - _t30*_t32;
  out[8] = d3f_drsa2_dga2;
  const double d3f_drsa3 = 0.4e1*_t19*_t21*_t37*_t7*_t8*rsa - _t20*_t73 + 0.4e1*_t21*_t33*_t7*_t8 - _t37*_t65 - _t47*_t63;
  out[9] = d3f_drsa3;
#endif
#if _KMAX >= 4
  const double d4f_dga24 = (_t13 * _t13 * _t13 * _t13)*_t77 - _t20*my_piecewise3(_t4, _hc0[1]*_hc0[6]*_t80 + _hc0[10]*_t12 + ((_hc0[3]) * (_hc0[3]))*_t43, 0) + _t21*_t45*_t82*rsa + (_t24 * _t24)*_t79 - 0.24e2*_t24*_t85;
  out[10] = d4f_dga24;
  const double d4f_drsa_dga23 = 0.4e1*_t13*_t21*_t24*_t7*_t8 + 0.4e1*_t13*_t21*_t52*_t7*_t8*rsa + (0.4e1 / 0.3e1)*_t19*_t21*_t45*_t7*_t8*rsa + 0.16e2*_t19*_t38*_t7*_t75*_t8*rsa - _t20*my_piecewise3(_t4, _hc0[11]*_t12 + _hc0[3]*_t86 + _hc0[3]*_t87 + _hc0[6]*_t28 + _hc0[6]*_t29 + _hc0[7]*_t44, 0) + 0.4e1*_t21*_t24*_t30*_t7*_t8*rsa - _t24*_t90 - 0.12e2*_t30*_t85 - _t42 - _t46;
  out[11] = d4f_drsa_dga23;
  const double d4f_drsa2_dga22 = -_t13*_t19*_t30*_t74*_t89 + _t13*_t62*_t93 - _t20*my_piecewise3(_t4, _hc0[1]*_hc0[8]*_t49 + 0.16e2*_hc0[1]*_t97 + _hc0[12]*_t12 + _hc0[2]*_hc0[3]*_t58 + _hc0[2]*_hc0[7]*_t49 + _hc0[3]*_t56 + _hc0[3]*_t60 + _hc0[3]*_t61 + ((_hc0[4]) * (_hc0[4]))*_t49 + _hc0[7]*_t34 + _t35*_t51 + _t51*_t54, 0) + _t22*_t33*_t77 + _t24*_t37*_t96 - _t24*_t53 + _t24*_t88*_t91 + (_t30 * _t30)*_t93 - _t32*_t52 - _t37*_t48 + _t52*_t88*_t92 + _t82*_t95 - _t83*_t94;
  out[12] = d4f_drsa2_dga22;
  const double d4f_drsa3_dga2 = _t100*_t13*_t76 + _t13*_t37*_t78 + _t13*_t73*_t96 + _t19*_t62*_t79 - _t20*my_piecewise3(_t4, _hc0[0]*_hc0[8]*_t67 + _hc0[1]*_hc0[9]*_t11 + _hc0[13]*_t12 + 0.24e2*_hc0[2]*_t97 + _hc0[4]*_t66 + _hc0[4]*_t69 + _hc0[5]*_t86 + _hc0[5]*_t87 + _hc0[8]*_t72 + 0.4e1*_t101*_t102 + 0.12e2*_t101*_t71 + _t103*_t35 + _t103*_t54, 0) + _t30*_t37*_t79 - _t30*_t84*_t99 - _t37*_t90 - _t62*_t65 - _t81*_t99 + _t94*_t95;
  out[13] = d4f_drsa3_dga2;
  const double d4f_drsa4 = -_t100*_t39 + 0.16e2*(_t19 * _t19 * _t19 * _t19)*_t7*_t75*_t8*rsa + 0.16e2*_t19*_t21*_t37*_t7*_t8 + (0.16e2 / 0.3e1)*_t19*_t21*_t7*_t73*_t8*rsa - _t20*my_piecewise3(_t4, _hc0[14]*_t12 + 0.48e2*_hc0[2]*_hc0[5]*_t26 + _hc0[2]*_hc0[9]*_t80 + ((_hc0[5]) * (_hc0[5]))*_t43 + 0.16e2*_hc0[9]*_t27 + 0.8e1*_hc1[1]*_hc1[3]*_t1 + ((_hc1[2]) * (_hc1[2]))*_t70 + _hc1[4]*_t18 + 0.16e2*_t102*_t104 + 0.48e2*_t104*_t71 + _t105*_t36 + _t105*_t68 + _t106*_t36 + _t106*_t68, 0) + 0.4e1*_t21*(_t37 * _t37)*_t7*_t8*rsa - 0.24e2*_t37*_t84*_t98 - 0.8e1 / 0.3e1*_t64*_t73;
  out[14] = d4f_drsa4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mu_aa_k, _KMAX)(const xc_func_type *p, double rsa, double ga2, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(fss_k, _KMAX)(p, rsa, ga2, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(kss0_k, _KMAX)(p, rsa, _hc1);
  const double _t1 = ((_hc0[0]) * (_hc0[0]));
  const double _t2 = ((_hc1[0]) * (_hc1[0]));
  const double _t3 = _t1*_t2;
  const double _t4 = _t3 > 9.9999999999999997e-61;
  const double _t5 = my_piecewise3(_t4, _t3, 9.9999999999999997e-61);
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = (0.1e1 / (M_PI * M_PI));
  const double _t8 = 0.1e1 - M_LN2;
  const double _t9 = _t7*_t8;
  const double _t10 = (0.2e1 / 0.3e1)*_t9;
#if _KMAX >= 1
  const double _t11 = 0.2e1*_t2;
  const double _t12 = _hc0[0]*_t11;
  const double _t13 = my_piecewise3(_t4, _hc0[1]*_t12, 0);
  const double _t14 = (0.1e1 / (_t5 * _t5));
  const double _t15 = _t10*_t14;
  const double _t16 = _t13*_t15;
  const double _t17 = 0.2e1*_t1;
  const double _t18 = _hc1[0]*_t17;
  const double _t19 = my_piecewise3(_t4, _hc0[2]*_t12 + _hc1[1]*_t18, 0);
  const double _t20 = _t15*rsa;
#endif
#if _KMAX >= 2
  const double _t21 = (0.1e1 / (_t5 * _t5 * _t5));
  const double _t22 = (_t13 * _t13);
  const double _t23 = ((_hc0[1]) * (_hc0[1]));
  const double _t24 = my_piecewise3(_t4, _hc0[3]*_t12 + _t11*_t23, 0);
  const double _t25 = _t15*_t24;
  const double _t26 = _hc1[0]*_hc1[1];
  const double _t27 = _hc0[0]*_t26;
  const double _t28 = 0.4e1*_t27;
  const double _t29 = _hc0[2]*_t11;
  const double _t30 = my_piecewise3(_t4, _hc0[1]*_t28 + _hc0[1]*_t29 + _hc0[4]*_t12, 0);
  const double _t31 = (0.4e1 / 0.3e1)*_t9;
  const double _t32 = _t14*_t31;
  const double _t33 = (_t19 * _t19);
  const double _t34 = 0.8e1*_t27;
  const double _t35 = ((_hc1[1]) * (_hc1[1]));
  const double _t36 = ((_hc0[2]) * (_hc0[2]));
  const double _t37 = my_piecewise3(_t4, _hc0[2]*_t34 + _hc0[5]*_t12 + _hc1[2]*_t18 + _t11*_t36 + _t17*_t35, 0);
#endif
#if _KMAX >= 3
  const double _t38 = (_t13 * _t13 * _t13);
  const double _t39 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t40 = 0.4e1*_t9;
  const double _t41 = _t39*_t40;
  const double _t42 = _t38*_t41;
  const double _t43 = 0.6e1*_t2;
  const double _t44 = _hc0[1]*_t43;
  const double _t45 = my_piecewise3(_t4, _hc0[3]*_t44 + _hc0[6]*_t12, 0);
  const double _t46 = _t15*_t45;
  const double _t47 = _t41*rsa;
  const double _t48 = _t22*_t47;
  const double _t49 = 0.4e1*_t2;
  const double _t50 = _hc0[4]*_t49;
  const double _t51 = 0.4e1*_t23;
  const double _t52 = my_piecewise3(_t4, _hc0[1]*_t50 + _hc0[3]*_t28 + _hc0[3]*_t29 + _hc0[7]*_t12 + _t26*_t51, 0);
  const double _t53 = _t33*_t47;
  const double _t54 = _hc1[0]*_hc1[2];
  const double _t55 = _hc0[0]*_t54;
  const double _t56 = 0.4e1*_t55;
  const double _t57 = _hc0[1]*_hc0[2];
  const double _t58 = 0.8e1*_t26;
  const double _t59 = _hc0[0]*_t35;
  const double _t60 = 0.4e1*_t59;
  const double _t61 = _hc0[5]*_t11;
  const double _t62 = my_piecewise3(_t4, _hc0[1]*_t56 + _hc0[1]*_t60 + _hc0[1]*_t61 + _hc0[2]*_t50 + _hc0[4]*_t34 + _hc0[8]*_t12 + _t57*_t58, 0);
  const double _t63 = (_t19 * _t19 * _t19);
  const double _t64 = _t14*_t9;
  const double _t65 = 0.2e1*_t64;
  const double _t66 = 0.12e2*_t55;
  const double _t67 = 0.12e2*_t26;
  const double _t68 = _hc0[0]*_hc0[5];
  const double _t69 = 0.12e2*_t59;
  const double _t70 = 0.6e1*_t1;
  const double _t71 = _hc1[1]*_hc1[2];
  const double _t72 = _hc0[2]*_t43;
  const double _t73 = my_piecewise3(_t4, _hc0[2]*_t66 + _hc0[2]*_t69 + _hc0[5]*_t72 + _hc0[9]*_t12 + _hc1[3]*_t18 + _t36*_t67 + _t67*_t68 + _t70*_t71, 0);
#endif
#if _KMAX >= 4
  const double _t74 = 0.16e2*_t9;
  const double _t75 = xc_powi(_t5, -5);
  const double _t76 = _t75*rsa;
  const double _t77 = _t74*_t76;
  const double _t78 = _t21*_t40;
  const double _t79 = _t78*rsa;
  const double _t80 = 0.8e1*_t2;
  const double _t81 = _t13*_t9;
  const double _t82 = (0.16e2 / 0.3e1)*_t81;
  const double _t83 = _t22*_t39;
  const double _t84 = _t9*rsa;
  const double _t85 = _t83*_t84;
  const double _t86 = _hc0[1]*_t67;
  const double _t87 = _hc0[4]*_t43;
  const double _t88 = _t19*_t9;
  const double _t89 = _t39*rsa;
  const double _t90 = 0.12e2*_t13*_t88*_t89;
  const double _t91 = (0.8e1 / 0.3e1)*_t21;
  const double _t92 = _t91*rsa;
  const double _t93 = _t9*_t92;
  const double _t94 = 0.8e1*_t88;
  const double _t95 = _t21*_t30;
  const double _t96 = _t21*_t31*rsa;
  const double _t97 = _hc0[4]*_t26;
  const double _t98 = _t33*_t39;
  const double _t99 = 0.12e2*_t98;
  const double _t100 = _t63*_t74;
  const double _t101 = _hc0[0]*_hc0[1];
  const double _t102 = _hc1[0]*_hc1[3];
  const double _t103 = 0.12e2*_t57;
  const double _t104 = _hc0[0]*_hc0[2];
  const double _t105 = 0.24e2*_t54;
  const double _t106 = 0.24e2*_t35;
#endif

  const double f = _t10*_t6*rsa;
  out[0] = f;
#if _KMAX >= 1
  const double df_dga2 = -_t16*rsa;
  out[1] = df_dga2;
  const double df_drsa = -_t19*_t20 + (0.2e1 / 0.3e1)*_t6*_t7*_t8;
  out[2] = df_drsa;
#endif
#if _KMAX >= 2
  const double d2f_dga22 = (0.4e1 / 0.3e1)*_t21*_t22*_t7*_t8*rsa - _t25*rsa;
  out[3] = d2f_dga22;
  const double d2f_drsa_dga2 = (0.4e1 / 0.3e1)*_t13*_t19*_t21*_t7*_t8*rsa - _t16 - _t20*_t30;
  out[4] = d2f_drsa_dga2;
  const double d2f_drsa2 = -_t19*_t32 - _t20*_t37 + (0.4e1 / 0.3e1)*_t21*_t33*_t7*_t8*rsa;
  out[5] = d2f_drsa2;
#endif
#if _KMAX >= 3
  const double d3f_dga23 = 0.4e1*_t13*_t21*_t24*_t7*_t8*rsa - _t42*rsa - _t46*rsa;
  out[6] = d3f_dga23;
  const double d3f_drsa_dga22 = (0.8e1 / 0.3e1)*_t13*_t21*_t30*_t7*_t8*rsa + (0.4e1 / 0.3e1)*_t19*_t21*_t24*_t7*_t8*rsa - _t19*_t48 - _t20*_t52 + (0.4e1 / 0.3e1)*_t21*_t22*_t7*_t8 - _t25;
  out[7] = d3f_drsa_dga22;
  const double d3f_drsa2_dga2 = (0.8e1 / 0.3e1)*_t13*_t19*_t21*_t7*_t8 + (0.4e1 / 0.3e1)*_t13*_t21*_t37*_t7*_t8*rsa - _t13*_t53 + (0.8e1 / 0.3e1)*_t19*_t21*_t30*_t7*_t8*rsa - _t20*_t62 - _t30*_t32;
  out[8] = d3f_drsa2_dga2;
  const double d3f_drsa3 = 0.4e1*_t19*_t21*_t37*_t7*_t8*rsa - _t20*_t73 + 0.4e1*_t21*_t33*_t7*_t8 - _t37*_t65 - _t47*_t63;
  out[9] = d3f_drsa3;
#endif
#if _KMAX >= 4
  const double d4f_dga24 = (_t13 * _t13 * _t13 * _t13)*_t77 - _t20*my_piecewise3(_t4, _hc0[1]*_hc0[6]*_t80 + _hc0[10]*_t12 + ((_hc0[3]) * (_hc0[3]))*_t43, 0) + _t21*_t45*_t82*rsa + (_t24 * _t24)*_t79 - 0.24e2*_t24*_t85;
  out[10] = d4f_dga24;
  const double d4f_drsa_dga23 = 0.4e1*_t13*_t21*_t24*_t7*_t8 + 0.4e1*_t13*_t21*_t52*_t7*_t8*rsa + (0.4e1 / 0.3e1)*_t19*_t21*_t45*_t7*_t8*rsa + 0.16e2*_t19*_t38*_t7*_t75*_t8*rsa - _t20*my_piecewise3(_t4, _hc0[11]*_t12 + _hc0[3]*_t86 + _hc0[3]*_t87 + _hc0[6]*_t28 + _hc0[6]*_t29 + _hc0[7]*_t44, 0) + 0.4e1*_t21*_t24*_t30*_t7*_t8*rsa - _t24*_t90 - 0.12e2*_t30*_t85 - _t42 - _t46;
  out[11] = d4f_drsa_dga23;
  const double d4f_drsa2_dga22 = -_t13*_t19*_t30*_t74*_t89 + _t13*_t62*_t93 - _t20*my_piecewise3(_t4, _hc0[1]*_hc0[8]*_t49 + 0.16e2*_hc0[1]*_t97 + _hc0[12]*_t12 + _hc0[2]*_hc0[3]*_t58 + _hc0[2]*_hc0[7]*_t49 + _hc0[3]*_t56 + _hc0[3]*_t60 + _hc0[3]*_t61 + ((_hc0[4]) * (_hc0[4]))*_t49 + _hc0[7]*_t34 + _t35*_t51 + _t51*_t54, 0) + _t22*_t33*_t77 + _t24*_t37*_t96 - _t24*_t53 + _t24*_t88*_t91 + (_t30 * _t30)*_t93 - _t32*_t52 - _t37*_t48 + _t52*_t88*_t92 + _t82*_t95 - _t83*_t94;
  out[12] = d4f_drsa2_dga22;
  const double d4f_drsa3_dga2 = _t100*_t13*_t76 + _t13*_t37*_t78 + _t13*_t73*_t96 + _t19*_t62*_t79 - _t20*my_piecewise3(_t4, _hc0[0]*_hc0[8]*_t67 + _hc0[1]*_hc0[9]*_t11 + _hc0[13]*_t12 + 0.24e2*_hc0[2]*_t97 + _hc0[4]*_t66 + _hc0[4]*_t69 + _hc0[5]*_t86 + _hc0[5]*_t87 + _hc0[8]*_t72 + 0.4e1*_t101*_t102 + 0.12e2*_t101*_t71 + _t103*_t35 + _t103*_t54, 0) + _t30*_t37*_t79 - _t30*_t84*_t99 - _t37*_t90 - _t62*_t65 - _t81*_t99 + _t94*_t95;
  out[13] = d4f_drsa3_dga2;
  const double d4f_drsa4 = -_t100*_t39 + 0.16e2*(_t19 * _t19 * _t19 * _t19)*_t7*_t75*_t8*rsa + 0.16e2*_t19*_t21*_t37*_t7*_t8 + (0.16e2 / 0.3e1)*_t19*_t21*_t7*_t73*_t8*rsa - _t20*my_piecewise3(_t4, _hc0[14]*_t12 + 0.48e2*_hc0[2]*_hc0[5]*_t26 + _hc0[2]*_hc0[9]*_t80 + ((_hc0[5]) * (_hc0[5]))*_t43 + 0.16e2*_hc0[9]*_t27 + 0.8e1*_hc1[1]*_hc1[3]*_t1 + ((_hc1[2]) * (_hc1[2]))*_t70 + _hc1[4]*_t18 + 0.16e2*_t102*_t104 + 0.48e2*_t104*_t71 + _t105*_t36 + _t105*_t68 + _t106*_t36 + _t106*_t68, 0) + 0.4e1*_t21*(_t37 * _t37)*_t7*_t8*rsa - 0.24e2*_t37*_t84*_t98 - 0.8e1 / 0.3e1*_t64*_t73;
  out[14] = d4f_drsa4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = xc_powr(0.12e2, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3/xc_powr(na, 1, 3);
  const double _t5 = xc_powr(0.18e2, 1, 3);
  const double _t6 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t7 = _t5*_t6;
  const double _t8 = _t7*gaa;
  const double _t9 = xc_powr(na, -8, 3);
  const double _t10 = (0.1e1 / 0.18e2)*_t9;
  const double _t11 = _t10*_t8;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mu_aa_k, _KMAX)(p, _t4, _t11, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_eab_k, _KMAX)(p, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_factor_k, _KMAX)(p, _t4, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mu_ba_k, _KMAX)(p, _t4, _t11, _hc3);
  double _hc4[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_eab_k, _KMAX)(p, _hc3[0], _hc4);
  const double _t12 = 1.0*_hc3[0] - 10000000.0 >= 0;
  const double _t13 = 1.0*_hc0[0] - 10000000.0 >= 0;
  const double _t14 = (0.1e1 / 0.2e1)*_hc2[0];
  const double _t15 = 0.2e1*my_piecewise3(_t12, 0, (0.1e1 / 0.2e1)*_hc4[0]) + 0.2e1*my_piecewise3(_t13, 0, _hc1[0]*_t14);
  const double zk = _t15;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t16 = _t3/xc_powr(na, 4, 3);
  const double _t17 = (0.1e1 / 0.6e1)*_t16;
  const double _t18 = xc_powr(na, -11, 3);
  const double _t19 = (0.4e1 / 0.27e2)*_t18;
  const double _t20 = _t19*_t8;
  const double _t28 = (0.1e1 / 0.36e2)*_t9;
  const double _t21 = -_hc3[1]*_t20 - _hc3[2]*_t17;
  const double _t22 = (0.1e1 / 0.2e1)*_hc4[1];
  const double _t23 = my_piecewise3(_t12, 0, _t21*_t22);
  const double _t24 = _hc1[0]*_hc2[1];
  const double _t25 = -_hc0[1]*_t20 - _hc0[2]*_t17;
  const double _t26 = my_piecewise3(_t13, 0, (0.1e1 / 0.2e1)*_hc1[1]*_hc2[0]*_t25 - 0.1e1 / 0.12e2*_t16*_t24);
  const double _t27 = _hc3[1]*_t7;
  const double _t29 = _t27*_t28;
  const double _t30 = _hc1[1]*_hc2[0];
  const double _t31 = _hc0[1]*_t7;
  const double _t32 = _t28*_t31;
  const double _t33 = 0.2e1*my_piecewise3(_t12, 0, _hc4[1]*_t29) + 0.2e1*my_piecewise3(_t13, 0, _t30*_t32);
  const double dF_dna = _t15 + na*(0.2e1*_t23 + 0.2e1*_t26);
  const double dF_dgaa = _t33*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t37 = xc_powr(na, -7, 3);
  const double _t38 = (0.2e1 / 0.9e1)*_t37;
  const double _t39 = _t3*_t38;
  const double _t41 = xc_powr(na, -14, 3);
  const double _t42 = (0.44e2 / 0.81e2)*_t41;
  const double _t43 = _t42*_t8;
  const double _t62 = (0.1e1 / M_PI);
  const double _t63 = (0.1e1 / (na * na * na * na));
  const double _t64 = (0.1e1 / 0.18e2)*_t63;
  const double _t65 = _t62*_t64;
  const double _t66 = _t19*_t7;
  const double _t67 = _t1/(M_PI * M_CBRTPI);
  const double _t69 = xc_powr(na, -19, 3);
  const double _t70 = _t69*gaa;
  const double _t71 = (0.2e1 / 0.81e2)*_t70;
  const double _t83 = xc_powr(na, -16, 3);
  const double _t84 = (0.1e1 / 0.216e3)*_t83;
  const double _t87 = _t67*_t84;
  const double _t34 = (_t21 * _t21);
  const double _t35 = (0.1e1 / 0.2e1)*_hc4[2];
  const double _t36 = -_hc3[4]*_t20 - _hc3[5]*_t17;
  const double _t40 = -_hc3[3]*_t20 - _hc3[4]*_t17;
  const double _t44 = _hc3[1]*_t43 + _hc3[2]*_t39 - _t20*_t40;
  const double _t45 = -_t17*_t36 + _t44;
  const double _t46 = my_piecewise3(_t12, 0, _t22*_t45 + _t34*_t35);
  const double _t47 = _t24*_t3;
  const double _t48 = (0.1e1 / 0.36e2)*_hc1[0];
  const double _t49 = _hc2[2]*_t7;
  const double _t50 = _t49*_t9;
  const double _t51 = (_t25 * _t25);
  const double _t52 = _hc1[2]*_t14;
  const double _t53 = _hc1[1]*_hc2[1];
  const double _t54 = _t25*_t53;
  const double _t55 = -_hc0[4]*_t20 - _hc0[5]*_t17;
  const double _t56 = _hc0[2]*_t3;
  const double _t57 = -_hc0[3]*_t20 - _hc0[4]*_t17;
  const double _t58 = _hc0[1]*_t43 - _t20*_t57 + _t38*_t56;
  const double _t59 = -_t17*_t55 + _t58;
  const double _t60 = _hc1[1]*_t14;
  const double _t61 = my_piecewise3(_t13, 0, -_t17*_t54 + (0.1e1 / 0.9e1)*_t37*_t47 + _t48*_t50 + _t51*_t52 + _t59*_t60);
  const double _t68 = _hc3[3]*_t67;
  const double _t72 = -_hc3[1]*_t66 - _hc3[4]*_t65 - _t68*_t71;
  const double _t73 = _hc4[2]*_t21;
  const double _t74 = my_piecewise3(_t12, 0, _t22*_t72 + _t29*_t73);
  const double _t75 = _hc0[1]*_t62;
  const double _t76 = _t53*_t75;
  const double _t77 = _hc0[4]*_t62;
  const double _t78 = _hc0[3]*_t67;
  const double _t79 = -_t19*_t31 - _t64*_t77 - _t71*_t78;
  const double _t80 = _hc1[2]*_hc2[0];
  const double _t81 = _t25*_t80;
  const double _t82 = my_piecewise3(_t13, 0, _t32*_t81 + _t60*_t79 - 0.1e1 / 0.36e2*_t63*_t76);
  const double _t85 = _t68*_t84;
  const double _t86 = ((_hc3[1]) * (_hc3[1]));
  const double _t88 = _t86*_t87;
  const double _t89 = _t78*_t84;
  const double _t90 = ((_hc0[1]) * (_hc0[1]));
  const double _t91 = _t87*_t90;
  const double _t92 = 0.2e1*my_piecewise3(_t12, 0, _hc4[1]*_t85 + _hc4[2]*_t88) + 0.2e1*my_piecewise3(_t13, 0, _t30*_t89 + _t80*_t91);
  const double d2F_dna2 = 0.4e1*_t23 + 0.4e1*_t26 + na*(0.2e1*_t46 + 0.2e1*_t61);
  const double d2F_dna_dgaa = _t33 + na*(0.2e1*_t74 + 0.2e1*_t82);
  const double d2F_dgaa2 = _t92*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t96 = (0.1e1 / 0.3e1)*_t16;
  const double _t97 = (0.4e1 / 0.9e1)*_t37;
  const double _t99 = (0.8e1 / 0.27e2)*_t18;
  const double _t101 = (0.88e2 / 0.81e2)*_t41;
  const double _t105 = xc_powr(na, -10, 3);
  const double _t106 = (0.14e2 / 0.27e2)*_t105;
  const double _t107 = xc_powr(na, -17, 3);
  const double _t108 = (0.616e3 / 0.243e3)*_t107;
  const double _t121 = (0.1e1 / 0.3e1)*_t37;
  const double _t124 = (0.1e1 / 0.4e1)*_t16;
  const double _t141 = (0.1e1 / 0.9e1)*_t63;
  const double _t143 = (0.4e1 / 0.81e2)*_t69;
  const double _t144 = _t143*_t67;
  const double _t148 = xc_powi(na, -5);
  const double _t149 = (0.2e1 / 0.27e2)*_t148;
  const double _t150 = xc_powr(na, -22, 3);
  const double _t151 = (0.22e2 / 0.243e3)*_t150;
  const double _t152 = _t151*gaa;
  const double _t153 = _t67*_t71;
  const double _t173 = (0.1e1 / (M_PI * M_PI));
  const double _t174 = _t173/xc_powi(na, 9);
  const double _t176 = (0.2e1 / 0.243e3)*gaa;
  const double _t177 = _t5/(M_PI * M_CBRTPI * M_CBRTPI);
  const double _t178 = xc_powr(na, -20, 3);
  const double _t179 = (0.1e1 / 0.324e3)*_t178;
  const double _t180 = _t177*_t179;
  const double _t186 = (0.1e1 / 0.648e3)*_t177*_t178;
  const double _t190 = _t174*_t176;
  const double _t198 = xc_powi(na, -8);
  const double _t199 = (0.1e1 / 0.648e3)*_t198;
  const double _t202 = (0.1e1 / 0.216e3)*_t173*_t198;
  const double _t204 = _t173*_t199;
  const double _t93 = (_t21 * _t21 * _t21);
  const double _t94 = (0.1e1 / 0.2e1)*_hc4[3];
  const double _t95 = _t21*_t35;
  const double _t98 = _hc3[2]*_t3;
  const double _t100 = _t40*_t8;
  const double _t102 = _hc3[1]*_t8;
  const double _t103 = -_t100*_t99 + _t101*_t102 + _t97*_t98;
  const double _t104 = _t103 - _t36*_t96;
  const double _t109 = -_hc3[8]*_t20 - _hc3[9]*_t17;
  const double _t110 = -_hc3[7]*_t20 - _hc3[8]*_t17;
  const double _t111 = _hc3[4]*_t43 + _hc3[5]*_t39 - _t109*_t17 - _t110*_t20;
  const double _t112 = -_hc3[6]*_t20 - _hc3[7]*_t17;
  const double _t113 = _hc3[3]*_t43 + _hc3[4]*_t39 - _t110*_t17 - _t112*_t20;
  const double _t114 = (0.4e1 / 0.9e1)*_t1*_t2*_t36*_t37 - _t102*_t108 - _t106*_t98 - _t111*_t17 - _t113*_t20 + (0.88e2 / 0.81e2)*_t40*_t41*_t5*_t6*gaa;
  const double _t115 = my_piecewise3(_t12, 0, _t104*_t95 + _t114*_t22 + _t45*_t95 + _t93*_t94);
  const double _t116 = _hc2[3]*_t62;
  const double _t117 = _hc1[0]*_t49;
  const double _t118 = (_t25 * _t25 * _t25);
  const double _t119 = _hc1[3]*_t14;
  const double _t120 = _t3*_t54;
  const double _t122 = _hc1[1]*_t25;
  const double _t123 = (0.1e1 / 0.12e2)*_t50;
  const double _t125 = _hc1[2]*_hc2[1];
  const double _t126 = _t125*_t51;
  const double _t127 = _t53*_t59;
  const double _t128 = _t25*_t52;
  const double _t129 = _t57*_t8;
  const double _t130 = _hc0[1]*_t8;
  const double _t131 = _t101*_t130 - _t129*_t99 + _t56*_t97;
  const double _t132 = _t131 - _t55*_t96;
  const double _t133 = -_hc0[8]*_t20 - _hc0[9]*_t17;
  const double _t134 = -_hc0[7]*_t20 - _hc0[8]*_t17;
  const double _t135 = _hc0[4]*_t43 + _hc0[5]*_t39 - _t133*_t17 - _t134*_t20;
  const double _t136 = -_hc0[6]*_t20 - _hc0[7]*_t17;
  const double _t137 = _hc0[3]*_t43 + _hc0[4]*_t39 - _t134*_t17 - _t136*_t20;
  const double _t138 = (0.4e1 / 0.9e1)*_t1*_t2*_t37*_t55 - _t106*_t56 - _t108*_t130 - _t135*_t17 - _t137*_t20 + (0.88e2 / 0.81e2)*_t41*_t5*_t57*_t6*gaa;
  const double _t139 = my_piecewise3(_t13, 0, -0.7e1 / 0.27e2*_t105*_t47 - _t116*_t48*_t63 - 0.1e1 / 0.9e1*_t117*_t18 + _t118*_t119 + _t120*_t121 + _t122*_t123 - _t124*_t126 - _t124*_t127 + _t128*_t132 + _t128*_t59 + _t138*_t60);
  const double _t140 = _hc4[3]*_t34;
  const double _t142 = _hc3[4]*_t62;
  const double _t145 = _hc3[3]*_t144;
  const double _t146 = -_t141*_t142 - _t145*gaa - _t27*_t99;
  const double _t147 = _hc4[2]*_t29;
  const double _t154 = -_hc3[4]*_t66 - _hc3[7]*_t153 - _hc3[8]*_t65;
  const double _t155 = -_hc3[3]*_t66 - _hc3[6]*_t153 - _hc3[7]*_t65;
  const double _t156 = _t142*_t149 + _t152*_t68 - _t154*_t17 - _t155*_t20 + _t27*_t42 - _t40*_t66;
  const double _t157 = my_piecewise3(_t12, 0, _t140*_t29 + _t146*_t95 + _t147*_t45 + _t156*_t22);
  const double _t158 = _hc0[1]*_hc1[1];
  const double _t159 = _hc2[2]*_t158;
  const double _t160 = _t125*_t25;
  const double _t161 = _hc1[3]*_hc2[0];
  const double _t162 = _t161*_t51;
  const double _t163 = _t53*_t79;
  const double _t164 = _t143*_t78;
  const double _t165 = -_t141*_t77 - _t164*gaa - _t31*_t99;
  const double _t166 = _t32*_t80;
  const double _t167 = _t78*gaa;
  const double _t168 = -_hc0[4]*_t66 - _hc0[7]*_t153 - _hc0[8]*_t65;
  const double _t169 = (0.2e1 / 0.81e2)*_hc0[6];
  const double _t170 = -_hc0[3]*_t66 - _hc0[7]*_t65 - _t169*_t67*_t70;
  const double _t171 = _t149*_t77 + _t151*_t167 - _t168*_t17 - _t170*_t20 + _t31*_t42 - _t57*_t66;
  const double _t172 = my_piecewise3(_t13, 0, -_hc0[1]*_t160*_t65 + _t128*_t165 + (0.1e1 / 0.27e2)*_t148*_t76 + _t159*_t87 + _t162*_t32 - _t163*_t17 + _t166*_t59 + _t171*_t60);
  const double _t175 = _hc3[6]*_t174;
  const double _t181 = -_hc3[7]*_t180 - _t145 - _t175*_t176;
  const double _t182 = _hc4[3]*_t88;
  const double _t183 = _hc4[2]*_t27;
  const double _t184 = _t10*_t183;
  const double _t185 = my_piecewise3(_t12, 0, _t181*_t22 + _t182*_t21 + _t184*_t72 + _t73*_t85);
  const double _t187 = _hc0[3]*_t53;
  const double _t188 = _hc1[2]*_t90;
  const double _t189 = _hc2[1]*_t188;
  const double _t191 = _hc0[7]*_t177;
  const double _t192 = -_hc0[6]*_t190 - _t164 - _t179*_t191;
  const double _t193 = _t161*_t91;
  const double _t194 = _t31*_t80;
  const double _t195 = _t10*_t194;
  const double _t196 = my_piecewise3(_t13, 0, -_t186*_t187 - _t186*_t189 + _t192*_t60 + _t193*_t25 + _t195*_t79 + _t81*_t89);
  const double _t197 = _hc3[6]*_t173;
  const double _t200 = _t197*_t199;
  const double _t201 = _hc3[1]*_hc4[2];
  const double _t203 = _hc3[3]*_t202;
  const double _t205 = ((_hc3[1]) * (_hc3[1]) * (_hc3[1]))*_t204;
  const double _t206 = _hc2[0]*_t204;
  const double _t207 = _hc0[1]*_hc0[3];
  const double _t208 = _t202*_t207;
  const double _t209 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t210 = _hc1[3]*_t209;
  const double _t211 = 0.2e1*my_piecewise3(_t12, 0, _hc4[1]*_t200 + _hc4[3]*_t205 + _t201*_t203) + 0.2e1*my_piecewise3(_t13, 0, _hc0[6]*_hc1[1]*_t206 + _t206*_t210 + _t208*_t80);
  const double d3F_dna3 = 0.6e1*_t46 + 0.6e1*_t61 + na*(0.2e1*_t115 + 0.2e1*_t139);
  const double d3F_dna2_dgaa = 0.4e1*_t74 + 0.4e1*_t82 + na*(0.2e1*_t157 + 0.2e1*_t172);
  const double d3F_dna_dgaa2 = _t92 + na*(0.2e1*_t185 + 0.2e1*_t196);
  const double d3F_dgaa3 = _t211*na;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t213 = _t18*_t8;
  const double _t216 = (0.2e1 / 0.3e1)*_t37;
  const double _t217 = (0.44e2 / 0.27e2)*_t41;
  const double _t218 = (0.4e1 / 0.9e1)*_t18;
  const double _t220 = (0.28e2 / 0.27e2)*_t105;
  const double _t221 = (0.1232e4 / 0.243e3)*_t107;
  const double _t223 = xc_powr(na, -13, 3);
  const double _t224 = (0.140e3 / 0.81e2)*_t223;
  const double _t225 = (0.10472e5 / 0.729e3)*_t178;
  const double _t226 = (0.14e2 / 0.9e1)*_t105;
  const double _t227 = (0.616e3 / 0.81e2)*_t107;
  const double _t228 = _t216*_t3;
  const double _t229 = _t106*_t3;
  const double _t230 = _t108*_t8;
  const double _t245 = (0.1e1 / 0.6e1)*_t63;
  const double _t246 = (0.2e1 / 0.27e2)*_t70;
  const double _t250 = (0.4e1 / 0.27e2)*_t148;
  const double _t251 = (0.44e2 / 0.243e3)*_t150;
  const double _t253 = _t8*_t99;
  const double _t254 = xc_powi(na, -6);
  const double _t255 = (0.14e2 / 0.81e2)*_t254;
  const double _t256 = (0.308e3 / 0.729e3)/xc_powr(na, 25, 3);
  const double _t257 = _t149*_t62;
  const double _t258 = _t42*_t7;
  const double _t259 = _t152*_t67;
  const double _t261 = (0.1e1 / 0.12e2)*_t63;
  const double _t262 = (0.1e1 / 0.72e2)*_t83;
  const double _t263 = _t262*_t67;
  const double _t272 = (0.8e1 / 0.81e2)*_t69;
  const double _t273 = (0.1e1 / 0.162e3)*_t178;
  const double _t275 = (0.22e2 / 0.729e3)/xc_powi(na, 10);
  const double _t276 = xc_powr(na, -23, 3);
  const double _t277 = (0.1e1 / 0.243e3)*_t276;
  const double _t278 = _t7*_t99;
  const double _t280 = (0.1e1 / 0.486e3)*_t177*_t276;
  const double _t281 = _t1/((M_PI * M_PI * M_CBRTPI)*xc_powr(na, 28, 3));
  const double _t282 = (0.1e1 / 0.1944e4)*_t281;
  const double _t283 = (0.1e1 / 0.2187e4)*gaa/xc_powr(na, 35, 3);
  const double _t284 = _t5/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t287 = (0.1e1 / 0.12e2)*_t9;
  const double _t289 = (0.1e1 / 0.3888e4)*_t281;
  const double _t292 = xc_powr(na, -32, 3);
  const double _t293 = (0.1e1 / 0.11664e5)*_t292;
  const double _t294 = _t284*_t292;
  const double _t295 = (0.1e1 / 0.2916e4)*_t294;
  const double _t296 = (0.1e1 / 0.11664e5)*_t294;
  const double _t297 = (0.1e1 / 0.3888e4)*_t294;
  const double _t298 = (0.1e1 / 0.1944e4)*_t294;
  const double _t212 = _hc3[5]*_t16;
  const double _t214 = _hc3[4]*_t213;
  const double _t215 = _t34*_t94;
  const double _t219 = _t104*_t35;
  const double _t222 = _t113*_t8;
  const double _t231 = -_hc3[12]*_t20 - _hc3[13]*_t17;
  const double _t232 = -_hc3[11]*_t20 - _hc3[12]*_t17;
  const double _t233 = _hc3[7]*_t43 + _hc3[8]*_t39 - _t17*_t231 - _t20*_t232;
  const double _t234 = _hc1[3]*_hc2[1];
  const double _t235 = (0.1e1 / 0.6e1)*_t50;
  const double _t236 = _hc0[5]*_t16;
  const double _t237 = _hc0[4]*_t213;
  const double _t238 = _t119*_t51;
  const double _t239 = _t160*_t96;
  const double _t240 = _t132*_t52;
  const double _t241 = _t137*_t8;
  const double _t242 = -_hc0[12]*_t20 - _hc0[13]*_t17;
  const double _t243 = -_hc0[11]*_t20 - _hc0[12]*_t17;
  const double _t244 = _hc0[7]*_t43 + _hc0[8]*_t39 - _t17*_t242 - _t20*_t243;
  const double _t247 = _t35*_t72;
  const double _t248 = _hc4[3]*_t21;
  const double _t249 = _t248*_t29;
  const double _t252 = _t251*_t68;
  const double _t260 = -_hc3[11]*_t153 - _hc3[12]*_t65 - _hc3[7]*_t66;
  const double _t264 = _hc1[4]*_hc2[0];
  const double _t265 = _t125*_t75;
  const double _t266 = _t52*_t79;
  const double _t267 = _t161*_t25;
  const double _t268 = _t267*_t32;
  const double _t269 = _t251*_t78;
  const double _t270 = -_hc0[11]*_t153 - _hc0[12]*_t65 - _hc0[7]*_t66;
  const double _t271 = _hc0[6]*gaa;
  const double _t274 = _hc3[7]*_t177;
  const double _t279 = _hc2[2]*_t204;
  const double _t285 = _hc3[10]*_t284;
  const double _t286 = _t262*_t72;
  const double _t288 = _hc4[3]*_t86;
  const double _t290 = _hc0[10]*_t284;
  const double _t291 = _t161*_t90;
  const double d4F_dna4 = 0.8e1*_t115 + 0.8e1*_t139 + na*(0.2e1*my_piecewise3(_t12, 0, (0.1e1 / 0.2e1)*_hc4[4]*(_t21 * _t21 * _t21 * _t21) + _t114*_t73 + _t215*(_t103 + _t16*((0.1e1 / 0.18e2)*_t212 + (0.4e1 / 0.81e2)*_t214)) + _t215*(_t16*((0.1e1 / 0.36e2)*_t212 + (0.2e1 / 0.81e2)*_t214) + _t44) + _t215*(-_t100*_t218 + _t102*_t217 + _t16*((0.1e1 / 0.12e2)*_t212 + (0.2e1 / 0.27e2)*_t214) + _t216*_t98) + _t219*_t45 + _t22*(-_t100*_t227 + _t102*_t225 + _t111*_t228 - _t17*(-_hc3[4]*_t230 - _hc3[5]*_t229 + (0.4e1 / 0.9e1)*_t1*_t109*_t2*_t37 + (0.88e2 / 0.81e2)*_t110*_t41*_t5*_t6*gaa - _t17*(_hc3[8]*_t43 + _hc3[9]*_t39 - _t17*(-_hc3[13]*_t20 - _hc3[14]*_t17) - _t20*_t231) - _t20*_t233) - _t20*(-_hc3[3]*_t230 - _hc3[4]*_t229 + (0.4e1 / 0.9e1)*_t1*_t110*_t2*_t37 + (0.88e2 / 0.81e2)*_t112*_t41*_t5*_t6*gaa - _t17*_t233 - _t20*(_hc3[6]*_t43 + _hc3[7]*_t39 - _t17*_t232 - _t20*(-_hc3[10]*_t20 - _hc3[11]*_t17))) + _t217*_t222 + _t224*_t98 - _t226*_t3*_t36) + _t35*(_t45 * _t45) + _t95*((0.8e1 / 0.9e1)*_t1*_t2*_t36*_t37 - _t102*_t221 - _t111*_t96 - _t220*_t98 - _t222*_t99 + (0.176e3 / 0.81e2)*_t40*_t41*_t5*_t6*gaa)) + 0.2e1*my_piecewise3(_t13, 0, _hc1[0]*_hc2[4]*_t87 + (0.2e1 / 0.9e1)*_hc1[0]*_t116*_t148 + _hc1[1]*_t235*_t59 + _hc1[2]*_t235*_t51 + _hc1[4]*_t14*(_t25 * _t25 * _t25 * _t25) - _t116*_t122*_t141 + (0.40e2 / 0.81e2)*_t117*_t41 - _t118*_t234*_t96 - _t120*_t220 - _t122*_t218*_t49 + _t126*_t228 + _t127*_t228 + _t128*((0.8e1 / 0.9e1)*_t1*_t2*_t37*_t55 - _t130*_t221 - _t135*_t96 - _t220*_t56 - _t241*_t99 + (0.176e3 / 0.81e2)*_t41*_t5*_t57*_t6*gaa) - _t132*_t239 - _t138*_t53*_t96 + _t138*_t81 + (0.70e2 / 0.81e2)*_t223*_t47 + _t238*(_t131 + _t16*((0.1e1 / 0.18e2)*_t236 + (0.4e1 / 0.81e2)*_t237)) + _t238*(_t16*((0.1e1 / 0.36e2)*_t236 + (0.2e1 / 0.81e2)*_t237) + _t58) + _t238*(-_t129*_t218 + _t130*_t217 + _t16*((0.1e1 / 0.12e2)*_t236 + (0.2e1 / 0.27e2)*_t237) + _t216*_t56) - _t239*_t59 + _t240*_t59 + _t52*(_t59 * _t59) + _t60*(-_t129*_t227 + _t130*_t225 + _t135*_t228 - _t17*(-_hc0[4]*_t230 - _hc0[5]*_t229 + (0.4e1 / 0.9e1)*_t1*_t133*_t2*_t37 + (0.88e2 / 0.81e2)*_t134*_t41*_t5*_t6*gaa - _t17*(_hc0[8]*_t43 + _hc0[9]*_t39 - _t17*(-_hc0[13]*_t20 - _hc0[14]*_t17) - _t20*_t242) - _t20*_t244) - _t20*(-_hc0[3]*_t230 - _hc0[4]*_t229 + (0.4e1 / 0.9e1)*_t1*_t134*_t2*_t37 + (0.88e2 / 0.81e2)*_t136*_t41*_t5*_t6*gaa - _t17*_t244 - _t20*(_hc0[6]*_t43 + _hc0[7]*_t39 - _t17*_t243 - _t20*(-_hc0[10]*_t20 - _hc0[11]*_t17))) + _t217*_t241 + _t224*_t56 - _t226*_t3*_t55)));
  const double d4F_dna3_dgaa = 0.6e1*_t157 + 0.6e1*_t172 + na*(0.2e1*my_piecewise3(_t12, 0, _hc4[4]*_t29*_t93 + _t104*_t249 + _t114*_t147 + _t156*_t95 + _t215*(-_t142*_t245 - _t218*_t27 - _t246*_t68) + _t219*_t72 + _t22*((0.4e1 / 0.9e1)*_t1*_t154*_t2*_t37 - _t108*_t27 - _t113*_t66 - _t142*_t255 + (0.88e2 / 0.81e2)*_t155*_t41*_t5*_t6*gaa - _t17*(_hc3[4]*_t258 + _hc3[7]*_t259 + _hc3[8]*_t257 - _t110*_t66 - _t17*(-_hc3[12]*_t153 - _hc3[13]*_t65 - _hc3[8]*_t66) - _t20*_t260) - _t20*(_hc3[3]*_t258 + _hc3[6]*_t259 + _hc3[7]*_t257 - _t112*_t66 - _t17*_t260 - _t20*(-_hc3[10]*_t153 - _hc3[11]*_t65 - _hc3[6]*_t66)) - _t256*_t68*gaa + (0.88e2 / 0.81e2)*_t40*_t41*_t5*_t6) + _t247*_t45 + _t249*_t45 + _t95*(_t101*_t27 + _t142*_t250 - _t154*_t96 - _t155*_t253 + _t252*gaa - _t40*_t7*_t99)) + 0.2e1*my_piecewise3(_t13, 0, _hc0[1]*_hc1[2]*_hc2[2]*_t25*_t263 + _hc1[1]*_t123*_t79 - _hc2[3]*_t158*_t186 + _t118*_t264*_t32 + _t121*_t163*_t3 - _t124*_t160*_t165 - _t124*_t171*_t53 + _t128*_t171 + _t128*(_t101*_t31 - _t168*_t96 - _t170*_t253 + _t250*_t77 + _t269*gaa - _t57*_t7*_t99) + _t132*_t268 + _t138*_t166 + (0.1e1 / 0.9e1)*_t148*_t160*_t75 - 0.1e1 / 0.54e2*_t159*_t67*_t69 - _t234*_t261*_t51*_t75 + _t238*(-_t218*_t31 - _t245*_t77 - _t246*_t78) + _t240*_t79 - 0.7e1 / 0.81e2*_t254*_t76 - _t261*_t265*_t59 + _t266*_t59 + _t268*_t59 + _t60*((0.4e1 / 0.9e1)*_t1*_t168*_t2*_t37 - _t108*_t31 - _t137*_t66 - _t167*_t256 - _t17*(_hc0[4]*_t258 + _hc0[7]*_t259 + _hc0[8]*_t257 - _t134*_t66 - _t17*(-_hc0[12]*_t153 - _hc0[13]*_t65 - _hc0[8]*_t66) - _t20*_t270) + (0.88e2 / 0.81e2)*_t170*_t41*_t5*_t6*gaa - _t20*(_hc0[3]*_t258 + _hc0[7]*_t257 - _t136*_t66 + _t151*_t271*_t67 - _t17*_t270 - _t20*(-_hc0[10]*_t153 - _hc0[11]*_t65 - _hc0[6]*_t66)) - _t255*_t77 + (0.88e2 / 0.81e2)*_t41*_t5*_t57*_t6)));
  const double d4F_dna2_dgaa2 = 0.4e1*_t185 + 0.4e1*_t196 + na*(0.2e1*my_piecewise3(_t12, 0, _hc4[2]*_t45*_t85 + _hc4[4]*_t34*_t88 + _t10*_t146*_t248*_t27 + _t140*_t85 + _t146*_t247 + _t156*_t184 + _t182*_t45 + _t22*(-_t155*_t278 - _t17*(-_hc3[11]*_t190 - _hc3[12]*_t180 - _hc3[7]*_t144) + _t197*_t275*gaa - _t20*(-_hc3[10]*_t190 - _hc3[11]*_t180 - _hc3[6]*_t144) + _t252 + _t274*_t277) + _t95*(-0.4e1 / 0.243e3*_t175*gaa - _t272*_t68 - _t273*_t274)) + 0.2e1*my_piecewise3(_t13, 0, _hc0[3]*_hc1[1]*_t279 - _hc0[3]*_t160*_t180 + _t10*_t165*_t267*_t31 + _t128*(-0.4e1 / 0.243e3*_t174*_t271 - _t191*_t273 - _t272*_t78) - _t141*_t265*_t79 + _t162*_t89 + _t165*_t266 - _t17*_t192*_t53 + _t171*_t195 - _t180*_t234*_t25*_t90 + _t187*_t280 + _t188*_t279 + _t189*_t280 + _t193*_t59 + _t264*_t51*_t91 + _t59*_t80*_t89 + _t60*(-_t17*(-_hc0[11]*_t190 - _hc0[12]*_t180 - _hc0[7]*_t144) - _t170*_t278 + _t173*_t271*_t275 + _t191*_t277 - _t20*(-_hc0[10]*_t190 - _hc0[11]*_t180 - _hc0[6]*_t144) + _t269)));
  const double d4F_dna_dgaa3 = _t211 + na*(0.2e1*my_piecewise3(_t12, 0, _hc3[1]*_t203*_t248 + _hc4[2]*_t286*_t68 + _hc4[4]*_t205*_t21 + _t181*_t183*_t287 + _t200*_t73 + _t22*(-_hc3[11]*_t282 - 0.2e1 / 0.81e2*_t175 - _t283*_t285) + _t286*_t288*_t67) + 0.2e1*my_piecewise3(_t13, 0, _hc0[6]*_t204*_t81 - _hc0[6]*_t289*_t53 + _hc1[4]*_t206*_t209*_t25 - _hc2[1]*_t210*_t289 - 0.1e1 / 0.1296e4*_t125*_t207*_t281 + _t192*_t194*_t287 + _t208*_t267 + _t262*_t78*_t79*_t80 + _t263*_t291*_t79 + _t60*(-_hc0[11]*_t282 - _t169*_t174 - _t283*_t290)));
  const double d4F_dgaa4 = na*(0.2e1*my_piecewise3(_t12, 0, ((_hc3[1]) * (_hc3[1]) * (_hc3[1]) * (_hc3[1]))*_hc4[4]*_t296 + ((_hc3[3]) * (_hc3[3]))*_hc4[2]*_t297 + _hc3[3]*_t288*_t298 + _hc3[6]*_t201*_t295 + _hc4[1]*_t285*_t293) + 0.2e1*my_piecewise3(_t13, 0, ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t264*_t296 + _hc0[1]*_hc0[6]*_t295*_t80 + ((_hc0[3]) * (_hc0[3]))*_t297*_t80 + _hc0[3]*_t291*_t298 + _t290*_t293*_t30));
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
  const double gbb = sigma[2];

  const double _t1 = xc_powr(na, -1, 3);
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = (0.1e1 / 0.2e1)*_t4;
  const double _t6 = _t1*_t5;
  const double _t7 = xc_powr(na, -8, 3);
  const double _t8 = xc_powr(0.6e1, 2, 3);
  const double _t9 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t10 = _t8*_t9;
  const double _t11 = (0.1e1 / 0.36e2)*_t10;
  const double _t12 = _t11*_t7;
  const double _t13 = _t12*gaa;
  const double _t14 = xc_powr(nb, -1, 3);
  const double _t15 = _t14*_t5;
  const double _t16 = xc_powr(nb, -8, 3);
  const double _t17 = _t11*_t16;
  const double _t18 = _t17*gbb;
  const double _t20 = na + nb;
  const double _t21 = (0.1e1 / _t20);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mu_aa_k, _KMAX)(p, _t6, _t13, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_eab_k, _KMAX)(p, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_factor_k, _KMAX)(p, _t6, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mu_aa_k, _KMAX)(p, _t15, _t18, _hc3);
  double _hc4[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_eab_k, _KMAX)(p, _hc3[0], _hc4);
  double _hc5[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_factor_k, _KMAX)(p, _t15, _hc5);
  double _hc6[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mu_ba_k, _KMAX)(p, _t6, _t13, _hc6);
  double _hc7[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_eab_k, _KMAX)(p, _hc6[0], _hc7);
  double _hc8[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mu_ba_k, _KMAX)(p, _t15, _t18, _hc8);
  double _hc9[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_eab_k, _KMAX)(p, _hc8[0], _hc9);
  const double _t19 = 1.0*_hc6[0] - 10000000.0 >= 0;
  const double _t22 = 1.0*_hc8[0] - 10000000.0 >= 0;
  const double _t23 = 1.0*_hc0[0] - 10000000.0 >= 0;
  const double _t24 = _hc1[0]*_hc2[0];
  const double _t25 = 1.0*_hc3[0] - 10000000.0 >= 0;
  const double _t26 = _hc4[0]*_hc5[0];
  const double _t27 = my_piecewise3(_t19, 0, _hc7[0]*_t21*nb) + my_piecewise3(_t22, 0, _hc9[0]*_t21*na) + my_piecewise3(_t23, 0, _t21*_t24*na) + my_piecewise3(_t25, 0, _t21*_t26*nb);
  const double zk = _t27;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t28 = (0.1e1 / (_t20 * _t20));
  const double _t37 = xc_powr(na, -4, 3);
  const double _t38 = _t37*_t4;
  const double _t39 = (0.1e1 / 0.6e1)*_t38;
  const double _t40 = xc_powr(na, -11, 3);
  const double _t41 = (0.2e1 / 0.27e2)*_t10;
  const double _t42 = _t40*_t41;
  const double _t51 = (0.1e1 / 0.6e1)*_t21;
  const double _t58 = xc_powr(nb, -4, 3);
  const double _t59 = _t4*_t58;
  const double _t60 = (0.1e1 / 0.6e1)*_t59;
  const double _t61 = xc_powr(nb, -11, 3);
  const double _t62 = _t41*_t61;
  const double _t73 = _t11*_t21;
  const double _t74 = xc_powr(na, -5, 3);
  const double _t82 = xc_powr(nb, -5, 3);
  const double _t83 = _t73*_t82;
  const double _t29 = _t26*_t28;
  const double _t30 = _t29*nb;
  const double _t31 = my_piecewise3(_t25, 0, -_t30);
  const double _t32 = _hc9[0]*_t28;
  const double _t33 = _t32*na;
  const double _t34 = my_piecewise3(_t22, 0, _hc9[0]*_t21 - _t33);
  const double _t35 = _hc7[0]*_t28;
  const double _t36 = _t35*nb;
  const double _t43 = _hc6[1]*_t42;
  const double _t44 = -_hc6[2]*_t39 - _t43*gaa;
  const double _t45 = my_piecewise3(_t19, 0, _hc7[1]*_t21*_t44*nb - _t36);
  const double _t46 = _t24*_t28;
  const double _t47 = _t46*na;
  const double _t48 = _hc1[0]*_hc2[1];
  const double _t49 = _t1*_t48;
  const double _t50 = _t4*_t49;
  const double _t52 = _hc0[1]*_t42;
  const double _t53 = -_hc0[2]*_t39 - _t52*gaa;
  const double _t54 = my_piecewise3(_t23, 0, _hc1[0]*_hc2[0]*_t21 + _hc1[1]*_hc2[0]*_t21*_t53*na - _t47 - _t50*_t51);
  const double _t55 = _t31 + _t34 + _t45 + _t54;
  const double _t56 = my_piecewise3(_t23, 0, -_t47);
  const double _t57 = my_piecewise3(_t19, 0, _hc7[0]*_t21 - _t36);
  const double _t63 = _hc8[1]*_t62;
  const double _t64 = -_hc8[2]*_t60 - _t63*gbb;
  const double _t65 = my_piecewise3(_t22, 0, _hc9[1]*_t21*_t64*na - _t33);
  const double _t66 = _hc4[0]*_hc5[1];
  const double _t67 = _t14*_t66;
  const double _t68 = _t4*_t67;
  const double _t69 = _hc3[1]*_t62;
  const double _t70 = -_hc3[2]*_t60 - _t69*gbb;
  const double _t71 = my_piecewise3(_t25, 0, _hc4[0]*_hc5[0]*_t21 + _hc4[1]*_hc5[0]*_t21*_t70*nb - _t30 - _t51*_t68);
  const double _t72 = _t56 + _t57 + _t65 + _t71;
  const double _t75 = _hc1[1]*_hc2[0];
  const double _t76 = _hc0[1]*_t75;
  const double _t77 = _t74*_t76;
  const double _t78 = _hc7[1]*_t21;
  const double _t79 = _t78*nb;
  const double _t80 = _hc6[1]*_t12;
  const double _t81 = my_piecewise3(_t19, 0, _t79*_t80) + my_piecewise3(_t23, 0, _t73*_t77);
  const double _t84 = _hc3[1]*_hc4[1];
  const double _t85 = _hc5[0]*_t84;
  const double _t86 = _hc9[1]*_t21;
  const double _t87 = _t86*na;
  const double _t88 = _hc8[1]*_t17;
  const double _t89 = my_piecewise3(_t22, 0, _t87*_t88) + my_piecewise3(_t25, 0, _t83*_t85);
  const double dF_dna = _t20*_t55 + _t27;
  const double dF_dnb = _t20*_t72 + _t27;
  const double dF_dgaa = _t20*_t81;
  const double dF_dgbb = _t20*_t89;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t90 = (0.1e1 / (_t20 * _t20 * _t20));
  const double _t97 = _t28*nb;
  const double _t104 = xc_powr(na, -7, 3);
  const double _t105 = (0.2e1 / 0.9e1)*_t4;
  const double _t106 = _t104*_t105;
  const double _t110 = xc_powr(na, -14, 3);
  const double _t111 = (0.22e2 / 0.81e2)*_t110;
  const double _t119 = (0.1e1 / 0.9e1)*_t21;
  const double _t126 = 0.2e1*_t21;
  const double _t127 = _t28*na;
  const double _t129 = _t21*na;
  const double _t133 = _t21*_t4;
  const double _t134 = (0.1e1 / 0.3e1)*_t133;
  const double _t165 = xc_powr(nb, -7, 3);
  const double _t166 = _t105*_t165;
  const double _t170 = xc_powr(nb, -14, 3);
  const double _t171 = (0.22e2 / 0.81e2)*_t170;
  const double _t179 = _t21*nb;
  const double _t184 = _t134*_t14;
  const double _t199 = (0.1e1 / (na * na * na * na));
  const double _t200 = (0.1e1 / M_PI);
  const double _t201 = (0.1e1 / 0.36e2)*_t200;
  const double _t202 = _t199*_t201;
  const double _t203 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t204 = _t2*_t203;
  const double _t206 = xc_powr(na, -19, 3);
  const double _t207 = (0.1e1 / 0.81e2)*_t206;
  const double _t208 = _t207*gaa;
  const double _t214 = _t201*_t21;
  const double _t215 = (0.1e1 / (na * na * na));
  const double _t219 = _t11*_t28;
  const double _t230 = _t219*_t82;
  const double _t240 = (0.1e1 / (nb * nb * nb * nb));
  const double _t241 = _t201*_t240;
  const double _t243 = xc_powr(nb, -19, 3);
  const double _t244 = (0.1e1 / 0.81e2)*_t243;
  const double _t245 = _t244*gbb;
  const double _t252 = (0.1e1 / (nb * nb * nb));
  const double _t253 = _t214*_t252;
  const double _t264 = (0.1e1 / 0.216e3)*_t21;
  const double _t265 = xc_powr(na, -13, 3);
  const double _t268 = _t204*_t265;
  const double _t269 = _t264*_t268;
  const double _t272 = xc_powr(na, -16, 3);
  const double _t273 = (0.1e1 / 0.216e3)*_t272;
  const double _t279 = xc_powr(nb, -13, 3);
  const double _t280 = _t264*_t279;
  const double _t283 = _t204*_t280;
  const double _t287 = xc_powr(nb, -16, 3);
  const double _t288 = (0.1e1 / 0.216e3)*_t287;
  const double _t91 = _t26*_t90;
  const double _t92 = 0.2e1*_t91*nb;
  const double _t93 = my_piecewise3(_t25, 0, _t92);
  const double _t94 = 0.2e1*_hc9[0]*_t90*na;
  const double _t95 = my_piecewise3(_t22, 0, -0.2e1*_t32 + _t94);
  const double _t96 = 0.2e1*_hc7[0]*_t90*nb;
  const double _t98 = _hc7[1]*_t44;
  const double _t99 = _t97*_t98;
  const double _t100 = (_t44 * _t44);
  const double _t101 = _hc7[2]*_t100;
  const double _t102 = _hc6[4]*_t42;
  const double _t103 = -_hc6[5]*_t39 - _t102*gaa;
  const double _t107 = _hc6[3]*_t42;
  const double _t108 = -_hc6[4]*_t39 - _t107*gaa;
  const double _t109 = _t108*_t42;
  const double _t112 = _hc6[1]*_t10;
  const double _t113 = _t111*_t112;
  const double _t114 = _hc6[2]*_t106 - _t109*gaa + _t113*gaa;
  const double _t115 = -_t103*_t39 + _t114;
  const double _t116 = my_piecewise3(_t19, 0, _t101*_t21*nb + _t115*_t78*nb + _t96 - 0.2e1*_t99);
  const double _t117 = _t24*_t90;
  const double _t118 = 0.2e1*_t117*na;
  const double _t120 = _t38*_t48;
  const double _t121 = _t28*_t50;
  const double _t122 = _hc1[0]*_hc2[2];
  const double _t123 = _t122*_t74;
  const double _t124 = _hc1[1]*_t53;
  const double _t125 = _hc2[0]*_t124;
  const double _t128 = _t125*_t127;
  const double _t130 = _hc2[0]*_t129;
  const double _t131 = (_t53 * _t53);
  const double _t132 = _hc1[2]*_t131;
  const double _t135 = _hc2[1]*_t124;
  const double _t136 = _t1*_t135;
  const double _t137 = _hc0[4]*_t42;
  const double _t138 = -_hc0[5]*_t39 - _t137*gaa;
  const double _t139 = _hc0[3]*_t42;
  const double _t140 = -_hc0[4]*_t39 - _t139*gaa;
  const double _t141 = _t140*_t42;
  const double _t142 = _hc0[1]*_t10;
  const double _t143 = _t111*_t142;
  const double _t144 = _hc0[2]*_t106 - _t141*gaa + _t143*gaa;
  const double _t145 = -_t138*_t39 + _t144;
  const double _t146 = _hc1[1]*_t130;
  const double _t147 = my_piecewise3(_t23, 0, _t118 - _t119*_t120 + (0.1e1 / 0.3e1)*_t121 + _t123*_t73 + _t125*_t126 - 0.2e1*_t128 + _t130*_t132 - _t134*_t136 + _t145*_t146 - 0.2e1*_t46);
  const double _t148 = _t116 + _t147 + _t93 + _t95;
  const double _t149 = my_piecewise3(_t23, 0, _t118 + (0.1e1 / 0.6e1)*_t121 - _t128 - _t46);
  const double _t150 = _t28*_t68;
  const double _t151 = _hc4[1]*_t70;
  const double _t152 = _hc5[0]*_t151;
  const double _t153 = _t152*_t97;
  const double _t154 = my_piecewise3(_t25, 0, (0.1e1 / 0.6e1)*_t150 - _t153 - _t29 + _t92);
  const double _t155 = my_piecewise3(_t19, 0, -_t35 + _t44*_t78 + _t96 - _t99);
  const double _t156 = _hc9[1]*_t64;
  const double _t157 = _t127*_t156;
  const double _t158 = my_piecewise3(_t22, 0, -_t157 - _t32 + _t64*_t86 + _t94);
  const double _t159 = my_piecewise3(_t23, 0, _t118);
  const double _t160 = my_piecewise3(_t19, 0, -0.2e1*_t35 + _t96);
  const double _t161 = (_t64 * _t64);
  const double _t162 = _hc9[2]*_t161;
  const double _t163 = _hc8[4]*_t62;
  const double _t164 = -_hc8[5]*_t60 - _t163*gbb;
  const double _t167 = _hc8[3]*_t62;
  const double _t168 = -_hc8[4]*_t60 - _t167*gbb;
  const double _t169 = _t168*_t62;
  const double _t172 = _hc8[1]*_t10;
  const double _t173 = _t171*_t172;
  const double _t174 = _hc8[2]*_t166 - _t169*gbb + _t173*gbb;
  const double _t175 = -_t164*_t60 + _t174;
  const double _t176 = my_piecewise3(_t22, 0, -0.2e1*_t157 + _t162*_t21*na + _t175*_t86*na + _t94);
  const double _t177 = _t59*_t66;
  const double _t178 = _hc4[0]*_hc5[2];
  const double _t180 = _hc5[0]*_t179;
  const double _t181 = (_t70 * _t70);
  const double _t182 = _hc4[2]*_t181;
  const double _t183 = _hc5[1]*_t151;
  const double _t185 = _hc3[4]*_t62;
  const double _t186 = -_hc3[5]*_t60 - _t185*gbb;
  const double _t187 = _hc3[3]*_t62;
  const double _t188 = -_hc3[4]*_t60 - _t187*gbb;
  const double _t189 = _t188*_t62;
  const double _t190 = _hc3[1]*_t10;
  const double _t191 = _t171*_t190;
  const double _t192 = _hc3[2]*_t166 - _t189*gbb + _t191*gbb;
  const double _t193 = -_t186*_t60 + _t192;
  const double _t194 = _hc4[1]*_t180;
  const double _t195 = my_piecewise3(_t25, 0, -_t119*_t177 + _t126*_t152 + (0.1e1 / 0.3e1)*_t150 - 0.2e1*_t153 + _t178*_t83 + _t180*_t182 - _t183*_t184 + _t193*_t194 - 0.2e1*_t29 + _t92);
  const double _t196 = _t159 + _t160 + _t176 + _t195;
  const double _t197 = _hc7[1]*_t97;
  const double _t198 = _t197*_t80;
  const double _t205 = _hc6[3]*_t204;
  const double _t209 = -_hc6[4]*_t202 - _t205*_t208 - _t43;
  const double _t210 = _t209*_t78;
  const double _t211 = _hc7[2]*_t179;
  const double _t212 = _t211*_t44;
  const double _t213 = my_piecewise3(_t19, 0, -_t198 + _t210*nb + _t212*_t80);
  const double _t216 = _hc1[1]*_hc2[1];
  const double _t217 = _hc0[1]*_t216;
  const double _t218 = _t215*_t217;
  const double _t220 = -_t219*_t77;
  const double _t221 = _hc0[3]*_t204;
  const double _t222 = _t221*gaa;
  const double _t223 = -_hc0[4]*_t202 - _t207*_t222 - _t52;
  const double _t224 = _hc1[2]*_hc2[0];
  const double _t225 = _t224*_t53;
  const double _t226 = _t225*_t74;
  const double _t227 = _hc0[1]*_t226;
  const double _t228 = my_piecewise3(_t23, 0, _t12*_t21*_t76 + _t146*_t223 - _t214*_t218 + _t220 + _t227*_t73);
  const double _t229 = _t213 + _t228;
  const double _t231 = -_t230*_t85;
  const double _t232 = my_piecewise3(_t25, 0, _t231);
  const double _t233 = _hc9[1]*_t127;
  const double _t234 = _t233*_t88;
  const double _t235 = my_piecewise3(_t22, 0, (0.1e1 / 0.36e2)*_hc8[1]*_hc9[1]*_t16*_t21*_t8*_t9 - _t234);
  const double _t236 = _t232 + _t235;
  const double _t237 = my_piecewise3(_t23, 0, _t220);
  const double _t238 = my_piecewise3(_t19, 0, (0.1e1 / 0.36e2)*_hc6[1]*_hc7[1]*_t21*_t7*_t8*_t9 - _t198);
  const double _t239 = _t237 + _t238;
  const double _t242 = _hc8[3]*_t204;
  const double _t246 = -_hc8[4]*_t241 - _t242*_t245 - _t63;
  const double _t247 = _t246*_t86;
  const double _t248 = _hc9[2]*_t21;
  const double _t249 = _t248*_t64;
  const double _t250 = _t249*na;
  const double _t251 = my_piecewise3(_t22, 0, -_t234 + _t247*na + _t250*_t88);
  const double _t254 = _hc5[1]*_t84;
  const double _t255 = _t17*_t85;
  const double _t256 = _hc3[3]*_t204;
  const double _t257 = _t256*gbb;
  const double _t258 = -_hc3[4]*_t241 - _t244*_t257 - _t69;
  const double _t259 = _hc4[2]*_t70;
  const double _t260 = _hc3[1]*_t259;
  const double _t261 = _hc5[0]*_t260;
  const double _t262 = my_piecewise3(_t25, 0, _t194*_t258 + _t21*_t255 + _t231 - _t253*_t254 + _t261*_t83);
  const double _t263 = _t251 + _t262;
  const double _t266 = _t221*_t75;
  const double _t267 = _t265*_t266;
  const double _t270 = ((_hc0[1]) * (_hc0[1]));
  const double _t271 = _t224*_t270;
  const double _t274 = _t205*_t273;
  const double _t275 = ((_hc6[1]) * (_hc6[1]));
  const double _t276 = _t204*_t275;
  const double _t277 = _t273*_t276;
  const double _t278 = my_piecewise3(_t19, 0, _t211*_t277 + _t274*_t79) + my_piecewise3(_t23, 0, _t264*_t267 + _t269*_t271);
  const double _t281 = _hc4[1]*_hc5[0];
  const double _t282 = _t256*_t281;
  const double _t284 = ((_hc3[1]) * (_hc3[1]));
  const double _t285 = _hc4[2]*_t284;
  const double _t286 = _hc5[0]*_t285;
  const double _t289 = _t242*_t288;
  const double _t290 = _t248*na;
  const double _t291 = ((_hc8[1]) * (_hc8[1]));
  const double _t292 = _t204*_t291;
  const double _t293 = _t288*_t292;
  const double _t294 = my_piecewise3(_t22, 0, _t289*_t87 + _t290*_t293) + my_piecewise3(_t25, 0, _t280*_t282 + _t283*_t286);
  const double d2F_dna2 = _t148*_t20 + 0.2e1*_t31 + 0.2e1*_t34 + 0.2e1*_t45 + 0.2e1*_t54;
  const double d2F_dna_dnb = _t20*(_t149 + _t154 + _t155 + _t158) + _t55 + _t72;
  const double d2F_dnb2 = _t196*_t20 + 0.2e1*_t56 + 0.2e1*_t57 + 0.2e1*_t65 + 0.2e1*_t71;
  const double d2F_dna_dgaa = _t20*_t229 + _t81;
  const double d2F_dna_dgbb = _t20*_t236 + _t89;
  const double d2F_dnb_dgaa = _t20*_t239 + _t81;
  const double d2F_dnb_dgbb = _t20*_t263 + _t89;
  const double d2F_dgaa2 = _t20*_t278;
  const double d2F_dgbb2 = _t20*_t294;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 2] += d2F_dna_dgbb;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 3] += d2F_dnb_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
#endif
#if _KMAX >= 3
  const double _t295 = (0.1e1 / (_t20 * _t20 * _t20 * _t20));
  const double _t308 = 0.6e1*_t90;
  const double _t315 = (0.1e1 / 0.3e1)*_t38;
  const double _t316 = (0.4e1 / 0.9e1)*_t104;
  const double _t318 = (0.4e1 / 0.27e2)*_t40;
  const double _t321 = (0.44e2 / 0.81e2)*_t110;
  const double _t326 = xc_powr(na, -10, 3);
  const double _t327 = (0.14e2 / 0.27e2)*_t326;
  const double _t328 = xc_powr(na, -17, 3);
  const double _t329 = (0.308e3 / 0.243e3)*_t328;
  const double _t331 = _t10*_t111;
  const double _t354 = _t104*_t4;
  const double _t355 = (0.4e1 / 0.27e2)*_t21;
  const double _t357 = _t4*_t90;
  const double _t361 = (0.1e1 / 0.12e2)*_t10;
  const double _t362 = 0.6e1*_t28;
  const double _t363 = _t308*na;
  const double _t364 = 0.3e1*_t21;
  const double _t369 = _t28*_t4;
  const double _t370 = _t1*_t369;
  const double _t372 = _t21*_t361;
  const double _t375 = _t21*_t6;
  const double _t407 = 0.2e1*_t28;
  const double _t432 = (0.1e1 / 0.3e1)*_t59;
  const double _t433 = (0.4e1 / 0.9e1)*_t165;
  const double _t435 = (0.4e1 / 0.27e2)*_t61;
  const double _t438 = (0.44e2 / 0.81e2)*_t170;
  const double _t443 = xc_powr(nb, -10, 3);
  const double _t444 = (0.14e2 / 0.27e2)*_t443;
  const double _t445 = xc_powr(nb, -17, 3);
  const double _t446 = (0.308e3 / 0.243e3)*_t445;
  const double _t448 = _t10*_t171;
  const double _t467 = _t28*_t361;
  const double _t472 = _t14*_t369;
  const double _t473 = _t21*_t432;
  const double _t503 = (0.1e1 / 0.18e2)*_t90;
  const double _t510 = (0.1e1 / 0.18e2)*_t7;
  const double _t514 = (0.1e1 / 0.18e2)*_t199;
  const double _t516 = (0.2e1 / 0.81e2)*_t204;
  const double _t517 = _t206*_t516;
  const double _t521 = xc_powi(na, -5);
  const double _t522 = (0.1e1 / 0.27e2)*_t521;
  const double _t523 = xc_powr(na, -22, 3);
  const double _t524 = (0.11e2 / 0.243e3)*_t523;
  const double _t525 = _t524*gaa;
  const double _t526 = _t204*_t208;
  const double _t529 = _t204*_t207;
  const double _t531 = _t42*gaa;
  const double _t534 = (0.1e1 / 0.54e2)*_t21;
  const double _t536 = (0.1e1 / 0.18e2)*_t28;
  const double _t540 = _t536*_t7;
  const double _t544 = (0.1e1 / 0.18e2)*_t200;
  const double _t553 = _t73*_t74;
  const double _t558 = _t1*_t134;
  const double _t573 = _t16*_t536;
  const double _t595 = (0.1e1 / 0.18e2)*_t16;
  const double _t599 = (0.1e1 / 0.18e2)*_t240;
  const double _t601 = _t243*_t516;
  const double _t605 = xc_powi(nb, -5);
  const double _t606 = (0.1e1 / 0.27e2)*_t605;
  const double _t607 = xc_powr(nb, -22, 3);
  const double _t608 = (0.11e2 / 0.243e3)*_t607;
  const double _t609 = _t608*gbb;
  const double _t610 = _t204*_t245;
  const double _t613 = _t204*_t244;
  const double _t615 = _t62*gbb;
  const double _t644 = xc_powi(na, -9);
  const double _t645 = (0.1e1 / (M_PI * M_PI));
  const double _t646 = (0.1e1 / 0.486e3)*_t645;
  const double _t647 = _t644*_t646;
  const double _t648 = _t647*gaa;
  const double _t649 = xc_powr(na, -20, 3);
  const double _t650 = (0.1e1 / (M_PI * M_CBRTPI * M_CBRTPI));
  const double _t651 = _t650*_t8;
  const double _t652 = (0.1e1 / 0.1296e4)*_t651;
  const double _t653 = _t649*_t652;
  const double _t659 = _t21*_t273;
  const double _t660 = (0.1e1 / 0.216e3)*_t28;
  const double _t662 = _t328*_t652;
  const double _t665 = _t204*_t659;
  const double _t666 = _t268*_t660;
  const double _t682 = _t279*_t660;
  const double _t694 = xc_powi(nb, -9);
  const double _t695 = _t646*_t694;
  const double _t696 = _t695*gbb;
  const double _t697 = xc_powr(nb, -20, 3);
  const double _t698 = _t652*_t697;
  const double _t704 = _t21*_t288;
  const double _t705 = _t445*_t652;
  const double _t720 = xc_powi(na, -7);
  const double _t721 = (0.1e1 / 0.1296e4)*_t645;
  const double _t722 = _t21*_t721;
  const double _t723 = _t720*_t722;
  const double _t726 = (0.1e1 / 0.432e3)*_t645;
  const double _t727 = _t720*_t726;
  const double _t731 = xc_powi(na, -8);
  const double _t732 = _t721*_t731;
  const double _t734 = _t726*_t731;
  const double _t739 = xc_powi(nb, -7);
  const double _t740 = _t722*_t739;
  const double _t744 = _t726*_t739;
  const double _t748 = xc_powi(nb, -8);
  const double _t749 = _t721*_t748;
  const double _t751 = _t726*_t748;
  const double _t296 = _t26*_t295;
  const double _t297 = 0.6e1*_t296;
  const double _t298 = _t297*nb;
  const double _t299 = -_t298;
  const double _t300 = my_piecewise3(_t25, 0, _t299);
  const double _t301 = _hc9[0]*_t295;
  const double _t302 = 0.6e1*_t301;
  const double _t303 = _t302*na;
  const double _t304 = my_piecewise3(_t22, 0, 0.6e1*_hc9[0]*_t90 - _t303);
  const double _t305 = _hc7[0]*_t295;
  const double _t306 = 0.6e1*_t305;
  const double _t307 = _t306*nb;
  const double _t309 = _t308*_t98;
  const double _t310 = (_t44 * _t44 * _t44);
  const double _t311 = _hc7[3]*_t310;
  const double _t312 = _t21*_t311;
  const double _t313 = _t101*_t97;
  const double _t314 = _t115*_t197;
  const double _t317 = _hc6[2]*_t4;
  const double _t319 = _t10*_t108;
  const double _t320 = _t318*_t319;
  const double _t322 = _t112*_t321;
  const double _t323 = _t316*_t317 - _t320*gaa + _t322*gaa;
  const double _t324 = -_t103*_t315 + _t323;
  const double _t325 = _t324*_t44;
  const double _t330 = _t112*_t329;
  const double _t332 = _hc6[4]*_t331;
  const double _t333 = _hc6[8]*_t42;
  const double _t334 = -_hc6[9]*_t39 - _t333*gaa;
  const double _t335 = _hc6[7]*_t42;
  const double _t336 = -_hc6[8]*_t39 - _t335*gaa;
  const double _t337 = _t336*_t42;
  const double _t338 = _hc6[5]*_t106 + _t332*gaa - _t334*_t39 - _t337*gaa;
  const double _t339 = _hc6[3]*_t331;
  const double _t340 = _hc6[6]*_t42;
  const double _t341 = -_hc6[7]*_t39 - _t340*gaa;
  const double _t342 = _t341*_t42;
  const double _t343 = _hc6[4]*_t106 - _t336*_t39 + _t339*gaa - _t342*gaa;
  const double _t344 = _t343*_t42;
  const double _t345 = (0.4e1 / 0.9e1)*_t103*_t104*_t2*_t3 + (0.44e2 / 0.81e2)*_t108*_t110*_t8*_t9*gaa - _t317*_t327 - _t330*gaa - _t338*_t39 - _t344*gaa;
  const double _t346 = _t345*_t78;
  const double _t347 = my_piecewise3(_t19, 0, _t115*_t212 + _t211*_t325 - _t307 + _t309*nb + _t312*nb - 0.3e1*_t313 - 0.3e1*_t314 + _t346*nb);
  const double _t348 = _t24*_t295;
  const double _t349 = 0.6e1*_t348;
  const double _t350 = _t349*na;
  const double _t351 = -_t350;
  const double _t352 = _hc1[0]*_hc2[3];
  const double _t353 = _t215*_t352;
  const double _t356 = _t28*_t48;
  const double _t358 = _t357*_t49;
  const double _t359 = _t122*_t21;
  const double _t360 = _t123*_t28;
  const double _t365 = _hc2[0]*_t132;
  const double _t366 = (_t53 * _t53 * _t53);
  const double _t367 = _hc1[3]*_t366;
  const double _t368 = _t127*_t365;
  const double _t371 = _t135*_t21;
  const double _t373 = _hc2[2]*_t124;
  const double _t374 = _t373*_t74;
  const double _t376 = _hc2[1]*_t132;
  const double _t377 = _t145*_t75;
  const double _t378 = _t127*_t377;
  const double _t379 = _t145*_t216;
  const double _t380 = _hc1[2]*_t130;
  const double _t381 = _t380*_t53;
  const double _t382 = _hc0[2]*_t4;
  const double _t383 = _t10*_t140;
  const double _t384 = _t318*_t383;
  const double _t385 = _t142*_t321;
  const double _t386 = _t316*_t382 - _t384*gaa + _t385*gaa;
  const double _t387 = -_t138*_t315 + _t386;
  const double _t388 = _t142*_t329;
  const double _t389 = _hc0[4]*_t331;
  const double _t390 = _hc0[8]*_t42;
  const double _t391 = -_hc0[9]*_t39 - _t390*gaa;
  const double _t392 = _hc0[7]*_t42;
  const double _t393 = -_hc0[8]*_t39 - _t392*gaa;
  const double _t394 = _t393*_t42;
  const double _t395 = _hc0[5]*_t106 + _t389*gaa - _t39*_t391 - _t394*gaa;
  const double _t396 = _hc0[3]*_t331;
  const double _t397 = _hc0[6]*gaa;
  const double _t398 = -_hc0[7]*_t39 - _t397*_t42;
  const double _t399 = _t398*_t42;
  const double _t400 = _hc0[4]*_t106 - _t39*_t393 + _t396*gaa - _t399*gaa;
  const double _t401 = _t400*_t42;
  const double _t402 = (0.4e1 / 0.9e1)*_t104*_t138*_t2*_t3 + (0.44e2 / 0.81e2)*_t110*_t140*_t8*_t9*gaa - _t327*_t382 - _t388*gaa - _t39*_t395 - _t401*gaa;
  const double _t403 = my_piecewise3(_t23, 0, 0.6e1*_t117 - _t12*_t359 - _t125*_t362 + _t125*_t363 + _t130*_t367 + _t135*_t370 + _t145*_t381 + _t146*_t402 - _t214*_t353 + _t315*_t356 - _t315*_t371 + _t351 + _t354*_t355*_t48 - _t358 - _t360*_t361 + _t364*_t365 + _t364*_t377 - 0.3e1*_t368 + _t372*_t374 - _t375*_t376 - _t375*_t379 - 0.3e1*_t378 + _t381*_t387);
  const double _t404 = _t300 + _t304 + _t347 + _t403;
  const double _t405 = _t357*_t67;
  const double _t406 = my_piecewise3(_t25, 0, 0.2e1*_hc4[0]*_hc5[0]*_t90 + 0.2e1*_hc4[1]*_hc5[0]*_t70*_t90*nb - _t298 - 0.1e1 / 0.3e1*_t405);
  const double _t408 = _t156*_t407 + _t303;
  const double _t409 = my_piecewise3(_t22, 0, 0.4e1*_hc9[0]*_t90 + 0.2e1*_hc9[1]*_t64*_t90*na - _t408);
  const double _t410 = my_piecewise3(_t23, 0, 0.4e1*_hc1[0]*_hc2[0]*_t90 + (0.1e1 / 0.9e1)*_hc1[0]*_hc2[1]*_t2*_t28*_t3*_t37 + 0.4e1*_hc1[1]*_hc2[0]*_t53*_t90*na + (0.1e1 / 0.3e1)*_hc1[1]*_hc2[1]*_t1*_t2*_t28*_t3*_t53 - _t11*_t360 - _t125*_t407 - _t350 - 0.2e1 / 0.3e1*_t358 - _t368 - _t378);
  const double _t411 = _t307 + _t407*_t98;
  const double _t412 = my_piecewise3(_t19, 0, 0.2e1*_hc7[0]*_t90 + _hc7[1]*_t115*_t21 + 0.4e1*_hc7[1]*_t44*_t90*nb + _hc7[2]*_t100*_t21 - _t313 - _t314 - _t411);
  const double _t413 = 0.2e1*_t149 + 0.2e1*_t154 + 0.2e1*_t155 + 0.2e1*_t158;
  const double _t414 = my_piecewise3(_t23, 0, 0.2e1*_hc1[0]*_hc2[0]*_t90 + 0.2e1*_hc1[1]*_hc2[0]*_t53*_t90*na - _t350 - 0.1e1 / 0.3e1*_t358);
  const double _t415 = my_piecewise3(_t19, 0, 0.4e1*_hc7[0]*_t90 + 0.2e1*_hc7[1]*_t44*_t90*nb - _t411);
  const double _t416 = _t178*_t82;
  const double _t417 = _hc5[0]*_t97;
  const double _t418 = _t182*_t417;
  const double _t419 = _hc4[1]*_t193;
  const double _t420 = _t417*_t419;
  const double _t421 = my_piecewise3(_t25, 0, 0.4e1*_hc4[0]*_hc5[0]*_t90 + (0.1e1 / 0.9e1)*_hc4[0]*_hc5[1]*_t2*_t28*_t3*_t58 + 0.4e1*_hc4[1]*_hc5[0]*_t70*_t90*nb + (0.1e1 / 0.3e1)*_hc4[1]*_hc5[1]*_t14*_t2*_t28*_t3*_t70 - _t152*_t407 - _t219*_t416 - _t298 - 0.2e1 / 0.3e1*_t405 - _t418 - _t420);
  const double _t422 = _t175*_t233;
  const double _t423 = _t127*_t162;
  const double _t424 = my_piecewise3(_t22, 0, 0.2e1*_hc9[0]*_t90 + _hc9[1]*_t175*_t21 + 0.4e1*_hc9[1]*_t64*_t90*na + _hc9[2]*_t161*_t21 - _t408 - _t422 - _t423);
  const double _t425 = my_piecewise3(_t23, 0, _t351);
  const double _t426 = my_piecewise3(_t19, 0, 0.6e1*_hc7[0]*_t90 - _t307);
  const double _t427 = _t156*_t308;
  const double _t428 = (_t64 * _t64 * _t64);
  const double _t429 = _hc9[3]*_t428;
  const double _t430 = _t21*_t429;
  const double _t431 = _t175*_t249;
  const double _t434 = _hc8[2]*_t4;
  const double _t436 = _t10*_t168;
  const double _t437 = _t435*_t436;
  const double _t439 = _t172*_t438;
  const double _t440 = _t433*_t434 - _t437*gbb + _t439*gbb;
  const double _t441 = -_t164*_t432 + _t440;
  const double _t442 = _t249*_t441;
  const double _t447 = _t172*_t446;
  const double _t449 = _hc8[4]*_t448;
  const double _t450 = _hc8[8]*_t62;
  const double _t451 = -_hc8[9]*_t60 - _t450*gbb;
  const double _t452 = _hc8[7]*_t62;
  const double _t453 = -_hc8[8]*_t60 - _t452*gbb;
  const double _t454 = _t453*_t62;
  const double _t455 = _hc8[5]*_t166 + _t449*gbb - _t451*_t60 - _t454*gbb;
  const double _t456 = _hc8[3]*_t448;
  const double _t457 = _hc8[6]*_t62;
  const double _t458 = -_hc8[7]*_t60 - _t457*gbb;
  const double _t459 = _t458*_t62;
  const double _t460 = _hc8[4]*_t166 - _t453*_t60 + _t456*gbb - _t459*gbb;
  const double _t461 = _t460*_t62;
  const double _t462 = (0.4e1 / 0.9e1)*_t164*_t165*_t2*_t3 + (0.44e2 / 0.81e2)*_t168*_t170*_t8*_t9*gbb - _t434*_t444 - _t447*gbb - _t455*_t60 - _t461*gbb;
  const double _t463 = _t462*_t86;
  const double _t464 = my_piecewise3(_t22, 0, -_t303 - 0.3e1*_t422 - 0.3e1*_t423 + _t427*na + _t430*na + _t431*na + _t442*na + _t463*na);
  const double _t465 = _hc4[0]*_hc5[3];
  const double _t466 = _t165*_t66;
  const double _t468 = _t152*nb;
  const double _t469 = _hc5[0]*_t364;
  const double _t470 = (_t70 * _t70 * _t70);
  const double _t471 = _hc4[3]*_t470;
  const double _t474 = _hc5[2]*_t151;
  const double _t475 = _t474*_t82;
  const double _t476 = _hc5[1]*_t21;
  const double _t477 = _t15*_t476;
  const double _t478 = _hc4[2]*_t180;
  const double _t479 = _t478*_t70;
  const double _t480 = _hc3[2]*_t4;
  const double _t481 = _t10*_t188;
  const double _t482 = _t435*_t481;
  const double _t483 = _t190*_t438;
  const double _t484 = _t433*_t480 - _t482*gbb + _t483*gbb;
  const double _t485 = -_t186*_t432 + _t484;
  const double _t486 = _t190*_t446;
  const double _t487 = _hc3[4]*_t448;
  const double _t488 = _hc3[8]*_t62;
  const double _t489 = -_hc3[9]*_t60 - _t488*gbb;
  const double _t490 = _hc3[7]*_t62;
  const double _t491 = -_hc3[8]*_t60 - _t490*gbb;
  const double _t492 = _t491*_t62;
  const double _t493 = _hc3[5]*_t166 + _t487*gbb - _t489*_t60 - _t492*gbb;
  const double _t494 = _hc3[3]*_t448;
  const double _t495 = _hc3[6]*gbb;
  const double _t496 = -_hc3[7]*_t60 - _t495*_t62;
  const double _t497 = _t496*_t62;
  const double _t498 = _hc3[4]*_t166 - _t491*_t60 + _t494*gbb - _t497*gbb;
  const double _t499 = _t498*_t62;
  const double _t500 = (0.4e1 / 0.9e1)*_t165*_t186*_t2*_t3 + (0.44e2 / 0.81e2)*_t170*_t188*_t8*_t9*gbb - _t444*_t480 - _t486*gbb - _t493*_t60 - _t499*gbb;
  const double _t501 = my_piecewise3(_t25, 0, -_t152*_t362 - _t17*_t178*_t21 + _t180*_t471 + _t182*_t469 - _t182*_t477 + _t183*_t472 - _t183*_t473 + _t193*_t479 + _t194*_t500 - _t253*_t465 + _t28*_t432*_t66 + _t299 + _t308*_t468 + _t355*_t4*_t466 + _t372*_t475 - _t405 - _t416*_t467 - 0.3e1*_t418 + _t419*_t469 - _t419*_t477 - 0.3e1*_t420 + _t479*_t485 + 0.6e1*_t91);
  const double _t502 = _t425 + _t426 + _t464 + _t501;
  const double _t504 = _hc7[1]*_t112;
  const double _t505 = _t504*_t7;
  const double _t506 = _t503*_t505*nb;
  const double _t507 = _t197*_t209;
  const double _t508 = _hc7[2]*_t97;
  const double _t509 = _t44*_t508;
  const double _t511 = _t112*_t510;
  const double _t512 = _hc7[3]*_t179;
  const double _t513 = _t100*_t512;
  const double _t515 = _hc6[4]*_t200;
  const double _t518 = _hc6[3]*_t517;
  const double _t519 = -_t112*_t318 - _t514*_t515 - _t518*gaa;
  const double _t520 = _t115*_t80;
  const double _t527 = -_hc6[7]*_t526 - _hc6[8]*_t202 - _t102;
  const double _t528 = _hc6[6]*gaa;
  const double _t530 = -_hc6[7]*_t202 - _t107 - _t528*_t529;
  const double _t532 = -_t109 + _t113 + _t205*_t525 - _t39*_t527 + _t515*_t522 - _t530*_t531;
  const double _t533 = my_piecewise3(_t19, 0, _t211*_t520 + _t212*_t519 + _t506 - 0.2e1*_t507 - _t509*_t511 + _t513*_t80 + _t532*_t78*nb);
  const double _t535 = _t200*_t217;
  const double _t537 = _t200*_t218;
  const double _t538 = _hc1[1]*_hc2[2];
  const double _t539 = _hc0[1]*_t538;
  const double _t541 = _t142*_t75;
  const double _t542 = _t541*_t74;
  const double _t543 = _t503*_t542;
  const double _t545 = _hc0[1]*_t53;
  const double _t546 = _hc1[2]*_t545;
  const double _t547 = _hc2[1]*_t21;
  const double _t548 = _t215*_t547;
  const double _t549 = _t223*_t75;
  const double _t550 = _t127*_t549;
  const double _t551 = _t142*_t225;
  const double _t552 = _t142*_t226;
  const double _t554 = _hc1[3]*_t131;
  const double _t555 = _hc0[1]*_t554;
  const double _t556 = _hc2[0]*_t555;
  const double _t557 = _t216*_t223;
  const double _t559 = _hc0[4]*_t200;
  const double _t560 = _hc0[3]*_t517;
  const double _t561 = -_t142*_t318 - _t514*_t559 - _t560*gaa;
  const double _t562 = _hc0[1]*_t224;
  const double _t563 = _t553*_t562;
  const double _t564 = -_hc0[7]*_t526 - _hc0[8]*_t202 - _t137;
  const double _t565 = -_hc0[7]*_t202 - _t139 - _t397*_t529;
  const double _t566 = -_t141 + _t143 + _t222*_t524 - _t39*_t564 + _t522*_t559 - _t531*_t565;
  const double _t567 = my_piecewise3(_t23, 0, _t126*_t549 + _t145*_t563 + _t146*_t566 - _t199*_t534*_t535 + _t21*_t510*_t551 + _t269*_t539 + _t381*_t561 + _t536*_t537 - _t536*_t552 - _t540*_t541 + _t543 - _t544*_t546*_t548 - 0.2e1*_t550 + _t553*_t556 - _t557*_t558);
  const double _t568 = _t533 + _t567;
  const double _t569 = _t190*_t281;
  const double _t570 = _t569*_t82;
  const double _t571 = _t503*_t570;
  const double _t572 = my_piecewise3(_t25, 0, _t571);
  const double _t574 = _hc9[1]*_t172;
  const double _t575 = _t16*_t574;
  const double _t576 = _t503*_t575*na;
  const double _t577 = my_piecewise3(_t22, 0, -_t573*_t574 + _t576);
  const double _t578 = _t572 + _t577;
  const double _t579 = my_piecewise3(_t23, 0, (0.1e1 / 0.18e2)*_hc0[1]*_hc1[1]*_hc2[0]*_t74*_t8*_t9*_t90 + (0.1e1 / 0.36e2)*_hc0[1]*_hc1[1]*_hc2[1]*_t200*_t215*_t28 - _t12*_t28*_t76 - _t219*_t227 - _t550);
  const double _t580 = _hc7[1]*_t28;
  const double _t581 = _hc7[2]*_t21;
  const double _t582 = _t44*_t581;
  const double _t583 = my_piecewise3(_t19, 0, _t210 + _t506 - _t507 - _t509*_t80 - _t580*_t80 + _t582*_t80);
  const double _t584 = _hc4[1]*_t258;
  const double _t585 = _t417*_t584;
  const double _t586 = my_piecewise3(_t25, 0, (0.1e1 / 0.18e2)*_hc3[1]*_hc4[1]*_hc5[0]*_t8*_t82*_t9*_t90 + (0.1e1 / 0.36e2)*_hc3[1]*_hc4[1]*_hc5[1]*_t200*_t252*_t28 - _t230*_t261 - _t255*_t28 - _t585);
  const double _t587 = _hc9[1]*_t28;
  const double _t588 = _t233*_t246;
  const double _t589 = _hc9[2]*_t127;
  const double _t590 = _t589*_t64;
  const double _t591 = my_piecewise3(_t22, 0, _t247 + _t249*_t88 + _t576 - _t587*_t88 - _t588 - _t590*_t88);
  const double _t592 = my_piecewise3(_t23, 0, _t543);
  const double _t593 = my_piecewise3(_t19, 0, -_t504*_t540 + _t506);
  const double _t594 = _t592 + _t593;
  const double _t596 = _t172*_t595;
  const double _t597 = _hc9[3]*_t129;
  const double _t598 = _t161*_t597;
  const double _t600 = _hc8[4]*_t200;
  const double _t602 = _hc8[3]*_t601;
  const double _t603 = -_t172*_t435 - _t599*_t600 - _t602*gbb;
  const double _t604 = _t175*_t88;
  const double _t611 = -_hc8[7]*_t610 - _hc8[8]*_t241 - _t163;
  const double _t612 = _hc8[6]*gbb;
  const double _t614 = -_hc8[7]*_t241 - _t167 - _t612*_t613;
  const double _t616 = -_t169 + _t173 + _t242*_t609 - _t60*_t611 + _t600*_t606 - _t614*_t615;
  const double _t617 = my_piecewise3(_t22, 0, _t249*_t603*na + _t290*_t604 + _t576 - 0.2e1*_t588 - _t590*_t596 + _t598*_t88 + _t616*_t86*na);
  const double _t618 = _t200*_t254;
  const double _t619 = _t252*_t254;
  const double _t620 = _t200*_t619;
  const double _t621 = _hc5[2]*_t84;
  const double _t622 = _t252*_t260;
  const double _t623 = _hc5[0]*_t584;
  const double _t624 = _hc5[0]*_t21;
  const double _t625 = _t190*_t259;
  const double _t626 = _hc5[0]*_t625;
  const double _t627 = _t626*_t82;
  const double _t628 = _hc4[3]*_t181;
  const double _t629 = _hc3[1]*_t628;
  const double _t630 = _hc5[0]*_t83;
  const double _t631 = _hc5[1]*_t584;
  const double _t632 = _hc3[4]*_t200;
  const double _t633 = _hc3[3]*_t601;
  const double _t634 = -_t190*_t435 - _t599*_t632 - _t633*gbb;
  const double _t635 = _hc3[1]*_hc4[2];
  const double _t636 = _t193*_t635;
  const double _t637 = -_hc3[7]*_t610 - _hc3[8]*_t241 - _t185;
  const double _t638 = -_hc3[7]*_t241 - _t187 - _t495*_t613;
  const double _t639 = -_t189 + _t191 + _t257*_t608 - _t60*_t637 + _t606*_t632 - _t615*_t638;
  const double _t640 = my_piecewise3(_t25, 0, _t126*_t623 - _t184*_t631 + _t194*_t639 - _t240*_t534*_t618 + _t283*_t621 - _t476*_t544*_t622 + _t479*_t634 + _t536*_t620 - _t536*_t627 - _t569*_t573 + _t571 - 0.2e1*_t585 + _t595*_t624*_t625 + _t629*_t630 + _t630*_t636);
  const double _t641 = _t617 + _t640;
  const double _t642 = _t197*_t274;
  const double _t643 = _t277*_t508;
  const double _t654 = -_hc6[6]*_t648 - _hc6[7]*_t653 - _t518;
  const double _t655 = _t654*_t78;
  const double _t656 = _t277*_t44;
  const double _t657 = _t209*_t211;
  const double _t658 = my_piecewise3(_t19, 0, _t212*_t274 + _t511*_t657 + _t512*_t656 - _t642 - _t643 + _t655*nb);
  const double _t661 = _t267*_t660;
  const double _t663 = _hc0[3]*_t21;
  const double _t664 = _t216*_t663;
  const double _t667 = _t271*_t666;
  const double _t668 = _hc1[2]*_t270;
  const double _t669 = _t547*_t668;
  const double _t670 = -_hc0[7]*_t653 - _t397*_t647 - _t560;
  const double _t671 = _t221*_t225;
  const double _t672 = _t265*_t671;
  const double _t673 = _t269*_t270;
  const double _t674 = _hc1[3]*_hc2[0];
  const double _t675 = _t53*_t674;
  const double _t676 = _t21*_t224;
  const double _t677 = _t223*_t676;
  const double _t678 = _t142*_t74;
  const double _t679 = (0.1e1 / 0.18e2)*_t678;
  const double _t680 = my_piecewise3(_t23, 0, _t146*_t670 + _t264*_t672 + _t266*_t659 + _t271*_t665 - _t661 - _t662*_t664 - _t662*_t669 - _t667 + _t673*_t675 + _t677*_t679);
  const double _t681 = _t658 + _t680;
  const double _t683 = _t282*_t682;
  const double _t684 = _t204*_t286;
  const double _t685 = _t682*_t684;
  const double _t686 = my_piecewise3(_t25, 0, -_t683 - _t685);
  const double _t687 = _t233*_t289;
  const double _t688 = _t293*_t589;
  const double _t689 = my_piecewise3(_t22, 0, (0.1e1 / 0.216e3)*_hc8[3]*_hc9[1]*_t2*_t203*_t21*_t287 + (0.1e1 / 0.216e3)*_hc9[2]*_t2*_t203*_t21*_t287*_t291 - _t687 - _t688);
  const double _t690 = _t686 + _t689;
  const double _t691 = my_piecewise3(_t23, 0, -_t661 - _t667);
  const double _t692 = my_piecewise3(_t19, 0, (0.1e1 / 0.216e3)*_hc6[3]*_hc7[1]*_t2*_t203*_t21*_t272 + (0.1e1 / 0.216e3)*_hc7[2]*_t2*_t203*_t21*_t272*_t275 - _t642 - _t643);
  const double _t693 = _t691 + _t692;
  const double _t699 = -_hc8[6]*_t696 - _hc8[7]*_t698 - _t602;
  const double _t700 = _t699*_t86;
  const double _t701 = _t293*_t64;
  const double _t702 = _t246*_t290;
  const double _t703 = my_piecewise3(_t22, 0, _t250*_t289 + _t596*_t702 + _t597*_t701 - _t687 - _t688 + _t700*na);
  const double _t706 = _hc3[3]*_hc4[1];
  const double _t707 = _t476*_t706;
  const double _t708 = -_hc3[7]*_t698 - _t495*_t695 - _t633;
  const double _t709 = _t256*_t259;
  const double _t710 = _hc5[0]*_t709;
  const double _t711 = _hc4[3]*_t284;
  const double _t712 = _t70*_t711;
  const double _t713 = _hc5[0]*_t283;
  const double _t714 = _t258*_t624;
  const double _t715 = _t190*_t82;
  const double _t716 = _hc4[2]*_t715;
  const double _t717 = (0.1e1 / 0.18e2)*_t716;
  const double _t718 = my_piecewise3(_t25, 0, _t194*_t708 + _t280*_t710 + _t282*_t704 - _t285*_t476*_t705 - _t683 + _t684*_t704 - _t685 - _t705*_t707 + _t712*_t713 + _t714*_t717);
  const double _t719 = _t703 + _t718;
  const double _t724 = _hc0[6]*_t75;
  const double _t725 = _t562*_t663;
  const double _t728 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t729 = _hc1[3]*_t728;
  const double _t730 = _hc2[0]*_t729;
  const double _t733 = _hc6[6]*_t732;
  const double _t735 = _hc6[1]*_hc6[3]*_t734;
  const double _t736 = ((_hc6[1]) * (_hc6[1]) * (_hc6[1]));
  const double _t737 = _t732*_t736;
  const double _t738 = my_piecewise3(_t19, 0, _t211*_t735 + _t512*_t737 + _t733*_t79) + my_piecewise3(_t23, 0, _t723*_t724 + _t723*_t730 + _t725*_t727);
  const double _t741 = _hc3[6]*_t281;
  const double _t742 = _hc3[3]*_t635;
  const double _t743 = _t624*_t742;
  const double _t745 = ((_hc3[1]) * (_hc3[1]) * (_hc3[1]));
  const double _t746 = _hc4[3]*_t745;
  const double _t747 = _hc5[0]*_t740;
  const double _t750 = _hc8[6]*_t749;
  const double _t752 = _hc8[1]*_hc8[3]*_t751;
  const double _t753 = ((_hc8[1]) * (_hc8[1]) * (_hc8[1]));
  const double _t754 = _t749*_t753;
  const double _t755 = my_piecewise3(_t22, 0, _t290*_t752 + _t597*_t754 + _t750*_t87) + my_piecewise3(_t25, 0, _t740*_t741 + _t743*_t744 + _t746*_t747);
  const double d3F_dna3 = 0.3e1*_t116 + 0.3e1*_t147 + _t20*_t404 + 0.3e1*_t93 + 0.3e1*_t95;
  const double d3F_dna2_dnb = _t148 + _t20*(_t406 + _t409 + _t410 + _t412) + _t413;
  const double d3F_dna_dnb2 = _t196 + _t20*(_t414 + _t415 + _t421 + _t424) + _t413;
  const double d3F_dnb3 = 0.3e1*_t159 + 0.3e1*_t160 + 0.3e1*_t176 + 0.3e1*_t195 + _t20*_t502;
  const double d3F_dna2_dgaa = _t20*_t568 + 0.2e1*_t213 + 0.2e1*_t228;
  const double d3F_dna2_dgbb = _t20*_t578 + 0.2e1*_t232 + 0.2e1*_t235;
  const double d3F_dna_dnb_dgaa = _t20*(_t579 + _t583) + _t229 + _t239;
  const double d3F_dna_dnb_dgbb = _t20*(_t586 + _t591) + _t236 + _t263;
  const double d3F_dnb2_dgaa = _t20*_t594 + 0.2e1*_t237 + 0.2e1*_t238;
  const double d3F_dnb2_dgbb = _t20*_t641 + 0.2e1*_t251 + 0.2e1*_t262;
  const double d3F_dna_dgaa2 = _t20*_t681 + _t278;
  const double d3F_dna_dgbb2 = _t20*_t690 + _t294;
  const double d3F_dnb_dgaa2 = _t20*_t693 + _t278;
  const double d3F_dnb_dgbb2 = _t20*_t719 + _t294;
  const double d3F_dgaa3 = _t20*_t738;
  const double d3F_dgbb3 = _t20*_t755;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 2] += d3F_dna2_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 3] += d3F_dna_dnb_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 5] += d3F_dna_dnb_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 6] += d3F_dnb2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 5] += d3F_dna_dgbb2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 6] += d3F_dnb_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
#endif
#if _KMAX >= 4
  const double _t756 = xc_powi(_t20, -5);
  const double _t757 = 0.24e2*_t756;
  const double _t758 = _t757*nb;
  const double _t760 = _t757*na;
  const double _t765 = 0.12e2*_t90;
  const double _t773 = _t10*gaa;
  const double _t774 = _t40*_t773;
  const double _t776 = (0.2e1 / 0.3e1)*_t104;
  const double _t777 = (0.22e2 / 0.27e2)*_t110;
  const double _t779 = (0.2e1 / 0.9e1)*_t40;
  const double _t782 = (0.28e2 / 0.27e2)*_t326;
  const double _t783 = _t328*gaa;
  const double _t784 = (0.616e3 / 0.243e3)*_t783;
  const double _t785 = _t10*_t318;
  const double _t786 = _t785*gaa;
  const double _t787 = (0.140e3 / 0.81e2)*_t265;
  const double _t788 = (0.5236e4 / 0.729e3)*_t649;
  const double _t789 = (0.14e2 / 0.9e1)*_t326;
  const double _t790 = (0.308e3 / 0.81e2)*_t783;
  const double _t791 = _t4*_t776;
  const double _t792 = _t773*_t777;
  const double _t793 = _t327*_t4;
  const double _t794 = _t329*_t773;
  const double _t795 = _t331*gaa;
  const double _t800 = (0.1e1 / 0.9e1)*_t200;
  const double _t801 = _t21*_t800;
  const double _t802 = (0.28e2 / 0.81e2)*_t133;
  const double _t805 = _t295*_t4;
  const double _t807 = (0.4e1 / 0.81e2)*_t10;
  const double _t808 = (0.1e1 / 0.9e1)*_t28;
  const double _t809 = _t10*_t808;
  const double _t810 = _t10*_t90;
  const double _t812 = _t295*na;
  const double _t814 = 0.12e2*_t28;
  const double _t815 = 0.4e1*_t21;
  const double _t817 = _t765*na;
  const double _t819 = _t215*_t801;
  const double _t820 = 0.4e1*_t90;
  const double _t822 = _t10*_t119;
  const double _t823 = (0.1e1 / 0.3e1)*_t10*_t28;
  const double _t824 = (0.2e1 / 0.3e1)*_t21*_t38;
  const double _t825 = _t4*_t407;
  const double _t826 = _t1*_t825;
  const double _t827 = (0.2e1 / 0.3e1)*_t133;
  const double _t828 = _t1*_t827;
  const double _t830 = _t10*_t51;
  const double _t852 = 0.3e1*_t28;
  const double _t853 = 0.2e1*_t90;
  const double _t855 = _t853*na;
  const double _t856 = (0.2e1 / 0.3e1)*_t357;
  const double _t862 = 0.8e1*_t90;
  const double _t880 = _t10*gbb;
  const double _t881 = _t61*_t880;
  const double _t883 = (0.2e1 / 0.3e1)*_t165;
  const double _t884 = (0.22e2 / 0.27e2)*_t170;
  const double _t886 = (0.2e1 / 0.9e1)*_t61;
  const double _t888 = (0.28e2 / 0.27e2)*_t443;
  const double _t889 = _t445*gbb;
  const double _t890 = (0.616e3 / 0.243e3)*_t889;
  const double _t891 = _t10*_t435;
  const double _t892 = _t891*gbb;
  const double _t893 = (0.140e3 / 0.81e2)*_t279;
  const double _t894 = (0.5236e4 / 0.729e3)*_t697;
  const double _t895 = (0.14e2 / 0.9e1)*_t443;
  const double _t896 = (0.308e3 / 0.81e2)*_t889;
  const double _t897 = _t4*_t883;
  const double _t898 = _t880*_t884;
  const double _t899 = _t4*_t444;
  const double _t900 = _t446*_t880;
  const double _t901 = _t448*gbb;
  const double _t906 = _t295*nb;
  const double _t910 = _t252*_t801;
  const double _t912 = _t14*_t825;
  const double _t928 = (0.1e1 / 0.6e1)*_t90;
  const double _t934 = (0.1e1 / 0.12e2)*_t199;
  const double _t935 = (0.1e1 / 0.27e2)*_t206;
  const double _t939 = (0.2e1 / 0.27e2)*_t521;
  const double _t940 = (0.22e2 / 0.243e3)*_t523;
  const double _t943 = (0.7e1 / 0.81e2)/xc_powi(na, 6);
  const double _t944 = xc_powr(na, -25, 3);
  const double _t945 = (0.154e3 / 0.729e3)*_t944;
  const double _t946 = _t200*_t522;
  const double _t947 = _t204*_t525;
  const double _t949 = _t204*_t524;
  const double _t950 = (0.2e1 / 0.81e2)*_t21;
  const double _t951 = (0.1e1 / 0.72e2)*_t28;
  const double _t953 = (0.1e1 / 0.6e1)*_t295;
  const double _t957 = (0.1e1 / 0.6e1)*_t28;
  const double _t958 = (0.1e1 / 0.12e2)*_t200;
  const double _t960 = (0.1e1 / 0.72e2)*_t21;
  const double _t961 = _t268*_t960;
  const double _t981 = _t800*_t90;
  const double _t982 = _t219*_t74;
  const double _t1000 = (0.1e1 / 0.12e2)*_t16;
  const double _t1002 = (0.1e1 / 0.12e2)*_t240;
  const double _t1003 = (0.1e1 / 0.27e2)*_t243;
  const double _t1006 = (0.2e1 / 0.27e2)*_t605;
  const double _t1007 = (0.22e2 / 0.243e3)*_t607;
  const double _t1010 = (0.7e1 / 0.81e2)/xc_powi(nb, 6);
  const double _t1011 = xc_powr(nb, -25, 3);
  const double _t1012 = (0.154e3 / 0.729e3)*_t1011;
  const double _t1013 = _t200*_t606;
  const double _t1014 = _t204*_t609;
  const double _t1016 = _t204*_t608;
  const double _t1018 = _t204*_t279;
  const double _t1031 = (0.11e2 / 0.1458e4)/xc_powi(na, 10);
  const double _t1033 = (0.1e1 / 0.972e3)/xc_powr(na, 23, 3);
  const double _t1036 = (0.1e1 / 0.243e3)*_t644;
  const double _t1037 = (0.4e1 / 0.81e2)*_t206;
  const double _t1038 = (0.1e1 / 0.648e3)*_t649;
  const double _t1039 = (0.1e1 / 0.108e3)*_t272;
  const double _t1042 = _t90*nb;
  const double _t1049 = _t1039*_t28;
  const double _t1051 = (0.1e1 / 0.1944e4)*_t651;
  const double _t1052 = _t1051*_t649;
  const double _t1054 = (0.1e1 / 0.648e3)*_t651;
  const double _t1055 = _t1054*_t328;
  const double _t1057 = (0.1e1 / 0.108e3)*_t28;
  const double _t1060 = _t1039*_t21;
  const double _t1063 = (0.1e1 / 0.108e3)*_t90;
  const double _t1065 = _t1063*_t279;
  const double _t1067 = (0.1e1 / 0.108e3)*_t287;
  const double _t1071 = _t90*na;
  const double _t1073 = _t273*_t28;
  const double _t1076 = _t28*_t288;
  const double _t1084 = (0.11e2 / 0.1458e4)/xc_powi(nb, 10);
  const double _t1086 = (0.1e1 / 0.972e3)/xc_powr(nb, 23, 3);
  const double _t1088 = (0.1e1 / 0.243e3)*_t694;
  const double _t1089 = (0.4e1 / 0.81e2)*_t243;
  const double _t1090 = (0.1e1 / 0.648e3)*_t697;
  const double _t1094 = _t1067*_t28;
  const double _t1095 = _t1051*_t697;
  const double _t1097 = _t1054*_t445;
  const double _t1106 = (0.1e1 / 0.162e3)*_t645;
  const double _t1107 = _t1106*_t644;
  const double _t1108 = _t2/(M_PI * M_PI * M_CBRTPI);
  const double _t1109 = (0.1e1 / 0.7776e4)*_t1108;
  const double _t1110 = _t1109/xc_powr(na, 28, 3);
  const double _t1111 = _t8/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t1112 = (0.1e1 / 0.17496e5)*_t1111;
  const double _t1113 = _t1112*gaa/xc_powr(na, 35, 3);
  const double _t1114 = (0.1e1 / 0.72e2)*_t272;
  const double _t1115 = _t21*_t732;
  const double _t1116 = _t28*_t721;
  const double _t1117 = _t1116*_t720;
  const double _t1121 = _t1109*_t944;
  const double _t1123 = (0.1e1 / 0.2592e4)*_t1108;
  const double _t1125 = _t1116*_t739;
  const double _t1133 = _t1106*_t694;
  const double _t1134 = _t1109/xc_powr(nb, 28, 3);
  const double _t1135 = _t1112*gbb/xc_powr(nb, 35, 3);
  const double _t1136 = (0.1e1 / 0.72e2)*_t287;
  const double _t1137 = _t21*_t749;
  const double _t1141 = xc_powr(na, -29, 3);
  const double _t1142 = (0.1e1 / 0.46656e5)*_t1111;
  const double _t1143 = _t1142*_t21;
  const double _t1144 = _t1141*_t1143;
  const double _t1145 = _t1111*_t1141;
  const double _t1146 = (0.1e1 / 0.15552e5)*_t1111;
  const double _t1147 = xc_powr(na, -32, 3);
  const double _t1148 = _t1142*_t1147;
  const double _t1150 = (0.1e1 / 0.11664e5)*_t1111;
  const double _t1151 = (0.1e1 / 0.7776e4)*_t1111;
  const double _t1152 = xc_powr(nb, -29, 3);
  const double _t1154 = xc_powr(nb, -32, 3);
  const double _t1155 = _t1142*_t1154;
  const double _t759 = _t26*_t758;
  const double _t761 = _hc9[0]*_t760;
  const double _t762 = _hc7[0]*_t758;
  const double _t763 = _t295*_t98*nb;
  const double _t764 = _hc7[4]*_t179;
  const double _t766 = _t101*nb;
  const double _t767 = _t311*_t97;
  const double _t768 = _hc7[1]*_t115;
  const double _t769 = _t768*nb;
  const double _t770 = _t115*_t509;
  const double _t771 = _t325*_t508;
  const double _t772 = _hc6[5]*_t38;
  const double _t775 = _hc6[4]*_t774;
  const double _t778 = _t112*gaa;
  const double _t780 = _t211*_t324;
  const double _t781 = _t197*_t345;
  const double _t796 = -_hc6[12]*_t531 - _hc6[13]*_t39;
  const double _t797 = -_hc6[11]*_t531 - _hc6[12]*_t39;
  const double _t798 = _hc6[7]*_t795 + _hc6[8]*_t106 - _t39*_t796 - _t531*_t797;
  const double _t799 = _t24*_t760;
  const double _t803 = _t354*_t356;
  const double _t804 = _t120*_t90;
  const double _t806 = _t49*_t805;
  const double _t811 = _t123*_t810;
  const double _t813 = _t125*_t812;
  const double _t816 = _hc2[0]*_t367;
  const double _t818 = _t127*_t816;
  const double _t821 = _t136*_t4;
  const double _t829 = _hc2[1]*_t828;
  const double _t831 = _t538*_t74;
  const double _t832 = _t225*_t815;
  const double _t833 = _t127*_t225;
  const double _t834 = _t145*_t833;
  const double _t835 = _t387*_t833;
  const double _t836 = _hc0[5]*_t38;
  const double _t837 = _hc0[4]*_t774;
  const double _t838 = _t130*_t554;
  const double _t839 = _t142*gaa;
  const double _t840 = _hc1[2]*_t53;
  const double _t841 = _t829*_t840;
  const double _t842 = _t380*_t387;
  const double _t843 = _t402*_t75;
  const double _t844 = _t127*_t843;
  const double _t845 = -_hc0[12]*_t531 - _hc0[13]*_t39;
  const double _t846 = -_hc0[11]*_t531 - _hc0[12]*_t39;
  const double _t847 = _hc0[7]*_t795 + _hc0[8]*_t106 - _t39*_t845 - _t531*_t846;
  const double _t848 = _t67*_t805;
  const double _t849 = _t295*_t468;
  const double _t850 = _t156*_t295*na;
  const double _t851 = _t427 + _t761;
  const double _t854 = _t309 + _t762;
  const double _t857 = _t177*_t90;
  const double _t858 = _t416*_t810;
  const double _t859 = _hc5[0]*nb;
  const double _t860 = _t853*_t859;
  const double _t861 = _t14*_t183;
  const double _t863 = _hc9[1]*_t175;
  const double _t864 = _t369*_t466;
  const double _t865 = _hc5[0]*_t852;
  const double _t866 = _t417*_t471;
  const double _t867 = _t4*_t861;
  const double _t868 = _t259*_t417;
  const double _t869 = _t193*_t868;
  const double _t870 = _t485*_t868;
  const double _t871 = _hc4[1]*_t500;
  const double _t872 = _t417*_t871;
  const double _t873 = _t233*_t462;
  const double _t874 = _t127*_t429;
  const double _t875 = _t441*_t64;
  const double _t876 = _t589*_t875;
  const double _t877 = _t175*_t590;
  const double _t878 = _hc9[4]*_t129;
  const double _t879 = _hc8[5]*_t59;
  const double _t882 = _hc8[4]*_t881;
  const double _t885 = _t172*gbb;
  const double _t887 = _t290*_t441;
  const double _t902 = -_hc8[12]*_t615 - _hc8[13]*_t60;
  const double _t903 = -_hc8[11]*_t615 - _hc8[12]*_t60;
  const double _t904 = _hc8[7]*_t901 + _hc8[8]*_t166 - _t60*_t902 - _t615*_t903;
  const double _t905 = 0.24e2*_t152;
  const double _t907 = _hc5[0]*_t814;
  const double _t908 = _hc5[0]*_t815;
  const double _t909 = _t765*_t859;
  const double _t911 = (0.2e1 / 0.3e1)*_t476*_t59;
  const double _t913 = _hc5[1]*_t14*_t827;
  const double _t914 = _hc5[2]*_t82;
  const double _t915 = _t830*_t914;
  const double _t916 = _t259*_t908;
  const double _t917 = _hc3[5]*_t59;
  const double _t918 = _hc3[4]*_t881;
  const double _t919 = _t180*_t628;
  const double _t920 = _t190*gbb;
  const double _t921 = _t259*_t913;
  const double _t922 = _t478*_t485;
  const double _t923 = -_hc3[12]*_t615 - _hc3[13]*_t60;
  const double _t924 = -_hc3[11]*_t615 - _hc3[12]*_t60;
  const double _t925 = _hc3[7]*_t901 + _hc3[8]*_t166 - _t60*_t923 - _t615*_t924;
  const double _t926 = (0.1e1 / 0.6e1)*_t505*_t906;
  const double _t927 = _hc7[1]*_t209;
  const double _t929 = _t112*_t44;
  const double _t930 = _hc7[2]*_t929;
  const double _t931 = _hc7[3]*_t97;
  const double _t932 = (0.1e1 / 0.12e2)*_t112*_t7;
  const double _t933 = _t509*_t519;
  const double _t936 = _t205*gaa;
  const double _t937 = _t44*_t512;
  const double _t938 = _t197*_t532;
  const double _t941 = _t205*_t940;
  const double _t942 = _t530*_t785;
  const double _t948 = -_hc6[11]*_t526 - _hc6[12]*_t202 - _t335;
  const double _t952 = _t541*_t7;
  const double _t954 = _t542*_t953;
  const double _t955 = -_t954;
  const double _t956 = _t200*_t546;
  const double _t959 = _t548*_t958;
  const double _t962 = _hc2[0]*_t554;
  const double _t963 = _t142*_t7;
  const double _t964 = (0.1e1 / 0.12e2)*_t678;
  const double _t965 = _hc1[4]*_hc2[0];
  const double _t966 = _t561*_t833;
  const double _t967 = _hc0[1]*_hc1[2];
  const double _t968 = (0.1e1 / 0.12e2)*_t145;
  const double _t969 = _t224*_t678;
  const double _t970 = _t223*_t380;
  const double _t971 = _t145*_t674;
  const double _t972 = _t545*_t674;
  const double _t973 = _t566*_t75;
  const double _t974 = _t127*_t973;
  const double _t975 = _t221*_t940;
  const double _t976 = _t565*_t785;
  const double _t977 = -_hc0[11]*_t526 - _hc0[12]*_t202 - _t392;
  const double _t978 = _t570*_t953;
  const double _t979 = -_t978;
  const double _t980 = (0.1e1 / 0.6e1)*_t575*_t812;
  const double _t983 = _t407*_t927 + _t540*_t930 + _t926;
  const double _t984 = 0.2e1*_t579 + 0.2e1*_t583;
  const double _t985 = _t16*_t569;
  const double _t986 = _t623*nb;
  const double _t987 = _hc9[1]*_t246;
  const double _t988 = _t172*_t64;
  const double _t989 = _hc9[2]*_t988;
  const double _t990 = _t407*_t987 + _t573*_t989 + _t980;
  const double _t991 = 0.2e1*_t586 + 0.2e1*_t591;
  const double _t992 = _t204*_t621;
  const double _t993 = _hc5[0]*_t230;
  const double _t994 = _t634*_t868;
  const double _t995 = _hc4[1]*_t639;
  const double _t996 = _t417*_t995;
  const double _t997 = _t233*_t616;
  const double _t998 = _t590*_t603;
  const double _t999 = _hc9[3]*_t127;
  const double _t1001 = _t1000*_t172;
  const double _t1004 = _t242*gbb;
  const double _t1005 = _t597*_t64;
  const double _t1008 = _t1007*_t242;
  const double _t1009 = _t614*_t891;
  const double _t1015 = -_hc8[11]*_t610 - _hc8[12]*_t241 - _t452;
  const double _t1017 = _t252*_t476*_t958;
  const double _t1019 = _t1000*_t190*_t624;
  const double _t1020 = _hc5[0]*_t28;
  const double _t1021 = (0.1e1 / 0.12e2)*_t1020;
  const double _t1022 = _hc3[1]*_t630;
  const double _t1023 = _t259*_t634;
  const double _t1024 = _hc4[2]*_t193;
  const double _t1025 = _t258*_t478;
  const double _t1026 = _hc4[3]*_t70;
  const double _t1027 = _t1022*_t1026;
  const double _t1028 = _t1007*_t256;
  const double _t1029 = _t638*_t891;
  const double _t1030 = -_hc3[11]*_t610 - _hc3[12]*_t241 - _t490;
  const double _t1032 = _t528*_t645;
  const double _t1034 = _hc6[7]*_t651;
  const double _t1035 = _t197*_t654;
  const double _t1040 = _t1039*_t205;
  const double _t1041 = _t1039*_t276;
  const double _t1043 = _hc7[1]*_t1040*_t1042 + _hc7[2]*_t1041*_t1042;
  const double _t1044 = _t670*_t75;
  const double _t1045 = _t397*_t645;
  const double _t1046 = _hc0[7]*_t651;
  const double _t1047 = _t1044*_t127;
  const double _t1048 = _hc2[2]*_t723;
  const double _t1050 = _t204*_t271;
  const double _t1053 = _hc0[3]*_t28;
  const double _t1056 = _t223*_t969;
  const double _t1058 = _t270*_t675;
  const double _t1059 = _t1055*_t547;
  const double _t1061 = _t221*_t265;
  const double _t1062 = _t1061*_t264;
  const double _t1064 = _t1063*_t267 + _t1063*_t268*_t271;
  const double _t1066 = _t1065*_t282 + _t1065*_t684;
  const double _t1068 = _t1067*_t242;
  const double _t1069 = _hc9[2]*_t28;
  const double _t1070 = _t1067*_t292;
  const double _t1072 = _hc9[1]*_t1068*_t1071 + _hc9[2]*_t1070*_t1071;
  const double _t1074 = _hc7[2]*_t28;
  const double _t1075 = _t209*_t511;
  const double _t1077 = _hc4[1]*_t708;
  const double _t1078 = _t1077*_t417;
  const double _t1079 = _t204*_t712;
  const double _t1080 = _hc5[0]*_t258;
  const double _t1081 = _t1080*_t716;
  const double _t1082 = _t233*_t699;
  const double _t1083 = _t246*_t596;
  const double _t1085 = _t612*_t645;
  const double _t1087 = _hc8[7]*_t651;
  const double _t1091 = _t495*_t645;
  const double _t1092 = _hc3[7]*_t651;
  const double _t1093 = _hc5[2]*_t740;
  const double _t1096 = _hc5[1]*_t28;
  const double _t1098 = (0.1e1 / 0.108e3)*_t1020;
  const double _t1099 = _t1097*_t476;
  const double _t1100 = _t1067*_t624;
  const double _t1101 = _hc5[0]*_t256*_t280;
  const double _t1102 = _t1026*_t624;
  const double _t1103 = _t197*_t733;
  const double _t1104 = _t508*_t735;
  const double _t1105 = _t737*_t931;
  const double _t1118 = _t1117*_t724;
  const double _t1119 = _t1053*_t562*_t727;
  const double _t1120 = _t1117*_t730;
  const double _t1122 = _hc0[6]*_t21;
  const double _t1124 = _t270*_t674;
  const double _t1126 = _t1125*_t741;
  const double _t1127 = _t1020*_t742*_t744;
  const double _t1128 = _hc5[0]*_t746;
  const double _t1129 = _t1125*_t1128;
  const double _t1130 = _t233*_t750;
  const double _t1131 = _t589*_t752;
  const double _t1132 = _t754*_t999;
  const double _t1138 = _t1011*_t476;
  const double _t1139 = _t1109*_t1138;
  const double _t1140 = (0.1e1 / 0.72e2)*_t714;
  const double _t1149 = _t1147*_t211;
  const double _t1153 = _t1152*_t624;
  const double _t1156 = _t1154*_t290;
  const double d4F_dna4 = _t20*(my_piecewise3(_t19, 0, (_t115 * _t115)*_t211 + _t115*_t780 + 0.2e1*_t212*_t345 + _t212*((0.8e1 / 0.9e1)*_t103*_t104*_t2*_t3 + (0.88e2 / 0.81e2)*_t108*_t110*_t8*_t9*gaa - _t112*_t784 - _t315*_t338 - _t317*_t782 - _t343*_t786) + (_t44 * _t44 * _t44 * _t44)*_t764 + _t513*(_t114 + _t38*((0.1e1 / 0.36e2)*_t772 + (0.1e1 / 0.81e2)*_t775)) + _t513*(_t323 + _t38*((0.1e1 / 0.18e2)*_t772 + (0.2e1 / 0.81e2)*_t775)) + _t513*(_t317*_t776 - _t319*_t779*gaa + _t38*((0.1e1 / 0.12e2)*_t772 + (0.1e1 / 0.27e2)*_t775) + _t777*_t778) + _t762 - 0.24e2*_t763 + _t765*_t766 + _t765*_t769 - 0.4e1*_t767 - 0.4e1*_t770 - 0.4e1*_t771 - 0.4e1*_t781 + _t79*(-_t103*_t4*_t789 + _t317*_t787 - _t319*_t790 + _t338*_t791 + _t343*_t792 - _t39*(-_hc6[4]*_t794 - _hc6[5]*_t793 + (0.4e1 / 0.9e1)*_t104*_t2*_t3*_t334 + (0.44e2 / 0.81e2)*_t110*_t336*_t8*_t9*gaa - _t39*(_hc6[8]*_t795 + _hc6[9]*_t106 - _t39*(-_hc6[13]*_t531 - _hc6[14]*_t39) - _t531*_t796) - _t531*_t798) - _t531*(-_hc6[3]*_t794 - _hc6[4]*_t793 + (0.4e1 / 0.9e1)*_t104*_t2*_t3*_t336 + (0.44e2 / 0.81e2)*_t110*_t341*_t8*_t9*gaa - _t39*_t798 - _t531*(_hc6[7]*_t106 + _t331*_t528 - _t39*_t797 - _t531*(-_hc6[10]*_t531 - _hc6[11]*_t39))) + _t778*_t788)) + my_piecewise3(_t22, 0, -0.24e2*_t301 + _t761) + my_piecewise3(_t23, 0, _hc1[0]*_hc2[4]*_t269 + _hc1[4]*_t130*(_t53 * _t53 * _t53 * _t53) + _hc2[2]*_t132*_t74*_t830 - _hc2[3]*_t124*_t819 + _t122*_t7*_t809 + 0.24e2*_t125*_t90 + (0.4e1 / 0.3e1)*_t135*_t28*_t38 + (_t145 * _t145)*_t380 + _t145*_t830*_t831 + _t145*_t832 - _t145*_t841 + _t145*_t842 + _t146*(-_t138*_t4*_t789 + _t382*_t787 - _t383*_t790 - _t39*(-_hc0[4]*_t794 - _hc0[5]*_t793 + (0.4e1 / 0.9e1)*_t104*_t2*_t3*_t391 + (0.44e2 / 0.81e2)*_t110*_t393*_t8*_t9*gaa - _t39*(_hc0[8]*_t795 + _hc0[9]*_t106 - _t39*(-_hc0[13]*_t531 - _hc0[14]*_t39) - _t531*_t845) - _t531*_t847) + _t395*_t791 + _t400*_t792 - _t531*(-_hc0[3]*_t794 - _hc0[4]*_t793 + (0.4e1 / 0.9e1)*_t104*_t2*_t3*_t393 + (0.44e2 / 0.81e2)*_t110*_t398*_t8*_t9*gaa - _t39*_t847 - _t531*(_hc0[7]*_t106 + _t331*_t397 - _t39*_t846 - _t531*(-_hc0[10]*_t531 - _hc0[11]*_t39))) + _t788*_t839) + _t199*_t352*_t801 - _t216*_t402*_t828 + _t28*_t353*_t800 - _t326*_t48*_t802 - 0.24e2*_t348 + (0.16e2 / 0.27e2)*_t354*_t371 + _t359*_t40*_t807 - _t365*_t814 + _t365*_t817 - _t367*_t829 - _t373*_t7*_t822 - _t374*_t823 - _t376*_t824 + _t376*_t826 - _t377*_t814 + _t377*_t817 - _t379*_t824 + _t379*_t826 + 0.2e1*_t381*_t402 + _t381*((0.8e1 / 0.9e1)*_t104*_t138*_t2*_t3 + (0.88e2 / 0.81e2)*_t110*_t140*_t8*_t9*gaa - _t142*_t784 - _t315*_t395 - _t382*_t782 - _t400*_t786) + _t387*_t832 - _t387*_t841 + _t799 - 0.16e2 / 0.27e2*_t803 - 0.4e1 / 0.3e1*_t804 + 0.4e1*_t806 + (0.1e1 / 0.3e1)*_t811 - 0.24e2*_t813 + _t815*_t816 + _t815*_t843 - 0.4e1*_t818 - _t820*_t821 - 0.4e1*_t834 - 0.4e1*_t835 + _t838*(_t144 + _t38*((0.1e1 / 0.36e2)*_t836 + (0.1e1 / 0.81e2)*_t837)) + _t838*(_t38*((0.1e1 / 0.18e2)*_t836 + (0.2e1 / 0.81e2)*_t837) + _t386) + _t838*(_t38*((0.1e1 / 0.12e2)*_t836 + (0.1e1 / 0.27e2)*_t837) + _t382*_t776 - _t383*_t779*gaa + _t777*_t839) - 0.4e1*_t844) + my_piecewise3(_t25, 0, _t759)) + 0.4e1*_t300 + 0.4e1*_t304 + 0.4e1*_t347 + 0.4e1*_t403;
  const double d4F_dna3_dnb = _t20*(my_piecewise3(_t19, 0, -_t101*_t852 + _t115*_t582 - _t306 + _t308*_t766 + _t308*_t769 + _t312 + _t325*_t581 + _t346 - 0.18e2*_t763 - _t767 - _t768*_t852 - _t770 - _t771 - _t781 + _t854) + my_piecewise3(_t22, 0, -0.18e2*_t301 - 0.6e1*_t850 + _t851) + my_piecewise3(_t23, 0, 0.24e2*_hc1[0]*_hc2[0]*_t756*na + 0.3e1*_hc1[0]*_hc2[1]*_t1*_t2*_t295*_t3 + (0.1e1 / 0.36e2)*_hc1[0]*_hc2[2]*_t28*_t7*_t8*_t9 + (0.1e1 / 0.6e1)*_hc1[0]*_hc2[2]*_t74*_t8*_t9*_t90 + (0.1e1 / 0.36e2)*_hc1[0]*_hc2[3]*_t200*_t215*_t28 + 0.6e1*_hc1[1]*_hc2[0]*_t145*_t90*na + 0.12e2*_hc1[1]*_hc2[0]*_t53*_t90 + (0.1e1 / 0.2e1)*_hc1[1]*_hc2[1]*_t1*_t145*_t2*_t28*_t3 + (0.1e1 / 0.3e1)*_hc1[1]*_hc2[1]*_t2*_t28*_t3*_t37*_t53 + 0.6e1*_hc1[2]*_hc2[0]*_t131*_t90*na + (0.1e1 / 0.2e1)*_hc1[2]*_hc2[1]*_t1*_t131*_t2*_t28*_t3 - 0.18e2*_t348 - _t365*_t852 - _t374*_t467 - _t377*_t852 - 0.4e1 / 0.27e2*_t803 - 0.2e1 / 0.3e1*_t804 - 0.18e2*_t813 - _t818 - _t821*_t853 - _t834 - _t835 - _t844) + my_piecewise3(_t25, 0, -_t297 + _t759 + _t848 - 0.6e1*_t849)) + _t404 + 0.3e1*_t406 + 0.3e1*_t409 + 0.3e1*_t410 + 0.3e1*_t412;
  const double d4F_dna2_dnb2 = _t20*(my_piecewise3(_t19, 0, -_t101*_t407 - 0.12e2*_t305 - _t407*_t768 + _t762 - 0.12e2*_t763 + _t766*_t853 + _t769*_t853 + _t862*_t98) + my_piecewise3(_t22, 0, _t156*_t862 - _t162*_t407 + _t162*_t855 - 0.12e2*_t301 - _t407*_t863 + _t761 - 0.12e2*_t850 + _t855*_t863) + my_piecewise3(_t23, 0, _t125*_t820 - _t136*_t856 - 0.12e2*_t348 + _t365*_t855 + _t377*_t855 + _t799 - 0.2e1 / 0.9e1*_t804 + 0.2e1*_t806 + (0.1e1 / 0.18e2)*_t811 - 0.12e2*_t813) + my_piecewise3(_t25, 0, _t152*_t820 + _t182*_t860 - 0.12e2*_t296 + _t419*_t860 + _t759 + 0.2e1*_t848 - 0.12e2*_t849 - _t856*_t861 - 0.2e1 / 0.9e1*_t857 + (0.1e1 / 0.18e2)*_t858)) + 0.2e1*_t406 + 0.2e1*_t409 + 0.2e1*_t410 + 0.2e1*_t412 + 0.2e1*_t414 + 0.2e1*_t415 + 0.2e1*_t421 + 0.2e1*_t424;
  const double d4F_dna_dnb3 = _t20*(my_piecewise3(_t19, 0, -0.18e2*_t305 - 0.6e1*_t763 + _t854) + my_piecewise3(_t22, 0, _t162*_t363 - _t162*_t852 - _t302 + _t363*_t863 + _t430 + _t431 + _t442 + _t463 - 0.18e2*_t850 + _t851 - _t852*_t863 - _t873 - _t874 - _t876 - _t877) + my_piecewise3(_t23, 0, -_t349 + _t799 + _t806 - 0.6e1*_t813) + my_piecewise3(_t25, 0, 0.24e2*_hc4[0]*_hc5[0]*_t756*nb + 0.3e1*_hc4[0]*_hc5[1]*_t14*_t2*_t295*_t3 + (0.1e1 / 0.36e2)*_hc4[0]*_hc5[2]*_t16*_t28*_t8*_t9 + (0.1e1 / 0.6e1)*_hc4[0]*_hc5[2]*_t8*_t82*_t9*_t90 + (0.1e1 / 0.36e2)*_hc4[0]*_hc5[3]*_t200*_t252*_t28 + 0.6e1*_hc4[1]*_hc5[0]*_t193*_t90*nb + 0.12e2*_hc4[1]*_hc5[0]*_t70*_t90 + (0.1e1 / 0.2e1)*_hc4[1]*_hc5[1]*_t14*_t193*_t2*_t28*_t3 + (0.1e1 / 0.3e1)*_hc4[1]*_hc5[1]*_t2*_t28*_t3*_t58*_t70 + 0.6e1*_hc4[2]*_hc5[0]*_t181*_t90*nb + (0.1e1 / 0.2e1)*_hc4[2]*_hc5[1]*_t14*_t181*_t2*_t28*_t3 - _t182*_t865 - 0.18e2*_t296 - _t419*_t865 - _t467*_t475 - 0.18e2*_t849 - _t853*_t867 - 0.2e1 / 0.3e1*_t857 - 0.4e1 / 0.27e2*_t864 - _t866 - _t869 - _t870 - _t872)) + 0.3e1*_t414 + 0.3e1*_t415 + 0.3e1*_t421 + 0.3e1*_t424 + _t502;
  const double d4F_dnb4 = _t20*(my_piecewise3(_t19, 0, -0.24e2*_t305 + _t762) + my_piecewise3(_t22, 0, _t162*_t817 + (_t175 * _t175)*_t290 + _t175*_t887 + 0.2e1*_t250*_t462 + _t250*((0.8e1 / 0.9e1)*_t164*_t165*_t2*_t3 + (0.88e2 / 0.81e2)*_t168*_t170*_t8*_t9*gbb - _t172*_t890 - _t432*_t455 - _t434*_t888 - _t460*_t892) + _t598*(_t174 + _t59*((0.1e1 / 0.36e2)*_t879 + (0.1e1 / 0.81e2)*_t882)) + _t598*(_t440 + _t59*((0.1e1 / 0.18e2)*_t879 + (0.2e1 / 0.81e2)*_t882)) + _t598*(_t434*_t883 - _t436*_t886*gbb + _t59*((0.1e1 / 0.12e2)*_t879 + (0.1e1 / 0.27e2)*_t882) + _t884*_t885) + (_t64 * _t64 * _t64 * _t64)*_t878 + _t761 + _t817*_t863 - 0.24e2*_t850 + _t87*(-_t164*_t4*_t895 + _t434*_t893 - _t436*_t896 + _t455*_t897 + _t460*_t898 - _t60*(-_hc8[4]*_t900 - _hc8[5]*_t899 + (0.4e1 / 0.9e1)*_t165*_t2*_t3*_t451 + (0.44e2 / 0.81e2)*_t170*_t453*_t8*_t9*gbb - _t60*(_hc8[8]*_t901 + _hc8[9]*_t166 - _t60*(-_hc8[13]*_t615 - _hc8[14]*_t60) - _t615*_t902) - _t615*_t904) - _t615*(-_hc8[3]*_t900 - _hc8[4]*_t899 + (0.4e1 / 0.9e1)*_t165*_t2*_t3*_t453 + (0.44e2 / 0.81e2)*_t170*_t458*_t8*_t9*gbb - _t60*_t904 - _t615*(_hc8[7]*_t166 + _t448*_t612 - _t60*_t903 - _t615*(-_hc8[10]*_t615 - _hc8[11]*_t60))) + _t885*_t894) - 0.4e1*_t873 - 0.4e1*_t874 - 0.4e1*_t876 - 0.4e1*_t877) + my_piecewise3(_t23, 0, _t799) + my_piecewise3(_t25, 0, _hc4[0]*_hc5[4]*_t283 + _hc4[4]*_t180*(_t70 * _t70 * _t70 * _t70) + _hc5[1]*_t182*_t912 + _hc5[1]*_t419*_t912 - _hc5[3]*_t151*_t910 + (0.16e2 / 0.27e2)*_t133*_t165*_t183 + _t16*_t178*_t809 - _t16*_t474*_t822 + _t178*_t21*_t61*_t807 - _t182*_t907 + _t182*_t909 - _t182*_t911 + _t182*_t915 + (0.4e1 / 0.3e1)*_t183*_t28*_t59 + (_t193 * _t193)*_t478 + _t193*_t916 - _t193*_t921 + _t193*_t922 + _t194*(-_t186*_t4*_t895 + _t480*_t893 - _t481*_t896 + _t493*_t897 + _t498*_t898 - _t60*(-_hc3[4]*_t900 - _hc3[5]*_t899 + (0.4e1 / 0.9e1)*_t165*_t2*_t3*_t489 + (0.44e2 / 0.81e2)*_t170*_t491*_t8*_t9*gbb - _t60*(_hc3[8]*_t901 + _hc3[9]*_t166 - _t60*(-_hc3[13]*_t615 - _hc3[14]*_t60) - _t615*_t923) - _t615*_t925) - _t615*(-_hc3[3]*_t900 - _hc3[4]*_t899 + (0.4e1 / 0.9e1)*_t165*_t2*_t3*_t491 + (0.44e2 / 0.81e2)*_t170*_t496*_t8*_t9*gbb - _t60*_t925 - _t615*(_hc3[7]*_t166 + _t448*_t495 - _t60*_t924 - _t615*(-_hc3[10]*_t615 - _hc3[11]*_t60))) + _t894*_t920) + _t240*_t465*_t801 + _t252*_t28*_t465*_t800 - 0.24e2*_t296 - _t419*_t907 + _t419*_t909 - _t419*_t911 + _t419*_t915 - _t443*_t66*_t802 + _t471*_t908 - _t471*_t913 - _t475*_t823 + 0.2e1*_t479*_t500 + _t479*((0.8e1 / 0.9e1)*_t165*_t186*_t2*_t3 + (0.88e2 / 0.81e2)*_t170*_t188*_t8*_t9*gbb - _t190*_t890 - _t432*_t493 - _t480*_t888 - _t498*_t892) + _t485*_t916 - _t485*_t921 + _t759 - _t820*_t867 + 0.4e1*_t848 - 0.4e1 / 0.3e1*_t857 + (0.1e1 / 0.3e1)*_t858 - 0.16e2 / 0.27e2*_t864 - 0.4e1*_t866 - 0.4e1*_t869 - 0.4e1*_t870 + _t871*_t908 - _t871*_t913 - 0.4e1*_t872 + _t90*_t905 - _t905*_t906 + _t919*(_t192 + _t59*((0.1e1 / 0.36e2)*_t917 + (0.1e1 / 0.81e2)*_t918)) + _t919*(_t484 + _t59*((0.1e1 / 0.18e2)*_t917 + (0.2e1 / 0.81e2)*_t918)) + _t919*(_t480*_t883 - _t481*_t886*gbb + _t59*((0.1e1 / 0.12e2)*_t917 + (0.1e1 / 0.27e2)*_t918) + _t884*_t920))) + 0.4e1*_t425 + 0.4e1*_t426 + 0.4e1*_t464 + 0.4e1*_t501;
  const double d4F_dna3_dgaa = _t20*(my_piecewise3(_t19, 0, -_t100*_t931*_t932 - _t115*_t508*_t932 + _t115*_t657 + _t209*_t780 + _t211*_t345*_t80 + _t212*_t532 + _t212*(-_t315*_t527 - _t320 + _t322 + _t515*_t939 + _t941*gaa - _t942*gaa) + _t308*_t927*nb + _t310*_t764*_t80 + _t325*_t512*_t80 + _t513*(-_t112*_t779 - _t515*_t934 - _t935*_t936) + _t520*_t937 + _t7*_t928*_t930*nb + _t79*((0.4e1 / 0.9e1)*_t104*_t2*_t3*_t527 + (0.44e2 / 0.81e2)*_t108*_t110*_t8*_t9 + (0.44e2 / 0.81e2)*_t110*_t530*_t8*_t9*gaa - _t330 - _t344 - _t39*(_hc6[7]*_t947 + _hc6[8]*_t946 + _t332 - _t337 - _t39*(-_hc6[12]*_t526 - _hc6[13]*_t202 - _t333) - _t531*_t948) - _t515*_t943 - _t531*(_hc6[7]*_t946 + _t339 - _t342 - _t39*_t948 + _t528*_t949 - _t531*(-_hc6[10]*_t526 - _hc6[11]*_t202 - _t340)) - _t936*_t945) - _t926 - 0.3e1*_t933 - 0.3e1*_t938) + my_piecewise3(_t23, 0, -_hc0[1]*_hc1[1]*_hc2[3]*_t21*_t662 + _hc0[1]*_t366*_t553*_t965 + _hc2[1]*_t215*_t956*_t957 - _hc2[1]*_t375*_t561*_t840 + _hc2[2]*_t546*_t961 - _t145*_t959*_t967 + _t145*_t970 + _t146*((0.4e1 / 0.9e1)*_t104*_t2*_t3*_t564 + (0.44e2 / 0.81e2)*_t110*_t140*_t8*_t9 + (0.44e2 / 0.81e2)*_t110*_t565*_t8*_t9*gaa - _t222*_t945 - _t388 - _t39*(_hc0[7]*_t947 + _hc0[8]*_t946 + _t389 - _t39*(-_hc0[12]*_t526 - _hc0[13]*_t202 - _t390) - _t394 - _t531*_t977) - _t401 - _t531*(_hc0[7]*_t946 - _t39*_t977 + _t396 + _t397*_t949 - _t399 - _t531*(-_hc0[10]*_t526 - _hc0[11]*_t202 - _hc0[6]*_t42)) - _t559*_t943) - _t21*_t315*_t557 + (0.1e1 / 0.12e2)*_t21*_t962*_t963 - _t216*_t375*_t566 + _t223*_t372*_t831 + _t223*_t842 + _t225*_t364*_t561 - _t268*_t539*_t951 + _t28*_t514*_t535 - _t28*_t962*_t964 - _t28*_t968*_t969 - _t362*_t549 + _t363*_t549 + _t364*_t973 + _t370*_t557 + _t381*_t566 + _t381*(-_t315*_t564 - _t384 + _t385 + _t559*_t939 + _t975*gaa - _t976*gaa) + _t387*_t553*_t972 + _t402*_t563 - _t514*_t547*_t956 + _t521*_t535*_t950 - _t537*_t928 - _t539*_t665 + _t545*_t553*_t971 - _t551*_t7*_t957 + _t552*_t928 - _t555*_t959 + _t676*_t963*_t968 + _t838*(-_t142*_t779 - _t222*_t935 - _t559*_t934) + _t928*_t952 + _t955 - 0.3e1*_t966 - 0.3e1*_t974)) + 0.3e1*_t533 + 0.3e1*_t567;
  const double d4F_dna3_dgbb = _t20*(my_piecewise3(_t22, 0, (0.1e1 / 0.6e1)*_hc8[1]*_hc9[1]*_t16*_t8*_t9*_t90 - _t980) + my_piecewise3(_t25, 0, _t979)) + 0.3e1*_t572 + 0.3e1*_t577;
  const double d4F_dna2_dnb_dgaa = _t20*(my_piecewise3(_t19, 0, (0.1e1 / 0.18e2)*_hc6[1]*_hc7[1]*_t7*_t8*_t9*_t90 + (0.1e1 / 0.36e2)*_hc6[1]*_hc7[2]*_t115*_t21*_t7*_t8*_t9 + (0.1e1 / 0.9e1)*_hc6[1]*_hc7[2]*_t44*_t7*_t8*_t9*_t90*nb + (0.1e1 / 0.36e2)*_hc6[1]*_hc7[3]*_t100*_t21*_t7*_t8*_t9 + 0.4e1*_hc7[1]*_t209*_t90*nb + _hc7[1]*_t21*_t532 + _hc7[2]*_t21*_t44*_t519 - _t100*_t80*_t931 - _t508*_t520 - _t933 - _t938 - _t983) + my_piecewise3(_t23, 0, (0.1e1 / 0.9e1)*_hc0[1]*_hc1[1]*_hc2[0]*_t7*_t8*_t9*_t90 + (0.1e1 / 0.54e2)*_hc0[1]*_hc1[1]*_hc2[1]*_t199*_t200*_t28 + (0.1e1 / 0.9e1)*_hc0[1]*_hc1[2]*_hc2[0]*_t53*_t74*_t8*_t9*_t90 + (0.1e1 / 0.18e2)*_hc0[1]*_hc1[2]*_hc2[1]*_t200*_t215*_t28*_t53 + 0.4e1*_hc1[1]*_hc2[0]*_t223*_t90*na + (0.1e1 / 0.3e1)*_hc1[1]*_hc2[1]*_t1*_t2*_t223*_t28*_t3 - _t145*_t562*_t982 - _t218*_t981 - _t407*_t549 - _t539*_t666 - _t540*_t551 - _t556*_t982 - _t954 - _t966 - _t974)) + _t568 + _t984;
  const double d4F_dna2_dnb_dgbb = _t20*(my_piecewise3(_t22, 0, (0.1e1 / 0.9e1)*_hc8[1]*_hc9[1]*_t16*_t8*_t9*_t90 + (0.1e1 / 0.18e2)*_hc8[1]*_hc9[2]*_t16*_t64*_t8*_t9*_t90*na + 0.2e1*_hc9[1]*_t246*_t90*na - _t990) + my_piecewise3(_t25, 0, -_t503*_t620 + _t503*_t627 + _t503*_t985 + _t853*_t986 + _t979)) + _t578 + _t991;
  const double d4F_dna_dnb2_dgaa = _t20*(my_piecewise3(_t19, 0, (0.1e1 / 0.9e1)*_hc6[1]*_hc7[1]*_t7*_t8*_t9*_t90 + (0.1e1 / 0.18e2)*_hc6[1]*_hc7[2]*_t44*_t7*_t8*_t9*_t90*nb + 0.2e1*_hc7[1]*_t209*_t90*nb - _t983) + my_piecewise3(_t23, 0, -_t503*_t537 + _t503*_t552 + _t503*_t952 + _t549*_t855 + _t955)) + _t594 + _t984;
  const double d4F_dna_dnb2_dgbb = _t20*(my_piecewise3(_t22, 0, (0.1e1 / 0.18e2)*_hc8[1]*_hc9[1]*_t16*_t8*_t9*_t90 + (0.1e1 / 0.36e2)*_hc8[1]*_hc9[2]*_t16*_t175*_t21*_t8*_t9 + (0.1e1 / 0.9e1)*_hc8[1]*_hc9[2]*_t16*_t64*_t8*_t9*_t90*na + (0.1e1 / 0.36e2)*_hc8[1]*_hc9[3]*_t16*_t161*_t21*_t8*_t9 + _hc9[1]*_t21*_t616 + 0.4e1*_hc9[1]*_t246*_t90*na + _hc9[2]*_t21*_t603*_t64 - _t161*_t88*_t999 - _t589*_t604 - _t990 - _t997 - _t998) + my_piecewise3(_t25, 0, (0.1e1 / 0.9e1)*_hc3[1]*_hc4[1]*_hc5[0]*_t16*_t8*_t9*_t90 + (0.1e1 / 0.54e2)*_hc3[1]*_hc4[1]*_hc5[1]*_t200*_t240*_t28 + (0.1e1 / 0.9e1)*_hc3[1]*_hc4[2]*_hc5[0]*_t70*_t8*_t82*_t9*_t90 + (0.1e1 / 0.18e2)*_hc3[1]*_hc4[2]*_hc5[1]*_t200*_t252*_t28*_t70 + 0.4e1*_hc4[1]*_hc5[0]*_t258*_t90*nb + (0.1e1 / 0.3e1)*_hc4[1]*_hc5[1]*_t14*_t2*_t258*_t28*_t3 - _t407*_t623 - _t573*_t626 - _t619*_t981 - _t629*_t993 - _t636*_t993 - _t682*_t992 - _t978 - _t994 - _t996)) + _t641 + _t991;
  const double d4F_dnb3_dgaa = _t20*(my_piecewise3(_t19, 0, (0.1e1 / 0.6e1)*_hc6[1]*_hc7[1]*_t7*_t8*_t9*_t90 - _t926) + my_piecewise3(_t23, 0, _t955)) + 0.3e1*_t592 + 0.3e1*_t593;
  const double d4F_dnb3_dgbb = _t20*(my_piecewise3(_t22, 0, -_t1001*_t161*_t999 - _t1001*_t175*_t589 + _t1005*_t604 + _t16*_t928*_t989*na + _t175*_t702 + _t246*_t887 + _t250*_t616 + _t250*(_t1006*_t600 + _t1008*gbb - _t1009*gbb - _t432*_t611 - _t437 + _t439) + _t290*_t462*_t88 + _t363*_t987 + _t428*_t878*_t88 + _t597*_t875*_t88 + _t598*(-_t1002*_t600 - _t1003*_t1004 - _t172*_t886) + _t87*(-_t1004*_t1012 - _t1010*_t600 + (0.4e1 / 0.9e1)*_t165*_t2*_t3*_t611 + (0.44e2 / 0.81e2)*_t168*_t170*_t8*_t9 + (0.44e2 / 0.81e2)*_t170*_t614*_t8*_t9*gbb - _t447 - _t461 - _t60*(_hc8[7]*_t1014 + _hc8[8]*_t1013 - _t1015*_t615 + _t449 - _t454 - _t60*(-_hc8[12]*_t610 - _hc8[13]*_t241 - _t450)) - _t615*(_hc8[7]*_t1013 - _t1015*_t60 + _t1016*_t612 + _t456 - _t459 - _t615*(-_hc8[10]*_t610 - _hc8[11]*_t241 - _t457))) - _t980 - 0.3e1*_t997 - 0.3e1*_t998) + my_piecewise3(_t25, 0, _hc4[4]*_t1022*_t470 + _hc5[1]*_t200*_t622*_t957 + _hc5[2]*_t1018*_t260*_t960 - _hc5[3]*_t21*_t705*_t84 - _t1017*_t629 - _t1017*_t636 + _t1019*_t1024 + _t1019*_t628 - _t1021*_t193*_t716 - _t1021*_t628*_t715 + _t1023*_t469 - _t1023*_t477 + _t1025*_t193 + _t1027*_t193 + _t1027*_t485 - _t16*_t626*_t957 + _t194*(-_t1010*_t632 - _t1012*_t257 + (0.4e1 / 0.9e1)*_t165*_t2*_t3*_t637 + (0.44e2 / 0.81e2)*_t170*_t188*_t8*_t9 + (0.44e2 / 0.81e2)*_t170*_t638*_t8*_t9*gbb - _t486 - _t499 - _t60*(_hc3[7]*_t1014 + _hc3[8]*_t1013 - _t1030*_t615 + _t487 - _t492 - _t60*(-_hc3[12]*_t610 - _hc3[13]*_t241 - _t488)) - _t615*(_hc3[7]*_t1013 + _t1016*_t495 - _t1030*_t60 + _t494 - _t497 - _t615*(-_hc3[10]*_t610 - _hc3[11]*_t241 - _hc3[6]*_t62))) - _t200*_t260*_t476*_t599 + _t258*_t922 - _t279*_t951*_t992 + _t28*_t599*_t618 + _t308*_t986 - _t362*_t623 + _t372*_t584*_t914 + _t469*_t995 + _t472*_t631 - _t473*_t631 - _t477*_t995 + _t479*_t639 + _t479*(_t1006*_t632 + _t1028*gbb - _t1029*gbb - _t432*_t637 - _t482 + _t483) + _t500*_t630*_t635 + _t605*_t618*_t950 - _t620*_t928 + _t627*_t928 - _t704*_t992 + _t919*(-_t1002*_t632 - _t1003*_t257 - _t190*_t886) + _t928*_t985 + _t979 - 0.3e1*_t994 - 0.3e1*_t996)) + 0.3e1*_t617 + 0.3e1*_t640;
  const double d4F_dna2_dgaa2 = _t20*(my_piecewise3(_t19, 0, _t100*_t277*_t764 - 0.2e1*_t1035 - _t1040*_t509 - _t1041*_t44*_t931 + _t1043 - 0.1e1 / 0.9e1*_t112*_t209*_t508*_t7 + _t115*_t211*_t274 + _t115*_t277*_t512 + _t211*_t511*_t532 + _t212*(-_t1032*_t1036 - _t1034*_t1038 - _t1037*_t205) + _t274*_t513 + _t510*_t512*_t519*_t929 + _t519*_t657 + _t79*(_t1031*_t1032 + _t1033*_t1034 - _t39*(-_hc6[11]*_t648 - _hc6[12]*_t653 - _hc6[7]*_t517) - _t531*(-_hc6[10]*_t648 - _hc6[11]*_t653 - _hc6[6]*_t517) + _t941 - _t942)) + my_piecewise3(_t23, 0, _hc0[3]*_hc1[1]*_t1048 - _hc0[3]*_t1059*_t840 - _hc1[3]*_t1059*_t270*_t53 + _hc2[1]*_t1055*_t28*_t668 - _hc2[1]*_t223*_t819*_t967 + _t1044*_t126 - 0.2e1*_t1047 + _t1048*_t668 - _t1049*_t1050 - _t1049*_t266 - _t1052*_t664 - _t1052*_t669 + _t1053*_t1055*_t216 - _t1056*_t808 - _t1057*_t1058*_t268 - _t1057*_t672 + _t1058*_t1060*_t204 + _t1060*_t671 + _t1062*_t145*_t224 + _t1062*_t962 + _t1064 + _t119*_t223*_t224*_t963 + _t131*_t673*_t965 + _t146*(_t1031*_t1045 + _t1033*_t1046 - _t39*(-_hc0[11]*_t648 - _hc0[12]*_t653 - _hc0[7]*_t517) - _t531*(-_hc0[10]*_t648 - _hc0[11]*_t653 - _hc0[6]*_t517) + _t975 - _t976) + _t21*_t561*_t675*_t679 - _t216*_t558*_t670 + _t381*(-_t1036*_t1045 - _t1037*_t221 - _t1038*_t1046) + _t561*_t970 + _t566*_t676*_t679 + _t673*_t971)) + 0.2e1*_t658 + 0.2e1*_t680;
  const double d4F_dna2_dgbb2 = _t20*(my_piecewise3(_t22, 0, -_t1068*_t587 - _t1069*_t1070 + _t1072) + my_piecewise3(_t25, 0, _t1066)) + 0.2e1*_t686 + 0.2e1*_t689;
  const double d4F_dna_dnb_dgaa2 = _t20*(my_piecewise3(_t19, 0, _hc7[3]*_t21*_t656 - _t1035 + _t1043 - _t1074*_t277 - _t1075*_t508 + _t1075*_t581 - _t274*_t509 - _t274*_t580 + _t274*_t582 + _t655 - _t656*_t931) + my_piecewise3(_t23, 0, (0.1e1 / 0.108e3)*_hc0[3]*_hc1[1]*_hc2[0]*_t2*_t203*_t265*_t90 + (0.1e1 / 0.1296e4)*_hc0[3]*_hc1[1]*_hc2[1]*_t28*_t328*_t650*_t8 + (0.1e1 / 0.108e3)*_hc1[2]*_hc2[0]*_t2*_t203*_t265*_t270*_t90 + (0.1e1 / 0.1296e4)*_hc1[2]*_hc2[1]*_t270*_t28*_t328*_t650*_t8 - _t1047 - _t1050*_t1073 - _t1056*_t536 - _t1058*_t666 - _t1073*_t266 - _t660*_t672)) + _t681 + _t693;
  const double d4F_dna_dnb_dgbb2 = _t20*(my_piecewise3(_t22, 0, _hc9[3]*_t21*_t701 - _t1069*_t293 + _t1072 - _t1082 + _t1083*_t248 - _t1083*_t589 + _t249*_t289 - _t289*_t587 - _t289*_t590 + _t700 - _t701*_t999) + my_piecewise3(_t25, 0, (0.1e1 / 0.108e3)*_hc3[3]*_hc4[1]*_hc5[0]*_t2*_t203*_t279*_t90 + (0.1e1 / 0.1296e4)*_hc3[3]*_hc4[1]*_hc5[1]*_t28*_t445*_t650*_t8 + (0.1e1 / 0.108e3)*_hc4[2]*_hc5[0]*_t2*_t203*_t279*_t284*_t90 + (0.1e1 / 0.1296e4)*_hc4[2]*_hc5[1]*_t28*_t284*_t445*_t650*_t8 - _hc5[0]*_t1079*_t682 - _t1076*_t282 - _t1076*_t684 - _t1078 - _t1081*_t536 - _t682*_t710)) + _t690 + _t719;
  const double d4F_dnb2_dgaa2 = _t20*(my_piecewise3(_t19, 0, -_t1040*_t580 - _t1041*_t1074 + _t1043) + my_piecewise3(_t23, 0, _t1064)) + 0.2e1*_t691 + 0.2e1*_t692;
  const double d4F_dnb2_dgbb2 = _t20*(my_piecewise3(_t22, 0, -_t1068*_t590 - _t1070*_t64*_t999 + _t1072 - 0.2e1*_t1082 - 0.1e1 / 0.9e1*_t16*_t172*_t246*_t589 + _t161*_t293*_t878 + _t175*_t289*_t290 + _t175*_t293*_t597 + _t250*(-_t1085*_t1088 - _t1087*_t1090 - _t1089*_t242) + _t289*_t598 + _t290*_t596*_t616 + _t595*_t597*_t603*_t988 + _t603*_t702 + _t87*(_t1008 - _t1009 + _t1084*_t1085 + _t1086*_t1087 - _t60*(-_hc8[11]*_t696 - _hc8[12]*_t698 - _hc8[7]*_t601) - _t615*(-_hc8[10]*_t696 - _hc8[11]*_t698 - _hc8[6]*_t601))) + my_piecewise3(_t25, 0, -_hc3[3]*_t1099*_t259 + _hc4[2]*_t1080*_t119*_t16*_t190 + _hc4[4]*_t181*_t284*_t713 + _hc5[0]*_t1077*_t126 - _hc5[1]*_t1077*_t184 - _hc5[1]*_t258*_t635*_t910 - _t1018*_t1098*_t712 + _t1024*_t1101 + _t1025*_t634 + _t1066 - 0.2e1*_t1078 + _t1079*_t1100 - _t1081*_t808 + _t1093*_t285 + _t1093*_t706 - _t1094*_t282 - _t1094*_t684 - _t1095*_t285*_t476 - _t1095*_t707 + _t1096*_t1097*_t285 + _t1096*_t1097*_t706 - _t1098*_t279*_t709 - _t1099*_t712 + _t1100*_t709 + _t1101*_t628 + (0.1e1 / 0.18e2)*_t1102*_t634*_t715 + _t193*_t711*_t713 + _t194*(_t1028 - _t1029 + _t1084*_t1091 + _t1086*_t1092 - _t60*(-_hc3[11]*_t696 - _hc3[12]*_t698 - _hc3[7]*_t601) - _t615*(-_hc3[10]*_t696 - _hc3[11]*_t698 - _hc3[6]*_t601)) + _t479*(-_t1088*_t1091 - _t1089*_t256 - _t1090*_t1092) + _t624*_t639*_t717)) + 0.2e1*_t703 + 0.2e1*_t718;
  const double d4F_dna_dgaa3 = _t20*(my_piecewise3(_t19, 0, -_t1103 - _t1104 - _t1105 + _t1114*_t205*_t657 + _t1114*_t209*_t276*_t512 + _t211*_t654*_t932 + _t212*_t733 + _t44*_t737*_t764 + _t735*_t937 + _t79*(-_hc6[10]*_t1113 - _hc6[11]*_t1110 - _hc6[6]*_t1107)) + my_piecewise3(_t23, 0, -_hc0[3]*_t1123*_t547*_t944*_t967 + _hc0[6]*_t225*_t723 + (0.1e1 / 0.72e2)*_t1061*_t677 + _t1115*_t724 + _t1115*_t730 - _t1118 - _t1119 - _t1120 - _t1121*_t1122*_t216 - _t1121*_t547*_t729 + _t1124*_t223*_t961 + _t146*(-_hc0[10]*_t1113 - _hc0[11]*_t1110 - _hc0[6]*_t1107) + _t53*_t723*_t728*_t965 + _t663*_t727*_t972 + _t670*_t676*_t964 + _t725*_t734)) + _t738;
  const double d4F_dna_dgbb3 = _t20*(my_piecewise3(_t22, 0, (0.1e1 / 0.432e3)*_hc8[1]*_hc8[3]*_hc9[2]*_t21*_t645*_t748 + (0.1e1 / 0.1296e4)*_hc8[6]*_hc9[1]*_t21*_t645*_t748 + (0.1e1 / 0.1296e4)*_hc9[3]*_t21*_t645*_t748*_t753 - _t1130 - _t1131 - _t1132) + my_piecewise3(_t25, 0, -_t1126 - _t1127 - _t1129)) + _t755;
  const double d4F_dnb_dgaa3 = _t20*(my_piecewise3(_t19, 0, (0.1e1 / 0.432e3)*_hc6[1]*_hc6[3]*_hc7[2]*_t21*_t645*_t731 + (0.1e1 / 0.1296e4)*_hc6[6]*_hc7[1]*_t21*_t645*_t731 + (0.1e1 / 0.1296e4)*_hc7[3]*_t21*_t645*_t731*_t736 - _t1103 - _t1104 - _t1105) + my_piecewise3(_t23, 0, -_t1118 - _t1119 - _t1120)) + _t738;
  const double d4F_dnb_dgbb3 = _t20*(my_piecewise3(_t22, 0, _t1001*_t290*_t699 + _t1005*_t752 - _t1130 - _t1131 - _t1132 + _t1136*_t242*_t702 + _t1136*_t246*_t292*_t597 + _t250*_t750 + _t64*_t754*_t878 + _t87*(-_hc8[10]*_t1135 - _hc8[11]*_t1134 - _hc8[6]*_t1133)) + my_piecewise3(_t25, 0, _hc3[1]*_hc3[3]*_t1102*_t744 - _hc3[6]*_hc4[1]*_t1139 + _hc3[6]*_t259*_t747 + _hc4[2]*_t1140*_t256*_t279 + _hc4[4]*_t70*_t745*_t747 + _t1018*_t1140*_t711 - _t1123*_t1138*_t742 - _t1126 - _t1127 + _t1128*_t1137 - _t1129 + _t1137*_t741 - _t1139*_t746 + _t194*(-_hc3[10]*_t1135 - _hc3[11]*_t1134 - _hc3[6]*_t1133) + (0.1e1 / 0.12e2)*_t624*_t708*_t716 + _t743*_t751)) + _t755;
  const double d4F_dgaa4 = _t20*(my_piecewise3(_t19, 0, ((_hc6[1]) * (_hc6[1]) * (_hc6[1]) * (_hc6[1]))*_t1148*_t764 + _hc6[1]*_hc6[6]*_t1149*_t1150 + _hc6[10]*_t1148*_t79 + ((_hc6[3]) * (_hc6[3]))*_t1146*_t1149 + _hc6[3]*_t1147*_t1151*_t275*_t512) + my_piecewise3(_t23, 0, ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t1144*_t965 + _hc0[10]*_t1144*_t75 + ((_hc0[3]) * (_hc0[3]))*_t1141*_t1146*_t676 + (0.1e1 / 0.11664e5)*_t1122*_t1145*_t562 + (0.1e1 / 0.7776e4)*_t1124*_t1145*_t663));
  const double d4F_dgbb4 = _t20*(my_piecewise3(_t22, 0, ((_hc8[1]) * (_hc8[1]) * (_hc8[1]) * (_hc8[1]))*_t1155*_t878 + _hc8[1]*_hc8[6]*_t1150*_t1156 + _hc8[10]*_t1155*_t87 + ((_hc8[3]) * (_hc8[3]))*_t1146*_t1156 + _hc8[3]*_t1151*_t1154*_t291*_t597) + my_piecewise3(_t25, 0, ((_hc3[1]) * (_hc3[1]) * (_hc3[1]) * (_hc3[1]))*_hc4[4]*_t1142*_t1153 + _hc3[10]*_t1143*_t1152*_t281 + ((_hc3[3]) * (_hc3[3]))*_hc4[2]*_t1146*_t1153 + _hc3[3]*_t1151*_t1153*_t711 + _hc3[6]*_t1150*_t1153*_t635));
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 2] += d4F_dna3_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 3] += d4F_dna2_dnb_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 5] += d4F_dna2_dnb_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 6] += d4F_dna_dnb2_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 8] += d4F_dna_dnb2_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 9] += d4F_dnb3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 5] += d4F_dna2_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 6] += d4F_dna_dnb_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 11] += d4F_dna_dnb_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 12] += d4F_dnb2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 9] += d4F_dna_dgbb3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 10] += d4F_dnb_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
#endif
#endif
}
#endif