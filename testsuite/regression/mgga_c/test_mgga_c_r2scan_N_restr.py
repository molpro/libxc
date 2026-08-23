
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_r2scan_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.656294329293021e-02, -2.651934648651328e-02, -2.645502128548570e-02, -2.635910808790204e-02, -2.621404589263195e-02, -2.599067425199337e-02, -2.564037969637526e-02, -2.509129128525302e-02, -2.434192239703566e-02, -2.498420798935301e-02, -3.138925144208364e-02, -5.594882386578272e-02, -4.773750453454269e-02, -2.993089633910818e-02, -2.402879692414392e-02, -1.824722465283280e-02, -9.815656101905563e-03, -3.466918419907014e-03, -5.764410752534624e-04, -3.002387826536430e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_r2scan_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.643065045481517e-02, -3.661497037594891e-02, -3.688413353421018e-02, -3.727982561800278e-02, -3.786721367466731e-02, -3.875181133255166e-02, -4.011409917366324e-02, -4.230836806608528e-02, -4.650071361326487e-02, -6.073156399974497e-02, -6.100449543575397e-02, -8.243317400125043e-02, -3.267438311447817e-02, -4.050414126838887e-02, -4.906143044780007e-02, -5.008051991209522e-02, -2.463956293819854e-02, -7.412944749109353e-03, -1.265500639704005e-03, -9.370305175679290e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.374913525490187e-07, 2.585080796757295e-07, 2.919286354927780e-07, 3.474392929811881e-07, 4.455666664774968e-07, 6.351833437222573e-07, 1.051501567859752e-06, 2.154400752324446e-06, 6.163769349963817e-06, 3.584106571231418e-05, 9.873399182472122e-05, 3.302523073734837e-03, 1.238724311776411e-02, 1.793193227755613e-02, 6.474475596746293e-02, 4.038527702248284e-01, 1.864313475013815e+00, 1.141995140959580e+01, 2.213287613176129e+02, 2.370041807788318e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.052399986902351e-04, -3.120597485611250e-04, -3.220326946139848e-04, -3.367151192542368e-04, -3.585359351996229e-04, -3.914130912840746e-04, -4.420678312255992e-04, -5.244488339242506e-04, -6.930706360794321e-04, -1.409252800400386e-03, -2.628287174819266e-04, -1.631101246421987e-03, -2.092283803870511e-02, -2.315096225317142e-02, -2.812169724462564e-02, -3.082703469355916e-02, -1.068519226395689e-02, -1.516187217236462e-03, -2.571906848292480e-04, -5.908372876585980e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.913843118091206e-05, 4.057692258189181e-05, 4.250625922572504e-05, 4.484145223765797e-05, 4.668252775196082e-05, 4.340301145594871e-05, 1.154089824061692e-05, -1.843130716124429e-04, -1.535371398818321e-03, -6.178091894177428e-03, -3.239431354830372e-02, 4.144737786142802e-02, 2.055388754165666e-01, 1.533211409826152e-01, 2.025840172146852e-01, 7.789142602806702e+00, 7.864585147970099e+01, 6.636003317010501e+02, 2.703168138311103e+04, 9.926294733429139e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.299362919454437e-10, 3.130604956358116e-10, 4.707045974041569e-10, 8.041614473237979e-10, 1.624050915378339e-09, 4.110214378421230e-09, 1.425312176666420e-08, 7.744256314120989e-08, 8.097398701596581e-07, 1.236541705349113e-05, 6.378426151052765e-05, 3.439708774352491e-03, -2.181226996857270e-02, -3.188804351091813e-02, 4.429700580980639e-01, -1.436864781208972e+02, -1.787672219424593e+04, -5.032984716109782e+06, -2.184664862213492e+10, -5.694467819547980e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.536899707603503e-06, -1.725052535277190e-06, -2.034328263745659e-06, -2.572972386020461e-06, -3.592543592574678e-06, -5.771406047615921e-06, -1.134546308914737e-05, -3.004579512076100e-05, -1.262880279912996e-04, -6.491806667227952e-04, 2.213213494502942e-04, -8.523116110798309e-03, -6.133296931127699e-02, -4.817842019406768e-02, -4.555585791882339e-01, 1.272130140437682e+01, 1.404813198825427e+02, 1.335832090488520e+03, 5.014118530255699e+04, 1.738695529211152e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.317413056483585e-14, -5.428303840730267e-14, -7.541992972511585e-14, -1.209182825907369e-13, -2.380022579326329e-13, -6.287176464043519e-13, -2.539761762977999e-12, -1.913342499728988e-11, -3.729258083861498e-10, -1.990002638202824e-08, -1.575570548754031e-06, -9.718781888278644e-04, -9.758354287266553e-03, -8.430927188211665e-02, -3.404769457663471e+00, 2.662840681018435e+03, 3.738297838937689e+06, 3.304927221943993e+10, 1.630689961244501e+16, 3.235261149478515e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.953521665694501e-11, 4.694678927738720e-11, 6.009272046661194e-11, 8.566695582690995e-11, 1.425461887508400e-10, 2.963568970221623e-10, 8.520073957271542e-10, 3.974367315171253e-09, 3.948384130673624e-08, 7.100266024023174e-07, 1.346957880006309e-05, 5.666607740285857e-05, 1.310061531418422e-03, 7.558677550083302e-02, 1.031874670112841e+00, -2.784010702917416e+02, -3.101231374355235e+04, -8.869284759676397e+06, -3.765256666693837e+10, -9.950554860385200e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.587730394511162e-08, -2.934286460085155e-08, -3.514841281587813e-08, -4.554919022001326e-08, -6.608460649710749e-08, -1.128115925934613e-07, -2.441221152690016e-07, -7.558772467539797e-07, -4.098691234414177e-06, -2.518387776965285e-05, -1.626877652302621e-04, 8.114232179061454e-04, 3.386778829610311e-02, -5.563882687443682e-02, -2.496783182503560e-01, 2.783517039540832e+01, 2.491809515767684e+02, 2.289903693538831e+03, 8.515369958195159e+04, 3.052797549358505e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
