/* 
  This file was generated automatically with ./scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ./maple/lda_exc/lda_x_1d_exponential.mpl
  Type of functional: lda_exc
*/

#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)


static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, double *zk, LDA_OUT_PARAMS_NO_EXC(double *))
{

#ifndef XC_DONT_COMPILE_EXC
  double t2, t3, t4, t5, t7, t8;

#ifndef XC_DONT_COMPILE_VXC
  double t15, t16;

#ifndef XC_DONT_COMPILE_FXC
  double t20, t22, t24;

#ifndef XC_DONT_COMPILE_KXC
  double t27, t29, t32, t33, t34;
#endif

#endif

#endif

#endif


  lda_x_1d_exponential_params *params;

  assert(p->params != NULL);
  params = (lda_x_1d_exponential_params * )(p->params);

  t2 = M_PI * params->beta * rho[0];
  t3 = xc_integrate(func1, NULL, 0.0, t2);
  t4 = xc_integrate(func2, NULL, 0.0, t2);
  t5 = 0.1e1 / M_PI;
  t7 = 0.1e1 / params->beta;
  t8 = 0.1e1 / rho[0];
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    zk[0] = -0.15915494309189533577e0 * (-t4 * t5 * t7 * t8 + t3) * t7;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t15 = params->beta * params->beta;
  t16 = 0.1e1 / t15;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = (-0.15915494309189533577e0 * (-t4 * t5 * t7 * t8 + t3) * t7) - 0.15915494309189533577e0 * t8 * t4 * t5 * t16;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t20 = M_PI * M_PI;
  t22 = rho[0] * rho[0];
  t24 = xc_E1_scaled(t20 * t15 * t22);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.50000000000000000001e0 * t24;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t27 = t20 * M_PI;
  t29 = 0.1e1 / t20 * t16;
  t32 = t24 - t29 / t22;
  t33 = t27 * t32;
  t34 = t15 * rho[0];
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.31830988618379067154e0 * t33 * t34;

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


  if(v4rho4 != NULL && (p->info->flags & XC_FLAGS_HAVE_LXC))
    v4rho4[0] = -0.31830988618379067154e0 * t27 * (0.2e1 * t32 * t20 * t34 + 0.2e1 * t29 / t22 / rho[0]) * t34 - 0.31830988618379067154e0 * t33 * t15;

#ifndef XC_DONT_COMPILE_MXC

  if(order < 5) return;


#endif

#endif

#endif

#endif

#endif


}


static inline void
func_ferr(const xc_func_type *p, int order, const double *rho, double *zk, LDA_OUT_PARAMS_NO_EXC(double *))
{

#ifndef XC_DONT_COMPILE_EXC
  double t3, t4, t6, t7, t9, t10;

#ifndef XC_DONT_COMPILE_VXC
  double t17, t18;

#ifndef XC_DONT_COMPILE_FXC
  double t22, t24, t27;

#ifndef XC_DONT_COMPILE_KXC
  double t30, t32, t36, t37, t38;
#endif

#endif

#endif

#endif


  lda_x_1d_exponential_params *params;

  assert(p->params != NULL);
  params = (lda_x_1d_exponential_params * )(p->params);

  t3 = 0.2e1 * M_PI * params->beta * rho[0];
  t4 = xc_integrate(func1, NULL, 0.0, t3);
  t6 = xc_integrate(func2, NULL, 0.0, t3);
  t7 = 0.1e1 / M_PI;
  t9 = 0.1e1 / params->beta;
  t10 = 0.1e1 / rho[0];
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    zk[0] = -0.79577471545947667883e-1 * (-t6 * t7 * t9 * t10 + 0.2e1 * t4) * t9;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t17 = params->beta * params->beta;
  t18 = 0.1e1 / t17;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = (-0.79577471545947667883e-1 * (-t6 * t7 * t9 * t10 + 0.2e1 * t4) * t9) - 0.79577471545947667883e-1 * t10 * t6 * t7 * t18;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t22 = M_PI * M_PI;
  t24 = rho[0] * rho[0];
  t27 = xc_E1_scaled(0.4e1 * t22 * t17 * t24);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.99999999999999999999e0 * t27;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t30 = t22 * M_PI;
  t32 = 0.1e1 / t22 * t18;
  t36 = t27 - t32 / t24 / 0.4e1;
  t37 = t30 * t36;
  t38 = t17 * rho[0];
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.25464790894703253722e1 * t37 * t38;

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


  if(v4rho4 != NULL && (p->info->flags & XC_FLAGS_HAVE_LXC))
    v4rho4[0] = -0.25464790894703253722e1 * t30 * (0.8e1 * t36 * t22 * t38 + t32 / t24 / rho[0] / 0.2e1) * t38 - 0.25464790894703253722e1 * t37 * t17;

#ifndef XC_DONT_COMPILE_MXC

  if(order < 5) return;


#endif

#endif

#endif

#endif

#endif


}


