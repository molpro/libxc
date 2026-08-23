"""Regenerating a functional must give byte-identical C.

Several codegen passes walk the set returned by SymPy's `atoms()`, whose
iteration order varies between processes. Where that order escapes into the
output -- the helper toposort visiting callees, the channel fold creating
p-form helpers -- the generated C differed run to run even on the same
machine with the same interpreter, producing large spurious diffs on every
regeneration.

The end-to-end test below is deliberately a plain byte comparison rather
than an assertion about any particular pass, so it also catches sources of
nondeterminism that have not been found yet.
"""

import importlib.util
import os
import subprocess
import sys

import pytest

_HERE = os.path.dirname(os.path.abspath(__file__))
_ROOT = os.path.dirname(_HERE)
_COMPILE = os.path.join(_ROOT, "scripts", "sympy2c", "compile.py")
_SYMPY2C = os.path.join(_ROOT, "scripts", "sympy2c")
_PYTHON = os.path.join(_ROOT, "python")

# The generator lives in the source tree, not in an install or a dist tarball,
# and it needs SymPy. Skip rather than fail where either is absent: running the
# generator is a developer activity, and a build that only compiles and tests
# the library has no reason to carry SymPy (the Windows CI images do not).
_HAVE_GENERATOR = os.path.exists(_COMPILE) and os.path.isdir(_PYTHON)
_HAVE_SYMPY = importlib.util.find_spec("sympy") is not None

pytestmark = pytest.mark.skipif(
    not (_HAVE_GENERATOR and _HAVE_SYMPY),
    reason="code generator unavailable (not a source tree, or SymPy missing)")


# Helper emission order does not depend on the derivative order requested,
# so generate at --maxorder=0: ~0.8 s per run instead of ~19 s, with the
# full helper set still emitted.
_MAXORDER = "0"

# gga_c_p86vwn is the cheap case that actually exposes the bug: Q_vwn,
# f1_vwn, f2_vwn, f3_vwn and fx_vwn have no dependency edges between them,
# so every permutation is a valid topological order and only an explicit
# tie-break makes the output reproducible. Three runs, because two runs of a
# five-way shuffle agree by chance about 1% of the time.
_RUNS = 3


def _generate(functional, dest):
    subprocess.run(
        [sys.executable, _COMPILE, "--maxorder=" + _MAXORDER,
         functional, dest],
        check=True, capture_output=True, cwd=_ROOT)
    with open(dest) as fh:
        return fh.read()


@pytest.mark.parametrize("functional", ["gga_c_p86vwn"])
def test_generation_is_reproducible(functional, tmp_path):
    """Generating the same functional repeatedly gives identical C."""
    out = [_generate(functional, str(tmp_path / f"{functional}_{i}.c"))
           for i in range(_RUNS)]
    for i, text in enumerate(out[1:], start=1):
        assert text == out[0], (
            f"{functional} generation is not reproducible: run {i} differs "
            f"from run 0. Some pass is leaking set-iteration order into the "
            f"emitted C.")


def test_pform_helpers_are_created_in_a_stable_order():
    """The channel fold creates p-form helpers in a defined order.

    No functional in the library currently routes more than one squared-only
    wrapper through a single exchange channel, so this ordering cannot be
    reached end-to-end; build the multi-wrapper case directly to keep the
    guarantee from silently regressing.
    """
    sys.path[:0] = [_SYMPY2C, _PYTHON]
    sp = pytest.importorskip("sympy")
    import libxc_codegen as codegen
    from helper import Helper

    ss = sp.Symbol("sigma_ss", positive=True)
    x = sp.Symbol("x", positive=True)

    # Each wrapper is even in its gradient argument (so each is p-formable)
    # and independent of the others, leaving creation order unconstrained.
    names = ["wrapA", "wrapB", "wrapC", "wrapD", "wrapE"]
    helpers = [Helper(nm, [x], (1 + (i + 1) * x**2) / (1 + x**2 + x**4),
                      max_order=2)
               for i, nm in enumerate(names)]
    body = sum(h.call(sp.sqrt(ss)) for h in helpers)

    codegen._reset_specialized()
    try:
        folded = codegen._fold_channel_gradient(body, ss)
        created = [h.name for h in codegen._SPECIALIZED_ORDER]
    finally:
        codegen._reset_specialized()

    assert created == [nm + "_pf" for nm in names]
    # The fold is supposed to remove the bare sqrt(sigma_ss) as well.
    assert not codegen._has_fractional_ss(folded, ss)
