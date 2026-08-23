#!/usr/bin/env python3
"""Translate a libxc Maple functional into the SymPy functional format.

    maple/<family>/<name>.mpl  ->  python/<family>/<name>.py

Migration aid for the SymPy code-generator port. The functional .mpl
files are highly regular (copyright header, type/prefix headers, $ifdef
parameter blocks, a few `name := (args) -> expr` definitions); this
translates that structure mechanically. Constructs it cannot handle are
emitted as `# TODO(mpl2py): ...` markers and reported on stderr, so the
remaining work is an explicit, reviewable list rather than a 700-file
hand port.

Usage:
    python3 scripts/sympy2c/mpl2py.py maple/gga_exc/gga_x_pbe.mpl
    python3 scripts/sympy2c/mpl2py.py --check maple/gga_exc/gga_x_pbe.mpl
"""
import io
import keyword
import os
import re
import sys
import tokenize
from argparse import ArgumentParser


def _safe_ident(name):
  """Append '_' to identifiers that collide with a Python keyword."""
  return name + "_" if keyword.iskeyword(name) else name


def _strip_block_comment(text):
  """Return (copyright_lines, rest) splitting off a leading (* ... *).

  A functional that has no copyright header starts straight with a
  (* type: ... *) / (* prefix: ... *) directive (e.g. mgga_x_ktbm); that
  must not be consumed as the copyright, or the directive is lost."""
  m = re.match(r'\s*\(\*(.*?)\*\)', text, re.S)
  if not m:
    return [], text
  body = m.group(1).strip("\n")
  if re.match(r'\s*(type|prefix|replace)\s*:', body):
    return [], text
  return [ln.rstrip() for ln in body.splitlines()], text[m.end():]


# Maple name -> SymPy name rewrites
_TRIG_MAP = {
    "arcsinh": "asinh", "arccosh": "acosh", "arctanh": "atanh",
    "arccsch": "acsch", "arcsech": "asech", "arccoth": "acoth",
    "arcsin": "asin", "arccos": "acos", "arctan": "atan",
    "Zeta": "zeta",
    "ChebyshevT": "chebyshevt", "ChebyshevU": "chebyshevu",
    "ln": "log",
    # Maple's abs(x) translates to libxc's m_abs(x) -- a my_piecewise3
    # whose derivatives are piecewise constants, so it does not introduce
    # a DiracDelta on second-differentiation the way SymPy's Abs does.
    "abs": "m_abs",
}


def _translate_cond(cond):
  """Translate a Maple boolean condition to a SymPy one."""
  cond = cond.strip()
  if cond.startswith("(") and cond.endswith(")"):
    cond = cond[1:-1].strip()
  m = re.match(r'(.+?)(<=|>=|<>|=|<|>)(.+)', cond)
  if not m:
    return _translate_expr(cond)
  lhs = _translate_expr(m.group(1))
  rhs = _translate_expr(m.group(3))
  op = m.group(2)
  if op == "=":
    return "Eq({}, {})".format(lhs, rhs)
  if op == "<>":
    return "Ne({}, {})".format(lhs, rhs)
  return "{} {} {}".format(lhs, op, rhs)


def _translate_maple_if(s):
  """Translate `if C then E elif C2 then E2 [else E3] end if` to a
  my_piecewise3 chain. Returns None if the shape is not recognised."""
  s = re.sub(r'\bend\s+if\s*$', '', re.sub(r'^if\b', '', s.strip())).strip()
  else_expr = None
  m = re.search(r'\belse\b', s)
  if m:
    s, else_expr = s[:m.start()], s[m.end():].strip()
  branches = []
  for part in re.split(r'\belif\b', s):
    cm = re.match(r'(.*?)\bthen\b(.*)', part, re.S)
    if not cm:
      return None
    branches.append((_translate_cond(cm.group(1)),
                     _translate_expr(cm.group(2).strip())))
  if not branches:
    return None
  if else_expr is not None:
    result = _translate_expr(else_expr)
  else:
    # Promoting the last elif branch to the unconditional else CHANGES the
    # semantics for inputs matching no condition (Maple would leave the
    # expression unevaluated; the translation returns the last branch's
    # value). Sound only when the author knows every call site hits some
    # branch -- so say it out loud.
    _EXTRA_WARNINGS.append(
        "if-chain without else: last branch promoted to unconditional "
        "else (wrong for inputs matching no condition)")
    result = branches.pop()[1]      # last elif supplies the else value
  for cond, expr in reversed(branches):
    result = "my_piecewise3({}, {}, {})".format(cond, expr, result)
  return result


def _translate_iterators(expr):
  """Rewrite Maple's `add(BODY, i=LO..HI)` and `seq(BODY, i=LO..HI)`.

  add -> a Python `sum(...)`; seq -> a bare generator-expression clause
  (it almost always sits inside `[ ... ]`, becoming a list
  comprehension). Each keyword is processed right-most first so nested
  and sibling occurrences are all handled."""
  for kw in ("add", "seq"):
    while True:
      matches = list(re.finditer(r'\b' + kw + r'\(', expr))
      if not matches:
        break
      idx = matches[-1].start()
      depth, end = 0, -1
      for k in range(idx + len(kw), len(expr)):  # start at the '('
        if expr[k] == "(":
          depth += 1
        elif expr[k] == ")":
          depth -= 1
          if depth == 0:
            end = k
            break
      if end < 0:
        break
      inner = expr[idx + len(kw) + 1:end]
      m = re.search(r',\s*(\w+)\s*=\s*(.+?)\.\.(.+)$', inner)
      if not m:
        break
      body, var = inner[:m.start()].strip(), m.group(1)
      lo, hi = m.group(2).strip(), m.group(3).strip()
      comp = "({}) for {} in range({}, ({}) + 1)".format(body, var, lo, hi)
      repl = "sum({})".format(comp) if kw == "add" else comp
      expr = expr[:idx] + repl + expr[end + 1:]
  return expr


# expansion / substitution dummy variables seen in the file being
# translated; emitted as module-level Symbols by translate().
# Warnings raised by translation helpers that have no return channel for
# them (e.g. the if-expression translator); drained by translate().
_EXTRA_WARNINGS = []

_SERIES_DUMMIES = set()

