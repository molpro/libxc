
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_sb98_1a_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1a", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.586856348319359e+00, -3.516816828247139e+00, -3.418722220380242e+00, -3.282937657442734e+00, -3.098130152921270e+00, -2.852639586613160e+00, -2.537747116278756e+00, -2.153730466529851e+00, -1.718622790165248e+00, -1.273356329958776e+00, -8.535079109739706e-01, -5.606136679105934e-01, -4.808174233564880e-01, -3.993279200532242e-01, -2.870850766010254e-01, -1.779070284252990e-01, -8.828888977908070e-02, -2.701877023867452e-02, -4.696430927243116e-03, -4.502943064084705e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_sb98_1a_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1a", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.636913334061977e+00, -4.541057750340641e+00, -4.406668114794837e+00, -4.220343037513143e+00, -3.966082899472506e+00, -3.626826784763673e+00, -3.188180424796701e+00, -2.645319584805845e+00, -2.014922451200135e+00, -1.364992507756945e+00, -8.766729891932282e-01, -7.012185272899256e-01, -6.147138776051743e-01, -4.929836719066666e-01, -3.337970310016646e-01, -1.886596759918834e-01, -1.001736821342858e-01, -3.627882532506848e-02, -6.408812581269799e-03, -6.061679656076785e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_1a_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1a", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.492985768731171e-06, -1.617969322122206e-06, -1.815934260604567e-06, -2.143087448878622e-06, -2.717923455445192e-06, -3.821805504688316e-06, -6.233380305215552e-06, -1.257653126533440e-05, -3.410729977083946e-05, -1.322481178501763e-04, -6.895430204899962e-04, -3.407347076787135e-03, -8.787569188665212e-03, -1.341162622942235e-02, -4.379735565874942e-02, -2.625739465237367e-01, -1.377636244895226e+00, -2.120199521494457e+00, -1.140143291250867e+00, -2.276780627927763e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_1a_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.486056704732409e-03, -9.910561993978729e-03, -1.055719433984607e-02, -1.156817465079134e-02, -1.321082878974401e-02, -1.603761063533547e-02, -2.133942203840532e-02, -3.261860520626791e-02, -6.075496965456461e-02, -1.363565945326600e-01, -3.108748885623432e-01, -3.973498760968210e-01, -5.206445769872693e-01, -7.936905527639553e-01, -1.951001564558318e+00, -5.479091360555105e+00, 8.680798390829127e+00, -3.117097974380452e+02, -8.195786409951646e+03, -5.458541644741126e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_1a_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.223725150835801e-09, 1.062920628872155e-08, 1.304975659300001e-08, 1.756917400674460e-08, 2.705933441150855e-08, 5.068471550457846e-08, 1.256644498047022e-07, 4.576992654868838e-07, 2.685207501199973e-06, 2.481953033963064e-05, 3.682243998735978e-04, 1.863634407521820e-03, 8.667699607982277e-03, 1.340929477057174e-02, 3.567232886174956e-01, 3.741158730907398e+00, -2.906822422888035e+03, -2.506860973509862e+05, -1.669478351972766e+07, -2.563925206146567e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_1a_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.432910911472067e-14, 2.969555389750357e-14, 3.929093361181236e-14, 5.796942218847626e-14, 9.853268599803901e-14, 1.983581775973805e-13, 4.647578682547920e-13, 9.391210043123522e-13, 6.532424787181762e-13, 1.772653218193572e-09, 4.900100210770660e-07, 4.635650552370903e-04, 8.282406038516927e-03, 2.704205977790333e-02, 4.465445745190937e-01, 1.217376313436916e+02, 3.076238324199384e+05, 7.366084901361398e+08, 5.762841470790251e+12, 6.647778775027756e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
