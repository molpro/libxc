/*
 Copyright (C) 2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/*
  Well-behavedness scanner.

  Sweeps a functional over its input ingredients and flags any output --
  exc and EVERY derivative order compiled in for that functional (vxc, fxc,
  kxc, lxc) -- that is not finite, warning separately on values that are
  finite but enormous.  All output arrays are allocated and evaluated
  through libxc's own xc_mgga_vars_allocate_all_flags / _evaluate_functional
  machinery (which dispatches by family and sizes each array via func.dim),
  so the check covers exactly the generated expressions that exist.

  To stay inside the physically reachable region, points are sampled in the
  dimensionless reduced variables and converted to the raw ingredients,
  rather than sampling rho/sigma/tau independently (which would explore
  unphysical reduced gradients s ~ 1e13 etc.):

    per spin sigma:  reduced gradient s in [0, S_MAX]
                     |grad rho| = s * C_GRAD * rho^(4/3),  C_GRAD=2(6 pi^2)^(1/3)
    sigma_ab:        f * sqrt(sigma_aa*sigma_bb), f in [-1,1]  (Cauchy-Schwarz)
    per spin tau:    iso-orbital alpha in [0, ALPHA_MAX]  (alpha>=0 => FHC ok)
                     tau = (xs^2/8 + alpha*K_TAU) * rho^(5/3),  K_TAU=(3/10)(6 pi^2)^(2/3)
    per spin lapl:   reduced laplacian ul in [-UL_MAX, UL_MAX]  (signed)
                     lapl = ul * rho^(5/3)

  Modes: full Cartesian grid when its size <= GRID_BUDGET, otherwise Monte
  Carlo (reproducible splitmix64).

  Usage: xc-wellbehaved {<functional-id-or-name>|all} [unpol] [n_monte_carlo]
                        [seed=N] [order=N]
*/

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "util.h" /* xc_mgga_vars_allocate_all_flags etc.; pulls in xc.h */

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define HUGE_WARN 1e290
#define MAX_REPORT 30
#define GRID_BUDGET 2000000L
#define MC_DEFAULT 10000000L

/* physical envelope of the reduced variables */
#define S_MAX 30.0
#define ALPHA_MAX 10.0
#define UL_MAX 50.0
#define RHO_LO -10.0
#define RHO_HI 2.0
#define P_ZERO 0.03 /* probability of an exactly empty spin channel */
#define P_EQUAL 0.03 /* probability of an exactly spin-unpolarized point (z=0) */

/* --- reduced-variable grids (full-grid mode) --------------------------- */
static const double GRID_RHO[] = {0.0, 1e-8, 1e-5, 1e-2, 1e-1, 1.0, 1e1, 1e2};
static const double GRID_S[] = {0.0, 0.5, 1.0, 2.0, 5.0, 10.0, 20.0, 30.0};
static const double GRID_SABF[] = {-1.0, -0.5, 0.0, 0.5, 1.0};
static const double GRID_ALPHA[] = {0.0, 0.25, 0.5, 1.0, 2.0, 5.0, 10.0};
static const double GRID_UL[] = {-50.0, -10.0, -1.0, 0.0, 1.0, 10.0, 50.0};
#define NEL(a) ((int)(sizeof(a) / sizeof((a)[0])))

static double C_GRAD; /* 2*(6 pi^2)^(1/3) */
static double K_TAU;  /* (3/10)*(6 pi^2)^(2/3) */
static int max_order = 4; /* check up to this derivative order (capped by flags) */

/* --- running tallies --------------------------------------------------- */
static long n_points = 0, n_nan = 0, n_huge = 0, n_reported = 0;
static int detail = 1;

/* --- all output arrays (allocated once per functional) ----------------- */
static double *zk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA *, );
static struct {
  const char *name;
  const double *ptr;
  int n;
} out_list[80];
static int n_out;

/* --- splitmix64 PRNG --------------------------------------------------- */
static uint64_t seed0 = 0x123456789ABCDEFULL; /* fixed -> reproducible */
static uint64_t rng_state = 0x123456789ABCDEFULL;
static double
urand(void)
{
  uint64_t z = (rng_state += 0x9E3779B97F4A7C15ULL);
  z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
  z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
  z = z ^ (z >> 31);
  return (double)(z >> 11) * (1.0 / 9007199254740992.0);
}