static inline void
func_pol(const xc_func_type *p, int order, const double *rho, double *zk, LDA_OUT_PARAMS_NO_EXC(double *))
{

#ifndef XC_DONT_COMPILE_EXC
  double t1, t2, t3, t4, t5, t6, t7, t8;
  double t9, t11, t12, t13, t14, t15, t19, t20;
  double t21, t22, t23, t25, t26, t30;

#ifndef XC_DONT_COMPILE_VXC
  double t31, t32, t33, t34, t36, t37, t39, t40;
  double t41, t43, t45, t46, t49, t52, t53, t54;
  double t57, t58;

#ifndef XC_DONT_COMPILE_FXC
  double t64, t65, t67, t69, t71, t72, t73, t74;
  double t75, t76, t77, t78, t80, t82, t83, t84;
  double t85, t87, t89, t90, t91, t93, t95, t96;
  double t97, t98, t99, t101, t103, t104, t105, t107;
  double t109, t110, t115, t118, t122, t125, t132, t134;
  double t136, t137, t139, t142, t143, t144, t146, t148;
  double t149, t151, t154, t155;

#ifndef XC_DONT_COMPILE_KXC
  double t160, t161, t162, t164, t166, t169, t171, t173;
  double t174, t177, t178, t179, t180, t182, t183, t186;
  double t187, t189, t190, t192, t193, t194, t195, t196;
  double t197, t198, t199, t200, t201, t202, t203, t205;
  double t207, t208, t209, t211, t214, t216, t218, t219;
  double t222, t224, t225, t228, t230, t231, t233, t234;
  double t235, t236, t237, t238, t239, t240, t241, t242;
  double t243, t245, t247, t248, t251, t252, t259, t263;
  double t271, t275, t281, t283, t287, t289, t290, t291;
  double t292, t295, t297, t300, t302, t303, t305, t307;
  double t311, t312, t313, t316, t318, t321, t323, t324;
  double t331, t333, t336, t339, t340, t342, t345, t346;
  double t348, t350, t351, t353, t357, t358, t359, t361;
  double t364, t367, t368, t370, t373, t374, t376, t378;
  double t379, t381, t385, t386;

#ifndef XC_DONT_COMPILE_LXC
  double t391, t392, t395, t398, t402, t404, t405, t407;
  double t408, t413, t419, t420, t422, t423, t425, t427;
  double t428, t429, t430, t431, t432, t433, t435, t436;
  double t438, t451, t453, t456, t457, t458, t459, t461;
  double t463, t465, t468, t470, t471, t472, t473, t476;
  double t477, t480, t483, t488, t489, t491, t492, t497;
  double t503, t504, t506, t507, t509, t511, t512, t513;
  double t514, t515, t516, t517, t519, t528, t530, t533;
  double t534, t535, t542, t544, t547, t549, t550, t551;
  double t552, t559, t561, t580, t584, t586, t605, t628;
  double t629, t630, t631, t637, t639, t650, t652, t654;
  double t656, t661, t664, t669, t685, t694, t701, t703;
  double t705, t707, t709, t714, t717, t722, t734, t737;
  double t741, t753, t767, t768, t769, t775, t776, t778;
  double t795, t799, t803, t811, t815, t823, t828, t848;
  double t849, t852, t857, t859, t875, t892, t895, t903;
  double t912, t925, t940, t952, t955, t963, t984, t999;
#endif

#endif

#endif

#endif

#endif


  lda_x_1d_exponential_params *params;

  assert(p->params != NULL);
  params = (lda_x_1d_exponential_params * )(p->params);

  t1 = rho[0] - rho[1];
  t2 = rho[0] + rho[1];
  t3 = 0.1e1 / t2;
  t4 = t1 * t3;
  t5 = 0.1e1 + t4;
  t6 = t5 * M_PI;
  t7 = params->beta * t2;
  t8 = t6 * t7;
  t9 = xc_integrate(func1, NULL, 0.0, t8);
  t11 = xc_integrate(func2, NULL, 0.0, t8);
  t12 = 0.1e1 / M_PI;
  t13 = t11 * t12;
  t14 = 0.1e1 / params->beta;
  t15 = t14 * t3;
  t19 = 0.79577471545947667883e-1 * (-t13 * t15 + t5 * t9) * t14;
  t20 = 0.1e1 - t4;
  t21 = t20 * M_PI;
  t22 = t21 * t7;
  t23 = xc_integrate(func1, NULL, 0.0, t22);
  t25 = xc_integrate(func2, NULL, 0.0, t22);
  t26 = t25 * t12;
  t30 = 0.79577471545947667883e-1 * (-t26 * t15 + t20 * t23) * t14;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    zk[0] = -t19 - t30;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t31 = t2 * t2;
  t32 = 0.1e1 / t31;
  t33 = t1 * t32;
  t34 = t3 - t33;
  t36 = t14 * t32;
  t37 = t13 * t36;
  t39 = (t34 * t9 + t37) * t14;
  t40 = 0.79577471545947667883e-1 * t39;
  t41 = -t34;
  t43 = t26 * t36;
  t45 = (t41 * t23 + t43) * t14;
  t46 = 0.79577471545947667883e-1 * t45;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t19 - t30 + t2 * (-t40 - t46);

  t49 = -t3 - t33;
  t52 = (t49 * t9 + t37) * t14;
  t53 = 0.79577471545947667883e-1 * t52;
  t54 = -t49;
  t57 = (t54 * t23 + t43) * t14;
  t58 = 0.79577471545947667883e-1 * t57;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = -t19 - t30 + t2 * (-t53 - t58);

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t64 = 0.1e1 / t31 / t2;
  t65 = t1 * t64;
  t67 = -0.2e1 * t32 + 0.2e1 * t65;
  t69 = t34 * M_PI;
  t71 = t6 * params->beta;
  t72 = t69 * t7 + t71;
  t73 = t34 * t72;
  t74 = t5 * t5;
  t75 = M_PI * M_PI;
  t76 = t74 * t75;
  t77 = params->beta * params->beta;
  t78 = t77 * t31;
  t80 = xc_E1_scaled(t76 * t78);
  t82 = t72 * t80;
  t83 = t5 * t3;
  t84 = t82 * t83;
  t85 = t14 * t64;
  t87 = 0.2e1 * t13 * t85;
  t89 = (t67 * t9 + t73 * t80 + t84 - t87) * t14;
  t90 = 0.79577471545947667883e-1 * t89;
  t91 = -t67;
  t93 = t41 * M_PI;
  t95 = t21 * params->beta;
  t96 = t93 * t7 + t95;
  t97 = t41 * t96;
  t98 = t20 * t20;
  t99 = t98 * t75;
  t101 = xc_E1_scaled(t99 * t78);
  t103 = t96 * t101;
  t104 = t20 * t3;
  t105 = t103 * t104;
  t107 = 0.2e1 * t26 * t85;
  t109 = (t97 * t101 + t91 * t23 + t105 - t107) * t14;
  t110 = 0.79577471545947667883e-1 * t109;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.15915494309189533577e0 * t39 - 0.15915494309189533577e0 * t45 + t2 * (-t90 - t110);

  t115 = t49 * t72;
  t118 = (t115 * t80 + 0.2e1 * t65 * t9 + t84 - t87) * t14;
  t122 = t54 * t96;
  t125 = (t122 * t101 - 0.2e1 * t65 * t23 + t105 - t107) * t14;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = -t40 - t46 - t53 - t58 + t2 * (-0.79577471545947667883e-1 * t118 - 0.79577471545947667883e-1 * t125);

  t132 = 0.2e1 * t32 + 0.2e1 * t65;
  t134 = t49 * M_PI;
  t136 = t134 * t7 + t71;
  t137 = t49 * t136;
  t139 = t136 * t80;
  t142 = (t132 * t9 + t137 * t80 + t139 * t83 - t87) * t14;
  t143 = 0.79577471545947667883e-1 * t142;
  t144 = -t132;
  t146 = t54 * M_PI;
  t148 = t146 * t7 + t95;
  t149 = t54 * t148;
  t151 = t148 * t101;
  t154 = (t149 * t101 + t151 * t104 + t144 * t23 - t107) * t14;
  t155 = 0.79577471545947667883e-1 * t154;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = -0.15915494309189533577e0 * t52 - 0.15915494309189533577e0 * t57 + t2 * (-t143 - t155);

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t160 = t31 * t31;
  t161 = 0.1e1 / t160;
  t162 = t1 * t161;
  t164 = 0.6e1 * t64 - 0.6e1 * t162;
  t166 = t67 * t72;
  t169 = t67 * M_PI;
  t171 = t69 * params->beta;
  t173 = t169 * t7 + 0.2e1 * t171;
  t174 = t34 * t173;
  t177 = 0.1e1 / t75;
  t178 = 0.1e1 / t74 * t177;
  t179 = 0.1e1 / t77;
  t180 = t179 * t32;
  t182 = -t178 * t180 + t80;
  t183 = t5 * t75;
  t186 = t77 * t2;
  t187 = t76 * t186;
  t189 = 0.2e1 * t183 * t78 * t34 + 0.2e1 * t187;
  t190 = t182 * t189;
  t192 = t173 * t80;
  t193 = t192 * t83;
  t194 = t72 * t182;
  t195 = t189 * t5;
  t196 = t195 * t3;
  t197 = t194 * t196;
  t198 = t34 * t3;
  t199 = t82 * t198;
  t200 = t5 * t32;
  t201 = t82 * t200;
  t202 = 0.3e1 * t201;
  t203 = t14 * t161;
  t205 = 0.6e1 * t13 * t203;
  t207 = (t164 * t9 + 0.2e1 * t166 * t80 + t174 * t80 + t73 * t190 + t193 + t197 + t199 - t202 + t205) * t14;
  t208 = 0.79577471545947667883e-1 * t207;
  t209 = -t164;
  t211 = t91 * t96;
  t214 = t91 * M_PI;
  t216 = t93 * params->beta;
  t218 = t214 * t7 + 0.2e1 * t216;
  t219 = t41 * t218;
  t222 = 0.1e1 / t98 * t177;
  t224 = -t222 * t180 + t101;
  t225 = t20 * t75;
  t228 = t99 * t186;
  t230 = 0.2e1 * t225 * t78 * t41 + 0.2e1 * t228;
  t231 = t224 * t230;
  t233 = t218 * t101;
  t234 = t233 * t104;
  t235 = t96 * t224;
  t236 = t230 * t20;
  t237 = t236 * t3;
  t238 = t235 * t237;
  t239 = t41 * t3;
  t240 = t103 * t239;
  t241 = t20 * t32;
  t242 = t103 * t241;
  t243 = 0.3e1 * t242;
  t245 = 0.6e1 * t26 * t203;
  t247 = (0.2e1 * t211 * t101 + t219 * t101 + t209 * t23 + t97 * t231 + t234 + t238 + t240 - t243 + t245) * t14;
  t248 = 0.79577471545947667883e-1 * t247;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.23873241463784300365e0 * t89 - 0.23873241463784300365e0 * t109 + t2 * (-t208 - t248);

  t251 = 0.15915494309189533577e0 * t118;
  t252 = 0.15915494309189533577e0 * t125;
  t259 = t49 * t173;
  t263 = (t115 * t190 - 0.6e1 * t162 * t9 + t259 * t80 + 0.2e1 * t64 * t9 + 0.4e1 * t65 * t82 + t193 + t197 + t199 - t202 + t205) * t14;
  t271 = t54 * t218;
  t275 = (t271 * t101 - 0.4e1 * t65 * t103 + t122 * t231 + 0.6e1 * t162 * t23 - 0.2e1 * t64 * t23 + t234 + t238 + t240 - t243 + t245) * t14;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = -t90 - t110 - t251 - t252 + t2 * (-0.79577471545947667883e-1 * t263 - 0.79577471545947667883e-1 * t275);

  t281 = -0.2e1 * t64 - 0.6e1 * t162;
  t283 = t132 * t72;
  t287 = M_PI * params->beta;
  t289 = 0.2e1 * t33 * t287;
  t290 = t134 * params->beta;
  t291 = t289 + t290 + t171;
  t292 = t49 * t291;
  t295 = t291 * t80;
  t297 = t136 * t182;
  t300 = t139 * t200;
  t302 = t137 * t190 + t139 * t198 + 0.2e1 * t65 * t139 + t297 * t196 + t281 * t9 + t283 * t80 + t292 * t80 + t295 * t83 - 0.2e1 * t201 + t205 - t300;
  t303 = t302 * t14;
  t305 = -t281;
  t307 = t144 * t96;
  t311 = t146 * params->beta;
  t312 = -t289 + t311 + t216;
  t313 = t54 * t312;
  t316 = t312 * t101;
  t318 = t148 * t224;
  t321 = t151 * t241;
  t323 = t307 * t101 + t313 * t101 + t316 * t104 + t149 * t231 + t151 * t239 - 0.2e1 * t65 * t151 + t305 * t23 + t318 * t237 - 0.2e1 * t242 + t245 - t321;
  t324 = t323 * t14;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = -t251 - t252 - t143 - t155 + t2 * (-0.79577471545947667883e-1 * t303 - 0.79577471545947667883e-1 * t324);

  t331 = -0.6e1 * t64 - 0.6e1 * t162;
  t333 = t132 * t136;
  t336 = t132 * M_PI;
  t339 = t336 * t7 + 0.2e1 * t290;
  t340 = t49 * t339;
  t342 = t78 * t49;
  t345 = 0.2e1 * t183 * t342 + 0.2e1 * t187;
  t346 = t182 * t345;
  t348 = t339 * t80;
  t350 = t345 * t5;
  t351 = t350 * t3;
  t353 = t49 * t3;
  t357 = (t137 * t346 + t139 * t353 + t297 * t351 + t331 * t9 + 0.2e1 * t333 * t80 + t340 * t80 + t348 * t83 + t205 - 0.3e1 * t300) * t14;
  t358 = 0.79577471545947667883e-1 * t357;
  t359 = -t331;
  t361 = t144 * t148;
  t364 = t144 * M_PI;
  t367 = t364 * t7 + 0.2e1 * t311;
  t368 = t54 * t367;
  t370 = t78 * t54;
  t373 = 0.2e1 * t225 * t370 + 0.2e1 * t228;
  t374 = t224 * t373;
  t376 = t367 * t101;
  t378 = t373 * t20;
  t379 = t378 * t3;
  t381 = t54 * t3;
  t385 = (0.2e1 * t361 * t101 + t368 * t101 + t376 * t104 + t149 * t374 + t151 * t381 + t359 * t23 + t318 * t379 + t245 - 0.3e1 * t321) * t14;
  t386 = 0.79577471545947667883e-1 * t385;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = -0.23873241463784300365e0 * t142 - 0.23873241463784300365e0 * t154 + t2 * (-t358 - t386);

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


  t391 = t192 * t200;
  t392 = 0.4e1 * t391;
  t395 = 0.2e1 * t173 * t182 * t196;
  t398 = 0.1e1 / t74 / t5 * t177;
  t402 = t179 * t64;
  t404 = 0.2e1 * t178 * t402;
  t405 = 0.2e1 * t398 * t180 * t34 + t190 + t404;
  t407 = t72 * t405 * t196;
  t408 = t34 * t34;
  t413 = t183 * t186 * t34;
  t419 = 0.2e1 * t76 * t77;
  t420 = 0.2e1 * t183 * t78 * t67 + 0.2e1 * t408 * t75 * t78 + 0.8e1 * t413 + t419;
  t422 = t420 * t5 * t3;
  t423 = t194 * t422;
  t425 = t189 * t34 * t3;
  t427 = 0.2e1 * t194 * t425;
  t428 = t34 * t32;
  t429 = t82 * t428;
  t430 = 0.4e1 * t429;
  t431 = t5 * t64;
  t432 = t82 * t431;
  t433 = 0.12e2 * t432;
  t435 = 0.1e1 / t160 / t2;
  t436 = t14 * t435;
  t438 = 0.24e2 * t13 * t436;
  t451 = t169 * params->beta;
  t453 = t164 * M_PI * t7 + 0.3e1 * t451;
  t456 = t195 * t32;
  t457 = t194 * t456;
  t458 = 0.4e1 * t457;
  t459 = t1 * t435;
  t461 = -0.24e2 * t161 + 0.24e2 * t459;
  t463 = t405 * t189;
  t465 = t182 * t420;
  t468 = t453 * t80 * t83;
  t470 = 0.2e1 * t192 * t198;
  t471 = t67 * t3;
  t472 = t82 * t471;
  t473 = 0.3e1 * t164 * t72 * t80 + 0.3e1 * t67 * t173 * t80 + t34 * t453 * t80 + 0.3e1 * t166 * t190 + 0.2e1 * t174 * t190 + t461 * t9 + t73 * t463 + t73 * t465 - t392 + t395 + t407 + t423 + t427 - t430 + t433 - t438 - t458 + t468 + t470 + t472;
  t476 = t233 * t241;
  t477 = 0.4e1 * t476;
  t480 = 0.2e1 * t218 * t224 * t237;
  t483 = 0.1e1 / t98 / t20 * t177;
  t488 = 0.2e1 * t222 * t402;
  t489 = 0.2e1 * t483 * t180 * t41 + t231 + t488;
  t491 = t96 * t489 * t237;
  t492 = t41 * t41;
  t497 = t225 * t186 * t41;
  t503 = 0.2e1 * t99 * t77;
  t504 = 0.2e1 * t225 * t78 * t91 + 0.2e1 * t492 * t75 * t78 + 0.8e1 * t497 + t503;
  t506 = t504 * t20 * t3;
  t507 = t235 * t506;
  t509 = t230 * t41 * t3;
  t511 = 0.2e1 * t235 * t509;
  t512 = t41 * t32;
  t513 = t103 * t512;
  t514 = 0.4e1 * t513;
  t515 = t20 * t64;
  t516 = t103 * t515;
  t517 = 0.12e2 * t516;
  t519 = 0.24e2 * t26 * t436;
  t528 = t214 * params->beta;
  t530 = t209 * M_PI * t7 + 0.3e1 * t528;
  t533 = t236 * t32;
  t534 = t235 * t533;
  t535 = 0.4e1 * t534;
  t542 = t489 * t230;
  t544 = t224 * t504;
  t547 = t530 * t101 * t104;
  t549 = 0.2e1 * t233 * t239;
  t550 = t91 * t3;
  t551 = t103 * t550;
  t552 = 0.3e1 * t209 * t96 * t101 + 0.3e1 * t91 * t218 * t101 + t41 * t530 * t101 + 0.3e1 * t211 * t231 + 0.2e1 * t219 * t231 - t461 * t23 + t97 * t542 + t97 * t544 - t477 + t480 + t491 + t507 + t511 - t514 + t517 - t519 - t535 + t547 + t549 + t551;
  if(v4rho4 != NULL && (p->info->flags & XC_FLAGS_HAVE_LXC))
    v4rho4[0] = -0.31830988618379067153e0 * t207 - 0.31830988618379067153e0 * t247 + t2 * (-0.79577471545947667883e-1 * t473 * t14 - 0.79577471545947667883e-1 * t552 * t14);

  t559 = -t392 + t395 + t407 + t423 + t427 - t430 + t433 - t438 - t458 + t468 + t470;
  t561 = 0.24e2 * t459 * t9;
  t580 = 0.6e1 * t65 * t194 * t189 + t49 * t453 * t80 + 0.6e1 * t64 * t72 * t80 + t115 * t463 + t115 * t465 - 0.12e2 * t161 * t9 - 0.18e2 * t162 * t82 + 0.2e1 * t259 * t190 + 0.6e1 * t65 * t192 + t472 + t561;
  t584 = -t477 + t480 + t491 + t507 + t511 - t514 + t517 - t519 - t535 + t547 + t549;
  t586 = 0.24e2 * t459 * t23;
  t605 = t54 * t530 * t101 - 0.6e1 * t64 * t96 * t101 - 0.6e1 * t65 * t235 * t230 + 0.18e2 * t162 * t103 + t122 * t542 + t122 * t544 + 0.12e2 * t161 * t23 + 0.2e1 * t271 * t231 - 0.6e1 * t65 * t233 + t551 - t586;
  if(v4rho4 != NULL && (p->info->flags & XC_FLAGS_HAVE_LXC))
    v4rho4[1] = -t208 - t248 - 0.23873241463784300365e0 * t263 - 0.23873241463784300365e0 * t275 + t2 * (-0.79577471545947667883e-1 * (t559 + t580) * t14 - 0.79577471545947667883e-1 * (t584 + t605) * t14);

  t628 = 0.2e1 * t32 * M_PI * params->beta;
  t629 = t65 * t287;
  t630 = 0.2e1 * t629;
  t631 = t628 - t630 + t451;
  t637 = t162 * t139;
  t639 = t631 * t80 * t83 + t137 * t463 + t137 * t465 + t139 * t471 + t283 * t190 + 0.2e1 * t292 * t190 + 0.2e1 * t295 * t198 + 0.4e1 * t65 * t295 - 0.2e1 * t391 - 0.2e1 * t429 + 0.10e2 * t432 - t438 - 0.2e1 * t457 - 0.6e1 * t637;
  t650 = t295 * t200;
  t652 = t139 * t428;
  t654 = t139 * t431;
  t656 = t297 * t456;
  t661 = t291 * t182;
  t664 = t136 * t405;
  t669 = t132 * t173 * t80 + 0.2e1 * t64 * t136 * t80 + 0.4e1 * t65 * t297 * t189 + 0.2e1 * t281 * t72 * t80 + t49 * t631 * t80 + 0.2e1 * t661 * t196 + t664 * t196 + t297 * t422 + 0.2e1 * t297 * t425 + t561 - 0.2e1 * t650 - 0.2e1 * t652 + 0.2e1 * t654 - 0.2e1 * t656;
  t685 = -t628 + t630 + t528;
  t694 = t144 * t218 * t101 - 0.2e1 * t64 * t148 * t101 + 0.2e1 * t305 * t96 * t101 + t54 * t685 * t101 + t149 * t542 + t307 * t231 + 0.2e1 * t313 * t231 - 0.4e1 * t65 * t316 - 0.2e1 * t476 - 0.2e1 * t513 + 0.10e2 * t516 - t519 - 0.2e1 * t534 - t586;
  t701 = t162 * t151;
  t703 = t316 * t241;
  t705 = t151 * t512;
  t707 = t151 * t515;
  t709 = t318 * t533;
  t714 = t312 * t224;
  t717 = t148 * t489;
  t722 = t685 * t101 * t104 - 0.4e1 * t65 * t318 * t230 + t149 * t544 + t151 * t550 + 0.2e1 * t714 * t237 + t717 * t237 + 0.2e1 * t316 * t239 + t318 * t506 + 0.2e1 * t318 * t509 + 0.6e1 * t701 - 0.2e1 * t703 - 0.2e1 * t705 + 0.2e1 * t707 - 0.2e1 * t709;
  if(v4rho4 != NULL && (p->info->flags & XC_FLAGS_HAVE_LXC))
    v4rho4[2] = -0.15915494309189533577e0 * t263 - 0.15915494309189533577e0 * t275 - 0.15915494309189533577e0 * t303 - 0.15915494309189533577e0 * t324 + t2 * (-0.79577471545947667883e-1 * (t639 + t669) * t14 - 0.79577471545947667883e-1 * (t694 + t722) * t14);

  t734 = t183 * t186 * t49;
  t737 = t77 * t3 * t1;
  t741 = 0.2e1 * t34 * t75 * t342 + 0.4e1 * t183 * t737 + 0.4e1 * t413 + t419 + 0.4e1 * t734;
  t753 = 0.12e2 * t161 + 0.24e2 * t459;
  t767 = t336 * params->beta;
  t768 = 0.4e1 * t629;
  t769 = t281 * M_PI * t7 + t767 + t768;
  t775 = t348 * t200;
  t776 = t297 * t189 * t49 * t3 + t297 * t345 * t34 * t3 + t297 * t741 * t5 * t3 + 0.2e1 * t132 * t291 * t80 + 0.2e1 * t281 * t136 * t80 + t331 * t72 * t80 + t49 * t769 * t80 + t753 * t9 + 0.6e1 * t432 - t438 + 0.2e1 * t637 - 0.3e1 * t650 - 0.3e1 * t652 + 0.6e1 * t654 - t775;
  t778 = t139 * t49 * t32;
  t795 = t297 * t350 * t32;
  t799 = t339 * t182;
  t803 = t137 * t182 * t741 + t137 * t405 * t345 + 0.2e1 * t65 * t297 * t345 + t769 * t80 * t83 + 0.2e1 * t333 * t190 + t340 * t190 + t799 * t196 + t348 * t198 + t292 * t346 + t295 * t353 + 0.2e1 * t65 * t348 + t661 * t351 + t664 * t351 - 0.3e1 * t656 - t778 - t795;
  t811 = t318 * t378 * t32;
  t815 = t367 * t224;
  t823 = t225 * t186 * t54;
  t828 = 0.2e1 * t41 * t75 * t370 - 0.4e1 * t225 * t737 + 0.4e1 * t497 + t503 + 0.4e1 * t823;
  t848 = t364 * params->beta;
  t849 = t305 * M_PI * t7 - t768 + t848;
  t852 = t318 * t828 * t20 * t3 + t318 * t230 * t54 * t3 + t318 * t373 * t41 * t3 + 0.2e1 * t144 * t312 * t101 + 0.2e1 * t305 * t148 * t101 + t359 * t96 * t101 + t54 * t849 * t101 - 0.2e1 * t65 * t318 * t373 - t753 * t23 + t815 * t237 + t714 * t379 + t717 * t379 + 0.6e1 * t516 - t519 - t811;
  t857 = t376 * t241;
  t859 = t151 * t54 * t32;
  t875 = t849 * t101 * t104 + t149 * t224 * t828 + t149 * t489 * t373 + 0.2e1 * t361 * t231 + t368 * t231 + t376 * t239 + t313 * t374 + t316 * t381 - 0.2e1 * t65 * t376 - 0.2e1 * t701 - 0.3e1 * t703 - 0.3e1 * t705 + 0.6e1 * t707 - 0.3e1 * t709 - t857 - t859;
  if(v4rho4 != NULL && (p->info->flags & XC_FLAGS_HAVE_LXC))
    v4rho4[3] = -0.23873241463784300365e0 * t303 - 0.23873241463784300365e0 * t324 - t358 - t386 + t2 * (-0.79577471545947667883e-1 * (t776 + t803) * t14 - 0.79577471545947667883e-1 * (t852 + t875) * t14);

  t892 = 0.2e1 * t398 * t180 * t49 + t346 + t404;
  t895 = t49 * t49;
  t903 = 0.2e1 * t183 * t78 * t132 + 0.2e1 * t895 * t75 * t78 + t419 + 0.8e1 * t734;
  t912 = 0.24e2 * t161 + 0.24e2 * t459;
  t925 = t331 * M_PI * t7 + 0.3e1 * t767;
  t940 = -t438 - 0.4e1 * t795 + 0.12e2 * t654 - 0.4e1 * t775 - 0.4e1 * t778 + 0.2e1 * t799 * t351 + t136 * t892 * t351 + t297 * t903 * t5 * t3 + 0.2e1 * t297 * t345 * t49 * t3 + t912 * t9 + 0.3e1 * t333 * t346 + 0.2e1 * t340 * t346 + t137 * t892 * t345 + t137 * t182 * t903 + t925 * t80 * t83 + 0.2e1 * t348 * t353 + t139 * t132 * t3 + 0.3e1 * t331 * t136 * t80 + 0.3e1 * t132 * t339 * t80 + t49 * t925 * t80;
  t952 = 0.2e1 * t483 * t180 * t54 + t374 + t488;
  t955 = t54 * t54;
  t963 = 0.2e1 * t225 * t78 * t144 + 0.2e1 * t955 * t75 * t78 + t503 + 0.8e1 * t823;
  t984 = t359 * M_PI * t7 + 0.3e1 * t848;
  t999 = -t519 - 0.4e1 * t811 + 0.12e2 * t707 - 0.4e1 * t857 - 0.4e1 * t859 + 0.2e1 * t815 * t379 + t148 * t952 * t379 + t318 * t963 * t20 * t3 + 0.2e1 * t318 * t373 * t54 * t3 - t912 * t23 + 0.3e1 * t361 * t374 + 0.2e1 * t368 * t374 + t149 * t952 * t373 + t149 * t224 * t963 + t984 * t101 * t104 + 0.2e1 * t376 * t381 + t151 * t144 * t3 + 0.3e1 * t359 * t148 * t101 + 0.3e1 * t144 * t367 * t101 + t54 * t984 * t101;
  if(v4rho4 != NULL && (p->info->flags & XC_FLAGS_HAVE_LXC))
    v4rho4[4] = -0.31830988618379067153e0 * t357 - 0.31830988618379067153e0 * t385 + t2 * (-0.79577471545947667883e-1 * t940 * t14 - 0.79577471545947667883e-1 * t999 * t14);

#ifndef XC_DONT_COMPILE_MXC

  if(order < 5) return;


#endif

#endif

#endif

#endif

#endif


}
