"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

m_max = Symbol("m_max")
m_min = Symbol("m_min")
my_piecewise3 = Symbol("my_piecewise3")
ss = Symbol("ss")
st = Symbol("st")

include('scaling')

# parameters

wpbeh_A = Float('1.0161144')

wpbeh_B = -Float('0.37170836')

wpbeh_C = -Float('0.077215461')

wpbeh_D = Float('0.57786348')

# E is fixed by the requirement that EG is regular at s = 0, i.e.
# 3*Pi/4 + Ga(0) = 0 (else EG_orig carries a spurious ~epsilon/s^2 pole that
# the series branch drops, making the two branches disagree by that epsilon
# and the low-gradient junction discontinuous).  Solving Ga(0) = 0 for E:
# Ga(0) = sqrt(Pi)*(15 E + 6 C D + 4 B D^2 + 8 A D^3)/(16 D^(7/2))
# - 3*Pi/4*sqrt(A).
# The published float -0.051955731 satisfies this only to ~1.4e-8; compute it
# exactly instead (cf. Fc1/Fc2 below, likewise derived from A,B,C,D).

wpbeh_E = (Integer(12)*sqrt(pi)*(sqrt(wpbeh_A) - Integer(1))*wpbeh_D**(Integer(7)/Integer(2)) - (Integer(6)*wpbeh_C*wpbeh_D + Integer(4)*wpbeh_B*wpbeh_D**Integer(2) + Integer(8)*wpbeh_A*wpbeh_D**Integer(3)))/Integer(15)

#
# Note that kF has a 6 and not a 3 as it should in principle
# be. This is because the HSE formula, if one would take the papers
# seriously, does not fulfill the spin sum-rule. This is probably
# an oversight from them. So, we have to choose, either a 6 or a 3.
#
# Nwchem seems to have the factor of 6, but VASP and espresso have
# a 3. This would amount to rescaling omega by a factor of
# cbrt(2). We follow the quantum chemistry community and put the 6.

# Cutoff criterion below which to use polynomial expansion

EGscut = Float('0.08')

wcutoff = Integer(14)

expfcutoff = Integer(700)

# first let us calculate H(s)

wpbeh_Ha1 = Float('0.00979681')

wpbeh_Ha2 = Float('0.0410834')

wpbeh_Ha3 = Float('0.187440')

wpbeh_Ha4 = Float('0.00120824')

wpbeh_Ha5 = Float('0.0347188')

@helper
def wpbeh_H(s):
    return (
        + (wpbeh_Ha1*s**Integer(2) + wpbeh_Ha2*s**Integer(4))
        / (Integer(1) + wpbeh_Ha3*s**Integer(4) + wpbeh_Ha4*s**Integer(5) + wpbeh_Ha5*s**Integer(6))
    )

#
# Now we calculate F(s).  Fc1/Fc2 are determined by A,B,C,D; the published
# floats (6.4753871, 0.47965830) round them to ~6e-9 / ~8e-9, which enters EG
# at O(s^2) (its constant term) and, like the E rounding above, makes the
# low-gradient junction discontinuous.  Use the exact expressions.

wpbeh_Fc1 = Integer(4)*wpbeh_A**Integer(2)/(Integer(9)*wpbeh_C) + (wpbeh_B - wpbeh_A*wpbeh_D)/wpbeh_C

wpbeh_Fc2 = -Integer(4)/(Integer(3)*Integer(36)*wpbeh_C)

@helper
def wpbeh_F(s):
    return wpbeh_Fc1*wpbeh_H(s) + wpbeh_Fc2

# several auxiliary variables

@helper
def eb1(w):
    return my_piecewise3(w < wcutoff, Float('1.455915450052607'), Integer(2))

@helper
def aux1(s):
    return wpbeh_D + s**Integer(2)*wpbeh_H(s)

@helper
def aux2(s):
    return Integer(9)*wpbeh_H(s)*s**Integer(2)/(Integer(4)*wpbeh_A)

@helper
def aux3(w, s):
    return aux1(s) + w**Integer(2)

# aux4 -> 0 only when both s -> 0 and w -> 0 (the omega=0 / PBEh
# default at vanishing gradient).  There term1's t1 (~ +A/2 E1_scaled(aux5),
# aux5 ~ aux4) and t10 (~ -A/2 log(aux4/aux6)) each diverge like
# log(aux4); their sum is finite (the log(aux4) cancels), but evaluated
# separately they are +inf and -inf -> inf-inf = NaN / -inf.  Floor aux4
# (as the sibling gga_x_hjs floors its zeta): the floor passes
# identically through aux5 and aux6, so the cancellation is preserved and
# the finite limit is recovered.

@helper
def aux4(w, s):
    return m_max(s**Integer(2)*wpbeh_H(s) + eb1(w)*w**Integer(2), xc_reduced_floor)