/* --- reporting --------------------------------------------------------- */
static void
report(const char *kind, const char *quantity, int idx, const double rho[2],
       const double sig[3], const double lapl[2], const double tau[2],
       int mgga, int gga)
{
  if (!detail || n_reported >= MAX_REPORT)
    return;
  n_reported++;
  printf("  %-4s %s[%d] at rho=(%.4e,%.4e)", kind, quantity, idx, rho[0],
         rho[1]);
  if (gga)
    printf(" sigma=(%.4e,%.4e,%.4e)", sig[0], sig[1], sig[2]);
  if (mgga)
    printf(" lapl=(%.4e,%.4e) tau=(%.4e,%.4e)", lapl[0], lapl[1], tau[0],
           tau[1]);
  printf("\n");
}

static void
check(const char *quantity, const double *a, int n, const double rho[2],
      const double sig[3], const double lapl[2], const double tau[2],
      int mgga, int gga)
{
  int i;
  for (i = 0; i < n; i++) {
    if (isnan(a[i]) || isinf(a[i])) {
      n_nan++;
      report("NAN", quantity, i, rho, sig, lapl, tau, mgga, gga);
    } else if (fabs(a[i]) > HUGE_WARN) {
      n_huge++;
      report("HUGE", quantity, i, rho, sig, lapl, tau, mgga, gga);
    }
  }
}

/* --- evaluate one point and check every available output --------------- */
static void
eval_point(xc_func_type *f, double rho[2], double sig[3], double lapl[2],
           double tau[2])
{
  int fam = f->info->family, i;
  int gga = (fam == XC_FAMILY_GGA || fam == XC_FAMILY_HYB_GGA ||
             fam == XC_FAMILY_MGGA || fam == XC_FAMILY_HYB_MGGA);
  int mgga = (fam == XC_FAMILY_MGGA || fam == XC_FAMILY_HYB_MGGA);

  n_points++;
  xc_mgga_evaluate_functional(f, 1, rho, sig, lapl, tau,
                              zk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA, ));
  for (i = 0; i < n_out; i++)
    if (out_list[i].ptr != NULL)
      check(out_list[i].name, out_list[i].ptr, out_list[i].n, rho, sig, lapl,
            tau, mgga, gga);
}

/* reduced (rho, s, alpha, ul) per spin -> raw ingredients, then evaluate */
static void
build_and_eval(xc_func_type *f, int gga, int mgga, double ra, double sa,
               double aa, double ula, double rb, double sb, double ab,
               double ulb, double sabf)
{
  double rho[2] = {ra, rb};
  double sig[3] = {0, 0, 0}, lapl[2] = {0, 0}, tau[2] = {0, 0};

  if (gga) {
    double xa = sa * C_GRAD, xb = sb * C_GRAD;
    double ga = xa * pow(ra, 4.0 / 3.0), gb = xb * pow(rb, 4.0 / 3.0);
    sig[0] = ga * ga;
    sig[2] = gb * gb;
    sig[1] = sabf * sqrt(sig[0] * sig[2]);
    if (mgga) {
      tau[0] = (xa * xa / 8.0 + aa * K_TAU) * pow(ra, 5.0 / 3.0);
      tau[1] = (xb * xb / 8.0 + ab * K_TAU) * pow(rb, 5.0 / 3.0);
      lapl[0] = ula * pow(ra, 5.0 / 3.0);
      lapl[1] = ulb * pow(rb, 5.0 / 3.0);
    }
  }
  eval_point(f, rho, sig, lapl, tau);
}

