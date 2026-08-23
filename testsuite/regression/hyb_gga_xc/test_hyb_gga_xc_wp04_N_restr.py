
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_wp04_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wp04", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.457318103236156e+00, -4.374897121155915e+00, -4.259470581360561e+00, -4.099712823801343e+00, -3.882309671220456e+00, -3.593563856028191e+00, -3.223160078435698e+00, -2.770858693486746e+00, -2.255044555674910e+00, -1.714580970446869e+00, -1.176933419929467e+00, -7.540624331900417e-01, -6.481812596894175e-01, -5.517871729352255e-01, -4.177468608300891e-01, -2.859938109893631e-01, -1.825877843443590e-01, -1.098289545031112e-01, -6.424005960606115e-02, -4.036475653846760e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_wp04_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wp04", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.535673898755671e+00, -5.421430834670037e+00, -5.261296964367262e+00, -5.039372135975112e+00, -4.736791456674012e+00, -4.333802193030863e+00, -3.814891765545035e+00, -3.178683630339684e+00, -2.454083329744955e+00, -1.722531743433957e+00, -1.136235911938184e+00, -8.990565896486719e-01, -8.079009960356427e-01, -6.452869621162240e-01, -4.418348402907332e-01, -2.599082881875377e-01, -1.373323628965612e-01, -6.566523401348609e-02, -2.532107946973897e-02, -8.132584331125559e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wp04_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wp04", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.973365493834560e-06, -4.284421958506176e-06, -4.773365625134530e-06, -5.571977886393683e-06, -6.949569731766902e-06, -9.516861422524321e-06, -1.485020502123489e-05, -2.773353365711640e-05, -6.597675452452114e-05, -2.160656198125475e-04, -1.092157564523133e-03, -6.898819219272674e-03, -1.375326604131432e-02, -2.703188184987934e-02, -9.445612664174846e-02, -5.901269654021236e-01, -6.720104621487900e+00, -1.750035086228596e+02, -1.622633627346951e+04, -9.648129154020391e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wp04_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wp04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.195732196766770e-02, -1.249155135111054e-02, -1.330091902454562e-02, -1.455489181987625e-02, -1.656042532649665e-02, -1.991445916911512e-02, -2.587982890285651e-02, -3.738691918132356e-02, -6.182616731546217e-02, -1.187131621986560e-01, -2.711097738643187e-01, -5.542286714012233e-01, -6.899190187445149e-01, -1.153003634755803e+00, -2.519225370368882e+00, -6.581748193893024e+00, -1.541617655561674e+01, 5.766669934252902e+00, 9.602947774345552e+03, 8.690897836238954e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wp04_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wp04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.015934652848483e-08, 2.287786137105248e-08, 2.742007884678180e-08, 3.551475830402609e-08, 5.131933881805995e-08, 8.639450997842038e-08, 1.792816513909236e-07, 4.906609542315533e-07, 1.889687417672519e-06, 1.059203024453157e-05, 1.368182349405740e-04, 8.626723901243792e-03, 3.276956936456294e-02, 8.925998798824310e-02, 5.442649114067032e-01, 1.447975428284777e+00, -1.531936901666956e+03, -1.269977547916871e+06, -9.717924413765873e+09, -3.278731135683904e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wp04_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wp04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.011078552452891e-13, 1.261169053693262e-13, 1.731761894080644e-13, 2.727841984081540e-13, 5.224411193976026e-13, 1.319801248682762e-12, 4.920883341215620e-12, 3.152519693043290e-11, 4.237598828025486e-10, 1.540409377211426e-08, 2.049751853201175e-06, 4.995451013147923e-04, 4.394483773373484e-03, 2.953052862954389e-02, 1.258386832649627e+00, 3.541774696472140e+02, 7.223682832280960e+05, 1.919855555809720e+10, 2.326982400665981e+16, 7.738247796595587e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
