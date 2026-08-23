
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_vcml_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vcml", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.473062712000199e+00, -4.387645213833693e+00, -4.268035785347604e+00, -4.102515383079325e+00, -3.877321802895512e+00, -3.578326629042201e+00, -3.194968937148583e+00, -2.727443763916735e+00, -2.199178975707484e+00, -1.628520664522459e+00, -1.001589387504807e+00, -6.415378439634696e-01, -5.590554213850166e-01, -4.781505692608833e-01, -3.446829696257365e-01, -2.062140883525888e-01, -7.951260046621049e-02, -1.722522198700796e-02, -3.284151857994802e-03, -3.617975452404347e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_vcml_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vcml", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.625965252669326e+00, -5.507956569928299e+00, -5.342641113630976e+00, -5.113760588163884e+00, -4.802253627655015e+00, -4.388892109090443e+00, -3.861447979308879e+00, -3.234421250896343e+00, -2.611457011587947e+00, -1.178316316207522e+00, -1.089669165878517e+00, -8.091407325002922e-01, -7.550235480247014e-01, -5.985427871805501e-01, -3.205352187097000e-01, -2.322214981763392e-01, -1.183153909940629e-01, -2.619795926039550e-02, -4.409401127739620e-03, -4.824419074720600e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_vcml_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vcml", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.591693587777359e-06, -3.868681618702073e-06, -4.301806687454384e-06, -5.002823898361834e-06, -6.191276599581637e-06, -8.324624546989649e-06, -1.233398556743540e-05, -1.873183373597388e-05, -7.233629993058696e-07, -9.323794510871331e-04, -8.773030285263229e-04, -4.901655183279795e-03, -1.293987764278187e-02, -5.928328226766667e-02, -3.317980358623585e-01, -3.974565321071687e-01, -2.853625693214259e+00, 4.285795902904863e+00, 7.310755593890956e+00, 9.440771363030469e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_vcml_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vcml", 1)
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


def test_mgga_x_vcml_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vcml", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.365125346848331e-02, -1.436821485564218e-02, -1.547943232417663e-02, -1.726432331400469e-02, -2.029377456430686e-02, -2.590709792362896e-02, -3.789621090985620e-02, -6.899681918963982e-02, -9.874638969317220e-02, 1.021168252584011e-01, -3.788053216685161e-02, -6.068702724195444e-01, -1.519206864224642e+00, -1.867191956947355e+00, -9.684327069920824e+00, -5.817389869054127e+01, -6.139478043418435e+02, -1.689813920451472e+03, -6.189784853409552e+03, -4.171334575648161e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_vcml_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vcml", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.006812556438685e-08, 7.087784995580597e-08, 9.002049496731140e-08, 1.272529739510175e-07, 2.103669926371988e-07, 4.378086533880118e-07, 1.277847685569711e-06, 5.925663151407844e-06, 2.430241622911828e-05, -4.998191376016616e-04, -3.964018844598153e-04, 6.808100471884413e-03, -9.228995802641417e-02, 5.402740323689041e-01, 1.861135653070803e+01, 1.229803541144761e+03, 1.093394695763250e+05, 7.068438493602309e+06, 5.655346121188669e+08, 1.753650234854444e+11]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_x_vcml_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vcml", 1)
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


def test_mgga_x_vcml_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vcml", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.112660753846756e-12, -1.428855583591885e-12, -2.048117094574885e-12, -3.439809479232540e-12, -7.261253433663113e-12, -2.132702302080830e-11, -1.007742123154357e-10, -9.162164654973725e-10, -1.087408559529655e-08, 9.476917172713167e-07, 2.394249328980769e-07, 1.591207173076435e-04, -2.201791071846376e-02, -3.219350180527158e-01, -4.713134378872460e+01, -2.503915104332992e+04, -2.202856849504406e+07, -4.216004443014012e+10, -3.794250888076298e+14, -7.172472468121942e+19]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_x_vcml_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vcml", 1)
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


def test_mgga_x_vcml_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vcml", 1)
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
