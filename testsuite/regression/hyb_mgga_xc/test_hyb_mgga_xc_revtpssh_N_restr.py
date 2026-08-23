
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_revtpssh_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_revtpssh", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.359588917949915e+00, -4.271844387186675e+00, -4.148795649469438e+00, -3.978140890554248e+00, -3.745188752015231e+00, -3.434323313827463e+00, -3.032696433937186e+00, -2.537567677934053e+00, -1.969631100932471e+00, -1.393762081482568e+00, -8.978845640417922e-01, -6.250824935541621e-01, -5.554258810782963e-01, -4.652128888395605e-01, -3.254844584619151e-01, -1.945137925459288e-01, -1.042261992040435e-01, -3.744696464842535e-02, -7.889997764965335e-03, -8.731419601423361e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_revtpssh_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_revtpssh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.228982671999060e+00, -5.129176194147551e+00, -4.989286494016095e+00, -4.795388457843903e+00, -4.530804597952842e+00, -4.177437260923837e+00, -3.718505810904464e+00, -3.141320435969610e+00, -2.436379284476668e+00, -1.624673243340492e+00, -9.672205861218968e-01, -8.425717717984281e-01, -7.415925764322501e-01, -5.963562490808383e-01, -4.120537235577321e-01, -2.054773517888305e-01, -1.100621169299089e-01, -4.815441548154097e-02, -1.050156863874833e-02, -1.164162951567226e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_revtpssh_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_revtpssh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.683857260357089e-05, -1.745647387302203e-05, -1.837845118903865e-05, -1.977456815082279e-05, -2.193157570596431e-05, -2.535733436796825e-05, -3.102773364746901e-05, -4.124709839484013e-05, -6.514011153318430e-05, -1.669846452660462e-04, -7.935866658861577e-04, 2.218846256596824e-03, -8.501292772315604e-04, -3.070787572573024e-02, -6.233987619547794e-02, -3.506178834143479e-01, -1.994418908434421e+00, -4.014781333177184e+00, -5.020247845407854e+00, -5.566866470904311e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_revtpssh_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_revtpssh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.447821529047681e-02, 2.390680760180117e-02, 2.310495123891011e-02, 2.199096729821085e-02, 2.046488839160917e-02, 1.841533331440790e-02, 1.574252556475579e-02, 1.241794781038944e-02, 8.611664146538432e-03, 4.914228392467594e-03, 2.282046648952912e-03, -5.463998390672500e-04, 6.470864953733294e-03, 4.025186644011505e-02, 3.162374409371707e-02, 9.759223503462311e-03, 6.158913740405155e-04, 9.079395614000331e-06, 1.217596027517917e-08, 3.958183982331195e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_revtpssh_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_revtpssh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.304922907936690e-03, -4.363984881256525e-03, -4.447586867048627e-03, -4.567491687492510e-03, -4.750478582031453e-03, -5.091276243790537e-03, -6.045127035583055e-03, -1.015828210524275e-02, -3.204731330666998e-02, -1.312525228911072e-01, -4.060951756777785e-01, -3.992518174199666e-01, -5.928995389878154e-01, -8.992330582151256e-01, -2.544142796507599e+00, -1.063501514008992e+01, 3.409582685225383e+01, -2.909517212598989e+02, -1.199903146370450e+04, -1.004841673035952e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_revtpssh_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_revtpssh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.229388438940963e-07, -1.394770604822172e-07, -1.670496511603488e-07, -2.159878122778761e-07, -3.107751917392761e-07, -5.176008400921859e-07, -1.044484741958164e-06, -2.646710049381593e-06, -8.104681218736584e-06, -2.058433585663810e-05, 3.125178925601445e-04, 3.827198847339777e-03, -1.454909146872189e-03, -7.831587808370184e-03, -6.195239614649540e-01, 6.766458858999993e+00, -4.967898557490731e+03, -4.698585315165441e+05, -7.001612846091318e+07, -5.767118322934938e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_revtpssh_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_revtpssh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.521430213442491e-04, 1.621275815572872e-04, 1.775160578243605e-04, 2.019187403599757e-04, 2.421549832718143e-04, 3.120279864871867e-04, 4.415880812709810e-04, 7.009468188911965e-04, 1.262746203826800e-03, 2.459780034311123e-03, 3.094931791477157e-03, -5.956025600855737e-03, 1.474712776201465e-02, 3.954066248797163e-02, 8.483859551556825e-01, 2.925991637598130e+00, 2.551010201165375e+00, 1.224256486463301e+00, 1.931927849106791e-01, 4.749294569327132e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_revtpssh_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_revtpssh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.970499255763517e-12, 2.404952913510558e-12, 3.196536654673410e-12, 4.792819622686113e-12, 8.508261905157944e-12, 1.907887585761760e-11, 5.872244128695894e-11, 2.737583314284489e-10, 2.144457240955782e-09, 3.210324367482344e-08, 4.107868591059822e-07, -1.188012443025332e-03, -2.197735510398303e-02, -5.647589946231431e-02, 1.595735059052548e+00, 1.991329633160120e+02, 5.138287167853668e+05, 1.431263695535636e+09, 2.544130795672793e+13, 1.625858331614179e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_revtpssh_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_revtpssh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.526751566876115e-09, 1.586617826556527e-09, 1.661515964729859e-09, 1.733942081884403e-09, 1.717098205553668e-09, 1.232463004379672e-09, -1.459890101097352e-09, -1.548986035090845e-08, -9.775681254461426e-08, -5.814577006055409e-07, 5.459447065083631e-06, 4.579231939348269e-04, 2.435365520627554e-02, 1.992192702421015e-01, 4.776189904245358e-02, -4.219570744628912e+00, 2.343509622640864e+01, 1.221681460144013e+01, 5.674824213308320e+01, 2.175415056642045e+01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_mgga_xc_revtpssh_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_revtpssh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.243249657409260e-06, -8.456844762677179e-06, -8.767036063424739e-06, -9.217529868299946e-06, -9.869060161496522e-06, -1.079821355411622e-05, -1.208220630276926e-05, -1.381081543820756e-05, -1.689946738564429e-05, -3.411576883121056e-05, -1.773404194952874e-04, 4.765927927106438e-05, -3.396690405599888e-02, -3.718324627410931e-01, -6.597138260748545e-01, -1.702937108239611e+00, -2.521693391806025e+00, -1.221040602026340e+00, -2.048820142426733e-01, -5.263116717710683e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
