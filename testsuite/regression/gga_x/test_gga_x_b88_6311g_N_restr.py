
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_b88_6311g_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88_6311g", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.351948104646101e+00, -4.270514154426967e+00, -4.156499990950811e+00, -3.998757996111901e+00, -3.784219601398787e+00, -3.499514847582773e+00, -3.134728599730171e+00, -2.689985299216601e+00, -2.183521617286849e+00, -1.651943605861109e+00, -1.114631692554622e+00, -6.746149998723124e-01, -5.678304279440261e-01, -4.801929536063165e-01, -3.576432925882230e-01, -2.390533323203489e-01, -1.497205727306859e-01, -9.169741143961121e-02, -5.859594265805670e-02, -4.058341387280465e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_b88_6311g_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88_6311g", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.356157861123819e+00, -5.242600258706048e+00, -5.083480399960662e+00, -4.863072646401775e+00, -4.562796699742761e+00, -4.163379875230017e+00, -3.650143911819801e+00, -3.023158495326196e+00, -2.313485720426242e+00, -1.603262768978470e+00, -1.033526291225620e+00, -7.975209929436400e-01, -7.120935080900911e-01, -5.546971670374486e-01, -3.635836108405318e-01, -1.997363752681880e-01, -9.617724162628549e-02, -4.175068259496981e-02, -1.618488703721877e-02, -6.649955870296084e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b88_6311g_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88_6311g", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.790211303719969e-06, -5.159513048365390e-06, -5.739046363719262e-06, -6.683311353916896e-06, -8.306265932482156e-06, -1.131449966488642e-05, -1.751312626919470e-05, -3.230399553157474e-05, -7.543650287469309e-05, -2.411738178592032e-04, -1.205608309094258e-03, -8.182047187647007e-03, -1.672312019341246e-02, -3.178770929669801e-02, -1.067337728807063e-01, -6.372261694220666e-01, -7.012812187850685e+00, -1.814254428007495e+02, -1.686505834355311e+04, -1.003496902973583e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b88_6311g_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88_6311g", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.204699548932005e-02, -1.257982778819775e-02, -1.338580943288331e-02, -1.463149806490234e-02, -1.661607988644031e-02, -1.991399330779682e-02, -2.571598376070364e-02, -3.669386316921450e-02, -5.922082406847091e-02, -1.089601763882879e-01, -2.416193500472108e-01, -5.417811948923218e-01, -6.773984359435472e-01, -1.109228805771071e+00, -2.274494843713832e+00, -5.112939937085169e+00, -6.058882781565106e+00, 1.465869306306886e+02, 1.795062577762845e+04, 1.037675125737346e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b88_6311g_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88_6311g", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.229224642556357e-08, 2.521062496401610e-08, 3.006133815169025e-08, 3.863831840653310e-08, 5.518560613999890e-08, 9.122730469684177e-08, 1.837944829137379e-07, 4.779222061836652e-07, 1.667179918355288e-06, 7.363776404867996e-06, 7.239909160018826e-05, 9.030930800090726e-03, 3.719353499912976e-02, 9.048923268329995e-02, 4.386965116301412e-01, -3.246405966996999e+00, -1.802258764090364e+03, -1.304681666314025e+06, -1.003018423962004e+10, -3.407947805754677e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b88_6311g_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88_6311g", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.434764172962472e-13, 1.786218748411546e-13, 2.445837376038614e-13, 3.836678442990677e-13, 7.302729156908812e-13, 1.827657437903522e-12, 6.717355948708868e-12, 4.208648939867695e-11, 5.467802272605759e-10, 1.898857232886114e-08, 2.472115725914992e-06, 6.887931768905437e-04, 6.328801097529120e-03, 4.010384802031649e-02, 1.588094774113499e+00, 4.082008247287158e+02, 7.676177583795150e+05, 1.987616429605197e+10, 2.416666882877561e+16, 8.048037010269839e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
