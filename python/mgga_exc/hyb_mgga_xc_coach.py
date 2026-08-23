"""
 Copyright (C) 2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

# COACH range-separated hybrid meta-GGA of Liang and Head-Gordon.
#
# E_x = E_x^{SL,sr} + c_x,sr * E_x,sr^HF + c_x,lr * E_x,lr^HF
# E_c = E_c,ss^SL  + E_c,os^SL                (+ VV10, + external D4-ATM)
#
# The Hartree-Fock pieces and the range separation are handled through
# the CAM machinery (c_x,lr = cam_alpha, c_x,sr = cam_alpha + cam_beta,
# omega = cam_omega); D4-ATM is an external dispersion correction that
# is outside the scope of libxc.  Here we implement the semi-local part:
#
# - short-range LDA exchange (erf attenuation) times a B97-type fitting
# factor g_x that is Legendre in v = 2 beta - 1 and monomial in u_x;
# - same-spin / opposite-spin correlation built on the SCAN alpha = 1
# (revised-PBE-like) base energy density via a Stoll decomposition,
# with a 2 beta self-correlation-correction factor on the same-spin
# part.

# short-range LDA exchange; uses p_a_cam_omega for the attenuation.
include('lda_x_erf')

# SCAN alpha = 1 correlation building blocks: f_pw (PW92), mphi, mgamma,
# tt (SCAN reduced gradient t), and A with the Hu-Langreth rs-dependent
# beta, all pulled in through the regTPSS chain.
include('gga_c_scan_e0')

# Legendre polynomials P_n on [-1, 1] via the orthopoly package (the
# same way mbeef / beefvdw pull theirs in).
# with(orthopoly)

# ----- nonlinearity parameters -----

coach_gamma_x = Float('0.004')

coach_gamma_ss = Float('0.01')

coach_gamma_os = Float('0.006')

# SCAN non-uniform-scaling-correction (NUSC) factor on exchange,
# g_x(s) = 1 - exp(-a1 s^(-1/2)) with a1 = 13.815 and s = xs (eq. 33).
# This multiplies the SR-LDA exchange enhancement to enforce the
# non-uniform density-scaling constraint; it suppresses exchange in the
# large-gradient (low-density) tails.  Uses the guarded, cancellation-
# free m_one_minus_recexp (1 - exp(-1/x)) with x = sqrt(xs)/a1, so
# 1/x = a1/sqrt(xs).  The outer sqrt gives dx/dxs = 1/(2 a1 sqrt(xs)) ->
# infinity at xs = 0 (empty channel at full polarization), leaking
# 0*infinity into fxc.  mgga_exchange_erf fixes the LDA-base spin scaling
# but not this enhancement-side singularity, so floor xs at xc_reduced_floor
# here (verified: dropping it reintroduces the full-polarization fxc NaN).

@helper
def coach_nusc(xs):
    return m_one_minus_recexp(sqrt(m_max(xs, xc_reduced_floor))/Float('13.815'))

# iso-orbital indicator beta = (tau - tau_W)/(tau + tau_UEG).  libxc
# uses the tau = (1/2) sum |grad phi|^2 convention, so in the reduced
# variables of work_mgga (ts = tau_sigma/rho_sigma^(5/3)) we have
# tau_W/rho_sigma^(5/3) = xs^2/8 and tau_UEG/rho_sigma^(5/3) =
# K_FACTOR_C.  (The paper's eqs. 16-17 use the factor-of-two larger
# tau = sum |grad phi|^2 convention, but beta is invariant since the
# factor cancels between numerator and denominator.)  With the work_mgga
# sigma clamp xs^2 <= 8 ts this keeps beta in [0, 1) and hence
# v = 2 beta - 1 in [-1, 1), where the Legendre expansion is well
# behaved.

# coach_beta/coach_v take the SQUARED reduced gradient xs2 = xs^2, so the
# opaque fitting helpers below are rational in sigma (see maple/util.mpl
# b97_u, t_vw): the sigma-derivatives never chain through sqrt(sigma).

@helper
def coach_beta(xs2, ts):
    return (ts - xs2/Integer(8))/(ts + K_FACTOR_C)

@helper
def coach_v(xs2, ts):
    return Integer(2)*coach_beta(xs2, ts) - Integer(1)

# SCAN alpha = 1 (revised-PBE-like) correlation energy per particle.
# H1 = gamma phi^3 log(1 + w1 (1 - g(A t^2))), g = (1 + 4 A t^2)^(-1/4),
# w1 = exp(-eps_c^LSDA/(gamma phi^3)) - 1, A = beta(rs)/(gamma w1).
# A, tt, mphi, mgamma, f_pw come from the include chain; the gradient
# enters through the SCAN reduced gradient inside tt(rs, z, xt).  The
# 1 - g and w1 terms are written through expm1/log1p.

@helper
def coach_w1(rs, z):
    return xc_expm1(-f_pw(rs, z)/(mgamma*mphi(z)**Integer(3)))

@helper
def coach_H1(rs, z, t):
    return mgamma*mphi(z)**Integer(3)*xc_log1p(coach_w1(rs, z)*scan_e0_one_minus_g(rs, z, t))

@helper
def coach_ec1(rs, z, xt, xs0, xs1):
    return f_pw(rs, z) + coach_H1(rs, z, tt(rs, z, xt))

# ----- nonzero expansion coefficients [c_ij, i, j] -----

# exchange: i = Legendre order in v, j = monomial order in u

coach_cx = maple_list([ maple_list([  Float('0.7080650005052257'),    Integer(0),  Integer(0)]), maple_list([  Float('5.973423554868972'),    Integer(0),  Integer(2)]), maple_list([-Float('17.33477136180401'),      Integer(0),  Integer(3)]), maple_list([ Float('25.0'),                  Integer(0),  Integer(5)]), maple_list([-Float('13.303231846931668'),     Integer(0),  Integer(7)]), maple_list([ -Float('0.20577489944575586'),  Integer(1),  Integer(0)]), maple_list([ -Float('0.10779574940300828'),   Integer(2),  Integer(0)]), maple_list([  Float('5.491317004106042'),    Integer(2),  Integer(2)]), maple_list([ -Float('6.658515516611359'),     Integer(2),  Integer(3)]), maple_list([  Float('1.839797240566924'),    Integer(3),  Integer(1)]), maple_list([ -Float('7.509521330876057'),     Integer(3),  Integer(2)]), maple_list([ Float('18.654513589197446'),    Integer(3),  Integer(3)]), maple_list([-Float('12.139029019506687'),     Integer(3),  Integer(4)]), maple_list([  Float('0.20195969717314624'),  Integer(4),  Integer(0)]), maple_list([  Float('0.2600717991008879'),    Integer(5),  Integer(0)]), maple_list([ -Float('3.463397249605392'),    Integer(5),  Integer(2)]), maple_list([  Float('3.75514691066743'),      Integer(5),  Integer(3)]), maple_list([  Float('0.2402820743898442'),   Integer(6),  Integer(0)]), maple_list([ -Float('0.8660852096125707'),    Integer(6),  Integer(1)]), maple_list([  Float('0.10480172805257999'),  Integer(7),  Integer(0)]), maple_list([ -Float('0.5657722952687481'),    Integer(7),  Integer(1)]), maple_list([ -Float('0.43586821950068677'),  Integer(8),  Integer(1)]), maple_list([  Float('0.9891478454228174'),    Integer(8),  Integer(4)]), maple_list([ -Float('0.09350557083826855'),  Integer(9),  Integer(0)]), maple_list([  Float('0.2557276229171211'),    Integer(9),  Integer(1)]), maple_list([ -Float('0.7171538898115716'),   Integer(9),  Integer(2)]), maple_list([ -Float('0.034948386270515386'), Integer(10),  Integer(0)]), maple_list([ -Float('0.03464312342837082'), Integer(11),  Integer(0)]), maple_list([  Float('0.20050993281346377'),  Integer(11),  Integer(1)]), maple_list([ -Float('0.3773473250434576'),  Integer(11),  Integer(2)]) ])

coach_nx = Integer(30)

# same-spin: i = Legendre order in v, j = monomial order in u

coach_css = maple_list([ maple_list([ -Float('0.3039405655250467'),    Integer(0),  Integer(0)]), maple_list([ -Float('1.2900096158738523'),   Integer(0),  Integer(1)]), maple_list([ Float('17.715459474491766'),     Integer(0),  Integer(4)]), maple_list([-Float('13.929080028872658'),    Integer(0),  Integer(7)]), maple_list([ -Float('1.8711635396581212'),    Integer(1),  Integer(0)]), maple_list([-Float('10.122833804966692'),    Integer(1),  Integer(1)]), maple_list([ Float('22.05988705553151'),      Integer(1),  Integer(2)]), maple_list([ -Float('1.8278556540465263'),   Integer(2),  Integer(0)]), maple_list([  Float('6.994998018578696'),     Integer(2),  Integer(1)]), maple_list([ -Float('8.349141007699943'),    Integer(2),  Integer(4)]), maple_list([ -Float('2.226676731002602'),     Integer(3),  Integer(1)]), maple_list([ -Float('2.7311170048590196'),   Integer(3),  Integer(2)]), maple_list([ -Float('1.4633617968363573'),    Integer(5),  Integer(0)]), maple_list([ -Float('0.8348281349925031'),   Integer(7),  Integer(0)]), maple_list([  Float('0.4818154118907339'),    Integer(8),  Integer(0)]), maple_list([ -Float('3.3444231176840256'),   Integer(8),  Integer(1)]), maple_list([  Float('6.986341349369924'),     Integer(8),  Integer(2)]), maple_list([ Float('14.980984577715752'),    Integer(8),  Integer(3)]), maple_list([-Float('25.0'),                   Integer(8),  Integer(4)]), maple_list([  Float('1.5676639733349753'),  Integer(11),  Integer(3)]) ])

coach_nss = Integer(20)

# opposite-spin: i = Legendre order in w, j = Legendre order in u

coach_cos = maple_list([ maple_list([  Float('2.0330833570991405'),    Integer(0),  Integer(0)]), maple_list([ -Float('3.071472897617402'),    Integer(0),  Integer(5)]), maple_list([ -Float('1.9671740896453935'),    Integer(0),  Integer(7)]), maple_list([ -Float('3.124170248419258'),    Integer(1),  Integer(0)]), maple_list([  Float('7.594716450411337'),     Integer(1),  Integer(1)]), maple_list([  Float('4.618674090063557'),    Integer(2),  Integer(4)]), maple_list([  Float('2.572431599509026'),     Integer(3),  Integer(7)]), maple_list([ -Float('1.120055362237976'),    Integer(4),  Integer(4)]), maple_list([ -Float('2.5762282779751264'),    Integer(4),  Integer(7)]), maple_list([ -Float('1.4299548850828665'),   Integer(5),  Integer(1)]), maple_list([-Float('20.76844377770899'),      Integer(5),  Integer(4)]), maple_list([ Float('25.0'),                  Integer(5),  Integer(5)]), maple_list([-Float('22.533887529213906'),     Integer(5),  Integer(6)]), maple_list([  Float('9.590467389102345'),    Integer(5),  Integer(7)]), maple_list([  Float('4.4188486804036184'),    Integer(6),  Integer(4)]), maple_list([  Float('4.293474773028771'),    Integer(8),  Integer(4)]), maple_list([ -Float('1.5286479621022213'),    Integer(9),  Integer(2)]), maple_list([  Float('2.3555422987546892'),   Integer(9),  Integer(7)]), maple_list([  Float('0.7896380110221484'),   Integer(10),  Integer(0)]), maple_list([ -Float('1.9225815901087469'),  Integer(10),  Integer(3)]), maple_list([  Float('2.229310613916473'),    Integer(11),  Integer(1)]), maple_list([ -Float('1.5811003317333285'),  Integer(11),  Integer(6)]), maple_list([  Float('1.1456216634190832'),   Integer(11),  Integer(7)]) ])

coach_nos = Integer(23)

# ----- fitting factors -----

# exchange / same-spin: Legendre in v, monomial in u

@helper
def coach_g_lv(mgamma, cc, n, xs2, ts):
    return sum((cc[i][Integer(1)]*legendre(cc[i][Integer(2)], coach_v(xs2, ts))*b97_u(mgamma, xs2)**cc[i][Integer(3)]) for i in range(Integer(1), (n) + Integer(1)))

# opposite-spin reduced gradient u_ab from s_ab^2 = (s_a^2 + s_b^2)/2;
# takes the SQUARED per-spin reduced gradients xs02 = xs0^2, xs12 = xs1^2

@helper
def coach_uos(xs02, xs12):
    return coach_gamma_os*(xs02 + xs12)/Integer(2)/(Integer(1) + coach_gamma_os*(xs02 + xs12)/Integer(2))

# opposite-spin kinetic variable w = (t_ab - 1)/(t_ab + 1),
# t_ab = (t_a + t_b)/2, t_sigma = tau_sigma^UEG/tau_sigma = K/ts (the
# ratio is convention-independent).  This coincides with wB97M-V's wx_os.
#
# wos is bounded in [-1, 1], but the naive rational form
# (K*(ts0+ts1) - 2*ts0*ts1)/(K*(ts0+ts1) + 2*ts0*ts1)
# has numerator and denominator that both scale as ts0*ts1.  When the
# Legendre polynomials P(n, wos) raise this to a power, the code
# generator distributes the exponent over the quotient, computing the
# numerator and denominator powers separately; for a large reduced tau
# (ts ~ 1e26, e.g. a tiny density with a huge kinetic energy density)
# ts0*ts1 ~ 1e52 and its high powers overflow the double range, giving
# inf/inf = NaN even though wos itself is ~ -1.
#
# Rewrite it via the per-spin bounded quantities
# p_i = ts_i/(K + ts_i)   in [0, 1),
# w_i = (K - ts_i)/(K + ts_i) in (-1, 1],
# so that wos = (p0*w1 + p1*w0)/(p0 + p1), with the base of every power
# now O(1).  Algebraically identical, but overflow-free.

@helper
def coach_p(t):
    return t/(K_FACTOR_C + t)

@helper
def coach_wos(ts0, ts1):
    return (
        (coach_p(ts0)*mgga_w(ts1) + coach_p(ts1)*mgga_w(ts0))
        /(coach_p(ts0) + coach_p(ts1))
    )

@helper
def coach_g_os(cc, n, ts0, ts1, xs02, xs12):
    return (
        sum((cc[i][Integer(1)]*legendre(cc[i][Integer(2)], coach_wos(ts0, ts1))
        *legendre(cc[i][Integer(3)], coach_uos(xs02, xs12))) for i in range(Integer(1), (n) + Integer(1)))
    )

# ----- exchange: short-range LDA exchange (spin-scaled via mgga_exchange_erf)
# times the B97-type g_x and the NUSC factor -----

@helper
def coach_fx_enh(xs, u, ts):
    return coach_g_lv(coach_gamma_x, coach_cx, coach_nx, xs**Integer(2), ts) * coach_nusc(xs)

@helper
def coach_fx(rs, z, xs0, xs1, ts0, ts1):
    return mgga_exchange_erf(coach_fx_enh, rs, z, xs0, xs1, Integer(0), Integer(0), ts0, ts1)

# ----- same-spin correlation: Stoll parallel base, SCC factor 2 beta -----

# Screen each per-spin term as a whole.  gga_stoll_par screens itself, but the
# 2 beta and g_lv factors multiply it from outside; at an empty spin channel
# their reduced-gradient derivatives diverge, so the screened product is 0*NaN
# in fxc.  Wrapping the full term in the density screen masks the empty channel,
# exactly as mgga_exchange does for the coach_fx exchange term.

@helper
def coach_fss(rs, z, xs0, xs1, ts0, ts1):
    return (
        + my_piecewise3(screen_dens_zeta(rs,  z), Integer(0),
        gga_stoll_par(coach_ec1, rs,  z, xs0,  Integer(1))
        * (Integer(2)*coach_beta(xs0**Integer(2), ts0)) * coach_g_lv(coach_gamma_ss, coach_css, coach_nss, xs0**Integer(2), ts0))
        + my_piecewise3(screen_dens_zeta(rs, -z), Integer(0),
        gga_stoll_par(coach_ec1, rs, -z, xs1, -Integer(1))
        * (Integer(2)*coach_beta(xs1**Integer(2), ts1)) * coach_g_lv(coach_gamma_ss, coach_css, coach_nss, xs1**Integer(2), ts1))
    )

# ----- opposite-spin correlation: Stoll perpendicular base -----

@helper
def coach_ec_os(rs, z, xt, xs0, xs1):
    return (
        + coach_ec1(rs, z, xt, xs0, xs1)
        - gga_stoll_par(coach_ec1, rs,  z, xs0,  Integer(1))
        - gga_stoll_par(coach_ec1, rs, -z, xs1, -Integer(1))
    )

@helper
def coach_fos(rs, z, xt, xs0, xs1, ts0, ts1):
    return (
        coach_ec_os(rs, z, xt, xs0, xs1)
        * coach_g_os(coach_cos, coach_nos, ts0, ts1, xs0**Integer(2), xs1**Integer(2))
    )

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return (
        + coach_fx(rs, z, xs0, xs1, ts0, ts1)
        + coach_fss(rs, z, xs0, xs1, ts0, ts1)
        + coach_fos(rs, z, xt, xs0, xs1, ts0, ts1)
    )

TYPE = "mgga_exc"