# Helpers libxc_codegen.py provides natively, so they are not translated from
# .mpl: the Maple series/asymptotic-truncation scaffolding (padding_order,
# throw_out_large_n), the SymPy-native enforce_smooth_lr that replaces it, and
# one_minus_z_pow_n (parse-time type()/add metaprogramming).
_NATIVE_HELPERS = {"padding_order", "throw_out_large_n", "enforce_smooth_lr",
                   "one_minus_z_pow_n"}

# set while translating a file that does `with(orthopoly)`, so Maple's
# Legendre polynomial P(n, x) is rewritten to SymPy's legendre(n, x).
_ORTHOPOLY = [False]

# (regex, replacement) pairs from `(* replace: "A" -> "B" *)` headers,
# applied to every translated expression.
_REPLACE = []


def _split_args(s):
  """Split a call-argument string on top-level commas."""
  args, depth, cur = [], 0, ""
  for c in s:
    if c in "([":
      depth += 1
    elif c in ")]":
      depth -= 1
    if c == "," and depth == 0:
      args.append(cur)
      cur = ""
    else:
      cur += c
  if cur.strip():
    args.append(cur)
  return [a.strip() for a in args]


def _maple_arrow_to_lambda(val):
  """Lower a Maple arrow function `(args) -> body` (or `a -> body`),
  optionally parenthesized, to a Python lambda. Returns None if `val`
  is not an arrow. Used for substitution-rule values such as
  `my_piecewise3 = ((c, a, b) -> b)` inside eval()/subs()."""
  s = val.strip()
  if "->" not in s:
    return None
  if s.startswith("(") and s.endswith(")") and _balanced(s[1:-1]):
    s = s[1:-1].strip()
  m = (re.match(r'\(([^)]*)\)\s*->(.*)$', s, re.S)
       or re.match(r'(\w+)\s*->(.*)$', s, re.S))
  if not m:
    return None
  return "(lambda {}: {})".format(m.group(1).strip(),
                                  _translate_expr(m.group(2).strip()))


def _translate_series(expr):
  """Rewrite Maple's symbolic-series calls onto the libxc_codegen
  helpers: taylor/series(BODY, VAR=POINT, ORDER), eval(EXPR, VAR=VAL
  [, ...]) and subs(VAR=VAL [, ...], EXPR). convert() and diff() need no
  rewrite -- they map straight onto helpers of the same name. Expansion
  and substitution variables are collected into _SERIES_DUMMIES."""
  for kw, helper in (("taylor", "maple_taylor"),
                     ("series", "maple_series"),
                     ("eval", "maple_eval"),
                     ("subs", "maple_eval")):
    while True:
      matches = list(re.finditer(r'\b' + kw + r'\(', expr))
      if not matches:
        break
      idx = matches[-1].start()
      depth, end = 0, -1
      for k in range(idx + len(kw), len(expr)):
        if expr[k] == "(":
          depth += 1
        elif expr[k] == ")":
          depth -= 1
          if depth == 0:
            end = k
            break
      if end < 0:
        break
      args = _split_args(expr[idx + len(kw) + 1:end])
      if kw in ("taylor", "series") and len(args) == 3:
        body, eqn, order = args
        var, point = (p.strip() for p in eqn.split("=", 1))
        _SERIES_DUMMIES.add(var)
        new = "{}({}, {}, {}, {})".format(helper, body, var, point, order)
      elif kw in ("eval", "subs") and len(args) >= 2:
        # eval(EXPR, eqs...): EXPR first; subs(eqs..., EXPR): EXPR last.
        if kw == "eval":
          target, eqn_args = args[0], args[1:]
        else:
          target, eqn_args = args[-1], args[:-1]
        # the equations may be wrapped in a single Maple list
        if len(eqn_args) == 1 and eqn_args[0].strip().startswith("["):
          eqn_args = _split_args(eqn_args[0].strip()[1:-1])
        flat, ok = [], True
        for eqn in eqn_args:
          if "=" not in eqn:
            ok = False
            break
          var, val = (p.strip() for p in eqn.split("=", 1))
          if var != "csgn":
            _SERIES_DUMMIES.add(var)
          lam = _maple_arrow_to_lambda(val)
          flat += [var, lam if lam is not None else val]
        if not ok:
          break  # not a substitution list; leave for the compile check
        new = "maple_eval({}, {})".format(target, ", ".join(flat))
      else:
        break  # unrecognised arity; leave for the compile check to flag
      expr = expr[:idx] + new + expr[end + 1:]
  return expr


def _ends_statement(buf):
  """True if buf ends a Maple statement -- ends with ':' once any
  trailing (* *) comments are removed."""
  return re.sub(r'(\(\*.*?\*\)\s*)+$', '', buf, flags=re.S).rstrip().endswith(":")


def _split_maple_statements(buf):
  """Split a Maple source buffer into individual ':'-terminated
  statements. ':=' is not a terminator; (* *) comments are kept intact
  and never split on. A preprocessor directive (`$define`, `$undef`,
  `$include`, ...) is its own statement -- not `:`-terminated -- so the
  end of the directive line also ends the current statement."""
  parts, cur = [], ""
  i, n = 0, len(buf)
  in_comment = False
  while i < n:
    if in_comment:
      if buf[i:i + 2] == "*)":
        cur += "*)"
        i += 2
        in_comment = False
      else:
        cur += buf[i]
        i += 1
      continue
    if buf[i:i + 2] == "(*":
      cur += "(*"
      i += 2
      in_comment = True
      continue
    if buf[i] == ";" or (buf[i] == ":" and buf[i:i + 2] != ":="):
      parts.append(cur)
      cur = ""
      i += 1
      continue
    # A preprocessor directive ends at end-of-line, not at a colon.
    # Split immediately so it does not absorb the following statement.
    if (buf[i] == "$"
        and (not cur or cur[-1] == "\n")
        and re.match(r"\$(define|undef|include|ifdef|ifndef|else|endif)\b",
                     buf[i:])):
      eol = buf.find("\n", i)
      if eol < 0:
        eol = n
      cur += buf[i:eol]
      parts.append(cur)
      cur = ""
      i = eol
      continue
    cur += buf[i]
    i += 1
  if cur.strip():
    parts.append(cur)
  return [p for p in parts if p.strip()]


