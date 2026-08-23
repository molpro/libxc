
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_wi_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wi", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.878665839630977e-01, -1.858225675801022e-01, -1.828289453596550e-01, -1.784088039773697e-01, -1.718041222945689e-01, -1.617609679582709e-01, -1.461032632976286e-01, -1.209665097357907e-01, -8.089808132801872e-02, -3.144834539271112e-02, -1.178609410468910e-02, -5.753045656647964e-02, -5.845223755725521e-02, -4.001065159723465e-02, -1.344589056253718e-02, 3.617654857537704e-04, 2.374836318962820e-04, -4.490630145121982e-07, -6.342026733089863e-10, -3.431250892787659e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_wi_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wi", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.563546501307921e-01, -2.562922264246237e-01, -2.562667242593458e-01, -2.563707613737838e-01, -2.568308725977831e-01, -2.581676864560619e-01, -2.613997789609148e-01, -2.670634787912197e-01, -2.628784168881798e-01, -1.873158419818508e-01, -1.027702964454704e-01, -1.103120328679524e-01, -8.650421789858853e-02, -8.895131233348760e-02, -6.506962680173317e-02, -6.107131218390929e-03, 1.031462288461754e-03, -2.576398598320599e-07, -3.805213321573010e-09, -2.058750534954487e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_wi_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wi", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.980320533083293e-07, 5.521725914510975e-07, 6.404235256732255e-07, 7.923234164081380e-07, 1.074871424872977e-06, 1.661148097631676e-06, 3.073411651785731e-06, 7.161920152747099e-06, 2.079505917810741e-05, 5.935075271982288e-05, 2.329820065771740e-04, 3.017055331628263e-03, 4.613742702680290e-03, 1.397028713018868e-02, 4.471151818083114e-02, 3.527888204682095e-02, -4.845861657805821e-02, -7.686520585014684e-04, 8.058047207683669e-04, 3.385602793361965e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_wi_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wi", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.778820775601549e-04, 4.227653332395756e-04, 4.959644378838958e-04, 6.216523244266985e-04, 8.528784763039289e-04, 1.315939373765887e-03, 2.314956082544759e-03, 4.235806691808803e-03, 1.408444418745740e-03, -6.180261050084503e-02, -2.293803448517867e-01, 6.336874517503877e-02, 7.513158613941912e-03, 1.435474791815821e-01, -1.411312882889513e+00, -4.680556021381918e+00, 1.901118956135285e+00, 9.928622124383975e-01, -6.661402401123888e-02, -2.666224516464040e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_wi_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wi", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.425070286888407e-09, -6.404855286873188e-09, -8.124999321548323e-09, -1.141484936345100e-08, -1.851044573231573e-08, -3.654085789668141e-08, -9.277262161961782e-08, -2.986608256263709e-07, -5.072240275305435e-07, 2.181721733104391e-05, 5.624263940306653e-04, -8.551385405739737e-03, -2.248553636005444e-02, -9.441472666037534e-02, 1.055906153022887e+00, 2.413378844410698e+01, -1.051578612352413e+02, -2.243309831486035e+03, 1.692769227904101e+04, 5.261508095029242e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_wi_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wi", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.038902068738163e-14, 1.318500818938647e-14, 1.850510747297583e-14, 2.986297871688652e-14, 5.811989122045767e-14, 1.421026903080166e-13, 4.027981832443046e-13, -9.245195409660499e-13, -1.731091364764186e-10, -1.457975980964884e-08, -2.032086244005029e-06, 1.243023954232347e-04, 2.417064726401137e-03, 8.031740077033252e-04, -1.856046209125846e+00, -1.509094445394226e+02, 1.158947824378699e+04, 5.126786749512844e+06, -5.633047340157560e+09, -1.359681434093142e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
