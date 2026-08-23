
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_13_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_13", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.122240570595430e+00, -5.022116455894931e+00, -4.881656166256628e+00, -4.686703526334640e+00, -4.420123534417608e+00, -4.062910114265752e+00, -3.596498589457394e+00, -3.005002028859928e+00, -2.277371386373055e+00, -1.462429253116398e+00, -8.211721442558761e-01, -5.601091133861225e-01, -5.771519646377721e-01, -4.985243796127862e-01, -3.285032956095302e-01, -1.650217594819467e-01, -6.766908110762809e-02, -2.131494154682912e-02, -4.410985154879066e-03, -4.882654031012765e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_13_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_13", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.283943342176560e+00, -6.146947308942241e+00, -5.955270552877732e+00, -5.690452844674823e+00, -5.331401065473558e+00, -4.858345014986407e+00, -4.262722292503721e+00, -3.565423016292652e+00, -2.814200761100621e+00, -1.949365689345870e+00, -1.107796301992974e+00, -7.952140831663157e-01, -8.633654776511103e-01, -6.760509374221559e-01, -4.424236103361661e-01, -2.174474289863770e-01, -8.634669054535075e-02, -2.700149101741525e-02, -5.568165576481617e-03, -6.150407388696581e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_13_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_13", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.129847376526833e-05, -1.222418511782636e-05, -1.368386716786076e-05, -1.607740503135651e-05, -2.022337357639959e-05, -2.796432756718519e-05, -4.389432194471153e-05, -8.038892320434510e-05, -1.682234056526117e-04, -3.446530086865706e-04, -6.709736085484545e-04, -3.704336920672541e-03, -2.395810443062562e-02, -5.989386168039513e-02, -1.619875891107848e-01, -3.884396652207365e-01, -1.133615835373896e+00, -9.056497638000684e+00, -2.280135648665234e+02, -2.028711676847030e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_13_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_13", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.238229728770898e-02, 1.272078728742336e-02, 1.322493002402918e-02, 1.398656191122479e-02, 1.515895408269836e-02, 1.700293827476809e-02, 1.993929262626553e-02, 2.435778404893023e-02, 2.844218267304648e-02, 2.241334328156882e-02, 8.325315493637056e-03, 8.238569829976601e-03, 6.305048656478854e-02, 1.008589615750441e-01, 1.094089445364402e-01, 4.774595210587020e-02, 9.899720940959486e-03, 2.267476020900670e-03, 5.040656776446145e-04, 6.157266975623073e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_13_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_13", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.702254491222316e-02, -1.782364548090769e-02, -1.903103300533580e-02, -2.088209387475745e-02, -2.377652766104194e-02, -2.837315400578228e-02, -3.557125214024025e-02, -4.564208995770626e-02, -6.031028879842884e-02, -1.386524996299680e-01, -3.185551080615779e-01, -8.274275841287392e-01, -9.444140508830928e-01, -1.315791730088175e+00, -2.835893901251678e+00, -8.046808276331852e+00, -3.252644110553785e+01, -3.177821127542438e+02, -7.473992460696822e+03, -6.135661123350220e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_13_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_13", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.165647871863599e-08, 9.355900197664540e-08, 1.136483239347518e-07, 1.499268338671502e-07, 2.218721996523410e-07, 3.835199122012686e-07, 8.050663069531601e-07, 2.019730263977646e-06, 3.935676056111670e-06, -2.630941132174888e-05, -4.442888699417659e-04, -6.686306192993389e-03, 2.314229964834496e-02, 1.355097879480172e-01, -7.130861814449784e-01, -2.941228500368738e+01, -1.265438788769778e+02, 2.058661911926457e+05, 7.050982450356576e+08, 4.654254720672070e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_13_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_13", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.574925329994011e-05, -6.174824548545188e-05, -7.147484080964863e-05, -8.805361326894571e-05, -1.183002653119360e-04, -1.784652808835720e-04, -3.089786889042498e-04, -5.837860285889376e-04, -6.873204539398266e-04, 2.456228400570773e-03, 8.032914078420383e-03, 4.205786045099982e-02, 7.256300147579922e-02, -6.078622585688902e-02, 8.633884353894655e-01, 4.991127647442022e+00, 3.919249112120757e+00, -4.640593742562222e+01, -1.551824476323729e+03, -1.412513641031666e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_13_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_13", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.413458458168427e-13, -1.793740931012478e-13, -2.524258083040481e-13, -4.116427488177038e-13, -8.273105933451195e-13, -2.229395140718310e-12, -8.988691530242215e-12, -6.134508531097368e-11, -7.635949905976780e-10, -1.616462347400576e-08, -6.696609144767186e-07, -5.663469704174475e-05, -2.259674810336369e-03, -3.287782363841491e-02, -1.305500485058986e+00, -1.728544163526940e+02, -1.647509453189413e+05, -1.960827728302103e+09, -7.077978044438071e+14, -3.611935338747717e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_13_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_13", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.816546679573647e-10, 4.618758389198841e-10, 6.074542214940826e-10, 8.999355501444680e-10, 1.579801641714052e-09, 3.524425649789564e-09, 1.095176414999466e-08, 5.237881371899815e-08, 3.967636255549525e-07, 3.782168856866137e-06, 3.937801850305526e-05, 1.338771497312573e-03, 2.414611233729323e-02, 1.910474146480233e-01, 3.302312726750196e+00, 7.246786189243525e+01, 3.157083867473959e+03, 9.063217268198804e+05, 2.844700489988999e+09, 1.995432562349406e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_13_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_13", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.999079874978298e-08, -9.374375877258650e-08, -1.380451632929503e-07, -2.295595661833953e-07, -4.466993253433789e-07, -1.066841672339815e-06, -3.319285919998490e-06, -1.415207837581347e-05, -7.738921522527066e-05, -3.436220109527566e-04, -7.716346207585618e-04, -5.503881184393783e-03, -7.513893429569277e-02, -3.570224516851155e-01, -3.047982805418974e+00, -1.357566830232468e+01, -4.150726194093799e+01, -3.306937285891552e+02, -9.118354774483647e+03, -8.785353356381987e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
