
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_revtpss_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtpss", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.479844598634615e-02, -5.427199190329046e-02, -5.350598804547127e-02, -5.238539494839402e-02, -5.073278894129426e-02, -4.826631811797975e-02, -4.452314017180758e-02, -3.873948750162401e-02, -2.988991329636329e-02, -1.847804933152232e-02, -1.293346062337476e-02, -4.389467429895472e-02, -5.285530253385545e-02, -3.770280545476135e-02, -2.254898147977633e-02, -7.768049262394220e-03, -7.665429349145419e-04, -1.241744038381007e-05, -1.585742559231618e-08, -5.332726017462805e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_revtpss_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.219797593086090e-01, -1.207037320996716e-01, -1.188901873785247e-01, -1.163278904131546e-01, -1.127410122251227e-01, -1.077931697578872e-01, -1.011202118694490e-01, -9.233448513773219e-02, -8.035856763062039e-02, -6.177693934292754e-02, -5.003896037209984e-02, -8.827098424777023e-02, -8.179684625343484e-02, -7.446507479874249e-02, -5.848606176581130e-02, -3.007602239407307e-02, -3.991085355980805e-03, -7.186453666586928e-05, -9.566212890086331e-08, -3.296989745108629e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revtpss_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.310089696492538e-06, 1.363617881116230e-06, 1.443849912109258e-06, 1.566173394445652e-06, 1.757185590430801e-06, 2.065939055424162e-06, 2.593221706334627e-06, 3.595672100299666e-06, 6.008820771186242e-06, 1.458637475120304e-05, 9.015770150379572e-05, 3.365385988234696e-03, 9.296012681805282e-03, 1.331421920623402e-02, 2.915866837124964e-02, 9.696916052611643e-02, 1.801852596379465e-01, 1.096102560239552e-01, 1.748607375170924e-02, 4.709184973559134e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revtpss_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.363567334948175e-03, -1.315380428003262e-03, -1.246679648443425e-03, -1.149127774367496e-03, -1.011547635036774e-03, -8.200786278456013e-04, -5.616904268862106e-04, -2.404972033811724e-04, 7.124814999813882e-05, 1.904109252944013e-04, 1.112293395530705e-04, 4.893963107456783e-06, -3.042374998026715e-04, -8.766482174498722e-04, 2.611278018408769e-03, 2.938846013269525e-03, 4.588769443651918e-04, 8.962914586457593e-06, 1.217331806970277e-08, 3.958177482423213e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revtpss_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.918747780919587e-04, -4.201709960820655e-04, -4.639462290923428e-04, -5.337468259341796e-04, -6.498085037645055e-04, -8.542943400173353e-04, -1.245865652481921e-03, -2.112086487459885e-03, -4.733733126991257e-03, -1.637523949631779e-02, -6.449974969029997e-02, -2.311355340120278e-02, 5.063841158122482e-03, -9.891030743086787e-02, -6.174892831682408e-01, -5.535623698014779e+00, -1.651983662901860e+01, -1.087561705435010e+01, -1.722921069794133e+00, -4.516445622329566e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revtpss_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.553210177691113e-09, 4.184529606467806e-09, 5.271317991407897e-09, 7.287639546023824e-09, 1.143798236254842e-08, 2.128362585743440e-08, 4.953298269622353e-08, 1.539350054609765e-07, 7.136391828983350e-07, 6.505099638426099e-06, 1.659320348474025e-04, 8.597131643752074e-04, -1.004620844256350e-02, 4.692303687277238e-02, 6.677409731784069e-01, 2.650283257253689e+01, 9.830237361594931e+02, 2.124278765736183e+04, 3.981268133440275e+05, 8.064708969397373e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_revtpss_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.999147255638681e-07, 7.126590669562096e-07, 3.994039346045934e-07, -1.520268701972243e-07, -1.183992584636098e-06, -3.247304373941965e-06, -7.586705412170596e-06, -1.632931797776941e-05, -2.628328550410057e-05, 3.102829323172744e-06, 6.868142066178828e-05, -1.348597533339247e-04, -1.163414133335868e-03, -3.832991760772698e-02, -1.032343904185947e-01, 3.579838726473979e-01, 1.651780880725325e+00, 1.192189657900333e+00, 1.931008302378464e-01, 4.749277377129253e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revtpss_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.369305217783983e-14, 9.366717126180820e-14, 1.089586533654380e-13, 1.316517029942229e-13, 1.580320444033503e-13, 1.281324155458458e-13, -5.409890873159798e-13, -8.654931988689241e-12, -1.449848092705852e-10, -4.732973518842728e-09, -7.361517357698923e-07, -7.379341465900697e-04, -7.403977147875552e-03, -5.243647327815883e-02, -1.517594467297763e+00, -2.395190853332584e+02, -8.968379786028378e+04, -6.053574633497992e+07, -1.332386568527520e+11, -2.063145024932204e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_revtpss_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.666713085189581e-10, -6.236609033985754e-10, -7.146405861423994e-10, -8.659796210160498e-10, -1.131449466642763e-09, -1.626311623893195e-09, -2.588494451200067e-09, -4.259695571201852e-09, -3.873829307492298e-09, 3.078040518497895e-08, 5.478473125941765e-07, 1.275961597335905e-05, -9.502601930931800e-04, 2.439941536869150e-04, 1.693308622758071e-01, 3.231162257021721e+00, 2.295798243991856e+01, 6.848227853829697e+01, 8.097277740076851e+01, 2.543553039419911e+01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_revtpss_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.384704637350281e-06, 1.437516764860155e-06, 1.515035900131114e-06, 1.628996511411882e-06, 1.795211840201550e-06, 2.028213595001221e-06, 2.306815687768697e-06, 2.413847894626059e-06, 1.400144709582403e-06, -2.631264266729465e-06, -1.006876959451908e-05, -2.016220950002190e-06, 1.682200452443092e-03, 2.422106640157190e-02, -5.975478258150550e-02, -7.666498952638394e-01, -1.782089118834313e+00, -1.213800546356531e+00, -2.048761835432415e-01, -5.263116366591693e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
