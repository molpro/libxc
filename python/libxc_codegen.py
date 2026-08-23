"""
Public API for libxc Python math definitions.

Mirrors maple/util.mpl: provides the symbolic primitives (constants,
my_piecewise3, lda_x_spin, gga_exchange, ...) used inside the per-functional
math files at python/<family>/<name>.py.

Adding a new functional:
    1. Write python/<family>/<name>.py mirroring maple/<family>/<name>.mpl.
    2. Run `python3 scripts/sympy2c/compile.py <name>` to regenerate
       src/maple2c/<family>/<name>.c.
"""

from __future__ import annotations

import inspect
import math
import os
import re
import sys
from contextlib import contextmanager
from functools import lru_cache, partial
from itertools import combinations_with_replacement, product

import sympy as sp

# Plain math functions re-exported so translated functional files (which
# use the Maple spellings) resolve them via `from libxc_codegen import *`.
from sympy import (  # noqa: F401
    exp, log, sqrt, sin, cos, tan, atan, atan2, sinh, cosh, tanh,
    asinh, acosh, atanh, acsch, asech, acoth,
    erf, erfc, legendre, sech, csch, coth,
    chebyshevt, chebyshevu, LambertW, expint, polylog,
    Eq, Ne, And, Or, Not, Integer, Float, Rational,
)

# Pull in low-level codegen machinery from scripts/sympy2c.
_HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(_HERE, "..", "scripts", "sympy2c"))
from sympy2c import (  # noqa: E402
    LibxcCPrinter,
    cam_omega,
    cam_alpha,
    cam_beta,
    dens_threshold,
    my_piecewise3,
    my_piecewise5,
    simplify_conditions,
    zeta_threshold,
)
import helper as helper_mod  # noqa: E402
from helper import Helper, HelperCPrinter  # noqa: E402
import _cse_fast  # vendored cse: memoised node-count -> identical output, faster


# ============================================================================
# Maple-equivalent primitives (mirrors maple/util.mpl)
# ============================================================================

# libxc per-functional runtime quantities (Maple uses the p_a_* names).
p_a_zeta_threshold = zeta_threshold
p_a_dens_threshold = dens_threshold
p_a_cam_omega = cam_omega          # range-separation parameter omega
p_a_cam_alpha = cam_alpha          # CAM short-range mixing
p_a_cam_beta = cam_beta            # CAM long-range mixing
# the bare parameter struct pointer (passed to external
# routines such as case21's xbspline); prints as `params`.
params = sp.Symbol("params")

# DIMENSIONS / RS_FACTOR / LDA_X_FACTOR follow Maple util.mpl: the values
# depend on whether the functional being compiled declared
# xc_dimensions_1d / xc_dimensions_2d / (default) 3D. compile_module
# mutates these three module globals at the top of each compilation and
# restores them at the end; library helpers below look them up at call
# time so they pick up the per-functional setting automatically.
DIMENSIONS = 3

_RS_FACTOR_BY_DIM = {
    1: sp.Rational(1, 2),
    2: 1 / sp.sqrt(sp.pi),
    3: (sp.Rational(3, 4) / sp.pi) ** sp.Rational(1, 3),
}
RS_FACTOR = _RS_FACTOR_BY_DIM[3]

# Maple's Pi constant
pi = sp.pi

_M_CBRT3 = sp.Symbol("M_CBRT3", positive=True)
_M_CBRTPI = sp.Symbol("M_CBRTPI", positive=True)

X2S = sp.Rational(1, 2) * (sp.Integer(6) * sp.pi ** 2) ** sp.Rational(-1, 3)
X_FACTOR_C = (
    sp.Rational(3, 8) * sp.Integer(4) ** sp.Rational(2, 3) * _M_CBRT3 / _M_CBRTPI
)
# The 2D X factor symbol is bound further down (after Float etc. are in scope).
# _LDA_X_FACTOR_BY_DIM is populated at module-load completion (see below).
LDA_X_FACTOR = -X_FACTOR_C
K_FACTOR_C = sp.Rational(3, 10) * (sp.Integer(6) * sp.pi ** 2) ** sp.Rational(2, 3)

MU_GE = sp.Rational(10, 81)
MU_PBE = sp.Float("0.06672455060314922") * sp.pi ** 2 / 3
KAPPA_PBE = sp.Float("0.8040")


# ============================================================================
# Plain math functions (inlined into top-level expressions, no separate C fn)
# ============================================================================

def r_ws(n):
    return RS_FACTOR / n ** sp.Rational(1, DIMENSIONS)


def n_total(rs):
    return (RS_FACTOR / rs) ** DIMENSIONS


def n_spin(rs, z):
    return (1 + z) * n_total(rs) / 2


# Spin-density screening (set by the codegen around assembly). When True,
# screen_dens emits its density as a symbolic marker _screen_dens(z) instead of
# n_spin(rs, z) = (1 +/- z)*nt/2. The marker is baked into @helper bodies at
# resolve time, survives inlining, and the codegen then resolves each
# _screen_dens(zform) -- on the fully inlined expression -- to the RAW channel
# density (na for the +z channel, nb for -z). This makes the empty-channel
# screen exact: at full polarization the reconstruction's 1 +/- z cancels and
# the work_* per-channel floor parks the empty channel exactly on dens_threshold,
# so the comparison flips; the raw channel density does not. Only the SCREEN
# uses the marker -- n_spin in energy contexts (e.g. OP's b88_zab, which calls
# n_spin at non-channel zeta) keeps its reconstruction, so energies are
# unchanged. Both the AD bridge and the legacy sp.diff emitter enable the mode
# around helper resolution and assembly; _resolve_screen_dens_kernel then resolves
# the markers on the assembled (na, nb) expression.
_SCREEN_DENS_MODE = False
_screen_dens_marker = sp.Function("_screen_dens")


@contextmanager
def _screen_dens_context(enabled=True):
    """Enable (or, with enabled=False, disable) spin-density screening for the
    block: screen_dens emits the _screen_dens(z) marker instead of the
    (1 +/- z)*nt/2 reconstruction. Used around @helper resolution and kernel
    assembly so helper-internal screens (e.g. b88_zab's per-channel screen) also
    get the marker. Disabled around the spin-scaled exchange/kinetic xchan
    construction: there the channel zeta is the literal +/-1 (exact, no
    cancellation), so the plain reconstruction already screens on the raw
    per-channel density and needs no marker (which xchan, built outside
    _kernel_clean, would otherwise leak unresolved)."""
    global _SCREEN_DENS_MODE
    saved = _SCREEN_DENS_MODE
    _SCREEN_DENS_MODE = enabled
    try:
        yield
    finally:
        _SCREEN_DENS_MODE = saved


def _resolve_screen_dens_kernel(expr, na, nb):
    """Resolve every _screen_dens(zform) marker on a fully assembled kernel
    expression (z already substituted to (na - nb)/(na + nb), so zform is in
    na/nb terms). Polarized: replace by the RAW channel density -- na for the +z
    channel, nb for -z, by the sign of zform at a generic point -- so the floored
    empty-channel screen is exact rather than the cancelling (1 +/- z)*nt/2.
    GUARDED: only when the raw density EQUALS the reconstruction at that generic
    point (confirming zform is a genuine channel zeta); a non-channel zeta keeps
    its reconstruction. Unpolarized (nb == 0): always the reconstruction (z = 0,
    no cancellation). Mirrors ad_bridge._resolve_screen_dens in (na, nb) space."""
    sd = _screen_dens_marker
    is_marker = lambda e: getattr(e, "is_Function", False) and e.func is sd
    if not expr.has(sd):
        return expr
    nt = na + nb
    recon = lambda zform: (1 + zform) * nt / 2
    if nb == 0 or nb is sp.S.Zero:
        return expr.replace(is_marker, lambda e: recon(e.args[0]))
    # generic interior point; the tiny threshold values fold any inlined z_thr
    # clamp (a my_piecewise5 over p_a_zeta_threshold) so float() succeeds.
    gen = {na: sp.Float("0.7"), nb: sp.Float("0.3"),
           p_a_zeta_threshold: sp.Float("1e-12"),
           p_a_dens_threshold: sp.Float("1e-12")}
    # z_thr is a library helper kept opaque in the legacy emitter, so it appears
    # as a z_thr(...) Function (not the inlined clamp). It is the identity in the
    # interior, so strip it for the generic-point sign/guard evaluation.
    strip = lambda e: e.replace(
        lambda x: getattr(x, "is_Function", False)
        and getattr(x.func, "__name__", "") == "z_thr",
        lambda x: x.args[0])

    def pick(e):
        zform = e.args[0]
        zz = strip(zform)
        try:
            sval = float(zz.subs(gen))
            recon_g = float(recon(zz).subs(gen))
        except (TypeError, ValueError):
            return recon(zform)
        raw = na if sval > 0 else nb if sval < 0 else (na + nb) / 2
        if abs(float(raw.subs(gen)) - recon_g) < 1e-9 * (abs(recon_g) + 1.0):
            return raw
        return recon(zform)

    return expr.replace(is_marker, pick)


def sigma_spin(rs, z, xs):
    return xs ** 2 * n_spin(rs, z) ** sp.Rational(8, 3)


def screen_dens(rs, z):
    dens = _screen_dens_marker(z) if _SCREEN_DENS_MODE else n_spin(rs, z)
    return sp.Le(dens, p_a_dens_threshold)


# ============================================================================
# Library helpers (built once at import; emitted as static inline C functions)
# ============================================================================

_LIBRARY_HELPERS = []


def _build_library_helper(name, args, expr, max_order=4):
    h = Helper(name, args, expr, max_order=max_order)
    _LIBRARY_HELPERS.append(h)
    return h


# opz_pow_n at exponent 4/3 (the only one the LDA/GGA-exchange path needs).
_z = sp.Symbol("z", real=True)
_opz_pow_n_4_3_helper = _build_library_helper(
    "opz_pow_n_4_3", [_z],
    my_piecewise3(
        sp.Le(1 + _z, p_a_zeta_threshold),
        p_a_zeta_threshold ** sp.Rational(4, 3),
        (1 + _z) ** sp.Rational(4, 3),
    ),
)


# Built lazily the first time a non-constant exponent is seen (lda_c_pk09's
# ss(rs,z), lda_xc_ksdt, lda_x_sloc), so functionals that never need it pay no
# build/emit cost. Created during helper resolution (before the order maps), so
# it lands in the library pool and is emitted normally.
_opz_pow_n_gen_helper = None


def opz_pow_n(z, n):
    """Mirrors maple opz_pow_n. n = 4/3 is a dedicated helper; any other
    *constant* exponent is inlined; a *non-constant* exponent routes through the
    2-arg opz_pow_n_gen helper so (1+z)^n -- and its log-laden high-order
    derivatives -- are differentiated once and chained, not re-expanded at every
    use (the dominant cost in lda_c_pk09's alpha_z)."""
    global _opz_pow_n_gen_helper
    n = sp.sympify(n)
    if n == sp.Rational(4, 3):
        return _opz_pow_n_4_3_helper.call(z)
    if n.is_number:
        # (1+z)^n = 1 + [(1+z)^n - 1], routed through the opz_pow_n_m1 helper.
        # That helper is a NON-INLINED @helper whose body is
        # expm1(n*log1p(m_max(z, thr-1))) -- no pow of (1+z) exists anywhere and
        # the clamp lives INSIDE log1p's argument, so the singular high
        # derivatives (1+z)^(n-2) = 0^(negative) = inf at full polarization
        # (z -> -1) never form, and being isolated in a helper the main body's
        # CSE cannot hoist them. This is the shared meta-GGA empty-spin-channel
        # v2rho2 NaN. Neither my_piecewise3(.., thr^n, (1+z)^n) nor a base clamp
        # m_max(1+z,thr)^n survive: the codegen distributes Pow back over the
        # piecewise, re-exposing a raw (1+z)^n branch whose derivative is inf.
        return 1 + opz_pow_n_m1(z, n)
    if _opz_pow_n_gen_helper is None:
        _zg = sp.Symbol("z", real=True)
        _ng = sp.Symbol("n", real=True)
        _opz_pow_n_gen_helper = _build_library_helper(
            "opz_pow_n_gen", [_zg, _ng],
            my_piecewise3(
                sp.Le(1 + _zg, p_a_zeta_threshold),
                p_a_zeta_threshold ** _ng,
                (1 + _zg) ** _ng,
            ),
        )
    return _opz_pow_n_gen_helper.call(z, n)


# z_thr -- zeta clamping helper.
_zz = sp.Symbol("z", real=True)
_z_thr_helper = _build_library_helper(
    "z_thr", [_zz],
    my_piecewise5(
        sp.Le(1 + _zz, p_a_zeta_threshold), p_a_zeta_threshold - 1,
        sp.Le(1 - _zz, p_a_zeta_threshold), 1 - p_a_zeta_threshold,
        _zz,
    ),
)


def z_thr(z):
    return _z_thr_helper.call(z)


# lda_x_spin -- per-spin Slater exchange. The 3D form is wrapped as a
# pre-baked library helper so that 3D GGAs share one C function for all
# their lda_x_spin calls. Other dimensions inline the expression because
# (i) opz_pow_n's helper covers only the 4/3 exponent and (ii) only a
# handful of 2D/1D functionals exist, so code-size pressure is minimal.
_rs = sp.Symbol("rs", positive=True)
_zs = sp.Symbol("z", real=True)
_lda_x_spin_helper = _build_library_helper(
    "lda_x_spin", [_rs, _zs],
    -X_FACTOR_C
    * _opz_pow_n_4_3_helper.call(_zs)
    * sp.Integer(2) ** sp.Rational(-4, 3)
    * ((sp.Rational(3, 4) / sp.pi) ** sp.Rational(1, 3))
    / _rs,
)


def lda_x_spin(rs, z):
    if DIMENSIONS == 3:
        return _lda_x_spin_helper.call(rs, z)
    exp_n = sp.Integer(1) + sp.Rational(1, DIMENSIONS)
    return (LDA_X_FACTOR
            * opz_pow_n(z, exp_n)
            * sp.Integer(2) ** (-exp_n)
            * RS_FACTOR
            / rs)


def lda_exchange(rs, z):
    """Mirrors maple lda_exchange: separable LDA exchange -- the per-spin LDA
    exchange of both channels, screened. No enhancement (LDA has no reduced
    gradient), so unlike gga/mgga_exchange it takes no func."""
    return (
        my_piecewise3(screen_dens(rs,  z), 0, lda_x_spin(rs,  z))
      + my_piecewise3(screen_dens(rs, -z), 0, lda_x_spin(rs, -z))
    )


def gga_exchange(func, rs, z, xs0, xs1):
    """Mirrors maple gga_exchange: separable GGA exchange."""
    return (
        my_piecewise3(screen_dens(rs,  z), 0,
                       lda_x_spin(rs, z_thr( z)) * func(xs0))
      + my_piecewise3(screen_dens(rs, -z), 0,
                       lda_x_spin(rs, z_thr(-z)) * func(xs1))
    )


# ============================================================================
# Further maple/util.mpl primitives
# ============================================================================
#
# Maple's series machinery (padding_order, throw_out_large_n,
# enforce_smooth_lr, f_large) is intentionally not mirrored here: it relies
# on Maple's symbolic `series`/`convert`/`degree` and needs a separate
# SymPy design. Functionals using it stay on the manual-port list.

_R3 = sp.Rational           # local shorthand

# --- physical / numerical constants ---
M_C = sp.Float("137.0359996287515")              # speed of light
XT2S = _R3(1, 2) * (sp.Integer(3) * sp.pi**2) ** _R3(-1, 3)
X2S_2D = _R3(1, 2) * (sp.Integer(4) * sp.pi) ** _R3(-1, 2)
X_FACTOR_2D_C = sp.Integer(8) / (3 * sp.sqrt(sp.pi))

# Precision-abstract machine epsilon and minimum-normal symbols. The
# functional sources reference these names so a future single- or
# extended-precision libxc build can just redefine the underlying C
# macros (see src/util.h: XC_EPSILON / XC_MIN), leaving every Maple
# and SymPy source unchanged.
XC_EPSILON = sp.Symbol("XC_EPSILON", positive=True)
XC_MIN = sp.Symbol("XC_MIN", positive=True)


# Dimension -> LDA exchange factor. The 1D entry is omitted -- maple's
# util.mpl leaves LDA_X_FACTOR undefined in 1D, and any 1D functional
# that wants exchange must supply its own normalisation.
_LDA_X_FACTOR_BY_DIM = {
    2: -X_FACTOR_2D_C,
    3: -X_FACTOR_C,
}


def _set_dimension(dim):
    """Mutate the dimension-sensitive module globals (DIMENSIONS,
    RS_FACTOR, LDA_X_FACTOR) so that library helpers called from
    functional bodies pick up the correct dimension. Returns the
    previous (dim, rs, lda_x) tuple so the caller can restore it."""
    global DIMENSIONS, RS_FACTOR, LDA_X_FACTOR
    prev = (DIMENSIONS, RS_FACTOR, LDA_X_FACTOR)
    DIMENSIONS = dim
    RS_FACTOR = _RS_FACTOR_BY_DIM[dim]
    LDA_X_FACTOR = _LDA_X_FACTOR_BY_DIM.get(dim, prev[2])
    return prev


def _restore_dimension(prev):
    global DIMENSIONS, RS_FACTOR, LDA_X_FACTOR
    DIMENSIONS, RS_FACTOR, LDA_X_FACTOR = prev


def _detect_dimension(mod):
    if getattr(mod, "_macro_xc_dimensions_1d", False):
        return 1
    if getattr(mod, "_macro_xc_dimensions_2d", False):
        return 2
    return 3


# --- differentiable min / max / abs (mirror m_min, m_max, m_abs) ---
def m_min(x1, x2):
    return my_piecewise3(sp.Gt(x1, x2), x2, x1)


def m_max(x1, x2):
    return my_piecewise3(sp.Gt(x1, x2), x1, x2)


def m_abs(x):
    return my_piecewise3(sp.Ge(x, 0), x, -x)


def m_recexp(x):
    """exp(-1/x), made well-behaved as x -> 0."""
    cut = -1 / sp.log(XC_EPSILON)
    return my_piecewise3(sp.Le(x, cut), 0, sp.exp(-1 / m_max(cut, x)))


# --- spin-resolved kinetic / laplacian aggregates ---
def t_total(z, ts0, ts1):
    # Route (1+-z)^(5/3) through opz_pow_n (clamped via the opz_pow_n_m1 helper),
    # NOT raw ((1+-z)/2)^(5/3): the raw power's second z-derivative diverges like
    # (1+-z)^(-1/3) at full polarization (z -> -+1), giving 0*inf = NaN in v2rho2
    # at an empty spin channel in EVERY meta-GGA correlation built on t_total
    # (via mgga_alpha_total_reg / t_vw). Matches maple/util.mpl; value-identical
    # above p_a_zeta_threshold. ((1+-z)/2)^(5/3) = (1+-z)^(5/3) / 2^(5/3).
    return (ts0 * opz_pow_n(z, _R3(5, 3))
            + ts1 * opz_pow_n(-z, _R3(5, 3))) / sp.Integer(2) ** _R3(5, 3)


def u_total(z, us0, us1):
    return t_total(z, us0, us1)


def t_vw(z, xt2, us0, us1):
    """von Weizsaecker term. Takes the SQUARED total reduced gradient xt2 = xt**2
    (= sigma_total/rho_total**(8/3), rational in sigma), NOT xt: a functional
    linear in the vW term (lp90, zlp, cs) then has v2sigma2 exactly zero and stays
    cancellation-free. Passing xt would route the sigma chain rule through
    d(sqrt(sigma)), whose 1/sigma terms cancel only in exact arithmetic and blow
    up at a small gradient. Callers pass xt**2 across their opaque-helper
    boundary."""
    return (xt2 - u_total(z, us0, us1)) / 8


# --- zeta-interpolation functions ---
# f_zeta lives in the appendix as a @helper (next to one_minus_f_zeta): its
# cancellation-free body is an exp(log1p) chain whose 4th-order derivatives
# explode when inlined at every call site -- as an opaque helper it is
# differentiated ONCE into four small slots. Module-level names resolve at
# call time, so every user in this file and in the math modules finds it.


def f_zeta_2d(z):
    return _R3(1, 2) * (opz_pow_n(z, _R3(3, 2)) + opz_pow_n(-z, _R3(3, 2)))


def mphi(z):
    return (opz_pow_n(z, _R3(2, 3)) + opz_pow_n(-z, _R3(2, 3))) / 2


def tt(rs, z, xt):
    return xt / (4 * sp.Integer(2) ** _R3(1, 3) * mphi(z) * sp.sqrt(rs))


def beta_Hu_Langreth(rs):
    return (sp.Float("0.066724550603149220") * (1 + sp.Float("0.1") * rs)
            / (1 + sp.Float("0.1778") * rs))


# --- per-spin Slater (Thomas-Fermi) LDA kinetic energy ---
# Inlined rather than registered as a library helper: library helpers
# are emitted into every generated functional, and lda_k_spin is only
# used by kinetic functionals -- registering it would dump dead code
# into every exchange/correlation file.
def lda_k_spin(rs, z):
    return (K_FACTOR_C * opz_pow_n(z, _R3(5, 3))
            * sp.Integer(2) ** _R3(-5, 3) * (RS_FACTOR / rs) ** 2)


def screen_dens_zeta(rs, z):
    return sp.Or(screen_dens(rs, z), sp.Le(1 + z, p_a_zeta_threshold))


# --- spin-scaling wrappers ---
def gga_exchange_nsp(func, rs, z, xs0, xs1):
    """Non-separable GGA exchange (func also receives rs, z)."""
    return (
        my_piecewise3(screen_dens(rs,  z), 0,
                      lda_x_spin(rs, z_thr( z)) * func(rs, z_thr( z), xs0))
      + my_piecewise3(screen_dens(rs, -z), 0,
                      lda_x_spin(rs, z_thr(-z)) * func(rs, z_thr(-z), xs1))
    )


def gga_kinetic(func, rs, z, xs0, xs1):
    """Separable GGA kinetic energy."""
    return (
        my_piecewise3(screen_dens(rs,  z), 0,
                      lda_k_spin(rs, z_thr( z)) * func(xs0))
      + my_piecewise3(screen_dens(rs, -z), 0,
                      lda_k_spin(rs, z_thr(-z)) * func(xs1))
    )


def gga_exchange_p(func, rs, z, xs0, xs1):
    """Separable GGA exchange with the enhancement expressed in the SQUARE of
    the reduced gradient: func receives xs**2 instead of xs.

    For a functional that depends on the reduced gradient only through xs**2
    (the physical gradient-expansion variable), this keeps every sigma
    derivative cancellation-free. The kernel substitutes xs = sqrt(gaa)/na**k,
    so xs**2 = gaa/na**(2k) is rational in gaa; the opaque enhancement is then
    differentiated with respect to gaa/na**(2k) rather than sqrt(gaa)/na**k, and
    no half-integer power of gaa (1/sqrt(gaa), 1/gaa**(3/2), ...) ever enters.
    Passing xs itself makes the chain rule route through d(sqrt(gaa)) and the
    resulting 1/gaa**(k/2) terms cancel only in exact arithmetic, losing all
    accuracy in the second and higher derivatives at low density."""
    return (
        my_piecewise3(screen_dens(rs,  z), 0,
                      lda_x_spin(rs, z_thr( z)) * func(xs0**2))
      + my_piecewise3(screen_dens(rs, -z), 0,
                      lda_x_spin(rs, z_thr(-z)) * func(xs1**2))
    )


def gga_kinetic_p(func, rs, z, xs0, xs1):
    """Separable GGA kinetic energy with the enhancement expressed in xs**2.
    See gga_exchange_p for why feeding the squared reduced gradient makes the
    sigma derivatives cancellation-free."""
    return (
        my_piecewise3(screen_dens(rs,  z), 0,
                      lda_k_spin(rs, z_thr( z)) * func(xs0**2))
      + my_piecewise3(screen_dens(rs, -z), 0,
                      lda_k_spin(rs, z_thr(-z)) * func(xs1**2))
    )


def gga_exchange_nsp_p(func, rs, z, xs0, xs1):
    """Non-separable GGA exchange (func also receives rs, z) with the
    enhancement expressed in xs**2. See gga_exchange_p."""
    return (
        my_piecewise3(screen_dens(rs,  z), 0,
                      lda_x_spin(rs, z_thr( z)) * func(rs, z_thr( z), xs0**2))
      + my_piecewise3(screen_dens(rs, -z), 0,
                      lda_x_spin(rs, z_thr(-z)) * func(rs, z_thr(-z), xs1**2))
    )


def mgga_exchange(func, rs, z, xs0, xs1, u0, u1, t0, t1):
    """Separable meta-GGA exchange."""
    return (
        my_piecewise3(screen_dens(rs,  z), 0,
                      lda_x_spin(rs, z_thr( z)) * func(xs0, u0, t0))
      + my_piecewise3(screen_dens(rs, -z), 0,
                      lda_x_spin(rs, z_thr(-z)) * func(xs1, u1, t1))
    )


