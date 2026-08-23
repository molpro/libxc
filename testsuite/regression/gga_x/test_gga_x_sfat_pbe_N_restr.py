
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_sfat_pbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sfat_pbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.085992298082052e+00, -4.004106245236274e+00, -3.889451202497474e+00, -3.730806029219326e+00, -3.515004693413157e+00, -3.228550792682642e+00, -2.861361792761600e+00, -2.413281492531472e+00, -1.901746696744614e+00, -1.361925186711185e+00, -8.384659777555513e-01, -4.837868618685792e-01, -3.945678581691990e-01, -3.034067462257988e-01, -1.823722052867340e-01, -7.253411833035542e-02, -1.208183793302002e-02, -5.054884230089115e-04, -4.628159202912765e-06, -6.264897344201684e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_sfat_pbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sfat_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.184725359254697e+00, -5.071014459743816e+00, -4.911649145111980e+00, -4.690842808136395e+00, -4.389920232441886e+00, -3.989496911573906e+00, -3.474943235590984e+00, -2.847472546249498e+00, -2.144106200061162e+00, -1.462524247203837e+00, -9.127100180137196e-01, -6.385593860874679e-01, -5.485117369821854e-01, -4.069082345669529e-01, -2.392048508742662e-01, -1.048141822691931e-01, -2.182305864647878e-02, -9.997885143760662e-04, -9.251917312891398e-06, -1.252972186644848e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sfat_pbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sfat_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.563519015842048e-06, -3.847607095064816e-06, -4.294679174169181e-06, -5.025980933033187e-06, -6.289554375614288e-06, -8.647149365344163e-06, -1.353722692345226e-05, -2.521154181777705e-05, -5.831009300467878e-05, -1.711475517378770e-04, -7.243862990984621e-04, -4.319791246196870e-03, -7.633930440392254e-03, -1.422384206663702e-02, -3.665976401372853e-02, -7.946016139124844e-02, -3.751704052498771e-02, -1.129343102370564e-03, -2.682536977960436e-06, -4.441894040881897e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sfat_pbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sfat_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.200506842261026e-02, -1.254715425018304e-02, -1.336847034687400e-02, -1.464059350358602e-02, -1.667241852799619e-02, -2.005506309343915e-02, -2.598543099356847e-02, -3.689604218334755e-02, -5.641669830948830e-02, -7.894381226715556e-02, -1.268693771500164e-01, -4.862058774797875e-01, -6.060589137749702e-01, -9.341590790065524e-01, -1.558701209937507e+00, -2.683610218344097e+00, -1.554526192765840e+01, -3.010768619299586e+01, -3.235167861283911e+01, -3.245321209257116e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sfat_pbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sfat_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.151457447850087e-08, 2.448687156066562e-08, 2.946282160944543e-08, 3.834799817233405e-08, 5.570954952176343e-08, 9.407102738841788e-08, 1.933654823508163e-07, 4.969364923123108e-07, 1.368435345611792e-06, -4.518265702519646e-06, -2.355893147328079e-04, 5.496675799970057e-03, 1.835062499558400e-02, 4.123767216834957e-02, -1.050529348047815e-01, -1.312151671705890e+01, -1.601185891349028e+02, -1.821510212953374e+02, -5.003074585616540e+01, -6.135971171507191e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sfat_pbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sfat_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.845950971691905e-14, 6.151403658988064e-14, 8.662575246884000e-14, 1.415035481804334e-13, 2.855812050663584e-13, 7.778385137070128e-13, 3.228497000766563e-12, 2.399159096772239e-11, 3.882396335764284e-10, 1.647136927221822e-08, 2.084507649043666e-06, 2.220951287610609e-04, 1.235793708758586e-03, 1.257859357053747e-02, 6.314699753744972e-01, 9.988008587748325e+01, 1.184738523258913e+04, 4.151619400940060e+05, 1.362865961405899e+07, 1.297366750958845e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
