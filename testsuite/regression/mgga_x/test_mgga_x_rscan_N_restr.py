
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_rscan_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rscan", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.885388403375691e+00, -4.786551246813685e+00, -4.648022856994937e+00, -4.456055836361059e+00, -4.194327281071904e+00, -3.845671093565610e+00, -3.396222994293630e+00, -2.842510774053084e+00, -2.199631746065504e+00, -1.506396054203301e+00, -8.387719624582128e-01, -5.691116132098839e-01, -5.789795164311629e-01, -4.941035287451017e-01, -3.339050477795325e-01, -1.766341218607798e-01, -7.525547008255978e-02, -2.114495038667159e-02, -2.799865669117374e-03, -1.281417733310223e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_rscan_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.522701994083987e+00, -6.391120322093012e+00, -6.206627803175759e+00, -5.950750045720001e+00, -5.601143784775972e+00, -5.132483074629041e+00, -4.514821845937961e+00, -3.699894660641676e+00, -2.758588833162936e+00, -1.787051315651658e+00, -1.137353527475854e+00, -7.845592907092234e-01, -8.661039324004656e-01, -6.633375641908722e-01, -4.156638686412192e-01, -1.726142200437276e-01, -6.754878294201895e-02, -3.432274115799529e-02, -5.040831108881804e-03, -2.469598788234423e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rscan_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.940607598009920e-08, 7.084818218085322e-08, 6.961158607675584e-08, 5.631008905013710e-08, -9.941840437505378e-09, -3.445219410290330e-07, -2.415467648396721e-06, -1.719887351470298e-05, -7.297964485120133e-05, -3.596958989783716e-04, -7.181901121441614e-04, -5.689135041725020e-03, -2.348513430647147e-02, -4.071159184014861e-02, -1.609285466494016e-01, -1.345193486581923e+00, -7.483723612200261e+00, 1.338895786816625e+01, 3.560375480974770e+02, 1.609108265540971e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rscan_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.814815238469602e-05, 6.975822168795253e-05, 9.073026005374818e-05, 1.326391695934985e-04, 2.294476868443130e-04, 5.032189617903812e-04, 1.494612937818480e-03, 5.319806471122492e-03, 1.034675571403841e-02, 1.760685282225247e-02, 9.074172535599022e-03, 8.420051729959369e-03, 6.267127640733619e-02, 6.670912996139770e-02, 8.770315643191175e-02, 1.295537927891378e-01, 6.464270825499864e-02, 1.742874953293905e-04, 5.507019522928346e-12, 1.411271578301863e-22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rscan_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.978115886306701e-03, -1.004282348439227e-02, -1.000760118622617e-02, -9.585659861063587e-03, -7.773127130851727e-03, -7.074510601735054e-04, 2.640997335282595e-02, 7.057547789281113e-02, -7.627811758767047e-02, -1.801268955162931e-01, -3.152466185893623e-01, -1.037207983947322e+00, -9.468292518064657e-01, -1.462809953542394e+00, -3.993569772669309e+00, -3.570637726673428e+01, -1.342193693801271e+01, -4.703766419223575e+02, -1.298264472937221e+04, -5.776495003334915e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rscan_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.967417022173933e-08, -7.699848625835594e-08, -1.110837688747122e-07, -1.880011946355499e-07, -3.987725757553080e-07, -1.149925817121146e-06, -4.701614532864435e-06, -1.757642337453958e-05, 9.580424435165002e-07, -2.341808643972458e-05, 9.816255990832421e-05, -7.210925499859766e-03, 5.802596139461853e-02, 1.698588352047924e-01, 1.196241124852594e+00, 3.282758485171359e+02, -5.171189772935085e+03, -5.564754488787178e+04, 1.933002583367464e+09, 7.705310754108644e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rscan_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.296478201928246e-05, 1.010400839377538e-04, 1.340889504338717e-04, 2.011106221561297e-04, 3.581486294405857e-04, 8.020670020367516e-04, 2.278900647001948e-03, 5.102458079827761e-03, 3.539623657328323e-04, 3.594466271153219e-03, 1.333338307923908e-03, 6.140582183474799e-02, 3.522421864301457e-02, -1.732054322689427e-02, 4.088955650111483e-01, -2.062384388255627e+01, 1.040195086051271e+02, 1.349951830003701e+02, 1.125174212397152e-03, 4.206723325908739e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rscan_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.692546682443286e-12, 2.333944675600107e-12, 3.703594005139362e-12, 7.184018268069777e-12, 1.852112744733069e-11, 7.059943944007983e-11, 4.308066613755995e-10, 2.903981434378593e-09, 1.390951454078933e-09, 1.321596139920777e-07, -2.833761200307354e-06, 9.647532784024166e-04, 7.435747567132284e-03, 1.241419146599001e-01, 5.694856849675459e+00, -3.974870031638925e+03, 8.030462140657488e+05, 6.461724607385374e+08, -9.788228570263752e+14, -2.804133666173711e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rscan_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.406344597924266e-09, -3.123619363703882e-09, -4.543762081060441e-09, -7.776884713780939e-09, -1.674684184110047e-08, -4.928898461319193e-08, -2.075522348986342e-07, -8.220621579869150e-07, -1.581343091962788e-07, -5.856301001210265e-06, 4.910018867520067e-05, 6.478303182454802e-04, -7.553167898322610e-04, -1.461472543884670e-01, -2.514863409435473e+00, 3.832885778514818e+02, -6.193828641668453e+03, -7.619163625779711e+05, -7.941763814909802e+02, -2.336731733602061e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rscan_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.446384115573996e-06, 4.207900620296814e-06, 5.605406921973151e-06, 8.455133931874093e-06, 1.518833731557681e-05, 3.447333484551857e-05, 1.000859312777970e-04, 2.328589610393629e-04, 1.775644854707294e-05, 2.608906694183541e-04, -6.806542240121589e-04, -6.448107488435592e-03, -3.344097678280422e-02, 1.793653900091101e-01, 1.136645703597846e+00, -3.690473668088453e+01, 4.265768010953416e+01, 1.952500797472773e+02, 1.809034176574719e-03, 7.203140879677270e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
