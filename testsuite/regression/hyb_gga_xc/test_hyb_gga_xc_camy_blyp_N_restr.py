
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_camy_blyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_blyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.344385126275245e+00, -3.278672257427496e+00, -3.186631731279672e+00, -3.059211696995269e+00, -2.885742162392613e+00, -2.655164700543521e+00, -2.358900369609882e+00, -1.995825817351958e+00, -1.578217416590383e+00, -1.133054318129594e+00, -7.021346809160605e-01, -4.300373952576756e-01, -3.576714942278937e-01, -2.783694142110029e-01, -1.683033851591638e-01, -5.989822534441195e-02, 2.141377066581655e-03, -3.647196002703182e-03, -9.145397000711960e-04, -1.024011540921665e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_camy_blyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_blyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.215559686172663e+00, -4.125199152568441e+00, -3.998606183941213e+00, -3.823301800800034e+00, -3.584577431894147e+00, -3.267265326641323e+00, -2.860060985514349e+00, -2.363898252488382e+00, -1.805689439814955e+00, -1.255354440854630e+00, -8.113865057175929e-01, -5.679588695768324e-01, -4.891250477777225e-01, -3.780788402156491e-01, -2.450340673025520e-01, -1.355023047543978e-01, -5.056794969969085e-02, -5.300935840565425e-03, -1.216233248229873e-03, -1.364671481846423e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camy_blyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_blyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.006263530740624e-06, -3.234660175473387e-06, -3.592364780444727e-06, -4.173427719422988e-06, -5.167386155370604e-06, -6.995449919460044e-06, -1.071157610533806e-05, -1.935246366644727e-05, -4.317000302917133e-05, -1.225284909229379e-04, -4.636669196854933e-04, -2.810641956702348e-03, -5.244159122025424e-03, -7.358528547287682e-03, -4.252282771946281e-03, 2.119155263571544e-01, 4.141320819562539e+00, 5.232433459587360e+00, -2.289649516133231e-04, -5.167964732339352e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camy_blyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_blyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.358982653771910e-03, -9.766839744496335e-03, -1.038305664889701e-02, -1.133373785730418e-02, -1.284396682259563e-02, -1.534131803868095e-02, -1.969406102035450e-02, -2.775707703996664e-02, -4.329692328785537e-02, -6.994754258113174e-02, -1.130980480787343e-01, -3.610673223340221e-01, -4.771580739149619e-01, -6.731250171846355e-01, -8.721286260126526e-01, 1.719272509929297e+00, 1.235019818131168e+01, -9.802748697982258e+01, -1.404142183149334e+03, -1.175337214927008e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camy_blyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_blyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.453167727334591e-08, 1.642228396946194e-08, 1.955879123226138e-08, 2.508724261474483e-08, 3.569318682895525e-08, 5.854157106176273e-08, 1.158071893079991e-07, 2.859995320868939e-07, 8.095327917375172e-07, -1.009262114610679e-06, -1.574354632223280e-04, 1.441969376145770e-03, 7.240026541822734e-03, -6.619875201260072e-03, -5.784193878527009e-01, -3.886654926517595e+01, -3.663089928726926e+03, 1.625519339302490e+05, -2.905108276366518e+03, -5.092062849123016e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camy_blyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_blyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.846704356654380e-14, 9.774218910704017e-14, 1.339439966668910e-13, 2.103562737381191e-13, 4.010648531440136e-13, 1.006162788891722e-12, 3.710307115444444e-12, 2.333782507987465e-11, 3.036686450752235e-10, 1.037317662866581e-08, 1.234435339576773e-06, 2.717079493558824e-04, 2.245965869035047e-03, 1.358615392957586e-02, 4.438643715579247e-01, 6.281110276945575e+01, 1.685922013506894e+04, 2.887829617397368e+06, 7.910626052443515e+08, 1.076640207759563e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
