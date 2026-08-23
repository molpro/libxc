"""A helper's result array must cover every slot the helper writes.

Helpers are order-graded: `foo_k2` is the variant an order-2 kernel calls,
and it writes only the slots order 2 needs. The caller sizes the array with
a `_KMAX` conditional to match. If that bound is computed from anything
other than what the callee actually writes, the callee runs off the end of
the caller's stack frame -- which shows up as a segfault in an unrelated
place, not as a wrong number.

That happened: the bound counted slots by total derivative order, but the
dependency fixpoint can need a helper one order *above* the top-level order
consuming it (the chain rule through its arguments), so e.g. f_zeta writes
its 4th derivative in the _KMAX=3 variant. Every such array was short.

This is a cheap regex scan of the generated C -- no build, no generation --
so it can afford to check the whole library.
"""

import glob
import os
import re

import pytest

_HERE = os.path.dirname(os.path.abspath(__file__))
_MAPLE2C = os.path.join(os.path.dirname(_HERE), "src", "maple2c")

_MAX_KMAX = 4

pytestmark = pytest.mark.skipif(
    not os.path.isdir(_MAPLE2C),
    reason="generated sources not present")


def _helper_writes(text):
    """helper name -> {guard order: highest out[] index written at it}."""
    writes, fn, stack = {}, None, []
    for line in text.splitlines():
        s = line.strip()
        m = re.search(r"void XC_CAT\((\w+)_k, _KMAX\)", s)
        if m:
            fn, stack = m.group(1), []
            writes.setdefault(fn, {})
            continue
        g = re.match(r"#if _KMAX >= (\d+)", s)
        if g:
            stack.append(int(g.group(1)))
            continue
        if s.startswith("#if"):
            stack.append(None)          # unrelated conditional
            continue
        if s == "#endif":
            if stack:
                stack.pop()
            continue
        w = re.match(r"out\[(\d+)\]\s*=", s)
        if w and fn is not None:
            live = [x for x in stack if x is not None]
            at = max(live) if live else 0
            cur = writes[fn]
            cur[at] = max(cur.get(at, -1), int(w.group(1)))
    return writes


def _size_at(bound, kmax):
    """Evaluate a C array bound -- an integer literal or a chain of
    `(_KMAX) >= k ? n : ...` conditionals -- at a given _KMAX."""
    e = bound.replace("_KMAX", str(kmax))
    assert re.fullmatch(r"[\d\s()?:>=<]+", e), f"unparsed array bound: {bound}"
    cond = re.compile(r"\s*\(?(\d+)\)?\s*>=\s*(\d+)\s*\?\s*(\d+)\s*:\s*(.*)")
    while True:
        if re.fullmatch(r"\s*\d+\s*", e):
            return int(e)
        m = cond.fullmatch(e)
        assert m, f"unparsed array bound: {bound}"
        if int(m.group(1)) >= int(m.group(2)):
            return int(m.group(3))
        e = m.group(4)


def _graded_sources():
    return sorted(p for p in glob.glob(os.path.join(_MAPLE2C, "*", "*.c"))
                  if "_k, _KMAX" in open(p).read())


@pytest.mark.parametrize("path", _graded_sources(),
                         ids=lambda p: os.path.basename(p))
def test_helper_arrays_cover_what_the_helper_writes(path):
    text = open(path).read()
    writes = _helper_writes(text)
    dims, short = {}, []
    decl = re.compile(r"double (_hc\d+)\[([^\]]+)\]")
    call = re.compile(r"XC_CAT\((\w+)_k, _KMAX\)\s*\([^;]*?(_hc\d+)\)\s*;")
    for line in text.splitlines():
        d = decl.search(line)
        if d:
            dims[d.group(1)] = d.group(2)
        c = call.search(line)
        if not c:
            continue
        fn, arr = c.group(1), c.group(2)
        if arr not in dims or fn not in writes:
            continue
        for kmax in range(_MAX_KMAX + 1):
            need = max([v for g, v in writes[fn].items() if g <= kmax],
                       default=-1) + 1
            have = _size_at(dims[arr], kmax)
            if need == 0:
                continue        # nothing written at this order
            # Exact, not just sufficient: the generator knows how many slots
            # the callee writes, so a mismatch either way is a bug -- too
            # small runs off the caller's frame, too large means the sizing
            # is not actually derived from the callee.
            if have != need:
                short.append(f"{arr}[{have}] at _KMAX={kmax} but {fn} "
                             f"writes {need} slots")
                break
    assert not short, (
        f"{os.path.basename(path)}: helper array does not match the slots the "
        f"callee writes:\n  " + "\n  ".join(short))
