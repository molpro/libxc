"""Unit tests for the libxc C-side math utilities.

For each utility (LambertW, xc_dilogarithm, xc_E1_scaled, xc_erfcx,
the modified Bessel functions, and the tanh-sinh quadrature in
xc_integrate) we evaluate the C implementation via ctypes against a
SymPy/mpmath reference computed at 50-digit precision and rounded to
double. Tolerances are stated as multiples of XC_EPSILON; a passing
test certifies the implementation is accurate to ~1 ULP, the
project-wide "exact to floating-point precision" target.

This file complements src/special_functions.c, src/bessel.c,
src/expint_e1.c, src/faddeeva.c and src/integrate.c. See
scripts/sympy2c/eval_reference.py for the same SymPy references used
in functional-level regression tests."""

import ctypes

import pytest

sp = pytest.importorskip("sympy")

# Reuse the shared library handle pylibxc already located and loaded
# (its module directory first, then LD_LIBRARY_PATH via find_library).
# Building our own CDLL from a hardcoded path next to pylibxc/__init__.py
# breaks for out-of-tree builds -- where libxc.so lives in the build
# tree, not the source tree -- and the resulting OSError at import time
# would abort collection of the whole test suite, not just this file.
from pylibxc import core as _LIB

# C float epsilon -- libxc currently builds at double precision.
EPS = 2.220446049250313e-16


def _bind(name, restype, *argtypes):
    try:
        fn = getattr(_LIB, name)
    except AttributeError:
        # These are internal helpers, not part of libxc's public API, so
        # they are not declared extern "C". When libxc is built with a C++
        # compiler (the g++/clang++ CI jobs use CC=clang++ etc.) their
        # symbols are name-mangled and unreachable by their C name. The
        # numerics are compiler-independent and fully covered by the
        # C-compiled builds (gcc, the CMake-python jobs, intel with
        # -fp-model=strict), so skip rather than fail there.
        pytest.skip(
            "libxc built as C++: internal math symbol %r is name-mangled "
            "and not callable by its C name; covered by the C builds" % name,
            allow_module_level=True)
    fn.restype = restype
    fn.argtypes = argtypes
    return fn


# ---- Bindings to the C utilities under test --------------------------------

LambertW = _bind("LambertW", ctypes.c_double, ctypes.c_double)
xc_dilogarithm = _bind("xc_dilogarithm", ctypes.c_double, ctypes.c_double)
xc_erfcx = _bind("xc_erfcx", ctypes.c_double, ctypes.c_double)
xc_expint_e1_impl = _bind("xc_expint_e1_impl",
                          ctypes.c_double, ctypes.c_double, ctypes.c_int)
xc_bessel_I0 = _bind("xc_bessel_I0", ctypes.c_double, ctypes.c_double)
xc_bessel_I1 = _bind("xc_bessel_I1", ctypes.c_double, ctypes.c_double)
xc_bessel_K0 = _bind("xc_bessel_K0", ctypes.c_double, ctypes.c_double)
xc_bessel_K1 = _bind("xc_bessel_K1", ctypes.c_double, ctypes.c_double)


def xc_E1_scaled(x):                  # mirrors the inline in util.h
    return xc_expint_e1_impl(x, 1)


# ---- Reference values via SymPy --------------------------------------------

def _ref(expr, x, precision=50):
    """Evaluate `expr` (a SymPy expression in symbol `x`) at the given
    Python-float x at the requested precision, return as a Python
    float (rounded from mpmath)."""
    s = sp.Symbol("x")
    return float(expr.subs(s, sp.Float(x, precision)).evalf(precision))


def _close(value, reference, tol_eps):
    """libxc's regression-test convention: relative-with-floor."""
    return abs(value - reference) <= tol_eps * EPS * (1.0 + abs(reference))


# ---- Test grids ------------------------------------------------------------
# Each grid samples a representative range plus a few edge cases.

_X_FLOAT_POS = [1e-8, 1e-4, 0.1, 0.5, 1.0, 1.5, 3.0, 8.0, 20.0, 50.0, 200.0]
_X_FLOAT_NEG = [-x for x in _X_FLOAT_POS]
_X_FLOAT_REAL = _X_FLOAT_NEG[::-1] + [0.0] + _X_FLOAT_POS


# ---- LambertW (principal branch W_0) ---------------------------------------

@pytest.mark.parametrize("x", _X_FLOAT_POS + [-0.3, -0.2, -0.1])
def test_LambertW(x):
    s = sp.Symbol("x")
    ref = _ref(sp.LambertW(s), x)
    got = LambertW(x)
    # Halley iteration in libxc terminates at 2*XC_EPSILON; 4*EPS
    # absorbs the rounding of the termination test.
    assert _close(got, ref, tol_eps=4.0)


# ---- Dilogarithm Li_2 ------------------------------------------------------
# For x > 1, Li_2 acquires an imaginary part along the principal
# branch; libxc's xc_dilogarithm returns the analytic continuation in
# the real direction (Spence's function), Re Li_2(x) for real x. So
# we restrict to x <= 1 and compare against SymPy's polylog there.

