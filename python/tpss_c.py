"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""


from libxc_codegen import *  # noqa: F401, F403

params_a_C0_c = param_default("C0_c")
params_a_d = param_default("d")

# Equation 28 squared with Equation 25 built in

@helper
def tpss_xi2(z, xt, xs0, xs1):
    return one_minus_z_pow_n(z, Integer(2))*(t_total(z, xs0**Integer(2), xs1**Integer(2)) - xt**Integer(2))/(Integer(2)*(Integer(3)*pi**Integer(2))**(Integer(1)/Integer(3)))**Integer(2)

# Equation 33

@helper
def tpss_C00(cc, z):
    return + sum((cc[i]*z**(Integer(2)*(i-Integer(1)))) for i in range(Integer(1), (Integer(4)) + Integer(1)))

# Equation 34

# The series expansion of C0 for z -> +- 1 goes as C + D*(1+-z)^(2/3) + O(1+-z)
# whose first derivative seems to diverge for ferromagnetic densities, leading
# to severe numerical instabilities. I can not correct for the bad design of
# the functional, and this is the possible solution that I found

@helper
def tpss_C0_den(z, xt, xs0, xs1):
    return Integer(1) + tpss_xi2(z, xt, xs0, xs1)*(opz_pow_n(z, -Integer(4)/Integer(3)) + opz_pow_n(-z, -Integer(4)/Integer(3)))/Integer(2)

@helper
def tpss_C0(cc, z, xt, xs0, xs1):
    return (
        my_piecewise3(Integer(1) - m_abs(z) <= Float('1e-12'),
        sum((cc[i]) for i in range(Integer(1), (Integer(4)) + Integer(1))),
        tpss_C00(cc, z) / tpss_C0_den(z_thr(z), xt, xs0, xs1)**Integer(4))
    )

# Equation 11, with tau_W from Equation 12

@helper
def tpss_aux(z, xt, ts0, ts1):
    return m_min(xt**Integer(2)/(Integer(8)*t_total(z, ts0, ts1)), Integer(1))

# Max of two GGA-correlation values, taking the two RESULTS as scalar params.
# Keeping the f_gga > f_gga comparison on va/vb inside this helper (rather than
# as a kernel piecewise condition over two large inlined f_gga bodies) avoids
# inlining f_gga into a condition -- which otherwise explodes simplify_conditions'
# cancel (987 -> 1.17M ops) and bloats the generated C.

@helper
def tpss_fmax(va, vb):
    return m_max(va, vb)

# n_sigma/n \epsilon^sigma in Equation 25

@helper
def tpss_par_s0(f_gga, rs, z, xt, xs0, xs1):
    return tpss_fmax(f_gga(rs*(Integer(2)/(Integer(1) + z))**(Integer(1)/Integer(3)),  Integer(1), xs0, xs0, Integer(0)), f_gga(rs, z, xt, xs0, xs1))*(Integer(1) + z)/Integer(2)

@helper
def tpss_par_s1(f_gga, rs, z, xt, xs0, xs1):
    return tpss_fmax(f_gga(rs*(Integer(2)/(Integer(1) - z))**(Integer(1)/Integer(3)), -Integer(1), xs1, Integer(0), xs1), f_gga(rs, z, xt, xs0, xs1))*(Integer(1) - z)/Integer(2)

# Second line of Equation 25

# The screening of the density is important in order to stabilize this functional
# for ferromagnetic densities

@helper
def tpss_par(f_gga, rs, z, xt, xs0, xs1, ts0, ts1):
    return (
        - (Integer(1) + tpss_C0(params_a_C0_c, z, xt, xs0, xs1))*tpss_aux(z, xt, ts0, ts1)**Integer(2)*(
        + my_piecewise3(screen_dens_zeta(rs,  z),
        f_gga(rs, z_thr(z), xt, xs0, xs1)*(Integer(1) + z)/Integer(2),
        tpss_par_s0(f_gga, rs, z_thr(z), xt, xs0, xs1)
        )
        + my_piecewise3(screen_dens_zeta(rs, -z),
        f_gga(rs, z_thr(z), xt, xs0, xs1)*(Integer(1) - z)/Integer(2),
        tpss_par_s1(f_gga, rs, z_thr(z), xt, xs0, xs1)
        )
        )
    )

# First line of Equation 25

@helper
def tpss_perp(f_gga, rs, z, xt, xs0, xs1, ts0, ts1):
    return (
        (Integer(1) + tpss_C0(params_a_C0_c, z, xt, xs0, xs1)*tpss_aux(z, xt, ts0, ts1)**Integer(2))
        * f_gga(rs, z, xt, xs0, xs1)
    )

# Equation in full 25

@helper
def tpss_f0(f_gga, rs, z, xt, xs0, xs1, ts0, ts1):
    return (
        + tpss_par (f_gga, rs, z, xt, xs0, xs1, ts0, ts1)
        + tpss_perp(f_gga, rs, z, xt, xs0, xs1, ts0, ts1)
    )

# Equation 24

@helper
def tpss_f(f_gga, rs, z, xt, xs0, xs1, ts0, ts1):
    return (
        + tpss_f0(f_gga, rs, z, xt, xs0, xs1, ts0, ts1)
        * (Integer(1) + params_a_d*tpss_f0(f_gga, rs, z, xt, xs0, xs1, ts0, ts1)*tpss_aux(z, xt, ts0, ts1)**Integer(3))
    )
