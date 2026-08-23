
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_hjs_b88_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b88", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.206207199268529e+00, -4.123766160459954e+00, -4.008309231094405e+00, -3.848504303495279e+00, -3.631026150645779e+00, -3.342161286920693e+00, -2.971590895835377e+00, -2.519226588521405e+00, -2.004584035377627e+00, -1.471623841276847e+00, -9.630639208334091e-01, -5.940857295473517e-01, -4.990803550209588e-01, -4.031567153490893e-01, -2.746720711376266e-01, -1.554109463592310e-01, -7.266196615391261e-02, -2.648181477100327e-02, -2.862005241643752e-02, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_hjs_b88_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.368928412494672e+00, -5.255507399684853e+00, -5.096533081483149e+00, -4.876227098296865e+00, -4.575866778590902e+00, -4.175819418125476e+00, -3.660495491626814e+00, -3.027565615303533e+00, -2.302303122721267e+00, -1.566233012044254e+00, -9.823379039292904e-01, -7.521874336923203e-01, -6.605902452969608e-01, -5.068776950220838e-01, -3.118951295126540e-01, -1.387758983173302e-01, -3.434637174200599e-02, 5.337676296556206e-03, 1.146934030215165e-01, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_b88_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.789663995348284e-06, -3.011589574738097e-06, -3.360959630165830e-06, -3.932865617040150e-06, -4.922631639998871e-06, -6.776409125552597e-06, -1.065904740483900e-05, -2.018213185826333e-05, -4.934833717711655e-05, -1.676271213391802e-04, -8.584974120329997e-04, -4.798817595057366e-03, -8.993797832694024e-03, -1.862053090424999e-02, -6.947090040332057e-02, -4.670022611469598e-01, -5.352940890163029e+00, -1.176165882260620e+02, -4.488871013693346e+04, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_b88_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.154582856004660e-02, -1.205702106954100e-02, -1.283158150973635e-02, -1.403210155237225e-02, -1.595433665468147e-02, -1.917951856542004e-02, -2.497116586639530e-02, -3.647533319290442e-02, -6.257000652068996e-02, -1.212625735878539e-01, -2.882492024649441e-01, -5.239559400749653e-01, -6.470074249334612e-01, -1.084459663500017e+00, -2.546334590011097e+00, -7.119232312236156e+00, -1.751409845150952e+01, -2.407330454371660e+02, -4.701508868330528e+06, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_b88_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.542755507389042e-08, 1.754785368280235e-08, 2.110282973735507e-08, 2.747264889430311e-08, 4.002226215954762e-08, 6.833806406213249e-08, 1.460038617260903e-07, 4.298708007409208e-07, 1.963173317164269e-06, 1.175517479254698e-05, 1.910038550459673e-04, 7.075852324457609e-03, 2.415362384082386e-02, 7.681758544323793e-02, 6.862836597105628e-01, 8.654604633184251e+00, -5.487463882945889e+02, 3.194859881516200e+05, 1.330604347328469e+12, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_b88_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.725110899691897e-14, 7.180470570612700e-14, 9.934475452233070e-14, 1.580733018982334e-13, 3.066263992482522e-13, 7.855536718188625e-13, 2.957096965697790e-12, 1.875629629432565e-11, 2.474740410078658e-10, 1.052351284786729e-08, 1.387995661150187e-06, 2.494478095281405e-04, 1.592788020398028e-03, 1.363586587117010e-02, 6.254008044985155e-01, 2.347525405824975e+02, 5.057162581761344e+05, 8.569449812238515e+09, -3.132277360312560e+17, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
