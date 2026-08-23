
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_mpw3pw_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw3pw", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.530452242642216e+00, -3.463977197268512e+00, -3.370861444286745e+00, -3.241940076221392e+00, -3.066410154304382e+00, -2.833092911513278e+00, -2.533417135266468e+00, -2.166766183876819e+00, -1.747535712587528e+00, -1.308339614298694e+00, -8.831639847235775e-01, -5.844018717122941e-01, -5.096222365710239e-01, -4.229899774754138e-01, -3.068135598827696e-01, -1.955825073073491e-01, -1.112517739951130e-01, -3.166813707819598e-02, -2.374321435887043e-03, -2.979935261627785e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_mpw3pw_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw3pw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.449379512414396e+00, -4.357753193148443e+00, -4.229309847785273e+00, -4.051280351229996e+00, -3.808497840756981e+00, -3.485040562340931e+00, -3.068293218682239e+00, -2.556758999253276e+00, -1.972715327128135e+00, -1.380150922320129e+00, -9.056384865271072e-01, -7.325864391167660e-01, -6.567406116794322e-01, -5.277094886790882e-01, -3.587919329959671e-01, -1.972768593422415e-01, -1.072028191371575e-01, -7.329200230333197e-02, -4.187457257192583e-03, -3.895947323393184e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw3pw_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw3pw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.510322787840645e-06, -2.711408023391496e-06, -3.027916028497796e-06, -3.545846865432830e-06, -4.441535694767154e-06, -6.116336017145191e-06, -9.610182079086462e-06, -1.809033662378890e-05, -4.337484584712731e-05, -1.426017869835530e-04, -7.031726858577307e-04, -2.665925827935497e-03, -3.264263011567549e-03, -9.300582963646453e-03, -4.043203797221046e-02, -3.214613846803946e-01, -2.692450326353573e+00, 7.134129353484256e+01, 3.162161213724146e+02, 5.924838233579629e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw3pw_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw3pw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.638836667716878e-03, -1.007175187981650e-02, -1.072790655421451e-02, -1.174519555862239e-02, -1.337399740813391e-02, -1.610312360887340e-02, -2.097383659694712e-02, -3.043660877379428e-02, -5.086681312798330e-02, -9.984943731110406e-02, -2.386342013523191e-01, -4.480763541900725e-01, -5.320547459037834e-01, -9.373088261561018e-01, -2.444245104054317e+00, -8.203393999782612e+00, 5.845232360937357e+01, -1.149728919142533e+03, -1.913956625903782e+04, -3.238331391933576e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw3pw_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw3pw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.685858756741240e-08, 1.914124577529980e-08, 2.295794383188904e-08, 2.976765158571484e-08, 4.308960804751769e-08, 7.275844425878740e-08, 1.518619858548535e-07, 4.210543982748941e-07, 1.678278925392024e-06, 1.028608496073213e-05, 1.651283775712149e-04, 7.065645810563294e-03, 1.638490397010468e-02, 7.412973336002740e-02, 8.395524996225290e-01, 1.747708871657592e+01, -6.282542794727464e+03, 9.329905263171248e+05, 4.059612122366885e+09, 5.601137123143798e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw3pw_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw3pw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.132888326485592e-14, 1.643484227822340e-14, 2.691514635892126e-14, 5.162294862026869e-14, 1.220141449733419e-13, 3.818286141264079e-13, 1.749873652718696e-12, 1.349325760026508e-11, 2.108532802008412e-10, 8.526067409623493e-09, 1.072485679845156e-06, -1.715608633540004e-04, -2.928374380008136e-03, -9.599298129236010e-03, -1.286679280145065e-01, 9.301651869791738e+01, 6.717366813192468e+05, -8.762754254903683e+09, -1.507216011568332e+15, -1.616904418941167e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
