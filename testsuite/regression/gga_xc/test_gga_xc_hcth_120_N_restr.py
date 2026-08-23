
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_hcth_120_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_120", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.529806524701910e+00, -4.438061945828198e+00, -4.309623344034830e+00, -4.131964811434531e+00, -3.890476695479611e+00, -3.570479280879297e+00, -3.162095816894222e+00, -2.669836069813783e+00, -2.128058546966165e+00, -1.606396880155033e+00, -1.104209587386024e+00, -7.193458703236609e-01, -6.269940677554615e-01, -5.159959708025568e-01, -3.777953696784980e-01, -2.527804241964766e-01, -1.274653146235930e-01, -3.407429959706045e-02, -5.688140497608590e-03, -5.794805016326554e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_hcth_120_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_120", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.118236969214697e+00, -5.991032404498502e+00, -5.812318111536725e+00, -5.563761156859989e+00, -5.222943855346872e+00, -4.764690789910330e+00, -4.164426780954678e+00, -3.404018046492940e+00, -2.486763828744641e+00, -1.529432334115614e+00, -9.454494246099281e-01, -9.204306180249837e-01, -8.258627404143255e-01, -6.423431660664284e-01, -4.143077749375145e-01, -2.291800312863028e-01, -1.659340440420178e-01, -4.916423025808898e-02, -7.770904306849728e-03, -7.744165904411333e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_120_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_120", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.040336336929431e-06, 1.053517206357254e-06, 1.062120413520121e-06, 1.046894483214291e-06, 9.447819091884736e-07, 5.370619501866160e-07, -1.030225678868896e-06, -7.706426172340463e-06, -4.157260601539397e-05, -2.393772112673755e-04, -1.368504772462224e-03, -2.253849319372245e-03, -8.958094965028082e-04, -1.339499626648877e-02, -7.578168551559997e-02, -5.631908297283384e-01, -4.943505224609357e-01, 4.730229919308274e+00, 1.054355167398956e+01, 1.438566959125743e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_120_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_120", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.284659928829067e-02, -1.350492290681622e-02, -1.452044304084701e-02, -1.613898091334272e-02, -1.884918938687582e-02, -2.374524878803906e-02, -3.368547798165118e-02, -5.754066209778257e-02, -1.253791979038176e-01, -3.003245077290959e-01, -6.220346740508097e-01, -6.365414492549812e-01, -8.005933194807640e-01, -1.294781877554119e+00, -3.842469006857745e+00, -9.900111752035977e-01, 1.202116627661745e+01, -7.923090695601974e+02, -1.041404200730151e+04, -6.773561539448655e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_120_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_120", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.601488878391365e-08, 1.924603124935829e-08, 2.498330717254939e-08, 3.614441191587255e-08, 6.088791212394573e-08, 1.269812546259695e-07, 3.563066285316144e-07, 1.483267666754204e-06, 9.725356287608218e-06, 8.834777166634882e-05, 1.191655635834033e-03, 1.169978856194968e-02, 5.280625015339874e-02, 1.145225456818043e-01, 1.857691330699014e+00, -2.194107678655619e+01, -4.432848892721723e+03, 4.993549382249834e+05, 1.448822713042693e+08, 1.485044053234829e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_120_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_120", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.457593093833959e-13, -3.038662639502066e-13, -4.120545495195951e-13, -6.378697161275966e-13, -1.194253588639023e-12, -2.939844994184749e-12, -1.071315144018697e-11, -6.711858707416980e-11, -8.056396770940666e-10, -1.414131654743335e-08, -2.356626950946515e-07, -4.515246675621980e-04, -1.704622306249096e-02, -6.385066627143293e-03, -3.556470372961233e-01, 4.286965296755300e+02, 3.115626897023009e+05, -1.632924905597546e+09, -5.344783527302356e+13, -4.201584071407238e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
