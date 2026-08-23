/*
  Generated from python/gga_exc/gga_x_beefvdw.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_beefvdw
*/

#ifndef _GGA_X_BEEFVDW_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_BEEFVDW_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_BEEFVDW_HELPER_BODIES
#include "gga_x_beefvdw.c"
#undef _GGA_X_BEEFVDW_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_BEEFVDW_HELPER_BODIES
#include "gga_x_beefvdw.c"
#undef _GGA_X_BEEFVDW_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_BEEFVDW_HELPER_BODIES
#include "gga_x_beefvdw.c"
#undef _GGA_X_BEEFVDW_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_BEEFVDW_HELPER_BODIES
#include "gga_x_beefvdw.c"
#undef _GGA_X_BEEFVDW_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_BEEFVDW_HELPER_BODIES
#include "gga_x_beefvdw.c"
#undef _GGA_X_BEEFVDW_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_beefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_beefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_beefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_beefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_beefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_beefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_beefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_beefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_beefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_beefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_BEEFVDW_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(beefvdw_xi_k, _KMAX)(const xc_func_type *p, double p_, double *out) {

  const double _t1 = p_ + 0.4e1;
  const double _t2 = (0.1e1 / _t1);
#if _KMAX >= 1
  const double _t3 = (0.1e1 / (_t1 * _t1));
#endif
#if _KMAX >= 2
  const double _t4 = (0.1e1 / (_t1 * _t1 * _t1));
#endif
#if _KMAX >= 3
  const double _t5 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
#endif

  const double f = 0.2e1*_t2*p_ - 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dp_ = 0.2e1*_t2 - 0.2e1*_t3*p_;
  out[1] = df_dp_;
#endif
#if _KMAX >= 2
  const double d2f_dp_2 = -0.4e1*_t3 + 0.4e1*_t4*p_;
  out[2] = d2f_dp_2;
#endif
#if _KMAX >= 3
  const double d3f_dp_3 = 0.12e2*_t4 - 0.12e2*_t5*p_;
  out[3] = d3f_dp_3;
