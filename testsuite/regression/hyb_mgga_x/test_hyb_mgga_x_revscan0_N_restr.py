
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_revscan0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revscan0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.663450682556538e+00, -3.589287168580250e+00, -3.485335497571367e+00, -3.341271372348497e+00, -3.144826064581506e+00, -2.883071795580577e+00, -2.545521310398166e+00, -2.129736971677354e+00, -1.648891741673117e+00, -1.131834421411680e+00, -6.200508429160514e-01, -4.174210943700659e-01, -4.276855973560036e-01, -3.712336834304441e-01, -2.506183352811656e-01, -1.301454511059189e-01, -4.894930558695555e-02, -1.247309978723200e-02, -1.638928298278412e-03, -7.496012794223497e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_revscan0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revscan0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.815675142040447e+00, -4.716006933293133e+00, -4.576284333379725e+00, -4.382599244586399e+00, -4.118390118409548e+00, -3.766119482454437e+00, -3.311303877774095e+00, -2.749548171617869e+00, -2.093904679623847e+00, -1.346199759770162e+00, -8.431732812679685e-01, -5.740140084170493e-01, -6.716212625776840e-01, -4.991300563636294e-01, -3.086543349229728e-01, -1.422792439830808e-01, -4.531768716394341e-02, -1.882965498172676e-02, -2.921410669122616e-03, -1.443956206149411e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revscan0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revscan0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.135511894964493e-06, -2.307090625370015e-06, -2.577719702600921e-06, -3.022116858399585e-06, -3.795357798142300e-06, -5.258104436817671e-06, -8.385158058741929e-06, -1.643738382406206e-05, -4.496676930438740e-05, -2.656703895734102e-04, -6.808412049843188e-04, -4.529778430174913e-03, -2.383623725530715e-02, -3.266012411477233e-02, -1.382710290908297e-01, -7.077516027113665e-01, -5.427017239523706e+00, -1.686734448209278e+00, 1.858137755864931e+02, 9.371977792568838e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revscan0_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revscan0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.175595019102697e-03, 3.230675200925012e-03, 3.311143910894308e-03, 3.429517691333365e-03, 3.605470211227484e-03, 3.871441465585435e-03, 4.286357145909269e-03, 4.983606049578893e-03, 6.445595431800732e-03, 1.302189565930244e-02, 8.553035779446815e-03, 6.438442732917534e-03, 6.592437668456673e-02, 5.380705053914431e-02, 7.522580921335009e-02, 6.887888587156171e-02, 4.633046155327394e-02, 2.569805485432581e-03, 5.163048820115748e-05, 1.264882770957649e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revscan0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revscan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.764007893377839e-03, -1.018210104687683e-02, -1.081370925230738e-02, -1.178822998723559e-02, -1.333755048315135e-02, -1.590678016073043e-02, -2.042417271643844e-02, -2.901624077513022e-02, -4.694339479193228e-02, -9.321739213416411e-02, -2.713053961867907e-01, -7.957307051666392e-01, -1.246614520186890e+00, -1.124165455614865e+00, -2.840116681819326e+00, -2.169231138913958e+02, -6.481475605254568e+02, -1.766437680512880e+03, -1.327266739645289e+04, -3.582514016065138e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revscan0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revscan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.490753152204254e-09, 7.117765271217055e-09, 8.077360958238440e-09, 9.543262101076745e-09, 1.163596832355777e-08, 1.336766588726588e-08, 3.551243354227101e-09, -1.358408761473049e-07, -2.263363062142406e-06, -7.794298194766335e-05, -1.008810858166232e-04, -5.838384096721815e-03, -1.964404812852303e-02, 1.609821624306852e-01, -9.183089260555202e-01, 4.083223026686076e+03, 1.259429119141799e+05, 9.502250019967651e+06, 5.413660076455662e+09, 5.678022926484757e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revscan0_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revscan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.776397249429742e-06, 5.556787520659856e-06, 6.867058902262227e-06, 9.213424788700846e-06, 1.381017656457860e-05, 2.401061105010786e-05, 5.092232969420737e-05, 1.418098384720831e-04, 5.949991620990994e-04, 5.519544475690837e-03, 4.220176893209555e-03, 4.874772210382174e-02, 3.006874969708397e-01, -5.148315497763457e-02, 1.414088169765120e+00, -3.751534922668993e+02, -9.442685580380819e+02, -2.306556233194897e+03, -9.633459712229273e+03, -3.589832909340876e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revscan0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revscan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.037626608503912e-13, 2.579982727151248e-13, 3.620099501887320e-13, 5.883653614796120e-13, 1.179449999243809e-12, 3.187469882851667e-12, 1.317681822024307e-11, 1.002649191635080e-10, 1.909006722379431e-09, 1.863809828438385e-07, -9.663758043450695e-06, 7.723789753765972e-04, -7.419600112876444e-03, 1.921204207589929e-01, 1.497852717701807e+01, -7.980856840088165e+04, -2.605456853014005e+07, -6.121745588730997e+10, -3.813791705501057e+15, -2.314507676031909e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revscan0_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revscan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.338806121502676e-10, -2.794313924882324e-10, -3.607490594187757e-10, -5.203398836540147e-10, -8.792922609390829e-10, -1.861973077959439e-09, -5.438506279363225e-09, -2.525443148998921e-08, -2.378257421783158e-07, -8.513761002646136e-06, 1.350003740869695e-04, 5.196578972330782e-04, 4.655985244262665e-02, -2.771686138165856e-01, -7.586047860328067e+00, 7.440442233742330e+03, 2.048496815330708e+05, 1.546261618769392e+07, 7.428050946719316e+09, 2.086322253000988e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revscan0_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revscan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.711858010498460e-07, 3.055650841062588e-07, 3.626955913144979e-07, 4.638325545498505e-07, 6.599416852641997e-07, 1.093607464475047e-06, 2.254524174907540e-06, 6.386352155949253e-06, 2.974147849296978e-05, 3.901980008580229e-04, -1.781924408282471e-03, -5.112984009823271e-03, -1.909451141709353e-01, 4.170484941484452e-01, 3.885708310628436e+00, -6.936175266768834e+02, -1.613471553729692e+03, -3.995026057049592e+03, -1.702509117113598e+04, -6.456600774482125e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