/* --- full Cartesian-grid sweep ----------------------------------------- */
static void
scan_grid(xc_func_type *f, int gga, int mgga)
{
  int ia, ib, isa, isb, iab, iaa2, iab2, iula, iulb;
  for (ia = 0; ia < NEL(GRID_RHO); ia++)
  for (ib = 0; ib < NEL(GRID_RHO); ib++) {
    double ra = GRID_RHO[ia], rb = GRID_RHO[ib];
    if (!gga) {
      build_and_eval(f, gga, mgga, ra, 0, 0, 0, rb, 0, 0, 0, 0);
      continue;
    }
    for (isa = 0; isa < NEL(GRID_S); isa++)
    for (isb = 0; isb < NEL(GRID_S); isb++)
    for (iab = 0; iab < NEL(GRID_SABF); iab++) {
      double sa = GRID_S[isa], sb = GRID_S[isb], sabf = GRID_SABF[iab];
      if (!mgga) {
        build_and_eval(f, gga, mgga, ra, sa, 0, 0, rb, sb, 0, 0, sabf);
        continue;
      }
      for (iaa2 = 0; iaa2 < NEL(GRID_ALPHA); iaa2++)
      for (iab2 = 0; iab2 < NEL(GRID_ALPHA); iab2++)
      for (iula = 0; iula < NEL(GRID_UL); iula++)
      for (iulb = 0; iulb < NEL(GRID_UL); iulb++)
        build_and_eval(f, gga, mgga, ra, sa, GRID_ALPHA[iaa2], GRID_UL[iula],
                       rb, sb, GRID_ALPHA[iab2], GRID_UL[iulb], sabf);
    }
  }
}

/* --- Monte-Carlo sweep ------------------------------------------------- */
static double
rho_sample(void)
{
  return (urand() < P_ZERO)
             ? 0.0
             : pow(10.0, RHO_LO + urand() * (RHO_HI - RHO_LO));
}

static void
scan_monte_carlo(xc_func_type *f, int gga, int mgga, long ntrials)
{
  long t;
  for (t = 0; t < ntrials; t++) {
    double ra = rho_sample(), rb = rho_sample();
    /* occasionally force an exactly spin-unpolarized point (zeta = 0); the
       channels are otherwise sampled independently, so rho_a == rho_b has
       measure zero and the z->0 branch of some functionals would be missed */
    if (urand() < P_EQUAL)
      rb = ra;
    double sa = 0, sb = 0, aa = 0, ab = 0, ula = 0, ulb = 0, sabf = 0;
    if (gga) {
      sa = urand() * S_MAX;
      sb = urand() * S_MAX;
      sabf = 2.0 * urand() - 1.0;
    }
    if (mgga) {
      aa = urand() * ALPHA_MAX;
      ab = urand() * ALPHA_MAX;
      ula = (2.0 * urand() - 1.0) * UL_MAX;
      ulb = (2.0 * urand() - 1.0) * UL_MAX;
    }
    build_and_eval(f, gga, mgga, ra, sa, aa, ula, rb, sb, ab, ulb, sabf);
  }
}

static double
grid_size(int gga, int mgga)
{
  double n = (double)NEL(GRID_RHO) * NEL(GRID_RHO);
  if (gga)
    n *= (double)NEL(GRID_S) * NEL(GRID_S) * NEL(GRID_SABF);
  if (mgga)
    n *= (double)NEL(GRID_ALPHA) * NEL(GRID_ALPHA) * NEL(GRID_UL) *
         NEL(GRID_UL);
  return n;
}

