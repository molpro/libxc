/*
  Generated from python/lda_exc/lda_x.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_x
*/

#ifndef _LDA_X_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_X_KERNEL_BODY
#define _KMAX 0
#define _LDA_X_HELPER_BODIES
#include "lda_x.c"
#undef _LDA_X_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_X_HELPER_BODIES
#include "lda_x.c"
#undef _LDA_X_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_X_HELPER_BODIES
#include "lda_x.c"
#undef _LDA_X_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_X_HELPER_BODIES
#include "lda_x.c"
#undef _LDA_X_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_X_HELPER_BODIES
#include "lda_x.c"
#undef _LDA_X_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_x.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_x.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_x.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_x.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_x.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_x.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_x.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_x.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_x.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_x.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_X_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_spin_z1_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(0.12e2, 1, 3)*M_CBRT3/(M_CBRTPI*M_CBRTPI);
  const double _t2 = (0.3e1 / 0.8e1)*_t1;

  const double f = -_t2/rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t2/(rs * rs);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -0.3e1 / 0.4e1*_t1/(rs * rs * rs);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (0.9e1 / 0.4e1)*_t1/(rs * rs * rs * rs);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -0.9e1*_t1/xc_powi(rs, 5);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_lda_x_z1_k, _KMAX)(const xc_func_type *p, double rs, double *out) {
  const lda_x_params *params = (const lda_x_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_x_spin_z1_k, _KMAX)(p, rs, _hc0);
  const double _t1 = -p->dens_threshold + (0.3e1 / 0.4e1)/(M_PI*(rs * rs * rs)) <= 0;

  const double f = params->alpha*my_piecewise3(_t1, 0, _hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = params->alpha*my_piecewise3(_t1, 0, _hc0[1]);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = params->alpha*my_piecewise3(_t1, 0, _hc0[2]);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = params->alpha*my_piecewise3(_t1, 0, _hc0[3]);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = params->alpha*my_piecewise3(_t1, 0, _hc0[4]);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double *out) {
  const lda_x_params *params = (const lda_x_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = _t3/xc_powr(n_s, 1, 3);
  const double _t5 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 2
  const double _t7 = xc_powr(0.6e1, 2, 3);
  const double _t8 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_lda_x_z1_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t4, _hc0);
#if _KMAX >= 2
  const double _t6 = _hc0[1]*_t3;
#endif
#if _KMAX >= 3
  const double _t9 = _hc0[3]/M_PI;
  const double _t10 = _hc0[2]*_t7*_t8;
#endif

  const double f = my_piecewise3(_t5, 0, _hc0[0]*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dn_s = my_piecewise3(_t5, 0, _hc0[0] - 0.1e1 / 0.6e1*_hc0[1]*_t4);
  out[1] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dn_s2 = my_piecewise3(_t5, 0, (0.1e1 / 0.36e2)*_hc0[2]*_t7*_t8/xc_powr(n_s, 5, 3) - 0.1e1 / 0.9e1*_t6/xc_powr(n_s, 4, 3));
  out[2] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dn_s3 = my_piecewise3(_t5, 0, (0.4e1 / 0.27e2)*_hc0[1]*_t1*_t2/xc_powr(n_s, 7, 3) - 0.1e1 / 0.36e2*_t10/xc_powr(n_s, 8, 3) - 0.1e1 / 0.36e2*_t9/(n_s * n_s * n_s));
  out[3] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dn_s4 = my_piecewise3(_t5, 0, (0.1e1 / 0.216e3)*_hc0[4]*_t1/((M_PI * M_CBRTPI)*xc_powr(n_s, 13, 3)) + (0.4e1 / 0.81e2)*_t10/xc_powr(n_s, 11, 3) - 0.28e2 / 0.81e2*_t6/xc_powr(n_s, 10, 3) + (0.1e1 / 0.9e1)*_t9/(n_s * n_s * n_s * n_s));
  out[4] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  assert(p->params != NULL);
  const lda_x_params *params = (const lda_x_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(xchan_k, _KMAX)(p, (0.1e1 / 0.2e1)*na, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc0[2];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc0[3];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc0[4];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, _hc1);
  const double zk = (_hc0[0] + _hc1[0])/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[1];
  const double dF_dnb = _hc1[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = _hc0[2];
  const double d2F_dnb2 = _hc1[2];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = _hc0[3];
  const double d3F_dnb3 = _hc1[3];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = _hc0[4];
  const double d4F_dnb4 = _hc1[4];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif