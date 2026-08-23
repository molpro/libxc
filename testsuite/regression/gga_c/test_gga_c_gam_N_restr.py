
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_gam_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gam", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.191320463228511e-03, -1.810722391227285e-03, -1.435075931847181e-03, -1.244724283664775e-03, -1.669846541694612e-03, -3.620574865442816e-03, -8.783871662716870e-03, -1.969394432552379e-02, -3.869195785293161e-02, -6.194941357510553e-02, -6.348296847523895e-02, -3.419876025458940e-03, -5.228972584062504e-03, -6.507934133315660e-03, -2.819811431746774e-02, -3.249911772649693e-02, 6.599224248583473e-02, 7.785039764303180e-02, 2.281574791628246e-02, 2.817612852636980e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_gam_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gam", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.145711355106323e-02, -2.447819327959273e-02, -1.460219191728780e-02, -8.601883002018587e-04, 1.761734664977208e-02, 4.078594757244941e-02, 6.591290717307093e-02, 8.556906570890535e-02, 8.849386566616758e-02, 5.104396955207366e-02, 4.746451252268853e-03, 2.942253646450715e-02, -4.666392645968975e-02, 3.884876219925531e-02, 4.121394406324663e-02, -9.378276835889075e-02, -1.247104899720603e-01, 7.398180367286895e-02, 2.941030090270227e-02, 3.736620907612791e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_gam_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gam", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.133427624524035e-07, 2.587126048564193e-07, 1.647827835559260e-07, -5.303124930005752e-09, -3.322444325012230e-07, -1.004067055500416e-06, -2.492670794643469e-06, -6.132034857917979e-06, -1.650504629428398e-05, -4.800238255989012e-05, -2.005624978179894e-04, -2.660650192011757e-03, 1.518809948273719e-02, -1.713764977307491e-02, -6.913353251171191e-02, 2.999744013523862e-01, 1.383771514515246e+01, 5.380701134972806e+01, 8.819925964418482e+01, 1.100215826772400e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_gam_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gam", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.641441084010122e-03, -2.793942239513984e-03, -3.008112202643707e-03, -3.299480674136203e-03, -3.666452385509639e-03, -4.038395381557235e-03, -4.145832243017963e-03, -3.291126938341762e-03, 1.299488679556269e-03, 5.217193694655706e-02, 3.130170054803734e-01, -3.125334437975988e-01, -5.326853058292558e-01, -5.401638582718263e-01, 1.106799544042705e+00, 4.554039468198513e+01, -3.371304407527635e+02, -2.132500339214946e+03, 2.623363559543314e+04, 3.141741353380447e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_gam_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gam", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.819516350416299e-08, 3.180563294948524e-08, 3.756400388068139e-08, 4.706576589951210e-08, 6.332616519875665e-08, 9.185697997009843e-08, 1.404364627620603e-07, 2.017487585961886e-07, -9.728030584756100e-08, -2.060150981426842e-05, -8.318260599745558e-04, 2.556443668731027e-02, 1.927711812304886e-01, 2.098618793664097e-01, -9.556983888611489e-01, -2.506634318818782e+02, 2.104966565261891e+04, 6.065135319580282e+06, 1.220933679488308e+09, 1.137397794313351e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_gam_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gam", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.322785280429294e-13, -3.913400652311564e-13, -4.913594966225650e-13, -6.704194955477006e-13, -1.009811230529497e-12, -1.659757045018557e-12, -2.490105631389414e-12, 4.011329416653714e-12, 2.073955308589793e-10, 1.341497107666055e-08, 2.732178836007262e-06, -1.519054662850289e-03, -9.277157939978992e-02, -3.220797557303283e-02, 2.383193401639838e+00, 1.134678863014431e+03, -2.826525242031659e+06, -1.898542368449878e+10, -4.472585741748030e+14, -3.213379392108022e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
