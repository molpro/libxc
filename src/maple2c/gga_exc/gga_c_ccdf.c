/*
  Generated from python/gga_exc/gga_c_ccdf.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_ccdf
*/

#ifndef _GGA_C_CCDF_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_CCDF_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_CCDF_HELPER_BODIES
#include "gga_c_ccdf.c"
#undef _GGA_C_CCDF_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_CCDF_HELPER_BODIES
#include "gga_c_ccdf.c"
#undef _GGA_C_CCDF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_CCDF_HELPER_BODIES
#include "gga_c_ccdf.c"
#undef _GGA_C_CCDF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_CCDF_HELPER_BODIES
#include "gga_c_ccdf.c"
#undef _GGA_C_CCDF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_CCDF_HELPER_BODIES
#include "gga_c_ccdf.c"
#undef _GGA_C_CCDF_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_ccdf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_ccdf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_ccdf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_ccdf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_ccdf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_ccdf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_ccdf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_ccdf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_ccdf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_ccdf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_CCDF_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_ccdf_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double xs0, double xs1, double *out) {
  const gga_c_ccdf_params *params = (const gga_c_ccdf_params *)(p->params);

  const double _t1 = xc_powr(0.3e1, 2, 3);
  const double _t2 = (M_CBRTPI * M_CBRTPI);
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = params->c4*((0.1e1 / 0.6e1)*_t1*_t3*xt - params->c5);
  const double _t5 = exp(-_t4);
  const double _t6 = _t5 + 0.1e1;
  const double _t7 = _t6 - params->c3;
  const double _t8 = (0.1e1 / _t6);
  const double _t9 = M_CBRTPI;
  const double _t10 = (0.1e1 / (rs * rs * rs));
  const double _t11 = xc_powr(_t10, -1, 3);
  const double _t12 = xc_powr(0.6e1, 2, 3)*_t11;
  const double _t13 = _t12*params->c2;
  const double _t14 = (0.1e1 / 0.3e1)*_t13*_t9;
  const double _t15 = _t14 + 0.1e1;
  const double _t16 = (0.1e1 / _t15);
  const double _t17 = _t16*params->c1;
  const double _t18 = _t17*_t8;
#if _KMAX >= 1
  const double _t19 = _t18*_t5;
  const double _t20 = (0.1e1 / 0.6e1)*_t1;
  const double _t21 = (0.1e1 / (_t6 * _t6));
  const double _t22 = (0.1e1 / (_t15 * _t15));
  const double _t23 = (0.1e1 / rs);
  const double _t24 = _t8*params->c1;
  const double _t25 = _t24*_t7;
  const double _t26 = _t23*_t25;
#endif
#if _KMAX >= 2
  const double _t27 = exp(-0.2e1*_t4);
  const double _t28 = _t21*_t27;
  const double _t29 = _t17*_t28;
  const double _t30 = ((params->c4) * (params->c4));
  const double _t31 = (0.1e1 / 0.6e1)*_t30;
  const double _t32 = (M_PI * M_CBRTPI);
  const double _t33 = M_CBRT3/_t32;
  const double _t34 = _t31*_t33;
  const double _t35 = (0.1e1 / 0.12e2)*_t30;
  const double _t36 = _t33*_t35;
  const double _t37 = (0.1e1 / (_t6 * _t6 * _t6));
  const double _t38 = _t17*_t37;
  const double _t39 = _t27*_t7;
  const double _t40 = _t38*_t39;
  const double _t41 = _t17*_t7;
  const double _t42 = _t21*_t5;
  const double _t43 = _t41*_t42;
  const double _t44 = _t24*_t5;
  const double _t45 = _t44*params->c4;
  const double _t46 = _t22*_t23;
  const double _t47 = _t11*_t46*params->c2;
  const double _t48 = (0.1e1 / 0.6e1)*xc_powr(0.12e2, 1, 3)*_t47/_t9;
  const double _t49 = _t42*_t7*params->c1;
  const double _t50 = _t49*params->c4;
  const double _t51 = (0.1e1 / (rs * rs));
  const double _t52 = xc_powr(_t10, -2, 3);
  const double _t53 = (0.1e1 / (_t15 * _t15 * _t15));
  const double _t54 = ((params->c2) * (params->c2));
  const double _t55 = _t51*_t52*_t53*_t54;
#endif
#if _KMAX >= 3
  const double _t56 = (0.1e1 / (M_PI * M_PI));
  const double _t57 = ((params->c4) * (params->c4) * (params->c4));
  const double _t58 = _t56*_t57;
  const double _t59 = exp(-0.3e1*_t4);
  const double _t60 = (0.1e1 / 0.4e1)*_t59;
  const double _t61 = _t38*_t60;
  const double _t62 = (0.1e1 / (_t6 * _t6 * _t6 * _t6));
  const double _t63 = xc_powr(0.2e1, 2, 3);
  const double _t64 = (0.1e1 / M_PI);
  const double _t65 = _t47*_t63*_t64;
  const double _t66 = _t37*params->c1;
  const double _t67 = _t39*_t66;
  const double _t68 = M_CBRT2;
  const double _t69 = _t55*_t68;
  const double _t70 = ((params->c2) * (params->c2) * (params->c2))/(_t15 * _t15 * _t15 * _t15);
#endif
#if _KMAX >= 4
  const double _t71 = ((params->c4) * (params->c4) * (params->c4) * (params->c4))/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t72 = _t20*_t71*exp(-0.4e1*_t4);
  const double _t73 = _t1*_t71;
  const double _t74 = (0.7e1 / 0.72e2)*_t73;
  const double _t75 = (0.1e1 / 0.144e3)*_t73;
  const double _t76 = _t62*_t7;
  const double _t77 = _t13*_t46*_t57/(M_PI * M_CBRTPI * M_CBRTPI);
  const double _t78 = (0.1e1 / 0.12e2)*_t77;
  const double _t79 = _t59*_t78;
  const double _t80 = _t28*params->c1;
  const double _t81 = (0.1e1 / 0.72e2)*_t77;
  const double _t82 = _t1*_t3*_t30*_t69;
  const double _t83 = (0.2e1 / 0.9e1)*_t82;
  const double _t84 = (0.1e1 / 0.9e1)*_t82;
  const double _t85 = (0.4e1 / 0.3e1)*_t1*_t70*_t9;