def _wrap_numbers(expr):
  """Wrap numeric literals so the translated expression stays exact.

  Maple arithmetic is exact: `1/3` is a rational. Python would evaluate
  the same `1/3` in double precision, collapsing Maple's exact rational
  exponents into floats -- so x^(1/3) ends up as pow(x, 0.33333...)
  instead of a cube root. Making every literal a SymPy number keeps the
  whole functional symbolic: Integer(1)/Integer(3) is Rational(1, 3),
  and the C printer can emit M_CBRTPI / POW_1_3() chains. Float literals
  are rebuilt from their source text (Float('0.8040')) so the value is
  not pinned to double precision -- a prerequisite for quad-precision
  code generation."""
  try:
    toks = list(tokenize.generate_tokens(io.StringIO(expr).readline))
  except (tokenize.TokenError, IndentationError, SyntaxError):
    return expr                          # not lexable: leave it untouched
  lines = expr.split("\n")
  edits = []
  for i, tok in enumerate(toks):
    if tok.type != tokenize.NUMBER or tok.start[0] != tok.end[0]:
      continue
    # skip a literal already inside Integer(...) (idempotency); Float(...)
    # holds its digits in a string token, so it is never re-wrapped.
    if (i >= 2 and toks[i - 1].string == "("
        and toks[i - 2].string in ("Integer", "Float")):
      continue
    text = tok.string
    if re.fullmatch(r'[0-9]+', text):
      new = "Integer(" + text + ")"
    elif (any(c in text for c in ".eE")
          and re.fullmatch(r'[0-9]*\.?[0-9]*([eE][-+]?[0-9]+)?', text)):
      new = "Float('" + text + "')"
    else:
      continue                           # hex / binary / complex: leave it
    edits.append((tok.start[0], tok.start[1], tok.end[1], new))
  for row, c0, c1, new in sorted(edits, reverse=True):
    ln = lines[row - 1]
    lines[row - 1] = ln[:c0] + new + ln[c1:]
  return "\n".join(lines)


def _balanced(s):
  """True if parentheses/brackets in s are balanced."""
  d = 0
  for c in s:
    if c in "([":
      d += 1
    elif c in ")]":
      d -= 1
      if d < 0:
        return False
  return d == 0


def _split_top(s, sep):
  """Split s on each occurrence of sep sitting at bracket depth 0."""
  parts, depth, last, i = [], 0, 0, 0
  while i < len(s):
    c = s[i]
    if c in "([":
      depth += 1
    elif c in ")]":
      depth -= 1
    if depth == 0 and s[i:i + len(sep)] == sep:
      parts.append(s[last:i])
      i += len(sep)
      last = i
      continue
    i += 1
  parts.append(s[last:])
  return parts


def _eqify(cond):
  """Translate a Maple boolean used as a my_piecewise condition into a
  symbolic SymPy boolean: `a = b` -> Eq(a, b), `a <> b` -> Ne(a, b),
  `a and b` -> And(a, b), `a or b` -> Or(a, b), `not a` -> Not(a).
  Python's `and`/`or` cannot be used -- they eagerly evaluate the truth
  value of a SymPy Relational, which raises. Comparisons valid in Python
  (<=, <, ...) and bare predicate calls are returned unchanged."""
  cond = " ".join(cond.split())
  for kw, fn in ((" or ", "Or"), (" and ", "And")):
    parts = _split_top(cond, kw)
    if len(parts) > 1:
      return fn + "(" + ", ".join(_eqify(p) for p in parts) + ")"
  c = cond.strip()
  m = re.match(r'not\b\s*(.*)', c, re.S)
  if m:
    return "Not(" + _eqify(m.group(1)) + ")"
  if c.startswith("(") and c.endswith(")") and _balanced(c[1:-1]):
    return "(" + _eqify(c[1:-1]) + ")"
  depth = 0
  for i, ch in enumerate(c):
    if ch in "([":
      depth += 1
    elif ch in ")]":
      depth -= 1
    elif depth == 0:
      for op in ("<=", ">=", "<>", "==", "=", "<", ">"):
        if c[i:i + len(op)] == op:
          lhs, rhs = c[:i].strip(), c[i + len(op):].strip()
          if op == "=":
            return "Eq({}, {})".format(lhs, rhs)
          if op == "<>":
            return "Ne({}, {})".format(lhs, rhs)
          return c              # <=, >=, ==, <, > are valid Python
  return c                      # no comparison: a bare predicate call


def _translate_piecewise_conds(expr):
  """Maple `=` is equality, but in a my_piecewise condition slot the
  translator would otherwise emit Python `=` (assignment). Rewrite the
  condition arguments -- my_piecewise3's 1st, my_piecewise5's 1st/3rd."""
  for kw, slots in (("my_piecewise3", (0,)), ("my_piecewise5", (0, 2))):
    pat = re.compile(r'\b' + kw + r'\(')
    pos = 0
    while True:
      m = pat.search(expr, pos)
      if not m:
        break
      start = m.end() - 1
      depth, end = 0, -1
      for k in range(start, len(expr)):
        if expr[k] == "(":
          depth += 1
        elif expr[k] == ")":
          depth -= 1
          if depth == 0:
            end = k
            break
      if end < 0:
        break
      args = _split_args(expr[start + 1:end])
      changed = False
      for ci in slots:
        if ci < len(args):
          new = _eqify(args[ci])
          if new != " ".join(args[ci].split()):
            args[ci] = new
            changed = True
      if changed:
        expr = (expr[:start + 1]
                + ", ".join(a.strip() for a in args) + expr[end:])
      pos = m.end()
  return expr


def _fix_atan2(expr):
  """Maple's 2-argument arctan(y, x) is atan2; the 1-argument form is
  plain atan. The blind arctan -> atan trig rename cannot tell them
  apart, so resolve it from the call's arity first."""
  while True:
    m = re.search(r'\barctan\(', expr)
    if not m:
      return expr
    paren = m.end() - 1
    depth, end = 0, -1
    for k in range(paren, len(expr)):
      if expr[k] == "(":
        depth += 1
      elif expr[k] == ")":
        depth -= 1
        if depth == 0:
          end = k
          break
    if end < 0:
      return expr
    name = "atan2" if len(_split_args(expr[paren + 1:end])) == 2 else "atan"
    expr = expr[:m.start()] + name + expr[paren:]


