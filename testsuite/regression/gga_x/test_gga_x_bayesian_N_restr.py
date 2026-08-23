
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_bayesian_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bayesian", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.284723471852571e+00, -4.202918701800574e+00, -4.088420107522035e+00, -3.930083774028142e+00, -3.714906137107110e+00, -3.429738677547185e+00, -3.065256064159470e+00, -2.622955882727588e+00, -2.123652542938991e+00, -1.605945782239561e+00, -1.084204672652953e+00, -6.606897404163681e-01, -5.607977560972028e-01, -4.692071041185260e-01, -3.476345349577966e-01, -2.325801211392706e-01, -1.377702683523125e-01, -5.930499096524428e-02, -1.433957966074774e-02, -1.652584906652908e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_bayesian_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bayesian", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.386982394157985e+00, -5.271714923425179e+00, -5.110060971000994e+00, -4.885862799787010e+00, -4.579864016333051e+00, -4.171760453674720e+00, -3.645472319905152e+00, -3.000001198943207e+00, -2.269406150938608e+00, -1.552151774349849e+00, -9.987055553861598e-01, -7.983996122661249e-01, -7.168977795677581e-01, -5.532357643926037e-01, -3.540619133872511e-01, -1.965454031283717e-01, -1.180123797726571e-01, -6.468078787343698e-02, -1.824302470078680e-02, -2.191556676060548e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bayesian_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bayesian", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.497726782642354e-06, -3.796631013661382e-06, -4.270191763352020e-06, -5.052351759306210e-06, -6.422756574830123e-06, -9.031622255443629e-06, -1.460388292658542e-05, -2.850796923833976e-05, -7.092630188166020e-05, -2.370614491658615e-04, -1.190297142340230e-03, -6.621668361081564e-03, -1.145465279076373e-02, -2.688863458375585e-02, -1.031312146070596e-01, -6.080963012085498e-01, -4.452487779068402e+00, -3.243186695760262e+01, -2.386190338618298e+02, -2.513933088006475e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bayesian_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bayesian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.250960038507836e-02, -1.310142216048193e-02, -1.400152174392880e-02, -1.540355399330647e-02, -1.766190137399699e-02, -2.147126787377085e-02, -2.829659316104276e-02, -4.139681391915991e-02, -6.763863432844153e-02, -1.155702861392722e-01, -2.299833325471595e-01, -5.878718262249685e-01, -6.884393075289332e-01, -1.228655116987480e+00, -2.550899306312207e+00, -2.216124422003453e+00, 4.926876000718470e+01, 2.904910500505516e+02, -1.347336891750124e+04, -1.810443682248285e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bayesian_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bayesian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.664030059353150e-08, 3.051373311464051e-08, 3.704901605832837e-08, 4.885263526223476e-08, 7.231438548064406e-08, 1.255630929836121e-07, 2.700020033844294e-07, 7.599883521939714e-07, 2.839892874312132e-06, 1.118676744593256e-05, 6.064959975980674e-05, 1.269144263011930e-02, 3.984839929056607e-02, 1.357064114871961e-01, 7.437791299289913e-01, -1.826894841282951e+01, -6.055293608742943e+03, -2.164088723351191e+06, -2.128442633676403e+09, -1.727453664347867e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bayesian_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bayesian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.428010457064174e-15, -5.286761105409460e-15, -1.776862509885337e-15, 9.882349951413889e-15, 5.472808655378563e-14, 2.716613342230816e-13, 1.740315187396364e-12, 1.775088208166350e-11, 3.535466342799065e-10, 1.707586497120149e-08, 2.469565200723842e-06, 1.255038823502937e-04, -1.004524411738063e-03, 1.194248343828297e-02, 1.233072512948855e+00, 4.707775822459810e+02, 8.202811785726065e+05, 7.904059534915338e+09, 8.827940438500432e+14, 5.488100312168654e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