def mgga_exchange_nsp(func, rs, z, xs0, xs1, u0, u1, t0, t1):
    """Non-separable meta-GGA exchange (func also receives rs, z)."""
    return (
        my_piecewise3(screen_dens(rs,  z), 0,
                      lda_x_spin(rs, z_thr( z))
                      * func(rs, z_thr( z), xs0, u0, t0))
      + my_piecewise3(screen_dens(rs, -z), 0,
                      lda_x_spin(rs, z_thr(-z))
                      * func(rs, z_thr(-z), xs1, u1, t1))
    )


def mgga_kinetic(func, rs, z, xs0, xs1, u0, u1):
    """Separable meta-GGA kinetic energy."""
    return (
        my_piecewise3(screen_dens(rs,  z), 0,
                      lda_k_spin(rs, z_thr( z)) * func(xs0, u0))
      + my_piecewise3(screen_dens(rs, -z), 0,
                      lda_k_spin(rs, z_thr(-z)) * func(xs1, u1))
    )


def mgga_exchange_p(func, rs, z, xs0, xs1, u0, u1, t0, t1):
    """Separable meta-GGA exchange with the reduced gradient passed as the
    squared value p = mgga_p(xs) = s**2 instead of xs. p = X2S**2*gaa/na**(8/3)
    is rational in sigma (the sqrt(gaa) folds), so the opaque enhancement is
    differentiated with respect to it and the sigma derivatives stay
    cancellation-free -- see gga_exchange_p. The laplacian u and tau t carry no
    sqrt and are passed unchanged. Use for functionals whose gradient
    dependence is through s**2 only. mgga_p (= s**2) is inlined, so mgga_p(xs)
    folds the sqrt at the expression level."""
    return (
        my_piecewise3(screen_dens(rs,  z), 0,
                      lda_x_spin(rs, z_thr( z)) * func(mgga_p(xs0), u0, t0))
      + my_piecewise3(screen_dens(rs, -z), 0,
                      lda_x_spin(rs, z_thr(-z)) * func(mgga_p(xs1), u1, t1))
    )


def mgga_kinetic_p(func, rs, z, xs0, xs1, u0, u1):
    """Separable meta-GGA kinetic energy with the reduced gradient passed as
    p = mgga_p(xs) = s**2. See mgga_exchange_p."""
    return (
        my_piecewise3(screen_dens(rs,  z), 0,
                      lda_k_spin(rs, z_thr( z)) * func(mgga_p(xs0), u0))
      + my_piecewise3(screen_dens(rs, -z), 0,
                      lda_k_spin(rs, z_thr(-z)) * func(mgga_p(xs1), u1))
    )


# --- Stoll decomposition ---
def lda_stoll_par(lda_func, rs, z, *_ignored):
    # Maple `->` procedures silently ignore surplus arguments; some
    # callers (mgga_c_bc95, ...) pass a 4th `spin` argument that
    # util.mpl's 3-parameter lda_stoll_par never uses.
    return my_piecewise3(
        screen_dens_zeta(rs, z), 0,
        opz_pow_n(z, 1) / 2
        * lda_func(rs * sp.Integer(2) ** _R3(1, 3) * opz_pow_n(z, _R3(-1, 3)), 1))


def lda_stoll_perp(lda_func, rs, z):
    return (lda_func(rs, z)
            - lda_stoll_par(lda_func, rs,  z)
            - lda_stoll_par(lda_func, rs, -z))


def gga_stoll_par(gga_func, rs, z, xs, spin):
    return my_piecewise3(
        screen_dens_zeta(rs, z), 0,
        gga_func(rs * sp.Integer(2) ** _R3(1, 3) * opz_pow_n(z, _R3(-1, 3)),
                 spin, xs, xs * (1 + spin) / 2, xs * (1 - spin) / 2)
        * opz_pow_n(z, 1) / 2)


# --- curvature of the Fermi hole ---
def Fermi_D(xs, ts):
    # Single-fraction form, mirroring util.mpl: cancellation-free at the
    # iso-orbital limit xs^2/(8*ts) -> 1 where 1 - close-to-1 loses all
    # significant digits.
    return (8 * ts - xs**2) / (8 * ts)


def Fermi_D_corrected(xs, ts):
    cnst = param("Fermi_D_cnst")
    return Fermi_D(xs, ts) * (-xc_expm1(-4 * ts**2 / cnst**2))


# --- Becke R_F factors used in several correlation functionals ---
def b88_R_F(f_x, rs, z, xs):
    return 1 / (2 * X_FACTOR_C * n_spin(rs, z) ** _R3(1, 3) * f_x(xs))


def b88_zss(css, f_x, rs, z, xs):
    return 2 * css * b88_R_F(f_x, rs, z, xs)


def b88_zab(cab, f_x, rs, z, xs0, xs1):
    return cab * (
        my_piecewise3(screen_dens(rs,  z), 0, b88_R_F(f_x, rs, z_thr( z), xs0))
      + my_piecewise3(screen_dens(rs, -z), 0, b88_R_F(f_x, rs, z_thr(-z), xs1)))


def b94_R_F(f_x, rs, z, xs, us, ts):
    return 1 / (2 * X_FACTOR_C * n_spin(rs, z) ** _R3(1, 3) * f_x(xs, us, ts))


def b94_zss(css, f_x, rs, z, xs, us, ts):
    return 2 * css * b94_R_F(f_x, rs, z, xs, us, ts)


def b94_zab(cab, f_x, rs, z, xs0, xs1, us0, us1, ts0, ts1):
    return cab * (
        my_piecewise3(screen_dens(rs,  z), 0,
                      b94_R_F(f_x, rs, z_thr( z), xs0, us0, ts0))
      + my_piecewise3(screen_dens(rs, -z), 0,
                      b94_R_F(f_x, rs, z_thr(-z), xs1, us1, ts1)))


# --- power series often used in meta-GGAs ---
def mgga_w(t):
    return (K_FACTOR_C - t) / (K_FACTOR_C + t)


def mgga_series_w(a, n, t):
    """Sum a[i]*mgga_w(t)^(i-1) for Maple 1-based i in 1..n. `a` is an
    array parameter or list literal; a raw Python list is wrapped so it
    too uses Maple 1-based indexing."""
    if isinstance(a, list):
        a = maple_list(a)
    return sum(a[i] * mgga_w(t) ** (i - 1) for i in range(1, n + 1))


# --- Fermi wavevector (used by screened functionals) ---
def kF(rs, z):
    return ((3 * sp.pi**2) ** _R3(1, 3) * opz_pow_n(z, _R3(1, 3))
            * RS_FACTOR / rs)

def nu(rs, z):
    """Maple nu: the range-separation parameter divided by the Fermi
    wavevector, used by screened functionals."""
    return p_a_cam_omega / kF(rs, z)


# ============================================================================
# Maple symbolic / series machinery
# ============================================================================
# A few functionals build a Taylor/series polynomial approximation of an
# otherwise ill-behaved branch. Maple does this with taylor/series +
# convert(...,polynom) + eval(...); these mirror those onto SymPy.

infinity = sp.oo
Symbol = sp.Symbol
Function = sp.Function
polynom = sp.Symbol("polynom")    # marker argument of convert(...)
csgn = sp.Function("csgn")        # Maple complex-sign function


# libxc special functions: opaque C routines whose derivatives util.mpl
# supplies through `diff/` rules. Each class also implements
# `_eval_evalf` so that scripts/sympy2c/eval_reference.py can compute
# them at arbitrary precision via the matching sympy / mpmath primitive
# -- crucial for the full kernel-vs-mpmath floating-point-accuracy
# pipeline (we don't want to leave these as opaque atoms in evalf).
class xc_E1_scaled(sp.Function):
    """exp(x) * E1(x); d/dy xc_E1_scaled(y) = xc_E1_scaled(y) - 1/y.

    SymPy equivalent: ``sp.exp(y) * sp.expint(1, y)``."""
    def fdiff(self, argindex=1):
        (y,) = self.args
        return _E1S_DERIV[1](y)

    def _eval_evalf(self, prec):
        (y,) = self.args
        return (sp.exp(y) * sp.expint(1, y))._eval_evalf(prec)


class xc_erfcx(sp.Function):
    """exp(x^2) * erfc(x); d/dy = 2*y*xc_erfcx(y) - 2/sqrt(pi).

    SymPy equivalent: ``sp.exp(y**2) * sp.erfc(y)``."""
    def fdiff(self, argindex=1):
        (y,) = self.args
        return _ERFCX_DERIV[1](y)

    def _eval_evalf(self, prec):
        (y,) = self.args
        return (sp.exp(y * y) * sp.erfc(y))._eval_evalf(prec)


class BesselI(sp.Function):
    """Modified Bessel function I_n(y). Backed by libxc's xc_bessel_I0 /
    xc_bessel_I1 (via the functional's `replace:` headers); derivatives
    use the recurrence I0' = I1, I1' = I0 - I1/y, staying within n=0,1.

    SymPy equivalent: ``sp.besseli(n, y)``."""
    def fdiff(self, argindex=1):
        n, y = self.args
        if argindex == 2:               # d/dy
            if n == 0:
                return BesselI(1, y)
            if n == 1:
                return BesselI(0, y) - BesselI(1, y) / y
        return sp.S.Zero                # order argument is not differentiated

    def _eval_evalf(self, prec):
        n, y = self.args
        return sp.besseli(n, y)._eval_evalf(prec)


class BesselK(sp.Function):
    """Modified Bessel function K_n(y), second kind. Backed by libxc's
    xc_bessel_K0 / xc_bessel_K1 (via the functional's `replace:`
    headers); derivatives use the recurrence K0' = -K1,
    K1' = -K0 - K1/y, staying within n=0,1.

    SymPy equivalent: ``sp.besselk(n, y)``."""
    def fdiff(self, argindex=1):
        n, y = self.args
        if argindex == 2:               # d/dy
            if n == 0:
                return -BesselK(1, y)
            if n == 1:
                return -BesselK(0, y) - BesselK(1, y) / y
        return sp.S.Zero                # order argument is not differentiated

    def _eval_evalf(self, prec):
        n, y = self.args
        return sp.besselk(n, y)._eval_evalf(prec)


class xc_dilogarithm(sp.Function):
    """Dilogarithm Li_2(y) = -integral_0^y log(1-t)/t dt. Backed by
    libxc's xc_dilogarithm C routine; the maple sources use the bare
    name ``dilog`` which mpl2py translates to this class.

    SymPy equivalent: ``sp.polylog(2, y)``."""
    def fdiff(self, argindex=1):
        (y,) = self.args
        # d/dy Li_2(y) = -log(1-y)/y; emitted via the isolated C jet-helper.
        return _DILOG_DERIV[1](y)

    def _eval_evalf(self, prec):
        (y,) = self.args
        return sp.polylog(2, y)._eval_evalf(prec)


def _make_deriv_classes(base_name, elem_fn, maxk=4):
    """Isolated-helper derivative classes xc_<base>_d1..dK for a special
    function with elementary form elem_fn(y). Each prints as the C jet-helper
    xc_<base>_dk(y); fdiff chains to the next order so sp.diff in the codegen
    emits helper calls instead of the inline (cancellation-prone) recurrence.
    _eval_evalf computes the TRUE k-th derivative at arbitrary precision via
    elem_fn, so eval_reference stays an INDEPENDENT oracle -- the references are
    bit-identical to before and the build-vs-reference check is not circular."""
    reg = {}
    yv = sp.Symbol("_deriv_y")
    for k in range(1, maxk + 1):
        elem_k = sp.diff(elem_fn(yv), yv, k)

        def _fdiff(self, argindex=1, _k=k):
            (y,) = self.args
            nxt = reg.get(_k + 1)
            return nxt(y) if nxt is not None else sp.diff(elem_fn(y), y, _k + 1)

        def _evalf(self, prec, _elem_k=elem_k):
            (y,) = self.args
            return _elem_k.subs(yv, y)._eval_evalf(prec)

        reg[k] = type("%s_d%d" % (base_name, k), (sp.Function,),
                      {"fdiff": _fdiff, "_eval_evalf": _evalf})
    return reg


# Derivative-helper registries (referenced by the base classes' fdiff above).
_ERFCX_DERIV = _make_deriv_classes("xc_erfcx", lambda y: sp.exp(y * y) * sp.erfc(y))
_E1S_DERIV = _make_deriv_classes("xc_E1_scaled", lambda y: sp.exp(y) * sp.expint(1, y))
_DILOG_DERIV = _make_deriv_classes("xc_dilogarithm", lambda y: sp.polylog(2, y))
_LAMBERTW_DERIV = _make_deriv_classes("xc_lambertw", lambda y: sp.LambertW(y))


def _lambertw_fdiff(self, argindex=1):
    (y,) = self.args
    return _LAMBERTW_DERIV[1](y)


def _lambertw_evalf(self, prec):
    (y,) = self.args
    return sp.LambertW(y)._eval_evalf(prec)


# Shadow the imported sympy LambertW with a same-named class whose derivatives
# emit the isolated C jet-helpers (xc_lambertw_dk). Generated modules pick this
# up via `from libxc_codegen import *`; it prints as "LambertW" (the C value) and
# the AD path still dispatches it by name. _eval_evalf keeps the true value so
# eval_reference stays an independent oracle. (Only internal uses of the name
# were the sympy import and a string literal, so shadowing is safe.)
LambertW = type("LambertW", (sp.Function,),
                {"fdiff": _lambertw_fdiff, "_eval_evalf": _lambertw_evalf})


zeta = sp.zeta                    # Maple's Riemann Zeta


def simplify(expr, *_options):
    """Mirror Maple's simplify: a form-only transformation. The
    generated code's value is unchanged and CSE handles the form, so
    for codegen this is the identity."""
    return expr


def evalf(x):
    """Maple evalf: force numeric evaluation of a constant expression."""
    return sp.sympify(x).evalf()


class _TSUnsupported(Exception):
    """Raised inside the fast formal-power-series evaluator when a node
    is not supported, so maple_taylor falls back to sp.series."""


# Fast truncated power/Laurent-series arithmetic. A series is a pair
# (val, c): val is an integer valuation and c a fixed-length list of
# coefficients, representing  var**val * sum_k c[k]*var**k. Division is
# always defined (Laurent field), so a removable 0/0 -- e.g. wpbeh's
# EG(s), whose float params leave a spurious ~1e-9 principal part -- just
# yields tiny negative-power terms that the downstream non-negative
# `coeff(.., k)` extraction discards, exactly as sp.series would. The
# point is speed: sp.series on these nested rational/erfc expressions is
# exponential (the gga_x_wpbeh / tpss "series perf wall"); this is the
# O(order**2) formal recurrence.

def _ts_norm(val, c, L):
    i = 0
    while i < len(c) and getattr(c[i], "is_zero", c[i] == 0):
        i += 1
    if i == 0:
        return (val, (c + [sp.S.Zero] * L)[:L])
    return (val + i, (c[i:] + [sp.S.Zero] * (i + L))[:L])


def _ts_const(x, L):
    return _ts_norm(0, [sp.sympify(x)] + [sp.S.Zero] * (L - 1), L)


def _ts_scale(A, k, L):
    return _ts_norm(A[0], [k * ci for ci in A[1]], L)


def _ts_add(A, B, L):
    v = min(A[0], B[0])
    c = [sp.S.Zero] * L
    for off, S in ((A[0] - v, A), (B[0] - v, B)):
        for k, ck in enumerate(S[1]):
            if k + off < L and ck != 0:
                c[k + off] += ck
    return _ts_norm(v, c, L)


def _ts_mul(A, B, L):
    c = [sp.S.Zero] * L
    for i, a in enumerate(A[1]):
        if a == 0:
            continue
        for j, b in enumerate(B[1]):
            if i + j >= L:
                break
            if b != 0:
                c[i + j] += a * b
    return _ts_norm(A[0] + B[0], c, L)


def _ts_inv_unit(c, L):
    if c[0] == 0:
        raise _TSUnsupported
    b = [sp.S.Zero] * L
    b[0] = sp.S.One / c[0]
    for k in range(1, L):
        s = sum(c[j] * b[k - j] for j in range(1, k + 1) if c[j] != 0)
        b[k] = -s / c[0]
    return b


def _ts_pow_unit(c, p, L):
    if c[0] == 0:
        raise _TSUnsupported
    b = [sp.S.Zero] * L
    b[0] = c[0] ** p
    for k in range(1, L):
        s = sum((p * i - (k - i)) * c[i] * b[k - i]
                for i in range(1, k + 1) if c[i] != 0)
        b[k] = s / (k * c[0])
    return b


def _ts_powc(A, p, L):
    p = sp.sympify(p)
    if p.is_Integer and p >= 0:
        out = _ts_const(1, L)
        base = A
        e = int(p)
        while e:
            if e & 1:
                out = _ts_mul(out, base, L)
            e >>= 1
            if e:
                base = _ts_mul(base, base, L)
        return out
    vp = A[0] * p
    if not vp.is_Integer:
        raise _TSUnsupported
    return _ts_norm(int(vp), _ts_pow_unit(A[1], p, L), L)


def _ts_regular(A, L):
    """Convert (val, c) with val >= 0 to an ordinary coefficient list
    L0..L_{L-1} (L0 is the value at var=0). val < 0 is a pole -> the
    composing transcendental is singular: unsupported."""
    if A[0] < 0:
        raise _TSUnsupported
    out = [sp.S.Zero] * L
    for k, ck in enumerate(A[1]):
        if A[0] + k < L:
            out[A[0] + k] = ck
    return out


def _ts_deriv_list(c):
    return [(m + 1) * c[m + 1] for m in range(len(c) - 1)] + [sp.S.Zero]


def _ts_exp(A, L):
    c = _ts_regular(A, L)
    b = [sp.S.Zero] * L
    b[0] = sp.exp(c[0])
    for k in range(1, L):
        s = sum(j * c[j] * b[k - j] for j in range(1, k + 1) if c[j] != 0)
        b[k] = s / k
    return _ts_norm(0, b, L)


def _ts_log(A, L):
    c = _ts_regular(A, L)
    if c[0] == 0:
        raise _TSUnsupported
    b = [sp.S.Zero] * L
    b[0] = sp.log(c[0])
    for k in range(1, L):
        s = k * c[k] - sum(j * b[j] * c[k - j] for j in range(1, k) if b[j] != 0)
        b[k] = s / (k * c[0])
    return _ts_norm(0, b, L)


def _ts_erf(A, L):
    # E(s) = erf(u(s)); E' = (2/sqrt(pi)) exp(-u^2) u'. Integrate.
    c = _ts_regular(A, L)
    u = (0, c)
    expn = _ts_exp(_ts_scale(_ts_mul(u, u, L), -1, L), L)
    dprime = _ts_scale(_ts_mul(expn, (0, _ts_deriv_list(c)), L),
                       2 / sp.sqrt(sp.pi), L)
    pr = _ts_regular(dprime, L)
    b = [sp.S.Zero] * L
    b[0] = sp.erf(c[0])
    for k in range(1, L):
        b[k] = pr[k - 1] / k
    return _ts_norm(0, b, L)


def _ts_build(expr, var, L):
    expr = sp.sympify(expr)
    if expr == var:
        return (1, [sp.S.One] + [sp.S.Zero] * (L - 1))
    if var not in expr.free_symbols:
        return _ts_const(expr, L)
    if isinstance(expr, sp.Abs):
        # the reduced gradient s >= 0, so sqrt(s**2) = |s| = s; resolve
        # Abs by the sign of the leading coefficient (the csgn=1 / s>=0
        # convention the Maple pipeline applies after series()).
        inner = _ts_build(expr.args[0], var, L)
        lead = inner[1][0]
        if lead.is_positive or (lead.is_number and complex(lead).real > 0):
            return inner
        if lead.is_negative or (lead.is_number and complex(lead).real < 0):
            return _ts_scale(inner, -1, L)
        raise _TSUnsupported
    if expr.is_Add:
        acc = _ts_const(0, L)
        for a in expr.args:
            acc = _ts_add(acc, _ts_build(a, var, L), L)
        return acc
    if isinstance(expr, sp.exp):
        return _ts_exp(_ts_build(expr.args[0], var, L), L)
    if isinstance(expr, sp.log):
        return _ts_log(_ts_build(expr.args[0], var, L), L)
    if isinstance(expr, sp.erf):
        return _ts_erf(_ts_build(expr.args[0], var, L), L)
    if isinstance(expr, sp.erfc):
        return _ts_add(_ts_const(1, L),
                       _ts_scale(_ts_erf(_ts_build(expr.args[0], var, L), L),
                                 -1, L), L)
    if expr.is_Pow:
        base, e = expr.as_base_exp()
        if var in e.free_symbols:
            raise _TSUnsupported
        return _ts_powc(_ts_build(base, var, L), e, L)
    if expr.is_Mul:
        num = _ts_const(1, L)
        den = None
        for a in expr.args:
            b, e = a.as_base_exp()
            if e.is_Number and e < 0:
                d = _ts_powc(_ts_build(b, var, L), -e, L)
                den = d if den is None else _ts_mul(den, d, L)
            else:
                num = _ts_mul(num, _ts_build(a, var, L), L)
        if den is not None:
            num = _ts_mul(num, (-den[0], _ts_inv_unit(den[1], L)), L)
        return num
    # An unrecognised head may be a non-elementary primitive (xc_erfcx,
    # xc_expm1, my_dilog, ...) that to_elementary rewrites in terms of
    # exp/erf/log; lower just this node and retry.
    low = to_elementary(expr)
    if low != expr:
        return _ts_build(low, var, L)
    raise _TSUnsupported


@lru_cache(maxsize=None)
def maple_taylor(expr, var, point, order):
    """Maple taylor()/series(): the series of `expr` about var=point,
    carried to `order`. The O() term is kept; convert(..., polynom)
    drops it.

    Helper applications are inlined to their concrete bodies first.
    SymPy cannot asymptotically expand an opaque @helper application at
    an infinite point ("Asymptotic expansion of <helper> ... is not
    implemented"); and even at a finite point Maple's taylor() expands
    the actual formula, not the formal series of an undefined function.
    Inlining makes both cases see the concrete expression.

    About var=0 a fast formal-series evaluator (_ts_build) is tried
    first; it is O(order**2) where sp.series is exponential on the nested
    rational/erfc expressions of wpbeh/tpss/... Any unsupported node
    falls back to sp.series, preserving the exact result."""
    inlined = _deep_inline(expr)
    if point == 0 or point == sp.S.Zero:
        try:
            val, c = _ts_build(inlined, var, order + 8)
            terms = [ck * var ** (val + k)
                     for k, ck in enumerate(c)
                     if ck != 0 and val + k < order]
            return sp.Add(*terms) + sp.O(var ** order)
        except _TSUnsupported:
            pass
    return sp.series(inlined, var, point, n=order)


maple_series = maple_taylor


def convert(expr, kind):
    """Maple convert(expr, polynom): drop the O() term of a series."""
    return expr.removeO() if hasattr(expr, "removeO") else expr


def diff(expr, *variables):
    """Maple diff(): symbolic differentiation."""
    return sp.diff(expr, *variables)


def maple_eval(expr, *subs):
    """Maple eval(expr, target=value, ...): substitution.

    `subs` is a flat (target, value, target, value, ...) sequence. A
    plain symbol target is substituted directly; a function target
    (e.g. csgn) has every application replaced by the value."""
    out = expr
    # Conditional-strip markers (my_piecewise3/5, m_min/m_max, m_abs) are used
    # to collapse a branch before a Taylor series (series() cannot expand a
    # relational). When the expression is still a sum of @helper proxies (e.g.
    # term2345 = term2 + term3 + ... in wpbeh), the piecewise lives inside the
    # un-inlined helper bodies and .replace() cannot reach it -- it then
    # surfaces only when maple_taylor deep-inlines, after the strip, and breaks
    # series on the leftover '>' condition. Deep-inline first so every hidden
    # conditional is reachable by the strip. (to_elementary's special-function
    # lowering targets xc_* heads, not these markers, so it is unaffected.)
    _STRIP = {"my_piecewise3", "my_piecewise5", "m_min", "m_max", "m_abs"}
    if any(isinstance(t, type) and getattr(t, "__name__", "") in _STRIP
           for t in subs[0::2]):
        out = _deep_inline(out)
    for tgt, val in zip(subs[0::2], subs[1::2]):
        if isinstance(tgt, sp.Basic):
            out = out.subs(tgt, val)
        elif not isinstance(tgt, type):
            # A plain inlined python helper (e.g. m_recexp / m_one_minus_recexp,
            # which to_elementary lists) never appears as an application, so
            # there is nothing to replace -- and SymPy treats a non-type callable
            # .replace() query as a match-everything predicate, recursively
            # wrapping every node. That turned to_elementary into a nested-exp
            # explosion that stalled sp.series (vt84f/gg99/mbrxc/mggac). Skip it.
            continue
        elif callable(val) and not isinstance(val, sp.Basic):
            # function -> function rule, e.g. my_piecewise3 = (c,a,b)->b:
            # apply the rule to each application's arguments
            out = out.replace(tgt, val)
        else:                       # function -> value rule, e.g. csgn = 1
            out = out.replace(tgt, lambda *a: val)
    return out


