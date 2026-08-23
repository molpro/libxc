
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_xc_vcml_rvv10_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_vcml_rvv10", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.537443820159549e+00, -4.450987768698670e+00, -4.329889481340491e+00, -4.162237860851041e+00, -3.934000724414736e+00, -3.630677150017249e+00, -3.241217638193771e+00, -2.765281091051307e+00, -2.226167609769409e+00, -1.644254553663132e+00, -1.013399795511432e+00, -6.854087084614146e-01, -6.121070970285009e-01, -5.158765930787801e-01, -3.654840164682364e-01, -2.125946502537863e-01, -8.009935267632558e-02, -1.723455511690023e-02, -3.284163916720359e-03, -3.617975456580530e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_xc_vcml_rvv10_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_vcml_rvv10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.758251208364908e+00, -5.639277686614183e+00, -5.472561566404099e+00, -5.241637951238046e+00, -4.927127805235107e+00, -4.509295345880832e+00, -3.975052832092029e+00, -3.337346289619251e+00, -2.697125186698879e+00, -1.238979623926810e+00, -1.138467893403849e+00, -8.976994162677604e-01, -8.372112568173364e-01, -6.775189277398563e-01, -3.823487745107112e-01, -2.601985859917884e-01, -1.216684406883424e-01, -2.625661877338012e-02, -4.409479579391896e-03, -4.824419102332888e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_vcml_rvv10_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_vcml_rvv10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.874451165374602e-06, -3.103393357557883e-06, -3.461971953559302e-06, -4.043528276497796e-06, -5.031649377401282e-06, -6.807215336226875e-06, -1.012094950865691e-05, -1.501178489120413e-05, 6.689752058550997e-06, -9.141972902554082e-04, -7.780299799008297e-04, -1.505629566764408e-03, -3.852141028327798e-03, -4.479258204178505e-02, -2.936593903280158e-01, -2.810710789171331e-01, -2.664414193082312e+00, 4.396166293487957e+00, 7.328248884811438e+00, 9.441242284397180e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_vcml_rvv10_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_vcml_rvv10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.246714861193189e-05, -9.183917050720375e-05, -1.073738169987433e-04, -1.348437998671857e-04, -1.883003010312926e-04, -3.083373451009087e-04, -6.425570749808461e-04, -1.911745918937697e-03, -8.065625859480233e-03, 3.466886895464879e-02, 2.628280614276839e-03, 1.293031343836544e-03, 1.770101562499992e-02, 7.047402457649879e-02, 1.322140306776884e-01, 2.149413937593008e-02, 4.192550086104914e-02, 1.158793781671345e-03, 3.538442861728449e-06, 5.436844236100760e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_vcml_rvv10_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_vcml_rvv10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.393569397885843e-02, -1.467581438004780e-02, -1.582369006685100e-02, -1.766912971209798e-02, -2.080496590063852e-02, -2.662278519369382e-02, -3.905946590521118e-02, -7.133301615894209e-02, -1.048785737103417e-01, 8.222916524968987e-02, -1.067173993411248e-01, -6.291483515171655e-01, -1.509831984605765e+00, -1.929214882628850e+00, -1.048933639522505e+01, -6.434078702815071e+01, -6.291755851951667e+02, -1.699373514350945e+03, -6.191295588412271e+03, -4.171334976907769e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_vcml_rvv10_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_vcml_rvv10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.283991459213940e-08, 7.408192913171031e-08, 9.396645088413556e-08, 1.325751701623550e-07, 2.185461244440547e-07, 4.529665167003945e-07, 1.314574251430011e-06, 6.055651315091264e-06, 2.506579994008338e-05, -4.918262484207810e-04, -2.128173678398995e-04, 7.474494584008106e-03, -1.051059166746736e-01, 5.485411585045161e-01, 1.930559992081093e+01, 1.262677975737576e+03, 1.103799821054589e+05, 7.089844822670065e+06, 5.659329194763128e+08, 1.753730882484605e+11]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_xc_vcml_rvv10_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_vcml_rvv10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.903471150224922e-05, -6.679830372731353e-05, -7.981001277583373e-05, -1.031556363244071e-04, -1.494117336335325e-04, -2.553239575302141e-04, -5.537472862782751e-04, -1.640035636957719e-03, -3.732579772469785e-03, 2.810577795942605e-02, -1.237849465173084e-03, 7.539042641450840e-03, 4.601960378514482e-01, -3.045757820879081e-01, -7.236034266854846e+00, -1.215776541536775e+02, -8.009432390299573e+02, -1.498194425940296e+03, -9.935056553469100e+02, -2.324514770526588e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_vcml_rvv10_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_vcml_rvv10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.211489302128145e-12, -1.549004495442180e-12, -2.207204473314388e-12, -3.677896371765572e-12, -7.685864836112884e-12, -2.229981807662030e-11, -1.039571197430064e-10, -9.334512900474321e-10, -1.106198178145590e-08, 9.424176250970039e-07, -5.232352965512705e-07, -5.573934868844214e-04, -2.892659082107626e-02, -3.626869287683159e-01, -4.862198613627330e+01, -2.530303910217074e+04, -2.212125603822849e+07, -4.222086241140742e+10, -3.795583641541471e+14, -7.172678783462510e+19]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_xc_vcml_rvv10_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_vcml_rvv10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.717667822194007e-09, 2.072172677774070e-09, 2.715088778486400e-09, 4.007944390596239e-09, 7.030038734447577e-09, 1.583510556693909e-08, 5.123364964493186e-08, 2.727001380288206e-07, 1.585696435918360e-06, -4.305826986089133e-05, 3.252558471940873e-05, 1.534589238595253e-04, 7.706847940196529e-02, 4.069845337850369e-01, 2.358470936643040e+01, 2.383065703421641e+03, 1.691780213622439e+05, 9.995101415751472e+06, 7.632523492978696e+08, 1.347675419420482e+11]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_xc_vcml_rvv10_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_vcml_rvv10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.462740425369722e-06, -2.794903555332068e-06, -3.354340582637705e-06, -4.365532228796000e-06, -6.392179908489031e-06, -1.112000110832108e-05, -2.488865267364082e-05, -7.854351040471838e-05, -2.220790690977064e-04, 2.014611605429901e-03, -3.621406364329626e-04, -8.840403411116503e-04, -2.716051841365109e-01, -5.265265876385395e-01, -1.144867377551937e+01, -2.211744509349441e+02, -1.317199050920333e+03, -2.571565065699971e+03, -1.743891009440257e+03, -4.162480026568797e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
