#!/usr/bin/env python3

# Copyright (C) 2021 M.A.L. Marques
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

import sys, re, os
from argparse import ArgumentParser, BooleanOptionalAction
from maple2c_lib.utils import *

def maple2c_init():
  mparser = ArgumentParser(usage="Convert a maple file into C code")
  mparser.add_argument('--srcdir', type = str, default = ".",
                       help='Directory where to find the source code')
  mparser.add_argument('--functional', type = str,
                       help='Name of the functional', required = True)
  mparser.add_argument('--maxorder', type = int, default = 3,
                       help='Maximum order of the derivatives')
  # BooleanOptionalAction: with type=str any value was truthy, so the natural
  # `--simplify false` / `--simplify no` silently turned ON simplify(...,
  # symbolic) -- which destroys the cancellation-free FP-stable forms.
  mparser.add_argument('--simplify', default = False,
                       action = BooleanOptionalAction,
                       help='Add a final simplification command? (destroys '
                            'cancellation-free forms; off by default)')
  # Exchange and kinetic-energy functionals obey exact spin scaling, so
  # each spin channel can be evaluated as an independent function of its
  # own same-spin density. Doing so avoids reconstructing the spin
  # densities from the total density and the spin polarization, which is
  # ill-conditioned for small or strongly polarized densities. On by
  # default; --no-spin-density restores the legacy (rs, zeta) path.
  mparser.add_argument('--spin-density', default = True,
                       action = BooleanOptionalAction,
                       help='Use the spin-density evaluation path for '
                            'spin-scaled (exchange / kinetic) functionals')

  parse = mparser.parse_args()

  # gather all information necessary to maple2c
  params = {}
  params["srcdir"]     = parse.srcdir
  params["functional"] = parse.functional
  params["maxorder"]   = parse.maxorder
  params["simplify_begin"] = "simplify(" if parse.simplify else ""
  params["simplify_end"]   = ", symbolic)" if parse.simplify else ""
  params["spin_density"]   = parse.spin_density

  # extract the family of the functional
  m = re.match(r'^(hyb_)?([^_]*)', params["functional"])
  params["family"] = m.group(2)

  # find out where the maple file resides
  possible_paths = [
    params["functional"],
    params["srcdir"] + "/maple/" + params["functional"],
    params["srcdir"] + "/maple/" + params["family"] + "_vxc/" + params["functional"],
    params["srcdir"] + "/maple/" + params["family"] + "_exc/" + params["functional"],
    ]
  for p in possible_paths:
    if os.path.isfile(p):
      params["maple_file"] = p
      break
    if os.path.isfile(p + ".mpl"):
      params["maple_file"] = p + ".mpl"
      break

  if "maple_file" not in params:
    print("File '" + params["functional"] + ".mpl" + "' not found")
    sys.exit(1)

  # we now read the header of the maple file to configure the functional
  fh = open(params["maple_file"], "r")
  params["replace"] = []
  params["prefix"]  = ""
  for line in fh:
    m = re.match(r'^\(\* type:\s(\S*)\s', line)
    if m:
      params["functype"] = m.group(1)

    m = re.match(r'^\(\* replace:\s*"([^"]*)"\s*->\s*"([^"]*)"', line)
    if m:
      params["replace"].append(m.group(1, 2))

    m = re.match(r'^\(\* spin_scaled:\s*(\S+)', line)
    if m:
      params["spin_scaled_directive"] = m.group(1).lower() in ("true", "yes", "1")

    if re.match(r'^\(\* prefix:', line):
      for line in fh:
        if re.match(r'^\*', line):
          break
        else:
          params["prefix"] += line

  if "functype" not in params:
    print("Could not determine type of functional")
    print("Please add something like '(* type: lda_exc *)' to the maple file")
    sys.exit(1)

  # Detect whether this is a spin-scaled functional (exchange or
  # kinetic energy). Such functionals obey exact spin scaling, so each
  # spin channel can be evaluated from its own same-spin density via
  # the spin-density path.
  fh.seek(0)
  contents = fh.read()
  fh.close()

  if "spin_scaled_directive" in params:
    # An explicit (* spin_scaled: true|false *) directive wins. It is
    # needed for functionals the heuristic cannot classify -- e.g.
    # mgga_x_mscan, which references lda_x_spin only as a prefactor but
    # depends on the total reduced gradient and is not spin-scalable.
    params["spin_scaled"] = params["spin_scaled_directive"]
  else:
    # Heuristic: a functional is spin-scaled if it routes through one
    # of util.mpl's spin-scaling wrappers. Restricted to pure exchange
    # (_x_) and kinetic-energy (_k_) functionals -- correlation does
    # not spin-scale, so exchange-correlation (_xc_) and pure
    # correlation (_c_) functionals are excluded even when they
    # reference a wrapper for their exchange part (e.g. mgga_xc_b98
    # uses lda_x_spin). The non-separable (*_nsp) wrappers genuinely
    # depend on the total density and are excluded by the word
    # boundaries.
    m = re.match(r'^(?:hyb_)?[^_]+_([^_]+)', params["functional"])
    component = m.group(1) if m else ""
    spin_scaled_wrappers = ["lda_x_spin", "lda_k_spin", "gga_exchange",
                            "gga_kinetic", "mgga_exchange", "mgga_kinetic"]
    params["spin_scaled"] = component in ("x", "k") and any(
      re.search(r'\b' + w + r'\b', contents) for w in spin_scaled_wrappers)

  return params

# the code starts here
params = maple2c_init()

from maple2c_lib.lda  import work_lda_exc, work_lda_vxc
from maple2c_lib.gga  import work_gga_exc, work_gga_vxc
from maple2c_lib.mgga import work_mgga_exc, work_mgga_vxc

if params["functype"] == "lda_exc":
  work_lda_exc(params)

elif params["functype"] == "lda_vxc":
  work_lda_vxc(params)

elif params["functype"] == "gga_exc":
  work_gga_exc(params)

elif params["functype"] == "gga_vxc":
  work_gga_vxc(params)

elif params["functype"] == "mgga_exc":
  work_mgga_exc(params)

elif params["functype"] == "mgga_vxc":
  work_mgga_vxc(params)