@helper
def aux5(w, s):
    return Integer(9)*aux4(w, s)/(Integer(4)*wpbeh_A)

@helper
def aux6(w, s):
    return wpbeh_D + aux4(w, s)

# and now G(s)

# exp(aux2)*(1 - erf(sqrt(aux2))) = exp(u^2)*erfc(u) = erfcx(u)
# with u = sqrt(aux2); xc_erfcx is the scaled complementary erf,
# so it avoids both the 1 - erf cancellation at large u and the
# exp(u^2) overflow.

@helper
def Ga(s):
    return (
        + sqrt(pi)*(
        + Integer(15)*wpbeh_E
        + Integer(6)*wpbeh_C*(Integer(1) + wpbeh_F(s)*s**Integer(2))*aux1(s)
        + Integer(4)*wpbeh_B*aux1(s)**Integer(2)
        + Integer(8)*wpbeh_A*aux1(s)**Integer(3))
        / (Integer(16)*aux1(s)**(Integer(7)/Integer(2)))
        - (Integer(3)*pi/Integer(4))*sqrt(wpbeh_A)*xc_erfcx(sqrt(aux2(s)))
    )

@helper
def Gb(s):
    return Integer(15)*sqrt(pi)*s**Integer(2)/(Integer(16)*aux1(s)**(Integer(7)/Integer(2)))

@helper
def wpbeh_EG_orig(s):
    return -(Integer(3)*pi/Integer(4) + Ga(s))/Gb(s)

# The exact EG is 0/0 as s -> 0: Gb ~ s^2/aux1^(7/2) -> 0 while
# (3*Pi/4 + Ga) -> 0 too (Ga -> -3*Pi/4), so evaluating it directly at
# small s suffers catastrophic cancellation and division by a vanishing
# Gb.  Below EGscut use its small-s Taylor expansion instead -- generated
# here by the Maple pipeline straight from the exact expression rather
# than hard-coded coefficients:
# - to_elementary makes xc_erfcx native so series() can resolve the
# removable s^(-2) singularity;
# - csgn=1 removes the csgn(s^2) that series() emits because it will
# not assume the reduced gradient s >= 0 (sqrt(s^2) = |s|);
# - the parameters are floats, so the limit identity (3*Pi/4+Ga)|_0 = 0
# only holds to ~1e-9 and series() leaves a spurious ~1e-9/s^2
# principal part; keep only the non-negative powers (the true
# expansion is regular at s = 0).

@helper
def wpbeh_EG_poly(s):
    P = convert(maple_eval(maple_series(to_elementary(wpbeh_EG_orig(st)), st, Integer(0), Integer(24)), csgn, Integer(1)), polynom)
    return maple_eval(sum((coeff(P, st, k)*st**k) for k in range(Integer(0), (Integer(22)) + Integer(1))), st, s)

# Clamp each branch's argument so the exact form is never evaluated
# below EGscut (its 0/0 region) nor the polynomial far above it.

@helper
def wpbeh_EG(s):
    return (
        my_piecewise3(s > EGscut,
        wpbeh_EG_orig(m_max(s, EGscut)),
        wpbeh_EG_poly(m_min(s, EGscut))
        )
    )

@helper
def term2(s):
    return (
        (
        + aux1(s)**Integer(2)*wpbeh_B
        + aux1(s)*wpbeh_C
        + Integer(2)*wpbeh_E
        + aux1(s)*s**Integer(2)*wpbeh_C*wpbeh_F(s)
        + Integer(2)*s**Integer(2)*wpbeh_EG(s)
        )/(Integer(2)*aux1(s)**Integer(3))
    )

@helper
def term3(w, s):
    return (
        -w*(
        + Integer(4)*aux3(w, s)**Integer(2)*wpbeh_B
        + Integer(6)*aux3(w, s)*wpbeh_C
        + Integer(15)*wpbeh_E
        + Integer(6)*aux3(w, s)*s**Integer(2)*wpbeh_C*wpbeh_F(s)
        + Integer(15)*s**Integer(2)*wpbeh_EG(s)
        )/(Integer(8)*aux1(s)*aux3(w, s)**(Integer(5)/Integer(2)))
    )

@helper
def term4(w, s):
    return (
        -w**Integer(3)*(
        + aux3(w, s)*wpbeh_C
        + Integer(5)*wpbeh_E
        + aux3(w, s)*s**Integer(2)*wpbeh_C*wpbeh_F(s)
        + Integer(5)*s**Integer(2)*wpbeh_EG(s)
        )/(Integer(2)*aux1(s)**Integer(2)*aux3(w, s)**(Integer(5)/Integer(2)))
    )

