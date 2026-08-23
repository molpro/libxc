
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_k_csk1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.296966923407897e+01, 3.556189670409647e+01, 3.839400564515083e+01, 4.104381146606887e+01, 4.282705663716045e+01, 4.292624133355324e+01, 4.074747544339433e+01, 3.639740444111641e+01, 3.085119667377754e+01, 2.506972818787713e+01, 1.855801913527932e+01, 5.495795824661357e+00, 1.173437426243990e+00, 1.144058496128546e+00, 1.034630447834393e+00, 8.934075670227837e-01, 8.232647558565594e-01, 7.886012831121799e-01, 7.695092523802779e-01, 7.603747199823221e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_k_csk1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.648571477563947e+00, 1.207816886769756e+01, 2.119119133167461e+01, 2.966018917783419e+01, 3.549391257608355e+01, 3.654794712393414e+01, 3.157373364856090e+01, 2.137841653159063e+01, 9.496353063947593e+00, 4.124904439133100e+00, 5.347064349514572e+00, 3.372161670707775e+00, 2.077891892430417e+00, 1.126752267063890e+00, 4.238156885840338e-01, 1.622493421466743e-01, -3.095611856645676e-02, -6.697200775475011e-02, -6.676869345014272e-02, -6.380103735044013e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.870326586230967e-04, 7.204619977752697e-04, 7.683506832108345e-04, 8.392160080991802e-04, 9.507711623671025e-04, 1.144073087292563e-03, 1.524268812889999e-03, 2.395565812514610e-03, 4.750881107777209e-03, 1.004619174009736e-02, 8.645034528253355e-03, 2.242556589178138e-02, 1.542055017424270e-01, 3.029133281267634e-01, 7.320206280020815e-01, 1.193073304640676e+00, 1.414276029841669e+01, 4.315313285405495e+02, 4.862782240123167e+04, 3.597414593058018e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk1_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.942406239332645e-03, 5.455351440855377e-03, 9.701753084749066e-03, 1.634375656176272e-02, 2.572716439330073e-02, 3.734778937486034e-02, 4.950286840332412e-02, 5.980500781000506e-02, 6.805102327870430e-02, 9.867065271575104e-02, 1.666666666666667e-01, 1.666666666666667e-01, 9.239198724715877e-02, 9.045047488995037e-02, 1.139336586531467e-01, 1.666666665607913e-01, 1.666666666666667e-01, 1.666666666666667e-01, 1.666666666666667e-01, 1.666666666666667e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.170598576010556e-01, 7.541156589898121e-01, 9.295304199854910e-01, 1.150036752200917e+00, 1.429054479523671e+00, 1.804587388337057e+00, 2.388707730193720e+00, 3.522909914247395e+00, 6.427535293694455e+00, 1.730451193041177e+01, 4.239153277108595e+00, 4.081130305988752e+00, 8.791108377551364e+00, 1.689605641305249e+01, 5.449197495697953e+01, 2.843097824574262e+01, 1.914271442609397e+02, 4.562850252709118e+03, 4.694792517190282e+05, 3.305245723518189e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.032228057049414e-06, -4.681330141599561e-06, -5.821553838850952e-06, -7.954326603241956e-06, -1.231724308482686e-05, -2.252344663621011e-05, -5.181405708139797e-05, -1.663224310419195e-04, -8.825599472146347e-04, -1.105611558497969e-02, -5.381036783617875e-03, -3.620923240079726e-02, -1.077897142009457e+00, -4.812952045271235e+00, -7.546212711294076e+01, -1.024878928055520e+02, -1.440127215780993e+04, -1.340778870086196e+07, -1.702558880269725e+11, -9.317802063129685e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk1_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.262849768113546e-05, 1.021745286866407e-04, 1.945959202636471e-04, 3.634432555781227e-04, 6.696107971144968e-04, 1.239947408500528e-03, 2.404495914173254e-03, 5.272423793912645e-03, 1.506343223838748e-02, 8.268989878812590e-02, 2.817681462947307e-132, 0.000000000000000e+00, 4.334971789054147e-01, 1.087637793533781e+00, 6.485734309396940e+00, 2.395404414852049e-05, -2.885305818058042e-129, -9.232978617785736e-128, -1.181821263076574e-125, -6.050924866952060e-123]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_k_csk1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.560645025505496e-13, 4.923409354228296e-13, 1.607128728415116e-12, 5.553494073959402e-12, 2.112253153052373e-11, 9.443066744995814e-11, 5.526436445591402e-10, 5.027507779883394e-09, 9.437466649200990e-08, 6.939485673135830e-06, 0.000000000000000e+00, 0.000000000000000e+00, 1.119554369508999e-01, 1.205230270509589e+00, 1.076781036218933e+02, 1.929763987511943e-02, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk1_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.192360974500066e-11, -1.244035533270233e-10, -3.718935594424872e-10, -1.132622798519198e-09, -3.593979241416431e-09, -1.239341579301811e-08, -5.003266949987638e-08, -2.679899518241408e-07, -2.372814028629398e-06, -6.135956776264741e-05, 0.000000000000000e+00, 0.000000000000000e+00, -6.904980046082577e-02, -3.861402405914071e-01, -1.082139467606304e+01, -3.369735661206636e-04, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk1_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.126193993718608e-08, 3.143399820512246e-08, 8.605708871323160e-08, 2.309959075567815e-07, 6.115122502748589e-07, 1.626555854855380e-06, 4.529624183556457e-06, 1.428513240020705e-05, 5.965845097780716e-05, 5.425469167828953e-04, 0.000000000000000e+00, 0.000000000000000e+00, 4.258725680085454e-02, 1.237143548850182e-01, 1.087524564384286e+00, 5.884200606856568e-06, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