def _wrap_lists(expr):
  """Wrap Maple list literals [...] as maple_list([...]) so they keep
  Maple's 1-based subscripting wherever they appear (a list passed as a
  call argument is indexed 1-based inside the callee, e.g. b97.mpl's
  b97_g). A '[' following an identifier, ')' or ']' is a subscript and
  is left alone; an already-wrapped list is skipped."""
  i = 0
  while i < len(expr):
    if expr[i] != "[":
      i += 1
      continue
    j = i - 1
    while j >= 0 and expr[j] in " \t\n":
      j -= 1
    if j >= 0 and (expr[j].isalnum() or expr[j] in "_)]"):
      i += 1                              # subscript, not a literal
      continue
    if expr[:i].rstrip().endswith("maple_list("):
      i += 1                              # already wrapped
      continue
    depth, end = 0, -1
    for k in range(i, len(expr)):
      if expr[k] in "([":
        depth += 1
      elif expr[k] in ")]":
        depth -= 1
        if depth == 0:
          end = k
          break
    if end < 0:
      break
    expr = expr[:i] + "maple_list(" + expr[i:end + 1] + ")" + expr[end + 1:]
    # advance only past the inserted `maple_list(`, so nested list rows
    # of a matrix literal are wrapped too on the next iterations.
    i += len("maple_list(")
  return expr


def _translate_expr(expr):
  """Translate a Maple expression fragment to Python / SymPy syntax."""
  if '"' in expr:
    # Every rewrite below applies INSIDE string literals too ("for Pi in x^2"
    # would become "for_ pi in x**2"). Nothing in the corpus carries strings
    # through here (printf scaffolding is dropped by the proc translator), so
    # rather than grow a string-aware tokenizer, flag it loudly.
    _EXTRA_WARNINGS.append(
        "expression contains a string literal; translation rewrites apply "
        "inside it and may mangle its content: " + expr[:60])
  expr = re.sub(r'\(\*.*?\*\)', ' ', expr, flags=re.S)  # drop inline comments
  # rename Maple identifiers that collide with Python keywords (e.g. a
  # variable named `lambda`). The boolean-operator keywords are spelled
  # the same in Maple and Python, so they are left untouched.
  for kw in keyword.kwlist:
    if kw in ("and", "or", "not", "in", "is"):
      continue
    expr = re.sub(r'\b' + kw + r'\b', kw + '_', expr)
  expr = _translate_series(expr)
  expr = expr.replace("^", "**")
  expr = re.sub(r'\bPi\b', 'pi', expr)
  if _ORTHOPOLY[0]:                       # Maple orthopoly P -> legendre
    expr = re.sub(r'\bP\(', 'legendre(', expr)
  expr = _fix_atan2(expr)                 # 2-arg arctan -> atan2
  for maple_name, sympy_name in _TRIG_MAP.items():
    expr = re.sub(r'\b' + maple_name + r'\b', sympy_name, expr)
  expr = _translate_iterators(expr)
  expr = _wrap_lists(expr)
  expr = _translate_piecewise_conds(expr)
  expr = _wrap_numbers(expr)
  return expr


def _translate_def(text):
  """Translate a `name := (args) -> body :` Maple definition.

  Returns (chunk, warnings)."""
  warnings = []
  text = text.strip().rstrip(":").strip()
  name, rhs = re.match(r'(\w+)\s*:?=\s*(.*)', text, re.S).group(1, 2)
  name = _safe_ident(name)
  rhs = rhs.strip()

  # function definition: either (a, b) -> body or single-arg a -> body
  m = re.match(r'\(([^)]*)\)\s*->(.*)', rhs, re.S)
  if not m:
    m = re.match(r'(\w+)\s*->(.*)', rhs, re.S)
  if not m:
    # proc(PARAMS) STATEMENTS end proc -- a multi-statement function
    pm = re.match(r'proc\s*\(([^)]*)\)(.*)end\s+proc', rhs, re.S)
    if pm:
      pargs = ", ".join(_safe_ident(a.strip())
                        for a in pm.group(1).split(",") if a.strip())
      lines = []
      for st in _split_maple_statements(pm.group(2)):
        # keep any (* *) comments as Python comments
        for cmt in re.findall(r'\(\*(.*?)\*\)', st, re.S):
          t = " ".join(cmt.split())
          lines.append("    # " + t if t else "    #")
        s = " ".join(re.sub(r'\(\*.*?\*\)', ' ', st, flags=re.S).split())
        if not s or re.match(r'(local|global|option)\b', s):
          continue                       # declarations: not needed in Python
        if re.match(r'if\b', s):         # a proc body that is an if-chain
          piecewise = _translate_maple_if(s)
          if piecewise is not None:
            lines.append("    return " + piecewise)
            continue
        rm = re.match(r'return\b(.*)', s)
        if rm:
          lines.append("    return " + _translate_expr(rm.group(1).strip()))
          continue
        am = re.match(r'(\w+)\s*:?=\s*(.*)', s)
        if am:
          lines.append("    {} = {}".format(
              _safe_ident(am.group(1)), _translate_expr(am.group(2).strip())))
          continue
        if re.match(r'(printf|fprintf|print|check_asymptotics)\b', s):
          continue   # debug / verification scaffolding, not eval math
        if re.match(r'(for|while|do|od|end|break|next)\b', s):
          warnings.append("unhandled proc statement: " + s[:50])
          lines.append("    # TODO(mpl2py): " + s)
          continue
        # a bare expression is Maple's implicit return value
        lines.append("    return " + _translate_expr(s))
      decorator = "" if name == "f" else "@helper\n"
      return ("{}def {}({}):\n{}".format(decorator, name, pargs,
                                         "\n".join(lines)), warnings)

    # plain assignment (a constant or a non-callable expression): a
    # module-level binding is the faithful translation. A list literal
    # is wrapped so it keeps Maple's 1-based subscripting.
    expr = _translate_expr(" ".join(ln.strip() for ln in rhs.splitlines()))
    if expr.lstrip().startswith("["):
      return "{} = maple_list({})".format(name, expr), warnings
    return "{} = {}".format(name, expr), warnings

  args = ", ".join(_safe_ident(a.strip())
                   for a in m.group(1).split(",") if a.strip())
  body = _translate_expr(m.group(2))
  body_lines = [ln.rstrip() for ln in body.splitlines() if ln.strip()]

  # Every definition except the final `f` is offered to @helper; the
  # decorator itself falls back to inlining when the function takes a
  # callable or array-valued argument and so cannot be wrapped.
  decorator = "" if name == "f" else "@helper\n"

  if len(body_lines) == 1:
    ret = "    return " + body_lines[0].strip()
  else:
    ret = ("    return (\n"
           + "\n".join("        " + ln.strip() for ln in body_lines)
           + "\n    )")
  return "{}def {}({}):\n{}".format(decorator, name, args, ret), warnings