/* build the (name, pointer, length) list of every allocated output array */
static void
build_out_list(const xc_func_type *f)
{
  n_out = 0;
#define ADD(nm)                                                                \
  do {                                                                         \
    out_list[n_out].name = #nm;                                                \
    out_list[n_out].ptr = nm;                                                  \
    out_list[n_out].n = (int)f->dim.nm;                                        \
    n_out++;                                                                   \
  } while (0)
  ADD(zk);
  ADD(vrho); ADD(vsigma); ADD(vlapl); ADD(vtau);
  ADD(v2rho2); ADD(v2rhosigma); ADD(v2rholapl); ADD(v2rhotau); ADD(v2sigma2);
  ADD(v2sigmalapl); ADD(v2sigmatau); ADD(v2lapl2); ADD(v2lapltau); ADD(v2tau2);
  ADD(v3rho3); ADD(v3rho2sigma); ADD(v3rho2lapl); ADD(v3rho2tau);
  ADD(v3rhosigma2); ADD(v3rhosigmalapl); ADD(v3rhosigmatau); ADD(v3rholapl2);
  ADD(v3rholapltau); ADD(v3rhotau2); ADD(v3sigma3); ADD(v3sigma2lapl);
  ADD(v3sigma2tau); ADD(v3sigmalapl2); ADD(v3sigmalapltau); ADD(v3sigmatau2);
  ADD(v3lapl3); ADD(v3lapl2tau); ADD(v3lapltau2); ADD(v3tau3);
  ADD(v4rho4); ADD(v4rho3sigma); ADD(v4rho3lapl); ADD(v4rho3tau);
  ADD(v4rho2sigma2); ADD(v4rho2sigmalapl); ADD(v4rho2sigmatau);
  ADD(v4rho2lapl2); ADD(v4rho2lapltau); ADD(v4rho2tau2); ADD(v4rhosigma3);
  ADD(v4rhosigma2lapl); ADD(v4rhosigma2tau); ADD(v4rhosigmalapl2);
  ADD(v4rhosigmalapltau); ADD(v4rhosigmatau2); ADD(v4rholapl3);
  ADD(v4rholapl2tau); ADD(v4rholapltau2); ADD(v4rhotau3); ADD(v4sigma4);
  ADD(v4sigma3lapl); ADD(v4sigma3tau); ADD(v4sigma2lapl2); ADD(v4sigma2lapltau);
  ADD(v4sigma2tau2); ADD(v4sigmalapl3); ADD(v4sigmalapl2tau);
  ADD(v4sigmalapltau2); ADD(v4sigmatau3); ADD(v4lapl4); ADD(v4lapl3tau);
  ADD(v4lapl2tau2); ADD(v4lapltau3); ADD(v4tau4);
#undef ADD
}

/* scan one functional; -1 if it cannot be initialised, else 1 if any
   non-finite output was seen and 0 otherwise */
static int
scan_one(int id, int nspin, long mc)
{
  xc_func_type func;
  int fam, gga, mgga, flags;
  double ngrid;

  if (id <= 0 || xc_func_init(&func, id, nspin) != 0)
    return -1;

  n_points = n_nan = n_huge = n_reported = 0;
  rng_state = seed0;

  fam = func.info->family;
  flags = func.info->flags;
  gga = (fam == XC_FAMILY_GGA || fam == XC_FAMILY_HYB_GGA ||
         fam == XC_FAMILY_MGGA || fam == XC_FAMILY_HYB_MGGA);
  mgga = (fam == XC_FAMILY_MGGA || fam == XC_FAMILY_HYB_MGGA);
  ngrid = grid_size(gga, mgga);

  /* allocate every output up to the requested order that the functional
     actually provides -- gate each order by both the order cap and the
     functional's HAVE_* flag (the flags ARE the compiled-in order), so we
     never ask evaluate_functional for a derivative it does not implement */
  zk MGGA_OUT_PARAMS_NO_EXC(=, ) = NULL;
  xc_mgga_vars_allocate_all_flags(
      fam, 1, &func.dim, (flags & XC_FLAGS_HAVE_EXC) != 0,
      (max_order >= 1) && (flags & XC_FLAGS_HAVE_VXC) != 0,
      (max_order >= 2) && (flags & XC_FLAGS_HAVE_FXC) != 0,
      (max_order >= 3) && (flags & XC_FLAGS_HAVE_KXC) != 0,
      (max_order >= 4) && (flags & XC_FLAGS_HAVE_LXC) != 0,
      &zk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA &, ), flags);
  build_out_list(&func);

  if (detail) {
    printf("Scanning %s (id %d, %s, orders<=%d)\n", func.info->name, id,
           nspin == XC_POLARIZED ? "polarized" : "unpolarized", max_order);
    if (mc > 0 || ngrid > (double)GRID_BUDGET)
      printf("Mode: Monte Carlo, %ld trials (full grid would be %.3g points)\n",
             (mc > 0) ? mc : MC_DEFAULT, ngrid);
    else
      printf("Mode: full grid, %.0f points\n", ngrid);
  }

  if (mc > 0 || ngrid > (double)GRID_BUDGET)
    scan_monte_carlo(&func, gga, mgga, (mc > 0) ? mc : MC_DEFAULT);
  else
    scan_grid(&func, gga, mgga);

  if (detail) {
    printf("Scanned %ld points: %ld non-finite, %ld huge (>%.0e)\n", n_points,
           n_nan, n_huge, HUGE_WARN);
    if (n_reported >= MAX_REPORT)
      printf("(report truncated at %d offending points)\n", MAX_REPORT);
  } else if (n_nan > 0 || n_huge > 0) {
    printf("FAIL id=%-4d %-48s %ld non-finite, %ld huge\n", id,
           func.info->name, n_nan, n_huge);
  }

  xc_mgga_vars_free_all_flags(zk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA, ), flags);
  xc_func_end(&func);
  return (n_nan > 0) ? 1 : 0;
}