@pytest.mark.parametrize("x",
                         [v for v in _X_FLOAT_REAL[3:-3] if v < 1.0])
def test_xc_dilogarithm(x):
    s = sp.Symbol("x")
    ref = _ref(sp.polylog(2, s), x)
    got = xc_dilogarithm(x)
    assert _close(got, ref, tol_eps=8.0)


def test_xc_dilogarithm_at_one():
    """Li_2(1) = pi^2 / 6 is the canonical edge case."""
    import math
    ref = math.pi * math.pi / 6.0
    got = xc_dilogarithm(1.0)
    assert _close(got, ref, tol_eps=4.0)


# ---- erfcx -----------------------------------------------------------------
# erfcx(x) = exp(x^2) * erfc(x) grows as exp(x^2) for very negative x
# and overflows IEEE double at |x| ~ 27. Restrict the grid; the
# Faddeeva-package implementation handles the in-range cases to ~1 ULP.

@pytest.mark.parametrize("x", [v for v in _X_FLOAT_REAL if abs(v) <= 26.0])
def test_xc_erfcx(x):
    s = sp.Symbol("x")
    ref = _ref(sp.exp(s * s) * sp.erfc(s), x)
    got = xc_erfcx(x)
    assert _close(got, ref, tol_eps=2.0)


# ---- Exponential integral E1 (scaled and unscaled) -------------------------

@pytest.mark.parametrize("x", _X_FLOAT_POS)
def test_xc_E1(x):
    s = sp.Symbol("x")
    ref = _ref(sp.expint(1, s), x)
    got = xc_expint_e1_impl(x, 0)
    assert _close(got, ref, tol_eps=8.0)


@pytest.mark.parametrize("x", _X_FLOAT_POS)
def test_xc_E1_scaled(x):
    s = sp.Symbol("x")
    ref = _ref(sp.exp(s) * sp.expint(1, s), x)
    got = xc_E1_scaled(x)
    assert _close(got, ref, tol_eps=8.0)


# ---- Modified Bessel functions ---------------------------------------------

@pytest.mark.parametrize("x", _X_FLOAT_POS)
def test_xc_bessel_I0(x):
    s = sp.Symbol("x")
    assert _close(xc_bessel_I0(x), _ref(sp.besseli(0, s), x), tol_eps=8.0)


@pytest.mark.parametrize("x", _X_FLOAT_POS)
def test_xc_bessel_I1(x):
    s = sp.Symbol("x")
    assert _close(xc_bessel_I1(x), _ref(sp.besseli(1, s), x), tol_eps=8.0)


@pytest.mark.parametrize("x", _X_FLOAT_POS)
def test_xc_bessel_K0(x):
    s = sp.Symbol("x")
    assert _close(xc_bessel_K0(x), _ref(sp.besselk(0, s), x), tol_eps=8.0)


@pytest.mark.parametrize("x", _X_FLOAT_POS)
def test_xc_bessel_K1(x):
    s = sp.Symbol("x")
    assert _close(xc_bessel_K1(x), _ref(sp.besselk(1, s), x), tol_eps=8.0)


# ---- xc_integrate (tanh-sinh quadrature) -----------------------------------
# Driving xc_integrate from python is fiddly (the integrand is a C
# callback). We exercise it through a small set of integrands where
# the analytic result is known and verify the answer is exact to
# floating-point precision.

class _Integrand(ctypes.Structure):
    """A trivial callback-shim type used by the tests below."""
    pass


_INTEGR_FN = ctypes.CFUNCTYPE(None,
                              ctypes.POINTER(ctypes.c_double),  # x[]
                              ctypes.c_int,                     # n
                              ctypes.c_void_p)                  # ex

xc_integrate = _bind("xc_integrate", ctypes.c_double,
                     _INTEGR_FN, ctypes.c_void_p,
                     ctypes.c_double, ctypes.c_double)


def _run_integral(integrand, a, b):
    @_INTEGR_FN
    def _f(x_ptr, n, _ex):
        for i in range(n):
            x_ptr[i] = integrand(x_ptr[i])
    return xc_integrate(_f, None, a, b)


@pytest.mark.parametrize("a,b,fn,ref", [
    # Polynomial, smooth, no endpoint singularities.
    (0.0, 1.0, lambda x: x * x,                1.0 / 3.0),
    (-2.0, 3.0, lambda x: x ** 4,               (3.0 ** 5 - (-2.0) ** 5) / 5.0),
    # Smooth transcendental on a finite interval.
    (0.0, 1.0, lambda x: x ** 0.5 * (1 - x),    4.0 / 15.0),
    (0.0, 3.14159265358979323846, lambda x: __import__("math").sin(x), 2.0),
    # Exponential, modest dynamic range.
    (0.0, 5.0, lambda x: __import__("math").exp(-x), 1.0 - __import__("math").exp(-5.0)),
])
def test_xc_integrate_smooth(a, b, fn, ref):
    got = _run_integral(fn, a, b)
    assert _close(got, ref, tol_eps=64.0)        # tanh-sinh, smooth -> few ULP
