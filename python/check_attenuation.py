"""
 2020 Susi Lehtola and Miguel A. L. Marques

   This script is used to check the convergence of the series
   expansions of the various attenuation functions, and to
   establish cutoff values for their series expansions.
"""


from libxc_codegen import *  # noqa: F401, F403

include('attenuation')
include('util')

# For exact results we use 1000 digit

exact_digits = Integer(1000)

# Double precision has 15 digits

double_digits = Integer(15)

# An acceptable relative error at double precision is 1e-13

error_thr = Float('1e-13')

@helper
def check_asymptotics(f, fname, a):
    # Grid spacing
    da = Float('0.01')
    # Maximum value of a
    amax = Integer(5)
    # First, we compare we find a point where to make the cutoff
    # Exact result
    # TODO(mpl2py): for acut from amax by -da to da do Digits := exact_digits
    exact = evalf(f(acut))
    # Double precision
    Digits = double_digits
    # Error
    Digits = exact_digits
    return #printf("Cutoff %e exact % e double % e error % e\n", acut, exact, doubleprec, err)
    return break_
    # TODO(mpl2py): end if
    # TODO(mpl2py): end do
    # Now we find the series expansion that has the same level of agreement
    # TODO(mpl2py): for expord from 4 to 1000 by 2 do f_series := a -> eval(throw_out_large_n(convert(series(f(b), b=infinity, expord+padding_order), polynom), expord), b=a)
    return #printf("Expansion order %3d original % e asymptotic % e error % " # "e\n", expord, exact, ser, err)
    # Check if the expansion is accurate everywhere
    return accurate := true
    # Exact result
    # TODO(mpl2py): for aval from acut by da to amax do Digits := exact_digits
    lexact = evalf(f(aval))
    # Double precision
    Digits = double_digits
    lser = evalf(f_series(aval))
    # Error
    return #printf("a= %e exact % e double % e error % e\n", aval, lexact, lser, lerr)
    return accurate := false
    # TODO(mpl2py): break
    # TODO(mpl2py): end if
    # TODO(mpl2py): end do
    return break_
    # TODO(mpl2py): end if
    # TODO(mpl2py): end if
    # TODO(mpl2py): end do
    return \n")
    return \n", fname, fname, acut, expord)

# TODO(mpl2py): printf("attenuation_erf\n"):

# TODO(mpl2py): check_asymptotics(attenuation_erf0, "attenuation_erf", a):

# TODO(mpl2py): printf("\nattenuation_erf_f2\n"):

# TODO(mpl2py): check_asymptotics(attenuation_erf_f20, "attenuation_erf_f2", a):

# TODO(mpl2py): printf("\nattenuation_erf_f3\n"):

# TODO(mpl2py): check_asymptotics(attenuation_erf_f30, "attenuation_erf_f3", a):

# TODO(mpl2py): printf("\nattenuation_gau\n"):

# TODO(mpl2py): check_asymptotics(attenuation_gau0, "attenuation_gau", a):

# TODO(mpl2py): printf("\nattenuation_yukawa\n"):

# TODO(mpl2py): check_asymptotics(attenuation_yukawa0, "attenuation_yukawa", a):