def _deep_inline(expr):
    """Recursively replace every helper-function application in `expr`
    with its inlined symbolic body, yielding a fully concrete
    expression. Needed because SymPy cannot series-expand an opaque
    helper-function application."""
    while True:
        applied = [a for a in expr.atoms(sp.Function)
                   if hasattr(type(a), "helper")]
        if not applied:
            return expr
        for app in applied:
            cls = type(app)
            body = cls.helper._derivs[cls.multiindex]
            body = body.subs(dict(zip(cls.helper.args, app.args)))
            expr = expr.subs(app, body)


def _as_inline(f):
    """Return an inline version of a possibly @helper-wrapped callable:
    one that yields a fully concrete (helper-free) expression. SymPy
    cannot series-expand an opaque helper-function application, in
    particular at infinity, so the actual formula has to be exposed."""
    h = getattr(f, "_helper", None)
    if h is None:
        return lambda *args: _deep_inline(f(*args))
    return lambda *args: _deep_inline(
        h.expr.subs(dict(zip(h.args, args))))


def enforce_smooth_lr(f, a, a_cutoff, expansion_order):
    """Mirrors maple enforce_smooth_lr: below a_cutoff evaluate f
    directly; at or above it use f's large-argument (a -> oo) series
    expansion, truncated to `expansion_order` terms. The m_max / m_min
    clamps keep each branch inside its valid domain.

    Maple's padding_order / throw_out_large_n scaffolding is not
    mirrored -- it only exists to dodge a Maple series-truncation bug
    that SymPy does not have."""
    f_inline = _as_inline(f)
    b = sp.Symbol("_lr_b", positive=True)
    large = sp.series(f_inline(b), b, sp.oo, n=expansion_order).removeO()
    return my_piecewise3(
        sp.Ge(a, a_cutoff),
        large.subs(b, m_max(a, a_cutoff)),
        f(m_min(a, a_cutoff)),
    )


