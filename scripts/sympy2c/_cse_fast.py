"""Drop-in faster ``cse`` for the code generator.

Profiling the slow correlation functionals (e.g. mgga_c_tpss, gga_c_pbe at high
derivative order) shows that ``sympy.cse`` is dominated not by the common-arg
matcher (already index-optimised upstream) but by the *canonical ordering* used
inside ``tree_cse._rebuild``: every commutative node's arguments are sorted with
``ordered()``, whose tie-break key is the node count
``sympy.core.sorting._node_count``. That counter is

    _node_count(e) = 1 + sum(map(_node_count, e.args))   # for non-Float e

i.e. a full recursive re-traversal, recomputed millions of times with **no
memoisation** -- it accounted for ~85% of cse time in the profile.

``_node_count`` is a pure function of the (immutable, hashable) expression, so
memoising it returns the *same* counts -> the *same* ordering -> **byte-identical
cse output**, only far faster. We install a memoised counter for the duration of
the call and restore the original afterwards (so nothing else is affected and the
cache cannot grow unbounded across a multi-functional run).

This is the single vendored optimisation the build relies on; it changes neither
the generated math nor its size, only the time to produce it.
"""

import sympy as sp
import sympy.core.sorting as _sorting

# Capture the genuine implementations once, so wrapping is recursion-safe even if
# a caller rebinds ``sympy.cse`` to this module's ``cse``.
_orig_cse = sp.cse


def _make_memo_node_count():
    cache = {}

    def memo(e):
        # Mirror sympy.core.sorting._node_count exactly, with memoisation.
        if e.is_Float:
            return 0.5
        c = cache.get(e)
        if c is None:
            c = 1 + sum(map(memo, e.args))
            cache[e] = c
        return c

    return memo


def cse(*args, **kwargs):
    """``sympy.cse`` with a memoised ``_node_count``; identical output."""
    saved = _sorting._node_count
    _sorting._node_count = _make_memo_node_count()
    try:
        return _orig_cse(*args, **kwargs)
    finally:
        _sorting._node_count = saved
