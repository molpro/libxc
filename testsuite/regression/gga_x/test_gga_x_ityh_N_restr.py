
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ityh_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.204635722584239e+00, -4.122695091599867e+00, -4.007946943242805e+00, -3.849137842858696e+00, -3.633039466467949e+00, -3.346035545232004e+00, -2.977823007079115e+00, -2.527915184171710e+00, -2.013702148352699e+00, -1.471991771776848e+00, -9.384600724796232e-01, -5.528591629206032e-01, -4.559329936735321e-01, -3.608187928630986e-01, -2.287499311283716e-01, -9.850332682779764e-02, -1.635694135635856e-02, -6.260656054790740e-04, -5.607332845846733e-06, -7.580656045803687e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ityh_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.275761923230889e+00, -5.162369980857917e+00, -5.003474425455667e+00, -4.783360623225064e+00, -4.483448935490902e+00, -4.084437978193726e+00, -3.571556380580129e+00, -2.944689112089089e+00, -2.234839517584111e+00, -1.525581033139195e+00, -9.595075437312652e-01, -7.060122648646213e-01, -6.136571748236908e-01, -4.657640232766514e-01, -2.861875175232723e-01, -1.337415712403464e-01, -2.929787865004737e-02, -1.243046804799553e-03, -1.121341185720542e-05, -1.516130858030748e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ityh_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.963929739543137e-06, -4.270421651374545e-06, -4.751481334669607e-06, -5.535491307715104e-06, -6.883393342102468e-06, -9.382380512111265e-06, -1.453077351989865e-05, -2.679337140081210e-05, -6.227500249088433e-05, -1.947423896192225e-04, -9.039439780388717e-04, -5.363120064753299e-03, -1.027738016127635e-02, -1.834469039377540e-02, -4.976364280022175e-02, -1.438035046999265e-01, -1.189515223486784e-01, -1.170426063575433e-02, -2.095943564656266e-04, -4.729014088830309e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ityh_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.185171453317856e-02, -1.237606257267559e-02, -1.316960865503982e-02, -1.439704774180733e-02, -1.635505516887256e-02, -1.961567836994488e-02, -2.537211633865024e-02, -3.632239504990288e-02, -5.890687437345251e-02, -1.080111006707573e-01, -2.291083480662556e-01, -4.999037301952340e-01, -6.328639394532135e-01, -9.825835218863153e-01, -1.818187431687408e+00, -3.689661245587577e+00, -2.026289326394008e+01, -3.765952635152575e+01, -3.924434926550376e+01, -3.926985446627497e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ityh_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.975972003018205e-08, 2.238997785541886e-08, 2.677389817217499e-08, 3.455715792355567e-08, 4.966451228623979e-08, 8.287159064396163e-08, 1.693476704383456e-07, 4.498758476316497e-07, 1.614849088132317e-06, 7.091640129984848e-06, 4.253726164856307e-05, 5.647115726573873e-03, 2.128116769942100e-02, 4.436113139866744e-02, 1.807495129041321e-02, -1.154039291941365e+01, -3.093846008642285e+02, -1.207107004962851e+03, -2.659814106535636e+03, -4.659560671141116e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ityh_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.013126159910808e-13, 1.262768926133936e-13, 1.732029776478496e-13, 2.723745018014985e-13, 5.203502892734821e-13, 1.309432645314416e-12, 4.852068531946535e-12, 3.076295791251976e-11, 4.058476466076871e-10, 1.422089797163580e-08, 1.766166486534898e-06, 4.025545805318000e-04, 3.394337117580050e-03, 2.120254306489799e-02, 7.410062824039105e-01, 1.133379825708774e+02, 2.261508432024786e+04, 2.729791164635249e+06, 7.242130437988863e+08, 9.851939956077305e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