def one_minus_z_pow_n(z, n):
    """Maple one_minus_z_pow_n: 1 - z**n in the cancellation-free factored
    form -- (1 - z)*(1 + z)*sum(z**(2k)) for even n, (1 - z)*sum(z**k) for
    odd n. `n` is a positive integer, concrete at call time, so the sum is
    spelled out (Maple evaluates the add at parse time). Mirrors
    maple/util.mpl; kept native because the parse-time type()/add
    metaprogramming does not map onto the symbolic translator."""
    if n % 2 == 0:
        return (1 - z) * (1 + z) * sum(z ** (2 * k)
                                       for k in range((n - 2) // 2 + 1))
    return (1 - z) * sum(z ** k for k in range(n))


# ============================================================================
# Per-functional helper / parameter declarations
# ============================================================================

def helper(func):
    """Decorator: turn a Python function into a per-functional helper.

    Wrapping is *lazy*. The helper's symbolic expression is not built
    when the decorator runs but on first use -- by which point the whole
    math module, and every file it $includes, has finished loading. This
    mirrors Maple, which resolves names at evaluation time: a functional
    that $includes a fragment and then redefines one of its helpers
    (e.g. gga_c_acgga overrides PBE's `tp`) then has the override take
    effect everywhere, including inside the included fragment's own
    helpers. Building eagerly at decoration time would instead bake in
    whichever definition happened to be visible right then.

    The decorator returns a proxy callable. Calling it resolves the
    helper once (memoised) and yields either a sympy Function call -- so
    the helper can appear unexpanded in larger expressions and be
    differentiated through fdiff -- or, when it cannot be wrapped as a
    standalone helper, the inlined expression.
    """
    sig = inspect.signature(func)
    # functional arguments (densities, reduced gradients, ...) are
    # real; declaring so lets SymPy differentiate e.g. Abs() cleanly.
    # An argument whose name collides with the fixed C helper signature
    # `(const xc_func_type *p, ..., double *out)` is renamed, or the
    # emitted prototype would declare `p`/`out` twice.
    arg_syms = [sp.Symbol(name + "_" if name in ("p", "out", "ip")
                          else name, real=True)
                for name in sig.parameters]
    # Per-flag resolution. The body is built once with the separable exchange
    # wrappers live (_EMIT_EXCHANGE True) and, on demand, once with them off
    # (for the spin-scaling energy split). The off body reuses the on helper
    # when unchanged (this helper holds no exchange), folds away when it is pure
    # exchange, and otherwise becomes a _rest variant queued for emission.
    res = {True: {"done": False, "helper": None, "zero": False},
           False: {"done": False, "helper": None, "zero": False}}

    def _resolve_flag(on):
        """Build the helper's expression for the current exchange flag
        (idempotent). Runs after the module is fully loaded, so every name the
        body references binds to its final, possibly overridden, definition."""
        slot = res[on]
        if slot["done"]:
            return slot
        slot["done"] = True
        if not on and not _MODULE_HAS_EXCHANGE:
            # No separable wrapper ran with exchange live anywhere in this
            # functional, so the exchange-off body equals the on body. Reuse the
            # on helper directly rather than re-evaluating func and structurally
            # comparing it (both O(tree) per helper -- the dominant cost for
            # heavy correlation functionals such as gga_c_gapc). Sound because
            # f_x_func evaluates f on (setting the flag) before f_rest runs off.
            on_slot = _resolve_flag(True)
            slot["helper"] = on_slot["helper"]
            slot["zero"] = on_slot["zero"]
            slot["raw"] = on_slot.get("raw")
            return slot
        try:
            expr = func(*arg_syms)
        except (TypeError, AttributeError, IndexError, NameError):
            # Takes a callable or array-valued argument (a higher-order helper
            # or one indexing a param_array); it cannot be a standalone helper,
            # so leave it to inline -- which then respects the flag itself.
            return slot
        # Keep the raw (pre-clean) body: the on-helper's .expr is cleaned in
        # place later, so the off body must be compared against this instead.
        slot["raw"] = expr
        if not on:
            on_slot = res[True]
            if on_slot["done"] and expr == on_slot.get("raw"):
                slot["helper"] = on_slot["helper"]   # no exchange in this helper
                return slot
            if expr == 0:
                slot["zero"] = True                  # pure exchange -> gone
                return slot
        h = Helper(func.__name__ + ("" if on else "_rest"),
                   arg_syms, expr, max_order=_GEN_MAX_ORDER)
        h._needs_params = any(
            isinstance(s, sp.Symbol)
            and (s.name.startswith("params_a_") or s.name == "params")
            for s in expr.free_symbols
        )
        slot["helper"] = h
        if not on:
            _SPECIALIZED_ORDER.append(h)
        return slot

    def _resolve():
        _call._helper = _resolve_flag(True)["helper"]

    def _call(*args):
        slot = _resolve_flag(_EMIT_EXCHANGE)
        # Maple `->` procedures silently drop surplus arguments; match that, so
        # a helper called with extra args does not build a sympy Function of the
        # wrong arity (which then breaks fdiff).
        args = args[:len(arg_syms)]
        if slot["helper"] is not None and any(
                callable(a) or isinstance(a, _MapleList) for a in args):
            # Called with a callable or list-valued argument -- a higher-order
            # helper (e.g. op.py's op_b88_zab) or one taking a coefficient
            # table. It cannot be a standalone C function; inline it.
            slot["helper"] = None
            if _EMIT_EXCHANGE:
                _call._helper = None
        if slot["helper"] is None:
            return sp.S.Zero if slot["zero"] else func(*args)
        return slot["helper"].call(*args)

    _call.__name__ = func.__name__
    _call._is_helper_proxy = True
    _call._resolve = _resolve
    _call._helper = None
    return _call


class _Param(sp.Symbol):
    """A per-functional parameter.

    Usable directly as a scalar -- the C printer renders it
    `params->NAME` -- and also subscriptable: Maple indexes parameter
    arrays from 1, so `param[i]` yields the symbol the printer renders
    as `params->NAME[i-1]`. Whether a parameter is scalar or a tabulated
    coefficient list is thus decided at *use*, as in maple2c, not at
    declaration -- so a table indexed only inside an $include'd helper
    still works (every loop is unrolled, so the index is concrete)."""

    def __getitem__(self, i):
        return sp.Symbol(f"{self.name}[{int(i) - 1}]", real=True)

    def __iter__(self):
        # __getitem__ alone makes Python treat the object as iterable
        # (the old [0],[1],... protocol); since __getitem__ never raises
        # IndexError that iteration is infinite. A parameter is a scalar
        # symbol -- declare it explicitly non-iterable.
        raise TypeError(f"{self.name} is not iterable")

    @classmethod
    def class_key(cls):
        # Sort exactly like a plain Symbol, so SymPy's canonical term
        # ordering -- and thus the generated C -- is unchanged.
        return sp.Symbol.class_key()


def param(name):
    """Declare a per-functional parameter (scalar or array-valued)."""
    return _Param(f"params_a_{name}", real=True)


def _expr_uses_params(expr):
    """True if `expr` references a per-functional parameter (a params_a_* symbol,
    including an array element like params_a_c_x[3], or the bare `params`), so the
    emitter must declare `params` in the helper/kernel that contains it."""
    return any(
        getattr(s, "is_Symbol", False)
        and (s.name.startswith("params_a_") or s.name == "params")
        for s in expr.free_symbols
    )


def _find_include(name):
    """Locate a math fragment <name>.py anywhere under the python/ tree."""
    for root, _dirs, files in os.walk(_HERE):
        if name + ".py" in files:
            return os.path.join(root, name + ".py")
    raise FileNotFoundError(f"include: no python/**/{name}.py found")


def define(name):
    """Mirror Maple's `$define`: mark a preprocessor macro as set in the
    caller's namespace (tested by defined())."""
    sys._getframe(1).f_globals["_macro_" + name] = True


def undef(name):
    """Mirror Maple's `$undef`: clear a previously-set macro in the
    caller's namespace. Silently no-ops if the macro was never set --
    matches Maple, where $undef of an unknown name is harmless."""
    sys._getframe(1).f_globals.pop("_macro_" + name, None)


def defined(name):
    """Mirror Maple's `$ifdef` test -- True if `name` was $define'd in
    the current functional (e.g. by an includer activating a
    parameter-default block)."""
    return sys._getframe(1).f_globals.get("_macro_" + name, False)


def include(name):
    """Mirror Maple's textual `$include`: run the named math fragment in
    the *caller's* namespace, so the fragment and its includer share one
    scope.

    A plain Python `import` gives the fragment its own module globals,
    which hides the helpers the includer defines around the $include
    point -- e.g. maple/tpss_x.mpl references tpss_ff / tpss_kappa,
    which maple/mgga_x_tpss.mpl defines just above its $include. exec'ing
    the fragment in the caller's globals makes every name resolve in the
    single shared scope, exactly as Maple's paste does."""
    caller = sys._getframe(1).f_globals
    path = _find_include(name)
    # Per-functional output metadata (the libxc TYPE, the params struct,
    # the post-process REPLACE rules) belongs to the functional being
    # compiled, not to a fragment it pulls in -- Maple reads type: and
    # prefix: only from the top .mpl file. Shield these names so an
    # included fragment cannot leak e.g. its PARAMS_STRUCT into a
    # parameter-free includer. `f` and helpers are deliberately not
    # shielded: a fragment legitimately supplies the includer's `f`.
    META = ("TYPE", "PARAMS_STRUCT", "REPLACE")
    saved = {k: caller[k] for k in META if k in caller}
    with open(path) as fh:
        exec(compile(fh.read(), path, "exec"), caller)
    for k in META:
        caller.pop(k, None)
    caller.update(saved)


# Maple's `params_a_X` parameters and `params_a_X[i]` coefficient tables
# are the same object here -- a _Param is both scalar and subscriptable
# -- so param_array is just a translator-facing alias of param.
param_array = param


def param_default(name):
    """Declare a parameter's default without clobbering a value an
    includer already bound to it.

    Maple's $include is a textual paste into one shared scope: a
    fragment's parameter block only ever sets a params_a_X that the
    includer left unassigned (e.g. gga_c_zpbeint fixes params_a_gamma
    to a constant, then $include's gga_c_pbe, whose own gamma default
    must not overwrite it). param() always makes a fresh symbol; this
    keeps whatever the caller's namespace already holds. mpl2py emits
    every auto-declared parameter default through this function."""
    key = f"params_a_{name}"
    caller = sys._getframe(1).f_globals
    if key in caller:
        return caller[key]
    return _Param(key, real=True)


class _MapleList:
    """A list literal carried over from Maple source.

    Maple indexes lists from 1; this wrapper preserves that so translated
    code can keep the original 1-based subscripts."""

    def __init__(self, data):
        self._data = list(data)

    def __getitem__(self, i):
        return self._data[int(i) - 1]

    def __setitem__(self, i, value):
        self._data[int(i) - 1] = value

    def __len__(self):
        return len(self._data)

    def __iter__(self):
        # Without this guard Python's legacy iteration protocol would start
        # at __getitem__(0) == _data[-1], silently yielding
        # [last, first, second, ...]. Translated code indexes explicitly
        # (Maple is 1-based); iteration is a bug, so fail loudly like _Param.
        raise TypeError(
            "_MapleList is 1-indexed and not iterable; index it explicitly")


def maple_list(data):
    """Wrap a list literal so it is subscripted with Maple 1-based indices."""
    return _MapleList(data)


# ============================================================================
# C code emission driver
# ============================================================================

ORDER_NAMES = ["EXC", "VXC", "FXC", "KXC", "LXC"]
HAVE_FLAGS = " | ".join(f"XC_FLAGS_I_HAVE_{o}" for o in ORDER_NAMES)
ORDER_FLAG = {0: "XC_FLAGS_HAVE_EXC", 1: "XC_FLAGS_HAVE_VXC",
              2: "XC_FLAGS_HAVE_FXC", 3: "XC_FLAGS_HAVE_KXC",
              4: "XC_FLAGS_HAVE_LXC"}

LDA_FIELDS = {0: ["zk"], 1: ["vrho"], 2: ["v2rho2"], 3: ["v3rho3"], 4: ["v4rho4"]}

GGA_FIELDS = {
    0: [("zk", 0, 0)],
    1: [("vrho", 1, 0), ("vsigma", 0, 1)],
    2: [("v2rho2", 2, 0), ("v2rhosigma", 1, 1), ("v2sigma2", 0, 2)],
    3: [("v3rho3", 3, 0), ("v3rho2sigma", 2, 1),
        ("v3rhosigma2", 1, 2), ("v3sigma3", 0, 3)],
    4: [("v4rho4", 4, 0), ("v4rho3sigma", 3, 1), ("v4rho2sigma2", 2, 2),
        ("v4rhosigma3", 1, 3), ("v4sigma4", 0, 4)],
}


def _make_deriv_fields(varnames, max_order):
    """Build the order -> [(field, count-per-variable...)] table for a
    functional family whose outputs are mixed partials in `varnames`.

    Field names follow libxc's convention: 'zk' at order 0, 'v<var>' at
    order 1, and 'v<order><var><count>...' above, the count omitted when
    1. The per-order entry order matches itertools' combinations (the
    same order libxc's xc_*_out_params arrays use)."""
    fields = {}
    for o in range(max_order + 1):
        entries = []
        for combo in combinations_with_replacement(varnames, o):
            counts = tuple(combo.count(v) for v in varnames)
            if o == 0:
                name = "zk"
            else:
                parts = "".join(v + ("" if c == 1 else str(c))
                                for v, c in zip(varnames, counts) if c)
                name = ("v" if o == 1 else f"v{o}") + parts
            entries.append((name,) + counts)
        fields[o] = entries
    return fields


# meta-GGA outputs: mixed partials in rho, sigma, lapl, tau
MGGA_FIELDS = _make_deriv_fields(("rho", "sigma", "lapl", "tau"), 4)


def _deriv_name(diff_vars, value_name="zk", base="F"):
    """Name a derivative output by the variables it differentiates.

    []           -> value_name        (e.g. 'zk' / 'f')
    ['na']       -> 'd<base>_dna'      (e.g. 'dF_dna')
    ['na','na']  -> 'd2<base>_dna2'
    ['na','gab'] -> 'd2<base>_dna_dgab'"""
    if not diff_vars:
        return value_name
    order = len(diff_vars)
    prefix = "d" + base if order == 1 else f"d{order}{base}"
    seen = []
    for v in diff_vars:
        if v not in seen:
            seen.append(v)
    parts = []
    for v in seen:
        c = diff_vars.count(v)
        parts.append("_d" + v + (str(c) if c > 1 else ""))
    return prefix + "".join(parts)


def _helper_order_map(helpers, max_order):
    """Highest derivative order each helper must be emitted to.

    A helper appearing in a kernel is needed at the generation
    max_order; a helper nested inside another can be needed deeper,
    because the enclosing helper's value may already reference it
    differentiated (Leibniz/chain rule). Propagate to a fixpoint and
    extend each helper's derivative table to the result."""
    kmap = {id(h): max_order for h in helpers}
    comp = {}                          # helper id -> {sub id: max pre-order}
    for h in helpers:
        m = {}
        for a in h.expr.atoms(sp.Function):
            cls = type(a)
            if hasattr(cls, "helper"):
                sid = id(cls.helper)
                m[sid] = max(m.get(sid, 0), sum(cls.multiindex))
        comp[id(h)] = m
    cap = max_order + 8                # guard a helper-composition cycle
    changed = True
    while changed:
        changed = False
        for hid, subs in comp.items():
            for sid, p in subs.items():
                if sid not in kmap:
                    continue
                new = min(kmap[hid] + p, cap)
                if new > kmap[sid]:
                    kmap[sid] = new
                    changed = True
    for h in helpers:
        h.ensure_order(kmap[id(h)])
    return kmap


def _reachable_helpers(f_func, helpers):
    """Keep only the helpers transitively reachable from f.

    An $include pulls in a fragment's entire helper set, but a
    functional that overrides part of it (or only uses a slice) leaves
    the rest dead. Such dead helpers are still valid Python yet may
    reference parameters the functional never exposes -- emitting them
    as C breaks the build. Maple expands from f and never sees them.

    Call this *after* _helper_order_map has populated each helper's
    derivative table: a helper for an implicitly-defined quantity
    (Becke-Roussel's br89_x) reaches further helpers only through its
    derivative formula, so the whole _derivs table must be scanned."""
    hset = set(helpers)
    nargs = len(inspect.signature(f_func).parameters)
    probe = [sp.Symbol(f"_rp{i}", positive=True) for i in range(nargs)]
    try:
        root = f_func(*probe)
    except Exception:
        return helpers                 # cannot probe f -- keep all
    if not isinstance(root, sp.Basic):
        return helpers

    def helpers_in(expr):
        return {type(a).helper for a in expr.atoms(sp.Function)
                if hasattr(type(a), "helper") and type(a).helper in hset}

    def sub(h):
        found = set()
        for e in (h.expr, *h._derivs.values()):
            found |= helpers_in(e)
        return found

    reached, frontier = set(), list(helpers_in(root))
    while frontier:
        h = frontier.pop()
        if h in reached:
            continue
        reached.add(h)
        frontier += sub(h)
    return [h for h in helpers if h in reached]


def _toposort_helpers(helpers):
    """Order helpers so each is emitted after every helper it calls.

    The C definitions are plain `static inline` functions, so a callee
    must be defined before its caller. Namespace-insertion order is not
    safe: overriding a helper pulled in by include() (e.g. gga_c_acggap
    redefining `tp` to call its own `bcgp_pt`) keeps the helper's
    original, earlier slot while gaining a dependency on a helper
    defined later. A depth-first post-order over the call graph fixes
    this; it preserves the input order wherever that is already valid."""
    hset = set(helpers)
    # `atoms()` hands back a set, whose iteration order varies between runs.
    # Visiting a helper's callees in that order shuffles mutually independent
    # siblings (p86vwn's Q_vwn / f1_vwn / f2_vwn / f3_vwn / fx_vwn have no
    # edges between them, so every permutation is a valid topological order),
    # and the generated C then differs run to run for no reason. Rank the
    # callees by position in the input list instead: deterministic, and it
    # keeps the input order wherever that is already a valid order.
    rank = {id(h): i for i, h in enumerate(helpers)}

    def deps(h):
        seen = {}
        for a in h.expr.atoms(sp.Function):
            cls = type(a)
            sub = getattr(cls, "helper", None)
            if sub in hset and sub is not h:
                seen[id(sub)] = sub
        return [seen[k] for k in sorted(seen, key=lambda i: rank[i])]

    ordered, done, active = [], set(), set()

    def visit(h):
        if h in done or h in active:
            return        # already placed, or a cycle -- emit best-effort
        active.add(h)
        for d in deps(h):
            visit(d)
        active.discard(h)
        done.add(h)
        ordered.append(h)

    for h in helpers:
        visit(h)
    return ordered


def _helper_slots(helper, kmap):
    """Ordered multi-indices a helper exposes -- value first, then every
    partial up to the order the dependency fixpoint (kmap) found it is
    needed at. The helper emission and every call site index `out`
    through this list, so they agree on slot numbers.

    Sorted by TOTAL order first, so the slots needed at order k are exactly
    the first `_slot_prefixes()[k]` entries. Sorting by the multi-index
    alone (the plain tuple order) interleaves the orders -- for a five-
    argument helper the two order-1 slots land at indices 1 and 70 -- which
    makes the array impossible to truncate: an exc-only kernel would still
    have to declare all 126 doubles to reach slot 0."""
    return [mi for mi in sorted(helper._derivs, key=lambda mi: (sum(mi), mi))
            if sum(mi) <= kmap[id(helper)]]


def _helper_variant(name):
    """C expression naming the `_KMAX`-order variant of helper `name`.

    Helpers are order-graded exactly like the kernel: one body in the file,
    re-included once per order with _KMAX set, so each order gets a variant
    that computes and stores only its own slots. The body is textual and
    shared, so a call site cannot spell the order literally -- it pastes
    _KMAX in."""
    return f"XC_CAT({name}_k, _KMAX)"


# Per-top-level-order helper-order maps, set for the functional being
# compiled. _slot_dim needs them to size a consolidated call's array, and the
# family emitters do not thread them through.
_GUARD_KMAPS = None


def _slot_dim(helper, kmap):
    """C array bound for a consolidated call to `helper`.

    Sized by how many slots the callee WRITES at each order, which is
    `_helper_slots(helper, guard_kmaps[k])` -- not by how many slots have
    total derivative order <= k. Those differ: the dependency fixpoint can
    need a helper one order above the top-level order that consumes it (the
    chain rule through its arguments), so e.g. f_zeta writes its 4th
    derivative in the _KMAX=3 variant. Sizing by total order made every such
    array short by a slot and smashed the caller's stack.

    Both sets are prefixes of the (sum, mi)-sorted slot list, so the written
    set stays contiguous from 0 either way.

    A conditional chain of integer literals is an integer constant
    expression, so this stays a plain array -- not a VLA -- and folds at
    compile time."""
    full = len(_helper_slots(helper, kmap))
    if not _GUARD_KMAPS:
        return str(full)

    def _written_at(order):
        # The variant compiled at _KMAX=order writes every slot guarded at an
        # order <= it, and _emit_helper_c guards a slot at the LOWEST order
        # that reaches it. So the live cap is the running maximum over all
        # orders up to this one, not this order's map alone -- the per-order
        # maps are not required to be monotone.
        # A helper missing from a map is one synthesized during kernel
        # emission (a z=const specialization), registered into the maps
        # afterwards as `setdefault(id(spec), t)`. Default to `t` to match,
        # rather than to the full jet -- that overshot and left the array
        # bigger than anything the callee writes.
        cap = max((_GUARD_KMAPS[t].get(id(helper), t)
                   for t in _GUARD_KMAPS if t <= order), default=-1)
        if cap < 0:
            return 1        # not reached at this order; the call is not
                            # compiled here, but the array still needs a bound
        return max(1, min(sum(1 for mi in helper._derivs if sum(mi) <= cap),
                          full))

    orders = sorted(_GUARD_KMAPS)
    sizes = {k: _written_at(k) for k in orders}
    if sizes[orders[0]] == sizes[orders[-1]]:
        return str(sizes[orders[-1]])
    chain = "".join(f"(_KMAX) >= {k} ? {sizes[k]} : " for k in orders[:0:-1])
    return chain + str(sizes[orders[0]])


def _consolidate_helpers(exprs, kmap):
    """Replace every helper-function application in `exprs` with an
    array-slot symbol, so each (helper, arguments) pair is evaluated by a
    single call that returns the value and all derivatives at once.

    Returns (calls, new_exprs):
      calls     -- [(arrname, helper, argtuple), ...] in dependency order
                   (a call's args reference only earlier calls' slots)
      new_exprs -- exprs with each application replaced by a Symbol
                   '<arrname>_<slot>'."""
    calls = []
    groups = {}                       # (id(helper), argtuple) -> arrname
    counter = [0]
    cache = {}

    def rw(e):
        cached = cache.get(e)
        if cached is not None:
            return cached
        if isinstance(e, sp.Function) and hasattr(type(e), "helper"):
            cls = type(e)
            helper = cls.helper
            if helper._derivs[cls.multiindex] == 0:
                # structurally-zero derivative: fold it away, so dead
                # chain-rule terms -- and the inputs that feed only them
                # -- drop out of the kernel entirely.
                res = sp.S.Zero
            else:
                # arguments the helper does not actually depend on are
                # passed as zero, so an unused input is never even read
                # (e.g. mgga_x_lta ignores the laplacian).
                live = [a in helper.expr.free_symbols for a in helper.args]
                args = tuple(rw(a) if live[j] else sp.S.Zero
                             for j, a in enumerate(e.args))
                key = (id(helper), args)
                arr = groups.get(key)
                if arr is None:
                    arr = f"_hc{counter[0]}"
                    counter[0] += 1
                    groups[key] = arr
                    calls.append((arr, helper, args))
                slot = _helper_slots(helper, kmap).index(cls.multiindex)
                res = sp.Symbol(f"{arr}_{slot}")
        elif e.args:
            res = e.func(*[rw(a) for a in e.args])
        else:
            res = e
        cache[e] = res
        return res

    return calls, [rw(e) for e in exprs]


# --------------------------------------------------------------------------
# Numerical-stability rewrites (applied to every emitted expression)
# --------------------------------------------------------------------------
#
# These transformations target near-cancellation forms that the symbolic
# differentiation hands us in a form that's exact in real arithmetic but
# catastrophically lossy in IEEE-754 double precision. They run as
# expression-tree rewrites (no `simplify` -- fast, predictable, no
# unintended algebraic restructuring), before CSE and emission.
#
# Catalogue:
#
#   1. (1 - z^2) and its rationally-coefficiented siblings
#      (a*(1 - z^2) or (a - b*z^2) when a/b is a positive perfect square)
#      are factored to (1+z)(1-z). At fully spin-polarized z = +/-1 the
#      subtraction loses all significance; the product form is stable.
#      This is the single biggest win for functionals like cs1, lyp,
#      wigner, ml1, pmgb06, pw_erf -- anywhere a zeta-symmetric
#      correlation channel is written.
#
#   2. powdenest (no force): collapses `x / (-x)**(2/3) = -(-x)**(1/3)`
#      and related forms that arise when differentiating the (1-z)
#      branch of opz_pow_n-type expressions. Without it the kernel
#      emits 0 / 0**(2/3) at the screened-zeta edge and returns NaN.
#      force=True would catch a few more forms but at the cost of
#      collapsing Abs(z) -> z, which silently strips the m_abs()
#      screens that several functionals (e.g. gga_c_w94) rely on.
#
#   3. log(1 + X)  ->  log1p(X). The libm routine is accurate for
#      tiny X; the naive form `log(1 + small)` collapses the small
#      bits into the binary representation of 1 before log sees it.
#
#   4. exp(X) - 1  ->  expm1(X). Same story symmetrically.
#      `1 - exp(X)` is left for sympy's sign propagation to land as
#      `-expm1(X)` automatically.
#
#   5. sqrt(X^2 + Y^2)  ->  hypot(X, Y). Avoids the over/underflow
#      window for either coordinate when computing X^2 + Y^2.
#
#   6. 1 - cos(X)  ->  2*sin(X/2)**2 (haversine).
#
# Patterns considered and explicitly rejected:
#   - (1+z)^a + (1-z)^a - 2 (f_zeta-style): the obvious rewrite via
#     expm1/log1p is mathematically exact but the expm1 terms cancel
#     at small z just as badly. Needs a Taylor-in-z^2 leading-order
#     extraction -- a structural fix, not a tree rewrite.
#   - x*log(x) at x->0: limit is 0, but the stable form is a
#     piecewise (x<=0 ? 0 : x*log(x)), not a substitution, and would
#     fight the existing screen_dens machinery.
#
# (x - sin(x) and similar trig cancellations would also belong here
# but do not arise in libxc -- only gga_c_revtca uses sin, in the
# form sinc(x) = sin(x)/x, and its 0/0 is already protected by a
# manual Taylor switch in the .mpl source.)

# sympy.codegen.cfunctions wraps the libm C99 routines we want to
# emit (expm1, log1p, hypot). C99CodePrinter (the base of our
# LibxcCPrinter) already knows their C names, so once we substitute
# these Function nodes the rest of the pipeline just works.
from sympy.codegen.cfunctions import (
    expm1 as _cf_expm1, log1p as _cf_log1p, hypot as _cf_hypot,
)


def _rewrite_libm_stable_forms(expr):
    """Substitute the near-cancellation forms whose stable equivalents
    are either libm primitives or simple trig identities:

      exp(X) - 1       -> expm1(X)           [and 1 - exp(X) -> -expm1(X)]
      log(1 + X)       -> log1p(X)
      sqrt(X^2 + Y^2)  -> hypot(X, Y)        [two-term only]
      1 - cos(X)       -> 2 * sin(X/2)**2    [haversine identity]

    Each pattern loses significance at its respective small-argument
    limit; the rewrites are accurate over the full domain at the same
    runtime cost.

    (1+X)^a + (1-X)^a - 2 is NOT in this list: the obvious rewrite to
    expm1(a*log1p(X)) + expm1(a*log1p(-X)) is mathematically exact but
    not a stability win -- at small X the two expm1 terms still
    cancel against each other (+aX vs -aX) at the same precision the
    original cancels against the -2. A real fix needs a Taylor-in-X^2
    leading-order extraction, which is a different shape of rewrite
    and not done here.)"""
    # log(1 + X)  ->  log1p(X)
    def repl_log1p(node):
        arg = node.args[0]
        if not arg.is_Add:
            return node
        one_terms = [a for a in arg.args if a == sp.S.One]
        if not one_terms:
            return node
        rest = sp.Add(*[a for a in arg.args if a != sp.S.One])
        return _cf_log1p(rest)
    # Guard each rewrite with a cheap internal .has() so the per-node Python
    # predicate walk is skipped entirely when its target head is absent
    # (output-identical: the rewrite cannot fire without it).
    if expr.has(sp.log):
        expr = expr.replace(lambda e: isinstance(e, sp.log), repl_log1p)

    # exp(X) - 1  ->  expm1(X), and 1 - exp(X)  ->  -expm1(X).
    # Match a two-term Add whose terms are exp() and (+/-1), or
    # -exp() and (+/-1) -- the negated case is `Add(1, Mul(-1, exp))`.
    def _strip_unit_sign(a):
        if isinstance(a, sp.exp):
            return sp.S.One, a.args[0]
        if (a.is_Mul and len(a.args) == 2
                and a.args[0] == sp.S.NegativeOne
                and isinstance(a.args[1], sp.exp)):
            return sp.S.NegativeOne, a.args[1].args[0]
        return None
    def repl_expm1(node):
        if not node.is_Add or len(node.args) != 2:
            return node
        units = [a for a in node.args
                 if a == sp.S.One or a == sp.S.NegativeOne]
        exps = [_strip_unit_sign(a) for a in node.args]
        exps = [e for e in exps if e is not None]
        if len(units) != 1 or len(exps) != 1:
            return node
        unit = units[0]
        sign, x = exps[0]
        # exp(X) + (-1) -> expm1(X);  -exp(X) + 1 -> -expm1(X);
        # exp(X) + 1 and -exp(X) + (-1) are not cancellation cases.
        if sign == sp.S.One and unit == sp.S.NegativeOne:
            return _cf_expm1(x)
        if sign == sp.S.NegativeOne and unit == sp.S.One:
            return -_cf_expm1(x)
        return node
    if expr.has(sp.exp):
        expr = expr.replace(lambda e: e.is_Add, repl_expm1)

    # 1 - cos(X)  ->  2*sin(X/2)**2 (haversine identity). At X -> 0
    # the original loses all bits to (1 - 1); the identity evaluates
    # via sin which has full precision near zero.
    def repl_haversine(node):
        if not node.is_Add or len(node.args) != 2:
            return node
        ones = [a for a in node.args if a == sp.S.One]
        neg_cos = [a for a in node.args
                   if a.is_Mul and len(a.args) == 2
                   and a.args[0] == sp.S.NegativeOne
                   and isinstance(a.args[1], sp.cos)]
        if len(ones) == 1 and len(neg_cos) == 1:
            X = neg_cos[0].args[1].args[0]
            return 2 * sp.sin(X / 2) ** 2
        return node
    if expr.has(sp.cos):
        expr = expr.replace(lambda e: e.is_Add, repl_haversine)

    # sqrt(X^2 + Y^2)  ->  hypot(X, Y). Only the two-term case --
    # libm has no n-ary hypot, and 3+ argument hypot has its own
    # stability story (norm in higher dims).
    def repl_hypot(node):
        if not (node.is_Pow and node.exp == sp.Rational(1, 2)):
            return node
        base = node.base
        if not base.is_Add or len(base.args) != 2:
            return node
        sq_args = []
        for a in base.args:
            if a.is_Pow and a.exp == 2:
                sq_args.append(a.base)
            else:
                return node
        return _cf_hypot(sq_args[0], sq_args[1])
    expr = expr.replace(lambda e: e.is_Pow, repl_hypot)
    return expr


def _factor_const_minus_square(expr):
    """Rewrite (c - coef*b^2) -> coef*(sqrt(c/coef) - b)(sqrt(c/coef) + b)
    when c and coef are positive Rationals and c/coef is a perfect
    square. Catches (1 - z**2), (1 - z**2)/4 (= 1/4 - z**2/4), and
    (4 - z**2). Leaves symbolic constants (a - z**2 with a a Symbol)
    untouched because we can't prove they're a perfect square."""
    if not isinstance(expr, sp.Basic) or expr.is_Atom:
        return expr
    new_args = tuple(_factor_const_minus_square(a) for a in expr.args)
    if any(na is not oa for na, oa in zip(new_args, expr.args)):
        expr = expr.func(*new_args)
    if not expr.is_Add or len(expr.args) != 2:
        return expr
    pos_consts, neg_sq_terms = [], []
    for a in expr.args:
        if a.is_Rational and a > 0:
            pos_consts.append(a)
            continue
        coef, body = a.as_coeff_Mul()
        if (coef.is_Rational and coef < 0
                and body.is_Pow and body.exp == 2):
            neg_sq_terms.append((-coef, body.base))
    if len(pos_consts) != 1 or len(neg_sq_terms) != 1:
        return expr
    c, (coef, b) = pos_consts[0], neg_sq_terms[0]
    ratio = c / coef
    s = sp.sqrt(ratio)
    if not (s.is_Rational or s.is_Integer):
        return expr
    return coef * (s - b) * (s + b)


def _helper_has_through_z_chain(helper):
    """True if this helper's body has a `(1 + z_formal)` or
    `(1 - z_formal)` Add subexpression, where `z_formal` is the
    helper's own z-coordinate argument. These are the helpers that the
    kernel-clean pass needs to inline so the (1+z), (1-z) patterns can
    be rewritten in `na`/`nb`-precise form before differentiation.

    Helpers without such chains -- the vast majority of mGGAs (SCAN,
    TPSS, R2SCAN, ...) -- are left opaque, which is far cheaper.
    """
    # Conventionally `z` is the helper's second formal argument when
    # present; fall back to a name check otherwise.
    z_candidates = [a for a in helper.args
                    if getattr(a, "name", "") in ("z", "zeta")]
    if not z_candidates:
        return False
    z = z_candidates[0]
    one_plus = 1 + z
    one_minus = 1 - z

    # Scan VALUE subtrees only. A (1 +- z) inside a frozen piecewise
    # condition (e.g. the zeta-threshold clamp `1 + z <= zeta_threshold`)
    # is never differentiated and never receives the na/nb value rewrite
    # this inlining exists for -- and the library helpers (opz_pow_n_4_3)
    # have always evaluated exactly such conditions from z. Counting
    # conditions made benefits() inline every caller of the f_zeta helper
    # (whose value path hides the 1+z inside xc_log1p), ballooning the
    # PW92-family kernels ~2x and their generation ~10x.
    def scan(e):
        if not isinstance(e, sp.Basic):
            return False
        if e == one_plus or e == one_minus:
            return True
        if isinstance(e, sp.Function) and type(e).__name__ in (
                "my_piecewise3", "my_piecewise5"):
            # value args only: skip args[0] (and args[2] for piecewise5)
            args = e.args
            vals = ([args[1], args[2]] if len(args) == 3
                    else [args[1], args[3], args[4]])
            return any(scan(a) for a in vals)
        if e.is_Relational:
            return False
        return any(scan(a) for a in e.args)

    return scan(helper.expr)


def _helper_reaches_screen(helper, _seen=None):
    """True if this helper's body contains a _screen_dens marker, directly or
    through a (per-functional) helper it calls. Such helpers MUST be inlined into
    the kernel: a standalone C helper only has (rs, z) and so can only express the
    screen as the cancelling (1 +/- z)*nt/2 reconstruction, whereas the kernel has
    the raw channel densities na/nb. Inlining lets _resolve_screen_dens_kernel
    rewrite the screen to the exact raw form."""
    if _seen is None:
        _seen = set()
    if id(helper) in _seen:
        return False
    _seen.add(id(helper))
    sd = _screen_dens_marker
    for sub in sp.preorder_traversal(helper.expr):
        if getattr(sub, "is_Function", False):
            if sub.func is sd:
                return True
            sub_helper = getattr(sub.func, "helper", None)
            if sub_helper is not None and _helper_reaches_screen(sub_helper, _seen):
                return True
    return False


# If the inlined kernel expression grows past this many sympy ops we
# bail out: the post-inline xreplace + diff become quadratic-ish and
# blow past compile.py's per-functional timeout. The 1500-op threshold
# is roughly 10x cs1's inlined size (the smallest functional that
# benefits) and well below SCAN/TPSS-class explosions (3000+ ops).
_KERNEL_INLINE_SIZE_CAP = 1500


def _inline_perfunc_helpers(expr):
    """Replace every per-functional @helper application in `expr` with
    the (recursively inlined) body of the appropriate derivative slot,
    substituting formal args -> concrete args. Library helpers in
    _LIBRARY_HELPERS are kept opaque so their static-inline C versions
    remain shared across functionals; per-functional helpers that
    don't reference `(1+z)`/`(1-z)` are also kept opaque so SCAN-class
    functionals don't blow up to 80x size for no benefit. If the
    fully-inlined result exceeds _KERNEL_INLINE_SIZE_CAP, the original
    helper-opaque expression is returned -- the through-z fix would be
    correct but the subsequent sp.diff pass would time out.

    This is the prerequisite for kernel-level pattern replacement
    (sp.xreplace) to see through the helper boundary -- without it,
    `n_spin(rs, z) * (something)/(1+z)` style subterms keep their
    through-z form and the substituted kernel expression has
    `(na - nb)/(na + nb)` chains that lose precision to rounding at
    boundary spin densities."""
    library_ids = {id(h) for h in _LIBRARY_HELPERS}
    _benefit_cache = {}

    def benefits(helper, screen_only):
        key = (id(helper), screen_only)
        if key in _benefit_cache:
            return _benefit_cache[key]
        # A helper needs inlining if it has the through-z chain, reaches a screen
        # marker (which must be resolved against na/nb at the kernel), OR if any
        # nested per-functional callee does (both propagate up). Inside a
        # piecewise CONDITION (screen_only) only the screen-marker need applies:
        # the (1+z)/(1-z) precision rewrite is a VALUE concern (its 1/(1-z) -> inf
        # only corrupts arithmetic, not a boolean comparison), so through-z-only
        # helpers (e.g. f_pbe via its callees) stay opaque there. That keeps a
        # comparison like `f_pbe(a) > f_pbe(b)` a small comparison of helper calls
        # instead of two inlined ~1000-op bodies that explode simplify_conditions'
        # cancel (1.17M ops on tpss) -- the 14x generation speedup for TPSS-class
        # correlation (cost: those functionals' C grows ~1.8x; localized to them).
        ok = _helper_reaches_screen(helper) or (
            not screen_only and _helper_has_through_z_chain(helper))
        if not ok:
            for sub in sp.preorder_traversal(helper.expr):
                cls = getattr(sub, "func", None)
                if (cls is not None and isinstance(sub, sp.Function)
                        and hasattr(cls, "helper")
                        and id(cls.helper) not in library_ids
                        and benefits(cls.helper, screen_only)):
                    ok = True
                    break
        _benefit_cache[key] = ok
        return ok

    def go(e, in_cond):
        if not isinstance(e, sp.Basic) or e.is_Atom:
            return e
        cls = e.func
        if isinstance(e, sp.Function) and hasattr(cls, "helper"):
            helper = cls.helper
            if id(helper) not in library_ids and benefits(helper, in_cond):
                helper.ensure_order(sum(cls.multiindex))
                body = helper._derivs[cls.multiindex]
                body = body.xreplace(dict(zip(helper.args, e.args)))
                return go(body, in_cond)
        if cls is my_piecewise3:
            c, t, el = e.args
            new = (go(c, True), go(t, in_cond), go(el, in_cond))
        elif cls is my_piecewise5:
            c1, t1, c2, t2, el = e.args
            new = (go(c1, True), go(t1, in_cond), go(c2, True),
                   go(t2, in_cond), go(el, in_cond))
        else:
            new = tuple(go(a, in_cond) for a in e.args)
        if any(na is not oa for na, oa in zip(new, e.args)):
            return e.func(*new)
        return e

    result = go(expr, False)
    # A screen marker that survives to the C output is undefined (won't compile),
    # so screen-reaching helpers must inline regardless of the size cap.
    if (sp.count_ops(result) > _KERNEL_INLINE_SIZE_CAP
            and not result.has(_screen_dens_marker)):
        return expr
    return result


def _kernel_clean(expr, na, nb):
    """Kernel-level cleanup: applied once to f_func's output after the
    (rs, z, xt, xs, u, t) substitutions have been baked in.

    Inlines per-functional helpers (so the (1+z), (1-z) subexpressions
    are visible), then targets the precise patterns
        (na - nb)/(na + nb) + 1   ==   2*na/(na + nb)
        -(na - nb)/(na + nb) + 1  ==   2*nb/(na + nb)
    via xreplace. The result is a different but mathematically identical
    factorisation: each `n_spin` chain collapses to a direct `na`- or
    `nb`-only form, without going through the full sp.cancel polynomial
    expansion (which was correct but produced a ~75x expression-size
    explosion on cs1 and timed out the downstream sp.diff).

    Without this the kernel computes `(na-nb)/(na+nb)` in double
    precision, which rounds to exactly 1.0 when one channel sits at
    dens_threshold and na is ~0.3; the formal derivative then contains
    `1/(1+(-z)) = 1/0 = inf` factors that propagate NaN. With it,
    derivatives at the boundary match the high-precision sympy/mpmath
    reference -- including the opposite-spin correlation contributions
    to vrho_beta / vsigma_bb that are physically non-zero when nb is
    tiny.

    `na`, `nb` are the kernel symbols against which the substitution
    was built; the rules below are written in their terms."""
    expr = _inline_perfunc_helpers(expr)
    # Resolve spin-density screen markers to the raw channel density (na/nb)
    # before the (1 +/- z) energy terms collapse below, so empty-channel screens
    # are exact rather than the cancelling reconstruction.
    expr = _resolve_screen_dens_kernel(expr, na, nb)
    ntot = na + nb
    z = (na - nb) / ntot
    rules = {
        z + 1: 2 * na / ntot,
        1 + z: 2 * na / ntot,
        -z + 1: 2 * nb / ntot,
        1 - z: 2 * nb / ntot,
    }
    return expr.xreplace(rules)


def _numeric_clean_source(expr):
    """Source-level rewrites: applied once to the functional's f(...)
    expression (and to each helper body) before symbolic differentiation.
    The factored form propagates naturally through sp.diff, so doing
    this here -- once -- is far cheaper than running it on every
    derivative output, which would be O(thousands) of calls per
    functional for an order-2 mGGA."""
    expr = _factor_const_minus_square(expr)
    expr = _rewrite_libm_stable_forms(expr)
    return expr


# Helper bodies are differentiated eagerly in Helper.__init__, so the cleaner
# must run inside construction -- rebinding h.expr afterwards leaves the
# cached raw-body derivatives in _derivs, and emission reads _derivs. The
# hook (rather than an import) avoids a helper.py -> libxc_codegen cycle.
helper_mod.SOURCE_CLEAN = _numeric_clean_source


def _has_neg_base_pow(m):
    """True if the Mul carries a `(-base)**e` factor -- the artifact that
    differentiation creates and a powsimp combine repairs."""
    return any(a.is_Pow and a.base.could_extract_minus_sign()
               for a in sp.Mul.make_args(m))


def _numeric_clean_postdiff(expr):
    """Post-differentiation rewrite, applied to each emitted output.
    Differentiation creates `x/(-x)**(2/3) = -(-x)**(1/3)` forms (the source
    never does), which a powsimp combine repairs. Running the full sp.powdenest
    -- a *global* powsimp pass -- over each whole order-4 output is pathological:
    it was 74% of lda_xc_ksdt's ~3 h generation. Instead apply the combine only
    to the Muls that actually carry a `(-base)**e` factor, leaving the bulk
    untouched (~48x faster on ksdt, identical values; the only form differences
    are combines powsimp would also have done globally, e.g. `2*2**a` vs
    `2**(a+1)`, or term reordering).

    force=True stays out: it would collapse Abs(z) -> z (sympy reads `force` as
    "every symbol is positive"), stripping the m_abs() screens w94 and others
    rely on; the (-(z-1))**(2/3) boundary case carries the structure sympy needs
    without it."""
    return expr.replace(lambda m: m.is_Mul and _has_neg_base_pow(m),
                        lambda m: sp.powsimp(m))


# --------------------------------------------------------------------------
# Conditional helper calls
# --------------------------------------------------------------------------
#
# A helper written as `my_piecewise3(c, A(clamp(x)), B(clamp(x)))` -- the
# standard two-regime form, where each branch's argument is clamped into its
# own valid domain so neither can produce a NaN that the select would then
# have to swallow -- consolidates into *two* unconditional calls plus a
# ternary that throws one result away. That is exactly the right shape for
# the symbolic layer and for AD, but in the emitted C it means every grid
# point pays for both regimes.
#
# For cheap helpers that is the better trade anyway: a branch costs more in
# missed prediction and blocked vectorization than a handful of flops. But
# when a branch is a long series expansion -- gga_x_wpbeh's term2345_series
# runs to a couple of thousand lines -- evaluating the unselected side
# dominates the kernel. So: work out, per consolidated call, the piecewise
# context its results are actually read under, and if that context is a
# single branch and the helper is expensive, guard the call with a real `if`.
#
# The array is zero-initialized so the unselected slots are well-defined
# reads rather than indeterminate ones; the select discards them either way.

_HELPER_COST_CACHE = {}

# Flop-count above which skipping an unselected branch beats the branch
# itself. Well clear of the small clamps/screens (opz_pow_n, z_thr, ...)
# that make up the bulk of the helper calls in a typical kernel.
_GUARD_COST_MIN = 200

# Cap on how many distinct branch contexts we track per temporary before
# giving up on it and calling it unconditional. Keeps the propagation
# linear; a temp read under more than a handful of contexts is not one we
# could have guarded anyway.
_MAX_CTXS = 8


def _helper_cost(helper, kmap):
    """Rough flop count of one consolidated call to `helper`, charging
    nested helper calls at their own transitive cost. Used only to decide
    whether skipping the call is worth a branch, so the accounting is
    deliberately crude -- each distinct nested helper is charged once."""
    key = id(helper)
    cached = _HELPER_COST_CACHE.get(key)
    if cached is not None:
        return cached
    _HELPER_COST_CACHE[key] = 0          # cycle guard
    total, nested = 0, {}
    for mi in _helper_slots(helper, kmap):
        e = helper._derivs[mi]
        total += sp.count_ops(e)
        for sub in sp.preorder_traversal(e):
            if isinstance(sub, sp.Function) and hasattr(type(sub), "helper"):
                nested.setdefault(id(type(sub).helper), type(sub).helper)
    for h in nested.values():
        if h is not helper and id(h) in kmap:
            total += _helper_cost(h, kmap)
    _HELPER_COST_CACHE[key] = total
    return total


def _use_contexts(roots, repl):
    """Map every symbol read by `roots` (plus, transitively, by the CSE
    temporaries they reach) to the set of piecewise branch contexts it is
    read under.

    A context is a frozenset of (condition, taken) pairs; the empty
    frozenset means "read unconditionally". `repl` must be in CSE order
    (a temp's definition only references earlier temps), so walking it in
    reverse guarantees every use of a temp is recorded before its own
    definition is expanded."""
    TOP = frozenset()
    ctxs = {}

    def walk(expr, ctx):
        stack = [(expr, ctx)]
        while stack:
            e, c = stack.pop()
            if e.is_Symbol:
                ctxs.setdefault(e, set()).add(c)
                continue
            f = e.func
            if f is my_piecewise3:
                cond, t, o = e.args
                stack.append((cond, c))
                stack.append((t, c | {(cond, True)}))
                stack.append((o, c | {(cond, False)}))
                continue
            if f is my_piecewise5:
                c1, t1, c2, t2, o = e.args
                stack.append((c1, c))
                stack.append((t1, c | {(c1, True)}))
                stack.append((c2, c | {(c1, False)}))
                stack.append((t2, c | {(c1, False), (c2, True)}))
                stack.append((o, c | {(c1, False), (c2, False)}))
                continue
            stack.extend((a, c) for a in e.args)

    for r in roots:
        walk(r, TOP)
    for sym, sub in reversed(repl):
        seen = ctxs.get(sym)
        if not seen:
            continue                     # temp is dead
        if TOP in seen or len(seen) > _MAX_CTXS:
            seen = {TOP}
            ctxs[sym] = seen
        for c in seen:
            walk(sub, c)
    return ctxs


def _call_guard(arr, size, ctxs):
    """The single branch context every slot of consolidated call `arr` is
    read under, or None if the slots are read unconditionally, under more
    than one context, or not at all."""
    seen = set()
    for slot in range(size):
        s = ctxs.get(sp.Symbol(f"{arr}_{slot}"))
        if s:
            seen |= s
    if len(seen) != 1:
        return None
    (ctx,) = seen
    return ctx or None


def _emit_with_helpers(exprs, printer, kmap, return_records=False):
    """CSE `exprs` (which may contain helper applications) and return
    (lines, strs): C body lines declaring the CSE temporaries and the
    consolidated helper calls -- scheduled in dependency order so each
    call's arguments are ready -- and the printed C for each input
    expression.

    With return_records=True also return (records, red_body): `records`
    is a list of (chunk_lines, defines, uses) parallel to the emitted
    declarations -- one per CSE temp or per helper-call array+invocation
    -- and `red_body` the symbolic reduced expression for each input.
    These let the caller attach per-statement #ifndef guards by
    derivative order while keeping the single shared CSE intact."""
    # DiracDelta only arises from differentiating a Heaviside/abs/m_max
    # branch; in the integration context the integrand is smooth on a
    # measure-1 set and the delta-term contribution is zero. Strip it
    # before CSE so it doesn't become a C reference to an undeclared
    # DiracDelta function.
    exprs = [e.replace(lambda x: isinstance(x, sp.DiracDelta),
                       lambda x: sp.S.Zero)
             if e.has(sp.DiracDelta) else e
             for e in exprs]
    calls, exprs2 = _consolidate_helpers(exprs, kmap)
    flat_args = [a for (_, _, args) in calls for a in args]
    # CSE temps use a `_t` prefix to keep clear of helper names/args
    # (e.g. mGGA τ helpers take parameters `t0`/`t1`; the gga_x_wpbeh
    # family defines helpers literally named `t1` through `t10`).
    repl, reduced = _cse_fast.cse(flat_args + list(exprs2),
                           symbols=sp.numbered_symbols("_t", start=1),
                           optimizations=[])
    n = len(flat_args)
    red_args, red_body = reduced[:n], reduced[n:]

    specs, k = [], 0
    for (arr, helper, args) in calls:
        specs.append((arr, helper, red_args[k:k + len(args)]))
        k += len(args)

    temp_names = {s for s, _ in repl}

    def deps(e):
        return {s for s in e.free_symbols
                if s in temp_names or s.name.startswith("_hc")}

    # Branch context each consolidated call's results are read under. The
    # arguments are roots too (a call may feed another call's arguments, and
    # those reads are not under the consumer's select).
    ctxs = _use_contexts(list(red_body) + list(red_args), repl)

    lines = []
    records = []        # (chunk_lines, defines, uses) parallel to `lines`
    done = set()
    repl_left = list(repl)
    calls_left = list(specs)              # already dependency-ordered
    while repl_left or calls_left:
        progressed = False
        while calls_left:
            arr, helper, rargs = calls_left[0]
            need = set().union(*(deps(a) for a in rargs)) if rargs else set()
            hslots = _helper_slots(helper, kmap)
            size = len(hslots)
            dim = _slot_dim(helper, kmap)
            guard = None
            if _helper_cost(helper, kmap) >= _GUARD_COST_MIN:
                guard = _call_guard(arr, size, ctxs)
            if guard is not None:
                gneed = need | set().union(*(deps(c) for c, _ in guard))
                if gneed <= done:
                    need = gneed
                elif need <= done:
                    # The condition is not ready but the call is. Guarding is
                    # only ever an optimization, so drop it rather than stall
                    # the schedule (or deadlock it, if the condition can only
                    # become ready after this call).
                    guard = None
                else:
                    need = gneed
            if not need <= done:
                break
            argc = ", ".join(["p"] + [printer.doprint(a) for a in rargs])
            if guard is None:
                chunk = [f"  double {arr}[{dim}];",
                         f"  {_helper_variant(helper.name)}({argc}, {arr});"]
            else:
                cond = " && ".join(
                    printer.doprint(c) if taken else f"!({printer.doprint(c)})"
                    for c, taken in sorted(guard, key=lambda p: str(p[0])))
                chunk = [f"  double {arr}[{dim}] = {{0.}};",
                         f"  if({cond}) {_helper_variant(helper.name)}"
                         f"({argc}, {arr});"]
            lines += chunk
            defs = {sp.Symbol(f"{arr}_{s}") for s in range(size)}
            records.append((chunk, defs, set(need)))
            done |= defs
            calls_left.pop(0)
            progressed = True
        still = []
        for sym, sub in repl_left:
            if deps(sub) <= done:
                line = f"  const double {sym.name} = {printer.doprint(sub)};"
                lines.append(line)
                records.append(([line], {sym}, deps(sub)))
                done.add(sym)
                progressed = True
            else:
                still.append((sym, sub))
        repl_left = still
        if not progressed:
            raise RuntimeError("helper-call scheduling deadlock")
    strs = [printer.doprint(e) for e in red_body]
    if return_records:
        return lines, strs, records, list(red_body)
    return lines, strs


def _coalesce_guards(lines):
    """Merge consecutive '#if X ... #endif' blocks that share the same guard X
    into a single block, dropping the redundant '#endif'/'#if X' pairs the
    per-statement order guards emit (cuts the helper boilerplate ~3x)."""
    _open = ("#if ", "#ifndef ")
    out = []
    for ln in lines:
        s = ln.strip()
        if s.startswith(_open) and out and out[-1].strip() == "#endif":
            # The guard the trailing #endif closes. Blocks may already span
            # several statements (after a prior merge), so scan back to the
            # matching #ifndef tracking depth.
            depth, j = 0, len(out) - 1
            while j >= 0:
                t = out[j].strip()
                if t == "#endif":
                    depth += 1
                elif t.startswith(_open):
                    depth -= 1
                    if depth == 0:
                        break
                j -= 1
            if j >= 0 and out[j].strip() == s:
                out.pop()      # drop the closing #endif and reuse the open block
                continue       # without re-opening with a duplicate #ifndef
        out.append(ln)
    return out


# z=const specialized helpers for the spin-restricted (unpol) kernels: a helper
# called with a constant spin argument is re-emitted with that arg fixed and its
# spin-polarization branches folded.  Collected per functional.
_SPECIALIZED = {}          # (helper name, fixed) -> specialized Helper
_SPECIALIZED_ORDER = []    # creation order (dependencies first), for emission


def _reset_specialized():
    _SPECIALIZED.clear()
    _SPECIALIZED_ORDER.clear()
    _PFORM_CACHE.clear()
    # _DEEP_USED_CACHE is keyed on id(helper); once the specialized helpers
    # are dropped, a later in-process compile can allocate a new Helper at a
    # recycled id and silently inherit the previous functional's used-formals
    # set -- which _zero_out_dead_helper_calls turns into wrong derivatives.
    _DEEP_USED_CACHE.clear()
    # Same id-recycling hazard as _DEEP_USED_CACHE: a new Helper landing on a
    # freed id would inherit the previous functional's cost and be guarded (or
    # not) on the strength of an unrelated expression.
    _HELPER_COST_CACHE.clear()


def _const_tag(v):
    # Build a valid C identifier fragment from a constant value. Besides the
    # common -, /, . the constant may be a symbolic number (e.g. 6*pi**2), so
    # map every remaining non-alphanumeric character to '_'.
    s = str(v).replace("-", "m").replace("/", "_").replace(".", "p")
    return re.sub(r"[^0-9A-Za-z_]", "_", s)


def _get_specialized(h, fixed):
    """(Cached) Helper equal to `h` with the args in `fixed` (a tuple of
    (arg_index, constant)) removed and its body partially evaluated there,
    folded, and with nested constant-arg helper calls specialized too."""
    key = (h.name, fixed)
    if key in _SPECIALIZED:
        return _SPECIALIZED[key]
    fixed_d = dict(fixed)
    new_args = [h.args[i] for i in range(len(h.args)) if i not in fixed_d]
    subs = {h.args[i]: v for i, v in fixed_d.items()}
    body = _specialize_const_helpers(simplify_conditions(h.expr.subs(subs)))
    # Const-z (z=+/-1 for spin-scaled exchange, z=0 for correlation) specialized
    # helpers feed the unpol kernels, which bypass _kernel_clean. The z here is an
    # exact constant, so the screen has no (1+/-z) cancellation: resolve any
    # _screen_dens marker to the plain n_spin(rs, z) reconstruction (identical to
    # what mode-off screen_dens would have produced).
    if body.has(_screen_dens_marker):
        rs_syms = [a for a in new_args if getattr(a, "name", "") == "rs"]
        if rs_syms:
            rs_s = rs_syms[0]
            body = body.replace(
                lambda e: getattr(e, "is_Function", False)
                and e.func is _screen_dens_marker,
                lambda e: n_spin(rs_s, e.args[0]))
    tag = "".join(f"_{h.args[i].name}{_const_tag(v)}"
                  for i, v in sorted(fixed_d.items()))
    spec = Helper(h.name + tag, new_args, body, h.max_order)
    # Carry params info so an emitted specialized helper that uses params->...
    # gets its `params` declaration (else it references an undeclared name).
    if getattr(h, "params_struct", None):
        spec.params_struct = h.params_struct
    if getattr(h, "_needs_params", False):
        spec._needs_params = True
    _SPECIALIZED[key] = spec
    _SPECIALIZED_ORDER.append(spec)
    return spec


def _specialize_const_helpers(expr):
    """Replace each value-slot helper application that has constant arguments
    with a specialized variant (those args fixed and folded); an all-constant
    application folds to its value at this slot."""
    if not isinstance(expr, sp.Basic) or expr.is_Atom:
        return expr
    new_args = tuple(_specialize_const_helpers(a) for a in expr.args)
    if any(na is not oa for na, oa in zip(new_args, expr.args)):
        expr = expr.func(*new_args)
    cls = expr.func
    if (isinstance(expr, sp.Function) and hasattr(cls, "helper")
            and all(c == 0 for c in cls.multiindex)):
        h = cls.helper
        args = expr.args
        fixed = tuple((i, a) for i, a in enumerate(args) if a.is_number)
        if fixed:
            if len(fixed) == len(args):
                val = h.expr.subs(dict(zip(h.args, args)))
                return _specialize_const_helpers(simplify_conditions(val))
            spec = _get_specialized(h, fixed)
            drop = {i for i, _ in fixed}
            keep = [a for i, a in enumerate(args) if i not in drop]
            return spec.call(*keep)
    return expr


def _register_specialized(kmap, max_order):
    """Register every newly-synthesized helper (z=const specializations and the
    spin-scaled xchan kernel) in kmap so the kernel emission resolves it."""
    for spec in _SPECIALIZED_ORDER:
        if id(spec) not in kmap:
            spec.ensure_order(max_order)
            kmap[id(spec)] = max_order


def _specialize_unpol(spinmode, f_expr, nf, kmap, max_order):
    """For the unpol spinmode (constant spin polarization: z=0 for correlation,
    z=1 per channel for spin-scaled exchange) specialize the helpers called with
    that constant so their spin-polarization branches fold, registering the new
    variants in kmap so the kernel emission resolves them. Pol is left generic."""
    if spinmode != "unpol":
        return f_expr, nf
    f_expr = _specialize_const_helpers(f_expr)
    nf = _specialize_const_helpers(nf)
    _register_specialized(kmap, max_order)
    return f_expr, nf


def _channel_grad_symbol(arg_syms):
    """The sigma_ss argument of a spin-scaled meta-GGA/GGA channel (None for the
    LDA channel, which carries no reduced gradient)."""
    for a in arg_syms:
        if getattr(a, "name", "") == "sigma_ss":
            return a
    return None


def _has_fractional_ss(expr, ss):
    """True if a half-integer (or other non-integer) power of sigma_ss appears
    anywhere in `expr` -- i.e. the bare reduced gradient sqrt(sigma_ss) has not
    folded. Integer powers (including 1/ss**k) are fine."""
    return any(getattr(p, "base", None) == ss
               and getattr(p.exp, "is_Rational", False) and p.exp.q != 1
               for p in expr.atoms(sp.Pow))


def _inline_grad_wrappers(expr, ss):
    """Recursively inline every @helper application that carries a fractional
    power of sigma_ss (the bare reduced gradient sqrt(sigma_ss)) in an argument.
    A @helper already called with an argument free of fractional sigma_ss -- e.g.
    b97_u(gamma, xs**2) with xs**2 = sigma_ss/n_s**k -- and special-function
    applications (no `helper` attribute: Becke-Roussel, erfcx, ...) are left in
    place, so only the opaque wrapper hiding the square is expanded."""
    while True:
        targets = [a for a in expr.atoms(sp.Function)
                   if hasattr(type(a), "helper")
                   and any(_has_fractional_ss(arg, ss) for arg in a.args)]
        if not targets:
            return expr
        for app in targets:
            h = type(app).helper
            expr = expr.subs(app, h.expr.subs(dict(zip(h.args, app.args))))


# --- auto p-form of squared-only helper subtrees -----------------------------
# The compact alternative to inlining: a helper H(x, ...) that is even in its
# reduced-gradient argument x (uses it only through x**2) has a p-form variant
# H_p(p, ...) = H(sqrt(p), ...) that is rational in p = x**2.  Emitting H_p and
# calling it with x**2 keeps the helper OPAQUE and compact (its order-4 jet is
# computed once on its own small body) while feeding it the square, which is
# rational in sigma_ss.  This is what the source-level mgga_exchange_p /
# tpss_x p-form does by hand; here the generator does it for any squared-only
# subtree, so the channel body neither inlines nor keeps a fractional sigma_ss.

_PFORM_CACHE = {}   # (id(helper), grad_slot) -> p-form Helper (or None if not even)


def _rewire_to_square(expr, x):
    """Rewrite `expr` so the reduced-gradient symbol x only ever reaches an opaque
    helper as an even quantity: a helper called with the bare x is replaced by its
    p-form variant fed x**2; helpers called with an already-even argument are kept
    and their arguments rewired.  Returns None if a helper (or special function) is
    called with x in a way that cannot be squared away."""
    if x not in expr.free_symbols:
        return expr
    cls = type(expr)
    if isinstance(expr, sp.Function) and hasattr(cls, "helper"):
        grad_slot, new_args = None, []
        for j, a in enumerate(expr.args):
            if a == x:
                grad_slot = j
                new_args.append(x**2)          # -> p after the final x->sqrt(p)
            elif x in getattr(a, "free_symbols", ()):
                r = _rewire_to_square(a, x)
                if r is None:
                    return None
                new_args.append(r)
            else:
                new_args.append(a)
        if grad_slot is not None:
            hp = _pform_helper(cls.helper, grad_slot)
            if hp is None:
                return None
            return hp.call(*new_args)
        return expr.func(*new_args)
    if not expr.args:
        return expr
    out = []
    for a in expr.args:
        r = _rewire_to_square(a, x)
        if r is None:
            return None
        out.append(r)
    return expr.func(*out)


def _pform_helper(h, j):
    """Build (memoised) the p-form variant of helper `h` in gradient slot j:
    H_p(p, ...) = H(sqrt(p), ...), rational in p because H is even in that
    argument.  Returns None when H is not even-reducible (a genuine
    sqrt-of-gradient, e.g. SCAN)."""
    key = (id(h), j)
    if key in _PFORM_CACHE:
        return _PFORM_CACHE[key]
    _PFORM_CACHE[key] = None                    # recursion guard
    x = h.args[j]
    p = sp.Symbol(x.name + "2", positive=True)
    rewired = _rewire_to_square(h.expr, x)
    if rewired is None:
        return None
    body = rewired.subs(x, sp.sqrt(p))          # even powers of x fold to p
    if _has_fractional_ss(body, p):             # a half-integer p survived -> not even
        return None
    new_args = list(h.args)
    new_args[j] = p
    hp = Helper(h.name + "_pf", new_args, body, h.max_order)
    if getattr(h, "params_struct", None):
        hp.params_struct = h.params_struct
    if getattr(h, "_needs_params", False):
        hp._needs_params = True
    _PFORM_CACHE[key] = hp
    _SPECIALIZED_ORDER.append(hp)
    return hp


def _fold_channel_gradient(xbody, ss):
    """Remove the spurious sqrt(sigma_ss) a squared-only exchange enhancement picks
    up when it is hidden behind an opaque wrapper helper with a *linear* reduced-
    gradient interface (a mixed hyb_mgga_xc, or any functional whose exchange is
    routed through a helper taking the bare xs).  The channel would otherwise
    differentiate through xs = sqrt(sigma_ss) and reintroduce the 1/sigma**(k/2)
    tail that traps at sigma_ss = 0.

    For each such wrapper, first try the compact fix: replace H(xs, ...) with its
    p-form variant H_p(xs**2, ...) (recursively p-forming H's even subtree), so the
    helper stays opaque and its order-4 body is not inlined into the channel.  Only
    when H is not even-reducible (a genuine sqrt-of-gradient exchange, SCAN-type)
    fall back to inlining, and keep the inline only when it actually removes the
    fractional sigma_ss -- otherwise the wrapper is left untouched."""
    if ss is None:
        return xbody
    # Sorted for the same reason as the helper toposort: this loop *creates*
    # p-form helpers, and creation order is emission order, so iterating the
    # raw atoms() set would shuffle them between runs.
    for app in sorted(xbody.atoms(sp.Function), key=sp.default_sort_key):
        if not hasattr(type(app), "helper"):
            continue
        gslot = next((j for j, a in enumerate(app.args)
                      if _has_fractional_ss(a, ss)), None)
        if gslot is None:
            continue
        hp = _pform_helper(type(app).helper, gslot)
        if hp is not None:
            new_args = list(app.args)
            new_args[gslot] = app.args[gslot]**2
            xbody = xbody.subs(app, hp.call(*new_args))
            continue
        inlined = _inline_grad_wrappers(app, ss)
        if not _has_fractional_ss(inlined, ss):
            xbody = xbody.subs(app, inlined)
    return xbody


def _build_xchan(arg_syms, xbody, kmap, max_order, params_struct=None):
    """Build the single-channel spin-scaled exchange/kinetic helper xchan(...)
    from its per-channel energy density `xbody` (n_s * f_x evaluated at z=1),
    folding the z=1 branches and registering it plus any nested specializations
    in kmap and the emission queue. Returns None when there is no spin-scalable
    part (pure correlation), in which case the functional stays fully z-based."""
    # Screen the channel on its own (raw, floored) density, mirroring the
    # non-split gga/lda_exchange screen. work_mgga floors an empty channel to
    # dens_threshold and still calls xchan there; without this screen a
    # special-function exchange (e.g. the Becke-Roussel solver in mgga_x_mbr)
    # is evaluated at that degenerate density and can crash. n_s is the channel
    # density (the first xchan argument).
    n_s = arg_syms[0]
    xbody = my_piecewise3(sp.Le(n_s, p_a_dens_threshold), sp.S.Zero, xbody)
    xbody = _specialize_const_helpers(simplify_conditions(xbody))
    # Fold any spurious sqrt(sigma_ss) hidden behind an opaque exchange wrapper
    # (mixed hyb_mgga_xc), so the channel's sigma_ss derivatives stay
    # cancellation-free and finite at sigma_ss = 0, matching the pure-exchange case.
    ss = _channel_grad_symbol(arg_syms)
    if ss is not None:
        xbody = _specialize_const_helpers(simplify_conditions(
            _fold_channel_gradient(xbody, ss)))
    if xbody == 0:
        return None
    xchan = Helper("xchan", list(arg_syms), xbody, max_order)
    # A parametrized exchange (e.g. B97's c_x[]) references params-> in xchan's
    # body, so it needs the params declaration emitted (mirrors the kernel).
    if params_struct:
        xchan.params_struct = params_struct
    _SPECIALIZED_ORDER.append(xchan)
    _register_specialized(kmap, max_order)
    return xchan


def _emit_helper_c(h, printer, kmap, guard_kmaps=None):
    """Emit a helper as one inline C routine computing its value and every
    derivative slot into `out`.

    A single CSE is kept over all slots (full cross-order sharing). When
    `guard_kmaps` is given (one helper-order map per top-level derivative
    order), each declaration and each out[] write is wrapped in
    `#if _KMAX >= <order>` at the *lowest* order that consumes it, so a
    lower-order variant drops the code it does not need while shared temps
    are still computed once."""
    argnames = [a.name for a in h.args]
    vname = "f" if "f" not in argnames else "fval"
    slots = _helper_slots(h, kmap)
    slot_index = {mi: i for i, mi in enumerate(slots)}
    names = []
    for mi in slots:
        dv = [argnames[j] for j, c in enumerate(mi) for _ in range(c)]
        names.append(_deriv_name(dv, value_name=vname, base=vname))
    # Apply only the post-differentiation pass: the helper's body was
    # cleaned at resolution time, and its derivatives are computed by
    # symbolic diff so they may carry the `x/(-x)**(2/3)` form that
    # only powdenest catches.
    exprs = [_numeric_clean_postdiff(h._derivs[mi]) for mi in slots]
    decl, strs, records, red_body = _emit_with_helpers(
        exprs, printer, kmap, return_records=True)

    # Lowest top-level derivative order at which each slot is first needed.
    if guard_kmaps is None:
        slot_order = {mi: 0 for mi in slots}
    else:
        slot_order = {}
        for order in sorted(guard_kmaps):
            for mi in _helper_slots(h, guard_kmaps[order]):
                slot_order.setdefault(mi, order)
        for mi in slots:
            slot_order.setdefault(mi, 0)

    # Propagate orders back through the CSE DAG: a temp/call's guard order
    # is the minimum over the slots and later declarations that consume it.
    slot_users = {}        # symbol -> slot indices using it
    for i, rb in enumerate(red_body):
        for s in rb.free_symbols:
            slot_users.setdefault(s, set()).add(i)
    rec_users = {}         # symbol -> record indices using it
    for k, (_chunk, _defs, uses) in enumerate(records):
        for s in uses:
            rec_users.setdefault(s, set()).add(k)
    rec_order = [0] * len(records)
    for k in reversed(range(len(records))):
        _chunk, defs, _uses = records[k]
        cons = [slot_order[slots[i]] for s in defs for i in slot_users.get(s, ())]
        cons += [rec_order[j] for s in defs for j in rec_users.get(s, ())]
        rec_order[k] = min(cons) if cons else 0

    # Order guards mirror the kernel's: the helper body is included once per
    # order with _KMAX set, so a slot needed only from order k up compiles
    # only into the variants that evaluate order k.
    def guard(order):
        return None if order == 0 else f"_KMAX >= {order}"

    arg_list = ", ".join(
        ["const xc_func_type *p"]
        + [f"double {a}" for a in argnames]
        + ["double *out"])
    # Build the body first, then gate the params extraction on whether the
    # fully-rendered body actually reads a parameter -- this catches every
    # reference form, including param-pointer constructs the intermediate
    # records/strs don't expose (e.g. xc_integrate(..., &(params->x), ...)).
    body = []
    for k, (chunk, _defs, _uses) in enumerate(records):
        g = guard(rec_order[k])
        if g:
            body.append(f"#if {g}")
        body += chunk
        if g:
            body.append("#endif")
    body.append("")
    for i, mi in enumerate(slots):
        g = guard(slot_order[mi])
        if g:
            body.append(f"#if {g}")
        body.append(f"  const double {names[i]} = {strs[i]};")
        body.append(f"  out[{slot_index[mi]}] = {names[i]};")
        if g:
            body.append("#endif")
    out = [f"GPU_DEVICE_FUNCTION static inline void "
           f"{_helper_variant(h.name)}({arg_list}) {{"]
    # Emit the params extraction whenever the helper has a params struct: param
    # references reach the rendered C through routes the body text doesn't
    # expose (the `params,` arg form, post-emission REPLACE rules), so gating on
    # the body risks a missing declaration.
    if getattr(h, "params_struct", None):
        out.append(f"  const {h.params_struct} *params = "
                   f"(const {h.params_struct} *)(p->params);")
    out.append("")
    out += body
    out.append("}")
    out.append("")
    return "\n".join(_coalesce_guards(out))


class _Graded:
    """Marker returned by a family emitter to request the self-including
    single-body file layout in _compile_module_inner."""
    def __init__(self, stanza, template):
        self.stanza = stanza
        self.template = template


def _helper_stanza(name, guard, max_order, min_order=0):
    """Re-include the helper body once per order.

    Keyed on order alone, not (order, spin): helpers are spin-independent,
    so reusing the kernel's stanza would define each variant twice."""
    lines = []
    for T in range(min_order, max_order + 1):
        # order 0 needs no guard: XC_MAXORDER is 0..4, so `>= 0` is
        # vacuous. (A _vxc functional starts at 1, where it is not.)
        _g = [f"#if XC_MAXORDER >= {T}"] if T else []
        lines += _g + [f"#define _KMAX {T}",
                       f"#define {guard}",
                       f'#include "{name}.c"',
                       f"#undef {guard}",
                       "#undef _KMAX"] + (["#endif"] if T else [])
    return "\n".join(lines)


def _selfinclude_stanza(name, max_order, min_order=0):
    lines = []
    for T in range(min_order, max_order + 1):
        for spin in ("unpol", "pol"):
            _g = [f"#if XC_MAXORDER >= {T}"] if T else []
            lines += _g + [
                f"#define _KMAX {T}",
                f"#define _SPIN_UNPOL {1 if spin == 'unpol' else 0}",
                f"#define FUNC_NAME func_{ORDER_NAMES[T].lower()}_{spin}",
                f'#include "{name}.c"',
                "#undef _KMAX", "#undef _SPIN_UNPOL", "#undef FUNC_NAME",
            ] + (["#endif"] if T else [])
    return "\n".join(lines)


def _graded_template(sig, params_struct, unpol_body, pol_body):
    pre = []
    if params_struct:
        pre = ["  assert(p->params != NULL);",
               f"  const {params_struct} *params = "
               f"(const {params_struct} *)(p->params);",
               "  (void)params;"]
    return "\n".join([
        "GPU_DEVICE_FUNCTION static inline void",
        f"FUNC_NAME({sig})",
        "{",
        *pre,
        "#if _SPIN_UNPOL",
        unpol_body,
        "#else",
        pol_body,
        "#endif",
        "}"])


def _graded_kernel_body(input_reads, outputs, printer, kmap, max_order,
                        min_order=0):
    """One order-graded kernel body over a single shared CSE. `outputs` is the
    FULL (name, field, k, order, expr) list across all orders. Each temporary
    is guarded at the minimum order that consumes it; the base order
    (`min_order`, 0 for exc families, 1 for vxc-direct which has no EXC output)
    is always present, higher orders wrap in `#if _KMAX >= K`."""
    cleaned = [(n, f, k, o, _numeric_clean_postdiff(e))
               for n, f, k, o, e in outputs]
    outputs = [t for t in cleaned if t[4].is_zero is not True]
    exprs = [t[4] for t in outputs]
    _decl, strs, records, red_body = _emit_with_helpers(
        exprs, printer, kmap, return_records=True)
    out_order = [t[3] for t in outputs]
    # Min-consumer-order per CSE record, propagated back through the shared DAG.
    sym_users = {}
    for i, rb in enumerate(red_body):
        for s in rb.free_symbols:
            sym_users.setdefault(s, set()).add(i)
    rec_users = {}
    for k, (_c, _d, uses) in enumerate(records):
        for s in uses:
            rec_users.setdefault(s, set()).add(k)
    rec_order = [0] * len(records)
    for k in reversed(range(len(records))):
        _c, defs, _u = records[k]
        cons = [out_order[i] for s in defs for i in sym_users.get(s, ())]
        cons += [rec_order[j] for s in defs for j in rec_users.get(s, ())]
        rec_order[k] = min(cons) if cons else 0
    block = {K: [] for K in range(max_order + 1)}
    for k, (chunk, _d, _u) in enumerate(records):
        block[rec_order[k]] += chunk
    for i, (name, field, kk, o, _e) in enumerate(outputs):
        block[o].append(f"  const double {name} = {strs[i]};")
    for i, (name, field, kk, o, _e) in enumerate(outputs):
        block[o].append(f"  if(out->{field} != NULL)"
                        f" out->{field}[ip*p->dim.{field} + {kk}] += {name};")
    segs = list(input_reads)
    for K in range(0, min_order + 1):
        segs += block[K]
    for K in range(min_order + 1, max_order + 1):
        if any(l.strip() for l in block[K]):
            segs.append(f"#if _KMAX >= {K}")
            segs += block[K]
            segs.append("#endif")
    return "\n".join(segs)


def _params_prologue(params_struct, body_lines):
    """The params-struct extraction prologue. Emitted whenever the functional
    has a params struct: param references reach the rendered C through several
    routes (direct params->, the `params,` arg form, and post-emission REPLACE
    rules), so gating on the body text alone is unreliable and risks a missing
    declaration. `body_lines` is unused (kept for call-site symmetry)."""
    if not params_struct:
        return []
    return [
        "  assert(p->params != NULL);",
        f"  const {params_struct} *params ="
        f" (const {params_struct} *)(p->params);",
        "",
    ]


def _comb_with_repl(nvars, order):
    if order == 0:
        return [()]
    return list(combinations_with_replacement(range(nvars), order))


def _is_helper_call_zero(helper, multiindex):
    """True if calling `helper` at this derivative slot is identically
    zero. Cheap criterion (does not materialize the slot body): the
    slot is the partial derivative of helper's value body wrt the
    formal-arg positions counted by `multiindex`. If any of those
    formals is not *deeply used* in the value body (via
    `_deeply_used_formals`, which peeks through nested helper calls
    so e.g. mbr's br89_f -> br89_Q chain correctly reports `u` as
    not influencing the value), the derivative wrt that formal is
    zero, and the whole slot collapses. Avoids the O(huge) walk over
    each slot's symbolic body that recursive zero-out would do on
    SCAN/KCIS-class functionals."""
    if all(c == 0 for c in multiindex):
        return False
    used = _deeply_used_formals(helper, (0,) * len(helper.args))
    for i, c in enumerate(multiindex):
        if c > 0 and helper.args[i] not in used:
            return True
    return False


def _zero_out_dead_helper_calls(expr):
    """Replace any helper-Function application whose corresponding
    derivative-slot body is identically zero (per `_is_helper_call_zero`)
    with sp.S.Zero. The kernel chain rule sometimes spawns helper calls
    that compute to zero by construction -- e.g. mbr overrides
    `br89_Q(x, u, t)` so its body doesn't reference `u`, hence the
    entire br89_f -> br89_Q derivative chain w.r.t. the laplacian
    vanishes -- and leaving those calls in the emitted C forces a read
    of an input (often pylibxc's NULL `lapl` pointer for non-laplacian
    mGGAs) that isn't actually used in the value."""
    if not isinstance(expr, sp.Basic) or expr.is_Atom:
        return expr
    new_args = tuple(_zero_out_dead_helper_calls(a) for a in expr.args)
    if any(na is not oa for na, oa in zip(new_args, expr.args)):
        expr = expr.func(*new_args)
    cls = expr.func
    if isinstance(expr, sp.Function) and hasattr(cls, "helper"):
        helper = cls.helper
        if _is_helper_call_zero(helper, cls.multiindex):
            return sp.S.Zero
        # Replace each argument passed to a formal that does not deeply
        # influence this slot's value with 0, so a dead input (notably the
        # laplacian for tau-only mGGAs) is not read at all. The runtime
        # `lapl != NULL` guard is insufficient: work_mgga forms &lapl[ip*dim]
        # from a NULL base, yielding a non-NULL-but-invalid pointer for ip>0.
        if len(helper.args) == len(expr.args):
            used = _deeply_used_formals(helper, cls.multiindex)
            zeroed = tuple(a if f in used else sp.S.Zero
                           for f, a in zip(helper.args, expr.args))
            if zeroed != expr.args:
                expr = expr.func(*zeroed)
    return expr


_DEEP_USED_CACHE = {}


def _deeply_used_formals(helper, multiindex):
    """For a (helper, derivative-slot) pair, return the subset of
    formal args that actually influence the value of the body. An arg
    is "deeply used" if it appears as a free symbol in the body OR is
    passed (as a free symbol) into a deeply-used formal of a nested
    helper call. mbr's `br89_Q(x, u, t)` body never references `u`,
    so even though `br89_f`'s body contains `br89_Q(x, u, t)` and has
    `u` in its own free_symbols, the analysis here propagates `u` as
    not-deeply-used out through br89_f's caller as well."""
    key = (id(helper), tuple(multiindex))
    if key in _DEEP_USED_CACHE:
        return _DEEP_USED_CACHE[key]
    helper.ensure_order(sum(multiindex))
    body = helper._derivs[multiindex]
    formals = set(helper.args)
    used = set()

    def visit(e):
        if not isinstance(e, sp.Basic):
            return
        if e.is_Atom:
            if e in formals:
                used.add(e)
            return
        if e.is_Mul:
            # A product with a zero (dead derivative-slot) helper factor is
            # identically zero, so none of its other factors influence the
            # value -- don't let their symbols (e.g. a laplacian arriving via
            # d(uc)/dn_s next to a zero br89_f u-derivative) leak in as used.
            for fac in e.args:
                fcls = getattr(fac, "func", None)
                if (isinstance(fac, sp.Function) and hasattr(fcls, "helper")
                        and _is_helper_call_zero(fcls.helper, fcls.multiindex)):
                    return
        cls = e.func
        if isinstance(e, sp.Function) and hasattr(cls, "helper"):
            inner = cls.helper
            inner_used = _deeply_used_formals(inner, cls.multiindex)
            for f, a in zip(inner.args, e.args):
                if f in inner_used:
                    visit(a)
            return
        for a in e.args:
            visit(a)

    visit(body)
    _DEEP_USED_CACHE[key] = used
    return used


def _live_input_symbols(exprs):
    """Walk `exprs` and return the set of symbols that genuinely
    influence the value, peeking through nested helper Function
    applications via `_deeply_used_formals`. mbr's br89_f -> br89_Q
    chain is the motivating case: the kernel passes `la` into the
    `u` slot of br89_f, br89_f's body contains br89_Q(x, u, t), but
    mbr's override of br89_Q drops `u` from the body -- so `la` does
    not actually flow into the value and the lapl input read can be
    skipped (the kernel would otherwise segfault on pylibxc's NULL
    lapl pointer)."""
    live = set()

    def visit(e):
        if not isinstance(e, sp.Basic):
            return
        if e.is_Atom:
            if isinstance(e, sp.Symbol):
                live.add(e)
            return
        cls = e.func
        if isinstance(e, sp.Function) and hasattr(cls, "helper"):
            helper = cls.helper
            for formal, actual in zip(
                    helper.args,
                    e.args,
            ):
                if formal in _deeply_used_formals(helper, cls.multiindex):
                    visit(actual)
            return
        for a in e.args:
            visit(a)

    for e in exprs:
        visit(e)
    return live


def _gga_partials(order_rho, order_sigma, n_rho, n_sigma):
    rho_combos = _comb_with_repl(n_rho, order_rho)
    sigma_combos = _comb_with_repl(n_sigma, order_sigma)
    return [(r, s) for r in rho_combos for s in sigma_combos]


def _emit_lda(f_func, max_order, params_struct, printer, kmap, split=False,
              dim=3):
    spin_bodies = {}
    inv_dim = sp.Rational(1, dim)
    # The separable exchange/kinetic part obeys exact spin scaling, so it is
    # emitted once as a single-channel helper xchan(n_s) and called per spin
    # (from its own density at z=1: well-conditioned, cross-spin derivatives
    # structurally zero); the remainder stays on the (rs, zeta) path. split=False
    # (--no-spin-density) keeps the whole functional z-based.
    if split:
        f_rest_func, f_x_func = _split_xc(f_func)
        na_ = sp.Symbol("na", positive=True)
        nb_ = sp.Symbol("nb", positive=True)
        nt_ = na_ + nb_
        z_ = (na_ - nb_) / nt_
        xdirect = nt_ * f_x_func(r_ws(nt_), z_)
        xrecon = (na_ * f_x_func(r_ws(na_), sp.S.One)
                  + nb_ * f_x_func(r_ws(nb_), sp.S.One))
        split = _split_exact(xdirect, xrecon)
    if split:
        _ns = sp.Symbol("n_s", positive=True)
        with _screen_dens_context(False):
            xchan = _build_xchan([_ns], _ns * f_x_func(r_ws(_ns), sp.S.One),
                                 kmap, max_order, params_struct)
    else:
        f_rest_func, xchan = f_func, None
    for spinmode in ("unpol", "pol"):
        if spinmode == "unpol":
            na = sp.Symbol("na", positive=True)
            rho_syms = [na]
            n_total_expr = na
        else:
            na = sp.Symbol("na", positive=True)
            nb = sp.Symbol("nb", positive=True)
            rho_syms = [na, nb]
            n_total_expr = na + nb

        rs_expr = RS_FACTOR / n_total_expr ** inv_dim
        z_expr = (sp.S.Zero if spinmode == "unpol"
                  else (na - nb) / n_total_expr)
        nb_for_clean = rho_syms[1] if len(rho_syms) > 1 else sp.S.Zero
        f_rest_expr = simplify_conditions(_numeric_clean_source(
            _kernel_clean(f_rest_func(rs_expr, z_expr),
                          rho_syms[0], nb_for_clean)))
        nf_rest = n_total_expr * f_rest_expr
        if xchan is not None:
            nf_x = (2 * xchan.call(na / 2) if spinmode == "unpol"
                    else xchan.call(na) + xchan.call(nb))
        else:
            nf_x = sp.S.Zero
        nf = simplify_conditions(nf_rest + nf_x)
        f_expr = simplify_conditions(nf / n_total_expr)
        f_expr, nf = _specialize_unpol(spinmode, f_expr, nf, kmap, max_order)
        n_rho = len(rho_syms)

        # Full output list across all orders, emitted once as one graded body.
        outputs = []
        for o in range(0, max_order + 1):
            field = LDA_FIELDS[o][0]
            for k, idx in enumerate(_comb_with_repl(n_rho, o)):
                expr = nf if o > 0 else f_expr
                for i in idx:
                    expr = sp.diff(expr, rho_syms[i])
                dv = [rho_syms[i].name for i in idx]
                outputs.append((_deriv_name(dv), field, k, o, expr))
        outputs = [(n, f, k, o, _zero_out_dead_helper_calls(e))
                   for n, f, k, o, e in outputs]
        reads = [f"  const double {s.name} = rho[{i}];"
                 for i, s in enumerate(rho_syms)]
        reads.append("")
        spin_bodies[spinmode] = _graded_kernel_body(
            reads, outputs, printer, kmap, max_order)

    sig = ("const xc_func_type *p, size_t ip, const double *rho, "
           "xc_lda_out_params *out")
    template = _graded_template(sig, params_struct,
                                spin_bodies["unpol"], spin_bodies["pol"])
    return _Graded(_selfinclude_stanza(_GEN_NAME, max_order), template)


def _emit_gga(f_func, max_order, params_struct, printer, kmap, split=False,
              dim=3):
    spin_bodies = {}
    inv_dim = sp.Rational(1, dim)
    exp_grad = sp.Integer(1) + inv_dim       # 4/3 in 3D, 3/2 in 2D, 2 in 1D
    if split:
        f_rest_func, f_x_func = _split_xc(f_func)
        na_ = sp.Symbol("na", positive=True)
        nb_ = sp.Symbol("nb", positive=True)
        gaa_ = sp.Symbol("gaa", positive=True)
        gab_ = sp.Symbol("gab")
        gbb_ = sp.Symbol("gbb", positive=True)
        nt_ = na_ + nb_
        z_ = (na_ - nb_) / nt_
        xa_ = sp.sqrt(gaa_) / na_ ** exp_grad
        xb_ = sp.sqrt(gbb_) / nb_ ** exp_grad
        xt_ = sp.sqrt(gaa_ + 2 * gab_ + gbb_) / nt_ ** exp_grad
        xdirect = nt_ * f_x_func(r_ws(nt_), z_, xt_, xa_, xb_)
        xrecon = (na_ * f_x_func(r_ws(na_), sp.S.One, sp.S.Zero, xa_, xa_)
                  + nb_ * f_x_func(r_ws(nb_), sp.S.One, sp.S.Zero, xb_, xb_))
        split = _split_exact(xdirect, xrecon)
    if split:
        _ns = sp.Symbol("n_s", positive=True)
        _ss = sp.Symbol("sigma_ss", positive=True)
        _xc = sp.sqrt(_ss) / _ns ** exp_grad
        with _screen_dens_context(False):
            xchan = _build_xchan(
                [_ns, _ss],
                _ns * f_x_func(r_ws(_ns), sp.S.One, sp.S.Zero, _xc, _xc),
                kmap, max_order, params_struct)
    else:
        f_rest_func, xchan = f_func, None
    for spinmode in ("unpol", "pol"):
        if spinmode == "unpol":
            na = sp.Symbol("na", positive=True)
            gaa = sp.Symbol("gaa", positive=True)
            rho_syms = [na]
            sigma_syms = [gaa]
            n_total_expr = na
        else:
            na = sp.Symbol("na", positive=True)
            nb = sp.Symbol("nb", positive=True)
            gaa = sp.Symbol("gaa", positive=True)
            gab = sp.Symbol("gab")
            gbb = sp.Symbol("gbb", positive=True)
            rho_syms = [na, nb]
            sigma_syms = [gaa, gab, gbb]
            n_total_expr = na + nb

        rs_expr = RS_FACTOR / n_total_expr ** inv_dim
        if spinmode == "unpol":
            z_expr = sp.S.Zero
            xt_expr = sp.sqrt(gaa) / na ** exp_grad
            xs0_expr = sp.sqrt(gaa / 4) / (na / 2) ** exp_grad
            xs1_expr = xs0_expr
        else:
            z_expr = (na - nb) / n_total_expr
            sigma_total = gaa + 2 * gab + gbb
            xt_expr = (sp.sqrt(sigma_total)
                       / n_total_expr ** exp_grad)
            xs0_expr = sp.sqrt(gaa) / na ** exp_grad
            xs1_expr = sp.sqrt(gbb) / nb ** exp_grad
        nb_for_clean = nb if spinmode != "unpol" else sp.S.Zero
        na_for_clean = na
        f_rest_expr = simplify_conditions(_numeric_clean_source(_kernel_clean(
            f_rest_func(rs_expr, z_expr, xt_expr, xs0_expr, xs1_expr),
            na_for_clean, nb_for_clean)))
        nf_rest = n_total_expr * f_rest_expr
        if xchan is not None:
            nf_x = (2 * xchan.call(na / 2, gaa / 4) if spinmode == "unpol"
                    else xchan.call(na, gaa) + xchan.call(nb, gbb))
        else:
            nf_x = sp.S.Zero
        nf = simplify_conditions(nf_rest + nf_x)
        f_expr = simplify_conditions(nf / n_total_expr)
        f_expr, nf = _specialize_unpol(spinmode, f_expr, nf, kmap, max_order)
        n_rho = len(rho_syms)
        n_sigma = len(sigma_syms)

        # Full output list across all orders, emitted once as one graded body.
        outputs = []
        for o in range(0, max_order + 1):
            for field, oR, oS in GGA_FIELDS[o]:
                for k, (ridx, sidx) in enumerate(
                        _gga_partials(oR, oS, n_rho, n_sigma)):
                    expr = nf if o > 0 else f_expr
                    for i in ridx:
                        expr = sp.diff(expr, rho_syms[i])
                    for i in sidx:
                        expr = sp.diff(expr, sigma_syms[i])
                    dv = ([rho_syms[i].name for i in ridx]
                          + [sigma_syms[i].name for i in sidx])
                    outputs.append((_deriv_name(dv), field, k, o, expr))
        outputs = [(n, f, k, o, _zero_out_dead_helper_calls(e))
                   for n, f, k, o, e in outputs]
        used = _live_input_symbols(e for _, _, _, _, e in outputs)
        reads = [f"  const double {s.name} = rho[{i}];"
                 for i, s in enumerate(rho_syms)]
        reads += [f"  const double {s.name} = sigma[{i}];"
                  for i, s in enumerate(sigma_syms) if s in used]
        reads.append("")
        spin_bodies[spinmode] = _graded_kernel_body(
            reads, outputs, printer, kmap, max_order)

    sig = ("const xc_func_type *p, size_t ip, const double *rho, "
           "const double *sigma, xc_gga_out_params *out")
    template = _graded_template(sig, params_struct,
                                spin_bodies["unpol"], spin_bodies["pol"])
    return _Graded(_selfinclude_stanza(_GEN_NAME, max_order), template)


def _mgga_partials(orders, nvars):
    """orders / nvars are 4-tuples (rho, sigma, lapl, tau). Return every
    (rho-idx, sigma-idx, lapl-idx, tau-idx) combination of mixed
    partials."""
    groups = [_comb_with_repl(nv, o) for nv, o in zip(nvars, orders)]
    out = []
    for r in groups[0]:
        for s in groups[1]:
            for ll in groups[2]:
                for t in groups[3]:
                    out.append((r, s, ll, t))
    return out


def _mixed_partials(orders, nvars):
    """Every mixed-partial index combination across a set of variable
    groups: pick orders[g] derivatives (with repetition) from the
    nvars[g] variables of group g. Returns a list of tuples, each a
    per-group tuple of chosen 0-based indices, in the component order
    libxc's xc_*_out_params arrays use."""
    groups = [_comb_with_repl(nv, o) for nv, o in zip(nvars, orders)]
    return [tuple(combo) for combo in product(*groups)]


def _emit_mgga(f_func, max_order, params_struct, printer, kmap, split=False,
               dim=3):
    spin_bodies = {}
    inv_dim = sp.Rational(1, dim)
    exp_grad = sp.Integer(1) + inv_dim       # 4/3 in 3D, 3/2 in 2D
    exp_kin = sp.Integer(1) + 2 * inv_dim    # 5/3 in 3D, 2   in 2D
    if split:
        f_rest_func, f_x_func = _split_xc(f_func)
        na_ = sp.Symbol("na", positive=True)
        nb_ = sp.Symbol("nb", positive=True)
        gaa_ = sp.Symbol("gaa", positive=True)
        gab_ = sp.Symbol("gab")
        gbb_ = sp.Symbol("gbb", positive=True)
        la_ = sp.Symbol("la", real=True)
        lb_ = sp.Symbol("lb", real=True)
        ta_ = sp.Symbol("ta", positive=True)
        tb_ = sp.Symbol("tb", positive=True)
        nt_ = na_ + nb_
        z_ = (na_ - nb_) / nt_
        xa_ = sp.sqrt(gaa_) / na_ ** exp_grad
        xb_ = sp.sqrt(gbb_) / nb_ ** exp_grad
        xt_ = sp.sqrt(gaa_ + 2 * gab_ + gbb_) / nt_ ** exp_grad
        ua_, ub_ = la_ / na_ ** exp_kin, lb_ / nb_ ** exp_kin
        tta_, ttb_ = ta_ / na_ ** exp_kin, tb_ / nb_ ** exp_kin
        xdirect = nt_ * f_x_func(r_ws(nt_), z_, xt_, xa_, xb_,
                                 ua_, ub_, tta_, ttb_)
        xrecon = (na_ * f_x_func(r_ws(na_), sp.S.One, sp.S.Zero,
                                 xa_, xa_, ua_, ua_, tta_, tta_)
                  + nb_ * f_x_func(r_ws(nb_), sp.S.One, sp.S.Zero,
                                   xb_, xb_, ub_, ub_, ttb_, ttb_))
        split = _split_exact(xdirect, xrecon)
    if split:
        _ns = sp.Symbol("n_s", positive=True)
        _ss = sp.Symbol("sigma_ss", positive=True)
        _ls = sp.Symbol("lapl_s", real=True)
        _ts = sp.Symbol("tau_s", positive=True)
        _xc = sp.sqrt(_ss) / _ns ** exp_grad
        _uc = _ls / _ns ** exp_kin
        _tc = _ts / _ns ** exp_kin
        with _screen_dens_context(False):
            xchan = _build_xchan(
                [_ns, _ss, _ls, _ts],
                _ns * f_x_func(r_ws(_ns), sp.S.One, sp.S.Zero,
                               _xc, _xc, _uc, _uc, _tc, _tc),
                kmap, max_order, params_struct)
    else:
        f_rest_func, xchan = f_func, None
    for spinmode in ("unpol", "pol"):
        if spinmode == "unpol":
            na = sp.Symbol("na", positive=True)
            gaa = sp.Symbol("gaa", positive=True)
            la = sp.Symbol("la")
            ta = sp.Symbol("ta", positive=True)
            rho_syms = [na]
            sigma_syms = [gaa]
            lapl_syms = [la]
            tau_syms = [ta]
            n_total_expr = na
        else:
            na = sp.Symbol("na", positive=True)
            nb = sp.Symbol("nb", positive=True)
            gaa = sp.Symbol("gaa", positive=True)
            gab = sp.Symbol("gab")
            gbb = sp.Symbol("gbb", positive=True)
            la = sp.Symbol("la")
            lb = sp.Symbol("lb")
            ta = sp.Symbol("ta", positive=True)
            tb = sp.Symbol("tb", positive=True)
            rho_syms = [na, nb]
            sigma_syms = [gaa, gab, gbb]
            lapl_syms = [la, lb]
            tau_syms = [ta, tb]
            n_total_expr = na + nb

        rs_expr = RS_FACTOR / n_total_expr ** inv_dim
        if spinmode == "unpol":
            z_expr = sp.S.Zero
            xt_expr = sp.sqrt(gaa) / na ** exp_grad
            xs0_expr = sp.sqrt(gaa / 4) / (na / 2) ** exp_grad
            xs1_expr = xs0_expr
            u0_expr = (la / 2) / (na / 2) ** exp_kin
            u1_expr = u0_expr
            t0_expr = (ta / 2) / (na / 2) ** exp_kin
            t1_expr = t0_expr
        else:
            z_expr = (na - nb) / n_total_expr
            sigma_total = gaa + 2 * gab + gbb
            xt_expr = (sp.sqrt(sigma_total)
                       / n_total_expr ** exp_grad)
            xs0_expr = sp.sqrt(gaa) / na ** exp_grad
            xs1_expr = sp.sqrt(gbb) / nb ** exp_grad
            u0_expr = la / na ** exp_kin
            u1_expr = lb / nb ** exp_kin
            t0_expr = ta / na ** exp_kin
            t1_expr = tb / nb ** exp_kin
        nb_for_clean = nb if spinmode != "unpol" else sp.S.Zero
        na_for_clean = na
        f_rest_expr = simplify_conditions(_numeric_clean_source(_kernel_clean(
            f_rest_func(rs_expr, z_expr, xt_expr, xs0_expr, xs1_expr,
                        u0_expr, u1_expr, t0_expr, t1_expr),
            na_for_clean, nb_for_clean)))
        nf_rest = n_total_expr * f_rest_expr
        if xchan is not None:
            nf_x = (2 * xchan.call(na / 2, gaa / 4, la / 2, ta / 2)
                    if spinmode == "unpol"
                    else xchan.call(na, gaa, la, ta)
                    + xchan.call(nb, gbb, lb, tb))
        else:
            nf_x = sp.S.Zero
        nf = simplify_conditions(nf_rest + nf_x)
        f_expr = simplify_conditions(nf / n_total_expr)
        f_expr, nf = _specialize_unpol(spinmode, f_expr, nf, kmap, max_order)
        groups = [rho_syms, sigma_syms, lapl_syms, tau_syms]
        nvars = tuple(len(g) for g in groups)

        # Full output list across all orders, emitted once as one graded body
        # (see _graded_kernel_body); temps/writes are guarded `#if _KMAX >= K`.
        outputs = []
        for o in range(0, max_order + 1):
            for field, oR, oS, oL, oT in MGGA_FIELDS[o]:
                for k, idxs in enumerate(
                        _mgga_partials((oR, oS, oL, oT), nvars)):
                    expr = nf if o > 0 else f_expr
                    dv = []
                    for grp, gidx in zip(groups, idxs):
                        for i in gidx:
                            expr = sp.diff(expr, grp[i])
                            dv.append(grp[i].name)
                    outputs.append((_deriv_name(dv), field, k, o, expr))
        outputs = [(n, f, k, o, _zero_out_dead_helper_calls(e))
                   for n, f, k, o, e in outputs]
        used_live = _live_input_symbols(e for _, _, _, _, e in outputs)
        all_syms = set()
        for _, _, _, _, e in outputs:
            all_syms.update(e.free_symbols)
        reads = [f"  const double {s.name} = rho[{i}];"
                 for i, s in enumerate(rho_syms)]
        for arr, syms in (("sigma", sigma_syms),
                          ("lapl", lapl_syms),
                          ("tau", tau_syms)):
            for i, s in enumerate(syms):
                if s not in all_syms:
                    continue
                # `lapl` may be a NULL pointer at runtime (tau-only mGGAs);
                # always read it NULL-safe. See the pre-graded emitter history
                # for the live/dead rationale.
                if arr != "lapl" and s in used_live:
                    reads.append(f"  const double {s.name} = {arr}[{i}];")
                else:
                    reads.append(
                        f"  const double {s.name} = "
                        f"({arr} != NULL) ? {arr}[{i}] : 0.0;")
        reads.append("")
        spin_bodies[spinmode] = _graded_kernel_body(
            reads, outputs, printer, kmap, max_order)

    sig = ("const xc_func_type *p, size_t ip, const double *rho, "
           "const double *sigma, const double *lapl, const double *tau, "
           "xc_mgga_out_params *out")
    template = _graded_template(sig, params_struct,
                                spin_bodies["unpol"], spin_bodies["pol"])
    return _Graded(_selfinclude_stanza(_GEN_NAME, max_order), template)


# Per-family configuration for the *_vxc emitter: the libxc kernel
# signature and the (field-name, per-group derivative-count) table at
# each derivative order. The group order is (rho, sigma, lapl, tau);
# only the leading rho count is consulted, to skip rho-free outputs.
_VXC_CONFIG = {
    "lda": dict(
        sig=("const xc_func_type *p, size_t ip, const double *rho, "
             "xc_lda_out_params *out"),
        fields={o: [(LDA_FIELDS[o][0], (o,))] for o in range(1, 5)},
    ),
    "gga": dict(
        sig=("const xc_func_type *p, size_t ip, const double *rho, "
             "const double *sigma, xc_gga_out_params *out"),
        fields={o: [(f, (oR, oS)) for f, oR, oS in GGA_FIELDS[o]]
                for o in range(1, 5)},
    ),
    "mgga": dict(
        sig=("const xc_func_type *p, size_t ip, const double *rho, "
             "const double *sigma, const double *lapl, const double *tau, "
             "xc_mgga_out_params *out"),
        fields={o: [(f, tuple(c)) for f, *c in MGGA_FIELDS[o]]
                for o in range(1, 5)},
    ),
}


def _emit_vxc(family, f_func, max_order, params_struct, printer, kmap,
              spin_scaled=False, dim=3):
    """Generate C for a *_vxc functional, whose math file defines f(...)
    as the exchange-correlation potential itself, not the energy.

    Such functionals (model potentials like LB94, BJ06/TB09) have no
    energy density. The lowest output is the potential vrho; the higher
    ones -- v2rho2, v2rhosigma, ... -- are its derivatives, so a libxc
    output of derivative order K is the (K-1)-th derivative of f. The
    spin-down potential is f evaluated with the two spin channels
    exchanged.

    Outputs with no rho derivative (vsigma, vtau, ...) have no meaning
    for a potential-valued f and are skipped, mirroring maple2c's
    work_*_vxc. spin_scaled never applies here -- a model potential
    does not route through the spin-scaling wrappers -- and is accepted
    only for a uniform dispatch signature."""
    cfg = _VXC_CONFIG[family]
    # f is already a first-order quantity, so VXC is the lowest order;
    # clamp to the [VXC, LXC] range libxc's out-params can hold.
    top = min(max(max_order, 1), 4)
    inv_dim = sp.Rational(1, dim)
    exp_grad = sp.Integer(1) + inv_dim
    exp_kin = sp.Integer(1) + 2 * inv_dim
    spin_bodies = {}
    for spinmode in ("unpol", "pol"):
        unpol = spinmode == "unpol"
        na = sp.Symbol("na", positive=True)
        nb = sp.Symbol("nb", positive=True)
        rho_syms = [na] if unpol else [na, nb]
        n_tot = na if unpol else na + nb
        rs = RS_FACTOR / n_tot ** inv_dim
        z = sp.S.Zero if unpol else (na - nb) / n_tot
        groups = [rho_syms]
        # input_lines are accumulated unconditionally here; pruned at
        # emit time using the symbols actually referenced by pot_up /
        # pot_dn (see further down). This keeps NULL-pointer inputs --
        # pylibxc passes NULL for lapl when the functional doesn't use
        # it -- from being dereferenced.
        input_lines = [(s, f"  const double {s.name} = rho[{i}];")
                       for i, s in enumerate(rho_syms)]

        if family == "lda":
            pot_up = f_func(rs, z)
            pot_dn = None if unpol else f_func(rs, -z)
        else:
            gaa = sp.Symbol("gaa", positive=True)
            gab = sp.Symbol("gab")
            gbb = sp.Symbol("gbb", positive=True)
            sigma_syms = [gaa] if unpol else [gaa, gab, gbb]
            groups.append(sigma_syms)
            input_lines += [(s, f"  const double {s.name} = sigma[{i}];")
                            for i, s in enumerate(sigma_syms)]
            if unpol:
                xt = sp.sqrt(gaa) / na ** exp_grad
                xs0 = sp.sqrt(gaa / 4) / (na / 2) ** exp_grad
                xs1 = xs0
            else:
                xt = (sp.sqrt(gaa + 2 * gab + gbb)
                      / n_tot ** exp_grad)
                xs0 = sp.sqrt(gaa) / na ** exp_grad
                xs1 = sp.sqrt(gbb) / nb ** exp_grad

            if family == "gga":
                pot_up = f_func(rs, z, xt, xs0, xs1)
                pot_dn = None if unpol else f_func(rs, -z, xt, xs1, xs0)
            else:  # mgga
                la = sp.Symbol("la")
                lb = sp.Symbol("lb")
                ta = sp.Symbol("ta", positive=True)
                tb = sp.Symbol("tb", positive=True)
                lapl_syms = [la] if unpol else [la, lb]
                tau_syms = [ta] if unpol else [ta, tb]
                groups += [lapl_syms, tau_syms]
                input_lines += [(s, f"  const double {s.name} = lapl[{i}];")
                                for i, s in enumerate(lapl_syms)]
                input_lines += [(s, f"  const double {s.name} = tau[{i}];")
                                for i, s in enumerate(tau_syms)]
                if unpol:
                    u0 = (la / 2) / (na / 2) ** exp_kin
                    t0 = (ta / 2) / (na / 2) ** exp_kin
                    u1, t1 = u0, t0
                else:
                    u0 = la / na ** exp_kin
                    u1 = lb / nb ** exp_kin
                    t0 = ta / na ** exp_kin
                    t1 = tb / nb ** exp_kin
                pot_up = f_func(rs, z, xt, xs0, xs1, u0, u1, t0, t1)
                pot_dn = (None if unpol else
                          f_func(rs, -z, xt, xs1, xs0, u1, u0, t1, t0))

        # Rewrite the (1 +/- z) spin-density reconstructions to the raw na/nb
        # form (as the energy emitters do via _kernel_clean), so a model
        # potential evaluated on the floored empty channel uses that channel's
        # own density rather than the cancelling (1 - z)*nt/2 -- which otherwise
        # couples the empty-channel potential to the occupied channel (tb09's
        # down-channel vrho on the H atom).
        nb_clean = nb if not unpol else sp.S.Zero
        pot_up = simplify_conditions(_kernel_clean(pot_up, na, nb_clean))
        if pot_dn is not None:
            pot_dn = simplify_conditions(_kernel_clean(pot_dn, na, nb_clean))
        nvars = tuple(len(g) for g in groups)

        # Full output list across all vxc orders (1..top), emitted once as one
        # order-graded body (base order is VXC=1, not EXC).
        outputs = []
        for o in range(1, top + 1):
            for field, counts in cfg["fields"][o]:
                if counts[0] < 1:      # rho-free output: no vxc form
                    continue
                for k, idxs in enumerate(_mixed_partials(counts, nvars)):
                    ridx = idxs[0]
                    # Spend one rho derivative to descend onto the potential;
                    # its spin channel selects vrho_0/1.
                    expr = pot_up if ridx[0] == 0 else pot_dn
                    rest = (ridx[1:],) + idxs[1:]
                    for grp, gidx in zip(groups, rest):
                        for i in gidx:
                            expr = sp.diff(expr, grp[i])
                    outputs.append((f"{field}_{k}", field, k, o, expr))
        outputs = [(n, f, k, o, _zero_out_dead_helper_calls(e))
                   for n, f, k, o, e in outputs]
        used = _live_input_symbols(e for _, _, _, _, e in outputs)
        # rho reads stay unconditional (the functional is rho-based by
        # construction); other inputs only if referenced by some output.
        reads = [line for sym, line in input_lines
                 if sym in rho_syms or sym in used]
        reads.append("")
        spin_bodies[spinmode] = _graded_kernel_body(
            reads, outputs, printer, kmap, top, min_order=1)

    template = _graded_template(cfg["sig"], params_struct,
                                spin_bodies["unpol"], spin_bodies["pol"])
    return _Graded(_selfinclude_stanza(_GEN_NAME, top, min_order=1), template)


_FAMILY_DISPATCH = {
    "lda_exc": _emit_lda,
    "gga_exc": _emit_gga,
    "mgga_exc": _emit_mgga,
    "lda_vxc": partial(_emit_vxc, "lda"),
    "gga_vxc": partial(_emit_vxc, "gga"),
    "mgga_vxc": partial(_emit_vxc, "mgga"),
}


class _ParamPrefixPrinter(HelperCPrinter):
    """Printer that auto-maps `params_a_NAME` symbols to `params->NAME`."""

    def _print_Symbol(self, expr):
        if expr.name in self.symbol_map:
            return self.symbol_map[expr.name]
        if expr.name.startswith("params_a_"):
            member = expr.name[len("params_a_"):]
            # mpl2py flattens a 2-D parameter table X[i][j] into params
            # named X_<i>_; restore the C subscript so the access hits
            # the real struct member X[i] (possibly [j] in turn).
            member = re.sub(r"_(\d+)_(?=\[|$)", r"[\1]", member)
            return "params->" + member
        # consolidated helper-call slot: _hc<call>_<slot> -> _hc<call>[<slot>]
        m = re.match(r"_hc(\d+)_(\d+)$", expr.name)
        if m:
            return f"_hc{m.group(1)}[{m.group(2)}]"
        return expr.name


def compile_module(mod, output_path, max_order=1, spin_density=True):
    """Generate C code from a math module and write it to output_path.

    max_order is the highest derivative order generated -- 0 is exc, 1
    adds vxc, and 2/3/4 add fxc/kxc/lxc. It defaults to 1 (first
    derivatives): the higher orders are far more expensive to generate.

    Exchange and kinetic-energy functionals obey exact spin scaling, so
    each spin channel is evaluated independently from its own same-spin
    density. Set spin_density=False to force the legacy (rs, zeta) path."""
    type_str = mod.TYPE
    params_struct = getattr(mod, "PARAMS_STRUCT", None)
    # Every functional is split: its separable exchange/kinetic part is
    # spin-scaled (evaluated per channel), the remainder stays on the (rs, zeta)
    # path. spin_density=False (--no-spin-density) forces the whole functional
    # onto the legacy z-based path.
    split = spin_density

    # Dimension detection: a functional advertises 1D/2D via define() at
    # module top-level. We mutate libxc_codegen's DIMENSIONS / RS_FACTOR
    # / LDA_X_FACTOR module globals so that library helpers (r_ws,
    # n_total, lda_x_spin, ...) called during helper resolution and
    # kernel emission pick up the right values; the emitter is passed
    # the same dim explicitly. Saved and restored around the whole
    # body so successive compile_module calls see a clean slate.
    dim = _detect_dimension(mod)
    _dim_saved = _set_dimension(dim)
    # The .py module did `from libxc_codegen import *` at top, which
    # copied the (then-default 3D) values of DIMENSIONS / RS_FACTOR /
    # LDA_X_FACTOR into its own namespace. Refresh those copies so any
    # function or @helper body in the .py file that names them sees the
    # per-module values too. Save and restore for symmetry.
    _mod_saved = {k: getattr(mod, k, _MISSING)
                  for k in ("DIMENSIONS", "RS_FACTOR", "LDA_X_FACTOR")}
    mod.DIMENSIONS = DIMENSIONS
    mod.RS_FACTOR = RS_FACTOR
    mod.LDA_X_FACTOR = LDA_X_FACTOR
    try:
        return _compile_module_inner(
            mod, output_path, max_order, spin_density,
            type_str, params_struct, split, dim)
    finally:
        for k, v in _mod_saved.items():
            if v is _MISSING:
                delattr(mod, k)
            else:
                setattr(mod, k, v)
        _restore_dimension(_dim_saved)


_MISSING = object()


def _compile_module_inner(mod, output_path, max_order, spin_density,
                          type_str, params_struct, split, dim):
    global _MODULE_HAS_EXCHANGE, _GEN_MAX_ORDER, _GEN_NAME
    _MODULE_HAS_EXCHANGE = False
    _GEN_MAX_ORDER = max_order
    _GEN_NAME = mod.__name__.split(".")[-1]   # for the self-include stanza
    # Per-functional helpers. Resolve every helper now that the module
    # and all its $includes have finished loading, so each name in a
    # helper body binds to its final (possibly overridden) definition.
    # Screen-dens mode is on so helper-internal screens (e.g. b88_zab's
    # per-channel screen) bake the _screen_dens marker into their bodies;
    # _emit_* resolves it to the raw channel density after assembly.
    with _screen_dens_context():
        for obj in list(vars(mod).values()):
            if getattr(obj, "_is_helper_proxy", False):
                obj._resolve()
    # Collect the resolved helpers from the module namespace, in order.
    # A REPLACE rule that injects `params->` or `params,` into the
    # generated C body needs a `params` declaration in scope wherever it
    # fires -- including inside helpers (e.g. gga_x_fd_lb94's fd_int0
    # rewrite). Detect this once per module and treat every helper as
    # if it needed params.
    replace_uses_params = any(
        re.search(r"params\s*->|params\s*,", repl)
        for _, repl in getattr(mod, "REPLACE", []))

    per_functional_helpers = []
    for name, obj in list(vars(mod).items()):
        if not getattr(obj, "_is_helper_proxy", False):
            continue
        h = obj._helper
        if h is None:                  # resolved to an inlined fallback
            continue
        # A helper that references a params_a_* symbol (scalar or an array element
        # like params_a_c_x[3]) needs the `params` declaration emitted. Detect it
        # uniformly from the body -- the per-split _needs_params flag only covers
        # the exchange/rest split helpers, not plain @helpers (e.g. b97mv_fx).
        needs_params = (getattr(h, "_needs_params", False) or replace_uses_params
                        or _expr_uses_params(h.expr))
        if needs_params and params_struct:
            h.params_struct = params_struct
        # A params-injecting REPLACE rule rewrites the rendered body after
        # emission, so the body alone can't reveal the use; flag it so the
        # helper prologue is emitted conservatively.
        h._replace_params = replace_uses_params
        # The source-level numerical-stability rewrites run inside
        # Helper.__init__ (helper_mod.SOURCE_CLEAN), BEFORE the derivative
        # table is built. Rebinding h.expr here -- as this code once did --
        # was a no-op for emission: __init__ had already differentiated the
        # raw body into _derivs, and emission reads _derivs.
        per_functional_helpers.append(h)

    printer = _ParamPrefixPrinter()

    # Highest derivative order each helper must be emitted to (a helper
    # nested inside another can be needed beyond the generation order).
    # Built over every collected helper, and also populates each
    # helper's derivative table -- which the reachability scan needs.
    # One map per top-level order lets the helper emitter guard each
    # statement by the lowest order that needs it; the full-order map
    # (built last, so the derivative tables end up fully populated) keeps
    # slot numbering unchanged.
    helper_pool = _LIBRARY_HELPERS + per_functional_helpers
    guard_kmaps = {order: _helper_order_map(helper_pool, order)
                   for order in range(max_order + 1)}
    kmap = guard_kmaps[max_order]
    global _GUARD_KMAPS
    _GUARD_KMAPS = guard_kmaps

    # Drop helpers unreachable from f: dead code pulled in by include(), or an
    # eagerly-built library helper the functional never calls (e.g. lda_x_spin in
    # a range-separated functional that only uses lda_x_erf_spin). One
    # reachability pass over the whole pool so chains *through* library helpers
    # are followed. Library helpers keep their build order (already
    # callee-before-caller); per-functional ones are toposorted. kmap is left
    # over the full set, so it still resolves any helper.
    reachable = set(_reachable_helpers(mod.f, helper_pool))
    # Screen-reaching helpers are force-inlined into the kernel (so the screen
    # resolves against na/nb); they must not also be emitted standalone, where
    # the unresolved _screen_dens marker would be undefined C. They stay in
    # helper_pool/kmap above so the inliner can still pull their derivative slots.
    emit_ok = lambda h: not _helper_reaches_screen(h)
    library_helpers = [h for h in _LIBRARY_HELPERS
                       if h in reachable and emit_ok(h)]
    per_functional_helpers = _toposort_helpers(
        [h for h in per_functional_helpers if h in reachable and emit_ok(h)])

    if type_str not in _FAMILY_DISPATCH:
        raise NotImplementedError(f"Unsupported TYPE: {type_str}")
    _reset_specialized()
    # Mode stays on through assembly so top-level screen_dens calls (e.g. op_f's
    # screen) also emit the marker; _emit_* resolves them per spinmode.
    with _screen_dens_context():
        bodies = _FAMILY_DISPATCH[type_str](mod.f, max_order, params_struct,
                                            printer, kmap, split, dim=dim)
    # z=const helpers synthesized for the unpol kernels (registered in kmap as
    # they were created). Register them in each per-order guard map too -- each
    # is a leaf needed up to the top-level order -- so they can be emitted.
    for spec in _SPECIALIZED_ORDER:
        kmap.setdefault(id(spec), max_order)
        for order in guard_kmaps:
            guard_kmaps[order].setdefault(id(spec), order)

    family = type_str          # the python/<family>/ dir matches TYPE
    name = mod.__name__.split(".")[-1]

    import sympy as _sympy
    _pyver = ".".join(map(str, sys.version_info[:3]))
    out = []
    out.append("/*")
    out.append(f"  Generated from python/{family}/{name}.py via")
    out.append(f"  python/libxc_codegen.py with Python {_pyver}, "
               f"SymPy {_sympy.__version__}.")
    out.append(f"  Do not edit -- regenerate via")
    out.append(f"  scripts/sympy2c/compile.py {name}")
    out.append("*/")
    out.append("")
    # MAPLE2C_FLAGS must advertise exactly the derivative orders that
    # were generated: the general test suite requests an order only if
    # the functional's info flags claim it, and a claimed-but-NULL
    # kernel would be called. A *_vxc functional defines the potential
    # directly -- it has no energy (EXC) output, and the potential is
    # already a first-order quantity -- so its orders run VXC..,
    # otherwise EXC...
    if type_str.endswith("_vxc"):
        mc_order = min(max(max_order, 1), 4)
        orders = ORDER_NAMES[1:mc_order + 1]
    else:
        mc_order = max_order
        orders = ORDER_NAMES[:mc_order + 1]
    have_flags = " | ".join(f"XC_FLAGS_I_HAVE_{o}" for o in orders)
    _graded = isinstance(bodies, _Graded)
    _body_guard = f"_{name.upper()}_KERNEL_BODY"
    if _graded:
        # First pass defines the flags + helpers; re-inclusions (the stanza
        # below) take the #else branch to expand the single graded body.
        out.append(f"#ifndef {_body_guard}")
    out.append(f"#define maple2c_order {mc_order}")
    out.append(f"#define MAPLE2C_FLAGS ({have_flags})")
    out.append("")
    # Final uniform pass: any emitted helper whose body references params_a_*
    # needs the `params` declaration. Covers helpers synthesized outside the
    # per-functional collection (split _rest, z=const specializations, xchan).
    if params_struct:
        for h in library_helpers + per_functional_helpers + _SPECIALIZED_ORDER:
            if not getattr(h, "params_struct", None) and _expr_uses_params(h.expr):
                h.params_struct = params_struct
    # Emit every candidate helper, then keep only those reachable from the kernel
    # dispatch by a call-graph pass over the generated C. The pre-emission
    # reachability (over mod.f) predates the channel fold, which can replace a
    # squared-only wrapper with its p-form variant and leave the original
    # uncalled; this drops that dead code. Emission order (callee before caller)
    # is preserved, so the surviving subset stays declaration-correct.
    _kernel_text = ("\n".join(bodies) if not _graded
                    else bodies.stanza + "\n" + bodies.template)
    _emitted = [_emit_helper_c(h, printer, kmap, guard_kmaps)
                for h in (library_helpers + per_functional_helpers
                          + list(_SPECIALIZED_ORDER))]
    _name_re = re.compile(r"\bvoid\s+(?:XC_CAT\(\s*)?([A-Za-z_]\w*?)_k\s*,"
                          r"\s*_KMAX\s*\)\s*\(")
    _named = []
    for _ct in _emitted:
        _m = _name_re.search(_ct)
        _named.append((_m.group(1) if _m else None, _ct))
    _by_name = {nm: ct for nm, ct in _named if nm}

    def _calls(text, nm):
        # call sites read XC_CAT(<nm>_k, _KMAX)(...)
        return re.search(r"\b" + re.escape(nm) + r"_k\s*,\s*_KMAX\s*\)",
                         text) is not None

    _reach = set()
    _frontier = [nm for nm in _by_name if _calls(_kernel_text, nm)]
    while _frontier:
        nm = _frontier.pop()
        if nm in _reach:
            continue
        _reach.add(nm)
        _frontier += [o for o in _by_name
                      if o not in _reach and _calls(_by_name[nm], o)]
    _live_helpers = [ct for nm, ct in _named if nm is None or nm in _reach]
    if not _graded:
        out += _live_helpers
        out.append("/* ---- top-level dispatch ---- */")
        out.append("")
        out.extend(bodies)
    else:
        # Helpers are order-graded like the kernel: one body in the file,
        # re-included once per order. Each variant computes and stores only
        # the slots that order needs, so an exc-only call neither evaluates
        # nor reserves space for higher-order derivatives.
        _helper_guard = f"_{name.upper()}_HELPER_BODIES"
        out.append("/* ---- top-level dispatch ---- */")
        out.append("")
        out.append(f"#define {_body_guard}")
        out.append(_helper_stanza(_GEN_NAME, _helper_guard, mc_order,
                                  min_order=1 if type_str.endswith("_vxc")
                                  else 0))
        out.append(bodies.stanza)
        out.append(f"#elif defined({_helper_guard})")
        out.append("")
        out.append("/* ---- helpers (one graded body -> <name>_k<order>) ---- */")
        out.append("")
        out += _live_helpers
        out.append("#else  /* re-inclusion: one graded body -> func_<order>_<spin> */")
        out.append(bodies.template)
        out.append("#endif")

    c_text = "\n".join(out)

    # `replace:` headers are post-process text substitutions on the
    # generated C (mirroring maple2c). They rename a function to its
    # libxc C name -- which may also inject fixed leading arguments,
    # e.g. fd_int0( -> xc_integrate(func0, &(params->beta), 0.0, .
    for pattern, replacement in getattr(mod, "REPLACE", []):
        c_text = re.sub(pattern, replacement, c_text)

    with open(output_path, "w") as fh:
        fh.write(c_text)


__all__ = [
    "my_piecewise3", "my_piecewise5",
    "X2S", "XT2S", "X2S_2D", "X_FACTOR_C", "X_FACTOR_2D_C",
    "LDA_X_FACTOR", "K_FACTOR_C", "M_C",
    "RS_FACTOR", "DIMENSIONS", "pi", "XC_EPSILON", "XC_MIN",
    "MU_GE", "MU_PBE", "KAPPA_PBE",
    "p_a_zeta_threshold", "p_a_dens_threshold",
    "r_ws", "n_total", "n_spin", "sigma_spin", "screen_dens",
    "screen_dens_zeta",
    "z_thr", "lda_x_spin", "lda_k_spin", "lda_exchange", "opz_pow_n",
    "m_min", "m_max", "m_abs", "m_recexp",
    "t_total", "u_total", "t_vw",
    "f_zeta", "f_zeta_2d", "mphi", "tt", "beta_Hu_Langreth",
    "gga_exchange", "gga_exchange_nsp", "gga_kinetic",
    "gga_exchange_p", "gga_exchange_nsp_p", "gga_kinetic_p",
    "mgga_exchange", "mgga_exchange_nsp", "mgga_kinetic",
    "mgga_exchange_p", "mgga_kinetic_p",
    "lda_stoll_par", "lda_stoll_perp", "gga_stoll_par",
    "Fermi_D", "Fermi_D_corrected",
    "b88_R_F", "b88_zss", "b88_zab",
    "b94_R_F", "b94_zss", "b94_zab",
    "mgga_w", "mgga_series_w", "kF", "nu", "p_a_cam_omega",
    "p_a_cam_alpha", "p_a_cam_beta", "params",
    "param_array", "param_default", "maple_list",
    "infinity", "Symbol", "Function", "polynom", "csgn",
    "xc_E1_scaled", "xc_erfcx", "BesselI", "BesselK", "zeta", "evalf",
    "Eq", "Ne", "And", "Or", "Not",
    "Integer", "Float", "Rational",
    "maple_taylor", "maple_series", "convert", "diff", "maple_eval",
    "enforce_smooth_lr",
    "exp", "log", "sqrt", "sin", "cos", "tan", "atan",
    "sinh", "cosh", "tanh", "asinh", "acosh", "atanh", "atan2", "erf", "erfc", "LambertW", "legendre",
    "chebyshevt", "chebyshevu", "simplify",
    "sech", "csch", "coth", "acsch", "asech", "acoth",
    "helper", "param", "include", "define", "undef", "defined",
    "compile_module",
]


# ===========================================================================
# Shared util.mpl helpers/wrappers added by the maple-stability cleanup,
# lifted from the mpl2py translation (util.py).  Functionals import
# libxc_codegen, so these live here beside gga_exchange/lda_x_spin/etc.
# Additions only.
# ===========================================================================

params_a_Fermi_D_cnst = param_default("Fermi_D_cnst")


my_dilog = Function("my_dilog")   # inert dilog wrapper (to_elementary -> polylog)


class xc_expm1(Function):
    # Evaluate at EXACT zero only: expm1(0) = 0 lets a build-time constant
    # (e.g. f_zeta(0) on the unpolarized path) keep propagating, which the
    # dead-branch pruning and the f_pw-style zeta0 specialization depend on.
    # Any other constant stays symbolic so the C still calls xc_expm1.
    @classmethod
    def eval(cls, y):
        if y is sp.S.Zero:
            return sp.S.Zero

    def fdiff(self, argindex=1):
        y, = self.args
        if argindex == 1:
            return (xc_expm1(y) + Integer(1)) * Integer(1)
        return 0


class xc_log1p(Function):
    @classmethod
    def eval(cls, y):
        if y is sp.S.Zero:
            return sp.S.Zero

    def fdiff(self, argindex=1):
        y, = self.args
        if argindex == 1:
            return Integer(1) / (Integer(1) + y)
        return 0


class xc_asinh(Function):
    def fdiff(self, argindex=1):
        y, = self.args
        if argindex == 1:
            return Integer(1) / sqrt(Integer(1) + y**Integer(2))
        return 0


class xc_atanh(Function):
    def fdiff(self, argindex=1):
        y, = self.args
        if argindex == 1:
            return Integer(1) / ((Integer(1) + y) * (Integer(1) - y))
        return 0


class xc_x_minus_log1p(Function):
    def fdiff(self, argindex=1):
        y, = self.args
        if argindex == 1:
            return y / (Integer(1) + y) * Integer(1)
        return 0


@helper
def m_one_minus_recexp(x):
    return my_piecewise3(x <= -Integer(1)/log(XC_EPSILON), Integer(1), -xc_expm1(-Integer(1)/m_max(-Integer(1)/log(XC_EPSILON),x)))


def to_elementary(expr):
    return maple_eval(expr, xc_expm1, (lambda q: exp(q) - Integer(1)), xc_log1p, (lambda q: log(Integer(1) + q)), xc_asinh, (lambda q: asinh(q)), xc_atanh, (lambda q: atanh(q)), xc_x_minus_log1p, (lambda q: q - log(Integer(1) + q)), my_dilog, (lambda q: polylog(Integer(2), q)), m_recexp, (lambda q: exp(-Integer(1)/q)), m_one_minus_recexp, (lambda q: Integer(1) - exp(-Integer(1)/q)), xc_erfcx, (lambda q: exp(q**Integer(2))*erfc(q)), xc_E1_scaled, (lambda q: exp(q)*expint(Integer(1), q)))


@helper
def opz_pow_n_m1(z, n):
    return my_piecewise3(Integer(1) + z <= p_a_zeta_threshold, (p_a_zeta_threshold)**n - Integer(1), xc_expm1(n*xc_log1p(m_max(z, p_a_zeta_threshold - Integer(1)))))


@helper
def f_zeta(z):
    # Written as the sum of two (1 +- z)^(4/3) - 1 contributions, mirroring
    # util.mpl: at small z the direct opz_pow_n(...) + opz_pow_n(...) - 2
    # form cancels against the `- 2` (both powers are 1 + O(z)), losing
    # every significant digit of the ~z^2 result.
    #
    # Structure matters as much as the math here:
    # * a @helper: the exp(log1p) chain inlined at every call site made
    #   4th-order generation of every PW92 dependent ~10x slower -- the
    #   opaque call is differentiated once into four small slots;
    # * the m1 piecewise INLINED at the fixed exponent (not a call to the
    #   2-arg opz_pow_n_m1 helper), so that (a) the unpolarized path's
    #   f_zeta(0) folds to an exact build-time 0 in ONE specialization
    #   step -- the dead-branch pruning and the f_pw-style zeta0
    #   specialization depend on that constant -- and (b) the emitted C
    #   helper carries no runtime exponent argument, mirroring the old
    #   opz_pow_n_4_3.
    # KEEP IN SYNC: f_zeta and one_minus_f_zeta.
    n = Integer(4) / Integer(3)

    def m1(y):
        return my_piecewise3(
            Integer(1) + y <= p_a_zeta_threshold,
            p_a_zeta_threshold ** n - Integer(1),
            xc_expm1(n * xc_log1p(m_max(y, p_a_zeta_threshold - Integer(1)))))

    return (m1(z) + m1(-z)) / (Integer(2) ** n - 2)


@helper
def one_minus_f_zeta(z):
    return (
        -Integer(2)**(Integer(4)/Integer(3))
        * (Integer(1) + opz_pow_n_m1((z-Integer(1))/Integer(2), Integer(4)/Integer(3)) + opz_pow_n_m1((-z-Integer(1))/Integer(2), Integer(4)/Integer(3)))
        /(Integer(2)**(Integer(4)/Integer(3)) - Integer(2))
    )


@helper
def f_zeta_2d_m1(z):
    return (opz_pow_n_m1(z,Integer(3)/Integer(2)) + opz_pow_n_m1(-z,Integer(3)/Integer(2)))/Integer(2)


@helper
def mphi_m1(z):
    return (opz_pow_n_m1(z,Integer(2)/Integer(3)) + opz_pow_n_m1(-z,Integer(2)/Integer(3)))/Integer(2)


@helper
def gga_exchange_erf(func, rs, z, xs0, xs1):
    return (
        + my_piecewise3(screen_dens(rs,  z), Integer(0), lda_x_erf_spin(rs, z_thr( z))*func(xs0))
        + my_piecewise3(screen_dens(rs, -z), Integer(0), lda_x_erf_spin(rs, z_thr(-z))*func(xs1))
    )


@helper
def mgga_exchange_erf(func, rs, z, xs0, xs1, u0, u1, t0, t1):
    return (
        + my_piecewise3(screen_dens(rs,  z), Integer(0), lda_x_erf_spin(rs, z_thr( z))*func(xs0, u0, t0))
        + my_piecewise3(screen_dens(rs, -z), Integer(0), lda_x_erf_spin(rs, z_thr(-z))*func(xs1, u1, t1))
    )


# ---------------------------------------------------------------------------
# Spin-scaled exchange/kinetic split (the exchange part of any functional is
# spin-scalable even when the rest is not). The separable wrappers below obey
# exact spin scaling -- func sees only per-channel reduced quantities -- so
# their contribution is evaluated per spin channel from its own same-spin
# density (well-conditioned; cross-spin derivatives structurally zero). The
# non-separable *_nsp wrappers (func also gets rs, z) are deliberately excluded.
#
# A module flag toggles these wrappers off, letting the emitter split any f as
#   f_rest = f|wrappers->0   (evaluated on the (rs, zeta) path)
#   f_x    = f - f_rest      (evaluated per channel, spin-scaled).
# ---------------------------------------------------------------------------
# Only the high-level separable wrappers trigger the split: func receives only
# per-channel reduced quantities, so the contribution is genuinely separable.
# lda_x_spin / lda_k_spin are low-level building blocks -- a functional may
# multiply them by a NON-separable factor (e.g. mgga_x_mscan scales them by an
# enhancement of the total reduced gradient xt), so they must NOT trigger spin
# scaling; the separable LDA case uses lda_exchange.
_SEPARABLE_WRAPPERS = (
    "lda_exchange",
    "gga_exchange", "gga_kinetic", "gga_exchange_erf",
    "gga_exchange_p", "gga_exchange_nsp_p", "gga_kinetic_p",
    "mgga_exchange", "mgga_kinetic", "mgga_exchange_erf",
    "mgga_exchange_p", "mgga_kinetic_p",
)
_EMIT_EXCHANGE = True
# Set True (per compile) the first time a separable wrapper actually runs with
# exchange live. If it stays False the functional has no spin-scalable exchange,
# so the exchange-off (f_rest) pass is identical to the on pass and the off
# helpers can be reused without the costly per-helper re-eval + structural
# compare -- see the _resolve_flag short-circuit.
_MODULE_HAS_EXCHANGE = False

# Highest derivative order the current module is being generated to. A helper's
# derivative table is eagerly built to this order at construction; the
# _helper_order_map fixpoint then tops up (incrementally) any helper that a
# nesting chain needs beyond it. Hardcoding order 4 here forced every helper to
# be differentiated four orders deep even for an order-1 (exc+vxc) build -- the
# dominant cost for helper-heavy correlation functionals. Set per module in
# _compile_module_inner.
_GEN_MAX_ORDER = 4


def _make_splittable(fn):
    def wrapper(*args, **kwargs):
        if not _EMIT_EXCHANGE:
            return sp.S.Zero
        global _MODULE_HAS_EXCHANGE
        _MODULE_HAS_EXCHANGE = True
        return fn(*args, **kwargs)
    wrapper.__name__ = getattr(fn, "__name__", "wrapper")
    return wrapper


for _w in _SEPARABLE_WRAPPERS:
    globals()[_w] = _make_splittable(globals()[_w])


def _generic_point(syms):
    """A numeric value for each symbol so an algebraic identity can be tested
    numerically. Densities na/nb are fixed to a polarized point; cube-root macros
    (M_CBRT2/3/...) take their real value; everything else gets a distinct,
    positive, generic value (avoiding 0 / coincidences that could hide a
    difference)."""
    pt = {}
    for s in syms:
        name = getattr(s, "name", "")
        if name == "na":
            pt[s] = sp.Float("0.7")
        elif name == "nb":
            pt[s] = sp.Float("0.3")
        elif name == "dens_threshold":
            pt[s] = sp.Float("1e-8")
        elif name == "zeta_threshold":
            pt[s] = sp.Float("1e-12")
        else:
            m = re.fullmatch(r"M_CBRT(\d+)", name)
            if m:
                pt[s] = sp.Integer(int(m.group(1))) ** sp.Rational(1, 3)
            else:
                pt[s] = sp.Float(0.137 + (abs(hash(name)) % 89) * 0.011)
    return pt


def _split_exact(direct, split):
    """True if the spin-scaled `split` energy density reproduces the `direct`
    functional. For a separable exchange this is an algebraic identity, so it
    holds at a generic numeric point; when the exchange carries a non-spin-scalable
    factor (lda_x_rel's phi(rs), cc06's laplacian factor) the split evaluates that
    factor at the per-channel density instead of the total and the two differ.
    On any evaluation failure, assume valid (don't disable a working split)."""
    # Cheap structural short-circuit: when there is no separable exchange (pure
    # correlation) f_x is 0, so direct and split are the same expression and their
    # difference cancels symbolically. Return before the expensive _deep_inline,
    # which would otherwise expand the whole (e.g. PBE-correlation) functional.
    if (direct - split) == 0:
        return True
    sd = _screen_dens_marker
    # The channel density behind a _screen_dens(zform) marker is proportional to
    # 1 + zform (zero exactly at the empty channel), and the marker dropped its rs.
    # Map it to 1 + zform so the screen still fires only for an empty channel
    # (e.g. the minority of a fully-polarized single-channel evaluation) -- which
    # is load-bearing for the spin-scaling identity of a plain exchange.
    drop_screen = lambda e: e.replace(
        lambda x: getattr(x, "is_Function", False) and x.func is sd,
        lambda x: 1 + x.args[0])
    try:
        d = to_elementary(drop_screen(_deep_inline(direct)))
        s = to_elementary(drop_screen(_deep_inline(split)))
        pt = _generic_point((d - s).free_symbols)
        dv = complex(sp.N(d.subs(pt)))
        sv = complex(sp.N(s.subs(pt)))
    except (TypeError, ValueError, AttributeError, ZeroDivisionError):
        return True
    if not all(math.isfinite(x) for x in (dv.real, dv.imag, sv.real, sv.imag)):
        return True
    return abs(dv - sv) <= 1e-7 * (abs(dv) + 1.0)


def _split_xc(f_func):
    """Split f into (f_rest_func, f_x_func): the non-spin-scalable remainder
    (separable exchange/kinetic wrappers off) and the spin-scalable
    exchange/kinetic part (the difference)."""
    def f_rest_func(*args):
        global _EMIT_EXCHANGE
        _EMIT_EXCHANGE = False
        try:
            return f_func(*args)
        finally:
            _EMIT_EXCHANGE = True

    def f_x_func(*args):
        return f_func(*args) - f_rest_func(*args)

    return f_rest_func, f_x_func


# These reduced-gradient / reduced-Laplacian variables are just a constant
# times the input (s = X2S*x, p = s**2, q = X2S**2*u), so they are inlined
# rather than emitted as opaque C helpers. Emitting them as helpers hid the
# structure from the differentiator: e.g. mgga_p(xs) with xs = sqrt(gaa)/... was
# differentiated through its argument and reintroduced sqrt(gaa) (and the
# 1/gaa**(k/2) tail cancellation) even though (X2S*xs)**2 = X2S**2*gaa/na**(8/3)
# is rational in gaa. Inlining folds the sqrt at the expression level, which is
# what makes the *_p reduced-gradient helpers cancellation-free.
def gga_s(x):
    return X2S*x


def gga_s_total(xt):
    return XT2S*xt


def mgga_p(x):
    return gga_s(x)**Integer(2)


def mgga_q(u):
    return X2S**Integer(2)*u


xc_reduced_floor = XC_EPSILON**(Integer(2)/Integer(3))


@helper
def mgga_alpha(x, t):
    return (t - x**Integer(2)/Integer(8))/K_FACTOR_C


@helper
def mgga_alpha_reg(x, t, eta):
    return (t - x**Integer(2)/Integer(8))/(K_FACTOR_C + eta*x**Integer(2)/Integer(8))


# Deorbitalized counterparts. A kinetic energy functional written as an
# enhancement over the von Weizsaecker limit, tau_ked = tau_W + tau_unif*a,
# yields the iso-orbital indicator directly as `a`: K_FACTOR_C*f_W(x) is
# identically x^2/8, so the tau_W that mgga_alpha subtracts is exactly the one
# the KED added, and the two cancel analytically. Passing `a` avoids forming
# tau and subtracting tau_W back off it -- a cancellation costing
# ~log10(tau/alpha) digits, unbounded in the tail where tau -> tau_W.
# mgga_alpha_deorb is the identity, and exists so the substitution is stated
# rather than implied.
def mgga_alpha_deorb(a):
    return a


@helper
def mgga_alpha_deorb_reg(x, a, eta):
    return K_FACTOR_C*a/(K_FACTOR_C + eta*x**Integer(2)/Integer(8))


# The correlation counterpart. mgga_alpha_total measures the *total* tau
# against the von Weizsaecker term of the *total* density, so a per-spin KED
# leaves a residue: t_total is linear in its last two arguments, and
# K_FACTOR_C*f_W(xs) = xs^2/8, hence
#
#   t_total(z, ts0, ts1) - xt^2/8
#      = [t_total(z, xs0^2, xs1^2) - xt^2]/8 + K_FACTOR_C*t_total(z, a0, a1).
#
# The first bracket is sum_s |grad rho_s|^2/rho_s - |grad rho|^2/rho =
# |rho_1 grad rho_0 - rho_0 grad rho_1|^2/(rho_0 rho_1 rho) >= 0, and vanishes
# identically when the spin densities are proportional. The dominant
# tau-against-tau_W cancellation is gone.
@helper
def mgga_alpha_total_deorb(z, xt, xs0, xs1, a0, a1):
    return ((t_total(z, xs0**Integer(2), xs1**Integer(2)) - xt**Integer(2))/Integer(8)
            + K_FACTOR_C*t_total(z, a0, a1)) / (K_FACTOR_C*t_total(z, Integer(1), Integer(1)))


@helper
def mgga_alpha_total_deorb_reg(z, xt, xs0, xs1, a0, a1, eta):
    # ... and with the regularized denominator (the r2SCAN family).
    return ((t_total(z, xs0**Integer(2), xs1**Integer(2)) - xt**Integer(2))/Integer(8)
            + K_FACTOR_C*t_total(z, a0, a1)) / (K_FACTOR_C*t_total(z, Integer(1), Integer(1))
            + eta*xt**Integer(2)/Integer(8))


@helper
def mgga_alpha_safe(x, t):
    # (8t - x^2)/(8t) is the cancellation-free form of 1 - x^2/(8t): at the
    # iso-orbital limit (x^2 -> 8t) the subtraction 8t - x^2 is Sterbenz-exact,
    # whereas 1 - x^2/(8t) rounds x^2/(8t) to ~1 and loses the small residual.
    return (t/K_FACTOR_C)*m_max((Integer(8)*t - x**Integer(2))/(Integer(8)*t), xc_reduced_floor)


@helper
def mgga_alpha_total(z, xt, ts0, ts1):
    return (t_total(z, ts0, ts1) - xt**Integer(2)/Integer(8))/(K_FACTOR_C*t_total(z, Integer(1), Integer(1)))


@helper
def mgga_alpha_total_reg(z, xt, ts0, ts1, eta):
    return (t_total(z, ts0, ts1) - xt**Integer(2)/Integer(8))/(K_FACTOR_C*t_total(z, Integer(1), Integer(1)) + eta*xt**Integer(2)/Integer(8))


@helper
def b97_u(mgamma, x2):
    return mgamma*x2/(Integer(1) + mgamma*x2)


__all__ += [
    "b97_u", "f_zeta_2d_m1", "gga_exchange_erf", "gga_s", "gga_s_total", "m_one_minus_recexp", "mgga_alpha", "mgga_alpha_deorb", "mgga_alpha_deorb_reg", "mgga_alpha_total_deorb", "mgga_alpha_total_deorb_reg", "mgga_alpha_reg", "mgga_alpha_safe", "mgga_alpha_total", "mgga_alpha_total_reg", "mgga_exchange_erf", "mgga_p", "mgga_q", "mphi_m1", "my_dilog", "one_minus_f_zeta", "opz_pow_n_m1", "params_a_Fermi_D_cnst", "to_elementary", "xc_asinh", "xc_atanh", "xc_expm1", "xc_log1p", "xc_reduced_floor", "xc_x_minus_log1p", "one_minus_z_pow_n",
]


def coeff(expr, var, n):
    """Maple coeff(expr, var, n): the coefficient of var**n in expr."""
    return expr.coeff(var, n)


def expand(expr):
    """Maple expand(): distribute products and powers."""
    return sp.expand(expr)


__all__ += ["coeff", "expand"]


# ===========================================================================
# erf-attenuation chain + lda_x_erf_spin, shared so the lifted gga/mgga_
# exchange_erf helpers (range-separated exchange) resolve them.  Lifted from
# attenuation.py and lda_x_erf.py.
# ===========================================================================

@helper
def att_erf_aux1(a):
    return sqrt(pi)*erf(Integer(1)/(Integer(2)*a))


@helper
def att_erf_aux2(a):
    return xc_expm1(-Integer(1)/(Integer(4)*a**Integer(2)))


@helper
def att_erf_aux3(a):
    return Integer(2)*a**Integer(2)*att_erf_aux2(a) + Integer(1)/Integer(2)


@helper
def attenuation_erf0(a):
    return Integer(1) - Integer(8)/Integer(3)*a*(att_erf_aux1(a) + Integer(2)*a*(att_erf_aux2(a) - att_erf_aux3(a)))


@helper
def attenuation_erf(a):
    return enforce_smooth_lr(attenuation_erf0, a, Float('1.35'), Integer(16))


@helper
def one_minus_attenuation_erf0(a):
    return Integer(8)/Integer(3)*a*(att_erf_aux1(a) + Integer(2)*a*(att_erf_aux2(a) - att_erf_aux3(a)))


@helper
def one_minus_attenuation_erf(a):
    return enforce_smooth_lr(one_minus_attenuation_erf0, a, Float('1.35'), Integer(16))


a_cnst = (Integer(4)/(Integer(9)*pi))**(Integer(1)/Integer(3))*p_a_cam_omega/Integer(2)


lda_x_ax = -RS_FACTOR*X_FACTOR_C/Integer(2)**(Integer(4)/Integer(3))


@helper
def lda_x_erf_spin(rs, z):
    return lda_x_ax*opz_pow_n(z,Integer(4)/Integer(3))/rs * attenuation_erf(a_cnst*rs/opz_pow_n(z,Integer(1)/Integer(3)))


__all__ += ["att_erf_aux1", "att_erf_aux2", "att_erf_aux3", "attenuation_erf0", "attenuation_erf", "one_minus_attenuation_erf0", "one_minus_attenuation_erf", "a_cnst", "lda_x_ax", "lda_x_erf_spin"]
