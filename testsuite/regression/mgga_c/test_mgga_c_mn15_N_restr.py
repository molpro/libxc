
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_mn15_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.627211990070048e-01, -1.602761460538621e-01, -1.565794105094508e-01, -1.508010392277988e-01, -1.413404571186415e-01, -1.250761223050258e-01, -9.652941933648551e-02, -4.917416728505601e-02, 1.686648006909041e-02, 8.344939503519572e-02, 8.189430389867319e-02, -8.359904618239190e-02, -5.440520444709984e-02, -3.264807775810825e-02, 8.143670746064624e-03, 4.083167723375263e-02, 1.339421019085043e-02, -1.807592362514095e-03, -9.319748690000518e-04, -1.293275479600079e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_mn15_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.534194851229611e-01, -3.484892360862096e-01, -3.431516764223059e-01, -3.385282548177306e-01, -3.364338967901277e-01, -3.377723764027410e-01, -3.364914071837579e-01, -3.114395889639693e-01, -2.455998220221594e-01, -1.447004878316090e-01, -5.483047128917396e-02, -1.368028543962318e-01, -1.266859556665969e-01, -1.436984341437945e-01, -1.227640203940778e-01, -2.285284379623774e-02, 3.235734345344170e-02, 8.808104565509480e-05, -1.161480643911679e-03, -1.700573981398222e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn15_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.463208569033268e-06, 2.465722856525992e-06, 2.464958021603266e-06, 2.456191200758123e-06, 2.434049934152820e-06, 2.412965023328715e-06, 2.563490977997978e-06, 4.052133000056204e-06, 1.404482349164897e-05, 7.119025816526028e-05, 5.789341960269746e-04, 1.706732537077386e-02, 1.265591699136588e-02, 2.126100171155661e-02, 1.280002078990187e-01, 6.576199974082080e-01, 1.108681967545541e+00, 5.089769796799801e-01, 6.396614467201757e-02, 1.596125864636352e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn15_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.277926482329719e-04, -6.718336159360753e-04, -2.792178049674597e-04, 3.239773030993457e-04, 1.232482971686641e-03, 2.506339669439391e-03, 3.966397861765064e-03, 4.828586803873097e-03, 4.032409813214236e-03, 1.741706404403350e-03, -1.984229147102209e-03, -1.361949022153830e-02, 1.349101074387495e-02, 3.096805163199592e-02, 1.718279936510678e-03, -3.256517640294541e-02, -2.479584268608134e-02, -2.225151216196291e-03, -3.477121112954275e-05, -6.592377767142455e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn15_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.216457888726464e-03, -3.048772263873367e-03, -2.793065580911214e-03, -2.412559656349832e-03, -1.898382290464760e-03, -1.417298779102007e-03, -1.723321836746617e-03, -4.396692311012435e-03, -1.057235608085428e-02, -6.979450564986639e-02, -3.572490378040515e-01, 5.645534647671371e-01, -8.461345467569401e-01, -7.222883214692415e-01, 3.815479921731567e-01, -3.150612707350595e+01, -9.532425002523295e+00, 1.821547828331042e+02, -7.676398024772072e+02, -1.375000597393775e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn15_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.658257397192552e-08, 5.039128266414154e-08, 5.617549004960061e-08, 6.504700705989087e-08, 7.854711297993161e-08, 9.734690091704308e-08, 1.106172476566609e-07, 2.884156441787255e-08, -3.679603707129729e-07, 1.534391114404884e-05, 8.454744298048377e-04, -2.377943514266200e-02, -7.811222316953412e-02, -1.894383690191323e-01, -4.106435176977417e-01, 1.730782911027947e+02, 6.182314719178957e+03, 1.000951176013192e+05, 1.462729827656202e+06, 2.734848339369681e+07]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_mn15_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.338417423208903e-05, -2.932290411716840e-05, -3.789334288125288e-05, -4.975210345474255e-05, -6.404067829168817e-05, -7.303594501914354e-05, -4.692524720772061e-05, 8.143356418408616e-05, 3.122060978061920e-04, 8.185451003399033e-04, 1.589663733230958e-03, -2.622999590132621e-02, 4.008394774474716e-01, 6.570759312683521e-01, -1.071037047948388e-01, 1.536370024989221e-01, -5.581118426922441e+01, -1.954369326428725e+02, -3.588382994506630e+02, -5.091896838436964e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn15_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.401091861961780e-13, -3.879393353968611e-13, -4.679649839894238e-13, -6.110354182107983e-13, -8.935573306157900e-13, -1.551537831149245e-12, -3.700701733932851e-12, -1.887103842661280e-11, -3.588190719122895e-10, -2.089098682071317e-08, -4.523841815147804e-06, -3.715293498528117e-03, -1.005509183636417e-02, -6.273654581078693e-02, -5.346264666781781e+00, -1.597279916926003e+03, -5.596316934982551e+05, -2.820627300602032e+08, -4.875330076759249e+11, -6.992832557367163e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_mn15_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.033386071693167e-10, -9.781040090670743e-10, -1.091089918124832e-09, -1.262281506290953e-09, -1.513819701123614e-09, -1.817577384827115e-09, -1.698609177349647e-09, 2.900423152820484e-09, 4.704050767164917e-08, 4.345832744349933e-07, 8.057669496461558e-06, 2.462458557358416e-03, 2.426865319922148e-02, 1.216144775060853e-01, 1.917806540457962e+00, 2.301427103680579e+01, 1.861239576859260e+02, 4.379684921943799e+02, 3.341906622014450e+02, 8.616115486927750e+01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_mn15_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn15", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.573117449255718e-06, 2.738305015263818e-06, 2.961898328664102e-06, 3.236671289851184e-06, 3.475184809639189e-06, 3.300454054229631e-06, 1.444253315204269e-06, -5.268332789111035e-06, -2.064875446947096e-05, -5.300407205505907e-05, -1.199050695577006e-04, 8.248170792610996e-04, -1.909269673081414e-01, -6.095380863002650e-01, -1.143828596218631e+00, -1.959907616695003e+00, 5.013207905292546e+01, 1.958785254107462e+02, 3.896704472470552e+02, 5.843752767803617e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
