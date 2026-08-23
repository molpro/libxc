
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_15_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_15", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.049945981737343e+00, -4.949978560908045e+00, -4.809818793779289e+00, -4.615472146563631e+00, -4.350182799175863e+00, -3.995890558419499e+00, -3.536536478176846e+00, -2.962980051318209e+00, -2.278670507854216e+00, -1.530723556761534e+00, -9.105309226192283e-01, -6.104230851028332e-01, -5.749526526921694e-01, -4.959613862960600e-01, -3.395245441197127e-01, -1.840629703492418e-01, -7.885978020327739e-02, -2.508785064081277e-02, -5.195476908611384e-03, -5.749301869920437e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_15_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_15", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.259696887964651e+00, -6.121446681146161e+00, -5.927739391689720e+00, -5.659504389738928e+00, -5.294428973454914e+00, -4.810206930204728e+00, -4.193062215271072e+00, -3.455875330150966e+00, -2.659244532119414e+00, -1.858626605452870e+00, -1.141233549117043e+00, -7.817912058132984e-01, -8.292869358838730e-01, -6.472283075710947e-01, -4.181395313569081e-01, -2.290175076143386e-01, -1.006478706806575e-01, -3.224939235536351e-02, -6.667515452586444e-03, -7.363972239750262e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_15_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_15", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.086829067252224e-05, -1.175512481172356e-05, -1.315298292799868e-05, -1.544399494299600e-05, -1.940990230983024e-05, -2.681022378330003e-05, -4.204074131802408e-05, -7.705305341438257e-05, -1.626185499006961e-04, -3.401979926689510e-04, -6.495735486492839e-04, -3.520328278396552e-03, -2.284908560326384e-02, -5.736105080357613e-02, -1.584679045480304e-01, -3.843309094629181e-01, -1.023345811947296e+00, -7.500071902415558e+00, -1.889822647564079e+02, -1.701466251965910e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_15_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_15", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.316469724649248e-02, 1.344552862622636e-02, 1.385809078983016e-02, 1.446888739091090e-02, 1.538126469287677e-02, 1.675292969574271e-02, 1.879106705921365e-02, 2.152643360932525e-02, 2.329352235680497e-02, 1.736293872238330e-02, 5.378263345325322e-03, 1.024924382067599e-03, 4.945760564456242e-02, 8.202555705642865e-02, 8.290600336708713e-02, 3.779158811866053e-02, 8.168249011224990e-03, 1.854765241286170e-03, 4.175455516954385e-04, 5.164020273702845e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_15_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.724412333731122e-02, -1.809302998458158e-02, -1.938188398886444e-02, -2.138133756852257e-02, -2.457094142511190e-02, -2.982239691334212e-02, -3.864342590536139e-02, -5.272653447869045e-02, -6.998695436418727e-02, -9.795234581788917e-02, -1.828032169877495e-01, -5.806310888566717e-01, -1.049118305782790e+00, -1.501258259557490e+00, -2.341391938463036e+00, -4.931153283872119e+00, -3.449967019812156e+01, -3.882566436501563e+02, -9.272206564940296e+03, -7.620476674619332e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_15_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.789404351710384e-08, 8.922529561267225e-08, 1.083505449538202e-07, 1.428952515041277e-07, 2.114579800474298e-07, 3.659120627917138e-07, 7.721660257329003e-07, 1.980927268748922e-06, 4.409251161651224e-06, -2.104354246602324e-05, -4.382619761018493e-04, -6.774196534968074e-03, 2.269811755681083e-02, 1.371389621973214e-01, -5.185212245553938e-01, -2.770758012138093e+01, 1.330162514119919e+02, 3.296255805006424e+05, 1.082656708162538e+09, 7.118738644328591e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_15_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.068020632436987e-05, -4.465867451020724e-05, -5.104669994468209e-05, -6.178810579981098e-05, -8.102594070140267e-05, -1.183865706764160e-04, -1.972579445815384e-04, -3.610216662985930e-04, -4.567846106201457e-04, 1.182164857634490e-03, 3.475942229536466e-03, 2.128177365452604e-02, 1.257404632835543e-01, 7.134210549417250e-02, 5.034114336370796e-01, 2.421372557785925e+00, -1.252552471186762e+00, -8.023387385642778e+01, -2.389688611565090e+03, -2.160535820386640e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_15_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.400167968908902e-13, -1.776556209026518e-13, -2.499496895832261e-13, -4.074965933033531e-13, -8.188113375351401e-13, -2.206986617947234e-12, -8.915748370213237e-12, -6.135957123044055e-11, -7.874565015217897e-10, -1.805701615290222e-08, -8.163379205890470e-07, -6.556375744090960e-05, -2.258492638560641e-03, -3.313381803921049e-02, -1.418950925772963e+00, -2.152431151860535e+02, -2.184675889034032e+05, -2.627983577636891e+09, -9.491877760453542e+14, -4.842196828972641e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_15_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.922914834334274e-10, 4.733820325059027e-10, 6.199900367905555e-10, 9.129529441974614e-10, 1.588655696714459e-09, 3.500172680903534e-09, 1.069444440301099e-08, 5.019633745922587e-08, 3.780668892357678e-07, 3.741034732419801e-06, 4.036148594827836e-05, 1.321610749102203e-03, 2.288951893583351e-02, 1.812567890660341e-01, 3.212836452485957e+00, 7.638582643340470e+01, 3.452391529610612e+03, 1.000338976207449e+06, 3.158903634498979e+09, 2.223776228921708e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_15_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.975516614224900e-07, -5.712264377700706e-07, -6.967237427809845e-07, -9.269470815411658e-07, -1.396639522668190e-06, -2.511028169972138e-06, -5.768712855026723e-06, -1.816024418620832e-05, -7.687627265522191e-05, -3.001047771354132e-04, -6.207591816333448e-04, -3.336996685919499e-03, -9.058139801720314e-02, -4.016672554097051e-01, -2.683895505422453e+00, -1.212668173230639e+01, -4.042567649866545e+01, -3.338503799885132e+02, -9.325230288386336e+03, -9.038127488926118e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
