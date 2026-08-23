
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_dldf_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_dldf", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.867143369621862e-02, -7.888078235166802e-02, -7.919593981075317e-02, -7.967708257617347e-02, -8.042195153198352e-02, -8.158275023222221e-02, -8.335027145600987e-02, -8.569916106528892e-02, -8.696628282202985e-02, -8.004899810686983e-02, -6.954289946097189e-02, -5.775775462178772e-02, -5.107439088421075e-02, -4.971625448726957e-02, -4.853961205170336e-02, -2.107571441498392e-02, 2.473903879546075e-02, 2.253751457395692e-02, 6.476068551872822e-03, 8.121163384907849e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_dldf_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_dldf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.461891358740532e-02, -6.349416621017741e-02, -6.195592226368508e-02, -5.992152764860222e-02, -5.740615216676437e-02, -5.477110768518102e-02, -5.343382342686792e-02, -5.782774704777510e-02, -7.955996995975509e-02, -1.315092743524382e-01, -1.447799843533107e-01, -4.279270149881741e-02, -5.982660086403097e-02, -3.305999921194954e-02, -5.764370244311618e-02, -1.111602723584232e-01, -3.354212024656711e-02, 2.008749476203761e-02, 7.268909679470204e-03, 9.142674322535876e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_dldf_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_dldf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.352073246077431e-07, 1.170151914679387e-07, 8.723257526904148e-08, 3.646095986979657e-08, -5.400621405678287e-08, -2.210261633192686e-07, -5.229370345500916e-07, -8.946835727621303e-07, 6.740597408652511e-07, 2.642309426750109e-05, 2.180861967366565e-04, -1.595405743796177e-03, 2.589942485428763e-03, -6.076253136027433e-03, 1.163822418625018e-02, 5.337646811723210e-01, 5.021727775349280e+00, 3.144208590167169e+01, 8.106479044871847e+02, 9.105928231647331e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_dldf_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_dldf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.048799262342193e-04, -7.820372535984241e-04, -7.507081559704433e-04, -7.088783357893412e-04, -6.555894792476048e-04, -5.935315975238545e-04, -5.343193795945921e-04, -5.047426787858463e-04, -5.353077534495524e-04, -5.831579377573038e-04, -4.505979136482711e-04, -1.679100519292786e-04, -1.780985776052374e-03, -3.893840946691542e-03, -6.231172266417754e-03, -8.881395546950036e-03, -8.331905546046297e-03, -5.018386796058220e-03, -1.751907678108460e-03, -2.763008785551932e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_dldf_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_dldf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.561330135261993e-04, -5.678029356998332e-04, -5.804257088217177e-04, -5.874321754334896e-04, -5.651952674832814e-04, -4.299080323423935e-04, 1.375075060616862e-04, 2.507099169440732e-03, 1.323894550735535e-02, 5.934730790478366e-02, 2.013004907731940e-01, -1.026441055366799e-01, -1.606857338082415e-01, -3.353194700308801e-02, 2.400744815697783e+00, 7.018019430169117e+00, -1.494967749380793e+02, -4.204726153669093e+02, 5.734618031298402e+03, 6.419896945557529e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_dldf_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_dldf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.239445324766064e-09, 1.004888151881906e-08, 1.125772586999650e-08, 1.302490665734734e-08, 1.530842555813186e-08, 1.625918313094353e-08, 6.360963643180459e-10, -1.611023902709987e-07, -1.888603082313370e-06, -2.629905813725873e-05, -5.819463656339867e-04, 7.915757920588429e-03, 6.067886952307817e-02, 1.109011931233364e-02, -2.520581460841953e+00, -4.841948682634408e+01, 9.681515306439140e+03, 1.376839851627069e+06, 9.840149437627296e+08, 7.298273411933288e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_dldf_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_dldf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.103941135912151e-06, -8.305103574372294e-06, -8.558649008040335e-06, -8.831187861821213e-06, -8.973731492199279e-06, -8.470247718236130e-06, -5.669747692380481e-06, 4.333716467077571e-06, 3.364303705314185e-05, 1.007133958857139e-04, 2.381714783064890e-04, -3.018467228941317e-04, -7.782262219934890e-03, -8.169759828940661e-03, 1.004211861698876e-01, 3.420637442813833e-01, -4.165520053889232e-01, -3.301536519461362e+01, -1.659050342369634e+03, -2.208474026048918e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_dldf_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_dldf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.183219477119353e-14, -1.034988940948763e-13, -1.211426547904322e-13, -1.460350743320010e-13, -1.670420489520521e-13, -6.743940994824500e-14, 1.250039013955347e-12, 1.716500692442326e-11, 3.062250947800371e-10, 1.007964633885716e-08, 1.217279601161951e-06, -2.810442049530997e-04, -2.462973106492698e-02, 2.229313550515086e-02, 2.643318770858863e+00, -5.101894699321575e+00, -1.023144933714857e+06, -3.813600013274170e+09, -8.421300311178206e+13, -6.024570637268505e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_dldf_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_dldf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.564538864952955e-11, -5.099617745333321e-11, -6.040296054508145e-11, -7.862070719373636e-11, -1.192642205085484e-10, -2.298132281286551e-10, -6.194042413907631e-10, -2.495032982267467e-09, -1.538191413473826e-08, -1.508418780651056e-07, -2.711747148840635e-06, -3.644928810936469e-05, -1.602249550319277e-03, -1.591787114873921e-02, -3.408427822356480e-01, -1.338619739422148e+01, -1.614781822619148e+03, -9.426036928062446e+05, -4.454649904195431e+09, -4.035081287228788e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_dldf_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_dldf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.656733005268650e-07, 3.783355214038542e-07, 3.975049982789994e-07, 4.273462447431187e-07, 4.760576334787460e-07, 5.625559556728561e-07, 7.405929000743846e-07, 1.200017420366985e-06, 2.725372258852282e-06, 8.635047482920158e-06, 2.939127336255436e-05, 7.873157280407620e-05, 5.750057235049970e-03, 3.551737390345035e-02, 1.923549214197343e-01, 1.735607471507523e+00, 2.179796654138230e+01, 4.531587148515002e+02, 1.965633631119349e+04, 2.449281573819706e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