#endif

  const double f = _t18*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs1 = 0;
  out[1] = df_dxs1;
  const double df_dxs0 = 0;
  out[2] = df_dxs0;
  const double df_dxt = (0.1e1 / 0.6e1)*_t1*_t16*_t21*_t3*_t5*_t7*params->c1*params->c4 - _t19*_t20*_t3*params->c4;
  out[3] = df_dxt;
  const double df_dz = 0;
  out[4] = df_dz;
  const double df_drs = -_t14*_t22*_t26;
  out[5] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxs12 = 0;
  out[6] = d2f_dxs12;
  const double d2f_dxs0_dxs1 = 0;
  out[7] = d2f_dxs0_dxs1;
  const double d2f_dxs02 = 0;
  out[8] = d2f_dxs02;
  const double d2f_dxt_dxs1 = 0;
  out[9] = d2f_dxt_dxs1;
  const double d2f_dxt_dxs0 = 0;
  out[10] = d2f_dxt_dxs0;
  const double d2f_dxt2 = _t19*_t36 - _t29*_t34 + _t34*_t40 - _t36*_t43;
  out[11] = d2f_dxt2;
  const double d2f_dz_dxs1 = 0;
  out[12] = d2f_dz_dxs1;
  const double d2f_dz_dxs0 = 0;
  out[13] = d2f_dz_dxs0;
  const double d2f_dz_dxt = 0;
  out[14] = d2f_dz_dxt;
  const double d2f_dz2 = 0;
  out[15] = d2f_dz2;
  const double d2f_drs_dxs1 = 0;
  out[16] = d2f_drs_dxs1;
  const double d2f_drs_dxs0 = 0;
  out[17] = d2f_drs_dxs0;
  const double d2f_drs_dxt = _t45*_t48 - _t48*_t50;
  out[18] = d2f_drs_dxt;
  const double d2f_drs_dz = 0;
  out[19] = d2f_drs_dz;
  const double d2f_drs2 = (0.4e1 / 0.3e1)*xc_powr(0.6e1, 1, 3)*_t2*_t25*_t55;
  out[20] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxs13 = 0;
  out[21] = d3f_dxs13;
  const double d3f_dxs0_dxs12 = 0;
  out[22] = d3f_dxs0_dxs12;
  const double d3f_dxs02_dxs1 = 0;
  out[23] = d3f_dxs02_dxs1;
  const double d3f_dxs03 = 0;
  out[24] = d3f_dxs03;
  const double d3f_dxt_dxs12 = 0;
  out[25] = d3f_dxt_dxs12;
  const double d3f_dxt_dxs0_dxs1 = 0;
  out[26] = d3f_dxt_dxs0_dxs1;
  const double d3f_dxt_dxs02 = 0;
  out[27] = d3f_dxt_dxs02;
  const double d3f_dxt2_dxs1 = 0;
  out[28] = d3f_dxt2_dxs1;
  const double d3f_dxt2_dxs0 = 0;
  out[29] = d3f_dxt2_dxs0;
  const double d3f_dxt3 = (0.1e1 / 0.4e1)*_t16*_t21*_t27*_t56*_t57*params->c1 + (0.1e1 / 0.24e2)*_t16*_t21*_t5*_t56*_t57*_t7*params->c1 + (0.1e1 / 0.4e1)*_t16*_t56*_t57*_t59*_t62*_t7*params->c1 - 0.1e1 / 0.24e2*_t19*_t58 - 0.1e1 / 0.4e1*_t40*_t58 - _t58*_t61;
  out[30] = d3f_dxt3;
  const double d3f_dz_dxs12 = 0;
  out[31] = d3f_dz_dxs12;
  const double d3f_dz_dxs0_dxs1 = 0;
  out[32] = d3f_dz_dxs0_dxs1;
  const double d3f_dz_dxs02 = 0;
  out[33] = d3f_dz_dxs02;
  const double d3f_dz_dxt_dxs1 = 0;
  out[34] = d3f_dz_dxt_dxs1;
  const double d3f_dz_dxt_dxs0 = 0;
  out[35] = d3f_dz_dxt_dxs0;
  const double d3f_dz_dxt2 = 0;
  out[36] = d3f_dz_dxt2;
  const double d3f_dz2_dxs1 = 0;
  out[37] = d3f_dz2_dxs1;
  const double d3f_dz2_dxs0 = 0;
  out[38] = d3f_dz2_dxs0;
  const double d3f_dz2_dxt = 0;
  out[39] = d3f_dz2_dxt;
  const double d3f_dz3 = 0;
  out[40] = d3f_dz3;
  const double d3f_drs_dxs12 = 0;
  out[41] = d3f_drs_dxs12;
  const double d3f_drs_dxs0_dxs1 = 0;
  out[42] = d3f_drs_dxs0_dxs1;
  const double d3f_drs_dxs02 = 0;
  out[43] = d3f_drs_dxs02;
  const double d3f_drs_dxt_dxs1 = 0;
  out[44] = d3f_drs_dxt_dxs1;
  const double d3f_drs_dxt_dxs0 = 0;
  out[45] = d3f_drs_dxt_dxs0;
  const double d3f_drs_dxt2 = (0.1e1 / 0.6e1)*_t11*_t21*_t22*_t23*_t27*_t30*_t63*_t64*params->c1*params->c2 + (0.1e1 / 0.12e2)*_t11*_t21*_t22*_t23*_t30*_t5*_t63*_t64*_t7*params->c1*params->c2 - _t31*_t65*_t67 - _t35*_t44*_t65;
  out[46] = d3f_drs_dxt2;
  const double d3f_drs_dz_dxs1 = 0;
  out[47] = d3f_drs_dz_dxs1;
  const double d3f_drs_dz_dxs0 = 0;
  out[48] = d3f_drs_dz_dxs0;
  const double d3f_drs_dz_dxt = 0;
  out[49] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = 0;
  out[50] = d3f_drs_dz2;
  const double d3f_drs2_dxs1 = 0;
  out[51] = d3f_drs2_dxs1;
  const double d3f_drs2_dxs0 = 0;
  out[52] = d3f_drs2_dxs0;
  const double d3f_drs2_dxt = (0.2e1 / 0.3e1)*_t21*_t5*_t51*_t52*_t53*_t54*_t68*_t7*params->c1*params->c4 - 0.2e1 / 0.3e1*_t45*_t69;
  out[53] = d3f_drs2_dxt;
  const double d3f_drs2_dz = 0;
  out[54] = d3f_drs2_dz;
  const double d3f_drs3 = -0.8e1*M_PI*_t25*_t70;
  out[55] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxs14 = 0;
  out[56] = d4f_dxs14;
  const double d4f_dxs0_dxs13 = 0;
  out[57] = d4f_dxs0_dxs13;
  const double d4f_dxs02_dxs12 = 0;
  out[58] = d4f_dxs02_dxs12;
  const double d4f_dxs03_dxs1 = 0;
  out[59] = d4f_dxs03_dxs1;
  const double d4f_dxs04 = 0;
  out[60] = d4f_dxs04;
  const double d4f_dxt_dxs13 = 0;
  out[61] = d4f_dxt_dxs13;
  const double d4f_dxt_dxs0_dxs12 = 0;
  out[62] = d4f_dxt_dxs0_dxs12;
  const double d4f_dxt_dxs02_dxs1 = 0;
  out[63] = d4f_dxt_dxs02_dxs1;
  const double d4f_dxt_dxs03 = 0;
  out[64] = d4f_dxt_dxs03;
  const double d4f_dxt2_dxs12 = 0;
  out[65] = d4f_dxt2_dxs12;
  const double d4f_dxt2_dxs0_dxs1 = 0;
  out[66] = d4f_dxt2_dxs0_dxs1;
  const double d4f_dxt2_dxs02 = 0;
  out[67] = d4f_dxt2_dxs02;
  const double d4f_dxt3_dxs1 = 0;
  out[68] = d4f_dxt3_dxs1;
  const double d4f_dxt3_dxs0 = 0;
  out[69] = d4f_dxt3_dxs0;
  const double d4f_dxt4 = -_t17*_t60*_t73*_t76 - _t17*_t62*_t72 + _t19*_t75 - _t29*_t74 + _t40*_t74 + _t41*_t72/xc_powi(_t6, 5) - _t43*_t75 + _t61*_t73;
  out[70] = d4f_dxt4;
  const double d4f_dz_dxs13 = 0;
  out[71] = d4f_dz_dxs13;
  const double d4f_dz_dxs0_dxs12 = 0;
  out[72] = d4f_dz_dxs0_dxs12;
  const double d4f_dz_dxs02_dxs1 = 0;
  out[73] = d4f_dz_dxs02_dxs1;
  const double d4f_dz_dxs03 = 0;
  out[74] = d4f_dz_dxs03;
  const double d4f_dz_dxt_dxs12 = 0;
  out[75] = d4f_dz_dxt_dxs12;
  const double d4f_dz_dxt_dxs0_dxs1 = 0;
  out[76] = d4f_dz_dxt_dxs0_dxs1;
  const double d4f_dz_dxt_dxs02 = 0;
  out[77] = d4f_dz_dxt_dxs02;
  const double d4f_dz_dxt2_dxs1 = 0;
  out[78] = d4f_dz_dxt2_dxs1;
  const double d4f_dz_dxt2_dxs0 = 0;
  out[79] = d4f_dz_dxt2_dxs0;
  const double d4f_dz_dxt3 = 0;
  out[80] = d4f_dz_dxt3;
  const double d4f_dz2_dxs12 = 0;
  out[81] = d4f_dz2_dxs12;
  const double d4f_dz2_dxs0_dxs1 = 0;
  out[82] = d4f_dz2_dxs0_dxs1;
  const double d4f_dz2_dxs02 = 0;
  out[83] = d4f_dz2_dxs02;
  const double d4f_dz2_dxt_dxs1 = 0;
  out[84] = d4f_dz2_dxt_dxs1;
  const double d4f_dz2_dxt_dxs0 = 0;
  out[85] = d4f_dz2_dxt_dxs0;
  const double d4f_dz2_dxt2 = 0;
  out[86] = d4f_dz2_dxt2;
  const double d4f_dz3_dxs1 = 0;
  out[87] = d4f_dz3_dxs1;
  const double d4f_dz3_dxs0 = 0;
  out[88] = d4f_dz3_dxs0;
  const double d4f_dz3_dxt = 0;
  out[89] = d4f_dz3_dxt;
  const double d4f_dz4 = 0;
  out[90] = d4f_dz4;
  const double d4f_drs_dxs13 = 0;
  out[91] = d4f_drs_dxs13;
  const double d4f_drs_dxs0_dxs12 = 0;
  out[92] = d4f_drs_dxs0_dxs12;
  const double d4f_drs_dxs02_dxs1 = 0;
  out[93] = d4f_drs_dxs02_dxs1;
  const double d4f_drs_dxs03 = 0;
  out[94] = d4f_drs_dxs03;
  const double d4f_drs_dxt_dxs12 = 0;
  out[95] = d4f_drs_dxt_dxs12;
  const double d4f_drs_dxt_dxs0_dxs1 = 0;
  out[96] = d4f_drs_dxt_dxs0_dxs1;
  const double d4f_drs_dxt_dxs02 = 0;
  out[97] = d4f_drs_dxt_dxs02;
  const double d4f_drs_dxt2_dxs1 = 0;
  out[98] = d4f_drs_dxt2_dxs1;
  const double d4f_drs_dxt2_dxs0 = 0;
  out[99] = d4f_drs_dxt2_dxs0;
  const double d4f_drs_dxt3 = _t44*_t81 - _t49*_t81 + _t66*_t79 + _t67*_t78 - _t76*_t79*params->c1 - _t78*_t80;
  out[100] = d4f_drs_dxt3;
  const double d4f_drs_dz_dxs12 = 0;
  out[101] = d4f_drs_dz_dxs12;
  const double d4f_drs_dz_dxs0_dxs1 = 0;
  out[102] = d4f_drs_dz_dxs0_dxs1;
  const double d4f_drs_dz_dxs02 = 0;
  out[103] = d4f_drs_dz_dxs02;
  const double d4f_drs_dz_dxt_dxs1 = 0;
  out[104] = d4f_drs_dz_dxt_dxs1;
  const double d4f_drs_dz_dxt_dxs0 = 0;
  out[105] = d4f_drs_dz_dxt_dxs0;
  const double d4f_drs_dz_dxt2 = 0;
  out[106] = d4f_drs_dz_dxt2;
  const double d4f_drs_dz2_dxs1 = 0;
  out[107] = d4f_drs_dz2_dxs1;
  const double d4f_drs_dz2_dxs0 = 0;
  out[108] = d4f_drs_dz2_dxs0;
  const double d4f_drs_dz2_dxt = 0;
  out[109] = d4f_drs_dz2_dxt;
  const double d4f_drs_dz3 = 0;
  out[110] = d4f_drs_dz3;
  const double d4f_drs2_dxs12 = 0;
  out[111] = d4f_drs2_dxs12;
  const double d4f_drs2_dxs0_dxs1 = 0;
  out[112] = d4f_drs2_dxs0_dxs1;
  const double d4f_drs2_dxs02 = 0;
  out[113] = d4f_drs2_dxs02;
  const double d4f_drs2_dxt_dxs1 = 0;
  out[114] = d4f_drs2_dxt_dxs1;
  const double d4f_drs2_dxt_dxs0 = 0;
  out[115] = d4f_drs2_dxt_dxs0;
  const double d4f_drs2_dxt2 = _t44*_t84 - _t49*_t84 + _t67*_t83 - _t80*_t83;
  out[116] = d4f_drs2_dxt2;
  const double d4f_drs2_dz_dxs1 = 0;
  out[117] = d4f_drs2_dz_dxs1;
  const double d4f_drs2_dz_dxs0 = 0;
  out[118] = d4f_drs2_dz_dxs0;
  const double d4f_drs2_dz_dxt = 0;
  out[119] = d4f_drs2_dz_dxt;
  const double d4f_drs2_dz2 = 0;
  out[120] = d4f_drs2_dz2;
  const double d4f_drs3_dxs1 = 0;
  out[121] = d4f_drs3_dxs1;
  const double d4f_drs3_dxs0 = 0;
  out[122] = d4f_drs3_dxs0;
  const double d4f_drs3_dxt = _t45*_t85 - _t50*_t85;
  out[123] = d4f_drs3_dxt;
  const double d4f_drs3_dz = 0;
  out[124] = d4f_drs3_dz;
  const double d4f_drs4 = (0.32e2 / 0.3e1)*_t12*_t26*_t32*((params->c2) * (params->c2) * (params->c2) * (params->c2))/xc_powi(_t15, 5);
  out[125] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_ccdf_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double xs0, double xs1, double *out) {
  const gga_c_ccdf_params *params = (const gga_c_ccdf_params *)(p->params);

  const double _t1 = xc_powr(0.3e1, 2, 3);
  const double _t2 = (M_CBRTPI * M_CBRTPI);
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = params->c4*((0.1e1 / 0.6e1)*_t1*_t3*xt - params->c5);
  const double _t5 = exp(-_t4);
  const double _t6 = _t5 + 0.1e1;
  const double _t7 = _t6 - params->c3;
  const double _t8 = (0.1e1 / _t6);
  const double _t9 = M_CBRTPI;
  const double _t10 = (0.1e1 / (rs * rs * rs));
  const double _t11 = xc_powr(_t10, -1, 3);
  const double _t12 = xc_powr(0.6e1, 2, 3)*_t11;
  const double _t13 = _t12*params->c2;
  const double _t14 = (0.1e1 / 0.3e1)*_t13*_t9;
  const double _t15 = _t14 + 0.1e1;
  const double _t16 = (0.1e1 / _t15);
  const double _t17 = _t16*params->c1;
  const double _t18 = _t17*_t8;
#if _KMAX >= 1
  const double _t19 = _t18*_t5;
  const double _t20 = (0.1e1 / 0.6e1)*_t1;
  const double _t21 = (0.1e1 / (_t6 * _t6));
  const double _t22 = (0.1e1 / (_t15 * _t15));
  const double _t23 = (0.1e1 / rs);
  const double _t24 = _t8*params->c1;
  const double _t25 = _t24*_t7;
  const double _t26 = _t23*_t25;
#endif
#if _KMAX >= 2
  const double _t27 = exp(-0.2e1*_t4);
  const double _t28 = _t21*_t27;
  const double _t29 = _t17*_t28;
  const double _t30 = ((params->c4) * (params->c4));
  const double _t31 = (0.1e1 / 0.6e1)*_t30;
  const double _t32 = (M_PI * M_CBRTPI);
  const double _t33 = M_CBRT3/_t32;
  const double _t34 = _t31*_t33;
  const double _t35 = (0.1e1 / 0.12e2)*_t30;
  const double _t36 = _t33*_t35;
  const double _t37 = (0.1e1 / (_t6 * _t6 * _t6));
  const double _t38 = _t17*_t37;
  const double _t39 = _t27*_t7;
  const double _t40 = _t38*_t39;
  const double _t41 = _t17*_t7;
  const double _t42 = _t21*_t5;
  const double _t43 = _t41*_t42;
  const double _t44 = _t24*_t5;
  const double _t45 = _t44*params->c4;
  const double _t46 = _t22*_t23;
  const double _t47 = _t11*_t46*params->c2;
  const double _t48 = (0.1e1 / 0.6e1)*xc_powr(0.12e2, 1, 3)*_t47/_t9;
  const double _t49 = _t42*_t7*params->c1;
  const double _t50 = _t49*params->c4;
  const double _t51 = (0.1e1 / (rs * rs));
  const double _t52 = xc_powr(_t10, -2, 3);
  const double _t53 = (0.1e1 / (_t15 * _t15 * _t15));
  const double _t54 = ((params->c2) * (params->c2));
  const double _t55 = _t51*_t52*_t53*_t54;
#endif
#if _KMAX >= 3
  const double _t56 = (0.1e1 / (M_PI * M_PI));
  const double _t57 = ((params->c4) * (params->c4) * (params->c4));
  const double _t58 = _t56*_t57;
  const double _t59 = exp(-0.3e1*_t4);
  const double _t60 = (0.1e1 / 0.4e1)*_t59;
  const double _t61 = _t38*_t60;
  const double _t62 = (0.1e1 / (_t6 * _t6 * _t6 * _t6));
  const double _t63 = xc_powr(0.2e1, 2, 3);
  const double _t64 = (0.1e1 / M_PI);
  const double _t65 = _t47*_t63*_t64;
  const double _t66 = _t37*params->c1;
  const double _t67 = _t39*_t66;
  const double _t68 = M_CBRT2;
  const double _t69 = _t55*_t68;
  const double _t70 = ((params->c2) * (params->c2) * (params->c2))/(_t15 * _t15 * _t15 * _t15);
#endif
#if _KMAX >= 4
  const double _t71 = ((params->c4) * (params->c4) * (params->c4) * (params->c4))/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t72 = _t20*_t71*exp(-0.4e1*_t4);
  const double _t73 = _t1*_t71;
  const double _t74 = (0.7e1 / 0.72e2)*_t73;
  const double _t75 = (0.1e1 / 0.144e3)*_t73;
  const double _t76 = _t62*_t7;
  const double _t77 = _t13*_t46*_t57/(M_PI * M_CBRTPI * M_CBRTPI);
  const double _t78 = (0.1e1 / 0.12e2)*_t77;
  const double _t79 = _t59*_t78;
  const double _t80 = _t28*params->c1;
  const double _t81 = (0.1e1 / 0.72e2)*_t77;
  const double _t82 = _t1*_t3*_t30*_t69;
  const double _t83 = (0.2e1 / 0.9e1)*_t82;
  const double _t84 = (0.1e1 / 0.9e1)*_t82;
  const double _t85 = (0.4e1 / 0.3e1)*_t1*_t70*_t9;
#endif

  const double f = _t18*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs1 = 0;
  out[1] = df_dxs1;
  const double df_dxs0 = 0;
  out[2] = df_dxs0;
  const double df_dxt = (0.1e1 / 0.6e1)*_t1*_t16*_t21*_t3*_t5*_t7*params->c1*params->c4 - _t19*_t20*_t3*params->c4;
  out[3] = df_dxt;
  const double df_drs = -_t14*_t22*_t26;
  out[4] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxs12 = 0;
  out[5] = d2f_dxs12;
  const double d2f_dxs0_dxs1 = 0;
  out[6] = d2f_dxs0_dxs1;
  const double d2f_dxs02 = 0;
  out[7] = d2f_dxs02;
  const double d2f_dxt_dxs1 = 0;
  out[8] = d2f_dxt_dxs1;
  const double d2f_dxt_dxs0 = 0;
  out[9] = d2f_dxt_dxs0;
  const double d2f_dxt2 = _t19*_t36 - _t29*_t34 + _t34*_t40 - _t36*_t43;
  out[10] = d2f_dxt2;
  const double d2f_drs_dxs1 = 0;
  out[11] = d2f_drs_dxs1;
  const double d2f_drs_dxs0 = 0;
  out[12] = d2f_drs_dxs0;
  const double d2f_drs_dxt = _t45*_t48 - _t48*_t50;
  out[13] = d2f_drs_dxt;
  const double d2f_drs2 = (0.4e1 / 0.3e1)*xc_powr(0.6e1, 1, 3)*_t2*_t25*_t55;
  out[14] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxs13 = 0;
  out[15] = d3f_dxs13;
  const double d3f_dxs0_dxs12 = 0;
  out[16] = d3f_dxs0_dxs12;
  const double d3f_dxs02_dxs1 = 0;
  out[17] = d3f_dxs02_dxs1;
  const double d3f_dxs03 = 0;
  out[18] = d3f_dxs03;
  const double d3f_dxt_dxs12 = 0;
  out[19] = d3f_dxt_dxs12;
  const double d3f_dxt_dxs0_dxs1 = 0;
  out[20] = d3f_dxt_dxs0_dxs1;
  const double d3f_dxt_dxs02 = 0;
  out[21] = d3f_dxt_dxs02;
  const double d3f_dxt2_dxs1 = 0;
  out[22] = d3f_dxt2_dxs1;
  const double d3f_dxt2_dxs0 = 0;
  out[23] = d3f_dxt2_dxs0;
  const double d3f_dxt3 = (0.1e1 / 0.4e1)*_t16*_t21*_t27*_t56*_t57*params->c1 + (0.1e1 / 0.24e2)*_t16*_t21*_t5*_t56*_t57*_t7*params->c1 + (0.1e1 / 0.4e1)*_t16*_t56*_t57*_t59*_t62*_t7*params->c1 - 0.1e1 / 0.24e2*_t19*_t58 - 0.1e1 / 0.4e1*_t40*_t58 - _t58*_t61;
  out[24] = d3f_dxt3;
  const double d3f_drs_dxs12 = 0;
  out[25] = d3f_drs_dxs12;
  const double d3f_drs_dxs0_dxs1 = 0;
  out[26] = d3f_drs_dxs0_dxs1;
  const double d3f_drs_dxs02 = 0;
  out[27] = d3f_drs_dxs02;
  const double d3f_drs_dxt_dxs1 = 0;
  out[28] = d3f_drs_dxt_dxs1;
  const double d3f_drs_dxt_dxs0 = 0;
  out[29] = d3f_drs_dxt_dxs0;
  const double d3f_drs_dxt2 = (0.1e1 / 0.6e1)*_t11*_t21*_t22*_t23*_t27*_t30*_t63*_t64*params->c1*params->c2 + (0.1e1 / 0.12e2)*_t11*_t21*_t22*_t23*_t30*_t5*_t63*_t64*_t7*params->c1*params->c2 - _t31*_t65*_t67 - _t35*_t44*_t65;
  out[30] = d3f_drs_dxt2;
  const double d3f_drs2_dxs1 = 0;
  out[31] = d3f_drs2_dxs1;
  const double d3f_drs2_dxs0 = 0;
  out[32] = d3f_drs2_dxs0;
  const double d3f_drs2_dxt = (0.2e1 / 0.3e1)*_t21*_t5*_t51*_t52*_t53*_t54*_t68*_t7*params->c1*params->c4 - 0.2e1 / 0.3e1*_t45*_t69;
  out[33] = d3f_drs2_dxt;
  const double d3f_drs3 = -0.8e1*M_PI*_t25*_t70;
  out[34] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxs14 = 0;
  out[35] = d4f_dxs14;
  const double d4f_dxs0_dxs13 = 0;
  out[36] = d4f_dxs0_dxs13;
  const double d4f_dxs02_dxs12 = 0;
  out[37] = d4f_dxs02_dxs12;
  const double d4f_dxs03_dxs1 = 0;
  out[38] = d4f_dxs03_dxs1;
  const double d4f_dxs04 = 0;
  out[39] = d4f_dxs04;
  const double d4f_dxt_dxs13 = 0;
  out[40] = d4f_dxt_dxs13;
  const double d4f_dxt_dxs0_dxs12 = 0;
  out[41] = d4f_dxt_dxs0_dxs12;
  const double d4f_dxt_dxs02_dxs1 = 0;
  out[42] = d4f_dxt_dxs02_dxs1;
  const double d4f_dxt_dxs03 = 0;
  out[43] = d4f_dxt_dxs03;
  const double d4f_dxt2_dxs12 = 0;
  out[44] = d4f_dxt2_dxs12;
  const double d4f_dxt2_dxs0_dxs1 = 0;
  out[45] = d4f_dxt2_dxs0_dxs1;
  const double d4f_dxt2_dxs02 = 0;
  out[46] = d4f_dxt2_dxs02;
  const double d4f_dxt3_dxs1 = 0;
  out[47] = d4f_dxt3_dxs1;
  const double d4f_dxt3_dxs0 = 0;
  out[48] = d4f_dxt3_dxs0;
  const double d4f_dxt4 = -_t17*_t60*_t73*_t76 - _t17*_t62*_t72 + _t19*_t75 - _t29*_t74 + _t40*_t74 + _t41*_t72/xc_powi(_t6, 5) - _t43*_t75 + _t61*_t73;
  out[49] = d4f_dxt4;
  const double d4f_drs_dxs13 = 0;
  out[50] = d4f_drs_dxs13;
  const double d4f_drs_dxs0_dxs12 = 0;
  out[51] = d4f_drs_dxs0_dxs12;
  const double d4f_drs_dxs02_dxs1 = 0;
  out[52] = d4f_drs_dxs02_dxs1;
  const double d4f_drs_dxs03 = 0;
  out[53] = d4f_drs_dxs03;
  const double d4f_drs_dxt_dxs12 = 0;
  out[54] = d4f_drs_dxt_dxs12;
  const double d4f_drs_dxt_dxs0_dxs1 = 0;
  out[55] = d4f_drs_dxt_dxs0_dxs1;
  const double d4f_drs_dxt_dxs02 = 0;
  out[56] = d4f_drs_dxt_dxs02;
  const double d4f_drs_dxt2_dxs1 = 0;
  out[57] = d4f_drs_dxt2_dxs1;
  const double d4f_drs_dxt2_dxs0 = 0;
  out[58] = d4f_drs_dxt2_dxs0;
  const double d4f_drs_dxt3 = _t44*_t81 - _t49*_t81 + _t66*_t79 + _t67*_t78 - _t76*_t79*params->c1 - _t78*_t80;
  out[59] = d4f_drs_dxt3;
  const double d4f_drs2_dxs12 = 0;
  out[60] = d4f_drs2_dxs12;
  const double d4f_drs2_dxs0_dxs1 = 0;
  out[61] = d4f_drs2_dxs0_dxs1;
  const double d4f_drs2_dxs02 = 0;
  out[62] = d4f_drs2_dxs02;
  const double d4f_drs2_dxt_dxs1 = 0;
  out[63] = d4f_drs2_dxt_dxs1;
  const double d4f_drs2_dxt_dxs0 = 0;
  out[64] = d4f_drs2_dxt_dxs0;
  const double d4f_drs2_dxt2 = _t44*_t84 - _t49*_t84 + _t67*_t83 - _t80*_t83;
  out[65] = d4f_drs2_dxt2;
  const double d4f_drs3_dxs1 = 0;
  out[66] = d4f_drs3_dxs1;
  const double d4f_drs3_dxs0 = 0;
  out[67] = d4f_drs3_dxs0;
  const double d4f_drs3_dxt = _t45*_t85 - _t50*_t85;
  out[68] = d4f_drs3_dxt;
  const double d4f_drs4 = (0.32e2 / 0.3e1)*_t12*_t26*_t32*((params->c2) * (params->c2) * (params->c2) * (params->c2))/xc_powi(_t15, 5);
  out[69] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_c_ccdf_params *params = (const gga_c_ccdf_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = (0.1e1 / 0.2e1)/xc_powr(na, 1, 3);
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = xc_powr(gaa, 1, 2);
  const double _t6 = xc_powr(na, -4, 3);
  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(f_ccdf_z0_k, _KMAX)(p, _t1*_t4, _t5*_t6, 0, 0, _hc0);
  const double zk = _hc0[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t7 = xc_powr(na, -7, 3);
  const double _t8 = _t5*_t7;
  const double _t9 = (0.4e1 / 0.3e1)*_t8;
  const double _t11 = (0.1e1 / 0.6e1)*_t6;
  const double _t12 = (0.1e1 / _t5);
  const double _t10 = _hc0[4]*_t4;
  const double _t13 = _hc0[3]*_t12;
  const double dF_dna = _hc0[0] + na*(-_hc0[3]*_t9 - _t10*_t11);
  const double dF_dgaa = _t1*_t13;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t14 = (0.8e1 / 0.3e1)*_t8;
  const double _t15 = (0.1e1 / 0.3e1)*_t6;
  const double _t17 = xc_powr(na, -10, 3);
  const double _t18 = (0.28e2 / 0.9e1)*_t17;
  const double _t19 = (0.2e1 / 0.9e1)*_t7;
  const double _t21 = _t11*_t4;
  const double _t24 = (0.1e1 / 0.2e1)*_t6;
  const double _t25 = xc_powr(na, -11, 3);
  const double _t26 = (0.2e1 / 0.3e1)*_t25;
  const double _t28 = (0.2e1 / 0.3e1)*_t7;
  const double _t29 = _t12*_t4;
  const double _t31 = xc_powr(na, -8, 3);
  const double _t32 = (0.1e1 / 0.12e2)*_t31;
  const double _t33 = (0.1e1 / gaa);
  const double _t34 = (0.1e1 / 0.4e1)*_t31;
  const double _t35 = xc_powr(gaa, -3, 2);
  const double _t37 = (0.1e1 / 0.4e1)*_t6;
  const double _t16 = _hc0[3]*_t5;
  const double _t20 = (0.4e1 / 0.3e1)*_hc0[10];
  const double _t22 = -_hc0[13]*_t21 - _t20*_t8;
  const double _t23 = -_hc0[13]*_t9 - _hc0[14]*_t21;
  const double _t27 = _hc0[10]*_t26;
  const double _t30 = _hc0[13]*_t29;
  const double _t36 = _hc0[3]*_t35;
  const double _t38 = _hc0[10]*_t33*_t34 - _t36*_t37;
  const double d2F_dna2 = -_hc0[3]*_t14 - _t10*_t15 + na*(_t10*_t19 + _t16*_t18 - _t21*_t23 - _t22*_t9);
  const double d2F_dna_dgaa = _t13*_t24 + na*(-_t13*_t28 - _t27 - _t30*_t32);
  const double d2F_dgaa2 = _t38*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t39 = (0.28e2 / 0.3e1)*_t17;
  const double _t40 = 0.4e1*_t8;
  const double _t42 = xc_powr(na, -13, 3);
  const double _t43 = (0.280e3 / 0.27e2)*_t42;
  const double _t44 = (0.14e2 / 0.27e2)*_t17;
  const double _t45 = _t18*_t5;
  const double _t46 = _t19*_t4;
  const double _t53 = (0.4e1 / 0.3e1)*_t7;
  const double _t54 = xc_powr(na, -14, 3);
  const double _t55 = (0.14e2 / 0.9e1)*_t54;
  const double _t57 = (0.14e2 / 0.9e1)*_t17;
  const double _t58 = (0.1e1 / 0.9e1)*_t25;
  const double _t59 = _t12*_t28;
  const double _t61 = _t29*_t32;
  const double _t65 = _t35*_t37;
  const double _t68 = (0.1e1 / (gaa * gaa));
  const double _t69 = xc_powr(gaa, -5, 2);
  const double _t71 = (0.3e1 / 0.8e1)*_t6;
  const double _t41 = _t23*_t4;
  const double _t47 = -_hc0[24]*_t9 - _hc0[30]*_t21;
  const double _t48 = -_hc0[30]*_t9 - _hc0[33]*_t21;
  const double _t49 = _hc0[10]*_t45 + _hc0[13]*_t46 - _t21*_t48 - _t47*_t9;
  const double _t50 = -_hc0[33]*_t9 - _hc0[34]*_t21;
  const double _t51 = _hc0[13]*_t45 + _hc0[14]*_t46 - _t21*_t50 - _t48*_t9;
  const double _t52 = _t20*_t25;
  const double _t56 = _hc0[10]*_t55;
  const double _t60 = _hc0[24]*_t26;
  const double _t62 = -_hc0[10]*_t59 - _hc0[30]*_t61 - _t60;
  const double _t63 = _hc0[30]*_t26;
  const double _t64 = -_hc0[13]*_t59 - _hc0[33]*_t61 - _t63;
  const double _t66 = -_hc0[10]*_t65 + (0.1e1 / 0.4e1)*_hc0[24]*_t31*_t33;
  const double _t67 = -_hc0[13]*_t65 + (0.1e1 / 0.4e1)*_hc0[30]*_t31*_t33;
  const double _t70 = _hc0[3]*_t69;
  const double _t72 = _t12*_t66;
  const double _t73 = -_hc0[10]*_t34*_t68 + _t24*_t72 + _t70*_t71;
  const double d3F_dna3 = _t10*_t28 + _t16*_t39 - _t22*_t40 - _t24*_t41 + na*(-_t10*_t44 - _t16*_t43 + (0.56e2 / 0.9e1)*_t17*_t22*_t5 + (0.4e1 / 0.9e1)*_t2*_t23*_t3*_t7 - _t21*_t51 - _t49*_t9);
  const double d3F_dna2_dgaa = -_t13*_t53 - 0.1e1 / 0.6e1*_t30*_t31 - _t52 + na*(_t13*_t57 - _t21*_t64 - _t22*_t59 + _t30*_t58 + _t56 - _t62*_t9);
  const double d3F_dna_dgaa2 = _t38 + na*((0.1e1 / 0.3e1)*_hc0[3]*_t35*_t7 - _t21*_t67 - _t27*_t33 - _t66*_t9);
  const double d3F_dgaa3 = _t73*na;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t75 = _t43*_t5;
  const double _t76 = _t4*_t44;
  const double _t80 = 0.2e1*_t7;
  const double _t81 = _t12*_t57;
  const double _t82 = _t29*_t58;
  const double _t86 = _t69*_t71;
  const double _t87 = _t34*_t68;
  const double _t88 = _t12*_t24;
  const double _t74 = _t4*_t51;
  const double _t77 = -_hc0[59]*_t9 - _hc0[65]*_t21;
  const double _t78 = -_hc0[65]*_t9 - _hc0[68]*_t21;
  const double _t79 = _hc0[30]*_t45 + _hc0[33]*_t46 - _t21*_t78 - _t77*_t9;
  const double _t83 = -_hc0[30]*_t59 - _hc0[59]*_t26 - _hc0[65]*_t61;
  const double _t84 = -_hc0[24]*_t65 + (0.1e1 / 0.4e1)*_hc0[49]*_t31*_t33;
  const double _t85 = -_hc0[30]*_t65 + (0.1e1 / 0.4e1)*_hc0[59]*_t31*_t33;
  const double _t89 = _hc0[10]*_t86 - _hc0[24]*_t87 + _t84*_t88;
  const double d4F_dna4 = -0.56e2 / 0.27e2*_t10*_t17 - 0.1120e4 / 0.27e2*_t16*_t42 + (0.224e3 / 0.9e1)*_t17*_t22*_t5 + (0.16e2 / 0.9e1)*_t2*_t23*_t3*_t7 - 0.16e2 / 0.3e1*_t49*_t8 - 0.2e1 / 0.3e1*_t6*_t74 + na*((0.140e3 / 0.81e2)*_t10*_t42 + (0.3640e4 / 0.81e2)*_t16/xc_powr(na, 16, 3) - _t21*(-_hc0[13]*_t75 - _hc0[14]*_t76 + (0.56e2 / 0.9e1)*_t17*_t48*_t5 + (0.4e1 / 0.9e1)*_t2*_t3*_t50*_t7 - _t21*(_hc0[33]*_t45 + _hc0[34]*_t46 - _t21*(-_hc0[68]*_t9 - _hc0[69]*_t21) - _t78*_t9) - _t79*_t9) - 0.280e3 / 0.9e1*_t22*_t42*_t5 + _t28*_t74 + _t39*_t49*_t5 - _t41*_t57 - _t9*(-_hc0[10]*_t75 - _hc0[13]*_t76 + (0.56e2 / 0.9e1)*_t17*_t47*_t5 + (0.4e1 / 0.9e1)*_t2*_t3*_t48*_t7 - _t21*_t79 - _t9*(_hc0[24]*_t45 + _hc0[30]*_t46 - _t21*_t77 - _t9*(-_hc0[49]*_t9 - _hc0[59]*_t21))));
  const double d4F_dna3_dgaa = (0.14e2 / 0.3e1)*_hc0[10]*_t54 - _t12*_t22*_t80 + (0.14e2 / 0.3e1)*_t13*_t17 - _t24*_t4*_t64 + (0.1e1 / 0.3e1)*_t25*_t30 - _t40*_t62 + na*(-0.140e3 / 0.27e2*_hc0[10]/xc_powr(na, 17, 3) + (0.28e2 / 0.9e1)*_t12*_t17*_t22 - 0.140e3 / 0.27e2*_t13*_t42 + (0.56e2 / 0.9e1)*_t17*_t5*_t62 + (0.4e1 / 0.9e1)*_t2*_t3*_t64*_t7 - _t21*(_hc0[13]*_t81 + _hc0[30]*_t55 + _hc0[33]*_t82 - _t21*(-_hc0[33]*_t59 - _hc0[65]*_t26 - _hc0[68]*_t61) - _t48*_t59 - _t83*_t9) - 0.7e1 / 0.27e2*_t30*_t54 - _t49*_t59 - _t9*(_hc0[10]*_t81 + _hc0[24]*_t55 + _hc0[30]*_t82 - _t21*_t83 - _t47*_t59 - _t9*(-_hc0[24]*_t59 - _hc0[49]*_t26 - _hc0[59]*_t61)));
  const double d4F_dna2_dgaa2 = (0.2e1 / 0.3e1)*_hc0[3]*_t35*_t7 - _t14*_t66 - _t15*_t4*_t67 - _t33*_t52 + na*(-_t12*_t53*_t62 - 0.7e1 / 0.9e1*_t17*_t36 - _t21*((0.1e1 / 0.3e1)*_hc0[13]*_t35*_t7 - _t21*(-_hc0[33]*_t65 + (0.1e1 / 0.4e1)*_hc0[65]*_t31*_t33) - _t33*_t63 - _t85*_t9) + (0.1e1 / 0.3e1)*_t22*_t35*_t7 + _t33*_t56 + _t45*_t66 + _t46*_t67 - _t9*((0.1e1 / 0.3e1)*_hc0[10]*_t35*_t7 - _t21*_t85 - _t33*_t60 - _t84*_t9));
  const double d4F_dna_dgaa3 = _t73 + na*((0.1e1 / 0.2e1)*_hc0[10]*_t25*_t68 - _t21*(_hc0[13]*_t86 - _hc0[30]*_t87 + _t85*_t88) - 0.1e1 / 0.2e1*_t7*_t70 - _t72*_t80 - _t89*_t9);
  const double d4F_dgaa4 = na*((0.9e1 / 0.16e2)*_hc0[10]*_t31/(gaa * gaa * gaa) - 0.15e2 / 0.16e2*_hc0[3]*_t6/xc_powr(gaa, 7, 2) - 0.3e1 / 0.4e1*_t35*_t6*_t66 + _t88*_t89);
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
  const double _t2 = xc_powr(_t1, -1, 3);
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = (0.1e1 / (M_CBRTPI));
  const double _t5 = _t3*_t4;
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
  const double _t7 = xc_powr(_t1, -4, 3);
  const double _t8 = gaa + 0.2e1*gab + gbb;
  const double _t9 = xc_powr(_t8, 1, 2);
  double _hc0[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(f_ccdf_k, _KMAX)(p, _t2*_t6, 0, _t7*_t9, 0, 0, _hc0);
  const double zk = _hc0[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t11 = (0.1e1 / 0.6e1)*_t7;
  const double _t12 = xc_powr(_t1, -7, 3);
  const double _t14 = (0.4e1 / 0.3e1)*_t9;
  const double _t16 = (0.1e1 / _t9);
  const double _t10 = _hc0[5]*_t5;
  const double _t13 = _hc0[3]*_t12;
  const double _t15 = _hc0[0] + _t1*(-_t10*_t11 - _t13*_t14);
  const double _t17 = _hc0[3]*_t16;
  const double _t18 = _t17*_t2;
  const double _t19 = (0.1e1 / 0.2e1)*_t18;
  const double dF_dna = _t15;
  const double dF_dnb = _t15;
  const double dF_dgaa = _t19;
  const double dF_dgab = _t18;
  const double dF_dgbb = _t19;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t20 = (0.1e1 / 0.3e1)*_t7;
  const double _t21 = (0.8e1 / 0.3e1)*_t9;
  const double _t22 = (0.2e1 / 0.9e1)*_t12;
  const double _t24 = xc_powr(_t1, -10, 3);
  const double _t25 = (0.28e2 / 0.9e1)*_t24;
  const double _t26 = _t11*_t5;
  const double _t27 = _t12*_t14;
  const double _t32 = xc_powr(_t1, -11, 3);
  const double _t36 = (0.1e1 / 0.12e2)*_t5;
  const double _t37 = xc_powr(_t1, -8, 3);
  const double _t42 = (0.1e1 / 0.6e1)*_t5;
  const double _t45 = (0.1e1 / _t8);
  const double _t48 = xc_powr(_t8, -3, 2);
  const double _t54 = xc_powr(_t1, -5, 3);
  const double _t23 = _hc0[3]*_t9;
  const double _t28 = -_hc0[18]*_t27 - _hc0[20]*_t26;
  const double _t29 = -_hc0[11]*_t27 - _hc0[18]*_t26;
  const double _t30 = _t1*(_t10*_t22 + _t23*_t25 - _t26*_t28 - _t27*_t29) - _t10*_t20 - _t13*_t21;
  const double _t31 = _t17*_t7;
  const double _t33 = _hc0[11]*_t32;
  const double _t34 = (0.2e1 / 0.3e1)*_t33;
  const double _t35 = _t12*_t17;
  const double _t38 = _hc0[18]*_t37;
  const double _t39 = _t16*_t38;
  const double _t40 = _t1*(-_t34 - 0.2e1 / 0.3e1*_t35 - _t36*_t39) + (0.1e1 / 0.2e1)*_t31;
  const double _t41 = (0.4e1 / 0.3e1)*_t33;
  const double _t43 = (0.4e1 / 0.3e1)*_t35 + _t39*_t42 + _t41;
  const double _t44 = -_t1*_t43 + _t31;
  const double _t46 = _hc0[11]*_t45;
  const double _t47 = _t37*_t46;
  const double _t49 = _hc0[3]*_t48;
  const double _t50 = _t49*_t7;
  const double _t51 = (0.1e1 / 0.4e1)*_t47 - 0.1e1 / 0.4e1*_t50;
  const double _t52 = _t1*_t51;
  const double _t53 = (0.1e1 / 0.2e1)*_t47 - 0.1e1 / 0.2e1*_t50;
  const double _t55 = _t46*_t54;
  const double _t56 = _t2*_t49;
  const double d2F_dna2 = _t30;
  const double d2F_dna_dnb = _t30;
  const double d2F_dnb2 = _t30;
  const double d2F_dna_dgaa = _t40;
  const double d2F_dna_dgab = _t44;
  const double d2F_dna_dgbb = _t40;
  const double d2F_dnb_dgaa = _t40;
  const double d2F_dnb_dgab = _t44;
  const double d2F_dnb_dgbb = _t40;
  const double d2F_dgaa2 = _t52;
  const double d2F_dgaa_dgab = _t1*_t53;
  const double d2F_dgaa_dgbb = _t52;
  const double d2F_dgab2 = _t55 - _t56;
  const double d2F_dgab_dgbb = (0.1e1 / 0.2e1)*_t55 - 0.1e1 / 0.2e1*_t56;
  const double d2F_dgbb2 = _t52;
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
  const double _t57 = (0.2e1 / 0.3e1)*_t12;
  const double _t58 = (0.28e2 / 0.3e1)*_t24;
  const double _t59 = _t6*_t7;
  const double _t61 = 0.4e1*_t12;
  const double _t62 = (0.14e2 / 0.27e2)*_t24;
  const double _t63 = xc_powr(_t1, -13, 3);
  const double _t64 = (0.280e3 / 0.27e2)*_t63;
  const double _t65 = _t22*_t5;
  const double _t66 = _t25*_t9;
  const double _t73 = xc_powr(_t1, -14, 3);
  const double _t75 = (0.14e2 / 0.9e1)*_t24;
  const double _t76 = (0.1e1 / 0.9e1)*_t5;
  const double _t79 = _t12*_t16;
  const double _t80 = (0.2e1 / 0.3e1)*_t79;
  const double _t81 = (0.2e1 / 0.3e1)*_t32;
  const double _t83 = _t16*_t37;
  const double _t91 = (0.1e1 / 0.3e1)*_t5;
  const double _t93 = (0.4e1 / 0.3e1)*_t79;
  const double _t94 = (0.4e1 / 0.3e1)*_t32;
  const double _t102 = _t48*_t7;
  const double _t103 = (0.1e1 / 0.4e1)*_t102;
  const double _t107 = (0.1e1 / 0.2e1)*_t102;
  const double _t115 = xc_powi(_t1, -5);
  const double _t117 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t118 = _t117*_t45;
  const double _t122 = (0.1e1 / (_t8 * _t8));
  const double _t124 = (0.1e1 / 0.4e1)*_t37;
  const double _t125 = xc_powr(_t8, -5, 2);
  const double _t132 = (0.1e1 / 0.2e1)*_t7;
  const double _t133 = _t132*_t16;
  const double _t142 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t60 = _t29*_t9;
  const double _t67 = -_hc0[53]*_t27 - _hc0[55]*_t26;
  const double _t68 = -_hc0[46]*_t27 - _hc0[53]*_t26;
  const double _t69 = _hc0[18]*_t66 + _hc0[20]*_t65 - _t26*_t67 - _t27*_t68;
  const double _t70 = -_hc0[30]*_t27 - _hc0[46]*_t26;
  const double _t71 = _hc0[11]*_t66 + _hc0[18]*_t65 - _t26*_t68 - _t27*_t70;
  const double _t72 = _t1*(-_t10*_t62 + (0.4e1 / 0.9e1)*_t12*_t28*_t3*_t4 - _t23*_t64 + (0.56e2 / 0.9e1)*_t24*_t29*_t9 - _t26*_t69 - _t27*_t71) + _t10*_t57 + _t23*_t58 - _t28*_t59 - _t60*_t61;
  const double _t74 = _hc0[11]*_t73;
  const double _t77 = _hc0[18]*_t16;
  const double _t78 = _t32*_t77;
  const double _t82 = _hc0[46]*_t81;
  const double _t84 = _hc0[53]*_t83;
  const double _t85 = -_hc0[18]*_t80 - _t36*_t84 - _t82;
  const double _t86 = _hc0[30]*_t81;
  const double _t87 = _hc0[46]*_t36;
  const double _t88 = -_hc0[11]*_t80 - _t83*_t87 - _t86;
  const double _t89 = _t1*(_t17*_t75 - _t26*_t85 - _t27*_t88 - _t29*_t80 + (0.14e2 / 0.9e1)*_t74 + _t76*_t78) - _t43;
  const double _t90 = (0.8e1 / 0.3e1)*_t33;
  const double _t92 = _t5*_t78;
  const double _t95 = _hc0[46]*_t94;
  const double _t96 = -_hc0[18]*_t93 - _t42*_t84 - _t95;
  const double _t97 = _hc0[30]*_t94;
  const double _t98 = _hc0[46]*_t42;
  const double _t99 = -_hc0[11]*_t93 - _t83*_t98 - _t97;
  const double _t100 = _t1*(_t17*_t25 - _t26*_t96 - _t27*_t99 - _t29*_t93 + (0.28e2 / 0.9e1)*_t74 + (0.2e1 / 0.9e1)*_t92) - 0.8e1 / 0.3e1*_t35 - _t39*_t91 - _t90;
  const double _t101 = _t34*_t45;
  const double _t104 = -_hc0[18]*_t103 + (0.1e1 / 0.4e1)*_hc0[46]*_t37*_t45;
  const double _t105 = -_hc0[11]*_t103 + (0.1e1 / 0.4e1)*_hc0[30]*_t37*_t45;
  const double _t106 = _t1*((0.1e1 / 0.3e1)*_hc0[3]*_t12*_t48 - _t101 - _t104*_t26 - _t105*_t27) + _t51;
  const double _t108 = -_hc0[11]*_t107 + (0.1e1 / 0.2e1)*_hc0[30]*_t37*_t45;
  const double _t109 = -_hc0[18]*_t107 + (0.1e1 / 0.2e1)*_hc0[46]*_t37*_t45;
  const double _t110 = -0.2e1 / 0.3e1*_hc0[3]*_t12*_t48;
  const double _t111 = _t41*_t45;
  const double _t112 = _t110 + _t111;
  const double _t113 = _t1*(-_t108*_t27 - _t109*_t26 - _t112) + _t53;
  const double _t114 = -0.4e1 / 0.3e1*_hc0[3]*_t12*_t48;
  const double _t116 = _hc0[30]*_t115*_t16;
  const double _t119 = -0.1e1 / 0.6e1*_hc0[18]*_t3*_t37*_t4*_t48 + _t111 + _t114 + (0.4e1 / 0.3e1)*_t116 + _t118*_t98;
  const double _t120 = -_t1*_t119 + _t47 - _t50;
  const double _t121 = _t1*((0.1e1 / 0.12e2)*_hc0[18]*_t3*_t37*_t4*_t48 - _t101 - _t110 - 0.2e1 / 0.3e1*_t116 - _t118*_t87) + _t53;
  const double _t123 = _hc0[11]*_t122;
  const double _t126 = _hc0[3]*_t125;
  const double _t127 = _t126*_t7;
  const double _t128 = _t105*_t16;
  const double _t129 = _t128*_t7;
  const double _t130 = -_t123*_t124 + (0.3e1 / 0.8e1)*_t127 + (0.1e1 / 0.2e1)*_t129;
  const double _t131 = _t1*_t130;
  const double _t134 = _t123*_t37;
  const double _t135 = (0.3e1 / 0.4e1)*_t127;
  const double _t136 = -0.1e1 / 0.2e1*_t134 + _t135;
  const double _t137 = _t108*_t133 + _t136;
  const double _t138 = _hc0[30]*_t48;
  const double _t139 = _t117*_t138;
  const double _t140 = (0.3e1 / 0.2e1)*_t127 - 0.3e1 / 0.2e1*_t134 + (0.1e1 / 0.2e1)*_t139;
  const double _t141 = -0.3e1 / 0.4e1*_t134 + _t135 + (0.1e1 / 0.4e1)*_t139;
  const double _t143 = _t138*_t142;
  const double _t144 = _t123*_t54;
  const double _t145 = _t126*_t2;
  const double d3F_dna3 = _t72;
  const double d3F_dna2_dnb = _t72;
  const double d3F_dna_dnb2 = _t72;
  const double d3F_dnb3 = _t72;
  const double d3F_dna2_dgaa = _t89;
  const double d3F_dna2_dgab = _t100;
  const double d3F_dna2_dgbb = _t89;
  const double d3F_dna_dnb_dgaa = _t89;
  const double d3F_dna_dnb_dgab = _t100;
  const double d3F_dna_dnb_dgbb = _t89;
  const double d3F_dnb2_dgaa = _t89;
  const double d3F_dnb2_dgab = _t100;
  const double d3F_dnb2_dgbb = _t89;
  const double d3F_dna_dgaa2 = _t106;
  const double d3F_dna_dgaa_dgab = _t113;
  const double d3F_dna_dgaa_dgbb = _t106;
  const double d3F_dna_dgab2 = _t120;
  const double d3F_dna_dgab_dgbb = _t121;
  const double d3F_dna_dgbb2 = _t106;
  const double d3F_dnb_dgaa2 = _t106;
  const double d3F_dnb_dgaa_dgab = _t113;
  const double d3F_dnb_dgaa_dgbb = _t106;
  const double d3F_dnb_dgab2 = _t120;
  const double d3F_dnb_dgab_dgbb = _t121;
  const double d3F_dnb_dgbb2 = _t106;
  const double d3F_dgaa3 = _t131;
  const double d3F_dgaa2_dgab = _t1*_t137;
  const double d3F_dgaa2_dgbb = _t131;
  const double d3F_dgaa_dgab2 = _t1*_t140;
  const double d3F_dgaa_dgab_dgbb = _t1*_t141;
  const double d3F_dgaa_dgbb2 = _t131;
  const double d3F_dgab3 = _t143 - 0.3e1*_t144 + 0.3e1*_t145;
  const double d3F_dgab2_dgbb = (0.1e1 / 0.2e1)*_t143 - 0.3e1 / 0.2e1*_t144 + (0.3e1 / 0.2e1)*_t145;
  const double d3F_dgab_dgbb2 = _t128*_t2 - 0.1e1 / 0.2e1*_t144 + (0.3e1 / 0.4e1)*_t145;
  const double d3F_dgbb3 = _t131;
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
  const double _t148 = xc_powr(_t1, -16, 3);
  const double _t149 = _t5*_t62;
  const double _t150 = _t64*_t9;
  const double _t155 = _t61*_t9;
  const double _t159 = (0.14e2 / 0.9e1)*_t73;
  const double _t160 = _t16*_t75;
  const double _t161 = _t16*_t32;
  const double _t163 = _t36*_t83;
  const double _t166 = (0.28e2 / 0.9e1)*_t73;
  const double _t167 = _t16*_t25;
  const double _t168 = (0.2e1 / 0.9e1)*_t5;
  const double _t169 = _t42*_t83;
  const double _t174 = _t37*_t45;
  const double _t175 = (0.1e1 / 0.4e1)*_t174;
  const double _t179 = _t12*_t21;
  const double _t180 = _t20*_t5;
  const double _t186 = (0.1e1 / 0.2e1)*_t174;
  const double _t193 = xc_powi(_t1, -6);
  const double _t195 = (0.8e1 / 0.3e1)*_t79;
  const double _t196 = _t115*_t16;
  const double _t198 = _t118*_t42;
  const double _t202 = _t118*_t36;
  const double _t206 = _t125*_t7;
  const double _t207 = (0.3e1 / 0.8e1)*_t206;
  const double _t208 = _t122*_t124;
  const double _t211 = (0.3e1 / 0.4e1)*_t206;
  const double _t213 = _t122*_t37;
  const double _t214 = (0.1e1 / 0.2e1)*_t213;
  const double _t221 = _t117*_t48;
  const double _t222 = (0.1e1 / 0.2e1)*_t221;
  const double _t223 = (0.3e1 / 0.2e1)*_t206;
  const double _t224 = (0.3e1 / 0.2e1)*_t213;
  const double _t227 = (0.3e1 / 0.4e1)*_t213;
  const double _t228 = (0.1e1 / 0.4e1)*_t221;
  const double _t231 = _t45/xc_powr(_t1, 19, 3);
  const double _t237 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t146 = _t5*_t69;
  const double _t147 = _t71*_t9;
  const double _t151 = -_hc0[116]*_t27 - _hc0[123]*_t26;
  const double _t152 = -_hc0[100]*_t27 - _hc0[116]*_t26;
  const double _t153 = _hc0[46]*_t66 + _hc0[53]*_t65 - _t151*_t26 - _t152*_t27;
  const double _t154 = _t1*((0.140e3 / 0.81e2)*_t10*_t63 + _t146*_t57 + _t147*_t58 + (0.3640e4 / 0.81e2)*_t148*_t23 - _t26*(-_hc0[18]*_t150 - _hc0[20]*_t149 + (0.4e1 / 0.9e1)*_t12*_t3*_t4*_t67 - _t153*_t27 + (0.56e2 / 0.9e1)*_t24*_t68*_t9 - _t26*(_hc0[53]*_t66 + _hc0[55]*_t65 - _t151*_t27 - _t26*(-_hc0[123]*_t27 - _hc0[125]*_t26))) - _t27*(-_hc0[11]*_t150 - _hc0[18]*_t149 + (0.4e1 / 0.9e1)*_t12*_t3*_t4*_t68 - _t153*_t26 + (0.56e2 / 0.9e1)*_t24*_t70*_t9 - _t27*(_hc0[30]*_t66 + _hc0[46]*_t65 - _t152*_t26 - _t27*(-_hc0[100]*_t26 - _hc0[70]*_t27))) - _t28*_t5*_t75 - 0.280e3 / 0.9e1*_t60*_t63) - 0.56e2 / 0.27e2*_t10*_t24 - 0.16e2 / 0.3e1*_t12*_t147 + (0.16e2 / 0.9e1)*_t12*_t28*_t3*_t4 - 0.2e1 / 0.3e1*_t146*_t7 - 0.1120e4 / 0.27e2*_t23*_t63 + (0.224e3 / 0.9e1)*_t24*_t29*_t9;
  const double _t156 = _hc0[11]/xc_powr(_t1, 17, 3);
  const double _t157 = _t5*_t77;
  const double _t158 = _t157*_t73;
  const double _t162 = _hc0[53]*_t161;
  const double _t164 = -_hc0[100]*_t81 - _hc0[116]*_t163 - _hc0[46]*_t80;
  const double _t165 = _t1*((0.4e1 / 0.9e1)*_t12*_t3*_t4*_t85 - 0.140e3 / 0.27e2*_t156 - 0.7e1 / 0.27e2*_t158 + (0.28e2 / 0.9e1)*_t16*_t24*_t29 - 0.140e3 / 0.27e2*_t17*_t63 + (0.56e2 / 0.9e1)*_t24*_t88*_t9 - _t26*(_hc0[18]*_t160 + _hc0[46]*_t159 + _t162*_t76 - _t164*_t27 - _t26*(-_hc0[116]*_t81 - _hc0[123]*_t163 - _hc0[53]*_t80) - _t68*_t80) - _t27*(_hc0[11]*_t160 + _hc0[30]*_t159 + _hc0[46]*_t161*_t76 - _t164*_t26 - _t27*(-_hc0[100]*_t163 - _hc0[30]*_t80 - _hc0[70]*_t81) - _t70*_t80) - _t71*_t80) - _t155*_t88 + (0.14e2 / 0.3e1)*_t17*_t24 - 0.2e1*_t29*_t79 - _t59*_t85 + (0.14e2 / 0.3e1)*_t74 + (0.1e1 / 0.3e1)*_t92;
  const double _t170 = -_hc0[100]*_t94 - _hc0[116]*_t169 - _hc0[46]*_t93;
  const double _t171 = _t1*((0.4e1 / 0.9e1)*_t12*_t3*_t4*_t96 - 0.280e3 / 0.27e2*_t156 - 0.14e2 / 0.27e2*_t158 + (0.56e2 / 0.9e1)*_t16*_t24*_t29 - _t17*_t64 + (0.56e2 / 0.9e1)*_t24*_t9*_t99 - _t26*(_hc0[18]*_t167 + _hc0[46]*_t166 + _t162*_t168 - _t170*_t27 - _t26*(-_hc0[116]*_t94 - _hc0[123]*_t169 - _hc0[53]*_t93) - _t68*_t93) - _t27*(_hc0[11]*_t167 + _hc0[30]*_t166 + _hc0[46]*_t161*_t168 - _t170*_t26 - _t27*(-_hc0[100]*_t169 - _hc0[30]*_t93 - _hc0[70]*_t94) - _t70*_t93) - _t71*_t93) - _t155*_t99 + _t157*_t81 - _t16*_t29*_t61 + _t17*_t58 - _t59*_t96 + (0.28e2 / 0.3e1)*_t74;
  const double _t172 = _t88*_t93;
  const double _t173 = _t45*_t82;
  const double _t176 = _hc0[100]*_t175 - _hc0[46]*_t103;
  const double _t177 = _t45*_t86;
  const double _t178 = (0.1e1 / 0.4e1)*_hc0[70]*_t37*_t45 - 0.1e1 / 0.4e1*_t138*_t7;
  const double _t181 = _t1*(_t104*_t65 + _t105*_t66 + (0.1e1 / 0.3e1)*_t12*_t29*_t48 + _t159*_t46 - _t172 - 0.7e1 / 0.9e1*_t24*_t49 - _t26*((0.1e1 / 0.3e1)*_hc0[18]*_t12*_t48 - _t173 - _t176*_t27 - _t26*(_hc0[116]*_t175 - _hc0[53]*_t103)) - _t27*((0.1e1 / 0.3e1)*_hc0[11]*_t12*_t48 - _t176*_t26 - _t177 - _t178*_t27)) - _t104*_t180 - _t105*_t179 - _t112;
  const double _t182 = _t45*_t90;
  const double _t183 = -0.28e2 / 0.9e1*_hc0[11]*_t45*_t73;
  const double _t184 = -0.2e1 / 0.3e1*_hc0[11]*_t12*_t48;
  const double _t185 = _t45*_t97;
  const double _t187 = _hc0[100]*_t186 - _hc0[46]*_t107;
  const double _t188 = (0.1e1 / 0.2e1)*_hc0[70]*_t37*_t45 - _t132*_t138;
  const double _t189 = -0.2e1 / 0.3e1*_hc0[18]*_t12*_t48;
  const double _t190 = _t45*_t95;
  const double _t191 = -0.2e1 / 0.3e1*_t12*_t29*_t48 + _t172 + _t49*_t75 + _t80*_t99;
  const double _t192 = _t1*((0.28e2 / 0.9e1)*_t108*_t24*_t9 + (0.2e1 / 0.9e1)*_t109*_t12*_t3*_t4 - _t183 - _t191 - _t26*(-_t187*_t27 - _t189 - _t190 - _t26*(_hc0[116]*_t186 - _hc0[53]*_t107)) - _t27*(-_t184 - _t185 - _t187*_t26 - _t188*_t27)) - _t108*_t179 - _t109*_t180 - _t114 - _t182;
  const double _t194 = _hc0[18]*_t32*_t48;
  const double _t197 = _hc0[100]*_t196;
  const double _t199 = (0.4e1 / 0.3e1)*_hc0[70];
  const double _t200 = (0.1e1 / 0.3e1)*_hc0[18]*_t3*_t37*_t4*_t48 + (0.8e1 / 0.3e1)*_hc0[3]*_t12*_t48 - _hc0[46]*_t118*_t91 + _t1*((0.28e2 / 0.9e1)*_hc0[30]*_t16*_t193 + (0.2e1 / 0.9e1)*_hc0[46]*_t115*_t3*_t4*_t45 + (0.4e1 / 0.3e1)*_t12*_t29*_t48 - _t168*_t194 - _t183 - _t195*_t99 - _t25*_t49 - _t26*(-_hc0[116]*_t198 + (0.4e1 / 0.3e1)*_hc0[18]*_t12*_t48 + (0.1e1 / 0.6e1)*_hc0[53]*_t3*_t37*_t4*_t48 - _t190 - 0.4e1 / 0.3e1*_t197) - _t27*(-_hc0[100]*_t198 + (0.4e1 / 0.3e1)*_hc0[11]*_t12*_t48 + (0.1e1 / 0.6e1)*_hc0[46]*_t3*_t37*_t4*_t48 - _t185 - _t196*_t199)) - 0.8e1 / 0.3e1*_t116 - _t182;
  const double _t201 = (0.2e1 / 0.3e1)*_hc0[70];
  const double _t203 = _t1*((0.14e2 / 0.9e1)*_hc0[11]*_t45*_t73 + (0.14e2 / 0.9e1)*_hc0[30]*_t16*_t193 + (0.1e1 / 0.9e1)*_hc0[46]*_t115*_t3*_t4*_t45 - _t191 - _t194*_t76 - _t26*(-_hc0[116]*_t202 + (0.1e1 / 0.12e2)*_hc0[53]*_t3*_t37*_t4*_t48 - _t173 - _t189 - 0.2e1 / 0.3e1*_t197) - _t27*(-_hc0[100]*_t202 + (0.1e1 / 0.12e2)*_hc0[46]*_t3*_t37*_t4*_t48 - _t177 - _t184 - _t196*_t201)) - _t119;
  const double _t204 = _t125*_t13;
  const double _t205 = _t12*_t128;
  const double _t209 = _hc0[11]*_t207 - _hc0[30]*_t208 + _t133*_t178;
  const double _t210 = _t1*((0.1e1 / 0.2e1)*_hc0[11]*_t122*_t32 - 0.1e1 / 0.2e1*_t204 - 0.2e1*_t205 - _t209*_t27 - _t26*(_hc0[18]*_t207 - _hc0[46]*_t208 + _t133*_t176)) + _t130;
  const double _t212 = _hc0[11]*_t211;
  const double _t215 = -_hc0[30]*_t214 + _t133*_t188 + _t212;
  const double _t216 = _hc0[18]*_t211;
  const double _t217 = _t204 + (0.4e1 / 0.3e1)*_t205;
  const double _t218 = _t1*(_hc0[11]*_t122*_t32 - _t108*_t93 - _t215*_t27 - _t217 - _t26*(-_hc0[46]*_t214 + _t133*_t187 + _t216)) + _t137;
  const double _t219 = 0.2e1*_t204;
  const double _t220 = _t115*_t138;
  const double _t225 = _hc0[11]*_t223 - _hc0[30]*_t224 + _hc0[70]*_t222;
  const double _t226 = _t1*((0.8e1 / 0.3e1)*_hc0[11]*_t122*_t32 - _t108*_t195 - _t219 - 0.2e1 / 0.3e1*_t220 - _t225*_t27 - _t26*(_hc0[100]*_t222 + _hc0[18]*_t223 - _hc0[46]*_t224)) + _t140;
  const double _t229 = -_hc0[30]*_t227 + _hc0[70]*_t228 + _t212;
  const double _t230 = _t1*((0.4e1 / 0.3e1)*_hc0[11]*_t122*_t32 - _t108*_t80 - _t217 - 0.1e1 / 0.3e1*_t220 - _t229*_t27 - _t26*(_hc0[100]*_t228 - _hc0[46]*_t227 + _t216)) + _t141;
  const double _t232 = _hc0[100]*_t148*_t48;
  const double _t233 = _t125*_t38;
  const double _t234 = _t1*(0.4e1*_hc0[11]*_t122*_t32 + (0.1e1 / 0.2e1)*_hc0[46]*_t117*_t122*_t3*_t4 - _t199*_t231 - 0.4e1*_t204 - _t232*_t42 - _t233*_t6) + 0.3e1*_t127 - 0.3e1*_t134 + _t139;
  const double _t235 = _t1*(0.2e1*_hc0[11]*_t122*_t32 - _hc0[18]*_t124*_t125*_t5 + (0.1e1 / 0.4e1)*_hc0[46]*_t117*_t122*_t3*_t4 - _t201*_t231 - _t219 - _t232*_t36) + _t140;
  const double _t236 = _t1*((0.2e1 / 0.3e1)*_hc0[11]*_t122*_t32 + (0.1e1 / 0.12e2)*_hc0[46]*_t117*_t122*_t3*_t4 - _t169*_t176 - _t178*_t94 - _t217 - 0.1e1 / 0.8e1*_t233*_t5) + _t129 + _t136;
  const double _t238 = _hc0[11]*_t237;
  const double _t239 = _t238*_t37;
  const double _t240 = _hc0[3]/xc_powr(_t8, 7, 2);
  const double _t241 = _t240*_t7;
  const double _t242 = _t16*_t209;
  const double _t243 = _t1*(-0.3e1 / 0.4e1*_t102*_t105 + _t132*_t242 + (0.9e1 / 0.16e2)*_t239 - 0.15e2 / 0.16e2*_t241);
  const double _t244 = _t102*_t108;
  const double _t245 = _t105*_t107 + (0.15e2 / 0.8e1)*_t241;
  const double _t246 = (0.15e2 / 0.4e1)*_t241;
  const double _t247 = _hc0[30]*_t125;
  const double _t248 = _t117*_t247;
  const double _t249 = _hc0[70]*_t122;
  const double _t250 = _t148*_t249;
  const double _t251 = _t249*_t63;
  const double _t252 = _t238*_t54;
  const double _t253 = _t2*_t240;
  const double _t254 = _t142*_t247;
  const double _t255 = _t105*_t2*_t48;
  const double d4F_dna4 = _t154;
  const double d4F_dna3_dnb = _t154;
  const double d4F_dna2_dnb2 = _t154;
  const double d4F_dna_dnb3 = _t154;
  const double d4F_dnb4 = _t154;
  const double d4F_dna3_dgaa = _t165;
  const double d4F_dna3_dgab = _t171;
  const double d4F_dna3_dgbb = _t165;
  const double d4F_dna2_dnb_dgaa = _t165;
  const double d4F_dna2_dnb_dgab = _t171;
  const double d4F_dna2_dnb_dgbb = _t165;
  const double d4F_dna_dnb2_dgaa = _t165;
  const double d4F_dna_dnb2_dgab = _t171;
  const double d4F_dna_dnb2_dgbb = _t165;
  const double d4F_dnb3_dgaa = _t165;
  const double d4F_dnb3_dgab = _t171;
  const double d4F_dnb3_dgbb = _t165;
  const double d4F_dna2_dgaa2 = _t181;
  const double d4F_dna2_dgaa_dgab = _t192;
  const double d4F_dna2_dgaa_dgbb = _t181;
  const double d4F_dna2_dgab2 = _t200;
  const double d4F_dna2_dgab_dgbb = _t203;
  const double d4F_dna2_dgbb2 = _t181;
  const double d4F_dna_dnb_dgaa2 = _t181;
  const double d4F_dna_dnb_dgaa_dgab = _t192;
  const double d4F_dna_dnb_dgaa_dgbb = _t181;
  const double d4F_dna_dnb_dgab2 = _t200;
  const double d4F_dna_dnb_dgab_dgbb = _t203;
  const double d4F_dna_dnb_dgbb2 = _t181;
  const double d4F_dnb2_dgaa2 = _t181;
  const double d4F_dnb2_dgaa_dgab = _t192;
  const double d4F_dnb2_dgaa_dgbb = _t181;
  const double d4F_dnb2_dgab2 = _t200;
  const double d4F_dnb2_dgab_dgbb = _t203;
  const double d4F_dnb2_dgbb2 = _t181;
  const double d4F_dna_dgaa3 = _t210;
  const double d4F_dna_dgaa2_dgab = _t218;
  const double d4F_dna_dgaa2_dgbb = _t210;
  const double d4F_dna_dgaa_dgab2 = _t226;
  const double d4F_dna_dgaa_dgab_dgbb = _t230;
  const double d4F_dna_dgaa_dgbb2 = _t210;
  const double d4F_dna_dgab3 = _t234;
  const double d4F_dna_dgab2_dgbb = _t235;
  const double d4F_dna_dgab_dgbb2 = _t236;
  const double d4F_dna_dgbb3 = _t210;
  const double d4F_dnb_dgaa3 = _t210;
  const double d4F_dnb_dgaa2_dgab = _t218;
  const double d4F_dnb_dgaa2_dgbb = _t210;
  const double d4F_dnb_dgaa_dgab2 = _t226;
  const double d4F_dnb_dgaa_dgab_dgbb = _t230;
  const double d4F_dnb_dgaa_dgbb2 = _t210;
  const double d4F_dnb_dgab3 = _t234;
  const double d4F_dnb_dgab2_dgbb = _t235;
  const double d4F_dnb_dgab_dgbb2 = _t236;
  const double d4F_dnb_dgbb3 = _t210;
  const double d4F_dgaa4 = _t243;
  const double d4F_dgaa3_dgab = _t1*((0.9e1 / 0.8e1)*_hc0[11]*_t237*_t37 + (0.1e1 / 0.2e1)*_t16*_t215*_t7 - 0.1e1 / 0.2e1*_t244 - _t245);
  const double d4F_dgaa3_dgbb = _t243;
  const double d4F_dgaa2_dgab2 = _t1*((0.5e1 / 0.2e1)*_hc0[11]*_t237*_t37 + (0.1e1 / 0.2e1)*_t16*_t225*_t7 - _t244 - _t246 - 0.1e1 / 0.4e1*_t248);
  const double d4F_dgaa2_dgab_dgbb = _t1*((0.5e1 / 0.4e1)*_hc0[11]*_t237*_t37 + (0.1e1 / 0.2e1)*_t16*_t229*_t7 - 0.1e1 / 0.4e1*_t244 - _t245 - 0.1e1 / 0.8e1*_t248);
  const double d4F_dgaa2_dgbb2 = _t243;
  const double d4F_dgaa_dgab3 = _t1*((0.15e2 / 0.2e1)*_t239 - 0.15e2 / 0.2e1*_t241 - 0.3e1*_t248 + (0.1e1 / 0.2e1)*_t250);
  const double d4F_dgaa_dgab2_dgbb = _t1*((0.15e2 / 0.4e1)*_t239 - _t246 - 0.3e1 / 0.2e1*_t248 + (0.1e1 / 0.4e1)*_t250);
  const double d4F_dgaa_dgab_dgbb2 = _t1*((0.7e1 / 0.4e1)*_hc0[11]*_t237*_t37 + (0.1e1 / 0.2e1)*_t178*_t37*_t45 - _t245 - 0.1e1 / 0.2e1*_t248);
  const double d4F_dgaa_dgbb3 = _t243;
  const double d4F_dgab4 = _t251 + 0.15e2*_t252 - 0.15e2*_t253 - 0.6e1*_t254;
  const double d4F_dgab3_dgbb = (0.1e1 / 0.2e1)*_t251 + (0.15e2 / 0.2e1)*_t252 - 0.15e2 / 0.2e1*_t253 - 0.3e1*_t254;
  const double d4F_dgab2_dgbb2 = (0.7e1 / 0.2e1)*_hc0[11]*_t237*_t54 + _t178*_t45*_t54 - 0.15e2 / 0.4e1*_t253 - _t254 - _t255;
  const double d4F_dgab_dgbb3 = _t2*_t242 + (0.9e1 / 0.8e1)*_t252 - 0.15e2 / 0.8e1*_t253 - 0.3e1 / 0.2e1*_t255;
  const double d4F_dgbb4 = _t243;
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