def _translate_diff_rule(buf):
  """Translate a Maple `diff/FUNC` derivative rule into a SymPy Function
  subclass with an fdiff method.

  The rule body is the chain rule, PARTIAL * diff(arg, x); setting that
  diff(...) factor to 1 recovers PARTIAL, the partial derivative the
  fdiff method must return."""
  text = " ".join(buf.split()).rstrip(":").strip()
  m = re.match(r'`diff/(\w+)`\s*:=\s*(.*)', text)
  if not m:
    return "# TODO(mpl2py): " + text[:70], ["unhandled diff rule"]
  fname, rest = m.group(1), m.group(2).strip()

  pm = re.match(r'proc\s*\(([^)]*)\)(.*?)end\s+proc', rest)
  if not pm:
    pm = re.match(r'\(([^)]*)\)\s*->(.*)', rest)
  if not pm:
    return "# TODO(mpl2py): " + text[:70], ["unhandled diff rule: " + fname]

  params = [p.strip() for p in pm.group(1).split(",") if p.strip()]
  body = pm.group(2).strip()
  if len(params) < 2:
    return "# TODO(mpl2py): " + text[:70], ["diff rule arity: " + fname]
  fargs, dvar = params[:-1], params[-1]

  # locate the chain-rule factor diff(<one of fargs>, dvar)
  dm = re.search(r'diff\(\s*(\w+)\s*,\s*' + re.escape(dvar) + r'\s*\)', body)
  if not dm or dm.group(1) not in fargs:
    return "# TODO(mpl2py): " + text[:70], ["diff rule shape: " + fname]
  argindex = fargs.index(dm.group(1)) + 1
  partial = _translate_expr(body[:dm.start()] + "1" + body[dm.end():])
  # Only the FIRST diff(arg, dvar) factor becomes the partial: a rule whose
  # body carries several (the diff/my_piecewise3 shape) would get a partial
  # for one argument and a dangling diff() for the rest -- silently wrong
  # derivatives. Refuse rather than mistranslate.
  if re.search(r'\bdiff\(', partial):
    return ("# TODO(mpl2py): " + text[:70],
            ["diff rule has multiple diff() factors (only the first would be "
             "translated, the rest silently wrong): " + fname])

  # The SymPy class keeps the Maple name; any `replace:` header is a
  # post-process on the generated C, applied by the engine -- it may
  # rename the call or inject fixed leading C arguments.
  cls = fname
  unpack = ", ".join(_safe_ident(a) for a in fargs)
  if len(fargs) == 1:
    unpack += ","
  chunk = (
      "class {}(Function):\n".format(cls)
      + "    def fdiff(self, argindex=1):\n"
      + "        {} = self.args\n".format(unpack)
      + "        if argindex == {}:\n".format(argindex)
      + "            return {}\n".format(partial)
      + "        return 0")
  return chunk, []


def _indent(lines):
  """Indent every (possibly multi-line) entry by two spaces."""
  out = []
  for ln in lines:
    for sub in ln.split("\n"):
      out.append("  " + sub if sub.strip() else "")
  return out


def _translate_block_body(blk_lines):
  """Translate the body of a $ifdef block -- a run of Maple statements,
  almost always `params_a_X := value` parameter assignments. Returns
  (python_lines, warnings)."""
  out, warnings = [], []
  for st in _split_maple_statements("\n".join(blk_lines)):
    for cmt in re.findall(r'\(\*(.*?)\*\)', st, re.S):
      t = " ".join(cmt.split())
      out.append("# " + t if t else "#")
    s = " ".join(re.sub(r'\(\*.*?\*\)', ' ', st, flags=re.S).split())
    s = s.strip().rstrip(":").strip()
    if not s:
      continue
    if s.startswith("#"):
      out.append(s)
      continue
    md = re.match(r'\$define\s+(\w+)', s)
    if md:
      out.append("define({!r})".format(md.group(1)))
      continue
    if re.match(r'\w+\s*:?=', s):
      chunk, warn = _translate_def(s)
      out.append(chunk)
      warnings.extend(warn)
    else:
      warnings.append("unhandled in $ifdef block: " + s)
      out.append("# TODO(mpl2py): " + s)
  if not any(ln.strip() and not ln.lstrip().startswith("#") for ln in out):
    out.append("pass")          # a Python `if:` needs a real statement
  return out, warnings


def _def_name(chunk):
  """The identifier a def chunk binds (def/class NAME, or NAME = ...)."""
  for line in chunk.splitlines():
    s = line.strip()
    if not s or s.startswith("#") or s.startswith("@"):
      continue
    m = re.match(r'(?:def|class)\s+(\w+)', s)
    if m:
      return m.group(1)
    m = re.match(r'(\w+)\s*=(?!=)', s)
    if m:
      return m.group(1)
    return None
  return None


def _topo_sort_defs(defs):
  """Reorder def chunks so each one follows the chunks it references.
  Maple resolves names lazily; Python module-level code does not, so a
  constant defined after one that uses it (lda_c_pw_erf's bc := d - ...)
  would raise. A stable topological sort keeps source order except where
  a forward reference forces a move; a dependency cycle is left in
  source order (the @helper inline fallback copes).

  include()/define()/undef() chunks are ordering BARRIERS: an include is a
  textual paste that captures whatever the includer assigned ABOVE the paste
  point (the params-before-include override pattern, e.g. gga_c_zpbeint),
  and such chunks bind no name, so nothing would otherwise stop the sort
  from floating a definition past one. Sort each inter-barrier segment
  independently; a forward reference across a barrier is left in place --
  the compile check reports it loudly instead of it being silently moved
  to where it captures the wrong binding."""
  barrier = re.compile(r"^\s*(include|define|undef)\(", re.M)
  segments, cur = [], []
  for ch in defs:
    if _def_name(ch) is None and barrier.search(ch):
      segments.append(cur)
      segments.append([ch])
      cur = []
    else:
      cur.append(ch)
  segments.append(cur)
  if len(segments) > 1:
    out = []
    for seg in segments:
      out.extend(_topo_sort_segment(seg))
    return out
  return _topo_sort_segment(defs)


