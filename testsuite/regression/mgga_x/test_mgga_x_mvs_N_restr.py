
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_mvs_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mvs", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.885509638958514e+00, -4.786667541711137e+00, -4.648125750088282e+00, -4.456123963631997e+00, -4.194305199974996e+00, -3.845409420106682e+00, -3.395319001532112e+00, -2.840149289858531e+00, -2.194754727514751e+00, -1.497681550524688e+00, -7.986797994396018e-01, -5.759524857015776e-01, -5.823649756366551e-01, -4.935138011300677e-01, -3.330418327882720e-01, -1.680379978495470e-01, -5.372046637506227e-02, -9.746121326213733e-03, -9.261183546319826e-04, -3.443688435215193e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_mvs_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mvs", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.325406969288989e+00, -6.190356380280132e+00, -6.000892811495972e+00, -5.737968889967894e+00, -5.378725184832537e+00, -4.898605092618804e+00, -4.276815967170597e+00, -3.507824883463636e+00, -2.628948656363450e+00, -1.804779207824124e+00, -1.112933442515364e+00, -8.072847403578332e-01, -9.590081621749214e-01, -6.650406264724701e-01, -4.239695410959850e-01, -8.800859704177721e-02, -8.139352049151799e-02, -1.817225082802101e-02, -1.831360101518235e-03, -6.883250184541175e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mvs_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mvs", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.502067471381529e-06, -5.967318992542798e-06, -6.705046654368831e-06, -7.925524938746212e-06, -1.007090145426003e-05, -1.418178346869963e-05, -2.307283340545954e-05, -4.570898658613861e-05, -1.147889599351910e-04, -3.188750096976111e-04, -3.804579816171524e-04, -8.184876666400208e-04, -3.271427022085185e-02, -2.600697252554854e-02, -1.202256610540496e-01, -2.996476902076191e+00, -2.405876093061449e+00, 5.820175462478895e+00, 1.519959999330733e+02, 4.830133407249031e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mvs_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mvs", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.912789048329530e-03, 8.073486696290516e-03, 8.309676043427094e-03, 8.659920736325011e-03, 9.185580437846990e-03, 9.986604378488032e-03, 1.122604568522827e-02, 1.313631786868698e-02, 1.567756064089443e-02, 1.571900180860136e-02, 6.000556584363486e-03, 4.316635122852001e-03, 1.077587679017829e-01, 4.501810502851843e-02, 6.670434719645255e-02, 2.890638521580648e-01, 3.488265897800540e-02, 2.262175247494874e-03, 3.679708257577194e-05, 7.404561508135618e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mvs_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mvs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.542479142354043e-02, -1.621957330396083e-02, -1.744404928925422e-02, -1.939058442354230e-02, -2.263215192536413e-02, -2.842002041732545e-02, -3.990346626627340e-02, -6.652039915660388e-02, -1.400755815807576e-01, -2.871239067002244e-01, -2.706469936870001e-01, -6.147683689014141e-01, -5.220909309131093e-01, -1.344315669399069e+00, -3.736066102615259e+00, -1.987523940601674e+02, -4.327625432061646e+02, -1.770923208260554e+03, -1.047894968989302e+04, -1.902818988364759e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mvs_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mvs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.416616386108045e-08, 6.304663103168079e-08, 7.844255162541253e-08, 1.074327505093462e-07, 1.689543594502531e-07, 3.242209673270178e-07, 8.277730516121022e-07, 3.159342141551737e-06, 2.007871495502332e-05, 1.470644977087856e-04, -1.264220752345523e-05, -2.685697354472490e-03, 1.634529635623220e-01, 1.541119650074853e-01, 1.202706484193300e+00, 3.274956764700493e+03, 7.574924250381481e+04, 8.446055300318578e+06, 4.198247794455943e+09, 3.199109674880086e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mvs_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mvs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.409567181444255e-05, -3.779800687360878e-05, -4.385200433099060e-05, -5.432853697572373e-05, -7.400405178940918e-05, -1.155764036796820e-04, -2.194371158373331e-04, -5.447533620664026e-04, -1.826402087115664e-03, -4.723753722132518e-03, 1.398388060116138e-03, 1.862156066790608e-02, -2.769176332543918e-01, -6.333632088035163e-02, 2.173563629284559e-01, -2.834781015637378e+02, -5.490112092649682e+02, -1.888039786934463e+03, -6.804610126423787e+03, -2.099794954536193e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mvs_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mvs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.885567809834830e-13, -4.960875702409746e-13, -7.046265506176807e-13, -1.165986419340006e-12, -2.400286445102623e-12, -6.743874083622445e-12, -2.941389228096246e-11, -2.361795824532603e-10, -4.167296131269937e-09, -1.173363465408662e-07, -5.416306487087458e-06, -7.674360931896007e-05, 1.047414925128575e-02, -1.474632357693411e-02, 5.261831941783263e+00, -5.897132941224728e+04, -1.554150972119895e+07, -5.257618757514654e+10, -2.825784696967786e+15, -1.280511294988956e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mvs_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mvs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.616609674711420e-10, 6.745243604020685e-10, 8.774259930698338e-10, 1.279715115435917e-09, 2.197970289826794e-09, 4.763936981940194e-09, 1.433624716599143e-08, 6.781174488045430e-08, 5.652878426071083e-07, 5.673088143746540e-06, 7.425473172900662e-05, 4.708110061471948e-04, -3.407542316062351e-02, 2.801199138194410e-02, -2.726560704377766e+00, 5.515205243621558e+03, 1.208412039848270e+05, 1.276882366333798e+07, 5.259627647784760e+09, 1.220865008148833e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mvs_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mvs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.049594070986425e-07, -9.093174178181775e-07, -1.083273960358330e-06, -1.392533325512344e-06, -1.995474080975362e-06, -3.336368215979926e-06, -6.926858441567731e-06, -1.929676269301722e-05, -7.592281147540065e-05, -2.687439799733321e-04, -9.595599363380074e-04, -2.335871800619468e-03, 1.120206260107760e-01, -4.811231749442643e-02, 1.454631309412984e+00, -5.151098807406813e+02, -9.599430515807896e+02, -3.314850853181379e+03, -1.207130707737875e+04, -3.779159730224668e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