@helper
def term5(w, s):
    return (
        -w**Integer(5)*(
        + wpbeh_E
        + s**Integer(2)*wpbeh_EG(s)
        )/(aux1(s)**Integer(3)*aux3(w, s)**(Integer(5)/Integer(2)))
    )

# --- small-s stabilisation of the rational (aux1-based) terms ---
# For s -> 0, aux1 = D + s^2 H(s) rounds to D in double precision
# (s^2 H ~ 1e-31 is lost against D ~ 0.58), so the (aux1 - D) = s^2 H
# factors generated in the second derivatives of term2..term5 collapse
# to 0/0 -> NaN.  This is the HSE03/HSE06 v2sigma2 / v2rhosigma blow-up
# at small gradient and the long-standing low-sigma crash.
#
# term2..term5 are rational in s (EG via its polynomial branch, valid
# below EGscut), so the small-s expansion is an exact, convergent
# Taylor series (the nearest pole, aux1 = 0, sits at |s| ~ sqrt(D/Ha1)
# ~ 7.7, so it converges geometrically).  Maple generates it from the
# explicit-EG-polynomial form; term1 carries the erfcx/E1
# transcendentals but stays smooth in s^2 and is left direct.

@helper
def term2345(w, s):
    return term2(s) + term3(w, s) + term4(w, s) + term5(w, s)

# series() cannot expand a my_piecewise3, and term2345 carries one
# through wpbeh_EG (plus the m_max/m_min clamps).  Below the cutoff EG
# is its polynomial branch, so collapse my_piecewise3 to that branch and
# the clamps to the identity, leaving a clean rational whose Taylor
# series is exact.  (wpbeh_EG is the only piecewise inside term2345.)

@helper
def term2345_series(w, s):
    return maple_eval(convert(maple_series(maple_eval(term2345(w, ss), my_piecewise3, (lambda c, a, b: b), m_min, (lambda a, b: a), m_max, (lambda a, b: a)), ss, Integer(0), Integer(24)), polynom), ss, s)

# Glue: series below the cutoff, original above it; the m_max/m_min
# clamps keep the unselected branch finite (cf. enforce_smooth_lr).
# The series is an order-24 Taylor polynomial about s = 0; its truncation
# error grows as ~(s/0.7)^23, so it is accurate to machine precision only for
# s below ~0.14 (4e-4 by s = 0.5).  The original is accurate everywhere the
# value is concerned, so the junction belongs as low as the series is still
# exact: 0.13.  With E/Fc1/Fc2 computed exactly (above) EG_poly = EG_orig to
# machine precision, so at 0.13 both branches agree to XC_EPSILON and the hard
# switch is continuous -- no blend needed.  (Above ~0.14 the series has drifted
# away, which was the discontinuity when the cutoff sat at 0.5.)

wpbeh_scut = Float('0.13')

@helper
def term2345_smooth(w, s):
    return (
        my_piecewise3(s >= wpbeh_scut,
        term2345(w, m_max(s, wpbeh_scut)),
        term2345_series(w, m_min(s, wpbeh_scut)))
    )

# aux4 - aux6 = -D (since aux6 = D + aux4), so at large w both
# saturate to eb1*w^2 and aux4/aux6 -> 1.  Route through xc_log1p
# with the subtraction written symbolically against the helpers so
# the polynomials stay single-source -- Maple simplifies away the
# matching aux4 terms before codegen, so the emitted C is
# cancellation-free and any future retuning of aux6 flows through
# automatically.

@helper
def t10(w, s):
    return Integer(1)/Integer(2)*wpbeh_A*xc_log1p((aux4(w, s) - aux6(w, s))/aux6(w, s))

# Use simple gaussian approximation for large w

@helper
def term1_largew(w, s):
    return (
        -Integer(1)/Integer(2)*wpbeh_A*(-xc_E1_scaled(aux5(w, s))
        + xc_log1p((aux6(w, s) - aux4(w, s))/aux4(w, s)))
    )

# For everything else use the full blown expression

ea1 = -Float('1.128223946706117')

ea2 = Float('1.452736265762971')

ea3 = -Float('1.243162299390327')

ea4 = Float('0.971824836115601')

ea5 = -Float('0.568861079687373')

ea6 = Float('0.246880514820192')

ea7 = -Float('0.065032363850763')

ea8 = Float('0.008401793031216')

@helper
def np1(w):
    return (
        - Float('1.5')*ea1*sqrt(wpbeh_A)*w
        + Integer(27)*ea3*w**Integer(3)/(Integer(8)*sqrt(wpbeh_A))
        - Integer(243)*ea5*w**Integer(5)/(Integer(32)*(wpbeh_A)**(Integer(3)/Integer(2)))
        + Integer(2187)*ea7*w**Integer(7)/(Integer(128)*(wpbeh_A)**(Integer(5)/Integer(2)))
    )

