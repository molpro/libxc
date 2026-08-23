
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_modtpss_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_modtpss", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.696490409111902e+00, -4.601504752592083e+00, -4.468389519255899e+00, -4.283962238077279e+00, -4.032618729374918e+00, -3.698111131491891e+00, -3.267955037234409e+00, -2.742189452071616e+00, -2.148740883079314e+00, -1.560008957962702e+00, -1.029070542282491e+00, -6.496284693979448e-01, -5.601816120609215e-01, -4.787036344615264e-01, -3.418293099120674e-01, -2.206472113200111e-01, -1.210230889802804e-01, -4.193446853220668e-02, -8.770073805276628e-03, -9.701626090629276e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_modtpss_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_modtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.751165652856529e+00, -5.640531807896496e+00, -5.485327330523443e+00, -5.269901832081144e+00, -4.975286536270433e+00, -4.580356207037334e+00, -4.064210547926677e+00, -3.408173942288343e+00, -2.595975250361577e+00, -1.672118749369005e+00, -9.761961084179982e-01, -8.296169655633060e-01, -7.284990571891816e-01, -5.826245988593446e-01, -3.869298285167692e-01, -1.901212526196792e-01, -1.342695712350001e-01, -5.473401307773169e-02, -1.168198747419093e-02, -1.293533891169831e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_modtpss_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_modtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.455253013690452e-05, -1.500646273251519e-05, -1.567592897680907e-05, -1.667284250544952e-05, -1.817757689189664e-05, -2.049928860690138e-05, -2.427245529493450e-05, -3.159780663439522e-05, -5.547627274093335e-05, -1.980903925779537e-04, -1.182124534901652e-03, -2.640049973530742e-03, -1.500368599274981e-02, -4.198061184796054e-02, -9.008467616835039e-02, -5.770835366330231e-01, -1.839142240460211e+00, -2.655877967324343e+00, -3.115898553770573e+00, -3.436715761258039e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_modtpss_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_modtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.063642489940819e-02, 2.000215127301230e-02, 1.911206950258593e-02, 1.787636448052566e-02, 1.618790723977083e-02, 1.393736759269810e-02, 1.106248352540324e-02, 7.682228722707248e-03, 4.369304591646229e-03, 2.209312945894163e-03, 1.506945723527221e-03, -3.183102243295003e-04, 8.751909546381964e-03, 3.351890099002111e-02, 1.660510215696113e-02, 2.521632346301175e-03, 2.754758685166203e-05, 6.364667896381604e-09, 6.146918838974802e-14, 7.210667027034277e-21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_modtpss_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_modtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.154415241776327e-03, -5.273954190204513e-03, -5.456297505163434e-03, -5.746797507483199e-03, -6.249484950468091e-03, -7.262469661850522e-03, -9.869501769248060e-03, -1.890511401825643e-02, -5.745191518794185e-02, -1.876993132694968e-01, -3.909000945858077e-01, -4.464433400295629e-01, -6.934501716631141e-01, -8.142943457479436e-01, -3.063098458672284e+00, -5.030195053175678e-01, 4.675864332051867e+01, -4.225054211466968e+02, -1.347349789580124e+04, -1.116642245574368e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_modtpss_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_modtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.188364402843131e-07, -1.346751529496192e-07, -1.609778282617728e-07, -2.073555124329271e-07, -2.961403926191489e-07, -4.855629893803916e-07, -9.450549136278201e-07, -2.170105264473958e-06, -4.541122804940532e-06, 7.970290190406603e-06, 1.888269364950663e-04, 7.209783113877371e-03, 2.629975217066408e-02, -1.612232226603218e-01, -3.294446952346150e-01, -3.699043871115707e+01, -6.262692095170198e+03, -3.253063661663405e+05, -4.360980399572603e+07, -3.560598912361623e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_modtpss_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_modtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.348623323002400e-04, 1.441342633446271e-04, 1.584357382942464e-04, 1.811276454888960e-04, 2.185241805722696e-04, 2.832076626809838e-04, 4.014594157434109e-04, 6.283368393104050e-04, 1.070581014813575e-03, 1.920411153793013e-03, 3.692754048462382e-03, -7.833561916109653e-03, 1.277390156910377e-02, 1.981339090375754e-01, 9.230461755838482e-01, 1.342487862089802e+00, 3.966269651719384e-02, 2.162037632576691e-03, 6.797045465451549e-06, 1.214565813879765e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_modtpss_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_modtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.462325099941263e-12, 1.802980420528339e-12, 2.428982506159314e-12, 3.705630899048024e-12, 6.719495200692217e-12, 1.543645408849242e-11, 4.864739237330229e-11, 2.297509661149747e-10, 1.768314375184142e-09, 2.935313767302724e-08, 2.629882349426634e-06, -8.218586001763951e-04, -2.135734910314762e-02, 1.311906870824287e-01, 3.270072808556194e+00, 6.032140932361768e+02, 5.913870226262934e+05, 9.809801523100324e+08, 1.583388171763679e+13, 1.003782049877588e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_modtpss_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_modtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.218675287921053e-09, 2.339872019863706e-09, 2.509426235443977e-09, 2.730315210046912e-09, 2.945870208289254e-09, 2.791233886108557e-09, 2.623477609160788e-10, -1.652468005037505e-08, -1.295627981194437e-07, -9.455128968563615e-07, -6.135122259040026e-06, 7.593341376150367e-04, 3.179694336856127e-02, 4.101330623810464e-02, -8.365377280180336e-01, -6.526555249257511e+00, 2.759432223264463e+01, -4.790334053915889e+00, -3.924930979135522e+00, -6.179728732437632e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_modtpss_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_modtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.276560781723022e-06, -9.496549099028752e-06, -9.807769276791304e-06, -1.023902985520398e-05, -1.080684445986582e-05, -1.145181980829265e-05, -1.180769610088938e-05, -1.044647889310048e-05, -3.343884609994903e-06, 7.968373939641154e-06, -5.350596029842401e-05, -1.270238522335152e-04, -4.199855194744539e-02, -2.109002974230990e-01, -7.312972571446553e-02, -1.336735268839621e-01, -3.515288649563719e-01, -8.903094030951575e-05, 7.255487190732783e-06, 1.747452682945401e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
