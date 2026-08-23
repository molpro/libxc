"""
 Copyright (C) 2025 Angel Rosado, Mario Benites, Efstratios Manousakis

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

# ring-diagram series fit

@helper
def chip(z):
    return (Integer(1)+z)**(Integer(1)/Integer(3))

@helper
def chim(z):
    return (Integer(1)-z)**(Integer(1)/Integer(3))

@helper
def chi(z):
    return chip(z) + chim(z)

d0 = -Float('0.803')

@helper
def d1(z):
    return Float('0.8822') + Float('0.1648')*z**Integer(2) + Float('0.0432')*z**Integer(4)

@helper
def c0(z):
    return -Float('0.1423') + Float('0.0036')*z**Integer(2) + Float('0.1971')*(chi(z)-Integer(2)) - Float('0.0326')*(chi(z)**Integer(2)-Integer(4)) - Float('0.0177')*(chi(z)**Integer(3)-Integer(8))

# chip(z)^3 = 1+z and chim(z)^3 = 1-z, so the two log terms are
# (1+-z)*log(chi+-(z)/chi(z)); each is a bounded x*log(x)-type quantity whose
# limit is 0 at full polarization (z -> +-1), where chim/chip vanishes and the
# bare log diverges. Guard those two branches so they return the finite limit
# instead of 0*log(0) = NaN; my_piecewise3 is lazy, so the log is never
# evaluated in the excluded branch.

@helper
def cl(z):
    return (
        Integer(1)/(Integer(2)*pi**Integer(2))*(Integer(2) - log(Integer(4)) + chi(z)*chip(z)*chim(z)
        + my_piecewise3(Integer(1) + z <= p_a_zeta_threshold, Integer(0), (Integer(1)+z)*log(chip(z)/chi(z)))
        + my_piecewise3(Integer(1) - z <= p_a_zeta_threshold, Integer(0), (Integer(1)-z)*log(chim(z)/chi(z))))
    )

@helper
def a2(z):
    return Float('90.76') + Float('192.62')*(chi(z)-Integer(2)) - Float('3956.38')*(log(chi(z))/chi(z)-log(Integer(2))/Integer(2))

@helper
def b2(z):
    return Float('54.55') + Float('149.46')*(chi(z)-Integer(2)) - Float('2070.06')*(log(chi(z))/chi(z)-log(Integer(2))/Integer(2))

# b0(z) is the closed form fixed by the rs -> 0 constraints (Benites, Rosado &
# Manousakis, Phys. Rev. B 110, 195151 (2024), Eqs. (43)-(44) -> Eq. (48)).
# Its denominator 2*log(b2) - 1.75*log(a2) vanishes wherever b2(z) = a2(z)^(7/8),
# and the independently fitted a2(z), b2(z) (Eqs. (56)-(57)) cross that curve at
# z = 0.510437 and z = 0.998640. The numerator does not vanish there, so b0 --
# and hence a0 and epsilon_r -- have genuine, non-removable poles at those two
# polarizations, with b0 changing sign in between. This is a property of the
# published fit, reproduced faithfully here; it makes spin-polarized energies
# grid-dependent (non-convergent under radial quadrature) near those zeta.

@helper
def b0(z):
    return (Integer(2)*c0(z)+cl(z)*log(a2(z)))/(Integer(2)*log(b2(z))-Float('1.75')*log(a2(z)))

@helper
def a0(z):
    return -Float('0.5')*(cl(z)+Float('1.75')*b0(z))

@helper
def a1(z):
    return d1(z)/a2(z)

@helper
def b1(z):
    return d0/b2(z)

@helper
def epsilon_r(rs, z):
    return (a0(z)+a1(z)*rs)*log(Integer(1)+a2(z)/rs**Integer(2)) + (b0(z)+b1(z)*rs)*log(Integer(1)+b2(z)/rs**Float('1.75'))

# kite-diagram series fit

@helper
def AA0(z):
    return Float('0.04836')

@helper
def AA1(z):
    return Float('0.10215') - Float('0.05028')*z**Integer(2) - Float('0.01283')*z**Integer(4)

@helper
def AA2(z):
    return -Float('0.01382') + Float('0.00016')*z**Integer(2) + Float('0.00808')*z**Integer(4)

@helper
def AA3(z):
    return Float('0.46529') + Float('0.05868')*z**Integer(2) - Float('0.32923')*z**Integer(4)

@helper
def AA4(z):
    return Float('0.00364') - Float('0.00259')*z**Integer(2) - Float('0.00021')*z**Integer(4)

@helper
def epsilon_2b(rs, z):
    return AA0(z)/(Integer(1)+AA1(z)*rs) + AA2(z)*rs*log( Integer(1) + Integer(1)/(AA3(z)*rs+AA4(z)*rs**Float('1.5')) )

# dividing by two to convert from Rydberg to Hartree

def f(rs, z):
    return ( epsilon_r(rs, z) + epsilon_2b(rs, z) )/Integer(2)

TYPE = "lda_exc"
