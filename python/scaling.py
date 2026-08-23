"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""


from libxc_codegen import *  # noqa: F401, F403

# no scaling

@helper
def s_scaling_0(s):
    return s

# original scaling of Heyd, eq (16) in J. Chem. Phys. 120, 7274
# (2004), doi:10.1063/1.1668634

strans = Float('8.3')

smax = Float('8.572844')

sconst = Float('18.79622316')

@helper
def s_scaling_1(s):
    return (
        my_piecewise3(
        s < strans, s,
        smax - sconst/s**Integer(2)
        )
    )

# first version of the scaling by TM Henderson, apparently used by Gaussian.
# eq (8) in J. Chem. Phys. 131, 044108 (2009); doi:10.1063/1.3185673

@helper
def s_scaling_2(s):
    return (
        my_piecewise3(
        s < Integer(1),  s,
        my_piecewise3(s > Integer(15), smax, m_max(m_min(s, Integer(15)), Integer(1)) - xc_log1p(exp(m_max(m_min(s, Integer(15)), Integer(1)) - smax)))
        )
    )

# second version of the scaling by TM Henderson,
# eq (9) in J. Chem. Phys. 131, 044108 (2009); doi:10.1063/1.3185673

@helper
def s_scaling_3(s):
    return s + xc_expm1(-s)*xc_log1p(exp(s - smax))

# appendix of JCP 128, 194105 (2008), doi:10.1063/1.2921797

s_p = maple_list([Float('0.615482'), Float('1.136921'), -Float('0.449154'), Float('0.0175739')*Float('8.572844')])

s_q = maple_list([Float('1.229195'), -Float('0.0269253'), Float('0.313417'), -Float('0.0508314'), Float('0.0175739')])

@helper
def s_scaling_4(s):
    return s*(Integer(1) + s**Integer(3)*sum((s_p[i]*s**i) for i in range(Integer(1), (Integer(4)) + Integer(1))))/(Integer(1) + s**Integer(3)*sum((s_q[i]*s**i) for i in range(Integer(1), (Integer(5)) + Integer(1))))
