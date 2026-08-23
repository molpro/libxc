#!/usr/bin/env python3
"""
Helper machinery for the SymPy code generator.

A `Helper` wraps one Maple-level identifier (e.g. ``opz_pow_n_4_3``)
together with its arguments, defining expression, and all derivatives up
to maple2c order. It also acts as a SymPy Function, so it can appear
unexpanded inside larger expressions and `sympy.diff` chains through its
derivatives automatically.

`HelperCPrinter` is the C printer that recognises helper-function calls.

(Both classes used to live in the prototype file lda_x_v2.py; they were
extracted here when that prototype was retired.)
"""

import os
import sys
from itertools import combinations_with_replacement

import sympy as sp

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from sympy2c import LibxcCPrinter  # noqa: E402


# Applied to every helper body before the derivative table is built (set by
# libxc_codegen to its source-level numerical-stability cleaner). It must run
# HERE, not after construction: __init__ eagerly differentiates the body into
# _derivs, and emission reads _derivs -- so a later rebind of .expr leaves the
# cached raw-body derivatives in place, silently bypassing the stability
# rewrites inside every emitted helper.
SOURCE_CLEAN = None


class Helper:
    """A Maple-level definition that gets emitted as inline C functions.

    Each instance represents one symbolic identifier (e.g. ``opz_pow_n_4_3``).
    """

    def __init__(self, name, args, expr, max_order=4):
        if SOURCE_CLEAN is not None:
            expr = SOURCE_CLEAN(expr)
        self.name = name
        self.args = list(args)
        self.expr = expr
        self.max_order = max_order
        self._sym_func = self._make_sym_func()
        self._derivs = {(0,) * len(self.args): expr}
        self._computed_order = 0
        self.ensure_order(max_order)

    # -- symbolic call construction --------------------------------------

    def _make_sym_func(helper_self):
        """Build a sympy Function subclass whose derivatives dispatch to
        the correct multi-index helper."""

        nargs = len(helper_self.args)

        class _F(sp.Function):
            nargs_ = nargs
            helper = helper_self
            multiindex = (0,) * nargs

            def fdiff(self, argindex):
                mi = list(self.multiindex)
                mi[argindex - 1] += 1
                return self.helper._call_with_index(tuple(mi), self.args)

        _F.__name__ = helper_self.name
        return _F

    def call(self, *concrete_args):
        """Return a sympy expression for a call to the value function."""
        return self._sym_func(*concrete_args)

    def _call_with_index(self, mi, concrete_args):
        cls = self._make_indexed_func(mi)
        return cls(*concrete_args)

    def _make_indexed_func(helper_self, mi):
        """Construct (cached) a sympy Function class for a particular
        multi-index derivative of this helper."""
        cache = helper_self.__dict__.setdefault("_indexed_classes", {})
        if mi in cache:
            return cache[mi]

        nargs = len(helper_self.args)
        suffix = "".join(str(k) for k in mi)
        full_name = f"{helper_self.name}_d{suffix}"

        class _F(sp.Function):
            nargs_ = nargs
            helper = helper_self
            multiindex = mi
            cname = full_name

            def fdiff(self, argindex):
                mi2 = list(self.multiindex)
                mi2[argindex - 1] += 1
                return self.helper._call_with_index(tuple(mi2), self.args)

        _F.__name__ = full_name
        cache[mi] = _F
        return _F

    # -- derivative computation ------------------------------------------

    def ensure_order(self, order):
        """Make sure _derivs holds every partial derivative up to total
        `order`. Computed incrementally -- a helper nested inside another
        can be needed beyond the generation order, so the depth is not
        known until the dependency fixpoint has run."""
        for o in range(self._computed_order + 1, order + 1):
            for idx in combinations_with_replacement(
                    range(len(self.args)), o):
                mi = [0] * len(self.args)
                for i in idx:
                    mi[i] += 1
                mi = tuple(mi)
                if mi in self._derivs:
                    continue
                e = self.expr
                for i in idx:
                    e = sp.diff(e, self.args[i])
                self._derivs[mi] = e
        self._computed_order = max(self._computed_order, order)


class HelperCPrinter(LibxcCPrinter):
    """C printer that recognises helper-function calls."""

    def _print_Function(self, expr):
        cls = expr.func
        if hasattr(cls, "helper"):
            # Helper or indexed-derivative call. All helpers carry `p` first.
            cname = getattr(cls, "cname", cls.helper.name)
            args = ", ".join(["p"] + [self._print(a) for a in expr.args])
            return f"{cname}({args})"
        if cls.__name__ in ("BesselI", "BesselK"):
            # The order argument must print as a plain 0 / 1 so the
            # functional's `replace:` headers (BesselI(0, / BesselK(1, )
            # match -- the default printer would emit Maple-style 0.1e1.
            n, y = expr.args
            return f"{cls.__name__}({int(n)}, {self._print(y)})"
        try:
            return super()._print_Function(expr)
        except Exception:
            # A custom external function -- e.g. a diff-rule function
            # such as xc_dilogarithm or xc_mgga_x_br89_get_x, backed by
            # a libxc C routine. Emit a plain C call.
            args = ", ".join(self._print(a) for a in expr.args)
            return f"{cls.__name__}({args})"