def _topo_sort_segment(defs):
  names = {}
  for idx, ch in enumerate(defs):
    nm = _def_name(ch)
    if nm and nm not in names:
      names[nm] = idx
  ident = re.compile(r'\b[A-Za-z_]\w*\b')
  deps = []
  for idx, ch in enumerate(defs):
    if _def_name(ch) is None:
      deps.append(set())             # a comment chunk: no dependencies
      continue
    deps.append({names[u] for u in ident.findall(ch)
                 if u in names and names[u] != idx})
  order, emitted, remaining = [], set(), list(range(len(defs)))
  while remaining:
    for idx in remaining:
      if deps[idx] <= emitted:
        order.append(idx)
        emitted.add(idx)
        remaining.remove(idx)
        break
    else:                            # cycle: emit the rest as-is
      order.extend(remaining)
      break
  return [defs[i] for i in order]


def translate(mpl_text):
  """Translate Maple functional source to a SymPy .py module.

  Returns (py_text, warnings)."""
  warnings = []
  _EXTRA_WARNINGS.clear()
  _SERIES_DUMMIES.clear()
  _ORTHOPOLY[0] = False
  _REPLACE.clear()
  copyright_lines, rest = _strip_block_comment(mpl_text)

  functype = None
  params_struct = None
  header_comments = []   # type / prefix, emitted near the top
  param_names = []       # ordered unique scalar params_a_* names
  array_param_names = [] # ordered unique array-valued params_a_* names
  preamble = []          # comments / $ifdef blocks before the first def
  defs = []              # def chunks and any comments between them
  seen_def = False

  lines = rest.splitlines()
  i, n = 0, len(lines)
  # index just past the last comment consumed, so that comment lines that
  # were adjacent in the Maple source stay in ONE chunk. Chunks are
  # blank-line separated when the module is assembled, and a comment block
  # must not come out double spaced.
  last_comment_end = -1
  while i < n:
    line = lines[i]
    stripped = line.strip()

    if not stripped:
      # keep blank lines that separate preamble groups
      if preamble and preamble[-1] != "" and not seen_def:
        preamble.append("")
      i += 1
      continue

    # ---- (* type: X *) -------------------------------------------------
    m = re.match(r'\(\*\s*type:\s*(\S+)\s*\*\)', stripped)
    if m:
      functype = m.group(1)
      header_comments.append("# type: " + functype)
      i += 1
      continue

    # ---- (* replace: "A" -> "B" *) -------------------------------------
    m = re.match(r'\(\*\s*replace:\s*"([^"]*)"\s*->\s*"([^"]*)"', stripped)
    if m:
      _REPLACE.append((m.group(1), m.group(2)))
      header_comments.append('# replace: "{}" -> "{}"'.format(*m.groups()))
      i += 1
      continue

    # ---- (* prefix: ... *) (may span lines) ----------------------------
    if re.match(r'\(\*\s*prefix:', stripped):
      buf = line
      while "*)" not in buf and i + 1 < n:
        i += 1
        buf += "\n" + lines[i]
      i += 1
      text = re.sub(r'\(\*\s*prefix:', '', buf).replace("*)", "")
      plines = [ln.rstrip() for ln in text.splitlines()]
      while plines and not plines[0].strip():
        plines.pop(0)
      while plines and not plines[-1].strip():
        plines.pop()
      header_comments.append("# prefix:")
      for ln in plines:
        if ln.strip():
          header_comments.append("#   " + ln.strip())
          ps = re.match(r'(\w+_params)\s*\*\s*params', ln.strip())
          if ps:
            params_struct = ps.group(1)
        else:
          header_comments.append("#")
      continue

    # ---- Maple '#' line comment (already valid Python) ----------------
    if stripped.startswith("#"):
      target = defs if seen_def else preamble
      if i == last_comment_end and target and target[-1].startswith("#"):
        target[-1] += "\n" + stripped
      else:
        target.append(stripped)
      i += 1
      last_comment_end = i
      continue

    # ---- (* comment *), possibly spanning several lines ----------------
    if stripped.startswith("(*"):
      buf = line
      while "*)" not in buf and i + 1 < n:
        i += 1
        buf += "\n" + lines[i]
      i += 1
      inner = re.sub(r'^\s*\(\*', '', buf).replace("*)", "")
      target = defs if seen_def else preamble
      target.append("\n".join("# " + s if s else "#"
                              for s in (ln.strip()
                                        for ln in inner.splitlines())))
      last_comment_end = i
      continue

    # ---- $include "foo.mpl" --------------------------------------------
    # Maple's $include is a textual paste. Emit a runtime include() at
    # this exact position so the fragment shares the includer's
    # namespace (see libxc_codegen.include). A system include such as
    # <util.mpl> is already covered by the libxc_codegen import.
    m = re.match(r'\$include\s+"?([^"\s]+)"?', stripped)
    if m:
      inc = m.group(1)
      if not inc.startswith("<"):
        if inc.endswith(".mpl"):
          inc = inc[:-len(".mpl")]
        # Emit inline, at the file position of the $include. Maple's
        # $include is a textual paste, so a fragment captures whatever
        # the includer assigned *above* the paste (e.g. gga_c_zpbeint
        # sets params_a_gamma to a constant before $include'ing
        # gga_c_pbe). Hoisting the include would run it too early.
        (defs if seen_def else preamble).append(
            "include({!r})".format(inc))
      i += 1
      continue

    # ---- $ifdef / $ifndef ... [$else] ... $endif -----------------------
    # Maple's preprocessor conditionals. Translated to a runtime
    # `if defined(...)` so an includer that $define's the macro can
    # activate a parameter-default block (see libxc_codegen.define).
    m = re.match(r'\$(ifdef|ifndef)\s+(\w+)', stripped)
    if m:
      negate = m.group(1) == "ifndef"
      macro = m.group(2)
      blk, depth = [], 1
      while i + 1 < n and depth > 0:
        i += 1
        ln = lines[i].strip()
        if re.match(r'\$ifn?def\b', ln):
          depth += 1
        elif re.match(r'\$endif\b', ln):
          depth -= 1
          if depth == 0:
            break
        blk.append(lines[i])
      i += 1
      cond = ("not defined({!r})" if negate
              else "defined({!r})").format(macro)
      # split into (condition, lines) branches at $elif / $else
      branches = [(cond, [])]
      for ln in blk:
        em = re.match(r'\s*\$elif\s+(\w+)', ln)
        if em:
          branches.append(("defined({!r})".format(em.group(1)), []))
        elif re.match(r'\s*\$else\b', ln):
          branches.append((None, []))
        else:
          branches[-1][1].append(ln)
      block = []
      for j, (bcond, blines) in enumerate(branches):
        if j == 0:
          block.append("if {}:".format(bcond))
        elif bcond is None:
          block.append("else:")
        else:
          block.append("elif {}:".format(bcond))
        body, warn = _translate_block_body(blines)
        block += _indent(body)
        warnings.extend(warn)
      (defs if seen_def else preamble).append("\n".join(block))
      continue

    # ---- $define X -----------------------------------------------------
    m = re.match(r'\$define\s+(\w+)', stripped)
    if m:
      # Inline, like $include: a $define activates the $ifdef blocks of
      # a fragment $include'd just below it, so its position matters.
      (defs if seen_def else preamble).append(
          "define({!r})".format(m.group(1)))
      i += 1
      continue

    # ---- $undef X ------------------------------------------------------
    m = re.match(r'\$undef\s+(\w+)', stripped)
    if m:
      # Inline, same as $define above: $undef position matters because it
      # gates any $ifdef blocks following it (and is used by e.g.
      # gga_c_q2d to drop the xc_dimensions_2d macro a 2D $include left
      # set, so the outer functional is correctly classified as 3D).
      (defs if seen_def else preamble).append(
          "undef({!r})".format(m.group(1)))
      i += 1
      continue

    # ---- other preprocessor directives (stray $elif/$else) -------------
    if re.match(r'\$(define|undef|ifdef|ifndef|elif|else|endif)\b', stripped):
      (defs if seen_def else preamble).append("# " + stripped)
      i += 1
      continue

    # ---- with(PACKAGE): a Maple package load --------------------------
    m = re.match(r'with\((\w+)\)', stripped)
    if m:
      pkg = m.group(1)
      (defs if seen_def else preamble).append("# with({})".format(pkg))
      if pkg == "orthopoly":
        # orthopoly provides P() etc.; SymPy provides legendre() directly
        _ORTHOPOLY[0] = True
      i += 1
      continue

    # ---- if evalb(Polarization = "...") then ... else ... end if ------
    # Defines something differently for unpol vs pol. The engine already
    # handles unpol (zeta=0) and pol separately, and the pol branch is
    # the general formula -- emit only that branch.
    m = re.match(r'if\s+evalb\s*\(\s*Polarization\s*=\s*"(\w+)"', stripped)
    if m:
      polariz = m.group(1)
      buf = line
      while not re.search(r'\bend\s+if\b', buf) and i + 1 < n:
        i += 1
        buf += "\n" + lines[i]
      i += 1
      inner = re.sub(r'^.*?\bthen\b', '', buf, count=1, flags=re.S)
      inner = re.sub(r'\bend\s+if\b.*$', '', inner, flags=re.S)
      em = re.search(r'\belse\b', inner)
      pol_blk = (inner[em.end():] if em else "") if polariz == "unpol" \
          else (inner[:em.start()] if em else inner)
      for stmt in _split_maple_statements(pol_blk):
        code = re.sub(r'\(\*.*?\*\)', ' ', stmt, flags=re.S).strip()
        if code:
          chunk, warn = _translate_def(code)
          defs.append(chunk)
          warnings.extend(warn)
          seen_def = True
      continue

    # ---- IDENT[index] := expr : a Maple indexed (element) assignment --
    if re.match(r'\w+\s*\[\s*\d+\s*\]\s*:?=', stripped):
      buf = line
      while not _ends_statement(buf) and i + 1 < n:
        i += 1
        buf += "\n" + lines[i]
      i += 1
      for stmt in _split_maple_statements(buf):
        for cmt in re.findall(r'\(\*(.*?)\*\)', stmt, re.S):
          t = " ".join(cmt.split())
          defs.append("# " + t if t else "#")
        code = re.sub(r'\(\*.*?\*\)', ' ', stmt, flags=re.S).strip()
        if not code:
          continue
        am = re.match(r'(\w+)\s*\[\s*(\d+)\s*\]\s*:?=\s*(.*)', code)
        if am:
          defs.append("{}[{}] = {}".format(
              am.group(1), am.group(2),
              _translate_expr(am.group(3).strip())))
          seen_def = True
        else:
          defs.append("# TODO(mpl2py): " + code)
          warnings.append("unhandled: " + code[:60])
      continue

    # ---- `diff/FUNC` := ... : a Maple custom-derivative rule ----------
    if stripped.startswith("`diff/"):
      buf = line
      while not _ends_statement(buf) and i + 1 < n:
        i += 1
        buf += "\n" + lines[i]
      i += 1
      chunk, warn = _translate_diff_rule(buf)
      defs.append(chunk)
      warnings.extend(warn)
      seen_def = True
      continue

    # ---- statement(s): one or more `name :?= ...` on the line(s) -------
    # Accepts both Maple ':=' and a bare '='. A single physical line may
    # carry several ':'-terminated statements with (* *) comments
    # interspersed; the buffer is split into individual statements and
    # any comments are preserved as Python comments.
    if re.match(r'\w+\s*:?=(?!=)', stripped):
      buf = line
      # a `proc` body has its own ':'-terminated statements -- it runs
      # to `end proc`, not to the first ':'
      while i + 1 < n:
        if re.search(r':?=\s*proc\b', buf):
          if re.search(r'\bend\s+proc\b', buf):
            break
        elif _ends_statement(buf):
          break
        i += 1
        buf += "\n" + lines[i]
      i += 1
      # helpers libxc_codegen.py provides natively are not translated
      _nm = re.match(r'(\w+)', buf.strip())
      if _nm and _nm.group(1) in _NATIVE_HELPERS:
        (defs if seen_def else preamble).append(
            "# {} provided natively by libxc_codegen".format(_nm.group(1)))
        seen_def = True
        continue
      # a proc definition is one statement; hand it straight to
      # _translate_def rather than splitting on its inner ':'
      if re.search(r':?=\s*proc\b', buf):
        chunk, warn = _translate_def(buf)
        defs.append(chunk)
        warnings.extend(warn)
        seen_def = True
        continue
      for stmt in _split_maple_statements(buf):
        # keep any (* *) comments, emitted as Python comments
        for cmt in re.findall(r'\(\*(.*?)\*\)', stmt, re.S):
          text = " ".join(cmt.split())
          (defs if seen_def else preamble).append(
              "# " + text if text else "#")
        code = re.sub(r'\(\*.*?\*\)', ' ', stmt, flags=re.S).strip()
        if not code:
          continue
        # array-valued / scalar parameter assignment. A top-level
        # params_a_* := value is a concrete value Maple assigns
        # unconditionally (e.g. gga_xc_th1's params_a_n := 21, which
        # sets the term count); emit it as a real assignment that
        # overrides the param() default.
        pm = re.match(r'(params_a_\w+)\s*:?=(?!=)', code)
        if pm and "->" not in code:
          pname = pm.group(1)
          if "[" in code:
            if pname not in array_param_names:
              array_param_names.append(pname)
          elif pname not in param_names:
            param_names.append(pname)
          chunk, warn = _translate_def(code)
          (defs if seen_def else preamble).append(chunk)
          warnings.extend(warn)
          continue
        # ordinary definition / constant
        chunk, warn = _translate_def(code)
        defs.append(chunk)
        warnings.extend(warn)
        seen_def = True
      continue

    # ---- anything else -------------------------------------------------
    warnings.append("unhandled line: " + stripped)
    (defs if seen_def else preamble).append("# TODO(mpl2py): " + stripped)
    i += 1

  # Any params_a_* symbol referenced but never assigned in the .mpl
  # (its default lives only in the C source) still needs a declaration.
  # A parameter is array-valued if it is indexed (params_a_X[...]) or
  # assigned a list literal (params_a_X := [...]) -- the latter catches
  # tabulated coefficients indexed only inside an $include'd helper
  # (e.g. mgga_c_m05 passes params_a_css to b97.mpl's b97_g).
  for pname in re.findall(r'\bparams_a_\w+', rest):
    if pname in param_names or pname in array_param_names:
      continue
    p = re.escape(pname)
    if re.search(p + r'\s*\[', rest) or re.search(p + r'\s*:?=\s*\[', rest):
      array_param_names.append(pname)
    else:
      param_names.append(pname)

  # ---- assemble the module ------------------------------------------
  out = ['"""']
  out += copyright_lines if copyright_lines else [" libxc functional"]
  out += ['"""', ""]
  out += header_comments
  out += ["", "from libxc_codegen import *  # noqa: F401, F403", ""]

  # default parameter declarations. A $ifdef block in the preamble below
  # may reassign one to a concrete value when its macro has been
  # $define'd (by this file or an includer), so these must come first.
  # param_default() is used rather than param() so that, when this file
  # is itself a fragment run via include(), a parameter the includer
  # already bound (above its $include) is not overwritten.
  for pname in param_names:
    out.append('{} = param_default("{}")'.format(
        pname, pname[len("params_a_"):]))
  for pname in array_param_names:
    out.append('{} = param_default("{}")'.format(
        pname, pname[len("params_a_"):]))
  if param_names or array_param_names:
    out.append("")

  # expansion / substitution dummy variables for the series machinery
  for dummy in sorted(_SERIES_DUMMIES):
    out.append('{} = Symbol("{}")'.format(dummy, dummy))
  if _SERIES_DUMMIES:
    out.append("")

  while preamble and preamble[-1] == "":
    preamble.pop()
  out += preamble
  if preamble:
    out.append("")

  for chunk in _topo_sort_defs(defs):
    out.append(chunk)
    out.append("")

  # TYPE / PARAMS_STRUCT / REPLACE are module constants read after the
  # module is imported; emit them last so a runtime include() earlier in
  # the file cannot clobber this functional's own values.
  tail = []
  if functype:
    tail.append('TYPE = "{}"'.format(functype))
  if params_struct:
    tail.append('PARAMS_STRUCT = "{}"'.format(params_struct))
  if _REPLACE:
    # post-process substitutions for the generated C (see compile_module)
    tail.append("REPLACE = [")
    for pat, repl in _REPLACE:
      tail.append("    ({!r}, {!r}),".format(pat, repl))
    tail.append("]")
  if tail:
    out += tail + [""]

  py_text = "\n".join(out).rstrip() + "\n"

  # a clean translation must at least be valid Python
  try:
    compile(py_text, "<mpl2py>", "exec")
  except SyntaxError as e:
    warnings.append("generated code does not compile (line {}): {}".format(
        e.lineno, e.msg))

  warnings.extend(_EXTRA_WARNINGS)
  return py_text, warnings