#endif
#if _KMAX >= 4
  const double d4f_dp_4 = -0.48e2*_t5 + 0.48e2*p_/xc_powi(_t1, 5);
  out[4] = d4f_dp_4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(beefvdw_f_pf_k, _KMAX)(const xc_func_type *p, double x2, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t3 = _t1*_t2;
#if _KMAX >= 2
  const double _t32 = xc_powr(0.6e1, 2, 3);
  const double _t33 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t34 = _t32*_t33;
#endif
#if _KMAX >= 3
  const double _t38 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
#endif
#if _KMAX >= 4
  const double _t43 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t44 = _t1*_t43;
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(beefvdw_xi_k, _KMAX)(p, (0.1e1 / 0.24e2)*_t3*x2, _hc0);
  const double _t4 = ((_hc0[0]) * (_hc0[0]));
  const double _t5 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t6 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t7 = xc_powi((_hc0[0]), 5);
  const double _t8 = xc_powi((_hc0[0]), 6);
  const double _t9 = xc_powi((_hc0[0]), 7);
  const double _t10 = xc_powi((_hc0[0]), 8);
  const double _t11 = xc_powi((_hc0[0]), 9);
  const double _t12 = xc_powi((_hc0[0]), 10);
  const double _t13 = xc_powi((_hc0[0]), 11);
  const double _t14 = xc_powi((_hc0[0]), 12);
  const double _t15 = xc_powi((_hc0[0]), 13);
  const double _t16 = xc_powi((_hc0[0]), 14);
  const double _t17 = xc_powi((_hc0[0]), 15);
  const double _t18 = xc_powi((_hc0[0]), 16);
  const double _t19 = xc_powi((_hc0[0]), 17);
  const double _t20 = xc_powi((_hc0[0]), 18);
  const double _t21 = xc_powi((_hc0[0]), 19);
  const double _t22 = xc_powi((_hc0[0]), 20);
  const double _t23 = xc_powi((_hc0[0]), 21);
  const double _t24 = xc_powi((_hc0[0]), 22);
  const double _t25 = xc_powi((_hc0[0]), 23);
  const double _t26 = xc_powi((_hc0[0]), 24);
  const double _t27 = xc_powi((_hc0[0]), 25);
  const double _t28 = xc_powi((_hc0[0]), 26);
  const double _t29 = xc_powi((_hc0[0]), 27);
  const double _t30 = xc_powi((_hc0[0]), 28);
#if _KMAX >= 1
  const double _t31 = _hc0[1]*_t3;
#endif
#if _KMAX >= 2
  const double _t35 = _hc0[2]*_t34;
  const double _t36 = ((_hc0[1]) * (_hc0[1]));
  const double _t37 = _t34*_t36;
#endif
#if _KMAX >= 3
  const double _t39 = _hc0[3]*_t38;
  const double _t40 = _hc0[1]*_hc0[2]*_t38;
  const double _t41 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t42 = _t38*_t41;
#endif
#if _KMAX >= 4
  const double _t45 = _hc0[4]*_t44;
  const double _t46 = _hc0[1]*_hc0[3]*_t44;
  const double _t47 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t48 = _t44*_t47;
  const double _t49 = ((_hc0[2]) * (_hc0[2]));
  const double _t50 = _t44*_t49;
  const double _t51 = _hc0[2]*_t36*_t44;
#endif

  const double f = 4135.586188014654*xc_powi((_hc0[0]), 29) + 0.45041101205155826*_hc0[0] - 442.33229018433804*_t10 - 617.54786104528591*_t11 + 3783.5396407252406*_t12 + 2274.8997850816486*_t13 - 20148.245175625048*_t14 - 2810.2401805684603*_t15 + 70504.541869034001*_t16 - 10276.426607863832*_t17 - 168370.84139014117*_t18 + 56174.007979372669*_t19 + 279670.48856303055*_t20 - 129814.81812794985*_t21 - 323524.03136049327*_t22 + 180782.00670879148*_t23 + 255894.79526235332*_t24 - 161142.1539984628*_t25 - 132044.6618218215*_t26 + 90365.611108522804*_t27 + 40074.935854432384*_t28 - 29150.193011493262*_t29 - 5427.7774626371856*_t30 - 0.38916037779196816*_t4 + 0.52755620115589807*_t5 - 0.69459735177639015*_t6 - 7.2975787893717134*_t7 + 30.542034959315849*_t8 + 86.005730499279622*_t9 + 1.5817624751136816;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx2 = -0.032430031482664011*_hc0[0]*_t31 + 1576.4748503021835*_hc0[1]*_t1*_t11*_t2 + 1042.6624014957556*_hc0[1]*_t1*_t12*_t2 + 41127.649423603172*_hc0[1]*_t1*_t15*_t2 + 39789.922318722311*_hc0[1]*_t1*_t18*_t2 + 209752.86642227293*_hc0[1]*_t1*_t19*_t2 + 158184.25587019254*_hc0[1]*_t1*_t2*_t22 + 234570.22899049055*_hc0[1]*_t1*_t2*_t23 + 94130.844904711266*_hc0[1]*_t1*_t2*_t26 + 43414.513842301749*_hc0[1]*_t1*_t2*_t27 + 4997.1666438510401*_hc0[1]*_t1*_t2*_t30 + 0.065944525144487259*_hc0[1]*_t1*_t2*_t4 + 7.6355087398289623*_hc0[1]*_t1*_t2*_t7 + 25.085004728956559*_hc0[1]*_t1*_t2*_t8 + 0.01876712550214826*_hc0[1]*_t1*_t2 - 231.5804478919822*_t10*_t31 - 10074.122587812524*_t13*_t31 - 1522.2134311412492*_t14*_t31 - 6422.766629914895*_t16*_t31 - 112247.22759342744*_t17*_t31 - 102770.06435129362*_t20*_t31 - 269603.35946707777*_t21*_t31 - 154427.89758186019*_t24*_t31 - 132044.6618218215*_t25*_t31 - 32793.967137929918*_t28*_t31 - 6332.4070397433834*_t29*_t31 - 0.11576622529606502*_t31*_t5 - 1.5203289144524403*_t31*_t6 - 147.44409672811267*_t31*_t9;
  out[1] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dx22 = 0.005495377095373938*_hc0[0]*_t32*_t33*_t36 - 0.001351251311777667*_hc0[0]*_t35 + 65.686452095924309*_hc0[2]*_t11*_t32*_t33 + 43.444266728989817*_hc0[2]*_t12*_t32*_t33 + 1713.6520593167988*_hc0[2]*_t15*_t32*_t33 + 1657.9134299467628*_hc0[2]*_t18*_t32*_t33 + 8739.7027675947047*_hc0[2]*_t19*_t32*_t33 + 6591.0106612580221*_hc0[2]*_t22*_t32*_t33 + 9773.7595412704395*_hc0[2]*_t23*_t32*_t33 + 3922.1185376963026*_hc0[2]*_t26*_t32*_t33 + 1808.9380767625728*_hc0[2]*_t27*_t32*_t33 + 208.21527682712667*_hc0[2]*_t30*_t32*_t33 + 0.002747688547686969*_hc0[2]*_t32*_t33*_t4 + 0.31814619749287343*_hc0[2]*_t32*_t33*_t7 + 1.0452085303731899*_hc0[2]*_t32*_t33*_t8 + 0.00078196356258951078*_hc0[2]*_t32*_t33 + 591.1780688633188*_t10*_t32*_t33*_t36 - 9.6491853288325906*_t10*_t35 + 434.44266728989817*_t11*_t32*_t33*_t36 - 4617.3061860807402*_t12*_t37 - 419.7551078255218*_t13*_t35 - 761.1067155706246*_t13*_t37 + 22277.476771118385*_t14*_t32*_t33*_t36 - 63.425559630885381*_t14*_t35 - 3746.6138674503559*_t15*_t37 - 267.61527624645396*_t16*_t35 - 70154.517245892144*_t16*_t37 + 26526.614879148205*_t17*_t32*_t33*_t36 - 4676.9678163928093*_t17*_t35 + 148574.94704910999*_t18*_t32*_t33*_t36 - 77077.54826347022*_t19*_t37 - 4282.0860146372343*_t20*_t35 - 213435.99291143657*_t20*_t37 + 131820.21322516046*_t21*_t32*_t33*_t36 - 11233.47331112824*_t21*_t35 + 205248.95036667923*_t22*_t32*_t33*_t36 - 141558.90611670516*_t23*_t37 - 6434.4957325775076*_t24*_t35 - 126542.80091257894*_t24*_t37 + 94130.844904711266*_t25*_t32*_t33*_t36 - 5501.8609092425622*_t25*_t35 + 45223.451919064326*_t26*_t32*_t33*_t36 - 35526.797732757412*_t27*_t37 - 1366.4152974137464*_t28*_t35 - 7123.9579197113062*_t28*_t37 + 5830.0277511595468*_t29*_t32*_t33*_t36 - 263.85029332264094*_t29*_t35 + 1.5907309874643671*_t32*_t33*_t36*_t6 + 6.2712511822391397*_t32*_t33*_t36*_t7 - 0.0048235927206693755*_t35*_t5 - 0.063347038102185005*_t35*_t6 - 6.1435040303380273*_t35*_t9 - 0.014470778162008128*_t37*_t4 - 0.25338815240874002*_t37*_t5 - 43.004528212366196*_t37*_t8 - 77.193482630660725*_t37*_t9 - 0.001351251311777667*_t37;
  out[2] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dx23 = 0.0041215328215304528*_hc0[0]*_hc0[1]*_hc0[2]*_t38 - 0.00033781282794441674*_hc0[0]*_t39 - 0.0072353890810040629*_hc0[0]*_t42 + 443.38355164748901*_hc0[1]*_hc0[2]*_t10*_t38 + 325.8320004674236*_hc0[1]*_hc0[2]*_t11*_t38 + 16708.107578338786*_hc0[1]*_hc0[2]*_t14*_t38 + 19894.961159361155*_hc0[1]*_hc0[2]*_t17*_t38 + 111431.2102868325*_hc0[1]*_hc0[2]*_t18*_t38 + 98865.15991887034*_hc0[1]*_hc0[2]*_t21*_t38 + 153936.71277500942*_hc0[1]*_hc0[2]*_t22*_t38 + 70598.133678533457*_hc0[1]*_hc0[2]*_t25*_t38 + 33917.588939298235*_hc0[1]*_hc0[2]*_t26*_t38 + 4372.5208133696597*_hc0[1]*_hc0[2]*_t29*_t38 + 1.1930482405982754*_hc0[1]*_hc0[2]*_t38*_t6 + 4.7034383866793545*_hc0[1]*_hc0[2]*_t38*_t7 + 16.421613023981074*_hc0[3]*_t11*_t38 + 10.861066682247454*_hc0[3]*_t12*_t38 + 428.41301482919971*_hc0[3]*_t15*_t38 + 414.4783574866907*_hc0[3]*_t18*_t38 + 2184.9256918986762*_hc0[3]*_t19*_t38 + 1647.7526653145053*_hc0[3]*_t22*_t38 + 2443.4398853176099*_hc0[3]*_t23*_t38 + 980.52963442407565*_hc0[3]*_t26*_t38 + 452.23451919064314*_hc0[3]*_t27*_t38 + 52.053819206781661*_hc0[3]*_t30*_t38 + 0.00068692213692174214*_hc0[3]*_t38*_t4 + 0.079536549373218357*_hc0[3]*_t38*_t7 + 0.26130213259329749*_hc0[3]*_t38*_t8 + 0.00019549089064737767*_hc0[3]*_t38 + 977.49600140227096*_t10*_t38*_t41 - 2.4122963322081477*_t10*_t39 - 11543.265465201852*_t11*_t42 - 3462.9796395605545*_t12*_t40 - 2093.0434678192173*_t12*_t42 + 66832.430313355158*_t13*_t38*_t41 - 104.93877695638044*_t13*_t39 - 570.83003667796845*_t13*_t40 - 15.856389907721343*_t14*_t39 - 12176.495069213655*_t14*_t42 - 2809.9604005877668*_t15*_t40 - 245540.8103606225*_t15*_t42 + 99474.805796805769*_t16*_t38*_t41 - 66.90381906161349*_t16*_t39 - 52615.887934419108*_t16*_t40 + 594299.78819643997*_t17*_t38*_t41 - 1169.2419540982023*_t17*_t39 - 327579.58011974843*_t18*_t42 - 57808.161197602662*_t19*_t40 - 960461.96810146444*_t19*_t42 + 626146.01281951217*_t20*_t38*_t41 - 1070.5215036593086*_t20*_t39 - 160076.99468357742*_t20*_t40 + 1026244.7518333961*_t21*_t38*_t41 - 2808.3683277820601*_t21*_t39 - 743184.25711270212*_t22*_t42 - 106169.17958752887*_t23*_t40 - 695985.40501918411*_t23*_t42 + 541252.35820208979*_t24*_t38*_t41 - 1608.6239331443767*_t24*_t39 - 94907.100684434205*_t24*_t40 + 271340.71151438594*_t25*_t38*_t41 - 1375.4652273106403*_t25*_t39 - 222042.48582973384*_t26*_t42 - 26645.098299568057*_t27*_t40 - 46305.726478123492*_t27*_t42 + 39352.687320326942*_t28*_t38*_t41 - 341.60382435343661*_t28*_t39 - 5342.968439783479*_t28*_t40 - 65.962573330660234*_t29*_t39 + 1.5907309874643671*_t38*_t41*_t5 + 7.8390639777989257*_t38*_t41*_t6 + 1182.3561377266374*_t38*_t41*_t9 + 0.0013738442738434843*_t38*_t41 - 0.0012058981801673439*_t39*_t5 - 0.015836759525546251*_t39*_t6 - 1.5358760075845068*_t39*_t9 - 0.010853083621506094*_t4*_t40 - 0.19004111430655501*_t4*_t42 - 0.19004111430655501*_t40*_t5 - 32.253396159274644*_t40*_t8 - 57.895111972995544*_t40*_t9 - 0.0010134384838332501*_t40 - 64.506792318549287*_t42*_t7 - 135.08859460365628*_t42*_t8;
  out[3] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dx24 = 0.0002289740456405807*_hc0[0]*_hc0[1]*_hc0[3]*_t1*_t43 + 0.00017173053423043554*_hc0[0]*_t1*_t43*_t49 - 1.4075534497684031e-5*_hc0[0]*_t45 - 0.015836759525546251*_hc0[0]*_t48 - 0.0018088472702510157*_hc0[0]*_t51 + 24.632419535971611*_hc0[1]*_hc0[3]*_t1*_t10*_t43 + 18.101777803745755*_hc0[1]*_hc0[3]*_t1*_t11*_t43 + 928.22819879659926*_hc0[1]*_hc0[3]*_t1*_t14*_t43 + 1105.2756199645085*_hc0[1]*_hc0[3]*_t1*_t17*_t43 + 6190.6227937129161*_hc0[1]*_hc0[3]*_t1*_t18*_t43 + 5492.5088843816848*_hc0[1]*_hc0[3]*_t1*_t21*_t43 + 8552.0395986116346*_hc0[1]*_hc0[3]*_t1*_t22*_t43 + 3922.1185376963026*_hc0[1]*_hc0[3]*_t1*_t25*_t43 + 1884.3104966276796*_hc0[1]*_hc0[3]*_t1*_t26*_t43 + 242.9178229649811*_hc0[1]*_hc0[3]*_t1*_t29*_t43 + 0.066280457811015298*_hc0[1]*_hc0[3]*_t1*_t43*_t6 + 0.26130213259329749*_hc0[1]*_hc0[3]*_t1*_t43*_t7 + 244.37400035056771*_hc0[2]*_t1*_t10*_t36*_t43 + 16708.107578338786*_hc0[2]*_t1*_t13*_t36*_t43 + 24868.701449201442*_hc0[2]*_t1*_t16*_t36*_t43 + 148574.94704910999*_hc0[2]*_t1*_t17*_t36*_t43 + 156536.50320487804*_hc0[2]*_t1*_t20*_t36*_t43 + 256561.18795834904*_hc0[2]*_t1*_t21*_t36*_t43 + 135313.08955052245*_hc0[2]*_t1*_t24*_t36*_t43 + 67835.177878596471*_hc0[2]*_t1*_t25*_t36*_t43 + 9838.1718300817338*_hc0[2]*_t1*_t28*_t36*_t43 + 0.39768274686609179*_hc0[2]*_t1*_t36*_t43*_t5 + 1.9597659944497314*_hc0[2]*_t1*_t36*_t43*_t6 + 295.58903443165934*_hc0[2]*_t1*_t36*_t43*_t9 + 0.00034346106846087107*_hc0[2]*_t1*_t36*_t43 + 0.68423387599921137*_hc0[4]*_t1*_t11*_t43 + 0.45254444509364389*_hc0[4]*_t1*_t12*_t43 + 17.850542284549988*_hc0[4]*_t1*_t15*_t43 + 17.269931561945445*_hc0[4]*_t1*_t18*_t43 + 91.038570495778174*_hc0[4]*_t1*_t19*_t43 + 68.656361054771054*_hc0[4]*_t1*_t22*_t43 + 101.80999522156708*_hc0[4]*_t1*_t23*_t43 + 40.855401434336486*_hc0[4]*_t1*_t26*_t43 + 18.843104966276798*_hc0[4]*_t1*_t27*_t43 + 2.1689091336159025*_hc0[4]*_t1*_t30*_t43 + 2.8621755705072588e-5*_hc0[4]*_t1*_t4*_t43 + 0.0033140228905507649*_hc0[4]*_t1*_t43*_t7 + 0.010887588858054062*_hc0[4]*_t1*_t43*_t8 + 8.1454537769740695e-6*_hc0[4]*_t1*_t43 + 18.474314651978709*_t1*_t10*_t43*_t49 + 13.576333352809316*_t1*_t11*_t43*_t49 + 30631.530560287778*_t1*_t12*_t43*_t47 + 696.17114909744942*_t1*_t14*_t43*_t49 + 58026.970048136704*_t1*_t15*_t43*_t47 + 371437.36762277497*_t1*_t16*_t43*_t47 + 828.95671497338139*_t1*_t17*_t43*_t49 + 4642.9670952846873*_t1*_t18*_t43*_t49 + 469609.50961463409*_t1*_t19*_t43*_t47 + 812443.76186810527*_t1*_t20*_t43*_t47 + 4119.3816632862636*_t1*_t21*_t43*_t49 + 6414.0296989587259*_t1*_t22*_t43*_t49 + 496147.99501858227*_t1*_t23*_t43*_t47 + 260034.84853461987*_t1*_t24*_t43*_t47 + 2941.5889032722271*_t1*_t25*_t43*_t49 + 1413.2328724707597*_t1*_t26*_t43*_t49 + 42632.077930354186*_t1*_t27*_t43*_t47 + 182.18836722373581*_t1*_t29*_t43*_t49 + 0.19884137343304589*_t1*_t4*_t43*_t47 + 1.3065106629664875*_t1*_t43*_t47*_t5 + 344.85387350360259*_t1*_t43*_t47*_t8 + 325.83200046742365*_t1*_t43*_t47*_t9 + 0.049710343358261473*_t1*_t43*_t49*_t6 + 0.19597659944497309*_t1*_t43*_t49*_t7 - 0.10051234717533948*_t10*_t45 - 4328.7245494506942*_t10*_t48 - 872.10144492467396*_t11*_t48 - 2885.8163663004625*_t11*_t51 - 192.38775775336413*_t12*_t46 - 144.2908183150231*_t12*_t50 - 523.26086695480444*_t12*_t51 - 4.3724490398491849*_t13*_t45 - 31.712779815442691*_t13*_t46 - 6088.2475346068277*_t13*_t48 - 23.784584861582019*_t13*_t50 - 0.66068291282172265*_t14*_t45 - 133001.27227867051*_t14*_t48 - 3044.1237673034138*_t14*_t51 - 156.10891114376483*_t15*_t46 - 117.08168335782361*_t15*_t50 - 61385.202590155634*_t15*_t51 - 2.7876591275672284*_t16*_t45 - 2923.104885245506*_t16*_t46 - 2192.3286639341295*_t16*_t50 - 48.718414754091761*_t17*_t45 - 218386.38674649893*_t17*_t48 - 680327.22740520397*_t18*_t48 - 81894.895029937106*_t18*_t51 - 3211.5645109779252*_t19*_t46 - 2408.6733832334439*_t19*_t50 - 240115.49202536611*_t19*_t51 - 44.60506265247119*_t20*_t45 - 8893.1663713098569*_t20*_t46 - 6669.8747784823918*_t20*_t50 - 117.01534699091917*_t21*_t45 - 619320.21426058514*_t21*_t48 - 608987.22939178604*_t22*_t48 - 185796.06427817553*_t22*_t51 - 5898.2877548627148*_t23*_t46 - 4423.7158161470361*_t23*_t50 - 173996.35125479603*_t23*_t51 - 67.025997214349019*_t24*_t45 - 5272.6167046907885*_t24*_t46 - 3954.4625285180919*_t24*_t50 - 57.311051137943345*_t25*_t45 - 222042.48582973384*_t25*_t48 - 48235.131748045307*_t26*_t48 - 55510.621457433459*_t26*_t51 - 1480.2832388648919*_t27*_t46 - 1110.2124291486689*_t27*_t50 - 11576.431619530871*_t27*_t51 - 14.233492681393191*_t28*_t45 - 296.83157998797105*_t28*_t46 - 222.62368499097829*_t28*_t50 - 2.7484405554441764*_t29*_t45 - 0.00060294909008367194*_t4*_t46 - 0.00045221181756275393*_t4*_t50 - 0.047510278576638754*_t4*_t51 - 5.024575750697266e-5*_t45*_t5 - 0.0006598649802310938*_t45*_t6 - 0.063994833649354446*_t45*_t9 - 0.010557839683697501*_t46*_t5 - 1.7918553421819245*_t46*_t8 - 3.2163951096108634*_t46*_t9 - 5.6302137990736117e-5*_t46 - 13.438915066364435*_t48*_t6 - 33.772148650914069*_t48*_t7 - 0.00030147454504183592*_t48 - 0.0079183797627731256*_t5*_t50 - 1.3438915066364434*_t50*_t8 - 2.4122963322081477*_t50*_t9 - 4.2226603493052086e-5*_t50 - 16.126698079637322*_t51*_t7 - 33.772148650914069*_t51*_t8;
  out[4] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double *out) {

  const double _t1 = xc_powr(n_s, -8, 3);
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = _t2/M_CBRTPI;
  const double _t4 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t8 = xc_powr(n_s, -11, 3);
#endif
#if _KMAX >= 2
  const double _t13 = xc_powr(n_s, -16, 3);
  const double _t16 = xc_powr(n_s, -19, 3);
  const double _t18 = (0.8e1 / 0.3e1)*sigma_ss;
  const double _t19 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t21 = xc_powr(n_s, -14, 3);
  const double _t23 = xc_powr(n_s, -22, 3);
  const double _t25 = (sigma_ss * sigma_ss);
  const double _t26 = (0.64e2 / 0.9e1)*_t25;
  const double _t30 = xc_powi(n_s, -5);
  const double _t33 = (0.8e1 / 0.9e1)*sigma_ss;
#endif
#if _KMAX >= 3
  const double _t35 = xc_powi(n_s, -8);
  const double _t38 = xc_powi(n_s, -9);
  const double _t40 = xc_powr(n_s, -20, 3);
  const double _t42 = xc_powi(n_s, -10);
  const double _t45 = xc_powr(n_s, -23, 3);
  const double _t53 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t54 = (0.512e3 / 0.27e2)*_t53;
  const double _t60 = (0.2e1 / 0.9e1)*sigma_ss;
  const double _t62 = (0.32e2 / 0.9e1)*_t25;
#endif
#if _KMAX >= 4
  const double _t65 = xc_powr(n_s, -28, 3);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t4)) XC_CAT(beefvdw_f_pf_k, _KMAX)(p, _t1*sigma_ss, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t4)) XC_CAT(lda_x_spin_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t3/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc1);
  const double _t5 = my_piecewise3(_t4, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t6 = _hc0[1]*_hc1[0];
  const double _t7 = my_piecewise3(_t4, 0, _t1*_t6);
  const double _t9 = (0.8e1 / 0.3e1)*_t6*_t8;
  const double _t10 = _hc1[2]*_t3;
  const double _t11 = (0.1e1 / 0.6e1)*_t10;
  const double _t12 = my_piecewise3(_t4, 0, -_hc0[0]*_t11/xc_powr(n_s, 4, 3) - _t9*sigma_ss);
#endif
#if _KMAX >= 2
  const double _t14 = _hc0[2]*_hc1[0];
  const double _t15 = my_piecewise3(_t4, 0, _t13*_t14);
  const double _t17 = _t14*_t16;
  const double _t20 = my_piecewise3(_t4, 0, -_hc0[1]*_t11*_t19 - _t17*_t18 - _t9);
  const double _t22 = (0.88e2 / 0.9e1)*_t21*_t6;
  const double _t24 = _t14*_t23;
  const double _t27 = (0.2e1 / 0.9e1)*_hc0[0];
  const double _t28 = (0.1e1 / 0.36e2)*_hc0[0];
  const double _t29 = xc_powr(0.6e1, 2, 3)*_hc1[5]/(M_CBRTPI * M_CBRTPI);
  const double _t31 = _hc0[1]*_t10;
  const double _t32 = _t30*_t31;
  const double _t34 = my_piecewise3(_t4, 0, _t1*_t28*_t29 + _t10*_t27/xc_powr(n_s, 7, 3) + _t22*sigma_ss + _t24*_t26 + _t32*_t33);
#endif
#if _KMAX >= 3
  const double _t36 = _hc0[3]*_hc1[0];
  const double _t37 = my_piecewise3(_t4, 0, _t35*_t36);
  const double _t39 = _t36*_t38;
  const double _t41 = my_piecewise3(_t4, 0, -_hc0[2]*_t11*_t40 - 0.16e2 / 0.3e1*_t17 - _t18*_t39);
  const double _t43 = _t36*_t42;
  const double _t44 = (0.1e1 / 0.36e2)*_hc0[1];
  const double _t46 = _hc0[2]*_t10;
  const double _t47 = _t45*_t46;
  const double _t48 = my_piecewise3(_t4, 0, _t13*_t29*_t44 + _t22 + 0.24e2*_t24*sigma_ss + _t26*_t43 + (0.10e2 / 0.9e1)*_t32 + _t33*_t47);
  const double _t49 = (0.1232e4 / 0.27e2)*_t6/xc_powr(n_s, 17, 3);
  const double _t50 = _hc1[9]/M_PI;
  const double _t51 = _t14/xc_powr(n_s, 25, 3);
  const double _t52 = _t36/xc_powi(n_s, 11);
  const double _t55 = _hc0[0]*_t10;
  const double _t56 = _hc0[0]*_t29;
  const double _t57 = _t31/xc_powi(n_s, 6);
  const double _t58 = _hc0[1]*_t29;
  const double _t59 = _t16*_t58;
  const double _t61 = _t46/xc_powr(n_s, 26, 3);
  const double _t63 = my_piecewise3(_t4, 0, -_t19*_t28*_t50 - 0.704e3 / 0.9e1*_t25*_t51 - _t49*sigma_ss - _t52*_t54 - 0.14e2 / 0.27e2*_t55/xc_powr(n_s, 10, 3) - 0.1e1 / 0.9e1*_t56*_t8 - 0.20e2 / 0.3e1*_t57*sigma_ss - _t59*_t60 - _t61*_t62);
#endif
#if _KMAX >= 4
  const double _t64 = _hc0[4]*_hc1[0];
  const double _t66 = _hc0[2]*_t29;
  const double _t67 = _hc0[3]*_t10;
#endif

  const double f = my_piecewise3(_t4, 0, _t5*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t4, 0, _t7*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t4, 0, _t12*n_s + _t5);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t4, 0, _t15*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t4, 0, _t20*n_s + _t7);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t4, 0, 0.2e1*_t12 + _t34*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t4, 0, _t37*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t4, 0, _t15 + _t41*n_s);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t4, 0, 0.2e1*_t20 + _t48*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t4, 0, 0.3e1*_t34 + _t63*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t4, 0, n_s*my_piecewise3(_t4, 0, _t64/xc_powr(n_s, 32, 3)));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t4, 0, _t37 + n_s*my_piecewise3(_t4, 0, -_hc0[3]*_t11*_t65 - _t18*_t64/xc_powr(n_s, 35, 3) - 0.8e1*_t39));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t4, 0, 0.2e1*_t41 + n_s*my_piecewise3(_t4, 0, (0.304e3 / 0.9e1)*_t24 + _t26*_t64/xc_powr(n_s, 38, 3) + _t33*_t67/xc_powr(n_s, 31, 3) + (0.1e1 / 0.36e2)*_t35*_t66 + (0.344e3 / 0.9e1)*_t43*sigma_ss + 0.2e1*_t47));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t4, 0, 0.3e1*_t48 + n_s*my_piecewise3(_t4, 0, -0.1216e4 / 0.9e1*_t25*_t52 - _t38*_t60*_t66 - _t40*_t44*_t50 - _t49 - 0.5456e4 / 0.27e2*_t51*sigma_ss - _t54*_t64/xc_powr(n_s, 41, 3) - 0.194e3 / 0.27e2*_t57 - 0.1e1 / 0.3e1*_t59 - 0.124e3 / 0.9e1*_t61*sigma_ss - _t62*_t67/xc_powr(n_s, 34, 3)));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t4, 0, 0.4e1*_t63 + n_s*my_piecewise3(_t4, 0, (0.1e1 / 0.216e3)*_hc0[0]*_hc1[14]*_t13*_t2/(M_PI * M_CBRTPI) + (0.8e1 / 0.27e2)*_hc0[1]*_t45*_t50*sigma_ss + (0.62656e5 / 0.81e2)*_t14*_t25*_t65 + (0.40e2 / 0.81e2)*_t21*_t56 + (0.76e2 / 0.27e2)*_t23*_t58*sigma_ss + (0.32e2 / 0.27e2)*_t25*_t42*_t66 + (0.1664e4 / 0.27e2)*_t25*_t46/xc_powr(n_s, 29, 3) + _t27*_t30*_t50 + (0.3968e4 / 0.81e2)*_t31*sigma_ss/xc_powi(n_s, 7) + (0.11264e5 / 0.27e2)*_t36*_t53/xc_powi(n_s, 12) + (0.20944e5 / 0.81e2)*_t40*_t6*sigma_ss + (0.1024e4 / 0.81e2)*_t53*_t67/xc_powr(n_s, 37, 3) + (0.140e3 / 0.81e2)*_t55/xc_powr(n_s, 13, 3) + (0.4096e4 / 0.81e2)*_t64*(sigma_ss * sigma_ss * sigma_ss * sigma_ss)/xc_powr(n_s, 44, 3)));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, (0.1e1 / 0.2e1)*na, (0.1e1 / 0.4e1)*gaa, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[2];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc0[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc0[5];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[4];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc0[3];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc0[9];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc0[8];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[7];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc0[6];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc0[14];
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc0[13];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc0[12];
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[11];
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc0[10];
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

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, _hc1);
  const double zk = (_hc0[0] + _hc1[0])/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[2];
  const double dF_dnb = _hc1[2];
  const double dF_dgaa = _hc0[1];
  const double dF_dgbb = _hc1[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = _hc0[5];
  const double d2F_dnb2 = _hc1[5];
  const double d2F_dna_dgaa = _hc0[4];
  const double d2F_dnb_dgbb = _hc1[4];
  const double d2F_dgaa2 = _hc0[3];
  const double d2F_dgbb2 = _hc1[3];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = _hc0[9];
  const double d3F_dnb3 = _hc1[9];
  const double d3F_dna2_dgaa = _hc0[8];
  const double d3F_dnb2_dgbb = _hc1[8];
  const double d3F_dna_dgaa2 = _hc0[7];
  const double d3F_dnb_dgbb2 = _hc1[7];
  const double d3F_dgaa3 = _hc0[6];
  const double d3F_dgbb3 = _hc1[6];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = _hc0[14];
  const double d4F_dnb4 = _hc1[14];
  const double d4F_dna3_dgaa = _hc0[13];
  const double d4F_dnb3_dgbb = _hc1[13];
  const double d4F_dna2_dgaa2 = _hc0[12];
  const double d4F_dnb2_dgbb2 = _hc1[12];
  const double d4F_dna_dgaa3 = _hc0[11];
  const double d4F_dnb_dgbb3 = _hc1[11];
  const double d4F_dgaa4 = _hc0[10];
  const double d4F_dgbb4 = _hc1[10];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
#endif
#endif
}
#endif