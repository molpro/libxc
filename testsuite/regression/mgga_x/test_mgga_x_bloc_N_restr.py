
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_bloc_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_bloc", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.718572234437737e+00, -4.623226401143537e+00, -4.489602905036023e+00, -4.304463845760715e+00, -4.052133433540152e+00, -3.716273377716162e+00, -3.284280922100258e+00, -2.755991763220711e+00, -2.158715959311560e+00, -1.562917876478404e+00, -1.019713023535255e+00, -6.469711852601986e-01, -5.580062252707866e-01, -4.792310055459231e-01, -3.439133173674888e-01, -2.180386531161369e-01, -1.197712475706926e-01, -4.187048762212384e-02, -8.769439255103919e-03, -9.701617068941892e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_bloc_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_bloc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.932824468643039e+00, -5.823305408479315e+00, -5.669560522866508e+00, -5.455924828080234e+00, -5.163207382542110e+00, -4.769503267636370e+00, -4.251748475124391e+00, -3.586047094870959e+00, -2.746081542137884e+00, -1.762738951647754e+00, -9.671011113208448e-01, -8.346845753684229e-01, -7.332829892161186e-01, -5.655388229694690e-01, -3.955014606770915e-01, -1.960737527043930e-01, -1.306763811892584e-01, -5.448556549011521e-02, -1.167945263680602e-02, -1.293530282556203e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_bloc_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_bloc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.015314659839479e-05, -1.027865645614111e-05, -1.043905372258589e-05, -1.062255374721220e-05, -1.077334444439108e-05, -1.072012396098008e-05, -1.006907572855168e-05, -8.749150417924681e-06, -1.647571474218003e-05, -1.447516488538627e-04, -1.310916568884072e-03, -1.458444842640880e-03, -1.032328769891570e-02, -6.103843176766106e-02, -9.018441851707119e-02, -5.157291458471717e-01, -1.965640781011764e+00, -3.023380466467972e+00, -3.575695056615209e+00, -3.945369433529172e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_bloc_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_bloc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.434386322143966e-02, 1.364963154236589e-02, 1.268051193294866e-02, 1.134694379225170e-02, 9.553188392665770e-03, 7.232453907872481e-03, 4.445560140280740e-03, 1.622298869082139e-03, -4.165722976141219e-05, 1.009807081612400e-03, 3.133441547242077e-03, -8.510183925164836e-04, 6.794970382409679e-03, 5.310314302384954e-02, 2.026512481187914e-02, 1.138035378123154e-03, -1.716685732672625e-05, -3.754439931994484e-08, -1.149698625050644e-12, -3.239824273096723e-19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_bloc_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_bloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.299887086645309e-04, 4.378927980854581e-04, 7.540322985225031e-04, 1.239415711824488e-03, 1.979661872280874e-03, 3.027850267457177e-03, 3.960107601128996e-03, 1.134795098504212e-03, -2.637015911512884e-02, -1.326087321591462e-01, -2.949504598125794e-01, -4.351927283166633e-01, -6.721967690352141e-01, -8.013072747036689e-01, -1.404143769657595e+00, -2.605618647091065e+00, 4.965730555305926e+01, -4.008757003051421e+02, -1.344695141548211e+04, -1.116614206205966e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_bloc_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_bloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.477288951707739e-07, -2.806147725951982e-07, -3.352672992094743e-07, -4.317968077430213e-07, -6.173447463315770e-07, -1.017299919614685e-06, -2.015769298356802e-06, -4.949169198398851e-06, -1.451933607886168e-05, -5.211320566387205e-05, -3.176534497530892e-04, 4.826150324972691e-03, 1.169470357737933e-02, -1.736659317743926e-01, -3.946798475689590e+00, -3.820788868757045e+01, -6.380152696593170e+03, -3.682394848524099e+05, -5.003208032580426e+07, -4.087574385929967e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_bloc_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_bloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.883946190997620e-04, 3.078172504078862e-04, 3.377302478545272e-04, 3.850906647394266e-04, 4.629068815914594e-04, 5.969590200202917e-04, 8.408221668994196e-04, 1.306797118695293e-03, 2.223046492724310e-03, 4.253435019566541e-03, 6.713826120641649e-03, -6.463421754614322e-03, 1.842145915845421e-02, 2.257026017614564e-01, 2.249243275433158e+00, 2.816320009829286e+00, 8.104731811896236e-02, -1.201705190276596e-03, -9.501525718273694e-06, -2.670599612228372e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_bloc_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_bloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.448302597823329e-12, 5.418434614305389e-12, 7.184799403973064e-12, 1.074502566959715e-11, 1.903409829731880e-11, 4.267360745938977e-11, 1.319821567260628e-10, 6.254916303424981e-10, 5.141190333208346e-09, 9.462513173773282e-08, 4.475486767630069e-06, -4.814771389737939e-04, -1.645486751686800e-02, 1.511232148783272e-01, 1.140348153404109e+01, 7.895522489367216e+02, 6.157598515433153e+05, 1.112111703331626e+09, 1.816686844909430e+13, 1.152344679710656e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_bloc_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_bloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.227386183161394e-09, -2.740632859440555e-09, -3.640001289299632e-09, -5.346543750081880e-09, -8.956228433170504e-09, -1.779053378669897e-08, -4.397343167354140e-08, -1.427804859486248e-07, -6.379024498443753e-07, -3.935531218308512e-06, -8.636619155292918e-06, 3.758263705459367e-04, 2.631366634667172e-02, 8.646201959978493e-02, -3.946609903155195e+00, -3.424100598571910e+01, -2.661401782220961e+01, -3.581810487947345e+01, -1.157735618969270e+01, -1.490617162214834e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_bloc_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_bloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.624049142579542e-06, -2.323614623440579e-06, -1.821091278871591e-06, -9.352177800273066e-07, 7.322013263893490e-07, 4.125439048030753e-06, 1.164800477859517e-05, 2.961832504464733e-05, 7.254143173502613e-05, 1.432211591887353e-04, -1.295646617319173e-04, 1.949619882146439e-04, -3.773793181882340e-02, -3.163764154036211e-01, 1.140655739787417e+00, 2.419791862195445e+00, 2.446269069634215e-01, 1.524573825828914e-02, 5.130439232583344e-05, 1.026759580786186e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