int
main(int argc, char *argv[])
{
  int nspin = XC_POLARIZED, i;
  long mc = 0;

  C_GRAD = 2.0 * pow(6.0 * M_PI * M_PI, 1.0 / 3.0);
  K_TAU = 0.3 * pow(6.0 * M_PI * M_PI, 2.0 / 3.0);

  if (argc < 2) {
    fprintf(stderr,
            "usage: %s {<functional-id-or-name>|all} [unpol] [n_monte_carlo] "
            "[seed=N] [order=N]\n",
            argv[0]);
    return 2;
  }
  for (i = 2; i < argc; i++) {
    if (strcmp(argv[i], "unpol") == 0)
      nspin = XC_UNPOLARIZED;
    else if (strncmp(argv[i], "seed=", 5) == 0)
      seed0 = strtoull(argv[i] + 5, NULL, 0);
    else if (strncmp(argv[i], "order=", 6) == 0)
      max_order = atoi(argv[i] + 6);
    else
      mc = atol(argv[i]);
  }

  if (strcmp(argv[1], "all") == 0) {
    int n = xc_number_of_functionals(), k, nscanned = 0, nfail = 0, rc;
    int *list = (int *)malloc((size_t)n * sizeof(int));
    if (list == NULL)
      return 2;
    xc_available_functional_numbers(list);
    detail = 0;
    printf("Sweeping %d functionals (%s, orders<=%d, seed=0x%llx)\n", n,
           nspin == XC_POLARIZED ? "polarized" : "unpolarized", max_order,
           (unsigned long long)seed0);
    /* fork per functional so an assert()/SIGSEGV -- itself a
       well-behavedness failure -- is isolated and reported, not fatal */
    for (k = 0; k < n; k++) {
      pid_t pid;
      int status;
      fflush(stdout);
      pid = fork();
      if (pid == 0) {
        rc = scan_one(list[k], nspin, mc);
        fflush(stdout);
        _exit(rc < 0 ? 2 : rc);
      }
      if (pid < 0 || waitpid(pid, &status, 0) < 0) {
        fprintf(stderr, "fork/waitpid failed for id %d\n", list[k]);
        continue;
      }
      if (WIFSIGNALED(status)) {
        printf("CRASH id=%-4d %-48s signal %d\n", list[k],
               xc_functional_get_name(list[k]), WTERMSIG(status));
        nscanned++;
        nfail++;
      } else if (WIFEXITED(status)) {
        int e = WEXITSTATUS(status);
        if (e == 2)
          continue;
        nscanned++;
        if (e != 0)
          nfail++;
      }
    }
    free(list);
    printf("Swept %d functionals: %d with non-finite output\n", nscanned,
           nfail);
    return (nfail > 0) ? 1 : 0;
  } else {
    int id = atoi(argv[1]);
    int rc;
    if (id == 0)
      id = xc_functional_get_number(argv[1]);
    rc = scan_one(id, nspin, mc);
    if (rc < 0) {
      fprintf(stderr, "could not initialise functional '%s'\n", argv[1]);
      return 2;
    }
    return rc;
  }
}
