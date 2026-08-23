
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_pi_m06_2x_dl_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x_dl", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.994435529231843e-02, -6.904568485596532e-02, -6.774691412955021e-02, -6.586787807604233e-02, -6.314858500395611e-02, -5.922413830980857e-02, -5.362716828042214e-02, -4.592974476050613e-02, -3.626558371875228e-02, -2.572043799777112e-02, -1.635878379751790e-02, -4.579876729618552e-02, -5.242765841761460e-02, -3.587505386039572e-02, -1.793467211872433e-02, -6.271313911176863e-03, 5.144012306808384e-05, -2.210202512909000e-04, -5.128962503431948e-05, -1.711882143812453e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_pi_m06_2x_dl_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x_dl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.607467592648250e-01, -1.601044740220902e-01, -1.591469953367512e-01, -1.576864759295644e-01, -1.553666271466752e-01, -1.514206692531379e-01, -1.440198499127208e-01, -1.289498165038395e-01, -1.002515495679496e-01, -6.519338267885610e-02, -5.187028714030397e-02, -7.139845329292197e-02, -8.633435576243714e-02, -8.003235055190996e-02, -4.948948139007907e-02, -1.925233919853203e-02, -4.736321316938346e-03, -7.430124641741521e-03, -2.790026515809646e-03, -4.080317482298175e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_dl_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x_dl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.740928846587279e-06, 1.851877396022927e-06, 2.023709570651534e-06, 2.298079901869488e-06, 2.754434577538138e-06, 3.552529183395027e-06, 5.016436925432618e-06, 7.701017023728581e-06, 1.181018798619753e-05, 1.562806650754979e-05, 4.405139017236708e-05, 2.958174165842434e-03, 7.454424291730604e-03, 1.866249106405943e-02, 3.106169698562460e-02, 1.954025589317023e-02, 7.421327731187880e-01, 4.461819827895552e+01, 1.981893397367787e+03, 2.288483754337658e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_dl_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x_dl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.881188904787153e-03, -1.871189090124706e-03, -1.857055918707345e-03, -1.836876221924496e-03, -1.806820727806130e-03, -1.756618076022018e-03, -1.653861760674684e-03, -1.404521441109994e-03, -8.454321517758788e-04, -5.117545430886883e-05, 5.403038106574884e-04, -1.460263222100264e-03, 2.939392074435553e-03, -6.251428624931065e-03, -2.434376782130655e-03, 5.674250504872963e-03, -4.736146324932053e-03, -1.101587539416439e-02, -4.377225201703053e-03, -6.945588806909441e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_dl_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x_dl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.883620533647100e-05, 2.745728891225645e-05, 2.218803634871911e-05, 4.630339144157452e-06, -5.351623464209591e-05, -2.545995149805935e-04, -9.869555243007502e-04, -3.660780396009993e-03, -1.189776059430553e-02, -2.621601280937608e-02, -7.821966092270258e-02, 6.893414065314252e-02, -7.405878589801844e-02, -4.267124569589712e-02, -1.589215389987110e+00, -1.825410665400947e+00, 2.088254894756501e+01, 1.039299816004535e+02, -4.855298396766330e+03, -6.497368997284862e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_dl_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x_dl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.849411762042210e-09, -2.133979067620136e-09, -2.568341289329607e-09, -3.178477168462699e-09, -3.645773471652562e-09, -1.055867823957268e-09, 2.661577569780514e-08, 2.503044097166926e-07, 1.979733902546365e-06, 1.355048612513736e-05, 2.174362122883675e-04, -1.294345125134856e-02, 8.087971195429785e-03, -4.796823645067365e-03, 1.804242386807209e+00, 4.510967085713261e+00, -3.708439752003967e+03, -4.465192384656065e+05, 1.717460937612301e+09, 1.827529011151891e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_dl_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x_dl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.772610929778887e-06, 2.050201141055105e-06, 2.467482067949723e-06, 3.071001209357414e-06, 3.801252333312905e-06, 3.929798906961914e-06, -5.210415190762040e-07, -2.598679971685198e-05, -1.112679649721298e-04, -2.238559001613441e-04, -2.174492155509996e-04, 6.891837438055201e-03, 1.098442452595515e-02, 5.117991695455446e-03, -2.647578675471558e-01, 4.929860421113217e-01, 2.534290742942123e+01, 3.681831506265451e+01, -3.935778213953556e+03, -5.548562907111066e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_dl_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x_dl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.800809516140784e-14, 3.509457089530214e-14, 4.762356765932494e-14, 7.054382628507315e-14, 1.092069225496383e-13, 1.132375432658894e-13, -8.215033638995200e-13, -1.677904964000908e-11, -3.018689606834127e-10, -6.379496002022267e-09, -6.675272994501745e-07, -2.544056153662802e-04, -5.209089553776838e-03, -1.102455472711083e-03, -2.056508945553323e+00, -7.002123451871748e+00, 3.973723272103791e+05, 2.333413127235386e+09, 5.875776881063398e+13, 4.642579707213665e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_dl_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x_dl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.944324194982360e-10, -4.485502294754987e-10, -5.392655624174899e-10, -7.012099212038699e-10, -1.015787710451803e-09, -1.695048966256841e-09, -3.336274088896378e-09, -7.576556639217678e-09, -1.776147270171895e-08, -4.833405351078562e-08, -2.992195718649989e-07, 7.609746999033328e-04, -8.769399466400055e-03, -7.389245252514345e-02, -2.039189531626440e-01, -3.906974026979495e+00, -2.519117129136929e+03, -2.253418199523032e+06, -1.116786112696061e+10, -1.014367975134921e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_dl_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x_dl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.003567921775795e-06, 1.067655370674767e-06, 1.167178087831853e-06, 1.326728289492837e-06, 1.593716506200229e-06, 2.064943938524470e-06, 2.941355654713252e-06, 4.583148918174080e-06, 7.187059952889142e-06, 9.135694700507437e-06, 4.526871463164652e-06, -1.314638413643408e-03, 3.462069823885536e-03, 1.223503284425361e-01, 3.103366244837489e-01, -6.537828136648074e-03, 1.088962225856990e+01, 9.708495084693030e+02, 4.904425514211999e+04, 6.156821968422579e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