@helper
def np2(w):
    return (
        - wpbeh_A
        + Integer(9)*ea2*w**Integer(2)/Float('4.0')
        - Integer(81)*ea4*w**Integer(4)/(Integer(16)*wpbeh_A)
        + Integer(729)*ea6*w**Integer(6)/(Integer(64)*wpbeh_A**Integer(2))
        - Integer(6561)*ea8*w**Integer(8)/(Integer(256)*wpbeh_A**Integer(3))
    )

@helper
def t1(w, s):
    return Integer(1)/Integer(2)*(np1(w)*pi*xc_erfcx(sqrt(aux5(w, s))) - np2(w)*xc_E1_scaled(aux5(w, s)))

@helper
def f2(w, s):
    return Integer(1)/Integer(2)*ea1*sqrt(pi)*wpbeh_A/sqrt(aux6(w, s))

@helper
def f3(w, s):
    return Integer(1)/Integer(2)*ea2*wpbeh_A/aux6(w, s)

@helper
def f4(w, s):
    return ea3*sqrt(pi)*(-Integer(9)/(Integer(8)*sqrt(aux4(w, s))) + Float('0.25')*wpbeh_A/aux6(w, s)**(Integer(3)/Integer(2)))

@helper
def f5(w, s):
    return (ea4/Integer(128))*(-Integer(144)/aux4(w, s) + Integer(64)*wpbeh_A/aux6(w, s)**Integer(2))

@helper
def f6(w, s):
    return (
        ea5*(Integer(3)*sqrt(pi)*(Integer(3)*aux6(w, s)**(Integer(5)/Integer(2))*(Integer(9)*aux4(w, s) - Integer(2)*wpbeh_A)
        + Integer(4)*aux4(w, s)**(Integer(3)/Integer(2))*wpbeh_A**Integer(2)))/(Integer(32)*aux6(w, s)**(Integer(5)/Integer(2))*aux4(w, s)**(Integer(3)/Integer(2))*wpbeh_A)
    )

@helper
def f7(w, s):
    return ea6*((Integer(32)*wpbeh_A/aux6(w, s)**Integer(3) + (-Integer(36) + Integer(81)*s**Integer(2)*wpbeh_H(s)/wpbeh_A)/aux4(w, s)**Integer(2)))/Integer(32)

@helper
def f8(w, s):
    return (
        ea7*(-Integer(3)*sqrt(pi)*(-Integer(40)*aux4(w, s)**(Integer(5)/Integer(2))*wpbeh_A**Integer(3)
        + Integer(9)*aux6(w, s)**(Integer(7)/Integer(2))*(Integer(27)*aux4(w, s)**Integer(2) - Integer(6)*aux4(w, s)*wpbeh_A + Integer(4)*wpbeh_A**Integer(2))))
        /(Integer(128)*aux6(w, s)**(Integer(7)/Integer(2))*aux4(w, s)**(Integer(5)/Integer(2))*wpbeh_A**Integer(2))
    )

@helper
def f9(w, s):
    return (
        (
        + Integer(324)*ea6*eb1(w)*aux6(w, s)**Integer(4)*aux4(w, s)*wpbeh_A
        + ea8*(Integer(384)*aux4(w, s)**Integer(3)*wpbeh_A**Integer(3)
        + aux6(w, s)**Integer(4)*(-Integer(729)*aux4(w, s)**Integer(2) + Integer(324)*aux4(w, s)*wpbeh_A - Integer(288)*wpbeh_A**Integer(2)))
        )/(Integer(128)*aux6(w, s)**Integer(4)*aux4(w, s)**Integer(3)*wpbeh_A**Integer(2))
    )

@helper
def t2t9(w, s):
    return (
        + f2(w, s)*w + f3(w, s)*w**Integer(2) + f4(w, s)*w**Integer(3) + f5(w, s)*w**Integer(4)
        + f6(w, s)*w**Integer(5) + f7(w, s)*w**Integer(6) + f8(w, s)*w**Integer(7) + f9(w, s)*w**Integer(8)
    )

@helper
def term1(w, s):
    return (
        my_piecewise3(
        w > wcutoff, term1_largew(w, s),
        t1(m_min(w, wcutoff), s) + t2t9(m_min(w, wcutoff), s) + t10(m_min(w, wcutoff), s)
        )
    )

@helper
def f_wpbeh0(w, s):
    return (
        - Integer(8)/Integer(9) *(
        term1(w, s) + term2345_smooth(w, s)
        )
    )

@helper
def f_wpbeh(rs, z, x):
    return f_wpbeh0(nu(rs, z), m_max(Float('1e-15'), s_scaling_2(gga_s(x))))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange_nsp(f_wpbeh, rs, z, xs0, xs1)

TYPE = "gga_exc"
