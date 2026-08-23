
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lc_wpbe_whs_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbe_whs", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.143324877382589e+00, -4.060575427156445e+00, -3.944699798143807e+00, -3.784344844990809e+00, -3.566185046192309e+00, -3.276567325623760e+00, -2.905368355896240e+00, -2.452870759569671e+00, -1.938488983381430e+00, -1.401199591570768e+00, -8.722039864927212e-01, -5.014093950818708e-01, -4.179947018610046e-01, -3.122539815842996e-01, -1.779064764229444e-01, -6.565359124486152e-02, -8.474790911072302e-03, -1.730496919339696e-04, -1.406680149295430e-06, -1.895303220839013e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lc_wpbe_whs_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbe_whs", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.289007625537629e+00, -5.173649218889564e+00, -5.011872095160099e+00, -4.787507291035783e+00, -4.481274805203632e+00, -4.072799850205464e+00, -3.545759976898139e+00, -2.898287715563142e+00, -2.161741437697607e+00, -1.439282207217334e+00, -8.722712438118803e-01, -6.915347436744683e-01, -6.009664947313300e-01, -4.488517512829885e-01, -2.497587458399220e-01, -8.292759930964641e-02, -1.520509160644892e-02, -3.736871694038812e-04, -2.832712165782193e-06, -3.791225339977357e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_wpbe_whs_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbe_whs", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.102176871453988e-06, -3.365396983097687e-06, -3.781964901239119e-06, -4.468942795521444e-06, -5.670077681711564e-06, -7.950409315339613e-06, -1.280410909965558e-05, -2.486902467185484e-05, -6.154635965737679e-05, -2.000176812871701e-04, -9.538727547932635e-04, -1.999638235830851e-03, 5.667717965838325e-04, -3.788165405862503e-03, -2.604916048315675e-02, -1.750734820495603e-01, -1.901794591317195e-01, 4.264884175632647e-02, 6.034998360441354e-03, 1.504921204701269e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_wpbe_whs_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbe_whs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.254170732330252e-02, -1.313044670541798e-02, -1.402573405729363e-02, -1.542017318181037e-02, -1.766670668717043e-02, -2.145967467818746e-02, -2.827702044831692e-02, -4.150828055171615e-02, -6.851012384956594e-02, -1.075889516679599e-01, -2.243865807967288e-01, -5.640576888630727e-01, -6.200415791302508e-01, -1.138451877176621e+00, -3.480821690171136e+00, -6.527922283971058e+00, -9.893893494180405e+00, -1.577444208165199e+01, -1.035428371718747e+01, -9.830370317144434e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_wpbe_whs_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbe_whs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.697244717954793e-08, 3.082020743364635e-08, 3.730182940023922e-08, 4.898585466224242e-08, 7.216183104950154e-08, 1.246823932914615e-07, 2.673148382669488e-07, 7.572057117854697e-07, 2.886742977531553e-06, 6.997596864676414e-06, 2.676404509440773e-05, 1.074843189243271e-02, 1.271515315953297e-02, 1.061676293002637e-01, 1.781780473749403e+00, 1.435001710825394e+01, -3.022700000817922e+02, 8.609132369802341e+03, 1.380417141396773e+05, 2.578583987478888e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_gga_xc_lc_wpbe_whs_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbe_whs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.498192561079449e-14, -6.406094059674648e-14, -7.923787411252821e-14, -1.056401485719288e-13, -1.515784324153616e-13, -2.076805184592092e-13, 1.053621976793310e-13, 7.988845603285111e-12, 2.330854531781483e-10, 1.491208173748291e-08, 1.964980527083235e-06, -6.952939103182248e-04, -7.713331134701666e-03, -4.226038432386649e-02, -1.575206034184975e+00, -3.407919153526174e+01, 1.504963073417184e+04, -2.490666512648303e+07, -4.600139834379089e+10, -6.593255189665341e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