def main():
  ap = ArgumentParser(description=__doc__)
  ap.add_argument("mpl", help="path to a maple/<family>/<name>.mpl file")
  ap.add_argument("--check", action="store_true",
                  help="translate and report, but do not write the .py file")
  args = ap.parse_args()

  with open(args.mpl) as fh:
    py_text, warnings = translate(fh.read())

  fam = os.path.basename(os.path.dirname(args.mpl))
  name = os.path.basename(args.mpl)[:-len(".mpl")]
  if fam == "maple" and name == "util":
    # util.mpl's helpers are hand-ported into libxc_codegen.py, which every
    # functional pulls in via `from libxc_codegen import *` (a `<util.mpl>`
    # system include is deliberately not re-emitted). A generated python/util.py
    # would be dead, duplicated code -- don't write it.
    sys.stderr.write("{}: provided by libxc_codegen; not generating python/"
                     "util.py\n".format(args.mpl))
    return
  if fam == "maple":
    # shared library file (maple/<name>.mpl) -> top-level python module
    dest = os.path.join("python", name + ".py")
  else:
    dest = os.path.join("python", fam, name + ".py")

  if args.check:
    sys.stderr.write("{}: {} warning(s)\n".format(args.mpl, len(warnings)))
    for w in warnings:
      sys.stderr.write("  - " + w + "\n")
    sys.stdout.write(py_text)
    return

  os.makedirs(os.path.dirname(dest), exist_ok=True)
  with open(dest, "w") as fh:
    fh.write(py_text)
  status = "ok" if not warnings else "{} warning(s)".format(len(warnings))
  print("{} -> {}  [{}]".format(args.mpl, dest, status))
  for w in warnings:
    print("  - " + w)
  sys.exit(1 if warnings else 0)


if __name__ == "__main__":
  main()
