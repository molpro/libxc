
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_regtpss_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_regtpss", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.438110815935018e-02, -6.334255486497686e-02, -6.185369599288688e-02, -5.972247777171618e-02, -5.667892151922425e-02, -5.235052097504761e-02, -4.624870104518795e-02, -3.783732713457140e-02, -2.698863406192507e-02, -1.573388914067256e-02, -1.181040800662526e-02, -4.387086449794492e-02, -5.305167564348420e-02, -3.772602381789682e-02, -2.080104684249997e-02, -6.380561901197582e-03, -5.867522101150832e-04, -9.333129892271437e-06, -1.205872555675830e-08, -4.176182968147687e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_regtpss_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_regtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.322859556955816e-01, -1.313211166858838e-01, -1.299204527731229e-01, -1.278773630741617e-01, -1.248741775800916e-01, -1.204032367903899e-01, -1.136048527831501e-01, -1.029250387229074e-01, -8.566817511093218e-02, -6.066330771928734e-02, -4.879872752533147e-02, -8.855868376746823e-02, -8.218770879263498e-02, -7.897614055930618e-02, -6.181355580101120e-02, -2.797708781544919e-02, -3.353049694279536e-03, -5.865951298462061e-05, -7.845165227479421e-08, -2.761228758767693e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_regtpss_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_regtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.172424224027566e-07, 7.652882611441903e-07, 8.398347338950828e-07, 9.592956218640371e-07, 1.159627222180355e-06, 1.517409210762775e-06, 2.213036058778497e-06, 3.720048844769748e-06, 7.413115057856866e-06, 1.818216083172496e-05, 9.927304862549321e-05, 3.396025616515386e-03, 9.087736614454075e-03, 1.449070022588161e-02, 3.813864553434272e-02, 1.163854531900356e-01, 1.892115001319471e-01, 1.103703905830937e-01, 1.749329092048172e-02, 4.709213667115846e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_regtpss_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_regtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.844405103751176e-04, -3.075995244056133e-04, -3.442577426743730e-04, -4.048063980932925e-04, -5.111913363316626e-04, -7.156872700648627e-04, -1.163254995354982e-03, -2.336196969302275e-03, -6.132184017169492e-03, -1.988766000871121e-02, -6.883686717427316e-02, -2.227807909762112e-02, 9.374879618877381e-03, -6.202292568149404e-02, -8.050093253042210e-01, -6.166888337609439e+00, -1.522778085332326e+01, -9.559593899473001e+00, -1.510735002719438e+00, -4.012596085664279e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_regtpss_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_regtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.771789027752560e-09, 3.204079175904340e-09, 3.945955916824156e-09, 5.322196211337522e-09, 8.179131806855821e-09, 1.515786331238269e-08, 3.672656586029946e-08, 1.299881636834199e-07, 7.633837109651005e-07, 7.992889180880588e-06, 1.835845166199159e-04, 6.663941121236930e-04, -1.281595864825947e-02, 8.267126135611933e-03, 6.942433901029016e-01, 3.287443459281526e+01, 1.040512529133953e+03, 2.140632906775545e+04, 3.983073574458344e+05, 8.064763016156958e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_regtpss_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_regtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.882854828138824e-14, -1.201489118502955e-13, -1.590873787395032e-13, -2.380868925330324e-13, -4.246114024497713e-13, -9.727950558120067e-13, -3.182907427570679e-12, -1.723482455005954e-11, -1.878961861593417e-10, -5.274092174312818e-09, -7.626602294493474e-07, -7.165142041920650e-04, -6.908680102612500e-03, -4.075191071560007e-02, -1.490642347548699e+00, -2.638880588408291e+02, -9.268754318442018e+04, -6.081798126730476e+07, -1.332753465173464e+11, -2.063153405680139e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
