
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_k_gea4_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_gea4", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.941035378371660e+02, -1.783732774854891e+02, -9.564807587919597e+01, -3.910431502014391e+01, -2.791619629360786e+00, 1.813832564979538e+01, 2.773690811757239e+01, 2.971334928658839e+01, 2.767075670911757e+01, 2.446203309043568e+01, 1.871294684247442e+01, 5.560730844087455e+00, 1.048594035304551e+00, 1.057273780272460e+00, 1.016883987672228e+00, 8.970281528091792e-01, 8.588534719895534e-01, 1.236594947058781e+00, 1.258940833728887e+01, 1.059941475697850e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_k_gea4_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_gea4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.140388987772482e+01, 1.043991709281772e+02, 1.153182495948316e+02, 1.137422068010370e+02, 1.041300165172469e+02, 8.875021203225180e+01, 6.935023931676881e+01, 4.816012405382625e+01, 2.826594280218341e+01, 1.319051631356507e+01, 5.484932782778064e+00, 3.298653860112814e+00, 2.593306715504900e+00, 1.627648299124803e+00, 6.990845620675149e-01, 1.666512365142242e-01, 2.910887438520499e-02, 5.426075870280742e-01, 1.307251691133618e+01, 9.827592044999913e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_gea4_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_gea4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.812813311764324e-04, 1.611636097924717e-04, 1.520694065823920e-04, 1.537581046264708e-04, 1.687852200929484e-04, 2.050806478513748e-04, 2.838993752531032e-04, 4.668787679547880e-04, 9.623250427186050e-04, 2.542877387242232e-03, 5.831855131551668e-03, 1.499671428068904e-02, 3.851169881352143e-02, 7.368067593183465e-02, 2.223136925775630e-01, 1.044050469905139e+00, -7.437639244859106e+00, -7.718112113337914e+03, -2.379407938528422e+07, -1.549429625825200e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_gea4_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_gea4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.337138715799272e-01, 1.431687516020437e-01, 1.497308896234543e-01, 1.542774166825559e-01, 1.574166069859694e-01, 1.595706600391999e-01, 1.610381456969746e-01, 1.620608149204731e-01, 1.629974454868292e-01, 1.652740685934439e-01, 1.754454683899215e-01, 1.749670392179082e-01, 1.632585762726997e-01, 1.635341530053675e-01, 1.652979583647690e-01, 1.711146459454529e-01, 2.109825604095805e-01, 6.924824565956486e-01, 1.356791779881141e+01, 1.164560213246205e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_gea4_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_gea4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.811449252718683e+00, 1.266712514609541e+00, 1.002391889909559e+00, 8.860591990086129e-01, 8.570947502101421e-01, 8.942734691024490e-01, 1.005475658383867e+00, 1.238615755837016e+00, 1.738201466364758e+00, 2.861131937663983e+00, 3.802422359346820e+00, 4.264472747229449e+00, 4.611582222583386e+00, 6.305993326377572e+00, 1.127802510698278e+01, 3.283882484259660e+01, 1.260066443242615e+02, -5.241385243511662e+04, -1.866494936867365e+08, -1.247121623933921e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_gea4_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_gea4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.002295485789116e-06, -1.764555370372461e-06, -1.692588872541314e-06, -1.814506252078273e-06, -2.251116605713046e-06, -3.389435871242981e-06, -6.621227913132199e-06, -1.844398153671048e-05, -8.313780643991474e-05, -6.640211376727288e-04, -3.904488407517349e-03, -7.715257784886014e-03, -1.162354182201121e-01, -4.498918549543641e-01, -4.726436453595192e+00, -1.798278934068631e+02, -3.205912480261063e+04, 2.547407133606677e+07, 4.661867152273140e+13, 3.204218989109716e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_gea4_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_gea4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.141404419345761e-04, 2.407407824566576e-04, 1.924958452346592e-04, 1.635768425508128e-04, 1.516483386613590e-04, 1.592030668138564e-04, 1.994580058204913e-04, 3.203284180461871e-04, 7.164251492673985e-04, 2.182729929992471e-03, -4.509192280297036e-04, -1.868677431580393e-02, 1.616481904395226e-02, 3.792137759901515e-02, 1.510429099606750e-01, 1.553134615080013e+00, 5.116465070427532e+01, 7.332910177662669e+03, 6.540148628552732e+06, -1.416124152658782e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_gea4_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_gea4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.068636156963222e-13, 8.847566903345331e-13, 1.221479804348004e-12, 1.940882810732824e-12, 3.771612568753654e-12, 9.771241355733872e-12, 3.813037834624289e-11, 2.659262116891260e-10, 4.182204538311811e-09, 1.929895977958582e-07, 2.267765545153561e-05, 7.473303871055911e-04, 3.355874589794277e-03, 3.704763423720927e-02, 2.600144733881264e+00, 1.591840673080214e+03, 1.378517013682349e+07, 3.823830907324628e+12, 1.276530360192407e+20, 4.227516118944429e+30]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_gea4_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_gea4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.136203820757920e-10, -2.515030270935402e-10, -3.179851260317665e-10, -4.453185873327267e-10, -7.219534465636832e-10, -1.442713926857321e-09, -3.883578895814099e-09, -1.594701594745673e-08, -1.182949112719457e-07, -1.919735657491630e-06, -6.148125237768737e-05, -7.810530192331274e-04, -2.328495933259463e-03, -1.335328243175145e-02, -2.939719438122335e-01, -3.127114303857286e+01, -2.284489860992492e+04, -2.076814149126130e+08, -6.152584845389202e+13, -2.754267168120149e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_gea4_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_gea4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.801166999246094e-08, 7.531756476044641e-08, 8.720894103515814e-08, 1.076405785512835e-07, 1.455878073926619e-07, 2.244111334529666e-07, 4.167032060912235e-07, 1.007468327976149e-06, 3.525011583472798e-06, 2.011790041071813e-05, 1.755985599944844e-04, 8.599675846404857e-04, 1.702075954973767e-03, 5.070482415209130e-03, 3.501450061416051e-02, 6.471748127523874e-01, 3.988412153733378e+01, 1.188311446129443e+04, 3.124048491033135e+07, 1.890429779068020e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
