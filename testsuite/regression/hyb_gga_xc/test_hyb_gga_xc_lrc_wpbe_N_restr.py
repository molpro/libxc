
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lrc_wpbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lrc_wpbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.198990212241760e+00, -4.116236535863131e+00, -4.000354960244634e+00, -3.839991742423265e+00, -3.621820684359142e+00, -3.332188092707266e+00, -2.960970201380763e+00, -2.508447844897660e+00, -1.994016348303107e+00, -1.456496471687876e+00, -9.263648194636033e-01, -5.480298372090141e-01, -4.612188677932158e-01, -3.542146527961743e-01, -2.159181986223036e-01, -9.268384056366709e-02, -1.634783933966249e-02, -3.342776373549685e-04, -2.498812902324745e-06, -3.369330342503464e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lrc_wpbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lrc_wpbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.343571090034309e+00, -5.228188283664895e+00, -5.066376448566931e+00, -4.841962640603509e+00, -4.535661969035224e+00, -4.127094867566044e+00, -3.599938201395489e+00, -2.952340586127678e+00, -2.215734980451150e+00, -1.493474974762064e+00, -9.251242558297177e-01, -7.355434659572836e-01, -6.457259490822178e-01, -4.884527297510953e-01, -2.815275475338164e-01, -1.056377104260691e-01, -2.579394312908293e-02, -7.248784994271333e-04, -5.018796563062803e-06, -6.739286142499353e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lrc_wpbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lrc_wpbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.118676007288943e-06, -3.383250895949019e-06, -3.801951622391609e-06, -4.492418303042704e-06, -5.699575084834812e-06, -7.991103736743754e-06, -1.286783404370847e-05, -2.498681503574016e-05, -6.181249063484060e-05, -2.007574627704654e-04, -9.612415407416625e-04, -2.544340105083736e-03, -6.379322358652378e-04, -6.874563910035578e-03, -3.995185388803364e-02, -2.594626506409884e-01, -5.020726530635820e-01, 2.193225360168556e-02, 6.029367316091575e-03, 1.504918247298800e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lrc_wpbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lrc_wpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.253569196634661e-02, -1.312359027560498e-02, -1.401750365266316e-02, -1.540957792008782e-02, -1.765173792232440e-02, -2.143579045497078e-02, -2.823243665008672e-02, -4.140643300176639e-02, -6.820009755571774e-02, -1.063969308126254e-01, -2.197233711577217e-01, -5.800178933343415e-01, -6.393945714792815e-01, -1.197892136157308e+00, -3.506762030397975e+00, -5.648615117083732e+00, -4.626190197941504e+00, -2.822449505199337e+01, -1.802817123970392e+01, -1.746630194736169e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lrc_wpbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lrc_wpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.685626721923820e-08, 3.068203427099718e-08, 3.712499821688205e-08, 4.873501827739786e-08, 7.175121212838897e-08, 1.238635659772191e-07, 2.651788159239641e-07, 7.491940535206904e-07, 2.836608138607789e-06, 6.421767429651489e-06, 1.064386014521917e-05, 1.163172674088326e-02, 1.706662872251242e-02, 1.214719169474362e-01, 1.715838660775961e+00, 4.576349991862127e+00, -1.259508580214757e+03, 5.208371614888781e+03, 1.379281240142950e+05, 2.578579888089020e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_gga_xc_lrc_wpbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lrc_wpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.166987873817086e-14, -5.994375603466294e-14, -7.361426765781917e-14, -9.685611318196001e-14, -1.349844795221758e-13, -1.667158978393097e-13, 2.521964202397634e-13, 8.869687330991299e-12, 2.439354968068471e-10, 1.525944532575283e-08, 2.035717850278023e-06, -6.449037232705713e-04, -7.566241091900579e-03, -3.911590210856636e-02, -1.182203021269362e+00, 8.378874716387534e+01, 1.008982690849003e+05, -1.759800366008235e+07, -4.597286496473075e+10, -6.593246551958486e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
