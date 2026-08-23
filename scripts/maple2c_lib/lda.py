#!/usr/bin/env python3

# Copyright (C) 2021 M.A.L. Marques
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

from maple2c_lib.utils import *

# these are the variables that the functional depends on
variables = ["rho_0_", "rho_1_"]

# get arguments of the functions
input_args  = "const double *rho"
output_args = "xc_lda_out_params *out"
  
# the definition of the derivatives that libxc transmits to the calling program
partials = [
  ["zk"],
  ["vrho"],
  ["v2rho2"],
  ["v3rho3"],
  ["v4rho4"]
]

#####################################################################
def work_lda_exc(params):
  '''Process a LDA functional for the energy'''

  derivatives = partials_to_derivatives(params, "lda", partials)

  der_def, out_c = maple_define_derivatives(variables, derivatives, "mf")

  out_c = ", ".join(out_c)
  if out_c != "": out_c = ", " + out_c

  maple_zk = " zk_0_ = mzk(" + ", ".join(variables) + ")"

  if params.get("spin_density") and params.get("spin_scaled"):
    # Spin-density path for exchange / kinetic functionals. Each spin
    # channel is evaluated independently from its own same-spin
    # density, exploiting exact spin scaling: the energy density of a
    # channel is the functional evaluated at full spin polarization
    # (zeta = 1) with that channel's density. This avoids
    # reconstructing the spin densities from the total density and
    # spin polarization, which is ill-conditioned for small or
    # strongly polarized densities; cross-spin derivatives also become
    # structurally zero.
    maple_code = '''
# f_chan is the energy per unit volume of a single spin channel with
# spin density n_s, obtained by evaluating the functional at full spin
# polarization (zeta = 1).
f_chan := n_s -> {} n_s*f(r_ws(n_s), 1) {} :

$include <util.mpl>
'''.format(params["simplify_begin"], params["simplify_end"])

    # we build 2 variants of the functional, for unpolarized, and polarized densities
    variants = {
      "unpol": '''
# unpolarized: both channels carry half of the total density
mf   := (r0, r1) -> eval(2*f_chan(r0/2)):
mzk  := (r0, r1) -> eval(mf(r0, r1)/r0):

{}

{}
C([{}{}], optimize, deducetypes=false):

'''.format(der_def, maple_code, maple_zk, out_c),

      "pol": '''
# polarized: each channel is evaluated from its own spin density
mf   := (r0, r1) -> eval(f_chan(r0) + f_chan(r1)):
mzk  := (r0, r1) -> eval(mf(r0, r1)/(r0 + r1)):

{}

{}
C([{}{}], optimize, deducetypes=false):

'''.format(der_def, maple_code, maple_zk, out_c)
    }

    maple2c_run(params, variables, derivatives, variants, 0, input_args, output_args)
    return

  # we join all the pieces
  maple_code  = '''
# zk is energy per unit particle
mzk  := (r0, r1) -> \\
  {} + \\
    f(r_ws(dens(r0, r1)), zeta(r0, r1)) \\
  {} :

  (* mf is energy per unit volume *)
  mf   := (r0, r1) -> eval(dens(r0, r1)*mzk(r0, r1)):

$include <util.mpl>
'''.format(params["simplify_begin"], params["simplify_end"])

  # we build 2 variants of the functional, for unpolarized, and polarized densities
  variants = {
    "unpol": '''
dens := (r0, r1) -> r0:
zeta := (r0, r1) -> 0:

{}

{}
C([{}{}], optimize, deducetypes=false):

'''.format(der_def, maple_code, maple_zk, out_c),

    "pol": '''
dens := (r0, r1) -> r0 + r1:
zeta := (r0, r1) -> (r0 - r1)/(r0 + r1):

{}

{}
C([{}{}], optimize, deducetypes=false):

'''.format(der_def, maple_code, maple_zk, out_c)
  }

  maple2c_run(params, variables, derivatives, variants, 0, input_args, output_args)


#####################################################################
def work_lda_vxc(params):
  '''Process a LDA functional for the potential'''

  all_derivatives = partials_to_derivatives(params, "lda", partials)

  derivatives, derivatives1, derivatives2 = filter_vxc_derivatives(all_derivatives)
  
  # we obtain the missing pieces for maple
  # unpolarized calculation
  der_def_unpol, out_c_unpol = maple_define_derivatives(variables, derivatives1, "mf0")
  out_c_unpol = ", ".join(out_c_unpol)
  if out_c_unpol != "": out_c_unpol = ", " + out_c_unpol

  # polarized calculation
  der_def_pol1, out_c_pol1 = maple_define_derivatives(variables, derivatives1, "mf0")
  der_def_pol2, out_c_pol2 = maple_define_derivatives(variables, derivatives2, "mf1")
  
  der_def_pol = der_def_pol1 + der_def_pol2
  out_c_pol   = ", ".join(sorted(out_c_pol1 + out_c_pol2, key=sort_alphanumerically))
  if out_c_pol != "": out_c_pol = ", " + out_c_pol
  
  # we join all the pieces
  maple_code  = '''
mzk  := (r0, r1) -> \\
  {} + \\
    f(r_ws(dens(r0, r1)), zeta(r0, r1)) \\
  {} :

(* mf is the up potential *)
mf0   := (r0, r1) -> eval(mzk(r0, r1)):
mf1   := (r0, r1) -> eval(mzk(r1, r0)):

$include <util.mpl>
'''.format(params["simplify_begin"], params["simplify_end"])
  
  maple_vrho0 = " vrho_0_ = mf0(" + ", ".join(variables) + ")"
  maple_vrho1 = " vrho_1_ = mf1(" + ", ".join(variables) + ")"

  # we build 2 variants of the functional, for unpolarized, and polarized densities
  variants = {
    "unpol": '''
dens := (r0, r1) -> r0:
zeta := (r0, r1) -> 0:

{}

{}
C([{}{}], optimize, deducetypes=false):

'''.format(der_def_unpol, maple_code, maple_vrho0, out_c_unpol),

    "pol": '''
dens := (r0, r1) -> r0 + r1:
zeta := (r0, r1) -> (r0 - r1)/(r0 + r1):

{}

{}
C([{}, {}{}], optimize, deducetypes=false):

'''.format(der_def_pol, maple_code, maple_vrho0, maple_vrho1, out_c_pol)
  }

  maple2c_run(params, variables, derivatives, variants, 1, input_args, output_args)
