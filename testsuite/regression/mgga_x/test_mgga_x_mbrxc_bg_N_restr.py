
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_mbrxc_bg_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxc_bg", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.337271292842814e+00, -4.263495844489539e+00, -4.161035961579804e+00, -4.021026315020811e+00, -3.834186422426603e+00, -3.593050414355626e+00, -3.294867000978794e+00, -2.944102782377320e+00, -2.559342704463263e+00, -2.164159873903443e+00, -1.565399923156804e+00, -7.393869648832376e-01, -5.705309193886163e-01, -5.133919824897910e-01, -4.419011324324936e-01, -3.961102927336212e-01, -4.579525628931022e-01, -7.986130061437529e-01, -2.339450869254574e+00, -1.353383879562197e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_mbrxc_bg_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxc_bg", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.872302963640705e+00, -4.737085681289395e+00, -4.546402070646827e+00, -4.280933970701392e+00, -3.920641142755096e+00, -3.456570979732943e+00, -2.909926708477887e+00, -2.308719449624782e+00, -1.624518694337724e+00, -8.706990872501544e-01, -4.511269023667925e-01, -6.934763985279579e-01, -6.637716707256036e-01, -4.428088178297908e-01, -2.341237357119784e-01, -1.167915809399697e-03, 2.464653212808854e-01, 6.889058254972572e-01, 2.415501524532121e+00, 1.533137059740822e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxc_bg_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxc_bg", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.251939457260523e-06, -1.026025837680073e-05, -1.188759305607008e-05, -1.462997182061460e-05, -1.950006613571123e-05, -2.864915203253253e-05, -4.699622411206864e-05, -8.933178569334092e-05, -2.191780830681152e-04, -7.939665399459245e-04, -4.248991558462128e-03, -1.753797670594645e-02, -2.773459778382412e-02, -8.376045766533825e-02, -3.249385712387476e-01, -2.793326166061183e+00, -5.797402548063837e+01, -3.950863512417754e+03, -1.506920135081653e+06, -7.056954863598838e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxc_bg_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxc_bg", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.182857958367336e-03, -1.219473949582852e-03, -1.271602268361432e-03, -1.343705251452405e-03, -1.435722858684931e-03, -1.528588700099505e-03, -1.564507854279660e-03, -1.482982281484205e-03, -1.301296135401550e-03, -1.094608232334999e-03, -1.281911951716968e-03, -6.430538608769704e-03, -8.874201047592142e-03, -9.505571623317888e-03, -6.346083590437103e-03, -3.636303194533928e-03, -1.433020262041526e-03, -3.651174719302601e-04, -5.695120861130110e-05, -4.627205355491680e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxc_bg_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxc_bg", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.297308475277051e-02, -2.450846061050002e-02, -2.675580848301736e-02, -2.993977824681547e-02, -3.397920133107252e-02, -3.770015972923834e-02, -4.013522296292976e-02, -5.219821960644042e-02, -1.127815146293421e-01, -3.486985946446304e-01, -1.013843665373045e+00, -5.951457620122141e-01, -1.063575376169894e+00, -1.554481227487818e+00, -5.564073973432419e+00, -4.044046221498497e+01, -6.855825473872256e+02, -4.572075334210981e+04, -1.794869894269018e+07, -8.612593390958199e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxc_bg_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxc_bg", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.461852853069150e-07, 1.697011656807847e-07, 2.083315438990727e-07, 2.736105034544467e-07, 3.839818723198133e-07, 5.579579042249595e-07, 8.351396074591599e-07, 1.909712626438976e-06, 1.088300394657751e-05, 1.265380190009238e-04, 2.599166820928246e-03, 2.842588191180718e-02, 1.755549588273551e-01, 3.591871529182577e-01, 4.431293601581545e+00, 2.223670856291855e+02, 5.249414920399086e+04, 1.191825968707838e+08, 5.654524847359622e+12, 2.100875762749551e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxc_bg_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxc_bg", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.836037523362570e-06, 7.019356395763984e-06, 7.048698388762854e-06, 6.399031398805642e-06, 3.404629721805024e-06, -6.352193388369184e-06, -2.975279659830600e-05, -7.019246747492567e-05, -1.479395587991918e-04, -3.925386023597310e-04, -1.748616816227878e-03, -1.152940731460003e-02, 2.107652320355930e-02, -6.041343210124265e-02, -1.883608805656799e-01, -7.642639830485434e-01, -3.956574349346923e+00, -3.049611530586584e+01, -5.173537962809777e+02, -3.017000000436848e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxc_bg_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxc_bg", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.087493267570140e-13, -9.880718226563731e-13, -1.295513009598093e-12, -1.831730741200278e-12, -2.671840512797548e-12, -2.968797143004098e-12, 5.113306053483284e-12, 7.215863981439713e-11, 7.216618822845236e-10, 1.859572910650176e-08, 2.026206562981281e-06, -7.948617813154241e-05, -2.810315118347142e-02, 4.423742101592310e-02, 1.612133147954567e+00, 4.863324992287508e+02, 1.750831501320444e+06, 1.000530347308778e+11, 3.757345642681620e+17, 7.109618233613340e+26]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxc_bg_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxc_bg", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.708014256425448e-11, -4.987609140397156e-11, -5.104570752959266e-11, -4.204145224669408e-11, 1.332700480116641e-11, 2.614543957034455e-10, 1.216494534879448e-09, 4.647012036863143e-09, 2.130783488552671e-08, 1.790741698036743e-07, 5.232022992652140e-06, 8.991992126695348e-04, -3.971898870814942e-03, 2.607547198000771e-02, 2.012660410565179e-01, 4.602995430859526e+00, 3.005329309714011e+02, 7.722194118264271e+04, 1.589532692921080e+08, 7.223680859805980e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxc_bg_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxc_bg", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.019183498817079e-09, -5.927978803309795e-09, -5.460301103729301e-09, -3.861341693288044e-09, 9.812215660026822e-10, 1.395001968678870e-08, 4.049719505057924e-08, 7.714428250845516e-08, 1.265081015499762e-07, 2.468820165633273e-07, 1.578490499135346e-06, 3.297036682735584e-04, -1.270883010276560e-03, 2.959179945125257e-03, 3.930746404133574e-03, 5.992099022672082e-03, 7.428667854651152e-03, 7.136434820776586e-03, 6.007339465546825e-03, 4.736526647388955e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
